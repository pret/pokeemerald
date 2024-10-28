#include "gba/types.h"
#include "gba/defines.h"
#include "gba/isagbprint.h"
#include "global.h"
#include "main.h"
#include "bg.h"
#include "text_window.h"
#include "window.h"
#include "constants/characters.h"
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
#include "config/general.h"

//defines
#define MODE_SINGLES    0
#define MODE_DOUBLES    1
#define MODE_MIXED_SINGLES_AND_DOUBLES    2
#define RANDOM_MONS     0
#define RANDOM_ALL      1
#define XP_75           0
#define XP_50           1
#define XP_NONE         2
#define ACTIVE          0
#define INACTIVE        1
#define YES             0
#define NO              1
#define MEGAS_ON        0
#define MEGAS_OFF       1
#define HEAL_FLOORS_5   0
#define HEAL_FLOORS_10  1


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

enum MenuIds
{
    MENU_RUN,
    MENU_DIFF,
    MENU_RAND,
    MENU_PRESETS,
    MENU_COUNT
};

enum MenuItems_Run
{
    MENUITEM_RUN_BATTLEMODE,
    MENUITEM_RUN_3_MONS_ONLY,
    MENUITEM_RUN_NO_CASE_CHOICE,
    //MENUITEM_RUN_DUPLICATES,
    MENUITEM_RUN_CANCEL,
    MENUITEM_RUN_COUNT,
};

enum MenuItems_Difficulty
{
    MENUITEM_DIFF_XPMODE,
    MENUITEM_DIFF_SAVE_DELETION,
    MENUITEM_DIFF_STAT_CHANGER,
    MENUITEM_DIFF_DOUBLE_CASH,
    MENUITEM_DIFF_HEALFLOORS,
    MENUITEM_DIFF_LEGENDARIES,
    #ifdef PIT_GEN_9_MODE
    MENUITEM_DIFF_MEGAS,
    #endif
    MENUITEM_DIFF_CANCEL,
    MENUITEM_DIFF_COUNT,
};

enum MenuItems_Randomizer
{
    MENUITEM_RAND_MOVES,
    MENUITEM_RAND_ABILITIES,
    MENUITEM_RAND_BASE_STATS,
    MENUITEM_RAND_TYPES,
    //MENUITEM_RAND_EVOS,
    MENUITEM_RAND_CANCEL,
    MENUITEM_RAND_COUNT,
};

enum MenuItems_Presets
{
    MENUITEM_PRESET_MODE,
    MENUITEM_PRESET_CANCEL,
    MENUITEM_PRESET_SAVE,
    MENUITEM_PRESET_COUNT,
};

