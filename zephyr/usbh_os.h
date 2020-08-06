/*
*********************************************************************************************************
*                                             uC/USB-Host
*                                     The Embedded USB Host Stack
*
*                    Copyright 2004-2020 Silicon Laboratories Inc. www.silabs.com
*
*                                 SPDX-License-Identifier: APACHE-2.0
*
*               This software is subject to an open source license and is distributed by
*                Silicon Laboratories Inc. pursuant to the terms of the Apache License,
*                    Version 2.0 available at www.apache.org/licenses/LICENSE-2.0.
*
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                       USB HOST OS OPERATIONS
*
* Filename : usb_os.h
* Version  : V3.42.00
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                               MODULE
*********************************************************************************************************
*/

#ifndef USBH_OS_H
#define USBH_OS_H

/*
*********************************************************************************************************
*                                            INCLUDE FILES
*********************************************************************************************************
*/

#include <usbh_cpu.h>
// #include  <lib_def.h>
// #include  <lib_mem.h>
#include "usbh_err.h"
#include <zephyr.h>
/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/

#ifdef USBH_OS_MODULE
#define USBH_OS_EXT
#else
#define USBH_OS_EXT extern
#endif

/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/

typedef enum lib_err
{

    LIB_ERR_NONE = 0u,

    LIB_MEM_ERR_NONE = 10000u,
    LIB_MEM_ERR_NULL_PTR = 10001u, /* Ptr arg(s) passed NULL ptr(s).                       */

    LIB_MEM_ERR_INVALID_MEM_SIZE = 10100u,         /* Invalid mem     size.                                */
    LIB_MEM_ERR_INVALID_MEM_ALIGN = 10101u,        /* Invalid mem     align.                               */
    LIB_MEM_ERR_INVALID_SEG_SIZE = 10110u,         /* Invalid mem seg size.                                */
    LIB_MEM_ERR_INVALID_SEG_OVERLAP = 10111u,      /* Invalid mem seg overlaps other mem seg(s).           */
    LIB_MEM_ERR_INVALID_SEG_EXISTS = 10112u,       /* Invalid mem seg already exists.                      */
    LIB_MEM_ERR_INVALID_POOL = 10120u,             /* Invalid mem pool.                                    */
    LIB_MEM_ERR_INVALID_BLK_NBR = 10130u,          /* Invalid mem pool blk nbr.                            */
    LIB_MEM_ERR_INVALID_BLK_SIZE = 10131u,         /* Invalid mem pool blk size.                           */
    LIB_MEM_ERR_INVALID_BLK_ALIGN = 10132u,        /* Invalid mem pool blk align.                          */
    LIB_MEM_ERR_INVALID_BLK_IX = 10133u,           /* Invalid mem pool ix.                                 */
    LIB_MEM_ERR_INVALID_BLK_ADDR = 10135u,         /* Invalid mem pool blk addr.                           */
    LIB_MEM_ERR_INVALID_BLK_ADDR_IN_POOL = 10136u, /* Mem pool blk addr already in mem pool.               */

    LIB_MEM_ERR_SEG_EMPTY = 10200u,      /* Mem seg  empty; i.e. NO avail mem in seg.            */
    LIB_MEM_ERR_SEG_OVF = 10201u,        /* Mem seg  ovf;   i.e. req'd mem ovfs rem mem in seg.  */
    LIB_MEM_ERR_POOL_FULL = 10205u,      /* Mem pool full;  i.e. all mem blks avail in mem pool. */
    LIB_MEM_ERR_POOL_EMPTY = 10206u,     /* Mem pool empty; i.e. NO  mem blks avail in mem pool. */
    LIB_MEM_ERR_POOL_UNLIMITED = 10207u, /* Mem pool is unlimited.                               */

    LIB_MEM_ERR_HEAP_EMPTY = 10210u,    /* Heap seg empty; i.e. NO avail mem in heap.           */
    LIB_MEM_ERR_HEAP_OVF = 10211u,      /* Heap seg ovf;   i.e. req'd mem ovfs rem mem in heap. */
    LIB_MEM_ERR_HEAP_NOT_FOUND = 10215u /* Heap seg NOT found.                                  */

} LIB_ERR;

#define DEF_NULL 0u

#define DEF_NO 0u
#define DEF_YES 1u

#define DEF_INACTIVE 0u
#define DEF_ACTIVE 1u

