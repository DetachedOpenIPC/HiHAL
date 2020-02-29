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
 * File:   temperature.c
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

#if 0 // single test 15 loops
    
    for (int i = 0; i<15; i++) {
        setup_temperature_sensor(0, 255, 0, 0);
        float temperature = get_single_temperature();
        printf("CPU temperature: %f\n", temperature);
        usleep(1000000);
        clear();
    }
    
#else // cycle test 15 loops only get temp
    
    setup_temperature_sensor(1, 255, 0, 0);
    clear();
    for (int i = 0; i<15; i++) {
        float temperature[8] = {0};
        get_cycle_temperature(temperature);
        printf("CPU temperature: %f, %f, %f, %f, %f, %f, %f, %f\n", 
                temperature[0], temperature[1], temperature[2], temperature[3],
                temperature[4], temperature[5], temperature[6], temperature[7]);
        usleep(1000000);
    }
#endif

    return (EXIT_SUCCESS);
}