enum Game_Presets
{
    PRESET_NORMAL,
    PRESET_HARD
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
//static EWRAM_DATA u8 *statePresets = 0;

// const data
static const u8 sEqualSignGfx[]      = INCBIN_U8("graphics/interface/option_menu_equals_sign.4bpp"); // note: this is only used in the Japanese release
static const u16 sModeMenuBg_Pal[]   = {RGB(17, 18, 31)};
static const u16 sModeMenuText_Pal[] = INCBIN_U16("graphics/interface/option_menu_text_custom.gbapal");
static const u8 sLR_ButtonGfx[]      = INCBIN_U8("graphics/ui_menu/r_button.4bpp");

static const u32 sOptionsPlusTiles[]   = INCBIN_U32("graphics/ui_mode_menu/mode_menu_tiles.4bpp.lz");
static const u16 sOptionsPlusPalette[] = INCBIN_U16("graphics/ui_mode_menu/mode_menu_tiles.gbapal");
static const u32 sOptionsPlusTilemap[] = INCBIN_U32("graphics/ui_mode_menu/mode_menu_tiles.bin.lz");

// Scrolling Background
static const u32 sScrollBgTiles[]   = INCBIN_U32("graphics/ui_mode_menu/scroll_tiles.4bpp.lz");
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
    u16 submenu;
    u8 sel_run[MENUITEM_RUN_COUNT];
    u8 sel_diff[MENUITEM_DIFF_COUNT];
    u8 sel_rand[MENUITEM_RAND_COUNT];
    u8 sel_presets[MENUITEM_PRESET_COUNT];
    int menuCursor[MENU_COUNT];
    int visibleCursor[MENU_COUNT];
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
//static void DrawChoices_Autosave(int selection, int y);
static void DrawChoices_BattleMode(int selection, int y);
//static void DrawChoices_Randomizer(int selection, int y);
static void DrawChoices_3MonsOnly(int selection, int y);
static void DrawChoices_NoCaseChoice(int selection, int y);
static void DrawChoices_SaveDeletion(int selection, int y);
static void DrawChoices_DoubleCash(int selection, int y);
static void DrawChoices_RandMoves(int selection, int y);
static void DrawChoices_RandAbilities(int selection, int y);
static void DrawChoices_RandStats(int selection, int y);
static void DrawChoices_RandTypes(int selection, int y);
//static void DrawChoices_RandEvos(int selection, int y);
static void DrawChoices_XPMode(int selection, int y);
static void DrawChoices_StatChanger(int selection, int y);
static void DrawChoices_Legendaries(int selection, int y);
static void DrawChoices_Duplicates(int selection, int y);
static void DrawChoices_Megas(int selection, int y);
static void DrawChoices_HealFloors(int selection, int y);
static void DrawChoices_PresetsMode(int selection, int y);
static void DrawBgWindowFrames(void);
static void ApplyPresets(void);

// Menu draw and input functions
struct Menu_Run //MENU_RUN
{
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
} static const sItemFunctionsRun[MENUITEM_RUN_COUNT] =
{
    [MENUITEM_RUN_BATTLEMODE]     = {DrawChoices_BattleMode,   ProcessInput_Options_Three},
    [MENUITEM_RUN_3_MONS_ONLY]    = {DrawChoices_3MonsOnly,    ProcessInput_Options_Two},
    [MENUITEM_RUN_NO_CASE_CHOICE] = {DrawChoices_NoCaseChoice, ProcessInput_Options_Two},
    //[MENUITEM_RUN_DUPLICATES]     = {DrawChoices_Duplicates,  ProcessInput_Options_Two},
    [MENUITEM_RUN_CANCEL]         = {NULL, NULL},
};

struct Menu_Diff //MENU_DIFF
{
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
} static const sItemFunctionsDiff[MENUITEM_DIFF_COUNT] =
{
    [MENUITEM_DIFF_XPMODE]        = {DrawChoices_XPMode,       ProcessInput_Options_Three},
    [MENUITEM_DIFF_SAVE_DELETION] = {DrawChoices_SaveDeletion, ProcessInput_Options_Two},
    [MENUITEM_DIFF_STAT_CHANGER]  = {DrawChoices_StatChanger,  ProcessInput_Options_Two},
    [MENUITEM_DIFF_DOUBLE_CASH]   = {DrawChoices_DoubleCash,   ProcessInput_Options_Two},
    [MENUITEM_DIFF_HEALFLOORS]    = {DrawChoices_HealFloors,   ProcessInput_Options_Two},
    [MENUITEM_DIFF_LEGENDARIES]   = {DrawChoices_Legendaries,  ProcessInput_Options_Two},
    #ifdef PIT_GEN_9_MODE
    [MENUITEM_DIFF_MEGAS]         = {DrawChoices_Megas,        ProcessInput_Options_Two},
    #endif
    [MENUITEM_DIFF_CANCEL]        = {NULL, NULL},
};

struct Menu_Rand //MENU_RAND
{
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
} static const sItemFunctionsRand[MENUITEM_RAND_COUNT] =
{
    [MENUITEM_RAND_MOVES]      = {DrawChoices_RandMoves,     ProcessInput_Options_Two},
    [MENUITEM_RAND_ABILITIES]  = {DrawChoices_RandAbilities, ProcessInput_Options_Two},
    [MENUITEM_RAND_BASE_STATS] = {DrawChoices_RandStats,     ProcessInput_Options_Two},
    [MENUITEM_RAND_TYPES]      = {DrawChoices_RandTypes,     ProcessInput_Options_Two},
    //[MENUITEM_RAND_EVOS]       = {DrawChoices_RandEvos,      ProcessInput_Options_Two},
    [MENUITEM_RAND_CANCEL]     = {NULL, NULL},
};

struct Menu_Presets //MENU_PRESETS
{
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
} static const sItemFunctionsPresets[MENUITEM_PRESET_COUNT] =
{
    [MENUITEM_PRESET_MODE] = {DrawChoices_PresetsMode,     ProcessInput_Options_Two},
    [MENUITEM_PRESET_CANCEL] = {NULL, NULL},
    [MENUITEM_PRESET_SAVE]   = {NULL, NULL},
};

// Menu left side option names text
static const u8 sText_Defaults[]     = _("PRESETS");
static const u8 sText_Autosave[]     = _("AUTOSAVE");
static const u8 sText_BattleMode[]   = _("BATTLE MODE");
static const u8 sText_Randomizer[]   = _("RANDOMIZER");
static const u8 sText_XPMode[]       = _("XP MODE");
static const u8 sText_StatChanger[]  = _("STAT CHANGER");
static const u8 sText_Legendaries[]  = _("LEGENDARIES");
static const u8 sText_Duplicates[]   = _("DUPLICATES");
static const u8 sText_Megas[]        = _("TRAINER MEGAS");
static const u8 sText_HealFloors[]   = _("HEAL FLOORS");

static const u8 sText_3MonsOnly[]    = _("3 MONS ONLY");
static const u8 sText_NoCaseChoice[] = _("NO BIRCH CASE");
static const u8 sText_SaveDeletion[] = _("SAVE DELETION");
static const u8 sText_DoubleCash[]   = _("DOUBLE CASH");

static const u8 sText_Moves[]        = _("MOVES");
static const u8 sText_Abilities[]    = _("ABILITIES");
static const u8 sText_BaseStats[]    = _("BASE STATS");
static const u8 sText_Types[]        = _("TYPES");
static const u8 sText_Evos[]         = _("EVOLUTIONS");
static const u8 sText_Cancel[]       = _("SAVE & LEAVE");

static const u8 sText_GameMode[]     = _("GAME MODE");
static const u8 sText_CancelPreset[] = _("CANCEL&RETURN");
static const u8 sText_SavePreset[]   = _("SAVE PRESETS");

static const u8 *const sModeMenuItemsNamesRun[MENUITEM_RUN_COUNT] =
{
    [MENUITEM_RUN_BATTLEMODE]     = sText_BattleMode,
    [MENUITEM_RUN_3_MONS_ONLY]    = sText_3MonsOnly,
    [MENUITEM_RUN_NO_CASE_CHOICE] = sText_NoCaseChoice,
    //[MENUITEM_RUN_DUPLICATES]   = sText_Duplicates,
    [MENUITEM_RUN_CANCEL]         = sText_Cancel,
};

static const u8 *const sModeMenuItemsNamesDiff[MENUITEM_DIFF_COUNT] =
{
    [MENUITEM_DIFF_XPMODE]        = sText_XPMode,
    [MENUITEM_DIFF_SAVE_DELETION] = sText_SaveDeletion,
    [MENUITEM_DIFF_STAT_CHANGER]  = sText_StatChanger,
    [MENUITEM_DIFF_DOUBLE_CASH]   = sText_DoubleCash,
    [MENUITEM_DIFF_HEALFLOORS]    = sText_HealFloors,
    [MENUITEM_DIFF_LEGENDARIES]   = sText_Legendaries,
    #ifdef PIT_GEN_9_MODE
    [MENUITEM_DIFF_MEGAS]         = sText_Megas,
    #endif
    [MENUITEM_DIFF_CANCEL]        = sText_Cancel,
};

static const u8 *const sModeMenuItemsNamesRand[MENUITEM_RAND_COUNT] =
{
    [MENUITEM_RAND_MOVES]      = sText_Moves,
    [MENUITEM_RAND_ABILITIES]  = sText_Abilities,
    [MENUITEM_RAND_BASE_STATS] = sText_BaseStats,
    [MENUITEM_RAND_TYPES]      = sText_Types,
    //[MENUITEM_RAND_EVOS]       = sText_Evos,
    [MENUITEM_RAND_CANCEL]     = sText_Cancel,
};

static const u8 *const sModeMenuItemsNamesPresets[MENUITEM_PRESET_COUNT] =
{
    [MENUITEM_PRESET_MODE]   = sText_GameMode,
    [MENUITEM_PRESET_CANCEL] = sText_CancelPreset,
    [MENUITEM_PRESET_SAVE]   = sText_SavePreset,
};

static const u8 *const OptionTextRight(u8 menuItem)
{
    switch (sOptions->submenu)
    {
        case MENU_RUN:
            return sModeMenuItemsNamesRun[menuItem];
        case MENU_DIFF:
            return sModeMenuItemsNamesDiff[menuItem];
        case MENU_RAND:
            return sModeMenuItemsNamesRand[menuItem];
        case MENU_PRESETS:
            return sModeMenuItemsNamesPresets[menuItem];
        default:
            return gText_EmptyString2;
    }
}

// Menu left side text conditions
static bool8 CheckConditions(int selection)
{
    switch (sOptions->submenu)
    {
        case MENU_RUN:
            switch(selection)
            {
                case MENUITEM_RUN_BATTLEMODE:     return TRUE;
                case MENUITEM_RUN_3_MONS_ONLY:    return TRUE;
                case MENUITEM_RUN_NO_CASE_CHOICE: return TRUE;
                //case MENUITEM_RUN_DUPLICATES:     return TRUE;
                case MENUITEM_RUN_CANCEL:         return TRUE;
                case MENUITEM_RUN_COUNT:          return TRUE;
                default:                          return FALSE;
            }
        case MENU_DIFF:
            switch(selection)
            {
                case MENUITEM_DIFF_XPMODE:        return TRUE;
                case MENUITEM_DIFF_SAVE_DELETION: return TRUE;
                case MENUITEM_DIFF_STAT_CHANGER:  return TRUE;
                case MENUITEM_DIFF_DOUBLE_CASH:   return TRUE;
                case MENUITEM_DIFF_HEALFLOORS:    return TRUE;
                case MENUITEM_DIFF_LEGENDARIES:   return TRUE;
                #ifdef PIT_GEN_9_MODE
                case MENUITEM_DIFF_MEGAS:         return TRUE;
                #endif
                case MENUITEM_DIFF_CANCEL:        return TRUE;
                case MENUITEM_DIFF_COUNT:         return TRUE;
                default:                          return FALSE;
            }
        case MENU_RAND:
            switch(selection)
            {
                case MENUITEM_RAND_MOVES:         return TRUE;
                case MENUITEM_RAND_ABILITIES:     return TRUE;
                case MENUITEM_RAND_BASE_STATS:    return TRUE;
                case MENUITEM_RAND_TYPES:         return TRUE;
                //case MENUITEM_RAND_EVOS:          return TRUE;
                case MENUITEM_RAND_CANCEL:        return TRUE;
                case MENUITEM_RAND_COUNT:         return TRUE;
                default:                          return FALSE;
            }
        case MENU_PRESETS:
            switch(selection)
            {
                case MENUITEM_PRESET_MODE:        return TRUE;
                case MENUITEM_PRESET_CANCEL:      return TRUE;
                case MENUITEM_PRESET_SAVE:        return TRUE;
                case MENUITEM_PRESET_COUNT:       return TRUE;
                default:                          return FALSE;
            }
        default: return FALSE;
    }
}

// Descriptions
static const u8 sText_Empty[]                   = _("");
static const u8 sText_Desc_Save[]               = _("Save your settings.");
static const u8 sText_Desc_CancelPreset[]       = _("Cancel and return without setting\na preset.");
static const u8 sText_Desc_SavePreset[]         = _("Save preset and overwrite current\nmode choice.");
static const u8 sText_Desc_NormalMode[]         = _("Normal mode uses 50% XP share.");
static const u8 sText_Desc_HardMode[]           = _("Hard mode uses 75% XP share.");
static const u8 sText_Desc_Defaults_Normal[]    = _("Sets all options for Normal Mode below.");
static const u8 sText_Desc_Defaults_Hard[]      = _("Sets all options for Hard Mode below.");
static const u8 sText_Desc_Defaults_Custom[]    = _("Is shown when manually changing\nmode settings.");
static const u8 sText_Desc_Autosave_Off[]       = _("Autosave is inactive.");
static const u8 sText_Desc_Autosave_5[]         = _("Autosave is executed every\nfive floors during warping.");
static const u8 sText_Desc_Autosave_On[]        = _("Autosave is executed every\nfloor during warping.");
static const u8 sText_Desc_BattleMode_Singles[] = _("Play only single battles.");
static const u8 sText_Desc_BattleMode_Doubles[] = _("Play only double battles.");
static const u8 sText_Desc_BattleMode_Mix[]     = _("Play mixed singles and double battles.");
static const u8 sText_Desc_Randomizer_Mons[]    = _("Only randomize Pokémon species,\ntrainers and item drops.");
static const u8 sText_Desc_Randomizer_All[]     = _("Also randomize abilities and\nmoves.");
static const u8 sText_Desc_XPMode_75[]          = _("Exp. Share gives 75% XP to party\nmembers.");
static const u8 sText_Desc_XPMode_50[]          = _("Exp. Share gives 50% XP to party\nmembers. WARNING: Hard Mode!");
static const u8 sText_Desc_XPMode_None[]        = _("You won't receive any XP from battles.\nLevels are tied to the floor.");
static const u8 sText_Desc_StatChanger_On[]     = _("Enables the EV/IV Changer\nin the party menu.");
static const u8 sText_Desc_StatChanger_Off[]    = _("Makes the EV/IV Changer read only\nand adds an IV merchant option.");
static const u8 sText_Desc_Legendaries_On[]     = _("Legendaries can be found\nin the Birch Case.");
static const u8 sText_Desc_Legendaries_Off[]    = _("Legendaries can not be found\nin the Birch Case.");
static const u8 sText_Desc_Duplicates_On[]      = _("Truly random. Duplicates are\npossible in the Birch Case.");
static const u8 sText_Desc_Duplicates_Off[]     = _("Birch Case can't hold duplicates.");
static const u8 sText_Desc_Megas_On[]           = _("Trainer Pokémon have a 40% chance\nto mega evolve if possible.");
static const u8 sText_Desc_Megas_Off[]          = _("Trainer Pokémon can never mega\nevolve.");
static const u8 sText_Desc_HealFloors_5[]       = _("Get a rest stop to heal every\n5 floors.");
static const u8 sText_Desc_HealFloors_10[]      = _("Get a rest stop to heal every\n10 floors.");
static const u8 sText_Desc_3Mons_On[]           = _("Party size will never increase and\nremain at three (incl. trainers).");
static const u8 sText_Desc_3Mons_Off[]          = _("Party size will increase by one\nevery 25 floors.");
static const u8 sText_Desc_NoCaseChoice_On[]    = _("You can't choose your party\nand will be given random species.");
static const u8 sText_Desc_NoCaseChoice_Off[]   = _("You can choose your party from\nthe random Birch Case options.");
static const u8 sText_Desc_SaveDeletion_On[]    = _("Your save state will be deleted\nwhen fainting.");
static const u8 sText_Desc_SaveDeletion_Off[]   = _("Your save state will not be deleted\nwhen fainting.");
static const u8 sText_Desc_DoubleCash_On[]      = _("Doubles the amount of money\nreceived after winning a battle.");
static const u8 sText_Desc_DoubleCash_Off[]     = _("Sets the default amount of money\nreceived after winning a battle.");
static const u8 sText_Desc_RandMoves_On[]       = _("Randomizes the move learnsets.");
static const u8 sText_Desc_RandMoves_Off[]      = _("Keeps the default move learnsets.");
static const u8 sText_Desc_RandAbilities_On[]   = _("Randomizes the ability options.");
static const u8 sText_Desc_RandAbilities_Off[]  = _("Keeps the default ability options.");
static const u8 sText_Desc_RandStats_On[]       = _("Randomizes the base stats.");
static const u8 sText_Desc_RandStats_Off[]      = _("Keeps the default base stats.");
static const u8 sText_Desc_RandTypes_On[]       = _("Randomizes the species' type(s).");
static const u8 sText_Desc_RandTypes_Off[]      = _("Keeps the species' default type(s).");
static const u8 sText_Desc_RandEvos_On[]        = _("Randomizes the evolution species.");
static const u8 sText_Desc_RandEvos_Off[]       = _("Keeps the default evo line.");

static const u8 *const sModeMenuItemDescriptionsRun[MENUITEM_RUN_COUNT][3] =
{
    [MENUITEM_RUN_BATTLEMODE]     = {sText_Desc_BattleMode_Singles,  sText_Desc_BattleMode_Doubles,  sText_Desc_BattleMode_Mix},
    [MENUITEM_RUN_3_MONS_ONLY]    = {sText_Desc_3Mons_On,            sText_Desc_3Mons_Off,           sText_Empty},
    [MENUITEM_RUN_NO_CASE_CHOICE] = {sText_Desc_NoCaseChoice_On,     sText_Desc_NoCaseChoice_Off,    sText_Empty},
    //[MENUITEM_RUN_DUPLICATES]     = {sText_Desc_Duplicates_On,       sText_Desc_Duplicates_Off,      sText_Empty},
    [MENUITEM_RUN_CANCEL]         = {sText_Desc_Save,                sText_Empty,                    sText_Empty},
};

static const u8 *const sModeMenuItemDescriptionsDiff[MENUITEM_DIFF_COUNT][3] =
{
    [MENUITEM_DIFF_XPMODE]        = {sText_Desc_XPMode_75,        sText_Desc_XPMode_50,         sText_Desc_XPMode_None},
    [MENUITEM_DIFF_SAVE_DELETION] = {sText_Desc_SaveDeletion_On,  sText_Desc_SaveDeletion_Off,  sText_Empty},
    [MENUITEM_DIFF_STAT_CHANGER]  = {sText_Desc_StatChanger_On,   sText_Desc_StatChanger_Off,   sText_Empty},
    [MENUITEM_DIFF_DOUBLE_CASH]   = {sText_Desc_DoubleCash_On,    sText_Desc_DoubleCash_Off,    sText_Empty},
    [MENUITEM_DIFF_HEALFLOORS]    = {sText_Desc_HealFloors_5,     sText_Desc_HealFloors_10,     sText_Empty},
    [MENUITEM_DIFF_LEGENDARIES]   = {sText_Desc_Legendaries_On,   sText_Desc_Legendaries_Off,   sText_Empty},
    #ifdef PIT_GEN_9_MODE
    [MENUITEM_DIFF_MEGAS]         = {sText_Desc_Megas_On,         sText_Desc_Megas_Off,         sText_Empty},
    #endif
    [MENUITEM_DIFF_CANCEL]        = {sText_Desc_Save,             sText_Empty,                  sText_Empty},
};

static const u8 *const sModeMenuItemDescriptionsRand[MENUITEM_RAND_COUNT][3] =
{
    [MENUITEM_RAND_MOVES]         = {sText_Desc_RandMoves_On,      sText_Desc_RandMoves_Off,      sText_Empty},
    [MENUITEM_RAND_ABILITIES]     = {sText_Desc_RandAbilities_On,  sText_Desc_RandAbilities_Off,  sText_Empty},
    [MENUITEM_RAND_BASE_STATS]    = {sText_Desc_RandStats_On,      sText_Desc_RandStats_Off,      sText_Empty},
    [MENUITEM_RAND_TYPES]         = {sText_Desc_RandTypes_On,      sText_Desc_RandTypes_Off,      sText_Empty},
    //[MENUITEM_RAND_EVOS]          = {sText_Desc_RandEvos_On,       sText_Desc_RandEvos_Off,       sText_Empty},
    [MENUITEM_RAND_CANCEL]        = {sText_Desc_Save,              sText_Empty,                   sText_Empty},
};

static const u8 *const sModeMenuItemDescriptionsPresets[MENUITEM_PRESET_COUNT][3] =
{
    [MENUITEM_PRESET_MODE]        = {sText_Desc_NormalMode,    sText_Desc_HardMode,           sText_Empty},
    [MENUITEM_PRESET_CANCEL]      = {sText_Desc_CancelPreset,  sText_Empty,                   sText_Empty},
    [MENUITEM_PRESET_SAVE]        = {sText_Desc_SavePreset,    sText_Empty,                   sText_Empty},
};

static const u8 *const OptionTextDescription(void)
{
    u8 menuItem = sOptions->menuCursor[sOptions->submenu];;
    u8 selection;

    switch (sOptions->submenu)
    {
    case MENU_RUN:
        selection = sOptions->sel_run[menuItem];
        return sModeMenuItemDescriptionsRun[menuItem][selection];
    case MENU_DIFF:
        selection = sOptions->sel_diff[menuItem];
        return sModeMenuItemDescriptionsDiff[menuItem][selection];
    case MENU_RAND:
        selection = sOptions->sel_rand[menuItem];
        return sModeMenuItemDescriptionsRand[menuItem][selection];
    case MENU_PRESETS:
        selection = sOptions->sel_presets[menuItem];
        return sModeMenuItemDescriptionsPresets[menuItem][selection];
    default:
        return gText_EmptyString2;
    }
}

static u8 MenuItemCount(void)
{
    switch (sOptions->submenu)
    {
        case MENU_RUN:
            return MENUITEM_RUN_COUNT;
        case MENU_DIFF:
            return MENUITEM_DIFF_COUNT;
        case MENU_RAND:
            return MENUITEM_RAND_COUNT;
        case MENU_PRESETS:
            return MENUITEM_PRESET_COUNT;
        default:
            return 0;
    }
}

static u8 MenuItemCancel(void)
{
    switch (sOptions->submenu)
    {
        case MENU_RUN:
            return MENUITEM_RUN_CANCEL;
        case MENU_DIFF:
            return MENUITEM_DIFF_CANCEL;
        case MENU_RAND:
            return MENUITEM_RAND_CANCEL;
        default:
            return 99;
    }
}

static u8 MenuItemPresetsSave(void)
{
    switch (sOptions->submenu)
    {
        case MENU_PRESETS:
            return MENUITEM_PRESET_SAVE;
        default:
            return 99;
    }
}

static u8 MenuItemPresetsCancel(void)
{
    switch (sOptions->submenu)
    {
        case MENU_PRESETS:
            return MENUITEM_PRESET_CANCEL;
        default:
            return 99;
    }
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
        //run settings
        //sOptions->sel_run[MENUITEM_RUN_AUTOSAVE]        = gSaveBlock2Ptr->optionsAutosave;
        sOptions->sel_run[MENUITEM_RUN_BATTLEMODE]      = gSaveBlock2Ptr->modeBattleMode;
        sOptions->sel_run[MENUITEM_RUN_3_MONS_ONLY]     = gSaveBlock2Ptr->mode3MonsOnly;
        sOptions->sel_run[MENUITEM_RUN_NO_CASE_CHOICE]  = gSaveBlock2Ptr->modeNoCaseChoice;
        //sOptions->sel_run[MENUITEM_RUN_DUPLICATES]      = gSaveBlock2Ptr->modeDuplicates;
        //sOptions->sel_run[MENUITEM_RUN_RANDOMIZER]      = gSaveBlock2Ptr->modeRandomizer;
        //difficulty settings
        sOptions->sel_diff[MENUITEM_DIFF_XPMODE]        = gSaveBlock2Ptr->modeXP;
        sOptions->sel_diff[MENUITEM_DIFF_SAVE_DELETION] = gSaveBlock2Ptr->modeSaveDeletion;
        sOptions->sel_diff[MENUITEM_DIFF_STAT_CHANGER]  = gSaveBlock2Ptr->modeStatChanger;
        sOptions->sel_diff[MENUITEM_DIFF_DOUBLE_CASH]   = gSaveBlock2Ptr->modeCashRewards;
        sOptions->sel_diff[MENUITEM_DIFF_HEALFLOORS]    = gSaveBlock2Ptr->modeHealFloors10;
        sOptions->sel_diff[MENUITEM_DIFF_LEGENDARIES]   = gSaveBlock2Ptr->modeLegendaries;
        #ifdef PIT_GEN_9_MODE
        sOptions->sel_diff[MENUITEM_DIFF_MEGAS]         = gSaveBlock2Ptr->modeMegas;
        #endif
        //randomizer settings
        sOptions->sel_rand[MENUITEM_RAND_MOVES]         = !(gSaveBlock2Ptr->randomMoves);
        sOptions->sel_rand[MENUITEM_RAND_ABILITIES]     = !(gSaveBlock2Ptr->randomAbilities);
        sOptions->sel_rand[MENUITEM_RAND_BASE_STATS]    = !(gSaveBlock2Ptr->randomBST);
        sOptions->sel_rand[MENUITEM_RAND_TYPES]         = !(gSaveBlock2Ptr->randomType);
        //sOptions->sel_rand[MENUITEM_RAND_EVOS]          = gSaveBlock2Ptr->randomEvos;
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
        
        sOptions->arrowTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 240 / 2, 20, 110, MENUITEM_RUN_COUNT - 1, 110, 110, 0);

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
    ChangeBgY(3, 96, BG_COORD_SUB);
}