#define DEF_INVALID 0u
#define DEF_VALID 1u

#define DEF_OFF 0u
#define DEF_ON 1u

#define DEF_CLR 0u
#define DEF_SET 1u

#define DEF_FAIL 0u
#define DEF_OK 1u

#define DEF_OCTET_NBR_BITS 8u

/*
*********************************************************************************************************
*                                             DATA TYPES
*********************************************************************************************************
*/

typedef struct k_sem USBH_HSEM;     /* Handle on semaphores.                                */
typedef struct k_mutex USBH_HMUTEX; /* Handle on mutex.                                     */
typedef struct k_thread USBH_HTASK; /* Handle on tasks.                                     */
typedef struct k_msgq USBH_HQUEUE;  /* Handle on queues.                                    */
typedef CPU_INT32U USBH_HTMR;       /* Handle on timers.                                    */

typedef k_thread_entry_t USBH_TASK_FNCT; /* Task function.      
                                 */
typedef struct k_mem_pool MEM_POOL;

/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                               MACRO'S
*********************************************************************************************************
*/

#define DEF_MIN(a, b) MIN(a, b)
#define DEF_BIT_SET(var, bit) WRITE_BIT(var, bit, true)

#define DEF_BIT_IS_CLR(val, mask) (((((val) & (mask)) == 0u) && \
                                    ((mask) != 0u))             \
                                       ? (DEF_YES)              \
                                       : (DEF_NO))

#define DEF_BIT_IS_SET(val, mask) (((((val) & (mask)) == (mask)) && \
                                    ((mask) != 0u))                 \
                                       ? (DEF_YES)                  \
                                       : (DEF_NO))
#define DEF_BIT(n) BIT_MASK(n)
#define DEF_BIT_00 BIT_MASK(0)
#define DEF_BIT_01 BIT_MASK(1)
#define DEF_BIT_02 BIT_MASK(2)
#define DEF_BIT_03 BIT_MASK(3)
#define DEF_BIT_04 BIT_MASK(4)
#define DEF_BIT_05 BIT_MASK(5)
#define DEF_BIT_06 BIT_MASK(6)
#define DEF_BIT_07 BIT_MASK(7)
#define DEF_BIT_08 BIT_MASK(8)
#define DEF_BIT_09 BIT_MASK(9)
#define DEF_BIT_10 BIT_MASK(10)

#define Mem_Clr(buf, size) memset(buf, 0, size)
#define Mem_Set(buf, val, size) memset(buf, val, size)
#define Mem_Copy(dest, src, size) memcpy(dest, src, size)
#define Mem_HeapAlloc(size, unused1, unused2, unused3) k_malloc(size)
#define Mem_PoolBlkGet(pool, size, unused) k_mem_pool_malloc(pool, size)
#define Mem_PoolBlkFree(pointer, unused, unused2) k_free(pointer)

/******* currently no zephyr substitute available *************/

#define DEF_BIT_CLR_08(val, mask) ((val) = (CPU_INT08U)(((CPU_INT08U)(val)) & (CPU_INT08U)(~((CPU_INT08U)(mask)))))

#define DEF_BIT_CLR_16(val, mask) ((val) = (CPU_INT16U)(((CPU_INT16U)(val)) & (CPU_INT16U)(~((CPU_INT16U)(mask)))))

#define DEF_BIT_CLR_32(val, mask) ((val) = (CPU_INT32U)(((CPU_INT32U)(val)) & (CPU_INT32U)(~((CPU_INT32U)(mask)))))

#define DEF_BIT_CLR_64(val, mask) ((val) = (CPU_INT64U)(((CPU_INT64U)(val)) & (CPU_INT64U)(~((CPU_INT64U)(mask)))))

#if (CPU_CFG_DATA_SIZE_MAX == CPU_WORD_SIZE_08)

#define DEF_BIT_CLR(val, mask) ((sizeof((val)) == CPU_WORD_SIZE_08) ? DEF_BIT_CLR_08((val), (mask)) : 0)

#elif (CPU_CFG_DATA_SIZE_MAX == CPU_WORD_SIZE_16)

#define DEF_BIT_CLR(val, mask) ((sizeof((val)) == CPU_WORD_SIZE_08) ? DEF_BIT_CLR_08((val), (mask)) : ((sizeof((val)) == CPU_WORD_SIZE_16) ? DEF_BIT_CLR_16((val), (mask)) : 0))

