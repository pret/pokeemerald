#include "global.h"
#include "naming_screen.h"
#include "malloc.h"
#include "palette.h"
#include "task.h"
#include "sprite.h"
#include "string_util.h"
#include "window.h"
#include "bg.h"
#include "gpu_regs.h"
#include "pokemon.h"
#include "field_specials.h"
#include "field_player_avatar.h"
#include "event_object_movement.h"
#include "event_data.h"
#include "constants/vars.h"
#include "constants/songs.h"
#include "pokemon_storage_system.h"
#include "graphics.h"
#include "sound.h"
#include "trig.h"
#include "field_effect.h"
#include "pokemon_icon.h"
#include "data.h"
#include "strings.h"
#include "menu.h"
#include "text_window.h"
#include "overworld.h"
#include "constants/event_objects.h"
#include "constants/rgb.h"

EWRAM_DATA static struct NamingScreenData *gNamingScreenData = NULL;
extern u16 gKeyRepeatStartDelay;

// extern text
extern const u8 gText_MoveOkBack[];
extern const u8 gText_YourName[];
extern const u8 gText_BoxName[];
extern const u8 gText_PkmnsNickname[];
extern const u8 gText_TellHimTheWords[];


// start of .rodata
static const u8 gSpriteImage_858BBF8[] = INCBIN_U8("graphics/naming_screen/pc_icon/0.4bpp");
static const u8 gSpriteImage_858BCB8[] = INCBIN_U8("graphics/naming_screen/pc_icon/1.4bpp");
static const u16 gUnknown_0858BD78[] = INCBIN_U16("graphics/naming_screen/0.gbapal");
static const u16 gUnknown_0858BD98[] = INCBIN_U16("graphics/naming_screen/1.gbapal");

static const u8 *const sTransferredToPCMessages[] =
{
    gText_PkmnTransferredSomeonesPC,
    gText_PkmnTransferredLanettesPC,
    gText_PkmnTransferredSomeonesPCBoxFull,
    gText_PkmnTransferredLanettesPCBoxFull
};

static const u8 sText_AlphabetUpperLower[] = _("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!");

static const struct BgTemplate gUnknown_0858BE00[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .priority = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .priority = 1
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
        .priority = 2
    },
    {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .priority = 3
    }
};

static const struct WindowTemplate gUnknown_0858BE10[] =
{
    {
        .bg = 1,
        .tilemapLeft = 3,
        .tilemapTop = 10,
        .width = 19,
        .height = 8,
        .paletteNum = 10,
        .baseBlock = 0x030
    },
    {
        .bg = 2,
        .tilemapLeft = 3,
        .tilemapTop = 10,
        .width = 19,
        .height = 8,
        .paletteNum = 10,
        .baseBlock = 0x0C8
    },
    {
        .bg = 3,
        .tilemapLeft = 8,
        .tilemapTop = 6,
        .width = 17,
        .height = 2,
        .paletteNum = 10,
        .baseBlock = 0x030
    },
    {
        .bg = 3,
        .tilemapLeft = 8,
        .tilemapTop = 4,
        .width = 17,
        .height = 2,
        .paletteNum = 10,
        .baseBlock = 0x052
    },
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 11,
        .baseBlock = 0x074
    },
    DUMMY_WIN_TEMPLATE
};

static const u8 gUnknown_0858BE40[] = __("abcdef .ghijkl ,mnopqrs tuvwxyz ABCDEF .GHIJKL ,MNOPQRS TUVWXYZ 01234   56789   !?♂♀/-  …“”‘'   ");

static const u8 gUnknown_0858BEA0[] = { 8, 8, 6 };
static const u8 gUnknown_0858BEA3[] = { 0, 12, 24, 56, 68, 80, 92, 123, 0, 12, 24, 56, 68, 80, 92, 123, 0, 22, 44, 66, 88, 110, 0, 0 };

// forward declarations
static const struct NamingScreenTemplate *const sNamingScreenTemplates[];
static const struct SubspriteTable gUnknown_0858C050[];
static const struct SubspriteTable gUnknown_0858C058[];
static const struct SubspriteTable gUnknown_0858C070[];
static const struct SubspriteTable gUnknown_0858C078[];
static const struct SpriteTemplate gUnknown_0858C0C0;
static const struct SpriteTemplate gUnknown_0858C0D8;
static const struct SpriteTemplate gUnknown_0858C0F0;
static const struct SpriteTemplate gUnknown_0858C108;
static const struct SpriteTemplate gUnknown_0858C120;
static const struct SpriteTemplate gUnknown_0858C138;
static const struct SpriteTemplate sSpriteTemplate_InputArrow;
static const struct SpriteTemplate sSpriteTemplate_Underscore;
static const struct SpriteTemplate gUnknown_0858C180;
static const u8* const sNamingScreenKeyboardText[KBPAGE_COUNT][KBROW_COUNT];
static const struct SpriteSheet gUnknown_0858C1C8[];
static const struct SpritePalette gUnknown_0858C230[];

static void C2_NamingScreen(void);
static void NamingScreen_Init(void);
static void NamingScreen_InitBGs(void);
static void sub_80E3194(void);
static void sub_80E31B0(u8 taskId);
static bool8 MainState_BeginFadeIn(void);
static bool8 MainState_WaitFadeIn(void);
static bool8 MainState_HandleInput(void);
static bool8 MainState_MoveToOKButton(void);
static bool8 MainState_6(void);
static bool8 MainState_BeginFadeInOut(void);
static bool8 MainState_WaitFadeOutAndExit(void);
static void DisplaySentToPCMessage(void);
static bool8 sub_80E3604(void);
static bool8 MainState_StartPageSwap(void);
static bool8 MainState_WaitPageSwap(void);
static void StartPageSwapAnim(void);
static void Task_HandlePageSwapAnim(u8);
static bool8 IsPageSwapAnimNotInProgress(void);
static void sub_80E3948(u8, u8, u8);
static void Task_80E39BC(u8);
static u16 sub_80E3A74(u8);
static void sub_80E3AE8(u8);
static void sub_80E3B10(struct Task *, u8, u8);
static void sub_80E3CC8(void);
static void CursorInit(void);
static void SetCursorPos(s16, s16);
static void GetCursorPos(s16 *x, s16 *y);
static void MoveCursorToOKButton(void);
static void sub_80E3E3C(u8);
static void sub_80E3E94(u8);
static u8 IsCursorAnimFinished(void);
static u8 GetCurrentPageColumnCount(void);
static void CreatePageSwitcherSprites(void);
static void sub_80E4050(void);
static void sub_80E41B8(u8, struct Sprite *, struct Sprite *);
static void CreateBackOkSprites(void);
static void CreateUnderscoreSprites(void);
static void CreateInputTargetIcon(void);
static u8 HandleKeyboardEvent(void);
static u8 sub_80E45E0(void);
static u8 GetInputEvent(void);
static void SetInputState(u8);
static void sub_80E4964(void);
static u8 GetTextCaretPosition(void);
static void DeleteTextCharacter(void);
static bool8 sub_80E4B54(void);
static void AddTextCharacter(u8);
static void sub_80E4BE4(void);
static void choose_name_or_words_screen_load_bg_tile_patterns(void);
static void sub_80E4CB8(void);
static void choose_name_or_words_screen_apply_bg_pals(void);
static void sub_80E4CF8(u8, const void *);
static void nullsub_10(u8, u8);
static void sub_80E4D10(void);
static void sub_80E4DE4(u8, u8);
static void sub_80E4E5C(void);
static void sub_80E4EF0(void);
static void sub_80E4F58(void);
static void NamingScreen_TurnOffScreen(void);
static void NamingScreen_InitDisplayMode(void);
static void VBlankCB_NamingScreen(void);
static void sub_80E501C(void);
static bool8 IsLetter(u8);

void DoNamingScreen(u8 templateNum, u8 *destBuffer, u16 monSpecies, u16 monGender, u32 monPersonality, MainCallback returnCallback)
{
    gNamingScreenData = Alloc(sizeof(struct NamingScreenData));
    if (!gNamingScreenData)
    {
        SetMainCallback2(returnCallback);
    }
    else
    {
        gNamingScreenData->templateNum = templateNum;
        gNamingScreenData->monSpecies = monSpecies;
        gNamingScreenData->monGender = monGender;
        gNamingScreenData->monPersonality = monPersonality;
        gNamingScreenData->destBuffer = destBuffer;
        gNamingScreenData->returnCallback = returnCallback;

        if (templateNum == 0)
            StartTimer1();

        SetMainCallback2(C2_NamingScreen);
    }
}