//Header Window
//static const u8 sText_TopBar_Run[] = _("CHOOSE GAME MODE");
static const u8 sText_TopBar_Run[]        = _("RUN SETTINGS");
static const u8 sText_TopBar_Diff[]       = _("DIFFICULTY SETTINGS");
static const u8 sText_TopBar_Rand[]       = _("RANDOMIZER SETTINGS");
static const u8 sText_TopBar_Select[]     = _("{SELECT_BUTTON} PRESETS");
static const u8 sText_TopBar_Right[]      = _("PAGE");
static const u8 gText_SmallDot[]          = _("·");
static const u8 gText_LargeDot[]          = _("{EMOJI_CIRCLE}");
static void DrawTopBarText(void)
{
    const u8 color[3] = { 0, TEXT_COLOR_WHITE, TEXT_COLOR_OPTIONS_GRAY_FG };
    u8 pageDots[2*(MENU_COUNT - 1)] = _("");
    int i;

    if (sOptions->submenu != MENU_PRESETS)
    {
        //create navigation dots
        for (i = 0; i < (MENU_COUNT - 1); i++)
        {
            if (i == sOptions->submenu)
                StringAppend(pageDots, gText_LargeDot);
            else
                StringAppend(pageDots, gText_SmallDot);
            if (i < MENU_RAND)
                StringAppend(pageDots, gText_Space);
        }

        FillWindowPixelBuffer(WIN_TOPBAR, PIXEL_FILL(0));
        AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 5, 1, color, 0, pageDots);

        switch (sOptions->submenu)
        {
            case MENU_RUN:
                AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 40, 1, color, 0, sText_TopBar_Run);
                break;
            case MENU_DIFF:
                AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 40, 1, color, 0, sText_TopBar_Diff);
                break;
            case MENU_RAND:
                AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 40, 1, color, 0, sText_TopBar_Rand);
                break;
        }
        AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 125, 1, color, 0, sText_TopBar_Select);
        BlitBitmapToWindow(WIN_TOPBAR, sLR_ButtonGfx, 190, 4, 24, 8);
        AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 215, 1, color, 0, sText_TopBar_Right);
    }
    else
    {
        FillWindowPixelBuffer(WIN_TOPBAR, PIXEL_FILL(0));
        AddTextPrinterParameterized3(WIN_TOPBAR, FONT_NORMAL, 10, 1, color, 0, sText_Defaults);
    }

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
    u8 color_red[3];

    color_yellow[0] = TEXT_COLOR_TRANSPARENT;
    color_yellow[1] = TEXT_COLOR_WHITE;
    color_yellow[2] = TEXT_COLOR_OPTIONS_GRAY_FG;
    color_gray[0] = TEXT_COLOR_TRANSPARENT;
    color_gray[1] = TEXT_COLOR_WHITE;
    color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_SHADOW;
    color_red[0] = TEXT_COLOR_TRANSPARENT;
    color_red[1] = TEXT_COLOR_OPTIONS_RED_FG;
    color_red[2] = TEXT_COLOR_OPTIONS_GRAY_FG;

    if (CheckConditions(selection))
    {
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, 8, y, 0, 0, color_yellow, TEXT_SKIP_DRAW, OptionTextRight(selection));
    }
    else
    {
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, 8, y, 0, 0, color_gray, TEXT_SKIP_DRAW, OptionTextRight(selection));
    }
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
        case MENU_RUN:
            if (sItemFunctionsRun[id].drawChoices != NULL)
                sItemFunctionsRun[id].drawChoices(sOptions->sel_run[id], y);
            break;
        case MENU_DIFF:
            if (sItemFunctionsDiff[id].drawChoices != NULL)
                sItemFunctionsDiff[id].drawChoices(sOptions->sel_diff[id], y);
            break;
        case MENU_RAND:
            if (sItemFunctionsRand[id].drawChoices != NULL)
                sItemFunctionsRand[id].drawChoices(sOptions->sel_rand[id], y);
            break;
        case MENU_PRESETS:
            if (sItemFunctionsPresets[id].drawChoices != NULL)
                sItemFunctionsPresets[id].drawChoices(sOptions->sel_presets[id], y);
            break;
    }
}

