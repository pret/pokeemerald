#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "scanline_effect.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon_icon.h"
#include "sprite.h"
#include "item.h"
#include "task.h"
#include "bg.h"
#include "gpu_regs.h"
#include "window.h"
#include "text.h"
#include "text_window.h"
#include "international_string_util.h"
#include "strings.h"
#include "battle_ai_util.h"
#include "list_menu.h"
#include "decompress.h"
#include "trainer_pokemon_sprites.h"
#include "malloc.h"
#include "string_util.h"
#include "util.h"
#include "data.h"
#include "reset_rtc_screen.h"
#include "reshow_battle_screen.h"
#include "constants/abilities.h"
#include "constants/party_menu.h"
#include "constants/moves.h"
#include "constants/items.h"
#include "constants/rgb.h"

#define MAX_MODIFY_DIGITS 4

struct BattleDebugModifyArrows
{
    u8 arrowSpriteId[2];
    u16 minValue;
    u16 maxValue;
    int currValue;
    u8 currentDigit:4;
    u8 maxDigits:4;
    u8 charDigits[MAX_MODIFY_DIGITS];
    void *modifiedValPtr;
    u8 typeOfVal;
};

struct BattleDebugMenu
{
    enum BattlerId battlerId:3;
    enum BattlerId aiBattlerId:3;

    u8 battlerWindowId;

    u8 mainListWindowId;
    u8 mainListTaskId;
    u8 currentMainListItemId;

    u8 secondaryListWindowId;
    u8 secondaryListTaskId;
    u8 currentSecondaryListItemId;
    u8 secondaryListItemCount;

    u8 modifyWindowId;

    u8 activeWindow;

    struct BattleDebugModifyArrows modifyArrows;
    const struct BitfieldInfo *bitfield;
    bool8 battlerWasChanged[MAX_BATTLERS_COUNT];

    u8 aiViewState;

    u8 aiMonSpriteId;
    u8 aiMovesWindowId;

    union
    {
        u8 aiIconSpriteIds[MAX_BATTLERS_COUNT];
        u8 aiPartyIcons[PARTY_SIZE];
    } spriteIds;
};

struct __attribute__((__packed__)) BitfieldInfo
{
    u8 bitsCount;
    u8 currBit;
};

enum
{
    LIST_ITEM_MOVES,
    LIST_ITEM_ABILITY,
    LIST_ITEM_HELD_ITEM,
    LIST_ITEM_PP,
    LIST_ITEM_TYPES,
    LIST_ITEM_STATS,
    LIST_ITEM_STAT_STAGES,
    LIST_ITEM_STATUS1,
    LIST_ITEM_VOLATILE,
    LIST_ITEM_HAZARDS,
    LIST_ITEM_SIDE_STATUS,
    LIST_ITEM_AI,
    LIST_ITEM_AI_MOVES_PTS,
    LIST_ITEM_AI_INFO,
    LIST_ITEM_AI_PARTY,
    LIST_ITEM_VARIOUS,
    LIST_ITEM_INSTANT_WIN,
    LIST_ITEM_COUNT
};

enum
{
    LIST_STAT_HP_CURRENT,
    LIST_STAT_HP_MAX,
    LIST_STAT_ATTACK,
    LIST_STAT_DEFENSE,
    LIST_STAT_SPEED,
    LIST_STAT_SP_ATK,
    LIST_STAT_SP_DEF,
};

enum
{
    LIST_STATUS1_SLEEP,
    LIST_STATUS1_POISON,
    LIST_STATUS1_BURN,
    LIST_STATUS1_FREEZE,
    LIST_STATUS1_PARALYSIS,
    LIST_STATUS1_TOXIC_POISON,
    LIST_STATUS1_TOXIC_COUNTER,
    LIST_STATUS1_FROSTBITE,
};

enum
{
    LIST_SIDE_STICKY_WEB,
    LIST_SIDE_SPIKES,
    LIST_SIDE_TOXIC_SPIKES,
    LIST_SIDE_STEALTH_ROCK,
    LIST_SIDE_STEELSURGE,
};

enum
{
    LIST_SIDE_REFLECT,
    LIST_SIDE_LIGHTSCREEN,
    LIST_SIDE_SAFEGUARD,
    LIST_SIDE_MIST,
    LIST_SIDE_TAILWIND,
    LIST_SIDE_AURORA_VEIL,
    LIST_SIDE_LUCKY_CHANT,
    LIST_SIDE_DAMAGE_NON_TYPES,
    LIST_SIDE_RAINBOW,
    LIST_SIDE_SEA_OF_FIRE,
    LIST_SIDE_SWAMP,
};

enum
{
    LIST_AI_CHECK_BAD_MOVE,
    LIST_AI_TRY_TO_FAINT,
    LIST_AI_CHECK_VIABILITY,
    LIST_AI_FORCE_SETUP_FIRST_TURN,
    LIST_AI_RISKY,
    LIST_AI_TRY_TO_2HKO,
    LIST_AI_PREFER_BATON_PASS,
    LIST_AI_DOUBLE_BATTLE,
    LIST_AI_HP_AWARE,
    LIST_AI_POWERFUL_STATUS,
    LIST_AI_NEGATE_UNAWARE,
    LIST_AI_WILL_SUICIDE,
    LIST_AI_PREFER_STATUS_MOVES,
    LIST_AI_STALL,
    LIST_AI_SMART_SWITCHING,
    LIST_AI_ACE_POKEMON,
    LIST_AI_OMNISCIENT,
    LIST_AI_SMART_MON_CHOICES,
    LIST_AI_CONSERVATIVE,
    LIST_AI_SEQUENCE_SWITCHING,
    LIST_AI_DOUBLE_ACE_POKEMON,
    LIST_AI_WEIGH_ABILITY_PREDICTION,
    LIST_AI_PREFER_HIGHEST_DAMAGE_MOVE,
    LIST_AI_PREDICT_SWITCH,
    LIST_AI_PREDICT_INCOMING_MON,
    LIST_AI_DYNAMIC_FUNC,
    LIST_AI_ROAMING,
    LIST_AI_SAFARI,
    LIST_AI_FIRST_BATTLE,
};

enum
{
    VARIOUS_SHOW_HP,
    VARIOUS_SUBSTITUTE_HP,
    VARIOUS_IN_LOVE,
};

enum
{
    ACTIVE_WIN_MAIN,
    ACTIVE_WIN_SECONDARY,
    ACTIVE_WIN_MODIFY
};

enum
{
    VAL_U8,
    VAL_U16,
    VAL_U32,
    VAL_BITFIELD_8,
    VAL_BITFIELD_16,
    VAL_BITFIELD_32,
    VAL_VOLATILE,
    VAL_HAZARDS,
    VAR_SIDE_STATUS,
    VAR_SHOW_HP,
    VAR_SUBSTITUTE,
    VAR_IN_LOVE,
    VAR_U16_4_ENTRIES,
    VAL_S8,
    VAL_ALL_STAT_STAGES,
};

// Static Declarations
static const u8 *GetHoldEffectName(enum HoldEffect holdEffect);

// const rom data
static const u8 sText_Ability[] = _("Ability");
static const u8 sText_HeldItem[] = _("Held Item");
static const u8 sText_HoldEffect[] = _("Hold Effect");
static const u8 sText_EmptyString[] = _("");

static const struct BitfieldInfo sStatus1Bitfield[] =
{
    {/*Sleep*/ 3, 0},
    {/*Poison*/ 1, 3},
    {/*Burn*/ 1, 4},
    {/*Freeze*/ 1, 5},
    {/*Paralysis*/1, 6},
    {/*Toxic Poison*/ 1, 7},
    {/*Toxic Counter*/ 4, 8},
    {/*Frostbite*/ 1, 12},
};

static const struct BitfieldInfo sStatus3Bitfield[] =
{
    {/*Leech Seed Battler*/ 2, 0},
    {/*Leech Seed*/ 1, 2},
    {/*Always Hits*/ 2, 3},
    {/*Perish Song*/ 1, 5},
    {/*On Air*/ 1, 6},
    {/*Underground*/ 1, 7},
    {/*Minimized*/ 1, 8},
    {/*Charged Up*/ 1, 9},
    {/*Rooted*/ 1, 10},
    {/*Yawn*/ 2, 11},
    {/*Imprisoned Others*/ 1, 13},
    {/*Grudge*/ 1, 14},
    {/*Gastro Acid*/ 1, 16},
    {/*Embargo*/ 1, 17},
    {/*Underwater*/ 1, 18},
    {/*Smacked Down*/ 1, 21},
    {/*Telekinesis*/ 1, 23},
    {/*Miracle Eyed*/ 1, 25},
    {/*Magnet Rise*/ 1, 26},
    {/*Heal Blocked*/ 1, 27},
    {/*Aqua Ring*/ 1, 28},
    {/*Laser Focus*/ 1, 29},
    {/*Power Trick*/ 1, 30},
};

static const struct BitfieldInfo sAIBitfield[] =
{
    {/*Check Bad Move*/ 1, 0},
    {/*Try to Faint*/ 1, 1},
    {/*Check Viability*/ 1, 2},
    {/*Force Setup First Turn*/ 1, 3},
    {/*Risky*/ 1, 4},
    {/*Prefer Strongest Move*/ 1, 5},
    {/*Prefer Baton Pass*/ 1, 6},
    {/*Double Battle*/ 1, 7},
    {/*HP Aware*/ 1, 8},
    {/*Powerful Status*/ 1, 9},
    {/*Negate Unaware*/ 1, 10},
    {/*Will Suicide*/ 1, 11},
    {/*Prefer Status Moves*/ 1, 12},
    {/*Stall*/ 1, 13},
    {/*Smart Switching*/ 1, 14},
    {/*Ace Pokemon*/ 1, 15},
    {/*Omniscient*/ 1, 16},
    {/*Smart Mon Choices*/ 1, 17},
    {/*Conservative*/ 1, 18},
    {/*Sequence Switching*/ 1, 19},
    {/*Double Ace Pokemon*/ 1, 20},
    {/*Weigh Ability Prediction*/ 1, 21},
    {/*Prefer Highest Damage Move*/ 1, 22},
    {/*Predict Switch*/ 1, 23},
    {/*Predict Incoming Mon*/ 1, 24},
    {/*Dynamic Func*/ 1, 28},
    {/*Roaming*/ 1, 29},
    {/*Safari*/ 1, 30},
    {/*First Battle*/ 1, 31},
};

static const struct ListMenuItem sMainListItems[] =
{
    {COMPOUND_STRING("Moves"),        LIST_ITEM_MOVES},
    {sText_Ability,                   LIST_ITEM_ABILITY},
    {sText_HeldItem,                  LIST_ITEM_HELD_ITEM},
    {COMPOUND_STRING("PP"),           LIST_ITEM_PP},
    {COMPOUND_STRING("Types"),        LIST_ITEM_TYPES},
    {COMPOUND_STRING("Stats"),        LIST_ITEM_STATS},
    {COMPOUND_STRING("Stat Stages"),  LIST_ITEM_STAT_STAGES},
    {COMPOUND_STRING("Status1"),      LIST_ITEM_STATUS1},
    {COMPOUND_STRING("Volatiles"),    LIST_ITEM_VOLATILE},
    {COMPOUND_STRING("Hazards"),      LIST_ITEM_HAZARDS},
    {COMPOUND_STRING("Side Status"),  LIST_ITEM_SIDE_STATUS},
    {COMPOUND_STRING("AI"),           LIST_ITEM_AI},
    {COMPOUND_STRING("AI Pts/Dmg"),   LIST_ITEM_AI_MOVES_PTS},
    {COMPOUND_STRING("AI Info"),      LIST_ITEM_AI_INFO},
    {COMPOUND_STRING("AI Party"),     LIST_ITEM_AI_PARTY},
    {COMPOUND_STRING("Various"),      LIST_ITEM_VARIOUS},
    {COMPOUND_STRING("Instant Win"),  LIST_ITEM_INSTANT_WIN},
};

static const struct ListMenuItem sStatsListItems[] =
{
    {COMPOUND_STRING("HP Current"), LIST_STAT_HP_CURRENT},
    {COMPOUND_STRING("HP Max"),     LIST_STAT_HP_MAX},
    {COMPOUND_STRING("Attack"),     LIST_STAT_ATTACK},
    {COMPOUND_STRING("Defense"),    LIST_STAT_DEFENSE},
    {COMPOUND_STRING("Speed"),      LIST_STAT_SPEED},
    {COMPOUND_STRING("Sp. Atk"),    LIST_STAT_SP_ATK},
    {COMPOUND_STRING("Sp. Def"),    LIST_STAT_SP_DEF},
};

static const struct ListMenuItem sStatus1ListItems[] =
{
    {COMPOUND_STRING("Sleep"),         LIST_STATUS1_SLEEP},
    {COMPOUND_STRING("Poison"),        LIST_STATUS1_POISON},
    {COMPOUND_STRING("Burn"),          LIST_STATUS1_BURN},
    {COMPOUND_STRING("Freeze"),        LIST_STATUS1_FREEZE},
    {COMPOUND_STRING("Paralysis"),     LIST_STATUS1_PARALYSIS},
    {COMPOUND_STRING("Toxic Poison"),  LIST_STATUS1_TOXIC_POISON},
    {COMPOUND_STRING("Toxic Counter"), LIST_STATUS1_TOXIC_COUNTER},
    {COMPOUND_STRING("Frostbite"),     LIST_STATUS1_FROSTBITE},
};

