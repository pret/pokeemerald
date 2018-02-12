#ifndef GUARD_UNK_TEXT_UTIL_H
#define GUARD_UNK_TEXT_UTIL_H

void UnkTextUtil_Reset(void);
void UnkTextUtil_SetPtrI(u8 idx, const u8 *ptr);
u8 *UnkTextUtil_StringExpandPlaceholders(u8 *dest, const u8 *src);
const u8 *UnkTextUtil_GetPtrI(u8 idx);

#endif //GUARD_UNK_TEXT_UTIL_H