static void HighlightModeMenuItem(void)
{
    int cursor = sOptions->visibleCursor[sOptions->submenu];

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
        if (sOptions->menuCursor[sOptions->submenu] == MenuItemCancel())
            gTasks[taskId].func = Task_ModeMenuSave;
        if (sOptions->menuCursor[sOptions->submenu] == MenuItemPresetsSave())
            ApplyPresets();
        if (sOptions->menuCursor[sOptions->submenu] == MenuItemPresetsCancel())
        {
            if (sOptions->submenu == MENU_PRESETS)
            {
                sOptions->submenu = MENU_RUN;
                DrawTopBarText();
                ReDrawAll();
                HighlightModeMenuItem();
                DrawDescriptionText();
            }
        }
    }
    // Exit the menu when the player presses START
    else if (JOY_NEW(START_BUTTON) && sOptions->submenu != MENU_PRESETS)
    {
        gTasks[taskId].func = Task_ModeMenuSave;
    }
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
        HighlightModeMenuItem();
        DrawDescriptionText();
    }
    else if (JOY_REPEAT(DPAD_UP))
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
        HighlightModeMenuItem();
        DrawDescriptionText();
    }
    else if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        if (sOptions->submenu == MENU_RUN)
        {
            int cursor = sOptions->menuCursor[sOptions->submenu];
            u8 previousOption = sOptions->sel_run[cursor];
            if (CheckConditions(cursor))
            {
                if (sItemFunctionsRun[cursor].processInput != NULL)
                {
                    sOptions->sel_run[cursor] = sItemFunctionsRun[cursor].processInput(previousOption);
                    ReDrawAll();
                    DrawDescriptionText();
                }

                if (previousOption != sOptions->sel_run[cursor])
                    DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
            }
        }
        else if (sOptions->submenu == MENU_DIFF)
        {
            int cursor = sOptions->menuCursor[sOptions->submenu];
            u8 previousOption = sOptions->sel_diff[cursor];
            if (CheckConditions(cursor))
            {
                if (sItemFunctionsDiff[cursor].processInput != NULL)
                {
                    sOptions->sel_diff[cursor] = sItemFunctionsDiff[cursor].processInput(previousOption);
                    ReDrawAll();
                    DrawDescriptionText();
                }

                if (previousOption != sOptions->sel_diff[cursor])
                    DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
            }
        }
        else if (sOptions->submenu == MENU_RAND)
        {
            int cursor = sOptions->menuCursor[sOptions->submenu];
            u8 previousOption = sOptions->sel_rand[cursor];
            if (CheckConditions(cursor))
            {
                if (sItemFunctionsRand[cursor].processInput != NULL)
                {
                    sOptions->sel_rand[cursor] = sItemFunctionsRand[cursor].processInput(previousOption);
                    ReDrawAll();
                    DrawDescriptionText();
                }

                if (previousOption != sOptions->sel_rand[cursor])
                    DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
            }
        }
        else if (sOptions->submenu == MENU_PRESETS)
        {
            int cursor = sOptions->menuCursor[sOptions->submenu];
            u8 previousOption = sOptions->sel_presets[cursor];
            if (CheckConditions(cursor))
            {
                if (sItemFunctionsPresets[cursor].processInput != NULL)
                {
                    sOptions->sel_presets[cursor] = sItemFunctionsPresets[cursor].processInput(previousOption);
                    ReDrawAll();
                    DrawDescriptionText();
                }

                if (previousOption != sOptions->sel_presets[cursor])
                    DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
            }
        }
    }
    else if (JOY_NEW(R_BUTTON))
    {
        if (sOptions->submenu != MENU_PRESETS)
        {
            if (sOptions->submenu == MENU_RAND)
                sOptions->submenu = MENU_RUN;
            else
                sOptions->submenu++;

            DrawTopBarText();
            ReDrawAll();
            HighlightModeMenuItem();
            DrawDescriptionText();
        }
    }
    else if (JOY_NEW(L_BUTTON))
    {
        if (sOptions->submenu != MENU_PRESETS)
        {
            if (sOptions->submenu == MENU_RUN)
                sOptions->submenu = MENU_RAND;
            else
                sOptions->submenu--;
            
            DrawTopBarText();
            ReDrawAll();
            HighlightModeMenuItem();
            DrawDescriptionText();
        }
    }
    else if (JOY_NEW(SELECT_BUTTON))
    {
        if (sOptions->submenu != MENU_PRESETS)
            sOptions->submenu = MENU_PRESETS;
        else
            sOptions->submenu = MENU_RUN;

        DrawTopBarText();
        ReDrawAll();
        HighlightModeMenuItem();
        DrawDescriptionText();
    }
    else if (JOY_NEW(B_BUTTON)) //return from Presets view
    {
        if (sOptions->submenu == MENU_PRESETS)
        {
            sOptions->submenu = MENU_RUN;
            DrawTopBarText();
            ReDrawAll();
            HighlightModeMenuItem();
            DrawDescriptionText();
        }
    }
}