static void C2_NamingScreen(void)
{
    switch (gMain.state)
    {
    case 0:
        NamingScreen_TurnOffScreen();
        NamingScreen_Init();
        gMain.state++;
        break;
    case 1:
        NamingScreen_InitBGs();
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        gMain.state++;
        break;
    case 3:
        ResetSpriteData();
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 4:
        ResetTasks();
        gMain.state++;
        break;
    case 5:
        choose_name_or_words_screen_apply_bg_pals();
        gMain.state++;
        break;
    case 6:
        choose_name_or_words_screen_load_bg_tile_patterns();
        gMain.state++;
        break;
    case 7:
        sub_80E3CC8();
        UpdatePaletteFade();
        sub_80E501C();
        gMain.state++;
        break;
    default:
        sub_80E4CB8();
        sub_80E3194();
        break;
    }
}

static void NamingScreen_Init(void)
{
    gNamingScreenData->state = 0;
    gNamingScreenData->bg1vOffset = 0;
    gNamingScreenData->bg2vOffset = 0;
    gNamingScreenData->bg1Priority = BGCNT_PRIORITY(1);
    gNamingScreenData->bg2Priority = BGCNT_PRIORITY(2);
    gNamingScreenData->bgToReveal = 0;
    gNamingScreenData->bgToHide = 1;
    gNamingScreenData->template = sNamingScreenTemplates[gNamingScreenData->templateNum];
    gNamingScreenData->currentPage = gNamingScreenData->template->initialPage;
    gNamingScreenData->inputCharBaseXPos = (240 - gNamingScreenData->template->maxChars * 8) / 2 + 6;
    if (gNamingScreenData->templateNum == 4)
        gNamingScreenData->inputCharBaseXPos += 11;
    gNamingScreenData->keyRepeatStartDelayCopy = gKeyRepeatStartDelay;
    memset(gNamingScreenData->textBuffer, 0xFF, sizeof(gNamingScreenData->textBuffer));
    if (gNamingScreenData->template->copyExistingString != 0)
        StringCopy(gNamingScreenData->textBuffer, gNamingScreenData->destBuffer);
    gKeyRepeatStartDelay = 16;
}

static void sub_80E2FA4(void)
{
    u8 i;
    for (i = 0; i < MAX_SPRITES; i++)
    {
        if (gSprites[i].inUse)
            gSprites[i].invisible = FALSE;
    }
    sub_80E3E3C(0);
}

static void NamingScreen_InitBGs(void)
{
    u8 i;

    DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
    DmaClear32(3, (void *)OAM, OAM_SIZE);
    DmaClear16(3, (void *)PLTT, PLTT_SIZE);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_0858BE00, 4);

    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);

    InitStandardTextBoxWindows();
    sub_8197200();

    for (i = 0; i < 5; i++)
        gNamingScreenData->windows[i] = AddWindow(&gUnknown_0858BE10[i]);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0xC, 0x8));

    SetBgTilemapBuffer(1, gNamingScreenData->tilemapBuffer1);
    SetBgTilemapBuffer(2, gNamingScreenData->tilemapBuffer2);
    SetBgTilemapBuffer(3, gNamingScreenData->tilemapBuffer3);

    FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 0x20, 0x20);
    FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 0x20, 0x20);
    FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 0x20, 0x20);
}

static void sub_80E3194(void)
{
    CreateTask(sub_80E31B0, 2);
    SetMainCallback2(sub_80E4F58);
}

static void sub_80E31B0(u8 taskId)
{
    switch (gNamingScreenData->state)
    {
    case 0:
        MainState_BeginFadeIn();
        sub_80E2FA4();
        NamingScreen_InitDisplayMode();
        break;
    case 1:
        MainState_WaitFadeIn();
        break;
    case 2:
        MainState_HandleInput();
        break;
    case 3:
        MainState_MoveToOKButton();
        MainState_HandleInput();
        break;
    case 4:
        MainState_StartPageSwap();
        break;
    case 5:
        MainState_WaitPageSwap();
        break;
    case 6:
        MainState_6();
        break;
    case 7:
        sub_80E3604();
        break;
    case 8:
        MainState_BeginFadeInOut();
        break;
    case 9:
        MainState_WaitFadeOutAndExit();
        break;
    }
}

static const u8 sPageOrderLowerFirst[] = 
{ 
    KBPAGE_LETTERS_LOWER, 
    KBPAGE_SYMBOLS, 
    KBPAGE_LETTERS_UPPER 
};

static const u8 sPageOrderUpperFirst[] = 
{ 
    KBPAGE_LETTERS_UPPER, 
    KBPAGE_LETTERS_LOWER, 
    KBPAGE_SYMBOLS 
};

static const u8 sPageOrderSymbolsFirst[] = 
{ 
    KBPAGE_SYMBOLS, 
    KBPAGE_LETTERS_UPPER, 
    KBPAGE_LETTERS_LOWER 
};

static u8 sub_80E3244(u8 a1)
{
    return sPageOrderLowerFirst[a1];
}

static u8 sub_80E3254(void)
{
    return sPageOrderUpperFirst[gNamingScreenData->currentPage];
}

static u8 sub_80E3274(void)
{
    return sPageOrderSymbolsFirst[gNamingScreenData->currentPage];
}

static bool8 MainState_BeginFadeIn(void)
{
    sub_80E4CF8(3, gUnknown_08DD4544);
    gNamingScreenData->currentPage = KBPAGE_LETTERS_UPPER;
    sub_80E4CF8(2, gUnknown_08DD46E0);
    sub_80E4CF8(1, gUnknown_08DD4620);
    sub_80E4DE4(gNamingScreenData->windows[1], KBPAGE_LETTERS_LOWER);
    sub_80E4DE4(gNamingScreenData->windows[0], KBPAGE_LETTERS_UPPER);
    nullsub_10(2, KBPAGE_LETTERS_LOWER);
    nullsub_10(1, KBPAGE_LETTERS_UPPER);
    sub_80E4D10();
    sub_80E4964();
    sub_80E4EF0();
    CopyBgTilemapBufferToVram(1);
    CopyBgTilemapBufferToVram(2);
    CopyBgTilemapBufferToVram(3);
    BlendPalettes(-1, 16, 0);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
    gNamingScreenData->state++;
    return FALSE;
}

static bool8 MainState_WaitFadeIn(void)
{
    if (!gPaletteFade.active)
    {
        SetInputState(INPUT_STATE_ENABLED);
        sub_80E3E94(1);
        gNamingScreenData->state++;
    }
    return FALSE;
}

static bool8 MainState_HandleInput(void)
{
    return HandleKeyboardEvent();
}

static bool8 MainState_MoveToOKButton(void)
{
    if (IsCursorAnimFinished())
    {
        SetInputState(INPUT_STATE_ENABLED);
        MoveCursorToOKButton();
        gNamingScreenData->state = MAIN_STATE_HANDLE_INPUT;
    }
    return FALSE;
}

static bool8 MainState_6(void)
{
    sub_80E4BE4();
    SetInputState(INPUT_STATE_DISABLED);
    sub_80E3E94(0);
    sub_80E3948(3, 0, 1);
    if (gNamingScreenData->templateNum == NAMING_SCREEN_CAUGHT_MON &&
        CalculatePlayerPartyCount() >= 6)
    {
        DisplaySentToPCMessage();
        gNamingScreenData->state = MAIN_STATE_UPDATE_SENT_TO_PC_MESSAGE;
        return FALSE;
    }
    else
    {
        gNamingScreenData->state = MAIN_STATE_BEGIN_FADE_OUT;
        return TRUE;  //Exit the naming screen
    }
}

static bool8 MainState_BeginFadeInOut(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    gNamingScreenData->state++;
    return FALSE;
}

static bool8 MainState_WaitFadeOutAndExit(void)
{
    if (!gPaletteFade.active)
    {
        if (gNamingScreenData->templateNum == NAMING_SCREEN_PLAYER)
            SeedRngAndSetTrainerId();
        SetMainCallback2(gNamingScreenData->returnCallback);
        DestroyTask(FindTaskIdByFunc(sub_80E31B0));
        FreeAllWindowBuffers();
        FREE_AND_SET_NULL(gNamingScreenData);
    }
    return FALSE;
}

static void DisplaySentToPCMessage(void)
{
    u8 stringToDisplay = 0;

    if (!IsDestinationBoxFull())
    {
        StringCopy(gStringVar1, GetBoxNamePtr(VarGet(VAR_PC_BOX_TO_SEND_MON)));
        StringCopy(gStringVar2, gNamingScreenData->destBuffer);
    }
    else
    {
        StringCopy(gStringVar1, GetBoxNamePtr(VarGet(VAR_PC_BOX_TO_SEND_MON)));
        StringCopy(gStringVar2, gNamingScreenData->destBuffer);
        StringCopy(gStringVar3, GetBoxNamePtr(GetPCBoxToSendMon()));
        stringToDisplay = 2;
    }

    if (FlagGet(FLAG_SYS_PC_LANETTE))
        stringToDisplay++;

    StringExpandPlaceholders(gStringVar4, sTransferredToPCMessages[stringToDisplay]);
    DrawDialogueFrame(0, 0);
    gTextFlags.canABSpeedUpPrint = TRUE;
    AddTextPrinterParameterized2(0, 1, gStringVar4, GetPlayerTextSpeedDelay(), 0, 2, 1, 3);
    CopyWindowToVram(0, 3);
}

