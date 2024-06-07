#include "global.h"
#include "bg.h"
#include "sprite.h"
#include "palette.h"
#include "task.h"
#include "m4a.h"
#include "main.h"
#include "text.h"
#include "menu.h"
#include "gpu_regs.h"
#include "scanline_effect.h"
#include "string_util.h"
#include "title_screen.h"
#include "sound.h"
#include "trainer_pokemon_sprites.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#define tWindowSelected data[0]
#define tBgmIndex data[1]
#define tSeIndex data[2]
#define tBgmIndexOld data[3]
#define tSeIndexOld data[4]
#define tWhichSubmenu data[14]
#define tState data[15]

// wonky dim access macro
#define MULTI_DIM_ARR(x, dim, y) ((x) * dim + (y))

// dim access enums
enum
{
    B_8 = 1,
    B_16 = 2,
    B_32 = 4
};

// windows
enum
{
    WIN_INFO,
    WIN_MUS,
    WIN_SE,
    WIN_COUNT
};

// selected test
enum
{
    TEST_MUS,
    TEST_SE
};

// driver test cry enums
enum
{
    CRY_TEST_VOICE,
    CRY_TEST_VOLUME,
    CRY_TEST_PANPOT,
    CRY_TEST_PITCH,
    CRY_TEST_LENGTH,
    CRY_TEST_RELEASE,
    CRY_TEST_PROGRESS,
    CRY_TEST_CHORUS,
    CRY_TEST_PRIORITY
};

// minmax range enums
enum
{
    MIN,
    MAX
};

extern struct ToneData gCryTable[];
extern struct ToneData gCryTable_Reverse[];

static EWRAM_DATA u8 sIsFastForwarding = 0;
static EWRAM_DATA u8 sDriverTest_IsCryPlaying = 0;
static EWRAM_DATA u8 sDriverTest_IsCryPlayingOld = 0;
static EWRAM_DATA int sSoundTestParams[9] = {0};
static EWRAM_DATA u8 sDriverTest_Reverse = 0;
static EWRAM_DATA u8 sDriverTest_Stereo = 0;

struct MusicPlayerInfo *sMPlayInfo_Cry;
extern struct MusicPlayerInfo gMPlayInfo_BGM;

static const struct BgTemplate sSoundCheckMenuBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
};

static const struct WindowTemplate sSoundCheckMenuWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 28,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 20,
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 8,
        .width = 28,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 132,
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 28,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 244,
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct WindowTemplate sSoundCheckMenuDriverTestWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 28,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 20,
    },
    DUMMY_WIN_TEMPLATE,
};

static void Task_InitSoundCheckMenu(u8 taskId);
static void Task_InitSoundCheckMenu_CreateWindows(u8);
static void Task_HandleDrawingSoundCheckMenuText(u8);
static void Task_ProcessSoundCheckMenuInputAndRedraw(u8);
static void Task_ExitToTitleScreen(u8);
static void HighlightSelectedWindow(u8);
static void PrintSoundNumber(u16, u8);
static void PrintPaddedString(const u8 *const, u8);
static void Task_DrawSubmenu(u8);
static void Task_ProcessDriverTestInput(u8);
static void AdjustSelectedDriverParam(s8);
static void PrintDriverTestMenuText(void);
static void PrintSignedNumber(int, u16, u16, u8);
static void Task_DrawDriverTestMenu(u8);
static void Task_DrawPanTestMenu(u8);
static void Task_ProcessPanTestInput(u8);
static void PrintPanTestMenuText(void);
static void InitGpuRegs(void);
static void ClearTasksAndGraphicalStructs(void);
static void SetupDispcnt(void);
static void DestroyWindow(u8 windowId);
static void PutWindowTilemapAndCopyWindowToVram(u8 windowId);

static void CB2_SoundCheckMenu(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_SoundCheckMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();

    if (sIsFastForwarding != 0)
    {
        m4aSoundMain();
        m4aSoundMain();
        m4aSoundMain();
    }
}

void CB2_StartSoundCheckMenu(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        InitGpuRegs();
        gMain.state++;
        break;
    case 1:
        ClearTasksAndGraphicalStructs();
        gMain.state++;
        break;
    case 2:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sSoundCheckMenuBgTemplates, ARRAY_COUNT(sSoundCheckMenuBgTemplates));
        ResetBgPositions();
        gMain.state++;
        break;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy() == TRUE)
            return;
        ShowBg(0);
        gMain.state++;
        break;
    case 4:
        InitWindows(sSoundCheckMenuWindowTemplates);
        DeactivateAllTextPrinters();
        LoadMessageBoxAndBorderGfx();
        gMain.state++;
        break;
    case 5:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB(0, 0, 0));
        gMain.state++;
        break;
    case 6:
        SetupDispcnt();
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 |
                                    WININ_WIN0_OBJ |
                                    WININ_WIN1_BG0 |
                                    WININ_WIN1_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 |
                                     WINOUT_WIN01_OBJ |
                                     WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 |
                                     BLDCNT_TGT1_BD |
                                     BLDCNT_EFFECT_DARKEN);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 7);
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetVBlankCallback(VBlankCB_SoundCheckMenu);
        SetMainCallback2(CB2_SoundCheckMenu);
        taskId = CreateTask(Task_InitSoundCheckMenu_CreateWindows, 0);
        gTasks[taskId].tWindowSelected = TEST_MUS;
        gTasks[taskId].tBgmIndex = 0;
        gTasks[taskId].tSeIndex = 0;
        gTasks[taskId].tBgmIndexOld = 0;
        gTasks[taskId].tSeIndexOld = 0;
        sIsFastForwarding = 0;
        m4aSoundInit();
        gMain.state++;
        break;
    }
}

static void Task_InitSoundCheckMenu_CreateWindows(u8 taskId) // SanitizeDayCareMailForRuby
{
    const u8 soundcheckStr[] = _("SOUND TEST{CLEAR_TO 120}A: PLAY  B: EXIT");
    const u8 bgmStr[] = _("MUSIC");
    const u8 seStr[] = _("SOUND EFFECTS");
    const u8 upDownStr[] = _("{LEFT_ARROW}PREV {RIGHT_ARROW}NEXT");
    const u8 driverStr[] = _("R: CRY TEST");

    if (!gPaletteFade.active)
    {
        SetStandardWindowBorderStyle(WIN_INFO, FALSE);
        AddTextPrinterParameterized(WIN_INFO, 2, soundcheckStr, 0, 0, TEXT_SKIP_DRAW, NULL);
        AddTextPrinterParameterized(WIN_INFO, 2, driverStr, 120, 14, TEXT_SKIP_DRAW, NULL);
        PutWindowTilemapAndCopyWindowToVram(WIN_INFO);
        SetStandardWindowBorderStyle(WIN_MUS, FALSE);
        AddTextPrinterParameterized(WIN_MUS, 2, bgmStr, 0, 0, TEXT_SKIP_DRAW, NULL);
        AddTextPrinterParameterized(WIN_MUS, 2, upDownStr, 100, 0, TEXT_SKIP_DRAW, NULL);
        PutWindowTilemapAndCopyWindowToVram(WIN_MUS);
        SetStandardWindowBorderStyle(WIN_SE, FALSE);
        AddTextPrinterParameterized(WIN_SE, 2, seStr, 0, 0, TEXT_SKIP_DRAW, NULL);
        AddTextPrinterParameterized(WIN_SE, 2, upDownStr, 100, 0, TEXT_SKIP_DRAW, NULL);
        PutWindowTilemapAndCopyWindowToVram(WIN_SE);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, 239));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, 48));
        HighlightSelectedWindow(WIN_INFO);
        gTasks[taskId].func = Task_HandleDrawingSoundCheckMenuText;
    }
}

static const u8 *const gBGMNames[];
static const u8 *const gSENames[];

static void Task_HandleDrawingSoundCheckMenuText(u8 taskId) // sub_080E85F4
{
    FillWindowPixelRect(WIN_MUS, PIXEL_FILL(1), 0, 14, 224, 12);
    PrintSoundNumber(gTasks[taskId].tBgmIndex + (SONGS_START - 1), WIN_MUS); // print by BGM index
    PrintPaddedString(gBGMNames[gTasks[taskId].tBgmIndex], WIN_MUS);
    FillWindowPixelRect(WIN_SE, PIXEL_FILL(1), 0, 14, 224, 12);
    PrintSoundNumber(gTasks[taskId].tSeIndex, WIN_SE);
    PrintPaddedString(gSENames[gTasks[taskId].tSeIndex], WIN_SE);
    gTasks[taskId].func = Task_ProcessSoundCheckMenuInputAndRedraw;
}

static bool8 Task_ProcessSoundCheckMenuInput(u8 taskId) // sub_080E8688
{
    if (JOY_NEW(R_BUTTON)) // driver test
    {
        gTasks[taskId].tWhichSubmenu = 1;
        gTasks[taskId].tState = 0;
        gTasks[taskId].func = Task_DrawSubmenu;
    }
    else if (JOY_NEW(L_BUTTON))
    {
        gTasks[taskId].tWhichSubmenu = 0;
        gTasks[taskId].tState = 0;
        gTasks[taskId].func = Task_DrawSubmenu;
    }
    else if (JOY_NEW(A_BUTTON))
    {
        if (gTasks[taskId].tWindowSelected != TEST_MUS)
        {
            if (gTasks[taskId].tSeIndexOld != 0)
            {
                if (gTasks[taskId].tSeIndex != 0)
                {
                    m4aSongNumStop(gTasks[taskId].tSeIndexOld);
                    m4aSongNumStart(gTasks[taskId].tSeIndex);
                    gTasks[taskId].tSeIndexOld = gTasks[taskId].tSeIndex;
                }
                else
                {
                    m4aSongNumStop(gTasks[taskId].tSeIndexOld);
                    gTasks[taskId].tSeIndexOld = 0;
                }
            }
            else if (gTasks[taskId].tSeIndex != 0)
            {
                m4aSongNumStart(gTasks[taskId].tSeIndex);
                gTasks[taskId].tSeIndexOld = gTasks[taskId].tSeIndex;
            }
        }
        else
        {
            if (gTasks[taskId].tBgmIndexOld != 0)
            {
                if (gTasks[taskId].tBgmIndex != 0)
                {
                    m4aSongNumStop(gTasks[taskId].tBgmIndexOld + (SONGS_START - 1));
                    m4aSongNumStart(gTasks[taskId].tBgmIndex + (SONGS_START - 1));
                    gTasks[taskId].tBgmIndexOld = gTasks[taskId].tBgmIndex;
                }
                else
                {
                    m4aSongNumStop(gTasks[taskId].tBgmIndexOld + (SONGS_START - 1));
                    gTasks[taskId].tBgmIndexOld = 0;
                }
            }
            else if (gTasks[taskId].tBgmIndex != 0)
            {
                m4aSongNumStart(gTasks[taskId].tBgmIndex + (SONGS_START - 1));
                gTasks[taskId].tBgmIndexOld = gTasks[taskId].tBgmIndex;
            }
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        m4aSongNumStart(SE_SELECT);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB(0, 0, 0));
        gTasks[taskId].func = Task_ExitToTitleScreen;
    }
    else if (JOY_REPEAT(DPAD_UP | DPAD_DOWN))
    {
        gTasks[taskId].tWindowSelected ^= 1;
        HighlightSelectedWindow(gTasks[taskId].tWindowSelected);
        return FALSE;
    }
    else if (JOY_REPEAT(DPAD_LEFT))
    {
        if (gTasks[taskId].tWindowSelected != TEST_MUS)
        {
            if (gTasks[taskId].tSeIndex > 0)
                gTasks[taskId].tSeIndex--;
            else
                gTasks[taskId].tSeIndex = SOUND_EFFECTS_END;
        }
        else
        {
            if (gTasks[taskId].tBgmIndex > 0)
                gTasks[taskId].tBgmIndex--;
            else
                gTasks[taskId].tBgmIndex = (SONGS_END - (SONGS_START - 1));
        }
        return TRUE;
    }
    else if (JOY_REPEAT(DPAD_RIGHT))
    {
        if (gTasks[taskId].tWindowSelected != TEST_MUS)
        {
            if (gTasks[taskId].tSeIndex < SOUND_EFFECTS_END)
                gTasks[taskId].tSeIndex++;
            else
                gTasks[taskId].tSeIndex = 0;
        }
        else
        {
            if (gTasks[taskId].tBgmIndex < (SONGS_END - (SONGS_START - 1)))
                gTasks[taskId].tBgmIndex++;
            else
                gTasks[taskId].tBgmIndex = 0;
        }
        return TRUE;
    }
    else if (JOY_HELD(SELECT_BUTTON))
    {
        sIsFastForwarding = 1;
    }
    else
    {
        sIsFastForwarding = 0;
    }
    return FALSE;
}

static void Task_ProcessSoundCheckMenuInputAndRedraw(u8 taskId) // sub_080E8878
{
    if (Task_ProcessSoundCheckMenuInput(taskId) != FALSE)
        gTasks[taskId].func = Task_HandleDrawingSoundCheckMenuText;
}

static void Task_ExitToTitleScreen(u8 taskId) // sub_080E88A8
{
    u8 windowId;

    if (!gPaletteFade.active)
    {
        for (windowId = WIN_INFO; windowId < WIN_COUNT; windowId++)
        {
            DestroyWindow(windowId);
        }
        DestroyTask(taskId);
        SetMainCallback2(CB2_InitTitleScreen);
    }
}

static void HighlightSelectedWindow(u8 windowType) // sub_080E88E8
{
    switch (windowType)
    {
    case WIN_INFO:
        SetGpuReg(REG_OFFSET_WIN1H, WIN_RANGE(0, 239));
        SetGpuReg(REG_OFFSET_WIN1V, WIN_RANGE(56, 104));
        break;
    case WIN_MUS:
        SetGpuReg(REG_OFFSET_WIN1H, WIN_RANGE(0, 239));
        SetGpuReg(REG_OFFSET_WIN1V, WIN_RANGE(112, 160));
        break;
    }
}

static void PrintSoundNumber(u16 soundIndex, u8 windowId) // sub_080E8928
{
    ConvertIntToDecimalStringN(gStringVar1, soundIndex, STR_CONV_MODE_RIGHT_ALIGN, 4);
    
    gStringVar1[4] = CHAR_COLON;
    gStringVar1[5] = EOS;
    
    AddTextPrinterParameterized(windowId, 2, gStringVar1, 0, 14, TEXT_SKIP_DRAW, NULL);
    PutWindowTilemapAndCopyWindowToVram(windowId);
}

static void PrintPaddedString(const u8 *const string, u8 windowId) // sub_080E8978
{
    u8 i;
    u8 str[32];

    for (i = 0; i < 31; i++)
        str[i] = CHAR_SPACE; // pad string.

    str[31] = EOS;

    for (i = 0; string[i] != EOS && i < 31; i++)
        str[i] = string[i];

    AddTextPrinterParameterized(windowId, 2, str, 32, 14, TEXT_SKIP_DRAW, NULL);
    PutWindowTilemapAndCopyWindowToVram(windowId);
}

static void Task_DrawSubmenu(u8 taskId) // sub_080E89EC
{
    u8 windowId;

    switch (gTasks[taskId].tState)
    {
    case 0:
        for (windowId = WIN_INFO; windowId < WIN_COUNT; windowId++)
        {
            DestroyWindow(windowId);
        }
        FreeAllWindowBuffers();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sSoundCheckMenuBgTemplates, ARRAY_COUNT(sSoundCheckMenuBgTemplates));
        gTasks[taskId].tState++;
        break;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy() == TRUE)
            return;
        InitWindows(sSoundCheckMenuDriverTestWindowTemplates);
        SetStandardWindowBorderStyle(0, TRUE);
        gTasks[taskId].tState++;
        break;
    case 2:
        ShowBg(0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_BG0_ON |
                                      DISPCNT_OBJ_ON |
                                      DISPCNT_WIN0_ON);
        if (gTasks[taskId].tWhichSubmenu == 0)
        {
            gTasks[taskId].func = Task_DrawPanTestMenu;
        }
        else
        {
            gTasks[taskId].func = Task_DrawDriverTestMenu;
        }
        break;
    }
}

