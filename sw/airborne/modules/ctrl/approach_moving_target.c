/*
 * Copyright (C) 2021 Ewoud Smeur <e.j.j.smeur@tudelft.nl>
 *
 * This file is part of paparazzi
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, see
 * <http://www.gnu.org/licenses/>.
 */
/**
 * @file "modules/ctrl/approach_moving_target.c"
 * @author Ewoud Smeur <e.j.j.smeur@tudelft.nl>
 * Approach a moving target (e.g. ship)
 */

#include "approach_moving_target.h"

#include "generated/modules.h"
#include "modules/core/abi.h"

float amt_err_slowdown_gain = AMT_ERR_SLOWDOWN_GAIN;

float approach_moving_target_angle_deg;

#define DEBUG_AMT TRUE
#include <stdio.h>

// settings how drone should approach the ship
struct Amt amt = {
  .distance = 60,     // [m], diagonal decent line to ship
  .speed = -1.0,      // [m/s], speed over descent line to ship, inverted because software looks from ship to drone
  .pos_gain = 0.3,    // [-], how aggresive drone tracks the descent line
  .psi_ref = 180.0,   // [deg], descent line direction offset w.r.t. heading ship
  .slope_ref = 35.0,  // [deg], slope descent line
  .speed_gain = 1.0,  // [-], how agressive ..................
  .relvel_gain = 1.0, // [-], ................................
  .enabled_time = 0,
  .wp_id = 0,
};

// Telemetry info to send from drone to base
struct AmtTelem {
  struct FloatVect3 des_pos; 
  struct FloatVect3 des_vel;
};

struct AmtTelem amt_telem;
bool approach_moving_target_enabled = false; // NOT USED

static abi_event gps_ev;
static void gps_cb(uint8_t sender_id, uint32_t stamp, struct GpsState *gps_s);

struct FloatVect3 nav_get_speed_sp_from_diagonal(struct EnuCoor_i target, float pos_gain, float rope_heading);
void update_waypoint(uint8_t wp_id, struct FloatVect3 * target_ned);

#if PERIODIC_TELEMETRY
#include "modules/datalink/telemetry.h"
static void send_approach_moving_target(struct transport_tx *trans, struct link_device *dev)
{
  pprz_msg_send_APPROACH_MOVING_TARGET(trans, dev, AC_ID,
                              &amt_telem.des_pos.x,
                              &amt_telem.des_pos.y,
                              &amt_telem.des_pos.z,
                              &amt_telem.des_vel.x,
                              &amt_telem.des_vel.y,
                              &amt_telem.des_vel.z,
                              &amt.distance
                              );
}
#endif

struct LlaCoor_i gps_lla;

void approach_moving_target_init(void)
{
  AbiBindMsgGPS(ABI_BROADCAST, &gps_ev, gps_cb);

#if PERIODIC_TELEMETRY
  register_periodic_telemetry(DefaultPeriodic, PPRZ_MSG_ID_APPROACH_MOVING_TARGET, send_approach_moving_target);
#endif
}


/* Update INS (internal navigation system) based on GPS information */
static void gps_cb(uint8_t sender_id __attribute__((unused)),
                   uint32_t stamp,
                   struct GpsState *gps_s)
{
  gps_lla.lat = gps_s->lla_pos.lat;
  gps_lla.lon = gps_s->lla_pos.lon;
  gps_lla.alt = gps_s->lla_pos.alt;
}

// interface with ship position module?

// Update a waypoint such that you can see on the GCS where the drone wants to go
void update_waypoint(uint8_t wp_id, struct FloatVect3 * target_ned) {

  // Update the waypoint
  struct EnuCoor_f target_enu;
  ENU_OF_TO_NED(target_enu, *target_ned);
  waypoint_set_enu(wp_id, &target_enu);

  // Send waypoint update every half second
  RunOnceEvery(100/2, {
    // Send to the GCS that the waypoint has been moved
    DOWNLINK_SEND_WP_MOVED_ENU(DefaultChannel, DefaultDevice, &wp_id,
                                &waypoints[wp_id].enu_i.x,
                                &waypoints[wp_id].enu_i.y,
                                &waypoints[wp_id].enu_i.z);
  } );
}

// Function to enable from flight plan (call repeatedly!)
void approach_moving_target_enable(uint8_t wp_id) {
  amt.enabled_time = get_sys_time_msec();
  amt.wp_id = wp_id;
}

/**
 * @brief Generates a velocity reference from a diagonal approach path
 *
 */
