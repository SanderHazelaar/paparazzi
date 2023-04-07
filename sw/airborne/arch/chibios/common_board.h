/*
 * Copyright (C) 2022 Freek van Tienen <freek.v.tienen@gmail.com>
 *
 * This file is part of Paparazzi.
 *
 * Paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * Paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Paparazzi; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */

/**
 * @file arch/chibios/common_board.h
 * @brief Generic board file
 */
#ifndef ARCH_COMMON_BOARD_H
#define ARCH_COMMON_BOARD_H
/**
 * ChibiOS board file generated by the cfg file
 */
#include "board.h"
#include <hal.h>

/*
 * Concat macro
 */
#define _CONCAT_BOARD_PARAM(_s1, _s2) _s1 ## _s2
#define CONCAT_BOARD_PARAM(_s1, _s2) _CONCAT_BOARD_PARAM(_s1, _s2)

/*
 * LEDs
 */
#if defined(LINE_LED1)
#ifndef USE_LED_1
#define USE_LED_1 1
#endif
#define LED_1_GPIO        PAL_PORT(LINE_LED1)
#define LED_1_GPIO_PIN    PAL_PAD(LINE_LED1)
#define LED_1_GPIO_ON     gpio_clear
#define LED_1_GPIO_OFF    gpio_set
#endif

#if defined(LINE_LED2)
#ifndef USE_LED_2
#define USE_LED_2 1
#endif
#define LED_2_GPIO        PAL_PORT(LINE_LED2)
#define LED_2_GPIO_PIN    PAL_PAD(LINE_LED2)
#define LED_2_GPIO_ON     gpio_clear
#define LED_2_GPIO_OFF    gpio_set
#endif

#if defined(LINE_LED3)
#ifndef USE_LED_3
#define USE_LED_3 1
#endif
#define LED_3_GPIO        PAL_PORT(LINE_LED3)
#define LED_3_GPIO_PIN    PAL_PAD(LINE_LED3)
#define LED_3_GPIO_ON     gpio_clear
#define LED_3_GPIO_OFF    gpio_set
#endif

#if defined(LINE_LED4)
#ifndef USE_LED_4
#define USE_LED_4 1
#endif
#define LED_4_GPIO        PAL_PORT(LINE_LED4)
#define LED_4_GPIO_PIN    PAL_PAD(LINE_LED4)
#define LED_4_GPIO_ON     gpio_clear
#define LED_4_GPIO_OFF    gpio_set
#endif

/*
 * IMU Heater
 */
#if defined(LINE_IMU_HEATER)
#define IMU_HEATER_GPIO       PAL_PORT(LINE_IMU_HEATER)
#define IMU_HEATER_GPIO_PIN   PAL_PAD(LINE_IMU_HEATER)
#endif

/*
 * ADCs
 */
#if defined(LINE_ADC1)
#ifndef USE_ADC_1
#define USE_ADC_1 1
#endif
#if USE_ADC_1
#if defined(ADC1_ADC_IN)
#define AD1_1_CHANNEL     CONCAT_BOARD_PARAM(ADC_CHANNEL_IN, ADC1_ADC_IN)
#elif defined(ADC1_ADC_INP)
#define AD1_1_CHANNEL     CONCAT_BOARD_PARAM(ADC_CHANNEL_IN, ADC1_ADC_INP)
#endif
#define ADC_1             AD1_1
#define ADC_1_GPIO_PORT   PAL_PORT(LINE_ADC1)
#define ADC_1_GPIO_PIN    PAL_PAD(LINE_ADC1)
#endif
#endif

#if defined(LINE_ADC2)
#ifndef USE_ADC_2
#define USE_ADC_2 1
#endif
#if USE_ADC_2
#if defined(ADC2_ADC_IN)
#define AD1_2_CHANNEL     CONCAT_BOARD_PARAM(ADC_CHANNEL_IN, ADC2_ADC_IN)
#elif defined(ADC2_ADC_INP)
#define AD1_2_CHANNEL     CONCAT_BOARD_PARAM(ADC_CHANNEL_IN, ADC2_ADC_INP)
#endif
#define ADC_2             AD1_2
#define ADC_2_GPIO_PORT   PAL_PORT(LINE_ADC2)
#define ADC_2_GPIO_PIN    PAL_PAD(LINE_ADC2)
#endif
#endif