static void Task_ModeMenuSave(u8 taskId) // ToDo: add missing flags handling
{
    //write in saveblock
    //run settings
    gSaveBlock2Ptr->modeBattleMode   = sOptions->sel_run[MENUITEM_RUN_BATTLEMODE];
    gSaveBlock2Ptr->mode3MonsOnly    = sOptions->sel_run[MENUITEM_RUN_3_MONS_ONLY];
    gSaveBlock2Ptr->modeNoCaseChoice = sOptions->sel_run[MENUITEM_RUN_NO_CASE_CHOICE];
    //gSaveBlock2Ptr->modeDuplicates   = sOptions->sel_run[MENUITEM_RUN_DUPLICATES];

    //difficulty settings
    gSaveBlock2Ptr->modeXP           = sOptions->sel_diff[MENUITEM_DIFF_XPMODE];
    gSaveBlock2Ptr->modeStatChanger  = sOptions->sel_diff[MENUITEM_DIFF_STAT_CHANGER];
    gSaveBlock2Ptr->modeHealFloors10 = sOptions->sel_diff[MENUITEM_DIFF_HEALFLOORS];
    gSaveBlock2Ptr->modeLegendaries  = sOptions->sel_diff[MENUITEM_DIFF_LEGENDARIES];
    #ifdef PIT_GEN_9_MODE
    gSaveBlock2Ptr->modeMegas        = sOptions->sel_diff[MENUITEM_DIFF_MEGAS];
    #endif
    gSaveBlock2Ptr->modeCashRewards  = sOptions->sel_diff[MENUITEM_DIFF_DOUBLE_CASH];
    gSaveBlock2Ptr->modeSaveDeletion = sOptions->sel_diff[MENUITEM_DIFF_SAVE_DELETION];

    //randomizer settings
    gSaveBlock2Ptr->randomMoves      = !(sOptions->sel_rand[MENUITEM_RAND_MOVES]);
    gSaveBlock2Ptr->randomAbilities  = !(sOptions->sel_rand[MENUITEM_RAND_ABILITIES]);
    gSaveBlock2Ptr->randomBST        = !(sOptions->sel_rand[MENUITEM_RAND_BASE_STATS]);
    gSaveBlock2Ptr->randomType       = !(sOptions->sel_rand[MENUITEM_RAND_TYPES]);
    //gSaveBlock2Ptr->randomEvos       = sOptions->sel_rand[MENUITEM_RAND_EVOS];


    //set flags/vars
    if (sOptions->sel_run[MENUITEM_RUN_BATTLEMODE] == MODE_DOUBLES)
        FlagSet(FLAG_DOUBLES_MODE);
    else if(sOptions->sel_run[MENUITEM_RUN_BATTLEMODE] == MODE_MIXED_SINGLES_AND_DOUBLES)
    {
        FlagSet(FLAG_MIXED_DOUBLES_MODE);
        FlagClear(FLAG_DOUBLES_MODE);
    }
    else
    {
        FlagClear(FLAG_DOUBLES_MODE);
        FlagClear(FLAG_MIXED_DOUBLES_MODE);
    }
        
    /*if (sOptions->sel_run[MENUITEM_RUN_RANDOMIZER] == RANDOM_ALL)
        FlagSet(FLAG_RANDOM_MODE);
    else
        FlagClear(FLAG_RANDOM_MODE);*/

    if (sOptions->sel_diff[MENUITEM_DIFF_XPMODE] == XP_NONE)
        FlagSet(FLAG_NO_EXP_MODE);
    else
        FlagClear(FLAG_NO_EXP_MODE);

    if (sOptions->sel_diff[MENUITEM_DIFF_XPMODE] == XP_50)
        FlagSet(FLAG_XPSHARE_50);
    else
        FlagClear(FLAG_XPSHARE_50);
    
    if (sOptions->sel_diff[MENUITEM_DIFF_STAT_CHANGER] == ACTIVE)
        FlagSet(FLAG_STAT_CHANGER);
    else
        FlagClear(FLAG_STAT_CHANGER);

    if (sOptions->sel_diff[MENUITEM_DIFF_LEGENDARIES] == NO)
        FlagSet(FLAG_NO_LEGENDARIES);
    else
        FlagClear(FLAG_NO_LEGENDARIES);

    /*
    if (sOptions->sel_run[MENUITEM_RUN_DUPLICATES] == NO)
        FlagSet(FLAG_NO_DUPLICATES);
    else
        FlagClear(FLAG_NO_DUPLICATES);*/

    #ifdef PIT_GEN_9_MODE
    if (sOptions->sel_diff[MENUITEM_DIFF_MEGAS] == MEGAS_OFF)
        FlagClear(FLAG_MEGAS);
    else
        FlagSet(FLAG_MEGAS);
    #endif

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
            sOptions->arrowTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 240 / 2, 20, 110, MenuItemCount() - 1, 110, 110, 0);

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
static const u8 sText_BattleMode_Singles[]  = _("SNGLS");
static const u8 sText_BattleMode_Doubles[]  = _("DUOS");
static const u8 sText_BattleMode_Mix[]      = _("MIX");
static const u8 sText_Randomizer_Mons[]     = _("MONS");
static const u8 sText_Randomizer_All[]      = _("ALL");
static const u8 sText_XPShare_75[]          = _("NORMAL");
static const u8 sText_XPShare_50[]          = _("HARD");
static const u8 sText_XPShare_None[]        = _("NONE");
static const u8 sText_StatChanger_On[]      = _("ACTIVE");
static const u8 sText_StatChanger_Off[]     = _("INACTIVE");
static const u8 sText_Choice_Yes[]          = _("YES");
static const u8 sText_Choice_No[]           = _("NO");
static const u8 sText_HealFloors_5[]        = _("5FLRS");
static const u8 sText_HealFloors_10[]       = _("10FLRS");

