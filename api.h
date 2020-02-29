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
 * File:   api.h
 * Author: Sergey Sharshunov <s.sharshunov@gmail.com>
 *
 * Created on 26 февраля 2020 г., 18:34
 */

#ifndef API_H
#define API_H

#ifdef __cplusplus
extern "C" {
#endif

#include "hi_type.h"
#include "util.h"

#define clear() printf("\033[H\033[J")
    
//#define HISI_CPU_MODEL_3518CV100
#define HISI_CPU_MODEL_3516CV300
//#define HISI_CPU_MODEL_3516CV200

#define HISI_CPU_NAME "3518CV100"

#ifdef HISI_CPU_MODEL_3518CV100
    #include "hi3518cv100.h"    
#endif

#ifdef HISI_CPU_MODEL_3516CV300
    #include "hi3516cv300.h"    
#endif

#ifdef HISI_CPU_MODEL_3516CV200
    #include "hi3516cv200.h"    
#endif

#ifndef MHZ
#define MHZ (1000*1000)
#endif

#define HEX_SIZE                          8
#define MAX_REG_BUF         HEX_SIZE    + 2
#define MAX_ADDRESS_REG_BUF MAX_REG_BUF + 2
    
#define REG_UNLOCK_VALUE 0x1ACCE551
#define REG_LOCK_ANY_VALUE 0xFFFFFFFF

    
/*
 * Watchdog reference
 * Support all chips
 */

#define WDG_BASE_ADDRESS   0x20040000

#define WDG_LOAD_OFFSET    0x0000       // Initial count value register
#define WDG_VALUE_OFFSET   0x0004       // Current count value register
#define WDG_CONTROL_OFFSET 0x0008       // Control register
#define WDG_INTCLR_OFFSET  0x000C       // Interrupt clear register
#define WDG_RIS_OFFSET     0x0010       // Raw interrupt register
#define WDG_MIS_OFFSET     0x0014       // Masked interrupt status register
#define WDG_LOCK_OFFSET    0x0C00       // Lock register
    
#define WDG_LOAD_REG     WDG_BASE_ADDRESS + WDG_LOAD_OFFSET
#define WDG_VALUE_REG    WDG_BASE_ADDRESS + WDG_VALUE_OFFSET
#define WDG_CONTROL_REG  WDG_BASE_ADDRESS + WDG_CONTROL_OFFSET
#define WDG_INTCLR_REG   WDG_BASE_ADDRESS + WDG_INTCLR_OFFSET
#define WDG_RIS_REG      WDG_BASE_ADDRESS + WDG_RIS_OFFSET
#define WDG_MIS_REG      WDG_BASE_ADDRESS + WDG_MIS_OFFSET
#define WDG_LOCK_REG     WDG_BASE_ADDRESS + WDG_LOCK_OFFSET
    
/*
 Watchdog reference end
 */
    
/*
 * System Controller reference
 */

#define SC_BASE_ADDRESS   0x20050000

#define SC_CTRL_OFFSET      0x000       // System control register
#define SC_SYSRES_OFFSET    0x004       // System soft reset register
#define SOLFINT_OFFSET      0x001C      // Software interrupt register
#define SC_LOCKEN_OFFSET    0x0044      // Key register lock register
#define SYSSTAT_OFFSET      0x008C      // System status register (PLL_LOCK)
#define SCSYSID0_OFFSET     0xEE0       // Chip ID register 0
#define SCSYSID1_OFFSET     0xEE4       // Chip ID register 1
#define SCSYSID2_OFFSET     0xEE8       // Chip ID register 2
#define SCSYSID3_OFFSET     0xEEC       // Chip ID register 3
    
#define SC_CTRL_REG     SC_BASE_ADDRESS + SC_CTRL_OFFSET
#define SC_SYSRES_REG   SC_BASE_ADDRESS + SC_SYSRES_OFFSET
#define SOLFINT_REG     SC_BASE_ADDRESS + SOLFINT_OFFSET
#define SC_LOCKEN_REG   SC_BASE_ADDRESS + SC_LOCKEN_OFFSET
#define SYSSTAT_REG     SC_BASE_ADDRESS + SYSSTAT_OFFSET
#define SCSYSID0_REG    SC_BASE_ADDRESS + SCSYSID0_OFFSET
#define SCSYSID1_REG    SC_BASE_ADDRESS + SCSYSID1_OFFSET
#define SCSYSID2_REG    SC_BASE_ADDRESS + SCSYSID2_OFFSET
#define SCSYSID3_REG    SC_BASE_ADDRESS + SCSYSID3_OFFSET
       
/*
 * System Controller reference end
 */

/*
 * RTC reference
 */
    
#define RTC_APB_BASE_ADDRESS   0x20060000
    
#define SPI_CLK_DIV_OFFSET  0x0000      // SPI clock ratio register
#define SPI_RW_OFFSET       0x0004      // SPI read/write register
#define CONVER_T_OFFSET     0x0080      // Temperature sensor measurement control register
#define CRC_EN_OFFSET       0x0084      // Temperature sensor measurement CRC check enable register
#define INT_MASK_OFFSET     0x0088      // Temperature sensor measurement interrupt mask register
#define INT_CLEAR_OFFSET    0x008C      // Temperature sensor measurement interrupt clear register
#define BUSY_OFFSET         0x0090      // Temperature sensor measurement status register
#define INT_RAW_OFFSET      0x0094      // Raw temperature sensor measurement interrupt status register
#define INT_TCAP_OFFSET     0x0098      // Temperature sensor measurement interrupt status register
#define T_VALUE_OFFSET      0x009C      // Temperature sensor measurement value register
#define FILTER_NUM_OFFSET   0x00A0      // Filter glitch width configuration register
    
#define SPI_CLK_DIV_REG  RTC_APB_BASE_ADDRESS + SPI_CLK_DIV_OFFSET
#define SPI_RW_REG       RTC_APB_BASE_ADDRESS + SPI_RW_OFFSET
#define CONVER_T_REG     RTC_APB_BASE_ADDRESS + CONVER_T_OFFSET
#define CRC_EN_REG       RTC_APB_BASE_ADDRESS + CRC_EN_OFFSET
#define INT_MASK_REG     RTC_APB_BASE_ADDRESS + INT_MASK_OFFSET
#define INT_CLEAR_REG    RTC_APB_BASE_ADDRESS + INT_CLEAR_OFFSET
#define BUSY_REG         RTC_APB_BASE_ADDRESS + BUSY_OFFSET
#define INT_RAW_REG      RTC_APB_BASE_ADDRESS + INT_RAW_OFFSET
#define INT_TCAP_REG     RTC_APB_BASE_ADDRESS + INT_TCAP_OFFSET
#define T_VALUE_REG      RTC_APB_BASE_ADDRESS + T_VALUE_OFFSET
#define FILTER_NUM_REG   RTC_APB_BASE_ADDRESS + FILTER_NUM_OFFSET
           
/*
 * RTC reference end
 */

/*
 * GPIO reference
 */

#define GPIO0_BASE_ADDRESS      0x20140000
#define GPIO1_BASE_ADDRESS      0x20150000
#define GPIO2_BASE_ADDRESS      0x20160000
#define GPIO3_BASE_ADDRESS      0x20170000
#define GPIO4_BASE_ADDRESS      0x20180000
#define GPIO5_BASE_ADDRESS      0x20190000
#define GPIO6_BASE_ADDRESS      0x201A0000
#define GPIO7_BASE_ADDRESS      0x201B0000
#define GPIO8_BASE_ADDRESS      0x201C0000
#define GPIO9_BASE_ADDRESS      0x201D0000
#define GPIO10_BASE_ADDRESS     0x201E0000
#define GPIO11_BASE_ADDRESS     0x201F0000

// Register address of GPIOn = GPIOn base address + Offset address of the register
// The value of n ranges from 0 to 11.

/*  
 *  Mask for select gpio pins
 *  --------------------------------------------------------------------------------
 *  |  bits  | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
 *  |--------|----|----|----|----|----|----|---|---|---|---|---|---|---|---|---|---|
 *  |  gpio  |  x |  x |  x |  x |  x |  x | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 | x | x |
 *  |--------|----|----|----|----|----|----|---|---|---|---|---|---|---|---|---|---|
 *  |  0x3FC |  0 |  0 |  0 |  0 |  0 |  0 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 0 | 0 | example select all pins            (0b0000001111111100)
 *  |  0x200 |  0 |  0 |  0 |  0 |  0 |  0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | example select only 7 gpio pin     (0b0000001000000000)
 *  |  0x244 |  0 |  0 |  0 |  0 |  0 |  0 | 1 | 0 | 0 | 1 | 0 | 0 | 0 | 1 | 0 | 0 | example select 7, 4, 0 gpio pins   (0b0000001001000100)
 *  |  0x000 |  0 |  0 |  0 |  0 |  0 |  0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | example deselect all gpio pin      (0b0000000000000000)
 *  -------------------------------------------------------------------------------- 
*/

#define GPIO_DATA_MASK_ALL_PINS_OFFSET  0x3FC       // GPIO data register 0x3FC (0b11_1111_1100) mask
#define GPIO_DATA_MASK_NON_PINS_OFFSET  0x000       // GPIO data register 0x000 (0b00_0000_0000) mask
#define GPIO_DIR_OFFSET                 0x400       // GPIO direction control register
#define GPIO_IS_OFFSET                  0x404       // GPIO interrupt trigger register
#define GPIO_IBE_OFFSET                 0x408       // GPIO interrupt dual-edge trigger register
#define GPIO_IEV_OFFSET                 0x40C       // GPIO interrupt trigger event register
#define GPIO_IE_OFFSET                  0x410       // GPIO interrupt mask register 
#define GPIO_RIS_OFFSET                 0x414       // GPIO raw interrupt status register
#define GPIO_MIS_OFFSET                 0x418       // GPIO masked interrupt status register
#define GPIO_IC_OFFSET                  0x41C       // GPIO interrupt clear register

#define SPI_CLK_DIV_REG  RTC_APB_BASE_ADDRESS + SPI_CLK_DIV_OFFSET

#define GPIO_DATA_REG (x)     GPIO##x##_BASE_ADDRESS + GPIO_DATA_OFFSET   // x - gpiochip number
#define GPIO_DIR_REG  (x)     GPIO##x##_BASE_ADDRESS + GPIO_DIR_OFFSET    // x - gpiochip number
#define GPIO_IS_REG   (x)     GPIO##x##_BASE_ADDRESS + GPIO_IS_OFFSET     // x - gpiochip number
#define GPIO_IBE_REG  (x)     GPIO##x##_BASE_ADDRESS + GPIO_IBE_OFFSET    // x - gpiochip number
#define GPIO_IEV_REG  (x)     GPIO##x##_BASE_ADDRESS + GPIO_IEV_OFFSET    // x - gpiochip number
#define GPIO_IE_REG   (x)     GPIO##x##_BASE_ADDRESS + GPIO_IE_OFFSET     // x - gpiochip number
#define GPIO_RIS_REG  (x)     GPIO##x##_BASE_ADDRESS + GPIO_RIS_OFFSET    // x - gpiochip number
#define GPIO_MIS_REG  (x)     GPIO##x##_BASE_ADDRESS + GPIO_MIS_OFFSET    // x - gpiochip number
#define GPIO_IC_REG   (x)     GPIO##x##_BASE_ADDRESS + GPIO_IC_OFFSET     // x - gpiochip number

/*
 * GPIO reference end
 */




/*
 * Watchdog HAL api
 */

HI_S32 start_watchdog(HI_U32 interval) {
    
    static unsigned long rate = 3 * MHZ;
    unsigned long cnt = (~0x0)/rate;        /* max cnt */
    int seconds_multiplyer = 1000;
    
    himm_set(WDG_LOCK_REG, REG_UNLOCK_VALUE);
    himm_set(WDG_LOAD_REG, interval * seconds_multiplyer * cnt); // WDG_LOAD
    
    himm_get(WDG_LOAD_REG);
    
    himm_set(WDG_CONTROL_REG, 0x3); // WDG_CONTROL
    himm_get(WDG_CONTROL_REG);
    
    himm_set(WDG_LOCK_REG, REG_LOCK_ANY_VALUE); // WDG_LOCK
    himm_get(WDG_LOCK_REG);
    return 0;
}

HI_S32 refresh_watchdog(void) {   
    himm_set(WDG_LOCK_REG, REG_UNLOCK_VALUE); // WDG_LOCK
    himm_get(WDG_LOCK_REG);

    himm_set(WDG_INTCLR_REG, 0x1); // WDG_INTCLR
    himm_get(WDG_INTCLR_REG);

    himm_set(WDG_LOCK_REG, REG_LOCK_ANY_VALUE); // WDG_LOCK
    himm_get(WDG_LOCK_REG);
        
    return 0;
}

/*
 * Watchdog HAL api end
 */

/*
 * System Controller HAL api
 */

HI_S32 soft_reset_system(void) {   
    himm_set(SC_LOCKEN_REG, REG_UNLOCK_VALUE);
    himm_set(SC_SYSRES_REG, REG_LOCK_ANY_VALUE);
    return 0;
}

/*
 * System Controller HAL api end
 */
    


#ifdef __cplusplus
}
#endif

#endif /* API_H */

