#ifndef GUARD_NEW_MENU_HELPERS_H
#define GUARD_NEW_MENU_HELPERS_H

#include "text.h"
#include "task.h"

extern const u16 gUnknown_0860F074[];

void sub_81971D0(void);
void sub_8197200(void);
void sub_81973A4(void);
void sub_81973C4(u8, u8);
void sub_819746C(u8 windowId, bool8 copyToVram);
void sub_81973FC(u8, u8);
u16 AddTextPrinterParameterized(u8 windowId, u8 fontId, const u8 *str, u8 speed, void ( *callback)(u16, struct TextPrinter *), u8 fgColor, u8 bgColor, u8 shadowColor);
void DisplayItemMessageOnField(u8 taskId, const u8 *src, TaskFunc callback);
void sub_8197434(u8 a0, u8 a1);
void SetStandardWindowBorderStyle(u8 a0, u8 a1);
void sub_8197930(void);
u8 GetPlayerTextSpeed(void);
void sub_81978B0(u16 arg0);
u16 sub_8197224(void);
int sub_8196094(void);
void sub_8196080(u8*);
void AddTextPrinterForMessage(u8);

#endif // GUARD_NEW_MENU_HELPERS_H
