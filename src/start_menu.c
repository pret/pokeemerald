#include "global.h"
#include "start_menu.h"
#include "menu.h"
#include "safari_zone.h"
#include "event_data.h"
#include "window.h"
#include "string_util.h"
#include "text.h"

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

static void BuildStartMenuActions_LinkMode(void);
static void BuildStartMenuActions_UnionRoom(void);
static void BuildStartMenuActions_SafariZone(void);
static void BuildStartMenuActions_BattlePike(void);
static void BuildStartMenuActions_BattlePyramid(void);
static void BuildStartMenuActions_MultiBattleRoom(void);
static void BuildStartMenuActions_Normal(void);
u8 StartMenu_PlayerName(void);

extern bool32 is_c1_link_related_active(void);
extern bool32 InUnionRoom(void);
extern bool8 InBattlePike(void);
extern bool8 InBattlePyramid(void);
extern bool8 InMultiBattleRoom(void);
extern void sub_81973FC(u8 windowId, u8 a1);
extern void sub_8198070(u8 windowId, u8 a1);

EWRAM_DATA u8 sSafariBallsWindowId = 0;
EWRAM_DATA u8 sBattlePyramidFloorWindowId = 0;
EWRAM_DATA u8 sStartMenuCursorPos = 0;
EWRAM_DATA u8 sNumStartMenuActions = 0;
EWRAM_DATA u8 sCurrentStartMenuActions[9] = {0};

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
    if (FlagGet(SYS_POKEDEX_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKEDEX);
    if (FlagGet(SYS_POKEMON_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);
    if (FlagGet(SYS_POKENAV_GET) == TRUE)
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
    if (FlagGet(SYS_POKENAV_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKENAV);
    AddStartMenuAction(MENU_ACTION_PLAYER_LINK);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildStartMenuActions_UnionRoom(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);
    if (FlagGet(SYS_POKENAV_GET) == TRUE)
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

extern const struct WindowTemplate gSafariBallsWindowTemplate;
extern const struct WindowTemplate gPyramidFloorWindowTemplate_1;
extern const struct WindowTemplate gPyramidFloorWindowTemplate_2;
extern const u8 gText_SafariBallStock[];

void DisplaySafariBallsWindow(void)
{
    sSafariBallsWindowId = AddWindow(&gSafariBallsWindowTemplate);
    PutWindowTilemap(sSafariBallsWindowId);
    sub_81973FC(sSafariBallsWindowId, 0);
    ConvertIntToDecimalStringN(gStringVar1, gNumSafariBalls, STR_CONV_MODE_RIGHT_ALIGN, 2);
    StringExpandPlaceholders(gStringVar4, gText_SafariBallStock);
    PrintTextOnWindow(sSafariBallsWindowId, 1, gStringVar4, 0, 1, 0xFF, NULL);
    CopyWindowToVram(sSafariBallsWindowId, 2);
}

extern const u8* const gUnknown_08510510[];
extern const u8 gText_BattlePyramidFloor[];

void DisplayPyramidFloorWindow(void)
{
    // TODO: fix location
    if (gSaveBlock2Ptr->field_CAA[4] == 7)
        sBattlePyramidFloorWindowId = AddWindow(&gPyramidFloorWindowTemplate_1);
    else
        sBattlePyramidFloorWindowId = AddWindow(&gPyramidFloorWindowTemplate_2);
    PutWindowTilemap(sBattlePyramidFloorWindowId);
    sub_81973FC(sBattlePyramidFloorWindowId, 0);
    StringCopy(gStringVar1, gUnknown_08510510[gSaveBlock2Ptr->field_CAA[4]]);
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

extern const struct MenuAction sStartMenuItems[];

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
