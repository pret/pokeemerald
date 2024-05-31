#include "gba/types.h"
#include "gba/defines.h"
#include "gba/isagbprint.h"
#include "global.h"
#include "main.h"
#include "bg.h"
#include "text_window.h"
#include "window.h"
#include "characters.h"
#include "palette.h"
#include "task.h"
#include "overworld.h"
#include "malloc.h"
#include "gba/macro.h"
#include "menu_helpers.h"
#include "menu.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "strings.h"
#include "constants/rgb.h"
#include "decompress.h"
#include "constants/songs.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "pokemon_icon.h"
#include "graphics.h"
#include "data.h"
#include "pokedex.h"
#include "gpu_regs.h"
#include "ui_mode_menu.h"
#include "list_menu.h"
#include "international_string_util.h"
#include "event_data.h"
#include "constants/flags.h"
#include "ui_birch_case.h"

//defines
#define MODE_NORMAL     0
#define MODE_HARD       1
#define MODE_CUSTOM     2
#define MODE_SINGLES    0
#define MODE_DOUBLES    1
#define RANDOM_MONS     0
#define RANDOM_ALL      1
#define XP_75           0
#define XP_50           1
#define ACTIVE          0
#define INACTIVE        1
#define YES             0
#define NO              1


// This code is based on Ghoulslash's excellent UI tutorial:
// https://www.pokecommunity.com/showpost.php?p=10441093

struct ModeMenuState
{
    MainCallback savedCallback;
    u8 loadState;
};

enum WindowIds
{
    WIN_TOPBAR,
    WIN_OPTIONS,
    WIN_DESCRIPTION
};

enum MenuItems
{
    MENUITEM_MAIN_DEFAULTS,
    MENUITEM_MAIN_AUTOSAVE,
    MENUITEM_MAIN_BATTLEMODE,
    MENUITEM_MAIN_RANDOMIZER,
    MENUITEM_MAIN_XPSHARE,
    MENUITEM_MAIN_STAT_CHANGER,
    MENUITEM_MAIN_LEGENDARIES,
    MENUITEM_MAIN_DUPLICATES,
    MENUITEM_MAIN_CANCEL,
    MENUITEM_MAIN_COUNT,
};

static EWRAM_DATA struct ModeMenuState *sModeMenuState = NULL;

static const struct BgTemplate sModeMenuBgTemplates[] =
{
    {
       .bg = 0,
       .charBaseIndex = 1,
       .mapBaseIndex = 30,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 1,
    },
    {
       .bg = 1,
       .charBaseIndex = 1,
       .mapBaseIndex = 31,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 0,
    },
    {
       .bg = 2,
       .charBaseIndex = 0,
       .mapBaseIndex = 29,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 1,
    },
    {
       .bg = 3,
       .charBaseIndex = 3,
       .mapBaseIndex = 27,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 2,
    },
};

static const struct WindowTemplate sModeMenuWindowTemplates[] =
{
    [WIN_TOPBAR] =
    {
        .bg = 1,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 2
    },
    [WIN_OPTIONS] =
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 26,
        .height = 10,
        .paletteNum = 1,
        .baseBlock = 62
    },
    [WIN_DESCRIPTION] = 
    {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 1,
        .baseBlock = 500
    },
    DUMMY_WIN_TEMPLATE
};

//
//  Graphics Pointers to Tilemaps, Tilesets, Spritesheets, Palettes
//

// EWRAM vars
EWRAM_DATA static struct ModeMenu *sOptions = NULL;
static EWRAM_DATA u8 *sBg2TilemapBuffer = NULL;
static EWRAM_DATA u8 *sBg3TilemapBuffer = NULL;

// const data
static const u8 sEqualSignGfx[] = INCBIN_U8("graphics/interface/option_menu_equals_sign.4bpp"); // note: this is only used in the Japanese release
static const u16 sModeMenuBg_Pal[] = {RGB(17, 18, 31)};
static const u16 sModeMenuText_Pal[] = INCBIN_U16("graphics/interface/option_menu_text_custom.gbapal");

static const u32 sOptionsPlusTiles[] = INCBIN_U32("graphics/ui_mode_menu/mode_menu_tiles.4bpp.lz");
static const u16 sOptionsPlusPalette[] = INCBIN_U16("graphics/ui_mode_menu/mode_menu_tiles.gbapal");
static const u32 sOptionsPlusTilemap[] = INCBIN_U32("graphics/ui_mode_menu/mode_menu_tiles.bin.lz");

// Scrolling Background
static const u32 sScrollBgTiles[] = INCBIN_U32("graphics/ui_mode_menu/scroll_tiles.4bpp.lz");
static const u32 sScrollBgTilemap[] = INCBIN_U32("graphics/ui_mode_menu/scroll_tiles.bin.lz");
static const u16 sScrollBgPalette[] = INCBIN_U16("graphics/ui_mode_menu/scroll_tiles.gbapal");

