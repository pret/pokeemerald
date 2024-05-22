#include "gba/types.h"
#include "gba/defines.h"
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

// This code is based on Ghoulslash's excellent UI tutorial:
// https://www.pokecommunity.com/showpost.php?p=10441093

struct ModeMenuState
{
    // Save the callback to run when we exit: i.e. where do we want to go after closing the menu
    MainCallback savedCallback;
    // We will use this later to track some loading state
    u8 loadState;
    // Store the current dex mode, we'll have a mode that shows dex number/description as well as a few others
    u8 mode; // WIP
    // The sprite ID of the current mon icon, we need this so we can destroy the sprite when the user scrolls
    u8 monIconSpriteId; // WIP
    // The dex num of the currently displayed mon
    u16 monIconDexNum; // WIP
};

// GF window system passes window IDs around, so define this to avoid using magic numbers everywhere
enum WindowIds
{
    WIN_TOPBAR,
    WIN_OPTIONS,
    WIN_DESCRIPTION
};

// Menu items to browse through the list of options
enum MenuItems
{
    MENUITEM_MAIN_DEFAULTS,
    MENUITEM_MAIN_BATTLEMODE,
    MENUITEM_MAIN_RANDOMIZER,
    MENUITEM_MAIN_XPSHARE,
    MENUITEM_MAIN_STAT_CHANGER,
    MENUITEM_MAIN_LEGENDARIES,
    MENUITEM_MAIN_DUPLICATES,
    MENUITEM_MAIN_CANCEL,
    MENUITEM_MAIN_COUNT,
};

/*
 * Both of these can be pointers that live in EWRAM -- allocating the actual data on the heap will save precious WRAM
 * space since none of this data matters outside the context of our menu. We can easily cleanup when we're done. It's
 * worth noting that every time the game re-loads into the overworld, the heap gets nuked from orbit. However, it is
 * still good practice to clean up after oneself, so we will be sure to free everything before exiting.
 */
static EWRAM_DATA struct ModeMenuState *sModeMenuState = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

static const struct BgTemplate sModeMenuBgTemplates[] =
{
    //WIP not all needed!
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
    //u8 submenu;
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
//static void Task_ModeMenuWaitFadeAndBail(u8 taskId);
static void Task_ModeMenuWaitFadeAndExitGracefully(u8 taskId);

// Sample UI helper functions
void ModeMenu_Init(MainCallback callback);
//static bool8 ModeMenu_InitBgs(void);
//static void ModeMenu_FadeAndBail(void);
static bool8 ModeMenu_LoadGraphics(void);
static void ModeMenu_InitWindows(void);
static void ModeMenu_PrintUiButtonHints(void);
static void ModeMenu_PrintUiMonInfo(void);
static void ModeMenu_DrawMonIcon(u16 dexNum);
static void ModeMenu_FreeResources(void);
static int ProcessInput_Options_Two(int selection);
static int ProcessInput_Options_Three(int selection);
static void DrawChoices_Defaults(int selection, int y);
static void DrawChoices_BattleMode(int selection, int y);
static void DrawChoices_Randomizer(int selection, int y);
static void DrawChoices_XPShare(int selection, int y);
static void DrawChoices_StatChanger(int selection, int y);
static void DrawChoices_Legendaries(int selection, int y);
static void DrawChoices_Duplicates(int selection, int y);

// Menu draw and input functions
struct MainMenu
{
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
} static const sItemFunctionsMain[MENUITEM_MAIN_COUNT] =
{
    [MENUITEM_MAIN_DEFAULTS]     = {DrawChoices_Defaults,    ProcessInput_Options_Three},
    [MENUITEM_MAIN_BATTLEMODE]   = {DrawChoices_BattleMode,  ProcessInput_Options_Two},
    [MENUITEM_MAIN_RANDOMIZER]   = {DrawChoices_Randomizer,  ProcessInput_Options_Two},
    [MENUITEM_MAIN_XPSHARE]      = {DrawChoices_XPShare,     ProcessInput_Options_Two},
    [MENUITEM_MAIN_STAT_CHANGER] = {DrawChoices_StatChanger, ProcessInput_Options_Two},
    [MENUITEM_MAIN_LEGENDARIES]  = {DrawChoices_Legendaries, ProcessInput_Options_Two},
    [MENUITEM_MAIN_DUPLICATES]   = {DrawChoices_Duplicates,  ProcessInput_Options_Two},
    [MENUITEM_MAIN_CANCEL]       = {NULL, NULL},
};

// Menu left side option names text
static const u8 sText_Defaults[]    = _("DEFAULT");
static const u8 sText_BattleMode[]  = _("BATTLE MODE");
static const u8 sText_Randomizer[]  = _("RANDOMIZER");
static const u8 sText_XPShare[]     = _("XP SHARE");
static const u8 sText_StatChanger[] = _("STAT CHANGER");
static const u8 sText_Legendaries[] = _("LEGENDARIES");
static const u8 sText_Duplicates[]  = _("DUPLICATES");
static const u8 sText_Cancel[]      = _("CANCEL");

static const u8 *const sModeMenuItemsNamesMain[MENUITEM_MAIN_COUNT] =
{
    [MENUITEM_MAIN_DEFAULTS]     = sText_Defaults,
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
        case MENUITEM_MAIN_BATTLEMODE:     return TRUE;
        case MENUITEM_MAIN_RANDOMIZER:     return TRUE;
        case MENUITEM_MAIN_XPSHARE:        return TRUE;
        case MENUITEM_MAIN_STAT_CHANGER:   return TRUE;
        case MENUITEM_MAIN_LEGENDARIES:    return TRUE;
        case MENUITEM_MAIN_DUPLICATES:     return TRUE;
        case MENUITEM_MAIN_CANCEL:         return TRUE;
        case MENUITEM_MAIN_COUNT:          return TRUE;
    }
}