static const struct ListMenuItem sVolatileStatusListItems[] =
{
    {COMPOUND_STRING("Confusion"),          VOLATILE_CONFUSION},
    {COMPOUND_STRING("Flinched"),           VOLATILE_FLINCHED},
    {COMPOUND_STRING("Torment"),            VOLATILE_TORMENT},
    {COMPOUND_STRING("Powder"),             VOLATILE_POWDER},
    {COMPOUND_STRING("DefenseCurl"),        VOLATILE_DEFENSE_CURL},
    {COMPOUND_STRING("Rage"),               VOLATILE_RAGE},
    {COMPOUND_STRING("DestinyBond"),        VOLATILE_DESTINY_BOND},
    {COMPOUND_STRING("EscapePrevention"),   VOLATILE_ESCAPE_PREVENTION},
    {COMPOUND_STRING("Cursed"),             VOLATILE_CURSED},
    {COMPOUND_STRING("Foresight"),          VOLATILE_FORESIGHT},
    {COMPOUND_STRING("DragonCheer"),        VOLATILE_DRAGON_CHEER},
    {COMPOUND_STRING("FocusEnergy"),        VOLATILE_FOCUS_ENERGY},
    {COMPOUND_STRING("Electrified"),        VOLATILE_ELECTRIFIED},
    {COMPOUND_STRING("MudSport"),           VOLATILE_MUD_SPORT},
    {COMPOUND_STRING("WaterSport"),         VOLATILE_WATER_SPORT},
    {COMPOUND_STRING("Salt Cure"),          VOLATILE_SALT_CURE},
    {COMPOUND_STRING("Syrup Bomb"),         VOLATILE_SYRUP_BOMB},
    {COMPOUND_STRING("Glaive Rush"),        VOLATILE_GLAIVE_RUSH},
    {COMPOUND_STRING("Leech Seed"),         VOLATILE_LEECH_SEED},
    {COMPOUND_STRING("Lock On"),            VOLATILE_LOCK_ON},
    {COMPOUND_STRING("Perish Song"),        VOLATILE_PERISH_SONG},
    {COMPOUND_STRING("Minimize"),           VOLATILE_MINIMIZE},
    {COMPOUND_STRING("Charge"),             VOLATILE_CHARGE_TIMER},
    {COMPOUND_STRING("Root"),               VOLATILE_ROOT},
    {COMPOUND_STRING("Yawn"),               VOLATILE_YAWN},
    {COMPOUND_STRING("Imprison"),           VOLATILE_IMPRISON},
    {COMPOUND_STRING("Grudge"),             VOLATILE_GRUDGE},
    {COMPOUND_STRING("Gastro Acid"),        VOLATILE_GASTRO_ACID},
    {COMPOUND_STRING("Embargo"),            VOLATILE_EMBARGO_TIMER},
    {COMPOUND_STRING("Smack Down"),         VOLATILE_SMACK_DOWN},
    {COMPOUND_STRING("Telekinesis"),        VOLATILE_TELEKINESIS},
    {COMPOUND_STRING("Miracle Eye"),        VOLATILE_MIRACLE_EYE},
    {COMPOUND_STRING("Heal Block"),         VOLATILE_HEAL_BLOCK_TIMER},
    {COMPOUND_STRING("Aqua Ring"),          VOLATILE_AQUA_RING},
    {COMPOUND_STRING("Power Trick"),        VOLATILE_POWER_TRICK},
};

static const struct ListMenuItem sHazardsListItems[] =
{
    {COMPOUND_STRING("Spikes"),       LIST_SIDE_SPIKES},
    {COMPOUND_STRING("Sticky Web"),   LIST_SIDE_STICKY_WEB},
    {COMPOUND_STRING("Toxic Spikes"), LIST_SIDE_TOXIC_SPIKES},
    {COMPOUND_STRING("Stealth Rock"), LIST_SIDE_STEALTH_ROCK},
    {COMPOUND_STRING("Steelsurge"),   LIST_SIDE_STEELSURGE},
};

static const struct ListMenuItem sSideStatusListItems[] =
{
    {COMPOUND_STRING("Reflect"),          LIST_SIDE_REFLECT},
    {COMPOUND_STRING("Light Screen"),     LIST_SIDE_LIGHTSCREEN},
    {COMPOUND_STRING("Safeguard"),        LIST_SIDE_SAFEGUARD},
    {COMPOUND_STRING("Mist"),             LIST_SIDE_MIST},
    {COMPOUND_STRING("Tailwind"),         LIST_SIDE_TAILWIND},
    {COMPOUND_STRING("Aurora Veil"),      LIST_SIDE_AURORA_VEIL},
    {COMPOUND_STRING("Lucky Chant"),      LIST_SIDE_LUCKY_CHANT},
    {COMPOUND_STRING("Damage Non-Types"), LIST_SIDE_DAMAGE_NON_TYPES},
    {COMPOUND_STRING("Rainbow"),          LIST_SIDE_RAINBOW},
    {COMPOUND_STRING("Sea of Fire"),      LIST_SIDE_SEA_OF_FIRE},
    {COMPOUND_STRING("Swamp"),            LIST_SIDE_SWAMP},
};

static const struct ListMenuItem sAIListItems[] =
{
    {COMPOUND_STRING("Check Bad Move"),             LIST_AI_CHECK_BAD_MOVE},
    {COMPOUND_STRING("Try to Faint"),               LIST_AI_TRY_TO_FAINT},
    {COMPOUND_STRING("Check Viability"),            LIST_AI_CHECK_VIABILITY},
    {COMPOUND_STRING("Force Setup First Turn"),     LIST_AI_FORCE_SETUP_FIRST_TURN},
    {COMPOUND_STRING("Risky"),                      LIST_AI_RISKY},
    {COMPOUND_STRING("Try to 2HKO"),                LIST_AI_TRY_TO_2HKO},
    {COMPOUND_STRING("Prefer Baton Pass"),          LIST_AI_PREFER_BATON_PASS},
    {COMPOUND_STRING("Double Battle"),              LIST_AI_DOUBLE_BATTLE},
    {COMPOUND_STRING("HP Aware"),                   LIST_AI_HP_AWARE},
    {COMPOUND_STRING("Powerful Status"),            LIST_AI_POWERFUL_STATUS},
    {COMPOUND_STRING("Negate Unaware"),             LIST_AI_NEGATE_UNAWARE},
    {COMPOUND_STRING("Will Suicide"),               LIST_AI_WILL_SUICIDE},
    {COMPOUND_STRING("Prefer Status Moves"),        LIST_AI_PREFER_STATUS_MOVES},
    {COMPOUND_STRING("Stall"),                      LIST_AI_STALL},
    {COMPOUND_STRING("Smart Switching"),            LIST_AI_SMART_SWITCHING},
    {COMPOUND_STRING("Ace Pokémon"),                LIST_AI_ACE_POKEMON},
    {COMPOUND_STRING("Omniscient"),                 LIST_AI_OMNISCIENT},
    {COMPOUND_STRING("Smart Mon Choices"),          LIST_AI_SMART_MON_CHOICES},
    {COMPOUND_STRING("Conservative"),               LIST_AI_CONSERVATIVE},
    {COMPOUND_STRING("Sequence Switching"),         LIST_AI_SEQUENCE_SWITCHING},
    {COMPOUND_STRING("Double Ace Pokémon"),         LIST_AI_DOUBLE_ACE_POKEMON},
    {COMPOUND_STRING("Weigh Ability Prediction"),   LIST_AI_WEIGH_ABILITY_PREDICTION},
    {COMPOUND_STRING("Prefer Highest Damage Move"), LIST_AI_PREFER_HIGHEST_DAMAGE_MOVE},
    {COMPOUND_STRING("Predict Switch"),             LIST_AI_PREDICT_SWITCH},
    {COMPOUND_STRING("Predict Incoming Mon"),       LIST_AI_PREDICT_INCOMING_MON},
    {COMPOUND_STRING("Dynamic Func"),               LIST_AI_DYNAMIC_FUNC},
    {COMPOUND_STRING("Roaming"),                    LIST_AI_ROAMING},
    {COMPOUND_STRING("Safari"),                     LIST_AI_SAFARI},
    {COMPOUND_STRING("First Battle"),               LIST_AI_FIRST_BATTLE},
};

static const struct ListMenuItem sVariousListItems[] =
{
    {COMPOUND_STRING("Show HP"),       VARIOUS_SHOW_HP},
    {COMPOUND_STRING("Substitute HP"), VARIOUS_SUBSTITUTE_HP},
    {COMPOUND_STRING("In Love"),       VARIOUS_IN_LOVE},
};

static const struct ListMenuItem sSecondaryListItems[] =
{
    {sText_EmptyString, 0},
    {sText_EmptyString, 1},
    {sText_EmptyString, 2},
    {sText_EmptyString, 3},
    {sText_EmptyString, 4},
    {sText_EmptyString, 5},
    {sText_EmptyString, 6},
    {sText_EmptyString, 7},
    {sText_EmptyString, 8},
};


static const struct ListMenuTemplate sMainListTemplate =
{
    .items = sMainListItems,
    .moveCursorFunc = NULL,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sMainListItems),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = 1,
    .cursorKind = 0
};

static const struct ListMenuTemplate sSecondaryListTemplate =
{
    .items = sSecondaryListItems,
    .moveCursorFunc = NULL,
    .itemPrintFunc = NULL,
    .totalItems = 0,
    .maxShowed = 0,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = 1,
    .cursorKind = 0
};


static const struct WindowTemplate sMainListWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 9,
    .height = 12,
    .paletteNum = 0xF,
    .baseBlock = 0x1
};

static const struct WindowTemplate sSecondaryListWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 12,
    .tilemapTop = 3,
    .width = 20,
    .height = 16,
    .paletteNum = 0xF,
    .baseBlock = 0x6D
};

static const struct WindowTemplate sModifyWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 25,
    .tilemapTop = 2,
    .width = 4,
    .height = 2,
    .paletteNum = 0xF,
    .baseBlock = 0x1AD
};

static const struct WindowTemplate sBattlerWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 10,
    .tilemapTop = 0,
    .width = 14,
    .height = 2,
    .paletteNum = 0xF,
    .baseBlock = 0x1B5
};

static const struct BgTemplate sBgTemplates[] =
{
   {
       .bg = 0,
       .charBaseIndex = 0,
       .mapBaseIndex = 31,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 1,
       .baseTile = 0
   },
   {
       .bg = 1,
       .charBaseIndex = 2,
       .mapBaseIndex = 20,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 0,
       .baseTile = 0
   }
};

static const bool8 sHasChangeableEntries[LIST_ITEM_COUNT] =
{
    [LIST_ITEM_MOVES] = TRUE,
    [LIST_ITEM_AI_MOVES_PTS] = TRUE,
    [LIST_ITEM_PP] = TRUE,
    [LIST_ITEM_ABILITY] = TRUE,
    [LIST_ITEM_TYPES] = TRUE,
    [LIST_ITEM_HELD_ITEM] = TRUE,
    [LIST_ITEM_STAT_STAGES] = TRUE,
};

static const u16 sBgColor[] = {RGB_WHITE};

// this file's functions
static void Task_DebugMenuFadeOut(u8 taskId);
static void Task_DebugMenuProcessInput(u8 taskId);
static void Task_DebugMenuFadeIn(u8 taskId);
static void PrintOnBattlerWindow(u8 windowId, enum BattlerId battler);
static void UpdateWindowsOnChangedBattler(struct BattleDebugMenu *data);
static void CreateSecondaryListMenu(struct BattleDebugMenu *data);
static void PrintSecondaryEntries(struct BattleDebugMenu *data);
static void DestroyModifyArrows(struct BattleDebugMenu *data);
static void PrintDigitChars(struct BattleDebugMenu *data);
static void SetUpModifyArrows(struct BattleDebugMenu *data);
static void UpdateBattlerValue(struct BattleDebugMenu *data);
static void UpdateMonData(struct BattleDebugMenu *data);
static void ChangeHazardsValue(struct BattleDebugMenu *data);
static u32 GetHazardsValue(struct BattleDebugMenu *data);
static u16 *GetSideStatusValue(struct BattleDebugMenu *data, bool32 changeStatus, bool32 statusTrue);
static bool32 TryMoveDigit(struct BattleDebugModifyArrows *modArrows, bool32 moveUp);
static void SwitchToDebugView(u8 taskId);
static void SwitchToDebugViewFromAiParty(u8 taskId);

// code
static struct BattleDebugMenu *GetStructPtr(u8 taskId)
{
    u8 *taskDataPtr = (u8 *)(&gTasks[taskId].data[0]);

    return (struct BattleDebugMenu*)(T1_READ_PTR(taskDataPtr));
}

