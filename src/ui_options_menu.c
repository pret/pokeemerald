#include "global.h"
#include "main.h"
#include "scanline_effect.h"
#include "palette.h"
#include "sprite.h"
#include "task.h"
#include "malloc.h"
#include "bg.h"
#include "gpu_regs.h"
#include "window.h"
#include "text.h"
#include "text_window.h"
#include "international_string_util.h"
#include "strings.h"
#include "gba/m4a_internal.h"
#include "constants/rgb.h"
#include "menu_helpers.h"
#include "decompress.h"
#include "ui_options_menu.h"
#include "event_data.h"
#include "string_util.h"

// Window Ids
enum
{
    WIN_TOPBAR,
    WIN_OPTIONS,
    WIN_DESCRIPTION
};

enum MenuIds
{
    MENU_PIT,
    MENU_VANILLA,
    MENU_COUNT
};

// Menu items
enum MenuItems_Pit
{
    MENUITEM_PIT_AUTOSAVE,
    MENUITEM_PIT_RANDOM_MAPS,
    MENUITEM_PIT_RANDOM_MUSIC,
    MENUITEM_PIT_FOLLOWMONS,
    MENUITEM_PIT_CANCEL,
    MENUITEM_PIT_COUNT,
};

enum MenuItems_Vanilla
{
    MENUITEM_VANILLA_TEXTSPEED,
    MENUITEM_VANILLA_BATTLESCENE,
    MENUITEM_VANILLA_BATTLESTYLE,
    MENUITEM_VANILLA_SOUND,
    MENUITEM_VANILLA_BUTTONMODE,
    MENUITEM_VANILLA_CANCEL,
    MENUITEM_VANILLA_COUNT,
};