static bool8 sub_80E3604(void)
{
    RunTextPrinters();

    if (!IsTextPrinterActive(0) && (gMain.newKeys & A_BUTTON))
        gNamingScreenData->state = MAIN_STATE_BEGIN_FADE_OUT;

    return FALSE;
}

static bool8 MainState_StartPageSwap(void)
{
    SetInputState(INPUT_STATE_DISABLED);
    sub_80E4050();
    StartPageSwapAnim();
    sub_80E3E3C(1);
    sub_80E3948(0, 0, 1);
    PlaySE(SE_WIN_OPEN);
    gNamingScreenData->state = MAIN_STATE_WAIT_PAGE_SWAP;
    return FALSE;
}

static bool8 MainState_WaitPageSwap(void)
{
    s16 cursorX;
    s16 cursorY;
    bool32 var3;

    if (IsPageSwapAnimNotInProgress())
    {

        GetCursorPos(&cursorX, &cursorY);
        var3 = (cursorX == GetCurrentPageColumnCount());

        gNamingScreenData->state = MAIN_STATE_HANDLE_INPUT;
        gNamingScreenData->currentPage++;
        gNamingScreenData->currentPage %= 3;

        if (var3)
        {
            cursorX = GetCurrentPageColumnCount();
        }
        else
        {
            if (cursorX >= GetCurrentPageColumnCount())
                cursorX = GetCurrentPageColumnCount() - 1;
        }

        SetCursorPos(cursorX, cursorY);
        sub_80E4E5C();
        SetInputState(INPUT_STATE_ENABLED);
        sub_80E3E3C(0);
    }
    return FALSE;
}

//--------------------------------------------------
// Page Swap
//--------------------------------------------------

#define tState data[0]
#define tFrameCount data[1]

static bool8 PageSwapAnimState_Init(struct Task *);
static bool8 PageSwapAnimState_1(struct Task *);
static bool8 PageSwapAnimState_2(struct Task *);
static bool8 PageSwapAnimState_Done(struct Task *);

static bool8 (*const sPageSwapAnimStateFuncs[])(struct Task *) =
{
    PageSwapAnimState_Init,
    PageSwapAnimState_1,
    PageSwapAnimState_2,
    PageSwapAnimState_Done,
};

static void StartPageSwapAnim(void)
{
    u8 taskId;

    taskId = CreateTask(Task_HandlePageSwapAnim, 0);
    Task_HandlePageSwapAnim(taskId);
}

static void Task_HandlePageSwapAnim(u8 taskId)
{
    while (sPageSwapAnimStateFuncs[gTasks[taskId].tState](&gTasks[taskId]) != 0);
}

static bool8 IsPageSwapAnimNotInProgress(void)
{
    if (FindTaskIdByFunc(Task_HandlePageSwapAnim) == 0xFF)
        return TRUE;
    else
        return FALSE;
}

static bool8 PageSwapAnimState_Init(struct Task *task)
{
    gNamingScreenData->bg1vOffset = 0;
    gNamingScreenData->bg2vOffset = 0;
    task->tState++;
    return 0;
}

static bool8 PageSwapAnimState_1(struct Task *task)
{
    u16 *const arr[] =
    {
        &gNamingScreenData->bg2vOffset,
        &gNamingScreenData->bg1vOffset
    };

    task->tFrameCount += 4;
    *arr[gNamingScreenData->bgToReveal] = Sin(task->tFrameCount, 40);
    *arr[gNamingScreenData->bgToHide] = Sin((task->tFrameCount + 128) & 0xFF, 40);
    if (task->tFrameCount >= 64)
    {
        u8 temp = gNamingScreenData->bg1Priority;  //Why u8 and not u16?

        gNamingScreenData->bg1Priority = gNamingScreenData->bg2Priority;
        gNamingScreenData->bg2Priority = temp;
        task->tState++;
    }
    return 0;
}

static bool8 PageSwapAnimState_2(struct Task *task)
{
    u16 *const arr[] =
    {
        &gNamingScreenData->bg2vOffset,
        &gNamingScreenData->bg1vOffset
    };

    task->tFrameCount += 4;
    *arr[gNamingScreenData->bgToReveal] = Sin(task->tFrameCount, 40);
    *arr[gNamingScreenData->bgToHide] = Sin((task->tFrameCount + 128) & 0xFF, 40);
    if (task->tFrameCount >= 128)
    {
        u8 temp = gNamingScreenData->bgToReveal;

        gNamingScreenData->bgToReveal = gNamingScreenData->bgToHide;
        gNamingScreenData->bgToHide = temp;
        task->tState++;
    }
    return 0;
}

static bool8 PageSwapAnimState_Done(struct Task *task)
{
    DestroyTask(FindTaskIdByFunc(Task_HandlePageSwapAnim));
    return 0;
}

#undef tState
#undef tFrameCount

//--------------------------------------------------
//
//--------------------------------------------------

static void sub_80E3920(void)
{
    u8 taskId;

    taskId = CreateTask(Task_80E39BC, 3);
    gTasks[taskId].data[0] = 3;
}

static void sub_80E3948(u8 a, u8 b, u8 c)
{
    struct Task *task = &gTasks[FindTaskIdByFunc(Task_80E39BC)];

    if (a == task->data[0] && c == 0)
    {
        task->data[1] = b;
        task->data[2] = 1;
        return;
    }
    if (a == 3 && task->data[1] == 0 && c == 0)
        return;
    if (task->data[0] != 3)
        sub_80E3AE8(task->data[0]);
    sub_80E3B10(task, a, b);
}

static void Task_80E39BC(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (task->data[0] == 3 || task->data[2] == 0)
        return;
    MultiplyInvertedPaletteRGBComponents(sub_80E3A74(task->data[0]), task->data[3], task->data[3], task->data[3]);
    if (task->data[5] != 0)
    {
        task->data[5]--;
        if (task->data[5] != 0)
            return;
    }
    task->data[5] = 2;
    if (task->data[4] >= 0)
    {
        if (task->data[3] < 14)
        {
            task->data[3] += task->data[4];
            task->data[6] += task->data[4];
        }
        else
        {
            task->data[3] = 16;
            task->data[6]++;
        }
    }
    else
    {
        task->data[3] += task->data[4];
        task->data[6] += task->data[4];
    }

    if (task->data[3] == 16 && task->data[6] == 22)
    {
        task->data[4] = -4;
    }
    else if (task->data[3] == 0)
    {
        task->data[2] = task->data[1];
        task->data[4] = 2;
        task->data[6] = 0;
    }
}

static u16 sub_80E3A74(u8 a)
{
    const u16 arr[] =
    {
        IndexOfSpritePaletteTag(4) * 16 + 0x10E,
        IndexOfSpritePaletteTag(6) * 16 + 0x10E,
        IndexOfSpritePaletteTag(7) * 16 + 0x10E,
        IndexOfSpritePaletteTag(7) * 16 + 0x101,
    };

    return arr[a];
}

static void sub_80E3AE8(u8 a)
{
    u16 index = sub_80E3A74(a);

    gPlttBufferFaded[index] = gPlttBufferUnfaded[index];
}

static void sub_80E3B10(struct Task *task, u8 b, u8 c)
{
    task->data[0] = b;
    task->data[1] = c;
    task->data[2] = 1;
    task->data[3] = 4;
    task->data[4] = 2;
    task->data[5] = 0;
    task->data[6] = 4;
}

static void sub_80E3B30(struct Sprite *sprite)
{
    if (sprite->animEnded)
        StartSpriteAnim(sprite, 0);
    sprite->invisible = (sprite->data[4] & 0xFF);
    if (sprite->data[0] == GetCurrentPageColumnCount())
        sprite->invisible = TRUE;
    if (sprite->invisible || (sprite->data[4] & 0xFF00) == 0
     || sprite->data[0] != sprite->data[2] || sprite->data[1] != sprite->data[3])
    {
        sprite->data[5] = 0;
        sprite->data[6] = 2;
        sprite->data[7] = 2;
    }
    sprite->data[7]--;
    if (sprite->data[7] == 0)
    {
        sprite->data[5] += sprite->data[6];
        if (sprite->data[5] == 16 || sprite->data[5] == 0)
            sprite->data[6] = -sprite->data[6];
        sprite->data[7] = 2;
    }
    if ((sprite->data[4] & 0xFF00) != 0)
    {
        s8 gb = sprite->data[5];
        s8 r = sprite->data[5] >> 1;
        u16 index = IndexOfSpritePaletteTag(5) * 16 + 0x0101;

        MultiplyInvertedPaletteRGBComponents(index, r, gb, gb);
    }
}