#if defined(LINE_ADC3)
#ifndef USE_ADC_3
#define USE_ADC_3 1
#endif
#if USE_ADC_3
#if defined(ADC3_ADC_IN)
#define AD1_3_CHANNEL     CONCAT_BOARD_PARAM(ADC_CHANNEL_IN, ADC3_ADC_IN)
#elif defined(ADC3_ADC_INP)
#define AD1_3_CHANNEL     CONCAT_BOARD_PARAM(ADC_CHANNEL_IN, ADC3_ADC_INP)
#endif
#define ADC_3             AD1_3
#define ADC_3_GPIO_PORT   PAL_PORT(LINE_ADC3)
#define ADC_3_GPIO_PIN    PAL_PAD(LINE_ADC3)
#endif
#endif

#if defined(LINE_ADC4)
#ifndef USE_ADC_4
#define USE_ADC_4 1
#endif
#if USE_ADC_4
#if defined(ADC4_ADC_IN)
#define AD1_4_CHANNEL     CONCAT_BOARD_PARAM(ADC_CHANNEL_IN, ADC4_ADC_IN)
#elif defined(ADC4_ADC_INP)
#define AD1_4_CHANNEL     CONCAT_BOARD_PARAM(ADC_CHANNEL_IN, ADC4_ADC_INP)
#endif
#define ADC_4             AD1_4
#define ADC_4_GPIO_PORT   PAL_PORT(LINE_ADC4)
#define ADC_4_GPIO_PIN    PAL_PAD(LINE_ADC4)
#endif
#endif

#if defined(LINE_ADC5)
#ifndef USE_ADC_5
#define USE_ADC_5 1
#endif
#if USE_ADC_5
#if defined(ADC5_ADC_IN)
#define AD1_5_CHANNEL     CONCAT_BOARD_PARAM(ADC_CHANNEL_IN, ADC5_ADC_IN)
#elif defined(ADC5_ADC_INP)
#define AD1_5_CHANNEL     CONCAT_BOARD_PARAM(ADC_CHANNEL_IN, ADC5_ADC_INP)
#endif
#define ADC_5             AD1_5
#define ADC_5_GPIO_PORT   PAL_PORT(LINE_ADC5)
#define ADC_5_GPIO_PIN    PAL_PAD(LINE_ADC5)
#endif
#endif

#if defined(LINE_ADC6)
#if USE_ADC_6
#if defined(ADC6_ADC_IN)
#define AD1_6_CHANNEL     CONCAT_BOARD_PARAM(ADC_CHANNEL_IN, ADC6_ADC_IN)
#elif defined(ADC6_ADC_INP)
#define AD1_6_CHANNEL     CONCAT_BOARD_PARAM(ADC_CHANNEL_IN, ADC6_ADC_INP)
#endif
#define ADC_6             AD1_6
#define ADC_6_GPIO_PORT   PAL_PORT(LINE_ADC6)
#define ADC_6_GPIO_PIN    PAL_PAD(LINE_ADC6)
#endif
#endif

/*
 * PWM defines
 */
#if defined(LINE_SERVO1)
#ifndef USE_PWM1
#define USE_PWM1 1
#endif
#if USE_PWM1
#define PWM_SERVO_1 0
#define PWM_SERVO_1_GPIO    PAL_PORT(LINE_SERVO1)
#define PWM_SERVO_1_PIN     PAL_PAD(LINE_SERVO1)
#define PWM_SERVO_1_AF      AF_LINE_SERVO1
#define PWM_SERVO_1_DRIVER  CONCAT_BOARD_PARAM(PWMD, SERVO1_TIM)
#define PWM_SERVO_1_CHANNEL (SERVO1_TIM_CH-1)
#define PWM_SERVO_1_CONF    CONCAT_BOARD_PARAM(pwmcfg, SERVO1_TIM)
#endif
#endif

#if defined(LINE_SERVO2)
#ifndef USE_PWM2
#define USE_PWM2 1
#endif
#if USE_PWM2
#define PWM_SERVO_2 1
#define PWM_SERVO_2_GPIO    PAL_PORT(LINE_SERVO2)
#define PWM_SERVO_2_PIN     PAL_PAD(LINE_SERVO2)
#define PWM_SERVO_2_AF      AF_LINE_SERVO2
#define PWM_SERVO_2_DRIVER  CONCAT_BOARD_PARAM(PWMD, SERVO2_TIM)
#define PWM_SERVO_2_CHANNEL (SERVO2_TIM_CH-1)
#define PWM_SERVO_2_CONF    CONCAT_BOARD_PARAM(pwmcfg, SERVO2_TIM)
#endif
#endif

