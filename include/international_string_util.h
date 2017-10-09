#ifndef GUARD_INTERNATIONAL_STRING_UTIL_H
#define GUARD_INTERNATIONAL_STRING_UTIL_H

s32 GetStringCenterAlignXOffset(s32 fontId, const u8 *str, s32 totalWidth);
s32 GetStringRightAlignXOffset(s32 fontId, const u8 *str, s32 totalWidth);
s32 GetStringCenterAlignXOffsetWithLetterSpacing(s32 fontId, const u8 *str, s32 totalWidth, s32 letterSpacing);
s32 GetStringWidthDifference(s32 fontId, const u8 *str, s32 totalWidth, s32 letterSpacing);
s32 GetMaxWidthInMenuTable(const u8 **str, s32 arg1);
s32 sub_81DB3D8(const u8 **str, u8* arg1, s32 arg2);
// sub_81DB41C
// sub_81DB468
// sub_81DB494
// sub_81DB4DC
// sub_81DB52C
// sub_81DB554
// sub_81DB5AC
// sub_81DB5E8
// sub_81DB620

#endif // GUARD_INTERNATIONAL_STRING_UTIL_H