#elif (CPU_CFG_DATA_SIZE_MAX == CPU_WORD_SIZE_32)

#define DEF_BIT_CLR(val, mask) ((sizeof((val)) == CPU_WORD_SIZE_08) ? DEF_BIT_CLR_08((val), (mask)) : ((sizeof((val)) == CPU_WORD_SIZE_16) ? DEF_BIT_CLR_16((val), (mask)) : ((sizeof((val)) == CPU_WORD_SIZE_32) ? DEF_BIT_CLR_32((val), (mask)) : 0)))

#elif (CPU_CFG_DATA_SIZE_MAX == CPU_WORD_SIZE_64)

#define DEF_BIT_CLR(val, mask) ((sizeof((val)) == CPU_WORD_SIZE_08) ? DEF_BIT_CLR_08((val), (mask)) : ((sizeof((val)) == CPU_WORD_SIZE_16) ? DEF_BIT_CLR_16((val), (mask)) : ((sizeof((val)) == CPU_WORD_SIZE_32) ? DEF_BIT_CLR_32((val), (mask)) : ((sizeof((val)) == CPU_WORD_SIZE_64) ? DEF_BIT_CLR_64((val), (mask)) : 0))))

#else

#error "CPU_CFG_DATA_SIZE_MAX  illegally #defined in 'cpu.h'      "
#error "                       [See 'cpu.h  CONFIGURATION ERRORS']"

#endif

#define MEM_VAL_COPY_SET_INT08U_BIG(addr_dest, addr_src) MEM_VAL_COPY_GET_INT08U_BIG((addr_dest), (addr_src))
#define MEM_VAL_COPY_SET_INT16U_BIG(addr_dest, addr_src) MEM_VAL_COPY_GET_INT16U_BIG((addr_dest), (addr_src))
#define MEM_VAL_COPY_SET_INT24U_BIG(addr_dest, addr_src) MEM_VAL_COPY_GET_INT24U_BIG((addr_dest), (addr_src))
#define MEM_VAL_COPY_SET_INT32U_BIG(addr_dest, addr_src) MEM_VAL_COPY_GET_INT32U_BIG((addr_dest), (addr_src))

#define MEM_VAL_COPY_SET_INT08U_LITTLE(addr_dest, addr_src) MEM_VAL_COPY_GET_INT08U_LITTLE((addr_dest), (addr_src))
#define MEM_VAL_COPY_SET_INT16U_LITTLE(addr_dest, addr_src) MEM_VAL_COPY_GET_INT16U_LITTLE((addr_dest), (addr_src))
#define MEM_VAL_COPY_SET_INT24U_LITTLE(addr_dest, addr_src) MEM_VAL_COPY_GET_INT24U_LITTLE((addr_dest), (addr_src))
#define MEM_VAL_COPY_SET_INT32U_LITTLE(addr_dest, addr_src) MEM_VAL_COPY_GET_INT32U_LITTLE((addr_dest), (addr_src))

#define MEM_VAL_COPY_SET_INT08U(addr_dest, addr_src) MEM_VAL_COPY_GET_INT08U((addr_dest), (addr_src))
#define MEM_VAL_COPY_SET_INT16U(addr_dest, addr_src) MEM_VAL_COPY_GET_INT16U((addr_dest), (addr_src))
#define MEM_VAL_COPY_SET_INT24U(addr_dest, addr_src) MEM_VAL_COPY_GET_INT24U((addr_dest), (addr_src))
#define MEM_VAL_COPY_SET_INT32U(addr_dest, addr_src) MEM_VAL_COPY_GET_INT32U((addr_dest), (addr_src))

#define MEM_VAL_GET_INT08U_BIG(addr) ((CPU_INT08U)((CPU_INT08U)(((CPU_INT08U)(*(((CPU_INT08U *)(addr)) + 0))) << (0u * DEF_OCTET_NBR_BITS))))

#define MEM_VAL_GET_INT16U_BIG(addr) ((CPU_INT16U)(((CPU_INT16U)(((CPU_INT16U)(*(((CPU_INT08U *)(addr)) + 0))) << (1u * DEF_OCTET_NBR_BITS))) + \
                                                   ((CPU_INT16U)(((CPU_INT16U)(*(((CPU_INT08U *)(addr)) + 1))) << (0u * DEF_OCTET_NBR_BITS)))))