#if defined(LINE_SERVO3)
#ifndef USE_PWM3
#define USE_PWM3 1
#endif
#if USE_PWM3
#define PWM_SERVO_3 2
#define PWM_SERVO_3_GPIO    PAL_PORT(LINE_SERVO3)
#define PWM_SERVO_3_PIN     PAL_PAD(LINE_SERVO3)
#define PWM_SERVO_3_AF      AF_LINE_SERVO3
#define PWM_SERVO_3_DRIVER  CONCAT_BOARD_PARAM(PWMD, SERVO3_TIM)
#define PWM_SERVO_3_CHANNEL (SERVO3_TIM_CH-1)
#define PWM_SERVO_3_CONF    CONCAT_BOARD_PARAM(pwmcfg, SERVO3_TIM)
#endif
#endif

#if defined(LINE_SERVO4)
#ifndef USE_PWM4
#define USE_PWM4 1
#endif
#if USE_PWM4
#define PWM_SERVO_4 3
#define PWM_SERVO_4_GPIO    PAL_PORT(LINE_SERVO4)
#define PWM_SERVO_4_PIN     PAL_PAD(LINE_SERVO4)
#define PWM_SERVO_4_AF      AF_LINE_SERVO4
#define PWM_SERVO_4_DRIVER  CONCAT_BOARD_PARAM(PWMD, SERVO4_TIM)
#define PWM_SERVO_4_CHANNEL (SERVO4_TIM_CH-1)
#define PWM_SERVO_4_CONF    CONCAT_BOARD_PARAM(pwmcfg, SERVO4_TIM)
#endif
#endif

#if defined(LINE_SERVO5)
#ifndef USE_PWM5
#define USE_PWM5 1
#endif
#if USE_PWM5
#define PWM_SERVO_5 4
#define PWM_SERVO_5_GPIO    PAL_PORT(LINE_SERVO5)
#define PWM_SERVO_5_PIN     PAL_PAD(LINE_SERVO5)
#define PWM_SERVO_5_AF      AF_LINE_SERVO5
#define PWM_SERVO_5_DRIVER  CONCAT_BOARD_PARAM(PWMD, SERVO5_TIM)
#define PWM_SERVO_5_CHANNEL (SERVO5_TIM_CH-1)
#define PWM_SERVO_5_CONF    CONCAT_BOARD_PARAM(pwmcfg, SERVO5_TIM)
#endif
#endif

#if defined(LINE_SERVO6)
#ifndef USE_PWM6
#define USE_PWM6 1
#endif
#if USE_PWM6
#define PWM_SERVO_6 5
#define PWM_SERVO_6_GPIO    PAL_PORT(LINE_SERVO6)
#define PWM_SERVO_6_PIN     PAL_PAD(LINE_SERVO6)
#define PWM_SERVO_6_AF      AF_LINE_SERVO6
#define PWM_SERVO_6_DRIVER  CONCAT_BOARD_PARAM(PWMD, SERVO6_TIM)
#define PWM_SERVO_6_CHANNEL (SERVO6_TIM_CH-1)
#define PWM_SERVO_6_CONF    CONCAT_BOARD_PARAM(pwmcfg, SERVO6_TIM)
#endif
#endif

#if defined(LINE_SERVO7)
#ifndef USE_PWM7
#define USE_PWM7 1
#endif
#if USE_PWM7
#define PWM_SERVO_7 6
#define PWM_SERVO_7_GPIO    PAL_PORT(LINE_SERVO7)
#define PWM_SERVO_7_PIN     PAL_PAD(LINE_SERVO7)
#define PWM_SERVO_7_AF      AF_LINE_SERVO7
#define PWM_SERVO_7_DRIVER  CONCAT_BOARD_PARAM(PWMD, SERVO7_TIM)
#define PWM_SERVO_7_CHANNEL (SERVO7_TIM_CH-1)
#define PWM_SERVO_7_CONF    CONCAT_BOARD_PARAM(pwmcfg, SERVO7_TIM)
#endif
#endif

#if defined(LINE_SERVO8)
#ifndef USE_PWM8
#define USE_PWM8 1
#endif
#if USE_PWM8
#define PWM_SERVO_8 7
#define PWM_SERVO_8_GPIO    PAL_PORT(LINE_SERVO8)
#define PWM_SERVO_8_PIN     PAL_PAD(LINE_SERVO8)
#define PWM_SERVO_8_AF      AF_LINE_SERVO8
#define PWM_SERVO_8_DRIVER  CONCAT_BOARD_PARAM(PWMD, SERVO8_TIM)
#define PWM_SERVO_8_CHANNEL (SERVO8_TIM_CH-1)
#define PWM_SERVO_8_CONF    CONCAT_BOARD_PARAM(pwmcfg, SERVO8_TIM)
#endif
#endif