static void Task_DrawDriverTestMenu(u8 taskId) // sub_080E8AA0
{
    const u8 bbackStr[] = _("B BUTTON: BACK");
    const u8 aplayStr[] = _("A BUTTON: PLAY");
    const u8 voiceStr[] = _("VOICE…………");
    const u8 volumeStr[] = _("VOLUME………");
    const u8 panpotStr[] = _("PANPOT………");
    const u8 pitchStr[] = _("PITCH…………");
    const u8 lengthStr[] = _("LENGTH………");
    const u8 releaseStr[] = _("RELEASE……");
    const u8 progressStr[] = _("PROGRESS…");
    const u8 chorusStr[] = _("CHORUS………");
    const u8 priorityStr[] = _("PRIORITY…");
    const u8 playingStr[] = _("PLAYING");
    const u8 reverseStr[] = _("REVERSE");
    const u8 stereoStr[] = _("STEREO");

    SetStandardWindowBorderStyle(WIN_INFO, FALSE);
    AddTextPrinterParameterized(WIN_INFO, 2, bbackStr, 136, 16, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(WIN_INFO, 2, aplayStr, 136, 32, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(WIN_INFO, 2, playingStr, 136, 80, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(WIN_INFO, 2, reverseStr, 136, 96, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(WIN_INFO, 2, stereoStr, 136, 112, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(WIN_INFO, 2, voiceStr, 8, 0, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(WIN_INFO, 2, volumeStr, 8, 16, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(WIN_INFO, 2, panpotStr, 8, 32, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(WIN_INFO, 2, pitchStr, 8, 48, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(WIN_INFO, 2, lengthStr, 8, 64, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(WIN_INFO, 2, releaseStr, 8, 80, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(WIN_INFO, 2, progressStr, 8, 96, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(WIN_INFO, 2, chorusStr, 8, 112, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(WIN_INFO, 2, priorityStr, 8, 128, TEXT_SKIP_DRAW, NULL);
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, DISPLAY_WIDTH));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, DISPLAY_HEIGHT));
    sDriverTest_IsCryPlaying = 0;
    sDriverTest_IsCryPlayingOld = 0;
    sMPlayInfo_Cry = NULL;
    sDriverTest_Reverse = 0;
    sDriverTest_Stereo = 1;
    sSoundTestParams[CRY_TEST_VOICE] = 0;
    sSoundTestParams[CRY_TEST_VOLUME] = 120;
    sSoundTestParams[CRY_TEST_PANPOT] = 0;
    sSoundTestParams[CRY_TEST_PITCH] = 15360;
    sSoundTestParams[CRY_TEST_LENGTH] = 180;
    sSoundTestParams[CRY_TEST_PROGRESS] = 0;
    sSoundTestParams[CRY_TEST_RELEASE] = 0;
    sSoundTestParams[CRY_TEST_CHORUS] = 0;
    sSoundTestParams[CRY_TEST_PRIORITY] = 2;
    PrintDriverTestMenuText();
    InitMenuNormal(WIN_INFO, 2, 0, 0, 16, 9, 0);
    gTasks[taskId].func = Task_ProcessDriverTestInput;
}

static void Task_ProcessDriverTestInput(u8 taskId) // sub_080E8D68
{
    if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].tState = 0;
        gTasks[taskId].func = Task_InitSoundCheckMenu;
        return;
    }
    if (JOY_REPEAT(DPAD_UP))
    {
        Menu_MoveCursorNoWrapAround(-1);
        return;
    }
    if (JOY_REPEAT(DPAD_DOWN))
    {
        Menu_MoveCursorNoWrapAround(1);
        return;
    }
    if (JOY_NEW(START_BUTTON))
    {
        sDriverTest_Reverse ^= 1;
        PrintDriverTestMenuText();
        return;
    }
    if (JOY_NEW(SELECT_BUTTON))
    {
        sDriverTest_Stereo ^= 1;
        PrintDriverTestMenuText();
        SetPokemonCryStereo(sDriverTest_Stereo);
        return;
    }
    if (JOY_REPEAT(R_BUTTON))
    {
        AdjustSelectedDriverParam(10);
        PrintDriverTestMenuText();
        return;
    }
    if (JOY_REPEAT(L_BUTTON))
    {
        AdjustSelectedDriverParam(-10);
        PrintDriverTestMenuText();
        return;
    }
    if (JOY_REPEAT(DPAD_LEFT))
    {
        AdjustSelectedDriverParam(-1);
        PrintDriverTestMenuText();
        return;
    }
    if (JOY_REPEAT(DPAD_RIGHT))
    {
        AdjustSelectedDriverParam(1);
        PrintDriverTestMenuText();
        return;
    }
    if (JOY_NEW(A_BUTTON))
    {
        u8 divide, remaining;

        SetPokemonCryVolume(sSoundTestParams[CRY_TEST_VOLUME]);
        SetPokemonCryPanpot(sSoundTestParams[CRY_TEST_PANPOT]);
        SetPokemonCryPitch(sSoundTestParams[CRY_TEST_PITCH]);
        SetPokemonCryLength(sSoundTestParams[CRY_TEST_LENGTH]);
        SetPokemonCryProgress(sSoundTestParams[CRY_TEST_PROGRESS]);
        SetPokemonCryRelease(sSoundTestParams[CRY_TEST_RELEASE]);
        SetPokemonCryChorus(sSoundTestParams[CRY_TEST_CHORUS]);
        SetPokemonCryPriority(sSoundTestParams[CRY_TEST_PRIORITY]);

        remaining = sSoundTestParams[CRY_TEST_VOICE] % 128;
        divide = sSoundTestParams[CRY_TEST_VOICE] / 128;

        switch (divide)
        {
        case 0:
            if (sDriverTest_Reverse)
                sMPlayInfo_Cry = SetPokemonCryTone(&gCryTable_Reverse[(128 * 0) + remaining]);
            else
                sMPlayInfo_Cry = SetPokemonCryTone(&gCryTable[(128 * 0) + remaining]);
            break;
        case 1:
            if (sDriverTest_Reverse)
                sMPlayInfo_Cry = SetPokemonCryTone(&gCryTable_Reverse[(128 * 1) + remaining]);
            else
                sMPlayInfo_Cry = SetPokemonCryTone(&gCryTable[(128 * 1) + remaining]);
            break;
        case 2:
            if (sDriverTest_Reverse)
                sMPlayInfo_Cry = SetPokemonCryTone(&gCryTable_Reverse[(128 * 2) + remaining]);
            else
                sMPlayInfo_Cry = SetPokemonCryTone(&gCryTable[(128 * 2) + remaining]);
            break;
        case 3:
            if (sDriverTest_Reverse)
                sMPlayInfo_Cry = SetPokemonCryTone(&gCryTable_Reverse[(128 * 3) + remaining]);
            else
                sMPlayInfo_Cry = SetPokemonCryTone(&gCryTable[(128 * 3) + remaining]);
            break;
        }
    }

    if (sMPlayInfo_Cry != NULL)
    {
        sDriverTest_IsCryPlaying = IsPokemonCryPlaying(sMPlayInfo_Cry);

        if (sDriverTest_IsCryPlaying != sDriverTest_IsCryPlayingOld)
            PrintDriverTestMenuText();

        sDriverTest_IsCryPlayingOld = sDriverTest_IsCryPlaying;
    }
}

static void AdjustSelectedDriverParam(s8 delta) // sub_080E8FA4
{
    // also ideally should be a MinMax struct, but any attempt to make this into a struct causes it to not match due to the weird multi dim access.
    const int paramRanges[] =
    {
        0, 387,         // Voice
        0, 127,         // Volume
        -127, 127,      // Panpot
        -128, 32639,    // Pitch
        0, 65535,       // Length
        0, 255,         // Release
        0, 65535,       // Progress
        -64, 63,        // Chorus
        0, 65535        // Priority
    };

    u8 cursorPos = Menu_GetCursorPos();

    sSoundTestParams[cursorPos] += delta;

    if (sSoundTestParams[cursorPos] > paramRanges[MULTI_DIM_ARR(cursorPos, B_16, MAX)])
        sSoundTestParams[cursorPos] = paramRanges[MULTI_DIM_ARR(cursorPos, B_16, MIN)];

    if (sSoundTestParams[cursorPos] < paramRanges[MULTI_DIM_ARR(cursorPos, B_16, MIN)])
        sSoundTestParams[cursorPos] = paramRanges[MULTI_DIM_ARR(cursorPos, B_16, MAX)];
}

static void PrintDriverTestMenuText(void) // sub_080E900C
{
    PrintSignedNumber(sSoundTestParams[CRY_TEST_VOICE] + 1, 80, 0, 5);
    PrintSignedNumber(sSoundTestParams[CRY_TEST_VOLUME], 80, 16, 5);
    PrintSignedNumber(sSoundTestParams[CRY_TEST_PANPOT], 80, 32, 5);
    PrintSignedNumber(sSoundTestParams[CRY_TEST_PITCH], 80, 48, 5);
    PrintSignedNumber(sSoundTestParams[CRY_TEST_LENGTH], 80, 64, 5);
    PrintSignedNumber(sSoundTestParams[CRY_TEST_RELEASE], 80, 80, 5);
    PrintSignedNumber(sSoundTestParams[CRY_TEST_PROGRESS], 80, 96, 5);
    PrintSignedNumber(sSoundTestParams[CRY_TEST_CHORUS], 80, 112, 5);
    PrintSignedNumber(sSoundTestParams[CRY_TEST_PRIORITY], 80, 128, 5);
    PrintSignedNumber(sDriverTest_IsCryPlaying, 200, 80, 1);
    PrintSignedNumber(sDriverTest_Reverse, 200, 96, 1);
    PrintSignedNumber(sDriverTest_Stereo, 200, 112, 1);
}

static void PrintSignedNumber(int n, u16 x, u16 y, u8 digits) // sub_080E90C0
{
    const int powersOfTen[6] =
    {
              1,
             10,
            100,
           1000,
          10000,
         100000
    };

    u8 str[8];
    s8 i;
    s8 negative;
    s8 someVar2;

    for (i = 0; i <= digits; i++)
        str[i] = CHAR_SPACE;
    str[digits + 1] = EOS;

    negative = FALSE;
    if (n < 0)
    {
        n = -n;
        negative = TRUE;
    }

    if (digits == 1)
        someVar2 = TRUE;
    else
        someVar2 = FALSE;

    for (i = digits - 1; i >= 0; i--)
    {
        s8 d = n / powersOfTen[i];

        if (d != 0 || someVar2 || i == 0)
        {
            if (negative && !someVar2)
                str[digits - i - 1] = CHAR_HYPHEN;
            str[digits - i] = CHAR_0 + d;
            someVar2 = TRUE;
        }
        n %= powersOfTen[i];
    }

    AddTextPrinterParameterized(WIN_INFO, 2, str, x, y, TEXT_SKIP_DRAW, NULL);
    PutWindowTilemapAndCopyWindowToVram(WIN_INFO);
}

static const s8 gUnknown_08566E58[5] = { 0x3F, 0x00, 0xC0, 0x7F, 0x80 };

static void Task_DrawPanTestMenu(u8 taskId) // sub_080E91E4
{
    const u8 seStr[] = _("SOUND EFFECT");
    const u8 panStr[] = _("PAN");

    AddTextPrinterParameterized(WIN_INFO, 2, seStr, 10, 14, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(WIN_INFO, 2, panStr, 10, 28, TEXT_SKIP_DRAW, NULL);

    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, DISPLAY_WIDTH));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, DISPLAY_HEIGHT));
    sSoundTestParams[CRY_TEST_VOICE] = 1;
    sSoundTestParams[CRY_TEST_PANPOT] = 0;
    sSoundTestParams[CRY_TEST_CHORUS] = 0;
    sSoundTestParams[CRY_TEST_PROGRESS] = 0;
    sSoundTestParams[CRY_TEST_RELEASE] = 0;
    PrintPanTestMenuText();
    gTasks[taskId].func = Task_ProcessPanTestInput;
}

static void Task_ProcessPanTestInput(u8 taskId) // sub_080E9284
{
    if (sSoundTestParams[CRY_TEST_PROGRESS])
    {
        if (sSoundTestParams[CRY_TEST_RELEASE])
        {
            sSoundTestParams[CRY_TEST_RELEASE]--;
        }
        else
        {
            s8 panpot = gUnknown_08566E58[sSoundTestParams[CRY_TEST_PANPOT]];
            if (panpot != -128)
            {
                if (panpot == 127)
                {
                    sSoundTestParams[CRY_TEST_CHORUS] += 2;
                    if (sSoundTestParams[CRY_TEST_CHORUS] < 63)
                        SE12PanpotControl(sSoundTestParams[CRY_TEST_CHORUS]);
                }
            }
            else
            {
                sSoundTestParams[CRY_TEST_CHORUS] -= 2;
                if (sSoundTestParams[CRY_TEST_CHORUS] > -64)
                    SE12PanpotControl(sSoundTestParams[CRY_TEST_CHORUS]);
            }
        }
    }

    if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].tState = 0;
        gTasks[taskId].func = Task_InitSoundCheckMenu;
        return;
    }
    if (JOY_NEW(A_BUTTON))
    {
        s8 panpot = gUnknown_08566E58[sSoundTestParams[CRY_TEST_PANPOT]];
        if (panpot != -128)
        {
            if (panpot == 127)
            {
                PlaySE12WithPanning(sSoundTestParams[CRY_TEST_VOICE], -64);
                sSoundTestParams[CRY_TEST_CHORUS] = -64;
                sSoundTestParams[CRY_TEST_PROGRESS] = 1;
                sSoundTestParams[CRY_TEST_RELEASE] = 30;
                return;
            }
        }
        else
        {
            PlaySE12WithPanning(sSoundTestParams[CRY_TEST_VOICE], 63);
            sSoundTestParams[CRY_TEST_CHORUS] = 63;
            sSoundTestParams[CRY_TEST_PROGRESS] = 1;
            sSoundTestParams[CRY_TEST_RELEASE] = 30;
            return;
        }

        PlaySE12WithPanning(sSoundTestParams[CRY_TEST_VOICE], panpot);
        sSoundTestParams[CRY_TEST_PROGRESS] = 0;
        return;
    }
    if (JOY_NEW(L_BUTTON))
    {
        sSoundTestParams[CRY_TEST_PANPOT]++;
        if (sSoundTestParams[CRY_TEST_PANPOT] > 4)
            sSoundTestParams[CRY_TEST_PANPOT] = 0;
        PrintPanTestMenuText();
    }
    if (JOY_NEW(R_BUTTON))
    {
        sSoundTestParams[CRY_TEST_PANPOT]--;
        if (sSoundTestParams[CRY_TEST_PANPOT] < 0)
            sSoundTestParams[CRY_TEST_PANPOT] = 4;
        PrintPanTestMenuText();
    }
    if (JOY_REPEAT(DPAD_RIGHT))
    {
        sSoundTestParams[CRY_TEST_VOICE]++;
        if (sSoundTestParams[CRY_TEST_VOICE] > PH_NURSE_SOLO)
            sSoundTestParams[CRY_TEST_VOICE] = MUS_DUMMY;
        PrintPanTestMenuText();
    }
    else if (JOY_REPEAT(DPAD_LEFT))
    {
        sSoundTestParams[CRY_TEST_VOICE]--;
        if (sSoundTestParams[CRY_TEST_VOICE] < MUS_DUMMY)
            sSoundTestParams[CRY_TEST_VOICE] = PH_NURSE_SOLO;
        PrintPanTestMenuText();
    }
}

static void Task_InitSoundCheckMenu(u8 taskId) // sub_080E9410
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        DestroyWindow(WIN_INFO);
        FreeAllWindowBuffers();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sSoundCheckMenuBgTemplates, ARRAY_COUNT(sSoundCheckMenuBgTemplates));
        gTasks[taskId].tState++;
        break;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy() == TRUE)
            return;
        InitWindows(sSoundCheckMenuWindowTemplates);
        gTasks[taskId].tState++;
        break;
    case 2:
        ShowBg(0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_BG0_ON |
                                      DISPCNT_OBJ_ON |
                                      DISPCNT_WIN0_ON |
                                      DISPCNT_WIN1_ON);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(17, 223));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(1, 31));
        gTasks[taskId].func = Task_InitSoundCheckMenu_CreateWindows;
        break;
    }
}

