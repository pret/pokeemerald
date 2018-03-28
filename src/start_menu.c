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
#include "field_effect.h"
#include "task.h"
#include "overworld.h"
#include "link.h"
#include "battle_frontier_2.h"
#include "rom_818CFC8.h"
#include "field_specials.h"
#include "field_map_obj_helpers.h"
#include "script.h"
#include "main.h"
#include "sound.h"
#include "pokedex.h"
#include "field_weather.h"
#include "palette.h"
#include "item_menu.h"
#include "option_menu.h"
#include "event_scripts.h"
#include "save.h"
#include "gpu_regs.h"
#include "scanline_effect.h"
#include "text_window.h"
#include "load_save.h"
#include "international_string_util.h"

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

// Save status
enum
{
    SAVE_IN_PROGRESS,
    SAVE_SUCCESS,
    SAVE_CANCELED,
    SAVE_ERROR
};

EWRAM_DATA static u8 sSafariBallsWindowId = 0;
EWRAM_DATA static u8 sBattlePyramidFloorWindowId = 0;
EWRAM_DATA static u8 sStartMenuCursorPos = 0;
EWRAM_DATA static u8 sNumStartMenuActions = 0;
EWRAM_DATA static u8 sCurrentStartMenuActions[9] = {0};
EWRAM_DATA static u8 sUnknown_02037619[2] = {0};

EWRAM_DATA static u8 (*sSaveDialogCallback)(void) = NULL;
EWRAM_DATA static u8 sSaveDialogTimer = 0;
EWRAM_DATA static bool8 sSavingComplete = FALSE;
EWRAM_DATA static u8 sSaveWindowId = 0;

// Extern variables
extern u8 gDifferentSaveFile;
extern u16 gSaveFileStatus;
extern u8 gUnknown_03005DB4;

// Extern functions in uncompiled files
extern void sub_80AF688(void);
extern void var_800D_set_xB(void);
extern void sub_808B864(void);
extern void sub_808BCF4(void);
extern void sub_80BB534(void);
extern void play_some_sound(void);
extern void CB2_PartyMenuFromStartMenu(void);
extern void CB2_PokeNav(void);
extern void sub_80C4DDC(void (*)(void));
extern void sub_80C51C4(void (*)(void));
extern void sub_80C4E74(u8, void (*)(void));
extern void sub_81C4EFC(void);
extern void sub_80984F4(void);
extern void sub_81A9EC8(void);
extern void save_serialize_map(void);
extern void sub_81A9E90(void);

// Menu action callbacks
static bool8 StartMenuPokedexCallback(void);
static bool8 StartMenuPokemonCallback(void);
static bool8 StartMenuBagCallback(void);
static bool8 StartMenuPokeNavCallback(void);
static bool8 StartMenuPlayerNameCallback(void);
static bool8 StartMenuSaveCallback(void);
static bool8 StartMenuOptionCallback(void);
static bool8 StartMenuExitCallback(void);
static bool8 StartMenuSafariZoneRetireCallback(void);
static bool8 StartMenuLinkModePlayerNameCallback(void);
static bool8 StartMenuBattlePyramidRetireCallback(void);
static bool8 StartMenuBattlePyramidBagCallback(void);

// Menu callbacks
static bool8 sub_809FE28(void);
static bool8 sub_809FE44(void);
static bool8 sub_809FE9C(void);
static bool8 sub_809FEB8(void);
static bool8 sub_809FED4(void);
static bool8 HandleStartMenuInput(void);

// Save dialog callbacks
static u8 sub_80A00A0(void);
static u8 sub_80A00EC(void);
static u8 sub_80A0108(void);
static u8 sub_80A017C(void);
static u8 sub_80A01B4(void);
static u8 sub_80A01D0(void);
static u8 sub_80A01EC(void);
static u8 sub_80A0234(void);
static u8 sub_80A024C(void);
static u8 sub_80A02B0(void);
static u8 sub_80A02D8(void);
static u8 sub_80A02FC(void);
static u8 sub_80A0324(void);
static u8 sub_80A035C(void);
static u8 sub_80A0388(void);
static u8 sub_80A03A4(void);

// Task callbacks
static void task50_startmenu(u8 taskId);
static void task50_save_game(u8 taskId);
static void sub_80A0550(u8 taskId);
static void sub_80A08A4(u8 taskId);

// Some callback
static bool8 sub_809FA00(void);