#define TEXT_COLOR_OPTIONS_WHITE                1
#define TEXT_COLOR_OPTIONS_GRAY_FG              2
#define TEXT_COLOR_OPTIONS_GRAY_SHADOW          3
#define TEXT_COLOR_OPTIONS_GRAY_LIGHT_FG        4
#define TEXT_COLOR_OPTIONS_ORANGE_FG            5
#define TEXT_COLOR_OPTIONS_ORANGE_SHADOW        6
#define TEXT_COLOR_OPTIONS_RED_FG               7
#define TEXT_COLOR_OPTIONS_RED_SHADOW           8
#define TEXT_COLOR_OPTIONS_GREEN_FG             9
#define TEXT_COLOR_OPTIONS_GREEN_SHADOW         10
#define TEXT_COLOR_OPTIONS_GREEN_DARK_FG        11
#define TEXT_COLOR_OPTIONS_GREEN_DARK_SHADOW    12
#define TEXT_COLOR_OPTIONS_RED_DARK_FG          13
#define TEXT_COLOR_OPTIONS_RED_DARK_SHADOW      14

struct ModeMenu
{
    u8 sel[MENUITEM_MAIN_COUNT];
    int menuCursor;
    int visibleCursor;
    u8 arrowTaskId;
    u8 gfxLoadState;
};

#define Y_DIFF 16 // Difference in pixels between items.
#define OPTIONS_ON_SCREEN 5
#define NUM_OPTIONS_FROM_BORDER 1

//
//  local functions
//

// Callbacks for the sample UI
static void ModeMenu_SetupCB(void);
static void ModeMenu_MainCB(void);
static void ModeMenu_VBlankCB(void);

// Sample UI tasks
static void Task_ModeMenuWaitFadeIn(u8 taskId);
static void Task_ModeMenuMainInput(u8 taskId);
static void Task_ModeMenuSave(u8 taskId);
static void Task_ModeMenuWaitFadeAndExitGracefully(u8 taskId);

// Sample UI helper functions
void ModeMenu_Init(MainCallback callback);
static const u8 *const OptionTextRight(u8 menuItem);
static bool8 CheckConditions(int selection);
static void DrawTopBarText(void); //top Option text
static void DrawLeftSideOptionText(int selection, int y);
static void DrawRightSideChoiceText(const u8 *str, int x, int y, bool8 chosen, bool8 active);
static void DrawDescriptionText(void);
static void DrawModeMenuTexts(void); //left side text;
static void DrawChoices(u32 id, int y); //right side draw function
static void HighlightModeMenuItem(void);
static bool8 ModeMenu_LoadGraphics(void);
static void ModeMenu_FreeResources(void);
static void ScrollMenu(int direction);
static void ScrollAll(int direction); // to bottom or top
static int GetMiddleX(const u8 *txt1, const u8 *txt2, const u8 *txt3);
static int XOptions_ProcessInput(int x, int selection);
static int ProcessInput_Options_Two(int selection);
static int ProcessInput_Options_Three(int selection);
static void ReDrawAll(void);
static void DrawChoices_Defaults(int selection, int y);
static void DrawChoices_Autosave(int selection, int y);
static void DrawChoices_BattleMode(int selection, int y);
static void DrawChoices_Randomizer(int selection, int y);
static void DrawChoices_XPShare(int selection, int y);
static void DrawChoices_StatChanger(int selection, int y);
static void DrawChoices_Legendaries(int selection, int y);
static void DrawChoices_Duplicates(int selection, int y);
static void DrawBgWindowFrames(void);

// Menu draw and input functions
struct MainMenu
{
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
} static const sItemFunctionsMain[MENUITEM_MAIN_COUNT] =
{
    [MENUITEM_MAIN_DEFAULTS]     = {DrawChoices_Defaults,    ProcessInput_Options_Three},
    [MENUITEM_MAIN_AUTOSAVE]     = {DrawChoices_Autosave,    ProcessInput_Options_Three},
    [MENUITEM_MAIN_BATTLEMODE]   = {DrawChoices_BattleMode,  ProcessInput_Options_Two},
    [MENUITEM_MAIN_RANDOMIZER]   = {DrawChoices_Randomizer,  ProcessInput_Options_Two},
    [MENUITEM_MAIN_XPSHARE]      = {DrawChoices_XPShare,     ProcessInput_Options_Two},
    [MENUITEM_MAIN_STAT_CHANGER] = {DrawChoices_StatChanger, ProcessInput_Options_Two},
    [MENUITEM_MAIN_LEGENDARIES]  = {DrawChoices_Legendaries, ProcessInput_Options_Two},
    [MENUITEM_MAIN_DUPLICATES]   = {DrawChoices_Duplicates,  ProcessInput_Options_Two},
    [MENUITEM_MAIN_CANCEL]       = {NULL, NULL},
};

// Menu left side option names text
static const u8 sText_Defaults[]    = _("PRESETS");
static const u8 sText_Autosave[]    = _("AUTOSAVE");
static const u8 sText_BattleMode[]  = _("BATTLE MODE");
static const u8 sText_Randomizer[]  = _("RANDOMIZER");
static const u8 sText_XPShare[]     = _("XP SHARE");
static const u8 sText_StatChanger[] = _("STAT CHANGER");
static const u8 sText_Legendaries[] = _("LEGENDARIES");
static const u8 sText_Duplicates[]  = _("DUPLICATES");
static const u8 sText_Cancel[]      = _("SAVE & LEAVE");

