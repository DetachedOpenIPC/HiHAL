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
 * File:   hi3516ev200.h
 * Author: Sergey Sharshunov <s.sharshunov@gmail.com>
 *
 * Created on 29 февраля 2020 г., 15:53
 */

#ifndef HI3516EV200_H
#define HI3516EV200_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * System Controller reference end
 */

#define SC_BASE_ADDRESS                     0x12020000 

#define SC_VERSIONID_OFFSET     0x0018       // Version ID register 3-46
#define SOFTINT_OFFSET          0x001C       // Software interrupt register 3-46
#define SOFTTYPE_OFFSET         0x0020       // Software interrupt vector register 3-47
#define OTP_PO_BIT2_OFFSET      0x0088       // OTP power-on read back register 2 3-47
#define DIE_ID0_OFFSET          0x0400       // Die ID0 register 3-49
#define DIE_ID1_OFFSET          0x0404       // Die ID1 register 3-49
#define DIE_ID2_OFFSET          0x0408       // Die ID2 register 3-49
#define DIE_ID3_OFFSET          0x040C       // Die ID3 register 3-49
#define DIE_ID4_OFFSET          0x0410       // Die ID4 register 3-50
#define DIE_ID5_OFFSET          0x0414       // Die ID5 register 3-50
#define CHIP_ID_OFFSET          0x0EE0       // Chip ID register. 3-50
#define VENDOR_ID_OFFSET        0x0EEC       // Vendor ID register. 3-50

#define SC_VERSIONID_REG        PERIPHERAL_CONTROL_BASE_ADDRESS + SC_VERSIONID_OFFSET
#define SOFTINT_REG             PERIPHERAL_CONTROL_BASE_ADDRESS + SOFTINT_OFFSET
#define SOFTTYPE_REG            PERIPHERAL_CONTROL_BASE_ADDRESS + SOFTTYPE_OFFSET
#define OTP_PO_BIT2_REG         PERIPHERAL_CONTROL_BASE_ADDRESS + OTP_PO_BIT2_OFFSET
#define DIE_ID0_REG             PERIPHERAL_CONTROL_BASE_ADDRESS + DIE_ID0_OFFSET
#define DIE_ID1_REG             PERIPHERAL_CONTROL_BASE_ADDRESS + DIE_ID1_OFFSET
#define DIE_ID2_REG             PERIPHERAL_CONTROL_BASE_ADDRESS + DIE_ID2_OFFSET
#define DIE_ID3_REG             PERIPHERAL_CONTROL_BASE_ADDRESS + DIE_ID3_OFFSET
#define DIE_ID4_REG             PERIPHERAL_CONTROL_BASE_ADDRESS + DIE_ID4_OFFSET
#define DIE_ID5_REG             PERIPHERAL_CONTROL_BASE_ADDRESS + DIE_ID5_OFFSET
#define CHIP_ID_REG             PERIPHERAL_CONTROL_BASE_ADDRESS + CHIP_ID_OFFSET
#define VENDOR_ID_REG           PERIPHERAL_CONTROL_BASE_ADDRESS + VENDOR_ID_OFFSET

/*
 * System Controller reference
 */

/*
 * Peripheral Control Registers reference
 */

#define PERIPHERAL_CONTROL_BASE_ADDRESS     SC_BASE_ADDRESS