// Local functions
static void BuildStartMenuActions(void);
static void AddStartMenuAction(u8 action);
static void BuildNormalStartMenu(void);
static void BuildSafariZoneStartMenu(void);
static void BuildLinkModeStartMenu(void);
static void BuildUnionRoomStartMenu(void);
static void BuildBattlePikeStartMenu(void);
static void BuildBattlePyramidStartMenu(void);
static void BuildMultiBattleRoomStartMenu(void);
static void DisplaySafariBallsWindow(void);
static void DisplayPyramidFloorWindow(void);
static void RemoveExtraStartMenuWindows(void);
static bool32 PrintStartMenuActions(s8 *pIndex, u32 count);
static bool32 sub_809F894(void);
static void InitStartMenu(void);
static void sub_809F9D0(TaskFunc followupFunc);
static void sub_809FF28(void);
static u8 sub_809FF4C(void);
static void sub_809FF98(const u8 *message, u8 (*saveCallback)(void));
static void sub_80A0014(void);
static void sub_80A0024(void);
static void sub_80A0030(void);
static bool8 sub_80A003C(void);
static bool8 sub_80A0070(void);
static void sub_80A0340(void);
static void sub_80A03D8(void);
static bool32 sub_80A03E4(u8 *par1);
static void sub_80A0540(void);
static void sub_80A06B4(void);
static void sub_80A0888(void);
static void sub_80A0914(void);

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
    {gText_MenuPokedex, {.u8_void = StartMenuPokedexCallback}},
    {gText_MenuPokemon, {.u8_void = StartMenuPokemonCallback}},
    {gText_MenuBag, {.u8_void = StartMenuBagCallback}},
    {gText_MenuPokenav, {.u8_void = StartMenuPokeNavCallback}},
    {gText_MenuPlayer, {.u8_void = StartMenuPlayerNameCallback}},
    {gText_MenuSave, {.u8_void = StartMenuSaveCallback}},
    {gText_MenuOption, {.u8_void = StartMenuOptionCallback}},
    {gText_MenuExit, {.u8_void = StartMenuExitCallback}},
    {gText_MenuRetire, {.u8_void = StartMenuSafariZoneRetireCallback}},
    {gText_MenuPlayer, {.u8_void = StartMenuLinkModePlayerNameCallback}},
    {gText_MenuRest, {.u8_void = StartMenuSaveCallback}},
    {gText_MenuRetire, {.u8_void = StartMenuBattlePyramidRetireCallback}},
    {gText_MenuBag, {.u8_void = StartMenuBattlePyramidBagCallback}}
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

const struct WindowTemplate gSaveInfoWindowTemplate = {0, 1, 1, 0xE, 0xA, 0xF, 8};

void SetDexPokemonPokenavFlags(void) // unused
{
    FlagSet(FLAG_SYS_POKEDEX_GET);
    FlagSet(FLAG_SYS_POKEMON_GET);
    FlagSet(FLAG_SYS_POKENAV_GET);
}

static void BuildStartMenuActions(void)
{
    sNumStartMenuActions = 0;
    if (is_c1_link_related_active() == TRUE)
        BuildLinkModeStartMenu();
    else if (InUnionRoom() == TRUE)
        BuildUnionRoomStartMenu();
    else if (GetSafariZoneFlag() == TRUE)
        BuildSafariZoneStartMenu();
    else if (InBattlePike())
        BuildBattlePikeStartMenu();
    else if (InBattlePyramid())
        BuildBattlePyramidStartMenu();
    else if (InMultiBattleRoom())
        BuildMultiBattleRoomStartMenu();
    else
        BuildNormalStartMenu();
}

static void AddStartMenuAction(u8 action)
{
    AppendToList(sCurrentStartMenuActions, &sNumStartMenuActions, action);
}

static void BuildNormalStartMenu(void)
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

