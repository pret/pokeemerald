#ifndef GUARD_international_string_util_H
#define GUARD_international_string_util_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations

void TVShowConvertInternationalString(void *dest, const void *src, u8 language);
s32 GetMaxWidthInMenuTable(const u8 *const *strings, s32 nstrs);
u32 sub_81DB604(const u8 *);

#endif //GUARD_international_string_util_H
