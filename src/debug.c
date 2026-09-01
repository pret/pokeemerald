#include "global.h"
#include "battle.h"
#include "battle_setup.h"
#include "berry.h"
#include "clock.h"
#include "coins.h"
#include "credits.h"
#include "credits_frlg.h"
#include "data.h"
#include "daycare.h"
#include "debug.h"
#include "decoration.h"
#include "decoration_inventory.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_message_box.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "follower_npc.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "item_use.h"
#include "list_menu.h"
#include "m4a.h"
#include "main.h"
#include "main_menu.h"
#include "match_call.h"
#include "malloc.h"
#include "map_name_popup.h"
#include "mass_outbreak.h"
#include "menu.h"
#include "money.h"
#include "naming_screen.h"
#include "new_game.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "random_mon_generation.h"
#include "region_map.h"
#include "rtc.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "tv.h"
#include "pokemon_summary_screen.h"
#include "wild_encounter.h"
#include "constants/abilities.h"
#include "constants/battle_ai.h"
#include "constants/battle_frontier.h"
#include "constants/coins.h"
#include "constants/decorations.h"
#include "constants/event_objects.h"
#include "constants/expansion.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/map_groups.h"
#include "constants/random_mon_generation.h"
#include "constants/rgb.h"
#include "constants/script_commands.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/weather.h"
#include "siirtc.h"
#include "rtc.h"
#include "fake_rtc.h"
#include "save.h"
#include "vs_seeker.h"
#include "load_save.h"
#include "battle_partner.h"

enum FollowerNPCCreateDebugMenu
{
    DEBUG_FNPC_BRENDAN,
    DEBUG_FNPC_MAY,
    DEBUG_FNPC_STEVEN,
    DEBUG_FNPC_WALLY,
    DEBUG_FNPC_RED,
    DEBUG_FNPC_LEAF,
    DEBUG_FNPC_COUNT,
};

enum FlagsVarsDebugMenu
{
    DEBUG_FLAGVAR_MENU_ITEM_FLAGS,
    DEBUG_FLAGVAR_MENU_ITEM_VARS,
    DEBUG_FLAGVAR_MENU_ITEM_DEXFLAGS_ALL,
    DEBUG_FLAGVAR_MENU_ITEM_DEXFLAGS_RESET,
    DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_POKEDEX,
    DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_NATDEX,
    DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_POKENAV,
    DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_MATCH_CALL,
    DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_RUN_SHOES,
    DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_LOCATIONS,
    DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_BADGES_ALL,
    DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_GAME_CLEAR,
    DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_FRONTIER_PASS,
    DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_COLLISION,
    DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_ENCOUNTER,
    DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_TRAINER_SEE,
    DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_CATCHING,
    DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_BAG_USE,
};

enum DebugBattleType
{
    DEBUG_BATTLE_0_MENU_ITEM_WILD,
    DEBUG_BATTLE_0_MENU_ITEM_WILD_DOUBLE,
    DEBUG_BATTLE_0_MENU_ITEM_SINGLE,
    DEBUG_BATTLE_0_MENU_ITEM_DOUBLE,
    DEBUG_BATTLE_0_MENU_ITEM_MULTI,
};

enum DebugBattleAIFlags
{
    DEBUG_BATTLE_1_MENU_ITEM_AI_FLAG_00,
    DEBUG_BATTLE_1_MENU_ITEM_AI_FLAG_01,
    DEBUG_BATTLE_1_MENU_ITEM_AI_FLAG_02,
    DEBUG_BATTLE_1_MENU_ITEM_AI_FLAG_03,
    DEBUG_BATTLE_1_MENU_ITEM_AI_FLAG_04,
    DEBUG_BATTLE_1_MENU_ITEM_AI_FLAG_05,
    DEBUG_BATTLE_1_MENU_ITEM_AI_FLAG_06,
    DEBUG_BATTLE_1_MENU_ITEM_AI_FLAG_07,
    DEBUG_BATTLE_1_MENU_ITEM_AI_FLAG_08,
    DEBUG_BATTLE_1_MENU_ITEM_AI_FLAG_09,
    DEBUG_BATTLE_1_MENU_ITEM_AI_FLAG_10,
    DEBUG_BATTLE_1_MENU_ITEM_AI_FLAG_11,
    DEBUG_BATTLE_1_MENU_ITEM_AI_FLAG_12,
    DEBUG_BATTLE_1_MENU_ITEM_AI_FLAG_13,
    DEBUG_BATTLE_1_MENU_ITEM_AI_FLAG_14,
    DEBUG_BATTLE_1_MENU_ITEM_AI_FLAG_15,
    DEBUG_BATTLE_1_MENU_ITEM_AI_FLAG_16,
    DEBUG_BATTLE_1_MENU_ITEM_AI_FLAG_17,
    DEBUG_BATTLE_1_MENU_ITEM_CONTINUE,
};

enum DebugBattleEnvironment
{
    DEBUG_BATTLE_2_MENU_ITEM_ENVIRONMENT_0,
    DEBUG_BATTLE_2_MENU_ITEM_ENVIRONMENT_1,
    DEBUG_BATTLE_2_MENU_ITEM_ENVIRONMENT_2,
    DEBUG_BATTLE_2_MENU_ITEM_ENVIRONMENT_3,
    DEBUG_BATTLE_2_MENU_ITEM_ENVIRONMENT_4,
    DEBUG_BATTLE_2_MENU_ITEM_ENVIRONMENT_5,
    DEBUG_BATTLE_2_MENU_ITEM_ENVIRONMENT_6,
    DEBUG_BATTLE_2_MENU_ITEM_ENVIRONMENT_7,
    DEBUG_BATTLE_2_MENU_ITEM_ENVIRONMENT_8,
    DEBUG_BATTLE_2_MENU_ITEM_ENVIRONMENT_9,
};

enum DebugTrainerSelection
{
    TRAINERS_DEBUG_SELECTION_TRAINER1,
    TRAINERS_DEBUG_SELECTION_TRAINER2,
    TRAINERS_DEBUG_SELECTION_PARTNER,
};

enum DebugMenuTypes
{
    DEBUG_BASIC_MENU,
    DEBUG_FLAGS_MENU,
    DEBUG_TRAINERS_MENU,
    DEBUG_OUTBREAK_MENU,
};

// *******************************
// Constants
#define DEBUG_MENU_FONT FONT_NORMAL
#define DEBUG_LINE_HEIGHT (gFonts[DEBUG_MENU_FONT].maxLetterHeight + gFonts[DEBUG_MENU_FONT].lineSpacing)

#define DEBUG_MENU_WIDTH_MAIN 17
#define DEBUG_MENU_HEIGHT_MAIN 9

#define DEBUG_MENU_WIDTH_EXTRA 10
#define DEBUG_MENU_HEIGHT_EXTRA 4

#define DEBUG_MENU_WIDTH_WEATHER 15
#define DEBUG_MENU_HEIGHT_WEATHER 3

#define DEBUG_MENU_WIDTH_SOUND 20
#define DEBUG_MENU_HEIGHT_SOUND 6

#define DEBUG_MENU_WIDTH_FLAGVAR 4
#define DEBUG_MENU_HEIGHT_FLAGVAR 2

#define DEBUG_NUMBER_DIGITS_ITEMS 4

#define DEBUG_NUMBER_ICON_X 210
#define DEBUG_NUMBER_ICON_Y 50

#define DEBUG_MAX_MENU_ITEMS 20
#define DEBUG_MAX_SUB_MENU_LEVELS 4

#define DEBUG_OPTION_CANT_BE_TOGGLED 0xFF

#define DEBUG_ICON_TAG 0xFDF3
// *******************************
struct DebugMenuOption;

typedef void (*DebugFunc)(u8 taskId);
typedef void (*DebugFuncWithParams)(u8 taskId, const void *params);

struct DebugMenuOption
{
    const u8 *text;
    const void *action;
    const void *actionParams;
};

struct DebugMenuListData
{
    const struct DebugMenuOption *subMenuItems[DEBUG_MAX_SUB_MENU_LEVELS];
    struct ListMenuItem listItems[DEBUG_MAX_MENU_ITEMS + 1];
    u8 itemNames[DEBUG_MAX_MENU_ITEMS + 1][26];
    enum DebugMenuTypes menuType:2;
    u32 padding:30;
    s16 data[8];
};

struct DebugSelectionStep
{
    void (*stepUpdate)(u8 taskId, u8 digits, u32 min, u32 max);
    DebugFunc stepConfirm;
    union {
        u32 minValue;
        u32 (*minFunc)(u8 taskId);
    };
    union {
        u32 maxValue;
        u32 (*maxFunc)(u8 taskId);
    };
    u8 substepCount;
    u8 digits;
    bool8 useMinFunc:1;
    bool8 useMaxFunc:1;
    bool8 padding:6;
};

typedef const struct DebugSelectionStep *SelectionStep;

struct DebugSelection
{
    DebugFunc onInit;
    DebugFunc onCancel;
    bool32 (*onComplete)(u8 taskId);
    u8 maxSteps;
    const SelectionStep steps[];
};

// EWRAM
static EWRAM_DATA struct DebugMenuListData *sDebugMenuListData = NULL;
EWRAM_DATA bool8 gIsDebugBattle = FALSE;
EWRAM_DATA u64 gDebugAIFlags = 0;

// *******************************
// Define functions
static void Debug_ShowMenu(DebugFunc HandleInput, const struct DebugMenuOption *items);
static u32 Debug_GenerateListBasicMenu(const struct DebugMenuOption *items);
static u32 Debug_GenerateListTrainerMenu(const struct DebugMenuOption *items);
static u32 Debug_GenerateListFlagsMenu(const struct DebugMenuOption *items);
static u32 Debug_GenerateListOutbreakMenu(const struct DebugMenuOption *items);
static void Debug_DestroyMenu(u8 taskId);
static void DebugAction_Cancel(u8 taskId);
static void DebugAction_DestroyExtraWindow(u8 taskId);
static u8 DebugNativeStep_CreateDebugWindow(void);
static void DebugNativeStep_CloseDebugWindow(u8 taskId);

static void DebugAction_OpenSubMenu(u8 taskId, const struct DebugMenuOption *items);
static void DebugAction_OpenSubMenuTrainers(u8 taskId, const struct DebugMenuOption *items);
static void DebugAction_OpenSubMenuFlagsVars(u8 taskId, const struct DebugMenuOption *items);
static void DebugAction_OpenOutbreakMenu(u8 taskId, const struct DebugMenuOption *items);
static void DebugAction_OpenSubMenuFakeRTC(u8 taskId, const struct DebugMenuOption *items);
static void DebugAction_OpenSubMenuCreateFollowerNPC(u8 taskId, const struct DebugMenuOption *items);
static void DebugAction_ExecuteScript(u8 taskId, void *script);
static void DebugAction_ToggleFlag(u8 taskId, void *flagToggleFunc);

static void DebugTask_HandleMenuInput_General(u8 taskId);
static void DebugAction_Selection_StepUpdate(u8 taskId);
static void DebugAction_Selection_NextStep(u8 taskId);

static void DebugAction_Util_Fly(u8 taskId);
static void DebugAction_Util_WatchCredits(u8 taskId);
static void DebugAction_Util_CheatStart(u8 taskId);

static void DebugAction_TimeMenu_ChangeTimeOfDay(u8 taskId);
static void DebugAction_TimeMenu_ChangeWeekdays(u8 taskId);
static void DebugAction_TimeMenu_RedoDailyEvents(u8 taskId);

static void DebugAction_CreateFollowerNPC(u8 taskId);
static void DebugAction_DestroyFollowerNPC(u8 taskId);

static void DebugAction_PCBag_Fill_PCBoxes_Fast(u8 taskId);
static void DebugAction_PCBag_Fill_PCBoxes_Slow(u8 taskId);
static void DebugAction_PCBag_Fill_PCItemStorage(u8 taskId);
static void DebugAction_PCBag_Fill_PocketItems(u8 taskId);
static void DebugAction_PCBag_Fill_PocketPokeBalls(u8 taskId);
static void DebugAction_PCBag_Fill_PocketTMHM(u8 taskId);
static void DebugAction_PCBag_Fill_PocketBerries(u8 taskId);
static void DebugAction_PCBag_Fill_PocketKeyItems(u8 taskId);
static void DebugAction_PCBag_ClearBag(u8 taskId);
static void DebugAction_PCBag_ClearBoxes(u8 taskId);

static void DebugAction_Party_HealParty(u8 taskId);
static void DebugAction_Party_ClearPokerus(u8 taskId);
static void DebugAction_Party_ClearParty(u8 taskId);
static void DebugAction_Party_SetParty(u8 taskId);
static void DebugAction_Party_BattleSingle(u8 taskId);

static void DebugAction_Trainers_SwitchDoublesFlag(u8 taskId);
static void DebugAction_Trainers_SetRematch(u8 taskId);
static void DebugAction_Trainers_SetRematchReadiness(u8 taskId);
static void DebugAction_Trainers_TryBattle(u8 taskId);
static void DebugAction_Trainers_RechargeVsSeeker(u8 taskId);

static void DebugAction_Outbreak_ClearActive(u8 taskId);

static void DebugAction_FlagsVars_PokedexFlags_All(u8 taskId);
static void DebugAction_FlagsVars_PokedexFlags_Reset(u8 taskId);
static void DebugAction_FlagsVars_SwitchDex(u8 taskId);
static void DebugAction_FlagsVars_SwitchNatDex(u8 taskId);
static void DebugAction_FlagsVars_SwitchPokeNav(u8 taskId);
static void DebugAction_FlagsVars_SwitchMatchCall(u8 taskId);
static void DebugAction_FlagsVars_ToggleFlyFlags(u8 taskId);
static void DebugAction_FlagsVars_ToggleBadgeFlags(u8 taskId);
static void DebugAction_FlagsVars_ToggleGameClear(u8 taskId);
static void DebugAction_FlagsVars_ToggleFrontierPass(u8 taskId);
static void DebugAction_FlagsVars_CollisionOnOff(u8 taskId);
static void DebugAction_FlagsVars_EncounterOnOff(u8 taskId);
static void DebugAction_FlagsVars_TrainerSeeOnOff(u8 taskId);
static void DebugAction_FlagsVars_BagUseOnOff(u8 taskId);
static void DebugAction_FlagsVars_CatchingOnOff(u8 taskId);
static void DebugAction_FlagsVars_RunningShoes(u8 taskId);

static void DebugAction_Give_MaxMoney(u8 taskId);
static void DebugAction_Give_MaxCoins(u8 taskId);
static void DebugAction_Give_MaxBattlePoints(u8 taskId);
static void DebugAction_Give_DayCareEgg(u8 taskId);

static void DebugAction_Sound_SE(u8 taskId);
static void DebugAction_Sound_SE_SelectId(u8 taskId);
static void DebugAction_Sound_MUS(u8 taskId);
static void DebugAction_Sound_MUS_SelectId(u8 taskId);

static void DebugAction_BerryFunctions_ClearAll(u8 taskId);
static void DebugAction_BerryFunctions_Ready(u8 taskId);
static void DebugAction_BerryFunctions_NextStage(u8 taskId);
static void DebugAction_BerryFunctions_Pests(u8 taskId);
static void DebugAction_BerryFunctions_Weeds(u8 taskId);

static void DebugAction_Player_Name(u8 taskId);
static void DebugAction_Player_Gender(u8 taskId);
static void DebugAction_Player_Id(u8 taskId);

static void Debug_CreateInputDisplayWindow(u8 taskId);
static void DebugNativeStep_DelayedSelection(u8 taskId);
static void DebugAction_Selection_Init(u8 taskId, const void *params);

extern const u8 Debug_FlagsNotSetOverworldConfigMessage[];
extern const u8 Debug_FlagsNotSetBattleConfigMessage[];
extern const u8 Debug_VarsNotSetBattleConfigMessage[];
extern const u8 Debug_FlagsAndVarNotSetBattleConfigMessage[];
extern const u8 Debug_EventScript_FontTest[];
extern const u8 Debug_EventScript_CheckEVs[];
extern const u8 Debug_EventScript_CheckIVs[];
extern const u8 Debug_EventScript_GivePokerus[];
extern const u8 Debug_EventScript_InflictStatus1[];
extern const u8 Debug_EventScript_KoPokemon[];
extern const u8 Debug_EventScript_SetHiddenNature[];
extern const u8 Debug_EventScript_SetAbility[];
extern const u8 Debug_EventScript_SetFriendship[];
extern const u8 Debug_EventScript_Script_1[];
extern const u8 Debug_EventScript_Script_2[];
extern const u8 Debug_EventScript_Script_3[];
extern const u8 Debug_EventScript_Script_4[];
extern const u8 Debug_EventScript_Script_5[];
extern const u8 Debug_EventScript_Script_6[];
extern const u8 Debug_EventScript_Script_7[];
extern const u8 Debug_EventScript_Script_8[];
extern const u8 DebugScript_DaycareMonsNotCompatible[];
extern const u8 DebugScript_OneDaycareMons[];
extern const u8 DebugScript_ZeroDaycareMons[];

extern const u8 Debug_ShowFieldMessageStringVar4[];
extern const u8 Debug_CheatStart[];
extern const u8 Debug_CheatStartFrlg[];
extern const u8 Debug_HatchAnEgg[];
extern const u8 PlayersHouse_2F_EventScript_SetWallClock[];
extern const u8 PlayersHouse_2F_EventScript_CheckWallClock[];
extern const u8 Debug_CheckSaveBlock[];
extern const u8 Debug_CheckROMSpace[];
extern const u8 Debug_BoxFilledMessage[];
extern const u8 Debug_ShowExpansionVersion[];
extern const u8 Debug_EventScript_EWRAMCounters[];
extern const u8 Debug_Follower_NPC_Event_Script[];
extern const u8 Debug_Follower_NPC_Not_Enabled[];
extern const u8 Debug_EventScript_Steven_Multi[];
extern const u8 Debug_EventScript_WallyTutorial[];
extern const u8 Debug_EventScript_PrintTimeOfDay[];
extern const u8 Debug_EventScript_TellTheTime[];
extern const u8 Debug_EventScript_FakeRTCNotEnabled[];

extern const u8 Debug_BerryPestsDisabled[];
extern const u8 Debug_BerryWeedsDisabled[];

extern const u8 Common_EventScript_MoveRelearner[];

static const struct DebugSelection sWarpSelection;
static const struct DebugSelection sSetWeatherSelection;
static const struct DebugSelection sSpeciesGeneratorSelection;
static const struct DebugSelection sItemGeneratorSelection;
static const struct DebugSelection sMassOutbreakSpeciesSelection;
static const struct DebugSelection sMassOutbreakLevelSelection;
static const struct DebugSelection sMassOutbreakProbabilitySelection;
static const struct DebugSelection sMassOutbreakDaysLeftSelection;
static const struct DebugSelection sMassOutbreakMovesSelection;
static const struct DebugSelection sMassOutbreakLocationSelection;
static const struct DebugSelection sStaticMassOutbreakSelection;
static const struct DebugSelection sDynamicMassOutbreakSelection;
static const struct DebugSelection sToggleFlagSelection;
static const struct DebugSelection sSetVarSelection;
static const struct DebugSelection sGiveItemSelection;
static const struct DebugSelection sSimplePokemonSelection;
static const struct DebugSelection sComplexPokemonSelection;
static const struct DebugSelection sEggPokemonSelection;
static const struct DebugSelection sGiveDecorationSelection;
static const struct DebugSelection sTrainerFromMapSelection;
static const struct DebugSelection sTrainer1Selection;
static const struct DebugSelection sTrainer2Selection;
static const struct DebugSelection sPartnerSelection;

#include "data/map_group_count.h"

// Text
// General
static const u8 sDebugText_Arrow[] =         _("{CLEAR_TO 110}{RIGHT_ARROW}");
static const u8 sDebugText_True[] =          _("TRUE");
static const u8 sDebugText_False[] =         _("FALSE");
static const u8 sDebugText_Colored_True[] =  _("{COLOR GREEN}TRUE");
static const u8 sDebugText_Colored_False[] = _("{COLOR RED}FALSE");
static const u8 sDebugText_Dashes[] =        _("---");
static const u8 sDebugText_Empty[] =         _("");
static const u8 sDebugText_Continue[] =      _("Continue…");

//Time Menu

static const u8 *const gDayNameStringsTable[WEEKDAY_COUNT] = {
    COMPOUND_STRING("Sunday"),
    COMPOUND_STRING("Monday"),
    COMPOUND_STRING("Tuesday"),
    COMPOUND_STRING("Wednesday"),
    COMPOUND_STRING("Thursday"),
    COMPOUND_STRING("Friday"),
    COMPOUND_STRING("Saturday"),
};

static const u8 *const gTimeOfDayStringsTable[TIMES_OF_DAY_COUNT] = {
    COMPOUND_STRING("Morning"),
    COMPOUND_STRING("Day"),
    COMPOUND_STRING("Evening"),
    COMPOUND_STRING("Night"),
};

// Follower NPC

static const u8 *const gFollowerNPCStringsTable[DEBUG_FNPC_COUNT] = {
    COMPOUND_STRING("Brendan"),
    COMPOUND_STRING("May"),
    COMPOUND_STRING("Steven"),
    COMPOUND_STRING("Wally"),
    COMPOUND_STRING("Red"),
    COMPOUND_STRING("Leaf"),
};

// Give Menu
static const u8 sDebugText_PokemonShiny[] =             _("Shiny:{CLEAR_TO 90}\n   {STR_VAR_2}{CLEAR_TO 90}\n{CLEAR_TO 90}\n{CLEAR_TO 90}");
static const u8 sDebugText_IVs[] =                      _("IV {STR_VAR_1}:{CLEAR_TO 90}\n    {STR_VAR_3}{CLEAR_TO 90}\n{CLEAR_TO 90}\n{STR_VAR_2}{CLEAR_TO 90}");
static const u8 sDebugText_EVs[] =                      _("EV {STR_VAR_1}:{CLEAR_TO 90}\n    {STR_VAR_3}{CLEAR_TO 90}\n{CLEAR_TO 90}\n{STR_VAR_2}{CLEAR_TO 90}");
// Sound Menu
static const u8 sDebugText_Sound_SFX_ID[] =             _("SFX ID: {STR_VAR_3}   {START_BUTTON} Stop\n{STR_VAR_1}    \n{STR_VAR_2}");
static const u8 sDebugText_Sound_Music_ID[] =           _("Music ID: {STR_VAR_3}   {START_BUTTON} Stop\n{STR_VAR_1}    \n{STR_VAR_2}");

const u8 *const gText_DigitIndicator[] =
{
    COMPOUND_STRING("{LEFT_ARROW}+1{RIGHT_ARROW}        "),
    COMPOUND_STRING("{LEFT_ARROW}+10{RIGHT_ARROW}       "),
    COMPOUND_STRING("{LEFT_ARROW}+100{RIGHT_ARROW}      "),
    COMPOUND_STRING("{LEFT_ARROW}+1000{RIGHT_ARROW}     "),
    COMPOUND_STRING("{LEFT_ARROW}+10000{RIGHT_ARROW}    "),
    COMPOUND_STRING("{LEFT_ARROW}+100000{RIGHT_ARROW}   "),
    COMPOUND_STRING("{LEFT_ARROW}+1000000{RIGHT_ARROW}  "),
    COMPOUND_STRING("{LEFT_ARROW}+10000000{RIGHT_ARROW} "),
};

static const s32 sPowersOfTen[] =
{
             1,
            10,
           100,
          1000,
         10000,
        100000,
       1000000,
      10000000,
     100000000,
    1000000000,
};

static u32 (*const generateListFunctions[])(const struct DebugMenuOption *) =
{
    [DEBUG_BASIC_MENU] = Debug_GenerateListBasicMenu,
    [DEBUG_FLAGS_MENU] = Debug_GenerateListFlagsMenu,
    [DEBUG_TRAINERS_MENU] = Debug_GenerateListTrainerMenu,
    [DEBUG_OUTBREAK_MENU] = Debug_GenerateListOutbreakMenu
};

// *******************************
// Menu Actions. Make sure that submenus are defined before the menus that call them.
static const struct DebugMenuOption sDebugMenu_Actions_TimeMenu_TimesOfDay[] =
{
    [TIME_MORNING] = { gTimeOfDayStringsTable[TIME_MORNING], DebugAction_TimeMenu_ChangeTimeOfDay },
    [TIME_DAY]     = { gTimeOfDayStringsTable[TIME_DAY],     DebugAction_TimeMenu_ChangeTimeOfDay },
    [TIME_EVENING] = { gTimeOfDayStringsTable[TIME_EVENING], DebugAction_TimeMenu_ChangeTimeOfDay },
    [TIME_NIGHT]   = { gTimeOfDayStringsTable[TIME_NIGHT],   DebugAction_TimeMenu_ChangeTimeOfDay },
    { NULL }
};

static const struct DebugMenuOption sDebugMenu_Actions_TimeMenu_Weekdays[] =
{
    [WEEKDAY_SUN] = { gDayNameStringsTable[WEEKDAY_SUN], DebugAction_TimeMenu_ChangeWeekdays },
    [WEEKDAY_MON] = { gDayNameStringsTable[WEEKDAY_MON], DebugAction_TimeMenu_ChangeWeekdays },
    [WEEKDAY_TUE] = { gDayNameStringsTable[WEEKDAY_TUE], DebugAction_TimeMenu_ChangeWeekdays },
    [WEEKDAY_WED] = { gDayNameStringsTable[WEEKDAY_WED], DebugAction_TimeMenu_ChangeWeekdays },
    [WEEKDAY_THU] = { gDayNameStringsTable[WEEKDAY_THU], DebugAction_TimeMenu_ChangeWeekdays },
    [WEEKDAY_FRI] = { gDayNameStringsTable[WEEKDAY_FRI], DebugAction_TimeMenu_ChangeWeekdays },
    [WEEKDAY_SAT] = { gDayNameStringsTable[WEEKDAY_SAT], DebugAction_TimeMenu_ChangeWeekdays },
    { NULL }
};

static const struct DebugMenuOption sDebugMenu_Actions_FollowerNPCMenu_Create[] =
{
    [DEBUG_FNPC_BRENDAN] = { gFollowerNPCStringsTable[DEBUG_FNPC_BRENDAN], DebugAction_CreateFollowerNPC },
    [DEBUG_FNPC_MAY] =     { gFollowerNPCStringsTable[DEBUG_FNPC_MAY],     DebugAction_CreateFollowerNPC },
    [DEBUG_FNPC_STEVEN] =  { gFollowerNPCStringsTable[DEBUG_FNPC_STEVEN],  DebugAction_CreateFollowerNPC },
    [DEBUG_FNPC_WALLY] =   { gFollowerNPCStringsTable[DEBUG_FNPC_WALLY],   DebugAction_CreateFollowerNPC },
    [DEBUG_FNPC_RED] =     { gFollowerNPCStringsTable[DEBUG_FNPC_RED],     DebugAction_CreateFollowerNPC },
    [DEBUG_FNPC_LEAF] =    { gFollowerNPCStringsTable[DEBUG_FNPC_LEAF],    DebugAction_CreateFollowerNPC },
    { NULL }
};