static void SetStructPtr(u8 taskId, void *ptr)
{
    u32 structPtr = (u32)(ptr);
    u8 *taskDataPtr = (u8 *)(&gTasks[taskId].data[0]);

    taskDataPtr[0] = structPtr >> 0;
    taskDataPtr[1] = structPtr >> 8;
    taskDataPtr[2] = structPtr >> 16;
    taskDataPtr[3] = structPtr >> 24;
}

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_BattleDebugMenu(void)
{
    u8 taskId;
    struct BattleDebugMenu *data;

    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        gMain.state++;
        break;
    case 1:
        ResetVramOamAndBgCntRegs();
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        ResetAllBgsCoordinates();
        CloseMainBattleScreen();
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        gMain.state++;
        break;
    case 3:
        LoadPalette(sBgColor, BG_PLTT_ID(0), 2);
        LoadPalette(GetOverworldTextboxPalettePtr(), BG_PLTT_ID(15), PLTT_SIZEOF(8));
        gMain.state++;
        break;
    case 4:
        taskId = CreateTask(Task_DebugMenuFadeIn, 0);
        data = AllocZeroed(sizeof(struct BattleDebugMenu));
        SetStructPtr(taskId, data);

        data->battlerId = gBattleStruct->debugBattler;
        data->battlerWindowId = AddWindow(&sBattlerWindowTemplate);
        PutWindowTilemap(data->battlerWindowId);
        PrintOnBattlerWindow(data->battlerWindowId, data->battlerId);

        data->mainListWindowId = AddWindow(&sMainListWindowTemplate);

        gMultiuseListMenuTemplate = sMainListTemplate;
        gMultiuseListMenuTemplate.windowId = data->mainListWindowId;
        data->mainListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);

        data->currentMainListItemId = 0;
        data->activeWindow = ACTIVE_WIN_MAIN;
        data->secondaryListTaskId = 0xFF;
        CopyWindowToVram(data->mainListWindowId, COPYWIN_FULL);
        gMain.state++;
        break;
    case 5:
        BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        return;
    }
}

enum {
    COLORID_RED,
};

static const u8 sTextColorTable[][3] =
{
    [COLORID_RED]        = {TEXT_COLOR_WHITE,       TEXT_COLOR_RED,        TEXT_COLOR_LIGHT_RED},
};

static void PutMovesPointsText(struct BattleDebugMenu *data)
{
    u32 chosenMoveIndex = gAiBattleData->chosenMoveIndex[data->aiBattlerId];
    u8 *text = Alloc(0x50);

    FillWindowPixelBuffer(data->aiMovesWindowId, 0x11);
    AddTextPrinterParameterized(data->aiMovesWindowId, FONT_NORMAL, COMPOUND_STRING("Score/Dmg"), 3, 0, 0, NULL);
    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        text[0] = CHAR_SPACE;
        StringCopy(text + 1, GetMoveName(gBattleMons[data->aiBattlerId].moves[moveIndex]));
        AddTextPrinterParameterized(data->aiMovesWindowId, FONT_NORMAL, text, 0, (moveIndex * 15) + 15, 0, NULL);
        for (u32 count = 0, battler = 0; battler < MAX_BATTLERS_COUNT; battler++)
        {
            if (data->spriteIds.aiIconSpriteIds[battler] == 0xFF)
                continue;
            u32 battlerDef = gSprites[data->spriteIds.aiIconSpriteIds[battler]].data[0];
            ConvertIntToDecimalStringN(text,
                                       gAiBattleData->finalScore[data->aiBattlerId][battlerDef][moveIndex],
                                       STR_CONV_MODE_RIGHT_ALIGN, 3);
            // If chosen move and chosen target
            if ((chosenMoveIndex == moveIndex) && (gAiBattleData->chosenTarget[data->aiBattlerId] == battlerDef) && !(gAiLogicData->shouldSwitch & (1u << data->aiBattlerId)))
                AddTextPrinterParameterized3(data->aiMovesWindowId, FONT_NORMAL, 84 + count * 54, (moveIndex * 15) + 15, sTextColorTable[COLORID_RED], 0, text);
            else
                AddTextPrinterParameterized(data->aiMovesWindowId, FONT_NORMAL, text, 84 + count * 54, (moveIndex * 15) + 15, 0, NULL);

            if ((chosenMoveIndex == moveIndex) && (gAiBattleData->chosenTarget[data->aiBattlerId] == battlerDef) && !(gAiLogicData->shouldSwitch & (1u << data->aiBattlerId)))
                AddTextPrinterParameterized3(data->aiMovesWindowId, FONT_NORMAL, 103 + count * 54, (moveIndex * 15) + 15, sTextColorTable[COLORID_RED], 0, COMPOUND_STRING("/"));
            else
                AddTextPrinterParameterized(data->aiMovesWindowId, FONT_NORMAL, COMPOUND_STRING("/"), 103 + count * 54, (moveIndex * 15) + 15, 0, NULL);

            ConvertIntToDecimalStringN(text,
                                       AI_GetDamage(data->aiBattlerId, battlerDef, moveIndex, AI_ATTACKING, gAiLogicData),
                                       STR_CONV_MODE_LEADING_ZEROS, 3);
            if ((chosenMoveIndex == moveIndex) && (gAiBattleData->chosenTarget[data->aiBattlerId] == battlerDef) && !(gAiLogicData->shouldSwitch & (1u << data->aiBattlerId)))
                AddTextPrinterParameterized3(data->aiMovesWindowId, FONT_NORMAL, 110 + count * 54, (moveIndex * 15) + 15, sTextColorTable[COLORID_RED], 0, text);
            else
                AddTextPrinterParameterized(data->aiMovesWindowId, FONT_NORMAL, text, 110 + count * 54, (moveIndex * 15) + 15, 0, NULL);

            count++;
        }
    }

    if (gAiLogicData->shouldSwitch & (1u << data->aiBattlerId))
    {
        struct Pokemon *party = GetBattlerParty(data->aiBattlerId);
        enum Species switchMon = GetMonData(&party[gAiLogicData->mostSuitableMonId[data->aiBattlerId]], MON_DATA_SPECIES);
        AddTextPrinterParameterized3(data->aiMovesWindowId, FONT_NORMAL, 74, 79, sTextColorTable[COLORID_RED], 0, COMPOUND_STRING("Switching to "));
        AddTextPrinterParameterized3(data->aiMovesWindowId, FONT_NORMAL, 74 + 68, 79, sTextColorTable[COLORID_RED], 0, gSpeciesInfo[switchMon].speciesName);
    }

    CopyWindowToVram(data->aiMovesWindowId, COPYWIN_FULL);
    Free(text);
}

static void CleanUpAiInfoWindow(u8 taskId)
{
    u32 i;
    struct BattleDebugMenu *data = GetStructPtr(taskId);

    FreeMonIconPalettes();
    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        if (data->spriteIds.aiIconSpriteIds[i] != 0xFF)
            FreeAndDestroyMonIconSprite(&gSprites[data->spriteIds.aiIconSpriteIds[i]]);
    }
    FreeAndDestroyMonPicSprite(data->aiMonSpriteId);
    ClearWindowTilemap(data->aiMovesWindowId);
    RemoveWindow(data->aiMovesWindowId);
}

static void Task_ShowAiPoints(u8 taskId)
{
    u32 i, count;
    struct WindowTemplate winTemplate;
    struct BattleDebugMenu *data = GetStructPtr(taskId);
    struct Pokemon *mon;

    switch (data->aiViewState)
    {
    case 0:
        HideBg(0);
        ShowBg(1);

        // Swap battler if it's player mon
        data->aiBattlerId = data->battlerId;
        while (!BattlerHasAi(data->aiBattlerId))
        {
            if (++data->aiBattlerId >= gBattlersCount)
                data->aiBattlerId = 0;
        }
        data->battlerId = data->aiBattlerId;

        LoadMonIconPalettes();
        for (count = 0, i = 0; i < MAX_BATTLERS_COUNT; i++)
        {
            if (i != data->aiBattlerId && IsBattlerAlive(i))
            {
                data->spriteIds.aiIconSpriteIds[i] = CreateMonIcon(gBattleMons[i].species,
                                                         SpriteCallbackDummy,
                                                         106 + (count * 54), 17, 0, 0);
                gSprites[data->spriteIds.aiIconSpriteIds[i]].data[0] = i; // battler id
                count++;
            }
            else
            {
                data->spriteIds.aiIconSpriteIds[i] = 0xFF;
            }
        }
        mon = GetBattlerMon(data->aiBattlerId);

        data->aiMonSpriteId = CreateMonPicSprite(gBattleMons[data->aiBattlerId].species,
                                                 GetMonData(mon, MON_DATA_IS_SHINY),
                                                 gBattleMons[data->aiBattlerId].personality,
                                                 TRUE,
                                                 39, 135, 15, TAG_NONE);
        data->aiViewState++;
        break;
    // Put text
    case 1:
        winTemplate = CreateWindowTemplate(1, 0, 4, 30, 14, 15, 0x200);
        data->aiMovesWindowId = AddWindow(&winTemplate);
        PutWindowTilemap(data->aiMovesWindowId);
        PutMovesPointsText(data);

        data->aiViewState++;
        break;
    // Input
    case 2:
        if (JOY_NEW(R_BUTTON) && IsDoubleBattle())
        {
            CleanUpAiInfoWindow(taskId);
            do {
                data->battlerId++;
                data->battlerId %= gBattlersCount;
            } while (!IsBattlerAlive(data->battlerId));
            data->aiViewState = 0;
        }
        else if (JOY_NEW(L_BUTTON) && IsDoubleBattle())
        {
            CleanUpAiInfoWindow(taskId);
            do {
                if (data->battlerId == 0)
                    data->battlerId = gBattlersCount - 1;
                else
                    data->battlerId--;
            } while (!IsBattlerAlive(data->battlerId) || !BattlerHasAi(data->battlerId));
            data->aiViewState = 0;
        }
        else if (JOY_NEW(SELECT_BUTTON | B_BUTTON))
        {
            SwitchToDebugView(taskId);
            HideBg(1);
            ShowBg(0);
            return;
        }
        break;
    }
}

static void SwitchToAiPointsView(u8 taskId)
{
    gTasks[taskId].func = Task_ShowAiPoints;
    GetStructPtr(taskId)->aiViewState = 0;
}

static const u8 *const sAiInfoItemNames[] =
{
    sText_Ability,
    sText_HeldItem,
    sText_HoldEffect,
};

static void PutAiInfoText(struct BattleDebugMenu *data)
{
    u32 i;
    u8 *text = Alloc(0x50);

    FillWindowPixelBuffer(data->aiMovesWindowId, 0x11);

    // item names
    for (i = 0; i < ARRAY_COUNT(sAiInfoItemNames); i++)
    {
        AddTextPrinterParameterized(data->aiMovesWindowId, FONT_NORMAL, sAiInfoItemNames[i], 3, i * 15, 0, NULL);
    }

    // items info
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (IsOnPlayerSide(battler) && IsBattlerAlive(battler))
        {
            enum Ability ability = gAiLogicData->abilities[battler];
            enum HoldEffect holdEffect = gAiLogicData->holdEffects[battler];
            enum Item item = gAiLogicData->items[battler];
            u8 x = (GetBattlerPosition(battler) == B_POSITION_PLAYER_LEFT) ? 83 + battler * 75 : 83 + (battler - 1) * 75;
            AddTextPrinterParameterized(data->aiMovesWindowId, FONT_SMALL, gAbilitiesInfo[ability].name, x, 0, 0, NULL);
            AddTextPrinterParameterized(data->aiMovesWindowId, FONT_SMALL, GetItemName(item), x, 15, 0, NULL);
            AddTextPrinterParameterized(data->aiMovesWindowId, FONT_SMALL, GetHoldEffectName(holdEffect), x, 30, 0, NULL);
        }
    }

    CopyWindowToVram(data->aiMovesWindowId, COPYWIN_FULL);
    Free(text);
}

