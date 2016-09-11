#ifndef GUARD_RNG_H
#define GUARD_RNG_H

#include "global.h"

extern u32 sRngValue;
extern u32 sRng2Value;
extern u32 sRngCounter;
extern bool8 sRngSeedNotSet;

u16 Random(void);
void SeedRng(u16 seed);
u16 Random2(void);
void SeedRng2(u16 seed);
u16 RandomFeebas(void);

#endif // GUARD_RNG_H