/*
 * PWM input
 */
#define PWM_INPUT1_ICU            CONCAT_BOARD_PARAM(ICUD, PWM_INPUT1_TIM)
#define PWM_INPUT1_CHANNEL        CONCAT_BOARD_PARAM(ICU_CHANNEL_, PWM_INPUT1_TIM_CH)
#define PWM_INPUT1_GPIO_PORT      PAL_PORT(LINE_PWM_INPUT1)
#define PWM_INPUT1_GPIO_PIN       PAL_PAD(LINE_PWM_INPUT1)
#define PWM_INPUT1_GPIO_AF        AF_LINE_PWM_INPUT1

/**
 * UART defines
 */
#if defined(LINE_UART1_TX)
#define UART1_GPIO_PORT_TX    PAL_PORT(LINE_UART1_TX)
#define UART1_GPIO_TX         PAL_PAD(LINE_UART1_TX)
#endif
#if defined(LINE_UART1_RX)
#define UART1_GPIO_PORT_RX    PAL_PORT(LINE_UART1_RX)
#define UART1_GPIO_RX         PAL_PAD(LINE_UART1_RX)
#endif
#if defined(AF_LINE_UART1_TX)
#define UART1_GPIO_AF         AF_LINE_UART1_TX
#elif defined(AF_LINE_UART1_RX)
#define UART1_GPIO_AF         AF_LINE_UART1_RX
#else
#define UART1_GPIO_AF         ((void)0)
#endif

#if defined(LINE_UART2_TX)
#define UART2_GPIO_PORT_TX    PAL_PORT(LINE_UART2_TX)
#define UART2_GPIO_TX         PAL_PAD(LINE_UART2_TX)
#endif
#if defined(LINE_UART2_RX)
#define UART2_GPIO_PORT_RX    PAL_PORT(LINE_UART2_RX)
#define UART2_GPIO_RX         PAL_PAD(LINE_UART2_RX)
#endif
#if defined(AF_LINE_UART2_TX)
#define UART2_GPIO_AF         AF_LINE_UART2_TX
#elif defined(AF_LINE_UART2_RX)
#define UART2_GPIO_AF         AF_LINE_UART2_RX
#else
#define UART2_GPIO_AF         ((void)0)
#endif

#if defined(LINE_UART3_TX)
#define UART3_GPIO_PORT_TX    PAL_PORT(LINE_UART3_TX)
#define UART3_GPIO_TX         PAL_PAD(LINE_UART3_TX)
#endif
#if defined(LINE_UART3_RX)
#define UART3_GPIO_PORT_RX    PAL_PORT(LINE_UART3_RX)
#define UART3_GPIO_RX         PAL_PAD(LINE_UART3_RX)
#endif
#if defined(AF_LINE_UART3_TX)
#define UART3_GPIO_AF         AF_LINE_UART3_TX
#elif defined(AF_LINE_UART3_RX)
#define UART3_GPIO_AF         AF_LINE_UART3_RX
#else
#define UART3_GPIO_AF         ((void)0)
#endif

#if defined(LINE_UART4_TX)
#define UART4_GPIO_PORT_TX    PAL_PORT(LINE_UART4_TX)
#define UART4_GPIO_TX         PAL_PAD(LINE_UART4_TX)
#endif
#if defined(LINE_UART4_RX)
#define UART4_GPIO_PORT_RX    PAL_PORT(LINE_UART4_RX)
#define UART4_GPIO_RX         PAL_PAD(LINE_UART4_RX)
#endif
#if defined(AF_LINE_UART4_TX)
#define UART4_GPIO_AF         AF_LINE_UART4_TX
#elif defined(AF_LINE_UART4_RX)
#define UART4_GPIO_AF         AF_LINE_UART4_RX
#else
#define UART4_GPIO_AF         ((void)0)
#endif