static void PutAiPartyText(struct BattleDebugMenu *data)
{
    u32 i, j, count;
    u8 *text = Alloc(0x50), *txtPtr;
    struct AiPartyMon *aiMons = gAiPartyData->mons[GetBattlerSide(data->aiBattlerId)];

    FillWindowPixelBuffer(data->aiMovesWindowId, 0x11);
    count = gAiPartyData->count[GetBattlerSide(data->aiBattlerId)];
    for (i = 0; i < count; i++)
    {
        if (aiMons[i].wasSentInBattle)
        {
            text[0] = CHAR_LV;
            txtPtr = ConvertIntToDecimalStringN(text + 1, aiMons[i].level, STR_CONV_MODE_LEFT_ALIGN, 3);
            *txtPtr++ = CHAR_SPACE;
            if (aiMons[i].gender == MON_MALE)
                *txtPtr++ = CHAR_MALE;
            else if (aiMons[i].gender == MON_FEMALE)
                *txtPtr++ = CHAR_FEMALE;
            *txtPtr = EOS;
            AddTextPrinterParameterized5(data->aiMovesWindowId, FONT_SMALL_NARROW, text, i * 41, 0, 0, NULL, 0, 0);
        }

        txtPtr = StringCopyN(text, gAbilitiesInfo[aiMons[i].ability].name, 7); // The screen is too small to fit the whole string, so we need to drop the last letters.
        *txtPtr = EOS;
        AddTextPrinterParameterized5(data->aiMovesWindowId, FONT_SMALL_NARROW, text, i * 41, 15, 0, NULL, 0, 0);

        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            txtPtr = StringCopyN(text, GetMoveName(aiMons[i].moves[j]), 8);
            *txtPtr = EOS;
            AddTextPrinterParameterized5(data->aiMovesWindowId, FONT_SMALL_NARROW, text, i * 41, 35 + j * 15, 0, NULL, 0, 0);
        }

        txtPtr = StringCopyN(text, GetHoldEffectName(aiMons[i].heldEffect), 7);
        *txtPtr = EOS;
        AddTextPrinterParameterized5(data->aiMovesWindowId, FONT_SMALL_NARROW, text, i * 41, 35 + j * 15, 0, NULL, 0, 0);

        txtPtr = ConvertIntToDecimalStringN(text, aiMons[i].switchInCount, STR_CONV_MODE_LEFT_ALIGN, 2);
        *txtPtr = EOS;
        AddTextPrinterParameterized5(data->aiMovesWindowId, FONT_SMALL_NARROW, text, i * 41, 35 + (j + 1) * 15, 0, NULL, 0, 0);
    }

    CopyWindowToVram(data->aiMovesWindowId, COPYWIN_FULL);
    Free(text);
}

static void Task_ShowAiKnowledge(u8 taskId)
{
    u32 i, count;
    struct WindowTemplate winTemplate;
    struct BattleDebugMenu *data = GetStructPtr(taskId);
    struct Pokemon *mon;

    switch (data->aiViewState)
    {
    case 0:
        HideBg(0);
        ShowBg(1);

        // Swap battler if it's player mon
        data->aiBattlerId = data->battlerId;
        while (!BattlerHasAi(data->aiBattlerId))
        {
            if (++data->aiBattlerId >= gBattlersCount)
                data->aiBattlerId = 0;
        }

        LoadMonIconPalettes();
        for (count = 0, i = 0; i < MAX_BATTLERS_COUNT; i++)
        {
            if (IsOnPlayerSide(i) && IsBattlerAlive(i))
            {
                data->spriteIds.aiIconSpriteIds[i] = CreateMonIcon(gBattleMons[i].species,
                                                         SpriteCallbackDummy,
                                                         95 + (count * 80), 17, 0, 0);
                gSprites[data->spriteIds.aiIconSpriteIds[i]].data[0] = i; // battler id
                count++;
            }
            else
            {
                data->spriteIds.aiIconSpriteIds[i] = 0xFF;
            }
        }

        mon = GetBattlerMon(data->aiBattlerId);

        data->aiMonSpriteId = CreateMonPicSprite(gBattleMons[data->aiBattlerId].species,
                                                 GetMonData(mon, MON_DATA_IS_SHINY),
                                                 gBattleMons[data->aiBattlerId].personality,
                                                 TRUE,
                                                 39, 130, 15, TAG_NONE);
        data->aiViewState++;
        break;
    // Put text
    case 1:
        winTemplate = CreateWindowTemplate(1, 0, 4, 27, 14, 15, 0x200);
        data->aiMovesWindowId = AddWindow(&winTemplate);
        PutWindowTilemap(data->aiMovesWindowId);
        PutAiInfoText(data);
        data->aiViewState++;
        break;
    // Input
    case 2:
        if (JOY_NEW(SELECT_BUTTON | B_BUTTON))
        {
            SwitchToDebugView(taskId);
            HideBg(1);
            ShowBg(0);
            return;
        }
        break;
    }
}

#define sConditionSpriteId data[1]

static void Task_ShowAiParty(u8 taskId)
{
    u32 i, ailment;
    struct WindowTemplate winTemplate;
    struct AiPartyMon *aiMons;
    struct BattleDebugMenu *data = GetStructPtr(taskId);

    switch (data->aiViewState)
    {
    case 0:
        HideBg(0);
        ShowBg(1);

        LoadMonIconPalettes();
        LoadPartyMenuAilmentGfx();
        data->aiBattlerId = data->battlerId;
        aiMons = gAiPartyData->mons[GetBattlerSide(data->aiBattlerId)];
        for (i = 0; i < gAiPartyData->count[GetBattlerSide(data->aiBattlerId)]; i++)
        {
            enum Species species = SPECIES_NONE; // Question mark
            if (aiMons[i].wasSentInBattle && aiMons[i].species)
                species = aiMons[i].species;
            data->spriteIds.aiPartyIcons[i] = CreateMonIcon(species, SpriteCallbackDummy, (i * 41) + 15, 7, 1, 0);
            gSprites[data->spriteIds.aiPartyIcons[i]].oam.priority = 0;

            gSprites[data->spriteIds.aiPartyIcons[i]].sConditionSpriteId = CreateSprite(&gSpriteTemplate_StatusIcons, (i * 41) + 15, 7, 0);
            gSprites[gSprites[data->spriteIds.aiPartyIcons[i]].sConditionSpriteId].oam.priority = 0;
            if (aiMons[i].isFainted)
                ailment = AILMENT_FNT;
            else
                ailment = GetAilmentFromStatus(aiMons[i].status);

            if (ailment != AILMENT_NONE)
                StartSpriteAnim(&gSprites[gSprites[data->spriteIds.aiPartyIcons[i]].sConditionSpriteId], ailment - 1);
            else
                gSprites[gSprites[data->spriteIds.aiPartyIcons[i]].sConditionSpriteId].invisible = TRUE;
        }
        for (; i < PARTY_SIZE; i++)
            data->spriteIds.aiPartyIcons[i] = 0xFF;
        data->aiViewState++;
        break;
    // Put text
    case 1:
        winTemplate = CreateWindowTemplate(1, 0, 3, 29, 16, 15, 0x150);
        data->aiMovesWindowId = AddWindow(&winTemplate);
        PutWindowTilemap(data->aiMovesWindowId);
        PutAiPartyText(data);
        data->aiViewState++;
        break;
    // Input
    case 2:
        if (JOY_NEW(SELECT_BUTTON | B_BUTTON))
        {
            SwitchToDebugViewFromAiParty(taskId);
            HideBg(1);
            ShowBg(0);
            return;
        }
        break;
    }
}

static void SwitchToAiInfoView(u8 taskId)
{
    gTasks[taskId].func = Task_ShowAiKnowledge;
    GetStructPtr(taskId)->aiViewState = 0;
}

static void SwitchToAiPartyView(u8 taskId)
{
    gTasks[taskId].func = Task_ShowAiParty;
    GetStructPtr(taskId)->aiViewState = 0;
}

static void SwitchToDebugViewFromAiParty(u8 taskId)
{
    u32 i;
    struct BattleDebugMenu *data = GetStructPtr(taskId);

    FreeMonIconPalettes();
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (data->spriteIds.aiPartyIcons[i] != 0xFF)
        {
            DestroySpriteAndFreeResources(&gSprites[gSprites[data->spriteIds.aiPartyIcons[i]].sConditionSpriteId]);
            FreeAndDestroyMonIconSprite(&gSprites[data->spriteIds.aiPartyIcons[i]]);
        }
    }
    ClearWindowTilemap(data->aiMovesWindowId);
    RemoveWindow(data->aiMovesWindowId);

    gTasks[taskId].func = Task_DebugMenuProcessInput;
}

#undef sConditionSpriteId

static void SwitchToDebugView(u8 taskId)
{
    CleanUpAiInfoWindow(taskId);
    gTasks[taskId].func = Task_DebugMenuProcessInput;
}

static void Task_DebugMenuFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_DebugMenuProcessInput;
}

static void Task_DebugMenuProcessInput(u8 taskId)
{
    s32 listItemId = 0;
    struct BattleDebugMenu *data = GetStructPtr(taskId);

    // Exit the menu.
    if (JOY_NEW(SELECT_BUTTON) || ((JOY_NEW(B_BUTTON)) && data->activeWindow == ACTIVE_WIN_MAIN))
    {
        BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
        gTasks[taskId].func = Task_DebugMenuFadeOut;
        return;
    }

    // Try changing active battler.
    if (JOY_NEW(R_BUTTON))
    {
        if (data->battlerId++ == gBattlersCount - 1)
            data->battlerId = 0;
        UpdateWindowsOnChangedBattler(data);
    }
    else if (JOY_NEW(L_BUTTON))
    {
        if (data->battlerId-- == 0)
            data->battlerId = gBattlersCount - 1;
        UpdateWindowsOnChangedBattler(data);
    }

    // A main list item is active, handle input.
    if (data->activeWindow == ACTIVE_WIN_MAIN)
    {
        listItemId = ListMenu_ProcessInput(data->mainListTaskId);
        if (listItemId != LIST_CANCEL && listItemId != LIST_NOTHING_CHOSEN && listItemId < LIST_ITEM_COUNT)
        {
            if (listItemId == LIST_ITEM_AI_MOVES_PTS && JOY_NEW(A_BUTTON))
            {
                SwitchToAiPointsView(taskId);
                return;
            }
            else if (listItemId == LIST_ITEM_AI_INFO && JOY_NEW(A_BUTTON))
            {
                SwitchToAiInfoView(taskId);
                return;
            }
            else if (listItemId == LIST_ITEM_AI_PARTY && JOY_NEW(A_BUTTON))
            {
                SwitchToAiPartyView(taskId);
                return;
            }
            else if (listItemId == LIST_ITEM_INSTANT_WIN && JOY_NEW(A_BUTTON))
            {
                BattleDebug_WonBattle();
                BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
                gTasks[taskId].func = Task_DebugMenuFadeOut;
                return;
            }
            data->currentMainListItemId = listItemId;

            // Create the secondary menu list.
            CreateSecondaryListMenu(data);
            PrintSecondaryEntries(data);
            data->activeWindow = ACTIVE_WIN_SECONDARY;
        }
    }
    // Secondary list is active, handle input.
    else if (data->activeWindow == ACTIVE_WIN_SECONDARY)
    {
        listItemId = ListMenu_ProcessInput(data->secondaryListTaskId);
        if (listItemId == LIST_CANCEL)
        {
            DestroyListMenuTask(data->secondaryListTaskId, NULL, NULL);
            ClearStdWindowAndFrameToTransparent(data->secondaryListWindowId, TRUE);
            RemoveWindow(data->secondaryListWindowId);
            data->activeWindow = ACTIVE_WIN_MAIN;
            data->secondaryListTaskId = 0xFF;
        }
        else if (listItemId != LIST_NOTHING_CHOSEN)
        {
            data->currentSecondaryListItemId = listItemId;
            data->modifyWindowId = AddWindow(&sModifyWindowTemplate);
            PutWindowTilemap(data->modifyWindowId);
            CopyWindowToVram(data->modifyWindowId, COPYWIN_FULL);
            SetUpModifyArrows(data);
            PrintDigitChars(data);
            data->activeWindow = ACTIVE_WIN_MODIFY;
        }
    }
    // Handle value modifying.
    else if (data->activeWindow == ACTIVE_WIN_MODIFY)
    {
        if (JOY_NEW(B_BUTTON | A_BUTTON))
        {
            ClearStdWindowAndFrameToTransparent(data->modifyWindowId, TRUE);
            RemoveWindow(data->modifyWindowId);
            DestroyModifyArrows(data);
            data->activeWindow = ACTIVE_WIN_SECONDARY;
        }
        else if (JOY_NEW(DPAD_RIGHT))
        {
            if (data->modifyArrows.currentDigit != (data->modifyArrows.maxDigits - 1))
            {
                data->modifyArrows.currentDigit++;
                gSprites[data->modifyArrows.arrowSpriteId[0]].x2 += 6;
                gSprites[data->modifyArrows.arrowSpriteId[1]].x2 += 6;
            }
        }
        else if (JOY_NEW(DPAD_LEFT))
        {
            if (data->modifyArrows.currentDigit != 0)
            {
                data->modifyArrows.currentDigit--;
                gSprites[data->modifyArrows.arrowSpriteId[0]].x2 -= 6;
                gSprites[data->modifyArrows.arrowSpriteId[1]].x2 -= 6;
            }
        }
        else if (JOY_NEW(DPAD_UP))
        {
            if (TryMoveDigit(&data->modifyArrows, TRUE))
            {
                PrintDigitChars(data);
                UpdateBattlerValue(data);
                PrintSecondaryEntries(data);
            }
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            if (TryMoveDigit(&data->modifyArrows, FALSE))
            {
                PrintDigitChars(data);
                UpdateBattlerValue(data);
                PrintSecondaryEntries(data);
            }
        }
    }
}

