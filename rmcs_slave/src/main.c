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
  while (1) {
    board_set_rgbled_color(25.0, 50.0, 75.0);
    board_set_imuheater_power(25.0f);
    board_set_buzzer_freq(false, 514);
    // board_set_pinsocket_pwmout(true, 1, 1000, 50);
    // board_set_pinsocket_pwmout(true, 2, 1000, 50);

    board_delay_ms(5000);
    board_set_rgbled_color(0.0, 0.0, 0.0);
    // printf("hello hpm %s \n");
    // board_set_pinsocket_pwmout(true, 1, 1000, 0);
    // board_set_pinsocket_pwmout(false, 1, 1000, 75);
    board_set_buzzer_freq(true, 514);
    board_delay_ms(1000);
  }
  return 0;
}
