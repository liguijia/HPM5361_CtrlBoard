/*
 * Copyright (c) 2023-2025 HPMicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef HPM_PINMUX_H
#define HPM_PINMUX_H

#include "hpm_soc.h"

#ifdef __cplusplus
extern "C" {
#endif

void init_py_pins_as_pgpio(void);
void init_uart_pins(UART_Type *ptr);
void init_gpio_pins(void);
void init_led_pins_as_gpio(void);

#ifdef __cplusplus
}
#endif

#endif /* HPM_PINMUX_H */
