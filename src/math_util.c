
// Includes
#include "global.h"

// Static type declarations

// Static RAM declarations

// Static ROM declarations

// .rodata

// .text

s16 sub_8151534(s16 x, s16 y)
{
    s32 result;

    result = x;
    result *= y;
    result /= 256;
    return result;
}

s16 sub_8151550(u8 s, s16 x, s16 y)
{
    s32 result;

    result = x;
    result *= y;
    result /= (1 << s);
    return result;
}

s32 sub_8151574(s32 x, s32 y)
{
    s64 result;

    result = x;
    result *= y;
    result /= 256;
    return result;
}
