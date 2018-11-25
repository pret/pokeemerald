#ifndef GUARD_INTERNATIONAL_STRING_UTIL_H
#define GUARD_INTERNATIONAL_STRING_UTIL_H

#include "menu.h"

void sub_81DB52C(const u8 *src);
void TVShowConvertInternationalString(u8 *dest, const u8 *src, u8 language);
s32 GetStringCenterAlignXOffset(s32 fontId, const u8 *str, s32 totalWidth);
s32 GetStringRightAlignXOffset(s32 fontId, const u8 *str, s32 totalWidth);
s32 GetStringCenterAlignXOffsetWithLetterSpacing(s32 fontId, const u8 *str, s32 totalWidth, s32 letterSpacing);
s32 GetStringWidthDifference(s32 fontId, const u8 *str, s32 totalWidth, s32 letterSpacing);
s32 GetMaxWidthInMenuTable(const struct MenuAction *str, s32 arg1);
s32 sub_81DB3D8(const struct MenuAction *str, const u8* arg1, s32 arg2);
// sub_81DB41C
// CopyMonCategoryText
// sub_81DB494
void PadNameString(u8 *dst, u8 padWith);
void sub_81DB554(u8 *, u8);
void sub_81DB5AC(u8 *);
u32 sub_81DB604(const u8 *);
// sub_81DB620

#endif // GUARD_INTERNATIONAL_STRING_UTIL_H
