/*
 * Copyright (c) 2024 HPMicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "board.h"
#include "hpm_gpio_drv.h"
#include <stdio.h>

int main(void) {
  board_init();
  board_init_led_pins();
  while (1) {
    gpio_toggle_pin(BOARD_LED_GPIO_CTRL, BOARD_LED_GPIO_INDEX,
                    BOARD_LED_GPIO_PIN);
    board_delay_ms(500);
    gpio_toggle_pin(BOARD_LED_GPIO_CTRL, BOARD_LED_GPIO_INDEX,
                    BOARD_LED_GPIO_PIN);
    board_delay_ms(500);
  }
  return 0;
}
