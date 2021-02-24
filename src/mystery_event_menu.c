#include "global.h"
#include "mystery_event_menu.h"
#include "link.h"
#include "main.h"
#include "menu.h"
#include "mystery_event_script.h"
#include "palette.h"
#include "save.h"
#include "constants/songs.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "bg.h"
#include "window.h"
#include "gpu_regs.h"
#include "text_window.h"
#include "decompress.h"
#include "constants/rgb.h"

// this file's functions
static void CB2_MysteryEventMenu(void);
static void PrintMysteryMenuText(u8 windowId, const u8 *text, u8 x, u8 y, s32 speed);

// EWRAM vars
static EWRAM_DATA u8 sUnknown_0203BCF8 = 0; // set but unused

// const rom data
static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    }
};

static const struct WindowTemplate sWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 4,
        .tilemapTop = 15,
        .width = 22,
        .height = 4,
        .paletteNum = 14,
        .baseBlock = 20
    },
    {
        .bg = 0,
        .tilemapLeft = 7,
        .tilemapTop = 6,
        .width = 16,
        .height = 4,
        .paletteNum = 14,
        .baseBlock = 0x6C
    },
    DUMMY_WIN_TEMPLATE
};

// code
static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static bool8 CheckLanguageMatch(void)
{
    return (gLinkPlayers[0].language == gLinkPlayers[1].language);
}

void CB2_InitMysteryEventMenu(void)
{
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetTasks();
    SetVBlankCallback(VBlankCB);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    if (InitWindows(sWindowTemplates))
    {
        s32 i;

        DeactivateAllTextPrinters();
        for (i = 0; i < 2; i++)
            FillWindowPixelBuffer(i, PIXEL_FILL(0));

        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x1E, 0x14);
        LoadUserWindowBorderGfx(0, 1u, 0xD0u);
        Menu_LoadStdPalAt(0xE0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        CreateTask(Task_DestroySelf, 0);
        StopMapMusic();
        RunTasks();
        AnimateSprites();
        BuildOamBuffer();
        RunTextPrinters();
        UpdatePaletteFade();
        FillPalette(0, 0, 2);
        SetMainCallback2(CB2_MysteryEventMenu);
    }
}

static bool8 GetEventLoadMessage(u8 *dest, u32 status)
{
    bool8 retVal = TRUE;

    if (status == 0)
    {
        StringCopy(dest, gText_EventSafelyLoaded);
        retVal = FALSE;
    }

    if (status == 2)
        retVal = FALSE;

    if (status == 1)
        StringCopy(dest, gText_LoadErrorEndingSession);

    return retVal;
}

static void CB2_MysteryEventMenu(void)
{
    switch (gMain.state)
    {
    case 0:
        DrawStdFrameWithCustomTileAndPalette(0, 1, 1, 0xD);
        PutWindowTilemap(0);
        CopyWindowToVram(0, 3);
        ShowBg(0);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            PrintMysteryMenuText(0, gText_LinkStandby2, 1, 2, 1);
            gMain.state++;
        }
        break;
    case 2:
        if (!IsTextPrinterActive(0))
        {
            gMain.state++;
            gLinkType = LINKTYPE_MYSTERY_EVENT;
            OpenLink();
        }
        break;
    case 3:
        if ((gLinkStatus & 0x20) && (gLinkStatus & 0x1C) > 4)
        {
            PlaySE(SE_PIN);
            PrintMysteryMenuText(0, gText_PressAToLoadEvent, 1, 2, 1);
            gMain.state++;
        }
        if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            CloseLink();
            gMain.state = 15;
        }
        break;
    case 4:
        if (!IsTextPrinterActive(0))
            gMain.state++;
        break;
    case 5:
        if (GetLinkPlayerCount_2() == 2)
        {
            if (JOY_NEW(A_BUTTON))
            {
                PlaySE(SE_SELECT);
                CheckShouldAdvanceLinkState();
                DrawStdFrameWithCustomTileAndPalette(1, 1, 1, 0xD);
                PrintMysteryMenuText(1, gText_LoadingEvent, 1, 2, 0);
                PutWindowTilemap(1);
                CopyWindowToVram(1, 3);
                gMain.state++;
            }
            else if (JOY_NEW(B_BUTTON))
            {
                PlaySE(SE_SELECT);
                CloseLink();
                gMain.state = 15;
            }
        }
        else
        {
            GetEventLoadMessage(gStringVar4, 1);
            PrintMysteryMenuText(0, gStringVar4, 1, 2, 1);
            gMain.state = 13;
        }
        break;
    case 6:
        if (IsLinkConnectionEstablished())
        {
            if (gReceivedRemoteLinkPlayers != 0)
            {
                if (GetLinkPlayerDataExchangeStatusTimed(2, 2) == EXCHANGE_DIFF_SELECTIONS)
                {
                    SetCloseLinkCallback();
                    GetEventLoadMessage(gStringVar4, 1);
                    PrintMysteryMenuText(0, gStringVar4, 1, 2, 1);
                    gMain.state = 13;
                }
                else if (CheckLanguageMatch())
                {
                    PrintMysteryMenuText(0, gText_DontRemoveCableTurnOff, 1, 2, 1);
                    gMain.state++;
                }
                else
                {
                    CloseLink();
                    GetEventLoadMessage(gStringVar4, 1);
                    PrintMysteryMenuText(0, gStringVar4, 1, 2, 1);
                    gMain.state = 13;
                }
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            CloseLink();
            gMain.state = 15;
        }
        break;
    case 7:
        if (!IsTextPrinterActive(0))
            gMain.state++;
        break;
    case 8:
        if (GetBlockReceivedStatus())
        {
            ResetBlockReceivedFlags();
            gMain.state++;
        }
        break;
    case 9:
        gMain.state++;
        break;
    case 10:
        SetCloseLinkCallback();
        gMain.state++;
        break;
    case 11:
        if (gReceivedRemoteLinkPlayers == 0)
        {
            u16 unkVal = RunMysteryEventScript(gDecompressionBuffer);
            CpuFill32(0, gDecompressionBuffer, 0x7D4);
            if (!GetEventLoadMessage(gStringVar4, unkVal))
                TrySavingData(SAVE_NORMAL);
            gMain.state++;
        }
        break;
    case 12:
        PrintMysteryMenuText(0, gStringVar4, 1, 2, 1);
        gMain.state++;
        break;
    case 13:
        if (!IsTextPrinterActive(0))
        {
            gMain.state++;
            sUnknown_0203BCF8 = 0;
        }
        break;
    case 14:
        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            gMain.state++;
        }
        break;
    case 15:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
        gMain.state++;
        break;
    case 16:
        if (!gPaletteFade.active)
            DoSoftReset();
        break;
    }

    if (gLinkStatus & 0x40 && !IsLinkMaster())
    {
        CloseLink();
        GetEventLoadMessage(gStringVar4, 1);
        PrintMysteryMenuText(0, gStringVar4, 1, 2, 1);
        gMain.state = 13;
    }

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

static void PrintMysteryMenuText(u8 windowId, const u8 *text, u8 x, u8 y, s32 speed)
{
    u8 textColor[3];
    u8 letterSpacing = 0;
    u8 lineSpacing = 1;
    textColor[0] = 1;
    textColor[1] = 2;
    textColor[2] = 3;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(textColor[0]));
    AddTextPrinterParameterized4(windowId, 1, x, y, letterSpacing, lineSpacing, textColor, speed, text);
}