static void Task_DebugMenuFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        struct BattleDebugMenu *data = GetStructPtr(taskId);
        DestroyListMenuTask(data->mainListTaskId, 0, 0);
        if (data->secondaryListTaskId != 0xFF)
            DestroyListMenuTask(data->secondaryListTaskId, 0, 0);

        FreeAllWindowBuffers();
        UpdateMonData(data);
        gBattleStruct->debugBattler = data->battlerId;
        Free(data);
        DestroyTask(taskId);
        SetMainCallback2(ReshowBattleScreenAfterMenu);
    }
}

static void PrintOnBattlerWindow(u8 windowId, enum BattlerId battler)
{
    u8 text[POKEMON_NAME_LENGTH + 10];

    text[0] = CHAR_0 + battler;
    text[1] = CHAR_SPACE;
    text[2] = CHAR_HYPHEN;
    text[3] = CHAR_SPACE;
    StringCopy(&text[4], gBattleMons[battler].nickname);

    FillWindowPixelBuffer(windowId, 0x11);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, text, 0, 0, 0, NULL);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void UpdateWindowsOnChangedBattler(struct BattleDebugMenu *data)
{
    PrintOnBattlerWindow(data->battlerWindowId, data->battlerId);
    if (data->secondaryListTaskId != 0xFF)
    {
        DestroyListMenuTask(data->secondaryListTaskId, 0, 0);
        RemoveWindow(data->secondaryListWindowId);
        CreateSecondaryListMenu(data);
        data->currentSecondaryListItemId = 0;
        PrintSecondaryEntries(data);
    }
    if (data->activeWindow == ACTIVE_WIN_MODIFY)
    {
        DestroyModifyArrows(data);
        SetUpModifyArrows(data);
        PrintDigitChars(data);
    }
}


static void CreateSecondaryListMenu(struct BattleDebugMenu *data)
{
    struct WindowTemplate winTemplate;
    struct ListMenuTemplate listTemplate;
    u8 itemsCount = 1;

    winTemplate = sSecondaryListWindowTemplate;
    listTemplate = sSecondaryListTemplate;

    switch (data->currentMainListItemId)
    {
    case LIST_ITEM_ABILITY:
        itemsCount = 1;
        break;
    case LIST_ITEM_HELD_ITEM:
        itemsCount = 1;
        break;
    case LIST_ITEM_TYPES:
        itemsCount = 3;
        break;
    case LIST_ITEM_MOVES:
        itemsCount = 5;
        break;
    case LIST_ITEM_PP:
        itemsCount = 4;
        break;
    case LIST_ITEM_STATS:
        listTemplate.items = sStatsListItems;
        itemsCount = ARRAY_COUNT(sStatsListItems);
        break;
    case LIST_ITEM_STAT_STAGES:
        itemsCount = 8;
        break;
    case LIST_ITEM_STATUS1:
        listTemplate.items = sStatus1ListItems;
        itemsCount = ARRAY_COUNT(sStatus1ListItems);
        data->bitfield = sStatus1Bitfield;
        break;
    case LIST_ITEM_VOLATILE:
        listTemplate.items = sVolatileStatusListItems;
        itemsCount = ARRAY_COUNT(sVolatileStatusListItems);
        break;
    case LIST_ITEM_AI:
        listTemplate.items = sAIListItems;
        itemsCount = ARRAY_COUNT(sAIListItems);
        data->bitfield = sAIBitfield;
        break;
    case LIST_ITEM_VARIOUS:
        listTemplate.items = sVariousListItems;
        itemsCount = ARRAY_COUNT(sVariousListItems);
        break;
    case LIST_ITEM_HAZARDS:
        listTemplate.items = sHazardsListItems;
        itemsCount = ARRAY_COUNT(sHazardsListItems);
        break;
    case LIST_ITEM_SIDE_STATUS:
        listTemplate.items = sSideStatusListItems;
        itemsCount = ARRAY_COUNT(sSideStatusListItems);
        break;
    case LIST_ITEM_INSTANT_WIN:
    case LIST_ITEM_AI_MOVES_PTS:
    case LIST_ITEM_AI_INFO:
        return;
    }

    data->secondaryListItemCount = itemsCount;
    data->secondaryListWindowId = AddWindow(&winTemplate);

    listTemplate.totalItems = itemsCount;
    listTemplate.maxShowed = itemsCount;
    if (listTemplate.maxShowed > 7 && !sHasChangeableEntries[data->currentMainListItemId])
        listTemplate.maxShowed = 7;
    listTemplate.windowId = data->secondaryListWindowId;

    data->secondaryListTaskId = ListMenuInit(&listTemplate, 0, 0);
    CopyWindowToVram(data->secondaryListWindowId, COPYWIN_FULL);
}

static void PadString(const u8 *src, u8 *dst)
{
    u32 i;

    for (i = 0; i < 19 && src[i] != EOS; i++)
        dst[i] = src[i];

    for (; i < 19; i++)
        dst[i] = CHAR_SPACE;

    dst[i] = EOS;
}

static const u8 sTextAll[] = _("All");

static void PrintSecondaryEntries(struct BattleDebugMenu *data)
{
    u8 text[20];
    s32 i;
    struct TextPrinterTemplate printer;
    u8 yMultiplier;

    // Do not print entries if they are not changing.
    if (!sHasChangeableEntries[data->currentMainListItemId])
        return;

    yMultiplier = (GetFontAttribute(sSecondaryListTemplate.fontId, 1) + sSecondaryListTemplate.itemVerticalPadding);

    printer.type = WINDOW_TEXT_PRINTER;
    printer.windowId = data->secondaryListWindowId;
    printer.fontId = 1;
    printer.letterSpacing = 0;
    printer.lineSpacing = 1;
    printer.color.accent = 1;
    printer.color.foreground = 2;
    printer.color.background = 1;
    printer.color.shadow = 3;
    printer.x = sSecondaryListTemplate.item_X;
    printer.currentX = sSecondaryListTemplate.item_X;
    printer.currentChar = text;

    switch (data->currentMainListItemId)
    {
    case LIST_ITEM_MOVES:
    case LIST_ITEM_PP:
        for (i = 0; i < 4; i++)
        {
            PadString(GetMoveName(gBattleMons[data->battlerId].moves[i]), text);
            printer.currentY = printer.y = (i * yMultiplier) + sSecondaryListTemplate.upText_Y;
            AddTextPrinter(&printer, 0, NULL);
        }
        // Allow changing all moves at once. Useful for testing in wild doubles.
        if (data->currentMainListItemId == LIST_ITEM_MOVES)
        {
            PadString(sTextAll, text);
            printer.currentY = printer.y = (i * yMultiplier) + sSecondaryListTemplate.upText_Y;
            AddTextPrinter(&printer, 0, NULL);
        }
        break;
    case LIST_ITEM_ABILITY:
        PadString(gAbilitiesInfo[gBattleMons[data->battlerId].ability].name, text);
        printer.currentY = printer.y = sSecondaryListTemplate.upText_Y;
        AddTextPrinter(&printer, 0, NULL);
        break;
    case LIST_ITEM_HELD_ITEM:
        PadString(GetItemName(gBattleMons[data->battlerId].item), text);
        printer.currentY = printer.y = sSecondaryListTemplate.upText_Y;
        AddTextPrinter(&printer, 0, NULL);
        break;
    case LIST_ITEM_TYPES:
        for (i = 0; i < 3; i++)
        {
            enum Type *types = &gBattleMons[data->battlerId].types[0];

            PadString(gTypesInfo[types[i]].name, text);
            printer.currentY = printer.y = (i * yMultiplier) + sSecondaryListTemplate.upText_Y;
            AddTextPrinter(&printer, 0, NULL);
        }
        break;
    case LIST_ITEM_STAT_STAGES:
        for (i = 0; i < NUM_BATTLE_STATS - 1; i++)
        {
            u8 *txtPtr = StringCopy(text, gStatNamesTable[STAT_ATK + i]);
            txtPtr[0] = CHAR_SPACE;
            if (gBattleMons[data->battlerId].statStages[STAT_ATK + i] >= DEFAULT_STAT_STAGE)
            {
                txtPtr[1] = CHAR_PLUS;
                txtPtr[2] = CHAR_0 + (gBattleMons[data->battlerId].statStages[STAT_ATK + i] - DEFAULT_STAT_STAGE);
            }
            else
            {
                txtPtr[1] = CHAR_HYPHEN;
                txtPtr[2] = CHAR_6 - (gBattleMons[data->battlerId].statStages[STAT_ATK + i]);
            }
            txtPtr[3] = EOS;

            PadString(text, text);
            printer.currentY = printer.y = (i * yMultiplier) + sSecondaryListTemplate.upText_Y;
            AddTextPrinter(&printer, 0, NULL);
        }
        // Allow changing all stat stages at once.
        PadString(sTextAll, text);
        printer.currentY = printer.y = (i * yMultiplier) + sSecondaryListTemplate.upText_Y;
        AddTextPrinter(&printer, 0, NULL);
        break;
    }
}

static void DestroyModifyArrows(struct BattleDebugMenu *data)
{
    if (data->modifyArrows.arrowSpriteId[0] != 0xFF)
        DestroySpriteAndFreeResources(&gSprites[data->modifyArrows.arrowSpriteId[0]]);
    if (data->modifyArrows.arrowSpriteId[1] != 0xFF)
        DestroySpriteAndFreeResources(&gSprites[data->modifyArrows.arrowSpriteId[1]]);
}

static void PrintDigitChars(struct BattleDebugMenu *data)
{
    s32 i;
    u8 text[MAX_MODIFY_DIGITS + 1];

    for (i = 0; i < data->modifyArrows.maxDigits; i++)
        text[i] = data->modifyArrows.charDigits[i];

    text[i] = EOS;

    FillWindowPixelBuffer(data->modifyWindowId, 0x11);
    AddTextPrinterParameterized(data->modifyWindowId, FONT_NORMAL, text, 3, 0, 0, NULL);
}

static const u32 GetBitfieldToAndValue(u32 currBit, u32 bitsCount)
{
    u32 i;
    u32 toAnd = 0;

    for (i = 0; i < bitsCount; i++)
        toAnd |= (1 << (currBit + i));

    return toAnd;
}

static const u32 GetBitfieldValue(u32 value, u32 currBit, u32 bitsCount)
{
    return (value & (GetBitfieldToAndValue(currBit, bitsCount))) >> currBit;
}

static void UpdateBattlerValue(struct BattleDebugMenu *data)
{
    u32 i;
    switch (data->modifyArrows.typeOfVal)
    {
    case VAL_U8:
        *(u8 *)(data->modifyArrows.modifiedValPtr) = data->modifyArrows.currValue;
        break;
    case VAL_S8:
        *(s8 *)(data->modifyArrows.modifiedValPtr) = data->modifyArrows.currValue;
        break;
    case VAL_U16:
        *(u16 *)(data->modifyArrows.modifiedValPtr) = data->modifyArrows.currValue;
        break;
    case VAR_U16_4_ENTRIES:
        ((u16 *)(data->modifyArrows.modifiedValPtr))[0] = data->modifyArrows.currValue;
        ((u16 *)(data->modifyArrows.modifiedValPtr))[1] = data->modifyArrows.currValue;
        ((u16 *)(data->modifyArrows.modifiedValPtr))[2] = data->modifyArrows.currValue;
        ((u16 *)(data->modifyArrows.modifiedValPtr))[3] = data->modifyArrows.currValue;
        break;
    case VAL_ALL_STAT_STAGES:
        for (i = 0; i < NUM_BATTLE_STATS; i++)
            gBattleMons[data->battlerId].statStages[i] = data->modifyArrows.currValue;
        break;
    case VAL_U32:
        *(u32 *)(data->modifyArrows.modifiedValPtr) = data->modifyArrows.currValue;
        break;
    case VAL_BITFIELD_32:
        *(u32 *)(data->modifyArrows.modifiedValPtr) &= ~(GetBitfieldToAndValue(data->bitfield[data->currentSecondaryListItemId].currBit, data->bitfield[data->currentSecondaryListItemId].bitsCount));
        *(u32 *)(data->modifyArrows.modifiedValPtr) |= (data->modifyArrows.currValue << data->bitfield[data->currentSecondaryListItemId].currBit);
        break;
    case VAL_VOLATILE:
        SetMonVolatile(data->battlerId, data->currentSecondaryListItemId, data->modifyArrows.currValue);
        break;
    case VAL_HAZARDS:
        ChangeHazardsValue(data);
        break;
    case VAR_SIDE_STATUS:
        *GetSideStatusValue(data, TRUE, data->modifyArrows.currValue != 0) = data->modifyArrows.currValue;
        break;
    case VAR_SHOW_HP:
        (*(struct BattleSpriteInfo*)(data->modifyArrows.modifiedValPtr)).hpNumbersNoBars = data->modifyArrows.currValue;
        break;
    case VAR_SUBSTITUTE:
        *(u8 *)(data->modifyArrows.modifiedValPtr) = data->modifyArrows.currValue;
        if (*(u8 *)(data->modifyArrows.modifiedValPtr) == 0)
        {
            gBattleMons[data->battlerId].volatiles.substitute = FALSE;
            gBattleSpritesDataPtr->battlerData[data->battlerId].behindSubstitute = 0;
        }
        else
        {
            gBattleMons[data->battlerId].volatiles.substitute = TRUE;
            gBattleSpritesDataPtr->battlerData[data->battlerId].behindSubstitute = 1;
        }
        break;
    case VAR_IN_LOVE:
        if (data->modifyArrows.currValue)
        {
            if (IsBattlerAlive(GetOppositeBattler(data->battlerId)))
                gBattleMons[data->battlerId].volatiles.infatuation = INFATUATED_WITH(GetOppositeBattler(data->battlerId));
            else
                gBattleMons[data->battlerId].volatiles.infatuation = INFATUATED_WITH(GetPartnerBattler(GetOppositeBattler(data->battlerId)));
        }
        else
        {
            gBattleMons[data->battlerId].volatiles.infatuation = 0;
        }
        break;
    }
    data->battlerWasChanged[data->battlerId] = TRUE;
}