static void sub_80E3C20(struct Sprite *sprite)
{
    const s16 arr[] = {0, -4, -2, -1};

    if (sprite->data[0] == 0 || --sprite->data[0] == 0)
    {
        sprite->data[0] = 8;
        sprite->data[1] = (sprite->data[1] + 1) & 3;
    }
    sprite->pos2.x = arr[sprite->data[1]];
}

static void sub_80E3C6C(struct Sprite *sprite)
{
    const s16 arr[] = {2, 3, 2, 1};
    u8 var;

    var = GetTextCaretPosition();
    if (var != (u8)sprite->data[0])
    {
        sprite->pos2.y = 0;
        sprite->data[1] = 0;
        sprite->data[2] = 0;
    }
    else
    {
        sprite->pos2.y = arr[sprite->data[1]];
        sprite->data[2]++;
        if (sprite->data[2] > 8)
        {
            sprite->data[1] = (sprite->data[1] + 1) & 3;
            sprite->data[2] = 0;
        }
    }
}

//--------------------------------------------------
// Cursor
//--------------------------------------------------

static void sub_80E3CC8(void)
{
    CursorInit();
    CreatePageSwitcherSprites();
    CreateBackOkSprites();
    CreateUnderscoreSprites();
    CreateInputTargetIcon();
}