static const u8 *const sModeMenuItemsNamesMain[MENUITEM_MAIN_COUNT] =
{
    [MENUITEM_MAIN_DEFAULTS]     = sText_Defaults,
    [MENUITEM_MAIN_AUTOSAVE]     = sText_Autosave,
    [MENUITEM_MAIN_BATTLEMODE]   = sText_BattleMode,
    [MENUITEM_MAIN_RANDOMIZER]   = sText_Randomizer,
    [MENUITEM_MAIN_XPSHARE]      = sText_XPShare,
    [MENUITEM_MAIN_STAT_CHANGER] = sText_StatChanger,
    [MENUITEM_MAIN_LEGENDARIES]  = sText_Legendaries,
    [MENUITEM_MAIN_DUPLICATES]   = sText_Duplicates,
    [MENUITEM_MAIN_CANCEL]       = sText_Cancel,
};

static const u8 *const OptionTextRight(u8 menuItem)
{
    return sModeMenuItemsNamesMain[menuItem];
}

// Menu left side text conditions
static bool8 CheckConditions(int selection)
{
    switch(selection)
    {
        case MENUITEM_MAIN_DEFAULTS:       return TRUE;
        case MENUITEM_MAIN_AUTOSAVE:       return TRUE;
        case MENUITEM_MAIN_BATTLEMODE:     return TRUE;
        case MENUITEM_MAIN_RANDOMIZER:     return TRUE;
        case MENUITEM_MAIN_XPSHARE:        return TRUE;
        case MENUITEM_MAIN_STAT_CHANGER:   return TRUE;
        case MENUITEM_MAIN_LEGENDARIES:    return TRUE;
        case MENUITEM_MAIN_DUPLICATES:     return TRUE;
        case MENUITEM_MAIN_CANCEL:         return TRUE;
        case MENUITEM_MAIN_COUNT:          return TRUE;
        default:                           return FALSE;
    }
}

// Descriptions
static const u8 sText_Empty[]                   = _("");
static const u8 sText_Desc_Save[]               = _("Save your settings.");
static const u8 sText_Desc_Defaults_Normal[]    = _("Sets all options for Normal Mode.");
static const u8 sText_Desc_Defaults_Hard[]      = _("Sets all options for Hard Mode.");
static const u8 sText_Desc_Defaults_Custom[]    = _("Is shown when manually changing\nmode settings.");
static const u8 sText_Desc_Autosave_Off[]       = _("Autosave is inactive.");
static const u8 sText_Desc_Autosave_5[]         = _("Autosave is executed every\nfive floors during warping.");
static const u8 sText_Desc_Autosave_On[]        = _("Autosave is executed every\nfloor during warping.");
static const u8 sText_Desc_BattleMode_Singles[] = _("Play only single battles.");
static const u8 sText_Desc_BattleMode_Doubles[] = _("Play only double battles.");
static const u8 sText_Desc_Randomizer_Mons[]    = _("Only randomize Pokémon species,\ntrainers and item drops.");
static const u8 sText_Desc_Randomizer_All[]     = _("Also randomize abilities and\nmoves.");
static const u8 sText_Desc_XPShare_75[]         = _("Exp. Share gives 75% XP to\nparty mons.");
static const u8 sText_Desc_XPShare_50[]         = _("Exp. Share gives 50% XP to\nparty mons. WARNING: Hard Mode.");
static const u8 sText_Desc_StatChanger_On[]     = _("Enables the EV/IV Changer\nin the party menu.");
static const u8 sText_Desc_StatChanger_Off[]    = _("Disables the EV/IV Changer\nin the party menu.");
static const u8 sText_Desc_Legendaries_On[]     = _("Legendaries can be found in\nthe Birch Bag.");
static const u8 sText_Desc_Legendaries_Off[]    = _("Legendaries can not be found\nin the Birch Bag.");
static const u8 sText_Desc_Duplicates_On[]      = _("Truly random. Duplicates are\npossible in the Birch Bag.");
static const u8 sText_Desc_Duplicates_Off[]     = _("Birch bag can't hold duplicates.");

static const u8 *const sModeMenuItemDescriptionsMain[MENUITEM_MAIN_COUNT][3] =
{
    [MENUITEM_MAIN_DEFAULTS]     = {sText_Desc_Defaults_Normal,     sText_Desc_Defaults_Hard,       sText_Desc_Defaults_Custom},
    [MENUITEM_MAIN_AUTOSAVE]     = {sText_Desc_Autosave_Off,        sText_Desc_Autosave_5,          sText_Desc_Autosave_On},
    [MENUITEM_MAIN_BATTLEMODE]   = {sText_Desc_BattleMode_Singles,  sText_Desc_BattleMode_Doubles,  sText_Empty},
    [MENUITEM_MAIN_RANDOMIZER]   = {sText_Desc_Randomizer_Mons,     sText_Desc_Randomizer_All,      sText_Empty},
    [MENUITEM_MAIN_XPSHARE]      = {sText_Desc_XPShare_75,          sText_Desc_XPShare_50,          sText_Empty},
    [MENUITEM_MAIN_STAT_CHANGER] = {sText_Desc_StatChanger_On,      sText_Desc_StatChanger_Off,     sText_Empty},
    [MENUITEM_MAIN_LEGENDARIES]  = {sText_Desc_Legendaries_On,      sText_Desc_Legendaries_Off,     sText_Empty},
    [MENUITEM_MAIN_DUPLICATES]   = {sText_Desc_Duplicates_On,       sText_Desc_Duplicates_Off,      sText_Empty},
    [MENUITEM_MAIN_CANCEL]       = {sText_Desc_Save,                sText_Empty,                    sText_Empty},
};