// Descriptions
static const u8 sText_Empty[]                   = _("");
static const u8 sText_Desc_Save[]               = _("Save your settings.");
static const u8 sText_Desc_Defaults[]           = _("Set all options based on defaults.");
static const u8 sText_Desc_BattleMode_Singles[] = _("Play only single battles.");
static const u8 sText_Desc_BattleMode_Doubles[] = _("Play only double battles.");
static const u8 sText_Desc_Randomizer_Mons[]    = _("Only randomize Pokémon species\n, trainers and item drops.");
static const u8 sText_Desc_Randomizer_All[]     = _("Also randomize abilities and\nmoves.");
static const u8 sText_Desc_XPShare_75[]         = _("Exp. Share gives 75 pct XP\nto party mons.");
static const u8 sText_Desc_XPShare_50[]         = _("Exp. Share gives 50 pct XP\nto party mons.");
static const u8 sText_Desc_StatChanger[]        = _("Enables the Stat. Changer\nin the party menu.");
static const u8 sText_Desc_Legendaries_On[]     = _("Legendaries can be found in\nthe Birch Bag.");
static const u8 sText_Desc_Legendaries_Off[]    = _("Legendaries can not be found\nin the Birch Bag.");
static const u8 sText_Desc_Duplicates_On[]      = _("Truly random. Duplicates are\npossible in the Birch Bag.");
static const u8 sText_Desc_Duplicates_Off[]     = _("Birch bag can't hold duplicates.");

static const u8 *const sModeMenuItemDescriptionsMain[MENUITEM_MAIN_COUNT][3] =
{
    [MENUITEM_MAIN_DEFAULTS]     = {sText_Desc_Defaults,            sText_Desc_Defaults,            sText_Empty},
    [MENUITEM_MAIN_BATTLEMODE]   = {sText_Desc_BattleMode_Singles,  sText_Desc_BattleMode_Doubles,  sText_Empty},
    [MENUITEM_MAIN_RANDOMIZER]   = {sText_Desc_Randomizer_Mons,     sText_Desc_Randomizer_All,      sText_Empty},
    [MENUITEM_MAIN_XPSHARE]      = {sText_Desc_XPShare_75,          sText_Desc_XPShare_50,          sText_Empty},
    [MENUITEM_MAIN_STAT_CHANGER] = {sText_Desc_StatChanger,         sText_Desc_StatChanger,         sText_Empty},
    [MENUITEM_MAIN_LEGENDARIES]  = {sText_Desc_Legendaries_On,      sText_Desc_Legendaries_Off,     sText_Empty},
    [MENUITEM_MAIN_DUPLICATES]   = {sText_Desc_Duplicates_On,       sText_Desc_Duplicates_Off,      sText_Empty},
    [MENUITEM_MAIN_CANCEL]       = {sText_Desc_Save,                sText_Empty,                    sText_Empty},
};