static const struct DebugMenuOption sDebugMenu_Actions_TimeMenu[] =
{
    { COMPOUND_STRING("Get time…"),         DebugAction_ExecuteScript, Debug_EventScript_TellTheTime },
    { COMPOUND_STRING("Get time of day…"),  DebugAction_ExecuteScript, Debug_EventScript_PrintTimeOfDay },
    { COMPOUND_STRING("Set time of day…"),  DebugAction_OpenSubMenuFakeRTC, sDebugMenu_Actions_TimeMenu_TimesOfDay },
    { COMPOUND_STRING("Set weekday…"),      DebugAction_OpenSubMenuFakeRTC, sDebugMenu_Actions_TimeMenu_Weekdays },
    { COMPOUND_STRING("Redo daily events"), DebugAction_TimeMenu_RedoDailyEvents },
    { COMPOUND_STRING("Check wall clock…"), DebugAction_ExecuteScript, PlayersHouse_2F_EventScript_CheckWallClock },
    { COMPOUND_STRING("Set wall clock…"),   DebugAction_ExecuteScript, PlayersHouse_2F_EventScript_SetWallClock },
    { NULL }
};

static const struct DebugMenuOption sDebugMenu_Actions_BerryFunctions[] =
{
    { COMPOUND_STRING("Clear map trees"),      DebugAction_BerryFunctions_ClearAll },
    { COMPOUND_STRING("Ready map trees"),      DebugAction_BerryFunctions_Ready },
    { COMPOUND_STRING("Grow map trees"),       DebugAction_BerryFunctions_NextStage },
    { COMPOUND_STRING("Give map trees pests"), DebugAction_BerryFunctions_Pests },
    { COMPOUND_STRING("Give map trees weeds"), DebugAction_BerryFunctions_Weeds },
    { NULL }
};

static const struct DebugMenuOption sDebugMenu_Actions_FollowerNPCMenu[] =
{
    { COMPOUND_STRING("Create Follower"),  DebugAction_OpenSubMenuCreateFollowerNPC, sDebugMenu_Actions_FollowerNPCMenu_Create },
    { COMPOUND_STRING("Destroy Follower"), DebugAction_DestroyFollowerNPC },
    { NULL }
};

static const struct DebugMenuOption sDebugMenu_Actions_Utilities[] =
{
    { COMPOUND_STRING("Fly to map…"),               DebugAction_Util_Fly },
    { COMPOUND_STRING("Warp to map warp…"),         DebugAction_Selection_Init, &sWarpSelection},
    { COMPOUND_STRING("Set weather…"),              DebugAction_Selection_Init, &sSetWeatherSelection },
    { COMPOUND_STRING("Font Test…"),                DebugAction_ExecuteScript, Debug_EventScript_FontTest },
    { COMPOUND_STRING("Time Functions…"),           DebugAction_OpenSubMenu, sDebugMenu_Actions_TimeMenu, },
    { COMPOUND_STRING("Watch credits…"),            DebugAction_Util_WatchCredits },
    { COMPOUND_STRING("Cheat start"),               DebugAction_Util_CheatStart },
    { COMPOUND_STRING("Berry Functions…"),          DebugAction_OpenSubMenu, sDebugMenu_Actions_BerryFunctions },
    { COMPOUND_STRING("EWRAM Counters…"),           DebugAction_ExecuteScript, Debug_EventScript_EWRAMCounters },
    { COMPOUND_STRING("Follower NPC…"),             DebugAction_OpenSubMenu, sDebugMenu_Actions_FollowerNPCMenu },
    { COMPOUND_STRING("Test Species Randomizer"),   DebugAction_Selection_Init, &sSpeciesGeneratorSelection },
    { COMPOUND_STRING("Test Item Randomizer"),      DebugAction_Selection_Init, &sItemGeneratorSelection },
    { COMPOUND_STRING("Wally Tutorial"),            DebugAction_ExecuteScript, Debug_EventScript_WallyTutorial },
    { COMPOUND_STRING("Steven Multi"),              DebugAction_ExecuteScript, Debug_EventScript_Steven_Multi },
    { NULL }
};

static const struct DebugMenuOption sDebugMenu_Actions_PCBag_Fill[] =
{
    { COMPOUND_STRING("Fill PC Boxes Fast"),        DebugAction_PCBag_Fill_PCBoxes_Fast },
    { COMPOUND_STRING("Fill PC Boxes Slow (LAG!)"), DebugAction_PCBag_Fill_PCBoxes_Slow },
    { COMPOUND_STRING("Fill PC Items") ,            DebugAction_PCBag_Fill_PCItemStorage },
    { COMPOUND_STRING("Fill Pocket Items"),         DebugAction_PCBag_Fill_PocketItems },
    { COMPOUND_STRING("Fill Pocket Poké Balls"),    DebugAction_PCBag_Fill_PocketPokeBalls },
    { COMPOUND_STRING("Fill Pocket TMHM"),          DebugAction_PCBag_Fill_PocketTMHM },
    { COMPOUND_STRING("Fill Pocket Berries"),       DebugAction_PCBag_Fill_PocketBerries },
    { COMPOUND_STRING("Fill Pocket Key Items"),     DebugAction_PCBag_Fill_PocketKeyItems },
    { NULL }
};

static const struct DebugMenuOption sDebugMenu_Actions_PCBag[] =
{
    { COMPOUND_STRING("Access PC"),           DebugAction_ExecuteScript, EventScript_PC },
    { COMPOUND_STRING("Fill…"),               DebugAction_OpenSubMenu, sDebugMenu_Actions_PCBag_Fill },
    { COMPOUND_STRING("Clear Bag"),           DebugAction_PCBag_ClearBag },
    { COMPOUND_STRING("Clear Storage Boxes"), DebugAction_PCBag_ClearBoxes },
    { NULL }
};

static const struct DebugMenuOption sDebugMenu_Actions_EditPokemon[] =
{
    { COMPOUND_STRING("Inflict Status1"),    DebugAction_ExecuteScript, Debug_EventScript_InflictStatus1 },
    { COMPOUND_STRING("Faint Pokemon"),      DebugAction_ExecuteScript, Debug_EventScript_KoPokemon },
    { COMPOUND_STRING("Set Hidden Nature"),  DebugAction_ExecuteScript, Debug_EventScript_SetHiddenNature },
    { COMPOUND_STRING("Set Friendship"),     DebugAction_ExecuteScript, Debug_EventScript_SetFriendship },
    { COMPOUND_STRING("Set Ability"),        DebugAction_ExecuteScript, Debug_EventScript_SetAbility },
    { NULL }
};

static const struct DebugMenuOption sDebugMenu_Actions_Party[] =
{
    { COMPOUND_STRING("Move Relearner"),     DebugAction_ExecuteScript, Common_EventScript_MoveRelearner },
    { COMPOUND_STRING("Hatch an Egg"),       DebugAction_ExecuteScript, Debug_HatchAnEgg },
    { COMPOUND_STRING("Heal party"),         DebugAction_Party_HealParty },
    { COMPOUND_STRING("Edit Pokemon"),       DebugAction_OpenSubMenu, sDebugMenu_Actions_EditPokemon },
    { COMPOUND_STRING("Check EVs"),          DebugAction_ExecuteScript, Debug_EventScript_CheckEVs },
    { COMPOUND_STRING("Check IVs"),          DebugAction_ExecuteScript, Debug_EventScript_CheckIVs },
    { COMPOUND_STRING("Give Pokerus"),       DebugAction_ExecuteScript, Debug_EventScript_GivePokerus },
    { COMPOUND_STRING("Clear Pokerus"),      DebugAction_Party_ClearPokerus},
    { COMPOUND_STRING("Clear Party"),        DebugAction_Party_ClearParty },
    { COMPOUND_STRING("Set Party"),          DebugAction_Party_SetParty },
    { COMPOUND_STRING("Start Debug Battle"), DebugAction_Party_BattleSingle },
    { NULL }
};

static const struct DebugMenuOption sDebugMenu_Actions_Give[] =
{
    { COMPOUND_STRING("Give item XYZ…"),    DebugAction_Selection_Init, &sGiveItemSelection },
    { COMPOUND_STRING("Pokémon (Basic)"),   DebugAction_Selection_Init, &sSimplePokemonSelection },
    { COMPOUND_STRING("Pokémon (Complex)"), DebugAction_Selection_Init, &sComplexPokemonSelection },
    { COMPOUND_STRING("Give Egg"),          DebugAction_Selection_Init, &sEggPokemonSelection },
    { COMPOUND_STRING("Give Decoration…"),  DebugAction_Selection_Init, &sGiveDecorationSelection },
    { COMPOUND_STRING("Max Money"),         DebugAction_Give_MaxMoney },
    { COMPOUND_STRING("Max Coins"),         DebugAction_Give_MaxCoins },
    { COMPOUND_STRING("Max Battle Points"), DebugAction_Give_MaxBattlePoints },
    { COMPOUND_STRING("Daycare Egg"),       DebugAction_Give_DayCareEgg },
    { NULL }
};

static const struct DebugMenuOption sDebugMenu_Actions_Player[] =
{
    { COMPOUND_STRING("Player name"),    DebugAction_Player_Name },
    { COMPOUND_STRING("Toggle gender"),  DebugAction_Player_Gender },
    { COMPOUND_STRING("New Trainer ID"), DebugAction_Player_Id },
    { NULL }
};

static const struct DebugMenuOption sDebugMenu_Actions_Scripts[] =
{
    { COMPOUND_STRING("Script 1"), DebugAction_ExecuteScript, Debug_EventScript_Script_1 },
    { COMPOUND_STRING("Script 2"), DebugAction_ExecuteScript, Debug_EventScript_Script_2 },
    { COMPOUND_STRING("Script 3"), DebugAction_ExecuteScript, Debug_EventScript_Script_3 },
    { COMPOUND_STRING("Script 4"), DebugAction_ExecuteScript, Debug_EventScript_Script_4 },
    { COMPOUND_STRING("Script 5"), DebugAction_ExecuteScript, Debug_EventScript_Script_5 },
    { COMPOUND_STRING("Script 6"), DebugAction_ExecuteScript, Debug_EventScript_Script_6 },
    { COMPOUND_STRING("Script 7"), DebugAction_ExecuteScript, Debug_EventScript_Script_7 },
    { COMPOUND_STRING("Script 8"), DebugAction_ExecuteScript, Debug_EventScript_Script_8 },
    { NULL }
};

static const struct DebugMenuOption sDebugMenu_Actions_Trainers[] =
{
    { COMPOUND_STRING("Choose trainer from map"), DebugAction_Selection_Init, &sTrainerFromMapSelection},
    { COMPOUND_STRING("Trainer 1: {STR_VAR_1}"), DebugAction_Selection_Init, &sTrainer1Selection},
    { COMPOUND_STRING("Trainer 2: {STR_VAR_1}"), DebugAction_Selection_Init, &sTrainer2Selection},
    { COMPOUND_STRING("Partner: {STR_VAR_1}"), DebugAction_Selection_Init, &sPartnerSelection},
    { COMPOUND_STRING("Double Battle: {STR_VAR_1}"), DebugAction_ToggleFlag, DebugAction_Trainers_SwitchDoublesFlag },
    { COMPOUND_STRING("Matches {STR_VAR_1}/{STR_VAR_2}"), DebugAction_ToggleFlag, DebugAction_Trainers_SetRematch },
    { COMPOUND_STRING("Rematch Ready {STR_VAR_1}"), DebugAction_ToggleFlag, DebugAction_Trainers_SetRematchReadiness },
    { COMPOUND_STRING("Try Battle"), DebugAction_Trainers_TryBattle },
    { COMPOUND_STRING("Recharge VS Seeker"), DebugAction_Trainers_RechargeVsSeeker },
    { NULL }
};

static const struct DebugMenuOption sDebugMenu_Actions_MassOutbreak[] =
{
    { COMPOUND_STRING("Set Static Outbreak"), DebugAction_Selection_Init, &sStaticMassOutbreakSelection },
    { COMPOUND_STRING("Clear Active Outbreak"), DebugAction_Outbreak_ClearActive },
    { COMPOUND_STRING("Species: {STR_VAR_1}"), DebugAction_Selection_Init, &sMassOutbreakSpeciesSelection },
    { COMPOUND_STRING("Map: {STR_VAR_1}"), DebugAction_Selection_Init, &sMassOutbreakLocationSelection },
    { COMPOUND_STRING("Level: {STR_VAR_1}"), DebugAction_Selection_Init, &sMassOutbreakLevelSelection },
    { COMPOUND_STRING("Moves"), DebugAction_Selection_Init, &sMassOutbreakMovesSelection },
    { COMPOUND_STRING("Probability: {STR_VAR_1}"), DebugAction_Selection_Init, &sMassOutbreakProbabilitySelection },
    { COMPOUND_STRING("Days Left: {STR_VAR_1}"), DebugAction_Selection_Init, &sMassOutbreakDaysLeftSelection },
    { COMPOUND_STRING("Set Dynamic Outbreak"), DebugAction_Selection_Init, &sDynamicMassOutbreakSelection },
    { NULL }
};

static const struct DebugMenuOption sDebugMenu_Actions_Encounters[] =
{
    { COMPOUND_STRING("Mass outbreak…"), DebugAction_OpenOutbreakMenu, sDebugMenu_Actions_MassOutbreak },
    { NULL }
};

static const struct DebugMenuOption sDebugMenu_Actions_Sound[] =
{
    { COMPOUND_STRING("SFX…"),   DebugAction_Sound_SE },
    { COMPOUND_STRING("Music…"), DebugAction_Sound_MUS },
    { NULL }
};

static const struct DebugMenuOption sDebugMenu_Actions_ROMInfo2[] =
{
    { COMPOUND_STRING("Save Block space"),  DebugAction_ExecuteScript, Debug_CheckSaveBlock },
    { COMPOUND_STRING("ROM space"),         DebugAction_ExecuteScript, Debug_CheckROMSpace },
    { COMPOUND_STRING("Expansion Version"), DebugAction_ExecuteScript, Debug_ShowExpansionVersion },
    { NULL }
};

static const struct DebugMenuOption sDebugMenu_Actions_Flags[] =
{
    [DEBUG_FLAGVAR_MENU_ITEM_FLAGS]                = { COMPOUND_STRING("Set Flag XYZ…"),                     DebugAction_Selection_Init, &sToggleFlagSelection },
    [DEBUG_FLAGVAR_MENU_ITEM_VARS]                 = { COMPOUND_STRING("Set Var XYZ…"),                      DebugAction_Selection_Init, &sSetVarSelection},
    [DEBUG_FLAGVAR_MENU_ITEM_DEXFLAGS_ALL]         = { COMPOUND_STRING("Pokédex Flags All"),                 DebugAction_FlagsVars_PokedexFlags_All },
    [DEBUG_FLAGVAR_MENU_ITEM_DEXFLAGS_RESET]       = { COMPOUND_STRING("Pokédex Flags Reset"),               DebugAction_FlagsVars_PokedexFlags_Reset },
    [DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_POKEDEX]       = { COMPOUND_STRING("Toggle {STR_VAR_1}Pokédex"),         DebugAction_ToggleFlag, DebugAction_FlagsVars_SwitchDex },
    [DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_NATDEX]        = { COMPOUND_STRING("Toggle {STR_VAR_1}National Dex"),    DebugAction_ToggleFlag, DebugAction_FlagsVars_SwitchNatDex },
    [DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_POKENAV]       = { COMPOUND_STRING("Toggle {STR_VAR_1}PokéNav"),         DebugAction_ToggleFlag, DebugAction_FlagsVars_SwitchPokeNav },
    [DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_MATCH_CALL]    = { COMPOUND_STRING("Toggle {STR_VAR_1}Match Call"),      DebugAction_ToggleFlag, DebugAction_FlagsVars_SwitchMatchCall },
    [DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_RUN_SHOES]     = { COMPOUND_STRING("Toggle {STR_VAR_1}Running Shoes"),   DebugAction_ToggleFlag, DebugAction_FlagsVars_RunningShoes },
    [DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_LOCATIONS]     = { COMPOUND_STRING("Toggle {STR_VAR_1}Fly Flags"),       DebugAction_ToggleFlag, DebugAction_FlagsVars_ToggleFlyFlags },
    [DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_BADGES_ALL]    = { COMPOUND_STRING("Toggle {STR_VAR_1}All badges"),      DebugAction_ToggleFlag, DebugAction_FlagsVars_ToggleBadgeFlags },
    [DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_GAME_CLEAR]    = { COMPOUND_STRING("Toggle {STR_VAR_1}Game clear"),      DebugAction_ToggleFlag, DebugAction_FlagsVars_ToggleGameClear },
    [DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_FRONTIER_PASS] = { COMPOUND_STRING("Toggle {STR_VAR_1}Frontier Pass"),   DebugAction_ToggleFlag, DebugAction_FlagsVars_ToggleFrontierPass },
    [DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_COLLISION]     = { COMPOUND_STRING("Toggle {STR_VAR_1}Collision OFF"),   DebugAction_ToggleFlag, DebugAction_FlagsVars_CollisionOnOff },
    [DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_ENCOUNTER]     = { COMPOUND_STRING("Toggle {STR_VAR_1}Encounter OFF"),   DebugAction_ToggleFlag, DebugAction_FlagsVars_EncounterOnOff },
    [DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_TRAINER_SEE]   = { COMPOUND_STRING("Toggle {STR_VAR_1}Trainer See OFF"), DebugAction_ToggleFlag, DebugAction_FlagsVars_TrainerSeeOnOff },
    [DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_CATCHING]      = { COMPOUND_STRING("Toggle {STR_VAR_1}Catching OFF"),    DebugAction_ToggleFlag, DebugAction_FlagsVars_CatchingOnOff },
    [DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_BAG_USE]       = { COMPOUND_STRING("Toggle {STR_VAR_1}Bag Use OFF"),     DebugAction_ToggleFlag, DebugAction_FlagsVars_BagUseOnOff },
    { NULL }
};

static const u8 *const sDebugMenu_Actions_BagUse_Options[] =
{
    COMPOUND_STRING("No Bag: {STR_VAR_1}Inactive"),
    COMPOUND_STRING("No Bag: {STR_VAR_1}VS Trainers"),
    COMPOUND_STRING("No Bag: {STR_VAR_1}Active"),
    COMPOUND_STRING("No Bag: {STR_VAR_1}Invalid value"),
};

static const struct DebugMenuOption sDebugMenu_Actions_Main[] =
{
    { COMPOUND_STRING("Utilities…"),    DebugAction_OpenSubMenu, sDebugMenu_Actions_Utilities, },
    { COMPOUND_STRING("PC/Bag…"),       DebugAction_OpenSubMenu, sDebugMenu_Actions_PCBag, },
    { COMPOUND_STRING("Party…"),        DebugAction_OpenSubMenu, sDebugMenu_Actions_Party, },
    { COMPOUND_STRING("Give X…"),       DebugAction_OpenSubMenu, sDebugMenu_Actions_Give, },
    { COMPOUND_STRING("Player…"),       DebugAction_OpenSubMenu, sDebugMenu_Actions_Player, },
    { COMPOUND_STRING("Scripts…"),      DebugAction_OpenSubMenu, sDebugMenu_Actions_Scripts, },
    { COMPOUND_STRING("Trainers…"),     DebugAction_OpenSubMenuTrainers, sDebugMenu_Actions_Trainers, },
    { COMPOUND_STRING("Encounters…"),   DebugAction_OpenSubMenu, sDebugMenu_Actions_Encounters, },
    { COMPOUND_STRING("Flags & Vars…"), DebugAction_OpenSubMenuFlagsVars, sDebugMenu_Actions_Flags, },
    { COMPOUND_STRING("Sound…"),        DebugAction_OpenSubMenu, sDebugMenu_Actions_Sound, },
    { COMPOUND_STRING("ROM Info…"),     DebugAction_OpenSubMenu, sDebugMenu_Actions_ROMInfo2, },
    { COMPOUND_STRING("Cancel"),        DebugAction_Cancel, },
    { NULL }
};

// *******************************
// Windows
static const struct WindowTemplate sDebugMenuWindowTemplateMain =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = DEBUG_MENU_WIDTH_MAIN,
    .height = 2 * DEBUG_MENU_HEIGHT_MAIN,
    .paletteNum = 15,
    .baseBlock = 1,
};

static const struct WindowTemplate sDebugMenuWindowTemplateExtra =
{
    .bg = 0,
    .tilemapLeft = 30 - DEBUG_MENU_WIDTH_EXTRA - 1,
    .tilemapTop = 1,
    .width = DEBUG_MENU_WIDTH_EXTRA,
    .height = 2 * DEBUG_MENU_HEIGHT_EXTRA,
    .paletteNum = 15,
    .baseBlock = 1,
};

static const struct WindowTemplate sDebugMenuWindowTemplateWeather =
{
    .bg = 0,
    .tilemapLeft = 30 - DEBUG_MENU_WIDTH_WEATHER - 1,
    .tilemapTop = 1,
    .width = DEBUG_MENU_WIDTH_WEATHER,
    .height = 2 * DEBUG_MENU_HEIGHT_WEATHER,
    .paletteNum = 15,
    .baseBlock = 1,
};

static const struct WindowTemplate sDebugMenuWindowTemplateSound =
{
    .bg = 0,
    .tilemapLeft = 30 - DEBUG_MENU_WIDTH_SOUND - 1,
    .tilemapTop = 1,
    .width = DEBUG_MENU_WIDTH_SOUND,
    .height = DEBUG_MENU_HEIGHT_SOUND,
    .paletteNum = 15,
    .baseBlock = 1,
};

static const struct WindowTemplate sDebugMenuWindowTemplateFullScreen =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 28,
    .height = 18,
    .paletteNum = 15,
    .baseBlock = 1,
};

static bool32 Debug_SaveCallbackMenu(struct DebugMenuOption *callbackItems);

// *******************************
// Functions universal
void Debug_ShowMainMenu(void)
{
    sDebugMenuListData = AllocZeroed(sizeof(*sDebugMenuListData));
    sDebugMenuListData->menuType = DEBUG_BASIC_MENU;
    Debug_ShowMenu(DebugTask_HandleMenuInput_General, sDebugMenu_Actions_Main);
}

#define tMenuTaskId          data[0]
#define tWindowId            data[1]
#define tSubWindowId         data[2]
#define tInput               data[3]
#define tDigit               data[4]
#define tSpriteId            data[5]
#define tStepsDataIndex      data[9]
#define tSubstep             data[10]
#define tStep                data[11]
#define STEPS_DATA_PTR_ARG        12
#define DEBUG_SELECTION_PTR_ARG   14

static bool32 Debug_SaveCallbackMenu(struct DebugMenuOption *callbackItems)
{
    bool32 success = FALSE;
    for (u32 i = 0; i < DEBUG_MAX_SUB_MENU_LEVELS; i++)
    {
        if (sDebugMenuListData->subMenuItems[i] == NULL)
        {
            sDebugMenuListData->subMenuItems[i] = callbackItems;
            success = TRUE;
            break;
        }
    }
    return success;
}

static u32 Debug_RemoveCallbackMenu(void)
{
    u32 freeCallbackLevel = 0;
    for (u32 i = DEBUG_MAX_SUB_MENU_LEVELS; i > 0; i--)
    {
        if (sDebugMenuListData->subMenuItems[i - 1] != NULL)
        {
            sDebugMenuListData->subMenuItems[i - 1] = NULL;
            freeCallbackLevel = i - 1;
            break;
        }
    }
    return freeCallbackLevel;
}

static const struct DebugMenuOption *Debug_GetCurrentCallbackMenu(void)
{
    const struct DebugMenuOption *callbackItems = NULL;
    for (u32 i = DEBUG_MAX_SUB_MENU_LEVELS; i > 0; i--)
    {
        if (sDebugMenuListData->subMenuItems[i - 1] != NULL)
        {
            callbackItems = sDebugMenuListData->subMenuItems[i - 1];
            break;
        }
    }
    return callbackItems;
}

static bool32 IsSubMenuAction(const void *action)
{
    return action == DebugAction_OpenSubMenu
        || action == DebugAction_OpenSubMenuFlagsVars
        || action == DebugAction_OpenSubMenuFakeRTC
        || action == DebugAction_OpenSubMenuCreateFollowerNPC
        || action == DebugAction_OpenSubMenuTrainers
        || action == DebugAction_OpenOutbreakMenu;
}

static u32 Debug_GenerateListBasicMenu(const struct DebugMenuOption *items)
{
    u32 totalItems = 0;
    for (u32 i = 0; items[i].text != NULL; i++)
    {
        sDebugMenuListData->listItems[i].id = i;
        StringExpandPlaceholders(gStringVar4, items[i].text);
        if (IsSubMenuAction(items[i].action))
            StringAppend(gStringVar4, sDebugText_Arrow);
        StringCopy(&sDebugMenuListData->itemNames[i][0], gStringVar4);
        sDebugMenuListData->listItems[i].name = &sDebugMenuListData->itemNames[i][0];
        totalItems++;
    }
    return totalItems;
}

static void Debug_ShowMenu(DebugFunc HandleInput, const struct DebugMenuOption *items)
{
    struct ListMenuTemplate menuTemplate = {0};
    u8 windowId;
    u8 menuTaskId;
    u8 inputTaskId;

    if (items != NULL)
        Debug_SaveCallbackMenu((struct DebugMenuOption *)items);
    else
        items = Debug_GetCurrentCallbackMenu();

    // create window
    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sDebugMenuWindowTemplateMain);
    DrawStdWindowFrame(windowId, FALSE);
    CopyWindowToVram(windowId, COPYWIN_GFX);

    u32 totalItems = generateListFunctions[sDebugMenuListData->menuType](items);

    // create list menu
    menuTemplate.items = sDebugMenuListData->listItems;
    menuTemplate.moveCursorFunc = ListMenuDefaultCursorMoveFunc;
    menuTemplate.totalItems = totalItems;
    menuTemplate.maxShowed = DEBUG_MENU_HEIGHT_MAIN;
    menuTemplate.windowId = windowId;
    menuTemplate.header_X = 0;
    menuTemplate.item_X = 8;
    menuTemplate.cursor_X = 0;
    menuTemplate.upText_Y = 1;
    menuTemplate.cursorPal = 2;
    menuTemplate.fillValue = 1;
    menuTemplate.cursorShadowPal = 3;
    menuTemplate.lettersSpacing = 1;
    menuTemplate.itemVerticalPadding = 0;
    menuTemplate.scrollMultiple = LIST_NO_MULTIPLE_SCROLL;
    menuTemplate.fontId = DEBUG_MENU_FONT;
    menuTemplate.cursorKind = 0;
    menuTaskId = ListMenuInit(&menuTemplate, 0, 0);

    // create input handler task
    inputTaskId = CreateTask(HandleInput, 3);
    gTasks[inputTaskId].tMenuTaskId = menuTaskId;
    gTasks[inputTaskId].tWindowId = windowId;
    gTasks[inputTaskId].tSubWindowId = WINDOW_NONE;
    gTasks[inputTaskId].tSpriteId = SPRITE_NONE;

    // draw everything
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void Debug_CreateInputDisplayWindow(u8 taskId)
{
    u8 windowId;

    ClearStdWindowAndFrame(gTasks[taskId].tWindowId, TRUE);
    RemoveWindow(gTasks[taskId].tWindowId);
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sDebugMenuWindowTemplateExtra);
    DrawStdWindowFrame(windowId, FALSE);
    CopyWindowToVram(windowId, COPYWIN_FULL);
    gTasks[taskId].tSubWindowId = windowId;
}