static const struct WindowTemplate sOptionsMenuWinTemplates[] =
{
    {//WIN_TOPBAR
        .bg = 1,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 2
    },
    {//WIN_OPTIONS
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 26,
        .height = 10,
        .paletteNum = 1,
        .baseBlock = 62
    },
    {//WIN_DESCRIPTION
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

static const struct BgTemplate sOptionsMenuBgTemplates[] =
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

struct OptionsMenu
{
    u16 submenu;
    u8 sel_pit[MENUITEM_PIT_COUNT];
    u8 sel_van[MENUITEM_VANILLA_COUNT];
    int menuCursor[MENU_COUNT];
    int visibleCursor[MENU_COUNT];
    u8 arrowTaskId;
    u8 gfxLoadState;
};

#define Y_DIFF 16 // Difference in pixels between items.
#define OPTIONS_ON_SCREEN 5
#define NUM_OPTIONS_FROM_BORDER 1

// local functions
static void MainCB2(void);
static void VBlankCB(void);
static void DrawTopBarText(void); //top Option text
static void DrawLeftSideOptionText(int selection, int y);
static void DrawRightSideChoiceText(const u8 *str, int x, int y, bool8 chosen, bool8 active);
static void DrawOptionsMenuTexts(void); //left side text;
static void DrawChoices(u32 id, int y); //right side draw function
static void HighlightOptionsMenuItem(void);
static void Task_OptionsMenuFadeIn(u8 taskId);
static void Task_OptionsMenuProcessInput(u8 taskId);
static void Task_OptionsMenuSave(u8 taskId);
static void Task_OptionsMenuFadeOut(u8 taskId);
static void ScrollMenu(int direction);
static void ScrollAll(int direction); // to bottom or top
static int GetMiddleX(const u8 *txt1, const u8 *txt2, const u8 *txt3);
static int XOptions_ProcessInput(int x, int selection);
static int ProcessInput_Options_Two(int selection);
static int ProcessInput_Options_Three(int selection);
static int ProcessInput_Options_Four(int selection);
static int ProcessInput_FrameType(int selection);
static const u8 *const OptionTextDescription(void);
static const u8 *const OptionTextRight(u8 menuItem);
static bool8 CheckConditions(int selection);
static u8 MenuItemCount(void);
static u8 MenuItemCancel(void);
static void DrawDescriptionText(void);
static void DrawOptionsMenuChoice(const u8 *text, u8 x, u8 y, u8 style, bool8 active);
static void ReDrawAll(void);
static void DrawChoices_TextSpeed(int selection, int y);
static void DrawChoices_Autosave(int selection, int y);
static void DrawChoices_RandomMaps(int selection, int y);
static void DrawChoices_RandomMusic(int selection, int y);
static void DrawChoices_FollowMons(int selection, int y);
static void DrawChoices_BattleScene(int selection, int y);
static void DrawChoices_BattleStyle(int selection, int y);
static void DrawChoices_Sound(int selection, int y);
static void DrawChoices_ButtonMode(int selection, int y);
static void DrawChoices_FrameType(int selection, int y);
static void DrawBgWindowFrames(void);

// EWRAM vars
EWRAM_DATA static struct OptionsMenu *sOptions = NULL;
static EWRAM_DATA u8 *sBg2TilemapBuffer = NULL;
static EWRAM_DATA u8 *sBg3TilemapBuffer = NULL;

// const data
static const u8 sEqualSignGfx[] = INCBIN_U8("graphics/interface/option_menu_equals_sign.4bpp"); // note: this is only used in the Japanese release
static const u16 sOptionsMenuBg_Pal[] = {RGB(17, 18, 31)};
static const u16 sOptionsMenuText_Pal[] = INCBIN_U16("graphics/interface/option_menu_text_custom.gbapal");
static const u8 sLR_ButtonGfx[]      = INCBIN_U8("graphics/ui_menu/r_button.4bpp");

static const u32 sOptionsMenuTiles[] = INCBIN_U32("graphics/ui_options_menu/options_menu_tiles.4bpp.lz");
static const u16 sOptionsMenuPalette[] = INCBIN_U16("graphics/ui_options_menu/options_menu_tiles.gbapal");
static const u32 sOptionsMenuTilemap[] = INCBIN_U32("graphics/ui_options_menu/options_menu_tiles.bin.lz");

// Scrolling Background
static const u32 sScrollBgTiles[] = INCBIN_U32("graphics/ui_options_menu/scroll_tiles.4bpp.lz");
static const u32 sScrollBgTilemap[] = INCBIN_U32("graphics/ui_options_menu/scroll_tiles.bin.lz");
static const u16 sScrollBgPalette[] = INCBIN_U16("graphics/ui_options_menu/scroll_tiles.gbapal");

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

// Menu draw and input functions
struct Menu_Pit// MENU_PIT
{
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
} static const sItemFunctionsPit[MENUITEM_PIT_COUNT] =
{
    [MENUITEM_PIT_AUTOSAVE]     = {DrawChoices_Autosave,    ProcessInput_Options_Three},
    [MENUITEM_PIT_RANDOM_MAPS]  = {DrawChoices_RandomMaps,  ProcessInput_Options_Two},
    [MENUITEM_PIT_RANDOM_MUSIC] = {DrawChoices_RandomMusic,  ProcessInput_Options_Two},
    [MENUITEM_PIT_FOLLOWMONS]   = {DrawChoices_FollowMons,  ProcessInput_Options_Two},
    [MENUITEM_PIT_CANCEL]       = {NULL, NULL},
};

struct Menu_Vanilla// MENU_VANILLA
{
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
} static const sItemFunctionsVan[MENUITEM_VANILLA_COUNT] =
{
    [MENUITEM_VANILLA_TEXTSPEED]    = {DrawChoices_TextSpeed,   ProcessInput_Options_Three},
    [MENUITEM_VANILLA_BATTLESCENE]  = {DrawChoices_BattleScene, ProcessInput_Options_Two},
    [MENUITEM_VANILLA_BATTLESTYLE]  = {DrawChoices_BattleStyle, ProcessInput_Options_Two},
    [MENUITEM_VANILLA_SOUND]        = {DrawChoices_Sound,       ProcessInput_Options_Two},
    [MENUITEM_VANILLA_BUTTONMODE]   = {DrawChoices_ButtonMode,  ProcessInput_Options_Three},
    [MENUITEM_VANILLA_CANCEL]       = {NULL, NULL},
};

// Menu left side option names text

static const u8 sText_Autosave[]    = _("AUTOSAVE");
static const u8 sText_RandomMaps[]  = _("RANDOM MAPS");
static const u8 sText_RandomMusic[] = _("RANDOM MUSIC");
static const u8 sText_FollowMons[]  = _("FOLLOWER MONS");
static const u8 sText_Cancel[]      = _("SAVE & LEAVE");

static const u8 *const sOptionsMenuItemsNamesPit[MENUITEM_PIT_COUNT] =
{
    [MENUITEM_PIT_AUTOSAVE]     = sText_Autosave,
    [MENUITEM_PIT_RANDOM_MAPS]  = sText_RandomMaps,
    [MENUITEM_PIT_RANDOM_MUSIC] = sText_RandomMusic,
    [MENUITEM_PIT_FOLLOWMONS]   = sText_FollowMons,
    [MENUITEM_PIT_CANCEL]       = sText_Cancel,
};

static const u8 *const sOptionsMenuItemsNamesVan[MENUITEM_VANILLA_COUNT] =
{
    [MENUITEM_VANILLA_TEXTSPEED]   = gText_TextSpeed,
    [MENUITEM_VANILLA_BATTLESCENE] = gText_BattleScene,
    [MENUITEM_VANILLA_BATTLESTYLE] = gText_BattleStyle,
    [MENUITEM_VANILLA_SOUND]       = gText_Sound,
    [MENUITEM_VANILLA_BUTTONMODE]  = gText_ButtonMode,
    [MENUITEM_VANILLA_CANCEL]      = sText_Cancel,
};

static const u8 *const OptionTextRight(u8 menuItem)
{
    switch (sOptions->submenu)
    {
        case MENU_PIT:
            return sOptionsMenuItemsNamesPit[menuItem];
        case MENU_VANILLA:
            return sOptionsMenuItemsNamesVan[menuItem];
        default:
            return gText_EmptyString2;
    }
}

// Menu left side text conditions
static bool8 CheckConditions(int selection)
{
    switch (sOptions->submenu)
    {
        case MENU_PIT:
            switch(selection)
            {
                case MENUITEM_PIT_RANDOM_MAPS:     return TRUE;
                case MENUITEM_PIT_RANDOM_MUSIC:    return TRUE;
                case MENUITEM_PIT_AUTOSAVE:        return TRUE;
                case MENUITEM_PIT_FOLLOWMONS:      return TRUE;
                case MENUITEM_PIT_CANCEL:          return TRUE;
                case MENUITEM_PIT_COUNT:           return TRUE;
                default:                           return FALSE;
            }
        case MENU_VANILLA:
            switch(selection)
            {
                case MENUITEM_VANILLA_TEXTSPEED:       return TRUE;
                case MENUITEM_VANILLA_BATTLESCENE:     return TRUE;
                case MENUITEM_VANILLA_BATTLESTYLE:     return TRUE;
                case MENUITEM_VANILLA_SOUND:           return TRUE;
                case MENUITEM_VANILLA_BUTTONMODE:      return TRUE;
                case MENUITEM_VANILLA_CANCEL:          return TRUE;
                case MENUITEM_VANILLA_COUNT:           return TRUE;
                default:                               return FALSE;
            }
        default: return FALSE;
    }
}

// Descriptions
static const u8 sText_Empty[]                   = _("");
static const u8 sText_Desc_Save[]               = _("Save your settings.");
static const u8 sText_Desc_TextSpeed[]          = _("Choose one of the four text-display\nspeeds.");
static const u8 sText_Desc_Autosave_Off[]       = _("Autosave is inactive.");
static const u8 sText_Desc_Autosave_5[]         = _("Autosave is executed every\nfive floors during warping.");
static const u8 sText_Desc_Autosave_On[]        = _("Autosave is executed every\nfloor during warping.");
static const u8 sText_Desc_RandomMaps_On[]      = _("Activate randomized maps\nfor each floor of the pit.");
static const u8 sText_Desc_RandomMaps_Off[]     = _("Use the default map\nfor each floor of the pit.");
static const u8 sText_Desc_RandomMusic_On[]     = _("Activate randomized music\nfor each floor of the pit.");
static const u8 sText_Desc_RandomMusic_Off[]    = _("Use the default music\nfor each floor of the pit.");
static const u8 sText_Desc_FollowMon_On[]       = _("Activate to have your first\nPokémon following you around.");
static const u8 sText_Desc_FollowMon_Off[]      = _("Deactivate to have no\nPokémon following you around.");
static const u8 sText_Desc_BattleScene_On[]     = _("Show the POKéMON battle animations.");
static const u8 sText_Desc_BattleScene_Off[]    = _("Skip the POKéMON battle animations.");
static const u8 sText_Desc_BattleStyle_Shift[]  = _("Get the option to switch your\nPOKéMON after the enemies faints.");
static const u8 sText_Desc_BattleStyle_Set[]    = _("No free switch after fainting the\nenemies POKéMON.");
static const u8 sText_Desc_SoundMono[]          = _("Sound is the same in all speakers.\nRecommended for original hardware.");
static const u8 sText_Desc_SoundStereo[]        = _("Play the left and right audio channel\nseperatly. Great with headphones.");
static const u8 sText_Desc_ButtonMode[]         = _("All buttons work as normal.");
static const u8 sText_Desc_ButtonMode_LR[]      = _("On some screens the L and R buttons\nact as left and right.");
static const u8 sText_Desc_ButtonMode_LA[]      = _("The L button acts as another A\nbutton for one-handed play.");
static const u8 sText_Desc_FrameType[]          = _("Choose the frame surrounding the\nwindows.");

static const u8 *const sOptionsMenuItemDescriptionsPit[MENUITEM_PIT_COUNT][3] =
{
    [MENUITEM_PIT_AUTOSAVE]     = {sText_Desc_Autosave_Off,         sText_Desc_Autosave_5,      sText_Desc_Autosave_On},
    [MENUITEM_PIT_RANDOM_MAPS]  = {sText_Desc_RandomMaps_On,        sText_Desc_RandomMaps_Off,  sText_Empty},
    [MENUITEM_PIT_RANDOM_MUSIC] = {sText_Desc_RandomMusic_Off,      sText_Desc_RandomMusic_On,  sText_Empty},
    [MENUITEM_PIT_FOLLOWMONS]   = {sText_Desc_FollowMon_On,         sText_Desc_FollowMon_Off,   sText_Empty},
    [MENUITEM_PIT_CANCEL]       = {sText_Desc_Save,                 sText_Empty,                sText_Empty},
};

static const u8 *const sOptionsMenuItemDescriptionsVan[MENUITEM_VANILLA_COUNT][3] =
{
    [MENUITEM_VANILLA_TEXTSPEED]   = {sText_Desc_TextSpeed,            sText_Desc_TextSpeed,          sText_Desc_TextSpeed},
    [MENUITEM_VANILLA_BATTLESCENE] = {sText_Desc_BattleScene_On,       sText_Desc_BattleScene_Off,    sText_Empty},
    [MENUITEM_VANILLA_BATTLESTYLE] = {sText_Desc_BattleStyle_Shift,    sText_Desc_BattleStyle_Set,    sText_Empty},
    [MENUITEM_VANILLA_SOUND]       = {sText_Desc_SoundMono,            sText_Desc_SoundStereo,        sText_Empty},
    [MENUITEM_VANILLA_BUTTONMODE]  = {sText_Desc_ButtonMode,           sText_Desc_ButtonMode_LR,      sText_Desc_ButtonMode_LA},
    [MENUITEM_VANILLA_CANCEL]      = {sText_Desc_Save,                 sText_Empty,                   sText_Empty},
};

/*
// Disabled Descriptions
static const u8 sText_Desc_Disabled_Textspeed[]     = _("Only active if xyz.");
static const u8 *const sOptionsMenuItemDescriptionsDisabledMain[MENUITEM_VANILLA_COUNT] =
{
    [MENUITEM_VANILLA_TEXTSPEED]   = sText_Desc_Disabled_Textspeed,
    [MENUITEM_VANILLA_BATTLESCENE] = sText_Empty,
    [MENUITEM_VANILLA_BATTLESTYLE] = sText_Empty,
    [MENUITEM_VANILLA_SOUND]       = sText_Empty,
    [MENUITEM_VANILLA_BUTTONMODE]  = sText_Empty,
    [MENUITEM_VANILLA_CANCEL]      = sText_Empty,
};*/

static const u8 *const OptionTextDescription(void)
{
    u8 menuItem = sOptions->menuCursor[sOptions->submenu];
    u8 selection;

    switch (sOptions->submenu)
    {
    case MENU_PIT:
        selection = sOptions->sel_pit[menuItem];
        return sOptionsMenuItemDescriptionsPit[menuItem][selection];
    case MENU_VANILLA:
        selection = sOptions->sel_van[menuItem];
        return sOptionsMenuItemDescriptionsVan[menuItem][selection];
    default:
        return gText_EmptyString2;
    }
}

static u8 MenuItemCount(void)
{
    switch (sOptions->submenu)
    {
        case MENU_PIT:
            return MENUITEM_PIT_COUNT;
        case MENU_VANILLA:
            return MENUITEM_VANILLA_COUNT;
        default:
            return 0;
    }
}

static u8 MenuItemCancel(void)
{
    switch (sOptions->submenu)
    {
        case MENU_PIT:
            return MENUITEM_PIT_CANCEL;
        case MENU_VANILLA:
            return MENUITEM_VANILLA_CANCEL;
        default:
            return 0;
    }
}

// Main code
static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ChangeBgY(3, 96, BG_COORD_SUB);
}

static const u8 sText_TopBar_Pit[]         = _("THE PIT OPTIONS");
static const u8 sText_TopBar_Van[]         = _("VANILLA OPTIONS");
static const u8 sText_TopBar_Right[]       = _("PAGE");
static const u8 gText_SmallDot[]           = _("·");
static const u8 gText_LargeDot[]           = _("{EMOJI_CIRCLE}");

static void DrawTopBarText(void)
{
    int i;
    const u8 color[3] = { 0, TEXT_COLOR_WHITE, TEXT_COLOR_OPTIONS_GRAY_FG };
    u8 pageDots[2*MENU_COUNT] = _("");

    //create navigation dots
    for (i = 0; i < MENU_COUNT; i++)
    {
        DebugPrintf("i = %d", i);
        if (i == sOptions->submenu)
            StringAppend(pageDots, gText_LargeDot);
        else
            StringAppend(pageDots, gText_SmallDot);
        if (i < MENU_COUNT)
            StringAppend(pageDots, gText_Space);
    }

    FillWindowPixelBuffer(WIN_TOPBAR, PIXEL_FILL(0));
    AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 5, 1, color, 0, pageDots);

    switch (sOptions->submenu)
    {
        case MENU_PIT:
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 40, 1, color, 0, sText_TopBar_Pit);
            break;
        case MENU_VANILLA:
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 40, 1, color, 0, sText_TopBar_Van);
            break;
    }
    BlitBitmapToWindow(WIN_TOPBAR, sLR_ButtonGfx, 190, 4, 24, 8);
    AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 215, 1, color, 0, sText_TopBar_Right);

    PutWindowTilemap(WIN_TOPBAR);
    CopyWindowToVram(WIN_TOPBAR, COPYWIN_FULL);
}