static void PrintPanTestMenuText(void) // sub_080E94B8
{
    u8 lrStr[] = _("   L");
    u8 rlStr[] = _("   R");

    FillWindowPixelRect(WIN_INFO, PIXEL_FILL(1), 100, 14, 3, 28);
    PrintSignedNumber(sSoundTestParams[CRY_TEST_VOICE], 100, 14, 3);

    switch (gUnknown_08566E58[sSoundTestParams[CRY_TEST_PANPOT]])
    {
    case 127:
        AddTextPrinterParameterized(WIN_INFO, 2, lrStr, 100, 28, TEXT_SKIP_DRAW, NULL);
        break;
    case -128:
        AddTextPrinterParameterized(WIN_INFO, 2, rlStr, 100, 28, TEXT_SKIP_DRAW, NULL);
        break;
    default:
        PrintSignedNumber(gUnknown_08566E58[sSoundTestParams[CRY_TEST_PANPOT]], 100, 28, 3);
        break;
    }
}

static void InitGpuRegs(void) // sub_080E9560
{
    DmaClear16(3, VRAM, VRAM_SIZE);
    DmaClear32(3, OAM, OAM_SIZE);
    DmaClear16(3, PLTT, PLTT_SIZE);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WIN1H, 0);
    SetGpuReg(REG_OFFSET_WIN1V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
}

static void ClearTasksAndGraphicalStructs(void) // sub_080E96A8
{
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetAllPicSprites();
    ResetPaletteFade();
    FreeAllSpritePalettes();
}

static void SetupDispcnt(void) // sub_080E96C8
{
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                  DISPCNT_OBJ_1D_MAP |
                                  DISPCNT_BG0_ON |
                                  DISPCNT_OBJ_ON |
                                  DISPCNT_WIN0_ON |
                                  DISPCNT_WIN1_ON);
}

static void PutWindowTilemapAndCopyWindowToVram(u8 windowId) // sub_080E9734
{
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

static void DestroyWindow(u8 windowId) // sub_080E9750
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
    ClearWindowTilemap(windowId);
    CopyWindowToVram(windowId, 2);
    RemoveWindow(windowId);
}