static void DestroyDebugIcon(u8 taskId)
{
    if (gTasks[taskId].tSpriteId != SPRITE_NONE)
    {
        FreeSpriteTilesByTag(DEBUG_ICON_TAG);
        FreeSpritePaletteByTag(DEBUG_ICON_TAG);
        DestroySprite(&gSprites[gTasks[taskId].tSpriteId]);
        gTasks[taskId].tSpriteId = 0xFF;
    }
}

static void Debug_ResetInputDisplayMonIcon(u8 taskId, enum Species species)
{
    DestroyDebugIcon(taskId);
    gTasks[taskId].tSpriteId = CreateTaggedMonIcon(DEBUG_ICON_TAG, DEBUG_ICON_TAG, species);
    gSprites[gTasks[taskId].tSpriteId].callback = SpriteCB_MonIcon;
    gSprites[gTasks[taskId].tSpriteId].x = DEBUG_NUMBER_ICON_X;
    gSprites[gTasks[taskId].tSpriteId].y = DEBUG_NUMBER_ICON_Y;
    gSprites[gTasks[taskId].tSpriteId].subpriority = 4;
    gSprites[gTasks[taskId].tSpriteId].oam.priority = 0;
}

static void DebugNativeStep_PrintWindowSelection(u8 taskId)
{
    u32 windowId = gTasks[taskId].tSubWindowId;
    StringCopy(gStringVar4, gText_DigitIndicator[gTasks[taskId].tDigit]);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(windowId, DEBUG_MENU_FONT, gStringVar1, 0, 0                    , 0, NULL);
    AddTextPrinterParameterized(windowId, DEBUG_MENU_FONT, gStringVar2, 0, 1 * DEBUG_LINE_HEIGHT, 0, NULL);
    AddTextPrinterParameterized(windowId, DEBUG_MENU_FONT, gStringVar3, 0, 2 * DEBUG_LINE_HEIGHT, 0, NULL);
    AddTextPrinterParameterized(windowId, DEBUG_MENU_FONT, gStringVar4, 0, 3 * DEBUG_LINE_HEIGHT, 0, NULL);
}

static void Debug_DestroyMenu(u8 taskId)
{
    if (gTasks[taskId].tSubWindowId != WINDOW_NONE)
    {
        DestroyDebugIcon(taskId);
        ClearStdWindowAndFrame(gTasks[taskId].tSubWindowId, TRUE);
        RemoveWindow(gTasks[taskId].tSubWindowId);
    }
    DestroyListMenuTask(gTasks[taskId].tMenuTaskId, NULL, NULL);
    ClearStdWindowAndFrame(gTasks[taskId].tWindowId, TRUE);
    RemoveWindow(gTasks[taskId].tWindowId);
    DestroyTask(taskId);
}

static void Debug_DestroyMenu_Full(u8 taskId)
{
    if (gTasks[taskId].tSubWindowId != WINDOW_NONE)
    {
        DestroyDebugIcon(taskId);
        ClearStdWindowAndFrame(gTasks[taskId].tSubWindowId, TRUE);
        RemoveWindow(gTasks[taskId].tSubWindowId);
    }
    DestroyListMenuTask(gTasks[taskId].tMenuTaskId, NULL, NULL);
    ClearStdWindowAndFrame(gTasks[taskId].tWindowId, TRUE);
    RemoveWindow(gTasks[taskId].tWindowId);
    DestroyTask(taskId);
    ScriptContext_Enable();
    UnfreezeObjectEvents();
    Free(sDebugMenuListData);
}

static void Debug_DestroyMenu_Full_Script(u8 taskId, const u8 *script)
{
    Debug_DestroyMenu_Full(taskId);
    LockPlayerFieldControls();
    FreezeObjectEvents();
    ScriptContext_SetupScript(script);
}

static void Debug_HandleInput_Numeric(u8 taskId, s32 min, s32 max, u32 digits)
{
    if (JOY_NEW(DPAD_UP))
    {
        gTasks[taskId].tInput += sPowersOfTen[gTasks[taskId].tDigit];
        if (gTasks[taskId].tInput > max)
            gTasks[taskId].tInput = max;
    }
    if (JOY_NEW(DPAD_DOWN))
    {
        gTasks[taskId].tInput -= sPowersOfTen[gTasks[taskId].tDigit];
        if (gTasks[taskId].tInput < min)
            gTasks[taskId].tInput = min;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (gTasks[taskId].tDigit > 0)
            gTasks[taskId].tDigit -= 1;
    }
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (gTasks[taskId].tDigit < digits - 1)
            gTasks[taskId].tDigit += 1;
    }
}

enum SongType { SONG_SE, SONG_MUS };
enum FindSongMode { SONG_FIRST_GE, SONG_FIRST_GT, SONG_LAST_LT };
u32 FindSong(enum SongType, enum FindSongMode, u32 fromSongId);

static void Debug_HandleInput_SongId(u8 taskId, enum SongType type, u32 digits)
{
    if (JOY_NEW(DPAD_UP))
    {
        for (u32 i = 0; i < sPowersOfTen[gTasks[taskId].tDigit]; i++)
            gTasks[taskId].tInput = FindSong(type, SONG_FIRST_GT, gTasks[taskId].tInput);
    }
    if (JOY_NEW(DPAD_DOWN))
    {
        for (u32 i = 0; i < sPowersOfTen[gTasks[taskId].tDigit]; i++)
            gTasks[taskId].tInput = FindSong(type, SONG_LAST_LT, gTasks[taskId].tInput);
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (gTasks[taskId].tDigit > 0)
            gTasks[taskId].tDigit -= 1;
    }
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (gTasks[taskId].tDigit < digits - 1)
            gTasks[taskId].tDigit += 1;
    }
}

static void DebugAction_Cancel(u8 taskId)
{
    Debug_DestroyMenu_Full(taskId);
    ScriptContext_Enable();
}

static void DebugAction_DestroyExtraWindow(u8 taskId)
{
    DestroyDebugIcon(taskId);
    ClearStdWindowAndFrame(gTasks[taskId].tWindowId, TRUE);
    RemoveWindow(gTasks[taskId].tWindowId);

    ClearStdWindowAndFrame(gTasks[taskId].tSubWindowId, TRUE);
    RemoveWindow(gTasks[taskId].tSubWindowId);

    DestroyListMenuTask(gTasks[taskId].tMenuTaskId, NULL, NULL);
    DestroyTask(taskId);
    ScriptContext_Enable();
    UnfreezeObjectEvents();
}

static u8 DebugNativeStep_CreateDebugWindow(void)
{
    u8 windowId;

    LockPlayerFieldControls();
    FreezeObjectEvents();
    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sDebugMenuWindowTemplateExtra);
    DrawStdWindowFrame(windowId, FALSE);
    CopyWindowToVram(windowId, COPYWIN_FULL);

    return windowId;
}

static void DebugNativeStep_CloseDebugWindow(u8 taskId)
{
    ClearStdWindowAndFrame(gTasks[taskId].tSubWindowId, TRUE);
    RemoveWindow(gTasks[taskId].tSubWindowId);
    DestroyTask(taskId);
    UnfreezeObjectEvents();
    UnlockPlayerFieldControls();
}

static void DebugSelection_SetData(u8 taskId, u32 index, u16 value)
{
    u16 *stepsData = (u16 *)GetWordTaskArg(taskId, STEPS_DATA_PTR_ARG);
    stepsData[index] = value;
}

static u16 DebugSelection_GetData(u8 taskId, u32 index)
{
    u16 *stepsData = (u16 *)GetWordTaskArg(taskId, STEPS_DATA_PTR_ARG);
    return stepsData[index];
}

static void DebugAction_Selection_PrepareStep(u8 taskId, const struct DebugSelectionStep *selectionStep)
{
    u32 min, max;
    if (selectionStep->useMinFunc)
        min = selectionStep->minFunc(taskId);
    else
        min = selectionStep->minValue;
    if (selectionStep->useMaxFunc)
        max = selectionStep->maxFunc(taskId);
    else
        max = selectionStep->maxValue;

    gTasks[taskId].tInput = DebugSelection_GetData(taskId, gTasks[taskId].tStepsDataIndex);
    if (gTasks[taskId].tInput < min)
        gTasks[taskId].tInput = min;
    if (gTasks[taskId].tInput > max)
        gTasks[taskId].tInput = max;

    gTasks[taskId].tDigit = 0;
    selectionStep->stepUpdate(taskId, selectionStep->digits, min, max);
    gTasks[taskId].func = DebugAction_Selection_StepUpdate;
}

static void DebugAction_Selection_Cancel(u8 taskId)
{
    struct DebugSelection *selection = (struct DebugSelection *)GetWordTaskArg(taskId, DEBUG_SELECTION_PTR_ARG);
    if (gTasks[taskId].tStep == 0)
    {
        selection->onCancel(taskId);
        Free((void *)GetWordTaskArg(taskId, STEPS_DATA_PTR_ARG));
        return;
    }
    gTasks[taskId].tStep--;
    DebugAction_Selection_PrepareStep(taskId, selection->steps[gTasks[taskId].tStep]);
}

static void DebugAction_Selection_StepUpdate(u8 taskId)
{
    SelectionStep selectionStep = ((struct DebugSelection *)GetWordTaskArg(taskId, DEBUG_SELECTION_PTR_ARG))->steps[gTasks[taskId].tStep];
    if (JOY_NEW(A_BUTTON))
    {
        selectionStep->stepConfirm(taskId);
        gTasks[taskId].tSubstep++;
        gTasks[taskId].tStepsDataIndex++;
        if (gTasks[taskId].tSubstep < selectionStep->substepCount)
        {
            DebugAction_Selection_PrepareStep(taskId, selectionStep);
            return;
        }
        gTasks[taskId].tSubstep = 0;
        gTasks[taskId].func = DebugAction_Selection_NextStep;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].tStepsDataIndex--;
        if (gTasks[taskId].tSubstep > 0)
        {
            gTasks[taskId].tSubstep--;
            DebugAction_Selection_PrepareStep(taskId, selectionStep);
            return;
        }
        gTasks[taskId].tSubstep = 0;
        gTasks[taskId].func = DebugAction_Selection_Cancel;
    }
    else if (JOY_NEW(DPAD_ANY))
    {
        u32 min, max;
        if (selectionStep->useMinFunc)
            min = selectionStep->minFunc(taskId);
        else
            min = selectionStep->minValue;
        if (selectionStep->useMaxFunc)
            max = selectionStep->maxFunc(taskId);
        else
            max = selectionStep->maxValue;
        Debug_HandleInput_Numeric(taskId, min, max, selectionStep->digits);
        PlaySE(SE_SELECT);
        selectionStep->stepUpdate(taskId, selectionStep->digits, min, max);
        return;
    }
}

static void DebugAction_Selection_NextStep(u8 taskId)
{
    struct DebugSelection *selection = (struct DebugSelection *)GetWordTaskArg(taskId, DEBUG_SELECTION_PTR_ARG);
    gTasks[taskId].tStep++;
    if (gTasks[taskId].tStep == selection->maxSteps)
    {
        if (selection->onComplete(taskId))
        {
            Free((void *)GetWordTaskArg(taskId, STEPS_DATA_PTR_ARG));
            return;
        }
    }
    DebugAction_Selection_PrepareStep(taskId, selection->steps[gTasks[taskId].tStep]);
}

static void Debug_Selection_StepsDataInit(u8 taskId, const struct DebugSelection *selection)
{
    u32 dataSize = 0;
    for (u32 i = 0; i < selection->maxSteps; i++)
    {
        if (selection->steps[i]->substepCount)
            dataSize += selection->steps[i]->substepCount;
        else
            dataSize += 1;
    }
    u16 *stepsData = AllocZeroed(dataSize * sizeof(u16));
    SetWordTaskArg(taskId, STEPS_DATA_PTR_ARG, (u32) stepsData);
}

static void DebugAction_Selection_Init(u8 taskId, const void *params)
{
    const struct DebugSelection *selection = (const struct DebugSelection *)params;
    gTasks[taskId].tStep = -1;
    SetWordTaskArg(taskId, DEBUG_SELECTION_PTR_ARG, (u32) selection);
    Debug_Selection_StepsDataInit(taskId, selection);
    selection->onInit(taskId);
    gTasks[taskId].func = DebugAction_Selection_NextStep;
}

static void DebugSelectionStep_GenericInputConfirm(u8 taskId)
{
    DebugSelection_SetData(taskId, gTasks[taskId].tStepsDataIndex, gTasks[taskId].tInput);
}

static void DebugSelectionStep_GenericInputConfirmAndDestroyIcon(u8 taskId)
{
    DestroyDebugIcon(taskId);
    DebugSelectionStep_GenericInputConfirm(taskId);
}

static void DebugSelectionStep_ReturnToUtilMenu(u8 taskId)
{
    Debug_RemoveCallbackMenu();
    DebugAction_OpenSubMenu(taskId, sDebugMenu_Actions_Utilities);
}

static void DebugSelectionStep_ReturnToOutbreakMenu(u8 taskId)
{
    Debug_RemoveCallbackMenu();
    DebugAction_OpenOutbreakMenu(taskId, sDebugMenu_Actions_MassOutbreak);
}

static void DebugSelectionStep_ReturnToFlagsVarsMenu(u8 taskId)
{
    Debug_RemoveCallbackMenu();
    DebugAction_OpenSubMenuFlagsVars(taskId, sDebugMenu_Actions_Flags);
}

static void DebugSelectionStep_ReturnToGiveMenu(u8 taskId)
{
    Debug_RemoveCallbackMenu();
    DebugAction_OpenSubMenu(taskId, sDebugMenu_Actions_Give);
}

static void DebugSelectionStep_ReturnToTrainersMenu(u8 taskId)
{
    Debug_DestroyMenu(taskId);
    Debug_RemoveCallbackMenu();
    Debug_ShowMenu(DebugTask_HandleMenuInput_General, sDebugMenu_Actions_Trainers);
}

static u32 Debug_GenerateListTrainerMenu(const struct DebugMenuOption *items)
{
    u32 trainer1Id = sDebugMenuListData->data[0];
    u32 trainer2Id = sDebugMenuListData->data[2];
    u32 partnerId = sDebugMenuListData->data[4];

    s32 rematchTableId = sDebugMenuListData->data[1];
    bool32 isRealFight = sDebugMenuListData->data[3];
    bool32 noDraw;
    u32 offset = 0;
    u8 totalItems = 0;
    for (u32 i = 0; i < (ARRAY_COUNT(sDebugMenu_Actions_Trainers) - 1); i++)
    {
        noDraw = FALSE;
        switch (i)
        {
        case 1:
            ConvertIntToDecimalStringN(gStringVar1, trainer1Id, STR_CONV_MODE_LEADING_ZEROS, 3);
            break;
        case 2:
            if (trainer2Id == TRAINER_NONE)
                StringCopy(gStringVar1, COMPOUND_STRING("None"));
            else
                ConvertIntToDecimalStringN(gStringVar1, trainer2Id, STR_CONV_MODE_LEADING_ZEROS, 3);
            break;
        case 3:
            if (partnerId == PARTNER_NONE)
                StringCopy(gStringVar1, COMPOUND_STRING("None"));
            else
                ConvertIntToDecimalStringN(gStringVar1, partnerId, STR_CONV_MODE_LEADING_ZEROS, 3);
            break;
        case 4:
            if (sDebugMenuListData->data[5] || trainer2Id != TRAINER_NONE || partnerId != PARTNER_NONE)
                StringCopy(gStringVar1, COMPOUND_STRING("{COLOR GREEN} TRUE"));
            else
                StringCopy(gStringVar1, COMPOUND_STRING("{COLOR RED} FALSE"));
            break;
        case 5:
            if (!isRealFight)
            {
                noDraw = TRUE;
                break;
            }
            if (rematchTableId == -1)
            {
                if (HasTrainerBeenFought(trainer1Id))
                    StringCopy(gStringVar1, COMPOUND_STRING("1"));
                else
                    StringCopy(gStringVar1, COMPOUND_STRING("0"));
                StringCopy(gStringVar2, COMPOUND_STRING("1"));
            }
            else
            {
                ConvertIntToDecimalStringN(gStringVar1, CountBattledRematchTeams(rematchTableId), STR_CONV_MODE_LEADING_ZEROS, 1);
                ConvertIntToDecimalStringN(gStringVar2, CountMaxPossibleRematch(rematchTableId), STR_CONV_MODE_LEADING_ZEROS, 1);
            }
            break;
        case 6:
            if (FREE_MATCH_CALL || I_VS_SEEKER_CHARGING || !isRealFight || rematchTableId == -1)
            {
                noDraw = TRUE;
                break;
            }
            if (GetActiveTrainerRematches(rematchTableId))
                StringCopy(gStringVar1, COMPOUND_STRING("{COLOR GREEN} TRUE"));
            else
                StringCopy(gStringVar1, COMPOUND_STRING("{COLOR RED} FALSE"));
            break;
        case 8:
            if (FREE_MATCH_CALL || I_VS_SEEKER_CHARGING == 0)
                noDraw = TRUE;
            break;
        }

        StringExpandPlaceholders(gStringVar4, sDebugMenu_Actions_Trainers[i].text);
        StringCopy(&sDebugMenuListData->itemNames[i][0], gStringVar4);

        if (noDraw)
        {
            offset++;
        }
        else
        {
            sDebugMenuListData->listItems[i - offset].name = &sDebugMenuListData->itemNames[i][0];
            sDebugMenuListData->listItems[i - offset].id = i;
            totalItems++;
        }
    }
    return totalItems;
}

static u32 Debug_GenerateListOutbreakMenu(const struct DebugMenuOption *items)
{
    u32 offset = 0;
    u32 totalItems = 0;
    bool32 noDraw;

    for (u32 i = 0; i < (ARRAY_COUNT(sDebugMenu_Actions_MassOutbreak) - 1); i++)
    {
        noDraw = FALSE;
        if (gSaveBlock1Ptr->outbreakDaysLeft == 0 && i >= 1 && i <= 7)
            noDraw = TRUE;
        switch (i)
        {
        case 0:
            if (gSaveBlock1Ptr->outbreakDaysLeft > 0)
                noDraw = TRUE;
            break;
        case 2:
            StringCopy(gStringVar1, GetSpeciesName(gSaveBlock1Ptr->outbreakPokemonSpecies));
            break;
        case 3:
            GetMapName(gStringVar1, Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->outbreakLocationMapGroup, gSaveBlock1Ptr->outbreakLocationMapNum)->regionMapSectionId, 0);
            break;
        case 4:
            ConvertIntToDecimalStringN(gStringVar1, gSaveBlock1Ptr->outbreakPokemonLevel, STR_CONV_MODE_RIGHT_ALIGN, 3);
            break;
        case 6:
            ConvertIntToDecimalStringN(gStringVar1, gSaveBlock1Ptr->outbreakPokemonProbability, STR_CONV_MODE_RIGHT_ALIGN, 3);
            break;
        case 7:
            ConvertIntToDecimalStringN(gStringVar1, gSaveBlock1Ptr->outbreakDaysLeft, STR_CONV_MODE_RIGHT_ALIGN, 3);
            break;
        }

        StringExpandPlaceholders(gStringVar4, sDebugMenu_Actions_MassOutbreak[i].text);
        StringCopy(&sDebugMenuListData->itemNames[i][0], gStringVar4);

        if (noDraw)
        {
            offset++;
        }
        else
        {
            sDebugMenuListData->listItems[i - offset].name = &sDebugMenuListData->itemNames[i][0];
            sDebugMenuListData->listItems[i - offset].id = i;
            totalItems++;
        }
    }
    return totalItems;
}

static const u16 sLocationFlags[] =
{
    FLAG_VISITED_LITTLEROOT_TOWN,
    FLAG_VISITED_OLDALE_TOWN,
    FLAG_VISITED_DEWFORD_TOWN,
    FLAG_VISITED_LAVARIDGE_TOWN,
    FLAG_VISITED_FALLARBOR_TOWN,
    FLAG_VISITED_VERDANTURF_TOWN,
    FLAG_VISITED_PACIFIDLOG_TOWN,
    FLAG_VISITED_PETALBURG_CITY,
    FLAG_VISITED_SLATEPORT_CITY,
    FLAG_VISITED_MAUVILLE_CITY,
    FLAG_VISITED_RUSTBORO_CITY,
    FLAG_VISITED_FORTREE_CITY,
    FLAG_VISITED_LILYCOVE_CITY,
    FLAG_VISITED_MOSSDEEP_CITY,
    FLAG_VISITED_SOOTOPOLIS_CITY,
    FLAG_VISITED_EVER_GRANDE_CITY,
    FLAG_LANDMARK_POKEMON_LEAGUE,
    FLAG_LANDMARK_BATTLE_FRONTIER,
    FLAG_WORLD_MAP_PALLET_TOWN,
    FLAG_WORLD_MAP_VIRIDIAN_CITY,
    FLAG_WORLD_MAP_PEWTER_CITY,
    FLAG_WORLD_MAP_CERULEAN_CITY,
    FLAG_WORLD_MAP_LAVENDER_TOWN,
    FLAG_WORLD_MAP_VERMILION_CITY,
    FLAG_WORLD_MAP_CELADON_CITY,
    FLAG_WORLD_MAP_FUCHSIA_CITY,
    FLAG_WORLD_MAP_CINNABAR_ISLAND,
    FLAG_WORLD_MAP_INDIGO_PLATEAU_EXTERIOR,
    FLAG_WORLD_MAP_SAFFRON_CITY,
    FLAG_WORLD_MAP_ONE_ISLAND,
    FLAG_WORLD_MAP_TWO_ISLAND,
    FLAG_WORLD_MAP_THREE_ISLAND,
    FLAG_WORLD_MAP_FOUR_ISLAND,
    FLAG_WORLD_MAP_FIVE_ISLAND,
    FLAG_WORLD_MAP_SEVEN_ISLAND,
    FLAG_WORLD_MAP_SIX_ISLAND,
    FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F,
    FLAG_WORLD_MAP_ROUTE10_POKEMON_CENTER_1F,
};

static u32 Debug_CheckToggleFlags(u8 id)
{
    u32 result = FALSE;

    switch (id)
    {
    case DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_POKEDEX:
        result = FlagGet(FLAG_SYS_POKEDEX_GET);
        break;
    case DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_NATDEX:
        result = IsNationalPokedexEnabled();
        break;
    case DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_POKENAV:
        result = FlagGet(FLAG_SYS_POKENAV_GET);
        break;
    case DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_MATCH_CALL:
        result = FlagGet(FLAG_ADDED_MATCH_CALL_TO_POKENAV) && FlagGet(FLAG_HAS_MATCH_CALL);
        break;
    case DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_RUN_SHOES:
        result = FlagGet(FLAG_SYS_B_DASH);
        break;
    case DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_LOCATIONS:
        result = TRUE;
        for (u32 i = 0; i < ARRAY_COUNT(sLocationFlags); i++)
        {
            if (sLocationFlags[i] == 0) // Location flags for Frlg are set to flag 0 in Emerald and vice versa
                continue;

            if (!FlagGet(sLocationFlags[i]))
            {
                result = FALSE;
                break;
            }
        }
        break;
    case DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_BADGES_ALL:
        result = TRUE;
        for (u32 i = 0; i < ARRAY_COUNT(gBadgeFlags); i++)
        {
            if (!FlagGet(gBadgeFlags[i]))
            {
                result = FALSE;
                break;
            }
        }
        break;
    case DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_GAME_CLEAR:
        result = FlagGet(FLAG_SYS_GAME_CLEAR);
        break;
    case DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_FRONTIER_PASS:
        result = FlagGet(FLAG_SYS_FRONTIER_PASS);
        break;
    case DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_COLLISION:
        result = OW_FLAG_NO_COLLISION ? FlagGet(OW_FLAG_NO_COLLISION) : DEBUG_OPTION_CANT_BE_TOGGLED;
        break;
    case DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_ENCOUNTER:
        result = WE_FLAG_NO_ENCOUNTER ? FlagGet(WE_FLAG_NO_ENCOUNTER) : DEBUG_OPTION_CANT_BE_TOGGLED;
        break;
    case DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_TRAINER_SEE:
        result = OW_FLAG_NO_TRAINER_SEE ? FlagGet(OW_FLAG_NO_TRAINER_SEE) : DEBUG_OPTION_CANT_BE_TOGGLED;
        break;
    case DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_CATCHING:
        result = WE_FLAG_NO_CATCHING ? FlagGet(WE_FLAG_NO_CATCHING) : DEBUG_OPTION_CANT_BE_TOGGLED;
        break;
    case DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_BAG_USE:
        result = VarGet(B_VAR_NO_BAG_USE);
        if (result >= NO_BAG_INVALID_VALUE)
            result = NO_BAG_INVALID_VALUE;
        break;
    default:
        result = DEBUG_OPTION_CANT_BE_TOGGLED;
        break;
    }

    return result;
}

static u32 Debug_GenerateListFlagsMenu(const struct DebugMenuOption *items)
{
    const u8 sColor_Red[] = _("{COLOR RED}");
    const u8 sColor_Green[] = _("{COLOR GREEN}");
    u32 i, flagResult = 0;
    u8 const *name = NULL;

    u8 totalItems = min(ARRAY_COUNT(sDebugMenu_Actions_Flags) - 1, DEBUG_MAX_MENU_ITEMS);

    // Copy item names for all entries but the last (which is Cancel)
    for (i = 0; i < totalItems; i++)
    {
        flagResult = Debug_CheckToggleFlags(i);
        if (i == DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_BAG_USE)
            name = sDebugMenu_Actions_BagUse_Options[flagResult];
        else
            name = sDebugMenu_Actions_Flags[i].text;

        if (i == DEBUG_FLAGVAR_MENU_ITEM_TOGGLE_BAG_USE && flagResult == NO_BAG_INVALID_VALUE)
            flagResult = FALSE;

        if (flagResult == DEBUG_OPTION_CANT_BE_TOGGLED)
        {
            StringCopy(&sDebugMenuListData->itemNames[i][0], name);
        }
        else if (flagResult)
        {
            StringCopy(gStringVar1, sColor_Green);
            StringExpandPlaceholders(gStringVar4, name);
            StringCopy(&sDebugMenuListData->itemNames[i][0], gStringVar4);
        }
        else
        {
            StringCopy(gStringVar1, sColor_Red);
            StringExpandPlaceholders(gStringVar4, name);
            StringCopy(&sDebugMenuListData->itemNames[i][0], gStringVar4);
        }

        sDebugMenuListData->listItems[i].name = &sDebugMenuListData->itemNames[i][0];
        sDebugMenuListData->listItems[i].id = i;
    }
    return totalItems;
}

