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

enum {
    INPUT_NONE,
    INPUT_DPAD_UP,
    INPUT_DPAD_DOWN,
    INPUT_DPAD_LEFT,
    INPUT_DPAD_RIGHT,
    INPUT_A_BUTTON,
    INPUT_B_BUTTON,
    INPUT_LR_BUTTON,
    INPUT_SELECT,
    INPUT_START,
};

#define KBROW_COUNT 4
#define KBCOL_COUNT 8

enum {
    GFXTAG_BACK_BUTTON,
    GFXTAG_OK_BUTTON,
    GFXTAG_PAGE_SWITCH_BG,
    GFXTAG_PAGE_SWITCH_BUTTON,
    GFXTAG_PAGE_SWITCH_UPPER,
    GFXTAG_PAGE_SWITCH_LOWER,
    GFXTAG_PAGE_SWITCH_OTHERS,
    GFXTAG_CURSOR,
    GFXTAG_CURSOR_SQUISHED,
    GFXTAG_CURSOR_FILLED,
    GFXTAG_INPUT_ARROW,
    GFXTAG_UNDERSCORE,
};

enum {
    PALTAG_PC_ICON,
    PALTAG_1,
    PALTAG_2,
    PALTAG_3,
    PALTAG_PAGE_SWITCH,
    PALTAG_CURSOR,
    PALTAG_BACK_BUTTON,
    PALTAG_OK_BUTTON,
};

enum {
    WIN_KB_PAGE_1, // Which of these two windows is in front is cycled as the player swaps
    WIN_KB_PAGE_2, // Initiall WIN_KB_PAGE_1 is in front, with WIN_KB_PAGE_2 on deck
    WIN_TEXT_ENTRY,
    WIN_TEXT_ENTRY_BOX,
    WIN_BANNER,
    WIN_COUNT,
};

enum
{
    KBPAGE_LETTERS_LOWER,
    KBPAGE_LETTERS_UPPER,
    KBPAGE_SYMBOLS,
    KBPAGE_COUNT,  
};

enum
{
    KEY_ROLE_CHAR,
    KEY_ROLE_PAGE,
    KEY_ROLE_BACKSPACE,
    KEY_ROLE_OK,
};

enum
{
    BUTTON_PAGE,
    BUTTON_BACK,
    BUTTON_OK,
    BUTTON_COUNT,
};

enum
{
    STATE_BEGIN_FADE_IN,
    STATE_WAIT_FADE_IN,
    STATE_HANDLE_INPUT,
    STATE_MOVE_TO_OK_BUTTON,
    STATE_START_PAGE_SWAP,
    STATE_WAIT_PAGE_SWAP,
    STATE_6,
    STATE_UPDATE_SENT_TO_PC_MESSAGE,
    STATE_BEGIN_FADE_OUT,
};

enum
{
    INPUT_STATE_DISABLED,
    INPUT_STATE_ENABLED,
    INPUT_STATE_2,
};

struct NamingScreenTemplate
{
    u8 copyExistingString;
    u8 maxChars;
    u8 iconFunction;
    u8 addGenderIcon;
    u8 initialPage;
    u8 unused;
    const u8 *title;
};

struct NamingScreenData 
{
    u8 tilemapBuffer1[0x800];
    u8 tilemapBuffer2[0x800];
    u8 tilemapBuffer3[0x800];
    u8 textBuffer[16];
    u8 tileBuffer[0x600];
    u8 state;
    u8 windows[WIN_COUNT];
    u16 inputCharBaseXPos;
    u16 bg1vOffset;
    u16 bg2vOffset;
    u16 bg1Priority;
    u16 bg2Priority;
    u8 bgToReveal;
    u8 bgToHide;
    u8 currentPage;
    u8 cursorSpriteId;
    u8 selectBtnFrameSpriteId;
    u8 keyRepeatStartDelayCopy;
    const struct NamingScreenTemplate *template;
    u8 templateNum;
    u8 *destBuffer;
    u16 monSpecies;
    u16 monGender;
    u32 monPersonality;
    MainCallback returnCallback;
};

EWRAM_DATA static struct NamingScreenData *sNamingScreen = NULL;
extern u16 gKeyRepeatStartDelay;

// extern text
extern const u8 gText_MoveOkBack[];
extern const u8 gText_YourName[];
extern const u8 gText_BoxName[];
extern const u8 gText_PkmnsNickname[];
extern const u8 gText_TellHimTheWords[];


// start of .rodata
static const u8 sPCIconOn_Gfx[] = INCBIN_U8("graphics/naming_screen/pc_icon/0.4bpp");
static const u8 sPCIconOff_Gfx[] = INCBIN_U8("graphics/naming_screen/pc_icon/1.4bpp");
static const u16 sKeyboard_Pal[] = INCBIN_U16("graphics/naming_screen/keyboard.gbapal");
static const u16 sUnused_Pal[] = INCBIN_U16("graphics/naming_screen/unused.gbapal");

static const u8 *const sTransferredToPCMessages[] =
{
    gText_PkmnTransferredSomeonesPC,
    gText_PkmnTransferredLanettesPC,
    gText_PkmnTransferredSomeonesPCBoxFull,
    gText_PkmnTransferredLanettesPCBoxFull
};

static const u8 sText_AlphabetUpperLower[] = _("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!");

static const struct BgTemplate sBgTemplates[] =
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