#define MEM_VAL_GET_INT24U_BIG(addr) ((CPU_INT32U)(((CPU_INT32U)(((CPU_INT32U)(*(((CPU_INT08U *)(addr)) + 0))) << (2u * DEF_OCTET_NBR_BITS))) + \
                                                   ((CPU_INT32U)(((CPU_INT32U)(*(((CPU_INT08U *)(addr)) + 1))) << (1u * DEF_OCTET_NBR_BITS))) + \
                                                   ((CPU_INT32U)(((CPU_INT32U)(*(((CPU_INT08U *)(addr)) + 2))) << (0u * DEF_OCTET_NBR_BITS)))))

#define MEM_VAL_GET_INT32U_BIG(addr) ((CPU_INT32U)(((CPU_INT32U)(((CPU_INT32U)(*(((CPU_INT08U *)(addr)) + 0))) << (3u * DEF_OCTET_NBR_BITS))) + \
                                                   ((CPU_INT32U)(((CPU_INT32U)(*(((CPU_INT08U *)(addr)) + 1))) << (2u * DEF_OCTET_NBR_BITS))) + \
                                                   ((CPU_INT32U)(((CPU_INT32U)(*(((CPU_INT08U *)(addr)) + 2))) << (1u * DEF_OCTET_NBR_BITS))) + \
                                                   ((CPU_INT32U)(((CPU_INT32U)(*(((CPU_INT08U *)(addr)) + 3))) << (0u * DEF_OCTET_NBR_BITS)))))

#define MEM_VAL_GET_INT08U_LITTLE(addr) ((CPU_INT08U)((CPU_INT08U)(((CPU_INT08U)(*(((CPU_INT08U *)(addr)) + 0))) << (0u * DEF_OCTET_NBR_BITS))))

#define MEM_VAL_GET_INT16U_LITTLE(addr) ((CPU_INT16U)(((CPU_INT16U)(((CPU_INT16U)(*(((CPU_INT08U *)(addr)) + 0))) << (0u * DEF_OCTET_NBR_BITS))) + \
                                                      ((CPU_INT16U)(((CPU_INT16U)(*(((CPU_INT08U *)(addr)) + 1))) << (1u * DEF_OCTET_NBR_BITS)))))

#define MEM_VAL_GET_INT24U_LITTLE(addr) ((CPU_INT32U)(((CPU_INT32U)(((CPU_INT32U)(*(((CPU_INT08U *)(addr)) + 0))) << (0u * DEF_OCTET_NBR_BITS))) + \
                                                      ((CPU_INT32U)(((CPU_INT32U)(*(((CPU_INT08U *)(addr)) + 1))) << (1u * DEF_OCTET_NBR_BITS))) + \
                                                      ((CPU_INT32U)(((CPU_INT32U)(*(((CPU_INT08U *)(addr)) + 2))) << (2u * DEF_OCTET_NBR_BITS)))))

#define MEM_VAL_GET_INT32U_LITTLE(addr) ((CPU_INT32U)(((CPU_INT32U)(((CPU_INT32U)(*(((CPU_INT08U *)(addr)) + 0))) << (0u * DEF_OCTET_NBR_BITS))) + \
                                                      ((CPU_INT32U)(((CPU_INT32U)(*(((CPU_INT08U *)(addr)) + 1))) << (1u * DEF_OCTET_NBR_BITS))) + \
                                                      ((CPU_INT32U)(((CPU_INT32U)(*(((CPU_INT08U *)(addr)) + 2))) << (2u * DEF_OCTET_NBR_BITS))) + \
                                                      ((CPU_INT32U)(((CPU_INT32U)(*(((CPU_INT08U *)(addr)) + 3))) << (3u * DEF_OCTET_NBR_BITS)))))

#if (CPU_CFG_ENDIAN_TYPE == CPU_ENDIAN_TYPE_BIG)

#define MEM_VAL_GET_INT08U(addr) MEM_VAL_GET_INT08U_BIG(addr)
#define MEM_VAL_GET_INT16U(addr) MEM_VAL_GET_INT16U_BIG(addr)
#define MEM_VAL_GET_INT24U(addr) MEM_VAL_GET_INT24U_BIG(addr)
#define MEM_VAL_GET_INT32U(addr) MEM_VAL_GET_INT32U_BIG(addr)

