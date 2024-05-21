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
static void Task_ModeMenuWaitFadeAndBail(u8 taskId);
static void Task_ModeMenuWaitFadeAndExitGracefully(u8 taskId);

// Sample UI helper functions
void ModeMenu_Init(MainCallback callback);
static bool8 ModeMenu_InitBgs(void);
static void ModeMenu_FadeAndBail(void);
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
        if (OptionsMenu_LoadGraphics() == TRUE)
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

static bool8 OptionsMenu_LoadGraphics(void) // Load all the tilesets, tilemaps, spritesheets, and palettes
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

// original code ##############################

static void Task_ModeMenuWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_ModeMenuMainInput;
    }
}

static void Task_ModeMenuMainInput(u8 taskId)
{
    // Exit the menu when the player presses B
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_PC_OFF);
        // Fade screen to black
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        // Replace ourself with the "exit gracefully" task function
        gTasks[taskId].func = Task_ModeMenuWaitFadeAndExitGracefully;
    }
    // User pressed or held DPAD_DOWN, scroll down through dex list
    if (JOY_REPEAT(DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        // Destroy the old mon sprite, update the selected dex num, and draw the new sprite
        // WIP
        FreeAndDestroyMonIconSprite(&gSprites[sModeMenuState->monIconSpriteId]);
        if (sModeMenuState->monIconDexNum < NATIONAL_DEX_MEW)
        {
            sModeMenuState->monIconDexNum++;
        }
        else
        {
            // Wrap dex number around to Bulbasaur when user presses down on Mew
            sModeMenuState->monIconDexNum = NATIONAL_DEX_BULBASAUR;
        }
        ModeMenu_DrawMonIcon(sModeMenuState->monIconDexNum);
        ModeMenu_PrintUiMonInfo();
    }
    // User pressed or held DPAD_UP, scroll up through dex list
    if (JOY_REPEAT(DPAD_UP))
    {
        // WIP
        PlaySE(SE_SELECT);
        // Destroy the old mon sprite, update the selected dex num, and draw the new sprite
        FreeAndDestroyMonIconSprite(&gSprites[sModeMenuState->monIconSpriteId]);
        if (sModeMenuState->monIconDexNum > NATIONAL_DEX_BULBASAUR)
        {
            sModeMenuState->monIconDexNum--;
        }
        else
        {
            // Wrap dex number around to Mew when user presses Up on Bulbasaur
            sModeMenuState->monIconDexNum = NATIONAL_DEX_MEW;
        }
        ModeMenu_DrawMonIcon(sModeMenuState->monIconDexNum);
        ModeMenu_PrintUiMonInfo();
    }
    // User pressed A, cycle to next dex mode
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        if (sModeMenuState->mode == MODE_OTHER)
        {
            // Wrap back around to Info after the last mode
            sModeMenuState->mode = MODE_INFO;
        }
        else
        {
            sModeMenuState->mode++;
        }
        ModeMenu_PrintUiButtonHints();
        ModeMenu_PrintUiMonInfo();
    }
}

static void Task_ModeMenuWaitFadeAndBail(u8 taskId)
{
    // Wait until the screen fades to black before we start doing cleanup
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sModeMenuState->savedCallback);
        ModeMenu_FreeResources();
        DestroyTask(taskId);
    }
}

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