static void DebugTask_HandleMenuInput_General(u8 taskId)
{
    const struct DebugMenuOption *options = Debug_GetCurrentCallbackMenu();
    u32 input = ListMenu_ProcessInput(gTasks[taskId].tMenuTaskId);
    struct DebugMenuOption option = options[input];

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        if (option.action != NULL)
        {
            if (option.actionParams  != NULL)
                 ((DebugFuncWithParams)option.action)(taskId, option.actionParams);
            else
                ((DebugFunc)option.action)(taskId);
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        if (Debug_GetCurrentCallbackMenu() != NULL && Debug_RemoveCallbackMenu() != 0)
        {
            Debug_DestroyMenu(taskId);
            if (sDebugMenuListData->menuType != DEBUG_BASIC_MENU)
                sDebugMenuListData->menuType = DEBUG_BASIC_MENU;
            Debug_ShowMenu(DebugTask_HandleMenuInput_General, NULL);
        }
        else
        {
            Debug_DestroyMenu_Full(taskId);
            ScriptContext_Enable();
        }
    }
}

static void DebugAction_OpenSubMenuWithType(u8 taskId, const struct DebugMenuOption *items, enum DebugMenuTypes menuType)
{
    sDebugMenuListData->menuType = menuType;
    Debug_DestroyMenu(taskId);
    Debug_ShowMenu(DebugTask_HandleMenuInput_General, items);
}

static void DebugAction_OpenSubMenuTrainers(u8 taskId, const struct DebugMenuOption *items)
{
    sDebugMenuListData->data[0] = TRAINER_NONE;
    DebugAction_OpenSubMenuWithType(taskId, items, DEBUG_TRAINERS_MENU);
}

static void DebugAction_OpenSubMenuFlagsVars(u8 taskId, const struct DebugMenuOption *items)
{
    DebugAction_OpenSubMenuWithType(taskId, items, DEBUG_FLAGS_MENU);
}

static void DebugAction_OpenOutbreakMenu(u8 taskId, const struct DebugMenuOption *items)
{
    DebugAction_OpenSubMenuWithType(taskId, items, DEBUG_OUTBREAK_MENU);
}

static void DebugAction_OpenSubMenu(u8 taskId, const struct DebugMenuOption *items)
{
    DebugAction_OpenSubMenuWithType(taskId, items, DEBUG_BASIC_MENU);
}

static void DebugAction_OpenSubMenuFakeRTC(u8 taskId, const struct DebugMenuOption *items)
{
    if (!OW_USE_FAKE_RTC)
        Debug_DestroyMenu_Full_Script(taskId, Debug_EventScript_FakeRTCNotEnabled);
    else
        DebugAction_OpenSubMenuWithType(taskId, items, DEBUG_BASIC_MENU);
}

static void DebugAction_ExecuteScript(u8 taskId, void *script)
{
    Debug_DestroyMenu_Full_Script(taskId, (const u8 *)script);
}

static void DebugAction_ToggleFlag(u8 taskId, void *flagToggleFunc)
{
    ((DebugFunc)flagToggleFunc)(taskId);
    generateListFunctions[sDebugMenuListData->menuType](NULL);
    RedrawListMenu(gTasks[taskId].tMenuTaskId);
}

static void DebugAction_OpenSubMenuCreateFollowerNPC(u8 taskId, const struct DebugMenuOption *items)
{
    if (FNPC_ENABLE_NPC_FOLLOWERS)
        DebugAction_OpenSubMenuWithType(taskId, items, DEBUG_BASIC_MENU);
    else
        Debug_DestroyMenu_Full_Script(taskId, Debug_Follower_NPC_Not_Enabled);
}

// *******************************
// Actions Utilities

static void DebugAction_Util_Fly(u8 taskId)
{
    Debug_DestroyMenu(taskId);
    SetMainCallback2(CB2_OpenFlyMap);
}

static void DebugSelectionStep_UpdateMapGroup(u8 taskId, u8 digits, u32 min, u32 max)
{
    ConvertIntToDecimalStringN(gStringVar2, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, digits);
    ConvertIntToDecimalStringN(gStringVar3, max, STR_CONV_MODE_LEADING_ZEROS, digits);
    StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("Group: {STR_VAR_2} / {STR_VAR_3}"));
    StringCopy(gStringVar2, COMPOUND_STRING(""));
    StringCopy(gStringVar3, COMPOUND_STRING(""));
    DebugNativeStep_PrintWindowSelection(taskId);
}

static void DebugSelectionStep_UpdateMapNum(u8 taskId, u8 digits, u32 min, u32 max)
{
    u16 mapGroup = DebugSelection_GetData(taskId, gTasks[taskId].tStep - 1);
    ConvertIntToDecimalStringN(gStringVar2, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, digits);
    ConvertIntToDecimalStringN(gStringVar3, max, STR_CONV_MODE_LEADING_ZEROS, digits);
    StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("Map: {STR_VAR_2} / {STR_VAR_3}"));
    StringCopy(gStringVar2, COMPOUND_STRING("MapSec:"));
    GetMapName(gStringVar3, Overworld_GetMapHeaderByGroupAndId(mapGroup, gTasks[taskId].tInput)->regionMapSectionId, 0);
    DebugNativeStep_PrintWindowSelection(taskId);
}

static u32 DebugSelectionStep_GetLastMapNum(u8 taskId)
{
    u16 mapGroup = DebugSelection_GetData(taskId, gTasks[taskId].tStep - 1);
    return (MAP_GROUP_COUNT[mapGroup] - 1);
}

static void DebugSelectionStep_UpdateWarp(u8 taskId, u8 digits, u32 min, u32 max)
{
    u16 mapGroup = DebugSelection_GetData(taskId, gTasks[taskId].tStep - 2);
    u16 mapNum = DebugSelection_GetData(taskId, gTasks[taskId].tStep - 1);
    ConvertIntToDecimalStringN(gStringVar2, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, digits);
    ConvertIntToDecimalStringN(gStringVar3, max, STR_CONV_MODE_LEADING_ZEROS, digits);
    StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("Warp: {STR_VAR_2} / {STR_VAR_3}"));
    GetMapName(gStringVar2, Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum)->regionMapSectionId, 0);
    StringCopy(gStringVar3, COMPOUND_STRING(""));
    DebugNativeStep_PrintWindowSelection(taskId);
}

static u32 DebugSelectionStep_GetLastWarp(u8 taskId)
{
    u16 mapGroup = DebugSelection_GetData(taskId, gTasks[taskId].tStep - 2);
    u16 mapNum = DebugSelection_GetData(taskId, gTasks[taskId].tStep - 1);
    u32 count = Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum)->events->warpCount;
    return (count - 1);
}

static bool32 DebugSelection_SetWarp_OnComplete(u8 taskId)
{
    SetWarpDestinationToMapWarp(DebugSelection_GetData(taskId, 0),
        DebugSelection_GetData(taskId, 1), DebugSelection_GetData(taskId, 2));
    DoWarp();
    ResetInitialPlayerAvatarState();
    DebugAction_DestroyExtraWindow(taskId);
    ScriptContext_Stop();
    return TRUE;
}

static const struct DebugSelectionStep sMapGroupSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateMapGroup,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 0,
    .maxValue = MAP_GROUPS_COUNT - 1,
    .digits = 3
};

static const struct DebugSelectionStep sMapNumSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateMapNum,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 0,
    .maxFunc = DebugSelectionStep_GetLastMapNum,
    .digits = 3,
    .useMaxFunc = TRUE,
};

static const struct DebugSelectionStep sWarpSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateWarp,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 0,
    .maxFunc = DebugSelectionStep_GetLastWarp,
    .digits = 3,
    .useMaxFunc = TRUE,
};

static const struct DebugSelection sWarpSelection = {
    .onInit = Debug_CreateInputDisplayWindow,
    .onCancel = DebugSelectionStep_ReturnToUtilMenu,
    .onComplete = DebugSelection_SetWarp_OnComplete,
    .steps = {&sMapGroupSelectionStep, &sMapNumSelectionStep, &sWarpSelectionStep},
    .maxSteps = 3,
};

void CheckSaveBlock1Size(struct ScriptContext *ctx)
{
    u32 currSb1Size = sizeof(struct SaveBlock1);
    u32 maxSb1Size = SECTOR_DATA_SIZE * (SECTOR_ID_SAVEBLOCK1_END - SECTOR_ID_SAVEBLOCK1_START + 1);
    ConvertIntToDecimalStringN(gStringVar1, currSb1Size, STR_CONV_MODE_LEFT_ALIGN, 6);
    ConvertIntToDecimalStringN(gStringVar2, maxSb1Size, STR_CONV_MODE_LEFT_ALIGN, 6);
    ConvertIntToDecimalStringN(gStringVar3, maxSb1Size - currSb1Size, STR_CONV_MODE_LEFT_ALIGN, 6);
    ConvertIntToDecimalStringN(gStringVar4, 1, STR_CONV_MODE_LEFT_ALIGN, 6);
}

void CheckSaveBlock2Size(struct ScriptContext *ctx)
{
    u32 currSb2Size = (sizeof(struct SaveBlock2));
    u32 maxSb2Size = SECTOR_DATA_SIZE;
    ConvertIntToDecimalStringN(gStringVar1, currSb2Size, STR_CONV_MODE_LEFT_ALIGN, 6);
    ConvertIntToDecimalStringN(gStringVar2, maxSb2Size, STR_CONV_MODE_LEFT_ALIGN, 6);
    ConvertIntToDecimalStringN(gStringVar3, maxSb2Size - currSb2Size, STR_CONV_MODE_LEFT_ALIGN, 6);
}

void CheckSaveBlock3Size(struct ScriptContext *ctx)
{
    u32 currSb3Size = (sizeof(struct SaveBlock3));
    u32 maxSb3Size = SAVE_BLOCK_3_CHUNK_SIZE * NUM_SECTORS_PER_SLOT;
    ConvertIntToDecimalStringN(gStringVar1, currSb3Size, STR_CONV_MODE_LEFT_ALIGN, 6);
    ConvertIntToDecimalStringN(gStringVar2, maxSb3Size, STR_CONV_MODE_LEFT_ALIGN, 6);
    ConvertIntToDecimalStringN(gStringVar3, maxSb3Size - currSb3Size, STR_CONV_MODE_LEFT_ALIGN, 6);
}

void CheckPokemonStorageSize(struct ScriptContext *ctx)
{
    u32 currPkmnStorageSize = sizeof(struct PokemonStorage);
    u32 maxPkmnStorageSize = SECTOR_DATA_SIZE * (SECTOR_ID_PKMN_STORAGE_END - SECTOR_ID_PKMN_STORAGE_START + 1);
    ConvertIntToDecimalStringN(gStringVar1, currPkmnStorageSize, STR_CONV_MODE_LEFT_ALIGN, 6);
    ConvertIntToDecimalStringN(gStringVar2, maxPkmnStorageSize, STR_CONV_MODE_LEFT_ALIGN, 6);
    ConvertIntToDecimalStringN(gStringVar3, maxPkmnStorageSize - currPkmnStorageSize, STR_CONV_MODE_LEFT_ALIGN, 6);
}

enum RoundMode
{
    ROUND_CEILING,
    ROUND_NEAREST,
    ROUND_FLOOR,
};

static u8 *ConvertQ22_10ToDecimalString(u8 *string, u32 q22_10, u32 decimalDigits, enum RoundMode roundMode)
{
    string = ConvertIntToDecimalStringN(string, q22_10 >> 10, STR_CONV_MODE_LEFT_ALIGN, 10);

    if (decimalDigits == 0)
        return string;

    *string++ = CHAR_PERIOD;

    q22_10 &= (1 << 10) - 1;
    while (decimalDigits-- > 1)
    {
        q22_10 *= 10;
        *string++ = CHAR_0 + (q22_10 >> 10);
        q22_10 &= (1 << 10) - 1;
    }

    q22_10 *= 10;
    switch (roundMode)
    {
    case ROUND_CEILING: q22_10 += (1 << 10) - 1; break;
    case ROUND_NEAREST: q22_10 += 1 << (10 - 1); break;
    case ROUND_FLOOR:                            break;
    }
    *string++ = CHAR_0 + (q22_10 >> 10);

    *string++ = EOS;

    return string;
}

void CheckROMSize(struct ScriptContext *ctx)
{
    extern u8 __rom_end[];
    u32 currROMSizeB = __rom_end - (const u8 *)ROM_START;
    u32 currROMSizeKB = (currROMSizeB + 1023) / 1024;
    u32 currROMFreeKB = ((const u8 *)ROM_END - __rom_end) / 1024;
    ConvertQ22_10ToDecimalString(gStringVar1, currROMSizeKB, 2, ROUND_CEILING);
    ConvertQ22_10ToDecimalString(gStringVar2, currROMFreeKB, 2, ROUND_FLOOR);
}

static void DebugSelectionStep_UpdateWeather(u8 taskId, u8 digits, u32 min, u32 max)
{
    if (gTasks[taskId].tInput == WEATHER_ABNORMAL)
    {
        if (JOY_NEW(DPAD_DOWN))
            gTasks[taskId].tInput--;
        else
            gTasks[taskId].tInput++;
    }
    ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, digits);
    StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("Weather ID: {STR_VAR_3}"));
    StringCopy(gStringVar2, GetWeatherName(gTasks[taskId].tInput));
    StringCopy(gStringVar3, COMPOUND_STRING(""));
    DebugNativeStep_PrintWindowSelection(taskId);
}

static bool32 DebugSelection_SetWeather_OnComplete(u8 taskId)
{
    SetWeather(DebugSelection_GetData(taskId, 0));
    Debug_DestroyMenu_Full(taskId);
    return TRUE;
}

static const struct DebugSelectionStep sWeatherSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateWeather,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = WEATHER_NONE,
    .maxValue = WEATHER_DYNAMIC - 1,
    .digits = 2
};

static const struct DebugSelection sSetWeatherSelection = {
    .onInit = Debug_CreateInputDisplayWindow,
    .onCancel = DebugSelectionStep_ReturnToUtilMenu,
    .onComplete = DebugSelection_SetWeather_OnComplete,
    .steps = {&sWeatherSelectionStep},
    .maxSteps = 1,
};

static void DebugAction_Util_WatchCredits(u8 taskId)
{
    Debug_DestroyMenu_Full(taskId);
    SetMainCallback2(CB2_StartCreditsSequence);
}

static void DebugAction_Player_Name(u8 taskId)
{
    DoNamingScreen(NAMING_SCREEN_PLAYER, gSaveBlock2Ptr->playerName, gSaveBlock2Ptr->playerGender, 0, 0, CB2_ReturnToFieldContinueScript);
}

static void DebugAction_Player_Gender(u8 taskId)
{
    if (gSaveBlock2Ptr->playerGender == MALE)
        gSaveBlock2Ptr->playerGender = FEMALE;
    else
        gSaveBlock2Ptr->playerGender = MALE;
    Debug_DestroyMenu_Full(taskId);
    ScriptContext_Enable();
}

static void DebugAction_Player_Id(u8 taskId)
{
    u32 trainerId = Random32();
    SetTrainerId(trainerId, gSaveBlock2Ptr->playerTrainerId);
    Debug_DestroyMenu_Full(taskId);
    ScriptContext_Enable();
}

static void DebugAction_Util_CheatStart(u8 taskId)
{
    if (!FlagGet(FLAG_SYS_CLOCK_SET))
        RtcInitLocalTimeOffset(0, 0);

    InitTimeBasedEvents();
    if (IS_FRLG)
        Debug_DestroyMenu_Full_Script(taskId, Debug_CheatStartFrlg);
    else
        Debug_DestroyMenu_Full_Script(taskId, Debug_CheatStart);
}

void BufferExpansionVersion(struct ScriptContext *ctx)
{
    static const u8 sText_Released[] = _("\nRelease Build");
    static const u8 sText_Unreleased[] = _("\nDevelopment Build");
    u8 *string = gStringVar1;
    *string++ = CHAR_v;
    string = ConvertIntToDecimalStringN(string, EXPANSION_VERSION_MAJOR, STR_CONV_MODE_LEFT_ALIGN, 3);
    *string++ = CHAR_PERIOD;
    string = ConvertIntToDecimalStringN(string, EXPANSION_VERSION_MINOR, STR_CONV_MODE_LEFT_ALIGN, 3);
    *string++ = CHAR_PERIOD;
    string = ConvertIntToDecimalStringN(string, EXPANSION_VERSION_PATCH, STR_CONV_MODE_LEFT_ALIGN, 3);
    if (EXPANSION_TAGGED_RELEASE)
        string = StringCopy(string, sText_Released);
    else
        string = StringCopy(string, sText_Unreleased);
}

void DebugMenu_CalculateTime(struct ScriptContext *ctx)
{
    if (OW_USE_FAKE_RTC)
    {
        struct SiiRtcInfo *rtc = FakeRtc_GetCurrentTime();
        StringExpandPlaceholders(gStringVar1, gDayNameStringsTable[rtc->dayOfWeek]);
        ConvertIntToDecimalStringN(gStringVar2, rtc->hour, STR_CONV_MODE_LEFT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar3, rtc->minute, STR_CONV_MODE_LEADING_ZEROS, 2);
    }
    else
    {
        u32 day = ((gLocalTime.days - 1) + 6) % 7 ;
        RtcCalcLocalTime();
        StringExpandPlaceholders(gStringVar1, gDayNameStringsTable[day]);
        ConvertIntToDecimalStringN(gStringVar2, gLocalTime.hours, STR_CONV_MODE_LEFT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar3, gLocalTime.minutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    }
}

void DebugMenu_CalculateTimeOfDay(struct ScriptContext *ctx)
{
    enum TimeOfDay timeOfDay = GetTimeOfDay();
    switch (timeOfDay)
    {
    case TIME_MORNING:
    case TIME_DAY:
    case TIME_EVENING:
    case TIME_NIGHT:
        StringExpandPlaceholders(gStringVar1, gTimeOfDayStringsTable[timeOfDay]);
        break;
    case TIMES_OF_DAY_COUNT:
            break;
    }
}

#define tRandomiserType data[8]

#define SPECIES_RANDOMIZER 0
#define ITEM_RANDOMIZER 1

static void DebugAction_Util_Randomizer_RefreshValues(u8 taskId)
{
    const u8 *str;
    u32 x;
    u32 font;
    const struct FilterFuncArgs args = {
        .arg1 = DebugSelection_GetData(taskId, 1),
        .arg2 = DebugSelection_GetData(taskId, 2),
    };

    for (u32 i = 0; i < 27; i++)
    {
        if (gTasks[taskId].tRandomiserType == SPECIES_RANDOMIZER)
        {
            u32 species = GetRandomSpecies(DebugSelection_GetData(taskId, 0), &args);
            str = GetSpeciesName(species);
            x = (i % 3) * 72 + 16;
            font = FONT_NORMAL;
        }
        else
        {
            u32 item = GetRandomItem(DebugSelection_GetData(taskId, 0), &args);
            str = GetItemName(item);
            x = (i % 3) * 80;
            font = FONT_NARROW;
        }
        u32 y = (i / 3) * 16;
        AddTextPrinterParameterized(gTasks[taskId].tSubWindowId, font, str, x, y, 0, NULL);
    }
}

static void DebugAction_Util_Randomizer_Wait(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        FillWindowPixelBuffer(gTasks[taskId].tSubWindowId, PIXEL_FILL(1));
        DebugAction_Util_Randomizer_RefreshValues(taskId);
    }

    if (JOY_NEW(B_BUTTON))
    {
        Debug_RemoveCallbackMenu();
        DebugAction_OpenSubMenu(taskId, sDebugMenu_Actions_Utilities);
    }
}

static void DebugAction_Util_Randomizer_ShowValues(u8 taskId)
{

    ClearStdWindowAndFrame(gTasks[taskId].tWindowId, TRUE);
    RemoveWindow(gTasks[taskId].tWindowId);

    ClearStdWindowAndFrame(gTasks[taskId].tSubWindowId, TRUE);
    RemoveWindow(gTasks[taskId].tSubWindowId);

    gTasks[taskId].tSubWindowId = AddWindow(&sDebugMenuWindowTemplateFullScreen);
    DrawStdWindowFrame(gTasks[taskId].tSubWindowId, FALSE);
    CopyWindowToVram(gTasks[taskId].tSubWindowId, COPYWIN_FULL);

    DebugAction_Util_Randomizer_RefreshValues(taskId);
    gTasks[taskId].func = DebugAction_Util_Randomizer_Wait;
}

static bool32 DebugSelection_SpeciesGenerator_OnComplete(u8 taskId)
{
    gTasks[taskId].tRandomiserType = SPECIES_RANDOMIZER;
    DebugAction_Util_Randomizer_ShowValues(taskId);
    return TRUE;
}

static bool32 DebugSelection_ItemGenerator_OnComplete(u8 taskId)
{
    gTasks[taskId].tRandomiserType = ITEM_RANDOMIZER;
    DebugAction_Util_Randomizer_ShowValues(taskId);
    return TRUE;
}

static void DebugSelectionStep_UpdateGeneratorArgs(u8 taskId, u8 digits, u32 min, u32 max)
{
    ConvertIntToDecimalStringN(gStringVar2, gTasks[taskId].tSubstep + 1, STR_CONV_MODE_LEADING_ZEROS, 1);
    ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, digits);
    StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("Arg {STR_VAR_2}: {STR_VAR_3}"));
    StringCopy(gStringVar2, COMPOUND_STRING(""));
    StringCopy(gStringVar3, COMPOUND_STRING(""));
    DebugNativeStep_PrintWindowSelection(taskId);
}

static void DebugSelectionStep_UpdateGeneratorOption(u8 taskId, u8 digits, u32 min, u32 max)
{
    ConvertIntToDecimalStringN(gStringVar2, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, digits);
    StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("Options ID: {STR_VAR_2}"));
    StringCopy(gStringVar2, COMPOUND_STRING(""));
    StringCopy(gStringVar3, COMPOUND_STRING(""));
    DebugNativeStep_PrintWindowSelection(taskId);
}

static const struct DebugSelectionStep sRandomGeneratorArgsSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateGeneratorArgs,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 0,
    .maxValue = 0xFFFF,
    .digits = 5,
    .substepCount = 2,
};

static const struct DebugSelectionStep sSpeciesGeneratorSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateGeneratorOption,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 0,
    .maxValue = RANDOM_SPECIES_OPTIONS_COUNT - 1,
    .digits = 2,
};

static const struct DebugSelectionStep sItemGeneratorSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateGeneratorOption,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 0,
    .maxValue = RANDOM_ITEM_OPTIONS_COUNT - 1,
    .digits = 2,
};

static const struct DebugSelection sSpeciesGeneratorSelection = {
    .onInit = Debug_CreateInputDisplayWindow,
    .onCancel = DebugSelectionStep_ReturnToUtilMenu,
    .onComplete = DebugSelection_SpeciesGenerator_OnComplete,//DebugSelection_SetWarp_OnComplete,
    .steps = {&sSpeciesGeneratorSelectionStep, &sRandomGeneratorArgsSelectionStep},
    .maxSteps = 2,
};

static const struct DebugSelection sItemGeneratorSelection = {
    .onInit = Debug_CreateInputDisplayWindow,
    .onCancel = DebugSelectionStep_ReturnToUtilMenu,
    .onComplete = DebugSelection_ItemGenerator_OnComplete,//DebugSelection_SetWarp_OnComplete,
    .steps = {&sItemGeneratorSelectionStep, &sRandomGeneratorArgsSelectionStep},
    .maxSteps = 2,
};

#undef tRandomiserType

// *******************************
// Actions Trainers

static void Debug_Trainers_ResetTrainersData(void)
{
    sDebugMenuListData->data[0] = TRAINER_NONE;
    sDebugMenuListData->data[1] = -1;
    sDebugMenuListData->data[2] = TRAINER_NONE;
    sDebugMenuListData->data[3] = -1;
    sDebugMenuListData->data[4] = PARTNER_NONE;
    sDebugMenuListData->data[5] = FALSE;
}

void SetMultiTrainerBattle(struct ScriptContext *ctx);

static void ParseObjectEventScript(const u8 *script)
{
    struct ScriptContext *ctx = AllocZeroed(sizeof(struct ScriptContext));
    if (script[0] == SCR_OP_TRAINERBATTLE)
    {
        TrainerBattleLoadArgs(script + 1);
    }
    else if (Script_MatchesCallNative(script, NativeVsSeekerRematchId, TRUE))
    {
        ctx->scriptPtr = script + 5;
        sDebugMenuListData->data[0] = ScriptPeekHalfword(ctx);
    }
    else if (Script_MatchesSpecial(script, SavePlayerParty) && Script_MatchesCallNative(script + 3, SetMultiTrainerBattle, FALSE))
    {
        ctx->scriptPtr = script + 8;
        SetMultiTrainerBattle(ctx);
    }
    Free(ctx);
    if (!TRAINER_BATTLE_PARAM.opponentA && !TRAINER_BATTLE_PARAM.opponentB)
        return;
    sDebugMenuListData->data[0] = TRAINER_BATTLE_PARAM.opponentA;
    sDebugMenuListData->data[2] = TRAINER_BATTLE_PARAM.opponentB;
    if (gPartnerTrainerId)
        sDebugMenuListData->data[4] = gPartnerTrainerId - MAX_TRAINERS_COUNT;
    InitTrainerBattleParameter();
    gPartnerTrainerId = 0;
}

static u32 GetTrainerIdFromLocalId(u32 localId)
{
    Debug_Trainers_ResetTrainersData();
    ParseObjectEventScript(gMapHeader.events->objectEvents[localId - 1].script);
    if (GetTrainerBattleType(sDebugMenuListData->data[0]) == TRAINER_BATTLE_TYPE_DOUBLES)
        sDebugMenuListData->data[5] = TRUE;
    return sDebugMenuListData->data[0];
}

static void Debug_CreateTrainerIcon(u8 taskId)
{
    DestroyDebugIcon(taskId);
    u32 graphicsId = gMapHeader.events->objectEvents[gTasks[taskId].tInput - 1].graphicsId;
    gTasks[taskId].tSpriteId = CreateObjectGraphicsSpriteWithTag(graphicsId, SpriteCallbackDummy, DEBUG_NUMBER_ICON_X, DEBUG_NUMBER_ICON_Y, 4, DEBUG_ICON_TAG);
    StartSpriteAnim(&gSprites[gTasks[taskId].tSpriteId], ANIM_STD_GO_SOUTH);
    gSprites[gTasks[taskId].tSpriteId].oam.priority = 0;
    gSprites[gTasks[taskId].tSpriteId].oam.paletteNum =  LoadObjectEventPaletteCopy(gSprites[gTasks[taskId].tSpriteId].template->paletteTag, DEBUG_ICON_TAG);
}

