#ifndef GUARD_INTERNATIONAL_STRING_UTIL_H
#define GUARD_INTERNATIONAL_STRING_UTIL_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations

void sub_81DB52C(const u8 *src);
void TVShowConvertInternationalString(void *dest, const void *src, u8 language);
u32 sub_81DB604(const u8 *);
s32 GetStringCenterAlignXOffset(u8 fontId, const u8 *str, s32 totalWidth);

#endif //GUARD_INTERNATIONAL_STRING_UTIL_H