#define SOUND_LIST_BGM \
    X(MUS_STOP                        , "STOP"                            ) \
    X(MUS_LITTLEROOT_TEST             , "MUS-LITTLEROOT-TEST"             ) \
    X(MUS_GSC_ROUTE38                 , "MUS-GSC-ROUTE38"                 ) \
    X(MUS_CAUGHT                      , "MUS-CAUGHT"                      ) \
    X(MUS_VICTORY_WILD                , "MUS-VICTORY-WILD"                ) \
    X(MUS_VICTORY_GYM_LEADER          , "MUS-VICTORY-GYM-LEADER"          ) \
    X(MUS_VICTORY_LEAGUE              , "MUS-VICTORY-LEAGUE"              ) \
    X(MUS_C_COMM_CENTER               , "MUS-C-COMM-CENTER"               ) \
    X(MUS_GSC_PEWTER                  , "MUS-GSC-PEWTER"                  ) \
    X(MUS_C_VS_LEGEND_BEAST           , "MUS-C-VS-LEGEND-BEAST"           ) \
    X(MUS_ROUTE101                    , "MUS-ROUTE101"                    ) \
    X(MUS_ROUTE110                    , "MUS-ROUTE110"                    ) \
    X(MUS_ROUTE120                    , "MUS-ROUTE120"                    ) \
    X(MUS_PETALBURG                   , "MUS-PETALBURG"                   ) \
    X(MUS_OLDALE                      , "MUS-OLDALE"                      ) \
    X(MUS_GYM                         , "MUS-GYM"                         ) \
    X(MUS_SURF                        , "MUS-SURF"                        ) \
    X(MUS_PETALBURG_WOODS             , "MUS-PETALBURG-WOODS"             ) \
    X(MUS_LEVEL_UP                    , "MUS-LEVEL-UP"                    ) \
    X(MUS_HEAL                        , "MUS-HEAL"                        ) \
    X(MUS_OBTAIN_BADGE                , "MUS-OBTAIN-BADGE"                ) \
    X(MUS_OBTAIN_ITEM                 , "MUS-OBTAIN-ITEM"                 ) \
    X(MUS_EVOLVED                     , "MUS-EVOLVED"                     ) \
    X(MUS_OBTAIN_TMHM                 , "MUS-OBTAIN-TMHM"                 ) \
    X(MUS_LILYCOVE_MUSEUM             , "MUS-LILYCOVE-MUSEUM"             ) \
    X(MUS_ROUTE122                    , "MUS-ROUTE122"                    ) \
    X(MUS_OCEANIC_MUSEUM              , "MUS-OCEANIC-MUSEUM"              ) \
    X(MUS_EVOLUTION_INTRO             , "MUS-EVOLUTION-INTRO"             ) \
    X(MUS_EVOLUTION                   , "MUS-EVOLUTION"                   ) \
    X(MUS_MOVE_DELETED                , "MUS-MOVE-DELETED"                ) \
    X(MUS_ENCOUNTER_GIRL              , "MUS-ENCOUNTER-GIRL"              ) \
    X(MUS_ENCOUNTER_MALE              , "MUS-ENCOUNTER-MALE"              ) \
    X(MUS_ABANDONED_SHIP              , "MUS-ABANDONED-SHIP"              ) \
    X(MUS_FORTREE                     , "MUS-FORTREE"                     ) \
    X(MUS_BIRCH_LAB                   , "MUS-BIRCH-LAB"                   ) \
    X(MUS_B_TOWER_RS                  , "MUS-B-TOWER-RS"                  ) \
    X(MUS_ENCOUNTER_SWIMMER           , "MUS-ENCOUNTER-SWIMMER"           ) \
    X(MUS_CAVE_OF_ORIGIN              , "MUS-CAVE-OF-ORIGIN"              ) \
    X(MUS_OBTAIN_BERRY                , "MUS-OBTAIN-BERRY"                ) \
    X(MUS_AWAKEN_LEGEND               , "MUS-AWAKEN-LEGEND"               ) \
    X(MUS_SLOTS_JACKPOT               , "MUS-SLOTS-JACKPOT"               ) \
    X(MUS_SLOTS_WIN                   , "MUS-SLOTS-WIN"                   ) \
    X(MUS_TOO_BAD                     , "MUS-TOO-BAD"                     ) \
    X(MUS_ROULETTE                    , "MUS-ROULETTE"                    ) \
    X(MUS_LINK_CONTEST_P1             , "MUS-LINK-CONTEST-P1"             ) \
    X(MUS_LINK_CONTEST_P2             , "MUS-LINK-CONTEST-P2"             ) \
    X(MUS_LINK_CONTEST_P3             , "MUS-LINK-CONTEST-P3"             ) \
    X(MUS_LINK_CONTEST_P4             , "MUS-LINK-CONTEST-P4"             ) \
    X(MUS_ENCOUNTER_RICH              , "MUS-ENCOUNTER-RICH"              ) \
    X(MUS_VERDANTURF                  , "MUS-VERDANTURF"                  ) \
    X(MUS_RUSTBORO                    , "MUS-RUSTBORO"                    ) \
    X(MUS_POKE_CENTER                 , "MUS-POKE-CENTER"                 ) \
    X(MUS_ROUTE104                    , "MUS-ROUTE104"                    ) \
    X(MUS_ROUTE119                    , "MUS-ROUTE119"                    ) \
    X(MUS_CYCLING                     , "MUS-CYCLING"                     ) \
    X(MUS_POKE_MART                   , "MUS-POKE-MART"                   ) \
    X(MUS_LITTLEROOT                  , "MUS-LITTLEROOT"                  ) \
    X(MUS_MT_CHIMNEY                  , "MUS-MT-CHIMNEY"                  ) \
    X(MUS_ENCOUNTER_FEMALE            , "MUS-ENCOUNTER-FEMALE"            ) \
    X(MUS_LILYCOVE                    , "MUS-LILYCOVE"                    ) \
    X(MUS_ROUTE111                    , "MUS-ROUTE111"                    ) \
    X(MUS_HELP                        , "MUS-HELP"                        ) \
    X(MUS_UNDERWATER                  , "MUS-UNDERWATER"                  ) \
    X(MUS_VICTORY_TRAINER             , "MUS-VICTORY-TRAINER"             ) \
    X(MUS_TITLE                       , "MUS-TITLE"                       ) \
    X(MUS_INTRO                       , "MUS-INTRO"                       ) \
    X(MUS_ENCOUNTER_MAY               , "MUS-ENCOUNTER-MAY"               ) \
    X(MUS_ENCOUNTER_INTENSE           , "MUS-ENCOUNTER-INTENSE"           ) \
    X(MUS_ENCOUNTER_COOL              , "MUS-ENCOUNTER-COOL"              ) \
    X(MUS_ROUTE113                    , "MUS-ROUTE113"                    ) \
    X(MUS_ENCOUNTER_AQUA              , "MUS-ENCOUNTER-AQUA"              ) \
    X(MUS_FOLLOW_ME                   , "MUS-FOLLOW-ME"                   ) \
    X(MUS_ENCOUNTER_BRENDAN           , "MUS-ENCOUNTER-BRENDAN"           ) \
    X(MUS_EVER_GRANDE                 , "MUS-EVER-GRANDE"                 ) \
    X(MUS_ENCOUNTER_SUSPICIOUS        , "MUS-ENCOUNTER-SUSPICIOUS"        ) \
    X(MUS_VICTORY_AQUA_MAGMA          , "MUS-VICTORY-AQUA-MAGMA"          ) \
    X(MUS_CABLE_CAR                   , "MUS-CABLE-CAR"                   ) \
    X(MUS_GAME_CORNER                 , "MUS-GAME-CORNER"                 ) \
    X(MUS_DEWFORD                     , "MUS-DEWFORD"                     ) \
    X(MUS_SAFARI_ZONE                 , "MUS-SAFARI-ZONE"                 ) \
    X(MUS_VICTORY_ROAD                , "MUS-VICTORY-ROAD"                ) \
    X(MUS_AQUA_MAGMA_HIDEOUT          , "MUS-AQUA-MAGMA-HIDEOUT"          ) \
    X(MUS_SAILING                     , "MUS-SAILING"                     ) \
    X(MUS_MT_PYRE                     , "MUS-MT-PYRE"                     ) \
    X(MUS_SLATEPORT                   , "MUS-SLATEPORT"                   ) \
    X(MUS_MT_PYRE_EXTERIOR            , "MUS-MT-PYRE-EXTERIOR"            ) \
    X(MUS_SCHOOL                      , "MUS-SCHOOL"                      ) \
    X(MUS_HALL_OF_FAME                , "MUS-HALL-OF-FAME"                ) \
    X(MUS_FALLARBOR                   , "MUS-FALLARBOR"                   ) \
    X(MUS_SEALED_CHAMBER              , "MUS-SEALED-CHAMBER"              ) \
    X(MUS_CONTEST_WINNER              , "MUS-CONTEST-WINNER"              ) \
    X(MUS_CONTEST                     , "MUS-CONTEST"                     ) \
    X(MUS_ENCOUNTER_MAGMA             , "MUS-ENCOUNTER-MAGMA"             ) \
    X(MUS_INTRO_BATTLE                , "MUS-INTRO-BATTLE"                ) \
    X(MUS_WEATHER_KYOGRE              , "MUS-WEATHER-KYOGRE"              ) \
    X(MUS_WEATHER_GROUDON             , "MUS-WEATHER-GROUDON"             ) \
    X(MUS_SOOTOPOLIS                  , "MUS-SOOTOPOLIS"                  ) \
    X(MUS_CONTEST_RESULTS             , "MUS-CONTEST-RESULTS"             ) \
    X(MUS_HALL_OF_FAME_ROOM           , "MUS-HALL-OF-FAME-ROOM"           ) \
    X(MUS_TRICK_HOUSE                 , "MUS-TRICK-HOUSE"                 ) \
    X(MUS_ENCOUNTER_TWINS             , "MUS-ENCOUNTER-TWINS"             ) \
    X(MUS_ENCOUNTER_ELITE_FOUR        , "MUS-ENCOUNTER-ELITE-FOUR"        ) \
    X(MUS_ENCOUNTER_HIKER             , "MUS-ENCOUNTER-HIKER"             ) \
    X(MUS_CONTEST_LOBBY               , "MUS-CONTEST-LOBBY"               ) \
    X(MUS_ENCOUNTER_INTERVIEWER       , "MUS-ENCOUNTER-INTERVIEWER"       ) \
    X(MUS_ENCOUNTER_CHAMPION          , "MUS-ENCOUNTER-CHAMPION"          ) \
    X(MUS_CREDITS                     , "MUS-CREDITS"                     ) \
    X(MUS_END                         , "MUS-END"                         ) \
    X(MUS_VS_WILD                     , "MUS-VS-WILD"                     ) \
    X(MUS_VS_AQUA_MAGMA               , "MUS-VS-AQUA-MAGMA"               ) \
    X(MUS_VS_TRAINER                  , "MUS-VS-TRAINER"                  ) \
    X(MUS_VS_GYM_LEADER               , "MUS-VS-GYM-LEADER"               ) \
    X(MUS_VS_CHAMPION                 , "MUS-VS-CHAMPION"                 ) \
    X(MUS_VS_REGI                     , "MUS-VS-REGI"                     ) \
    X(MUS_VS_KYOGRE_GROUDON           , "MUS-VS-KYOGRE-GROUDON"           ) \
    X(MUS_VS_RIVAL                    , "MUS-VS-RIVAL"                    ) \
    X(MUS_VS_ELITE_FOUR               , "MUS-VS-ELITE-FOUR"               ) \
    X(MUS_VS_AQUA_MAGMA_LEADER        , "MUS-VS-AQUA-MAGMA-LEADER"        ) \
    X(MUS_RG_FOLLOW_ME                , "MUS-RG-FOLLOW-ME"                ) \
    X(MUS_RG_GAME_CORNER              , "MUS-RG-GAME-CORNER"              ) \
    X(MUS_RG_ROCKET_HIDEOUT           , "MUS-RG-ROCKET-HIDEOUT"           ) \
    X(MUS_RG_GYM                      , "MUS-RG-GYM"                      ) \
    X(MUS_RG_JIGGLYPUFF               , "MUS-RG-JIGGLYPUFF"               ) \
    X(MUS_RG_INTRO_FIGHT              , "MUS-RG-INTRO-FIGHT"              ) \
    X(MUS_RG_TITLE                    , "MUS-RG-TITLE"                    ) \
    X(MUS_RG_CINNABAR                 , "MUS-RG-CINNABAR"                 ) \
    X(MUS_RG_LAVENDER                 , "MUS-RG-LAVENDER"                 ) \
    X(MUS_RG_HEAL                     , "MUS-RG-HEAL"                     ) \
    X(MUS_RG_CYCLING                  , "MUS-RG-CYCLING"                  ) \
    X(MUS_RG_ENCOUNTER_ROCKET         , "MUS-RG-ENCOUNTER-ROCKET"         ) \
    X(MUS_RG_ENCOUNTER_GIRL           , "MUS-RG-ENCOUNTER-GIRL"           ) \
    X(MUS_RG_ENCOUNTER_BOY            , "MUS-RG-ENCOUNTER-BOY"            ) \
    X(MUS_RG_HALL_OF_FAME             , "MUS-RG-HALL-OF-FAME"             ) \
    X(MUS_RG_VIRIDIAN_FOREST          , "MUS-RG-VIRIDIAN-FOREST"          ) \
    X(MUS_RG_MT_MOON                  , "MUS-RG-MT-MOON"                  ) \
    X(MUS_RG_POKE_MANSION             , "MUS-RG-POKE-MANSION"             ) \
    X(MUS_RG_CREDITS                  , "MUS-RG-CREDITS"                  ) \
    X(MUS_RG_ROUTE1                   , "MUS-RG-ROUTE1"                   ) \
    X(MUS_RG_ROUTE24                  , "MUS-RG-ROUTE24"                  ) \
    X(MUS_RG_ROUTE3                   , "MUS-RG-ROUTE3"                   ) \
    X(MUS_RG_ROUTE11                  , "MUS-RG-ROUTE11"                  ) \
    X(MUS_RG_VICTORY_ROAD             , "MUS-RG-VICTORY-ROAD"             ) \
    X(MUS_RG_VS_GYM_LEADER            , "MUS-RG-VS-GYM-LEADER"            ) \
    X(MUS_RG_VS_TRAINER               , "MUS-RG-VS-TRAINER"               ) \
    X(MUS_RG_VS_WILD                  , "MUS-RG-VS-WILD"                  ) \
    X(MUS_RG_VS_CHAMPION              , "MUS-RG-VS-CHAMPION"              ) \
    X(MUS_RG_PALLET                   , "MUS-RG-PALLET"                   ) \
    X(MUS_RG_OAK_LAB                  , "MUS-RG-OAK-LAB"                  ) \
    X(MUS_RG_OAK                      , "MUS-RG-OAK"                      ) \
    X(MUS_RG_POKE_CENTER              , "MUS-RG-POKE-CENTER"              ) \
    X(MUS_RG_SS_ANNE                  , "MUS-RG-SS-ANNE"                  ) \
    X(MUS_RG_SURF                     , "MUS-RG-SURF"                     ) \
    X(MUS_RG_POKE_TOWER               , "MUS-RG-POKE-TOWER"               ) \
    X(MUS_RG_SILPH                    , "MUS-RG-SILPH"                    ) \
    X(MUS_RG_FUCHSIA                  , "MUS-RG-FUCHSIA"                  ) \
    X(MUS_RG_CELADON                  , "MUS-RG-CELADON"                  ) \
    X(MUS_RG_VICTORY_TRAINER          , "MUS-RG-VICTORY-TRAINER"          ) \
    X(MUS_RG_VICTORY_WILD             , "MUS-RG-VICTORY-WILD"             ) \
    X(MUS_RG_VICTORY_GYM_LEADER       , "MUS-RG-VICTORY-GYM-LEADER"       ) \
    X(MUS_RG_VERMILLION               , "MUS-RG-VERMILLION"               ) \
    X(MUS_RG_PEWTER                   , "MUS-RG-PEWTER"                   ) \
    X(MUS_RG_ENCOUNTER_RIVAL          , "MUS-RG-ENCOUNTER-RIVAL"          ) \
    X(MUS_RG_RIVAL_EXIT               , "MUS-RG-RIVAL-EXIT"               ) \
    X(MUS_RG_DEX_RATING               , "MUS-RG-DEX-RATING"               ) \
    X(MUS_RG_OBTAIN_KEY_ITEM          , "MUS-RG-OBTAIN-KEY-ITEM"          ) \
    X(MUS_RG_CAUGHT_INTRO             , "MUS-RG-CAUGHT-INTRO"             ) \
    X(MUS_RG_PHOTO                    , "MUS-RG-PHOTO"                    ) \
    X(MUS_RG_GAME_FREAK               , "MUS-RG-GAME-FREAK"               ) \
    X(MUS_RG_CAUGHT                   , "MUS-RG-CAUGHT"                   ) \
    X(MUS_RG_NEW_GAME_INSTRUCT        , "MUS-RG-NEW-GAME-INSTRUCT"        ) \
    X(MUS_RG_NEW_GAME_INTRO           , "MUS-RG-NEW-GAME-INTRO"           ) \
    X(MUS_RG_NEW_GAME_EXIT            , "MUS-RG-NEW-GAME-EXIT"            ) \
    X(MUS_RG_POKE_JUMP                , "MUS-RG-POKE-JUMP"                ) \
    X(MUS_RG_UNION_ROOM               , "MUS-RG-UNION-ROOM"               ) \
    X(MUS_RG_NET_CENTER               , "MUS-RG-NET-CENTER"               ) \
    X(MUS_RG_MYSTERY_GIFT             , "MUS-RG-MYSTERY-GIFT"             ) \
    X(MUS_RG_BERRY_PICK               , "MUS-RG-BERRY-PICK"               ) \
    X(MUS_RG_SEVII_CAVE               , "MUS-RG-SEVII-CAVE"               ) \
    X(MUS_RG_TEACHY_TV_SHOW           , "MUS-RG-TEACHY-TV-SHOW"           ) \
    X(MUS_RG_SEVII_ROUTE              , "MUS-RG-SEVII-ROUTE"              ) \
    X(MUS_RG_SEVII_DUNGEON            , "MUS-RG-SEVII-DUNGEON"            ) \
    X(MUS_RG_SEVII_123                , "MUS-RG-SEVII-123"                ) \
    X(MUS_RG_SEVII_45                 , "MUS-RG-SEVII-45"                 ) \
    X(MUS_RG_SEVII_67                 , "MUS-RG-SEVII-67"                 ) \
    X(MUS_RG_POKE_FLUTE               , "MUS-RG-POKE-FLUTE"               ) \
    X(MUS_RG_VS_DEOXYS                , "MUS-RG-VS-DEOXYS"                ) \
    X(MUS_RG_VS_MEWTWO                , "MUS-RG-VS-MEWTWO"                ) \
    X(MUS_RG_VS_LEGEND                , "MUS-RG-VS-LEGEND"                ) \
    X(MUS_RG_ENCOUNTER_GYM_LEADER     , "MUS-RG-ENCOUNTER-GYM-LEADER"     ) \
    X(MUS_RG_ENCOUNTER_DEOXYS         , "MUS-RG-ENCOUNTER-DEOXYS"         ) \
    X(MUS_RG_TRAINER_TOWER            , "MUS-RG-TRAINER-TOWER"            ) \
    X(MUS_RG_SLOW_PALLET              , "MUS-RG-SLOW-PALLET"              ) \
    X(MUS_RG_TEACHY_TV_MENU           , "MUS-RG-TEACHY-TV-MENU"           ) \
    X(MUS_ABNORMAL_WEATHER            , "MUS-ABNORMAL-WEATHER"            ) \
    X(MUS_B_FRONTIER                  , "MUS-B-FRONTIER"                  ) \
    X(MUS_B_ARENA                     , "MUS-B-ARENA"                     ) \
    X(MUS_OBTAIN_B_POINTS             , "MUS-OBTAIN-B-POINTS"             ) \
    X(MUS_REGISTER_MATCH_CALL         , "MUS-REGISTER-MATCH-CALL"         ) \
    X(MUS_B_PYRAMID                   , "MUS-B-PYRAMID"                   ) \
    X(MUS_B_PYRAMID_TOP               , "MUS-B-PYRAMID-TOP"               ) \
    X(MUS_B_PALACE                    , "MUS-B-PALACE"                    ) \
    X(MUS_RAYQUAZA_APPEARS            , "MUS-RAYQUAZA-APPEARS"            ) \
    X(MUS_B_TOWER                     , "MUS-B-TOWER"                     ) \
    X(MUS_OBTAIN_SYMBOL               , "MUS-OBTAIN-SYMBOL"               ) \
    X(MUS_B_DOME                      , "MUS-B-DOME"                      ) \
    X(MUS_B_PIKE                      , "MUS-B-PIKE"                      ) \
    X(MUS_B_FACTORY                   , "MUS-B-FACTORY"                   ) \
    X(MUS_VS_RAYQUAZA                 , "MUS-VS-RAYQUAZA"                 ) \
    X(MUS_VS_FRONTIER_BRAIN           , "MUS-VS-FRONTIER-BRAIN"           ) \
    X(MUS_VS_MEW                      , "MUS-VS-MEW"                      ) \
    X(MUS_B_DOME_LOBBY                , "MUS-B-DOME-LOBBY"                ) \
    X(MUS_DP_TWINLEAF_DAY             , "MUS-DP-TWINLEAF-DAY"             ) \
    X(MUS_DP_SANDGEM_DAY              , "MUS-DP-SANDGEM-DAY"              ) \
    X(MUS_DP_FLOAROMA_DAY             , "MUS-DP-FLOAROMA-DAY"             ) \
    X(MUS_DP_SOLACEON_DAY             , "MUS-DP-SOLACEON-DAY"             ) \
    X(MUS_DP_ROUTE225_DAY             , "MUS-DP-ROUTE225-DAY"             ) \
    X(MUS_DP_VALOR_LAKEFRONT_DAY      , "MUS-DP-VALOR-LAKEFRONT-DAY"      ) \
    X(MUS_DP_JUBILIFE_DAY             , "MUS-DP-JUBILIFE-DAY"             ) \
    X(MUS_DP_CANALAVE_DAY             , "MUS-DP-CANALAVE-DAY"             ) \
    X(MUS_DP_OREBURGH_DAY             , "MUS-DP-OREBURGH-DAY"             ) \
    X(MUS_DP_ETERNA_DAY               , "MUS-DP-ETERNA-DAY"               ) \
    X(MUS_DP_HEARTHOME_DAY            , "MUS-DP-HEARTHOME-DAY"            ) \
    X(MUS_DP_VEILSTONE_DAY            , "MUS-DP-VEILSTONE-DAY"            ) \
    X(MUS_DP_SUNYSHORE_DAY            , "MUS-DP-SUNYSHORE-DAY"            ) \
    X(MUS_DP_SNOWPOINT_DAY            , "MUS-DP-SNOWPOINT-DAY"            ) \
    X(MUS_DP_POKEMON_LEAGUE_DAY       , "MUS-DP-POKEMON-LEAGUE-DAY"       ) \
    X(MUS_DP_FIGHT_AREA_DAY           , "MUS-DP-FIGHT-AREA-DAY"           ) \
    X(MUS_DP_ROUTE201_DAY             , "MUS-DP-ROUTE201-DAY"             ) \
    X(MUS_DP_ROUTE203_DAY             , "MUS-DP-ROUTE203-DAY"             ) \
    X(MUS_DP_ROUTE205_DAY             , "MUS-DP-ROUTE205-DAY"             ) \
    X(MUS_DP_ROUTE206_DAY             , "MUS-DP-ROUTE206-DAY"             ) \
    X(MUS_DP_ROUTE209_DAY             , "MUS-DP-ROUTE209-DAY"             ) \
    X(MUS_DP_ROUTE210_DAY             , "MUS-DP-ROUTE210-DAY"             ) \
    X(MUS_DP_ROUTE216_DAY             , "MUS-DP-ROUTE216-DAY"             ) \
    X(MUS_DP_ROUTE228_DAY             , "MUS-DP-ROUTE228-DAY"             ) \
    X(MUS_DP_ROWAN                    , "MUS-DP-ROWAN"                    ) \
    X(MUS_DP_TV_BROADCAST             , "MUS-DP-TV-BROADCAST"             ) \
    X(MUS_DP_TWINLEAF_NIGHT           , "MUS-DP-TWINLEAF-NIGHT"           ) \
    X(MUS_DP_SANDGEM_NIGHT            , "MUS-DP-SANDGEM-NIGHT"            ) \
    X(MUS_DP_FLOAROMA_NIGHT           , "MUS-DP-FLOAROMA-NIGHT"           ) \
    X(MUS_DP_SOLACEON_NIGHT           , "MUS-DP-SOLACEON-NIGHT"           ) \
    X(MUS_DP_ROUTE225_NIGHT           , "MUS-DP-ROUTE225-NIGHT"           ) \
    X(MUS_DP_VALOR_LAKEFRONT_NIGHT    , "MUS-DP-VALOR-LAKEFRONT-NIGHT"    ) \
    X(MUS_DP_JUBILIFE_NIGHT           , "MUS-DP-JUBILIFE-NIGHT"           ) \
    X(MUS_DP_CANALAVE_NIGHT           , "MUS-DP-CANALAVE-NIGHT"           ) \
    X(MUS_DP_OREBURGH_NIGHT           , "MUS-DP-OREBURGH-NIGHT"           ) \
    X(MUS_DP_ETERNA_NIGHT             , "MUS-DP-ETERNA-NIGHT"             ) \
    X(MUS_DP_HEARTHOME_NIGHT          , "MUS-DP-HEARTHOME-NIGHT"          ) \
    X(MUS_DP_VEILSTONE_NIGHT          , "MUS-DP-VEILSTONE-NIGHT"          ) \
    X(MUS_DP_SUNYSHORE_NIGHT          , "MUS-DP-SUNYSHORE-NIGHT"          ) \
    X(MUS_DP_SNOWPOINT_NIGHT          , "MUS-DP-SNOWPOINT-NIGHT"          ) \
    X(MUS_DP_POKEMON_LEAGUE_NIGHT     , "MUS-DP-POKEMON-LEAGUE-NIGHT"     ) \
    X(MUS_DP_FIGHT_AREA_NIGHT         , "MUS-DP-FIGHT-AREA-NIGHT"         ) \
    X(MUS_DP_ROUTE201_NIGHT           , "MUS-DP-ROUTE201-NIGHT"           ) \
    X(MUS_DP_ROUTE203_NIGHT           , "MUS-DP-ROUTE203-NIGHT"           ) \
    X(MUS_DP_ROUTE205_NIGHT           , "MUS-DP-ROUTE205-NIGHT"           ) \
    X(MUS_DP_ROUTE206_NIGHT           , "MUS-DP-ROUTE206-NIGHT"           ) \
    X(MUS_DP_ROUTE209_NIGHT           , "MUS-DP-ROUTE209-NIGHT"           ) \
    X(MUS_DP_ROUTE210_NIGHT           , "MUS-DP-ROUTE210-NIGHT"           ) \
    X(MUS_DP_ROUTE216_NIGHT           , "MUS-DP-ROUTE216-NIGHT"           ) \
    X(MUS_DP_ROUTE228_NIGHT           , "MUS-DP-ROUTE228-NIGHT"           ) \
    X(MUS_DP_UNDERGROUND              , "MUS-DP-UNDERGROUND"              ) \
    X(MUS_DP_FLAG_CAPTURED            , "MUS-DP-FLAG-CAPTURED"            ) \
    X(MUS_DP_VICTORY_ROAD             , "MUS-DP-VICTORY-ROAD"             ) \
    X(MUS_DP_ETERNA_FOREST            , "MUS-DP-ETERNA-FOREST"            ) \
    X(MUS_DP_OLD_CHATEAU              , "MUS-DP-OLD-CHATEAU"              ) \
    X(MUS_DP_LAKE_CAVERNS             , "MUS-DP-LAKE-CAVERNS"             ) \
    X(MUS_DP_AMITY_SQUARE             , "MUS-DP-AMITY-SQUARE"             ) \
    X(MUS_DP_GALACTIC_HQ              , "MUS-DP-GALACTIC-HQ"              ) \
    X(MUS_DP_GALACTIC_ETERNA_BUILDING , "MUS-DP-GALACTIC-ETERNA-BUILDING" ) \
    X(MUS_DP_GREAT_MARSH              , "MUS-DP-GREAT-MARSH"              ) \
    X(MUS_DP_LAKE                     , "MUS-DP-LAKE"                     ) \
    X(MUS_DP_MT_CORONET               , "MUS-DP-MT-CORONET"               ) \
    X(MUS_DP_SPEAR_PILLAR             , "MUS-DP-SPEAR-PILLAR"             ) \
    X(MUS_DP_STARK_MOUNTAIN           , "MUS-DP-STARK-MOUNTAIN"           ) \
    X(MUS_DP_OREBURGH_GATE            , "MUS-DP-OREBURGH-GATE"            ) \
    X(MUS_DP_OREBURGH_MINE            , "MUS-DP-OREBURGH-MINE"            ) \
    X(MUS_DP_INSIDE_POKEMON_LEAGUE    , "MUS-DP-INSIDE-POKEMON-LEAGUE"    ) \
    X(MUS_DP_HALL_OF_FAME_ROOM        , "MUS-DP-HALL-OF-FAME-ROOM"        ) \
    X(MUS_DP_POKE_CENTER_DAY          , "MUS-DP-POKE-CENTER-DAY"          ) \
    X(MUS_DP_POKE_CENTER_NIGHT        , "MUS-DP-POKE-CENTER-NIGHT"        ) \
    X(MUS_DP_GYM                      , "MUS-DP-GYM"                      ) \
    X(MUS_DP_ROWAN_LAB                , "MUS-DP-ROWAN-LAB"                ) \
    X(MUS_DP_CONTEST_LOBBY            , "MUS-DP-CONTEST-LOBBY"            ) \
    X(MUS_DP_POKE_MART                , "MUS-DP-POKE-MART"                ) \
    X(MUS_DP_GAME_CORNER              , "MUS-DP-GAME-CORNER"              ) \
    X(MUS_DP_B_TOWER                  , "MUS-DP-B-TOWER"                  ) \
    X(MUS_DP_TV_STATION               , "MUS-DP-TV-STATION"               ) \
    X(MUS_DP_GALACTIC_HQ_BASEMENT     , "MUS-DP-GALACTIC-HQ-BASEMENT"     ) \
    X(MUS_DP_AZURE_FLUTE              , "MUS-DP-AZURE-FLUTE"              ) \
    X(MUS_DP_HALL_OF_ORIGIN           , "MUS-DP-HALL-OF-ORIGIN"           ) \
    X(MUS_DP_GTS                      , "MUS-DP-GTS"                      ) \
    X(MUS_DP_ENCOUNTER_BOY            , "MUS-DP-ENCOUNTER-BOY"            ) \
    X(MUS_DP_ENCOUNTER_TWINS          , "MUS-DP-ENCOUNTER-TWINS"          ) \
    X(MUS_DP_ENCOUNTER_INTENSE        , "MUS-DP-ENCOUNTER-INTENSE"        ) \
    X(MUS_DP_ENCOUNTER_GALACTIC       , "MUS-DP-ENCOUNTER-GALACTIC"       ) \
    X(MUS_DP_ENCOUNTER_LADY           , "MUS-DP-ENCOUNTER-LADY"           ) \
    X(MUS_DP_ENCOUNTER_HIKER          , "MUS-DP-ENCOUNTER-HIKER"          ) \
    X(MUS_DP_ENCOUNTER_RICH           , "MUS-DP-ENCOUNTER-RICH"           ) \
    X(MUS_DP_ENCOUNTER_SAILOR         , "MUS-DP-ENCOUNTER-SAILOR"         ) \
    X(MUS_DP_ENCOUNTER_SUSPICIOUS     , "MUS-DP-ENCOUNTER-SUSPICIOUS"     ) \
    X(MUS_DP_ENCOUNTER_ACE_TRAINER    , "MUS-DP-ENCOUNTER-ACE-TRAINER"    ) \
    X(MUS_DP_ENCOUNTER_GIRL           , "MUS-DP-ENCOUNTER-GIRL"           ) \
    X(MUS_DP_ENCOUNTER_CYCLIST        , "MUS-DP-ENCOUNTER-CYCLIST"        ) \
    X(MUS_DP_ENCOUNTER_ARTIST         , "MUS-DP-ENCOUNTER-ARTIST"         ) \
    X(MUS_DP_ENCOUNTER_ELITE_FOUR     , "MUS-DP-ENCOUNTER-ELITE-FOUR"     ) \
    X(MUS_DP_ENCOUNTER_CHAMPION       , "MUS-DP-ENCOUNTER-CHAMPION"       ) \
    X(MUS_DP_VS_WILD                  , "MUS-DP-VS-WILD"                  ) \
    X(MUS_DP_VS_GYM_LEADER            , "MUS-DP-VS-GYM-LEADER"            ) \
    X(MUS_DP_VS_UXIE_MESPRIT_AZELF    , "MUS-DP-VS-UXIE-MESPRIT-AZELF"    ) \
    X(MUS_DP_VS_TRAINER               , "MUS-DP-VS-TRAINER"               ) \
    X(MUS_DP_VS_GALACTIC_BOSS         , "MUS-DP-VS-GALACTIC-BOSS"         ) \
    X(MUS_DP_VS_DIALGA_PALKIA         , "MUS-DP-VS-DIALGA-PALKIA"         ) \
    X(MUS_DP_VS_CHAMPION              , "MUS-DP-VS-CHAMPION"              ) \
    X(MUS_DP_VS_GALACTIC              , "MUS-DP-VS-GALACTIC"              ) \
    X(MUS_DP_VS_RIVAL                 , "MUS-DP-VS-RIVAL"                 ) \
    X(MUS_DP_VS_ARCEUS                , "MUS-DP-VS-ARCEUS"                ) \
    X(MUS_DP_VS_LEGEND                , "MUS-DP-VS-LEGEND"                ) \
    X(MUS_DP_VICTORY_WILD             , "MUS-DP-VICTORY-WILD"             ) \
    X(MUS_DP_VICTORY_TRAINER          , "MUS-DP-VICTORY-TRAINER"          ) \
    X(MUS_DP_VICTORY_GYM_LEADER       , "MUS-DP-VICTORY-GYM-LEADER"       ) \
    X(MUS_DP_VICTORY_CHAMPION         , "MUS-DP-VICTORY-CHAMPION"         ) \
    X(MUS_DP_VICTORY_GALACTIC         , "MUS-DP-VICTORY-GALACTIC"         ) \
    X(MUS_DP_VICTORY_ELITE_FOUR       , "MUS-DP-VICTORY-ELITE-FOUR"       ) \
    X(MUS_DP_VS_GALACTIC_COMMANDER    , "MUS-DP-VS-GALACTIC-COMMANDER"    ) \
    X(MUS_DP_CONTEST                  , "MUS-DP-CONTEST"                  ) \
    X(MUS_DP_VS_ELITE_FOUR            , "MUS-DP-VS-ELITE-FOUR"            ) \
    X(MUS_DP_FOLLOW_ME                , "MUS-DP-FOLLOW-ME"                ) \
    X(MUS_DP_RIVAL                    , "MUS-DP-RIVAL"                    ) \
    X(MUS_DP_LAKE_EVENT               , "MUS-DP-LAKE-EVENT"               ) \
    X(MUS_DP_EVOLUTION                , "MUS-DP-EVOLUTION"                ) \
    X(MUS_DP_LUCAS                    , "MUS-DP-LUCAS"                    ) \
    X(MUS_DP_DAWN                     , "MUS-DP-DAWN"                     ) \
    X(MUS_DP_LEGEND_APPEARS           , "MUS-DP-LEGEND-APPEARS"           ) \
    X(MUS_DP_CATASTROPHE              , "MUS-DP-CATASTROPHE"              ) \
    X(MUS_DP_POKE_RADAR               , "MUS-DP-POKE-RADAR"               ) \
    X(MUS_DP_SURF                     , "MUS-DP-SURF"                     ) \
    X(MUS_DP_CYCLING                  , "MUS-DP-CYCLING"                  ) \
    X(MUS_DP_LETS_GO_TOGETHER         , "MUS-DP-LETS-GO-TOGETHER"         ) \
    X(MUS_DP_TV_END                   , "MUS-DP-TV-END"                   ) \
    X(MUS_DP_LEVEL_UP                 , "MUS-DP-LEVEL-UP"                 ) \
    X(MUS_DP_EVOLVED                  , "MUS-DP-EVOLVED"                  ) \
    X(MUS_DP_OBTAIN_KEY_ITEM          , "MUS-DP-OBTAIN-KEY-ITEM"          ) \
    X(MUS_DP_OBTAIN_ITEM              , "MUS-DP-OBTAIN-ITEM"              ) \
    X(MUS_DP_CAUGHT_INTRO             , "MUS-DP-CAUGHT-INTRO"             ) \
    X(MUS_DP_DEX_RATING               , "MUS-DP-DEX-RATING"               ) \
    X(MUS_DP_OBTAIN_BADGE             , "MUS-DP-OBTAIN-BADGE"             ) \
    X(MUS_DP_POKETCH                  , "MUS-DP-POKETCH"                  ) \
    X(MUS_DP_OBTAIN_TMHM              , "MUS-DP-OBTAIN-TMHM"              ) \
    X(MUS_DP_OBTAIN_ACCESSORY         , "MUS-DP-OBTAIN-ACCESSORY"         ) \
    X(MUS_DP_MOVE_DELETED             , "MUS-DP-MOVE-DELETED"             ) \
    X(MUS_DP_HEAL                     , "MUS-DP-HEAL"                     ) \
    X(MUS_DP_OBTAIN_BERRY             , "MUS-DP-OBTAIN-BERRY"             ) \
    X(MUS_DP_CONTEST_DRESS_UP         , "MUS-DP-CONTEST-DRESS-UP"         ) \
    X(MUS_DP_HALL_OF_FAME             , "MUS-DP-HALL-OF-FAME"             ) \
    X(MUS_DP_INTRO                    , "MUS-DP-INTRO"                    ) \
    X(MUS_DP_TITLE                    , "MUS-DP-TITLE"                    ) \
    X(MUS_DP_MYSTERY_GIFT             , "MUS-DP-MYSTERY-GIFT"             ) \
    X(MUS_DP_WFC                      , "MUS-DP-WFC"                      ) \
    X(MUS_DP_DANCE_EASY               , "MUS-DP-DANCE-EASY"               ) \
    X(MUS_DP_DANCE_DIFFICULT          , "MUS-DP-DANCE-DIFFICULT"          ) \
    X(MUS_DP_CONTEST_RESULTS          , "MUS-DP-CONTEST-RESULTS"          ) \
    X(MUS_DP_CONTEST_WINNER           , "MUS-DP-CONTEST-WINNER"           ) \
    X(MUS_DP_POFFINS                  , "MUS-DP-POFFINS"                  ) \
    X(MUS_DP_SLOTS_WIN                , "MUS-DP-SLOTS-WIN"                ) \
    X(MUS_DP_SLOTS_JACKPOT            , "MUS-DP-SLOTS-JACKPOT"            ) \
    X(MUS_DP_CREDITS                  , "MUS-DP-CREDITS"                  ) \
    X(MUS_DP_SLOTS_UNUSED             , "MUS-DP-SLOTS-UNUSED"             ) \
    X(MUS_PL_FIGHT_AREA_DAY           , "MUS-PL-FIGHT-AREA-DAY"           ) \
    X(MUS_PL_TV_BROADCAST             , "MUS-PL-TV-BROADCAST"             ) \
    X(MUS_PL_TV_END                   , "MUS-PL-TV-END"                   ) \
    X(MUS_PL_INTRO                    , "MUS-PL-INTRO"                    ) \
    X(MUS_PL_TITLE                    , "MUS-PL-TITLE"                    ) \
    X(MUS_PL_DISTORTION_WORLD         , "MUS-PL-DISTORTION-WORLD"         ) \
    X(MUS_PL_B_ARCADE                 , "MUS-PL-B-ARCADE"                 ) \
    X(MUS_PL_B_HALL                   , "MUS-PL-B-HALL"                   ) \
    X(MUS_PL_B_CASTLE                 , "MUS-PL-B-CASTLE"                 ) \
    X(MUS_PL_B_FACTORY                , "MUS-PL-B-FACTORY"                ) \
    X(MUS_PL_GLOBAL_TERMINAL          , "MUS-PL-GLOBAL-TERMINAL"          ) \
    X(MUS_PL_LILYCOVE_BOSSA_NOVA      , "MUS-PL-LILYCOVE-BOSSA-NOVA"      ) \
    X(MUS_PL_LOOKER                   , "MUS-PL-LOOKER"                   ) \
    X(MUS_PL_VS_GIRATINA              , "MUS-PL-VS-GIRATINA"              ) \
    X(MUS_PL_VS_FRONTIER_BRAIN        , "MUS-PL-VS-FRONTIER-BRAIN"        ) \
    X(MUS_PL_VICTORY_FRONTIER_BRAIN   , "MUS-PL-VICTORY-FRONTIER-BRAIN"   ) \
    X(MUS_PL_VS_REGI                  , "MUS-PL-VS-REGI"                  ) \
    X(MUS_PL_CONTEST_COOL             , "MUS-PL-CONTEST-COOL"             ) \
    X(MUS_PL_CONTEST_SMART            , "MUS-PL-CONTEST-SMART"            ) \
    X(MUS_PL_CONTEST_CUTE             , "MUS-PL-CONTEST-CUTE"             ) \
    X(MUS_PL_CONTEST_TOUGH            , "MUS-PL-CONTEST-TOUGH"            ) \
    X(MUS_PL_CONTEST_BEAUTY           , "MUS-PL-CONTEST-BEAUTY"           ) \
    X(MUS_PL_SPIN_TRADE               , "MUS-PL-SPIN-TRADE"               ) \
    X(MUS_PL_WIFI_MINIGAMES           , "MUS-PL-WIFI-MINIGAMES"           ) \
    X(MUS_PL_WIFI_PLAZA               , "MUS-PL-WIFI-PLAZA"               ) \
    X(MUS_PL_WIFI_PARADE              , "MUS-PL-WIFI-PARADE"              ) \
    X(MUS_PL_GIRATINA_APPEARS_1       , "MUS-PL-GIRATINA-APPEARS-1"       ) \
    X(MUS_PL_GIRATINA_APPEARS_2       , "MUS-PL-GIRATINA-APPEARS-2"       ) \
    X(MUS_PL_MYSTERY_GIFT             , "MUS-PL-MYSTERY-GIFT"             ) \
    X(MUS_PL_TWINLEAF_MUSIC_BOX       , "MUS-PL-TWINLEAF-MUSIC-BOX"       ) \
    X(MUS_PL_OBTAIN_ARCADE_POINTS     , "MUS-PL-OBTAIN-ARCADE-POINTS"     ) \
    X(MUS_PL_OBTAIN_CASTLE_POINTS     , "MUS-PL-OBTAIN-CASTLE-POINTS"     ) \
    X(MUS_PL_OBTAIN_B_POINTS          , "MUS-PL-OBTAIN-B-POINTS"          ) \
    X(MUS_PL_WIN_MINIGAME             , "MUS-PL-WIN-MINIGAME"             ) \
    X(MUS_HG_INTRO                    , "MUS-HG-INTRO"                    ) \
    X(MUS_HG_TITLE                    , "MUS-HG-TITLE"                    ) \
    X(MUS_HG_NEW_GAME                 , "MUS-HG-NEW-GAME"                 ) \
    X(MUS_HG_EVOLUTION                , "MUS-HG-EVOLUTION"                ) \
    X(MUS_HG_EVOLUTION_NO_INTRO       , "MUS-HG-EVOLUTION-NO-INTRO"       ) \
    X(MUS_HG_CYCLING                  , "MUS-HG-CYCLING"                  ) \
    X(MUS_HG_SURF                     , "MUS-HG-SURF"                     ) \
    X(MUS_HG_HALL_OF_FAME             , "MUS-HG-HALL-OF-FAME"             ) \
    X(MUS_HG_CREDITS                  , "MUS-HG-CREDITS"                  ) \
    X(MUS_HG_END                      , "MUS-HG-END"                      ) \
    X(MUS_HG_NEW_BARK                 , "MUS-HG-NEW-BARK"                 ) \
    X(MUS_HG_CHERRYGROVE              , "MUS-HG-CHERRYGROVE"              ) \
    X(MUS_HG_VIOLET                   , "MUS-HG-VIOLET"                   ) \
    X(MUS_HG_AZALEA                   , "MUS-HG-AZALEA"                   ) \
    X(MUS_HG_GOLDENROD                , "MUS-HG-GOLDENROD"                ) \
    X(MUS_HG_ECRUTEAK                 , "MUS-HG-ECRUTEAK"                 ) \
    X(MUS_HG_CIANWOOD                 , "MUS-HG-CIANWOOD"                 ) \
    X(MUS_HG_ROUTE29                  , "MUS-HG-ROUTE29"                  ) \
    X(MUS_HG_ROUTE30                  , "MUS-HG-ROUTE30"                  ) \
    X(MUS_HG_ROUTE34                  , "MUS-HG-ROUTE34"                  ) \
    X(MUS_HG_ROUTE38                  , "MUS-HG-ROUTE38"                  ) \
    X(MUS_HG_ROUTE42                  , "MUS-HG-ROUTE42"                  ) \
    X(MUS_HG_VERMILION                , "MUS-HG-VERMILION"                ) \
    X(MUS_HG_PEWTER                   , "MUS-HG-PEWTER"                   ) \
    X(MUS_HG_CERULEAN                 , "MUS-HG-CERULEAN"                 ) \
    X(MUS_HG_LAVENDER                 , "MUS-HG-LAVENDER"                 ) \
    X(MUS_HG_CELADON                  , "MUS-HG-CELADON"                  ) \
    X(MUS_HG_PALLET                   , "MUS-HG-PALLET"                   ) \
    X(MUS_HG_CINNABAR                 , "MUS-HG-CINNABAR"                 ) \
    X(MUS_HG_ROUTE1                   , "MUS-HG-ROUTE1"                   ) \
    X(MUS_HG_ROUTE3                   , "MUS-HG-ROUTE3"                   ) \
    X(MUS_HG_ROUTE11                  , "MUS-HG-ROUTE11"                  ) \
    X(MUS_HG_ROUTE24                  , "MUS-HG-ROUTE24"                  ) \
    X(MUS_HG_ROUTE26                  , "MUS-HG-ROUTE26"                  ) \
    X(MUS_HG_POKE_CENTER              , "MUS-HG-POKE-CENTER"              ) \
    X(MUS_HG_POKE_MART                , "MUS-HG-POKE-MART"                ) \
    X(MUS_HG_GYM                      , "MUS-HG-GYM"                      ) \
    X(MUS_HG_ELM_LAB                  , "MUS-HG-ELM-LAB"                  ) \
    X(MUS_HG_OAK                      , "MUS-HG-OAK"                      ) \
    X(MUS_HG_DANCE_THEATER            , "MUS-HG-DANCE-THEATER"            ) \
    X(MUS_HG_GAME_CORNER              , "MUS-HG-GAME-CORNER"              ) \
    X(MUS_HG_B_TOWER                  , "MUS-HG-B-TOWER"                  ) \
    X(MUS_HG_B_TOWER_RECEPTION        , "MUS-HG-B-TOWER-RECEPTION"        ) \
    X(MUS_HG_SPROUT_TOWER             , "MUS-HG-SPROUT-TOWER"             ) \
    X(MUS_HG_UNION_CAVE               , "MUS-HG-UNION-CAVE"               ) \
    X(MUS_HG_RUINS_OF_ALPH            , "MUS-HG-RUINS-OF-ALPH"            ) \
    X(MUS_HG_NATIONAL_PARK            , "MUS-HG-NATIONAL-PARK"            ) \
    X(MUS_HG_BURNED_TOWER             , "MUS-HG-BURNED-TOWER"             ) \
    X(MUS_HG_BELL_TOWER               , "MUS-HG-BELL-TOWER"               ) \
    X(MUS_HG_LIGHTHOUSE               , "MUS-HG-LIGHTHOUSE"               ) \
    X(MUS_HG_TEAM_ROCKET_HQ           , "MUS-HG-TEAM-ROCKET-HQ"           ) \
    X(MUS_HG_ICE_PATH                 , "MUS-HG-ICE-PATH"                 ) \
    X(MUS_HG_DRAGONS_DEN              , "MUS-HG-DRAGONS-DEN"              ) \
    X(MUS_HG_ROCK_TUNNEL              , "MUS-HG-ROCK-TUNNEL"              ) \
    X(MUS_HG_VIRIDIAN_FOREST          , "MUS-HG-VIRIDIAN-FOREST"          ) \
    X(MUS_HG_VICTORY_ROAD             , "MUS-HG-VICTORY-ROAD"             ) \
    X(MUS_HG_POKEMON_LEAGUE           , "MUS-HG-POKEMON-LEAGUE"           ) \
    X(MUS_HG_FOLLOW_ME_1              , "MUS-HG-FOLLOW-ME-1"              ) \
    X(MUS_HG_FOLLOW_ME_2              , "MUS-HG-FOLLOW-ME-2"              ) \
    X(MUS_HG_ENCOUNTER_RIVAL          , "MUS-HG-ENCOUNTER-RIVAL"          ) \
    X(MUS_HG_RIVAL_EXIT               , "MUS-HG-RIVAL-EXIT"               ) \
    X(MUS_HG_BUG_CONTEST_PREP         , "MUS-HG-BUG-CONTEST-PREP"         ) \
    X(MUS_HG_BUG_CATCHING_CONTEST     , "MUS-HG-BUG-CATCHING-CONTEST"     ) \
    X(MUS_HG_RADIO_ROCKET             , "MUS-HG-RADIO-ROCKET"             ) \
    X(MUS_HG_ROCKET_TAKEOVER          , "MUS-HG-ROCKET-TAKEOVER"          ) \
    X(MUS_HG_MAGNET_TRAIN             , "MUS-HG-MAGNET-TRAIN"             ) \
    X(MUS_HG_SS_AQUA                  , "MUS-HG-SS-AQUA"                  ) \
    X(MUS_HG_MT_MOON_SQUARE           , "MUS-HG-MT-MOON-SQUARE"           ) \
    X(MUS_HG_RADIO_JINGLE             , "MUS-HG-RADIO-JINGLE"             ) \
    X(MUS_HG_RADIO_LULLABY            , "MUS-HG-RADIO-LULLABY"            ) \
    X(MUS_HG_RADIO_MARCH              , "MUS-HG-RADIO-MARCH"              ) \
    X(MUS_HG_RADIO_UNOWN              , "MUS-HG-RADIO-UNOWN"              ) \
    X(MUS_HG_RADIO_POKE_FLUTE         , "MUS-HG-RADIO-POKE-FLUTE"         ) \
    X(MUS_HG_RADIO_OAK                , "MUS-HG-RADIO-OAK"                ) \
    X(MUS_HG_RADIO_BUENA              , "MUS-HG-RADIO-BUENA"              ) \
    X(MUS_HG_EUSINE                   , "MUS-HG-EUSINE"                   ) \
    X(MUS_HG_CLAIR                    , "MUS-HG-CLAIR"                    ) \
    X(MUS_HG_ENCOUNTER_GIRL_1         , "MUS-HG-ENCOUNTER-GIRL-1"         ) \
    X(MUS_HG_ENCOUNTER_BOY_1          , "MUS-HG-ENCOUNTER-BOY-1"          ) \
    X(MUS_HG_ENCOUNTER_SUSPICIOUS_1   , "MUS-HG-ENCOUNTER-SUSPICIOUS-1"   ) \
    X(MUS_HG_ENCOUNTER_SAGE           , "MUS-HG-ENCOUNTER-SAGE"           ) \
    X(MUS_HG_ENCOUNTER_KIMONO_GIRL    , "MUS-HG-ENCOUNTER-KIMONO-GIRL"    ) \
    X(MUS_HG_ENCOUNTER_ROCKET         , "MUS-HG-ENCOUNTER-ROCKET"         ) \
    X(MUS_HG_ENCOUNTER_GIRL_2         , "MUS-HG-ENCOUNTER-GIRL-2"         ) \
    X(MUS_HG_ENCOUNTER_BOY_2          , "MUS-HG-ENCOUNTER-BOY-2"          ) \
    X(MUS_HG_ENCOUNTER_SUSPICIOUS_2   , "MUS-HG-ENCOUNTER-SUSPICIOUS-2"   ) \
    X(MUS_HG_VS_WILD                  , "MUS-HG-VS-WILD"                  ) \
    X(MUS_HG_VS_TRAINER               , "MUS-HG-VS-TRAINER"               ) \
    X(MUS_HG_VS_GYM_LEADER            , "MUS-HG-VS-GYM-LEADER"            ) \
    X(MUS_HG_VS_RIVAL                 , "MUS-HG-VS-RIVAL"                 ) \
    X(MUS_HG_VS_ROCKET                , "MUS-HG-VS-ROCKET"                ) \
    X(MUS_HG_VS_SUICUNE               , "MUS-HG-VS-SUICUNE"               ) \
    X(MUS_HG_VS_ENTEI                 , "MUS-HG-VS-ENTEI"                 ) \
    X(MUS_HG_VS_RAIKOU                , "MUS-HG-VS-RAIKOU"                ) \
    X(MUS_HG_VS_CHAMPION              , "MUS-HG-VS-CHAMPION"              ) \
    X(MUS_HG_VS_WILD_KANTO            , "MUS-HG-VS-WILD-KANTO"            ) \
    X(MUS_HG_VS_TRAINER_KANTO         , "MUS-HG-VS-TRAINER-KANTO"         ) \
    X(MUS_HG_VS_GYM_LEADER_KANTO      , "MUS-HG-VS-GYM-LEADER-KANTO"      ) \
    X(MUS_HG_VICTORY_TRAINER          , "MUS-HG-VICTORY-TRAINER"          ) \
    X(MUS_HG_VICTORY_WILD             , "MUS-HG-VICTORY-WILD"             ) \
    X(MUS_HG_CAUGHT                   , "MUS-HG-CAUGHT"                   ) \
    X(MUS_HG_VICTORY_GYM_LEADER       , "MUS-HG-VICTORY-GYM-LEADER"       ) \
    X(MUS_HG_VS_HO_OH                 , "MUS-HG-VS-HO-OH"                 ) \
    X(MUS_HG_VS_LUGIA                 , "MUS-HG-VS-LUGIA"                 ) \
    X(MUS_HG_POKEATHLON_LOBBY         , "MUS-HG-POKEATHLON-LOBBY"         ) \
    X(MUS_HG_POKEATHLON_START         , "MUS-HG-POKEATHLON-START"         ) \
    X(MUS_HG_POKEATHLON_BEFORE        , "MUS-HG-POKEATHLON-BEFORE"        ) \
    X(MUS_HG_POKEATHLON_EVENT         , "MUS-HG-POKEATHLON-EVENT"         ) \
    X(MUS_HG_POKEATHLON_FINALS        , "MUS-HG-POKEATHLON-FINALS"        ) \
    X(MUS_HG_POKEATHLON_RESULTS       , "MUS-HG-POKEATHLON-RESULTS"       ) \
    X(MUS_HG_POKEATHLON_END           , "MUS-HG-POKEATHLON-END"           ) \
    X(MUS_HG_POKEATHLON_WINNER        , "MUS-HG-POKEATHLON-WINNER"        ) \
    X(MUS_HG_B_FACTORY                , "MUS-HG-B-FACTORY"                ) \
    X(MUS_HG_B_HALL                   , "MUS-HG-B-HALL"                   ) \
    X(MUS_HG_B_ARCADE                 , "MUS-HG-B-ARCADE"                 ) \
    X(MUS_HG_B_CASTLE                 , "MUS-HG-B-CASTLE"                 ) \
    X(MUS_HG_VS_FRONTIER_BRAIN        , "MUS-HG-VS-FRONTIER-BRAIN"        ) \
    X(MUS_HG_VICTORY_FRONTIER_BRAIN   , "MUS-HG-VICTORY-FRONTIER-BRAIN"   ) \
    X(MUS_HG_WFC                      , "MUS-HG-WFC"                      ) \
    X(MUS_HG_MYSTERY_GIFT             , "MUS-HG-MYSTERY-GIFT"             ) \
    X(MUS_HG_WIFI_PLAZA               , "MUS-HG-WIFI-PLAZA"               ) \
    X(MUS_HG_WIFI_MINIGAMES           , "MUS-HG-WIFI-MINIGAMES"           ) \
    X(MUS_HG_WIFI_PARADE              , "MUS-HG-WIFI-PARADE"              ) \
    X(MUS_HG_GLOBAL_TERMINAL          , "MUS-HG-GLOBAL-TERMINAL"          ) \
    X(MUS_HG_SPIN_TRADE               , "MUS-HG-SPIN-TRADE"               ) \
    X(MUS_HG_GTS                      , "MUS-HG-GTS"                      ) \
    X(MUS_HG_ROUTE47                  , "MUS-HG-ROUTE47"                  ) \
    X(MUS_HG_SAFARI_ZONE_GATE         , "MUS-HG-SAFARI-ZONE-GATE"         ) \
    X(MUS_HG_SAFARI_ZONE              , "MUS-HG-SAFARI-ZONE"              ) \
    X(MUS_HG_ETHAN                    , "MUS-HG-ETHAN"                    ) \
    X(MUS_HG_LYRA                     , "MUS-HG-LYRA"                     ) \
    X(MUS_HG_GAME_CORNER_WIN          , "MUS-HG-GAME-CORNER-WIN"          ) \
    X(MUS_HG_KIMONO_GIRL_DANCE        , "MUS-HG-KIMONO-GIRL-DANCE"        ) \
    X(MUS_HG_KIMONO_GIRL              , "MUS-HG-KIMONO-GIRL"              ) \
    X(MUS_HG_HO_OH_APPEARS            , "MUS-HG-HO-OH-APPEARS"            ) \
    X(MUS_HG_LUGIA_APPEARS            , "MUS-HG-LUGIA-APPEARS"            ) \
    X(MUS_HG_SPIKY_EARED_PICHU        , "MUS-HG-SPIKY-EARED-PICHU"        ) \
    X(MUS_HG_SINJOU_RUINS             , "MUS-HG-SINJOU-RUINS"             ) \
    X(MUS_HG_RADIO_ROUTE101           , "MUS-HG-RADIO-ROUTE101"           ) \
    X(MUS_HG_RADIO_ROUTE201           , "MUS-HG-RADIO-ROUTE201"           ) \
    X(MUS_HG_RADIO_TRAINER            , "MUS-HG-RADIO-TRAINER"            ) \
    X(MUS_HG_RADIO_VARIETY            , "MUS-HG-RADIO-VARIETY"            ) \
    X(MUS_HG_VS_KYOGRE_GROUDON        , "MUS-HG-VS-KYOGRE-GROUDON"        ) \
    X(MUS_HG_POKEWALKER               , "MUS-HG-POKEWALKER"               ) \
    X(MUS_HG_VS_ARCEUS                , "MUS-HG-VS-ARCEUS"                ) \
    X(MUS_HG_HEAL                     , "MUS-HG-HEAL"                     ) \
    X(MUS_HG_LEVEL_UP                 , "MUS-HG-LEVEL-UP"                 ) \
    X(MUS_HG_OBTAIN_ITEM              , "MUS-HG-OBTAIN-ITEM"              ) \
    X(MUS_HG_OBTAIN_KEY_ITEM          , "MUS-HG-OBTAIN-KEY-ITEM"          ) \
    X(MUS_HG_EVOLVED                  , "MUS-HG-EVOLVED"                  ) \
    X(MUS_HG_OBTAIN_BADGE             , "MUS-HG-OBTAIN-BADGE"             ) \
    X(MUS_HG_OBTAIN_TMHM              , "MUS-HG-OBTAIN-TMHM"              ) \
    X(MUS_HG_OBTAIN_ACCESSORY         , "MUS-HG-OBTAIN-ACCESSORY"         ) \
    X(MUS_HG_MOVE_DELETED             , "MUS-HG-MOVE-DELETED"             ) \
    X(MUS_HG_OBTAIN_BERRY             , "MUS-HG-OBTAIN-BERRY"             ) \
    X(MUS_HG_DEX_RATING_1             , "MUS-HG-DEX-RATING-1"             ) \
    X(MUS_HG_DEX_RATING_2             , "MUS-HG-DEX-RATING-2"             ) \
    X(MUS_HG_DEX_RATING_3             , "MUS-HG-DEX-RATING-3"             ) \
    X(MUS_HG_DEX_RATING_4             , "MUS-HG-DEX-RATING-4"             ) \
    X(MUS_HG_DEX_RATING_5             , "MUS-HG-DEX-RATING-5"             ) \
    X(MUS_HG_DEX_RATING_6             , "MUS-HG-DEX-RATING-6"             ) \
    X(MUS_HG_OBTAIN_EGG               , "MUS-HG-OBTAIN-EGG"               ) \
    X(MUS_HG_BUG_CONTEST_1ST_PLACE    , "MUS-HG-BUG-CONTEST-1ST-PLACE"    ) \
    X(MUS_HG_BUG_CONTEST_2ND_PLACE    , "MUS-HG-BUG-CONTEST-2ND-PLACE"    ) \
    X(MUS_HG_BUG_CONTEST_3RD_PLACE    , "MUS-HG-BUG-CONTEST-3RD-PLACE"    ) \
    X(MUS_HG_CARD_FLIP                , "MUS-HG-CARD-FLIP"                ) \
    X(MUS_HG_CARD_FLIP_GAME_OVER      , "MUS-HG-CARD-FLIP-GAME-OVER"      ) \
    X(MUS_HG_POKEGEAR_REGISTERED      , "MUS-HG-POKEGEAR-REGISTERED"      ) \
    X(MUS_HG_LETS_GO_TOGETHER         , "MUS-HG-LETS-GO-TOGETHER"         ) \
    X(MUS_HG_POKEATHLON_READY         , "MUS-HG-POKEATHLON-READY"         ) \
    X(MUS_HG_POKEATHLON_1ST_PLACE     , "MUS-HG-POKEATHLON-1ST-PLACE"     ) \
    X(MUS_HG_RECEIVE_POKEMON          , "MUS-HG-RECEIVE-POKEMON"          ) \
    X(MUS_HG_OBTAIN_ARCADE_POINTS     , "MUS-HG-OBTAIN-ARCADE-POINTS"     ) \
    X(MUS_HG_OBTAIN_CASTLE_POINTS     , "MUS-HG-OBTAIN-CASTLE-POINTS"     ) \
    X(MUS_HG_OBTAIN_B_POINTS          , "MUS-HG-OBTAIN-B-POINTS"          ) \
    X(MUS_HG_WIN_MINIGAME             , "MUS-HG-WIN-MINIGAME"             ) \

