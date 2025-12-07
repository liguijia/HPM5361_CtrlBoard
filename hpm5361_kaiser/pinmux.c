/*
 * Copyright (c) 2023-2025 HPMicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "pinmux.h"
#include "hpm_gpio_drv.h"
#include "hpm_gpiom_drv.h"
#include "hpm_iomux.h"
#include "hpm_soc.h"

void init_py_pins_as_soc_gpio(void) {
  /* 把 PY00-PY05 全部切回 SoC GPIO 域 */
  HPM_PIOC->PAD[IOC_PAD_PY00].FUNC_CTL = PIOC_PY00_FUNC_CTL_SOC_GPIO_Y_00;
  HPM_PIOC->PAD[IOC_PAD_PY01].FUNC_CTL = PIOC_PY01_FUNC_CTL_SOC_GPIO_Y_01;
  HPM_PIOC->PAD[IOC_PAD_PY02].FUNC_CTL = PIOC_PY02_FUNC_CTL_SOC_GPIO_Y_02;
  HPM_PIOC->PAD[IOC_PAD_PY03].FUNC_CTL = PIOC_PY03_FUNC_CTL_SOC_GPIO_Y_03;
  HPM_PIOC->PAD[IOC_PAD_PY04].FUNC_CTL = PIOC_PY04_FUNC_CTL_SOC_GPIO_Y_04;
  HPM_PIOC->PAD[IOC_PAD_PY05].FUNC_CTL = PIOC_PY05_FUNC_CTL_SOC_GPIO_Y_05;
}

// can pins
void init_can_pins(MCAN_Type *ptr) {
  if (ptr == HPM_MCAN0) {
    HPM_IOC->PAD[IOC_PAD_PA17].FUNC_CTL = IOC_PA17_FUNC_CTL_MCAN0_RXD;
    HPM_IOC->PAD[IOC_PAD_PA16].FUNC_CTL = IOC_PA16_FUNC_CTL_MCAN0_TXD;
  } else if (ptr == HPM_MCAN1) {
    HPM_IOC->PAD[IOC_PAD_PA20].FUNC_CTL = IOC_PA20_FUNC_CTL_MCAN1_RXD;
    HPM_IOC->PAD[IOC_PAD_PA21].FUNC_CTL = IOC_PA21_FUNC_CTL_MCAN1_TXD;
  } else if (ptr == HPM_MCAN2) {
    HPM_IOC->PAD[IOC_PAD_PA25].FUNC_CTL = IOC_PA25_FUNC_CTL_MCAN2_RXD;
    HPM_IOC->PAD[IOC_PAD_PA24].FUNC_CTL = IOC_PA24_FUNC_CTL_MCAN2_TXD;
  } else if (ptr == HPM_MCAN3) {
    HPM_IOC->PAD[IOC_PAD_PA30].FUNC_CTL = IOC_PA30_FUNC_CTL_MCAN3_RXD;
    HPM_IOC->PAD[IOC_PAD_PA31].FUNC_CTL = IOC_PA31_FUNC_CTL_MCAN3_TXD;
  }
}

