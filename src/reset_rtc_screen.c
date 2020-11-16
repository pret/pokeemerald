#include "global.h"
#include "reset_rtc_screen.h"
#include "event_data.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "rtc.h"
#include "save.h"
#include "sprite.h"
#include "constants/songs.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "scanline_effect.h"
#include "bg.h"
#include "window.h"
#include "gpu_regs.h"
#include "constants/rgb.h"

struct ResetRtcStruct
{
    /*0x0*/ u8 dataIndex;
    /*0x2*/ u16 minVal;
    /*0x4*/ u16 maxVal;
    /*0x6*/ u8 left;
    /*0x7*/ u8 right;
    /*0x8*/ u8 unk8;
};

// this file's functions
static void CB2_ResetRtcScreen(void);
static void VBlankCB(void);
static void Task_ResetRtcScreen(u8 taskId);
static void sub_809F048(void);

// const rom data
static const struct BgTemplate sBackgroundTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    }
};

static const struct WindowTemplate sUnknown_08510408[] =
{
    {0x00, 0x01, 0x01, 0x13, 0x09, 0x0f, 0x0155},
    {0x00, 0x02, 0x0f, 0x1b, 0x04, 0x0f, 0x00e9},
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sUnknown_08510420 = {0x00, 0x04, 0x09, 0x15, 0x02, 0x0f, 0x00bf};

static const struct ResetRtcStruct sUnknown_08510428[5] =
{
    {
        .dataIndex = 3,
        .minVal = 1,
        .maxVal = 9999,
        .left = 0,
        .right = 2,
        .unk8 = 0,
    },
    {
        .dataIndex = 4,
        .minVal = 0,
        .maxVal = 23,
        .left = 1,
        .right = 3,
        .unk8 = 0,
    },
    {
        .dataIndex = 5,
        .minVal = 0,
        .maxVal = 59,
        .left = 2,
        .right = 4,
        .unk8 = 0,
    },
    {
        .dataIndex = 6,
        .minVal = 0,
        .maxVal = 59,
        .left = 3,
        .right = 5,
        .unk8 = 0,
    },
    {
        .dataIndex = 7,
        .minVal = 0,
        .maxVal = 0,
        .left = 4,
        .right = 0,
        .unk8 = 6,
    },
};

static const struct OamData sOamData_08510464 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const u8 sResetRtcScreen_DownArrowGfx[] = INCBIN_U8("graphics/misc/reset_rtc_screen_downarrow.4bpp");
static const u8 sResetRtcScreen_RightArrowGfx[] = INCBIN_U8("graphics/misc/reset_rtc_screen_rightarrow.4bpp");
static const u16 sResetRtcScreen_ArrowPal[] = INCBIN_U16("graphics/misc/reset_rtc_screen_arrow.gbapal");

static const struct SpriteFrameImage sSpriteImageTable_85104B4[] =
{
    obj_frame_tiles(sResetRtcScreen_DownArrowGfx),
    obj_frame_tiles(sResetRtcScreen_RightArrowGfx)
};

const struct SpritePalette gSpritePalette_RtcArrow =
{
    sResetRtcScreen_ArrowPal, 0x1000
};

static const union AnimCmd sSpriteAnim_85104CC[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_85104D4[] =
{
    ANIMCMD_FRAME(0, 30, .vFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_85104DC[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSpriteAnimTable_85104E4[] =
{
    sSpriteAnim_85104CC,
    sSpriteAnim_85104D4,
    sSpriteAnim_85104DC,
};

const struct SpriteTemplate gSpriteTemplate_RtcArrow =
{
    .tileTag = 0xFFFF,
    .paletteTag = 0x1000,
    .oam = &sOamData_08510464,
    .anims = sSpriteAnimTable_85104E4,
    .images = sSpriteImageTable_85104B4,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// code
static void SpriteCB_ResetRtcCursor0(struct Sprite *sprite)
{
    int state = gTasks[sprite->data[0]].data[2];
    if (state != sprite->data[1])
    {
        sprite->data[1] = state;
        switch (state)
        {
        case 1:
            sprite->invisible = FALSE;
            sprite->animNum = 1;
            sprite->animDelayCounter = 0;
            sprite->pos1.x = 53;
            sprite->pos1.y = 68;
            break;
        case 2:
            sprite->invisible = FALSE;
            sprite->animNum = 1;
            sprite->animDelayCounter = 0;
            sprite->pos1.x = 86;
            sprite->pos1.y = 68;
            break;
        case 3:
            sprite->invisible = FALSE;
            sprite->animNum = 1;
            sprite->animDelayCounter = 0;
            sprite->pos1.x = 101;
            sprite->pos1.y = 68;
            break;
        case 4:
            sprite->invisible = FALSE;
            sprite->animNum = 1;
            sprite->animDelayCounter = 0;
            sprite->pos1.x = 116;
            sprite->pos1.y = 68;
            break;
        case 5:
            sprite->invisible = FALSE;
            sprite->animNum = 2;
            sprite->animDelayCounter = 0;
            sprite->pos1.x = 153;
            sprite->pos1.y = 80;
            break;
        case 6:
            DestroySprite(sprite);
            break;
        }
    }
}

static void SpriteCB_ResetRtcCursor1(struct Sprite *sprite)
{
    int state = gTasks[sprite->data[0]].data[2];
    if (state != sprite->data[1])
    {
        sprite->data[1] = state;
        switch (state)
        {
        case 1:
            sprite->invisible = FALSE;
            sprite->animNum = 0;
            sprite->animDelayCounter = 0;
            sprite->pos1.x = 53;
            sprite->pos1.y = 92;
            break;
        case 2:
            sprite->invisible = FALSE;
            sprite->animNum = 0;
            sprite->animDelayCounter = 0;
            sprite->pos1.x = 86;
            sprite->pos1.y = 92;
            break;
        case 3:
            sprite->invisible = FALSE;
            sprite->animNum = 0;
            sprite->animDelayCounter = 0;
            sprite->pos1.x = 101;
            sprite->pos1.y = 92;
            break;
        case 4:
            sprite->invisible = FALSE;
            sprite->animNum = 0;
            sprite->animDelayCounter = 0;
            sprite->pos1.x = 116;
            sprite->pos1.y = 92;
            break;
        case 5:
            sprite->invisible = TRUE;
            break;
        case 6:
            DestroySprite(sprite);
            break;
        }
    }
}

static void CreateCursor(u8 taskId)
{
    u32 spriteId;

    LoadSpritePalette(&gSpritePalette_RtcArrow);

    spriteId = CreateSpriteAtEnd(&gSpriteTemplate_RtcArrow, 53, 68, 0);
    gSprites[spriteId].callback = SpriteCB_ResetRtcCursor0;
    gSprites[spriteId].data[0] = taskId;
    gSprites[spriteId].data[1] = -1;

    spriteId = CreateSpriteAtEnd(&gSpriteTemplate_RtcArrow, 53, 68, 0);
    gSprites[spriteId].callback = SpriteCB_ResetRtcCursor1;
    gSprites[spriteId].data[0] = taskId;
    gSprites[spriteId].data[1] = -1;
}

static void FreeCursorPalette(void)
{
    FreeSpritePaletteByTag(gSpritePalette_RtcArrow.tag);
}

static void HideChooseTimeWindow(u8 windowId)
{
    ClearStdWindowAndFrameToTransparent(windowId, FALSE);
    RemoveWindow(windowId);
    ScheduleBgCopyTilemapToVram(0);
}

static void PrintTime(u8 windowId, u8 x, u8 y, u16 days, u8 hours, u8 minutes, u8 seconds)
{
    u8 *dest = gStringVar4;

    ConvertIntToDecimalStringN(gStringVar1, days, STR_CONV_MODE_RIGHT_ALIGN, 4);
    dest = StringCopy(dest, gStringVar1);
    dest = StringCopy(dest, gText_Day);

    ConvertIntToDecimalStringN(gStringVar1, hours, STR_CONV_MODE_RIGHT_ALIGN, 3);
    dest = StringCopy(dest, gStringVar1);
    dest = StringCopy(dest, gText_Colon3);

    ConvertIntToDecimalStringN(gStringVar1, minutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    dest = StringCopy(dest, gStringVar1);
    dest = StringCopy(dest, gText_Colon3);

    ConvertIntToDecimalStringN(gStringVar1, seconds, STR_CONV_MODE_LEADING_ZEROS, 2);
    dest = StringCopy(dest, gStringVar1);

    AddTextPrinterParameterized(windowId, 1, gStringVar4, x, y, TEXT_SPEED_FF, NULL);
}

static void ShowChooseTimeWindow(u8 windowId, u16 days, u8 hours, u8 minutes, u8 seconds)
{
    DrawStdFrameWithCustomTileAndPalette(windowId, FALSE, 0x214, 0xE);
    PrintTime(windowId, 0, 1, days, hours, minutes, seconds);
    AddTextPrinterParameterized(windowId, 1, gText_Confirm2, 126, 1, 0, NULL);
    ScheduleBgCopyTilemapToVram(0);
}

static bool32 MoveTimeUpDown(s16 *val, int minVal, int maxVal, u16 keys)
{
    if (keys & DPAD_DOWN)
    {
        *val -= 1;
        if (*val < minVal)
            *val = maxVal;
    }
    else if (keys & DPAD_UP)
    {
        *val += 1;
        if (*val > maxVal)
            *val = minVal;
    }
    else if (keys & DPAD_LEFT)
    {
        *val -= 10;
        if (*val < minVal)
            *val = maxVal;
    }
    else if (keys & DPAD_RIGHT)
    {
        *val += 10;
        if (*val > maxVal)
            *val = minVal;
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

static void Task_ResetRtc_3(u8 taskId)
{
    gTasks[taskId].data[0] = 1;
}

static void Task_ResetRtc_2(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    HideChooseTimeWindow(data[8]);
    FreeCursorPalette();
    gTasks[taskId].func = Task_ResetRtc_3;
}

static void Task_ResetRtc_1(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 selection = data[2];
    const struct ResetRtcStruct *selectionInfo = &sUnknown_08510428[selection - 1];

    if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].func = Task_ResetRtc_2;
        data[1] = 0;
        data[2] = 6;
        PlaySE(SE_SELECT);
        return;
    }

    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selectionInfo->right)
        {
            data[2] = selectionInfo->right;
            PlaySE(SE_SELECT);
            return;
        }
    }

    if (JOY_NEW(DPAD_LEFT))
    {
        if (selectionInfo->left)
        {
            data[2] = selectionInfo->left;
            PlaySE(SE_SELECT);
            return;
        }
    }

    if (selection == 5)
    {
        if (JOY_NEW(A_BUTTON))
        {
            gLocalTime.days = data[3];
            gLocalTime.hours = data[4];
            gLocalTime.minutes = data[5];
            gLocalTime.seconds = data[6];
            PlaySE(SE_SELECT);
            gTasks[taskId].func = Task_ResetRtc_2;
            data[1] = 1;
            data[2] = 6;
        }
    }
    else if (MoveTimeUpDown(&data[selectionInfo->dataIndex], selectionInfo->minVal, selectionInfo->maxVal, JOY_REPEAT(DPAD_UP | DPAD_DOWN)))
    {
        PlaySE(SE_SELECT);
        PrintTime(data[8], 0, 1, data[3], data[4], data[5], data[6]);
        CopyWindowToVram(data[8], 2);
    }
}

static void Task_ResetRtc_0(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    data[0] = 0;
    data[3] = gLocalTime.days;
    data[4] = gLocalTime.hours;
    data[5] = gLocalTime.minutes;
    data[6] = gLocalTime.seconds;
    data[8] = AddWindow(&sUnknown_08510420);
    ShowChooseTimeWindow(data[8], data[3], data[4], data[5], data[6]);
    CreateCursor(taskId);
    data[2] = 2;
    gTasks[taskId].func = Task_ResetRtc_1;
}

void CB2_InitResetRtcScreen(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetVBlankCallback(NULL);
    DmaClear16(3, PLTT, PLTT_SIZE);
    DmaFillLarge16(3, 0, (u8 *)VRAM, 0x18000, 0x1000);
    ResetOamRange(0, 128);
    LoadOam();
    ScanlineEffect_Stop();
    ScanlineEffect_Clear();
    ResetSpriteData();
    ResetTasks();
    ResetPaletteFade();
    sub_809F048();
    SetVBlankCallback(VBlankCB);
    SetMainCallback2(CB2_ResetRtcScreen);
    CreateTask(Task_ResetRtcScreen, 80);
}

static void sub_809F048(void)
{
    ClearScheduledBgCopiesToVram();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBackgroundTemplates, ARRAY_COUNT(sBackgroundTemplates));
    ScheduleBgCopyTilemapToVram(0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    InitWindows(sUnknown_08510408);
    DeactivateAllTextPrinters();
    LoadMessageBoxAndBorderGfx();
}

static void CB2_ResetRtcScreen(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    ProcessSpriteCopyRequests();
    LoadOam();
    TransferPlttBuffer();
}

static void ShowMessage(const u8 *str)
{
    DrawDialogFrameWithCustomTileAndPalette(1, FALSE, 0x200, 0xF);
    AddTextPrinterParameterized(1, 1, str, 0, 1, 0, NULL);
    ScheduleBgCopyTilemapToVram(0);
}

static void Task_ShowResetRtcPrompt(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        DrawStdFrameWithCustomTileAndPalette(0, FALSE, 0x214, 0xE);
        AddTextPrinterParameterized(0, 1, gText_PresentTime, 0, 1, TEXT_SPEED_FF, 0);
        PrintTime(
            0,
            0,
            17,
            gLocalTime.days,
            gLocalTime.hours,
            gLocalTime.minutes,
            gLocalTime.seconds);
        AddTextPrinterParameterized(0, 1, gText_PreviousTime, 0, 33, TEXT_SPEED_FF, 0);
        PrintTime(
            0,
            0,
            49,
            gSaveBlock2Ptr->lastBerryTreeUpdate.days,
            gSaveBlock2Ptr->lastBerryTreeUpdate.hours,
            gSaveBlock2Ptr->lastBerryTreeUpdate.minutes,
            gSaveBlock2Ptr->lastBerryTreeUpdate.seconds);
        ShowMessage(gText_ResetRTCConfirmCancel);
        CopyWindowToVram(0, 2);
        ScheduleBgCopyTilemapToVram(0);
        data[0]++;
    case 1:
        if (JOY_NEW(B_BUTTON))
        {
            DestroyTask(taskId);
            DoSoftReset();
        }
        else if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            DestroyTask(taskId);
        }
        break;
    }
}

static void Task_ResetRtcScreen(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 1, 0x10, 0, RGB_WHITEALPHA);
        data[0] = 1;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            if (gSaveFileStatus == SAVE_STATUS_EMPTY || gSaveFileStatus == SAVE_STATUS_CORRUPT)
            {
                ShowMessage(gText_NoSaveFileCantSetTime);
                data[0] = 5;
            }
            else
            {
                RtcCalcLocalTime();
                data[1] = CreateTask(Task_ShowResetRtcPrompt, 80);
                data[0] = 2;
            }
        }
        break;
    case 2:
        if (gTasks[data[1]].isActive != TRUE)
        {
            ClearStdWindowAndFrameToTransparent(0, FALSE);
            ShowMessage(gText_PleaseResetTime);
            gLocalTime = gSaveBlock2Ptr->lastBerryTreeUpdate;
            data[1] = CreateTask(Task_ResetRtc_0, 80);
            data[0] = 3;
        }
        break;
    case 3:
        if (gTasks[data[1]].data[0])
        {
            if (!gTasks[data[1]].data[1])
            {
                DestroyTask(data[1]);
                data[0] = 2;
            }
            else
            {
                DestroyTask(data[1]);
                RtcReset();
                RtcCalcLocalTimeOffset(
                    gLocalTime.days,
                    gLocalTime.hours,
                    gLocalTime.minutes,
                    gLocalTime.seconds);
                gSaveBlock2Ptr->lastBerryTreeUpdate = gLocalTime;
                VarSet(VAR_DAYS, gLocalTime.days);
                DisableResetRTC();
                ShowMessage(gText_ClockHasBeenReset);
                data[0] = 4;
            }
        }
        break;
    case 4:
        if (TrySavingData(SAVE_NORMAL) == SAVE_STATUS_OK)
        {
            ShowMessage(gText_SaveCompleted);
            PlaySE(SE_DING_DONG);
        }
        else
        {
            ShowMessage(gText_SaveFailed);
            PlaySE(SE_BOO);
        }
        data[0] = 5;
    case 5:
        if (JOY_NEW(A_BUTTON))
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 1, 0, 0x10, RGB_WHITEALPHA);
            data[0] = 6;
        }
        else
        {
            break;
        }
    case 6:
        if (!gPaletteFade.active)
        {
            DestroyTask(taskId);
            FreeAllWindowBuffers();
            DoSoftReset();
        }
    }
}