#define SOUND_LIST_SE \
    X(SE_STOP                  , "STOP"                     ) \
    X(SE_USE_ITEM              , "SE-USE-ITEM"              ) \
    X(SE_PC_LOGIN              , "SE-PC-LOGIN"              ) \
    X(SE_PC_OFF                , "SE-PC-OFF"                ) \
    X(SE_PC_ON                 , "SE-PC-ON"                 ) \
    X(SE_SELECT                , "SE-SELECT"                ) \
    X(SE_WIN_OPEN              , "SE-WIN-OPEN"              ) \
    X(SE_WALL_HIT              , "SE-WALL-HIT"              ) \
    X(SE_DOOR                  , "SE-DOOR"                  ) \
    X(SE_EXIT                  , "SE-EXIT"                  ) \
    X(SE_LEDGE                 , "SE-LEDGE"                 ) \
    X(SE_BIKE_BELL             , "SE-BIKE-BELL"             ) \
    X(SE_NOT_EFFECTIVE         , "SE-NOT-EFFECTIVE"         ) \
    X(SE_EFFECTIVE             , "SE-EFFECTIVE"             ) \
    X(SE_SUPER_EFFECTIVE       , "SE-SUPER-EFFECTIVE"       ) \
    X(SE_BALL_OPEN             , "SE-BALL-OPEN"             ) \
    X(SE_FAINT                 , "SE-FAINT"                 ) \
    X(SE_FLEE                  , "SE-FLEE"                  ) \
    X(SE_SLIDING_DOOR          , "SE-SLIDING-DOOR"          ) \
    X(SE_SHIP                  , "SE-SHIP"                  ) \
    X(SE_BANG                  , "SE-BANG"                  ) \
    X(SE_PIN                   , "SE-PIN"                   ) \
    X(SE_BOO                   , "SE-BOO"                   ) \
    X(SE_BALL                  , "SE-BALL"                  ) \
    X(SE_CONTEST_PLACE         , "SE-CONTEST-PLACE"         ) \
    X(SE_A                     , "SE-A"                     ) \
    X(SE_I                     , "SE-I"                     ) \
    X(SE_U                     , "SE-U"                     ) \
    X(SE_E                     , "SE-E"                     ) \
    X(SE_O                     , "SE-O"                     ) \
    X(SE_N                     , "SE-N"                     ) \
    X(SE_SUCCESS               , "SE-SUCCESS"               ) \
    X(SE_FAILURE               , "SE-FAILURE"               ) \
    X(SE_EXP                   , "SE-EXP"                   ) \
    X(SE_BIKE_HOP              , "SE-BIKE-HOP"              ) \
    X(SE_SWITCH                , "SE-SWITCH"                ) \
    X(SE_CLICK                 , "SE-CLICK"                 ) \
    X(SE_FU_ZAKU               , "SE-FU-ZAKU"               ) \
    X(SE_CONTEST_CONDITION_LOSE, "SE-CONTEST-CONDITION-LOSE") \
    X(SE_LAVARIDGE_FALL_WARP   , "SE-LAVARIDGE-FALL-WARP"   ) \
    X(SE_ICE_STAIRS            , "SE-ICE-STAIRS"            ) \
    X(SE_ICE_BREAK             , "SE-ICE-BREAK"             ) \
    X(SE_ICE_CRACK             , "SE-ICE-CRACK"             ) \
    X(SE_FALL                  , "SE-FALL"                  ) \
    X(SE_UNLOCK                , "SE-UNLOCK"                ) \
    X(SE_WARP_IN               , "SE-WARP-IN"               ) \
    X(SE_WARP_OUT              , "SE-WARP-OUT"              ) \
    X(SE_REPEL                 , "SE-REPEL"                 ) \
    X(SE_ROTATING_GATE         , "SE-ROTATING-GATE"         ) \
    X(SE_TRUCK_MOVE            , "SE-TRUCK-MOVE"            ) \
    X(SE_TRUCK_STOP            , "SE-TRUCK-STOP"            ) \
    X(SE_TRUCK_UNLOAD          , "SE-TRUCK-UNLOAD"          ) \
    X(SE_TRUCK_DOOR            , "SE-TRUCK-DOOR"            ) \
    X(SE_BERRY_BLENDER         , "SE-BERRY-BLENDER"         ) \
    X(SE_CARD                  , "SE-CARD"                  ) \
    X(SE_SAVE                  , "SE-SAVE"                  ) \
    X(SE_BALL_BOUNCE_1         , "SE-BALL-BOUNCE-1"         ) \
    X(SE_BALL_BOUNCE_2         , "SE-BALL-BOUNCE-2"         ) \
    X(SE_BALL_BOUNCE_3         , "SE-BALL-BOUNCE-3"         ) \
    X(SE_BALL_BOUNCE_4         , "SE-BALL-BOUNCE-4"         ) \
    X(SE_BALL_TRADE            , "SE-BALL-TRADE"            ) \
    X(SE_BALL_THROW            , "SE-BALL-THROW"            ) \
    X(SE_NOTE_C                , "SE-NOTE-C"                ) \
    X(SE_NOTE_D                , "SE-NOTE-D"                ) \
    X(SE_NOTE_E                , "SE-NOTE-E"                ) \
    X(SE_NOTE_F                , "SE-NOTE-F"                ) \
    X(SE_NOTE_G                , "SE-NOTE-G"                ) \
    X(SE_NOTE_A                , "SE-NOTE-A"                ) \
    X(SE_NOTE_B                , "SE-NOTE-B"                ) \
    X(SE_NOTE_C_HIGH           , "SE-NOTE-C-HIGH"           ) \
    X(SE_PUDDLE                , "SE-PUDDLE"                ) \
    X(SE_BRIDGE_WALK           , "SE-BRIDGE-WALK"           ) \
    X(SE_ITEMFINDER            , "SE-ITEMFINDER"            ) \
    X(SE_DING_DONG             , "SE-DING-DONG"             ) \
    X(SE_BALLOON_RED           , "SE-BALLOON-RED"           ) \
    X(SE_BALLOON_BLUE          , "SE-BALLOON-BLUE"          ) \
    X(SE_BALLOON_YELLOW        , "SE-BALLOON-YELLOW"        ) \
    X(SE_BREAKABLE_DOOR        , "SE-BREAKABLE-DOOR"        ) \
    X(SE_MUD_BALL              , "SE-MUD-BALL"              ) \
    X(SE_FIELD_POISON          , "SE-FIELD-POISON"          ) \
    X(SE_ESCALATOR             , "SE-ESCALATOR"             ) \
    X(SE_THUNDERSTORM          , "SE-THUNDERSTORM"          ) \
    X(SE_THUNDERSTORM_STOP     , "SE-THUNDERSTORM-STOP"     ) \
    X(SE_DOWNPOUR              , "SE-DOWNPOUR"              ) \
    X(SE_DOWNPOUR_STOP         , "SE-DOWNPOUR-STOP"         ) \
    X(SE_RAIN                  , "SE-RAIN"                  ) \
    X(SE_RAIN_STOP             , "SE-RAIN-STOP"             ) \
    X(SE_THUNDER               , "SE-THUNDER"               ) \
    X(SE_THUNDER2              , "SE-THUNDER2"              ) \
    X(SE_ELEVATOR              , "SE-ELEVATOR"              ) \
    X(SE_LOW_HEALTH            , "SE-LOW-HEALTH"            ) \
    X(SE_EXP_MAX               , "SE-EXP-MAX"               ) \
    X(SE_ROULETTE_BALL         , "SE-ROULETTE-BALL"         ) \
    X(SE_ROULETTE_BALL2        , "SE-ROULETTE-BALL2"        ) \
    X(SE_TAILLOW_WING_FLAP     , "SE-TAILLOW-WING-FLAP"     ) \
    X(SE_SHOP                  , "SE-SHOP"                  ) \
    X(SE_CONTEST_HEART         , "SE-CONTEST-HEART"         ) \
    X(SE_CONTEST_CURTAIN_RISE  , "SE-CONTEST-CURTAIN-RISE"  ) \
    X(SE_CONTEST_CURTAIN_FALL  , "SE-CONTEST-CURTAIN-FALL"  ) \
    X(SE_CONTEST_ICON_CHANGE   , "SE-CONTEST-ICON-CHANGE"   ) \
    X(SE_CONTEST_ICON_CLEAR    , "SE-CONTEST-ICON-CLEAR"    ) \
    X(SE_CONTEST_MONS_TURN     , "SE-CONTEST-MONS-TURN"     ) \
    X(SE_SHINY                 , "SE-SHINY"                 ) \
    X(SE_INTRO_BLAST           , "SE-INTRO-BLAST"           ) \
    X(SE_MUGSHOT               , "SE-MUGSHOT"               ) \
    X(SE_APPLAUSE              , "SE-APPLAUSE"              ) \
    X(SE_VEND                  , "SE-VEND"                  ) \
    X(SE_ORB                   , "SE-ORB"                   ) \
    X(SE_DEX_SCROLL            , "SE-DEX-SCROLL"            ) \
    X(SE_DEX_PAGE              , "SE-DEX-PAGE"              ) \
    X(SE_POKENAV_ON            , "SE-POKENAV-ON"            ) \
    X(SE_POKENAV_OFF           , "SE-POKENAV-OFF"           ) \
    X(SE_DEX_SEARCH            , "SE-DEX-SEARCH"            ) \
    X(SE_EGG_HATCH             , "SE-EGG-HATCH"             ) \
    X(SE_BALL_TRAY_ENTER       , "SE-BALL-TRAY-ENTER"       ) \
    X(SE_BALL_TRAY_BALL        , "SE-BALL-TRAY-BALL"        ) \
    X(SE_BALL_TRAY_EXIT        , "SE-BALL-TRAY-EXIT"        ) \
    X(SE_GLASS_FLUTE           , "SE-GLASS-FLUTE"           ) \
    X(SE_M_THUNDERBOLT         , "SE-M-THUNDERBOLT"         ) \
    X(SE_M_THUNDERBOLT2        , "SE-M-THUNDERBOLT2"        ) \
    X(SE_M_HARDEN              , "SE-M-HARDEN"              ) \
    X(SE_M_NIGHTMARE           , "SE-M-NIGHTMARE"           ) \
    X(SE_M_VITAL_THROW         , "SE-M-VITAL-THROW"         ) \
    X(SE_M_VITAL_THROW2        , "SE-M-VITAL-THROW2"        ) \
    X(SE_M_BUBBLE              , "SE-M-BUBBLE"              ) \
    X(SE_M_BUBBLE2             , "SE-M-BUBBLE2"             ) \
    X(SE_M_BUBBLE3             , "SE-M-BUBBLE3"             ) \
    X(SE_M_RAIN_DANCE          , "SE-M-RAIN-DANCE"          ) \
    X(SE_M_CUT                 , "SE-M-CUT"                 ) \
    X(SE_M_STRING_SHOT         , "SE-M-STRING-SHOT"         ) \
    X(SE_M_STRING_SHOT2        , "SE-M-STRING-SHOT2"        ) \
    X(SE_M_ROCK_THROW          , "SE-M-ROCK-THROW"          ) \
    X(SE_M_GUST                , "SE-M-GUST"                ) \
    X(SE_M_GUST2               , "SE-M-GUST2"               ) \
    X(SE_M_DOUBLE_SLAP         , "SE-M-DOUBLE-SLAP"         ) \
    X(SE_M_DOUBLE_TEAM         , "SE-M-DOUBLE-TEAM"         ) \
    X(SE_M_RAZOR_WIND          , "SE-M-RAZOR-WIND"          ) \
    X(SE_M_ICY_WIND            , "SE-M-ICY-WIND"            ) \
    X(SE_M_THUNDER_WAVE        , "SE-M-THUNDER-WAVE"        ) \
    X(SE_M_COMET_PUNCH         , "SE-M-COMET-PUNCH"         ) \
    X(SE_M_MEGA_KICK           , "SE-M-MEGA-KICK"           ) \
    X(SE_M_MEGA_KICK2          , "SE-M-MEGA-KICK2"          ) \
    X(SE_M_CRABHAMMER          , "SE-M-CRABHAMMER"          ) \
    X(SE_M_JUMP_KICK           , "SE-M-JUMP-KICK"           ) \
    X(SE_M_FLAME_WHEEL         , "SE-M-FLAME-WHEEL"         ) \
    X(SE_M_FLAME_WHEEL2        , "SE-M-FLAME-WHEEL2"        ) \
    X(SE_M_FLAMETHROWER        , "SE-M-FLAMETHROWER"        ) \
    X(SE_M_FIRE_PUNCH          , "SE-M-FIRE-PUNCH"          ) \
    X(SE_M_TOXIC               , "SE-M-TOXIC"               ) \
    X(SE_M_SACRED_FIRE         , "SE-M-SACRED-FIRE"         ) \
    X(SE_M_SACRED_FIRE2        , "SE-M-SACRED-FIRE2"        ) \
    X(SE_M_EMBER               , "SE-M-EMBER"               ) \
    X(SE_M_TAKE_DOWN           , "SE-M-TAKE-DOWN"           ) \
    X(SE_M_BLIZZARD            , "SE-M-BLIZZARD"            ) \
    X(SE_M_BLIZZARD2           , "SE-M-BLIZZARD2"           ) \
    X(SE_M_SCRATCH             , "SE-M-SCRATCH"             ) \
    X(SE_M_VICEGRIP            , "SE-M-VICEGRIP"            ) \
    X(SE_M_WING_ATTACK         , "SE-M-WING-ATTACK"         ) \
    X(SE_M_FLY                 , "SE-M-FLY"                 ) \
    X(SE_M_SAND_ATTACK         , "SE-M-SAND-ATTACK"         ) \
    X(SE_M_RAZOR_WIND2         , "SE-M-RAZOR-WIND2"         ) \
    X(SE_M_BITE                , "SE-M-BITE"                ) \
    X(SE_M_HEADBUTT            , "SE-M-HEADBUTT"            ) \
    X(SE_M_SURF                , "SE-M-SURF"                ) \
    X(SE_M_HYDRO_PUMP          , "SE-M-HYDRO-PUMP"          ) \
    X(SE_M_WHIRLPOOL           , "SE-M-WHIRLPOOL"           ) \
    X(SE_M_HORN_ATTACK         , "SE-M-HORN-ATTACK"         ) \
    X(SE_M_TAIL_WHIP           , "SE-M-TAIL-WHIP"           ) \
    X(SE_M_MIST                , "SE-M-MIST"                ) \
    X(SE_M_POISON_POWDER       , "SE-M-POISON-POWDER"       ) \
    X(SE_M_BIND                , "SE-M-BIND"                ) \
    X(SE_M_DRAGON_RAGE         , "SE-M-DRAGON-RAGE"         ) \
    X(SE_M_SING                , "SE-M-SING"                ) \
    X(SE_M_PERISH_SONG         , "SE-M-PERISH-SONG"         ) \
    X(SE_M_PAY_DAY             , "SE-M-PAY-DAY"             ) \
    X(SE_M_DIG                 , "SE-M-DIG"                 ) \
    X(SE_M_DIZZY_PUNCH         , "SE-M-DIZZY-PUNCH"         ) \
    X(SE_M_SELF_DESTRUCT       , "SE-M-SELF-DESTRUCT"       ) \
    X(SE_M_EXPLOSION           , "SE-M-EXPLOSION"           ) \
    X(SE_M_ABSORB_2            , "SE-M-ABSORB-2"            ) \
    X(SE_M_ABSORB              , "SE-M-ABSORB"              ) \
    X(SE_M_SCREECH             , "SE-M-SCREECH"             ) \
    X(SE_M_BUBBLE_BEAM         , "SE-M-BUBBLE-BEAM"         ) \
    X(SE_M_BUBBLE_BEAM2        , "SE-M-BUBBLE-BEAM2"        ) \
    X(SE_M_SUPERSONIC          , "SE-M-SUPERSONIC"          ) \
    X(SE_M_BELLY_DRUM          , "SE-M-BELLY-DRUM"          ) \
    X(SE_M_METRONOME           , "SE-M-METRONOME"           ) \
    X(SE_M_BONEMERANG          , "SE-M-BONEMERANG"          ) \
    X(SE_M_LICK                , "SE-M-LICK"                ) \
    X(SE_M_PSYBEAM             , "SE-M-PSYBEAM"             ) \
    X(SE_M_FAINT_ATTACK        , "SE-M-FAINT-ATTACK"        ) \
    X(SE_M_SWORDS_DANCE        , "SE-M-SWORDS-DANCE"        ) \
    X(SE_M_LEER                , "SE-M-LEER"                ) \
    X(SE_M_SWAGGER             , "SE-M-SWAGGER"             ) \
    X(SE_M_SWAGGER2            , "SE-M-SWAGGER2"            ) \
    X(SE_M_HEAL_BELL           , "SE-M-HEAL-BELL"           ) \
    X(SE_M_CONFUSE_RAY         , "SE-M-CONFUSE-RAY"         ) \
    X(SE_M_SNORE               , "SE-M-SNORE"               ) \
    X(SE_M_BRICK_BREAK         , "SE-M-BRICK-BREAK"         ) \
    X(SE_M_GIGA_DRAIN          , "SE-M-GIGA-DRAIN"          ) \
    X(SE_M_PSYBEAM2            , "SE-M-PSYBEAM2"            ) \
    X(SE_M_SOLAR_BEAM          , "SE-M-SOLAR-BEAM"          ) \
    X(SE_M_PETAL_DANCE         , "SE-M-PETAL-DANCE"         ) \
    X(SE_M_TELEPORT            , "SE-M-TELEPORT"            ) \
    X(SE_M_MINIMIZE            , "SE-M-MINIMIZE"            ) \
    X(SE_M_SKETCH              , "SE-M-SKETCH"              ) \
    X(SE_M_SWIFT               , "SE-M-SWIFT"               ) \
    X(SE_M_REFLECT             , "SE-M-REFLECT"             ) \
    X(SE_M_BARRIER             , "SE-M-BARRIER"             ) \
    X(SE_M_DETECT              , "SE-M-DETECT"              ) \
    X(SE_M_LOCK_ON             , "SE-M-LOCK-ON"             ) \
    X(SE_M_MOONLIGHT           , "SE-M-MOONLIGHT"           ) \
    X(SE_M_CHARM               , "SE-M-CHARM"               ) \
    X(SE_M_CHARGE              , "SE-M-CHARGE"              ) \
    X(SE_M_STRENGTH            , "SE-M-STRENGTH"            ) \
    X(SE_M_HYPER_BEAM          , "SE-M-HYPER-BEAM"          ) \
    X(SE_M_WATERFALL           , "SE-M-WATERFALL"           ) \
    X(SE_M_REVERSAL            , "SE-M-REVERSAL"            ) \
    X(SE_M_ACID_ARMOR          , "SE-M-ACID-ARMOR"          ) \
    X(SE_M_SANDSTORM           , "SE-M-SANDSTORM"           ) \
    X(SE_M_TRI_ATTACK          , "SE-M-TRI-ATTACK"          ) \
    X(SE_M_TRI_ATTACK2         , "SE-M-TRI-ATTACK2"         ) \
    X(SE_M_ENCORE              , "SE-M-ENCORE"              ) \
    X(SE_M_ENCORE2             , "SE-M-ENCORE2"             ) \
    X(SE_M_BATON_PASS          , "SE-M-BATON-PASS"          ) \
    X(SE_M_MILK_DRINK          , "SE-M-MILK-DRINK"          ) \
    X(SE_M_ATTRACT             , "SE-M-ATTRACT"             ) \
    X(SE_M_ATTRACT2            , "SE-M-ATTRACT2"            ) \
    X(SE_M_MORNING_SUN         , "SE-M-MORNING-SUN"         ) \
    X(SE_M_FLATTER             , "SE-M-FLATTER"             ) \
    X(SE_M_SAND_TOMB           , "SE-M-SAND-TOMB"           ) \
    X(SE_M_GRASSWHISTLE        , "SE-M-GRASSWHISTLE"        ) \
    X(SE_M_SPIT_UP             , "SE-M-SPIT-UP"             ) \
    X(SE_M_DIVE                , "SE-M-DIVE"                ) \
    X(SE_M_EARTHQUAKE          , "SE-M-EARTHQUAKE"          ) \
    X(SE_M_TWISTER             , "SE-M-TWISTER"             ) \
    X(SE_M_SWEET_SCENT         , "SE-M-SWEET-SCENT"         ) \
    X(SE_M_YAWN                , "SE-M-YAWN"                ) \
    X(SE_M_SKY_UPPERCUT        , "SE-M-SKY-UPPERCUT"        ) \
    X(SE_M_STAT_INCREASE       , "SE-M-STAT-INCREASE"       ) \
    X(SE_M_HEAT_WAVE           , "SE-M-HEAT-WAVE"           ) \
    X(SE_M_UPROAR              , "SE-M-UPROAR"              ) \
    X(SE_M_HAIL                , "SE-M-HAIL"                ) \
    X(SE_M_COSMIC_POWER        , "SE-M-COSMIC-POWER"        ) \
    X(SE_M_TEETER_DANCE        , "SE-M-TEETER-DANCE"        ) \
    X(SE_M_STAT_DECREASE       , "SE-M-STAT-DECREASE"       ) \
    X(SE_M_HAZE                , "SE-M-HAZE"                ) \
    X(SE_M_HYPER_BEAM2         , "SE-M-HYPER-BEAM2"         ) \
    X(SE_RG_DOOR               , "SE-RG-DOOR"               ) \
    X(SE_RG_CARD_FLIP          , "SE-RG-CARD-FLIP"          ) \
    X(SE_RG_CARD_FLIPPING      , "SE-RG-CARD-FLIPPING"      ) \
    X(SE_RG_CARD_OPEN          , "SE-RG-CARD-OPEN"          ) \
    X(SE_RG_BAG_CURSOR         , "SE-RG-BAG-CURSOR"         ) \
    X(SE_RG_BAG_POCKET         , "SE-RG-BAG-POCKET"         ) \
    X(SE_RG_BALL_CLICK         , "SE-RG-BALL-CLICK"         ) \
    X(SE_RG_SHOP               , "SE-RG-SHOP"               ) \
    X(SE_RG_SS_ANNE_HORN       , "SE-RG-SS-ANNE-HORN"       ) \
    X(SE_RG_HELP_OPEN          , "SE-RG-HELP-OPEN"          ) \
    X(SE_RG_HELP_CLOSE         , "SE-RG-HELP-CLOSE"         ) \
    X(SE_RG_HELP_ERROR         , "SE-RG-HELP-ERROR"         ) \
    X(SE_RG_DEOXYS_MOVE        , "SE-RG-DEOXYS-MOVE"        ) \
    X(SE_RG_POKE_JUMP_SUCCESS  , "SE-RG-POKE-JUMP-SUCCESS"  ) \
    X(SE_RG_POKE_JUMP_FAILURE  , "SE-RG-POKE-JUMP-FAILURE"  ) \
    X(SE_PHONE_CALL            , "SE-PHONE-CALL"            ) \
    X(SE_PHONE_CLICK           , "SE-PHONE-CLICK"           ) \
    X(SE_ARENA_TIMEUP1         , "SE-ARENA-TIMEUP1"         ) \
    X(SE_ARENA_TIMEUP2         , "SE-ARENA-TIMEUP2"         ) \
    X(SE_PIKE_CURTAIN_CLOSE    , "SE-PIKE-CURTAIN-CLOSE"    ) \
    X(SE_PIKE_CURTAIN_OPEN     , "SE-PIKE-CURTAIN-OPEN"     ) \
    X(SE_SUDOWOODO_SHAKE       , "SE-SUDOWOODO-SHAKE"       ) \
    X(MUS_DUMMY                , "MUS-DUMMY"                ) \
    X(PH_TRAP_BLEND            , "PH-TRAP-BLEND"            ) \
    X(PH_TRAP_HELD             , "PH-TRAP-HELD"             ) \
    X(PH_TRAP_SOLO             , "PH-TRAP-SOLO"             ) \
    X(PH_FACE_BLEND            , "PH-FACE-BLEND"            ) \
    X(PH_FACE_HELD             , "PH-FACE-HELD"             ) \
    X(PH_FACE_SOLO             , "PH-FACE-SOLO"             ) \
    X(PH_CLOTH_BLEND           , "PH-CLOTH-BLEND"           ) \
    X(PH_CLOTH_HELD            , "PH-CLOTH-HELD"            ) \
    X(PH_CLOTH_SOLO            , "PH-CLOTH-SOLO"            ) \
    X(PH_DRESS_BLEND           , "PH-DRESS-BLEND"           ) \
    X(PH_DRESS_HELD            , "PH-DRESS-HELD"            ) \
    X(PH_DRESS_SOLO            , "PH-DRESS-SOLO"            ) \
    X(PH_FLEECE_BLEND          , "PH-FLEECE-BLEND"          ) \
    X(PH_FLEECE_HELD           , "PH-FLEECE-HELD"           ) \
    X(PH_FLEECE_SOLO           , "PH-FLEECE-SOLO"           ) \
    X(PH_KIT_BLEND             , "PH-KIT-BLEND"             ) \
    X(PH_KIT_HELD              , "PH-KIT-HELD"              ) \
    X(PH_KIT_SOLO              , "PH-KIT-SOLO"              ) \
    X(PH_PRICE_BLEND           , "PH-PRICE-BLEND"           ) \
    X(PH_PRICE_HELD            , "PH-PRICE-HELD"            ) \
    X(PH_PRICE_SOLO            , "PH-PRICE-SOLO"            ) \
    X(PH_LOT_BLEND             , "PH-LOT-BLEND"             ) \
    X(PH_LOT_HELD              , "PH-LOT-HELD"              ) \
    X(PH_LOT_SOLO              , "PH-LOT-SOLO"              ) \
    X(PH_GOAT_BLEND            , "PH-GOAT-BLEND"            ) \
    X(PH_GOAT_HELD             , "PH-GOAT-HELD"             ) \
    X(PH_GOAT_SOLO             , "PH-GOAT-SOLO"             ) \
    X(PH_THOUGHT_BLEND         , "PH-THOUGHT-BLEND"         ) \
    X(PH_THOUGHT_HELD          , "PH-THOUGHT-HELD"          ) \
    X(PH_THOUGHT_SOLO          , "PH-THOUGHT-SOLO"          ) \
    X(PH_CHOICE_BLEND          , "PH-CHOICE-BLEND"          ) \
    X(PH_CHOICE_HELD           , "PH-CHOICE-HELD"           ) \
    X(PH_CHOICE_SOLO           , "PH-CHOICE-SOLO"           ) \
    X(PH_MOUTH_BLEND           , "PH-MOUTH-BLEND"           ) \
    X(PH_MOUTH_HELD            , "PH-MOUTH-HELD"            ) \
    X(PH_MOUTH_SOLO            , "PH-MOUTH-SOLO"            ) \
    X(PH_FOOT_BLEND            , "PH-FOOT-BLEND"            ) \
    X(PH_FOOT_HELD             , "PH-FOOT-HELD"             ) \
    X(PH_FOOT_SOLO             , "PH-FOOT-SOLO"             ) \
    X(PH_GOOSE_BLEND           , "PH-GOOSE-BLEND"           ) \
    X(PH_GOOSE_HELD            , "PH-GOOSE-HELD"            ) \
    X(PH_GOOSE_SOLO            , "PH-GOOSE-SOLO"            ) \
    X(PH_STRUT_BLEND           , "PH-STRUT-BLEND"           ) \
    X(PH_STRUT_HELD            , "PH-STRUT-HELD"            ) \
    X(PH_STRUT_SOLO            , "PH-STRUT-SOLO"            ) \
    X(PH_CURE_BLEND            , "PH-CURE-BLEND"            ) \
    X(PH_CURE_HELD             , "PH-CURE-HELD"             ) \
    X(PH_CURE_SOLO             , "PH-CURE-SOLO"             ) \
    X(PH_NURSE_BLEND           , "PH-NURSE-BLEND"           ) \
    X(PH_NURSE_HELD            , "PH-NURSE-HELD"            ) \
    X(PH_NURSE_SOLO            , "PH-NURSE-SOLO"            ) \

// Create BGM list
#define X(songId, name) static const u8 sBGMName_##songId[] = _(name);
SOUND_LIST_BGM
#undef X

#define X(songId, name) sBGMName_##songId,
static const u8 *const gBGMNames[] =
{
SOUND_LIST_BGM
};
#undef X

// Create SE list
#define X(songId, name) static const u8 sSEName_##songId[] = _(name);
SOUND_LIST_SE
#undef X

#define X(songId, name) sSEName_##songId,
static const u8 *const gSENames[] =
{
SOUND_LIST_SE
};
#undef X

#undef tWindowSelected
#undef tBgmIndex
#undef tSeIndex
#undef tBgmIndexOld
#undef tSeIndexOld
#undef tWhichSubmenu
#undef tState