void follow_diagonal_approach(void) {
  /* STEPS
    - check enable timeout
    - get target pos, vel, hdg (target is the landing spot)
    - calculate descent line unit vector (is it nesceserry to calculate this over and over every loop?)
    - 
  */

  // Check if the flight plan recently called the enable function
  if ( (get_sys_time_msec() - amt.enabled_time) > (2000 / NAVIGATION_FREQUENCY)) {
    return;
  }

  // Get the target position, velocity and heading
  struct NedCoor_f target_pos, target_vel = {0};
  float target_heading;
  if(!target_get_pos(&target_pos, &target_heading)) {
    // TODO: What to do? Same can be checked for the velocity
    return;
  }
  target_get_vel(&target_vel); // [m/s] update ground speed of the ship
  VECT3_SMUL(target_vel, target_vel, amt.speed_gain);

  // Reference model (descent line)
  // Translate angles to unit vector
  float gamma_ref = RadOfDeg(amt.slope_ref); // descent rate 
  float psi_ref = RadOfDeg(target_heading + amt.psi_ref); // how descent line lines up with ship heading
  amt.rel_unit_vec.x = cosf(gamma_ref) * cosf(psi_ref);
  amt.rel_unit_vec.y = cosf(gamma_ref) * sinf(psi_ref); 
  amt.rel_unit_vec.z = -sinf(gamma_ref);

  // Multiply vector with prefered descent dist to get ref point of descent
  // Desired position = rel_pos + target_pos ??????????????
  struct FloatVect3 ref_relpos;
  VECT3_SMUL(ref_relpos, amt.rel_unit_vec, amt.distance);

  // Add ref point of descent to ship location to get NED coordinate ref point of descent
  // ATTENTION, target_pos is already relative now!
  struct FloatVect3 des_pos;
  VECT3_SUM(des_pos, ref_relpos, target_pos);

  // ------------------------------------------------------------------------- ADD MORE COMMENTS FROM HERE ON

  struct FloatVect3 ref_relvel;
  VECT3_SMUL(ref_relvel, amt.rel_unit_vec, amt.speed * amt.relvel_gain); 

  // error controller
  struct FloatVect3 pos_err;
  struct FloatVect3 ec_vel;
  struct NedCoor_f *drone_pos = stateGetPositionNed_f();
  // ATTENTION, target_pos is already relative now!
  // VECT3_DIFF(pos_err, des_pos, *drone_pos);
  VECT3_COPY(pos_err, des_pos);
  VECT3_SMUL(ec_vel, pos_err, amt.pos_gain);

  // desired velocity = rel_vel + target_vel + error_controller(using NED position)
  struct FloatVect3 des_vel = {
    ref_relvel.x + target_vel.x + ec_vel.x,
    ref_relvel.y + target_vel.y + ec_vel.y,
    ref_relvel.z + target_vel.z + ec_vel.z,
  };

  vect_bound_in_3d(&des_vel, 10.0);

  // Bound vertical speed setpoint
  if(stateGetAirspeed_f() > 13.0) {
    Bound(des_vel.z, -4.0, 5.0);
  } else {
    Bound(des_vel.z, -nav_climb_vspeed, -nav_descend_vspeed);
  }

  AbiSendMsgVEL_SP(VEL_SP_FCR_ID, &des_vel);

  /* limit the speed such that the vertical component is small enough
  * and doesn't outrun the vehicle
  */
  float min_speed;
  float sin_gamma_ref = sinf(gamma_ref);
  if (sin_gamma_ref > 0.05) {
    min_speed = (nav_descend_vspeed+0.1) / sin_gamma_ref;
  } else {
    min_speed = -5.0; // prevent dividing by zero
  }

  // The upper bound is not very important
  Bound(amt.speed, min_speed, 4.0);

  // Reduce approach speed if the error is large
  float norm_pos_err_sq = VECT3_NORM2(pos_err);
  float int_speed = amt.speed / (norm_pos_err_sq * amt_err_slowdown_gain + 1.0);

  // integrate speed to get the distance
  float dt = FOLLOW_DIAGONAL_APPROACH_PERIOD;
  amt.distance += int_speed*dt;

  // For display purposes
  struct FloatVect3 disp_pos_target;
  VECT3_SUM(disp_pos_target, des_pos, *drone_pos);
  update_waypoint(amt.wp_id, &disp_pos_target);

  // Debug target pos:
  VECT3_DIFF(amt_telem.des_pos, *drone_pos, target_pos);

  // Update values for telemetry
  VECT3_COPY(amt_telem.des_pos, des_pos); 
  VECT3_COPY(amt_telem.des_vel, des_vel);
}