static void DrawOptionsMenuTexts(void) //left side text
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
    switch (sOptions->submenu)
    {
        case MENU_PIT:
            if (sItemFunctionsPit[id].drawChoices != NULL)
                sItemFunctionsPit[id].drawChoices(sOptions->sel_pit[id], y);
            break;
        case MENU_VANILLA:
            if (sItemFunctionsVan[id].drawChoices != NULL)
                sItemFunctionsVan[id].drawChoices(sOptions->sel_van[id], y);
            break;
    }
}

static void HighlightOptionsMenuItem(void)
{
    int cursor = sOptions->visibleCursor[sOptions->submenu];

    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(8, 232));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(cursor * Y_DIFF + 24, cursor * Y_DIFF + 40));
}

static bool8 OptionsMenu_LoadGraphics(void) // Load all the tilesets, tilemaps, spritesheets, and palettes
{
    switch (sOptions->gfxLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(2, sOptionsMenuTiles, 0, 0, 0);
        sOptions->gfxLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sOptionsMenuTilemap, sBg2TilemapBuffer);
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
        LoadPalette(sOptionsMenuPalette, 64, 32);
        LoadPalette(sScrollBgPalette, 32, 32);
        sOptions->gfxLoadState++;
        break;
    default:
        sOptions->gfxLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

void CB2_InitOptionsMenu(void)
{
    u32 i, taskId;

    taskId = TASK_NONE;

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
        InitBgsFromTemplates(0, sOptionsMenuBgTemplates, NELEMS(sOptionsMenuBgTemplates));
        InitWindows(sOptionsMenuWinTemplates);

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
        LoadPalette(sOptionsMenuBg_Pal, 0, sizeof(sOptionsMenuBg_Pal));
        LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, 0x70, 0x20);
        gMain.state++;
        break;
    case 5:
        LoadPalette(sOptionsMenuText_Pal, 16, sizeof(sOptionsMenuText_Pal));
        gMain.state++;
        break;
    case 6:
        sOptions->sel_van[MENUITEM_VANILLA_TEXTSPEED]   = gSaveBlock2Ptr->optionsTextSpeed - 1; //ignore SLOW
        sOptions->sel_pit[MENUITEM_PIT_AUTOSAVE]        = gSaveBlock2Ptr->optionsAutosave;
        sOptions->sel_pit[MENUITEM_PIT_RANDOM_MAPS]     = gSaveBlock2Ptr->optionsRandomMaps;
        sOptions->sel_pit[MENUITEM_PIT_RANDOM_MUSIC]    = gSaveBlock2Ptr->optionsRandomMusic;
        sOptions->sel_pit[MENUITEM_PIT_FOLLOWMONS]      = gSaveBlock2Ptr->optionsFollowMonsOff;
        sOptions->sel_van[MENUITEM_VANILLA_BATTLESCENE] = gSaveBlock2Ptr->optionsBattleSceneOff;
        sOptions->sel_van[MENUITEM_VANILLA_BATTLESTYLE] = gSaveBlock2Ptr->optionsBattleStyle;
        sOptions->sel_van[MENUITEM_VANILLA_SOUND]       = gSaveBlock2Ptr->optionsSound;
        sOptions->sel_van[MENUITEM_VANILLA_BUTTONMODE]  = gSaveBlock2Ptr->optionsButtonMode;
//        sOptions->sel_van[MENUITEM_VANILLA_FRAMETYPE]    = gSaveBlock2Ptr->optionsWindowFrameType;

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
        DrawOptionsMenuTexts();
        gMain.state++;
        break;
    case 10:
        taskId = CreateTask(Task_OptionsMenuFadeIn, 0);
        
        sOptions->arrowTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 240 / 2, 20, 110, MENUITEM_PIT_COUNT - 1, 110, 110, 0);

        for (i = 0; i < min(OPTIONS_ON_SCREEN, MenuItemCount()); i++)
            DrawChoices(i, i * Y_DIFF);

        HighlightOptionsMenuItem();

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
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        return;
    }
}