static const u8 *const OptionTextDescription(void)
{
    u8 menuItem = sOptions->menuCursor;
    u8 selection;

    //if (!CheckConditions(menuItem))
    //    return sModeMenuItemDescriptionsDisabledMain[menuItem];
    selection = sOptions->sel[menuItem];
    //if (menuItem == MENUITEM_MAIN_DEFAULTS || menuItem == MENUITEM_MAIN_DUPLICATES)
    //    selection = 0;
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
        ModeMenu_Init(CB2_ReturnToFieldWithOpenMenu);
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
    u32 i, taskId;

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
        sOptions->sel[MENUITEM_MAIN_DEFAULTS ]    = gSaveBlock2Ptr->modeDefault;
        sOptions->sel[MENUITEM_MAIN_BATTLEMODE]   = gSaveBlock2Ptr->modeBattleMode;
        sOptions->sel[MENUITEM_MAIN_RANDOMIZER]   = gSaveBlock2Ptr->modeRandomizer;
        sOptions->sel[MENUITEM_MAIN_XPSHARE]      = gSaveBlock2Ptr->modeXPShare;
        sOptions->sel[MENUITEM_MAIN_STAT_CHANGER] = gSaveBlock2Ptr->modeStatChanger;
        sOptions->sel[MENUITEM_MAIN_LEGENDARIES]  = gSaveBlock2Ptr->modeLegendaries;
        sOptions->sel[MENUITEM_MAIN_DUPLICATES]   = gSaveBlock2Ptr->modeDuplicates;

        //sOptions->submenu = MENU_MAIN;

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
    AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 105, 1, color, 0, sText_TopBar_Main);
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

static void DrawRightSideChoiceText(const u8 *text, int x, int y, bool8 choosen, bool8 active)
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


    if (choosen)
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

static bool8 ModeMenu_LoadGraphics(void) // Load all the tilesets, tilemaps, spritesheets, and palettes
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
        // WTF Archie???
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
        HighlightOptionMenuItem();
        return;
    }
}

static void Task_ModeMenuMainInput(u8 taskId)
{
    // WIP
    int i = 0;
    u8 optionsToDraw = min(OPTIONS_ON_SCREEN , MenuItemCount());

    if (JOY_NEW(A_BUTTON))
    {
        if (sOptions->menuCursor[sOptions->submenu] == MenuItemCancel())
            gTasks[taskId].func = Task_OptionMenuSave;
    }
    // Exit the menu when the player presses B
    else if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].func = Task_OptionMenuSave;
        /*
        //PlaySE(SE_PC_OFF);
        // Fade screen to black
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        // Replace ourself with the "exit gracefully" task function
        gTasks[taskId].func = Task_ModeMenuWaitFadeAndExitGracefully;*/
    }
    // User pressed or held DPAD_DOWN, scroll down through dex list
    else if (JOY_REPEAT(DPAD_DOWN))
    {
        if (sOptions->visibleCursor[sOptions->submenu] == optionsToDraw-2) // don't advance visible cursor until scrolled to the bottom
        {
            if (++sOptions->menuCursor[sOptions->submenu] == MenuItemCount() - 1)
                sOptions->visibleCursor[sOptions->submenu]++;
            else
                ScrollMenu(0);
        }
        else
        {
            if (++sOptions->menuCursor[sOptions->submenu] >= MenuItemCount()-1) // Scroll all the way to the top.
            {
                sOptions->visibleCursor[sOptions->submenu] = optionsToDraw-2;
                sOptions->menuCursor[sOptions->submenu] = MenuItemCount() - optionsToDraw-1;
                ScrollAll(1);
                sOptions->visibleCursor[sOptions->submenu] = sOptions->menuCursor[sOptions->submenu] = 0;
            }
            else
            {
                sOptions->visibleCursor[sOptions->submenu]++;
            }
        }
        HighlightOptionMenuItem();
        DrawDescriptionText();
    }
    // User pressed or held DPAD_UP, scroll up through dex list
    else if (JOY_REPEAT(DPAD_UP))
    {
        // WIP
        if (sOptions->visibleCursor[sOptions->submenu] == NUM_OPTIONS_FROM_BORDER) // don't advance visible cursor until scrolled to the bottom
        {
            if (--sOptions->menuCursor[sOptions->submenu] == 0)
                sOptions->visibleCursor[sOptions->submenu]--;
            else
                ScrollMenu(1);
        }
        else
        {
            if (--sOptions->menuCursor[sOptions->submenu] < 0) // Scroll all the way to the bottom.
            {
                sOptions->visibleCursor[sOptions->submenu] = sOptions->menuCursor[sOptions->submenu] = optionsToDraw-2;
                ScrollAll(0);
                sOptions->visibleCursor[sOptions->submenu] = optionsToDraw-1;
                sOptions->menuCursor[sOptions->submenu] = MenuItemCount() - 1;
            }
            else
            {
                sOptions->visibleCursor[sOptions->submenu]--;
            }
        }
        HighlightOptionMenuItem();
        DrawDescriptionText();
    }
}