static void CursorInit(void)
{
    gNamingScreenData->cursorSpriteId = CreateSprite(&gUnknown_0858C138, 38, 88, 1);
    sub_80E3E3C(1);
    gSprites[gNamingScreenData->cursorSpriteId].oam.priority = 1;
    gSprites[gNamingScreenData->cursorSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
    gSprites[gNamingScreenData->cursorSpriteId].data[6] = 1;
    gSprites[gNamingScreenData->cursorSpriteId].data[6] = 2;
    SetCursorPos(0, 0);
}

static void SetCursorPos(s16 x, s16 y)
{
    struct Sprite *cursorSprite = &gSprites[gNamingScreenData->cursorSpriteId];

    if (x < gUnknown_0858BEA0[sub_80E3274()])
        cursorSprite->pos1.x = gUnknown_0858BEA3[x + sub_80E3274() * 8] + 38;
    else
        cursorSprite->pos1.x = 0;

    cursorSprite->pos1.y = y * 16 + 88;
    cursorSprite->data[2] = cursorSprite->data[0];
    cursorSprite->data[3] = cursorSprite->data[1];
    cursorSprite->data[0] = x;
    cursorSprite->data[1] = y;
}

static void GetCursorPos(s16 *x, s16 *y)
{
    struct Sprite *cursorSprite = &gSprites[gNamingScreenData->cursorSpriteId];

    *x = cursorSprite->data[0];
    *y = cursorSprite->data[1];
}

static void MoveCursorToOKButton(void)
{
    SetCursorPos(GetCurrentPageColumnCount(), 2);
}

static void sub_80E3E3C(u8 a)
{
    gSprites[gNamingScreenData->cursorSpriteId].data[4] &= -256;
    gSprites[gNamingScreenData->cursorSpriteId].data[4] |= a;
    StartSpriteAnim(&gSprites[gNamingScreenData->cursorSpriteId], 0);
}

static void sub_80E3E94(u8 a)
{
    gSprites[gNamingScreenData->cursorSpriteId].data[4] &= 0xFF;
    gSprites[gNamingScreenData->cursorSpriteId].data[4] |= a << 8;
}

static void sub_80E3ED8(void)
{
    StartSpriteAnim(&gSprites[gNamingScreenData->cursorSpriteId], 1);
}

static bool8 IsCursorAnimFinished(void)
{
    return gSprites[gNamingScreenData->cursorSpriteId].animEnded;
}

enum
{
    KEY_ROLE_CHAR,
    KEY_ROLE_PAGE,
    KEY_ROLE_BACKSPACE,
    KEY_ROLE_OK,
};

static const u8 sKeyRoles[] = {KEY_ROLE_PAGE, KEY_ROLE_BACKSPACE, KEY_ROLE_OK};

static u8 GetKeyRoleAtCursorPos(void)
{
    s16 cursorX;
    s16 cursorY;

    GetCursorPos(&cursorX, &cursorY);
    if (cursorX < GetCurrentPageColumnCount())
        return KEY_ROLE_CHAR;
    else
        return sKeyRoles[cursorY];
}

static u8 GetCurrentPageColumnCount(void)
{
    return gUnknown_0858BEA0[sub_80E3274()];
}

static void CreatePageSwitcherSprites(void)
{
    u8 spriteId1;
    u8 spriteId2;
    u8 spriteId3;

    spriteId1 = CreateSprite(&gUnknown_0858C0C0, 0xCC, 0x58, 0);
    gNamingScreenData->selectBtnFrameSpriteId = spriteId1;
    SetSubspriteTables(&gSprites[spriteId1], gUnknown_0858C050);
    gSprites[spriteId1].invisible = TRUE;

    spriteId2 = CreateSprite(&gUnknown_0858C0F0, 0xCC, 0x54, 1);
    gSprites[spriteId1].data[6] = spriteId2;
    SetSubspriteTables(&gSprites[spriteId2], gUnknown_0858C058);
    gSprites[spriteId2].invisible = TRUE;

    spriteId3 = CreateSprite(&gUnknown_0858C0D8, 0xCC, 0x53, 2);
    gSprites[spriteId3].oam.priority = 1;
    gSprites[spriteId1].data[7] = spriteId3;
    gSprites[spriteId3].invisible = TRUE;
}

static void sub_80E4050(void)
{
    struct Sprite *sprite = &gSprites[gNamingScreenData->selectBtnFrameSpriteId];

    sprite->data[0] = 2;
    sprite->data[1] = gNamingScreenData->currentPage;
}

static u8 sub_80E40AC(struct Sprite *);
static u8 sub_80E4100(struct Sprite *);
static u8 sub_80E4104(struct Sprite *);
static u8 sub_80E4178(struct Sprite *);

static u8 (*const gUnknown_0858BEE8[])(struct Sprite *) =
{
    sub_80E40AC,
    sub_80E4100,
    sub_80E4104,
    sub_80E4178,
};

static void sub_80E4084(struct Sprite *sprite)
{
    while (gUnknown_0858BEE8[sprite->data[0]](sprite) != 0);
}

static u8 sub_80E40AC(struct Sprite *sprite)
{
    struct Sprite *sprite1 = &gSprites[sprite->data[6]];
    struct Sprite *sprite2 = &gSprites[sprite->data[7]];

    sub_80E41B8(sub_80E3244(gNamingScreenData->currentPage), sprite1, sprite2);
    sprite->data[0]++;
    return 0;
}

static u8 sub_80E4100(struct Sprite *sprite)
{
    return 0;
}

static u8 sub_80E4104(struct Sprite *sprite)
{
    struct Sprite *r4 = &gSprites[sprite->data[6]];
    struct Sprite *r5 = &gSprites[sprite->data[7]];

    r4->pos2.y++;
    if (r4->pos2.y > 7)
    {
        sprite->data[0]++;
        r4->pos2.y = -4;
        r4->invisible = TRUE;
        sub_80E41B8(sub_80E3244(((u8)sprite->data[1] + 1) % 3), r4, r5);
    }
    return 0;
}

static u8 sub_80E4178(struct Sprite *sprite)
{
    struct Sprite *r2 = &gSprites[sprite->data[6]];

    r2->invisible = FALSE;
    r2->pos2.y++;
    if (r2->pos2.y >= 0)
    {
        r2->pos2.y = 0;
        sprite->data[0] = 1;
    }
    return 0;
}

static const u16 gUnknown_0858BEF8[] = {1, 3, 2};
static const u16 gUnknown_0858BEFE[] = {4, 6, 5};

static void sub_80E41B8(u8 a, struct Sprite *b, struct Sprite *c)
{
    c->oam.paletteNum = IndexOfSpritePaletteTag(gUnknown_0858BEF8[a]);
    b->sheetTileStart = GetSpriteTileStartByTag(gUnknown_0858BEFE[a]);
    b->subspriteTableNum = a;
}

//

static void CreateBackOkSprites(void)
{
    u8 spriteId;

    spriteId = CreateSprite(&gUnknown_0858C108, 0xCC, 0x74, 0);
    SetSubspriteTables(&gSprites[spriteId], gUnknown_0858C070);
    gSprites[spriteId].invisible = TRUE;

    spriteId = CreateSprite(&gUnknown_0858C120, 0xCC, 0x8C, 0);
    SetSubspriteTables(&gSprites[spriteId], gUnknown_0858C070);
    gSprites[spriteId].invisible = TRUE;
}

static void CreateUnderscoreSprites(void)
{
    u8 spriteId;
    s16 xPos;
    u8 i;

    xPos = gNamingScreenData->inputCharBaseXPos - 5;
    spriteId = CreateSprite(&sSpriteTemplate_InputArrow, xPos, 0x38, 0);
    gSprites[spriteId].oam.priority = 3;
    gSprites[spriteId].invisible = TRUE;
    xPos = gNamingScreenData->inputCharBaseXPos;
    for (i = 0; i < gNamingScreenData->template->maxChars; i++, xPos += 8)
    {
        spriteId = CreateSprite(&sSpriteTemplate_Underscore, xPos + 3, 0x3C, 0);
        gSprites[spriteId].oam.priority = 3;
        gSprites[spriteId].data[0] = i;
        gSprites[spriteId].invisible = TRUE;
    }
}

//--------------------------------------------------
// Icon creation (the thing you're naming or giving input to)
//--------------------------------------------------

static void TaskDummy2(void);
static void NamingScreen_CreatePlayerIcon(void);
static void NamingScreen_CreatePCIcon(void);
static void NamingScreen_CreateMonIcon(void);
static void NamingScreen_CreateWandaDadIcon(void);

static void (*const sIconFunctions[])(void) =
{
    TaskDummy2,
    NamingScreen_CreatePlayerIcon,
    NamingScreen_CreatePCIcon,
    NamingScreen_CreateMonIcon,
    NamingScreen_CreateWandaDadIcon,
};

static void CreateInputTargetIcon(void)
{
    sIconFunctions[gNamingScreenData->template->iconFunction]();
}

static void TaskDummy2(void)
{

}

static void NamingScreen_CreatePlayerIcon(void)
{
    u8 rivalGfxId;
    u8 spriteId;

    rivalGfxId = GetRivalAvatarGraphicsIdByStateIdAndGender(0, gNamingScreenData->monSpecies);
    spriteId = AddPseudoObjectEvent(rivalGfxId, SpriteCallbackDummy, 0x38, 0x25, 0);
    gSprites[spriteId].oam.priority = 3;
    StartSpriteAnim(&gSprites[spriteId], 4);
}

static void NamingScreen_CreatePCIcon(void)
{
    u8 spriteId;

    spriteId = CreateSprite(&gUnknown_0858C180, 0x38, 0x29, 0);
    SetSubspriteTables(&gSprites[spriteId], gUnknown_0858C078);
    gSprites[spriteId].oam.priority = 3;
}

static void NamingScreen_CreateMonIcon(void)
{
    u8 spriteId;

    LoadMonIconPalettes();
    spriteId = CreateMonIcon(gNamingScreenData->monSpecies, SpriteCallbackDummy, 0x38, 0x28, 0, gNamingScreenData->monPersonality, 1);
    gSprites[spriteId].oam.priority = 3;
}

static void NamingScreen_CreateWandaDadIcon(void)
{
    u8 spriteId;

    spriteId = AddPseudoObjectEvent(OBJ_EVENT_GFX_MAN_1, SpriteCallbackDummy, 0x38, 0x25, 0);
    gSprites[spriteId].oam.priority = 3;
    StartSpriteAnim(&gSprites[spriteId], 4);
}

//--------------------------------------------------
// Keyboard handling
//--------------------------------------------------

static bool8 KeyboardKeyHandler_Character(u8);
static bool8 KeyboardKeyHandler_Page(u8);
static bool8 KeyboardKeyHandler_Backspace(u8);
static bool8 KeyboardKeyHandler_OK(u8);

static bool8 (*const sKeyboardKeyHandlers[])(u8) =
{
    KeyboardKeyHandler_Character,
    KeyboardKeyHandler_Page,
    KeyboardKeyHandler_Backspace,
    KeyboardKeyHandler_OK,
};

static bool8 HandleKeyboardEvent(void)
{
    u8 event = GetInputEvent();
    u8 keyRole = GetKeyRoleAtCursorPos();

    if (event == KBEVENT_PRESSED_SELECT)
    {
        return sub_80E45E0();
    }
    else if (event == KBEVENT_PRESSED_B)
    {
        DeleteTextCharacter();
        return FALSE;
    }
    else if (event == KBEVENT_PRESSED_START)
    {
        MoveCursorToOKButton();
        return FALSE;
    }
    else
    {
        return sKeyboardKeyHandlers[keyRole](event);
    }
}

static bool8 KeyboardKeyHandler_Character(u8 event)
{
    sub_80E3948(3, 0, 0);
    if (event == KBEVENT_PRESSED_A)
    {
        bool8 var = sub_80E4B54();

        sub_80E3ED8();
        if (var)
        {
            SetInputState(INPUT_STATE_2);
            gNamingScreenData->state = MAIN_STATE_MOVE_TO_OK_BUTTON;
        }
    }
    return FALSE;
}

static bool8 KeyboardKeyHandler_Page(u8 event)
{
    sub_80E3948(0, 1, 0);
    if (event == KBEVENT_PRESSED_A)
        return sub_80E45E0();
    else
        return FALSE;
}

static bool8 KeyboardKeyHandler_Backspace(u8 event)
{
    sub_80E3948(1, 1, 0);
    if (event == KBEVENT_PRESSED_A)
        DeleteTextCharacter();
    return FALSE;
}

static bool8 KeyboardKeyHandler_OK(u8 event)
{
    sub_80E3948(2, 1, 0);
    if (event == KBEVENT_PRESSED_A)
    {
        PlaySE(SE_SELECT);
        gNamingScreenData->state = MAIN_STATE_6;
        return TRUE;
    }
    else
        return FALSE;
}

static bool8 sub_80E45E0(void)
{
    gNamingScreenData->state = MAIN_STATE_START_PAGE_SWAP;
    return TRUE;
}

//--------------------------------------------------
// Input handling
//--------------------------------------------------

enum
{
    FNKEY_CASE,
    FNKEY_BACK,
    FNKEY_OK,
};

#define tState data[0]
#define tKeyboardEvent data[1]
#define tKbFunctionKey data[2]


static void InputState_Disabled(struct Task *);
static void InputState_Enabled(struct Task *);
static void InputState_2(struct Task *);

static void (*const sInputStateFuncs[])(struct Task *) =
{
    InputState_Disabled,
    InputState_Enabled,
    InputState_2,
};

static void Task_HandleInput(u8);
static void HandleDpadMovement(struct Task *);

static void InputInit(void)
{
    CreateTask(Task_HandleInput, 1);
}

static u8 GetInputEvent(void)
{
    u8 taskId = FindTaskIdByFunc(Task_HandleInput);

    return gTasks[taskId].tKeyboardEvent;
}

static void SetInputState(u8 state)
{
    u8 taskId = FindTaskIdByFunc(Task_HandleInput);

    gTasks[taskId].tState = state;
}

static void Task_HandleInput(u8 taskId)
{
    sInputStateFuncs[gTasks[taskId].tState](&gTasks[taskId]);
}

static void InputState_Disabled(struct Task *task)
{
    task->tKeyboardEvent = 0;
}

static void InputState_Enabled(struct Task *task)
{
    task->tKeyboardEvent = 0;

    if (gMain.newKeys & A_BUTTON)
        task->tKeyboardEvent = KBEVENT_PRESSED_A;
    else if (gMain.newKeys & B_BUTTON)
        task->tKeyboardEvent = KBEVENT_PRESSED_B;
    else if (gMain.newKeys & SELECT_BUTTON)
        task->tKeyboardEvent = KBEVENT_PRESSED_SELECT;
    else if (gMain.newKeys & START_BUTTON)
        task->tKeyboardEvent = KBEVENT_PRESSED_START;
    else
        HandleDpadMovement(task);
}

static void InputState_2(struct Task *task)
{
    task->tKeyboardEvent = 0;
}

static void HandleDpadMovement(struct Task *task)
{
    const s16 sDpadDeltaX[] =
    {
        0,   //none
        0,   //up
        0,   //down
        -1,  //left
        1    //right
    };

    const s16 sDpadDeltaY[] =
    {
        0,   //none
        -1,  //up
        1,   //down
        0,   //left
        0    //right
    };

    const s16 s4RowTo3RowTableY[] = {0, 1, 1, 2};
    const s16 gUnknown_0858BF50[] = {0, 0, 3};

    s16 cursorX;
    s16 cursorY;
    u16 dpadDir;
    s16 prevCursorX;

    GetCursorPos(&cursorX, &cursorY);
    dpadDir = 0;
    if (gMain.newAndRepeatedKeys & DPAD_UP)
        dpadDir = 1;
    if (gMain.newAndRepeatedKeys & DPAD_DOWN)
        dpadDir = 2;
    if (gMain.newAndRepeatedKeys & DPAD_LEFT)
        dpadDir = 3;
    if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
        dpadDir = 4;

    //Get new cursor position
    prevCursorX = cursorX;
    cursorX += sDpadDeltaX[dpadDir];
    cursorY += sDpadDeltaY[dpadDir];

    //Wrap cursor position in the X direction
    if (cursorX < 0)
        cursorX = GetCurrentPageColumnCount();
    if (cursorX > GetCurrentPageColumnCount())
        cursorX = 0;

    //Handle cursor movement in X direction
    if (sDpadDeltaX[dpadDir] != 0)
    {
        if (cursorX == GetCurrentPageColumnCount())
        {
            //We are now on the last column
            task->tKbFunctionKey = cursorY;
            cursorY = s4RowTo3RowTableY[cursorY];
        }
        else if (prevCursorX == GetCurrentPageColumnCount())
        {
            if (cursorY == 1)
                cursorY = task->tKbFunctionKey;
            else
                cursorY = gUnknown_0858BF50[cursorY];
        }
    }

    if (cursorX == GetCurrentPageColumnCount())
    {
        //There are only 3 keys on the last column, unlike the others,
        //so wrap Y accordingly
        if (cursorY < 0)
            cursorY = 2;
        if (cursorY > 2)
            cursorY = 0;
        if (cursorY == 0)
            task->tKbFunctionKey = FNKEY_BACK;
        else if (cursorY == 2)
            task->tKbFunctionKey = FNKEY_OK;
    }
    else
    {
        if (cursorY < 0)
            cursorY = 3;
        if (cursorY > 3)
            cursorY = 0;
    }
    SetCursorPos(cursorX, cursorY);
}

#undef tState
#undef tKeyboardEvent
#undef tKbFunctionKey

static void sub_80E4894(void)
{
    FillWindowPixelBuffer(gNamingScreenData->windows[3], PIXEL_FILL(1));
    AddTextPrinterParameterized(gNamingScreenData->windows[3], 1, gNamingScreenData->template->title, 8, 1, 0, 0);
    PutWindowTilemap(gNamingScreenData->windows[3]);
}

static void sub_80E48E8(void)
{
    u8 buffer[0x20];

    StringCopy(buffer, gSpeciesNames[gNamingScreenData->monSpecies]);
    StringAppendN(buffer, gNamingScreenData->template->title, 15);
    FillWindowPixelBuffer(gNamingScreenData->windows[3], PIXEL_FILL(1));
    AddTextPrinterParameterized(gNamingScreenData->windows[3], 1, buffer, 8, 1, 0, 0);
    PutWindowTilemap(gNamingScreenData->windows[3]);
}

static void (*const gUnknown_0858BF58[])(void) =
{
    sub_80E4894,
    sub_80E4894,
    sub_80E48E8,
    sub_80E48E8,
    sub_80E4894,
};

static void sub_80E4964(void)
{
    gUnknown_0858BF58[gNamingScreenData->templateNum]();
}

static void TaskDummy3(void);
static void sub_80E49BC(void);

static void (*const gUnknown_0858BF6C[])(void) =
{
    TaskDummy3,
    sub_80E49BC,
};

static void sub_80E498C(void)
{
    gUnknown_0858BF6C[gNamingScreenData->template->addGenderIcon]();
}

static void TaskDummy3(void)
{

}

static const u8 sGenderColors[2][3] =
{
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_BLUE, TEXT_COLOR_BLUE},
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_RED, TEXT_COLOR_RED}
};