// uart pins
void init_uart_pins(UART_Type *ptr) {
  if (ptr == HPM_UART0) {
    HPM_IOC->PAD[IOC_PAD_PA00].FUNC_CTL = IOC_PA00_FUNC_CTL_UART0_TXD;
    HPM_IOC->PAD[IOC_PAD_PA01].FUNC_CTL = IOC_PA01_FUNC_CTL_UART0_RXD;
  } else if (ptr == HPM_UART1) {
    HPM_IOC->PAD[IOC_PAD_PY07].FUNC_CTL = IOC_PY07_FUNC_CTL_UART1_TXD;
    HPM_PIOC->PAD[IOC_PAD_PY07].FUNC_CTL = PIOC_PY07_FUNC_CTL_SOC_GPIO_Y_07;

    HPM_IOC->PAD[IOC_PAD_PY06].FUNC_CTL = IOC_PY06_FUNC_CTL_UART1_RXD;
    HPM_PIOC->PAD[IOC_PAD_PY06].FUNC_CTL = PIOC_PY06_FUNC_CTL_SOC_GPIO_Y_06;

    HPM_IOC->PAD[IOC_PAD_PY05].FUNC_CTL = IOC_PY05_FUNC_CTL_UART1_DE;
    HPM_PIOC->PAD[IOC_PAD_PY05].FUNC_CTL = PIOC_PY05_FUNC_CTL_SOC_GPIO_Y_05;
  } else if (ptr == HPM_UART2) {
    HPM_IOC->PAD[IOC_PAD_PB09].FUNC_CTL = IOC_PB09_FUNC_CTL_UART2_RXD;
    HPM_IOC->PAD[IOC_PAD_PB08].FUNC_CTL = IOC_PB08_FUNC_CTL_UART2_TXD;
  } else if (ptr == HPM_UART3) {
    HPM_IOC->PAD[IOC_PAD_PA15].FUNC_CTL = IOC_PA15_FUNC_CTL_UART3_TXD;
    HPM_IOC->PAD[IOC_PAD_PA14].FUNC_CTL = IOC_PA14_FUNC_CTL_UART3_RXD;
  } else if (ptr == HPM_UART5) {
    HPM_IOC->PAD[IOC_PAD_PA23].FUNC_CTL = IOC_PA23_FUNC_CTL_UART5_TXD;
    HPM_IOC->PAD[IOC_PAD_PA22].FUNC_CTL = IOC_PA22_FUNC_CTL_UART5_RXD;
  }
}

// spi pins
void init_spi_pins(SPI_Type *ptr) {
  if (ptr == HPM_SPI1) {
    // SPI1:W25Q128
    HPM_IOC->PAD[IOC_PAD_PA27].FUNC_CTL =
        IOC_PA27_FUNC_CTL_SPI1_SCLK | IOC_PAD_FUNC_CTL_LOOP_BACK_MASK;

    HPM_IOC->PAD[IOC_PAD_PA29].FUNC_CTL = IOC_PA29_FUNC_CTL_SPI1_MOSI;
    HPM_IOC->PAD[IOC_PAD_PA28].FUNC_CTL = IOC_PA28_FUNC_CTL_SPI1_MISO;
    // Hardware cs
    HPM_IOC->PAD[IOC_PAD_PA26].FUNC_CTL = IOC_PA26_FUNC_CTL_SPI1_CS_0;
  } else if (ptr == HPM_SPI2) {
    // SPI2:BMI088
    HPM_IOC->PAD[IOC_PAD_PB11].FUNC_CTL =
        IOC_PB11_FUNC_CTL_SPI2_SCLK | IOC_PAD_FUNC_CTL_LOOP_BACK_MASK;

    HPM_IOC->PAD[IOC_PAD_PB13].FUNC_CTL = IOC_PB13_FUNC_CTL_SPI2_MOSI;
    HPM_IOC->PAD[IOC_PAD_PB12].FUNC_CTL = IOC_PB12_FUNC_CTL_SPI2_MISO;
    // gpio as cs
    HPM_IOC->PAD[IOC_PAD_PB10].FUNC_CTL = IOC_PB10_FUNC_CTL_GPIO_B_10;
    gpiom_set_pin_controller(HPM_GPIOM, GPIOM_ASSIGN_GPIOB, 10,
                             gpiom_soc_gpio0);
    gpio_set_pin_output(HPM_GPIO0, GPIO_OE_GPIOB, 10);
    gpio_write_pin(HPM_GPIO0, GPIO_DO_GPIOB, 10, 1); // high = 释放 CS

    HPM_IOC->PAD[IOC_PAD_PB14].FUNC_CTL = IOC_PB14_FUNC_CTL_GPIO_B_14;
    gpiom_set_pin_controller(HPM_GPIOM, GPIOM_ASSIGN_GPIOB, 14,
                             gpiom_soc_gpio0);
    gpio_set_pin_output(HPM_GPIO0, GPIO_OE_GPIOB, 14);
    gpio_write_pin(HPM_GPIO0, GPIO_DO_GPIOB, 14, 1); // high = 释放 CS

  } else if (ptr == HPM_SPI3) {
    // SPI3:PinSocket Output
    HPM_IOC->PAD[IOC_PAD_PA11].FUNC_CTL =
        IOC_PA11_FUNC_CTL_SPI3_SCLK | IOC_PAD_FUNC_CTL_LOOP_BACK_MASK;
    HPM_IOC->PAD[IOC_PAD_PA12].FUNC_CTL = IOC_PA12_FUNC_CTL_SPI3_MISO;
    HPM_IOC->PAD[IOC_PAD_PA13].FUNC_CTL = IOC_PA13_FUNC_CTL_SPI3_MOSI;
    // Hardware cs
    HPM_IOC->PAD[IOC_PAD_PA10].FUNC_CTL = IOC_PA10_FUNC_CTL_SPI3_CS_0;
    HPM_IOC->PAD[IOC_PAD_PA09].FUNC_CTL = IOC_PA09_FUNC_CTL_SPI3_CS_1;
  }
}

