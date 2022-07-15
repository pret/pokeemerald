#ifndef GUARD_DIGIT_OBJ_UTIL_H
#define GUARD_DIGIT_OBJ_UTIL_H

struct DigitObjUtilTemplate
{
    u8 strConvMode:2;
    u8 shape:2;
    u8 size:2;
    u8 priority:2;
    u8 oamCount;
    u8 xDelta;
    s16 x;
    s16 y;
    const struct SpriteSheet *spriteSheet;
    const struct SpritePalette *spritePal;
};

bool32 DigitObjUtil_Init(u32 count);
void DigitObjUtil_Free(void);
bool32 DigitObjUtil_CreatePrinter(u32 id, s32 num, const struct DigitObjUtilTemplate *template);
void DigitObjUtil_PrintNumOn(u32 id, s32 num);
void DigitObjUtil_DeletePrinter(u32 id);
void DigitObjUtil_HideOrShow(u32 id, bool32 hide);
u8 GetTilesPerImage(u32 shape, u32 size);

#endif // GUARD_DIGIT_OBJ_UTIL_H