#define MISC_CTRL0_OFFSET       0x8000 // MSIC function select register 0. 3-51
#define MISC_CTRL1_OFFSET       0x8004 // USB PHY trim parameter register 3-52
#define MISC_CTRL3_OFFSET       0x800C // CPU control register 1. 3-52
#define MISC_CTRL4_OFFSET       0x8010 // MISC function select register 4 3-53
#define MISC_CTRL6_OFFSET       0x8018 // VICAP mode control register 1. 3-53
#define MISC_CTRL7_OFFSET       0x801C // USB 2.0 control register 0 3-54
#define MISC_CTRL8_OFFSET       0x8020 // Embedded FE PHY control register 0 3-55
#define MISC_CTRL9_OFFSET       0x8024 // Embedded FE PHY control register 1 3-55
#define MISC_CTRL28_OFFSET      0x8070 // Bus priority control register 15 3-57
#define MISC_CTRL32_OFFSET      0x8080 // MDDRC W QOS register 0 3-57
#define MISC_CTRL33_OFFSET      0x8084 // MDDRC W QOS register 1 3-58
#define MISC_CTRL34_OFFSET      0x8088 // MDDRC W QOS register 2 3-59
#define MISC_CTRL36_OFFSET      0x8090 // MDDRC R QOS register 0 3-59
#define MISC_CTRL37_OFFSET      0x8094 // MDDRC R QOS register 1 3-59
#define MISC_CTRL38_OFFSET      0x8098 // MDDRC R QOS register 2 3-60
#define MISC_CTRL44_OFFSET      0x80B0 // SVB control register 3-60
#define MISC_CTRL45_OFFSET      0x80B4 // Temperature sensor (T-Sensor) control register 3-61
#define MISC_CTRL46_OFFSET      0x80B8 // T-Sensor status register 3-62
#define MISC_CTRL47_OFFSET      0x80BC // T-Sensor temperature record register 0 3-62
#define MISC_CTRL48_OFFSET      0x80C0 // T-Sensor temperature record register 1 3-62
#define MISC_CTRL49_OFFSET      0x80C4 // T-Sensor temperature record register 2 3-63
#define MISC_CTRL50_OFFSET      0x80C8 // T-Sensor temperature record register 3 3-63
#define MISC_CTRL52_OFFSET      0x80D0 // MISC_CTRL52 CPU HPM control register 0 3-63
#define MISC_CTRL53_OFFSET      0x80D4 // MISC_CTRL53 CPU HPM control register 1 3-64
#define MISC_CTRL54_OFFSET      0x80D8 // MISC_CTRL54 CPU HPM status register 0 3-64
#define MISC_CTRL55_OFFSET      0x80DC // MISC_CTRL55 CPU HPM status register 1 3-65
#define MISC_CTRL61_OFFSET      0x80F4 // MISC_CTRL61 CORE SHPM control register 3-65
#define MISC_CTRL62_OFFSET      0x80F8 // MISC_CTRL62 Stopwatch control register 3-65
#define MISC_CTRL63_OFFSET      0x80FC // MISC_CTRL63 Stopwatch timer value register 3-66

#define MISC_CTRL0_REG          PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL0_OFFSET
#define MISC_CTRL1_REG          PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL1_OFFSET
#define MISC_CTRL3_REG          PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL3_OFFSET
#define MISC_CTRL4_REG          PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL4_OFFSET
#define MISC_CTRL6_REG          PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL6_OFFSET
#define MISC_CTRL7_REG          PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL7_OFFSET
#define MISC_CTRL8_REG          PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL8_OFFSET
#define MISC_CTRL9_REG          PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL9_OFFSET
#define MISC_CTRL28_REG         PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL28_OFFSET
#define MISC_CTRL32_REG         PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL32_OFFSET
#define MISC_CTRL33_REG         PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL33_OFFSET
#define MISC_CTRL34_REG         PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL34_OFFSET
#define MISC_CTRL36_REG         PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL36_OFFSET
#define MISC_CTRL37_REG         PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL37_OFFSET
#define MISC_CTRL38_REG         PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL38_OFFSET
#define MISC_CTRL44_REG         PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL44_OFFSET
#define MISC_CTRL45_REG         PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL45_OFFSET
#define MISC_CTRL46_REG         PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL46_OFFSET
#define MISC_CTRL47_REG         PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL47_OFFSET
#define MISC_CTRL48_REG         PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL48_OFFSET
#define MISC_CTRL49_REG         PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL49_OFFSET
#define MISC_CTRL50_REG         PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL50_OFFSET
#define MISC_CTRL52_REG         PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL52_OFFSET
#define MISC_CTRL53_REG         PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL53_OFFSET
#define MISC_CTRL54_REG         PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL54_OFFSET
#define MISC_CTRL55_REG         PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL55_OFFSET
#define MISC_CTRL61_REG         PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL61_OFFSET
#define MISC_CTRL62_REG         PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL62_OFFSET
#define MISC_CTRL63_REG         PERIPHERAL_CONTROL_BASE_ADDRESS + MISC_CTRL63_OFFSET

/*
 * Peripheral Control Registers reference end
 */

/*
 * Watchdog reference
 */

#define WDG_BASE_ADDRESS        0x12030000

/*
 * Watchdog reference end
 */

/*
 * Power management controller (PMC) Registers reference
 */

#define PMC_BASE_ADDRESS      0x120F0000