static void Task_OptionsMenuFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_OptionsMenuProcessInput;
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
        HighlightOptionsMenuItem();
        return;
    }
}

static void Task_OptionsMenuProcessInput(u8 taskId)
{
    u8 optionsToDraw = min(OPTIONS_ON_SCREEN , MenuItemCount());

    if (JOY_NEW(A_BUTTON))
    {
        if (sOptions->menuCursor[sOptions->submenu] == MenuItemCancel())
            gTasks[taskId].func = Task_OptionsMenuSave;
    }
    else if (JOY_NEW(B_BUTTON) || (JOY_NEW(START_BUTTON)))
    {
        gTasks[taskId].func = Task_OptionsMenuSave;
    }
    else if (JOY_NEW(DPAD_UP))
    {
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
        HighlightOptionsMenuItem();
        DrawDescriptionText();
    }
    else if (JOY_NEW(DPAD_DOWN))
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
        HighlightOptionsMenuItem();
        DrawDescriptionText();
    }
    else if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        if (sOptions->submenu == MENU_PIT)
        {
            int cursor = sOptions->menuCursor[sOptions->submenu];
            u8 previousOption = sOptions->sel_pit[cursor];
            if (CheckConditions(cursor))
            {
                if (sItemFunctionsPit[cursor].processInput != NULL)
                {
                    sOptions->sel_pit[cursor] = sItemFunctionsPit[cursor].processInput(previousOption);
                    ReDrawAll();
                    DrawDescriptionText();
                }

                if (previousOption != sOptions->sel_pit[cursor])
                    DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
            }
        }
        else if (sOptions->submenu == MENU_VANILLA)
        {
            int cursor = sOptions->menuCursor[sOptions->submenu];
            u8 previousOption = sOptions->sel_van[cursor];
            if (CheckConditions(cursor))
            {
                if (sItemFunctionsVan[cursor].processInput != NULL)
                {
                    sOptions->sel_van[cursor] = sItemFunctionsVan[cursor].processInput(previousOption);
                    ReDrawAll();
                    DrawDescriptionText();
                }

                if (previousOption != sOptions->sel_van[cursor])
                    DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
            }
        }
    }
    else if (JOY_NEW(R_BUTTON))
    {
        if (sOptions->submenu == MENU_VANILLA)
            sOptions->submenu = MENU_PIT;
        else
            sOptions->submenu++;

        DrawTopBarText();
        ReDrawAll();
        HighlightOptionsMenuItem();
        DrawDescriptionText();
    }
    else if (JOY_NEW(L_BUTTON))
    {
        if (sOptions->submenu == MENU_PIT)
            sOptions->submenu = MENU_VANILLA;
        else
            sOptions->submenu--;
        
        DrawTopBarText();
        ReDrawAll();
        HighlightOptionsMenuItem();
        DrawDescriptionText();
    }
}

