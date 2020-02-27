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
 * File:   watchdog.c
 * Author: Sergey Sharshunov <s.sharshunov@gmail.com>
 *
 * Created on 26 февраля 2020 г., 17:58
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

//#define DEBUG

#include "HiHAL/api.h"

static int quit_flag = 0;

#define WATCH_SECONDS 5


void quitHandler(int dummy) {
    printf("\nSigint detected...\n");
    quit_flag = 1;
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    
    struct sigaction a;
    a.sa_handler = quitHandler;
    a.sa_flags = 0;
    sigemptyset( &a.sa_mask );
    sigaction( SIGINT, &a, NULL );
    
    static unsigned long rate = 3 * MHZ;
    unsigned long cnt = (~0x0)/rate;        /* max cnt */  
    printf("\ncnt: %lu\n", cnt);


   
    printf("\nWDG_LOCK disable lock...\n");
#ifndef HIMM_STRING
#if MANUAL
    himm_set(WDG_LOCK_REG, WDG_LOCK_REG_UNLOCK_VALUE);
    himm_set(WDG_LOAD_REG, WATCH_SECONDS * 1000 * cnt); // WDG_LOAD
    
    himm_get(WDG_LOAD_REG);
    
    himm_set(WDG_CONTROL_REG, 0x3); // WDG_CONTROL
    himm_get(WDG_CONTROL_REG);
    
    himm_set(WDG_LOCK_REG, WDG_LOCK_REG_LOCK_VALUE); // WDG_LOCK
    himm_get(WDG_LOCK_REG);
#else
    start_watchdog(WATCH_SECONDS); //  5 seconds
#endif
    
#else
    
    char value[MAX_REG_BUF]   = {0};
    char address[MAX_ADDRESS_REG_BUF] = {0};
    
    snprintf(value, MAX_REG_BUF, "0x%06lX", WATCH_SECONDS * 1000 * cnt);
    printf("val: %s\n", value);
    
    snprintf(address, MAX_ADDRESS_REG_BUF, "0x%06lX", WDG_BASE_ADDRESS+WDG_VALUE_OFFSET);
    printf("address: %s\n", address);
    
    himm_set("0x20040C00", "0x1ACCE551"); // WDG_LOCK
    
    himm_set("0x20040000", value); // WDG_LOAD
    himm_get("0x20040000");
    
    himm_set("0x20040008", "0x3"); // WDG_CONTROL
    himm_get("0x20040008");
    
    himm_set("0x20040C00", "0x1"); // WDG_LOCK
    himm_get("0x20040C00");
#endif
    
#if 1
    while (!quit_flag) {
        
#ifndef HIMM_STRING
            
#if MANUAL
        himm_set(WDG_LOCK_REG, WDG_LOCK_REG_UNLOCK_VALUE); // WDG_LOCK
        himm_get(WDG_LOCK_REG);

        himm_set(WDG_INTCLR_REG, 0x1); // WDG_INTCLR
        himm_get(WDG_INTCLR_REG);

        himm_set(WDG_LOCK_REG, WDG_LOCK_REG_LOCK_VALUE); // WDG_LOCK
        himm_get(WDG_LOCK_REG);
#else
        refresh_watchdog(); // reset watchdog
#endif
    
#else
        himm_set("0x20040C00", "0x1ACCE551"); // WDG_LOCK
        himm_get("0x20040C00");

        himm_set("0x2004000C", "0x1"); // WDG_INTCLR
        himm_get("0x2004000C");

        himm_set("0x20040C00", "0x1"); // WDG_LOCK
        himm_get("0x20040C00");
#endif
        sleep(WATCH_SECONDS - 1);
    }
#endif
    
    return (EXIT_SUCCESS);
}




