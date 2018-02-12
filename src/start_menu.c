#include "global.h"
#include "start_menu.h"
#include "menu.h"
#include "safari_zone.h"
#include "event_data.h"
#include "window.h"
#include "string_util.h"
#include "text.h"
#include "strings.h"
#include "bg.h"

// Menu actions
enum
{
    MENU_ACTION_POKEDEX,
    MENU_ACTION_POKEMON,
    MENU_ACTION_BAG,
    MENU_ACTION_POKENAV,
    MENU_ACTION_PLAYER,
    MENU_ACTION_SAVE,
    MENU_ACTION_OPTION,
    MENU_ACTION_EXIT,
    MENU_ACTION_RETIRE_SAFARI,
    MENU_ACTION_PLAYER_LINK,
    MENU_ACTION_REST_FRONTIER,
    MENU_ACTION_RETIRE_FRONTIER,
    MENU_ACTION_PYRAMID_BAG
};

extern bool32 is_c1_link_related_active(void);
extern bool32 InUnionRoom(void);
extern bool8 InBattlePike(void);
extern bool8 InBattlePyramid(void);
extern bool8 InMultiBattleRoom(void);
extern void NewMenuHelpers_DrawStdWindowFrame(u8 windowId, u8 a1);
extern void sub_8198070(u8 windowId, u8 a1);

// this file's functions
static void BuildStartMenuActions_LinkMode(void);
static void BuildStartMenuActions_UnionRoom(void);
static void BuildStartMenuActions_SafariZone(void);
static void BuildStartMenuActions_BattlePike(void);
static void BuildStartMenuActions_BattlePyramid(void);
static void BuildStartMenuActions_MultiBattleRoom(void);
static void BuildStartMenuActions_Normal(void);
bool8 StartMenu_Pokedex(void);
bool8 StartMenu_Pokemon(void);
bool8 StartMenu_Bag(void);
bool8 StartMenu_PokeNav(void);
bool8 StartMenu_PlayerName(void);
bool8 StartMenu_Save(void);
bool8 StartMenu_Option(void);
bool8 StartMenu_Exit(void);
bool8 StartMenu_SafariZoneRetire(void);
bool8 StartMenu_LinkModePlayerName(void);
bool8 StartMenu_BattlePyramidRetire(void);
bool8 StartMenu_BattlePyramidBag(void);

// EWRAM vars
EWRAM_DATA u8 sSafariBallsWindowId = 0;
EWRAM_DATA u8 sBattlePyramidFloorWindowId = 0;
EWRAM_DATA u8 sStartMenuCursorPos = 0;
EWRAM_DATA u8 sNumStartMenuActions = 0;
EWRAM_DATA u8 sCurrentStartMenuActions[9] = {0};
EWRAM_DATA u8 gUnknown_02037619[2] = {0};
EWRAM_DATA bool8 (*gUnknown_0203761C)(void) = NULL;
EWRAM_DATA u8 gUnknown_02037620 = 0;
EWRAM_DATA u8 gUnknown_02037621 = 0;
EWRAM_DATA u8 gUnknown_02037622 = 0;

// const rom data
static const struct WindowTemplate gSafariBallsWindowTemplate = {0, 1, 1, 9, 4, 0xF, 8};

static const u8* const sPyramindFloorNames[] =
{
    gText_Floor1,
    gText_Floor2,
    gText_Floor3,
    gText_Floor4,
    gText_Floor5,
    gText_Floor6,
    gText_Floor7,
    gText_Peak
};

static const struct WindowTemplate gPyramidFloorWindowTemplate_2 = {0, 1, 1, 0xA, 4, 0xF, 8};
static const struct WindowTemplate gPyramidFloorWindowTemplate_1 = {0, 1, 1, 0xC, 4, 0xF, 8};

const struct MenuAction sStartMenuItems[] =
{
    {gText_MenuPokedex, {.u8_void = StartMenu_Pokedex}},
    {gText_MenuPokemon, {.u8_void = StartMenu_Pokemon}},
    {gText_MenuBag, {.u8_void = StartMenu_Bag}},
    {gText_MenuPokenav, {.u8_void = StartMenu_PokeNav}},
    {gText_MenuPlayer, {.u8_void = StartMenu_PlayerName}},
    {gText_MenuSave, {.u8_void = StartMenu_Save}},
    {gText_MenuOption, {.u8_void = StartMenu_Option}},
    {gText_MenuExit, {.u8_void = StartMenu_Exit}},
    {gText_MenuRetire, {.u8_void = StartMenu_SafariZoneRetire}},
    {gText_MenuPlayer, {.u8_void = StartMenu_LinkModePlayerName}},
    {gText_MenuRest, {.u8_void = StartMenu_Save}},
    {gText_MenuRetire, {.u8_void = StartMenu_BattlePyramidRetire}},
    {gText_MenuBag, {.u8_void = StartMenu_BattlePyramidBag}}
};

const struct BgTemplate gUnknown_085105A8[] =
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