static void Task_OptionsMenuSave(u8 taskId)
{
    //write in saveblock
    //pit settings
    gSaveBlock2Ptr->optionsAutosave         = sOptions->sel_pit[MENUITEM_PIT_AUTOSAVE];
    gSaveBlock2Ptr->optionsRandomMaps       = sOptions->sel_pit[MENUITEM_PIT_RANDOM_MAPS];
    gSaveBlock2Ptr->optionsRandomMusic      = sOptions->sel_pit[MENUITEM_PIT_RANDOM_MUSIC];
    gSaveBlock2Ptr->optionsFollowMonsOff    = sOptions->sel_pit[MENUITEM_PIT_FOLLOWMONS];

    //vanilla settings
    gSaveBlock2Ptr->optionsTextSpeed        = sOptions->sel_van[MENUITEM_VANILLA_TEXTSPEED] + 1; //ignore SLOW
    gSaveBlock2Ptr->optionsBattleSceneOff   = sOptions->sel_van[MENUITEM_VANILLA_BATTLESCENE];
    gSaveBlock2Ptr->optionsBattleStyle      = sOptions->sel_van[MENUITEM_VANILLA_BATTLESTYLE];
    gSaveBlock2Ptr->optionsSound            = sOptions->sel_van[MENUITEM_VANILLA_SOUND];
    gSaveBlock2Ptr->optionsButtonMode       = sOptions->sel_van[MENUITEM_VANILLA_BUTTONMODE];


    //set flags/VARs
    VarSet(VAR_PIT_AUTOSAVE, sOptions->sel_pit[MENUITEM_PIT_AUTOSAVE]);

    if (sOptions->sel_pit[MENUITEM_PIT_FOLLOWMONS] == TRUE)
        FlagSet(FLAG_FOLLOWERS_OFF);
    else
        FlagClear(FLAG_FOLLOWERS_OFF);

    if (sOptions->sel_pit[MENUITEM_PIT_RANDOM_MAPS] == 0)
        FlagSet(FLAG_RANDOM_MAPS);
    else
        FlagClear(FLAG_RANDOM_MAPS);
    

    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gTasks[taskId].func = Task_OptionsMenuFadeOut;
}

