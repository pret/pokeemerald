#include "global.h"
#include "task.h"
#include "window.h"
#include "menu.h"
#include "menu_helpers.h"
#include "gpu_regs.h"
#include "bg.h"
#include "main.h"
#include "text.h"
#include "link.h"
#include "string_util.h"
#include "sound.h"
#include "mail.h"
#include "overworld.h"
#include "decompress.h"
#include "constants/songs.h"
#include "constants/items.h"
#include "constants/maps.h"

extern u8 gUnknown_0203A140;
extern TaskFunc gUnknown_0300117C;
extern struct YesNoFuncTable gUnknown_0203A138;

extern const struct CompressedSpriteSheet gUnknown_0859F514;
extern const struct CompressedSpritePalette gUnknown_0859F51C;

extern bool32 InUnionRoom(void);
extern bool32 sub_800B504(void);

// this file's functions
void Task_ContinueTaskAfterMessagePrints(u8 taskId);
void Task_CallYesOrNoCallback(u8 taskId);

// code
void ResetVramOamAndBgCntRegs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    CpuFill16(0, (void*) VRAM, VRAM_SIZE);
    CpuFill32(0, (void*) OAM, OAM_SIZE);
    CpuFill16(0, (void*) PLTT, PLTT_SIZE);
}

void ResetAllBgsCoordinates(void)
{
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
}

void SetVBlankHBlankCallbacksToNull(void)
{
    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
}

void DisplayMessageAndContinueTask(u8 taskId, u8 windowId, u16 arg2, u8 arg3, u8 fontId, u8 textSpeed, const u8 *string, void *taskFunc)
{
    gUnknown_0203A140 = windowId;
    sub_8197B1C(windowId, TRUE, arg2, arg3);

    if (string != gStringVar4)
        StringExpandPlaceholders(gStringVar4, string);

    gTextFlags.flag_0 = 1;
    AddTextPrinterParameterized(windowId, fontId, gStringVar4, textSpeed, NULL, 2, 1, 3);
    gUnknown_0300117C = taskFunc;
    gTasks[taskId].func = Task_ContinueTaskAfterMessagePrints;
}

bool16 RunTextPrintersRetIsActive(u8 textPrinterId)
{
    RunTextPrinters();
    return IsTextPrinterActive(textPrinterId);
}

void Task_ContinueTaskAfterMessagePrints(u8 taskId)
{
    if (!RunTextPrintersRetIsActive(gUnknown_0203A140))
        gUnknown_0300117C(taskId);
}

void sub_8121F68(u8 taskId, const struct YesNoFuncTable *data)
{
    gUnknown_0203A138 = *data;
    gTasks[taskId].func = Task_CallYesOrNoCallback;
}

void CreateYesNoMenuWithCallbacks(u8 taskId, const struct WindowTemplate *template, u8 arg2, u8 arg3, u8 arg4, u16 tileStart, u8 palette, const struct YesNoFuncTable *yesNo)
{
    CreateYesNoMenu(template, tileStart, palette, 0);
    gUnknown_0203A138 = *yesNo;
    gTasks[taskId].func = Task_CallYesOrNoCallback;
}

void Task_CallYesOrNoCallback(u8 taskId)
{
    switch (ProcessMenuInputNoWrap_())
    {
    case 0:
        PlaySE(SE_SELECT);
        gUnknown_0203A138.yesFunc(taskId);
        break;
    case 1:
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        gUnknown_0203A138.noFunc(taskId);
        break;
    }
}

bool8 AdjustQuantityAccordingToDPadInput(s16 *arg0, u16 arg1)
{
    s16 valBefore = (*arg0);

    if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_UP)
    {
        (*arg0)++;
        if ((*arg0) > arg1)
            (*arg0) = 1;

        if ((*arg0) == valBefore)
        {
            return FALSE;
        }
        else
        {
            PlaySE(SE_SELECT);
            return TRUE;
        }
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_DOWN)
    {
        (*arg0)--;
        if ((*arg0) <= 0)
            (*arg0) = arg1;

        if ((*arg0) == valBefore)
        {
            return FALSE;
        }
        else
        {
            PlaySE(SE_SELECT);
            return TRUE;
        }
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_RIGHT)
    {
        (*arg0) += 10;
        if ((*arg0) > arg1)
            (*arg0) = arg1;

        if ((*arg0) == valBefore)
        {
            return FALSE;
        }
        else
        {
            PlaySE(SE_SELECT);
            return TRUE;
        }
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_LEFT)
    {
        (*arg0) -= 10;
        if ((*arg0) <= 0)
            (*arg0) = 1;

        if ((*arg0) == valBefore)
        {
            return FALSE;
        }
        else
        {
            PlaySE(SE_SELECT);
            return TRUE;
        }
    }

    return FALSE;
}

u8 GetLRKeysState(void)
{
    if (gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)
    {
        if (gMain.newKeys & L_BUTTON)
            return 1;
        if (gMain.newKeys & R_BUTTON)
            return 2;
    }

    return 0;
}

u8 sub_812210C(void)
{
    if (gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)
    {
        if (gMain.newAndRepeatedKeys & L_BUTTON)
            return 1;
        if (gMain.newAndRepeatedKeys & R_BUTTON)
            return 2;
    }

    return 0;
}