static const struct WindowTemplate sWindowTemplates[WIN_COUNT + 1] =
{
    [WIN_KB_PAGE_1] = {
        .bg = 1,
        .tilemapLeft = 3,
        .tilemapTop = 10,
        .width = 19,
        .height = 8,
        .paletteNum = 10,
        .baseBlock = 0x030
    },
    [WIN_KB_PAGE_2] = {
        .bg = 2,
        .tilemapLeft = 3,
        .tilemapTop = 10,
        .width = 19,
        .height = 8,
        .paletteNum = 10,
        .baseBlock = 0x0C8
    },
    [WIN_TEXT_ENTRY] = {
        .bg = 3,
        .tilemapLeft = 8,
        .tilemapTop = 6,
        .width = 17,
        .height = 2,
        .paletteNum = 10,
        .baseBlock = 0x030
    },
    [WIN_TEXT_ENTRY_BOX] = {
        .bg = 3,
        .tilemapLeft = 8,
        .tilemapTop = 4,
        .width = 17,
        .height = 2,
        .paletteNum = 10,
        .baseBlock = 0x052
    },
    [WIN_BANNER] = {
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

// This handles what characters get inserted when a key is pressed
// The keys shown on the keyboard are handled separately by sNamingScreenKeyboardText
static const u8 sKeyboardChars[KBPAGE_COUNT * KBROW_COUNT * KBCOL_COUNT] = __(
    "abcdef ."
    "ghijkl ,"
    "mnopqrs "
    "tuvwxyz "
    "ABCDEF ."
    "GHIJKL ,"
    "MNOPQRS "
    "TUVWXYZ "
    "01234   "
    "56789   "
    "!?♂♀/-  "
    "…“”‘'   ");

static const u8 sPageColumnCounts[KBPAGE_COUNT] = { 
    [KBPAGE_LETTERS_LOWER] = KBCOL_COUNT, 
    [KBPAGE_LETTERS_UPPER] = KBCOL_COUNT, 
    [KBPAGE_SYMBOLS]       = 6 
};
static const u8 sPageColumnXPos[KBPAGE_COUNT * KBCOL_COUNT] = { 
    0, 12, 24, 56, 68, 80, 92, 123,  // KBPAGE_LETTERS_LOWER
    0, 12, 24, 56, 68, 80, 92, 123,  // KBPAGE_LETTERS_UPPER
    0, 22, 44, 66, 88, 110           // KBPAGE_SYMBOLS
};

// forward declarations
static const struct NamingScreenTemplate *const sNamingScreenTemplates[];
static const struct SubspriteTable sSubspriteTable_PageSwitchBg[];
static const struct SubspriteTable sSubspriteTable_PageSwitchText[];
static const struct SubspriteTable sSubspriteTable_Button[];
static const struct SubspriteTable sSubspriteTable_PCIcon[];
static const struct SpriteTemplate sSpriteTemplate_PageSwitchBg;
static const struct SpriteTemplate sSpriteTemplate_PageSwitchButton;
static const struct SpriteTemplate sSpriteTemplate_PageSwitchText;
static const struct SpriteTemplate sSpriteTemplate_BackButton;
static const struct SpriteTemplate sSpriteTemplate_OkButton;
static const struct SpriteTemplate sSpriteTemplate_Cursor;
static const struct SpriteTemplate sSpriteTemplate_InputArrow;
static const struct SpriteTemplate sSpriteTemplate_Underscore;
static const struct SpriteTemplate sSpriteTemplate_PCIcon;
static const u8* const sNamingScreenKeyboardText[KBPAGE_COUNT][KBROW_COUNT];
static const struct SpriteSheet sSpriteSheets[];
static const struct SpritePalette sSpritePalettes[];

static void CB2_LoadNamingScreen(void);
static void NamingScreen_Init(void);
static void NamingScreen_InitBGs(void);
static void CreateNamingScreenTask(void);
static void Task_NamingScreen(u8 taskId);
static bool8 MainState_FadeIn(void);
static bool8 MainState_WaitFadeIn(void);
static bool8 MainState_HandleInput(void);
static bool8 MainState_MoveToOKButton(void);
static bool8 MainState_6(void);
static bool8 MainState_FadeOut(void);
static bool8 MainState_Exit(void);
static void DisplaySentToPCMessage(void);
static bool8 MainState_7(void);
static bool8 MainState_StartPageSwap(void);
static bool8 MainState_WaitPageSwap(void);
static void StartPageSwapAnim(void);
static void Task_HandlePageSwapAnim(u8);
static bool8 IsPageSwapAnimNotInProgress(void);
static void TryStartButtonFlash(u8, bool8, bool8);
static void Task_UpdateButtonFlash(u8);
static u16 GetButtonPalOffset(u8);
static void RestoreButtonColor(u8);
static void StartButtonFlash(struct Task *, u8, bool8);
static void CreateSprites(void);
static void CreateCursorSprite(void);
static void SetCursorPos(s16, s16);
static void GetCursorPos(s16 *x, s16 *y);
static void MoveCursorToOKButton(void);
static void SetCursorInvisibility(u8);
static void SetCursorFlashing(bool8);
static u8 IsCursorAnimFinished(void);
static u8 GetCurrentPageColumnCount(void);
static void CreatePageSwitcherSprites(void);
static void sub_80E4050(void);
static void sub_80E41B8(u8, struct Sprite *, struct Sprite *);
static void CreateBackOkSprites(void);
static void CreateTextEntrySprites(void);
static void CreateInputTargetIcon(void);
static u8 HandleKeyboardEvent(void);
static u8 SwitchKeyboardPage(void);
static u8 GetInputEvent(void);
static void SetInputState(u8);
static void DrawTextEntryBox(void);
static u8 GetTextEntryPosition(void);
static void DeleteTextCharacter(void);
static bool8 AddTextCharacter(void);
static void BufferCharacter(u8);
static void SaveInputText(void);
static void LoadGfx(void);
static void CreateHelperTasks(void);
static void LoadPalettes(void);
static void DrawBgTilemap(u8, const void *);
static void NamingScreen_Dummy(u8, u8);
static void DrawTextEntry(void);
static void PrintKeyboardKeys(u8, u8);
static void DrawKeyboardPageOnDeck(void);
static void PrintControls(void);
static void CB2_NamingScreen(void);
static void NamingScreen_ResetVHBlank(void);
static void NamingScreen_SetVBlank(void);
static void VBlankCB_NamingScreen(void);
static void NamingScreen_ShowBgs(void);
static bool8 IsWideLetter(u8);

void DoNamingScreen(u8 templateNum, u8 *destBuffer, u16 monSpecies, u16 monGender, u32 monPersonality, MainCallback returnCallback)
{
    sNamingScreen = Alloc(sizeof(struct NamingScreenData));
    if (!sNamingScreen)
    {
        SetMainCallback2(returnCallback);
    }
    else
    {
        sNamingScreen->templateNum = templateNum;
        sNamingScreen->monSpecies = monSpecies;
        sNamingScreen->monGender = monGender;
        sNamingScreen->monPersonality = monPersonality;
        sNamingScreen->destBuffer = destBuffer;
        sNamingScreen->returnCallback = returnCallback;

        if (templateNum == NAMING_SCREEN_PLAYER)
            StartTimer1();

        SetMainCallback2(CB2_LoadNamingScreen);
    }
}

static void CB2_LoadNamingScreen(void)
{
    switch (gMain.state)
    {
    case 0:
        NamingScreen_ResetVHBlank();
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
        LoadPalettes();
        gMain.state++;
        break;
    case 6:
        LoadGfx();
        gMain.state++;
        break;
    case 7:
        CreateSprites();
        UpdatePaletteFade();
        NamingScreen_ShowBgs();
        gMain.state++;
        break;
    default:
        CreateHelperTasks();
        CreateNamingScreenTask();
        break;
    }
}

static void NamingScreen_Init(void)
{
    sNamingScreen->state = 0;
    sNamingScreen->bg1vOffset = 0;
    sNamingScreen->bg2vOffset = 0;
    sNamingScreen->bg1Priority = BGCNT_PRIORITY(1);
    sNamingScreen->bg2Priority = BGCNT_PRIORITY(2);
    sNamingScreen->bgToReveal = 0;
    sNamingScreen->bgToHide = 1;
    sNamingScreen->template = sNamingScreenTemplates[sNamingScreen->templateNum];
    sNamingScreen->currentPage = sNamingScreen->template->initialPage;
    sNamingScreen->inputCharBaseXPos = (240 - sNamingScreen->template->maxChars * 8) / 2 + 6;
    if (sNamingScreen->templateNum == NAMING_SCREEN_WALDA)
        sNamingScreen->inputCharBaseXPos += 11;
    sNamingScreen->keyRepeatStartDelayCopy = gKeyRepeatStartDelay;
    memset(sNamingScreen->textBuffer, 0xFF, sizeof(sNamingScreen->textBuffer));
    if (sNamingScreen->template->copyExistingString)
        StringCopy(sNamingScreen->textBuffer, sNamingScreen->destBuffer);
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
    SetCursorInvisibility(FALSE);
}

static void NamingScreen_InitBGs(void)
{
    u8 i;

    DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
    DmaClear32(3, (void *)OAM, OAM_SIZE);
    DmaClear16(3, (void *)PLTT, PLTT_SIZE);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));

    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);

    InitStandardTextBoxWindows();
    InitTextBoxGfxAndPrinters();

    for (i = 0; i < WIN_COUNT; i++)
        sNamingScreen->windows[i] = AddWindow(&sWindowTemplates[i]);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(12, 8));

    SetBgTilemapBuffer(1, sNamingScreen->tilemapBuffer1);
    SetBgTilemapBuffer(2, sNamingScreen->tilemapBuffer2);
    SetBgTilemapBuffer(3, sNamingScreen->tilemapBuffer3);

    FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 0x20, 0x20);
    FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 0x20, 0x20);
    FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 0x20, 0x20);
}

static void CreateNamingScreenTask(void)
{
    CreateTask(Task_NamingScreen, 2);
    SetMainCallback2(CB2_NamingScreen);
}

