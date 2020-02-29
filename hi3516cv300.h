/*
 * The MIT License
 *
 * Copyright 2020 Sergey Sharshunov <s.sharshunov@gmail.com>.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/* 
 * File:   hi3516cv300.h
 * Author: Sergey Sharshunov <s.sharshunov@gmail.com>
 *
 * Created on 28 февраля 2020 г., 12:50
 */

#ifndef HI3516CV300_H
#define HI3516CV300_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Peripheral Control Registers reference
 */

#define PERIPHERAL_CONTROL_BASE_ADDRESS      0x12030000

#define MISC_CTRL0_OFFSET 0x0000 // MSIC function select register 0 3-65
#define MISC_CTRL3_OFFSET 0x000C // RAM Retention control register 0 3-67
#define MISC_CTRL5_OFFSET 0x0014 // SYS bus control register 0 3-68
#define MISC_CTRL6_OFFSET 0x0018 // SYS bus control register 1 3-69
#define MISC_CTRL7_OFFSET 0x001C // SYS bus control register 2 3-70
#define MISC_CTRL8_OFFSET 0x0020 // SYS bus control register 3 3-71
#define MISC_CTRL9_OFFSET 0x0024 // Media bus control register 0 3-72
#define MISC_CTRL10_OFFSET 0x0028 // Media bus control register 1 3-73
#define MISC_CTRL12_OFFSET 0x0030 // Media bus control register 3 3-74
#define MISC_CTRL13_OFFSET 0x0034 // VIVO bus control register 0 3-75
#define MISC_CTRL14_OFFSET 0x0038 // VIVO bus control register 1 3-76
#define MISC_CTRL16_OFFSET 0x0040 // VIVO bus control register 3 3-77
#define MISC_CTRL17_OFFSET 0x0044 // DDR_QoS control register 0 3-78
#define MISC_CTRL18_OFFSET 0x0048 // DDR_QoS control register 1 3-78
#define MISC_CTRL19_OFFSET 0x004C // DDR_QoS control register 2 3-79
#define MISC_CTRL20_OFFSET 0x0050 // DDR_QoS control register 3 3-80
#define MISC_CTRL21_OFFSET 0x0054 // DDR_QoS control register 4 3-80
#define MISC_CTRL22_OFFSET 0x0058 // DDR_QoS control register 5 3-81
#define MISC_CTRL23_OFFSET 0x005C // USB2.0 control register 0 3-82
#define MISC_CTRL24_OFFSET 0x0060 // USB2.0 control register 1 3-84
#define MISC_CTRL25_OFFSET 0x0064 // USB2.0 control register 2 3-85
#define MISC_CTRL30_OFFSET 0x0078 // SVB control register 3-86
#define MISC_CTRL31_OFFSET 0x007C // Core high performance monitor (HPM) control register 0 3-87
#define MISC_CTRL32_OFFSET 0x0080 // Core HPM control register 1 3-88
#define MISC_CTRL33_OFFSET 0x0084 // Core HPM status register 0 3-89
#define MISC_CTRL34_OFFSET 0x0088 // Core HPM status register 1 3-90
#define MISC_CTRL35_OFFSET 0x008C // Media HPM control register 0 3-90
#define MISC_CTRL36_OFFSET 0x0090 // Media HPM control register 1 3-91
#define MISC_CTRL37_OFFSET 0x0094 // Media HPM status register 0 3-92
#define MISC_CTRL38_OFFSET 0x0098 // Media HPM status register 1 3-93
#define MISC_CTRL39_OFFSET 0x009C // Temperature sensor (T-Sensor) control register 3-93
#define MISC_CTRL40_OFFSET 0x00A0 // T-sensor status register 3-94
#define MISC_CTRL41_OFFSET 0x00A4 // T-sensor temperature record register 0 3-95
#define MISC_CTRL42_OFFSET 0x00A8 // T-sensor temperature record register 1 3-96
#define MISC_CTRL43_OFFSET 0x00AC // T-sensor temperature record register 2 3-96
#define MISC_CTRL44_OFFSET 0x00B0 // T-sensor temperature record register 3 3-97
#define MISC_CTRL47_OFFSET 0x00BC // Update mode clear register 3-97

