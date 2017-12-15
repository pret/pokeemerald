#ifndef GUARD_MENU_HELPERS_H
#define GUARD_MENU_HELPERS_H

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
void ResetVramOamAndBgCntRegs(void);
void SetVBlankHBlankCallbacksToNull(void);
void ResetAllBgsCoordinates(void);
bool16 RunTextPrintersRetIsActive(u8 textPrinterId);
void sub_8122344(void *arg0, u8 arg1);
void LoadListMenuArrowsGfx(void);
void sub_81223FC(u8 *a0, u8 count, u8 a2);
void sub_8122448(u8 *a0, u8 count, u16 x, u16 y);

#endif //GUARD_MENU_HELPERS_H