static void sub_80E49BC(void)
{
    u8 genderSymbol[2];
    bool8 isFemale = FALSE;

    StringCopy(genderSymbol, gText_MaleSymbol);

    if (gNamingScreenData->monGender != MON_GENDERLESS)
    {
        if (gNamingScreenData->monGender == MON_FEMALE)
        {
            StringCopy(genderSymbol, gText_FemaleSymbol);
            isFemale = TRUE;
        }
        AddTextPrinterParameterized3(gNamingScreenData->windows[2], 1, 0x68, 1, sGenderColors[isFemale], -1, genderSymbol);
    }
}

static u8 GetCharAtKeyboardPos(s16 a, s16 b)
{
    return gUnknown_0858BE40[a + b * 8 + sub_80E3274() * 32];
}


static u8 GetTextCaretPosition(void)
{
    u8 i;

    for (i = 0; i < gNamingScreenData->template->maxChars; i++)
    {
        if (gNamingScreenData->textBuffer[i] == EOS)
            return i;
    }
    return gNamingScreenData->template->maxChars - 1;
}

static u8 GetPreviousTextCaretPosition(void)
{
    s8 i;

    for (i = gNamingScreenData->template->maxChars - 1; i > 0; i--)
    {
        if (gNamingScreenData->textBuffer[i] != EOS)
            return i;
    }
    return 0;
}

static void DeleteTextCharacter(void)
{
    u8 index;
    u8 var2;

    index = GetPreviousTextCaretPosition();
    gNamingScreenData->textBuffer[index] = 0;
    sub_80E4D10();
    CopyBgTilemapBufferToVram(3);
    gNamingScreenData->textBuffer[index] = EOS;
    var2 = GetKeyRoleAtCursorPos();
    if (var2 == 0 || var2 == 2)
        sub_80E3948(1, 0, 1);
    PlaySE(SE_BOWA);
}

static bool8 sub_80E4B54(void)
{
    s16 x;
    s16 y;

    GetCursorPos(&x, &y);
    AddTextCharacter(GetCharAtKeyboardPos(x, y));
    sub_80E4D10();
    CopyBgTilemapBufferToVram(3);
    PlaySE(SE_SELECT);

    if (GetPreviousTextCaretPosition() != gNamingScreenData->template->maxChars - 1)
        return FALSE;
    else
        return TRUE;
}

static void AddTextCharacter(u8 ch)
{
    u8 index = GetTextCaretPosition();

    gNamingScreenData->textBuffer[index] = ch;
}

static void sub_80E4BE4(void)
{
    u8 i;

    for (i = 0; i < gNamingScreenData->template->maxChars; i++)
    {
        if (gNamingScreenData->textBuffer[i] != CHAR_SPACE && gNamingScreenData->textBuffer[i] != EOS)
        {
            StringCopyN(gNamingScreenData->destBuffer, gNamingScreenData->textBuffer, gNamingScreenData->template->maxChars + 1);
            break;
        }
    }
}

static void choose_name_or_words_screen_load_bg_tile_patterns(void)
{
    LZ77UnCompWram(gNamingScreenMenu_Gfx, gNamingScreenData->tileBuffer);
    LoadBgTiles(1, gNamingScreenData->tileBuffer, 0x600, 0);
    LoadBgTiles(2, gNamingScreenData->tileBuffer, 0x600, 0);
    LoadBgTiles(3, gNamingScreenData->tileBuffer, 0x600, 0);
    LoadSpriteSheets(gUnknown_0858C1C8);
    LoadSpritePalettes(gUnknown_0858C230);
}

static void sub_80E4CB8(void)
{
    InputInit();
    sub_80E3920();
}

static void choose_name_or_words_screen_apply_bg_pals(void)
{
    LoadPalette(gNamingScreenMenu_Pal, 0, 0xC0);
    LoadPalette(gUnknown_0858BD78, 0xA0, sizeof(gUnknown_0858BD78));
    LoadPalette(stdpal_get(2), 0xB0, 0x20);
}

static void sub_80E4CF8(u8 bg, const void *src)
{
    CopyToBgTilemapBuffer(bg, src, 0, 0);
}

static void nullsub_10(u8 a1, u8 page)
{

}

static void sub_80E4D10(void)
{
    u8 i;
    u8 temp[2];
    u16 unk2;
    u8 maxChars = gNamingScreenData->template->maxChars;
    u16 unk = gNamingScreenData->inputCharBaseXPos - 0x40;

    FillWindowPixelBuffer(gNamingScreenData->windows[2], PIXEL_FILL(1));

    for (i = 0; i < maxChars; i++)
    {
        temp[0] = gNamingScreenData->textBuffer[i];
        temp[1] = gText_ExpandedPlaceholder_Empty[0];
        unk2 = (IsLetter(temp[0]) == TRUE) ? 2 : 0;

        AddTextPrinterParameterized(gNamingScreenData->windows[2], 1, temp, i * 8 + unk + unk2, 1, 0xFF, NULL);
    }

    sub_80E498C();
    CopyWindowToVram(gNamingScreenData->windows[2], 2);
    PutWindowTilemap(gNamingScreenData->windows[2]);
}