#if defined(LINE_UART5_TX)
#define UART5_GPIO_PORT_TX    PAL_PORT(LINE_UART5_TX)
#define UART5_GPIO_TX         PAL_PAD(LINE_UART5_TX)
#endif
#if defined(LINE_UART5_RX)
#define UART5_GPIO_PORT_RX    PAL_PORT(LINE_UART5_RX)
#define UART5_GPIO_RX         PAL_PAD(LINE_UART5_RX)
#endif
#if defined(AF_LINE_UART5_TX)
#define UART5_GPIO_AF         AF_LINE_UART5_TX
#elif defined(AF_LINE_UART5_RX)
#define UART5_GPIO_AF         AF_LINE_UART5_RX
#else
#define UART5_GPIO_AF         ((void)0)
#endif

#if defined(LINE_UART6_TX)
#define UART6_GPIO_PORT_TX    PAL_PORT(LINE_UART6_TX)
#define UART6_GPIO_TX         PAL_PAD(LINE_UART6_TX)
#endif
#if defined(LINE_UART6_RX)
#define UART6_GPIO_PORT_RX    PAL_PORT(LINE_UART6_RX)
#define UART6_GPIO_RX         PAL_PAD(LINE_UART6_RX)
#endif
#if defined(AF_LINE_UART6_TX)
#define UART6_GPIO_AF         AF_LINE_UART6_TX
#elif defined(AF_LINE_UART6_RX)
#define UART6_GPIO_AF         AF_LINE_UART6_RX
#else
#define UART6_GPIO_AF         ((void)0)
#endif

#if defined(LINE_UART7_TX)
#define UART7_GPIO_PORT_TX    PAL_PORT(LINE_UART7_TX)
#define UART7_GPIO_TX         PAL_PAD(LINE_UART7_TX)
#endif
#if defined(LINE_UART7_RX)
#define UART7_GPIO_PORT_RX    PAL_PORT(LINE_UART7_RX)
#define UART7_GPIO_RX         PAL_PAD(LINE_UART7_RX)
#endif
#if defined(AF_LINE_UART7_TX)
#define UART7_GPIO_AF         AF_LINE_UART7_TX
#elif defined(AF_LINE_UART7_RX)
#define UART7_GPIO_AF         AF_LINE_UART7_RX
#else
#define UART7_GPIO_AF         ((void)0)
#endif

#if defined(LINE_UART8_TX)
#define UART8_GPIO_PORT_TX    PAL_PORT(LINE_UART8_TX)
#define UART8_GPIO_TX         PAL_PAD(LINE_UART8_TX)
#endif
#if defined(LINE_UART8_RX)
#define UART8_GPIO_PORT_RX    PAL_PORT(LINE_UART8_RX)
#define UART8_GPIO_RX         PAL_PAD(LINE_UART8_RX)
#endif
#if defined(AF_LINE_UART8_TX)
#define UART8_GPIO_AF         AF_LINE_UART8_TX
#elif defined(AF_LINE_UART8_RX)
#define UART8_GPIO_AF         AF_LINE_UART8_RX
#else
#define UART8_GPIO_AF         ((void)0)
#endif

/**
 * I2C defines
 */
// Digital noise filter: 0 disabled, [0x1 - 0xF] enable up to n t_I2CCLK
#define STM32_CR1_DNF(n)          ((n & 0x0f) << 8)

// Timing register
#if defined(STM32F7XX)
#define I2C_CFG_100KHZ_TIMINGR (STM32_TIMINGR_PRESC(3U) | STM32_TIMINGR_SCLDEL(8U) | STM32_TIMINGR_SDADEL(1U) | STM32_TIMINGR_SCLH(46U) | STM32_TIMINGR_SCLL(62U)) // 0x30812E3E
#define I2C_CFG_400KHZ_TIMINGR (STM32_TIMINGR_PRESC(6U) | STM32_TIMINGR_SCLDEL(0U) | STM32_TIMINGR_SDADEL(0U) | STM32_TIMINGR_SCLH(3U) | STM32_TIMINGR_SCLL(13U)) // 0x6000030D
#elif defined(STM32H7XX)
#define I2C_CFG_100KHZ_TIMINGR (STM32_TIMINGR_PRESC(0U) | STM32_TIMINGR_SCLDEL(7U) | STM32_TIMINGR_SDADEL(0U) | STM32_TIMINGR_SCLH(124U) | STM32_TIMINGR_SCLL(187U)) // 0x00707CBB
#define I2C_CFG_400KHZ_TIMINGR (STM32_TIMINGR_PRESC(0U) | STM32_TIMINGR_SCLDEL(3U) | STM32_TIMINGR_SDADEL(0U) | STM32_TIMINGR_SCLH(16U) | STM32_TIMINGR_SCLL(56U)) // 0x00300F38
#endif


