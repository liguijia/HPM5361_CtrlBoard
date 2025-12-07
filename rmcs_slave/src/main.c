/*
 * Copyright (c) 2024 HPMicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "board.h"
#include "hpm_gpio_drv.h"
#include <stdio.h>

uint32_t frq = 440;
int main(void) {
  board_init();
  board_init_rgbled();
  board_init_buzzer();
  board_init_pinsocket_pwmout();
  board_init_imuheater();
  board_set_rgbled_color(50.0, 25.0, 75.0);

  while (1) {
    board_set_imuheater_power(75.0f);
    board_set_buzzer_freq(false, frq);
    board_set_pinsocket_pwmout(true, 1, 1000, 50);
    // board_set_pinsocket_pwmout(true, 2, 1000, 50);
    gpio_toggle_pin(BOARD_LED_GPIO_CTRL, BOARD_LED_GPIO_INDEX,
                    BOARD_LED_GPIO_PIN);

    board_delay_ms(5000);
    gpio_toggle_pin(BOARD_LED_GPIO_CTRL, BOARD_LED_GPIO_INDEX,
                    BOARD_LED_GPIO_PIN);
    // printf("hello hpm %s \n");
    // board_set_pinsocket_pwmout(true, 1, 1000, 0);
    board_set_pinsocket_pwmout(false, 1, 1000, 75);
    board_set_buzzer_freq(true, frq);
    board_delay_ms(5000);
  }
  return 0;
}