// i2c pins
void init_i2c_pins(I2C_Type *ptr) {
  if (ptr == HPM_I2C0) {
    HPM_IOC->PAD[IOC_PAD_PA18].FUNC_CTL =
        IOC_PA18_FUNC_CTL_I2C0_SCL | IOC_PAD_FUNC_CTL_LOOP_BACK_MASK;
    HPM_IOC->PAD[IOC_PAD_PA18].PAD_CTL = IOC_PAD_PAD_CTL_OD_SET(1) |
                                         IOC_PAD_PAD_CTL_PE_SET(1) |
                                         IOC_PAD_PAD_CTL_PS_SET(1);

    HPM_IOC->PAD[IOC_PAD_PA19].FUNC_CTL = IOC_PA19_FUNC_CTL_I2C0_SDA;
    HPM_IOC->PAD[IOC_PAD_PA19].PAD_CTL = IOC_PAD_PAD_CTL_OD_SET(1) |
                                         IOC_PAD_PAD_CTL_PE_SET(1) |
                                         IOC_PAD_PAD_CTL_PS_SET(1);
  }
}

// pwm pins
void init_rgbled_pwm_pins(void) {
  HPM_IOC->PAD[IOC_PAD_PB04].FUNC_CTL = IOC_PB04_FUNC_CTL_PWM0_P_4;
  HPM_IOC->PAD[IOC_PAD_PB05].FUNC_CTL = IOC_PB05_FUNC_CTL_PWM0_P_5;
  HPM_IOC->PAD[IOC_PAD_PB06].FUNC_CTL = IOC_PB06_FUNC_CTL_PWM0_P_6;
}
void init_pinsocket_pwm_pins(void) {
  HPM_IOC->PAD[IOC_PAD_PB00].FUNC_CTL = IOC_PB00_FUNC_CTL_PWM0_P_0;
  HPM_IOC->PAD[IOC_PAD_PB01].FUNC_CTL = IOC_PB01_FUNC_CTL_PWM0_P_1;
  HPM_IOC->PAD[IOC_PAD_PB02].FUNC_CTL = IOC_PB02_FUNC_CTL_PWM0_P_2;
  HPM_IOC->PAD[IOC_PAD_PB03].FUNC_CTL = IOC_PB03_FUNC_CTL_PWM0_P_3;
}
void init_buzzer_pwm_pin(void) {
  HPM_IOC->PAD[IOC_PAD_PB07].FUNC_CTL = IOC_PB07_FUNC_CTL_PWM0_P_7;
}
void init_imuheater_pwm_pin(void) {
  /* IMU Heater: PWM1 channel5 on PY01 */
  HPM_IOC->PAD[IOC_PAD_PY01].FUNC_CTL = IOC_PY01_FUNC_CTL_PWM1_P_5;
  HPM_PIOC->PAD[IOC_PAD_PY01].FUNC_CTL = PIOC_PY01_FUNC_CTL_SOC_GPIO_Y_01;
}