#ifndef I2C1_CLOCK_SPEED
#define I2C1_CLOCK_SPEED 400000
#endif

#if I2C1_CLOCK_SPEED == 400000
#define I2C1_CFG_DEF { \
  .timingr = I2C_CFG_400KHZ_TIMINGR, \
  .cr1 = STM32_CR1_DNF(0), \
  .cr2 = 0 \
}
#elif I2C1_CLOCK_SPEED == 100000
#define I2C1_CFG_DEF { \
  .timingr = I2C_CFG_100KHZ_TIMINGR, \
  .cr1 = STM32_CR1_DNF(0), \
  .cr2 = 0 \
}
#else
#error "Unknown I2C1 clock speed"
#endif


#ifndef I2C2_CLOCK_SPEED
#define I2C2_CLOCK_SPEED 400000
#endif

#if I2C2_CLOCK_SPEED == 400000
#define I2C2_CFG_DEF { \
  .timingr = I2C_CFG_400KHZ_TIMINGR, \
  .cr1 = STM32_CR1_DNF(0), \
  .cr2 = 0 \
}
#elif I2C2_CLOCK_SPEED == 100000
#define I2C2_CFG_DEF { \
  .timingr = I2C_CFG_100KHZ_TIMINGR, \
  .cr1 = STM32_CR1_DNF(0), \
  .cr2 = 0 \
}
#else
#error "Unknown I2C2 clock speed"
#endif

#ifndef I2C3_CLOCK_SPEED
#define I2C3_CLOCK_SPEED 400000
#endif

#if I2C3_CLOCK_SPEED == 400000
#define I2C3_CFG_DEF { \
  .timingr = I2C_CFG_400KHZ_TIMINGR, \
  .cr1 = STM32_CR1_DNF(0), \
  .cr2 = 0 \
}
#elif I2C3_CLOCK_SPEED == 100000
#define I2C3_CFG_DEF { \
  .timingr = I2C_CFG_100KHZ_TIMINGR, \
  .cr1 = STM32_CR1_DNF(0), \
  .cr2 = 0 \
}
#else
#error "Unknown I2C3 clock speed"
#endif

#ifndef I2C4_CLOCK_SPEED
#define I2C4_CLOCK_SPEED 400000
#endif

#if I2C4_CLOCK_SPEED == 400000
#define I2C4_CFG_DEF { \
  .timingr = I2C_CFG_400KHZ_TIMINGR, \
  .cr1 = STM32_CR1_DNF(0), \
  .cr2 = 0 \
}
#elif I2C4_CLOCK_SPEED == 100000
#define I2C4_CFG_DEF { \
  .timingr = I2C_CFG_100KHZ_TIMINGR, \
  .cr1 = STM32_CR1_DNF(0), \
  .cr2 = 0 \
}
#else
#error "Unknown I2C4 clock speed"
#endif

/**
 * SPI Config
 */
#if defined(LINE_SPI1_MISO) && defined(LINE_SPI1_MOSI) && defined(LINE_SPI1_SCK)
#define SPI1_GPIO_PORT_MISO   PAL_PORT(LINE_SPI1_MISO)
#define SPI1_GPIO_MISO        PAL_PAD(LINE_SPI1_MISO)
#define SPI1_GPIO_PORT_MOSI   PAL_PORT(LINE_SPI1_MOSI)
#define SPI1_GPIO_MOSI        PAL_PAD(LINE_SPI1_MOSI)
#define SPI1_GPIO_PORT_SCK    PAL_PORT(LINE_SPI1_SCK)
#define SPI1_GPIO_SCK         PAL_PAD(LINE_SPI1_SCK)

#if defined(AF_LINE_SPI1_SCK)
#define SPI1_GPIO_AF    AF_LINE_SPI1_SCK
#endif
#endif

#if defined(LINE_SPI2_MISO) && defined(LINE_SPI2_MOSI) && defined(LINE_SPI2_SCK)
#define SPI2_GPIO_PORT_MISO   PAL_PORT(LINE_SPI2_MISO)
#define SPI2_GPIO_MISO        PAL_PAD(LINE_SPI2_MISO)
#define SPI2_GPIO_PORT_MOSI   PAL_PORT(LINE_SPI2_MOSI)
#define SPI2_GPIO_MOSI        PAL_PAD(LINE_SPI2_MOSI)
#define SPI2_GPIO_PORT_SCK    PAL_PORT(LINE_SPI2_SCK)
#define SPI2_GPIO_SCK         PAL_PAD(LINE_SPI2_SCK)