#define PWR_CTRL0_OFFSET            0x0000 // PWR control register 0 3-127
#define PWR_CTRL1_OFFSET            0x0004 // PWR control register 1 3-128
#define PWR_STATUS_OFFSET           0x0008 // PWR status register 3-128
#define PWR_WAKEUP_OUT_CRTL_OFFSET  0x0010 // PWR_WAKEUP output control register 3-129
#define PWR_SEQ_CRTL_OFFSET         0x0014 // PWR_SEQ pin control register 3-129
#define PWR_STARUP_CRTL_OFFSET      0x001C // PWR_STARUP pin control register 3-130
#define PWR_WAKEUP_CRTL_OFFSET      0x0020 // PWR_WAKEUP pin control register 3-130
#define PWR_EN_CRTL_OFFSET          0x0024 // PWR_EN pin control register 3-131
#define PWR_USER_REG0_OFFSET        0x0048 // PWR user register 0 3-131
#define PWR_USER_REG1_OFFSET        0x004C // PWR user register 1 3-131
#define PWR_USER_REG2_OFFSET        0x0050 // PWR user register 2 3-132
#define PWR_USER_REG3_OFFSET        0x0054 // PWR user register 3 3-132

#define PWR_CTRL0_REG                PMC_BASE_ADDRESS + PWR_CTRL0_OFFSET
#define PWR_CTRL1_REG                PMC_BASE_ADDRESS + PWR_CTRL1_OFFSET
#define PWR_STATUS_REG               PMC_BASE_ADDRESS + PWR_STATUS_OFFSET
#define PWR_WAKEUP_OUT_CRTL_REG      PMC_BASE_ADDRESS + PWR_WAKEUP_OUT_CRTL_OFFSET
#define PWR_SEQ_CRTL_REG             PMC_BASE_ADDRESS + PWR_SEQ_CRTL_OFFSET
#define PWR_STARUP_CRTL_REG          PMC_BASE_ADDRESS + PWR_STARUP_CRTL_OFFSET
#define PWR_WAKEUP_CRTL_REG          PMC_BASE_ADDRESS + PWR_WAKEUP_CRTL_OFFSET
#define PWR_EN_CRTL_REG              PMC_BASE_ADDRESS + PWR_EN_CRTL_OFFSET
#define PWR_USER_REG0_REG            PMC_BASE_ADDRESS + PWR_USER_REG0_OFFSET
#define PWR_USER_REG1_REG            PMC_BASE_ADDRESS + PWR_USER_REG1_OFFSET
#define PWR_USER_REG2_REG            PMC_BASE_ADDRESS + PWR_USER_REG2_OFFSET
#define PWR_USER_REG3_REG            PMC_BASE_ADDRESS + PWR_USER_REG3_OFFSET
  
/*
 * Power management controller (PMC) Registers reference end
 */

/*
 * Peripheral Control HAL api
 */

#define TEMPERATURE(x) ((((x - 117.0) / 798) * 165) - 40)

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
    himm_set(MISC_CTRL45_REG, request_value);
    return 0;
}

float get_single_temperature(void) {
    unsigned MASK = 0x3FF;
    HI_U32 CTRL47 = himm_get(MISC_CTRL47_REG);
    float temperature = TEMPERATURE((CTRL47 & MASK));
    return temperature;
}

int get_cycle_temperature(float *temperature) {
    unsigned MASK0 = 0x3FF;
    unsigned MASK1 = 0x3FF0000;
    HI_U32 CTRL47 = himm_get(MISC_CTRL47_REG);
    HI_U32 CTRL48 = himm_get(MISC_CTRL48_REG);
    HI_U32 CTRL49 = himm_get(MISC_CTRL49_REG);
    HI_U32 CTRL50 = himm_get(MISC_CTRL50_REG);
    
    temperature[0] = TEMPERATURE((CTRL47 & MASK0));
    temperature[1] = TEMPERATURE(((CTRL47 & MASK1) >> 16));
    temperature[2] = TEMPERATURE((CTRL48 & MASK0));
    temperature[3] = TEMPERATURE(((CTRL48 & MASK1) >> 16));
    temperature[4] = TEMPERATURE((CTRL49 & MASK0));
    temperature[5] = TEMPERATURE(((CTRL49 & MASK1) >> 16));
    temperature[6] = TEMPERATURE((CTRL50 & MASK0));
    temperature[7] = TEMPERATURE(((CTRL50 & MASK1) >> 16));
    return 0;
}

/*
 * Peripheral Control HAL api
 */


#ifdef __cplusplus
}
#endif

#endif /* HI3516EV200_H */

