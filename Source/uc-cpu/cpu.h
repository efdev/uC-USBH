/*
 * Copyright (c) 2020 PHYTEC Messtechnik GmbH
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef UC_USBH_CPU_H_
#define UC_USBH_CPU_H_

#include <zephyr.h>

typedef void CPU_VOID;
typedef char CPU_CHAR;
typedef bool CPU_BOOLEAN;
typedef uint8_t CPU_INT08U;
typedef int8_t CPU_INT08S;
typedef uint16_t CPU_INT16U;
typedef int16_t CPU_INT16S;
typedef uint32_t CPU_INT32U;
typedef int32_t CPU_INT32S;
typedef int64_t CPU_INT64U;
typedef float CPU_FP32;
typedef double CPU_FP64;
typedef void (*CPU_FNCT_PTR)(void *);
typedef volatile uint8_t CPU_REG08;
typedef volatile uint32_t CPU_REG32;

#define DEF_TRUE true
#define DEF_FALSE false

#define DEF_ENABLED 1
#define DEF_DISABLED 0

#define CPU_CRITICAL_ENTER()
#define CPU_INT_EN()
#define CPU_INT_DIS()
#define CPU_CRITICAL_EXIT()
#define CPU_SR_ALLOC()

/* Define  CPU         word sizes (see Note #1) :       */
#define CPU_CFG_ADDR_SIZE CPU_WORD_SIZE_32     /* Defines CPU address word size  (in octets).          */
#define CPU_CFG_DATA_SIZE CPU_WORD_SIZE_32     /* Defines CPU data    word size  (in octets).          */
#define CPU_CFG_DATA_SIZE_MAX CPU_WORD_SIZE_64 /* Defines CPU maximum word size  (in octets).          */

#define CPU_CFG_ENDIAN_TYPE CPU_ENDIAN_TYPE_LITTLE /* Defines CPU data    word-memory order (see Note #2). */

#if (CPU_CFG_ADDR_SIZE == CPU_WORD_SIZE_32)
typedef CPU_INT32U CPU_ADDR;
#elif (CPU_CFG_ADDR_SIZE == CPU_WORD_SIZE_16)
typedef CPU_INT16U CPU_ADDR;
#else
typedef CPU_INT08U CPU_ADDR;
#endif

/* CPU data    type based on data    bus size.          */
#if (CPU_CFG_DATA_SIZE == CPU_WORD_SIZE_32)
typedef CPU_INT32U CPU_DATA;
#elif (CPU_CFG_DATA_SIZE == CPU_WORD_SIZE_16)
typedef CPU_INT16U CPU_DATA;
#else
typedef CPU_INT08U CPU_DATA;
#endif

typedef CPU_DATA CPU_ALIGN;  /* Defines CPU data-word-alignment size.                */
typedef CPU_ADDR CPU_SIZE_T; /* Defines CPU standard 'size_t'   size.                */

#endif