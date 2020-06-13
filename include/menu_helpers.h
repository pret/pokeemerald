#ifndef GUARD_MENU_HELPERS_H
#define GUARD_MENU_HELPERS_H

#include "task.h"
#include "window.h"

#define MENU_L_PRESSED 1
#define MENU_R_PRESSED 2

// Exported type declarations

struct YesNoFuncTable
{
    TaskFunc yesFunc;
    TaskFunc noFunc;
};

// Exported RAM declarations

// Exported ROM declarations
void ResetVramOamAndBgCntRegs(void);
void ResetAllBgsCoordinates(void);
void SetVBlankHBlankCallbacksToNull(void);
void DisplayMessageAndContinueTask(u8 taskId, u8 windowId, u16 arg2, u8 arg3, u8 fontId, u8 textSpeed, const u8 *string, void *taskFunc);
bool16 RunTextPrintersRetIsActive(u8 textPrinterId);
void DoYesNoFuncWithChoice(u8 taskId, const struct YesNoFuncTable *data);
void CreateYesNoMenuWithCallbacks(u8 taskId, const struct WindowTemplate *template, u8 arg2, u8 arg3, u8 arg4, u16 tileStart, u8 palette, const struct YesNoFuncTable *yesNo);
bool8 AdjustQuantityAccordingToDPadInput(s16 *arg0, u16 arg1);
u8 GetLRKeysPressed(void);
u8 GetLRKeysPressedAndHeld(void);
bool8 sub_8122148(u16 itemId);
bool8 itemid_80BF6D8_mail_related(u16 itemId);
bool8 MenuHelpers_LinkSomething(void);
bool8 MenuHelpers_CallLinkSomething(void);
void sub_812220C(struct ItemSlot *slots, u8 count, u8 *arg2, u8 *usedSlotsCount, u8 maxUsedSlotsCount);
void sub_812225C(u16 *scrollOffset, u16 *cursorPos, u8 maxShownItems, u8 numItems);
void sub_8122298(u16 *arg0, u16 *arg1, u8 arg2, u8 arg3, u8 arg4);
void LoadListMenuArrowsGfx(void);
void sub_8122344(u8 *spriteIds, u8 count);
void sub_81223B0(u8 *spriteIds, u8 count);
void sub_81223FC(u8 *spriteIds, u8 count, bool8 invisible);
void sub_8122448(u8 *spriteIds, u8 count, s16 x, u16 y);

#endif //GUARD_MENU_HELPERS_H