static const u8 *const OptionTextDescription(void)
{
    u8 menuItem = sOptions->menuCursor;
    u8 selection;

    selection = sOptions->sel[menuItem];
    return sModeMenuItemDescriptionsMain[menuItem][selection];
}

static u8 MenuItemCount(void)
{
    return MENUITEM_MAIN_COUNT;
}

static u8 MenuItemCancel(void)
{
    return MENUITEM_MAIN_CANCEL;
}

//
//  main code
//

void Task_OpenModeMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        ModeMenu_Init(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        DestroyTask(taskId);
    }
}

void ModeMenu_Init(MainCallback callback)
{
    sModeMenuState = AllocZeroed(sizeof(struct ModeMenuState));
    if (sModeMenuState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    sModeMenuState->loadState = 0;
    sModeMenuState->savedCallback = callback;

    SetMainCallback2(ModeMenu_SetupCB);
}

static void ModeMenu_SetupCB(void)
{
    u32 i;
    u8 taskId;

    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        ResetVramOamAndBgCntRegs();
        sOptions = AllocZeroed(sizeof(*sOptions));
        FreeAllSpritePalettes();
        ResetTasks();
        ResetSpriteData();
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (void *)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        ResetBgsAndClearDma3BusyFlags(0);
        ResetBgPositions();
        
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG2);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 4);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);
        
        ResetAllBgsCoordinates();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sModeMenuBgTemplates, NELEMS(sModeMenuBgTemplates));
        InitWindows(sModeMenuWindowTemplates);

        sBg2TilemapBuffer = Alloc(0x800);
        memset(sBg2TilemapBuffer, 0, 0x800);
        SetBgTilemapBuffer(2, sBg2TilemapBuffer);
        ScheduleBgCopyTilemapToVram(2);

        sBg3TilemapBuffer = Alloc(0x800);
        memset(sBg3TilemapBuffer, 0, 0x800);
        SetBgTilemapBuffer(3, sBg3TilemapBuffer);
        ScheduleBgCopyTilemapToVram(3);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ScanlineEffect_Stop();
        gMain.state++;
        sOptions->gfxLoadState = 0;
        break;
    case 3:
        if (ModeMenu_LoadGraphics() == TRUE)
        {
            gMain.state++;
            LoadBgTiles(1, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1A2);
        }
        break;
    case 4:
        LoadPalette(sModeMenuBg_Pal, 0, sizeof(sModeMenuBg_Pal));
        LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, 0x70, 0x20);
        gMain.state++;
        break;
    case 5:
        LoadPalette(sModeMenuText_Pal, 16, sizeof(sModeMenuText_Pal));
        gMain.state++;
        break;
    case 6:
        sOptions->sel[MENUITEM_MAIN_DEFAULTS]     = gSaveBlock2Ptr->modeDefault;
        sOptions->sel[MENUITEM_MAIN_AUTOSAVE]     = gSaveBlock2Ptr->modeAutosave;
        sOptions->sel[MENUITEM_MAIN_BATTLEMODE]   = gSaveBlock2Ptr->modeBattleMode;
        sOptions->sel[MENUITEM_MAIN_RANDOMIZER]   = gSaveBlock2Ptr->modeRandomizer;
        sOptions->sel[MENUITEM_MAIN_XPSHARE]      = gSaveBlock2Ptr->modeXPShare;
        sOptions->sel[MENUITEM_MAIN_STAT_CHANGER] = gSaveBlock2Ptr->modeStatChanger;
        sOptions->sel[MENUITEM_MAIN_LEGENDARIES]  = gSaveBlock2Ptr->modeLegendaries;
        sOptions->sel[MENUITEM_MAIN_DUPLICATES]   = gSaveBlock2Ptr->modeDuplicates;
        gMain.state++;
        break;
    case 7:
        PutWindowTilemap(WIN_TOPBAR);
        DrawTopBarText();
        gMain.state++;
        break;
    case 8:
        PutWindowTilemap(WIN_DESCRIPTION);
        DrawDescriptionText();
        gMain.state++;
        break;
    case 9:
        PutWindowTilemap(WIN_OPTIONS);
        DrawModeMenuTexts();
        gMain.state++;
        break;
    case 10:
        taskId = CreateTask(Task_ModeMenuWaitFadeIn, 0);
        
        sOptions->arrowTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 240 / 2, 20, 110, MENUITEM_MAIN_COUNT - 1, 110, 110, 0);

        for (i = 0; i < min(OPTIONS_ON_SCREEN, MenuItemCount()); i++)
            DrawChoices(i, i * Y_DIFF);

        HighlightModeMenuItem();

        CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
        gMain.state++;
        break;
    case 11:
        DrawBgWindowFrames();
        gMain.state++;
        break;
    case 12:
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
        // Finally we can set our main callbacks since loading is finished
        SetVBlankCallback(ModeMenu_VBlankCB);
        SetMainCallback2(ModeMenu_MainCB);
        break;
    }
}

static void ModeMenu_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void ModeMenu_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ChangeBgY(3, 96, BG_COORD_ADD);
}