#define try_free(ptr) ({        \
    void ** ptr__ = (void **)&(ptr);   \
    if (*ptr__ != NULL)                \
        Free(*ptr__);                  \
})

static void Task_OptionsMenuFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        FreeAllWindowBuffers();
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
        SetMainCallback2(gMain.savedCallback);
    }
}

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

static int ProcessInput_Options_Four(int selection)
{
    return XOptions_ProcessInput(4, selection);
}

// Process Input functions ****SPECIFIC****
static int ProcessInput_FrameType(int selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection < WINDOW_FRAMES_COUNT - 1)
            selection++;
        else
            selection = 0;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, 0x70, 0x20);
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = WINDOW_FRAMES_COUNT - 1;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, 0x70, 0x20);
    }
    return selection;
}

// Draw Choices functions ****GENERIC****
static void DrawOptionsMenuChoice(const u8 *text, u8 x, u8 y, u8 style, bool8 active)
{
    bool8 chosen = FALSE;
    if (style != 0)
        chosen = TRUE;

    DrawRightSideChoiceText(text, x, y+1, chosen, active);
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
            sOptions->arrowTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 240 / 2, 20, 110, MENUITEM_VANILLA_COUNT - 1, 110, 110, 0);
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
static const u8 sText_Slow[]                = _("SLO");
static const u8 sText_Mid[]                 = _("MID");
static const u8 sText_Fast[]                = _("FAST");
static const u8 sText_Instant[]             = _("INST");
static const u8 sText_Autosave_Off[]        = _("OFF");
static const u8 sText_Autosave_5[]          = _("5FLRS");
static const u8 sText_Autosave_On[]         = _("ON");
static const u8 sText_On[]                  = _("ON");
static const u8 sText_Off[]                 = _("OFF");
static const u8 sText_Shift[]               = _("SHIFT");
static const u8 sText_Set[]                 = _("SET");
static const u8 sText_Mono[]                = _("MONO");
static const u8 sText_Stereo[]              = _("STEREO");
static const u8 sText_Normal[]              = _("NORMAL");
static const u8 sText_LR[]                  = _("LR");
static const u8 sText_L_A[]                 = _("L=A");
static const u8 sText_FrameType[]           = _("TYPE");
static const u8 sText_FrameTypeNumber[]     = _("");