#elif (CPU_CFG_ENDIAN_TYPE == CPU_ENDIAN_TYPE_LITTLE)

#define MEM_VAL_GET_INT08U(addr) MEM_VAL_GET_INT08U_LITTLE(addr)
#define MEM_VAL_GET_INT16U(addr) MEM_VAL_GET_INT16U_LITTLE(addr)
#define MEM_VAL_GET_INT24U(addr) MEM_VAL_GET_INT24U_LITTLE(addr)
#define MEM_VAL_GET_INT32U(addr) MEM_VAL_GET_INT32U_LITTLE(addr)

#else /* See Note #6.                                         */

#error "CPU_CFG_ENDIAN_TYPE  illegally #defined in 'cpu.h'      "
#error "                     [See 'cpu.h  CONFIGURATION ERRORS']"

#endif

#if (CPU_CFG_ENDIAN_TYPE == CPU_ENDIAN_TYPE_BIG)

#define MEM_VAL_COPY_GET_INT08U_BIG(addr_dest, addr_src)                            \
    do                                                                              \
    {                                                                               \
        (*(((CPU_INT08U *)(addr_dest)) + 0)) = (*(((CPU_INT08U *)(addr_src)) + 0)); \
    } while (0)

#define MEM_VAL_COPY_GET_INT16U_BIG(addr_dest, addr_src)                            \
    do                                                                              \
    {                                                                               \
        (*(((CPU_INT08U *)(addr_dest)) + 0)) = (*(((CPU_INT08U *)(addr_src)) + 0)); \
        (*(((CPU_INT08U *)(addr_dest)) + 1)) = (*(((CPU_INT08U *)(addr_src)) + 1)); \
    } while (0)

#define MEM_VAL_COPY_GET_INT24U_BIG(addr_dest, addr_src)                            \
    do                                                                              \
    {                                                                               \
        (*(((CPU_INT08U *)(addr_dest)) + 0)) = (*(((CPU_INT08U *)(addr_src)) + 0)); \
        (*(((CPU_INT08U *)(addr_dest)) + 1)) = (*(((CPU_INT08U *)(addr_src)) + 1)); \
        (*(((CPU_INT08U *)(addr_dest)) + 2)) = (*(((CPU_INT08U *)(addr_src)) + 2)); \
    } while (0)

#define MEM_VAL_COPY_GET_INT32U_BIG(addr_dest, addr_src)                            \
    do                                                                              \
    {                                                                               \
        (*(((CPU_INT08U *)(addr_dest)) + 0)) = (*(((CPU_INT08U *)(addr_src)) + 0)); \
        (*(((CPU_INT08U *)(addr_dest)) + 1)) = (*(((CPU_INT08U *)(addr_src)) + 1)); \
        (*(((CPU_INT08U *)(addr_dest)) + 2)) = (*(((CPU_INT08U *)(addr_src)) + 2)); \
        (*(((CPU_INT08U *)(addr_dest)) + 3)) = (*(((CPU_INT08U *)(addr_src)) + 3)); \
    } while (0)

#define MEM_VAL_COPY_GET_INT08U_LITTLE(addr_dest, addr_src)                         \
    do                                                                              \
    {                                                                               \
        (*(((CPU_INT08U *)(addr_dest)) + 0)) = (*(((CPU_INT08U *)(addr_src)) + 0)); \
    } while (0)

#define MEM_VAL_COPY_GET_INT16U_LITTLE(addr_dest, addr_src)                         \
    do                                                                              \
    {                                                                               \
        (*(((CPU_INT08U *)(addr_dest)) + 0)) = (*(((CPU_INT08U *)(addr_src)) + 1)); \
        (*(((CPU_INT08U *)(addr_dest)) + 1)) = (*(((CPU_INT08U *)(addr_src)) + 0)); \
    } while (0)

#define MEM_VAL_COPY_GET_INT24U_LITTLE(addr_dest, addr_src)                         \
    do                                                                              \
    {                                                                               \
        (*(((CPU_INT08U *)(addr_dest)) + 0)) = (*(((CPU_INT08U *)(addr_src)) + 2)); \
        (*(((CPU_INT08U *)(addr_dest)) + 1)) = (*(((CPU_INT08U *)(addr_src)) + 1)); \
        (*(((CPU_INT08U *)(addr_dest)) + 2)) = (*(((CPU_INT08U *)(addr_src)) + 0)); \
    } while (0)