struct TextColor   // Needed because of alignment
{
    u8 colors[3][4];
};

static const struct TextColor sTextColorStruct =
{
    {
        {TEXT_DYNAMIC_COLOR_4, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GREY},
        {TEXT_DYNAMIC_COLOR_5, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GREY},
        {TEXT_DYNAMIC_COLOR_6, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GREY}
    }
};

static const u8 sFillValues[KBPAGE_COUNT] =
{
    [KBPAGE_LETTERS_LOWER] = PIXEL_FILL(0xE),
    [KBPAGE_LETTERS_UPPER] = PIXEL_FILL(0xD),
    [KBPAGE_SYMBOLS] = PIXEL_FILL(0xF)
};

static const u8 *const sKeyboardTextColors[KBPAGE_COUNT] =
{
    [KBPAGE_LETTERS_LOWER] = sTextColorStruct.colors[1],
    [KBPAGE_LETTERS_UPPER] = sTextColorStruct.colors[0],
    [KBPAGE_SYMBOLS] = sTextColorStruct.colors[2]
};

static void sub_80E4DE4(u8 window, u8 page)
{
    u8 i;

    FillWindowPixelBuffer(window, sFillValues[page]);

    for (i = 0; i < KBROW_COUNT; i++)
    {
        AddTextPrinterParameterized3(window, 1, 0, i * 16 + 1, sKeyboardTextColors[page], 0, sNamingScreenKeyboardText[page][i]);
    }

    PutWindowTilemap(window);
}

static const u8 *const gUnknown_0858BF98[] =
{
    gUnknown_08DD4620,
    gUnknown_08DD46E0,
    gUnknown_08DD47A0
};

static void sub_80E4E5C(void)
{
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 bg1Priority = GetGpuReg(REG_OFFSET_BG1CNT) & 3;
    u8 bg2Priority = GetGpuReg(REG_OFFSET_BG2CNT) & 3;

    if (bg1Priority > bg2Priority)
    {
        unk1 = 1;
        unk2 = 1;
        unk3 = gNamingScreenData->windows[0];
    }
    else
    {
        unk1 = 2;
        unk2 = 2;
        unk3 = gNamingScreenData->windows[1];
    }

    sub_80E4CF8(unk1, gUnknown_0858BF98[gNamingScreenData->currentPage]);
    sub_80E4DE4(unk3, sub_80E3254());
    nullsub_10(unk1, sub_80E3254());
    CopyBgTilemapBufferToVram(unk2);
}

static void sub_80E4EF0(void)
{
    const u8 color[3] = { TEXT_DYNAMIC_COLOR_6, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GREY };

    FillWindowPixelBuffer(gNamingScreenData->windows[4], PIXEL_FILL(15));
    AddTextPrinterParameterized3(gNamingScreenData->windows[4], 0, 2, 1, color, 0, gText_MoveOkBack);
    PutWindowTilemap(gNamingScreenData->windows[4]);
    CopyWindowToVram(gNamingScreenData->windows[4], 3);
}