// gpio pins
void init_user_key_pin(void) {
  uint32_t pad_ctl = IOC_PAD_PAD_CTL_PE_SET(1) | // pull enable
                     IOC_PAD_PAD_CTL_PS_SET(1) | // pull select - pull down
                     IOC_PAD_PAD_CTL_HYS_SET(1); // enable Schmitt trigger

  /* PY03: user key config */
  HPM_IOC->PAD[IOC_PAD_PY03].FUNC_CTL = IOC_PY03_FUNC_CTL_GPIO_Y_03;
  HPM_PIOC->PAD[IOC_PAD_PY03].FUNC_CTL = PIOC_PY03_FUNC_CTL_SOC_GPIO_Y_03;
  HPM_IOC->PAD[IOC_PAD_PY03].PAD_CTL = pad_ctl;

  /* GPIOM config */
  gpiom_set_pin_controller(HPM_GPIOM, GPIOM_ASSIGN_GPIOY, 3, gpiom_soc_gpio0);
  gpio_set_pin_input(HPM_GPIO0, GPIO_OE_GPIOY, 3);
}
void init_user_sw_pin(void) {
  uint32_t pad_ctl = IOC_PAD_PAD_CTL_PE_SET(1) | // pull enable
                     IOC_PAD_PAD_CTL_PS_SET(0) | // pull select - pull down
                     IOC_PAD_PAD_CTL_HYS_SET(1); // enable Schmitt trigger

  /* PY04: user switch config */
  HPM_IOC->PAD[IOC_PAD_PY04].FUNC_CTL = IOC_PY04_FUNC_CTL_GPIO_Y_04;
  HPM_PIOC->PAD[IOC_PAD_PY04].FUNC_CTL = PIOC_PY04_FUNC_CTL_SOC_GPIO_Y_04;
  HPM_IOC->PAD[IOC_PAD_PY04].PAD_CTL = pad_ctl;

  /* GPIOM config */
  gpiom_set_pin_controller(HPM_GPIOM, GPIOM_ASSIGN_GPIOY, 4, gpiom_soc_gpio0);
  gpio_set_pin_input(HPM_GPIO0, GPIO_OE_GPIOY, 4);
}
void init_imu_int_pins() {
  // PB15 GPIO Output - bmi088_int1_gyro
  HPM_IOC->PAD[IOC_PAD_PB15].FUNC_CTL = IOC_PB15_FUNC_CTL_GPIO_B_15;

  gpiom_set_pin_controller(HPM_GPIOM, GPIOM_ASSIGN_GPIOB, 15, gpiom_soc_gpio0);
  gpio_set_pin_output(HPM_GPIO0, GPIO_OE_GPIOB, 15);
  gpio_write_pin(HPM_GPIO0, GPIO_DO_GPIOB, 15, 0);

  // PY00 GPIO Output - bmi088_int1_accel
  HPM_IOC->PAD[IOC_PAD_PY00].FUNC_CTL = IOC_PY00_FUNC_CTL_GPIO_Y_00;
  HPM_PIOC->PAD[IOC_PAD_PY00].FUNC_CTL = PIOC_PY00_FUNC_CTL_SOC_GPIO_Y_00;

  gpiom_set_pin_controller(HPM_GPIOM, GPIOM_ASSIGN_GPIOY, 0, gpiom_soc_gpio0);
  gpio_set_pin_output(HPM_GPIO0, GPIO_OE_GPIOY, 0);
  gpio_write_pin(HPM_GPIO0, GPIO_DO_GPIOY, 0, 0);
}
// TODO Remove - hpm5300evk config，if not use hpm5300evk
void init_gpio_pins(void) {
  /* Button input: enable pull-up and schmitt trigger to reduce jitter */
  uint32_t pad_ctl = IOC_PAD_PAD_CTL_PE_SET(1) | IOC_PAD_PAD_CTL_PS_SET(1) |
                     IOC_PAD_PAD_CTL_HYS_SET(1);
  HPM_IOC->PAD[IOC_PAD_PA09].FUNC_CTL = IOC_PA09_FUNC_CTL_GPIO_A_09;
  HPM_IOC->PAD[IOC_PAD_PA09].PAD_CTL = pad_ctl;
}

void init_led_pins_as_gpio(void) {
  HPM_IOC->PAD[IOC_PAD_PA23].FUNC_CTL = IOC_PA23_FUNC_CTL_GPIO_A_23;
}
//
