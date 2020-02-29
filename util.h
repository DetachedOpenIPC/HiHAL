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
 * File:   util.h
 * Author: Sergey Sharshunov <s.sharshunov@gmail.com>
 *
 * Created on 28 февраля 2020 г., 14:44
 */

#ifndef UTIL_H
#define UTIL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "hi_type.h"
#include "memmap.h"
    
#define DEFAULT_MD_LEN 128

//#define HIMM_STRING // enable if you want use string reg address and values
    
#ifndef HIMM_STRING
    
HI_S32 himm_set(HI_U32 reg_address, HI_U32 value) {
    HI_U32 ulOld;
    HI_VOID* pMem  = HI_NULL;
    
    pMem = memmap(reg_address, DEFAULT_MD_LEN);
    ulOld = *(HI_U32*)pMem;
    *(HI_U32*)pMem = value;
#ifdef DEBUG
    printf("0x%08X: 0x%08X --> 0x%08X \n", reg_address, ulOld, value);
#endif
    return 0;
}

HI_S32 himm_get(HI_U32 reg_address) {
    HI_U32 ulOld;
    HI_VOID* pMem  = HI_NULL;
    
    pMem = memmap(reg_address, DEFAULT_MD_LEN);
    ulOld = *(HI_U32*)pMem;
#ifdef DEBUG
    printf("0x%08X: 0x%08X\n", reg_address, ulOld);
#endif
    return ulOld;
}

#else

#define ASC2NUM(ch) (ch - '0')
#define HEXASC2NUM(ch) (ch - 'A' + 10)

HI_S32 atoulx(char* str, HI_U32* pulValue)
{
    HI_U32   ulResult=0;
    char ch;

    while (*str) {
        ch=toupper(*str);
        if (isdigit(ch) || ((ch >= 'A') && (ch <= 'F' )))
        {
            if (ulResult < 0x10000000)
            {
                ulResult = (ulResult << 4) + ((ch<='9')?(ASC2NUM(ch)):(HEXASC2NUM(ch)));
            }
            else
            {
                *pulValue=ulResult;
                return HI_FAILURE;
            }
        }
        else
        {
            *pulValue=ulResult;
            return HI_FAILURE;
        }
        str++;
    }
    
    *pulValue=ulResult;
    return HI_SUCCESS;
}
    
HI_S32 atoul(char* str, HI_U32* pulValue)
{
    HI_U32 ulResult=0;

    while (*str) {
        if (isdigit((int)*str)) {
            /*×îŽóÖ§³Öµœ0xFFFFFFFF(4294967295), 
               X * 10 + (*str)-48 <= 4294967295
               ËùÒÔ£¬ X = 429496729 */
            if ((ulResult<429496729) || ((ulResult==429496729) && (*str<'6')))
            {
                ulResult = ulResult*10 + (*str)-48;
            }
            else
            {
                *pulValue = ulResult;
                return HI_FAILURE;
            }
        }
        else
        {
            *pulValue=ulResult;
            return HI_FAILURE;
        }
        str++;
    }
    *pulValue=ulResult;
    return HI_SUCCESS;
}
    
HI_S32 StrToNumber(char* str , HI_U32* pulValue)
{
    if ( *str == '0' && (*(str+1) == 'x' || *(str+1) == 'X') )
    {
        if (*(str+2) == '\0')
        {
            return HI_FAILURE;
        }
        else
        {
            return atoulx(str+2, pulValue);
        }
    }
    else
    {
        return atoul(str,pulValue);
    }
}
    
HI_S32 himm_set(char* reg, char* value)
{
    HI_U32 ulAddr = 0;
    HI_U32 ulOld, ulNew;
    char strNew[16];
    HI_VOID* pMem  = HI_NULL;
    
    if ((reg != HI_NULL) && (reg[0] == '\0')) {
        printf("char array is empty\n");
        return -1;
    }
    
    if( StrToNumber(reg, &ulAddr) == HI_SUCCESS) {    
        pMem = memmap(ulAddr, DEFAULT_MD_LEN);
        ulOld = *(HI_U32*)pMem;
        if (StrToNumber(value, &ulNew) == HI_SUCCESS) {
            *(HI_U32*)pMem = ulNew;
            printf("%s: 0x%08X --> 0x%08X \n", reg, ulOld, ulNew);
        } else {
            printf("Input Error\n");
        }
    } else {
        printf("Please input address like 0x12345\n");
    }
    
    return 0;
}

HI_S32 himm_get(char* reg)
{
    HI_U32 ulAddr = 0;
    HI_U32 ulOld, ulNew;
    char strNew[16];
    HI_VOID* pMem  = HI_NULL;
    
    if ((reg != HI_NULL) && (reg[0] == '\0')) {
        printf("char array is empty\n");
        return -1;
    }
        if( StrToNumber(reg, &ulAddr) == HI_SUCCESS) {    
            pMem = memmap(ulAddr, DEFAULT_MD_LEN);
            ulOld = *(HI_U32*)pMem;
            /*hi_hexdump(STDOUT, pMem, DEFAULT_MD_LEN, 16);*/
            printf("%s: 0x%08X\n", reg, ulOld);
        } else {
            printf("Please input address like 0x12345\n");
        }
    return 0;
}

#endif


#ifdef __cplusplus
}
#endif

#endif /* UTIL_H */