#if defined(AF_LINE_SPI2_SCK)
#define SPI2_GPIO_AF    AF_LINE_SPI2_SCK
#endif
#endif

#if defined(LINE_SPI3_MISO) && defined(LINE_SPI3_MOSI) && defined(LINE_SPI3_SCK)
#define SPI3_GPIO_PORT_MISO   PAL_PORT(LINE_SPI3_MISO)
#define SPI3_GPIO_MISO        PAL_PAD(LINE_SPI3_MISO)
#define SPI3_GPIO_PORT_MOSI   PAL_PORT(LINE_SPI3_MOSI)
#define SPI3_GPIO_MOSI        PAL_PAD(LINE_SPI3_MOSI)
#define SPI3_GPIO_PORT_SCK    PAL_PORT(LINE_SPI3_SCK)
#define SPI3_GPIO_SCK         PAL_PAD(LINE_SPI3_SCK)

#if defined(AF_LINE_SPI3_SCK)
#define SPI3_GPIO_AF    AF_LINE_SPI3_SCK
#endif
#endif

#if defined(LINE_SPI4_MISO) && defined(LINE_SPI4_MOSI) && defined(LINE_SPI4_SCK)
#define SPI4_GPIO_PORT_MISO   PAL_PORT(LINE_SPI4_MISO)
#define SPI4_GPIO_MISO        PAL_PAD(LINE_SPI4_MISO)
#define SPI4_GPIO_PORT_MOSI   PAL_PORT(LINE_SPI4_MOSI)
#define SPI4_GPIO_MOSI        PAL_PAD(LINE_SPI4_MOSI)
#define SPI4_GPIO_PORT_SCK    PAL_PORT(LINE_SPI4_SCK)
#define SPI4_GPIO_SCK         PAL_PAD(LINE_SPI4_SCK)

#if defined(AF_LINE_SPI4_SCK)
#define SPI4_GPIO_AF    AF_LINE_SPI4_SCK
#endif
#endif

#if defined(LINE_SPI5_MISO) && defined(LINE_SPI5_MOSI) && defined(LINE_SPI5_SCK)
#define SPI5_GPIO_PORT_MISO   PAL_PORT(LINE_SPI5_MISO)
#define SPI5_GPIO_MISO        PAL_PAD(LINE_SPI5_MISO)
#define SPI5_GPIO_PORT_MOSI   PAL_PORT(LINE_SPI5_MOSI)
#define SPI5_GPIO_MOSI        PAL_PAD(LINE_SPI5_MOSI)
#define SPI5_GPIO_PORT_SCK    PAL_PORT(LINE_SPI5_SCK)
#define SPI5_GPIO_SCK         PAL_PAD(LINE_SPI5_SCK)

#if defined(AF_LINE_SPI5_SCK)
#define SPI5_GPIO_AF    AF_LINE_SPI5_SCK
#endif
#endif

#if defined(LINE_SPI6_MISO) && defined(LINE_SPI6_MOSI) && defined(LINE_SPI6_SCK)
#define SPI6_GPIO_PORT_MISO   PAL_PORT(LINE_SPI6_MISO)
#define SPI6_GPIO_MISO        PAL_PAD(LINE_SPI6_MISO)
#define SPI6_GPIO_PORT_MOSI   PAL_PORT(LINE_SPI6_MOSI)
#define SPI6_GPIO_MOSI        PAL_PAD(LINE_SPI6_MOSI)
#define SPI6_GPIO_PORT_SCK    PAL_PORT(LINE_SPI6_SCK)
#define SPI6_GPIO_SCK         PAL_PAD(LINE_SPI6_SCK)

#if defined(AF_LINE_SPI6_SCK)
#define SPI6_GPIO_AF    AF_LINE_SPI6_SCK
#endif
#endif

/**
 * SPI Slaves
 */
#if defined(LINE_SPI_SLAVE0)
#define SPI_SELECT_SLAVE0_PORT  PAL_PORT(LINE_SPI_SLAVE0)
#define SPI_SELECT_SLAVE0_PIN   PAL_PAD(LINE_SPI_SLAVE0)
#endif

#if defined(LINE_SPI_SLAVE1)
#define SPI_SELECT_SLAVE1_PORT  PAL_PORT(LINE_SPI_SLAVE1)
#define SPI_SELECT_SLAVE1_PIN   PAL_PAD(LINE_SPI_SLAVE1)
#endif

