#ifndef GUARD_MENU_HELPERS_H
#define GUARD_MENU_HELPERS_H

#include "task.h"

// Exported type declarations

struct YesNoFuncTable
{
    TaskFunc yesFunc;
    TaskFunc noFunc;
};

// Exported RAM declarations

// Exported ROM declarations

void sub_812225C(u16 *, u16 *, u8, u8);
void sub_8122298(u16 *, u16 *, u8, u8, u8);
void sub_8121F68(u8 taskId, const struct YesNoFuncTable *data);
bool8 sub_81221AC(void);
bool8 sub_81221EC(void);
void ResetVramOamAndBgCntRegs(void);
void SetVBlankHBlankCallbacksToNull(void);
void ResetAllBgsCoordinates(void);
bool16 RunTextPrintersRetIsActive(u8 textPrinterId);
void sub_8122344(void *arg0, u8 arg1);
void LoadListMenuArrowsGfx(void);
void sub_81223FC(u8 *a0, u8 count, u8 a2);
void sub_8122448(u8 *a0, u8 count, u16 x, u16 y);
void DisplayMessageAndContinueTask(u8 taskId, u8 arg1, u16 arg2, u8 arg3, u8 arg4, u8 textSpeed, const u8 *string, void *taskFunc);
void CreateYesNoMenuWithCallbacks(u8 taskId, const struct WindowTemplate *template, u8 arg2, u8 arg3, u8 arg4, u16 tileStart, u8 palette, const struct YesNoFuncTable *yesNo);
u8 GetLRKeysState(void);
u8 sub_812210C(void);
bool8 sub_81221EC(void);
bool8 sub_81221AC(void);
bool8 sub_8122148(u16);
bool8 AdjustQuantityAccordingToDPadInput(s16*, u16);
bool8 itemid_80BF6D8_mail_related(u16);

#endif //GUARD_MENU_HELPERS_H