/*static void DrawChoices_Autosave(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RUN_AUTOSAVE);
    u8 styles[3] = {0};
    int xMid;

    styles[selection] = 1;
    xMid = GetMiddleX(sText_Autosave_Off, sText_Autosave_5, sText_Autosave_On);

    DrawModeMenuChoice(sText_Autosave_Off, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_Autosave_5, xMid, y, styles[1], active);
    DrawModeMenuChoice(sText_Autosave_On, GetStringRightAlignXOffset(1, sText_Autosave_On, 198), y, styles[2], active);
}*/

static void DrawChoices_3MonsOnly(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RUN_3_MONS_ONLY);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_Choice_Yes, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_Choice_No, GetStringRightAlignXOffset(FONT_NORMAL, sText_Choice_No, 198), y, styles[1], active);
}

static void DrawChoices_NoCaseChoice(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RUN_NO_CASE_CHOICE);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_Choice_Yes, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_Choice_No, GetStringRightAlignXOffset(FONT_NORMAL, sText_Choice_No, 198), y, styles[1], active);
}

static void DrawChoices_SaveDeletion(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_DIFF_SAVE_DELETION);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_Choice_Yes, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_Choice_No, GetStringRightAlignXOffset(FONT_NORMAL, sText_Choice_No, 198), y, styles[1], active);
}