static void sub_80E4F58(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void NamingScreen_TurnOffScreen(void)
{
    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
}

static void NamingScreen_InitDisplayMode(void)
{
    SetVBlankCallback(VBlankCB_NamingScreen);
}

static void VBlankCB_NamingScreen(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    SetGpuReg(REG_OFFSET_BG1VOFS, gNamingScreenData->bg1vOffset);
    SetGpuReg(REG_OFFSET_BG2VOFS, gNamingScreenData->bg2vOffset);
    SetGpuReg(REG_OFFSET_BG1CNT, GetGpuReg(REG_OFFSET_BG1CNT) & 0xFFFC);
    SetGpuRegBits(REG_OFFSET_BG1CNT, gNamingScreenData->bg1Priority);
    SetGpuReg(REG_OFFSET_BG2CNT, GetGpuReg(REG_OFFSET_BG2CNT) & 0xFFFC);
    SetGpuRegBits(REG_OFFSET_BG2CNT, gNamingScreenData->bg2Priority);
}

static void sub_80E501C(void)
{
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
}

static bool8 IsLetter(u8 character)
{
    u8 i;

    for (i = 0; sText_AlphabetUpperLower[i] != EOS; i++)
    {
        if (character == sText_AlphabetUpperLower[i])
            return FALSE;
    }
    return FALSE;
}

static void sub_80E5074(void)
{
    DoNamingScreen(0, gSaveBlock2Ptr->playerName, gSaveBlock2Ptr->playerGender, 0, 0, CB2_ReturnToFieldWithOpenMenu);
}

static void sub_80E509C(void)
{
    DoNamingScreen(1, gSaveBlock2Ptr->playerName, gSaveBlock2Ptr->playerGender, 0, 0, CB2_ReturnToFieldWithOpenMenu);
}

static void sub_80E50C4(void)
{
    DoNamingScreen(2, gSaveBlock2Ptr->playerName, gSaveBlock2Ptr->playerGender, 0, 0, CB2_ReturnToFieldWithOpenMenu);
}

static void sub_80E50EC(void)
{
    DoNamingScreen(3, gSaveBlock2Ptr->playerName, gSaveBlock2Ptr->playerGender, 0, 0, CB2_ReturnToFieldWithOpenMenu);
}

//--------------------------------------------------
// Forward-declared variables
//--------------------------------------------------

static const struct NamingScreenTemplate playerNamingScreenTemplate =
{
    .copyExistingString = 0,
    .maxChars = 7,
    .iconFunction = 1,
    .addGenderIcon = 0,
    .initialPage = KBPAGE_LETTERS_UPPER,
    .unused = 35,
    .title = gText_YourName,
};

static const struct NamingScreenTemplate pcBoxNamingTemplate =
{
    .copyExistingString = 0,
    .maxChars = 8,
    .iconFunction = 2,
    .addGenderIcon = 0,
    .initialPage = KBPAGE_LETTERS_UPPER,
    .unused = 19,
    .title = gText_BoxName,
};

static const struct NamingScreenTemplate monNamingScreenTemplate =
{
    .copyExistingString = 0,
    .maxChars = 10,
    .iconFunction = 3,
    .addGenderIcon = 1,
    .initialPage = KBPAGE_LETTERS_UPPER,
    .unused = 35,
    .title = gText_PkmnsNickname,
};

static const struct NamingScreenTemplate wandaWordsScreenTemplate =
{
    .copyExistingString = 1,
    .maxChars = 15,
    .iconFunction = 4,
    .addGenderIcon = 0,
    .initialPage = KBPAGE_LETTERS_UPPER,
    .unused = 11,
    .title = gText_TellHimTheWords,
};

static const struct NamingScreenTemplate *const sNamingScreenTemplates[] =
{
    &playerNamingScreenTemplate,
    &pcBoxNamingTemplate,
    &monNamingScreenTemplate,
    &monNamingScreenTemplate,
    &wandaWordsScreenTemplate,
};

const struct OamData gOamData_858BFEC =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

const struct OamData gOamData_858BFF4 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

const struct OamData gOamData_858BFFC =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

static const struct Subsprite gUnknown_0858C004[] =
{
    {
        .x = -20,  
        .y = -16, 
        .shape = SPRITE_SHAPE(32x8),  
        .size = SPRITE_SIZE(32x8),  
        .tileOffset = 0,     
        .priority = 1
    },
    {
        .x =  12,  
        .y = -16, 
        .shape = SPRITE_SHAPE(8x8),  
        .size = SPRITE_SIZE(8x8),  
        .tileOffset = 4,     
        .priority = 1
    },
    {
        .x = -20,  
        .y = -8,  
        .shape = SPRITE_SHAPE(32x8),  
        .size = SPRITE_SIZE(32x8), 
        .tileOffset = 5,     
        .priority = 1
    },
    {
        .x =  12,  
        .y = -8,  
        .shape = SPRITE_SHAPE(8x8),  
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 9,     
        .priority = 1
    },
    {
        .x = -20,  
        .y =  0,  
        .shape = SPRITE_SHAPE(32x8),  
        .size = SPRITE_SIZE(32x8), 
        .tileOffset = 10,    
        .priority = 1
    },
    {
        .x =  12,  
        .y =  0,  
        .shape = SPRITE_SHAPE(8x8),  
        .size = SPRITE_SIZE(8x8), 
        .tileOffset = 14,    
        .priority = 1
    },
    {
        .x = -20,  
        .y =  8,  
        .shape = SPRITE_SHAPE(32x8),  
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 15,    
        .priority = 1
    },
    {
        .x =  12,  
        .y =  8,  
        .shape = SPRITE_SHAPE(8x8),  
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 19,    
        .priority = 1
    }
};

static const struct Subsprite gUnknown_0858C024[] =
{
    {
        .x = -12,  
        .y = -4,  
        .shape = SPRITE_SHAPE(16x8),  
        .size = SPRITE_SIZE(16x8),  
        .tileOffset = 0,     
        .priority = 1
    },
    {
        .x =   4,  
        .y = -4,  
        .shape = SPRITE_SHAPE(8x8),  
        .size = SPRITE_SIZE(8x8), 
        .tileOffset = 2,     
        .priority = 1
    }
};

static const struct Subsprite gUnknown_0858C02C[] =
{
    {
        .x = -20,  
        .y = -12, 
        .shape = SPRITE_SHAPE(32x8),  
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,     
        .priority = 1
    },
    {
        .x =  12,  
        .y = -12, 
        .shape = SPRITE_SHAPE(8x8),  
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 4,     
        .priority = 1
    },
    {
        .x = -20,  
        .y = -4,  
        .shape = SPRITE_SHAPE(32x8),  
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 5,     
        .priority = 1
    },
    {
        .x =  12,  
        .y = -4,  
        .shape = SPRITE_SHAPE(8x8),  
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 9,     
        .priority = 1
    },
    {
        .x = -20,  
        .y =  4,  
        .shape = SPRITE_SHAPE(32x8),  
        .size = SPRITE_SIZE(32x8), 
        .tileOffset = 10,    
        .priority = 1
    },
    {
        .x =  12,  
        .y =  4,  
        .shape = SPRITE_SHAPE(8x8),  
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 14,    
        .priority = 1
    }
};

static const struct Subsprite gUnknown_0858C044[] =
{
    {
        .x = -8,   
        .y = -12, 
        .shape = SPRITE_SHAPE(16x8),  
        .size = SPRITE_SIZE(16x8), 
        .tileOffset = 0,     
        .priority = 3
    },
    {
        .x = -8,   
        .y = -4,  
        .shape = SPRITE_SHAPE(16x8),  
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 2,     
        .priority = 3
    },
    {
        .x = -8,   
        .y =  4,  
        .shape = SPRITE_SHAPE(16x8),  
        .size = SPRITE_SIZE(16x8), 
        .tileOffset = 4,     
        .priority = 3
    }
};

static const struct SubspriteTable gUnknown_0858C050[] =
{
    {ARRAY_COUNT(gUnknown_0858C004), gUnknown_0858C004}
};

static const struct SubspriteTable gUnknown_0858C058[] =
{
    {ARRAY_COUNT(gUnknown_0858C024), gUnknown_0858C024},
    {ARRAY_COUNT(gUnknown_0858C024), gUnknown_0858C024},
    {ARRAY_COUNT(gUnknown_0858C024), gUnknown_0858C024}
};

static const struct SubspriteTable gUnknown_0858C070[] =
{
    {ARRAY_COUNT(gUnknown_0858C02C), gUnknown_0858C02C}
};

static const struct SubspriteTable gUnknown_0858C078[] =
{
    {ARRAY_COUNT(gUnknown_0858C044), gUnknown_0858C044}
};

static const struct SpriteFrameImage gUnknown_0858C080[] =
{
    {gSpriteImage_858BBF8, sizeof(gSpriteImage_858BBF8)},
    {gSpriteImage_858BCB8, sizeof(gSpriteImage_858BCB8)},
};

static const union AnimCmd gSpriteAnim_858C090[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd gSpriteAnim_858C098[] =
{
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_858C0A4[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const gSpriteAnimTable_858C0B0[] =
{
    gSpriteAnim_858C090
};

static const union AnimCmd *const gSpriteAnimTable_858C0B4[] =
{
    gSpriteAnim_858C090,
    gSpriteAnim_858C098
};

static const union AnimCmd *const gSpriteAnimTable_858C0BC[] =
{
    gSpriteAnim_858C0A4
};

static const struct SpriteTemplate gUnknown_0858C0C0 =
{
    .tileTag = 0x0002,
    .paletteTag = 0x0004,
    .oam = &gOamData_858BFEC,
    .anims = gSpriteAnimTable_858C0B0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80E4084
};

static const struct SpriteTemplate gUnknown_0858C0D8 =
{
    .tileTag = 0x0003,
    .paletteTag = 0x0001,
    .oam = &gOamData_858BFFC,
    .anims = gSpriteAnimTable_858C0B0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate gUnknown_0858C0F0 =
{
    .tileTag = 0x0004,
    .paletteTag = 0x0004,
    .oam = &gOamData_858BFEC,
    .anims = gSpriteAnimTable_858C0B0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate gUnknown_0858C108 =
{
    .tileTag = 0x0000,
    .paletteTag = 0x0006,
    .oam = &gOamData_858BFEC,
    .anims = gSpriteAnimTable_858C0B0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate gUnknown_0858C120 =
{
    .tileTag = 0x0001,
    .paletteTag = 0x0007,
    .oam = &gOamData_858BFEC,
    .anims = gSpriteAnimTable_858C0B0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate gUnknown_0858C138 =
{
    .tileTag = 0x0007,
    .paletteTag = 0x0005,
    .oam = &gOamData_858BFF4,
    .anims = gSpriteAnimTable_858C0B4,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80E3B30
};

static const struct SpriteTemplate sSpriteTemplate_InputArrow =
{
    .tileTag = 0x000A,
    .paletteTag = 0x0003,
    .oam = &gOamData_858BFEC,
    .anims = gSpriteAnimTable_858C0B0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80E3C20
};

static const struct SpriteTemplate sSpriteTemplate_Underscore =
{
    .tileTag = 0x000B,
    .paletteTag = 0x0003,
    .oam = &gOamData_858BFEC,
    .anims = gSpriteAnimTable_858C0B0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80E3C6C
};

static const struct SpriteTemplate gUnknown_0858C180 =
{
    .tileTag = 0xFFFF,
    .paletteTag = 0x0000,
    .oam = &gOamData_858BFEC,
    .anims = gSpriteAnimTable_858C0BC,
    .images = gUnknown_0858C080,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const u8* const sNamingScreenKeyboardText[KBPAGE_COUNT][KBROW_COUNT] =
{
    [KBPAGE_LETTERS_LOWER] = 
    {
        gText_NamingScreenKeyboard_abcdef,
        gText_NamingScreenKeyboard_ghijkl,
        gText_NamingScreenKeyboard_mnopqrs,
        gText_NamingScreenKeyboard_tuvwxyz
    },
    [KBPAGE_LETTERS_UPPER] = 
    {
        gText_NamingScreenKeyboard_ABCDEF,
        gText_NamingScreenKeyboard_GHIJKL,
        gText_NamingScreenKeyboard_MNOPQRS,
        gText_NamingScreenKeyboard_TUVWXYZ
    },
    [KBPAGE_SYMBOLS] = 
    {
        gText_NamingScreenKeyboard_01234,
        gText_NamingScreenKeyboard_56789,
        gText_NamingScreenKeyboard_Symbols1,
        gText_NamingScreenKeyboard_Symbols2
    },
};

static const struct SpriteSheet gUnknown_0858C1C8[] =
{
    {gNamingScreenRWindow_Gfx + 0x280,          0x1E0,  0x0000},
    {gNamingScreenRWindow_Gfx + 0x460,          0x1E0,  0x0001},
    {gNamingScreenRWindow_Gfx,                  0x280,  0x0002},
    {gNamingScreenKeyboardButton_Gfx + 0x20,    0x100,  0x0003},
    {gNamingScreenROptions_Gfx,                 0x060,  0x0004},
    {gNamingScreenROptions_Gfx + 0xA0,          0x060,  0x0005},
    {gNamingScreenROptions_Gfx + 0x140,         0x060,  0x0006},
    {gNamingScreenCursor_Gfx,                   0x080,  0x0007},
    {gNamingScreenCursor_Gfx + 0xA0,            0x080,  0x0008},
    {gNamingScreenCursor_Gfx + 0x140,           0x080,  0x0009},
    {gNamingScreenRightPointingTriangleTiles,   0x020,  0x000A},
    {gNamingScreenUnderscoreTiles,              0x020,  0x000B},
    {NULL}
};

static const struct SpritePalette gUnknown_0858C230[] =
{
    {gNamingScreenMenu_Pal,         0x0000},
    {gNamingScreenMenu_Pal + 0x10,  0x0001},
    {gNamingScreenMenu_Pal + 0x20,  0x0002},
    {gNamingScreenMenu_Pal + 0x30,  0x0003},
    {gNamingScreenMenu_Pal + 0x40,  0x0004},
    {gNamingScreenMenu_Pal + 0x50,  0x0005},
    {gNamingScreenMenu_Pal + 0x40,  0x0006},
    {gNamingScreenMenu_Pal + 0x40,  0x0007},
    {NULL}
};


