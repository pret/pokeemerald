#include "global.h"

s16 MathUtil_Mul16(s16 x, s16 y)
{
    s32 result;

    result = x;
    result *= y;
    result /= 256;
    return result;
}

s16 MathUtil_Mul16Shift(u8 s, s16 x, s16 y)
{
    s32 result;

    result = x;
    result *= y;
    result /= (1 << s);
    return result;
}

s32 MathUtil_Mul32(s32 x, s32 y)
{
    s64 result;

    result = x;
    result *= y;
    result /= 256;
    return result;
}

s16 MathUtil_Div16(s16 x, s16 y)
{
    if (y == 0)
    {
        return 0;
    }
    return (x << 8) / y;
}

s16 MathUtil_Div16Shift(u8 s, s16 x, s16 y)
{
    if (y == 0)
    {
        return 0;
    }
    return (x << s) / y;
}

s32 MathUtil_Div32(s32 x, s32 y)
{
    s64 _x;

    if (y == 0)
    {
        return 0;
    }
    _x = x;
    _x *= 256;
    return _x / y;
}

s16 MathUtil_Inv16(s16 y)
{
    s32 x;

    x = 0x10000;
    return x / y;
}

s16 MathUtil_Inv16Shift(u8 s, s16 y)
{
    s32 x;

    x = 0x100 << s;
    return x / y;
}

s32 MathUtil_Inv32(s32 y)
{
    s64 x;

    x = 0x10000;
    return x / y;
}