//Header Window
static const u8 sText_TopBar_Main[] = _("CHOOSE GAME MODE");
static void DrawTopBarText(void)
{
    const u8 color[3] = { 0, TEXT_COLOR_WHITE, TEXT_COLOR_OPTIONS_GRAY_FG };

    FillWindowPixelBuffer(WIN_TOPBAR, PIXEL_FILL(0));
    AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 80, 1, color, 0, sText_TopBar_Main);
    PutWindowTilemap(WIN_TOPBAR);
    CopyWindowToVram(WIN_TOPBAR, COPYWIN_FULL);
}

static void DrawModeMenuTexts(void) //left side text
{
    u8 i;

    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(0));
    for (i = 0; i < MenuItemCount(); i++)
        DrawLeftSideOptionText(i, (i * Y_DIFF) + 1);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
}

static void DrawDescriptionText(void)
{
    u8 color_gray[3];
    color_gray[0] = TEXT_COLOR_TRANSPARENT;
    color_gray[1] = TEXT_COLOR_OPTIONS_GRAY_FG;
    color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_SHADOW;
        
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(1));
    AddTextPrinterParameterized4(WIN_DESCRIPTION, FONT_NORMAL, 8, 1, 0, 0, color_gray, TEXT_SKIP_DRAW, OptionTextDescription());
    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_FULL);
}

static void DrawLeftSideOptionText(int selection, int y)
{
    u8 color_yellow[3];
    u8 color_gray[3];

    color_yellow[0] = TEXT_COLOR_TRANSPARENT;
    color_yellow[1] = TEXT_COLOR_WHITE;
    color_yellow[2] = TEXT_COLOR_OPTIONS_GRAY_FG;
    color_gray[0] = TEXT_COLOR_TRANSPARENT;
    color_gray[1] = TEXT_COLOR_WHITE;
    color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_SHADOW;

    if (CheckConditions(selection))
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, 8, y, 0, 0, color_yellow, TEXT_SKIP_DRAW, OptionTextRight(selection));
    else
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, 8, y, 0, 0, color_gray, TEXT_SKIP_DRAW, OptionTextRight(selection));
}

static void DrawRightSideChoiceText(const u8 *text, int x, int y, bool8 chosen, bool8 active)
{
    u8 color_red[3];
    u8 color_gray[3];

    if (active)
    {
        color_red[0] = TEXT_COLOR_TRANSPARENT;
        color_red[1] = TEXT_COLOR_OPTIONS_ORANGE_FG;
        color_red[2] = TEXT_COLOR_OPTIONS_GRAY_FG;
        color_gray[0] = TEXT_COLOR_TRANSPARENT;
        color_gray[1] = TEXT_COLOR_OPTIONS_WHITE;
        color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_FG;
    }
    else
    {
        color_red[0] = TEXT_COLOR_TRANSPARENT;
        color_red[1] = TEXT_COLOR_OPTIONS_WHITE;
        color_red[2] = TEXT_COLOR_OPTIONS_GRAY_FG;
        color_gray[0] = TEXT_COLOR_TRANSPARENT;
        color_gray[1] = TEXT_COLOR_OPTIONS_WHITE;
        color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_FG;
    }


    if (chosen)
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, x, y, 0, 0, color_red, TEXT_SKIP_DRAW, text);
    else
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, x, y, 0, 0, color_gray, TEXT_SKIP_DRAW, text);
}

static void DrawChoices(u32 id, int y) //right side draw function
{
    if (sItemFunctionsMain[id].drawChoices != NULL)
        sItemFunctionsMain[id].drawChoices(sOptions->sel[id], y);
}

static void HighlightModeMenuItem(void)
{
    int cursor = sOptions->visibleCursor;

    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(8, 232));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(cursor * Y_DIFF + 24, cursor * Y_DIFF + 40));
}

static bool8 ModeMenu_LoadGraphics(void) //Load all the tilesets, tilemaps, spritesheets, and palettes
{
    switch (sOptions->gfxLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(2, sOptionsPlusTiles, 0, 0, 0);
        sOptions->gfxLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sOptionsPlusTilemap, sBg2TilemapBuffer);
            sOptions->gfxLoadState++;
        }
        break;
    case 2:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(3, sScrollBgTiles, 0, 0, 0);
        sOptions->gfxLoadState++;
        break;
    case 3:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sScrollBgTilemap, sBg3TilemapBuffer);
            sOptions->gfxLoadState++;
        }
        break;
    case 4:
        LoadPalette(sOptionsPlusPalette, 64, 32);
        LoadPalette(sScrollBgPalette, 32, 32);
        sOptions->gfxLoadState++;
        break;
    default:
        sOptions->gfxLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void Task_ModeMenuWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_ModeMenuMainInput;
        SetGpuReg(REG_OFFSET_WIN0H, 0); // Idk man Im just trying to stop this stupid graphical bug from happening dont judge me
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG2);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 4);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        HighlightModeMenuItem();
        return;
    }
}