static bool8 ModeMenu_InitBgs(void)
{
    /*
     * 1 screenblock is 2 KiB, so that should be a good size for our tilemap buffer. We don't need more than one
     * screenblock since BG1's size setting is 0, which tells the GBA we are using a 32x32 tile background:
     *      (32 tile * 32 tile * 2 bytes/tile = 2048)
     * For more info on tilemap entries and how they work:
     * https://www.coranac.com/tonc/text/regbg.htm#sec-map
     */
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

    /*
     * Clear all BG-related data buffers and mark DMAs as ready. Also resets the BG and mode bits of reg DISPCNT to 0.
     * This will effectively turn off all BGs and activate Mode 0.
     * LTODO explain the underlying sDmaBusyBitfield here
     */
    ResetBgsAndClearDma3BusyFlags(0);

    /*
     * Use the BG templates defined at the top of the file to init various cached BG attributes. These attributes will
     * be used by the various load methods to correctly setup VRAM per the user template. Some of the attributes can
     * also be pushed into relevant video regs using the provided functions in `bg.h'
     */
    InitBgsFromTemplates(0, sModeMenuBgTemplates, NELEMS(sModeMenuBgTemplates));

    // Set the BG manager to use our newly allocated tilemap buffer for BG1's tilemap
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);

    /*
     * Schedule to copy the tilemap buffer contents (remember we zeroed it out earlier) into VRAM on the next VBlank.
     * Right now, BG1 will just use Tile 0 for every tile. We will change this once we load in our true tilemap
     * values from sModeMenuTilemap.
     */
    ScheduleBgCopyTilemapToVram(1);

    // Set reg DISPCNT to show BG0, BG1. Try commenting these out to see what happens.
    ShowBg(0);
    ShowBg(1);

    return TRUE;
}

static void ModeMenu_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_ModeMenuWaitFadeAndBail, 0);

    /*
     * Set callbacks to ours while we wait for the fade to finish, then our above task will cleanup and swap the
     * callbacks back to the one we saved earlier (which should re-load the overworld)
     */
    SetVBlankCallback(ModeMenu_VBlankCB);
    SetMainCallback2(ModeMenu_MainCB);
}

