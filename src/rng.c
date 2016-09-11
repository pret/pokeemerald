#include "global.h"
#include "rng.h"

u16 Random()
{
    sRngValue = sRngValue * 0x41C64E6D + 0x6073;
    sRngCounter++;
    return sRngValue >> 16;
}

void SeedRng(u16 seed)
{
    sRngValue = seed;
    sRngSeedNotSet = 0;
}

u16 Random2()
{
    sRng2Value = sRng2Value * 0x41C64E6D + 0x6073;
    return sRng2Value >> 16;
}

void SeedRng2(u16 seed)
{
    sRng2Value = seed;
}
