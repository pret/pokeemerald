#ifndef GUARD_UTIL_H
#define GUARD_UTIL_H

#include "sprite.h"

extern const u8 gMiscBlank_Gfx[]; // unused in Emerald
extern const u32 gBitTable[];

u8 CreateInvisibleSpriteWithCallback(void (*)(struct Sprite *));
void StoreWordInTwoHalfwords(u16 *, u32);
void LoadWordFromTwoHalfwords(u16 *, u32 *);
int CountTrailingZeroBits(u32 value);
u16 CalcCRC16(u8 *data, s32 length);
u16 CalcCRC16WithTable(u8 *data, u32 length);
u32 CalcByteArraySum(const u8* data, u32 length);

#endif // GUARD_UTIL_H