static void Task_ModeMenuMainInput(u8 taskId)
{
    u8 optionsToDraw = min(OPTIONS_ON_SCREEN , MenuItemCount());

    if (JOY_NEW(A_BUTTON))
    {
        if (sOptions->menuCursor == MenuItemCancel())
            gTasks[taskId].func = Task_ModeMenuSave;
    }
    // Exit the menu when the player presses B
    else if (JOY_NEW(SELECT_BUTTON) || JOY_NEW(START_BUTTON))
    {
        gTasks[taskId].func = Task_ModeMenuSave;
    }
    else if (JOY_REPEAT(DPAD_DOWN))
    {
        if (sOptions->visibleCursor == optionsToDraw-2) // don't advance visible cursor until scrolled to the bottom
        {
            if (++sOptions->menuCursor == MenuItemCount() - 1)
                sOptions->visibleCursor++;
            else
                ScrollMenu(0);
        }
        else
        {
            if (++sOptions->menuCursor >= MenuItemCount()-1) // Scroll all the way to the top.
            {
                sOptions->visibleCursor = optionsToDraw-2;
                sOptions->menuCursor = MenuItemCount() - optionsToDraw-1;
                ScrollAll(1);
                sOptions->visibleCursor = sOptions->menuCursor = 0;
            }
            else
            {
                sOptions->visibleCursor++;
            }
        }
        HighlightModeMenuItem();
        DrawDescriptionText();
    }
    else if (JOY_REPEAT(DPAD_UP))
    {
        if (sOptions->visibleCursor == NUM_OPTIONS_FROM_BORDER) // don't advance visible cursor until scrolled to the bottom
        {
            if (--sOptions->menuCursor == 0)
                sOptions->visibleCursor--;
            else
                ScrollMenu(1);
        }
        else
        {
            if (--sOptions->menuCursor < 0) // Scroll all the way to the bottom.
            {
                sOptions->visibleCursor = sOptions->menuCursor = optionsToDraw-2;
                ScrollAll(0);
                sOptions->visibleCursor = optionsToDraw-1;
                sOptions->menuCursor = MenuItemCount() - 1;
            }
            else
            {
                sOptions->visibleCursor--;
            }
        }
        HighlightModeMenuItem();
        DrawDescriptionText();
    }
    else if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        int cursor = sOptions->menuCursor;
        u8 previousOption = sOptions->sel[cursor];
        if (CheckConditions(cursor))
        {
            if (sItemFunctionsMain[cursor].processInput != NULL)
            {
                sOptions->sel[cursor] = sItemFunctionsMain[cursor].processInput(previousOption);

                //change selections based on defaults
                switch(sOptions->menuCursor)
                {
                    case 0: // 0 = first line => DEFAULT choice
                        //populate default options to the other mode lines
                        switch(sOptions->sel[cursor])
                        {
                            case MODE_NORMAL:
                                sOptions->sel[MENUITEM_MAIN_XPSHARE]      = XP_75;
                                sOptions->sel[MENUITEM_MAIN_STAT_CHANGER] = ACTIVE;
                                sOptions->sel[MENUITEM_MAIN_LEGENDARIES]  = YES;
                                sOptions->sel[MENUITEM_MAIN_DUPLICATES]   = NO;
                                break;
                            case MODE_HARD:
                                sOptions->sel[MENUITEM_MAIN_XPSHARE]      = XP_50;
                                sOptions->sel[MENUITEM_MAIN_STAT_CHANGER] = INACTIVE;
                                sOptions->sel[MENUITEM_MAIN_LEGENDARIES]  = NO;
                                sOptions->sel[MENUITEM_MAIN_DUPLICATES]   = NO;
                                break;
                            default:
                                break;
                        }
                        break;
                    case 1: //do nothing
                    case 2: //do nothing
                        break;
                    default: //set game mode to CUSTOM
                        sOptions->sel[MENUITEM_MAIN_DEFAULTS]   = MODE_CUSTOM;
                        break;
                }

                ReDrawAll();
                DrawDescriptionText();
            }

            if (previousOption != sOptions->sel[cursor])
                DrawChoices(cursor, sOptions->visibleCursor * Y_DIFF);
        }
    }
}

static void Task_ModeMenuSave(u8 taskId)
{
    //write in saveblock
    gSaveBlock2Ptr->modeDefault     = sOptions->sel[MENUITEM_MAIN_DEFAULTS];
    gSaveBlock2Ptr->modeAutosave    = sOptions->sel[MENUITEM_MAIN_AUTOSAVE];
    gSaveBlock2Ptr->modeBattleMode  = sOptions->sel[MENUITEM_MAIN_BATTLEMODE];
    gSaveBlock2Ptr->modeRandomizer  = sOptions->sel[MENUITEM_MAIN_RANDOMIZER];
    gSaveBlock2Ptr->modeXPShare     = sOptions->sel[MENUITEM_MAIN_XPSHARE];
    gSaveBlock2Ptr->modeStatChanger = sOptions->sel[MENUITEM_MAIN_STAT_CHANGER];
    gSaveBlock2Ptr->modeLegendaries = sOptions->sel[MENUITEM_MAIN_LEGENDARIES];
    gSaveBlock2Ptr->modeDuplicates  = sOptions->sel[MENUITEM_MAIN_DUPLICATES];

    //set flags/VARs
    VarSet(VAR_PIT_AUTOSAVE, sOptions->sel[MENUITEM_MAIN_AUTOSAVE]);

    if (sOptions->sel[MENUITEM_MAIN_BATTLEMODE] == MODE_DOUBLES)
        FlagSet(FLAG_DOUBLES_MODE);
    else
        FlagClear(FLAG_DOUBLES_MODE);

    if (sOptions->sel[MENUITEM_MAIN_RANDOMIZER] == RANDOM_ALL)
        FlagSet(FLAG_RANDOM_MODE);
    else
        FlagClear(FLAG_RANDOM_MODE);

    if (sOptions->sel[MENUITEM_MAIN_XPSHARE] == XP_50)
        FlagSet(FLAG_XPSHARE_50);
    else
        FlagClear(FLAG_XPSHARE_50);
    
    if (sOptions->sel[MENUITEM_MAIN_STAT_CHANGER] == ACTIVE)
        FlagSet(FLAG_STAT_CHANGER);
    else
        FlagClear(FLAG_STAT_CHANGER);

    if (sOptions->sel[MENUITEM_MAIN_LEGENDARIES] == NO)
        FlagSet(FLAG_NO_LEGENDARIES);
    else
        FlagClear(FLAG_NO_LEGENDARIES);

    if (sOptions->sel[MENUITEM_MAIN_DUPLICATES] == NO)
        FlagSet(FLAG_NO_DUPLICATES);
    else
        FlagClear(FLAG_NO_DUPLICATES);

    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gTasks[taskId].func = Task_ModeMenuWaitFadeAndExitGracefully;
}