static void DrawChoices_TextSpeed(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_VANILLA_TEXTSPEED);
    u8 styles[3] = {0};
    int xMid;

    styles[selection] = 1;
    xMid = GetMiddleX(sText_Mid, sText_Fast, sText_Instant);

    //DrawOptionsMenuChoice(sText_Slow, 104, y, styles[0], active);
    DrawOptionsMenuChoice(sText_Mid, 104, y, styles[0], active);
    DrawOptionsMenuChoice(sText_Fast, xMid, y, styles[1], active);
    DrawOptionsMenuChoice(sText_Instant, GetStringRightAlignXOffset(1, sText_Instant, 198), y, styles[2], active);
}

static void DrawChoices_Autosave(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_PIT_AUTOSAVE);
    u8 styles[3] = {0};
    int xMid;

    styles[selection] = 1;
    xMid = GetMiddleX(sText_Autosave_Off, sText_Autosave_5, sText_Autosave_On);

    DrawOptionsMenuChoice(sText_Autosave_Off, 104, y, styles[0], active);
    DrawOptionsMenuChoice(sText_Autosave_5, xMid, y, styles[1], active);
    DrawOptionsMenuChoice(sText_Autosave_On, GetStringRightAlignXOffset(1, sText_Autosave_On, 198), y, styles[2], active);
}