static bool8 ModeMenu_LoadGraphics(void)
{
    switch (sModeMenuState->loadState)
    {
    case 0:
        /*
         * Reset leftover temp buffers from any previous code that used them to load graphics. The loading code in
         * `menu.c' basically saves pointers to the decompression buffers after it copies to VRAM. Here, we just reset
         * all the pointers to NULL and set the tracking index to 0. This obviously assumes the previous screen freed
         * the buffers for us.
         */
        ResetTempTileDataBuffers();

        /*
         * Decompress our tileset and copy it into VRAM using the parameters we set in the BgTemplates at the top -- we
         * pass 1 for the bgId so it uses the charblock setting from the BG1 template.
         * The size, offset, mode parameters are set to 0:
         *
         *      Size is 0 because that tells the function to set the size dynamically based on the decompressed data.
         *
         *      Offset is 0 because we want to tiles loaded right at whatever charblock we set in the BgTemplate.
         *
         *      Mode is 0 because we are copying tiles and not a tilemap, and 0 tells the bg library to use the tile
         *      loading code as opposed to the tilemap loading code (unfortunately GameFreak didn't provide a mode
         *      enum -- it was probably a preprocessor define in the original game code. So you have to look at the
         *      library functions to figure out what the mode values mean).
         *
         * `menu.c' also has a alternative function `DecompressAndLoadBgGfxUsingHeap', which does the same thing but
         * automatically frees the decompression buffer for you. If you want, you can use that here instead and remove
         * the `ResetTempTileDataBuffers' call above, since it doesn't use the temp tile data buffers.
         */
        DecompressAndCopyTileDataToVram(1, sModeMenuTiles, 0, 0, 0);
        sModeMenuState->loadState++;
        break;
    case 1:
        /*
         * Each frame, keep trying to free the temp data buffer we used last frame to copy the tile data into VRAM. We
         * have to do a poll here because this free may not occur depending on the state of the DMA manager. If instead
         * you chose to load graphics using the alternative `DecompressAndLoadBgGfxUsingHeap', you can remove this call
         * and wrapping if statement since the polling/freeing is handled for you under the hood.
         * LTODO explain this better, like above sDmaBusyBitfield is being used here, this might be confusing
         */
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            /*
             * This basically just wraps the LZ77UnCompWram system call. It reads and decompresses whatever data is
             * provided in the `src' (argument 1), and writes the decompressed data to a WRAM location given in `dest'
             * (argument 2). In our case `dest' is just the tilemap buffer we heap-allocated earlier.
             */
            LZDecompressWram(sModeMenuTilemap, sBg1TilemapBuffer);
            sModeMenuState->loadState++;
        }
        break;
    case 2:
        /*
         * Copy our palette into the game's BG palette buffer, slot 0 -- this step does not directly get the palette
         * into VRAM. That only happens during VBlank if the current callback specifies a buffer transfer.
         */
        LoadPalette(sModeMenuPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        /*
         * Copy the message box palette into BG palette buffer, slot 15. Our window is set to use palette 15 and our
         * text color constants are defined assuming we are indexing into this palette.
         */
        LoadPalette(gMessageBox_Pal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        sModeMenuState->loadState++;
    default:
        sModeMenuState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void ModeMenu_InitWindows(void)
{
    /*
     * Initialize windows from the window templates we specified above. This makes two important allocations:
     *
     * 1) It allocates a tilemap buffer for the window tilemap, the size of which is based on the screen size setting
     *    specified in the BgTemplate (we didn't set one, so it defaults to 0, see BGXCNT register documentation for
     *    more details on screen sizes). For this UI, the size setting is 0 which just means use a single screen. We
     *    only allocate a single tilemap for the entire BG layer. So if you have multiple windows on the same BG, they
     *    will all share the same tilemap buffer.
     *
     * 2) It allocates one `tileData' buffer (often also called the pixel buffer in the code) for each window. *Each
     *    window has its own pixel buffer.* This is the buffer into which we actually draw text, and it gets copied upon
     *    request to the tile area of VRAM based on the BG charblock and window baseblock.
     *
     * It's also worth noting that the window API allows you to allocate and set your own tilemap buffer for the window
     * BG layer, just like we did earlier for BG1. However, it's better to just let the window API do the allocation and
     * setup for you through `InitWindows()' -- just make sure to call `FreeAllWindowBuffers()' before closing up shop
     * to return your memory.
     */
    InitWindows(sModeMenuWindowTemplates);

    // Marks all text printers as inactive. Basically just setting flags. That's it.
    DeactivateAllTextPrinters();

    /*
     * Schedule a copy of BG0 tilemap buffer to VRAM. This buffer was allocated for us by `InitWindows()' since we
     * specified a window on BG0 and had not yet set that layer's tilemap buffer. Note that the buffer was also zeroed
     * for us by `InitWindows()'
     */
    ScheduleBgCopyTilemapToVram(0);

    /*
     * Fill each entire window pixel buffer (i.e. window.tileData) with the given value. In this case, fill it with 0s
     * to make the window completely transparent. We will draw text into the window pixel buffer later.
     */
    FillWindowPixelBuffer(WIN_UI_HINTS, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    FillWindowPixelBuffer(WIN_MON_INFO, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    /*
     * Write an increasing sequence of tile indexes into each window's tilemap buffer, based on the offset provided by
     * the window.baseBlock. Why? Because the window text will be drawn onto the tiles themselves. So we just want each
     * subsequent tilemap entry to point to the next tile in VRAM. That way, we can treat the tiles as a
     * pseudo-framebuffer and render our text however we want. If you dive deeper into the implementation of
     * `PutWindowTilemap', you will see that it takes some fancy calculation to determine which entries in the
     * tilemap buffer we actually need to modify (because we are mapping from GameFreak windows, which are logically 2D,
     * to VRAM locations, which in reality is basically a 1D array). I will leave exploration of the inner-workings of
     * this function as an exercise to the reader.
     */
    PutWindowTilemap(WIN_UI_HINTS);
    PutWindowTilemap(WIN_MON_INFO);

    /*
     * Copy (well, schedule to copy) each window into VRAM using DMA3 under the hood. The COPYWIN_FULL argument means we
     * copy BOTH the tilemap buffer (which recall is just an incrementing sequence of references into our tile canvas)
     * and the tiles themselves. Typically when updating text on a window, you only need to copy the tile canvas (i.e.
     * using COPYWIN_GFX) since the tilemap should never change. But to init the window we need to get both into VRAM.
     */
    CopyWindowToVram(WIN_UI_HINTS, COPYWIN_FULL);
    CopyWindowToVram(WIN_MON_INFO, COPYWIN_FULL);
}

static const u8 sText_ModeMenuButtonHint1[] = _("{DPAD_UPDOWN}Change POKéMON");
static const u8 sText_ModeMenuButtonHint2[] = _("{A_BUTTON}Mode: {STR_VAR_1}");
static const u8 sText_ModeMenuButtonHint3[] = _("{B_BUTTON}Exit");
static void ModeMenu_PrintUiButtonHints(void)
{
    /*
     * Fill the window with transparent. You normally want to do this before drawing new text to remove the old text
     * from the window (otherwise you'll see strange remnants of the previous text's pixels underneath your new text).
     */
    FillWindowPixelBuffer(WIN_UI_HINTS, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    // Copy the current mode name into a temp string variable
    StringCopy(gStringVar1, sModeNames[sModeMenuState->mode]);

    /*
     * `StringExpandPlaceholders' takes the src string, expands all placeholders (i.e. those bits in braces that look
     * like {FOO}), then copies the expanded string into dest. The {STR_VAR_1} placeholder will expand to the current
     * contents of temp string gStringVar1, which is very useful for constructing dynamic strings. Note that above we
     * saved the mode name into gStringVar1.
     */
    StringExpandPlaceholders(gStringVar2, sText_ModeMenuButtonHint2);

    /*
     * Use the text printing system to add text to this window. We set the speed value to TEXT_SKIP_DRAW to tell the
     * printer to draw into the pixel buffer but skip the actual VRAM copy. Why? Because we want to wait until all the
     * text is rendered before we actually copy to VRAM and make the text visible. This prevents flickering from
     * occuring (for a technical reason explained below). Try changing the speed parameter TEXT_SKIP_DRAW to 0 (which
     * tells the text printer to copy to VRAM on the next VBlank) and observe the slight flicker that occurs.
     *
     * The reason you see flickering when drawing lots of text without setting TEXT_SKIP_DRAW is because without this,
     * each `AddTextPrinterX' call actually schedules a separate DMA transfer of the partially draw window pixel buffer.
     * Since the each transfer is transfering the entire buffer, if you queue up a lot of these by calling
     * `AddTextPrinterX' a lot of separate times, getting everything into VRAM is going to take multiple frames, and you
     * will see the partially drawn text show up as each subsequent DMA transfer finishes.
     */
    AddTextPrinterParameterized4(WIN_UI_HINTS, FONT_NORMAL, 0, 3, 0, 0, sModeMenuWindowFontColors[FONT_WHITE],
        TEXT_SKIP_DRAW, sRegionNameKanto);
    AddTextPrinterParameterized4(WIN_UI_HINTS, FONT_SMALL, 47, 0, 0, 0, sModeMenuWindowFontColors[FONT_WHITE],
        TEXT_SKIP_DRAW, sText_ModeMenuButtonHint1);
    AddTextPrinterParameterized4(WIN_UI_HINTS, FONT_SMALL, 47, 10, 0, 0, sModeMenuWindowFontColors[FONT_WHITE],
        TEXT_SKIP_DRAW, gStringVar2);
    AddTextPrinterParameterized4(WIN_UI_HINTS, FONT_SMALL, 47, 20, 0, 0, sModeMenuWindowFontColors[FONT_WHITE],
        TEXT_SKIP_DRAW, sText_ModeMenuButtonHint3);

    /*
     * Explicitly copy to VRAM now that all text is drawn into the window pixel buffer. We use COPYWIN_GFX here since no
     * changes were made to the BG tilemap, so no need to copy it again (recall that GF windows use tile rendering).
     */
    CopyWindowToVram(WIN_UI_HINTS, COPYWIN_GFX);
}

static const u8 sText_ModeMenuMonInfoSpecies[] = _("{NO}{STR_VAR_1} {STR_VAR_2}");
static const u8 sText_ModeMenuMonStats[] = _("Put stats info here");
static const u8 sText_ModeMenuMonOther[] = _("Put other info here");
static void ModeMenu_PrintUiMonInfo(void)
{
    u16 speciesId = NationalPokedexNumToSpecies(sModeMenuState->monIconDexNum);

    // Clear the window before drawing new text
    FillWindowPixelBuffer(WIN_MON_INFO, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    switch (sModeMenuState->mode)
    {
    case MODE_INFO:
        /*
         * Use the string manipulation library to put the National Dex num, species name, and dex description into
         * strings, ready to be drawn.
         */
        ConvertIntToDecimalStringN(gStringVar1, sModeMenuState->monIconDexNum, STR_CONV_MODE_LEADING_ZEROS, 3);
        StringCopy(gStringVar2, GetSpeciesName(speciesId));
        StringExpandPlaceholders(gStringVar3, sText_ModeMenuMonInfoSpecies);
        StringCopy(gStringVar4, GetSpeciesPokedexDescription(speciesId));

        // The window drawing code here works just like in `ModeMenu_PrintUiButtonHints'
        AddTextPrinterParameterized4(WIN_MON_INFO, FONT_SHORT, 5, 3, 0, 0, sModeMenuWindowFontColors[FONT_BLACK],
            TEXT_SKIP_DRAW, gStringVar3);
        AddTextPrinterParameterized4(WIN_MON_INFO, FONT_SMALL, 5, 25, 0, 0, sModeMenuWindowFontColors[FONT_BLACK],
            TEXT_SKIP_DRAW, gStringVar4);
        break;
    case MODE_STATS:
        AddTextPrinterParameterized4(WIN_MON_INFO, FONT_SHORT, 5, 3, 0, 0, sModeMenuWindowFontColors[FONT_BLACK],
            TEXT_SKIP_DRAW, sText_ModeMenuMonStats);
        break;
    case MODE_OTHER:
        AddTextPrinterParameterized4(WIN_MON_INFO, FONT_SHORT, 5, 3, 0, 0, sModeMenuWindowFontColors[FONT_BLACK],
            TEXT_SKIP_DRAW, sText_ModeMenuMonOther);
        break;
    default:
        break;
    }

    // Copy pixel buffer to VRAM now that we are done drawing text
    CopyWindowToVram(WIN_MON_INFO, COPYWIN_GFX);
}

static void ModeMenu_DrawMonIcon(u16 dexNum)
{
    // Convert the dex number to a species ID.
    u16 speciesId = NationalPokedexNumToSpecies(dexNum);

    /*
     * Create a new mon icon sprite and save off its sprite ID so we can easily free it when we need to update which
     * icon is displayed. We set the sprite callback to a preset supplied by the GF's mon icon code. This callback
     * updates the little bounce animation of the icon. `CreateMonIcon' handles all the details of sprite initialization
     * for us. Feel free to dive into the implementation to see the gory details.
     */
    sModeMenuState->monIconSpriteId = CreateMonIcon(speciesId, SpriteCB_MonIcon, MON_ICON_X, MON_ICON_Y, 4, 0);
    // Set prio to 0 so the icon sprite draws on top of everything
    gSprites[sModeMenuState->monIconSpriteId].oam.priority = 0;
}

static void ModeMenu_FreeResources(void)
{
    // Free our data struct and our BG1 tilemap buffer
    if (sModeMenuState != NULL)
    {
        Free(sModeMenuState);
    }
    if (sBg1TilemapBuffer != NULL)
    {
        Free(sBg1TilemapBuffer);
    }
    // Free all allocated tilemap and pixel buffers associated with the windows.
    FreeAllWindowBuffers();
    // Reset all sprite data
    ResetSpriteData();
}