#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef volatile u8  vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile s8  vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;

typedef float  f32;
typedef double f64;

typedef u8  bool8;
typedef u16 bool16;
typedef u32 bool32;

#define NULL (void *)0

#define TRUE  1
#define FALSE 0

#include "gba/io_reg.h"
#include "gba/syscall.h"
#include "gba/macro.h"

#endif // GUARD_GLOBAL_H