static void DebugSelectionStep_UpdateMapTrainer(u8 taskId, u8 digits, u32 min, u32 max)
{
    while (GetTrainerIdFromLocalId(gTasks[taskId].tInput) == TRAINER_NONE && gTasks[taskId].tInput >= min && gTasks[taskId].tInput <= max)
    {
        if (JOY_NEW(DPAD_DOWN))
            gTasks[taskId].tInput--;
        else
            gTasks[taskId].tInput++;
    }
    if (gTasks[taskId].tInput < min || gTasks[taskId].tInput > max)
    {
        gTasks[taskId].tInput = DebugSelection_GetData(taskId, 0);
        GetTrainerIdFromLocalId(gTasks[taskId].tInput);
    }

    u32 trainerId = sDebugMenuListData->data[0];
    if (trainerId)
        DebugSelection_SetData(taskId, 0, gTasks[taskId].tInput);
    Debug_CreateTrainerIcon(taskId);
    ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, digits);
    StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("Local ID: {STR_VAR_3}"));
    u8 *end;
    if (trainerId == TRAINER_NONE)
        end = StringCopy(gStringVar2, COMPOUND_STRING("Not a Trainer"));
    else
        end = StringCopy(gStringVar2, GetTrainerNameFromId(trainerId));
    WrapFontIdToFit(gStringVar2, end, DEBUG_MENU_FONT, WindowWidthPx(gTasks[taskId].tSubWindowId));
    StringCopy(gStringVar3, COMPOUND_STRING(""));
    DebugNativeStep_PrintWindowSelection(taskId);
}

static u32 DebugSelectionStep_GetObjectEventCount(u8 taskId)
{
    return gMapHeader.events->objectEventCount;
}

static void DebugSelection_SetTrainerFromMap_OnCancel(u8 taskId)
{
    sDebugMenuListData->data[1] = FirstBattleTrainerIdToRematchTableId(gRematchTable, sDebugMenuListData->data[0]);
    sDebugMenuListData->data[3] = TRUE;
    DebugSelectionStep_ReturnToTrainersMenu(taskId);
}

static bool32 DebugSelection_SetTrainerFromMap_OnComplete(u8 taskId)
{
    DebugSelection_SetTrainerFromMap_OnCancel(taskId);
    return TRUE;
}

static const struct DebugSelectionStep sMapTrainerSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateMapTrainer,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 1,
    .maxFunc = DebugSelectionStep_GetObjectEventCount,
    .digits = 3,
    .useMaxFunc = TRUE,
};

static const struct DebugSelection sTrainerFromMapSelection = {
    .onInit = Debug_CreateInputDisplayWindow,
    .onCancel = DebugSelection_SetTrainerFromMap_OnCancel,
    .onComplete = DebugSelection_SetTrainerFromMap_OnComplete,
    .steps = {&sMapTrainerSelectionStep},
    .maxSteps = 1,
};

static void DebugSelectionStep_PrepareTrainerDisplay(u8 taskId, u8 digits, u32 trainerId)
{
    ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, digits);
    StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("ID: {STR_VAR_3}"));
    u8 *end;
    if (gTasks[taskId].tInput == TRAINER_NONE )
        end = StringCopy(gStringVar2, COMPOUND_STRING("None"));
    else
        end = StringCopy(gStringVar2, GetTrainerNameFromId(trainerId));
    WrapFontIdToFit(gStringVar2, end, DEBUG_MENU_FONT, WindowWidthPx(gTasks[taskId].tSubWindowId));
    StringCopy(gStringVar3, COMPOUND_STRING(""));
}

static void DebugSelectionStep_UpdateTrainer(u8 taskId, u8 digits, u32 min, u32 max)
{
    DebugSelectionStep_PrepareTrainerDisplay(taskId, digits, gTasks[taskId].tInput);
    DebugNativeStep_PrintWindowSelection(taskId);
}

static void DebugSelectionStep_UpdatePartner(u8 taskId, u8 digits, u32 min, u32 max)
{
    DebugSelectionStep_PrepareTrainerDisplay(taskId, digits, TRAINER_PARTNER(gTasks[taskId].tInput));
    DebugNativeStep_PrintWindowSelection(taskId);
}

static const struct DebugSelectionStep sTrainerSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateTrainer,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 0,
    .maxValue = TRAINERS_COUNT - 1,
    .digits = 3,
};

static const struct DebugSelectionStep sPartnerSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdatePartner,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 0,
    .maxValue = PARTNER_COUNT - 1,
    .digits = 2,
};

// TRAINER_SINGLE_SELECTION creates selection functions that matches trainer battle
// position (opponent1, opponent 2 or partner) to the index where their trainer id
// is stored in the trainer menu data
#define TRAINER_SINGLE_SELECTION(label1, dataIndex)                                 \
static void DebugSelection_ ## label1 ## _Init(u8 taskId) {                         \
    Debug_CreateInputDisplayWindow(taskId);                                         \
    DebugSelection_SetData(taskId, 0, sDebugMenuListData->data[dataIndex]);         \
};                                                                                  \
static bool32 DebugSelection_ ## label1 ## _Complete(u8 taskId) {                   \
    if (DebugSelection_GetData(taskId, 0) != sDebugMenuListData->data[dataIndex])   \
    {                                                                               \
        sDebugMenuListData->data[dataIndex] = DebugSelection_GetData(taskId, 0);    \
        sDebugMenuListData->data[3] = FALSE;                                        \
        sDebugMenuListData->data[1] = -1;                                           \
    }                                                                               \
    DebugSelectionStep_ReturnToTrainersMenu(taskId);                                \
    return TRUE;                                                                    \
};                                                                                  \

TRAINER_SINGLE_SELECTION(Trainer1, 0)
TRAINER_SINGLE_SELECTION(Trainer2, 2)
TRAINER_SINGLE_SELECTION(Partner,  4)

static const struct DebugSelection sTrainer1Selection = {
    .onInit = DebugSelection_Trainer1_Init,
    .onCancel = DebugSelectionStep_ReturnToTrainersMenu,
    .onComplete = DebugSelection_Trainer1_Complete,
    .steps = {&sTrainerSelectionStep},
    .maxSteps = 1,
};

static const struct DebugSelection sTrainer2Selection = {
    .onInit = DebugSelection_Trainer2_Init,
    .onCancel = DebugSelectionStep_ReturnToTrainersMenu,
    .onComplete = DebugSelection_Trainer2_Complete,
    .steps = {&sTrainerSelectionStep},
    .maxSteps = 1,
};

static const struct DebugSelection sPartnerSelection = {
    .onInit = DebugSelection_Partner_Init,
    .onCancel = DebugSelectionStep_ReturnToTrainersMenu,
    .onComplete = DebugSelection_Partner_Complete,
    .steps = {&sPartnerSelectionStep},
    .maxSteps = 1,
};

static void DebugAction_Trainers_SwitchDoublesFlag(u8 taskId)
{
    if (sDebugMenuListData->data[2] != TRAINER_NONE || sDebugMenuListData->data[4] != PARTNER_NONE)
        return;
    if (sDebugMenuListData->data[5])
        sDebugMenuListData->data[5] = FALSE;
    else
        sDebugMenuListData->data[5] = TRUE;
}

static void DebugAction_Trainers_SetRematch(u8 taskId)
{
    s32 rematchId = sDebugMenuListData->data[1];

    if (rematchId == -1)
    {
        FlagToggle(TRAINER_FLAGS_START + sDebugMenuListData->data[0]);
        return;
    }

    for (u32 i = 0; i < REMATCHES_COUNT; i++)
    {
        if (gRematchTable[rematchId].trainerIds[i] == 0)
            break;

        if (!HasTrainerBeenFought(gRematchTable[rematchId].trainerIds[i]))
        {
            FlagToggle(TRAINER_FLAGS_START + gRematchTable[rematchId].trainerIds[i]);
            return;
        }
    }

    for (u32 i = 0; i < REMATCHES_COUNT; i++)
    {
        if (gRematchTable[rematchId].trainerIds[i] == 0)
            break;

        FlagToggle(TRAINER_FLAGS_START + gRematchTable[rematchId].trainerIds[i]);
    }
}

static void DebugAction_Trainers_SetRematchReadiness(u8 taskId)
{
    if (sDebugMenuListData->data[1] == -1)
        return;
    if (GetActiveTrainerRematches(sDebugMenuListData->data[1]))
        SetActiveTrainerRematches(sDebugMenuListData->data[1], FALSE);
    else
        SetActiveTrainerRematches(sDebugMenuListData->data[1], TRUE);
}

static void DebugAction_Trainers_TryBattle(u8 taskId)
{
    s32 trainer1Id = sDebugMenuListData->data[0];
    s32 trainer2Id = sDebugMenuListData->data[2];
    s32 partnerId = sDebugMenuListData->data[4];
    s32 rematchId = sDebugMenuListData->data[1];
    if (sDebugMenuListData->data[1] != -1)
    {
        s32 lastMatch = CountBattledRematchTeams(rematchId);
        if (lastMatch == REMATCHES_COUNT || gRematchTable[rematchId].trainerIds[lastMatch] == 0)
            lastMatch -= 1;
        trainer1Id = gRematchTable[rematchId].trainerIds[lastMatch];
    }
    gBattleTypeFlags = BATTLE_TYPE_TRAINER;
    TRAINER_BATTLE_PARAM.opponentA = trainer1Id;
    TRAINER_BATTLE_PARAM.opponentB = 0xFFFF;
    CreateNPCTrainerPartyFromTrainer(gParties[B_TRAINER_OPPONENT_A], GetTrainerStructFromId(trainer1Id));
    if (sDebugMenuListData->data[5] || partnerId != PARTNER_NONE || trainer2Id != TRAINER_NONE)
        gBattleTypeFlags |= BATTLE_TYPE_DOUBLE;
    if (trainer2Id != TRAINER_NONE)
    {
        TRAINER_BATTLE_PARAM.opponentB = trainer2Id;
        CreateNPCTrainerPartyFromTrainer(gParties[B_TRAINER_OPPONENT_B], GetTrainerStructFromId(trainer2Id));
        gBattleTypeFlags |= BATTLE_TYPE_TWO_OPPONENTS;
    }
    if (partnerId != PARTNER_NONE)
    {
        SavePlayerParty();
        gPartnerTrainerId = TRAINER_PARTNER(partnerId);
        gBattleTypeFlags |= BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER;
        for (u32 i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
        {
            gSelectedOrderFromParty[i] = i + 1;
            gSaveBlock2Ptr->frontier.selectedPartyMons[i] = gSelectedOrderFromParty[i];
        }
        FillPartnerParty(gPartnerTrainerId);
    }

    gBattleEnvironment = BattleSetup_GetEnvironmentId();
    CalculateEnemyPartyCount();
    BattleSetup_StartTrainerBattle_Debug();
    Debug_DestroyMenu_Full(taskId);
}

static void DebugAction_Trainers_RechargeVsSeeker(u8 taskId)
{
    SetTrainerRematchStepCounter(VSSEEKER_RECHARGE_STEPS);
    MapResetTrainerRematches(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum);
    ScriptContext_SetupScript(EventScript_VsSeekerChargingDone);
    Debug_DestroyMenu_Full(taskId);
}

// *******************************
// Actions Encounters - Mass Outbreak

static void DebugAction_Outbreak_ClearActive(u8 taskId)
{
    gSaveBlock1Ptr->outbreakDaysLeft = 0;
    Debug_RemoveCallbackMenu();
    DebugAction_OpenOutbreakMenu(taskId, sDebugMenu_Actions_MassOutbreak);
}

static void DebugSelectionStep_PrintGenericInput(u8 taskId, u8 digits, const u8 *str)
{
    StringCopy(gStringVar1, str);
    ConvertIntToDecimalStringN(gStringVar2, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, digits);
    StringCopy(gStringVar3, COMPOUND_STRING(""));
    DebugNativeStep_PrintWindowSelection(taskId);
}

static void DebugSelectionStep_PrintGenericBooleanInput(u8 taskId, const u8 *str)
{
    StringCopy(gStringVar1, str);
    if (gTasks[taskId].tInput == 0)
        StringCopy(gStringVar2, COMPOUND_STRING("FALSE"));
    else
        StringCopy(gStringVar2, COMPOUND_STRING("TRUE"));
    StringCopy(gStringVar3, COMPOUND_STRING(""));
    DebugNativeStep_PrintWindowSelection(taskId);
}

// UPDATE_GENERIC_INPUT is a macro to create a selection function that only update the selected
// value without doing anything special
#define UPDATE_GENERIC_INPUT(label, title)                                                  \
static void DebugSelectionStep_Update ## label(u8 taskId, u8 digits, u32 min, u32 max) {    \
    DebugSelectionStep_PrintGenericInput(taskId, digits, COMPOUND_STRING("" #title ":")); };

static void DebugSelectionStep_UpdateSpecies(u8 taskId, u8 digits, u32 min, u32 max)
{
    u32 species = gTasks[taskId].tInput;
    while (!IsSpeciesEnabled(species))
    {
        if (JOY_NEW(DPAD_DOWN))
            species--;
        else
            species++;
    }
    gTasks[taskId].tInput = species;
    ConvertIntToDecimalStringN(gStringVar3, species, STR_CONV_MODE_LEADING_ZEROS, digits);
    StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("Species: {STR_VAR_3}"));
    u8 *end = StringCopy(gStringVar2, GetSpeciesName(species));
    WrapFontIdToFit(gStringVar2, end, DEBUG_MENU_FONT, WindowWidthPx(gTasks[taskId].tSubWindowId));
    StringCopy(gStringVar3, COMPOUND_STRING(""));
    Debug_ResetInputDisplayMonIcon(taskId, species);
    DebugNativeStep_PrintWindowSelection(taskId);
}

static void DebugSelectionStep_UpdateMoves(u8 taskId, u8 digits, u32 min, u32 max)
{
    u32 moveId = gTasks[taskId].tInput;
    ConvertIntToDecimalStringN(gStringVar2, gTasks[taskId].tSubstep + 1, STR_CONV_MODE_LEADING_ZEROS, 1);
    ConvertIntToDecimalStringN(gStringVar3, moveId, STR_CONV_MODE_LEADING_ZEROS, digits);
    StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("Move {STR_VAR_2}: {STR_VAR_3}"));
    u8 *end;
    if (moveId == MOVES_COUNT)
        end = StringCopy(gStringVar2, COMPOUND_STRING("Default"));
    else
        end = StringCopy(gStringVar2, GetMoveName(moveId));
    WrapFontIdToFit(gStringVar2, end, DEBUG_MENU_FONT, WindowWidthPx(gTasks[taskId].tSubWindowId));
    StringCopy(gStringVar3, COMPOUND_STRING(""));
    DebugNativeStep_PrintWindowSelection(taskId);
}

static void DebugSelectionStep_MovesConfirm(u8 taskId)
{
    u32 moveId = gTasks[taskId].tInput;
    if (moveId != MOVE_NONE && moveId != MOVES_COUNT)
    {
        DebugSelection_SetData(taskId, gTasks[taskId].tStepsDataIndex, moveId);
        return;
    }
    while (++gTasks[taskId].tSubstep < MAX_MON_MOVES)
    {
        DebugSelection_SetData(taskId, ++gTasks[taskId].tStepsDataIndex, moveId);
    }
}

UPDATE_GENERIC_INPUT(Level, Level)
UPDATE_GENERIC_INPUT(OutbreakProbability, Probability)
UPDATE_GENERIC_INPUT(OutbreakDaysLeft, Days Left)

static const struct DebugSelectionStep sSpeciesSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateSpecies,
    .stepConfirm = DebugSelectionStep_GenericInputConfirmAndDestroyIcon,
    .minValue = 1,
    .maxValue = NUM_SPECIES - 1,
    .digits = 4
};

static const struct DebugSelectionStep sLevelSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateLevel,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = MIN_LEVEL,
    .maxValue = MAX_LEVEL,
    .digits = 3
};

static const struct DebugSelectionStep sMovesSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateMoves,
    .stepConfirm = DebugSelectionStep_MovesConfirm,
    .minValue = MOVE_NONE,
    .maxValue = MOVES_COUNT,
    .digits = 3,
    .substepCount = 4,
};

static const struct DebugSelectionStep sOutbreakProbabilitySelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateOutbreakProbability,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 1,
    .maxValue = 100,
    .digits = 3
};

static const struct DebugSelectionStep sOutbreakDaysLeftSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateOutbreakDaysLeft,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 1,
    .maxValue = 999,
    .digits = 3
};

// MASS_OUTRBREAK_SINGLE_COMPLETION creates selection functions that
// modify the data of the currentlyactive outbreak
#define MASS_OUTRBREAK_SINGLE_COMPLETION(label1, label2, saveField)                 \
static void DebugSelection_SetMassOutbreak ## label1 ## _Init(u8 taskId) {          \
    Debug_CreateInputDisplayWindow(taskId);                                         \
    DebugSelection_SetData(taskId, 0, gSaveBlock1Ptr->saveField);                   \
};                                                                                  \
static bool32 DebugSelection_SetMassOutbreak ## label1 ## _Complete(u8 taskId) {    \
    gSaveBlock1Ptr->saveField = DebugSelection_GetData(taskId, 0);                  \
    DebugSelectionStep_ReturnToOutbreakMenu(taskId);                                \
    return TRUE;                                                                    \
};                                                                                  \
static const struct DebugSelection sMassOutbreak ## label1 ## Selection = {         \
    .onInit = DebugSelection_SetMassOutbreak ## label1 ## _Init,                    \
    .onCancel = DebugSelectionStep_ReturnToOutbreakMenu,                            \
    .onComplete = DebugSelection_SetMassOutbreak ## label1 ## _Complete,            \
    .steps = {&s ## label2 ##SelectionStep},                                        \
    .maxSteps = 1,                                                                  \
};

MASS_OUTRBREAK_SINGLE_COMPLETION(Species,     Species,             outbreakPokemonSpecies);
MASS_OUTRBREAK_SINGLE_COMPLETION(Level,       Level,               outbreakPokemonLevel);
MASS_OUTRBREAK_SINGLE_COMPLETION(Probability, OutbreakProbability, outbreakPokemonProbability);
MASS_OUTRBREAK_SINGLE_COMPLETION(DaysLeft,    OutbreakDaysLeft,    outbreakDaysLeft);

static void DebugSelection_SetMassOutbreakLocation_Init(u8 taskId) {
    Debug_CreateInputDisplayWindow(taskId);
    DebugSelection_SetData(taskId, 0, gSaveBlock1Ptr->outbreakLocationMapGroup);
    DebugSelection_SetData(taskId, 1, gSaveBlock1Ptr->outbreakLocationMapNum);
};

static bool32 DebugSelection_SetMassOutbreakLocation_Complete(u8 taskId) {
    gSaveBlock1Ptr->outbreakLocationMapGroup = DebugSelection_GetData(taskId, 0);
    gSaveBlock1Ptr->outbreakLocationMapNum = DebugSelection_GetData(taskId, 1);
    DebugSelectionStep_ReturnToOutbreakMenu(taskId);
    return TRUE;
};

static const struct DebugSelection sMassOutbreakLocationSelection = {
    .onInit = DebugSelection_SetMassOutbreakLocation_Init,
    .onCancel = DebugSelectionStep_ReturnToOutbreakMenu,
    .onComplete = DebugSelection_SetMassOutbreakLocation_Complete,
    .steps = {&sMapGroupSelectionStep, &sMapNumSelectionStep},
    .maxSteps = 2,
};

static void DebugSelection_SetMassOutbreakMoves_Init(u8 taskId) {
    Debug_CreateInputDisplayWindow(taskId);
    for (u32 i = 0; i < MAX_MON_MOVES; i++)
        DebugSelection_SetData(taskId, i, gSaveBlock1Ptr->outbreakPokemonMoves[i]);
};

static bool32 DebugSelection_SetMassOutbreakMoves_Complete(u8 taskId) {
    for (u32 i = 0; i < MAX_MON_MOVES; i++)
    {
        u16 moveId = DebugSelection_GetData(taskId, i);
        if (moveId < MOVES_COUNT)
            gSaveBlock1Ptr->outbreakPokemonMoves[i] = moveId;
        else
            gSaveBlock1Ptr->outbreakPokemonMoves[i] = MOVE_NONE;
    }
    DebugSelectionStep_ReturnToOutbreakMenu(taskId);
    return TRUE;
};

static const struct DebugSelection sMassOutbreakMovesSelection = {
    .onInit = DebugSelection_SetMassOutbreakMoves_Init,
    .onCancel = DebugSelectionStep_ReturnToOutbreakMenu,
    .onComplete = DebugSelection_SetMassOutbreakMoves_Complete,
    .steps = {&sMovesSelectionStep},
    .maxSteps = 1,
};

static void DebugSelection_SetDynamicMassOutbreak_Init(u8 taskId)
{
    Debug_CreateInputDisplayWindow(taskId);
    DebugSelection_SetData(taskId, 0, gSaveBlock1Ptr->outbreakPokemonSpecies);
    DebugSelection_SetData(taskId, 1, gSaveBlock1Ptr->outbreakLocationMapGroup);
    DebugSelection_SetData(taskId, 2, gSaveBlock1Ptr->outbreakLocationMapNum);
    DebugSelection_SetData(taskId, 3, gSaveBlock1Ptr->outbreakPokemonLevel);
    for (u32 j = 0; j < MAX_MON_MOVES; j++)
        DebugSelection_SetData(taskId, 4 + j, gSaveBlock1Ptr->outbreakPokemonMoves[j]);
    DebugSelection_SetData(taskId, 8, gSaveBlock1Ptr->outbreakPokemonProbability);
    DebugSelection_SetData(taskId, 9, gSaveBlock1Ptr->outbreakDaysLeft);
}

static bool32 DebugSelection_SetDynamicMassOutbreak_Complete(u8 taskId)
{
    gSaveBlock1Ptr->outbreakPokemonSpecies = DebugSelection_GetData(taskId, 0);
    gSaveBlock1Ptr->outbreakLocationMapGroup = DebugSelection_GetData(taskId, 1);
    gSaveBlock1Ptr->outbreakLocationMapNum = DebugSelection_GetData(taskId, 2);
    gSaveBlock1Ptr->outbreakPokemonLevel = DebugSelection_GetData(taskId, 3);
    for (u32 j = 0; j < MAX_MON_MOVES; j++)
        gSaveBlock1Ptr->outbreakPokemonMoves[j] = DebugSelection_GetData(taskId, 4 + j);
    gSaveBlock1Ptr->outbreakPokemonProbability = DebugSelection_GetData(taskId, 8);
    gSaveBlock1Ptr->outbreakDaysLeft = DebugSelection_GetData(taskId, 9);
    DebugSelectionStep_ReturnToOutbreakMenu(taskId);
    return TRUE;
}

static const struct DebugSelection sDynamicMassOutbreakSelection = {
    .onInit = DebugSelection_SetDynamicMassOutbreak_Init,
    .onCancel = DebugSelectionStep_ReturnToOutbreakMenu,
    .onComplete = DebugSelection_SetDynamicMassOutbreak_Complete,
    .steps = {
        &sSpeciesSelectionStep,
        &sMapGroupSelectionStep,
        &sMapNumSelectionStep,
        &sLevelSelectionStep,
        &sMovesSelectionStep,
        &sOutbreakProbabilitySelectionStep,
        &sOutbreakDaysLeftSelectionStep,
    },
    .maxSteps = 7,
};

static void DebugSelectionStep_UpdateStaticOutbreak(u8 taskId, u8 digits, u32 min, u32 max)
{
    ConvertIntToDecimalStringN(gStringVar2, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, digits);
    StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("ID: {STR_VAR_2}"));
    GetStaticOutbreakMapName(gStringVar2, gTasks[taskId].tInput);
    StringCopy(gStringVar3, COMPOUND_STRING(""));
    Debug_ResetInputDisplayMonIcon(taskId, GetStaticOutbreakSpecies(gTasks[taskId].tInput));
    DebugNativeStep_PrintWindowSelection(taskId);
}

static const struct DebugSelectionStep sStaticOutbreakSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateStaticOutbreak,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 0,
    .maxValue = OUTBREAK_COUNT - 1,
    .digits = 2
};

static bool32 DebugSelection_SetStaticMassOutbreak_Complete(u8 taskId)
{
    StartStaticMassOutbreak(DebugSelection_GetData(taskId, 0));
    DebugSelectionStep_ReturnToOutbreakMenu(taskId);
    return TRUE;
};

static const struct DebugSelection sStaticMassOutbreakSelection = {
    .onInit = Debug_CreateInputDisplayWindow,
    .onCancel = DebugSelectionStep_ReturnToOutbreakMenu,
    .onComplete = DebugSelection_SetStaticMassOutbreak_Complete,
    .steps = {&sStaticOutbreakSelectionStep},
    .maxSteps = 1,
};

// *******************************
// Actions Flags and Vars

static void DebugSelectionStep_UpdateFlag(u8 taskId, u8 digits, u32 min, u32 max)
{
    u32 flag = gTasks[taskId].tInput;
    ConvertIntToDecimalStringN(gStringVar1, flag, STR_CONV_MODE_LEADING_ZEROS, digits);
    ConvertIntToHexStringN(gStringVar3, flag, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar2, COMPOUND_STRING("0x{STR_VAR_3}"));
    if (FlagGet(flag))
        StringCopy(gStringVar3, sDebugText_True);
    else
        StringCopy(gStringVar3, sDebugText_False);
    DebugNativeStep_PrintWindowSelection(taskId);
}

static bool32 DebugSelection_ToggleFlag_Complete(u8 taskId)
{
    FlagToggle(gTasks[taskId].tInput);
    gTasks[taskId].tStep = 0;
    gTasks[taskId].tStepsDataIndex = 0;
    return FALSE;
}

static const struct DebugSelectionStep sFlagSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateFlag,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = FLAG_TEMP_1,
    .maxValue = FLAGS_COUNT - 1,
    .digits = 4
};

static const struct DebugSelection sToggleFlagSelection = {
    .onInit = Debug_CreateInputDisplayWindow,
    .onCancel = DebugSelectionStep_ReturnToFlagsVarsMenu,
    .onComplete = DebugSelection_ToggleFlag_Complete,
    .steps = {&sFlagSelectionStep},
    .maxSteps = 1,
};

static void DebugSelectionStep_PrepareVarDisplay(u32 varId)
{
    u8 *end;
    end = StringCopy(gStringVar1, COMPOUND_STRING("Var: 0x"));
    ConvertIntToHexStringN(end, varId, STR_CONV_MODE_LEFT_ALIGN, 4);
    end = StringCopy(gStringVar2, COMPOUND_STRING("Val: "));
    ConvertIntToDecimalStringN(end, VarGet(varId), STR_CONV_MODE_LEADING_ZEROS, 5);
}

static void DebugSelectionStep_UpdateVarId(u8 taskId, u8 digits, u32 min, u32 max)
{
    DebugSelectionStep_PrepareVarDisplay(gTasks[taskId].tInput);
    StringCopy(gStringVar3, COMPOUND_STRING(""));
    DebugNativeStep_PrintWindowSelection(taskId);
    DebugSelection_SetData(taskId, gTasks[taskId].tStep + 1, VarGet(gTasks[taskId].tInput));
}

static void DebugSelectionStep_UpdateVarValue(u8 taskId, u8 digits, u32 min, u32 max)
{
    u8 *end;
    DebugSelectionStep_PrepareVarDisplay(DebugSelection_GetData(taskId, gTasks[taskId].tStep - 1));
    end = StringCopy(gStringVar3, COMPOUND_STRING("New: "));
    ConvertIntToDecimalStringN(end, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, 5);
    DebugNativeStep_PrintWindowSelection(taskId);
}

