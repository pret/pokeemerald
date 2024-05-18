#include "global.h"
#include "random.h"

EWRAM_DATA static u8 sUnknown = 0;
EWRAM_DATA static u32 sRandCount = 0;

// IWRAM common
u32 gRngValue;
u32 gRng2Value;

u16 Random(void)
{
    gRngValue = ISO_RANDOMIZE1(gRngValue);
    sRandCount++;
    return gRngValue >> 16;
}

void SeedRng(u16 seed)
{
    gRngValue = seed;
    sUnknown = 0;
}

void SeedRng2(u16 seed)
{
    gRng2Value = seed;
}

u16 Random2(void)
{
    gRng2Value = ISO_RANDOMIZE1(gRng2Value);
    return gRng2Value >> 16;
}

// Returns a random index according to a list of weights
u8 RandomWeightedIndex(u8 *weights, u8 length) {
    u32 i;
    u16 random_value;
    u16 weightSum = 0;
    for (i = 0; i < length; i++)
        weightSum += weights[i];
    random_value = Random() % weightSum;
    weightSum = 0;
    for (i = 0; i < length; i++) {
        weightSum += weights[i];
        if (random_value <= weightSum)
            return i;
    }
}