static void Task_ModeMenuWaitFadeAndExitGracefully(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        BirchCase_Init(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        ModeMenu_FreeResources();
        DestroyTask(taskId);
    }
}

//menu navigation code
static void ScrollMenu(int direction)
{
    int menuItem, pos;
    u8 optionsToDraw = min(OPTIONS_ON_SCREEN, MenuItemCount());

    if (direction == 0) // scroll down
        menuItem = sOptions->menuCursor + NUM_OPTIONS_FROM_BORDER, pos = optionsToDraw - 1;
    else
        menuItem = sOptions->menuCursor - NUM_OPTIONS_FROM_BORDER, pos = 0;

    // Hide one
    ScrollWindow(WIN_OPTIONS, direction, Y_DIFF, PIXEL_FILL(0));
    // Show one
    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(0), 0, Y_DIFF * pos, 26 * 8, Y_DIFF);
    // Print
    DrawChoices(menuItem, pos * Y_DIFF);
    DrawLeftSideOptionText(menuItem, (pos * Y_DIFF) + 1);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
}

static void ScrollAll(int direction) // to bottom or top
{
    int i, y, menuItem, pos;
    int scrollCount;
    u8 optionsToDraw = min(OPTIONS_ON_SCREEN, MenuItemCount());

    scrollCount = MenuItemCount() - optionsToDraw;

    // Move items up/down
    ScrollWindow(WIN_OPTIONS, direction, Y_DIFF * scrollCount, PIXEL_FILL(1));

    // Clear moved items
    if (direction == 0)
    {
        y = optionsToDraw - scrollCount;
        if (y < 0)
            y = optionsToDraw;
        y *= Y_DIFF;
    }
    else
    {
        y = 0;
    }

    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(0), 0, y, 26 * 8, Y_DIFF * scrollCount);
    // Print new texts
    for (i = 0; i < scrollCount; i++)
    {
        if (direction == 0) // From top to bottom
            menuItem = MenuItemCount() - 1 - i, pos = optionsToDraw - 1 - i;
        else // From bottom to top
            menuItem = i, pos = i;
        DrawChoices(menuItem, pos * Y_DIFF);
        DrawLeftSideOptionText(menuItem, (pos * Y_DIFF) + 1);
    }
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
}

// Process Input functions ****GENERIC****
static int GetMiddleX(const u8 *txt1, const u8 *txt2, const u8 *txt3)
{
    int xMid;
    int widthLeft = GetStringWidth(1, txt1, 0);
    int widthMid = GetStringWidth(1, txt2, 0);
    int widthRight = GetStringWidth(1, txt3, 0);

    widthMid -= (198 - 104);
    xMid = (widthLeft - widthMid - widthRight) / 2 + 104;
    return xMid;
}

static int XOptions_ProcessInput(int x, int selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (++selection > (x - 1))
            selection = 0;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (--selection < 0)
            selection = (x - 1);
    }
    return selection;
}

static int ProcessInput_Options_Two(int selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
        selection ^= 1;

    return selection;
}

static int ProcessInput_Options_Three(int selection)
{
    return XOptions_ProcessInput(3, selection);
}

// Draw Choices functions ****GENERIC****
static void DrawModeMenuChoice(const u8 *text, u8 x, u8 y, u8 style, bool8 active)
{
    bool8 chosen = FALSE;
    if (style != 0)
        chosen = TRUE;

    DrawRightSideChoiceText(text, x, y+1, chosen, active);
}

static void ReDrawAll(void)
{
    u8 menuItem = sOptions->menuCursor - sOptions->visibleCursor;
    u8 i;
    u8 optionsToDraw = min(OPTIONS_ON_SCREEN, MenuItemCount());

    if (MenuItemCount() <= OPTIONS_ON_SCREEN) // Draw or delete the scrolling arrows based on options in the menu
    {
        if (sOptions->arrowTaskId != TASK_NONE)
        {
            RemoveScrollIndicatorArrowPair(sOptions->arrowTaskId);
            sOptions->arrowTaskId = TASK_NONE;
        }
    }
    else
    {
        if (sOptions->arrowTaskId == TASK_NONE)
            sOptions->arrowTaskId = sOptions->arrowTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 240 / 2, 20, 110, MenuItemCount() - 1, 110, 110, 0);

    }

    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(0));
    for (i = 0; i < optionsToDraw; i++)
    {
        DrawChoices(menuItem+i, i * Y_DIFF);
        DrawLeftSideOptionText(menuItem+i, (i * Y_DIFF) + 1);
    }
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
}

