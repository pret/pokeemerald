#ifndef GUARD_DYNAMIC_PLACEHOLDER_TEXT_UTIL_H
#define GUARD_DYNAMIC_PLACEHOLDER_TEXT_UTIL_H

void DynamicPlaceholderTextUtil_Reset(void);
void DynamicPlaceholderTextUtil_SetPlaceholderPtr(u8 idx, const u8 *ptr);
u8 *DynamicPlaceholderTextUtil_ExpandPlaceholders(u8 *dest, const u8 *src);
const u8 *DynamicPlaceholderTextUtil_GetPlaceholderPtr(u8 idx);

#endif //GUARD_DYNAMIC_PLACEHOLDER_TEXT_UTIL_H