#define MEM_VAL_COPY_GET_INT32U_LITTLE(addr_dest, addr_src)                         \
    do                                                                              \
    {                                                                               \
        (*(((CPU_INT08U *)(addr_dest)) + 0)) = (*(((CPU_INT08U *)(addr_src)) + 3)); \
        (*(((CPU_INT08U *)(addr_dest)) + 1)) = (*(((CPU_INT08U *)(addr_src)) + 2)); \
        (*(((CPU_INT08U *)(addr_dest)) + 2)) = (*(((CPU_INT08U *)(addr_src)) + 1)); \
        (*(((CPU_INT08U *)(addr_dest)) + 3)) = (*(((CPU_INT08U *)(addr_src)) + 0)); \
    } while (0)

#define MEM_VAL_COPY_GET_INT08U(addr_dest, addr_src) MEM_VAL_COPY_GET_INT08U_BIG((addr_dest), (addr_src))
#define MEM_VAL_COPY_GET_INT16U(addr_dest, addr_src) MEM_VAL_COPY_GET_INT16U_BIG((addr_dest), (addr_src))
#define MEM_VAL_COPY_GET_INT24U(addr_dest, addr_src) MEM_VAL_COPY_GET_INT24U_BIG((addr_dest), (addr_src))
#define MEM_VAL_COPY_GET_INT32U(addr_dest, addr_src) MEM_VAL_COPY_GET_INT32U_BIG((addr_dest), (addr_src))

#elif (CPU_CFG_ENDIAN_TYPE == CPU_ENDIAN_TYPE_LITTLE)

#define MEM_VAL_COPY_GET_INT08U_BIG(addr_dest, addr_src)                            \
    do                                                                              \
    {                                                                               \
        (*(((CPU_INT08U *)(addr_dest)) + 0)) = (*(((CPU_INT08U *)(addr_src)) + 0)); \
    } while (0)

#define MEM_VAL_COPY_GET_INT16U_BIG(addr_dest, addr_src)                            \
    do                                                                              \
    {                                                                               \
        (*(((CPU_INT08U *)(addr_dest)) + 0)) = (*(((CPU_INT08U *)(addr_src)) + 1)); \
        (*(((CPU_INT08U *)(addr_dest)) + 1)) = (*(((CPU_INT08U *)(addr_src)) + 0)); \
    } while (0)

#define MEM_VAL_COPY_GET_INT24U_BIG(addr_dest, addr_src)                            \
    do                                                                              \
    {                                                                               \
        (*(((CPU_INT08U *)(addr_dest)) + 0)) = (*(((CPU_INT08U *)(addr_src)) + 2)); \
        (*(((CPU_INT08U *)(addr_dest)) + 1)) = (*(((CPU_INT08U *)(addr_src)) + 1)); \
        (*(((CPU_INT08U *)(addr_dest)) + 2)) = (*(((CPU_INT08U *)(addr_src)) + 0)); \
    } while (0)

#define MEM_VAL_COPY_GET_INT32U_BIG(addr_dest, addr_src)                            \
    do                                                                              \
    {                                                                               \
        (*(((CPU_INT08U *)(addr_dest)) + 0)) = (*(((CPU_INT08U *)(addr_src)) + 3)); \
        (*(((CPU_INT08U *)(addr_dest)) + 1)) = (*(((CPU_INT08U *)(addr_src)) + 2)); \
        (*(((CPU_INT08U *)(addr_dest)) + 2)) = (*(((CPU_INT08U *)(addr_src)) + 1)); \
        (*(((CPU_INT08U *)(addr_dest)) + 3)) = (*(((CPU_INT08U *)(addr_src)) + 0)); \
    } while (0)

#define MEM_VAL_COPY_GET_INT08U_LITTLE(addr_dest, addr_src)                         \
    do                                                                              \
    {                                                                               \
        (*(((CPU_INT08U *)(addr_dest)) + 0)) = (*(((CPU_INT08U *)(addr_src)) + 0)); \
    } while (0)

#define MEM_VAL_COPY_GET_INT16U_LITTLE(addr_dest, addr_src)                         \
    do                                                                              \
    {                                                                               \
        (*(((CPU_INT08U *)(addr_dest)) + 0)) = (*(((CPU_INT08U *)(addr_src)) + 0)); \
        (*(((CPU_INT08U *)(addr_dest)) + 1)) = (*(((CPU_INT08U *)(addr_src)) + 1)); \
    } while (0)

