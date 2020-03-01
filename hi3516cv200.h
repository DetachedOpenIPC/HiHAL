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
 * File:   hi3516cv200.h
 * Author: Sergey Sharshunov <s.sharshunov@gmail.com>
 *
 * Created on 28 февраля 2020 г., 22:16
 */

#ifndef HI3516CV200_H
#define HI3516CV200_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * System Controller reference
 */

#define SC_BASE_ADDRESS   0x20050000

#define SOLFINT_OFFSET      0x001C      // Software interrupt register

#define SOLFINT_REG      SC_BASE_ADDRESS + SOLFINT_OFFSET

/*
 * System Controller reference end
 */

/*
 * Peripheral Control Registers reference
 */

#define PERIPHERAL_CONTROL_BASE_ADDRESS      0x20120000

#define MISC_CTRL1_OFFSET 0x0004 // MISC register 1
#define MISC_CTRL2_OFFSET 0x0008 // MISC register 2
#define MISC_CTRL3_OFFSET 0x000C // MISC register 3
#define MISC_CTRL4_OFFSET 0x0010 // MISC register 4
#define MISC_CTRL6_OFFSET 0x0018 // MISC register 6
#define MISC_CTRL7_OFFSET 0x001C // MISC register 7
#define MISC_CTRL8_OFFSET 0x0020 // MISC register 8
#define MISC_CTRL9_OFFSET 0x0024 // MISC register 9
#define MISC_CTRL11_OFFSET 0x002C // MISC register 11
#define MISC_CTRL14_OFFSET 0x0038 // MISC register 14
#define MISC_CTRL15_OFFSET 0x003C // MISC register 15
#define MISC_CTRL16_OFFSET 0x0040 // MISC register 16
#define MISC_CTRL18_OFFSET 0x0048 // MISC register 18
#define MISC_CTRL22_OFFSET 0x0058 // MISC register 22
#define MISC_CTRL23_OFFSET 0x005C // MISC register 23
#define MISC_CTRL24_OFFSET 0x0060 // MISC register 24
#define MISC_CTRL25_OFFSET 0x0064 // MISC register 25
#define MISC_CTRL26_OFFSET 0x0068 // MISC register 26
#define MISC_CTRL27_OFFSET 0x006C // MISC register 27
#define MISC_CTRL30_OFFSET 0x0078 // MISC register 30
#define MISC_CTRL49_OFFSET 0x00C4 // Audio CODEC (ACODEC) control register 6
#define MISC_CTRL50_OFFSET 0x00C8 // ACODEC control register 0
#define MISC_CTRL51_OFFSET 0x00CC // ACODEC control register 1
#define MISC_CTRL52_OFFSET 0x00D0 // ACODEC control register 2
#define MISC_CTRL53_OFFSET 0x00D4 // ACODEC control register 3
#define MISC_CTRL54_OFFSET 0x00D8 // ACODEC control register 4
#define MISC_CTRL56_OFFSET 0x00E0 // MISC register 56
#define MISC_CTRL60_OFFSET 0x00F0 // MISC register 60
#define MISC_CTRL61_OFFSET 0x00F4 // MISC register 61
#define MISC_CTRL80_OFFSET 0x0140 // MISC register 80
#define MISC_CTRL81_OFFSET 0x0144 // MISC register 81


#define MISC_CTRL1_REG      PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL1_OFFSET
#define MISC_CTRL2_REG      PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL2_OFFSET
#define MISC_CTRL3_REG      PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL3_OFFSET
#define MISC_CTRL4_REG      PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL4_OFFSET
#define MISC_CTRL6_REG      PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL6_OFFSET
#define MISC_CTRL7_REG      PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL7_OFFSET
#define MISC_CTRL8_REG      PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL8_OFFSET
#define MISC_CTRL9_REG      PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL9_OFFSET
#define MISC_CTRL11_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL11_OFFSET
#define MISC_CTRL14_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL14_OFFSET
#define MISC_CTRL15_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL15_OFFSET
#define MISC_CTRL16_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL16_OFFSET
#define MISC_CTRL18_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL18_OFFSET
#define MISC_CTRL22_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL22_OFFSET
#define MISC_CTRL23_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL23_OFFSET
#define MISC_CTRL24_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL24_OFFSET
#define MISC_CTRL25_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL25_OFFSET
#define MISC_CTRL26_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL26_OFFSET
#define MISC_CTRL27_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL27_OFFSET
#define MISC_CTRL30_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL30_OFFSET
#define MISC_CTRL49_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL49_OFFSET
#define MISC_CTRL50_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL50_OFFSET
#define MISC_CTRL51_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL51_OFFSET
#define MISC_CTRL52_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL52_OFFSET
#define MISC_CTRL53_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL53_OFFSET
#define MISC_CTRL54_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL54_OFFSET
#define MISC_CTRL56_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL56_OFFSET
#define MISC_CTRL60_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL60_OFFSET
#define MISC_CTRL61_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL61_OFFSET
#define MISC_CTRL80_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL80_OFFSET
#define MISC_CTRL81_REG     PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL81_OFFSET