static u32 CharDigitsToValue(u8 *charDigits, u8 maxDigits)
{
    s32 i;
    u8 id = 0;
    u32 newValue = 0;
    u8 valueDigits[MAX_MODIFY_DIGITS];

    for (i = 0; i < MAX_MODIFY_DIGITS; i++)
        valueDigits[i] = charDigits[i] - CHAR_0;

    if (maxDigits >= MAX_MODIFY_DIGITS)
        newValue += valueDigits[id++] * 1000;
    if (maxDigits >= MAX_MODIFY_DIGITS - 1)
        newValue += valueDigits[id++] * 100;
    if (maxDigits >= MAX_MODIFY_DIGITS - 2)
        newValue += valueDigits[id++] * 10;
    if (maxDigits >= MAX_MODIFY_DIGITS - 3)
        newValue += valueDigits[id++];

    return newValue;
}

static void ValueToCharDigits(u8 *charDigits, u32 newValue, u8 maxDigits)
{
    s32 i;
    u8 valueDigits[MAX_MODIFY_DIGITS];
    u8 id = 0;

    if (maxDigits >= MAX_MODIFY_DIGITS)
        valueDigits[id++] = newValue / 1000;
    if (maxDigits >= MAX_MODIFY_DIGITS - 1)
        valueDigits[id++] = (newValue % 1000) / 100;
    if (maxDigits >= MAX_MODIFY_DIGITS - 2)
        valueDigits[id++] = (newValue % 100) / 10;
    if (maxDigits >= MAX_MODIFY_DIGITS - 3)
        valueDigits[id++] = newValue % 10;

    for (i = 0; i < MAX_MODIFY_DIGITS; i++)
        charDigits[i] = valueDigits[i] + CHAR_0;
}

static void ChangeHazardsValue(struct BattleDebugMenu *data)
{
    enum BattleSide side = GetBattlerSide(data->battlerId);

    switch (data->currentSecondaryListItemId)
    {
    case LIST_SIDE_SPIKES:
        if (data->modifyArrows.currValue > 0)
        {
            if (gSideTimers[side].spikesAmount == 0)
                PushHazardTypeToQueue(side, HAZARDS_SPIKES);
            gSideTimers[side].spikesAmount = data->modifyArrows.currValue;
        }
        else if (data->modifyArrows.currValue == 0)
        {
            gSideTimers[side].spikesAmount = 0;
            RemoveHazardFromField(side, HAZARDS_SPIKES);
        }
        break;
    case LIST_SIDE_TOXIC_SPIKES:
        if (data->modifyArrows.currValue > 0)
        {
            if (gSideTimers[side].toxicSpikesAmount == 0)
                PushHazardTypeToQueue(side, HAZARDS_TOXIC_SPIKES);
            gSideTimers[side].toxicSpikesAmount = data->modifyArrows.currValue;
        }
        else if (data->modifyArrows.currValue == 0)
        {
            gSideTimers[side].toxicSpikesAmount = 0;
            RemoveHazardFromField(side, HAZARDS_TOXIC_SPIKES);
        }
        break;
    case LIST_SIDE_STICKY_WEB:
        if (data->modifyArrows.currValue > 0)
            PushHazardTypeToQueue(side, HAZARDS_STICKY_WEB);
        else if (data->modifyArrows.currValue == 0)
            RemoveHazardFromField(side, HAZARDS_STICKY_WEB);
        break;
    case LIST_SIDE_STEALTH_ROCK:
        if (data->modifyArrows.currValue > 0)
            PushHazardTypeToQueue(side, HAZARDS_STEALTH_ROCK);
        else if (data->modifyArrows.currValue == 0)
            RemoveHazardFromField(side, HAZARDS_STEALTH_ROCK);
        break;
    case LIST_SIDE_STEELSURGE:
        if (data->modifyArrows.currValue > 0)
            PushHazardTypeToQueue(side, HAZARDS_STEELSURGE);
        else if (data->modifyArrows.currValue == 0)
            RemoveHazardFromField(side, HAZARDS_STEELSURGE);
        break;
    }
}

static u32 GetHazardsValue(struct BattleDebugMenu *data)
{
    u32 hazardsLayers = 0;
    switch (data->currentSecondaryListItemId)
    {
    case LIST_SIDE_SPIKES:
        hazardsLayers = gSideTimers[GetBattlerSide(data->battlerId)].spikesAmount;
        break;
    case LIST_SIDE_TOXIC_SPIKES:
        hazardsLayers = gSideTimers[GetBattlerSide(data->battlerId)].toxicSpikesAmount;
        break;
    case LIST_SIDE_STICKY_WEB:
        hazardsLayers = IsHazardOnSide(GetBattlerSide(data->battlerId), HAZARDS_STICKY_WEB);
        break;
    case LIST_SIDE_STEALTH_ROCK:
        hazardsLayers = IsHazardOnSide(GetBattlerSide(data->battlerId), HAZARDS_STEALTH_ROCK);
        break;
    case LIST_SIDE_STEELSURGE:
        hazardsLayers = IsHazardOnSide(GetBattlerSide(data->battlerId), HAZARDS_STEELSURGE);
        break;
    }
    return hazardsLayers;
}

static u16 *GetSideStatusValue(struct BattleDebugMenu *data, bool32 changeStatus, bool32 statusTrue)
{
    struct SideTimer *sideTimer = &gSideTimers[GetBattlerSide(data->battlerId)];

    switch (data->currentSecondaryListItemId)
    {
    case LIST_SIDE_REFLECT:
        if (changeStatus)
        {
            if (statusTrue)
                *(u32 *)(data->modifyArrows.modifiedValPtr) |= SIDE_STATUS_REFLECT;
            else
                *(u32 *)(data->modifyArrows.modifiedValPtr) &= ~SIDE_STATUS_REFLECT;
        }
        return &sideTimer->reflectTimer;
    case LIST_SIDE_LIGHTSCREEN:
        if (changeStatus)
        {
            if (statusTrue)
                *(u32 *)(data->modifyArrows.modifiedValPtr) |= SIDE_STATUS_LIGHTSCREEN;
            else
                *(u32 *)(data->modifyArrows.modifiedValPtr) &= ~SIDE_STATUS_LIGHTSCREEN;
        }
        return &sideTimer->lightscreenTimer;
    case LIST_SIDE_SAFEGUARD:
        if (changeStatus)
        {
            if (statusTrue)
                *(u32 *)(data->modifyArrows.modifiedValPtr) |= SIDE_STATUS_SAFEGUARD;
            else
                *(u32 *)(data->modifyArrows.modifiedValPtr) &= ~SIDE_STATUS_SAFEGUARD;
        }
        return &sideTimer->safeguardTimer;
    case LIST_SIDE_MIST:
        if (changeStatus)
        {
            if (statusTrue)
                *(u32 *)(data->modifyArrows.modifiedValPtr) |= SIDE_STATUS_MIST;
            else
                *(u32 *)(data->modifyArrows.modifiedValPtr) &= ~SIDE_STATUS_MIST;
        }
        return &sideTimer->mistTimer;
    case LIST_SIDE_TAILWIND:
        if (changeStatus)
        {
            if (statusTrue)
                *(u32 *)(data->modifyArrows.modifiedValPtr) |= SIDE_STATUS_TAILWIND;
            else
                *(u32 *)(data->modifyArrows.modifiedValPtr) &= ~SIDE_STATUS_TAILWIND;
        }
        return &sideTimer->tailwindTimer;
    case LIST_SIDE_AURORA_VEIL:
        if (changeStatus)
        {
            if (statusTrue)
                *(u32 *)(data->modifyArrows.modifiedValPtr) |= SIDE_STATUS_AURORA_VEIL;
            else
                *(u32 *)(data->modifyArrows.modifiedValPtr) &= ~SIDE_STATUS_AURORA_VEIL;
        }
        return &sideTimer->auroraVeilTimer;
    case LIST_SIDE_LUCKY_CHANT:
        if (changeStatus)
        {
            if (statusTrue)
                *(u32 *)(data->modifyArrows.modifiedValPtr) |= SIDE_STATUS_LUCKY_CHANT;
            else
                *(u32 *)(data->modifyArrows.modifiedValPtr) &= ~SIDE_STATUS_LUCKY_CHANT;
        }
        return &sideTimer->luckyChantTimer;
    case LIST_SIDE_DAMAGE_NON_TYPES:
        if (changeStatus)
        {
            if (statusTrue)
                *(u32 *)(data->modifyArrows.modifiedValPtr) |= SIDE_STATUS_DAMAGE_NON_TYPES;
            else
                *(u32 *)(data->modifyArrows.modifiedValPtr) &= ~SIDE_STATUS_DAMAGE_NON_TYPES;
            sideTimer->damageNonTypesType = GetMoveType(gCurrentMove);
        }
        return &sideTimer->damageNonTypesTimer;
    case LIST_SIDE_RAINBOW:
        if (changeStatus)
        {
            if (statusTrue)
                *(u32 *)(data->modifyArrows.modifiedValPtr) |= SIDE_STATUS_RAINBOW;
            else
                *(u32 *)(data->modifyArrows.modifiedValPtr) &= ~SIDE_STATUS_RAINBOW;
        }
        return &sideTimer->rainbowTimer;
    case LIST_SIDE_SEA_OF_FIRE:
        if (changeStatus)
        {
            if (statusTrue)
                *(u32 *)(data->modifyArrows.modifiedValPtr) |= SIDE_STATUS_SEA_OF_FIRE;
            else
                *(u32 *)(data->modifyArrows.modifiedValPtr) &= ~SIDE_STATUS_SEA_OF_FIRE;
        }
        return &sideTimer->seaOfFireTimer;
    case LIST_SIDE_SWAMP:
        if (changeStatus)
        {
            if (statusTrue)
                *(u32 *)(data->modifyArrows.modifiedValPtr) |= SIDE_STATUS_SWAMP;
            else
                *(u32 *)(data->modifyArrows.modifiedValPtr) &= ~SIDE_STATUS_SWAMP;
        }
        return &sideTimer->swampTimer;
    default:
        return NULL;
    }
}