static void DrawChoices_RandomMaps(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_PIT_RANDOM_MAPS);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionsMenuChoice(sText_On, 104, y, styles[0], active);
    DrawOptionsMenuChoice(sText_Off, GetStringRightAlignXOffset(FONT_NORMAL, sText_Off, 198), y, styles[1], active);
}

static void DrawChoices_RandomMusic(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_PIT_RANDOM_MUSIC);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionsMenuChoice(sText_On, 104, y, styles[1], active);
    DrawOptionsMenuChoice(sText_Off, GetStringRightAlignXOffset(FONT_NORMAL, sText_Off, 198), y, styles[0], active);
}

static void DrawChoices_FollowMons(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_PIT_FOLLOWMONS);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionsMenuChoice(sText_On, 104, y, styles[0], active);
    DrawOptionsMenuChoice(sText_Off, GetStringRightAlignXOffset(FONT_NORMAL, sText_Off, 198), y, styles[1], active);
}

static void DrawChoices_BattleScene(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_VANILLA_BATTLESCENE);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionsMenuChoice(sText_On, 104, y, styles[0], active);
    DrawOptionsMenuChoice(sText_Off, GetStringRightAlignXOffset(FONT_NORMAL, sText_Off, 198), y, styles[1], active);
}

static void DrawChoices_BattleStyle(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_VANILLA_BATTLESTYLE);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionsMenuChoice(sText_Shift, 104, y, styles[0], active);
    DrawOptionsMenuChoice(sText_Set, GetStringRightAlignXOffset(FONT_NORMAL, sText_Set, 198), y, styles[1], active);
}

static void DrawChoices_Sound(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_VANILLA_SOUND);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionsMenuChoice(sText_Mono, 104, y, styles[0], active);
    DrawOptionsMenuChoice(sText_Stereo, GetStringRightAlignXOffset(FONT_NORMAL, sText_Stereo, 198), y, styles[1], active);
}

static void DrawChoices_ButtonMode(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_VANILLA_BUTTONMODE);
    u8 styles[3] = {0};
    int xMid = GetMiddleX(gText_ButtonTypeNormal, gText_ButtonTypeLR, gText_ButtonTypeLEqualsA);
    styles[selection] = 1;

    DrawOptionsMenuChoice(sText_Normal, 104, y, styles[0], active);
    DrawOptionsMenuChoice(sText_LR, xMid, y, styles[1], active);
    DrawOptionsMenuChoice(sText_L_A, GetStringRightAlignXOffset(1, sText_L_A, 198), y, styles[2], active);
}

static void DrawChoices_FrameType(int selection, int y)
{
    bool8 active = 0; //CheckConditions(MENUITEM_VANILLA_FRAMETYPE);
    u8 text[16];
    u8 n = selection + 1;
    u16 i;

    for (i = 0; sText_FrameTypeNumber[i] != EOS && i <= 5; i++)
        text[i] = sText_FrameTypeNumber[i];

    // Convert a number to decimal string
    if (n / 10 != 0)
    {
        text[i] = n / 10 + CHAR_0;
        i++;
        text[i] = n % 10 + CHAR_0;
        i++;
    }
    else
    {
        text[i] = n % 10 + CHAR_0;
        i++;
        text[i] = 0x77;
        i++;
    }

    text[i] = EOS;

    DrawOptionsMenuChoice(sText_FrameType, 104, y, 0, active);
    DrawOptionsMenuChoice(text, 128, y, 1, active);
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
