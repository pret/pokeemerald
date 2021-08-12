#ifndef GUARD_GBA_TYPES_H
#define GUARD_GBA_TYPES_H

#include <stdint.h>

typedef uint8_t   u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t    s8;
typedef int16_t  s16;
typedef int32_t  s32;
typedef int64_t  s64;

typedef volatile u8   vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8   vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;

typedef float  f32;
typedef double f64;

typedef u8  bool8;
typedef u16 bool16;
typedef u32 bool32;
typedef vu8  vbool8;
typedef vu16 vbool16;
typedef vu32 vbool32;

struct BgCnt
{
    u16 priority:2;
    u16 charBaseBlock:2;
    u16 dummy:2;
    u16 mosaic:1;
    u16 palettes:1;
    u16 screenBaseBlock:5;
    u16 areaOverflowMode:1;
    u16 screenSize:2;
};
typedef volatile struct BgCnt vBgCnt;

struct PlttData
{
    u16 r:5; // red
    u16 g:5; // green
    u16 b:5; // blue
    u16 unused_15:1;
};

struct OamData
{
    /*0x00*/ u32 y:8;
    /*0x01*/ u32 affineMode:2;  // 0x1, 0x2 -> 0x4
             u32 objMode:2;     // 0x4, 0x8 -> 0xC
             u32 mosaic:1;      // 0x10
             u32 bpp:1;         // 0x20
             u32 shape:2;       // 0x40, 0x80 -> 0xC0

    /*0x02*/ u32 x:9;
             u32 matrixNum:5;   // bits 3/4 are h-flip/v-flip if not in affine mode
             u32 size:2;        // 0x4000, 0x8000 -> 0xC000

    /*0x04*/ u16 tileNum:10;    // 0x3FF
             u16 priority:2;    // 0x400, 0x800 -> 0xC00
             u16 paletteNum:4;
    /*0x06*/ u16 affineParam;
};

#define ST_OAM_HFLIP     0x08
#define ST_OAM_VFLIP     0x10
#define ST_OAM_MNUM_FLIP_MASK 0x18

#define ST_OAM_OBJ_NORMAL 0
#define ST_OAM_OBJ_BLEND  1
#define ST_OAM_OBJ_WINDOW 2

#define ST_OAM_AFFINE_OFF    0
#define ST_OAM_AFFINE_NORMAL 1
#define ST_OAM_AFFINE_ERASE  2
#define ST_OAM_AFFINE_DOUBLE 3

#define ST_OAM_AFFINE_ON_MASK     1
#define ST_OAM_AFFINE_DOUBLE_MASK 2

#define ST_OAM_4BPP 0
#define ST_OAM_8BPP 1

#define ST_OAM_SQUARE      0
#define ST_OAM_H_RECTANGLE 1
#define ST_OAM_V_RECTANGLE 2

#define ST_OAM_SIZE_0   0
#define ST_OAM_SIZE_1   1
#define ST_OAM_SIZE_2   2
#define ST_OAM_SIZE_3   3

#define SPRITE_SIZE_8x8     ((ST_OAM_SIZE_0 << 2) | (ST_OAM_SQUARE))
#define SPRITE_SIZE_16x16   ((ST_OAM_SIZE_1 << 2) | (ST_OAM_SQUARE))
#define SPRITE_SIZE_32x32   ((ST_OAM_SIZE_2 << 2) | (ST_OAM_SQUARE))
#define SPRITE_SIZE_64x64   ((ST_OAM_SIZE_3 << 2) | (ST_OAM_SQUARE))

#define SPRITE_SIZE_16x8    ((ST_OAM_SIZE_0 << 2) | (ST_OAM_H_RECTANGLE))
#define SPRITE_SIZE_32x8    ((ST_OAM_SIZE_1 << 2) | (ST_OAM_H_RECTANGLE))
#define SPRITE_SIZE_32x16   ((ST_OAM_SIZE_2 << 2) | (ST_OAM_H_RECTANGLE))
#define SPRITE_SIZE_64x32   ((ST_OAM_SIZE_3 << 2) | (ST_OAM_H_RECTANGLE))

#define SPRITE_SIZE_8x16    ((ST_OAM_SIZE_0 << 2) | (ST_OAM_V_RECTANGLE))
#define SPRITE_SIZE_8x32    ((ST_OAM_SIZE_1 << 2) | (ST_OAM_V_RECTANGLE))
#define SPRITE_SIZE_16x32   ((ST_OAM_SIZE_2 << 2) | (ST_OAM_V_RECTANGLE))
#define SPRITE_SIZE_32x64   ((ST_OAM_SIZE_3 << 2) | (ST_OAM_V_RECTANGLE))

#define SPRITE_SIZE(dim)  ((SPRITE_SIZE_##dim >> 2) & 0x03)
#define SPRITE_SHAPE(dim) (SPRITE_SIZE_##dim & 0x03)

struct BgAffineSrcData
{
    s32 texX;
    s32 texY;
    s16 scrX;
    s16 scrY;
    s16 sx;
    s16 sy;
    u16 alpha;
};

struct BgAffineDstData
{
    s16 pa;
    s16 pb;
    s16 pc;
    s16 pd;
    s32 dx;
    s32 dy;
};

struct ObjAffineSrcData
{
    s16 xScale;
    s16 yScale;
    u16 rotation;
};

// Multi-player SIO Control Structure
struct SioMultiCnt
{
    u16 baudRate:2;    // baud rate
    u16 si:1;          // SI terminal
    u16 sd:1;          // SD terminal
    u16 id:2;          // ID
    u16 error:1;       // error flag
    u16 enable:1;      // SIO enable
    u16 unused_11_8:4;
    u16 mode:2;        // communication mode (should equal 2)
    u16 intrEnable:1;  // IRQ enable
    u16 unused_15:1;
    u16 data;          // data
};

#define ST_SIO_MULTI_MODE 2 // Multi-player communication mode

// baud rate
#define ST_SIO_9600_BPS   0 //   9600 bps
#define ST_SIO_38400_BPS  1 //  38400 bps
#define ST_SIO_57600_BPS  2 //  57600 bps
#define ST_SIO_115200_BPS 3 // 115200 bps

#endif // GUARD_GBA_TYPES_H