#define MEM_VAL_COPY_GET_INT24U_LITTLE(addr_dest, addr_src)                         \
    do                                                                              \
    {                                                                               \
        (*(((CPU_INT08U *)(addr_dest)) + 0)) = (*(((CPU_INT08U *)(addr_src)) + 0)); \
        (*(((CPU_INT08U *)(addr_dest)) + 1)) = (*(((CPU_INT08U *)(addr_src)) + 1)); \
        (*(((CPU_INT08U *)(addr_dest)) + 2)) = (*(((CPU_INT08U *)(addr_src)) + 2)); \
    } while (0)

#define MEM_VAL_COPY_GET_INT32U_LITTLE(addr_dest, addr_src)                         \
    do                                                                              \
    {                                                                               \
        (*(((CPU_INT08U *)(addr_dest)) + 0)) = (*(((CPU_INT08U *)(addr_src)) + 0)); \
        (*(((CPU_INT08U *)(addr_dest)) + 1)) = (*(((CPU_INT08U *)(addr_src)) + 1)); \
        (*(((CPU_INT08U *)(addr_dest)) + 2)) = (*(((CPU_INT08U *)(addr_src)) + 2)); \
        (*(((CPU_INT08U *)(addr_dest)) + 3)) = (*(((CPU_INT08U *)(addr_src)) + 3)); \
    } while (0)

#define MEM_VAL_COPY_GET_INT08U(addr_dest, addr_src) MEM_VAL_COPY_GET_INT08U_LITTLE((addr_dest), (addr_src))
#define MEM_VAL_COPY_GET_INT16U(addr_dest, addr_src) MEM_VAL_COPY_GET_INT16U_LITTLE((addr_dest), (addr_src))
#define MEM_VAL_COPY_GET_INT24U(addr_dest, addr_src) MEM_VAL_COPY_GET_INT24U_LITTLE((addr_dest), (addr_src))
#define MEM_VAL_COPY_GET_INT32U(addr_dest, addr_src) MEM_VAL_COPY_GET_INT32U_LITTLE((addr_dest), (addr_src))

#else /* See Note #7.                                         */

#error "CPU_CFG_ENDIAN_TYPE  illegally #defined in 'cpu.h'      "
#error "                     [See 'cpu.h  CONFIGURATION ERRORS']"

#endif

#if (CPU_CFG_ENDIAN_TYPE == CPU_ENDIAN_TYPE_BIG)

#define MEM_VAL_COPY_GET_INTU_BIG(addr_dest, addr_src, val_size)                          \
    do                                                                                    \
    {                                                                                     \
        CPU_SIZE_T _i;                                                                    \
                                                                                          \
        for (_i = 0; _i < (val_size); _i++)                                               \
        {                                                                                 \
            (*(((CPU_INT08U *)(addr_dest)) + _i)) = (*(((CPU_INT08U *)(addr_src)) + _i)); \
        }                                                                                 \
    } while (0)

#define MEM_VAL_COPY_GET_INTU_LITTLE(addr_dest, addr_src, val_size)                       \
    do                                                                                    \
    {                                                                                     \
        CPU_SIZE_T _i;                                                                    \
        CPU_SIZE_T _j;                                                                    \
                                                                                          \
        _j = (val_size)-1;                                                                \
                                                                                          \
        for (_i = 0; _i < (val_size); _i++)                                               \
        {                                                                                 \
            (*(((CPU_INT08U *)(addr_dest)) + _i)) = (*(((CPU_INT08U *)(addr_src)) + _j)); \
            _j--;                                                                         \
        }                                                                                 \
    } while (0)

#define MEM_VAL_COPY_GET_INTU(addr_dest, addr_src, val_size) MEM_VAL_COPY_GET_INTU_BIG((addr_dest), (addr_src), (val_size))

#elif (CPU_CFG_ENDIAN_TYPE == CPU_ENDIAN_TYPE_LITTLE)

#define MEM_VAL_COPY_GET_INTU_BIG(addr_dest, addr_src, val_size)                          \
    do                                                                                    \
    {                                                                                     \
        CPU_SIZE_T _i;                                                                    \
        CPU_SIZE_T _j;                                                                    \
                                                                                          \
        _j = (val_size)-1;                                                                \
                                                                                          \
        for (_i = 0; _i < (val_size); _i++)                                               \
        {                                                                                 \
            (*(((CPU_INT08U *)(addr_dest)) + _i)) = (*(((CPU_INT08U *)(addr_src)) + _j)); \
            _j--;                                                                         \
        }                                                                                 \
    } while (0)