bool8 sub_8122148(u16 itemId)
{
    if (itemId != ITEM_ENIGMA_BERRY)
        return TRUE;
    else if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(TRADE_CENTER) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(TRADE_CENTER))
        return FALSE;
    else if (InUnionRoom() != TRUE)
        return TRUE;
    else
        return FALSE;
}

bool8 itemid_80BF6D8_mail_related(u16 itemId)
{
    if (is_c1_link_related_active() != TRUE && InUnionRoom() != TRUE)
        return TRUE;
    else if (ItemIsMail(itemId) != TRUE)
        return TRUE;
    else
        return FALSE;
}

bool8 sub_81221AC(void)
{
    if (is_c1_link_related_active() == TRUE || gReceivedRemoteLinkPlayers == 1)
        return TRUE;
    else
        return FALSE;
}

static bool8 sub_81221D0(void)
{
    if (!sub_81221AC())
        return FALSE;
    else
        return sub_8087598();
}

bool8 sub_81221EC(void)
{
    if (sub_81221D0() == TRUE)
        return TRUE;
    else if (sub_800B504() != TRUE)
        return FALSE;
    else
        return TRUE;
}

void sub_812220C(struct ItemSlot *slots, u8 count, u8 *arg2, u8 *usedSlotsCount, u8 maxUsedSlotsCount)
{
    u16 i;
    struct ItemSlot *slots_ = slots;

    (*usedSlotsCount) = 0;
    for (i = 0; i < count; i++)
    {
        if (slots_[i].itemId != ITEM_NONE)
            (*usedSlotsCount)++;
    }

    (*usedSlotsCount)++;
    if ((*usedSlotsCount) > maxUsedSlotsCount)
        *arg2 = maxUsedSlotsCount;
    else
        *arg2 = (*usedSlotsCount);
}

void sub_812225C(u16 *arg0, u16 *arg1, u8 arg2, u8 arg3)
{
    if ((*arg0) != 0 && (*arg0) + arg2 > arg3)
        (*arg0) = arg3 - arg2;

    if ((*arg0) + (*arg1) >= arg3)
    {
        if (arg3 == 0)
            (*arg1) = 0;
        else
            (*arg1) = arg3 - 1;
    }
}

#ifdef NONMATCHING
void sub_8122298(u16 *arg0, u16 *arg1, u8 arg2, u8 arg3, u8 arg4)
{
    if (arg2 & 1)
    {

    }
    else
    {

    }
}
#else
NAKED
void sub_8122298(u16 *arg0, u16 *arg1, u8 arg2, u8 arg3, u8 arg4)
{
    asm_unified("\n\
                	push {r4-r7,lr}\n\
	adds r5, r0, 0\n\
	adds r4, r1, 0\n\
	ldr r0, [sp, 0x14]\n\
	lsls r2, 24\n\
	lsrs r7, r2, 24\n\
	lsls r3, 24\n\
	lsrs r6, r3, 24\n\
	lsls r2, r0, 24\n\
	lsrs r0, r2, 24\n\
	movs r1, 0x1\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _081222F0\n\
	lsrs r2, 25\n\
	ldrh r0, [r4]\n\
	cmp r0, r2\n\
	bcc _08122322\n\
	movs r1, 0\n\
	subs r0, r2\n\
	cmp r1, r0\n\
	bge _08122322\n\
	ldrh r0, [r5]\n\
	adds r0, r7\n\
	cmp r0, r6\n\
	beq _08122322\n\
_081222CC:\n\
	ldrh r0, [r4]\n\
	subs r0, 0x1\n\
	strh r0, [r4]\n\
	ldrh r0, [r5]\n\
	adds r0, 0x1\n\
	strh r0, [r5]\n\
	adds r0, r1, 0x1\n\
	lsls r0, 24\n\
	lsrs r1, r0, 24\n\
	ldrh r0, [r4]\n\
	subs r0, r2\n\
	cmp r1, r0\n\
	bge _08122322\n\
	ldrh r0, [r5]\n\
	adds r0, r7\n\
	cmp r0, r6\n\
	bne _081222CC\n\
	b _08122322\n\
_081222F0:\n\
	ldrh r3, [r4]\n\
	lsrs r2, 25\n\
	adds r0, r2, 0x1\n\
	cmp r3, r0\n\
	blt _08122322\n\
	movs r1, 0\n\
	subs r0, r3, r2\n\
	b _08122316\n\
_08122300:\n\
	ldrh r0, [r4]\n\
	subs r0, 0x1\n\
	strh r0, [r4]\n\
	ldrh r0, [r5]\n\
	adds r0, 0x1\n\
	strh r0, [r5]\n\
	adds r0, r1, 0x1\n\
	lsls r0, 24\n\
	lsrs r1, r0, 24\n\
	ldrh r0, [r4]\n\
	subs r0, r2\n\
_08122316:\n\
	cmp r1, r0\n\
	bgt _08122322\n\
	ldrh r0, [r5]\n\
	adds r0, r7\n\
	cmp r0, r6\n\
	bne _08122300\n\
_08122322:\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0");
}
#endif // NONMATCHING

void LoadListMenuArrowsGfx(void)
{
    LoadCompressedObjectPic(&gUnknown_0859F514);
    LoadCompressedObjectPalette(&gUnknown_0859F51C);
}