static void SetUpModifyArrows(struct BattleDebugMenu *data)
{
    LoadSpritePalette(&gSpritePalette_Arrow);
    data->modifyArrows.arrowSpriteId[0] = CreateSprite(&gSpriteTemplate_Arrow, 207, 12, 0);
    data->modifyArrows.arrowSpriteId[1] = CreateSprite(&gSpriteTemplate_Arrow, 207, 36, 0);
    gSprites[data->modifyArrows.arrowSpriteId[1]].animNum = 1;
    switch (data->currentMainListItemId)
    {
    case LIST_ITEM_ABILITY:
        data->modifyArrows.minValue = 0;
        data->modifyArrows.maxValue = ABILITIES_COUNT - 1;
        data->modifyArrows.maxDigits = 3;
        data->modifyArrows.modifiedValPtr = &gBattleMons[data->battlerId].ability;
        data->modifyArrows.typeOfVal = VAL_U16;
        data->modifyArrows.currValue = gBattleMons[data->battlerId].ability;
        break;
    case LIST_ITEM_MOVES:
        data->modifyArrows.minValue = 0;
        data->modifyArrows.maxValue = MOVES_COUNT - 1;
        data->modifyArrows.maxDigits = 3;
        if (data->currentSecondaryListItemId == 4)
        {
            data->modifyArrows.modifiedValPtr = &gBattleMons[data->battlerId].moves[0];
            data->modifyArrows.currValue = gBattleMons[data->battlerId].moves[0];
            data->modifyArrows.typeOfVal = VAR_U16_4_ENTRIES;
        }
        else
        {
            data->modifyArrows.modifiedValPtr = &gBattleMons[data->battlerId].moves[data->currentSecondaryListItemId];
            data->modifyArrows.currValue = gBattleMons[data->battlerId].moves[data->currentSecondaryListItemId];
            data->modifyArrows.typeOfVal = VAL_U16;
        }
        break;
    case LIST_ITEM_PP:
        data->modifyArrows.minValue = 0;
        data->modifyArrows.maxValue = CalculatePPWithBonus(gBattleMons[data->battlerId].moves[data->currentSecondaryListItemId], gBattleMons[data->battlerId].ppBonuses, data->currentSecondaryListItemId);
        data->modifyArrows.maxDigits = 2;
        data->modifyArrows.modifiedValPtr = &gBattleMons[data->battlerId].pp[data->currentSecondaryListItemId];
        data->modifyArrows.typeOfVal = VAL_U8;
        data->modifyArrows.currValue = gBattleMons[data->battlerId].pp[data->currentSecondaryListItemId];
        break;
    case LIST_ITEM_HELD_ITEM:
        data->modifyArrows.minValue = 0;
        data->modifyArrows.maxValue = ITEMS_COUNT - 1;
        data->modifyArrows.maxDigits = 3;
        data->modifyArrows.modifiedValPtr = &gBattleMons[data->battlerId].item;
        data->modifyArrows.typeOfVal = VAL_U16;
        data->modifyArrows.currValue = gBattleMons[data->battlerId].item;
        break;
    case LIST_ITEM_TYPES:
        data->modifyArrows.minValue = 0;
        data->modifyArrows.maxValue = NUMBER_OF_MON_TYPES - 1;
        data->modifyArrows.maxDigits = 2;
        data->modifyArrows.modifiedValPtr = (u8 *)((&gBattleMons[data->battlerId].types[0]) + data->currentSecondaryListItemId);
        data->modifyArrows.typeOfVal = VAL_U8;
        data->modifyArrows.currValue = *(u8 *)((&gBattleMons[data->battlerId].types[0]) + data->currentSecondaryListItemId);
        break;
    case LIST_ITEM_STATS:
        data->modifyArrows.minValue = 0;
        data->modifyArrows.maxValue = 9999;
        data->modifyArrows.maxDigits = 4;
        data->modifyArrows.typeOfVal = VAL_U16;
        if (data->currentSecondaryListItemId == LIST_STAT_HP_CURRENT)
        {
            data->modifyArrows.modifiedValPtr = &gBattleMons[data->battlerId].hp;
            data->modifyArrows.currValue = gBattleMons[data->battlerId].hp;
            data->modifyArrows.minValue = 1;
            data->modifyArrows.maxValue = gBattleMons[data->battlerId].maxHP;
        }
        else if (data->currentSecondaryListItemId == LIST_STAT_HP_MAX)
        {
            data->modifyArrows.modifiedValPtr = &gBattleMons[data->battlerId].maxHP;
            data->modifyArrows.minValue = gBattleMons[data->battlerId].hp;
            data->modifyArrows.currValue = gBattleMons[data->battlerId].maxHP;
        }
        else
        {
            data->modifyArrows.modifiedValPtr = (u16 *)((&gBattleMons[data->battlerId].attack) + (data->currentSecondaryListItemId - 2));
            data->modifyArrows.currValue = *(u16 *)((&gBattleMons[data->battlerId].attack) + (data->currentSecondaryListItemId - 2));
        }
        break;
    case LIST_ITEM_STAT_STAGES:
        data->modifyArrows.minValue = 0;
        data->modifyArrows.maxValue = 12;
        data->modifyArrows.maxDigits = 2;
        if (data->currentSecondaryListItemId == NUM_BATTLE_STATS - 1) // Change all stats
        {
            data->modifyArrows.modifiedValPtr = &gBattleMons[data->battlerId].statStages[STAT_ATK];
            data->modifyArrows.currValue = gBattleMons[data->battlerId].statStages[STAT_ATK];
            data->modifyArrows.typeOfVal = VAL_ALL_STAT_STAGES;
        }
        else
        {
            data->modifyArrows.modifiedValPtr = &gBattleMons[data->battlerId].statStages[data->currentSecondaryListItemId + STAT_ATK];
            data->modifyArrows.typeOfVal = VAL_U8;
            data->modifyArrows.currValue = gBattleMons[data->battlerId].statStages[data->currentSecondaryListItemId + STAT_ATK];
        }
        break;
    case LIST_ITEM_VARIOUS:
        if (data->currentSecondaryListItemId == VARIOUS_SHOW_HP)
        {
            data->modifyArrows.minValue = 0;
            data->modifyArrows.maxValue = 1;
            data->modifyArrows.maxDigits = 1;
            data->modifyArrows.modifiedValPtr = &gBattleSpritesDataPtr->battlerData[data->battlerId];
            data->modifyArrows.typeOfVal = VAR_SHOW_HP;
            data->modifyArrows.currValue = gBattleSpritesDataPtr->battlerData[data->battlerId].hpNumbersNoBars;
        }
        else if (data->currentSecondaryListItemId == VARIOUS_SUBSTITUTE_HP)
        {
            u32 subHp = gBattleMons[data->battlerId].volatiles.substituteHP;
            data->modifyArrows.minValue = 0;
            data->modifyArrows.maxValue = 255;
            data->modifyArrows.maxDigits = 3;
            data->modifyArrows.modifiedValPtr = &subHp;
            gBattleMons[data->battlerId].volatiles.substituteHP = subHp;
            data->modifyArrows.typeOfVal = VAR_SUBSTITUTE;
            data->modifyArrows.currValue = gBattleMons[data->battlerId].volatiles.substituteHP;
        }
        else if (data->currentSecondaryListItemId == VARIOUS_IN_LOVE)
        {
            data->modifyArrows.minValue = 0;
            data->modifyArrows.maxValue = 1;
            data->modifyArrows.maxDigits = 1;
            data->modifyArrows.modifiedValPtr = NULL;
            data->modifyArrows.typeOfVal = VAR_IN_LOVE;
            data->modifyArrows.currValue = gBattleMons[data->battlerId].volatiles.infatuation;
        }
        break;
    case LIST_ITEM_STATUS1:
        data->modifyArrows.modifiedValPtr = &gBattleMons[data->battlerId].status1;
        data->modifyArrows.currValue = GetBitfieldValue(gBattleMons[data->battlerId].status1, data->bitfield[data->currentSecondaryListItemId].currBit, data->bitfield[data->currentSecondaryListItemId].bitsCount);
        data->modifyArrows.typeOfVal = VAL_BITFIELD_32;
        goto CASE_ITEM_STATUS;
    case LIST_ITEM_VOLATILE:
        data->modifyArrows.currValue = GetBattlerVolatile(data->battlerId, data->currentSecondaryListItemId);
        data->modifyArrows.typeOfVal = VAL_VOLATILE;
        data->modifyArrows.minValue = 0;
#define UNPACK_VOLATILE_MAX_SIZE(_enum, _fieldName, _typeMaxValue, ...) case _enum: data->modifyArrows.maxValue = min(MAX_u16, GET_VOLATILE_MAXIMUM(_typeMaxValue)); break;
        switch (data->currentSecondaryListItemId)
        {
        VOLATILE_DEFINITIONS(UNPACK_VOLATILE_MAX_SIZE)
        /* Expands to the following:
            * case VOLATILE_CONFUSION:
                data->modifyArrows.maxValue = MAX_BITS(3); // Max value 7
                break;
            * case VOLATILE_FLINCHED:
                data->modifyArrows.maxValue = MAX_BITS(1); // Max value 1
                break;
            * ...etc.
            */
        default:
            data->modifyArrows.maxValue = 0;
        }
        data->modifyArrows.maxDigits = MAX_DIGITS(data->modifyArrows.maxValue);
        break;
    case LIST_ITEM_AI:
        data->modifyArrows.modifiedValPtr = &gAiThinkingStruct->aiFlags[data->battlerId];
        data->modifyArrows.currValue = GetBitfieldValue(gAiThinkingStruct->aiFlags[data->battlerId], data->bitfield[data->currentSecondaryListItemId].currBit, data->bitfield[data->currentSecondaryListItemId].bitsCount);
        data->modifyArrows.typeOfVal = VAL_BITFIELD_32;
        goto CASE_ITEM_STATUS;
    CASE_ITEM_STATUS:
        data->modifyArrows.minValue = 0;
        data->modifyArrows.maxValue = (1 << data->bitfield[data->currentSecondaryListItemId].bitsCount) - 1;
        data->modifyArrows.maxDigits = MAX_DIGITS(data->modifyArrows.maxValue);
        break;
    case LIST_ITEM_HAZARDS:
        data->modifyArrows.minValue = 0;
        switch (data->currentSecondaryListItemId)
        {
        case LIST_SIDE_SPIKES:
            data->modifyArrows.maxValue = 3;
            break;
        case LIST_SIDE_TOXIC_SPIKES:
            data->modifyArrows.maxValue = 2;
            break;
        case LIST_SIDE_STICKY_WEB:
        case LIST_SIDE_STEALTH_ROCK:
        case LIST_SIDE_STEELSURGE:
            data->modifyArrows.maxValue = 1;
            break;
        }
        data->modifyArrows.maxDigits = 2;
        data->modifyArrows.typeOfVal = VAL_HAZARDS;
        data->modifyArrows.currValue = GetHazardsValue(data);
        break;
    case LIST_ITEM_SIDE_STATUS:
        data->modifyArrows.minValue = 0;
        data->modifyArrows.maxValue = 9;
        data->modifyArrows.maxDigits = 2;
        data->modifyArrows.modifiedValPtr = &gSideStatuses[GetBattlerSide(data->battlerId)];
        data->modifyArrows.typeOfVal = VAR_SIDE_STATUS;
        data->modifyArrows.currValue = *GetSideStatusValue(data, FALSE, FALSE);
        break;
    }

    data->modifyArrows.currentDigit = 0;
    ValueToCharDigits(data->modifyArrows.charDigits, data->modifyArrows.currValue, data->modifyArrows.maxDigits);
}

static bool32 TryMoveDigit(struct BattleDebugModifyArrows *modArrows, bool32 moveUp)
{
    s32 i;
    u8 charDigits[MAX_MODIFY_DIGITS];
    u32 newValue;

    for (i = 0; i < MAX_MODIFY_DIGITS; i++)
        charDigits[i] = modArrows->charDigits[i];

    if (moveUp)
    {
        if (charDigits[modArrows->currentDigit] == CHAR_9)
        {
            charDigits[modArrows->currentDigit] = CHAR_0;
            for (i = modArrows->currentDigit - 1; i >= 0; i--)
            {
                if (charDigits[i] == CHAR_9)
                {
                    charDigits[i] = CHAR_0;
                }
                else
                {
                    charDigits[i]++;
                    break;
                }
            }
        }
        else
            charDigits[modArrows->currentDigit]++;
    }
    else
    {
        if (charDigits[modArrows->currentDigit] == CHAR_0)
        {
            charDigits[modArrows->currentDigit] = CHAR_9;
            for (i = modArrows->currentDigit - 1; i >= 0; i--)
            {
                if (charDigits[i] == CHAR_0)
                {
                    charDigits[i] = CHAR_9;
                }
                else
                {
                    charDigits[i]--;
                    break;
                }
            }
        }
        else
            charDigits[modArrows->currentDigit]--;
    }

    newValue = CharDigitsToValue(charDigits, modArrows->maxDigits);
    if (newValue > modArrows->maxValue || newValue < modArrows->minValue)
    {
        return FALSE;
    }
    else
    {
        modArrows->currValue = newValue;
        for (i = 0; i < MAX_MODIFY_DIGITS; i++)
             modArrows->charDigits[i] = charDigits[i];
        return TRUE;
    }
}

static void UpdateMonData(struct BattleDebugMenu *data)
{
    s32 i, j;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        if (data->battlerWasChanged[i])
        {
            struct Pokemon *mon = GetBattlerMon(i);
            struct BattlePokemon *battleMon = &gBattleMons[i];

            SetMonData(mon, MON_DATA_HELD_ITEM, &battleMon->item);
            SetMonData(mon, MON_DATA_STATUS, &battleMon->status1);
            SetMonData(mon, MON_DATA_HP, &battleMon->hp);
            SetMonData(mon, MON_DATA_MAX_HP, &battleMon->maxHP);
            for (j = 0; j < 4; j++)
                SetMonData(mon, MON_DATA_MOVE1 + j, &battleMon->moves[j]);
        }
    }
}