#define MISC_CTRL0_REG      PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL0_OFFSET
#define MISC_CTRL3_REG      PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL3_OFFSET
#define MISC_CTRL5_REG      PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL5_OFFSET
#define MISC_CTRL6_REG      PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL6_OFFSET
#define MISC_CTRL7_REG      PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL7_OFFSET
#define MISC_CTRL8_REG      PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL8_OFFSET
#define MISC_CTRL9_REG      PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL9_OFFSET
#define MISC_CTRL10_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL10_OFFSET
#define MISC_CTRL12_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL12_OFFSET
#define MISC_CTRL13_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL13_OFFSET
#define MISC_CTRL14_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL14_OFFSET
#define MISC_CTRL16_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL16_OFFSET
#define MISC_CTRL17_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL17_OFFSET
#define MISC_CTRL18_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL18_OFFSET
#define MISC_CTRL19_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL19_OFFSET
#define MISC_CTRL20_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL20_OFFSET
#define MISC_CTRL21_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL21_OFFSET
#define MISC_CTRL22_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL22_OFFSET
#define MISC_CTRL23_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL23_OFFSET
#define MISC_CTRL24_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL24_OFFSET
#define MISC_CTRL25_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL25_OFFSET
#define MISC_CTRL30_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL30_OFFSET
#define MISC_CTRL31_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL31_OFFSET
#define MISC_CTRL32_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL32_OFFSET
#define MISC_CTRL33_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL33_OFFSET
#define MISC_CTRL34_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL34_OFFSET
#define MISC_CTRL35_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL35_OFFSET
#define MISC_CTRL36_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL36_OFFSET
#define MISC_CTRL37_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL37_OFFSET
#define MISC_CTRL38_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL38_OFFSET
#define MISC_CTRL39_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL39_OFFSET
#define MISC_CTRL40_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL40_OFFSET
#define MISC_CTRL41_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL41_OFFSET
#define MISC_CTRL42_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL42_OFFSET
#define MISC_CTRL43_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL43_OFFSET
#define MISC_CTRL44_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL44_OFFSET
#define MISC_CTRL47_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL47_OFFSET

/*
 * Peripheral Control Registers reference end
 */

/*
 * Peripheral Control HAL api
 */

#define TEMPERATURE(x) ((((x * 125.0) / 806) * 165) - 40)
    
int setup_temperature_sensor(int loop, int period_ms, int overflow, int underflow) {
    // Capture cycle = tsensor_monitor_period x 2, so if you want 10 ms set period_ms = 5;
    
    unsigned request_value = 0x00;
    if (loop == 1) {
        request_value = period_ms << 20;
        request_value ^= 1 << 30;
        request_value ^= 1 << 31;
#ifdef DEBUG
        printf("request_value     0x%08X:\n", request_value);
#endif
    } else if (loop == 0) {
        request_value ^= 1 << 31;
    } else {
#ifdef DEBUG
        printf("loop parameter invalid\n");
#endif
        return -1;
    }
    himm_set(MISC_CTRL39_REG, request_value);
    return 0;
}

float get_single_temperature(void) {
    unsigned MASK = 0x3FF;
    HI_U32 CTRL41 = himm_get(MISC_CTRL41_REG);
    CTRL41 &= MASK ;
    float temperature = TEMPERATURE(CTRL41);
    return temperature;
}

int get_cycle_temperature(float *temperature) {
    unsigned MASK0 = 0x3FF;
    unsigned MASK1 = 0x3FF0000;
    HI_U32 CTRL41 = himm_get(MISC_CTRL41_REG);
    HI_U32 CTRL42 = himm_get(MISC_CTRL42_REG);
    HI_U32 CTRL43 = himm_get(MISC_CTRL43_REG);
    HI_U32 CTRL44 = himm_get(MISC_CTRL44_REG);
    
    temperature[0] = TEMPERATURE((CTRL41 & MASK0));
    temperature[1] = TEMPERATURE(((CTRL41 & MASK1) >> 16));
    temperature[2] = TEMPERATURE((CTRL42 & MASK0));
    temperature[3] = TEMPERATURE(((CTRL42 & MASK1) >> 16));
    temperature[4] = TEMPERATURE((CTRL43 & MASK0));
    temperature[5] = TEMPERATURE(((CTRL43 & MASK1) >> 16));
    temperature[6] = TEMPERATURE((CTRL44 & MASK0));
    temperature[7] = TEMPERATURE(((CTRL44 & MASK1) >> 16));
    return 0;
}

/*
 * Peripheral Control HAL api
 */

#ifdef __cplusplus
}
#endif

#endif /* HI3516CV300_H */

