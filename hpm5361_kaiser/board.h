/*
 * Copyright (c) 2023-2025 HPMicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef _HPM_BOARD_H
#define _HPM_BOARD_H

#include "hpm_clock_drv.h"
#include "hpm_common.h"
#include "hpm_soc.h"
#include "hpm_soc_feature.h"
#include "pinmux.h"
#include <stdio.h>
#if !defined(CONFIG_NDEBUG_CONSOLE) || !CONFIG_NDEBUG_CONSOLE
#include "hpm_debug_console.h"
#endif

#define BOARD_NAME "hpm5361_kaiser"
#define BOARD_UF2_SIGNATURE (0x0A4D5048UL)

/* Console */
#if !defined(CONFIG_NDEBUG_CONSOLE) || !CONFIG_NDEBUG_CONSOLE
#ifndef BOARD_CONSOLE_TYPE
#define BOARD_CONSOLE_TYPE CONSOLE_TYPE_UART
#endif
#if BOARD_CONSOLE_TYPE == CONSOLE_TYPE_UART
#ifndef BOARD_CONSOLE_UART_BASE
#define BOARD_CONSOLE_UART_BASE HPM_UART0
#define BOARD_CONSOLE_UART_CLK_NAME clock_uart0
#endif
#define BOARD_CONSOLE_UART_BAUDRATE (115200UL)
#endif
#endif

/* User LED / Button */
#define BOARD_LED_GPIO_CTRL HPM_GPIO0
#define BOARD_LED_GPIO_INDEX GPIO_DI_GPIOA
#define BOARD_LED_GPIO_PIN 23
#define BOARD_LED_OFF_LEVEL 1
#define BOARD_LED_ON_LEVEL 0

#define BOARD_APP_GPIO_CTRL HPM_GPIO0
#define BOARD_APP_GPIO_INDEX GPIO_DI_GPIOA
#define BOARD_APP_GPIO_PIN 9

#ifdef __cplusplus
extern "C" {
#endif

void board_init(void);
void board_init_console(void);
void board_print_banner(void);
void board_print_clock_freq(void);
void board_init_gpio_pins(void);
void board_init_led_pins(void);
void board_led_write(uint8_t state);
void board_led_toggle(void);
void board_init_clock(void);
void board_delay_us(uint32_t us);
void board_delay_ms(uint32_t ms);

#ifdef __cplusplus
}
#endif
#endif /* _HPM_BOARD_H */