static void Task_OptionMenuSave(u8 taskId)
{
    gSaveBlock2Ptr->modeDefault     = sOptions->sel[MENUITEM_MAIN_DEFAULTS];
    gSaveBlock2Ptr->modeBattleMode  = sOptions->sel[MENUITEM_MAIN_BATTLEMODE];
    gSaveBlock2Ptr->modeRandomizer  = sOptions->sel[MENUITEM_MAIN_RANDOMIZER];
    gSaveBlock2Ptr->modeXPShare     = sOptions->sel[MENUITEM_MAIN_XPSHARE];
    gSaveBlock2Ptr->modeStatChanger = sOptions->sel[MENUITEM_MAIN_STAT_CHANGER];
    gSaveBlock2Ptr->modeLegendaries = sOptions->sel[MENUITEM_MAIN_LEGENDARIES];
    gSaveBlock2Ptr->modeDuplicates  = sOptions->sel[MENUITEM_MAIN_DUPLICATES];

    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gTasks[taskId].func = Task_ModeMenuWaitFadeAndExitGracefully;
}

/*static void Task_ModeMenuWaitFadeAndBail(u8 taskId) // WIP needed?
{
    // Wait until the screen fades to black before we start doing cleanup
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sModeMenuState->savedCallback);
        ModeMenu_FreeResources();
        DestroyTask(taskId);
    }
}*/

static void Task_ModeMenuWaitFadeAndExitGracefully(u8 taskId)
{
    /*
     * This function is basically the same as Task_ModeMenuWaitFadeAndBail. However, for this sample we broke it out
     * because typically you might want to do something different if the user gracefully exits a menu vs if you got
     * booted from a menu due to heap allocation failure.
     */

    // E.g. you could do some other processing here

    // Wait until the screen fades to black before we start doing final cleanup
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sModeMenuState->savedCallback);
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
        menuItem = sOptions->menuCursor[sOptions->submenu] + NUM_OPTIONS_FROM_BORDER, pos = optionsToDraw - 1;
    else
        menuItem = sOptions->menuCursor[sOptions->submenu] - NUM_OPTIONS_FROM_BORDER, pos = 0;

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

// #################### continue?

// Draw Choices functions ****GENERIC****
static void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style, bool8 active)
{
    bool8 choosen = FALSE;
    if (style != 0)
        choosen = TRUE;

    DrawRightSideChoiceText(text, x, y+1, choosen, active);
}

static void DrawChoices_Options_Three(const u8 *const *const strings, int selection, int y, bool8 active)
{
    // WIP this is the code for four
    static const u8 choiceOrders[][3] =
    {
        {0, 1, 2},
        {0, 1, 2},
        {1, 2, 3},
        {1, 2, 3},
    };
    u8 styles[4] = {0};
    int xMid;
    const u8 *order = choiceOrders[selection];

    styles[selection] = 1;
    xMid = GetMiddleX(strings[order[0]], strings[order[1]], strings[order[2]]);

    DrawOptionMenuChoice(strings[order[0]], 104, y, styles[order[0]], active);
    DrawOptionMenuChoice(strings[order[1]], xMid, y, styles[order[1]], active);
    DrawOptionMenuChoice(strings[order[2]], GetStringRightAlignXOffset(1, strings[order[2]], 198), y, styles[order[2]], active);
}