// Process Input functions ****SPECIFIC****
static const u8 sText_ModeNormal[]          = _("NORM");
static const u8 sText_ModeHard[]            = _("HARD");
static const u8 sText_ModeCustom[]          = _("CUST");
static const u8 sText_Autosave_Off[]        = _("OFF");
static const u8 sText_Autosave_5[]          = _("5FLRS");
static const u8 sText_Autosave_On[]         = _("ON");
static const u8 sText_BattleMode_Singles[]  = _("SINGLES");
static const u8 sText_BattleMode_Doubles[]  = _("DOUBLES");
static const u8 sText_Randomizer_Mons[]     = _("MONS");
static const u8 sText_Randomizer_All[]      = _("ALL");
static const u8 sText_XPShare_75[]          = _("NORMAL");
static const u8 sText_XPShare_50[]          = _("HARD");
static const u8 sText_StatChanger_On[]      = _("ACTIVE");
static const u8 sText_StatChanger_Off[]     = _("INACTIVE");
static const u8 sText_Choice_Yes[]          = _("YES");
static const u8 sText_Choice_No[]           = _("NO");

static void DrawChoices_Defaults(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_DEFAULTS);
    u8 styles[3] = {0};
    int xMid;

    styles[selection] = 1;
    xMid = GetMiddleX(sText_ModeNormal, sText_ModeHard, sText_ModeCustom);

    DrawModeMenuChoice(sText_ModeNormal, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_ModeHard, xMid, y, styles[1], active);
    DrawModeMenuChoice(sText_ModeCustom, GetStringRightAlignXOffset(1, sText_ModeCustom, 198), y, styles[2], active);
}

static void DrawChoices_Autosave(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_AUTOSAVE);
    u8 styles[3] = {0};
    int xMid;

    styles[selection] = 1;
    xMid = GetMiddleX(sText_Autosave_Off, sText_Autosave_5, sText_Autosave_On);

    DrawModeMenuChoice(sText_Autosave_Off, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_Autosave_5, xMid, y, styles[1], active);
    DrawModeMenuChoice(sText_Autosave_On, GetStringRightAlignXOffset(1, sText_Autosave_On, 198), y, styles[2], active);
}

static void DrawChoices_BattleMode(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_BATTLEMODE);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_BattleMode_Singles, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_BattleMode_Doubles, GetStringRightAlignXOffset(FONT_NORMAL, sText_BattleMode_Doubles, 198), y, styles[1], active);
}

static void DrawChoices_Randomizer(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_RANDOMIZER);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_Randomizer_Mons, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_Randomizer_All, GetStringRightAlignXOffset(FONT_NORMAL, sText_Randomizer_All, 198), y, styles[1], active);
}

static void DrawChoices_XPShare(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_XPSHARE);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_XPShare_75, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_XPShare_50, GetStringRightAlignXOffset(FONT_NORMAL, sText_XPShare_50, 198), y, styles[1], active);
}

static void DrawChoices_StatChanger(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_STAT_CHANGER);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_StatChanger_On, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_StatChanger_Off, GetStringRightAlignXOffset(FONT_NORMAL, sText_StatChanger_Off, 198), y, styles[1], active);
}

static void DrawChoices_Legendaries(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_LEGENDARIES);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_Choice_Yes, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_Choice_No, GetStringRightAlignXOffset(FONT_NORMAL, sText_Choice_No, 198), y, styles[1], active);
}

static void DrawChoices_Duplicates(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_DUPLICATES);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_Choice_Yes, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_Choice_No, GetStringRightAlignXOffset(FONT_NORMAL, sText_Choice_No, 198), y, styles[1], active);
}

// Background tilemap
#define TILE_TOP_CORNER_L 0x1A2 // 418
#define TILE_TOP_EDGE     0x1A3 // 419
#define TILE_TOP_CORNER_R 0x1A4 // 420
#define TILE_LEFT_EDGE    0x1A5 // 421
#define TILE_RIGHT_EDGE   0x1A7 // 423
#define TILE_BOT_CORNER_L 0x1A8 // 424
#define TILE_BOT_EDGE     0x1A9 // 425
#define TILE_BOT_CORNER_R 0x1AA // 426

static void DrawBgWindowFrames(void)
{
    // Description window
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1, 14,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2, 14, 27,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28, 14,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1, 15,  1,  4,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28, 15,  1,  4,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 19,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 19, 27,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 19,  1,  1,  7);

    CopyBgTilemapBufferToVram(1);
}

#define try_free(ptr) ({        \
    void ** ptr__ = (void **)&(ptr);   \
    if (*ptr__ != NULL)                \
        Free(*ptr__);                  \
})

static void ModeMenu_FreeResources(void)
{
    FreeAllWindowBuffers();
    ResetSpriteData();
    FREE_AND_SET_NULL(sOptions);
    try_free(sBg2TilemapBuffer);
    try_free(sBg3TilemapBuffer);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 4);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    HideBg(2);
    HideBg(3);
}