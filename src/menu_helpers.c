#include "global.h"
#include "task.h"
#include "window.h"
#include "menu.h"
#include "menu_helpers.h"
#include "gpu_regs.h"
#include "bg.h"
#include "main.h"
#include "text.h"
#include "graphics.h"
#include "link.h"
#include "string_util.h"
#include "sound.h"
#include "mail.h"
#include "overworld.h"
#include "decompress.h"
#include "constants/songs.h"
#include "constants/items.h"
#include "constants/maps.h"

// this file's functions
static void Task_ContinueTaskAfterMessagePrints(u8 taskId);
static void Task_CallYesOrNoCallback(u8 taskId);

// EWRAM vars
EWRAM_DATA static struct YesNoFuncTable gUnknown_0203A138 = {0};
EWRAM_DATA static u8 gUnknown_0203A140 = 0;

// IWRAM bss vars
static TaskFunc gUnknown_0300117C;

// const rom data
static const struct OamData sOamData_859F4E8 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_859F4F0[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_859F4F8[] =
{
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_859F500[] =
{
    ANIMCMD_FRAME(0, 0, 1, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_859F508[] =
{
    sSpriteAnim_859F4F0,
    sSpriteAnim_859F4F8,
    sSpriteAnim_859F500
};

static const struct CompressedSpriteSheet gUnknown_0859F514 =
{
    gBagSwapLineGfx, 0x100, 109
};

static const struct CompressedSpritePalette gUnknown_0859F51C =
{
    gBagSwapLinePal, 109
};

static const struct SpriteTemplate gUnknown_0859F524 =
{
    .tileTag = 109,
    .paletteTag = 109,
    .oam = &sOamData_859F4E8,
    .anims = sSpriteAnimTable_859F508,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

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
    DrawDialogFrameWithCustomTileAndPalette(windowId, TRUE, arg2, arg3);

    if (string != gStringVar4)
        StringExpandPlaceholders(gStringVar4, string);

    gTextFlags.canABSpeedUpPrint = 1;
    AddTextPrinterParameterized2(windowId, fontId, gStringVar4, textSpeed, NULL, 2, 1, 3);
    gUnknown_0300117C = taskFunc;
    gTasks[taskId].func = Task_ContinueTaskAfterMessagePrints;
}

bool16 RunTextPrintersRetIsActive(u8 textPrinterId)
{
    RunTextPrinters();
    return IsTextPrinterActive(textPrinterId);
}

static void Task_ContinueTaskAfterMessagePrints(u8 taskId)
{
    if (!RunTextPrintersRetIsActive(gUnknown_0203A140))
        gUnknown_0300117C(taskId);
}

void DoYesNoFuncWithChoice(u8 taskId, const struct YesNoFuncTable *data)
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

static void Task_CallYesOrNoCallback(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
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

    if ((JOY_REPEAT(DPAD_ANY)) == DPAD_UP)
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
    else if ((JOY_REPEAT(DPAD_ANY)) == DPAD_DOWN)
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
    else if ((JOY_REPEAT(DPAD_ANY)) == DPAD_RIGHT)
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
    else if ((JOY_REPEAT(DPAD_ANY)) == DPAD_LEFT)
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

u8 GetLRKeysPressed(void)
{
    if (gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)
    {
        if (JOY_NEW(L_BUTTON))
            return MENU_L_PRESSED;
        if (JOY_NEW(R_BUTTON))
            return MENU_R_PRESSED;
    }

    return 0;
}

u8 GetLRKeysPressedAndHeld(void)
{
    if (gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)
    {
        if (JOY_REPEAT(L_BUTTON))
            return MENU_L_PRESSED;
        if (JOY_REPEAT(R_BUTTON))
            return MENU_R_PRESSED;
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
    if (IsUpdateLinkStateCBActive() != TRUE && InUnionRoom() != TRUE)
        return TRUE;
    else if (ItemIsMail(itemId) != TRUE)
        return TRUE;
    else
        return FALSE;
}

bool8 MenuHelpers_LinkSomething(void)
{
    if (IsUpdateLinkStateCBActive() == TRUE || gReceivedRemoteLinkPlayers == 1)
        return TRUE;
    else
        return FALSE;
}

static bool8 sub_81221D0(void)
{
    if (!MenuHelpers_LinkSomething())
        return FALSE;
    else
        return sub_8087598();
}

bool8 MenuHelpers_CallLinkSomething(void)
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

void sub_812225C(u16 *scrollOffset, u16 *cursorPos, u8 maxShownItems, u8 numItems)
{
    if (*scrollOffset != 0 && *scrollOffset + maxShownItems > numItems)
        *scrollOffset = numItems - maxShownItems;

    if (*scrollOffset + *cursorPos >= numItems)
    {
        if (numItems == 0)
            *cursorPos = 0;
        else
            *cursorPos = numItems - 1;
    }
}

void sub_8122298(u16 *arg0, u16 *arg1, u8 arg2, u8 arg3, u8 arg4)
{
    u8 i;

    if (arg4 % 2 != 0)
    {
        if ((*arg1) >= arg4 / 2)
        {
            for (i = 0; i < (*arg1) - (arg4 / 2); i++)
            {
                if ((*arg0) + arg2 == arg3)
                    break;
                (*arg1)--;
                (*arg0)++;
            }
        }
    }
    else
    {
        if ((*arg1) >= (arg4 / 2) + 1)
        {
            for (i = 0; i <= (*arg1) - (arg4 / 2); i++)
            {
                if ((*arg0) + arg2 == arg3)
                    break;
                (*arg1)--;
                (*arg0)++;
            }
        }
    }
}

void LoadListMenuArrowsGfx(void)
{
    LoadCompressedSpriteSheet(&gUnknown_0859F514);
    LoadCompressedSpritePalette(&gUnknown_0859F51C);
}

void sub_8122344(u8 *spriteIds, u8 count)
{
    u8 i;

    for (i = 0; i < count; i++)
    {
        spriteIds[i] = CreateSprite(&gUnknown_0859F524, i * 16, 0, 0);
        if (i != 0)
            StartSpriteAnim(&gSprites[spriteIds[i]], 1);

        gSprites[spriteIds[i]].invisible = TRUE;
    }
}

void sub_81223B0(u8 *spriteIds, u8 count)
{
    u8 i;

    for (i = 0; i < count; i++)
    {
        if (i == count - 1)
            DestroySpriteAndFreeResources(&gSprites[spriteIds[i]]);
        else
            DestroySprite(&gSprites[spriteIds[i]]);
    }
}

void sub_81223FC(u8 *spriteIds, u8 count, bool8 invisible)
{
    u8 i;

    for (i = 0; i < count; i++)
    {
        gSprites[spriteIds[i]].invisible = invisible;
    }
}

void sub_8122448(u8 *spriteIds, u8 count, s16 x, u16 y)
{
    u8 i;
    bool8 unknownBit = count & 0x80;
    count &= ~(0x80);

    for (i = 0; i < count; i++)
    {
        if (i == count - 1 && unknownBit)
            gSprites[spriteIds[i]].pos2.x = x - 8;
        else
            gSprites[spriteIds[i]].pos2.x = x;

        gSprites[spriteIds[i]].pos1.y = 1 + y;
    }
}