#define MEM_VAL_COPY_GET_INTU_LITTLE(addr_dest, addr_src, val_size)                       \
    do                                                                                    \
    {                                                                                     \
        CPU_SIZE_T _i;                                                                    \
                                                                                          \
        for (_i = 0; _i < (val_size); _i++)                                               \
        {                                                                                 \
            (*(((CPU_INT08U *)(addr_dest)) + _i)) = (*(((CPU_INT08U *)(addr_src)) + _i)); \
        }                                                                                 \
    } while (0)

#define MEM_VAL_COPY_GET_INTU(addr_dest, addr_src, val_size) MEM_VAL_COPY_GET_INTU_LITTLE((addr_dest), (addr_src), (val_size))

#else /* See Note #8.                                         */

#error "CPU_CFG_ENDIAN_TYPE  illegally #defined in 'cpu.h'      "
#error "                     [See 'cpu.h  CONFIGURATION ERRORS']"

#endif

/******* ****************************** *************/

/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

USBH_ERR USBH_OS_LayerInit(void);
/* --------------- DELAY TASK FUNCTIONS --------------- */
void USBH_OS_DlyMS(CPU_INT32U dly);

void USBH_OS_DlyUS(CPU_INT32U dly);

/* ----------------- MUTEX FUNCTIONS ------------------ */
USBH_ERR USBH_OS_MutexCreate(USBH_HMUTEX *p_mutex);

USBH_ERR USBH_OS_MutexLock(USBH_HMUTEX mutex);

USBH_ERR USBH_OS_MutexUnlock(USBH_HMUTEX mutex);

USBH_ERR USBH_OS_MutexDestroy(USBH_HMUTEX mutex);

/* --------------- SEMAPHORE FUNCTIONS ---------------- */
USBH_ERR USBH_OS_SemCreate(USBH_HSEM *p_sem,
                           CPU_INT32U cnt);

USBH_ERR USBH_OS_SemWait(USBH_HSEM *sem,
                         CPU_INT32U timeout);

USBH_ERR USBH_OS_SemWaitAbort(USBH_HSEM *sem);

USBH_ERR USBH_OS_SemPost(USBH_HSEM *sem);

USBH_ERR USBH_OS_SemDestroy(USBH_HSEM sem);

/* ------------------ TASK FUNCTIONS ------------------ */
USBH_ERR USBH_OS_TaskCreate(CPU_CHAR *p_name,
                            CPU_INT32U prio,
                            USBH_TASK_FNCT task_fnct,
                            void *p_data,
                            CPU_INT32U *p_stk,
                            CPU_INT32U stk_size,
                            USBH_HTASK *p_task);

/* --------------- MSG QUEUE FUNCTIONS ---------------- */
// USBH_HQUEUE   USBH_OS_MsgQueueCreate (void            **p_start,
//                                       CPU_INT16U        size,
//                                       USBH_ERR         *p_err);

USBH_ERR USBH_OS_MsgQueuePut(USBH_HQUEUE *msg_q,
                             void *p_msg);

void USBH_OS_MsgQueueGet(USBH_HQUEUE *msg_q,
                         CPU_INT32U timeout,
                         USBH_ERR *p_err,
                         void *p_data);

/* ----------- INTERNAL USE TIMER FUNCTIONS ----------- */
USBH_HTMR USBH_OS_TmrCreate(CPU_CHAR *p_name,
                            CPU_INT32U interval_ms,
                            void (*p_callback)(void *p_tmr, void *p_arg),
                            void *p_callback_arg,
                            USBH_ERR *p_err);

USBH_ERR USBH_OS_TmrStart(USBH_HTMR tmr);

USBH_ERR USBH_OS_TmrDel(USBH_HTMR tmr);

/* ------------------- MISCELLANEOUS ------------------ */
void *USBH_OS_VirToBus(void *x);

void *USBH_OS_BusToVir(void *x);

// CPU_DATA CPU_CntTrailZeros(CPU_DATA val);


/*
*********************************************************************************************************
*                                        CONFIGURATION ERRORS
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*/
#endif