const struct WindowTemplate gUnknown_085105AC[] =
{
    {0, 2, 0xF, 0x1A, 4, 0xF, 0x194},
    DUMMY_WIN_TEMPLATE
};

const struct WindowTemplate gUnknown_085105BC = {0, 1, 1, 0xE, 0xA, 0xF, 8};

// code
void SetDexPokemonPokenavFlags(void) // unused
{
    FlagSet(FLAG_SYS_POKEDEX_GET);
    FlagSet(FLAG_SYS_POKEMON_GET);
    FlagSet(FLAG_SYS_POKENAV_GET);
}

void BuildStartMenuActions(void)
{
    sNumStartMenuActions = 0;
    if (is_c1_link_related_active() == TRUE)
        BuildStartMenuActions_LinkMode();
    else if (InUnionRoom() == TRUE)
        BuildStartMenuActions_UnionRoom();
    else if (GetSafariZoneFlag() == TRUE)
        BuildStartMenuActions_SafariZone();
    else if (InBattlePike())
        BuildStartMenuActions_BattlePike();
    else if (InBattlePyramid())
        BuildStartMenuActions_BattlePyramid();
    else if (InMultiBattleRoom())
        BuildStartMenuActions_MultiBattleRoom();
    else
        BuildStartMenuActions_Normal();
}

void AddStartMenuAction(u8 action)
{
    AppendToList(sCurrentStartMenuActions, &sNumStartMenuActions, action);
}

static void BuildStartMenuActions_Normal(void)
{
    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKEDEX);
    if (FlagGet(FLAG_SYS_POKEMON_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);
    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKENAV);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_SAVE);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildStartMenuActions_SafariZone(void)
{
    AddStartMenuAction(MENU_ACTION_RETIRE_SAFARI);
    AddStartMenuAction(MENU_ACTION_POKEDEX);
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildStartMenuActions_LinkMode(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);
    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKENAV);
    AddStartMenuAction(MENU_ACTION_PLAYER_LINK);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildStartMenuActions_UnionRoom(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);
    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKENAV);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildStartMenuActions_BattlePike(void)
{
    AddStartMenuAction(MENU_ACTION_POKEDEX);
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildStartMenuActions_BattlePyramid(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_PYRAMID_BAG);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_REST_FRONTIER);
    AddStartMenuAction(MENU_ACTION_RETIRE_FRONTIER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildStartMenuActions_MultiBattleRoom(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

void DisplaySafariBallsWindow(void)
{
    sSafariBallsWindowId = AddWindow(&gSafariBallsWindowTemplate);
    PutWindowTilemap(sSafariBallsWindowId);
    NewMenuHelpers_DrawStdWindowFrame(sSafariBallsWindowId, 0);
    ConvertIntToDecimalStringN(gStringVar1, gNumSafariBalls, STR_CONV_MODE_RIGHT_ALIGN, 2);
    StringExpandPlaceholders(gStringVar4, gText_SafariBallStock);
    PrintTextOnWindow(sSafariBallsWindowId, 1, gStringVar4, 0, 1, 0xFF, NULL);
    CopyWindowToVram(sSafariBallsWindowId, 2);
}

void DisplayPyramidFloorWindow(void)
{
    // TODO: fix location
    if (gSaveBlock2Ptr->field_CAA[4] == 7)
        sBattlePyramidFloorWindowId = AddWindow(&gPyramidFloorWindowTemplate_1);
    else
        sBattlePyramidFloorWindowId = AddWindow(&gPyramidFloorWindowTemplate_2);
    PutWindowTilemap(sBattlePyramidFloorWindowId);
    NewMenuHelpers_DrawStdWindowFrame(sBattlePyramidFloorWindowId, 0);
    StringCopy(gStringVar1, sPyramindFloorNames[gSaveBlock2Ptr->field_CAA[4]]);
    StringExpandPlaceholders(gStringVar4, gText_BattlePyramidFloor);
    PrintTextOnWindow(sBattlePyramidFloorWindowId, 1, gStringVar4, 0, 1, 0xFF, NULL);
    CopyWindowToVram(sBattlePyramidFloorWindowId, 2);
}

void RemoveExtraStartMenuWindows(void)
{
    if (GetSafariZoneFlag())
    {
        sub_8198070(sSafariBallsWindowId, 0);
        CopyWindowToVram(sSafariBallsWindowId, 2);
        RemoveWindow(sSafariBallsWindowId);
    }
    if (InBattlePyramid())
    {
        sub_8198070(sBattlePyramidFloorWindowId, 0);
        RemoveWindow(sBattlePyramidFloorWindowId);
    }
}

/*
// Prints n menu items starting at *index
static bool32 PrintStartMenuItemsMultistep(s16 *index, u32 n)
{
    s8 _index = *index;

    do
    {
        if (sStartMenuItems[sCurrentStartMenuActions[_index]].func.u8_void == StartMenu_PlayerName)
        {

        }
        else
        {

        }

    } while (++_index > sNumStartMenuActions);

    if (--n == 0)
    {
        *index = _index;
        return FALSE;
    }
    else
    {
        *index = _index;
        return TRUE;
    }
}*/
