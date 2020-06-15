/*
 * Copyright (c) 2020 PHYTEC Messtechnik GmbH
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef UC_MODBUS_CPU_H_
#define UC_MODBUS_CPU_H_

#include <zephyr.h>

typedef void CPU_VOID;
typedef char CPU_CHAR;
typedef bool CPU_BOOLEAN;
typedef u8_t CPU_INT08U;
typedef s8_t CPU_INT08S;
typedef u16_t CPU_INT16U;
typedef s16_t CPU_INT16S;
typedef u32_t CPU_INT32U;
typedef s32_t CPU_INT32S;
typedef float CPU_FP32;
typedef double CPU_FP64;
typedef void (*CPU_FNCT_PTR)(void *);

#define DEF_TRUE	true
#define DEF_FALSE	false

#define DEF_ENABLED 	1
#define DEF_DISABLED 	0

#endif