static const u8 *const sHoldEffectNames[HOLD_EFFECT_COUNT] =
{
    [HOLD_EFFECT_NONE]             = COMPOUND_STRING("????????"),
    [HOLD_EFFECT_RESTORE_HP]       = COMPOUND_STRING("Restore Hp"),
    [HOLD_EFFECT_CURE_PAR]         = COMPOUND_STRING("Cure Par"),
    [HOLD_EFFECT_CURE_SLP]         = COMPOUND_STRING("Cure Slp"),
    [HOLD_EFFECT_CURE_PSN]         = COMPOUND_STRING("Cure Psn"),
    [HOLD_EFFECT_CURE_BRN]         = COMPOUND_STRING("Cure Brn"),
    [HOLD_EFFECT_CURE_FRZ]         = COMPOUND_STRING("Cure Frz"),
    [HOLD_EFFECT_RESTORE_PP]       = COMPOUND_STRING("Restore Pp"),
    [HOLD_EFFECT_CURE_CONFUSION]   = COMPOUND_STRING("Cure Confusion"),
    [HOLD_EFFECT_CURE_STATUS]      = COMPOUND_STRING("Cure Status"),
    [HOLD_EFFECT_CONFUSE_FLAVOR]   = COMPOUND_STRING("Confuse Flavor"),
    [HOLD_EFFECT_ATTACK_UP]        = COMPOUND_STRING("Attack Up"),
    [HOLD_EFFECT_DEFENSE_UP]       = COMPOUND_STRING("Defense Up"),
    [HOLD_EFFECT_SPEED_UP]         = COMPOUND_STRING("Speed Up"),
    [HOLD_EFFECT_SP_ATTACK_UP]     = COMPOUND_STRING("Sp Attack Up"),
    [HOLD_EFFECT_SP_DEFENSE_UP]    = COMPOUND_STRING("Sp Defense Up"),
    [HOLD_EFFECT_CRITICAL_UP]      = COMPOUND_STRING("Critical Up"),
    [HOLD_EFFECT_RANDOM_STAT_UP]   = COMPOUND_STRING("Random Stat Up"),
    [HOLD_EFFECT_EVASION_UP]       = COMPOUND_STRING("Evasion Up"),
    [HOLD_EFFECT_WHITE_HERB]       = COMPOUND_STRING("Restore Stats"),
    [HOLD_EFFECT_MACHO_BRACE]      = COMPOUND_STRING("Macho Brace"),
    [HOLD_EFFECT_EXP_SHARE]        = COMPOUND_STRING("Exp Share"),
    [HOLD_EFFECT_QUICK_CLAW]       = COMPOUND_STRING("Quick Claw"),
    [HOLD_EFFECT_FRIENDSHIP_UP]    = COMPOUND_STRING("Friendship Up"),
    [HOLD_EFFECT_MENTAL_HERB]      = COMPOUND_STRING("Mental Herb"),
    [HOLD_EFFECT_CHOICE_BAND]      = COMPOUND_STRING("Choice Band"),
    [HOLD_EFFECT_FLINCH]           = COMPOUND_STRING("Flinch"),
    [HOLD_EFFECT_DOUBLE_PRIZE]     = COMPOUND_STRING("Double Prize"),
    [HOLD_EFFECT_REPEL]            = COMPOUND_STRING("Repel"),
    [HOLD_EFFECT_SOUL_DEW]         = COMPOUND_STRING("Soul Dew"),
    [HOLD_EFFECT_DEEP_SEA_TOOTH]   = COMPOUND_STRING("Deep Sea Tooth"),
    [HOLD_EFFECT_DEEP_SEA_SCALE]   = COMPOUND_STRING("Deep Sea Scale"),
    [HOLD_EFFECT_CAN_ALWAYS_RUN]   = COMPOUND_STRING("Can Always Run"),
    [HOLD_EFFECT_PREVENT_EVOLVE]   = COMPOUND_STRING("Prevent Evolve"),
    [HOLD_EFFECT_FOCUS_BAND]       = COMPOUND_STRING("Focus Band"),
    [HOLD_EFFECT_LUCKY_EGG]        = COMPOUND_STRING("Lucky Egg"),
    [HOLD_EFFECT_SCOPE_LENS]       = COMPOUND_STRING("Scope Lens"),
    [HOLD_EFFECT_LEFTOVERS]        = COMPOUND_STRING("Leftovers"),
    [HOLD_EFFECT_LIGHT_BALL]       = COMPOUND_STRING("Light Ball"),
    [HOLD_EFFECT_TYPE_POWER]       = COMPOUND_STRING("Type Power"),
    [HOLD_EFFECT_SHELL_BELL]       = COMPOUND_STRING("Shell Bell"),
    [HOLD_EFFECT_LUCKY_PUNCH]      = COMPOUND_STRING("Lucky Punch"),
    [HOLD_EFFECT_METAL_POWDER]     = COMPOUND_STRING("Metal Powder"),
    [HOLD_EFFECT_THICK_CLUB]       = COMPOUND_STRING("Thick Club"),
    [HOLD_EFFECT_LEEK]             = COMPOUND_STRING("Leek"),
    [HOLD_EFFECT_CHOICE_SCARF]     = COMPOUND_STRING("Choice Scarf"),
    [HOLD_EFFECT_CHOICE_SPECS]     = COMPOUND_STRING("Choice Specs"),
    [HOLD_EFFECT_DAMP_ROCK]        = COMPOUND_STRING("Damp Rock"),
    [HOLD_EFFECT_GRIP_CLAW]        = COMPOUND_STRING("Grip Claw"),
    [HOLD_EFFECT_HEAT_ROCK]        = COMPOUND_STRING("Heat Rock"),
    [HOLD_EFFECT_ICY_ROCK]         = COMPOUND_STRING("Icy Rock"),
    [HOLD_EFFECT_LIGHT_CLAY]       = COMPOUND_STRING("Light Clay"),
    [HOLD_EFFECT_SMOOTH_ROCK]      = COMPOUND_STRING("Smooth Rock"),
    [HOLD_EFFECT_POWER_HERB]       = COMPOUND_STRING("Power Herb"),
    [HOLD_EFFECT_BIG_ROOT]         = COMPOUND_STRING("Big Root"),
    [HOLD_EFFECT_EXPERT_BELT]      = COMPOUND_STRING("Expert Belt"),
    [HOLD_EFFECT_LIFE_ORB]         = COMPOUND_STRING("Life Orb"),
    [HOLD_EFFECT_METRONOME]        = COMPOUND_STRING("Metronome"),
    [HOLD_EFFECT_MUSCLE_BAND]      = COMPOUND_STRING("Muscle Band"),
    [HOLD_EFFECT_WIDE_LENS]        = COMPOUND_STRING("Wide Lens"),
    [HOLD_EFFECT_WISE_GLASSES]     = COMPOUND_STRING("Wise Glasses"),
    [HOLD_EFFECT_ZOOM_LENS]        = COMPOUND_STRING("Zoom Lens"),
    [HOLD_EFFECT_LAGGING_TAIL]     = COMPOUND_STRING("Lagging Tail"),
    [HOLD_EFFECT_FOCUS_SASH]       = COMPOUND_STRING("Focus Sash"),
    [HOLD_EFFECT_FLAME_ORB]        = COMPOUND_STRING("Flame Orb"),
    [HOLD_EFFECT_TOXIC_ORB]        = COMPOUND_STRING("Toxic Orb"),
    [HOLD_EFFECT_STICKY_BARB]      = COMPOUND_STRING("Sticky Barb"),
    [HOLD_EFFECT_IRON_BALL]        = COMPOUND_STRING("Iron Ball"),
    [HOLD_EFFECT_BLACK_SLUDGE]     = COMPOUND_STRING("Black Sludge"),
    [HOLD_EFFECT_DESTINY_KNOT]     = COMPOUND_STRING("Destiny Knot"),
    [HOLD_EFFECT_SHED_SHELL]       = COMPOUND_STRING("Shed Shell"),
    [HOLD_EFFECT_QUICK_POWDER]     = COMPOUND_STRING("Quick Powder"),
    [HOLD_EFFECT_ADAMANT_ORB]      = COMPOUND_STRING("Adamant Orb"),
    [HOLD_EFFECT_LUSTROUS_ORB]     = COMPOUND_STRING("Lustrous Orb"),
    [HOLD_EFFECT_GRISEOUS_ORB]     = COMPOUND_STRING("Griseous Orb"),
    [HOLD_EFFECT_ENIGMA_BERRY]     = COMPOUND_STRING("Enigma Berry"),
    [HOLD_EFFECT_RESIST_BERRY]     = COMPOUND_STRING("Resist Berry"),
    [HOLD_EFFECT_POWER_ITEM]       = COMPOUND_STRING("Power Item"),
    [HOLD_EFFECT_RESTORE_PCT_HP]   = COMPOUND_STRING("Restore Pct Hp"),
    [HOLD_EFFECT_MICLE_BERRY]      = COMPOUND_STRING("Micle Berry"),
    [HOLD_EFFECT_CUSTAP_BERRY]     = COMPOUND_STRING("Custap Berry"),
    [HOLD_EFFECT_JABOCA_BERRY]     = COMPOUND_STRING("Jaboca Berry"),
    [HOLD_EFFECT_ROWAP_BERRY]      = COMPOUND_STRING("Rowap Berry"),
    [HOLD_EFFECT_KEE_BERRY]        = COMPOUND_STRING("Kee Berry"),
    [HOLD_EFFECT_MARANGA_BERRY]    = COMPOUND_STRING("Maranga Berry"),
    [HOLD_EFFECT_PLATE]            = COMPOUND_STRING("Plate"),
    [HOLD_EFFECT_FLOAT_STONE]      = COMPOUND_STRING("Float Stone"),
    [HOLD_EFFECT_EVIOLITE]         = COMPOUND_STRING("Eviolite"),
    [HOLD_EFFECT_ASSAULT_VEST]     = COMPOUND_STRING("Assault Vest"),
    [HOLD_EFFECT_DRIVE]            = COMPOUND_STRING("Drive"),
    [HOLD_EFFECT_GEMS]             = COMPOUND_STRING("Gems"),
    [HOLD_EFFECT_ROCKY_HELMET]     = COMPOUND_STRING("Rocky Helmet"),
    [HOLD_EFFECT_AIR_BALLOON]      = COMPOUND_STRING("Air Balloon"),
    [HOLD_EFFECT_RED_CARD]         = COMPOUND_STRING("Red Card"),
    [HOLD_EFFECT_RING_TARGET]      = COMPOUND_STRING("Ring Target"),
    [HOLD_EFFECT_BINDING_BAND]     = COMPOUND_STRING("Binding Band"),
    [HOLD_EFFECT_EJECT_BUTTON]     = COMPOUND_STRING("Eject Button"),
    [HOLD_EFFECT_ABSORB_BULB]      = COMPOUND_STRING("Absorb Bulb"),
    [HOLD_EFFECT_CELL_BATTERY]     = COMPOUND_STRING("Cell Battery"),
    [HOLD_EFFECT_MEGA_STONE]       = COMPOUND_STRING("Mega Stone"),
    [HOLD_EFFECT_SAFETY_GOGGLES]   = COMPOUND_STRING("Safety Goggles"),
    [HOLD_EFFECT_LUMINOUS_MOSS]    = COMPOUND_STRING("Luminous Moss"),
    [HOLD_EFFECT_SNOWBALL]         = COMPOUND_STRING("Snowball"),
    [HOLD_EFFECT_WEAKNESS_POLICY]  = COMPOUND_STRING("Weakness Policy"),
    [HOLD_EFFECT_PRIMAL_ORB]       = COMPOUND_STRING("Primal Orb"),
    [HOLD_EFFECT_PROTECTIVE_PADS]  = COMPOUND_STRING("Protective Pads"),
    [HOLD_EFFECT_TERRAIN_EXTENDER] = COMPOUND_STRING("Terrain Extender"),
    [HOLD_EFFECT_TERRAIN_SEED]     = COMPOUND_STRING("Seeds"),
    [HOLD_EFFECT_ADRENALINE_ORB]   = COMPOUND_STRING("Adrenaline Orb"),
    [HOLD_EFFECT_MEMORY]           = COMPOUND_STRING("Memory"),
    [HOLD_EFFECT_Z_CRYSTAL]        = COMPOUND_STRING("Z-Crystal"),
    [HOLD_EFFECT_UTILITY_UMBRELLA] = COMPOUND_STRING("Utility Umbrella"),
    [HOLD_EFFECT_EJECT_PACK]       = COMPOUND_STRING("Eject Pack"),
    [HOLD_EFFECT_ROOM_SERVICE]     = COMPOUND_STRING("Room Service"),
    [HOLD_EFFECT_BLUNDER_POLICY]   = COMPOUND_STRING("Blunder Policy"),
    [HOLD_EFFECT_HEAVY_DUTY_BOOTS] = COMPOUND_STRING("Heavy Duty Boots"),
    [HOLD_EFFECT_THROAT_SPRAY]     = COMPOUND_STRING("Throat Spray"),
    [HOLD_EFFECT_ABILITY_SHIELD]   = COMPOUND_STRING("Ability Shield"),
    [HOLD_EFFECT_CLEAR_AMULET]     = COMPOUND_STRING("Clear Amulet"),
    [HOLD_EFFECT_MIRROR_HERB]      = COMPOUND_STRING("Mirror Herb"),
    [HOLD_EFFECT_PUNCHING_GLOVE]   = COMPOUND_STRING("Punching Glove"),
    [HOLD_EFFECT_COVERT_CLOAK]     = COMPOUND_STRING("Covert Cloak"),
    [HOLD_EFFECT_LOADED_DICE]      = COMPOUND_STRING("Loaded Dice"),
    [HOLD_EFFECT_BOOSTER_ENERGY]   = COMPOUND_STRING("Booster Energy"),
    [HOLD_EFFECT_OGERPON_MASK]     = COMPOUND_STRING("Ogerpon Mask"),
    [HOLD_EFFECT_BERSERK_GENE]     = COMPOUND_STRING("Berserk Gene"),
};

static const u8 *GetHoldEffectName(enum HoldEffect holdEffect)
{
    if (sHoldEffectNames[holdEffect] == NULL)
        return sHoldEffectNames[0];
    return sHoldEffectNames[holdEffect];
}