/*
 * Peripheral Control Registers reference end
 */

/*
 * Power management controller (PMC) Registers reference end
 */

#define PMC_BASE_ADDRESS      0x20270000

#define PERI_PMC0_OFFSET  0x0000 // PMC register 0 3-163
#define PERI_PMC4_OFFSET  0x0010 // PMC register 4 3-163
#define PERI_PMC5_OFFSET  0x0014 // PMC register 5 3-164
#define PERI_PMC10_OFFSET 0x0028 // Core HPM control register 1 3-165
#define PERI_PMC11_OFFSET 0x002C // Core HPM status register 1 3-166
#define PERI_PMC12_OFFSET 0x0030 // Core HPM status register 2 3-167
#define PERI_PMC13_OFFSET 0x0034 // Core HPM control register 2 3-167
#define PERI_PMC31_OFFSET 0x007C // HPM control register (fine 2) 3-168
#define PERI_PMC68_OFFSET 0x0110 // PMC register 68 3-168
#define PERI_PMC69_OFFSET 0x0114 // PMC register 69 3-169
#define PERI_PMC70_OFFSET 0x0118 // PMC register 70 3-170
#define PERI_PMC71_OFFSET 0x011C // PMC register 71 3-170

#define PERI_PMC0_REG      PMC_BASE_ADDRESS + PERI_PMC0_OFFSET
#define PERI_PMC4_REG      PMC_BASE_ADDRESS + PERI_PMC4_OFFSET
#define PERI_PMC5_REG      PMC_BASE_ADDRESS + PERI_PMC5_OFFSET
#define PERI_PMC10_REG     PMC_BASE_ADDRESS + PERI_PMC10_OFFSET
#define PERI_PMC11_REG     PMC_BASE_ADDRESS + PERI_PMC11_OFFSET
#define PERI_PMC12_REG     PMC_BASE_ADDRESS + PERI_PMC12_OFFSET
#define PERI_PMC13_REG     PMC_BASE_ADDRESS + PERI_PMC13_OFFSET
#define PERI_PMC31_REG     PMC_BASE_ADDRESS + PERI_PMC31_OFFSET
#define PERI_PMC68_REG     PMC_BASE_ADDRESS + PERI_PMC68_OFFSET
#define PERI_PMC69_REG     PMC_BASE_ADDRESS + PERI_PMC69_OFFSET
#define PERI_PMC70_REG     PMC_BASE_ADDRESS + PERI_PMC70_OFFSET
#define PERI_PMC71_REG     PMC_BASE_ADDRESS + PERI_PMC71_OFFSET

/*
 * Power management controller (PMC) Registers reference end
 */

/*
 * Watchdog reference
 */

#define WDG_BASE_ADDRESS        0x20040000

/*
 * Watchdog reference end
 */

/*
 * Peripheral Control HAL api
 */

#define TEMPERATURE(x) (((x * 180.0) / 256) - 40)

int setup_temperature_sensor(int loop, int period_ms, int overflow, int underflow) {
    // Capture cycle = tsensor_monitor_period x 2, so if you want 10 ms set period_ms = 5;
    
    unsigned request_value = 0x00;
    if (loop == 1) {
        request_value = period_ms << 16;
        request_value ^= 1 << 29;
        request_value ^= 1 << 30;
#ifdef DEBUG
        printf("request_value     0x%08X:\n", request_value);
#endif
    } else if (loop == 0) {
        request_value ^= 1 << 30;
    } else {
#ifdef DEBUG
        printf("loop parameter invalid\n");
#endif
        return -1;
    }
    himm_set(PERI_PMC68_REG, request_value);
    return 0;
}

float get_single_temperature(void) {
    unsigned MASK = 0xFF;
    HI_U32 PMC69 = himm_get(PERI_PMC69_REG);
    float temperature = TEMPERATURE((PMC69 & MASK));
    return temperature;
}

int get_cycle_temperature(float *temperature) {
    unsigned MASK0 = 0xFF;
    unsigned MASK1 = 0xFF00;
    unsigned MASK2 = 0xFF0000;
    unsigned MASK3 = 0xFF000000;
    HI_U32 PMC69 = himm_get(PERI_PMC69_REG);
    HI_U32 PMC70 = himm_get(PERI_PMC70_REG);
    
    temperature[0] = TEMPERATURE((PMC69 & MASK0));
    temperature[1] = TEMPERATURE(((PMC69 & MASK1) >> 8));
    temperature[2] = TEMPERATURE(((PMC69 & MASK2) >> 16));
    temperature[3] = TEMPERATURE(((PMC69 & MASK3) >> 24));
    temperature[4] = TEMPERATURE((PMC70 & MASK0));
    temperature[5] = TEMPERATURE(((PMC70 & MASK1) >> 8));
    temperature[6] = TEMPERATURE(((PMC70 & MASK2) >> 16));
    temperature[7] = TEMPERATURE(((PMC70 & MASK3) >> 24));
    
    return 0;
}

/*
 * Peripheral Control HAL api
 */



#ifdef __cplusplus
}
#endif

#endif /* HI3516CV200_H */