static void DrawChoices_DoubleCash(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_DIFF_DOUBLE_CASH);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_Choice_Yes, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_Choice_No, GetStringRightAlignXOffset(FONT_NORMAL, sText_Choice_No, 198), y, styles[1], active);
}

static void DrawChoices_HealFloors(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_DIFF_HEALFLOORS);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_HealFloors_5, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_HealFloors_10, GetStringRightAlignXOffset(FONT_NORMAL, sText_HealFloors_10, 198), y, styles[1], active);
}

static void DrawChoices_BattleMode(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RUN_BATTLEMODE);
    u8 styles[3] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_BattleMode_Singles, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_BattleMode_Doubles, GetStringRightAlignXOffset(FONT_NORMAL, sText_BattleMode_Doubles, 198 - 29), y, styles[1], active);
    DrawModeMenuChoice(sText_BattleMode_Mix, GetStringRightAlignXOffset(FONT_NORMAL, sText_BattleMode_Mix, 198), y, styles[2], active);
}

/*static void DrawChoices_Randomizer(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RUN_RANDOMIZER);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_Randomizer_Mons, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_Randomizer_All, GetStringRightAlignXOffset(FONT_NORMAL, sText_Randomizer_All, 198), y, styles[1], active);
}*/

static void DrawChoices_XPMode(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_DIFF_XPMODE);
    u8 styles[3] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_XPShare_75, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_XPShare_50, GetStringRightAlignXOffset(FONT_NORMAL, sText_XPShare_50, 198 - 29), y, styles[1], active);
    DrawModeMenuChoice(sText_XPShare_None, GetStringRightAlignXOffset(FONT_NORMAL, sText_XPShare_None, 198), y, styles[2], active);
}