static void ReDrawAll(void)
{
    u8 menuItem = sOptions->menuCursor[sOptions->submenu] - sOptions->visibleCursor[sOptions->submenu];
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
static const u8 sText_ModeNormal[]          = _("NORMAL");
static const u8 sText_ModeHard[]            = _("HARD");
static const u8 sText_ModeCustom[]          = _("CUSTOM");
static const u8 *const sTextModeStrings[]   = {sText_ModeNormal, sText_ModeHard, sText_ModeCustom};
static const u8 sText_BattleMode_Singles[]  = _("SINGLES");
static const u8 sText_BattleMode_Doubles[]  = _("DOUBLES");
static const u8 sText_Randomizer_Mons[]     = _("MONS");
static const u8 sText_Randomizer_All[]      = _("ALL");
static const u8 sText_XPShare_75[]          = _("75%");
static const u8 sText_XPShare_50[]          = _("50%");
static const u8 sText_StatChanger_On[]      = _("ACTIVE");
static const u8 sText_StatChanger_Off[]     = _("INACTIVE");
static const u8 sText_Choice_Yes[]          = _("YES");
static const u8 sText_Choice_No[]           = _("NO");

static void DrawChoices_Defaults(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_DEFAULTS);
    DrawChoices_Options_Three(sTextModeStrings, selection, y, active);
}

static void DrawChoices_BattleMode(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_BATTLEMODE);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_BattleMode_Singles, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_BattleMode_Doubles, GetStringRightAlignXOffset(FONT_NORMAL, sText_BattleMode_Doubles, 198), y, styles[1], active);
}

static void DrawChoices_Randomizer(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_RANDOMIZER);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_Randomizer_Mons, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_Randomizer_All, GetStringRightAlignXOffset(FONT_NORMAL, sText_Randomizer_All, 198), y, styles[1], active);
}

static void DrawChoices_XPShare(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_XPSHARE);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_XPShare_75, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_XPShare_50, GetStringRightAlignXOffset(FONT_NORMAL, sText_XPShare_50, 198), y, styles[1], active);
}

static void DrawChoices_StatChanger(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_STAT_CHANGER);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_StatChanger_On, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_StatChanger_Off, GetStringRightAlignXOffset(FONT_NORMAL, sText_StatChanger_Off, 198), y, styles[1], active);
}

static void DrawChoices_Legendaries(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_LEGENDARIES);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_Choice_Yes, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_Choice_No, GetStringRightAlignXOffset(FONT_NORMAL, sText_Choice_No, 198), y, styles[1], active);
}

static void DrawChoices_Duplicates(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_DUPLICATES);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_Choice_Yes, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_Choice_No, GetStringRightAlignXOffset(FONT_NORMAL, sText_Choice_No, 198), y, styles[1], active);
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
    //                     bg, tile,              x, y, width, height, palNum
    // Option Texts window
    //FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1,  2,  1,  1,  7);
    //FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2,  2, 26,  1,  7);
    //FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28,  2,  1,  1,  7);
    //FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1,  3,  1, 16,  7);
    //FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28,  3,  1, 16,  7);
    //FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 13,  1,  1,  7);
    //FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 13, 26,  1,  7);
    //FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 13,  1,  1,  7);

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

/*static bool8 ModeMenu_InitBgs(void)
{
   
    const u32 TILEMAP_BUFFER_SIZE = (1024 * 2);

    // BG registers may have scroll values left over from the previous screen. Reset all scroll values to 0.
    ResetAllBgsCoordinates();

    // Allocate our tilemap buffer on the heap
    sBg1TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    if (sBg1TilemapBuffer == NULL)
    {
        // Bail if the allocation fails
        return FALSE;
    }

    
    ResetBgsAndClearDma3BusyFlags(0);

   
    InitBgsFromTemplates(0, sModeMenuBgTemplates, NELEMS(sModeMenuBgTemplates));

    // Set the BG manager to use our newly allocated tilemap buffer for BG1's tilemap
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);

   
    ScheduleBgCopyTilemapToVram(1);

    // Set reg DISPCNT to show BG0, BG1. Try commenting these out to see what happens.
    ShowBg(0);
    ShowBg(1);

    return TRUE;
}*/

/*static void ModeMenu_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_ModeMenuWaitFadeAndBail, 0);
    SetVBlankCallback(ModeMenu_VBlankCB);
    SetMainCallback2(ModeMenu_MainCB);
}*/

/*static void ModeMenu_InitWindows(void)
{
    InitWindows(sModeMenuWindowTemplates);

    // Marks all text printers as inactive. Basically just setting flags. That's it.
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);
    FillWindowPixelBuffer(WIN_UI_HINTS, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    FillWindowPixelBuffer(WIN_MON_INFO, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(WIN_UI_HINTS);
    PutWindowTilemap(WIN_MON_INFO);
    CopyWindowToVram(WIN_UI_HINTS, COPYWIN_FULL);
    CopyWindowToVram(WIN_MON_INFO, COPYWIN_FULL);
}*/

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