static void Task_NamingScreen(u8 taskId)
{
    switch (sNamingScreen->state)
    {
    case 0:
        MainState_FadeIn();
        sub_80E2FA4();
        NamingScreen_SetVBlank();
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
        MainState_7();
        break;
    case 8:
        MainState_FadeOut();
        break;
    case 9:
        MainState_Exit();
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
    return sPageOrderUpperFirst[sNamingScreen->currentPage];
}

static u8 sub_80E3274(void)
{
    return sPageOrderSymbolsFirst[sNamingScreen->currentPage];
}

static bool8 MainState_FadeIn(void)
{
    DrawBgTilemap(3, gUnknown_08DD4544);
    sNamingScreen->currentPage = KBPAGE_LETTERS_UPPER;
    DrawBgTilemap(2, gUnknown_08DD46E0);
    DrawBgTilemap(1, gUnknown_08DD4620);
    PrintKeyboardKeys(sNamingScreen->windows[WIN_KB_PAGE_2], KBPAGE_LETTERS_LOWER);
    PrintKeyboardKeys(sNamingScreen->windows[WIN_KB_PAGE_1], KBPAGE_LETTERS_UPPER);
    NamingScreen_Dummy(2, KBPAGE_LETTERS_LOWER);
    NamingScreen_Dummy(1, KBPAGE_LETTERS_UPPER);
    DrawTextEntry();
    DrawTextEntryBox();
    PrintControls();
    CopyBgTilemapBufferToVram(1);
    CopyBgTilemapBufferToVram(2);
    CopyBgTilemapBufferToVram(3);
    BlendPalettes(-1, 16, 0);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
    sNamingScreen->state++;
    return FALSE;
}

static bool8 MainState_WaitFadeIn(void)
{
    if (!gPaletteFade.active)
    {
        SetInputState(INPUT_STATE_ENABLED);
        SetCursorFlashing(TRUE);
        sNamingScreen->state++;
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
        sNamingScreen->state = STATE_HANDLE_INPUT;
    }
    return FALSE;
}

static bool8 MainState_6(void)
{
    SaveInputText();
    SetInputState(INPUT_STATE_DISABLED);
    SetCursorFlashing(FALSE);
    TryStartButtonFlash(BUTTON_COUNT, FALSE, TRUE);
    if (sNamingScreen->templateNum == NAMING_SCREEN_CAUGHT_MON &&
        CalculatePlayerPartyCount() >= PARTY_SIZE)
    {
        DisplaySentToPCMessage();
        sNamingScreen->state = STATE_UPDATE_SENT_TO_PC_MESSAGE;
        return FALSE;
    }
    else
    {
        sNamingScreen->state = STATE_BEGIN_FADE_OUT;
        return TRUE;  //Exit the naming screen
    }
}

static bool8 MainState_FadeOut(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    sNamingScreen->state++;
    return FALSE;
}

static bool8 MainState_Exit(void)
{
    if (!gPaletteFade.active)
    {
        if (sNamingScreen->templateNum == NAMING_SCREEN_PLAYER)
            SeedRngAndSetTrainerId();
        SetMainCallback2(sNamingScreen->returnCallback);
        DestroyTask(FindTaskIdByFunc(Task_NamingScreen));
        FreeAllWindowBuffers();
        FREE_AND_SET_NULL(sNamingScreen);
    }
    return FALSE;
}

static void DisplaySentToPCMessage(void)
{
    u8 stringToDisplay = 0;

    if (!IsDestinationBoxFull())
    {
        StringCopy(gStringVar1, GetBoxNamePtr(VarGet(VAR_PC_BOX_TO_SEND_MON)));
        StringCopy(gStringVar2, sNamingScreen->destBuffer);
    }
    else
    {
        StringCopy(gStringVar1, GetBoxNamePtr(VarGet(VAR_PC_BOX_TO_SEND_MON)));
        StringCopy(gStringVar2, sNamingScreen->destBuffer);
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

static bool8 MainState_7(void)
{
    RunTextPrinters();

    if (!IsTextPrinterActive(0) && JOY_NEW(A_BUTTON))
        sNamingScreen->state = STATE_BEGIN_FADE_OUT;

    return FALSE;
}

static bool8 MainState_StartPageSwap(void)
{
    SetInputState(INPUT_STATE_DISABLED);
    sub_80E4050();
    StartPageSwapAnim();
    SetCursorInvisibility(TRUE);
    TryStartButtonFlash(BUTTON_PAGE, FALSE, TRUE);
    PlaySE(SE_WIN_OPEN);
    sNamingScreen->state = STATE_WAIT_PAGE_SWAP;
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

        sNamingScreen->state = STATE_HANDLE_INPUT;
        sNamingScreen->currentPage++;
        sNamingScreen->currentPage %= 3;

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
        DrawKeyboardPageOnDeck();
        SetInputState(INPUT_STATE_ENABLED);
        SetCursorInvisibility(FALSE);
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
    sNamingScreen->bg1vOffset = 0;
    sNamingScreen->bg2vOffset = 0;
    task->tState++;
    return 0;
}

static bool8 PageSwapAnimState_1(struct Task *task)
{
    u16 *const arr[] =
    {
        &sNamingScreen->bg2vOffset,
        &sNamingScreen->bg1vOffset
    };

    task->tFrameCount += 4;
    *arr[sNamingScreen->bgToReveal] = Sin(task->tFrameCount, 40);
    *arr[sNamingScreen->bgToHide] = Sin((task->tFrameCount + 128) & 0xFF, 40);
    if (task->tFrameCount >= 64)
    {
        u8 temp = sNamingScreen->bg1Priority;  //Why u8 and not u16?

        sNamingScreen->bg1Priority = sNamingScreen->bg2Priority;
        sNamingScreen->bg2Priority = temp;
        task->tState++;
    }
    return 0;
}

static bool8 PageSwapAnimState_2(struct Task *task)
{
    u16 *const arr[] =
    {
        &sNamingScreen->bg2vOffset,
        &sNamingScreen->bg1vOffset
    };

    task->tFrameCount += 4;
    *arr[sNamingScreen->bgToReveal] = Sin(task->tFrameCount, 40);
    *arr[sNamingScreen->bgToHide] = Sin((task->tFrameCount + 128) & 0xFF, 40);
    if (task->tFrameCount >= 128)
    {
        u8 temp = sNamingScreen->bgToReveal;

        sNamingScreen->bgToReveal = sNamingScreen->bgToHide;
        sNamingScreen->bgToHide = temp;
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

#define tButtonId data[0]
#define tColor    data[3]

static void CreateButtonFlashTask(void)
{
    u8 taskId;

    taskId = CreateTask(Task_UpdateButtonFlash, 3);
    gTasks[taskId].tButtonId = BUTTON_COUNT;
}

static void TryStartButtonFlash(u8 button, bool8 b, bool8 c)
{
    struct Task *task = &gTasks[FindTaskIdByFunc(Task_UpdateButtonFlash)];

    if (button == task->tButtonId && !c)
    {
        task->data[1] = b;
        task->data[2] = TRUE;
        return;
    }
    if (button == BUTTON_COUNT && !task->data[1] && !c)
        return;

    if (task->tButtonId != BUTTON_COUNT)
        RestoreButtonColor(task->tButtonId);

    StartButtonFlash(task, button, b);
}

static void Task_UpdateButtonFlash(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (task->tButtonId == BUTTON_COUNT || !task->data[2])
        return;

    MultiplyInvertedPaletteRGBComponents(GetButtonPalOffset(task->tButtonId), task->tColor, task->tColor, task->tColor);

    if (task->data[5] && --task->data[5])
        return;

    task->data[5] = 2;
    if (task->data[4] >= 0)
    {
        if (task->tColor < 14)
        {
            task->tColor += task->data[4];
            task->data[6] += task->data[4];
        }
        else
        {
            task->tColor = 16;
            task->data[6]++;
        }
    }
    else
    {
        task->tColor += task->data[4];
        task->data[6] += task->data[4];
    }

    if (task->tColor == 16 && task->data[6] == 22)
    {
        task->data[4] = -4;
    }
    else if (task->tColor == 0)
    {
        task->data[2] = task->data[1];
        task->data[4] = 2;
        task->data[6] = 0;
    }
}

static u16 GetButtonPalOffset(u8 button)
{
    const u16 palOffsets[] =
    {
        [BUTTON_PAGE]  = IndexOfSpritePaletteTag(PALTAG_PAGE_SWITCH) * 16 + 0x10E,
        [BUTTON_BACK]  = IndexOfSpritePaletteTag(PALTAG_BACK_BUTTON) * 16 + 0x10E,
        [BUTTON_OK]    = IndexOfSpritePaletteTag(PALTAG_OK_BUTTON) * 16 + 0x10E,
        [BUTTON_COUNT] = IndexOfSpritePaletteTag(PALTAG_OK_BUTTON) * 16 + 0x101,
    };

    return palOffsets[button];
}

static void RestoreButtonColor(u8 button)
{
    u16 index = GetButtonPalOffset(button);
    gPlttBufferFaded[index] = gPlttBufferUnfaded[index];
}

static void StartButtonFlash(struct Task *task, u8 button, bool8 c)
{
    task->tButtonId = button;
    task->data[1] = c;
    task->data[2] = TRUE;
    task->tColor = 4;
    task->data[4] = 2;
    task->data[5] = 0;
    task->data[6] = 4;
}

#undef tButtonId
#undef tColor

#define tInvisible data[4] & 0x00FF
#define tFlashing  data[4] & 0xFF00

static void SpriteCB_Cursor(struct Sprite *sprite)
{
    if (sprite->animEnded)
        StartSpriteAnim(sprite, 0);
    sprite->invisible = sprite->tInvisible;
    if (sprite->data[0] == GetCurrentPageColumnCount())
        sprite->invisible = TRUE;
    if (sprite->invisible || !(sprite->tFlashing)
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
    if (sprite->tFlashing)
    {
        s8 gb = sprite->data[5];
        s8 r = sprite->data[5] >> 1;
        u16 index = IndexOfSpritePaletteTag(PALTAG_CURSOR) * 16 + 0x0101;

        MultiplyInvertedPaletteRGBComponents(index, r, gb, gb);
    }
}

#define sDelay  data[0]
#define sXPosId data[1]

static void SpriteCB_InputArrow(struct Sprite *sprite)
{
    const s16 x[] = {0, -4, -2, -1};

    if (sprite->sDelay == 0 || --sprite->sDelay == 0)
    {
        sprite->sDelay = 8;
        sprite->sXPosId = (sprite->sXPosId + 1) & (ARRAY_COUNT(x) - 1);
    }
    sprite->pos2.x = x[sprite->sXPosId];
}

#undef sDelay
#undef sXPosId

static void SpriteCB_Underscore(struct Sprite *sprite)
{
    const s16 arr[] = {2, 3, 2, 1};
    u8 var;

    var = GetTextEntryPosition();
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

static void CreateSprites(void)
{
    CreateCursorSprite();
    CreatePageSwitcherSprites();
    CreateBackOkSprites();
    CreateTextEntrySprites();
    CreateInputTargetIcon();
}

static void CreateCursorSprite(void)
{
    sNamingScreen->cursorSpriteId = CreateSprite(&sSpriteTemplate_Cursor, 38, 88, 1);
    SetCursorInvisibility(TRUE);
    gSprites[sNamingScreen->cursorSpriteId].oam.priority = 1;
    gSprites[sNamingScreen->cursorSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
    gSprites[sNamingScreen->cursorSpriteId].data[6] = 1;
    gSprites[sNamingScreen->cursorSpriteId].data[6] = 2;
    SetCursorPos(0, 0);
}

static void SetCursorPos(s16 x, s16 y)
{
    struct Sprite *cursorSprite = &gSprites[sNamingScreen->cursorSpriteId];

    if (x < sPageColumnCounts[sub_80E3274()])
        cursorSprite->pos1.x = sPageColumnXPos[x + sub_80E3274() * KBCOL_COUNT] + 38;
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
    struct Sprite *cursorSprite = &gSprites[sNamingScreen->cursorSpriteId];

    *x = cursorSprite->data[0];
    *y = cursorSprite->data[1];
}

static void MoveCursorToOKButton(void)
{
    SetCursorPos(GetCurrentPageColumnCount(), 2);
}

static void SetCursorInvisibility(bool8 invisible)
{
    gSprites[sNamingScreen->cursorSpriteId].data[4] &= 0xFF00;
    gSprites[sNamingScreen->cursorSpriteId].data[4] |= invisible;
    StartSpriteAnim(&gSprites[sNamingScreen->cursorSpriteId], 0);
}

static void SetCursorFlashing(bool8 flashing)
{
    gSprites[sNamingScreen->cursorSpriteId].data[4] &= 0xFF;
    gSprites[sNamingScreen->cursorSpriteId].data[4] |= flashing << 8;
}

static void SquishCursor(void)
{
    StartSpriteAnim(&gSprites[sNamingScreen->cursorSpriteId], 1);
}

static bool8 IsCursorAnimFinished(void)
{
    return gSprites[sNamingScreen->cursorSpriteId].animEnded;
}

static const u8 sButtonKeyRoles[] = {KEY_ROLE_PAGE, KEY_ROLE_BACKSPACE, KEY_ROLE_OK};

static u8 GetKeyRoleAtCursorPos(void)
{
    s16 cursorX;
    s16 cursorY;

    GetCursorPos(&cursorX, &cursorY);
    if (cursorX < GetCurrentPageColumnCount())
        return KEY_ROLE_CHAR;
    else
        return sButtonKeyRoles[cursorY];
}

// If the cursor's x is equal to the column count, cursor is in the button column
static u8 GetCurrentPageColumnCount(void)
{
    return sPageColumnCounts[sub_80E3274()];
}

static void CreatePageSwitcherSprites(void)
{
    u8 bgSpriteId;
    u8 textSpriteId;
    u8 buttonSpriteId;

    bgSpriteId = CreateSprite(&sSpriteTemplate_PageSwitchBg, 204, 88, 0);
    sNamingScreen->selectBtnFrameSpriteId = bgSpriteId;
    SetSubspriteTables(&gSprites[bgSpriteId], sSubspriteTable_PageSwitchBg);
    gSprites[bgSpriteId].invisible = TRUE;

    textSpriteId = CreateSprite(&sSpriteTemplate_PageSwitchText, 204, 84, 1);
    gSprites[bgSpriteId].data[6] = textSpriteId;
    SetSubspriteTables(&gSprites[textSpriteId], sSubspriteTable_PageSwitchText);
    gSprites[textSpriteId].invisible = TRUE;

    buttonSpriteId = CreateSprite(&sSpriteTemplate_PageSwitchButton, 204, 83, 2);
    gSprites[buttonSpriteId].oam.priority = 1;
    gSprites[bgSpriteId].data[7] = buttonSpriteId;
    gSprites[buttonSpriteId].invisible = TRUE;
}

static void sub_80E4050(void)
{
    struct Sprite *sprite = &gSprites[sNamingScreen->selectBtnFrameSpriteId];

    sprite->data[0] = 2;
    sprite->data[1] = sNamingScreen->currentPage;
}

static u8 sub_80E40AC(struct Sprite *);
static u8 sub_80E4100(struct Sprite *);
static u8 sub_80E4104(struct Sprite *);
static u8 sub_80E4178(struct Sprite *);

static u8 (*const sPageSwitchSpriteFuncs[])(struct Sprite *) =
{
    sub_80E40AC,
    sub_80E4100,
    sub_80E4104,
    sub_80E4178,
};

static void SpriteCB_PageSwitch(struct Sprite *sprite)
{
    while (sPageSwitchSpriteFuncs[sprite->data[0]](sprite) != 0);
}

static u8 sub_80E40AC(struct Sprite *sprite)
{
    struct Sprite *sprite1 = &gSprites[sprite->data[6]];
    struct Sprite *sprite2 = &gSprites[sprite->data[7]];

    sub_80E41B8(sub_80E3244(sNamingScreen->currentPage), sprite1, sprite2);
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

static const u16 gUnknown_0858BEF8[] = {
    PALTAG_1, 
    PALTAG_3, 
    PALTAG_2
};

static const u16 gUnknown_0858BEFE[] = {
    GFXTAG_PAGE_SWITCH_UPPER, 
    GFXTAG_PAGE_SWITCH_OTHERS, 
    GFXTAG_PAGE_SWITCH_LOWER
};

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

    spriteId = CreateSprite(&sSpriteTemplate_BackButton, 204, 116, 0);
    SetSubspriteTables(&gSprites[spriteId], sSubspriteTable_Button);
    gSprites[spriteId].invisible = TRUE;

    spriteId = CreateSprite(&sSpriteTemplate_OkButton, 204, 140, 0);
    SetSubspriteTables(&gSprites[spriteId], sSubspriteTable_Button);
    gSprites[spriteId].invisible = TRUE;
}

static void CreateTextEntrySprites(void)
{
    u8 spriteId;
    s16 xPos;
    u8 i;

    xPos = sNamingScreen->inputCharBaseXPos - 5;
    spriteId = CreateSprite(&sSpriteTemplate_InputArrow, xPos, 56, 0);
    gSprites[spriteId].oam.priority = 3;
    gSprites[spriteId].invisible = TRUE;
    xPos = sNamingScreen->inputCharBaseXPos;
    for (i = 0; i < sNamingScreen->template->maxChars; i++, xPos += 8)
    {
        spriteId = CreateSprite(&sSpriteTemplate_Underscore, xPos + 3, 60, 0);
        gSprites[spriteId].oam.priority = 3;
        gSprites[spriteId].data[0] = i;
        gSprites[spriteId].invisible = TRUE;
    }
}

//--------------------------------------------------
// Icon creation (the thing you're naming or giving input to)
//--------------------------------------------------

static void NamingScreen_NoIcon(void);
static void NamingScreen_CreatePlayerIcon(void);
static void NamingScreen_CreatePCIcon(void);
static void NamingScreen_CreateMonIcon(void);
static void NamingScreen_CreateWaldaDadIcon(void);

static void (*const sIconFunctions[])(void) =
{
    NamingScreen_NoIcon,
    NamingScreen_CreatePlayerIcon,
    NamingScreen_CreatePCIcon,
    NamingScreen_CreateMonIcon,
    NamingScreen_CreateWaldaDadIcon,
};

static void CreateInputTargetIcon(void)
{
    sIconFunctions[sNamingScreen->template->iconFunction]();
}

static void NamingScreen_NoIcon(void)
{

}

static void NamingScreen_CreatePlayerIcon(void)
{
    u8 rivalGfxId;
    u8 spriteId;

    rivalGfxId = GetRivalAvatarGraphicsIdByStateIdAndGender(0, sNamingScreen->monSpecies);
    spriteId = AddPseudoObjectEvent(rivalGfxId, SpriteCallbackDummy, 56, 37, 0);
    gSprites[spriteId].oam.priority = 3;
    StartSpriteAnim(&gSprites[spriteId], 4);
}

static void NamingScreen_CreatePCIcon(void)
{
    u8 spriteId;

    spriteId = CreateSprite(&sSpriteTemplate_PCIcon, 56, 41, 0);
    SetSubspriteTables(&gSprites[spriteId], sSubspriteTable_PCIcon);
    gSprites[spriteId].oam.priority = 3;
}

static void NamingScreen_CreateMonIcon(void)
{
    u8 spriteId;

    LoadMonIconPalettes();
    spriteId = CreateMonIcon(sNamingScreen->monSpecies, SpriteCallbackDummy, 56, 40, 0, sNamingScreen->monPersonality, 1);
    gSprites[spriteId].oam.priority = 3;
}

static void NamingScreen_CreateWaldaDadIcon(void)
{
    u8 spriteId;

    spriteId = AddPseudoObjectEvent(OBJ_EVENT_GFX_MAN_1, SpriteCallbackDummy, 56, 37, 0);
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
    [KEY_ROLE_CHAR]      = KeyboardKeyHandler_Character,
    [KEY_ROLE_PAGE]      = KeyboardKeyHandler_Page,
    [KEY_ROLE_BACKSPACE] = KeyboardKeyHandler_Backspace,
    [KEY_ROLE_OK]        = KeyboardKeyHandler_OK,
};

static bool8 HandleKeyboardEvent(void)
{
    u8 event = GetInputEvent();
    u8 keyRole = GetKeyRoleAtCursorPos();

    if (event == INPUT_SELECT)
    {
        return SwitchKeyboardPage();
    }
    else if (event == INPUT_B_BUTTON)
    {
        DeleteTextCharacter();
        return FALSE;
    }
    else if (event == INPUT_START)
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
    TryStartButtonFlash(BUTTON_COUNT, FALSE, FALSE);
    if (event == INPUT_A_BUTTON)
    {
        bool8 textFull = AddTextCharacter();

        SquishCursor();
        if (textFull)
        {
            SetInputState(INPUT_STATE_2);
            sNamingScreen->state = STATE_MOVE_TO_OK_BUTTON;
        }
    }
    return FALSE;
}

static bool8 KeyboardKeyHandler_Page(u8 event)
{
    TryStartButtonFlash(BUTTON_PAGE, TRUE, FALSE);
    if (event == INPUT_A_BUTTON)
        return SwitchKeyboardPage();
    else
        return FALSE;
}

static bool8 KeyboardKeyHandler_Backspace(u8 event)
{
    TryStartButtonFlash(BUTTON_BACK, TRUE, FALSE);
    if (event == INPUT_A_BUTTON)
        DeleteTextCharacter();
    return FALSE;
}

static bool8 KeyboardKeyHandler_OK(u8 event)
{
    TryStartButtonFlash(BUTTON_OK, TRUE, FALSE);
    if (event == INPUT_A_BUTTON)
    {
        PlaySE(SE_SELECT);
        sNamingScreen->state = STATE_6;
        return TRUE;
    }
    else
        return FALSE;
}

static bool8 SwitchKeyboardPage(void)
{
    sNamingScreen->state = STATE_START_PAGE_SWAP;
    return TRUE;
}

//--------------------------------------------------
// Input handling
//--------------------------------------------------

#define tState data[0]
#define tKeyboardEvent data[1]
#define tButtonId data[2]


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

static void CreateInputHandlerTask(void)
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
    task->tKeyboardEvent = INPUT_NONE;
}

static void InputState_Enabled(struct Task *task)
{
    task->tKeyboardEvent = INPUT_NONE;

    if (JOY_NEW(A_BUTTON))
        task->tKeyboardEvent = INPUT_A_BUTTON;
    else if (JOY_NEW(B_BUTTON))
        task->tKeyboardEvent = INPUT_B_BUTTON;
    else if (JOY_NEW(SELECT_BUTTON))
        task->tKeyboardEvent = INPUT_SELECT;
    else if (JOY_NEW(START_BUTTON))
        task->tKeyboardEvent = INPUT_START;
    else
        HandleDpadMovement(task);
}

static void InputState_2(struct Task *task)
{
    task->tKeyboardEvent = INPUT_NONE;
}

static void HandleDpadMovement(struct Task *task)
{
    const s16 sDpadDeltaX[] =
    {
        [INPUT_NONE]       = 0,
        [INPUT_DPAD_UP]    = 0,
        [INPUT_DPAD_DOWN]  = 0,
        [INPUT_DPAD_LEFT]  = -1,
        [INPUT_DPAD_RIGHT] = 1
    };

    const s16 sDpadDeltaY[] =
    {
        [INPUT_NONE]       = 0,
        [INPUT_DPAD_UP]    = -1,
        [INPUT_DPAD_DOWN]  = 1,
        [INPUT_DPAD_LEFT]  = 0,
        [INPUT_DPAD_RIGHT] = 0
    };

    const s16 sKeyRowToButtonRow[KBROW_COUNT] = {0, 1, 1, 2};
    const s16 gUnknown_0858BF50[] = {0, 0, 3};

    s16 cursorX;
    s16 cursorY;
    u16 input;
    s16 prevCursorX;

    GetCursorPos(&cursorX, &cursorY);
    input = INPUT_NONE;
    if (JOY_REPEAT(DPAD_UP))
        input = INPUT_DPAD_UP;
    if (JOY_REPEAT(DPAD_DOWN))
        input = INPUT_DPAD_DOWN;
    if (JOY_REPEAT(DPAD_LEFT))
        input = INPUT_DPAD_LEFT;
    if (JOY_REPEAT(DPAD_RIGHT))
        input = INPUT_DPAD_RIGHT;

    // Get new cursor position
    prevCursorX = cursorX;
    cursorX += sDpadDeltaX[input];
    cursorY += sDpadDeltaY[input];

    // Wrap cursor position in the X direction
    if (cursorX < 0)
        cursorX = GetCurrentPageColumnCount();
    if (cursorX > GetCurrentPageColumnCount())
        cursorX = 0;

    
    // Handle moving on/off the button column
    if (sDpadDeltaX[input] != 0)
    {
        if (cursorX == GetCurrentPageColumnCount())
        {
            // Moved onto button column
            task->tButtonId = cursorY;
            cursorY = sKeyRowToButtonRow[cursorY];
        }
        else if (prevCursorX == GetCurrentPageColumnCount())
        {
            // Moved off button column
            if (cursorY == 1)
                cursorY = task->tButtonId;
            else
                cursorY = gUnknown_0858BF50[cursorY];
        }
    }

    // Wrap cursor position in the y direction
    if (cursorX == GetCurrentPageColumnCount())
    {
        // There are only 3 keys in the button column
        // so wrap Y accordingly
        if (cursorY < 0)
            cursorY = BUTTON_COUNT - 1;
        if (cursorY >= BUTTON_COUNT)
            cursorY = 0;

        if (cursorY == 0)
            task->tButtonId = BUTTON_BACK;
        else if (cursorY == BUTTON_COUNT - 1)
            task->tButtonId = BUTTON_OK;
    }
    else
    {
        if (cursorY < 0)
            cursorY = KBROW_COUNT - 1;
        if (cursorY > KBROW_COUNT - 1)
            cursorY = 0;
    }
    SetCursorPos(cursorX, cursorY);
}

#undef tState
#undef tKeyboardEvent
#undef tButtonId

static void DrawNormalTextEntryBox(void)
{
    FillWindowPixelBuffer(sNamingScreen->windows[WIN_TEXT_ENTRY_BOX], PIXEL_FILL(1));
    AddTextPrinterParameterized(sNamingScreen->windows[WIN_TEXT_ENTRY_BOX], 1, sNamingScreen->template->title, 8, 1, 0, 0);
    PutWindowTilemap(sNamingScreen->windows[WIN_TEXT_ENTRY_BOX]);
}

static void DrawMonTextEntryBox(void)
{
    u8 buffer[32];

    StringCopy(buffer, gSpeciesNames[sNamingScreen->monSpecies]);
    StringAppendN(buffer, sNamingScreen->template->title, 15);
    FillWindowPixelBuffer(sNamingScreen->windows[WIN_TEXT_ENTRY_BOX], PIXEL_FILL(1));
    AddTextPrinterParameterized(sNamingScreen->windows[WIN_TEXT_ENTRY_BOX], 1, buffer, 8, 1, 0, 0);
    PutWindowTilemap(sNamingScreen->windows[WIN_TEXT_ENTRY_BOX]);
}

static void (*const sDrawTextEntryBoxFuncs[])(void) =
{
    [NAMING_SCREEN_PLAYER]     = DrawNormalTextEntryBox,
    [NAMING_SCREEN_BOX]        = DrawNormalTextEntryBox,
    [NAMING_SCREEN_CAUGHT_MON] = DrawMonTextEntryBox,
    [NAMING_SCREEN_NICKNAME]   = DrawMonTextEntryBox,
    [NAMING_SCREEN_WALDA]      = DrawNormalTextEntryBox,
};

static void DrawTextEntryBox(void)
{
    sDrawTextEntryBoxFuncs[sNamingScreen->templateNum]();
}

static void DummyGenderIcon(void);
static void DrawGenderIcon(void);

static void (*const sDrawGenderIconFuncs[])(void) =
{
    [FALSE] = DummyGenderIcon,
    [TRUE]  = DrawGenderIcon,
};

static void TryDrawGenderIcon(void)
{
    sDrawGenderIconFuncs[sNamingScreen->template->addGenderIcon]();
}

static void DummyGenderIcon(void)
{

}

static const u8 sGenderColors[2][3] =
{
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_BLUE, TEXT_COLOR_BLUE},
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_RED, TEXT_COLOR_RED}
};

static void DrawGenderIcon(void)
{
    u8 text[2];
    bool8 isFemale = FALSE;

    StringCopy(text, gText_MaleSymbol);
    if (sNamingScreen->monGender != MON_GENDERLESS)
    {
        if (sNamingScreen->monGender == MON_FEMALE)
        {
            StringCopy(text, gText_FemaleSymbol);
            isFemale = TRUE;
        }
        AddTextPrinterParameterized3(sNamingScreen->windows[WIN_TEXT_ENTRY], 1, 0x68, 1, sGenderColors[isFemale], -1, text);
    }
}

static u8 GetCharAtKeyboardPos(s16 x, s16 y)
{
    return sKeyboardChars[x + y * KBCOL_COUNT + sub_80E3274() * KBCOL_COUNT * KBROW_COUNT];
}


static u8 GetTextEntryPosition(void)
{
    u8 i;

    for (i = 0; i < sNamingScreen->template->maxChars; i++)
    {
        if (sNamingScreen->textBuffer[i] == EOS)
            return i;
    }
    return sNamingScreen->template->maxChars - 1;
}

static u8 GetPreviousTextCaretPosition(void)
{
    s8 i;

    for (i = sNamingScreen->template->maxChars - 1; i > 0; i--)
    {
        if (sNamingScreen->textBuffer[i] != EOS)
            return i;
    }
    return 0;
}

static void DeleteTextCharacter(void)
{
    u8 index;
    u8 var2;

    index = GetPreviousTextCaretPosition();
    sNamingScreen->textBuffer[index] = 0;
    DrawTextEntry();
    CopyBgTilemapBufferToVram(3);
    sNamingScreen->textBuffer[index] = EOS;
    var2 = GetKeyRoleAtCursorPos();
    if (var2 == 0 || var2 == 2)
        TryStartButtonFlash(BUTTON_BACK, FALSE, TRUE);
    PlaySE(SE_BOWA);
}

// Returns TRUE if the text entry is now full
static bool8 AddTextCharacter(void)
{
    s16 x;
    s16 y;

    GetCursorPos(&x, &y);
    BufferCharacter(GetCharAtKeyboardPos(x, y));
    DrawTextEntry();
    CopyBgTilemapBufferToVram(3);
    PlaySE(SE_SELECT);

    if (GetPreviousTextCaretPosition() != sNamingScreen->template->maxChars - 1)
        return FALSE;
    else
        return TRUE;
}

static void BufferCharacter(u8 ch)
{
    u8 index = GetTextEntryPosition();
    sNamingScreen->textBuffer[index] = ch;
}

static void SaveInputText(void)
{
    u8 i;

    for (i = 0; i < sNamingScreen->template->maxChars; i++)
    {
        if (sNamingScreen->textBuffer[i] != CHAR_SPACE && sNamingScreen->textBuffer[i] != EOS)
        {
            StringCopyN(sNamingScreen->destBuffer, sNamingScreen->textBuffer, sNamingScreen->template->maxChars + 1);
            break;
        }
    }
}

static void LoadGfx(void)
{
    LZ77UnCompWram(gNamingScreenMenu_Gfx, sNamingScreen->tileBuffer);
    LoadBgTiles(1, sNamingScreen->tileBuffer, sizeof(sNamingScreen->tileBuffer), 0);
    LoadBgTiles(2, sNamingScreen->tileBuffer, sizeof(sNamingScreen->tileBuffer), 0);
    LoadBgTiles(3, sNamingScreen->tileBuffer, sizeof(sNamingScreen->tileBuffer), 0);
    LoadSpriteSheets(sSpriteSheets);
    LoadSpritePalettes(sSpritePalettes);
}

static void CreateHelperTasks(void)
{
    CreateInputHandlerTask();
    CreateButtonFlashTask();
}

static void LoadPalettes(void)
{
    LoadPalette(gNamingScreenMenu_Pal, 0, 0xC0);
    LoadPalette(sKeyboard_Pal, 0xA0, sizeof(sKeyboard_Pal));
    LoadPalette(GetTextWindowPalette(2), 0xB0, 0x20);
}

static void DrawBgTilemap(u8 bg, const void *src)
{
    CopyToBgTilemapBuffer(bg, src, 0, 0);
}

static void NamingScreen_Dummy(u8 bg, u8 page)
{

}

static void DrawTextEntry(void)
{
    u8 i;
    u8 temp[2];
    u16 extraWidth;
    u8 maxChars = sNamingScreen->template->maxChars;
    u16 x = sNamingScreen->inputCharBaseXPos - 0x40;

    FillWindowPixelBuffer(sNamingScreen->windows[WIN_TEXT_ENTRY], PIXEL_FILL(1));

    for (i = 0; i < maxChars; i++)
    {
        temp[0] = sNamingScreen->textBuffer[i];
        temp[1] = gText_ExpandedPlaceholder_Empty[0];
        extraWidth = (IsWideLetter(temp[0]) == TRUE) ? 2 : 0;

        AddTextPrinterParameterized(sNamingScreen->windows[WIN_TEXT_ENTRY], 1, temp, i * 8 + x + extraWidth, 1, 0xFF, NULL);
    }

    TryDrawGenderIcon();
    CopyWindowToVram(sNamingScreen->windows[WIN_TEXT_ENTRY], 2);
    PutWindowTilemap(sNamingScreen->windows[WIN_TEXT_ENTRY]);
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
    [KBPAGE_LETTERS_LOWER] = PIXEL_FILL(14),
    [KBPAGE_LETTERS_UPPER] = PIXEL_FILL(13),
    [KBPAGE_SYMBOLS]       = PIXEL_FILL(15)
};

static const u8 *const sKeyboardTextColors[KBPAGE_COUNT] =
{
    [KBPAGE_LETTERS_LOWER] = sTextColorStruct.colors[1],
    [KBPAGE_LETTERS_UPPER] = sTextColorStruct.colors[0],
    [KBPAGE_SYMBOLS]       = sTextColorStruct.colors[2]
};

static void PrintKeyboardKeys(u8 window, u8 page)
{
    u8 i;

    FillWindowPixelBuffer(window, sFillValues[page]);

    for (i = 0; i < KBROW_COUNT; i++)
        AddTextPrinterParameterized3(window, 1, 0, i * 16 + 1, sKeyboardTextColors[page], 0, sNamingScreenKeyboardText[page][i]);

    PutWindowTilemap(window);
}

static const u8 *const sKeyboardPageTilemaps[] =
{
    [KBPAGE_LETTERS_LOWER] = gUnknown_08DD4620, // upper
    [KBPAGE_LETTERS_UPPER] = gUnknown_08DD46E0, // lower
    [KBPAGE_SYMBOLS]       = gUnknown_08DD47A0  // symbols
};

// There are always 2 keyboard pages drawn, the current page and the one that will shown next if the player switches
// When the page switch is complete this function invisibly replaces the old page with the new next one
static void DrawKeyboardPageOnDeck(void)
{
    u8 bg;
    u8 bg_;
    u8 windowId;
    u8 bg1Priority = GetGpuReg(REG_OFFSET_BG1CNT) & 3;
    u8 bg2Priority = GetGpuReg(REG_OFFSET_BG2CNT) & 3;

    if (bg1Priority > bg2Priority)
    {
        bg = 1;
        bg_ = 1;
        windowId = sNamingScreen->windows[WIN_KB_PAGE_1];
    }
    else
    {
        bg = 2;
        bg_ = 2;
        windowId = sNamingScreen->windows[WIN_KB_PAGE_2];
    }

    DrawBgTilemap(bg, sKeyboardPageTilemaps[sNamingScreen->currentPage]);
    PrintKeyboardKeys(windowId, sub_80E3254());
    NamingScreen_Dummy(bg, sub_80E3254());
    CopyBgTilemapBufferToVram(bg_);
}

static void PrintControls(void)
{
    const u8 color[3] = { TEXT_DYNAMIC_COLOR_6, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GREY };

    FillWindowPixelBuffer(sNamingScreen->windows[WIN_BANNER], PIXEL_FILL(15));
    AddTextPrinterParameterized3(sNamingScreen->windows[WIN_BANNER], 0, 2, 1, color, 0, gText_MoveOkBack);
    PutWindowTilemap(sNamingScreen->windows[WIN_BANNER]);
    CopyWindowToVram(sNamingScreen->windows[WIN_BANNER], 3);
}

static void CB2_NamingScreen(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void NamingScreen_ResetVHBlank(void)
{
    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
}

static void NamingScreen_SetVBlank(void)
{
    SetVBlankCallback(VBlankCB_NamingScreen);
}

static void VBlankCB_NamingScreen(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    SetGpuReg(REG_OFFSET_BG1VOFS, sNamingScreen->bg1vOffset);
    SetGpuReg(REG_OFFSET_BG2VOFS, sNamingScreen->bg2vOffset);
    SetGpuReg(REG_OFFSET_BG1CNT, GetGpuReg(REG_OFFSET_BG1CNT) & 0xFFFC);
    SetGpuRegBits(REG_OFFSET_BG1CNT, sNamingScreen->bg1Priority);
    SetGpuReg(REG_OFFSET_BG2CNT, GetGpuReg(REG_OFFSET_BG2CNT) & 0xFFFC);
    SetGpuRegBits(REG_OFFSET_BG2CNT, sNamingScreen->bg2Priority);
}

static void NamingScreen_ShowBgs(void)
{
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
}

// Always false (presumably for non-latin languages)
static bool8 IsWideLetter(u8 character)
{
    u8 i;

    for (i = 0; sText_AlphabetUpperLower[i] != EOS; i++)
    {
        if (character == sText_AlphabetUpperLower[i])
            return FALSE;
    }
    return FALSE;
}

// Debug? Unused, and arguments aren't sensible for non-player screens.
static void Debug_NamingScreenPlayer(void)
{
    DoNamingScreen(NAMING_SCREEN_PLAYER, gSaveBlock2Ptr->playerName, gSaveBlock2Ptr->playerGender, 0, 0, CB2_ReturnToFieldWithOpenMenu);
}

static void Debug_NamingScreenBox(void)
{
    DoNamingScreen(NAMING_SCREEN_BOX, gSaveBlock2Ptr->playerName, gSaveBlock2Ptr->playerGender, 0, 0, CB2_ReturnToFieldWithOpenMenu);
}

static void Debug_NamingScreenCaughtMon(void)
{
    DoNamingScreen(NAMING_SCREEN_CAUGHT_MON, gSaveBlock2Ptr->playerName, gSaveBlock2Ptr->playerGender, 0, 0, CB2_ReturnToFieldWithOpenMenu);
}

static void Debug_NamingScreenNickname(void)
{
    DoNamingScreen(NAMING_SCREEN_NICKNAME, gSaveBlock2Ptr->playerName, gSaveBlock2Ptr->playerGender, 0, 0, CB2_ReturnToFieldWithOpenMenu);
}

//--------------------------------------------------
// Forward-declared variables
//--------------------------------------------------

static const struct NamingScreenTemplate sPlayerNamingScreenTemplate =
{
    .copyExistingString = FALSE,
    .maxChars = 7,
    .iconFunction = 1,
    .addGenderIcon = FALSE,
    .initialPage = KBPAGE_LETTERS_UPPER,
    .unused = 35,
    .title = gText_YourName,
};

static const struct NamingScreenTemplate sPCBoxNamingTemplate =
{
    .copyExistingString = FALSE,
    .maxChars = 8,
    .iconFunction = 2,
    .addGenderIcon = FALSE,
    .initialPage = KBPAGE_LETTERS_UPPER,
    .unused = 19,
    .title = gText_BoxName,
};

static const struct NamingScreenTemplate sMonNamingScreenTemplate =
{
    .copyExistingString = FALSE,
    .maxChars = 10,
    .iconFunction = 3,
    .addGenderIcon = TRUE,
    .initialPage = KBPAGE_LETTERS_UPPER,
    .unused = 35,
    .title = gText_PkmnsNickname,
};

static const struct NamingScreenTemplate sWaldaWordsScreenTemplate =
{
    .copyExistingString = TRUE,
    .maxChars = 15,
    .iconFunction = 4,
    .addGenderIcon = FALSE,
    .initialPage = KBPAGE_LETTERS_UPPER,
    .unused = 11,
    .title = gText_TellHimTheWords,
};

static const struct NamingScreenTemplate *const sNamingScreenTemplates[] =
{
    [NAMING_SCREEN_PLAYER]     = &sPlayerNamingScreenTemplate,
    [NAMING_SCREEN_BOX]        = &sPCBoxNamingTemplate,
    [NAMING_SCREEN_CAUGHT_MON] = &sMonNamingScreenTemplate,
    [NAMING_SCREEN_NICKNAME]   = &sMonNamingScreenTemplate,
    [NAMING_SCREEN_WALDA]      = &sWaldaWordsScreenTemplate,
};

static const struct OamData sOam_8x8 =
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

static const struct OamData sOam_16x16 =
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

static const struct OamData sOam_32x16 =
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

static const struct Subsprite sSubsprites_PageSwitchBg[] =
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

static const struct Subsprite sSubsprites_PageSwitchText[] =
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

static const struct Subsprite sSubsprites_Button[] =
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

static const struct Subsprite sSubsprites_PCIcon[] =
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

static const struct SubspriteTable sSubspriteTable_PageSwitchBg[] =
{
    {ARRAY_COUNT(sSubsprites_PageSwitchBg), sSubsprites_PageSwitchBg}
};

static const struct SubspriteTable sSubspriteTable_PageSwitchText[] =
{
    {ARRAY_COUNT(sSubsprites_PageSwitchText), sSubsprites_PageSwitchText},
    {ARRAY_COUNT(sSubsprites_PageSwitchText), sSubsprites_PageSwitchText},
    {ARRAY_COUNT(sSubsprites_PageSwitchText), sSubsprites_PageSwitchText}
};

static const struct SubspriteTable sSubspriteTable_Button[] =
{
    {ARRAY_COUNT(sSubsprites_Button), sSubsprites_Button}
};

static const struct SubspriteTable sSubspriteTable_PCIcon[] =
{
    {ARRAY_COUNT(sSubsprites_PCIcon), sSubsprites_PCIcon}
};

static const struct SpriteFrameImage sImageTable_PCIcon[] =
{
    {sPCIconOn_Gfx, sizeof(sPCIconOn_Gfx)},
    {sPCIconOff_Gfx, sizeof(sPCIconOff_Gfx)},
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

static const union AnimCmd sAnim_PCIcon[] =
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

static const union AnimCmd *const sAnims_PCIcon[] =
{
    sAnim_PCIcon
};

static const struct SpriteTemplate sSpriteTemplate_PageSwitchBg =
{
    .tileTag = GFXTAG_PAGE_SWITCH_BG,
    .paletteTag = PALTAG_PAGE_SWITCH,
    .oam = &sOam_8x8,
    .anims = gSpriteAnimTable_858C0B0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PageSwitch
};

static const struct SpriteTemplate sSpriteTemplate_PageSwitchButton =
{
    .tileTag = GFXTAG_PAGE_SWITCH_BUTTON,
    .paletteTag = PALTAG_1,
    .oam = &sOam_32x16,
    .anims = gSpriteAnimTable_858C0B0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_PageSwitchText =
{
    .tileTag = GFXTAG_PAGE_SWITCH_UPPER,
    .paletteTag = PALTAG_PAGE_SWITCH,
    .oam = &sOam_8x8,
    .anims = gSpriteAnimTable_858C0B0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_BackButton =
{
    .tileTag = GFXTAG_BACK_BUTTON,
    .paletteTag = PALTAG_BACK_BUTTON,
    .oam = &sOam_8x8,
    .anims = gSpriteAnimTable_858C0B0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_OkButton =
{
    .tileTag = GFXTAG_OK_BUTTON,
    .paletteTag = PALTAG_OK_BUTTON,
    .oam = &sOam_8x8,
    .anims = gSpriteAnimTable_858C0B0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_Cursor =
{
    .tileTag = GFXTAG_CURSOR,
    .paletteTag = PALTAG_CURSOR,
    .oam = &sOam_16x16,
    .anims = gSpriteAnimTable_858C0B4,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Cursor
};

static const struct SpriteTemplate sSpriteTemplate_InputArrow =
{
    .tileTag = GFXTAG_INPUT_ARROW,
    .paletteTag = PALTAG_3,
    .oam = &sOam_8x8,
    .anims = gSpriteAnimTable_858C0B0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_InputArrow
};

static const struct SpriteTemplate sSpriteTemplate_Underscore =
{
    .tileTag = GFXTAG_UNDERSCORE,
    .paletteTag = PALTAG_3,
    .oam = &sOam_8x8,
    .anims = gSpriteAnimTable_858C0B0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Underscore
};

static const struct SpriteTemplate sSpriteTemplate_PCIcon =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_PC_ICON,
    .oam = &sOam_8x8,
    .anims = sAnims_PCIcon,
    .images = sImageTable_PCIcon,
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

static const struct SpriteSheet sSpriteSheets[] =
{
    {gNamingScreenRWindow_Gfx + 0x280,          0x1E0,  GFXTAG_BACK_BUTTON},
    {gNamingScreenRWindow_Gfx + 0x460,          0x1E0,  GFXTAG_OK_BUTTON},
    {gNamingScreenRWindow_Gfx,                  0x280,  GFXTAG_PAGE_SWITCH_BG},
    {gNamingScreenPageButton_Gfx + 0x20,        0x100,  GFXTAG_PAGE_SWITCH_BUTTON},
    {gNamingScreenROptions_Gfx,                 0x060,  GFXTAG_PAGE_SWITCH_UPPER},
    {gNamingScreenROptions_Gfx + 0xA0,          0x060,  GFXTAG_PAGE_SWITCH_LOWER},
    {gNamingScreenROptions_Gfx + 0x140,         0x060,  GFXTAG_PAGE_SWITCH_OTHERS},
    {gNamingScreenCursor_Gfx,                   0x080,  GFXTAG_CURSOR},
    {gNamingScreenCursor_Gfx + 0xA0,            0x080,  GFXTAG_CURSOR_SQUISHED},
    {gNamingScreenCursor_Gfx + 0x140,           0x080,  GFXTAG_CURSOR_FILLED},
    {gNamingScreenInputArrow_Gfx,               0x020,  GFXTAG_INPUT_ARROW},
    {gNamingScreenUnderscore_Gfx,               0x020,  GFXTAG_UNDERSCORE},
    {}
};

static const struct SpritePalette sSpritePalettes[] =
{
    {gNamingScreenMenu_Pal,         PALTAG_PC_ICON},
    {gNamingScreenMenu_Pal + 0x10,  PALTAG_1}, // upper switch button
    {gNamingScreenMenu_Pal + 0x20,  PALTAG_2}, // lower switch button
    {gNamingScreenMenu_Pal + 0x30,  PALTAG_3}, // symbols switch button
    {gNamingScreenMenu_Pal + 0x40,  PALTAG_PAGE_SWITCH},
    {gNamingScreenMenu_Pal + 0x50,  PALTAG_CURSOR},
    {gNamingScreenMenu_Pal + 0x40,  PALTAG_BACK_BUTTON},
    {gNamingScreenMenu_Pal + 0x40,  PALTAG_OK_BUTTON},
    {}
};