static bool32 DebugSelection_SetVar_Complete(u8 taskId)
{
    u32 varId = DebugSelection_GetData(taskId, 0);
    u32 varValue = DebugSelection_GetData(taskId, 1);
    VarSet(varId, varValue);
    gTasks[taskId].tStep = 0;
    gTasks[taskId].tStepsDataIndex = 0;
    return FALSE;
}

static const struct DebugSelectionStep sVarIdSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateVarId,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = VARS_START,
    .maxValue = VARS_END,
    .digits = 4
};

static const struct DebugSelectionStep sVarValueSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateVarValue,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 0,
    .maxValue = 0xFFFF,
    .digits = 5
};

static const struct DebugSelection sSetVarSelection = {
    .onInit = Debug_CreateInputDisplayWindow,
    .onCancel = DebugSelectionStep_ReturnToFlagsVarsMenu,
    .onComplete = DebugSelection_SetVar_Complete,
    .steps = {&sVarIdSelectionStep, &sVarValueSelectionStep},
    .maxSteps = 2,
};

static void DebugAction_FlagsVars_PokedexFlags_All(u8 taskId)
{
    u16 i;
    for (i = 0; i < NATIONAL_DEX_COUNT; i++)
    {
        GetSetPokedexFlag(i + 1, FLAG_SET_CAUGHT);
        GetSetPokedexFlag(i + 1, FLAG_SET_SEEN);
    }
    Debug_DestroyMenu_Full(taskId);
    ScriptContext_Enable();
}

static void DebugAction_FlagsVars_PokedexFlags_Reset(u8 taskId)
{
    int boxId, boxPosition, partyId;
    enum Species species;

    // Reset Pokedex to emtpy
    memset(&gSaveBlock1Ptr->dexCaught, 0, sizeof(gSaveBlock1Ptr->dexCaught));
    memset(&gSaveBlock1Ptr->dexSeen, 0, sizeof(gSaveBlock1Ptr->dexSeen));

    // Add party Pokemon to Pokedex
    for (partyId = 0; partyId < PARTY_SIZE; partyId++)
    {
        if (GetMonData(&gParties[B_TRAINER_PLAYER][partyId], MON_DATA_SANITY_HAS_SPECIES))
        {
            species = GetMonData(&gParties[B_TRAINER_PLAYER][partyId], MON_DATA_SPECIES);
            GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_SET_CAUGHT);
            GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_SET_SEEN);
        }
    }

    // Add box Pokemon to Pokedex
    for (boxId = 0; boxId < TOTAL_BOXES_COUNT; boxId++)
    {
        for (boxPosition = 0; boxPosition < IN_BOX_COUNT; boxPosition++)
        {
            if (GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_SANITY_HAS_SPECIES))
            {
                species = GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_SPECIES);
                GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_SET_CAUGHT);
                GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_SET_SEEN);
            }
        }
    }
    Debug_DestroyMenu_Full(taskId);
    ScriptContext_Enable();
}

static void DebugAction_FlagsVars_SwitchDex(u8 taskId)
{
    if (FlagGet(FLAG_SYS_POKEDEX_GET))
        PlaySE(SE_PC_OFF);
    else
        PlaySE(SE_PC_LOGIN);
    FlagToggle(FLAG_SYS_POKEDEX_GET);
}

static void DebugAction_FlagsVars_SwitchNatDex(u8 taskId)
{
    if (IsNationalPokedexEnabled())
    {
        DisableNationalPokedex();
        PlaySE(SE_PC_OFF);
    }
    else
    {
        EnableNationalPokedex();
        PlaySE(SE_PC_LOGIN);
    }
}

static void DebugAction_FlagsVars_SwitchPokeNav(u8 taskId)
{
    if (FlagGet(FLAG_SYS_POKENAV_GET))
        PlaySE(SE_PC_OFF);
    else
        PlaySE(SE_PC_LOGIN);
    FlagToggle(FLAG_SYS_POKENAV_GET);
}

static void DebugAction_FlagsVars_SwitchMatchCall(u8 taskId)
{
    if (FlagGet(FLAG_ADDED_MATCH_CALL_TO_POKENAV))
    {
        PlaySE(SE_PC_OFF);
        FlagClear(FLAG_ADDED_MATCH_CALL_TO_POKENAV);
        FlagClear(FLAG_HAS_MATCH_CALL);
    }
    else
    {
        PlaySE(SE_PC_LOGIN);
        FlagSet(FLAG_ADDED_MATCH_CALL_TO_POKENAV);
        FlagSet(FLAG_HAS_MATCH_CALL);
    }
}

static void DebugAction_FlagsVars_RunningShoes(u8 taskId)
{
    if (FlagGet(FLAG_SYS_B_DASH))
        PlaySE(SE_PC_OFF);
    else
        PlaySE(SE_PC_LOGIN);
    FlagToggle(FLAG_SYS_B_DASH);
}

static void DebugAction_FlagsVars_ToggleFlyFlags(u8 taskId)
{
    u32 checkedFlag = sLocationFlags[0] == 0 ? sLocationFlags[ARRAY_COUNT(sLocationFlags) - 1] : sLocationFlags[0];
    if (FlagGet(checkedFlag))
    {
        PlaySE(SE_PC_OFF);
        for (u32 i = 0; i < ARRAY_COUNT(sLocationFlags); i++)
            FlagClear(sLocationFlags[i]);
    }
    else
    {
        PlaySE(SE_PC_LOGIN);
        for (u32 i = 0; i < ARRAY_COUNT(sLocationFlags); i++)
            FlagSet(sLocationFlags[i]);
    }
}

static void DebugAction_FlagsVars_ToggleBadgeFlags(u8 taskId)
{
    if (FlagGet(gBadgeFlags[ARRAY_COUNT(gBadgeFlags) - 1]))
    {
        PlaySE(SE_PC_OFF);
        for (u32 i = 0; i < ARRAY_COUNT(gBadgeFlags); i++)
            FlagClear(gBadgeFlags[i]);
    }
    else
    {
        PlaySE(SE_PC_LOGIN);
        for (u32 i = 0; i < ARRAY_COUNT(gBadgeFlags); i++)
            FlagSet(gBadgeFlags[i]);
    }
}

static void DebugAction_FlagsVars_ToggleGameClear(u8 taskId)
{
    // Sound effect
    if (FlagGet(FLAG_SYS_GAME_CLEAR))
        PlaySE(SE_PC_OFF);
    else
        PlaySE(SE_PC_LOGIN);
    FlagToggle(FLAG_SYS_GAME_CLEAR);
}

static void DebugAction_FlagsVars_ToggleFrontierPass(u8 taskId)
{
    // Sound effect
    if (FlagGet(FLAG_SYS_FRONTIER_PASS))
        PlaySE(SE_PC_OFF);
    else
        PlaySE(SE_PC_LOGIN);
    FlagToggle(FLAG_SYS_FRONTIER_PASS);
}

static void DebugAction_FlagsVars_CollisionOnOff(u8 taskId)
{
#if OW_FLAG_NO_COLLISION == 0
    Debug_DestroyMenu_Full_Script(taskId, Debug_FlagsNotSetOverworldConfigMessage);
#else
    if (FlagGet(OW_FLAG_NO_COLLISION))
        PlaySE(SE_PC_OFF);
    else
        PlaySE(SE_PC_LOGIN);
    FlagToggle(OW_FLAG_NO_COLLISION);
#endif
}

static void DebugAction_FlagsVars_EncounterOnOff(u8 taskId)
{
#if WE_FLAG_NO_ENCOUNTER == 0
    Debug_DestroyMenu_Full_Script(taskId, Debug_FlagsNotSetOverworldConfigMessage);
#else
    if (FlagGet(WE_FLAG_NO_ENCOUNTER))
        PlaySE(SE_PC_OFF);
    else
        PlaySE(SE_PC_LOGIN);
    FlagToggle(WE_FLAG_NO_ENCOUNTER);
#endif
}

static void DebugAction_FlagsVars_TrainerSeeOnOff(u8 taskId)
{
#if OW_FLAG_NO_TRAINER_SEE == 0
    Debug_DestroyMenu_Full_Script(taskId, Debug_FlagsNotSetOverworldConfigMessage);
#else
    if (FlagGet(OW_FLAG_NO_TRAINER_SEE))
        PlaySE(SE_PC_OFF);
    else
        PlaySE(SE_PC_LOGIN);
    FlagToggle(OW_FLAG_NO_TRAINER_SEE);
#endif
}

static void DebugAction_FlagsVars_BagUseOnOff(u8 taskId)
{
#if B_VAR_NO_BAG_USE < VARS_START || B_VAR_NO_BAG_USE > VARS_END
    Debug_DestroyMenu_Full_Script(taskId, Debug_VarsNotSetBattleConfigMessage);
#else
    PlaySE(SE_SELECT);
    VarSet(B_VAR_NO_BAG_USE, (VarGet(B_VAR_NO_BAG_USE) + 1) % 3);
#endif
}

static void DebugAction_FlagsVars_CatchingOnOff(u8 taskId)
{
#if WE_FLAG_NO_CATCHING == 0
    Debug_DestroyMenu_Full_Script(taskId, Debug_FlagsNotSetBattleConfigMessage);
#else
    if (FlagGet(WE_FLAG_NO_CATCHING))
        PlaySE(SE_PC_OFF);
    else
        PlaySE(SE_PC_LOGIN);
    FlagToggle(WE_FLAG_NO_CATCHING);
#endif
}

// *******************************
// Actions Give

static void Debug_DisplayItemIcon(u8 taskId, enum Item itemId)
{
    DestroyDebugIcon(taskId);
    gTasks[taskId].tSpriteId = AddItemIconSprite(DEBUG_ICON_TAG, DEBUG_ICON_TAG,  itemId);
    if (gTasks[taskId].tSpriteId != MAX_SPRITES)
    {
        gSprites[gTasks[taskId].tSpriteId].x = DEBUG_NUMBER_ICON_X + 8;
        gSprites[gTasks[taskId].tSpriteId].y = DEBUG_NUMBER_ICON_Y + 8;
        gSprites[gTasks[taskId].tSpriteId].oam.priority = 0;
    }
}

static void DebugSelectionStep_UpdateItem(u8 taskId, u8 digits, u32 min, u32 max)
{
    u32 itemId = gTasks[taskId].tInput;
    Debug_DisplayItemIcon(taskId, itemId);
    ConvertIntToDecimalStringN(gStringVar3, itemId, STR_CONV_MODE_LEADING_ZEROS, digits);
    StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("Item ID: {STR_VAR_3}"));
    u8* end = CopyItemName(itemId, gStringVar2);
    enum Move moveId = ItemIdToBattleMoveId(itemId);
    if (moveId != MOVE_NONE)
    {
        end = StringCopy(end, gText_Space);
        end = StringCopy(end, GetMoveName(moveId));
    }
    else if (CheckIfItemIsTMHMOrEvolutionStone(itemId) == ITEM_IS_TM_HM)
    {
        end = StringCopy(end, COMPOUND_STRING(" None"));
    }
    WrapFontIdToFit(gStringVar2, end, DEBUG_MENU_FONT, WindowWidthPx(gTasks[taskId].tSubWindowId));
    StringCopy(gStringVar3, COMPOUND_STRING(""));
    DebugNativeStep_PrintWindowSelection(taskId);
}

UPDATE_GENERIC_INPUT(Quantity, Quantity)

static bool32 DebugSelection_GiveItem_Complete(u8 taskId)
{
    AddBagItem(DebugSelection_GetData(taskId, 0), DebugSelection_GetData(taskId, 1));
    DebugSelectionStep_ReturnToGiveMenu(taskId);
    PlaySE(SE_SUCCESS);
    return TRUE;
}

static const struct DebugSelectionStep sItemSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateItem,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 1,
    .maxValue = ITEMS_COUNT - 1,
    .digits = 3
};

static const struct DebugSelectionStep sQuantitySelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateQuantity,
    .stepConfirm = DebugSelectionStep_GenericInputConfirmAndDestroyIcon,
    .minValue = 1,
    .maxValue = MAX_BAG_ITEM_CAPACITY,
    .digits = 3
};

static const struct DebugSelection sGiveItemSelection = {
    .onInit = Debug_CreateInputDisplayWindow,
    .onCancel = DebugSelectionStep_ReturnToGiveMenu,
    .onComplete = DebugSelection_GiveItem_Complete,
    .steps = {&sItemSelectionStep, &sQuantitySelectionStep},
    .maxSteps = 2,
};

static bool32 DebugSelection_GiveSimplePokemon_OnComplete(u8 taskId)
{
    ScriptGiveMon(DebugSelection_GetData(taskId, 0), DebugSelection_GetData(taskId, 1), ITEM_NONE);
    DebugSelectionStep_ReturnToGiveMenu(taskId);
    PlaySE(SE_SUCCESS);
    return TRUE;
}

static const struct DebugSelection sSimplePokemonSelection = {
    .onInit = Debug_CreateInputDisplayWindow,
    .onCancel = DebugSelectionStep_ReturnToGiveMenu,
    .onComplete = DebugSelection_GiveSimplePokemon_OnComplete,
    .steps = {
        &sSpeciesSelectionStep,
        &sLevelSelectionStep,
    },
    .maxSteps = 2,
};

static void DebugSelectionStep_UpdateGender(u8 taskId, u8 digits, u32 min, u32 max)
{
    enum Species species = DebugSelection_GetData(taskId, 0);
    u32 gender = GetGenderFromSpeciesAndPersonality(species, gTasks[taskId].tInput);
    if (gender == MON_FEMALE)
        StringCopy(gStringVar1, COMPOUND_STRING("FEMALE"));
    else if (gender == MON_MALE)
        StringCopy(gStringVar1, COMPOUND_STRING("MALE"));
    else
        StringCopy(gStringVar1, COMPOUND_STRING("GENDERLESS"));
    ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, digits);
    StringExpandPlaceholders(gStringVar2, COMPOUND_STRING("{STR_VAR_1} ({STR_VAR_3})"));
    StringCopy(gStringVar1, COMPOUND_STRING("Gender Value:"));
    StringCopy(gStringVar3, COMPOUND_STRING(""));
    DebugNativeStep_PrintWindowSelection(taskId);
}

static void DebugSelectionStep_GenderConfirm(u8 taskId)
{
    enum Species species = DebugSelection_GetData(taskId, 0);
    gTasks[taskId].tInput = GetGenderFromSpeciesAndPersonality(species, gTasks[taskId].tInput);
    DebugSelectionStep_GenericInputConfirm(taskId);
}

static void DebugSelectionStep_UpdateShinyness(u8 taskId, u8 digits, u32 min, u32 max)
{
    DebugSelectionStep_PrintGenericBooleanInput(taskId, COMPOUND_STRING("Shiny:"));
}

static u32 DebugSelectionStep_GetMaxAbility(u8 taskId)
{
    enum Species species = DebugSelection_GetData(taskId, 0);
    u32 max = 0;
    if ((gSpeciesInfo[species].abilities[1] != gSpeciesInfo[species].abilities[0]) && (gSpeciesInfo[species].abilities[1] != ABILITY_NONE))
        max++;
    if (gSpeciesInfo[species].abilities[2] != ABILITY_NONE)
        max++;
    return max;
}

static void DebugSelectionStep_UpdateAbility(u8 taskId, u8 digits, u32 min, u32 max)
{
    enum Ability abilities[NUM_ABILITY_SLOTS];
    enum Species species = DebugSelection_GetData(taskId, 0);
    abilities[0] = gSpeciesInfo[species].abilities[0];
    u32 i = 1;
    if (gSpeciesInfo[species].abilities[1] != abilities[0] && gSpeciesInfo[species].abilities[1] != ABILITY_NONE)
    {
        abilities[1] = gSpeciesInfo[species].abilities[1];
        i++;
    }
    if (gSpeciesInfo[species].abilities[2] != ABILITY_NONE)
    {
        abilities[i] = gSpeciesInfo[species].abilities[2];
    }

    ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, digits);
    StringCopy(gStringVar1, COMPOUND_STRING("Ability:"));
    StringCopy(gStringVar2, gAbilitiesInfo[abilities[gTasks[taskId].tInput]].name);
    StringCopy(gStringVar3, COMPOUND_STRING(""));
    DebugNativeStep_PrintWindowSelection(taskId);
}

static void DebugSelectionStep_AbilityConfirm(u8 taskId)
{
    enum Species species = DebugSelection_GetData(taskId, 0);
    if (gTasks[taskId].tInput == 1)
    {
        if ((gSpeciesInfo[species].abilities[1] == gSpeciesInfo[species].abilities[0]) || (gSpeciesInfo[species].abilities[1] == ABILITY_NONE))
            gTasks[taskId].tInput++;
    }
    DebugSelectionStep_GenericInputConfirm(taskId);
}


static void DebugSelectionStep_UpdateNature(u8 taskId, u8 digits, u32 min, u32 max)
{
    ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, digits);
    StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("Nature: {STR_VAR_3}"));
    StringCopy(gStringVar2, gNaturesInfo[gTasks[taskId].tInput].name);
    StringCopy(gStringVar3, COMPOUND_STRING(""));
    DebugNativeStep_PrintWindowSelection(taskId);
}

static void DebugSelectionStep_UpdateIVs(u8 taskId, u8 digits, u32 min, u32 max)
{
    StringCopy(gStringVar3, gStatNamesTable[gTasks[taskId].tSubstep]);
    StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("{STR_VAR_3} IV:"));
    ConvertIntToDecimalStringN(gStringVar2, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, digits);
    StringCopy(gStringVar3, COMPOUND_STRING(""));
    DebugNativeStep_PrintWindowSelection(taskId);
}

static void DebugSelectionStep_UpdateEVs(u8 taskId, u8 digits, u32 min, u32 max)
{
    StringCopy(gStringVar3, gStatNamesTable[gTasks[taskId].tSubstep]);
    StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("{STR_VAR_3} EV:"));
    ConvertIntToDecimalStringN(gStringVar2, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, digits);
    StringCopy(gStringVar3, COMPOUND_STRING(""));
    DebugNativeStep_PrintWindowSelection(taskId);
}

static void DebugSelectionStep_UpdateDynamaxLevel(u8 taskId, u8 digits, u32 min, u32 max)
{
    DebugSelectionStep_PrintGenericInput(taskId, digits, COMPOUND_STRING("Dynamax Level:"));
}

static void DebugSelectionStep_UpdateGigantamaxFactor(u8 taskId, u8 digits, u32 min, u32 max)
{
    DebugSelectionStep_PrintGenericBooleanInput(taskId, COMPOUND_STRING("Gmax Factor:"));
}

static void DebugSelectionStep_UpdateTeraType(u8 taskId, u8 digits, u32 min, u32 max)
{
    if (gTasks[taskId].tInput == TYPE_MYSTERY)
    {
        if (JOY_NEW(DPAD_DOWN))
            gTasks[taskId].tInput--;
        else
            gTasks[taskId].tInput++;
    }
    ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, digits);
    StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("Tera Type: {STR_VAR_3}"));
    StringCopy(gStringVar2, gTypesInfo[gTasks[taskId].tInput].name);
    StringCopy(gStringVar3, COMPOUND_STRING(""));
    DebugNativeStep_PrintWindowSelection(taskId);
}

static const struct DebugSelectionStep sGenderSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateGender,
    .stepConfirm = DebugSelectionStep_GenderConfirm,
    .minValue = 0,
    .maxValue = 255,
    .digits = 3
};

static const struct DebugSelectionStep sShinynessSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateShinyness,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 0,
    .maxValue = 1,
    .digits = 1
};

static const struct DebugSelectionStep sAbilitySelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateAbility,
    .stepConfirm = DebugSelectionStep_AbilityConfirm,
    .minValue = 0,
    .maxFunc = DebugSelectionStep_GetMaxAbility,
    .digits = 1,
    .useMaxFunc = TRUE
};

static const struct DebugSelectionStep sNatureSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateNature,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 0,
    .maxValue = NUM_NATURES - 1,
    .digits = 2,
};

static const struct DebugSelectionStep sIVsSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateIVs,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 0,
    .maxValue = MAX_PER_STAT_IVS,
    .digits = 2,
    .substepCount = 6
};

static const struct DebugSelectionStep sEVsSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateEVs,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 0,
    .maxValue = MAX_PER_STAT_EVS,
    .digits = 3,
    .substepCount = 6
};

static const struct DebugSelectionStep sDynamaxLevelSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateDynamaxLevel,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 0,
    .maxValue = MAX_DYNAMAX_LEVEL,
    .digits = 2,
};

static const struct DebugSelectionStep sGigantamaxFactorSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateGigantamaxFactor,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 0,
    .maxValue = 1,
    .digits = 1,
};

static const struct DebugSelectionStep sTeraTypeSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateTeraType,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 1,
    .maxValue = NUMBER_OF_MON_TYPES - 1,
    .digits = 2,
};

static bool32 DebugSelection_GiveComplexPokemon_OnComplete(u8 taskId)
{
    u16 *monData = (u16 *)GetWordTaskArg(taskId, STEPS_DATA_PTR_ARG);
    struct Pokemon mon;
    enum Species species = monData[0];
    u8 level = monData[1];
    u32 personality = GetMonPersonality(species, monData[2], monData[5] , RANDOM_UNOWN_LETTER);
    CreateMon(&mon, species, level, personality, OTID_STRUCT_PLAYER_ID);
    SetMonData(&mon, MON_DATA_IS_SHINY, &monData[3]);
    SetMonData(&mon, MON_DATA_ABILITY_NUM, &monData[4]);

    if (monData[6] == MOVE_NONE)
    {
        GiveMonInitialMoveset(&mon);
    }
    else
    {
        for (u32 i = 0; i < MAX_MON_MOVES; i++)
        {
            SetMonMoveSlot(&mon, monData[6 + i], i);
        }
    }

    u16 rawEvs[NUM_STATS];
    for (u32 i = 0; i < NUM_STATS; i++)
    {
        SetMonData(&mon, MON_DATA_HP_IV + i, &monData[10 + i]);
        rawEvs[i] = monData[16 + i];
    }

    u8 evs[NUM_STATS];
    ResolveEVs(rawEvs, evs, FALSE);
    for (u32 i = 0; i < NUM_STATS; i++)
    {
        SetMonData(&mon, MON_DATA_HP_EV + i, &evs[i]);
    }

    SetMonData(&mon, MON_DATA_DYNAMAX_LEVEL, &monData[22]);
    SetMonData(&mon, MON_DATA_GIGANTAMAX_FACTOR, &monData[23]);
    SetMonData(&mon, MON_DATA_TERA_TYPE, &monData[24]);

    CalculateMonStats(&mon);
    GiveScriptedMonToPlayer(&mon, PARTY_SIZE);
    DebugSelectionStep_ReturnToGiveMenu(taskId);
    return TRUE;
}

static const struct DebugSelection sComplexPokemonSelection = {
    .onInit = Debug_CreateInputDisplayWindow,
    .onCancel = DebugSelectionStep_ReturnToGiveMenu,
    .onComplete = DebugSelection_GiveComplexPokemon_OnComplete,
    .steps = {
        &sSpeciesSelectionStep,
        &sLevelSelectionStep,
        &sGenderSelectionStep,
        &sShinynessSelectionStep,
        &sAbilitySelectionStep,
        &sNatureSelectionStep,
        &sMovesSelectionStep,
        &sIVsSelectionStep,
        &sEVsSelectionStep,
        &sDynamaxLevelSelectionStep,
        &sGigantamaxFactorSelectionStep,
        &sTeraTypeSelectionStep,
    },
    .maxSteps = 12,
};

static bool32 DebugSelection_GiveEggPokemon_OnComplete(u8 taskId)
{
    ScriptGiveEgg(DebugSelection_GetData(taskId, 0));
    DebugSelectionStep_ReturnToGiveMenu(taskId);
    PlaySE(SE_SUCCESS);
    return TRUE;
}

static const struct DebugSelection sEggPokemonSelection = {
    .onInit = Debug_CreateInputDisplayWindow,
    .onCancel = DebugSelectionStep_ReturnToGiveMenu,
    .onComplete = DebugSelection_GiveEggPokemon_OnComplete,
    .steps = {
        &sSpeciesSelectionStep
    },
    .maxSteps = 1,
};

//Decoration
static void DebugSelectionStep_UpdateDecoration(u8 taskId, u8 digits, u32 min, u32 max)
{
    u32 decorationId = gTasks[taskId].tInput;
    DestroyDebugIcon(taskId);
    gTasks[taskId].tSpriteId = AddDecorationIconObject(decorationId,
        DEBUG_NUMBER_ICON_X + 8, DEBUG_NUMBER_ICON_Y + 10, 0,
        DEBUG_ICON_TAG, DEBUG_ICON_TAG);

    ConvertIntToDecimalStringN(gStringVar3, decorationId, STR_CONV_MODE_LEADING_ZEROS, digits);
    StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("Decor ID: {STR_VAR_3}"));
    u8* end = StringCopy(gStringVar2, gDecorations[decorationId].name);
    WrapFontIdToFit(gStringVar2, end, DEBUG_MENU_FONT, WindowWidthPx(gTasks[taskId].tSubWindowId));
    StringCopy(gStringVar3, COMPOUND_STRING(""));
    DebugNativeStep_PrintWindowSelection(taskId);
}

static bool32 DebugSelection_GiveDecoration_Complete(u8 taskId)
{
    DecorationAdd(DebugSelection_GetData(taskId, 0));
    DebugSelectionStep_ReturnToGiveMenu(taskId);
    PlaySE(SE_SUCCESS);
    return TRUE;
}

static const struct DebugSelectionStep sDecorationSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateDecoration,
    .stepConfirm = DebugSelectionStep_GenericInputConfirmAndDestroyIcon,
    .minValue = 1,
    .maxValue = NUM_DECORATIONS,
    .digits = 3
};

static const struct DebugSelection sGiveDecorationSelection = {
    .onInit = Debug_CreateInputDisplayWindow,
    .onCancel = DebugSelectionStep_ReturnToGiveMenu,
    .onComplete = DebugSelection_GiveDecoration_Complete,
    .steps = {&sDecorationSelectionStep},
    .maxSteps = 1,
};

static void DebugAction_Give_MaxMoney(u8 taskId)
{
    SetMoney(&gSaveBlock1Ptr->money, MAX_MONEY);
}

static void DebugAction_Give_MaxCoins(u8 taskId)
{
    SetCoins(MAX_COINS);

    if (!CheckBagHasItem(ITEM_COIN_CASE, 1))
        AddBagItem(ITEM_COIN_CASE, 1);
}

static void DebugAction_Give_MaxBattlePoints(u8 taskId)
{
    gSaveBlock2Ptr->frontier.battlePoints = MAX_BATTLE_FRONTIER_POINTS;
}

