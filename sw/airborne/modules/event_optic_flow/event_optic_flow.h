/*
 * Copyright (C) Bas Pijnacker Hordijk
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
 * @file "modules/event_opticflow/event_opticflow.h"
 * @author Bas Pijnacker Hordijk
 * Event based opticflow using DVS camera
 */

#ifndef EVENT_OPTICFLOW_H
#define EVENT_OPTICFLOW_H

#include <inttypes.h>

extern void event_optic_flow_init(void);
extern void event_optic_flow_start(void);
extern void event_optic_flow_periodic(void);
extern void event_optic_flow_stop(void);

#endif
