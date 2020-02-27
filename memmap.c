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
 * File:   memmap.c
 * Author: Sergey Sharshunov <s.sharshunov@gmail.com>
 *
 * Created on 26 февраля 2020 г., 18:34
 */

#include <stdio.h>
#include <stdlib.h>

#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

typedef struct tag_MMAP_Node {
    unsigned int Start_P;
    unsigned int Start_V;
    unsigned int length;
    unsigned int refcount;
    struct tag_MMAP_Node * next;
} TMMAP_Node_t;

TMMAP_Node_t * pTMMAPNode = NULL;

#define PAGE_SIZE 0x1000
#define PAGE_SIZE_MASK 0xfffff000

static int fd = -1;
static const char dev[] = "/dev/mem";

/* no need considering page_size of 4K */
void * memmap(unsigned int phy_addr, unsigned int size) {
    unsigned int phy_addr_in_page;
    unsigned int page_diff;

    unsigned int size_in_page;

    TMMAP_Node_t * pTmp;
    TMMAP_Node_t * pNew;

    void *addr=NULL;

    if(size == 0) {
#ifdef DEBUG
        printf("memmap():size can't be zero!\n");
#endif
        return NULL;
    }

    /* check if the physical memory space have been mmaped */
    pTmp = pTMMAPNode;
    while(pTmp != NULL) {
        if( (phy_addr >= pTmp->Start_P) &&
                ( (phy_addr + size) <= (pTmp->Start_P + pTmp->length) ) ) {
            pTmp->refcount++;
            return (void *)(pTmp->Start_V + phy_addr - pTmp->Start_P);
        }

        pTmp = pTmp->next;
    }

    /* not mmaped yet */
    if (fd < 0) {
        /* dev not opened yet, so open it */
        fd = open (dev, O_RDWR | O_SYNC);
        if (fd < 0) {
#ifdef DEBUG
            printf("memmap():open %s error!\n", dev);
#endif
            return NULL;
        }
    }

    /* addr align in page_size(4K) */
    phy_addr_in_page = phy_addr & PAGE_SIZE_MASK;
    page_diff = phy_addr - phy_addr_in_page;

    /* size in page_size */
    size_in_page =((size + page_diff - 1) & PAGE_SIZE_MASK) + PAGE_SIZE;

    addr = mmap ((void *)0, size_in_page, PROT_READ|PROT_WRITE, MAP_SHARED, fd, phy_addr_in_page);
    if (addr == MAP_FAILED) {
#ifdef DEBUG
        printf("memmap():mmap @ 0x%x error!\n", phy_addr_in_page);
#endif
        return NULL;
    }

    /* add this mmap to MMAP Node */
    pNew = (TMMAP_Node_t *)malloc(sizeof(TMMAP_Node_t));
    
    if (NULL == pNew) {
#ifdef DEBUG
        printf("memmap():malloc new node failed!\n");
#endif
        return NULL;
    }
    
    pNew->Start_P = phy_addr_in_page;
    pNew->Start_V = (unsigned int)addr;
    pNew->length = size_in_page;
    pNew->refcount = 1;
    pNew->next = NULL;

    if(pTMMAPNode == NULL) {
        pTMMAPNode = pNew;
    } else {
        pTmp = pTMMAPNode;
        while(pTmp->next != NULL) {
            pTmp = pTmp->next;
        }

        pTmp->next = pNew;
    }

    return (void *)(addr+page_diff);
}

int memunmap(void * addr_mapped) {
    TMMAP_Node_t * pPre;
    TMMAP_Node_t * pTmp;

    if(pTMMAPNode == NULL) {
#ifdef DEBUG
        printf("memunmap(): address have not been mmaped!\n");
#endif  
        return -1;
    }

    /* check if the physical memory space have been mmaped */
    pTmp = pTMMAPNode;
    pPre = pTMMAPNode;

    do {
        if( ((unsigned int)addr_mapped >= pTmp->Start_V) &&
                ((unsigned int)addr_mapped <= (pTmp->Start_V + pTmp->length)) ) {
            
            pTmp->refcount--;
            
            if(0 == pTmp->refcount) {
 
#ifdef DEBUG
                printf("memunmap(): map node will be remove!\n");
#endif                
                if(pTmp == pTMMAPNode) {
                    pTMMAPNode = NULL;
                } else {
                    pPre->next = pTmp->next;
                }

                /* munmap */
                if(munmap((void *)pTmp->Start_V, pTmp->length) != 0 ) {
#ifdef DEBUG
                    printf("memunmap(): munmap failed!\n");
#endif
                }
                free(pTmp);
            }
            return 0;
        }

        pPre = pTmp;
        pTmp = pTmp->next;
    } while(pTmp != NULL);
    
#ifdef DEBUG
    printf("memunmap(): address have not been mmaped!\n");
#endif
    return -1;
}

void * mmapfile(char* fn, unsigned int size) {
    int fd;
    void * pShm = NULL;
    if (fn == NULL) {
        return NULL;
    }
    /* Open the file.  */
    fd = open (fn, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG  | O_SYNC);      

    if (fd == -1) {
#ifdef DEBUG
        printf("Open file %s error: %i.\n",fn, errno);
#endif
        return NULL;
    }
    
    /* Create the memory-mapping.  */
    pShm = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close (fd);
    if (pShm != NULL) {
#ifdef DEBUG
        printf("Memory Map OK. Map File: %s, length:%#X, addr:0x%08lX", 
                        fn, size, (unsigned long)pShm);
#endif
    } else {
#ifdef DEBUG
        printf("Memory Map Failure. Map File %s, length:0x%08lX", 
                        fn, size);
#endif
    }
    return pShm;        
}

void * mmapfile_r(char* fn, unsigned int size) {
    int fd;
    void * pShm = NULL;
    if (fn == NULL) {
        return NULL;
    }
    /* Open the file.  */
    fd = open (fn, O_RDONLY | O_SYNC); 

    if (fd == -1) {
#ifdef DEBUG
        printf("Open file %s error: %d.\n",fn, errno );
#endif
        return NULL;
    }
    
    /* Create the memory-mapping.  */
    pShm = mmap(0, size, PROT_READ, MAP_SHARED, fd, 0);
    close (fd);
    if (pShm != NULL) {
#ifdef DEBUG
        printf("Memory Map OK. Map File: %s, length:%#X, addr:0x%08lX\n", 
                        fn, size, (unsigned long)pShm);
#endif
    } else {
#ifdef DEBUG
        printf("Memory Map Failure. Map File %s, length:0x%08lX\n", 
                        fn, size);
#endif
    }
    return pShm;        
}