static void DrawChoices_StatChanger(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_DIFF_STAT_CHANGER);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_StatChanger_On, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_StatChanger_Off, GetStringRightAlignXOffset(FONT_NORMAL, sText_StatChanger_Off, 198), y, styles[1], active);
}

static void DrawChoices_Legendaries(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_DIFF_LEGENDARIES);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_Choice_Yes, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_Choice_No, GetStringRightAlignXOffset(FONT_NORMAL, sText_Choice_No, 198), y, styles[1], active);
}

static void DrawChoices_Duplicates(int selection, int y)
{
    bool8 active = TRUE;//CheckConditions(MENUITEM_RUN_DUPLICATES);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_Choice_Yes, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_Choice_No, GetStringRightAlignXOffset(FONT_NORMAL, sText_Choice_No, 198), y, styles[1], active);
}

#ifdef PIT_GEN_9_MODE
static void DrawChoices_Megas(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_DIFF_MEGAS);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_Choice_Yes, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_Choice_No, GetStringRightAlignXOffset(FONT_NORMAL, sText_Choice_No, 198), y, styles[1], active);
}
#endif

static void DrawChoices_RandMoves(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RAND_MOVES);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_Choice_Yes, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_Choice_No, GetStringRightAlignXOffset(FONT_NORMAL, sText_Choice_No, 198), y, styles[1], active);
}

static void DrawChoices_RandAbilities(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RAND_ABILITIES);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_Choice_Yes, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_Choice_No, GetStringRightAlignXOffset(FONT_NORMAL, sText_Choice_No, 198), y, styles[1], active);
}

static void DrawChoices_RandStats(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RAND_BASE_STATS);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_Choice_Yes, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_Choice_No, GetStringRightAlignXOffset(FONT_NORMAL, sText_Choice_No, 198), y, styles[1], active);
}

static void DrawChoices_RandTypes(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RAND_TYPES);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_Choice_Yes, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_Choice_No, GetStringRightAlignXOffset(FONT_NORMAL, sText_Choice_No, 198), y, styles[1], active);
}

/*static void DrawChoices_RandEvos(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RAND_EVOS);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_Choice_Yes, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_Choice_No, GetStringRightAlignXOffset(FONT_NORMAL, sText_Choice_No, 198), y, styles[1], active);
}*/

static void DrawChoices_PresetsMode(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_PRESET_MODE);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawModeMenuChoice(sText_ModeNormal, 104, y, styles[0], active);
    DrawModeMenuChoice(sText_ModeHard, GetStringRightAlignXOffset(FONT_NORMAL, sText_ModeHard, 198), y, styles[1], active);
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

static void ApplyPresets(void)
{
    int cursor = sOptions->visibleCursor[sOptions->submenu];

    //general defaults:
    //run settings
    sOptions->sel_run[MENUITEM_RUN_BATTLEMODE]      = MODE_MIXED_SINGLES_AND_DOUBLES;
    sOptions->sel_run[MENUITEM_RUN_3_MONS_ONLY]     = NO;
    sOptions->sel_run[MENUITEM_RUN_NO_CASE_CHOICE]  = NO;
    //difficulty settings
    sOptions->sel_diff[MENUITEM_DIFF_DOUBLE_CASH]   = NO;
    sOptions->sel_diff[MENUITEM_DIFF_HEALFLOORS]    = HEAL_FLOORS_5;
    //randomizer settings
    sOptions->sel_rand[MENUITEM_RAND_MOVES]         = NO;
    sOptions->sel_rand[MENUITEM_RAND_ABILITIES]     = NO;
    sOptions->sel_rand[MENUITEM_RAND_BASE_STATS]    = NO;
    sOptions->sel_rand[MENUITEM_RAND_TYPES]         = NO;

    switch(sOptions->sel_presets[MENUITEM_PRESET_MODE])
    {
        case PRESET_NORMAL:
            sOptions->sel_diff[MENUITEM_DIFF_XPMODE]        = XP_75;
            sOptions->sel_diff[MENUITEM_DIFF_SAVE_DELETION] = NO;
            sOptions->sel_diff[MENUITEM_DIFF_STAT_CHANGER]  = ACTIVE;
            sOptions->sel_diff[MENUITEM_DIFF_LEGENDARIES]   = YES;
            #ifdef PIT_GEN_9_MODE
            sOptions->sel_diff[MENUITEM_DIFF_MEGAS]         = MEGAS_OFF;
            #endif
            break;
        case PRESET_HARD:
            sOptions->sel_diff[MENUITEM_DIFF_XPMODE]        = XP_50;
            sOptions->sel_diff[MENUITEM_DIFF_SAVE_DELETION] = YES;
            sOptions->sel_diff[MENUITEM_DIFF_STAT_CHANGER]  = INACTIVE;
            sOptions->sel_diff[MENUITEM_DIFF_LEGENDARIES]   = NO;
            #ifdef PIT_GEN_9_MODE
            sOptions->sel_diff[MENUITEM_DIFF_MEGAS]         = MEGAS_ON;
            #endif
            break;
        default:
            break;
    }

    //return to mode menu
    if (sOptions->submenu == MENU_PRESETS)
    {
        sOptions->submenu = MENU_RUN;
        DrawTopBarText();
        ReDrawAll();
        HighlightModeMenuItem();
        DrawDescriptionText();
    }
}