static void DebugAction_Give_DayCareEgg(u8 taskId)
{
    s32 emptySlot = Daycare_FindEmptySpot(&gSaveBlock1Ptr->daycare);
    if (emptySlot == 0) // no daycare mons
        Debug_DestroyMenu_Full_Script(taskId, DebugScript_ZeroDaycareMons);
    else if (emptySlot == 1) // 1 daycare mon
        Debug_DestroyMenu_Full_Script(taskId, DebugScript_OneDaycareMons);
    else if (GetDaycareCompatibilityScore(&gSaveBlock1Ptr->daycare) == PARENTS_INCOMPATIBLE) // not compatible parents
        Debug_DestroyMenu_Full_Script(taskId, DebugScript_DaycareMonsNotCompatible);
    else // 2 Pokémon which can have a Pokémon baby together
        TriggerPendingDaycareEgg();
}

// *******************************
// Actions TimeMenu

static void DebugAction_TimeMenu_ChangeTimeOfDay(u8 taskId)
{
    u32 input = ListMenu_ProcessInput(gTasks[taskId].tMenuTaskId);

    DebugAction_DestroyExtraWindow(taskId);
    switch (input)
    {
    case TIME_MORNING:
        FakeRtc_ForwardTimeTo(MORNING_HOUR_BEGIN, 0, 0);
        break;
    case TIME_DAY:
        FakeRtc_ForwardTimeTo(DAY_HOUR_BEGIN, 0, 0);
        break;
    case TIME_EVENING:
        FakeRtc_ForwardTimeTo(EVENING_HOUR_BEGIN, 0, 0);
        break;
    case TIME_NIGHT:
            FakeRtc_ForwardTimeTo(NIGHT_HOUR_BEGIN, 0, 0);
            break;
    }
    Debug_DestroyMenu_Full(taskId);
    SetMainCallback2(CB2_LoadMap);
}

static void DebugAction_TimeMenu_ChangeWeekdays(u8 taskId)
{
    u32 input = ListMenu_ProcessInput(gTasks[taskId].tMenuTaskId);
    struct SiiRtcInfo *rtc = FakeRtc_GetCurrentTime();
    u32 daysToAdd = 0;

    DebugAction_DestroyExtraWindow(taskId);
    daysToAdd = ((input - rtc->dayOfWeek) + WEEKDAY_COUNT) % WEEKDAY_COUNT;
    FakeRtc_AdvanceTimeBy(daysToAdd, 0, 0, 0);
    Debug_DestroyMenu_Full(taskId);
    SetMainCallback2(CB2_LoadMap);
}

void DebugAction_TimeMenu_RedoDailyEvents(u8 taskId)
{
    DoDailyEvents(1);
    Debug_DestroyMenu_Full(taskId);
    SetMainCallback2(CB2_LoadMap);
}

// *******************************
// Actions PCBag

static enum Species GetNextSpecies(enum Species species)
{
    do {
        species = (species < NUM_SPECIES - 1) ? species + 1 : 1;
    } while (!IsSpeciesEnabled(species));
    return species;
}

static void DebugAction_PCBag_Fill_PCBoxes_Fast(u8 taskId) //Credit: Sierraffinity
{
    int boxId, boxPosition;
    struct BoxPokemon boxMon;
    enum Species species = GetNextSpecies(SPECIES_NONE);
    u8 speciesName[POKEMON_NAME_LENGTH + 1];

    CreateBoxMon(&boxMon, species, 100, Random32(), OTID_STRUCT_PLAYER_ID);
    //mons are created with 0 IVs

    for (boxId = 0; boxId < TOTAL_BOXES_COUNT; boxId++)
    {
        for (boxPosition = 0; boxPosition < IN_BOX_COUNT; boxPosition++)
        {
            if (!GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_SANITY_HAS_SPECIES))
            {
                StringCopy(speciesName, GetSpeciesName(species));
                SetBoxMonData(&boxMon, MON_DATA_NICKNAME, &speciesName);
                SetBoxMonData(&boxMon, MON_DATA_SPECIES, &species);
                GiveBoxMonInitialMoveset(&boxMon);
                gPokemonStoragePtr->boxes[boxId][boxPosition] = boxMon;
                species = GetNextSpecies(species);
            }
        }
    }

    // Set flag for user convenience
    FlagSet(FLAG_SYS_POKEMON_GET);
    Debug_DestroyMenu_Full(taskId);
    ScriptContext_Enable();
}

static void DebugAction_PCBag_Fill_PCBoxes_Slow(u8 taskId)
{
    int boxId, boxPosition;
    struct BoxPokemon boxMon;
    enum Species species = GetNextSpecies(SPECIES_NONE);
    bool8 spaceAvailable = FALSE;

    for (boxId = 0; boxId < TOTAL_BOXES_COUNT; boxId++)
    {
        for (boxPosition = 0; boxPosition < IN_BOX_COUNT; boxPosition++)
        {
            if (!GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_SANITY_HAS_SPECIES))
            {
                if (!spaceAvailable)
                    PlayBGM(MUS_RG_MYSTERY_GIFT);
                CreateBoxMon(&boxMon, species, 100, Random32(), OTID_STRUCT_PLAYER_ID);
                SetBoxMonIVs(&boxMon, USE_RANDOM_IVS);
                GiveBoxMonInitialMoveset(&boxMon);
                gPokemonStoragePtr->boxes[boxId][boxPosition] = boxMon;
                species = GetNextSpecies(species);
                spaceAvailable = TRUE;
            }
        }
    }

    // Set flag for user convenience
    FlagSet(FLAG_SYS_POKEMON_GET);
    if (spaceAvailable)
        PlayBGM(GetCurrentMapMusic());

    Debug_DestroyMenu_Full_Script(taskId, Debug_BoxFilledMessage);
}

static void DebugAction_PCBag_Fill_PCItemStorage(u8 taskId)
{
    enum Item itemId;

    for (itemId = 1; itemId < ITEMS_COUNT; itemId++)
    {
        if (!CheckPCHasItem(itemId, MAX_PC_ITEM_CAPACITY))
            AddPCItem(itemId, MAX_PC_ITEM_CAPACITY);
    }
}

static void DebugAction_PCBag_Fill_PocketItems(u8 taskId)
{
    enum Item itemId;

    for (itemId = 1; itemId < ITEMS_COUNT; itemId++)
    {
        if (GetItemPocket(itemId) == POCKET_ITEMS && CheckBagHasSpace(itemId, MAX_BAG_ITEM_CAPACITY))
            AddBagItem(itemId, MAX_BAG_ITEM_CAPACITY);
    }
}

static void DebugAction_PCBag_Fill_PocketPokeBalls(u8 taskId)
{
    for (enum PokeBall ballId = BALL_STRANGE; ballId < POKEBALL_COUNT; ballId++)
    {
        if (CheckBagHasSpace(gPokeBalls[ballId].itemId, MAX_BAG_ITEM_CAPACITY))
            AddBagItem(gPokeBalls[ballId].itemId, MAX_BAG_ITEM_CAPACITY);
    }
}

static void DebugAction_PCBag_Fill_PocketTMHM(u8 taskId)
{
    u16 index, itemId;

    for (index = 0; index < NUM_ALL_MACHINES; index++)
    {
        itemId = GetTMHMItemId(index + 1);
        if (CheckBagHasSpace(itemId, 1) && ItemIdToBattleMoveId(itemId) != MOVE_NONE)
            AddBagItem(itemId, 1);
    }
}

static void DebugAction_PCBag_Fill_PocketBerries(u8 taskId)
{
    enum Item itemId;

    for (enum BerryId berryId = 1; berryId < NUM_BERRIES; berryId++)
    {
        itemId = BerryTypeToItemId(berryId);
        if (CheckBagHasSpace(itemId, MAX_BAG_ITEM_CAPACITY))
            AddBagItem(itemId, MAX_BAG_ITEM_CAPACITY);
    }
}

static void DebugAction_PCBag_Fill_PocketKeyItems(u8 taskId)
{
    enum Item itemId;

    for (itemId = 1; itemId < ITEMS_COUNT; itemId++)
    {
        if (GetItemPocket(itemId) == POCKET_KEY_ITEMS && CheckBagHasSpace(itemId, 1))
            AddBagItem(itemId, 1);
    }
}

static void DebugAction_PCBag_ClearBag(u8 taskId)
{
    PlaySE(MUS_LEVEL_UP);
    ClearBag();
}

static void DebugAction_PCBag_ClearBoxes(u8 taskId)
{
    ResetPokemonStorageSystem();
    Debug_DestroyMenu_Full(taskId);
    ScriptContext_Enable();
}

// *******************************
// Actions Sound
static const u8 *const sSongNames[];

#define tCurrentSong  data[6]

static void DebugAction_Sound_SE(u8 taskId)
{
    u8 windowId;

    ClearStdWindowAndFrame(gTasks[taskId].tWindowId, TRUE);
    RemoveWindow(gTasks[taskId].tWindowId);

    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sDebugMenuWindowTemplateSound);
    DrawStdWindowFrame(windowId, FALSE);

    CopyWindowToVram(windowId, COPYWIN_FULL);

    StopMapMusic(); //Stop map music to better hear sounds

    gTasks[taskId].func = DebugAction_Sound_SE_SelectId;
    gTasks[taskId].tSubWindowId = windowId;
    gTasks[taskId].tInput = FindSong(SONG_SE, SONG_FIRST_GE, MUS_DUMMY);
    gTasks[taskId].tDigit = 0;
    gTasks[taskId].tCurrentSong = gTasks[taskId].tInput;

    // Display initial sound effect
    StringCopy(gStringVar2, gText_DigitIndicator[0]);
    ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, DEBUG_NUMBER_DIGITS_ITEMS);
    StringCopyPadded(gStringVar1, sSongNames[gTasks[taskId].tInput], CHAR_SPACE, 35);
    StringExpandPlaceholders(gStringVar4, sDebugText_Sound_SFX_ID);
    AddTextPrinterParameterized(windowId, DEBUG_MENU_FONT, gStringVar4, 0, 0, 0, NULL);
}

static void DebugAction_Sound_SE_SelectId(u8 taskId)
{
    if (JOY_NEW(DPAD_ANY))
    {
        Debug_HandleInput_SongId(taskId, SONG_SE, DEBUG_NUMBER_DIGITS_ITEMS);

        StringCopy(gStringVar2, gText_DigitIndicator[gTasks[taskId].tDigit]);
        const u8 *seName = sSongNames[gTasks[taskId].tInput];
        if (seName == NULL)
            seName = sDebugText_Dashes;
        StringCopyPadded(gStringVar1, seName, CHAR_SPACE, 35);
        ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, DEBUG_NUMBER_DIGITS_ITEMS);
        StringExpandPlaceholders(gStringVar4, sDebugText_Sound_SFX_ID);
        AddTextPrinterParameterized(gTasks[taskId].tSubWindowId, DEBUG_MENU_FONT, gStringVar4, 0, 0, 0, NULL);
    }

    if (JOY_NEW(A_BUTTON))
    {
        m4aSongNumStop(gTasks[taskId].tCurrentSong);
        gTasks[taskId].tCurrentSong = gTasks[taskId].tInput;
        m4aSongNumStart(gTasks[taskId].tInput);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        m4aSongNumStop(gTasks[taskId].tCurrentSong);
        DebugAction_DestroyExtraWindow(taskId);
    }
    else if (JOY_NEW(START_BUTTON))
    {
        m4aSongNumStop(gTasks[taskId].tCurrentSong);
    }
}

static void DebugAction_Sound_MUS(u8 taskId)
{
    u8 windowId;

    ClearStdWindowAndFrame(gTasks[taskId].tWindowId, TRUE);
    RemoveWindow(gTasks[taskId].tWindowId);

    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sDebugMenuWindowTemplateSound);
    DrawStdWindowFrame(windowId, FALSE);

    CopyWindowToVram(windowId, COPYWIN_FULL);

    StopMapMusic(); //Stop map music to better hear new music

    gTasks[taskId].func = DebugAction_Sound_MUS_SelectId;
    gTasks[taskId].tSubWindowId = windowId;
    gTasks[taskId].tInput = FindSong(SONG_MUS, SONG_FIRST_GE, MUS_DUMMY);
    gTasks[taskId].tDigit = 0;
    gTasks[taskId].tCurrentSong = gTasks[taskId].tInput;

    // Display initial song
    StringCopy(gStringVar2, gText_DigitIndicator[0]);
    ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, DEBUG_NUMBER_DIGITS_ITEMS);
    StringCopyPadded(gStringVar1, sSongNames[gTasks[taskId].tInput], CHAR_SPACE, 35);
    StringExpandPlaceholders(gStringVar4, sDebugText_Sound_Music_ID);
    AddTextPrinterParameterized(windowId, DEBUG_MENU_FONT, gStringVar4, 0, 0, 0, NULL);
}

static void DebugAction_Sound_MUS_SelectId(u8 taskId)
{
    if (JOY_NEW(DPAD_ANY))
    {
        Debug_HandleInput_SongId(taskId, SONG_MUS, DEBUG_NUMBER_DIGITS_ITEMS);

        StringCopy(gStringVar2, gText_DigitIndicator[gTasks[taskId].tDigit]);
        const u8 *bgmName = sSongNames[gTasks[taskId].tInput];
        if (bgmName == NULL)
            bgmName = sDebugText_Dashes;
        StringCopyPadded(gStringVar1, bgmName, CHAR_SPACE, 35);
        ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, DEBUG_NUMBER_DIGITS_ITEMS);
        StringExpandPlaceholders(gStringVar4, sDebugText_Sound_Music_ID);
        AddTextPrinterParameterized(gTasks[taskId].tSubWindowId, DEBUG_MENU_FONT, gStringVar4, 0, 0, 0, NULL);
    }

    if (JOY_NEW(A_BUTTON))
    {
        m4aSongNumStop(gTasks[taskId].tCurrentSong);
        gTasks[taskId].tCurrentSong = gTasks[taskId].tInput;
        m4aSongNumStart(gTasks[taskId].tInput);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        // m4aSongNumStop(gTasks[taskId].tCurrentSong);   //Uncomment if music should stop after leaving menu
        DebugAction_DestroyExtraWindow(taskId);
    }
    else if (JOY_NEW(START_BUTTON))
    {
        m4aSongNumStop(gTasks[taskId].tCurrentSong);
    }
}

static const u32 gDebugFollowerNPCGraphics[] =
{
    OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL,
    OBJ_EVENT_GFX_RIVAL_MAY_NORMAL,
    OBJ_EVENT_GFX_STEVEN,
    OBJ_EVENT_GFX_WALLY,
    OBJ_EVENT_GFX_RED,
    OBJ_EVENT_GFX_LEAF,
};

static void DebugAction_CreateFollowerNPC(u8 taskId)
{
    u32 input = ListMenu_ProcessInput(gTasks[taskId].tMenuTaskId);
    u32 gfx = gDebugFollowerNPCGraphics[input];

    Debug_DestroyMenu_Full(taskId);
    LockPlayerFieldControls();
    DestroyFollowerNPC();
    SetFollowerNPCData(FNPC_DATA_BATTLE_PARTNER, PARTNER_STEVEN);
    CreateFollowerNPC(gfx, FNPC_ALL, Debug_Follower_NPC_Event_Script);
    UnlockPlayerFieldControls();
}

static void DebugAction_DestroyFollowerNPC(u8 taskId)
{
    if (FNPC_ENABLE_NPC_FOLLOWERS)
    {
        Debug_DestroyMenu_Full(taskId);
        LockPlayerFieldControls();
        DestroyFollowerNPC();
        UnlockPlayerFieldControls();
    }
    else
    {
        Debug_DestroyMenu_Full_Script(taskId, Debug_Follower_NPC_Not_Enabled);
    }
}

#undef tCurrentSong


#define SOUND_LIST_BGM              \
    X(MUS_LITTLEROOT_TEST)          \
    X(MUS_GSC_ROUTE38)              \
    X(MUS_CAUGHT)                   \
    X(MUS_VICTORY_WILD)             \
    X(MUS_VICTORY_GYM_LEADER)       \
    X(MUS_VICTORY_LEAGUE)           \
    X(MUS_C_COMM_CENTER)            \
    X(MUS_GSC_PEWTER)               \
    X(MUS_C_VS_LEGEND_BEAST)        \
    X(MUS_ROUTE101)                 \
    X(MUS_ROUTE110)                 \
    X(MUS_ROUTE120)                 \
    X(MUS_PETALBURG)                \
    X(MUS_OLDALE)                   \
    X(MUS_GYM)                      \
    X(MUS_SURF)                     \
    X(MUS_PETALBURG_WOODS)          \
    X(MUS_LEVEL_UP)                 \
    X(MUS_HEAL)                     \
    X(MUS_OBTAIN_BADGE)             \
    X(MUS_OBTAIN_ITEM)              \
    X(MUS_EVOLVED)                  \
    X(MUS_OBTAIN_TMHM)              \
    X(MUS_LILYCOVE_MUSEUM)          \
    X(MUS_ROUTE122)                 \
    X(MUS_OCEANIC_MUSEUM)           \
    X(MUS_EVOLUTION_INTRO)          \
    X(MUS_EVOLUTION)                \
    X(MUS_MOVE_DELETED)             \
    X(MUS_ENCOUNTER_GIRL)           \
    X(MUS_ENCOUNTER_MALE)           \
    X(MUS_ABANDONED_SHIP)           \
    X(MUS_FORTREE)                  \
    X(MUS_BIRCH_LAB)                \
    X(MUS_B_TOWER_RS)               \
    X(MUS_ENCOUNTER_SWIMMER)        \
    X(MUS_CAVE_OF_ORIGIN)           \
    X(MUS_OBTAIN_BERRY)             \
    X(MUS_AWAKEN_LEGEND)            \
    X(MUS_SLOTS_JACKPOT)            \
    X(MUS_SLOTS_WIN)                \
    X(MUS_TOO_BAD)                  \
    X(MUS_ROULETTE)                 \
    X(MUS_LINK_CONTEST_P1)          \
    X(MUS_LINK_CONTEST_P2)          \
    X(MUS_LINK_CONTEST_P3)          \
    X(MUS_LINK_CONTEST_P4)          \
    X(MUS_ENCOUNTER_RICH)           \
    X(MUS_VERDANTURF)               \
    X(MUS_RUSTBORO)                 \
    X(MUS_POKE_CENTER)              \
    X(MUS_ROUTE104)                 \
    X(MUS_ROUTE119)                 \
    X(MUS_CYCLING)                  \
    X(MUS_POKE_MART)                \
    X(MUS_LITTLEROOT)               \
    X(MUS_MT_CHIMNEY)               \
    X(MUS_ENCOUNTER_FEMALE)         \
    X(MUS_LILYCOVE)                 \
    X(MUS_DESERT)                   \
    X(MUS_HELP)                     \
    X(MUS_UNDERWATER)               \
    X(MUS_VICTORY_TRAINER)          \
    X(MUS_TITLE)                    \
    X(MUS_INTRO)                    \
    X(MUS_ENCOUNTER_MAY)            \
    X(MUS_ENCOUNTER_INTENSE)        \
    X(MUS_ENCOUNTER_COOL)           \
    X(MUS_ROUTE113)                 \
    X(MUS_ENCOUNTER_AQUA)           \
    X(MUS_FOLLOW_ME)                \
    X(MUS_ENCOUNTER_BRENDAN)        \
    X(MUS_EVER_GRANDE)              \
    X(MUS_ENCOUNTER_SUSPICIOUS)     \
    X(MUS_VICTORY_AQUA_MAGMA)       \
    X(MUS_CABLE_CAR)                \
    X(MUS_GAME_CORNER)              \
    X(MUS_DEWFORD)                  \
    X(MUS_SAFARI_ZONE)              \
    X(MUS_VICTORY_ROAD)             \
    X(MUS_AQUA_MAGMA_HIDEOUT)       \
    X(MUS_SAILING)                  \
    X(MUS_MT_PYRE)                  \
    X(MUS_SLATEPORT)                \
    X(MUS_MT_PYRE_EXTERIOR)         \
    X(MUS_SCHOOL)                   \
    X(MUS_HALL_OF_FAME)             \
    X(MUS_FALLARBOR)                \
    X(MUS_SEALED_CHAMBER)           \
    X(MUS_CONTEST_WINNER)           \
    X(MUS_CONTEST)                  \
    X(MUS_ENCOUNTER_MAGMA)          \
    X(MUS_INTRO_BATTLE)             \
    X(MUS_ABNORMAL_WEATHER)         \
    X(MUS_WEATHER_GROUDON)          \
    X(MUS_SOOTOPOLIS)               \
    X(MUS_CONTEST_RESULTS)          \
    X(MUS_HALL_OF_FAME_ROOM)        \
    X(MUS_TRICK_HOUSE)              \
    X(MUS_ENCOUNTER_TWINS)          \
    X(MUS_ENCOUNTER_ELITE_FOUR)     \
    X(MUS_ENCOUNTER_HIKER)          \
    X(MUS_CONTEST_LOBBY)            \
    X(MUS_ENCOUNTER_INTERVIEWER)    \
    X(MUS_ENCOUNTER_CHAMPION)       \
    X(MUS_CREDITS)                  \
    X(MUS_END)                      \
    X(MUS_B_FRONTIER)               \
    X(MUS_B_ARENA)                  \
    X(MUS_OBTAIN_B_POINTS)          \
    X(MUS_REGISTER_MATCH_CALL)      \
    X(MUS_B_PYRAMID)                \
    X(MUS_B_PYRAMID_TOP)            \
    X(MUS_B_PALACE)                 \
    X(MUS_RAYQUAZA_APPEARS)         \
    X(MUS_B_TOWER)                  \
    X(MUS_OBTAIN_SYMBOL)            \
    X(MUS_B_DOME)                   \
    X(MUS_B_PIKE)                   \
    X(MUS_B_FACTORY)                \
    X(MUS_VS_RAYQUAZA)              \
    X(MUS_VS_FRONTIER_BRAIN)        \
    X(MUS_VS_MEW)                   \
    X(MUS_B_DOME_LOBBY)             \
    X(MUS_VS_WILD)                  \
    X(MUS_VS_AQUA_MAGMA)            \
    X(MUS_VS_TRAINER)               \
    X(MUS_VS_GYM_LEADER)            \
    X(MUS_VS_CHAMPION)              \
    X(MUS_VS_REGI)                  \
    X(MUS_VS_KYOGRE_GROUDON)        \
    X(MUS_VS_RIVAL)                 \
    X(MUS_VS_ELITE_FOUR)            \
    X(MUS_VS_AQUA_MAGMA_LEADER)     \
    X(MUS_RG_FOLLOW_ME)             \
    X(MUS_RG_GAME_CORNER)           \
    X(MUS_RG_ROCKET_HIDEOUT)        \
    X(MUS_RG_GYM)                   \
    X(MUS_RG_JIGGLYPUFF)            \
    X(MUS_RG_INTRO_FIGHT)           \
    X(MUS_RG_TITLE)                 \
    X(MUS_RG_CINNABAR)              \
    X(MUS_RG_LAVENDER)              \
    X(MUS_RG_HEAL)                  \
    X(MUS_RG_CYCLING)               \
    X(MUS_RG_ENCOUNTER_ROCKET)      \
    X(MUS_RG_ENCOUNTER_GIRL)        \
    X(MUS_RG_ENCOUNTER_BOY)         \
    X(MUS_RG_HALL_OF_FAME)          \
    X(MUS_RG_VIRIDIAN_FOREST)       \
    X(MUS_RG_MT_MOON)               \
    X(MUS_RG_POKE_MANSION)          \
    X(MUS_RG_CREDITS)               \
    X(MUS_RG_ROUTE1)                \
    X(MUS_RG_ROUTE24)               \
    X(MUS_RG_ROUTE3)                \
    X(MUS_RG_ROUTE11)               \
    X(MUS_RG_VICTORY_ROAD)          \
    X(MUS_RG_VS_GYM_LEADER)         \
    X(MUS_RG_VS_TRAINER)            \
    X(MUS_RG_VS_WILD)               \
    X(MUS_RG_VS_CHAMPION)           \
    X(MUS_RG_PALLET)                \
    X(MUS_RG_OAK_LAB)               \
    X(MUS_RG_OAK)                   \
    X(MUS_RG_POKE_CENTER)           \
    X(MUS_RG_SS_ANNE)               \
    X(MUS_RG_SURF)                  \
    X(MUS_RG_POKE_TOWER)            \
    X(MUS_RG_SILPH)                 \
    X(MUS_RG_FUCHSIA)               \
    X(MUS_RG_CELADON)               \
    X(MUS_RG_VICTORY_TRAINER)       \
    X(MUS_RG_VICTORY_WILD)          \
    X(MUS_RG_VICTORY_GYM_LEADER)    \
    X(MUS_RG_VERMILLION)            \
    X(MUS_RG_PEWTER)                \
    X(MUS_RG_ENCOUNTER_RIVAL)       \
    X(MUS_RG_RIVAL_EXIT)            \
    X(MUS_RG_DEX_RATING)            \
    X(MUS_RG_OBTAIN_KEY_ITEM)       \
    X(MUS_RG_CAUGHT_INTRO)          \
    X(MUS_RG_PHOTO)                 \
    X(MUS_RG_GAME_FREAK)            \
    X(MUS_RG_CAUGHT)                \
    X(MUS_RG_NEW_GAME_INSTRUCT)     \
    X(MUS_RG_NEW_GAME_INTRO)        \
    X(MUS_RG_NEW_GAME_EXIT)         \
    X(MUS_RG_POKE_JUMP)             \
    X(MUS_RG_UNION_ROOM)            \
    X(MUS_RG_NET_CENTER)            \
    X(MUS_RG_MYSTERY_GIFT)          \
    X(MUS_RG_BERRY_PICK)            \
    X(MUS_RG_SEVII_CAVE)            \
    X(MUS_RG_TEACHY_TV_SHOW)        \
    X(MUS_RG_SEVII_ROUTE)           \
    X(MUS_RG_SEVII_DUNGEON)         \
    X(MUS_RG_SEVII_123)             \
    X(MUS_RG_SEVII_45)              \
    X(MUS_RG_SEVII_67)              \
    X(MUS_RG_POKE_FLUTE)            \
    X(MUS_RG_VS_DEOXYS)             \
    X(MUS_RG_VS_MEWTWO)             \
    X(MUS_RG_VS_LEGEND)             \
    X(MUS_RG_ENCOUNTER_GYM_LEADER)  \
    X(MUS_RG_ENCOUNTER_DEOXYS)      \
    X(MUS_RG_TRAINER_TOWER)         \
    X(MUS_RG_SLOW_PALLET)           \
    X(MUS_RG_TEACHY_TV_MENU)

