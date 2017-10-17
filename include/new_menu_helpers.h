#ifndef GUARD_NEW_MENU_HELPERS_H
#define GUARD_NEW_MENU_HELPERS_H

#include "text.h"

void sub_81973A4(void);
void sub_81973C4(u8, u8);
void sub_819746C(u8 windowId, bool8 copyToVram);
void sub_81973FC(u8, u8);
u16 AddTextPrinterParametrized(u8 windowId, u8 fontId, const u8 *str, u8 speed, void ( *callback)(u16, struct TextPrinter *), u8 fgColor, u8 bgColor, u8 shadowColor);

#endif // GUARD_NEW_MENU_HELPERS_H