#if defined(LINE_SPI_SLAVE2)
#define SPI_SELECT_SLAVE2_PORT  PAL_PORT(LINE_SPI_SLAVE2)
#define SPI_SELECT_SLAVE2_PIN   PAL_PAD(LINE_SPI_SLAVE2)
#endif

#if defined(LINE_SPI_SLAVE3)
#define SPI_SELECT_SLAVE3_PORT  PAL_PORT(LINE_SPI_SLAVE3)
#define SPI_SELECT_SLAVE3_PIN   PAL_PAD(LINE_SPI_SLAVE3)
#endif

#if defined(LINE_SPI_SLAVE4)
#define SPI_SELECT_SLAVE4_PORT  PAL_PORT(LINE_SPI_SLAVE4)
#define SPI_SELECT_SLAVE4_PIN   PAL_PAD(LINE_SPI_SLAVE4)
#endif

#if defined(LINE_SPI_SLAVE5)
#define SPI_SELECT_SLAVE5_PORT  PAL_PORT(LINE_SPI_SLAVE5)
#define SPI_SELECT_SLAVE5_PIN   PAL_PAD(LINE_SPI_SLAVE5)
#endif

#if defined(LINE_SPI_SLAVE6)
#define SPI_SELECT_SLAVE6_PORT  PAL_PORT(LINE_SPI_SLAVE6)
#define SPI_SELECT_SLAVE6_PIN   PAL_PAD(LINE_SPI_SLAVE6)
#endif

#if defined(LINE_SPI_SLAVE7)
#define SPI_SELECT_SLAVE7_PORT  PAL_PORT(LINE_SPI_SLAVE7)
#define SPI_SELECT_SLAVE7_PIN   PAL_PAD(LINE_SPI_SLAVE7)
#endif

#if defined(LINE_SPI_SLAVE8)
#define SPI_SELECT_SLAVE8_PORT  PAL_PORT(LINE_SPI_SLAVE8)
#define SPI_SELECT_SLAVE8_PIN   PAL_PAD(LINE_SPI_SLAVE8)
#endif

/**
 * SDIO
 */
#if defined(LINE_SDIO_D0) && defined(LINE_SDIO_D1) && defined(LINE_SDIO_D2) && defined(LINE_SDIO_D3) && defined(LINE_SDIO_CK) && defined(LINE_SDIO_CMD)
#define SDIO_D0_PORT    PAL_PORT(LINE_SDIO_D0)
#define SDIO_D0_PIN     PAL_PAD(LINE_SDIO_D0)
#define SDIO_D1_PORT    PAL_PORT(LINE_SDIO_D1)
#define SDIO_D1_PIN     PAL_PAD(LINE_SDIO_D1)
#define SDIO_D2_PORT    PAL_PORT(LINE_SDIO_D2)
#define SDIO_D2_PIN     PAL_PAD(LINE_SDIO_D2)
#define SDIO_D3_PORT    PAL_PORT(LINE_SDIO_D3)
#define SDIO_D3_PIN     PAL_PAD(LINE_SDIO_D3)
#define SDIO_CK_PORT    PAL_PORT(LINE_SDIO_CK)
#define SDIO_CK_PIN     PAL_PAD(LINE_SDIO_CK)
#define SDIO_CMD_PORT   PAL_PORT(LINE_SDIO_CMD)
#define SDIO_CMD_PIN    PAL_PAD(LINE_SDIO_CMD)

#if defined(AF_LINE_SDIO_CMD)
#define SDIO_AF   AF_LINE_SDIO_CMD
#else
#define SDIO_AF   ((void)0)
#endif
#endif

#if defined(LINE_USB_VBUS)
#define SDLOG_USB_VBUS_PORT   PAL_PORT(LINE_USB_VBUS)
#define SDLOG_USB_VBUS_PIN    PAL_PAD(LINE_USB_VBUS)
#define SDLOG_USB_VBUS_BOOT   false
#endif

/*
 * Actuators for fixedwing
 */
 /* Default actuators driver */
#define DEFAULT_ACTUATORS "modules/actuators/actuators_pwm.h"
#define ActuatorDefaultSet(_x,_y) ActuatorPwmSet(_x,_y)
#define ActuatorsDefaultInit() ActuatorsPwmInit()
#define ActuatorsDefaultCommit() ActuatorsPwmCommit()

#endif /* ARCH_COMMON_BOARD_H */