#define SOUND_LIST_SE               \
    X(SE_USE_ITEM)                  \
    X(SE_PC_LOGIN)                  \
    X(SE_PC_OFF)                    \
    X(SE_PC_ON)                     \
    X(SE_SELECT)                    \
    X(SE_WIN_OPEN)                  \
    X(SE_WALL_HIT)                  \
    X(SE_DOOR)                      \
    X(SE_EXIT)                      \
    X(SE_LEDGE)                     \
    X(SE_BIKE_BELL)                 \
    X(SE_NOT_EFFECTIVE)             \
    X(SE_EFFECTIVE)                 \
    X(SE_SUPER_EFFECTIVE)           \
    X(SE_BALL_OPEN)                 \
    X(SE_FAINT)                     \
    X(SE_FLEE)                      \
    X(SE_SLIDING_DOOR)              \
    X(SE_SHIP)                      \
    X(SE_BANG)                      \
    X(SE_PIN)                       \
    X(SE_BOO)                       \
    X(SE_BALL)                      \
    X(SE_CONTEST_PLACE)             \
    X(SE_A)                         \
    X(SE_I)                         \
    X(SE_U)                         \
    X(SE_E)                         \
    X(SE_O)                         \
    X(SE_N)                         \
    X(SE_SUCCESS)                   \
    X(SE_FAILURE)                   \
    X(SE_EXP)                       \
    X(SE_BIKE_HOP)                  \
    X(SE_SWITCH)                    \
    X(SE_CLICK)                     \
    X(SE_FU_ZAKU)                   \
    X(SE_CONTEST_CONDITION_LOSE)    \
    X(SE_LAVARIDGE_FALL_WARP)       \
    X(SE_ICE_STAIRS)                \
    X(SE_ICE_BREAK)                 \
    X(SE_ICE_CRACK)                 \
    X(SE_FALL)                      \
    X(SE_UNLOCK)                    \
    X(SE_WARP_IN)                   \
    X(SE_WARP_OUT)                  \
    X(SE_REPEL)                     \
    X(SE_ROTATING_GATE)             \
    X(SE_TRUCK_MOVE)                \
    X(SE_TRUCK_STOP)                \
    X(SE_TRUCK_UNLOAD)              \
    X(SE_TRUCK_DOOR)                \
    X(SE_BERRY_BLENDER)             \
    X(SE_CARD)                      \
    X(SE_SAVE)                      \
    X(SE_BALL_BOUNCE_1)             \
    X(SE_BALL_BOUNCE_2)             \
    X(SE_BALL_BOUNCE_3)             \
    X(SE_BALL_BOUNCE_4)             \
    X(SE_BALL_TRADE)                \
    X(SE_BALL_THROW)                \
    X(SE_NOTE_C)                    \
    X(SE_NOTE_D)                    \
    X(SE_NOTE_E)                    \
    X(SE_NOTE_F)                    \
    X(SE_NOTE_G)                    \
    X(SE_NOTE_A)                    \
    X(SE_NOTE_B)                    \
    X(SE_NOTE_C_HIGH)               \
    X(SE_PUDDLE)                    \
    X(SE_BRIDGE_WALK)               \
    X(SE_ITEMFINDER)                \
    X(SE_DING_DONG)                 \
    X(SE_BALLOON_RED)               \
    X(SE_BALLOON_BLUE)              \
    X(SE_BALLOON_YELLOW)            \
    X(SE_BREAKABLE_DOOR)            \
    X(SE_MUD_BALL)                  \
    X(SE_FIELD_POISON)              \
    X(SE_ESCALATOR)                 \
    X(SE_THUNDERSTORM)              \
    X(SE_THUNDERSTORM_STOP)         \
    X(SE_DOWNPOUR)                  \
    X(SE_DOWNPOUR_STOP)             \
    X(SE_RAIN)                      \
    X(SE_RAIN_STOP)                 \
    X(SE_THUNDER)                   \
    X(SE_THUNDER2)                  \
    X(SE_ELEVATOR)                  \
    X(SE_LOW_HEALTH)                \
    X(SE_EXP_MAX)                   \
    X(SE_ROULETTE_BALL)             \
    X(SE_ROULETTE_BALL2)            \
    X(SE_TAILLOW_WING_FLAP)         \
    X(SE_SHOP)                      \
    X(SE_CONTEST_HEART)             \
    X(SE_CONTEST_CURTAIN_RISE)      \
    X(SE_CONTEST_CURTAIN_FALL)      \
    X(SE_CONTEST_ICON_CHANGE)       \
    X(SE_CONTEST_ICON_CLEAR)        \
    X(SE_CONTEST_MONS_TURN)         \
    X(SE_SHINY)                     \
    X(SE_INTRO_BLAST)               \
    X(SE_MUGSHOT)                   \
    X(SE_APPLAUSE)                  \
    X(SE_VEND)                      \
    X(SE_ORB)                       \
    X(SE_DEX_SCROLL)                \
    X(SE_DEX_PAGE)                  \
    X(SE_POKENAV_ON)                \
    X(SE_POKENAV_OFF)               \
    X(SE_DEX_SEARCH)                \
    X(SE_EGG_HATCH)                 \
    X(SE_BALL_TRAY_ENTER)           \
    X(SE_BALL_TRAY_BALL)            \
    X(SE_BALL_TRAY_EXIT)            \
    X(SE_GLASS_FLUTE)               \
    X(SE_M_THUNDERBOLT)             \
    X(SE_M_THUNDERBOLT2)            \
    X(SE_M_HARDEN)                  \
    X(SE_M_NIGHTMARE)               \
    X(SE_M_VITAL_THROW)             \
    X(SE_M_VITAL_THROW2)            \
    X(SE_M_BUBBLE)                  \
    X(SE_M_BUBBLE2)                 \
    X(SE_M_BUBBLE3)                 \
    X(SE_M_RAIN_DANCE)              \
    X(SE_M_CUT)                     \
    X(SE_M_STRING_SHOT)             \
    X(SE_M_STRING_SHOT2)            \
    X(SE_M_ROCK_THROW)              \
    X(SE_M_GUST)                    \
    X(SE_M_GUST2)                   \
    X(SE_M_DOUBLE_SLAP)             \
    X(SE_M_DOUBLE_TEAM)             \
    X(SE_M_RAZOR_WIND)              \
    X(SE_M_ICY_WIND)                \
    X(SE_M_THUNDER_WAVE)            \
    X(SE_M_COMET_PUNCH)             \
    X(SE_M_MEGA_KICK)               \
    X(SE_M_MEGA_KICK2)              \
    X(SE_M_CRABHAMMER)              \
    X(SE_M_JUMP_KICK)               \
    X(SE_M_FLAME_WHEEL)             \
    X(SE_M_FLAME_WHEEL2)            \
    X(SE_M_FLAMETHROWER)            \
    X(SE_M_FIRE_PUNCH)              \
    X(SE_M_TOXIC)                   \
    X(SE_M_SACRED_FIRE)             \
    X(SE_M_SACRED_FIRE2)            \
    X(SE_M_EMBER)                   \
    X(SE_M_TAKE_DOWN)               \
    X(SE_M_BLIZZARD)                \
    X(SE_M_BLIZZARD2)               \
    X(SE_M_SCRATCH)                 \
    X(SE_M_VICEGRIP)                \
    X(SE_M_WING_ATTACK)             \
    X(SE_M_FLY)                     \
    X(SE_M_SAND_ATTACK)             \
    X(SE_M_RAZOR_WIND2)             \
    X(SE_M_BITE)                    \
    X(SE_M_HEADBUTT)                \
    X(SE_M_SURF)                    \
    X(SE_M_HYDRO_PUMP)              \
    X(SE_M_WHIRLPOOL)               \
    X(SE_M_HORN_ATTACK)             \
    X(SE_M_TAIL_WHIP)               \
    X(SE_M_MIST)                    \
    X(SE_M_POISON_POWDER)           \
    X(SE_M_BIND)                    \
    X(SE_M_DRAGON_RAGE)             \
    X(SE_M_SING)                    \
    X(SE_M_PERISH_SONG)             \
    X(SE_M_PAY_DAY)                 \
    X(SE_M_DIG)                     \
    X(SE_M_DIZZY_PUNCH)             \
    X(SE_M_SELF_DESTRUCT)           \
    X(SE_M_EXPLOSION)               \
    X(SE_M_ABSORB_2)                \
    X(SE_M_ABSORB)                  \
    X(SE_M_SCREECH)                 \
    X(SE_M_BUBBLE_BEAM)             \
    X(SE_M_BUBBLE_BEAM2)            \
    X(SE_M_SUPERSONIC)              \
    X(SE_M_BELLY_DRUM)              \
    X(SE_M_METRONOME)               \
    X(SE_M_BONEMERANG)              \
    X(SE_M_LICK)                    \
    X(SE_M_PSYBEAM)                 \
    X(SE_M_FAINT_ATTACK)            \
    X(SE_M_SWORDS_DANCE)            \
    X(SE_M_LEER)                    \
    X(SE_M_SWAGGER)                 \
    X(SE_M_SWAGGER2)                \
    X(SE_M_HEAL_BELL)               \
    X(SE_M_CONFUSE_RAY)             \
    X(SE_M_SNORE)                   \
    X(SE_M_BRICK_BREAK)             \
    X(SE_M_GIGA_DRAIN)              \
    X(SE_M_PSYBEAM2)                \
    X(SE_M_SOLAR_BEAM)              \
    X(SE_M_PETAL_DANCE)             \
    X(SE_M_TELEPORT)                \
    X(SE_M_MINIMIZE)                \
    X(SE_M_SKETCH)                  \
    X(SE_M_SWIFT)                   \
    X(SE_M_REFLECT)                 \
    X(SE_M_BARRIER)                 \
    X(SE_M_DETECT)                  \
    X(SE_M_LOCK_ON)                 \
    X(SE_M_MOONLIGHT)               \
    X(SE_M_CHARM)                   \
    X(SE_M_CHARGE)                  \
    X(SE_M_STRENGTH)                \
    X(SE_M_HYPER_BEAM)              \
    X(SE_M_WATERFALL)               \
    X(SE_M_REVERSAL)                \
    X(SE_M_ACID_ARMOR)              \
    X(SE_M_SANDSTORM)               \
    X(SE_M_TRI_ATTACK)              \
    X(SE_M_TRI_ATTACK2)             \
    X(SE_M_ENCORE)                  \
    X(SE_M_ENCORE2)                 \
    X(SE_M_BATON_PASS)              \
    X(SE_M_MILK_DRINK)              \
    X(SE_M_ATTRACT)                 \
    X(SE_M_ATTRACT2)                \
    X(SE_M_MORNING_SUN)             \
    X(SE_M_FLATTER)                 \
    X(SE_M_SAND_TOMB)               \
    X(SE_M_GRASSWHISTLE)            \
    X(SE_M_SPIT_UP)                 \
    X(SE_M_DIVE)                    \
    X(SE_M_EARTHQUAKE)              \
    X(SE_M_TWISTER)                 \
    X(SE_M_SWEET_SCENT)             \
    X(SE_M_YAWN)                    \
    X(SE_M_SKY_UPPERCUT)            \
    X(SE_M_STAT_INCREASE)           \
    X(SE_M_HEAT_WAVE)               \
    X(SE_M_UPROAR)                  \
    X(SE_M_HAIL)                    \
    X(SE_M_COSMIC_POWER)            \
    X(SE_M_TEETER_DANCE)            \
    X(SE_M_STAT_DECREASE)           \
    X(SE_M_HAZE)                    \
    X(SE_M_HYPER_BEAM2)             \
    X(SE_RG_DOOR)                   \
    X(SE_RG_CARD_FLIP)              \
    X(SE_RG_CARD_FLIPPING)          \
    X(SE_RG_CARD_OPEN)              \
    X(SE_RG_BAG_CURSOR)             \
    X(SE_RG_BAG_POCKET)             \
    X(SE_RG_BALL_CLICK)             \
    X(SE_RG_SHOP)                   \
    X(SE_RG_SS_ANNE_HORN)           \
    X(SE_RG_HELP_OPEN)              \
    X(SE_RG_HELP_CLOSE)             \
    X(SE_RG_HELP_ERROR)             \
    X(SE_RG_DEOXYS_MOVE)            \
    X(SE_RG_POKE_JUMP_SUCCESS)      \
    X(SE_RG_POKE_JUMP_FAILURE)      \
    X(SE_POKENAV_CALL)              \
    X(SE_POKENAV_HANG_UP)           \
    X(SE_ARENA_TIMEUP1)             \
    X(SE_ARENA_TIMEUP2)             \
    X(SE_PIKE_CURTAIN_CLOSE)        \
    X(SE_PIKE_CURTAIN_OPEN)         \
    X(SE_SUDOWOODO_SHAKE)

// Create song list
#define X(songId) [songId] = COMPOUND_STRING(#songId),
static const u8 *const sSongNames[] =
{
SOUND_LIST_BGM
SOUND_LIST_SE
};
#undef X

u32 FindSong(enum SongType type, enum FindSongMode mode, u32 fromSongId)
{
    static const u8 sSEPrefix[] = _("SE_");
    static const u8 sMUSPrefix[] = _("MUS_");
    const u8 *prefix;
    u32 prefixLength;
    switch (type)
    {
    case SONG_SE:
        prefix = sSEPrefix;
        prefixLength = ARRAY_COUNT(sSEPrefix);
        break;
    case SONG_MUS:
        prefix = sMUSPrefix;
        prefixLength = ARRAY_COUNT(sMUSPrefix);
        break;
    default:
        errorf("unknown song type: %d", type);
        return MUS_DUMMY;
    }

    s32 direction;
    u32 stopAfter;
    u32 songId;
    switch (mode)
    {
    case SONG_FIRST_GE:
        direction = 1;
        stopAfter = ARRAY_COUNT(sSongNames) - 1;
        assertf(fromSongId <= stopAfter, "song ID not in sSongNames: %d", fromSongId)
        {
            return MUS_DUMMY;
        }
        songId = fromSongId;
        break;
    case SONG_FIRST_GT:
        direction = 1;
        stopAfter = ARRAY_COUNT(sSongNames) - 1;
        if (fromSongId == stopAfter)
            return fromSongId;
        songId = fromSongId + 1;
        break;
    case SONG_LAST_LT:
        direction = -1;
        stopAfter = 0;
        if (fromSongId == 0)
            return fromSongId;
        songId = fromSongId - 1;
        break;
    default:
        errorf("unknown song search mode: %d", mode);
        return MUS_DUMMY;
    }

    while (TRUE)
    {
        // Found a match.
        if (sSongNames[songId] != NULL && StringCompareN(sSongNames[songId], prefix, prefixLength - 1) == 0)
            return songId;

        // No match in table.
        if (songId == stopAfter)
            return fromSongId;

        songId += direction;
    }
}

// *******************************
// Actions BerryFunctions

static void DebugAction_BerryFunctions_ClearAll(u8 taskId)
{
    u8 i;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].movementType == MOVEMENT_TYPE_BERRY_TREE_GROWTH)
        {
            RemoveBerryTree(GetObjectEventBerryTreeId(i));
            SetBerryTreeJustPicked(gObjectEvents[i].localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
        }
    }

    ScriptContext_Enable();
    Debug_DestroyMenu_Full(taskId);
}

static void DebugAction_BerryFunctions_Ready(u8 taskId)
{
    u8 i;
    struct BerryTree *tree;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].movementType == MOVEMENT_TYPE_BERRY_TREE_GROWTH)
        {
            tree = &gSaveBlock1Ptr->berryTrees[GetObjectEventBerryTreeId(i)];
            if (tree->stage != BERRY_STAGE_NO_BERRY)
            {
                tree->stage = BERRY_STAGE_BERRIES - 1;
                BerryTreeGrow(tree);
            }
        }
    }

    ScriptContext_Enable();
    Debug_DestroyMenu_Full(taskId);
}

static void DebugAction_BerryFunctions_NextStage(u8 taskId)
{
    u8 i;
    struct BerryTree *tree;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].movementType == MOVEMENT_TYPE_BERRY_TREE_GROWTH)
        {
            tree = &gSaveBlock1Ptr->berryTrees[GetObjectEventBerryTreeId(i)];
            BerryTreeGrow(tree);
        }
    }

    ScriptContext_Enable();
    Debug_DestroyMenu_Full(taskId);
}

static void DebugAction_BerryFunctions_Pests(u8 taskId)
{
    u8 i;

    if (!OW_BERRY_PESTS)
    {
        Debug_DestroyMenu_Full_Script(taskId, Debug_BerryPestsDisabled);
        return;
    }

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].movementType == MOVEMENT_TYPE_BERRY_TREE_GROWTH)
        {
            if (gSaveBlock1Ptr->berryTrees[GetObjectEventBerryTreeId(i)].stage != BERRY_STAGE_PLANTED)
                gSaveBlock1Ptr->berryTrees[GetObjectEventBerryTreeId(i)].pests = TRUE;
        }
    }

    ScriptContext_Enable();
    Debug_DestroyMenu_Full(taskId);
}

static void DebugAction_BerryFunctions_Weeds(u8 taskId)
{
    u8 i;

    if (!OW_BERRY_WEEDS)
    {
        Debug_DestroyMenu_Full_Script(taskId, Debug_BerryWeedsDisabled);
        return;
    }

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].movementType == MOVEMENT_TYPE_BERRY_TREE_GROWTH)
        {
            gSaveBlock1Ptr->berryTrees[GetObjectEventBerryTreeId(i)].weeds = TRUE;
        }
    }

    ScriptContext_Enable();
    Debug_DestroyMenu_Full(taskId);
}

// *******************************
// Actions Party/Boxes

static void DebugAction_Party_HealParty(u8 taskId)
{
    PlaySE(SE_USE_ITEM);
    HealPlayerParty();
    ScriptContext_Enable();
    Debug_DestroyMenu_Full(taskId);
}

void DebugNative_GetAbilityNames(void)
{
    enum Species species = GetMonData(&gParties[B_TRAINER_PLAYER][gSpecialVar_0x8004], MON_DATA_SPECIES);
    StringCopy(gStringVar1, gAbilitiesInfo[GetAbilityBySpecies(species, 0)].name);
    StringCopy(gStringVar2, gAbilitiesInfo[GetAbilityBySpecies(species, 1)].name);
    StringCopy(gStringVar3, gAbilitiesInfo[GetAbilityBySpecies(species, 2)].name);
}

#define tPartyId               data[6]

static void DebugNativeStep_InitAfterPartyMenu(u8 taskId)
{
    gTasks[taskId].tSubWindowId = DebugNativeStep_CreateDebugWindow();
    gTasks[taskId].tPartyId = gSpecialVar_0x8004;
}

static void DebugNativeStep_DelayedSelection(u8 taskId)
{
    DebugAction_Selection_Init(taskId, (void *)GetWordTaskArg(taskId, 14));
}

static void DebugSelectionStep_UpdateFriendship(u8 taskId, u8 digits, u32 min, u32 max)
{
    ConvertIntToDecimalStringN(gStringVar1, DebugSelection_GetData(taskId, 0), STR_CONV_MODE_LEADING_ZEROS, digits);
    ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, digits);
    StringExpandPlaceholders(gStringVar2, COMPOUND_STRING("{STR_VAR_1} {RIGHT_ARROW} {STR_VAR_3}"));
    StringCopy(gStringVar1, COMPOUND_STRING("Friendship:"));
    StringCopy(gStringVar3, COMPOUND_STRING(""));
    DebugNativeStep_PrintWindowSelection(taskId);
}

static void DebugSelection_SetFriendship_OnInit(u8 taskId)
{
    DebugNativeStep_InitAfterPartyMenu(taskId);
    DebugSelection_SetData(taskId, 0, GetMonData(&gParties[B_TRAINER_PLAYER][gTasks[taskId].tPartyId], MON_DATA_FRIENDSHIP));
}

static bool32 DebugSelection_SetFriendship_OnComplete(u8 taskId)
{
    u16 friendship = DebugSelection_GetData(taskId, 0);
    SetMonData(&gParties[B_TRAINER_PLAYER][gTasks[taskId].tPartyId], MON_DATA_FRIENDSHIP, &friendship);
    gTasks[taskId].func = DebugNativeStep_DelayedSelection;
    return TRUE;
}

static const struct DebugSelectionStep sFriendshipSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdateFriendship,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 0,
    .maxValue = MAX_FRIENDSHIP,
    .digits = 3
};

static const struct DebugSelection sFriendshipSelection = {
    .onInit = DebugSelection_SetFriendship_OnInit,
    .onCancel = DebugNativeStep_CloseDebugWindow,
    .onComplete = DebugSelection_SetFriendship_OnComplete,
    .steps = {&sFriendshipSelectionStep},
    .maxSteps = 1,
};

void DebugNative_Party_SetFriendship(void)
{
    if (gSpecialVar_0x8004 < PARTY_SIZE)
    {
        u32 taskId = CreateTask(DebugNativeStep_DelayedSelection, 1);
        SetWordTaskArg(taskId, DEBUG_SELECTION_PTR_ARG, (u32) &sFriendshipSelection);
    }
}

#undef tFriendship

static void DebugSelectionStep_UpdatePokerusStrain(u8 taskId, u8 digits, u32 min, u32 max)
{
    StringCopy(gStringVar1, COMPOUND_STRING("Strain:"));
    ConvertIntToDecimalStringN(gStringVar2, gTasks[taskId].tInput, STR_CONV_MODE_LEADING_ZEROS, digits);
    StringCopy(gStringVar3, COMPOUND_STRING(""));
    DebugNativeStep_PrintWindowSelection(taskId);
}

static void DebugSelectionStep_UpdatePokerusDaysLeft(u8 taskId, u8 digits, u32 min, u32 max)
{
    StringCopy(gStringVar1, COMPOUND_STRING("Days Left:"));
    s16 daysLeft = gTasks[taskId].tInput;
    u16 strain = DebugSelection_GetData(taskId, gTasks[taskId].tStepsDataIndex - 1);
    ConvertIntToDecimalStringN(gStringVar2, daysLeft, STR_CONV_MODE_LEADING_ZEROS, digits);

    if (daysLeft == 0 && strain == 0)
        StringCopy(gStringVar3, COMPOUND_STRING("No Pokerus"));
    else if (daysLeft == 0)
        StringCopy(gStringVar3, COMPOUND_STRING("Inactive"));
    else
        StringCopy(gStringVar3, COMPOUND_STRING(""));
    DebugNativeStep_PrintWindowSelection(taskId);
}

static void DebugSelection_SetPokerus_OnInit(u8 taskId)
{
    DebugNativeStep_InitAfterPartyMenu(taskId);
    DebugSelection_SetData(taskId, 0, GetMonData(&gParties[B_TRAINER_PLAYER][gTasks[taskId].tPartyId], MON_DATA_POKERUS_STRAIN));
    DebugSelection_SetData(taskId, 1, GetMonData(&gParties[B_TRAINER_PLAYER][gTasks[taskId].tPartyId], MON_DATA_POKERUS_DAYS_LEFT));
}

static bool32 DebugSelection_SetPokerus_OnComplete(u8 taskId)
{
    u16 strain = DebugSelection_GetData(taskId, 0);
    u16 daysLeft = DebugSelection_GetData(taskId, 1);
    SetMonData(&gParties[B_TRAINER_PLAYER][gTasks[taskId].tPartyId], MON_DATA_POKERUS_STRAIN, &strain);
    SetMonData(&gParties[B_TRAINER_PLAYER][gTasks[taskId].tPartyId], MON_DATA_POKERUS_DAYS_LEFT, &daysLeft);
    DebugNativeStep_CloseDebugWindow(taskId);
    return TRUE;
}

static const struct DebugSelectionStep sPokerusStrainSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdatePokerusStrain,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 0,
    .maxValue = 15,
    .digits = 2
};

static const struct DebugSelectionStep sPokerusDaysLeftSelectionStep = {
    .stepUpdate = DebugSelectionStep_UpdatePokerusDaysLeft,
    .stepConfirm = DebugSelectionStep_GenericInputConfirm,
    .minValue = 0,
    .maxValue = 15,
    .digits = 2
};

static const struct DebugSelection sPokerusSelection = {
    .onInit = DebugSelection_SetPokerus_OnInit,
    .onCancel = DebugNativeStep_CloseDebugWindow,
    .onComplete = DebugSelection_SetPokerus_OnComplete,
    .steps = {&sPokerusStrainSelectionStep, &sPokerusDaysLeftSelectionStep},
    .maxSteps = 2,
};

void DebugNative_Party_SetPokerus(void)
{
    if (gSpecialVar_0x8004 < PARTY_SIZE)
    {
        u32 taskId = CreateTask(DebugNativeStep_DelayedSelection, 1);
        SetWordTaskArg(taskId, DEBUG_SELECTION_PTR_ARG, (u32) &sPokerusSelection);
    }
}

#undef tStrain
#undef tPartyId

#undef tMenuTaskId
#undef tWindowId
#undef tSubWindowId
#undef tInput
#undef tDigit

static void DebugAction_Party_ClearPokerus(u8 taskId)
{
    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        if (!GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES))
            continue;
        u32 data = 0;
        SetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS, &data);
    }
    ScriptContext_Enable();
    Debug_DestroyMenu_Full(taskId);
}

static void DebugAction_Party_ClearParty(u8 taskId)
{
    ZeroPlayerPartyMons();
    ScriptContext_Enable();
    Debug_DestroyMenu_Full(taskId);
}

enum DebugTrainerIds
{
    DEBUG_TRAINER_PLAYER,
    DEBUG_TRAINER_AI,
    DEBUG_TRAINERS_COUNT
};

const struct Trainer sDebugTrainers[DIFFICULTY_COUNT][DEBUG_TRAINERS_COUNT] =
{
#include "data/debug_trainers.h"
};

const struct Trainer* GetDebugAiTrainer(void)
{
    return &sDebugTrainers[DIFFICULTY_NORMAL][DEBUG_TRAINER_AI];
}

static void DebugAction_Party_SetParty(u8 taskId)
{
    ZeroPlayerPartyMons();
    CreateNPCTrainerPartyFromTrainer(gParties[B_TRAINER_PLAYER], &sDebugTrainers[DIFFICULTY_NORMAL][DEBUG_TRAINER_PLAYER]);
    ScriptContext_Enable();
    Debug_DestroyMenu_Full(taskId);
}

static void DebugAction_Party_BattleSingle(u8 taskId)
{
    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();

    CreateNPCTrainerPartyFromTrainer(gParties[B_TRAINER_PLAYER], &sDebugTrainers[DIFFICULTY_NORMAL][DEBUG_TRAINER_PLAYER]);
    CreateNPCTrainerPartyFromTrainer(gParties[B_TRAINER_OPPONENT_A], GetDebugAiTrainer());

    gBattleTypeFlags = BATTLE_TYPE_TRAINER;
    if (sDebugTrainers[DIFFICULTY_NORMAL][DEBUG_TRAINER_AI].battleType == TRAINER_BATTLE_TYPE_DOUBLES)
        gBattleTypeFlags |= BATTLE_TYPE_DOUBLE;
    gDebugAIFlags = sDebugTrainers[DIFFICULTY_NORMAL][DEBUG_TRAINER_AI].aiFlags;
    gIsDebugBattle = TRUE;
    gBattleEnvironment = BattleSetup_GetEnvironmentId();
    CalculateEnemyPartyCount();
    BattleSetup_StartTrainerBattle_Debug();
    Debug_DestroyMenu_Full(taskId);
}

void CheckEWRAMCounters(struct ScriptContext *ctx)
{
    ConvertIntToDecimalStringN(gStringVar1, gFollowerSteps, STR_CONV_MODE_LEFT_ALIGN, 5);
    ConvertIntToDecimalStringN(gStringVar2, gChainFishingDexNavStreak, STR_CONV_MODE_LEFT_ALIGN, 5);
}