static void BuildSafariZoneStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_RETIRE_SAFARI);
    AddStartMenuAction(MENU_ACTION_POKEDEX);
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildLinkModeStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);
    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKENAV);
    AddStartMenuAction(MENU_ACTION_PLAYER_LINK);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildUnionRoomStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);
    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKENAV);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildBattlePikeStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEDEX);
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildBattlePyramidStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_PYRAMID_BAG);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_REST_FRONTIER);
    AddStartMenuAction(MENU_ACTION_RETIRE_FRONTIER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildMultiBattleRoomStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void DisplaySafariBallsWindow(void)
{
    sSafariBallsWindowId = AddWindow(&gSafariBallsWindowTemplate);
    PutWindowTilemap(sSafariBallsWindowId);
    NewMenuHelpers_DrawStdWindowFrame(sSafariBallsWindowId, FALSE);
    ConvertIntToDecimalStringN(gStringVar1, gNumSafariBalls, STR_CONV_MODE_RIGHT_ALIGN, 2);
    StringExpandPlaceholders(gStringVar4, gText_SafariBallStock);
    PrintTextOnWindow(sSafariBallsWindowId, 1, gStringVar4, 0, 1, 0xFF, NULL);
    CopyWindowToVram(sSafariBallsWindowId, 2);
}

static void DisplayPyramidFloorWindow(void)
{
    // TODO: fix location
    if (gSaveBlock2Ptr->field_CAA[4] == 7)
    {
        sBattlePyramidFloorWindowId = AddWindow(&gPyramidFloorWindowTemplate_1);
    }
    else
    {
        sBattlePyramidFloorWindowId = AddWindow(&gPyramidFloorWindowTemplate_2);
    }

    PutWindowTilemap(sBattlePyramidFloorWindowId);
    NewMenuHelpers_DrawStdWindowFrame(sBattlePyramidFloorWindowId, FALSE);
    StringCopy(gStringVar1, sPyramindFloorNames[gSaveBlock2Ptr->field_CAA[4]]);
    StringExpandPlaceholders(gStringVar4, gText_BattlePyramidFloor);
    PrintTextOnWindow(sBattlePyramidFloorWindowId, 1, gStringVar4, 0, 1, 0xFF, NULL);
    CopyWindowToVram(sBattlePyramidFloorWindowId, 2);
}

static void RemoveExtraStartMenuWindows(void)
{
    if (GetSafariZoneFlag())
    {
        sub_8198070(sSafariBallsWindowId, FALSE);
        CopyWindowToVram(sSafariBallsWindowId, 2);
        RemoveWindow(sSafariBallsWindowId);
    }
    if (InBattlePyramid())
    {
        sub_8198070(sBattlePyramidFloorWindowId, FALSE);
        RemoveWindow(sBattlePyramidFloorWindowId);
    }
}

static bool32 PrintStartMenuActions(s8 *pIndex, u32 count)
{
    s8 index = *pIndex;
    
    do
    {
        if (sStartMenuItems[sCurrentStartMenuActions[index]].func.u8_void == StartMenuPlayerNameCallback) {
            PrintPlayerNameOnWindow(GetStartMenuWindowId(), sStartMenuItems[sCurrentStartMenuActions[index]].text, 8, (index << 4) + 9);
        }
        else {
            StringExpandPlaceholders(gStringVar4, sStartMenuItems[sCurrentStartMenuActions[index]].text);
            PrintTextOnWindow(GetStartMenuWindowId(), 1, gStringVar4, 8, (index << 4) + 9, 0xFF, NULL);
        }

        index++;
        if (index >= sNumStartMenuActions) {
            *pIndex = index;
            return TRUE;
        }

        count--;
    }
    while (count != 0);

    *pIndex = index;
    return FALSE;
}

static bool32 sub_809F894(void) 
{
    s8 value = sUnknown_02037619[0];
    switch (value) 
    {
    case 0:
        sUnknown_02037619[0]++;
        break;
    case 1:
        BuildStartMenuActions();
        sUnknown_02037619[0]++;
        break;
    case 2:
        sub_81973A4();
        NewMenuHelpers_DrawStdWindowFrame(sub_81979C4(sNumStartMenuActions), FALSE);
        sUnknown_02037619[1] = 0;
        sUnknown_02037619[0]++;
        break;
    case 3:
        if (GetSafariZoneFlag() != FALSE)
        {
            DisplaySafariBallsWindow();
        }
        if (InBattlePyramid() != FALSE) 
        {
            DisplayPyramidFloorWindow();
        }
        sUnknown_02037619[0]++;
        break;
    case 4:
        if (PrintStartMenuActions(&sUnknown_02037619[1], 2) == FALSE) 
        {
            break;
        }
        sUnknown_02037619[0]++;
        break;
    case 5:
        sStartMenuCursorPos = sub_81983AC(GetStartMenuWindowId(), 1, 0, 9, 16, sNumStartMenuActions, sStartMenuCursorPos);
        CopyWindowToVram(GetStartMenuWindowId(), TRUE);
        return TRUE;
    default:
        break;
    }

    return FALSE;
}

static void InitStartMenu(void)
{
    sUnknown_02037619[0] = 0;
    sUnknown_02037619[1] = 0;
    while (!sub_809F894());
}

static void task50_startmenu(u8 taskId)
{
    if (sub_809F894() == TRUE)
    {
        SwitchTaskToFollowupFunc(taskId);
    }
}

static void sub_809F9D0(TaskFunc followupFunc)
{
    sUnknown_02037619[0] = 0;
    sUnknown_02037619[1] = 0;
    SetTaskFuncWithFollowupFunc(CreateTask(&task50_startmenu, 0x50), &task50_startmenu, followupFunc);
}

static bool8 sub_809FA00(void) 
{
    if (sub_809F894() == FALSE)
    {
        return FALSE;
    }

    sub_80AF688();
    return TRUE;
}

void sub_809FA18(void) // Called from field_screen.s
{
    sUnknown_02037619[0] = 0;
    sUnknown_02037619[1] = 0;
    gUnknown_03005DB0 = &sub_809FA00;
}

void sub_809FA34(u8 taskId) // Called from field_screen.s and rom_8011DC0.s
{
    struct Task* task = &gTasks[taskId];

    switch(task->data[0]) 
    {
    case 0:
        if (InUnionRoom() == TRUE)
        {
            var_800D_set_xB();
        }

        gMenuCallback = HandleStartMenuInput;
        task->data[0]++;
        break;
    case 1:
        if (gMenuCallback() == TRUE)
        {
            DestroyTask(taskId);
        }
        break;
    }
}

void sub_809FA9C(void) // Called from overworld.c and field_control_avatar.s
{
    if (!is_c1_link_related_active())
    {
        FreezeMapObjects();
        sub_808B864();
        sub_808BCF4();
    }
    sub_809F9D0(sub_809FA34);
    ScriptContext2_Enable();
}

static bool8 HandleStartMenuInput(void)
{
    if (gMain.newKeys & DPAD_UP)
    {
        PlaySE(5);
        sStartMenuCursorPos = MoveMenuCursor(-1);
    }
    
    if (gMain.newKeys & DPAD_DOWN)
    {
        PlaySE(5);
        sStartMenuCursorPos = MoveMenuCursor(1);
    }
    
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(5);
        if (sStartMenuItems[sCurrentStartMenuActions[sStartMenuCursorPos]].func.u8_void == StartMenuPokedexCallback)
        {
            if (GetNationalPokedexCount(0) == 0) {
                return FALSE;
            }
        }
        
        gMenuCallback = sStartMenuItems[sCurrentStartMenuActions[sStartMenuCursorPos]].func.u8_void;
        
        if (gMenuCallback != StartMenuSaveCallback 
            && gMenuCallback != StartMenuExitCallback
            && gMenuCallback != StartMenuSafariZoneRetireCallback
            && gMenuCallback != StartMenuBattlePyramidRetireCallback)
        {
           FadeScreen(1, 0);
        }
        
        return FALSE;
    }
    
    if (gMain.newKeys & (START_BUTTON | B_BUTTON))
    {
        RemoveExtraStartMenuWindows();
        sub_80A0934();
        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuPokedexCallback(void)
{
    if (!gPaletteFade.active)
    {
        IncrementGameStat(GAME_STAT_CHECKED_POKEDEX);
        play_some_sound();
        RemoveExtraStartMenuWindows();
        overworld_free_bg_tilemaps();
        SetMainCallback2(sub_80BB534);
        
        return TRUE;
    }
    
    return FALSE;
}

static bool8 StartMenuPokemonCallback(void)
{
    if (!gPaletteFade.active)
    {
        play_some_sound();
        RemoveExtraStartMenuWindows();
        overworld_free_bg_tilemaps();
        SetMainCallback2(CB2_PartyMenuFromStartMenu);
        
        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuBagCallback(void)
{
    if (!gPaletteFade.active)
    {
        play_some_sound();
        RemoveExtraStartMenuWindows();
        overworld_free_bg_tilemaps();
        SetMainCallback2(CB2_BagMenuFromStartMenu);

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuPokeNavCallback(void)
{
    if (!gPaletteFade.active)
    {
        play_some_sound();
        RemoveExtraStartMenuWindows();
        overworld_free_bg_tilemaps();
        SetMainCallback2(CB2_PokeNav);

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuPlayerNameCallback(void)
{
    if (!gPaletteFade.active)
    {
        play_some_sound();
        RemoveExtraStartMenuWindows();
        overworld_free_bg_tilemaps();

        if (is_c1_link_related_active() || InUnionRoom())
        {
            sub_80C4DDC(CB2_ReturnToFieldWithOpenMenu);
        }
        else if (FlagGet(FLAG_SYS_FRONTIER_PASS))
        {
            sub_80C51C4(CB2_ReturnToFieldWithOpenMenu);
        }
        else 
        {
            sub_80C4DDC(CB2_ReturnToFieldWithOpenMenu);
        }

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuSaveCallback(void)
{
    if (InBattlePyramid())
    {
        RemoveExtraStartMenuWindows();
    }

    gMenuCallback = sub_809FE28;

    return FALSE;
}

static bool8 StartMenuOptionCallback(void)
{
    if (!gPaletteFade.active)
    {
        play_some_sound();
        RemoveExtraStartMenuWindows();
        overworld_free_bg_tilemaps();
        SetMainCallback2(CB2_InitOptionMenu);
        gMain.savedCallback = CB2_ReturnToFieldWithOpenMenu;

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuExitCallback(void)
{
    RemoveExtraStartMenuWindows();
    sub_80A0934();
    
    return TRUE;
}

static bool8 StartMenuSafariZoneRetireCallback(void)
{
    RemoveExtraStartMenuWindows();
    sub_80A0934();
    SafariZoneRetirePrompt();

    return TRUE;
}

static bool8 StartMenuLinkModePlayerNameCallback(void)
{
    if (!gPaletteFade.active)
    {
        play_some_sound();
        overworld_free_bg_tilemaps();
        sub_80C4E74(gUnknown_03005DB4, CB2_ReturnToFieldWithOpenMenu);

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuBattlePyramidRetireCallback(void)
{
    gMenuCallback = sub_809FE9C;

    return FALSE;
}

void sub_809FDD4(void) // Called from battle_frontier_2.s
{
    sub_8197DF8(0, 0);
    sub_80984F4();
    sub_809F9D0(sub_809FA34);
    ScriptContext2_Enable();
}

static bool8 StartMenuBattlePyramidBagCallback(void)
{
    if (!gPaletteFade.active)
    {
        play_some_sound();
        RemoveExtraStartMenuWindows();
        overworld_free_bg_tilemaps();
        SetMainCallback2(sub_81C4EFC);

        return TRUE;
    }

    return FALSE;
}

static bool8 sub_809FE28(void)
{
    sub_809FF28();
    gMenuCallback = sub_809FE44;

    return FALSE;
}

static bool8 sub_809FE44(void)
{
    switch (sub_809FF4C())
    {
    case SAVE_IN_PROGRESS:
        return FALSE;
    case SAVE_CANCELED:
        sub_8197DF8(0, 0);
        InitStartMenu();
        gMenuCallback = HandleStartMenuInput;
        return FALSE;
    case SAVE_SUCCESS:
    case SAVE_ERROR:
        sub_8197DF8(0, 1);
        sub_80984F4();
        ScriptContext2_Disable();
        sub_81A9EC8();
        return TRUE;
    }

    return FALSE;
}

static bool8 sub_809FE9C(void)
{
    sub_80A0340();
    gMenuCallback = sub_809FED4;

    return FALSE;
}

static bool8 sub_809FEB8(void)
{
    InitStartMenu();
    gMenuCallback = HandleStartMenuInput;

    return FALSE;
}

static bool8 sub_809FED4(void)
{
    switch (sub_809FF4C())
    {
    case SAVE_SUCCESS:
        RemoveExtraStartMenuWindows();
        gMenuCallback = sub_809FEB8;
        return FALSE;
    case SAVE_IN_PROGRESS:
        return FALSE;
    case SAVE_CANCELED:
        sub_8197DF8(0, 1);
        sub_80984F4();
        ScriptContext2_Disable();
        ScriptContext1_SetupScript(BattleFrontier_BattlePyramidEmptySquare_EventScript_252C88);
        return TRUE;
    }

    return FALSE;
}

static void sub_809FF28(void)
{
    save_serialize_map();
    sSaveDialogCallback = sub_80A00A0;
    sSavingComplete = FALSE;
}

static u8 sub_809FF4C(void)
{
    if (sub_8197224() == TRUE)
    {
        return FALSE;
    }

    sSavingComplete = FALSE;
    return sSaveDialogCallback();
}

void sub_809FF80(void) // Called from cable_club.s
{
    sub_809FF28();
    CreateTask(task50_save_game, 0x50);
}

// DisplaySaveMessageWithCallback
static void sub_809FF98(const u8 *message, u8 (*saveCallback)(void)) // Appears to confirm save/rest/retire
{
    StringExpandPlaceholders(gStringVar4, message);
    sub_819786C(0, TRUE);
    AddTextPrinterForMessage_2(TRUE);
    sSavingComplete = TRUE;
    sSaveDialogCallback = saveCallback;
}

static void task50_save_game(u8 taskId)
{
    u8 status = sub_809FF4C();

    switch (status)
    {
    case SAVE_CANCELED:
    case SAVE_ERROR:
        gSpecialVar_Result = 0;
        break;
    case SAVE_SUCCESS:
        gSpecialVar_Result = status;
        break;
    case SAVE_IN_PROGRESS:
        return;
    }
    
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

static void sub_80A0014(void)
{
    sub_8197434(0, TRUE);
}

static void sub_80A0024(void)
{
    sub_80A0888();
}

static void sub_80A0030(void)
{
    sSaveDialogTimer = 60;
}

static bool8 sub_80A003C(void)
{
    sSaveDialogTimer--;

    if (gMain.heldKeys & A_BUTTON)
    {
        PlaySE(5);
        return TRUE;
    }
    else if (sSaveDialogTimer == 0)
    {
        return TRUE;
    }

    return FALSE;
}

static bool8 sub_80A0070(void)
{
    if (sSaveDialogTimer != 0)
    {
        sSaveDialogTimer--;
    }
    else if (gMain.heldKeys & A_BUTTON)
    {
        return TRUE;
    }

    return FALSE;
}

static u8 sub_80A00A0(void)
{
    sub_819746C(GetStartMenuWindowId(), FALSE);
    remove_start_menu_window_maybe();
    sub_80A06B4();

    if (InBattlePyramid())
    {
        sub_809FF98(gText_BattlePyramidConfirmRest, sub_80A00EC);
    }
    else 
    {
        sub_809FF98(gText_ConfirmSave, sub_80A00EC);
    }

    return SAVE_IN_PROGRESS;
}

static u8 sub_80A00EC(void)
{
    sub_8197930();
    sSaveDialogCallback = sub_80A0108;
    return SAVE_IN_PROGRESS;
}

static u8 sub_80A0108(void)
{
    switch (ProcessMenuInputNoWrap_())
    {
    case 0: // Yes
        switch (gSaveFileStatus)
        {
        case 0:
        case 2:
            if (gDifferentSaveFile == FALSE)
            {
                sSaveDialogCallback = sub_80A017C;
                return SAVE_IN_PROGRESS;
            }

            sSaveDialogCallback = sub_80A0234;
            return SAVE_IN_PROGRESS;
        default:
            sSaveDialogCallback = sub_80A017C;
            return SAVE_IN_PROGRESS;
        }
    case -1: // B Button
    case 1: // No
        sub_80A0024();
        sub_80A0014();
        return SAVE_CANCELED;
    }

    return SAVE_IN_PROGRESS;
}

// A different save file exists
static u8 sub_80A017C(void)
{
    if (gDifferentSaveFile == TRUE)
    {
        sub_809FF98(gText_DifferentSaveFile, sub_80A01B4);
    }
    else 
    {
        sub_809FF98(gText_AlreadySavedFile, sub_80A01D0);
    }

    return SAVE_IN_PROGRESS;
}

static u8 sub_80A01B4(void)
{
    sub_8197948(1);
    sSaveDialogCallback = sub_80A01EC;
    return SAVE_IN_PROGRESS;
}

static u8 sub_80A01D0(void)
{
    sub_8197930();
    sSaveDialogCallback = sub_80A01EC;
    return SAVE_IN_PROGRESS;
}

static u8 sub_80A01EC(void)
{
    switch (ProcessMenuInputNoWrap_())
    {
    case 0: // Yes
        sSaveDialogCallback = sub_80A0234;
        return SAVE_IN_PROGRESS;
    case -1: // B Button
    case 1: // No
        sub_80A0024();
        sub_80A0014();
        return SAVE_CANCELED;
    }

    return SAVE_IN_PROGRESS;
}

static u8 sub_80A0234(void)
{
    sub_809FF98(gText_SavingDontTurnOff, sub_80A024C);
    return SAVE_IN_PROGRESS;
}

static u8 sub_80A024C(void)
{
    u8 saveStatus;

    IncrementGameStat(GAME_STAT_SAVED_GAME);
    sub_81A9E90();

    if (gDifferentSaveFile == TRUE)
    {
        saveStatus = TrySavingData(SAVE_OVERWRITE_DIFFERENT_FILE);
        gDifferentSaveFile = FALSE;
    }
    else 
    {
        saveStatus = TrySavingData(SAVE_NORMAL);
    }

    if (saveStatus == 1) // Save succeded
    {
        sub_809FF98(gText_PlayerSavedGame, sub_80A02B0);
    }
    else                // Save error
    {
        sub_809FF98(gText_SaveError, sub_80A02FC);
    }

    sub_80A0030();
    return SAVE_IN_PROGRESS;
}

static u8 sub_80A02B0(void)
{
    if (!IsTextPrinterActive(0))
    {
        PlaySE(0x37); // 55
        sSaveDialogCallback = sub_80A02D8;
    }

    return SAVE_IN_PROGRESS;
}

static u8 sub_80A02D8(void)
{
    if (!IsSEPlaying() && sub_80A003C())
    {
        sub_80A0024();
        return SAVE_SUCCESS;
    }
    else 
    {
        return SAVE_IN_PROGRESS;
    }
}

static u8 sub_80A02FC(void)
{
    if (!IsTextPrinterActive(0))
    {
        PlaySE(0x16); // 22
        sSaveDialogCallback = sub_80A0324;
    }
    
    return SAVE_IN_PROGRESS;
}

static u8 sub_80A0324(void)
{
    if (!sub_80A0070()) 
    {
        return SAVE_IN_PROGRESS;
    }
    else
    {
        sub_80A0024();
        return SAVE_ERROR;
    }
}

static void sub_80A0340(void)
{
    sSaveDialogCallback = sub_80A035C;
    sSavingComplete = FALSE;
}

static u8 sub_80A035C(void)
{
    sub_819746C(GetStartMenuWindowId(), FALSE);
    remove_start_menu_window_maybe();
    sub_809FF98(gText_BattlePyramidConfirmRetire, sub_80A0388);

    return SAVE_IN_PROGRESS;
}

static u8 sub_80A0388(void)
{
    sub_8197948(1);
    sSaveDialogCallback = sub_80A03A4;

    return SAVE_IN_PROGRESS;
}

static u8 sub_80A03A4(void)
{
    switch (ProcessMenuInputNoWrap_())
    {
    case 0: // Yes
        return SAVE_CANCELED;
    case -1: // B Button
    case 1: // No
        sub_80A0014();
        return SAVE_SUCCESS;
    }
    
    return SAVE_IN_PROGRESS;
}

static void sub_80A03D8(void)
{
    TransferPlttBuffer();
}

static bool32 sub_80A03E4(u8 *par1)
{
    switch (*par1)
    {
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
        SetVBlankCallback(NULL);
        ScanlineEffect_Stop();
        DmaClear16(3, PLTT, PLTT_SIZE);
        DmaFillLarge16(3, 0, (void *)(VRAM + 0x0), 0x18000, 0x1000);
        break;
    case 1:
        ResetSpriteData();
        ResetTasks();
        ResetPaletteFade();
        ScanlineEffect_Clear();
        break;
    case 2:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, gUnknown_085105A8, ARRAY_COUNT(gUnknown_085105A8));
        InitWindows(gUnknown_085105AC);
        box_border_load_tiles_and_pal(0, 8, 224);
        sub_81978B0(240);
        break;
    case 3:
        ShowBg(0);
        BlendPalettes(-1, 16, 0);
        SetVBlankCallback(sub_80A03D8);
        EnableInterrupts(1);
        break;
    case 4:
        return TRUE;
    }

    (*par1)++;
    return FALSE;
}

void sub_80A0514(void) // Called from cable_club.s
{
    if (sub_80A03E4(&gMain.state))
    {
        CreateTask(&sub_80A0550, 0x50);
        SetMainCallback2(sub_80A0540);
    }
}

static void sub_80A0540(void)
{
    RunTasks();
    UpdatePaletteFade();
}

static void sub_80A0550(u8 taskId)
{
    s16 *step = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        switch (*step)
        {
        case 0:
            FillWindowPixelBuffer(0, 17);
            AddTextPrinterParameterized(0, 
                                        1, 
                                        gText_SavingDontTurnOffPower,
                                        255,
                                        NULL,
                                        2,
                                        1,
                                        3);
            sub_8098858(0, 8, 14);
            PutWindowTilemap(0);
            CopyWindowToVram(0, 3);
            BeginNormalPaletteFade(-1, 0, 16, 0, 0);
            
            if (gWirelessCommType != 0 && InUnionRoom())
            {
                if (sub_800A07C())
                {
                    *step = 1;
                }
                else 
                {
                    *step = 5;
                }
            }
            else
            {
                gSoftResetDisabled = 1;
                *step = 1;
            }
            break;
        case 1:
            sub_8076D5C();
            sub_8153430();
            *step = 2;
            break;
        case 2:
            if (sub_8153474())
            {
                sav2_gender2_inplace_and_xFE();
                *step = 3;
                gSoftResetDisabled = 0;
            }
            break;
        case 3:
            BeginNormalPaletteFade(-1, 0, 0, 16, 0);
            *step = 4;
            break;
        case 4:
            FreeAllWindowBuffers();
            SetMainCallback2(gMain.savedCallback);
            DestroyTask(taskId);
            break;
        case 5:
            CreateTask(&sub_8153688, 0x5);
            *step = 6;
            break;
        case 6:
            if (!FuncIsActiveTask(&sub_8153688))
            {
                *step = 3;
            }
            break;
        }
    }
}

static void sub_80A06B4(void)
{
    struct WindowTemplate saveInfoWindow = gSaveInfoWindowTemplate;
    u8 gender;
    u8 color;
    u32 xOffset;
    u32 yOffset;
    
    if (!FlagGet(FLAG_SYS_POKEDEX_GET))
    {
        saveInfoWindow.height -= 2;
    }

    sSaveWindowId = AddWindow(&saveInfoWindow);
    NewMenuHelpers_DrawStdWindowFrame(sSaveWindowId, FALSE);

    gender = gSaveBlock2Ptr->playerGender;
    color = TEXT_COLOR_RED;  // Red when gender is female, blue when male.

    if (gender == MALE)
    { 
        color = TEXT_COLOR_BLUE;
    }

    // Print region name
    yOffset = 1;
    sub_819A344(3, gStringVar4, TEXT_COLOR_GREEN);
    PrintTextOnWindow(sSaveWindowId, 1, gStringVar4, 0, yOffset, 0xFF, NULL);

    // Print player name
    yOffset = 0x11;
    PrintTextOnWindow(sSaveWindowId, 1, gText_SavingPlayer, 0, yOffset, 0xFF, NULL);
    sub_819A344(0, gStringVar4, color);
    xOffset = GetStringRightAlignXOffset(1, gStringVar4, 0x70);
    PrintPlayerNameOnWindow(sSaveWindowId, gStringVar4, xOffset, yOffset);

    // Print badge count
    yOffset = 0x21;
    PrintTextOnWindow(sSaveWindowId, 1, gText_SavingBadges, 0, yOffset, 0xFF, NULL);
    sub_819A344(4, gStringVar4, color);
    xOffset = GetStringRightAlignXOffset(1, gStringVar4, 0x70);
    PrintTextOnWindow(sSaveWindowId, 1, gStringVar4, xOffset, yOffset, 0xFF, NULL);

    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
    {

        // Print pokedex count
        yOffset = 0x31;
        PrintTextOnWindow(sSaveWindowId, 1, gText_SavingPokedex, 0, yOffset, 0xFF, NULL);
        sub_819A344(1, gStringVar4, color);
        xOffset = GetStringRightAlignXOffset(1, gStringVar4, 0x70);
        PrintTextOnWindow(sSaveWindowId, 1, gStringVar4, xOffset, yOffset, 0xFF, NULL);
    }

    // Print play time
    yOffset += 0x10;
    PrintTextOnWindow(sSaveWindowId, 1, gText_SavingTime, 0, yOffset, 0xFF, NULL);
    sub_819A344(2, gStringVar4, color);
    xOffset = GetStringRightAlignXOffset(1, gStringVar4, 0x70);
    PrintTextOnWindow(sSaveWindowId, 1, gStringVar4, xOffset, yOffset, 0xFF, NULL);

    CopyWindowToVram(sSaveWindowId, 2);
}

static void sub_80A0888(void)
{
    sub_819746C(sSaveWindowId, FALSE);
    RemoveWindow(sSaveWindowId);
}

static void sub_80A08A4(u8 taskId)
{
    if (!FuncIsActiveTask(sub_8153688))
    {
        DestroyTask(taskId);
        EnableBothScriptContexts();
    }
}

void sub_80A08CC(void) // Referenced in data/specials.inc and data/scripts/maps/BattleFrontier_BattleTowerLobby.inc
{
    u32 taskId1;
    u32 taskId2;

    taskId1 = CreateTask(&sub_8153688, 0x5);
    gTasks[taskId1].data[2] = 1;
    
    taskId2 = CreateTask(&sub_80A08A4, 0x6);
    gTasks[taskId2].data[1] = taskId1;
}

static void sub_80A0914(void)
{
    sub_819746C(GetStartMenuWindowId(), TRUE);
    remove_start_menu_window_maybe();
    sub_80984F4();
    ScriptContext2_Disable();
}

void sub_80A0934(void) // Called from map_name_popup.s
{
    PlaySE(5);
    sub_80A0914();
}

void AppendToList(u8 *list, u8 *pos, u8 newEntry)
{
    list[*pos] = newEntry;
    (*pos)++;
}