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
 * File:   3518cv100.h
 * Author: Sergey Sharshunov <s.sharshunov@gmail.com>
 *
 * Created on 28 февраля 2020 г., 14:25
 */

#ifndef _3518CV100_H_
#define _3518CV100_H_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * System Controller reference
 */

#define SC_BASE_ADDRESS   0x20050000

#define SC_IMCTRL_OFFSET    0x0008      // Interrupt mode control register
#define SC_IMSTAT_OFFSET    0x000C      // Interrupt mode status register
#define SC_XTALCTRL_OFFSET  0x0010      // Crystal oscillator control register
#define SC_PLLCTRL_OFFSET   0x0010      // PLL control register

#define SC_IMCTRL_REG       SC_BASE_ADDRESS + SC_IMCTRL_OFFSET
#define SC_IMSTAT_REG       SC_BASE_ADDRESS + SC_IMSTAT_OFFSET
#define SC_XTALCTRL_REG     SC_BASE_ADDRESS + SC_XTALCTRL_OFFSET
#define SC_PLLCTRL_REG      SC_BASE_ADDRESS + SC_PLLCTRL_OFFSET

/*
 * System Controller reference end
 */

/*
 * Watchdog reference
 */

#define WDG_BASE_ADDRESS        0x20040000

/*
 * Watchdog reference end
 */

int setup_temperature_sensor(int loop, int period_ms, int overflow, int underflow) {
#ifdef DEBUG
    printf("setup_temperature_sensor not supported\n");
#endif
    return 0;
}

float get_single_temperature(void) {
#ifdef DEBUG
    printf("get_single_temperature not supported\n");
#endif
    return 0;
}

int get_cycle_temperature(float *temperature) {
#ifdef DEBUG
    printf("get_cycle_temperature not supported\n");
#endif
    return 0;
}


#ifdef __cplusplus
}
#endif

#endif /* _3518CV100_H_ */

