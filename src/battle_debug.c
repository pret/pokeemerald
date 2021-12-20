#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_message.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "scanline_effect.h"
#include "palette.h"
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
#include "battle_ai_main.h"
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
#include "constants/moves.h"
#include "constants/items.h"
#include "constants/rgb.h"
#include "constants/hold_effects.h"

#define MAX_MODIFY_DIGITS 4

struct BattleDebugModifyArrows
{
    u8 arrowSpriteId[2];
    u16 minValue;
    u16 maxValue;
    int currValue;
    u8 currentDigit;
    u8 maxDigits;
    u8 charDigits[MAX_MODIFY_DIGITS];
    void *modifiedValPtr;
    u8 typeOfVal;
};

struct BattleDebugMenu
{
    u8 battlerId;
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

    u8 aiBattlerId;
    u8 aiViewState;
    u8 aiIconSpriteIds[MAX_BATTLERS_COUNT];
    u8 aiMonSpriteId;
    u8 aiMovesWindowId;
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
    LIST_ITEM_STATUS2,
    LIST_ITEM_STATUS3,
    LIST_ITEM_STATUS4,
    LIST_ITEM_SIDE_STATUS,
    LIST_ITEM_AI,
    LIST_ITEM_AI_MOVES_PTS,
    LIST_ITEM_AI_INFO,
    LIST_ITEM_VARIOUS,
    LIST_ITEM_COUNT
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
    VAR_SIDE_STATUS,
    VAR_SHOW_HP,
    VAR_SUBSTITUTE,
    VAR_IN_LOVE,
    VAR_U16_4_ENTRIES,
    VAL_S8,
    VAL_ITEM,
    VAL_ALL_STAT_STAGES,
};

enum
{
    LIST_SIDE_REFLECT,
    LIST_SIDE_LIGHTSCREEN,
    LIST_SIDE_SPIKES,
    LIST_SIDE_SAFEGUARD,
    LIST_SIDE_MIST,
    LIST_SIDE_AURORA_VEIL,
    LIST_SIDE_LUCKY_CHANT,
    LIST_SIDE_TAILWIND,
    LIST_SIDE_STEALTH_ROCK,
    LIST_SIDE_TOXIC_SPIKES,
    LIST_SIDE_STICKY_WEB,
};

enum
{
    VARIOUS_SHOW_HP,
    VARIOUS_SUBSTITUTE_HP,
    VARIOUS_IN_LOVE,
};

// Static Declarations
static const u8 *GetHoldEffectName(u16 holdEffect);

// const rom data
static const u8 sText_HoldEffect[] = _("Hold Effect");
static const u8 sText_Ability[] = _("Ability");
static const u8 sText_Moves[] = _("Moves");
static const u8 sText_Stats[] = _("Stats");
static const u8 sText_StatStages[] = _("Stat Stages");
static const u8 sText_Status1[] = _("Status1");
static const u8 sText_Status2[] = _("Status2");
static const u8 sText_Status3[] = _("Status3");
static const u8 sText_Status4[] = _("Status4");
static const u8 sText_HeldItem[] = _("Held Item");
static const u8 sText_SideStatus[] = _("Side Status");
static const u8 sText_MaxHp[] = _("HP Max");
static const u8 sText_CurrHp[] = _("HP Current");
static const u8 sText_Freeze[] = _("Freeze");
static const u8 sText_ToxicPoison[] = _("Toxic Poison");
static const u8 sText_ToxicCounter[] = _("Toxic Counter");
static const u8 sText_Flinch[] = _("Flinch");
static const u8 sText_Uproar[] = _("Uproar");
static const u8 sText_Bide[] = _("Bide");
static const u8 sText_LockConfuse[] = _("Lock Confuse");
static const u8 sText_MultipleTurns[] = _("MultipleTurns");
static const u8 sText_FocusEnergy[] = _("Focus Energy");
static const u8 sText_Transformed[] = _("Transformed");
static const u8 sText_Recharge[] = _("Recharge");
static const u8 sText_Rage[] = _("Rage");
static const u8 sText_Substitute[] = _("Substitute");
static const u8 sText_SubstituteHp[] = _("Substitute HP");
static const u8 sText_DestinyBond[] = _("Destiny Bond");
static const u8 sText_CantEscape[] = _("Cant Escape");
static const u8 sText_Nightmare[] = _("Nightmare");
static const u8 sText_Cursed[] = _("Cursed");
static const u8 sText_Foresight[] = _("Foresighted");
static const u8 sText_DefenseCurl[] = _("Def Curled");
static const u8 sText_Tormented[] = _("Tormented");
static const u8 sText_AlwaysHits[] = _("Sure Hit");
static const u8 sText_ChargedUp[] = _("Charged Up");
static const u8 sText_Rooted[] = _("Rooted");
static const u8 sText_Yawned[] = _("Yawned");
static const u8 sText_Minimized[] = _("Minimized");
static const u8 sText_NoCrit[] = _("No Crit");
static const u8 sText_Imprisoned[] = _("Imprison");
static const u8 sText_Reflect[] = _("Reflect");
static const u8 sText_LightScreen[] = _("Light Screen");
static const u8 sText_Spikes[] = _("Spikes");
static const u8 sText_Safeguard[] = _("Safeguard");
static const u8 sText_Mist[] = _("Mist");
static const u8 sText_ShowOpponentHP[] = _("Opponent Hp");
static const u8 sText_Types[] = _("Types");
static const u8 sText_GastroAcid[] = _("Gastro Acid");
static const u8 sText_SmackDown[] = _("Smacked Down");
static const u8 sText_MiracleEye[] = _("Miracle Eye");
static const u8 sText_AquaRing[] = _("Aqua Ring");
static const u8 sText_LaserFocus[] = _("Laser Focused");
static const u8 sText_Electrified[] = _("Electrified");
static const u8 sText_AuroraVeil[] = _("Aurora Veil");
static const u8 sText_LuckyChant[] = _("Lucky Chant");
static const u8 sText_Tailwind[] = _("Tailwind");
static const u8 sText_PP[] = _("PP");
static const u8 sText_StealthRock[] = _("Stealth Rock");
static const u8 sText_ToxicSpikes[] = _("Toxic Spikes");
static const u8 sText_StickyWeb[] = _("Sticky Web");
static const u8 sText_AI[] = _("AI");
static const u8 sText_NoBadMoves[] = _("No Bad Moves");
static const u8 sText_Viability[] = _("Viability");
static const u8 sText_TryFaint[] = _("Try Faint");
static const u8 sText_SetUpFirstTurn[] = _("Setup 1 turn");
static const u8 sText_Risky[] = _("Risky");
static const u8 sText_StrongestMove[] = _("Most dmg move");
static const u8 sText_Various[] = _("Various");
static const u8 sText_ShowHP[] = _("Show HP");
static const u8 sText_PreferBatonPass[] = _("Baton Pass");
static const u8 sText_InDoubles[] = _("In Doubles");
static const u8 sText_HpAware[] = _("HP aware");
static const u8 sText_Unknown[] = _("Unknown");
static const u8 sText_InLove[] = _("In Love");
static const u8 sText_AIMovePts[] = _("AI Pts/Dmg");
static const u8 sText_AiKnowledge[] = _("AI Info");
static const u8 sText_EffectOverride[] = _("Effect Override");

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
};

static const struct BitfieldInfo sStatus2Bitfield[] =
{
    {/*Confusion*/ 3, 0},
    {/*Flinch*/ 1, 3},
    {/*Uproar*/ 3, 4},
    // Bit 7 is unused.
    {/*Bide*/ 2, 8},
    {/*Lock Confuse*/ 2, 10},
    {/*Multiple Turns*/ 1, 12},
    // Wrap bits are omitted. Done in various.
    // In Love bits are omitted. Done in various.
    {/*Transformed*/ 1, 21},
    {/*Recharge*/ 1, 22},
    {/*Rage*/ 1, 23},
    {/*Substitute*/ 1, 24},
    {/*Destiny bond*/ 1, 25},
    {/*Can't escape*/ 1, 26},
    {/*Nightmares*/ 1, 27},
    {/*Cursed*/ 1, 28},
    {/*Foresighted*/ 1, 29},
    {/*Defense Curled*/ 1, 30},
    {/*Tormented*/ 1, 31},
};

static const struct BitfieldInfo sStatus3Bitfield[] =
{
    {/*Always hits*/ 2, 4},
    //*Perish Song*/ 1, 5},
    // On Air 1, 6,
    // Underground 1, 7,
    {/*Minimized*/ 1, 8},
    {/*Charged Up*/ 1, 9},
    {/*Rooted*/ 1, 10},
    {/*Yawn*/ 2, 11},
    {/*Imprison*/ 1, 13},
    // Grudge 1, 14,
    {/*No Crit*/ 1, 15},
    {/*Gastro Acid*/ 1, 16},
    // Embargo 1, 17,
    // Underwater 1, 18,
    // Intimidated Mons 1, 19,
    // Traced 1, 20,
    {/*Smacked Down*/ 1, 21},
    // Me First 1, 22,
    // Telekinesis 1, 23,
    // Phantom Force 1, 24},
    {/*Miracle Eyed*/ 1, 25},
    // Magnet Rise 1, 26,
    // Heal Block 1, 27,
    {/*Aqua Ring*/ 1, 28},
    {/*Laser Focus*/ 1, 29},
    // Power Trick 1, 30,
};

static const struct BitfieldInfo sStatus4Bitfield[] =
{
    {/*Electrified*/ 1, 0,}
};

static const struct BitfieldInfo sAIBitfield[] =
{
    {/*Check bad move*/ 1, 0},
    {/*Try To Faint*/ 1, 1},
    {/*Viability*/ 1, 2},
    {/*Set up first turn*/ 1, 3},
    {/*Risky*/ 1, 4},
    {/*Prefer Strongest Move*/ 1, 5},
    {/*Prefer Baton Pass*/ 1, 6},
    {/*In Doubles*/ 1, 7},
    {/*Hp aware*/ 1, 8},
    {/*Unknown*/ 1, 9},
};


static const struct ListMenuItem sMainListItems[] =
{
    {sText_Moves, LIST_ITEM_MOVES},
    {sText_Ability, LIST_ITEM_ABILITY},
    {sText_HeldItem, LIST_ITEM_HELD_ITEM},
    {sText_PP, LIST_ITEM_PP},
    {sText_Types, LIST_ITEM_TYPES},
    {sText_Stats, LIST_ITEM_STATS},
    {sText_StatStages, LIST_ITEM_STAT_STAGES},
    {sText_Status1, LIST_ITEM_STATUS1},
    {sText_Status2, LIST_ITEM_STATUS2},
    {sText_Status3, LIST_ITEM_STATUS3},
    {sText_Status4, LIST_ITEM_STATUS4},
    {sText_SideStatus, LIST_ITEM_SIDE_STATUS},
    {sText_AI, LIST_ITEM_AI},
    {sText_AIMovePts, LIST_ITEM_AI_MOVES_PTS},
    {sText_AiKnowledge, LIST_ITEM_AI_INFO},
    {sText_Various, LIST_ITEM_VARIOUS},
};

static const struct ListMenuItem sVariousListItems[] =
{
    {sText_ShowHP, VARIOUS_SHOW_HP},
    {sText_SubstituteHp, VARIOUS_SUBSTITUTE_HP},
    {sText_InLove, VARIOUS_IN_LOVE},
};

static const struct ListMenuItem sAIListItems[] =
{
    {sText_NoBadMoves, 0},
    {sText_TryFaint, 1},
    {sText_Viability, 2},
    {sText_SetUpFirstTurn, 3},
    {sText_Risky, 4},
    {sText_StrongestMove, 5},
    {sText_PreferBatonPass, 6},
    {sText_InDoubles, 7},
    {sText_HpAware, 8},
    // {sText_Unknown, 9},
};

static const struct ListMenuItem sStatsListItems[] =
{
    {sText_CurrHp, 0},
    {sText_MaxHp, 1},
    {gText_Attack, 2},
    {gText_Defense, 3},
    {gText_Speed, 4},
    {gText_SpAtk, 5},
    {gText_SpDef, 6},
};

static const struct ListMenuItem sStatus1ListItems[] =
{
    {gText_Sleep, 0},
    {gText_Poison, 1},
    {gText_Burn, 2},
    {sText_Freeze, 3},
    {gText_Paralysis, 4},
    {sText_ToxicPoison, 5},
    {sText_ToxicCounter, 6},
};

static const struct ListMenuItem sStatus2ListItems[] =
{
    {gText_Confusion, 0},
    {sText_Flinch, 1},
    {sText_Uproar, 2},
    {sText_Bide, 3},
    {sText_LockConfuse, 4},
    {sText_MultipleTurns, 5},
    {sText_FocusEnergy, 6},
    {sText_Recharge, 7},
    {sText_Rage, 8},
    {sText_Substitute, 9},
    {sText_DestinyBond, 10},
    {sText_CantEscape, 11},
    {sText_Nightmare, 12},
    {sText_Cursed, 13},
    {sText_Foresight, 14},
    {sText_DefenseCurl, 15},
    {sText_Tormented, 16},
};

static const struct ListMenuItem sStatus3ListItems[] =
{
    {sText_AlwaysHits, 0},
    {sText_Minimized, 1},
    {sText_ChargedUp, 2},
    {sText_Rooted, 3},
    {sText_Yawned, 4},
    {sText_Imprisoned, 5},
    {sText_NoCrit, 6},
    {sText_GastroAcid, 7},
    {sText_SmackDown, 8},
    {sText_MiracleEye, 9},
    {sText_AquaRing, 10},
    {sText_LaserFocus, 11},
};

static const struct ListMenuItem sStatus4ListItems[] =
{
    {sText_Electrified, 0},
};

static const struct ListMenuItem sSideStatusListItems[] =
{
    {sText_Reflect, LIST_SIDE_REFLECT},
    {sText_LightScreen, LIST_SIDE_LIGHTSCREEN},
    {sText_Spikes, LIST_SIDE_SPIKES},
    {sText_Safeguard, LIST_SIDE_SAFEGUARD},
    {sText_Mist, LIST_SIDE_MIST},
    {sText_AuroraVeil, LIST_SIDE_AURORA_VEIL},
    {sText_LuckyChant, LIST_SIDE_LUCKY_CHANT},
    {sText_Tailwind, LIST_SIDE_TAILWIND},
    {sText_StealthRock, LIST_SIDE_STEALTH_ROCK},
    {sText_ToxicSpikes, LIST_SIDE_TOXIC_SPIKES},
    {sText_StickyWeb, LIST_SIDE_STICKY_WEB},
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
    .baseBlock = 0x2
};

static const struct WindowTemplate sSecondaryListWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 12,
    .tilemapTop = 3,
    .width = 10,
    .height = 2,
    .paletteNum = 0xF,
    .baseBlock = 0xA0
};

static const struct WindowTemplate sModifyWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 25,
    .tilemapTop = 2,
    .width = 4,
    .height = 2,
    .paletteNum = 0xF,
    .baseBlock = 0x200
};

static const struct WindowTemplate sBattlerWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 10,
    .tilemapTop = 0,
    .width = 14,
    .height = 2,
    .paletteNum = 0xF,
    .baseBlock = 0x300
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

static const u8 sBitsToMaxDigit[] =
{
    [0] = 0,
    [1] = 1, // max 1
    [2] = 1, // max 3
    [3] = 1, // max 7
    [4] = 2, // max 15
    [5] = 2, // max 31
    [6] = 2, // max 63
    [7] = 3, // max 127
    [8] = 3, // max 255
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
static void PrintOnBattlerWindow(u8 windowId, u8 battlerId);
static void UpdateWindowsOnChangedBattler(struct BattleDebugMenu *data);
static void CreateSecondaryListMenu(struct BattleDebugMenu *data);
static void PrintSecondaryEntries(struct BattleDebugMenu *data);
static void DestroyModifyArrows(struct BattleDebugMenu *data);
static void PrintDigitChars(struct BattleDebugMenu *data);
static void SetUpModifyArrows(struct BattleDebugMenu *data);
static void UpdateBattlerValue(struct BattleDebugMenu *data);
static void UpdateMonData(struct BattleDebugMenu *data);
static u8 *GetSideStatusValue(struct BattleDebugMenu *data, bool32 changeStatus, bool32 statusTrue);
static bool32 TryMoveDigit(struct BattleDebugModifyArrows *modArrows, bool32 moveUp);
static void SwitchToDebugView(u8 taskId);

// code
static struct BattleDebugMenu *GetStructPtr(u8 taskId)
{
    u8 *taskDataPtr = (u8*)(&gTasks[taskId].data[0]);

    return (struct BattleDebugMenu*)(T1_READ_PTR(taskDataPtr));
}

static void SetStructPtr(u8 taskId, void *ptr)
{
    u32 structPtr = (u32)(ptr);
    u8 *taskDataPtr = (u8*)(&gTasks[taskId].data[0]);

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
        FreeAllWindowBuffers();
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
        LoadPalette(sBgColor, 0, 2);
        LoadPalette(GetOverworldTextboxPalettePtr(), 0xf0, 16);
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
        CopyWindowToVram(data->mainListWindowId, 3);
        gMain.state++;
        break;
    case 5:
        BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        return;
    }
}

static void PutMovesPointsText(struct BattleDebugMenu *data)
{
    u32 i, j, count;
    u8 *text = malloc(0x50);

    FillWindowPixelBuffer(data->aiMovesWindowId, 0x11);
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        text[0] = CHAR_SPACE;
        StringCopy(text + 1, gMoveNames[gBattleMons[data->aiBattlerId].moves[i]]);
        AddTextPrinterParameterized(data->aiMovesWindowId, 1, text, 0, i * 15, 0, NULL);
        for (count = 0, j = 0; j < MAX_BATTLERS_COUNT; j++)
        {
            if (data->aiIconSpriteIds[j] == 0xFF)
                continue;
            ConvertIntToDecimalStringN(text,
                                       gBattleStruct->aiFinalScore[data->aiBattlerId][gSprites[data->aiIconSpriteIds[j]].data[0]][i],
                                       STR_CONV_MODE_RIGHT_ALIGN, 3);
            AddTextPrinterParameterized(data->aiMovesWindowId, 1, text, 83 + count * 54, i * 15, 0, NULL);

            ConvertIntToDecimalStringN(text,
                                       gBattleStruct->aiSimulatedDamage[data->aiBattlerId][gSprites[data->aiIconSpriteIds[j]].data[0]][i],
                                       STR_CONV_MODE_RIGHT_ALIGN, 3);
            AddTextPrinterParameterized(data->aiMovesWindowId, 1, text, 110 + count * 54, i * 15, 0, NULL);

            count++;
        }
    }

    CopyWindowToVram(data->aiMovesWindowId, 3);
    free(text);
}

static void Task_ShowAiPoints(u8 taskId)
{
    u32 i, count;
    struct WindowTemplate winTemplate;
    struct BattleDebugMenu *data = GetStructPtr(taskId);

    switch (data->aiViewState)
    {
    case 0:
        HideBg(0);
        ShowBg(1);

        // Swap battler if it's player mon
        data->aiBattlerId = data->battlerId;
        while (!IsBattlerAIControlled(data->aiBattlerId))
        {
            if (++data->aiBattlerId >= gBattlersCount)
                data->aiBattlerId = 0;
        }

        LoadMonIconPalettes();
        for (count = 0, i = 0; i < MAX_BATTLERS_COUNT; i++)
        {
            if (i != data->aiBattlerId && IsBattlerAlive(i))
            {
            #ifndef POKEMON_EXPANSION
                data->aiIconSpriteIds[i] = CreateMonIcon(gBattleMons[i].species,
                                                         SpriteCallbackDummy,
                                                         95 + (count * 60), 17, 0, 0, FALSE);
            #else
                data->aiIconSpriteIds[i] = CreateMonIcon(gBattleMons[i].species,
                                                         SpriteCallbackDummy,
                                                         95 + (count * 60), 17, 0, 0);
            #endif
                gSprites[data->aiIconSpriteIds[i]].data[0] = i; // battler id
                count++;
            }
            else
            {
                data->aiIconSpriteIds[i] = 0xFF;
            }
        }
        #ifndef POKEMON_EXPANSION
        data->aiMonSpriteId = CreateMonPicSprite_HandleDeoxys(gBattleMons[data->aiBattlerId].species,
                                                 gBattleMons[data->aiBattlerId].otId,
                                                 gBattleMons[data->aiBattlerId].personality,
                                                 TRUE,
                                                 39, 130, 15, TAG_NONE);
        #else
        data->aiMonSpriteId = CreateMonPicSprite(gBattleMons[data->aiBattlerId].species,
                                                 gBattleMons[data->aiBattlerId].otId,
                                                 gBattleMons[data->aiBattlerId].personality,
                                                 TRUE,
                                                 39, 130, 15, TAG_NONE);
        #endif
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
        if (gMain.newKeys & (SELECT_BUTTON | B_BUTTON))
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
    u32 i, j, count;
    u8 *text = malloc(0x50);

    FillWindowPixelBuffer(data->aiMovesWindowId, 0x11);
    
    // item names
    for (i = 0; i < ARRAY_COUNT(sAiInfoItemNames); i++)
    {
        AddTextPrinterParameterized(data->aiMovesWindowId, 1, sAiInfoItemNames[i], 3, i * 15, 0, NULL);
    }
    
    // items info
    for (i = 0; i < gBattlersCount; i++)
    {
        if (GET_BATTLER_SIDE(i) == B_SIDE_PLAYER && IsBattlerAlive(i))
        {
            u16 ability = AI_GetAbility(i);
            u16 holdEffect = AI_GetHoldEffect(i);
            u16 item = gBattleMons[i].item;
            u8 x = (i == B_POSITION_PLAYER_LEFT) ? 83 + (i) * 75 : 83 + (i-1) * 75;
            AddTextPrinterParameterized(data->aiMovesWindowId, 0, gAbilityNames[ability], x, 0, 0, NULL);
            AddTextPrinterParameterized(data->aiMovesWindowId, 0, ItemId_GetName(item), x, 15, 0, NULL);
            AddTextPrinterParameterized(data->aiMovesWindowId, 0, GetHoldEffectName(holdEffect), x, 30, 0, NULL);
        }
    }

    CopyWindowToVram(data->aiMovesWindowId, 3);
    free(text);
}

static void Task_ShowAiKnowledge(u8 taskId)
{
    u32 i, count;
    struct WindowTemplate winTemplate;
    struct BattleDebugMenu *data = GetStructPtr(taskId);

    switch (data->aiViewState)
    {
    case 0:
        HideBg(0);
        ShowBg(1);

        // Swap battler if it's player mon
        data->aiBattlerId = data->battlerId;
        while (!IsBattlerAIControlled(data->aiBattlerId))
        {
            if (++data->aiBattlerId >= gBattlersCount)
                data->aiBattlerId = 0;
        }

        LoadMonIconPalettes();
        for (count = 0, i = 0; i < MAX_BATTLERS_COUNT; i++)
        {
            if (GET_BATTLER_SIDE(i) == B_SIDE_PLAYER && IsBattlerAlive(i))
            {
            #ifndef POKEMON_EXPANSION
                data->aiIconSpriteIds[i] = CreateMonIcon(gBattleMons[i].species,
                                                         SpriteCallbackDummy,
                                                         95 + (count * 80), 17, 0, 0, FALSE);
            #else
                data->aiIconSpriteIds[i] = CreateMonIcon(gBattleMons[i].species,
                                                         SpriteCallbackDummy,
                                                         95 + (count * 80), 17, 0, 0);
            #endif
                gSprites[data->aiIconSpriteIds[i]].data[0] = i; // battler id
                count++;
            }
            else
            {
                data->aiIconSpriteIds[i] = 0xFF;
            }
        }
        #ifndef POKEMON_EXPANSION
        data->aiMonSpriteId = CreateMonPicSprite_HandleDeoxys(gBattleMons[data->aiBattlerId].species,
                                                 gBattleMons[data->aiBattlerId].otId,
                                                 gBattleMons[data->aiBattlerId].personality,
                                                 TRUE,
                                                 39, 130, 15, TAG_NONE);
        #else
        data->aiMonSpriteId = CreateMonPicSprite(gBattleMons[data->aiBattlerId].species,
                                                 gBattleMons[data->aiBattlerId].otId,
                                                 gBattleMons[data->aiBattlerId].personality,
                                                 TRUE,
                                                 39, 130, 15, TAG_NONE);
        #endif
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
        if (gMain.newKeys & (SELECT_BUTTON | B_BUTTON))
        {
            SwitchToDebugView(taskId);
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

static void SwitchToDebugView(u8 taskId)
{
    u32 i;
    struct BattleDebugMenu *data = GetStructPtr(taskId);

    FreeMonIconPalettes();
    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        if (data->aiIconSpriteIds[i] != 0xFF)
            FreeAndDestroyMonIconSprite(&gSprites[data->aiIconSpriteIds[i]]);
    }
    FreeAndDestroyMonPicSprite(data->aiMonSpriteId);
    RemoveWindow(data->aiMovesWindowId);

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
    if (gMain.newKeys & SELECT_BUTTON)
    {
        BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
        gTasks[taskId].func = Task_DebugMenuFadeOut;
        return;
    }

    // Try changing active battler.
    if (gMain.newKeys & R_BUTTON)
    {
        if (data->battlerId++ == gBattlersCount - 1)
            data->battlerId = 0;
        UpdateWindowsOnChangedBattler(data);
    }
    else if (gMain.newKeys & L_BUTTON)
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
            if (listItemId == LIST_ITEM_AI_MOVES_PTS && gMain.newKeys & A_BUTTON)
            {
                SwitchToAiPointsView(taskId);
                return;
            }
            else if (listItemId == LIST_ITEM_AI_INFO && gMain.newKeys & A_BUTTON)
            {
                SwitchToAiInfoView(taskId);
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
            CopyWindowToVram(data->modifyWindowId, 3);
            SetUpModifyArrows(data);
            PrintDigitChars(data);
            data->activeWindow = ACTIVE_WIN_MODIFY;
        }
    }
    // Handle value modifying.
    else if (data->activeWindow == ACTIVE_WIN_MODIFY)
    {
        if (gMain.newKeys & (B_BUTTON | A_BUTTON))
        {
            ClearStdWindowAndFrameToTransparent(data->modifyWindowId, TRUE);
            RemoveWindow(data->modifyWindowId);
            DestroyModifyArrows(data);
            data->activeWindow = ACTIVE_WIN_SECONDARY;
        }
        else if (gMain.newKeys & DPAD_RIGHT)
        {
            if (data->modifyArrows.currentDigit != (data->modifyArrows.maxDigits - 1))
            {
                data->modifyArrows.currentDigit++;
                gSprites[data->modifyArrows.arrowSpriteId[0]].x2 += 6;
                gSprites[data->modifyArrows.arrowSpriteId[1]].x2 += 6;
            }
        }
        else if (gMain.newKeys & DPAD_LEFT)
        {
            if (data->modifyArrows.currentDigit != 0)
            {
                data->modifyArrows.currentDigit--;
                gSprites[data->modifyArrows.arrowSpriteId[0]].x2 -= 6;
                gSprites[data->modifyArrows.arrowSpriteId[1]].x2 -= 6;
            }
        }
        else if (gMain.newKeys & DPAD_UP)
        {
            if (TryMoveDigit(&data->modifyArrows, TRUE))
            {
                PrintDigitChars(data);
                UpdateBattlerValue(data);
                PrintSecondaryEntries(data);
            }
        }
        else if (gMain.newKeys & DPAD_DOWN)
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

static void PrintOnBattlerWindow(u8 windowId, u8 battlerId)
{
    u8 text[POKEMON_NAME_LENGTH + 10];

    text[0] = CHAR_0 + battlerId;
    text[1] = CHAR_SPACE;
    text[2] = CHAR_HYPHEN;
    text[3] = CHAR_SPACE;
    StringCopy(&text[4], gBattleMons[battlerId].nickname);

    FillWindowPixelBuffer(windowId, 0x11);
    AddTextPrinterParameterized(windowId, 1, text, 0, 0, 0, NULL);
    CopyWindowToVram(windowId, 3);
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
        itemsCount = 2;
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
    case LIST_ITEM_STATUS2:
        listTemplate.items = sStatus2ListItems;
        itemsCount = ARRAY_COUNT(sStatus2ListItems);
        data->bitfield = sStatus2Bitfield;
        winTemplate.height = 1;
        break;
    case LIST_ITEM_STATUS3:
        listTemplate.items = sStatus3ListItems;
        itemsCount = ARRAY_COUNT(sStatus3ListItems);
        data->bitfield = sStatus3Bitfield;
        break;
    case LIST_ITEM_STATUS4:
        listTemplate.items = sStatus4ListItems;
        itemsCount = ARRAY_COUNT(sStatus4ListItems);
        data->bitfield = sStatus4Bitfield;
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
    case LIST_ITEM_SIDE_STATUS:
        listTemplate.items = sSideStatusListItems;
        itemsCount = ARRAY_COUNT(sSideStatusListItems);
        break;
    case LIST_ITEM_AI_MOVES_PTS:
    case LIST_ITEM_AI_INFO:
        return;
    }

    data->secondaryListItemCount = itemsCount;
    winTemplate.height *= itemsCount;
    data->secondaryListWindowId = AddWindow(&winTemplate);

    listTemplate.totalItems = itemsCount;
    listTemplate.maxShowed = itemsCount;
    if (listTemplate.maxShowed > 7 && !sHasChangeableEntries[data->currentMainListItemId])
        listTemplate.maxShowed = 7;
    listTemplate.windowId = data->secondaryListWindowId;

    data->secondaryListTaskId = ListMenuInit(&listTemplate, 0, 0);
    CopyWindowToVram(data->secondaryListWindowId, 3);
}

static void PadString(const u8 *src, u8 *dst)
{
    u32 i;

    for (i = 0; i < 17 && src[i] != EOS; i++)
        dst[i] = src[i];

    for (; i < 17; i++)
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

    printer.windowId = data->secondaryListWindowId;
    printer.fontId = 1;
    printer.unk = 0;
    printer.letterSpacing = 0;
    printer.lineSpacing = 1;
    printer.fgColor = 2;
    printer.bgColor = 1;
    printer.shadowColor = 3;
    printer.x = sSecondaryListTemplate.item_X;
    printer.currentX = sSecondaryListTemplate.item_X;
    printer.currentChar = text;

    switch (data->currentMainListItemId)
    {
    case LIST_ITEM_MOVES:
    case LIST_ITEM_PP:
        for (i = 0; i < 4; i++)
        {
            PadString(gMoveNames[gBattleMons[data->battlerId].moves[i]], text);
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
        PadString(gAbilityNames[gBattleMons[data->battlerId].ability], text);
        printer.currentY = printer.y = sSecondaryListTemplate.upText_Y;
        AddTextPrinter(&printer, 0, NULL);
        break;
    case LIST_ITEM_HELD_ITEM:
        PadString(ItemId_GetName(gBattleMons[data->battlerId].item), text);
        printer.currentY = printer.y = sSecondaryListTemplate.upText_Y;
        AddTextPrinter(&printer, 0, NULL);

        PadString(sText_EffectOverride, text);
        printer.fontId = 0;
        printer.currentY = printer.y = sSecondaryListTemplate.upText_Y + yMultiplier;
        AddTextPrinter(&printer, 0, NULL);
        break;
    case LIST_ITEM_TYPES:
        for (i = 0; i < 3; i++)
        {
            u8 *types = &gBattleMons[data->battlerId].type1;

            PadString(gTypeNames[types[i]], text);
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
    FreeSpritePaletteByTag(gSpritePalette_Arrow.tag);
    if (data->modifyArrows.arrowSpriteId[0] != 0xFF)
        DestroySprite(&gSprites[data->modifyArrows.arrowSpriteId[0]]);
    if (data->modifyArrows.arrowSpriteId[1] != 0xFF)
        DestroySprite(&gSprites[data->modifyArrows.arrowSpriteId[1]]);
}

static void PrintDigitChars(struct BattleDebugMenu *data)
{
    s32 i;
    u8 text[MAX_MODIFY_DIGITS + 1];

    for (i = 0; i < data->modifyArrows.maxDigits; i++)
        text[i] = data->modifyArrows.charDigits[i];

    text[i] = EOS;

    AddTextPrinterParameterized(data->modifyWindowId, 1, text, 3, 0, 0, NULL);
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
        *(u8*)(data->modifyArrows.modifiedValPtr) = data->modifyArrows.currValue;
        break;
    case VAL_S8:
        *(s8*)(data->modifyArrows.modifiedValPtr) = data->modifyArrows.currValue;
        break;
    case VAL_U16:
        *(u16*)(data->modifyArrows.modifiedValPtr) = data->modifyArrows.currValue;
        break;
    case VAR_U16_4_ENTRIES:
        ((u16*)(data->modifyArrows.modifiedValPtr))[0] = data->modifyArrows.currValue;
        ((u16*)(data->modifyArrows.modifiedValPtr))[1] = data->modifyArrows.currValue;
        ((u16*)(data->modifyArrows.modifiedValPtr))[2] = data->modifyArrows.currValue;
        ((u16*)(data->modifyArrows.modifiedValPtr))[3] = data->modifyArrows.currValue;
        break;
    case VAL_ALL_STAT_STAGES:
        for (i = 0; i < NUM_BATTLE_STATS; i++)
            gBattleMons[data->battlerId].statStages[i] = data->modifyArrows.currValue;
        break;
    case VAL_U32:
        *(u32*)(data->modifyArrows.modifiedValPtr) = data->modifyArrows.currValue;
        break;
    case VAL_BITFIELD_32:
        *(u32*)(data->modifyArrows.modifiedValPtr) &= ~(GetBitfieldToAndValue(data->bitfield[data->currentSecondaryListItemId].currBit, data->bitfield[data->currentSecondaryListItemId].bitsCount));
        *(u32*)(data->modifyArrows.modifiedValPtr) |= (data->modifyArrows.currValue << data->bitfield[data->currentSecondaryListItemId].currBit);
        break;
    case VAR_SIDE_STATUS:
        *GetSideStatusValue(data, TRUE, data->modifyArrows.currValue != 0) = data->modifyArrows.currValue;
        break;
    case VAR_SHOW_HP:
        (*(struct BattleSpriteInfo*)(data->modifyArrows.modifiedValPtr)).hpNumbersNoBars = data->modifyArrows.currValue;
        break;
    case VAR_SUBSTITUTE:
        *(u8*)(data->modifyArrows.modifiedValPtr) = data->modifyArrows.currValue;
        if (*(u8*)(data->modifyArrows.modifiedValPtr) == 0)
        {
            gBattleMons[data->battlerId].status2 &= ~STATUS2_SUBSTITUTE;
            gBattleSpritesDataPtr->battlerData[data->battlerId].behindSubstitute = 0;
        }
        else
        {
            gBattleMons[data->battlerId].status2 |= STATUS2_SUBSTITUTE;
            gBattleSpritesDataPtr->battlerData[data->battlerId].behindSubstitute = 1;
        }
        break;
    case VAR_IN_LOVE:
        if (data->modifyArrows.currValue)
        {
            if (IsBattlerAlive(BATTLE_OPPOSITE(data->battlerId)))
                gBattleMons[data->battlerId].status2 |= STATUS2_INFATUATED_WITH(BATTLE_OPPOSITE(data->battlerId));
            else
                gBattleMons[data->battlerId].status2 |= STATUS2_INFATUATED_WITH(BATTLE_PARTNER(BATTLE_OPPOSITE(data->battlerId)));
        }
        else
        {
            gBattleMons[data->battlerId].status2 &= ~STATUS2_INFATUATION;
        }
        break;
    case VAL_ITEM:
        if (data->currentSecondaryListItemId == 0)
            *(u16*)(data->modifyArrows.modifiedValPtr) = data->modifyArrows.currValue;
        else if (data->currentSecondaryListItemId == 1)
            gBattleStruct->debugHoldEffects[data->battlerId] = data->modifyArrows.currValue;
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

static u8 *GetSideStatusValue(struct BattleDebugMenu *data, bool32 changeStatus, bool32 statusTrue)
{
    struct SideTimer *sideTimer = &gSideTimers[GET_BATTLER_SIDE(data->battlerId)];

    switch (data->currentSecondaryListItemId)
    {
    case LIST_SIDE_REFLECT:
        if (changeStatus)
        {
            if (statusTrue)
                *(u32*)(data->modifyArrows.modifiedValPtr) |= SIDE_STATUS_REFLECT;
            else
                *(u32*)(data->modifyArrows.modifiedValPtr) &= ~SIDE_STATUS_REFLECT;
            sideTimer->reflectBattlerId = data->battlerId;
        }
        return &sideTimer->reflectTimer;
    case LIST_SIDE_LIGHTSCREEN:
        if (changeStatus)
        {
            if (statusTrue)
                *(u32*)(data->modifyArrows.modifiedValPtr) |= SIDE_STATUS_LIGHTSCREEN;
            else
                *(u32*)(data->modifyArrows.modifiedValPtr) &= ~SIDE_STATUS_LIGHTSCREEN;
            sideTimer->lightscreenBattlerId = data->battlerId;
        }
        return &sideTimer->lightscreenTimer;
    case LIST_SIDE_SPIKES:
        if (changeStatus)
        {
            if (statusTrue)
                *(u32*)(data->modifyArrows.modifiedValPtr) |= SIDE_STATUS_SPIKES;
            else
                *(u32*)(data->modifyArrows.modifiedValPtr) &= ~SIDE_STATUS_SPIKES;
        }
        return &sideTimer->spikesAmount;
    case LIST_SIDE_SAFEGUARD:
        if (changeStatus)
        {
            if (statusTrue)
                *(u32*)(data->modifyArrows.modifiedValPtr) |= SIDE_STATUS_SAFEGUARD;
            else
                *(u32*)(data->modifyArrows.modifiedValPtr) &= ~SIDE_STATUS_SAFEGUARD;
            sideTimer->safeguardBattlerId = data->battlerId;
        }
        return &sideTimer->safeguardTimer;
    case LIST_SIDE_MIST:
        if (changeStatus)
        {
            if (statusTrue)
                *(u32*)(data->modifyArrows.modifiedValPtr) |= SIDE_STATUS_MIST;
            else
                *(u32*)(data->modifyArrows.modifiedValPtr) &= ~SIDE_STATUS_MIST;
            sideTimer->mistBattlerId = data->battlerId;
        }
        return &sideTimer->mistTimer;
    case LIST_SIDE_AURORA_VEIL:
        if (changeStatus)
        {
            if (statusTrue)
                *(u32*)(data->modifyArrows.modifiedValPtr) |= SIDE_STATUS_AURORA_VEIL;
            else
                *(u32*)(data->modifyArrows.modifiedValPtr) &= ~SIDE_STATUS_AURORA_VEIL;
            sideTimer->auroraVeilBattlerId = data->battlerId;
        }
        return &sideTimer->auroraVeilTimer;
    case LIST_SIDE_LUCKY_CHANT:
        if (changeStatus)
        {
            if (statusTrue)
                *(u32*)(data->modifyArrows.modifiedValPtr) |= SIDE_STATUS_LUCKY_CHANT;
            else
                *(u32*)(data->modifyArrows.modifiedValPtr) &= ~SIDE_STATUS_LUCKY_CHANT;
            sideTimer->luckyChantBattlerId = data->battlerId;
        }
        return &sideTimer->luckyChantTimer;
    case LIST_SIDE_TAILWIND:
        if (changeStatus)
        {
            if (statusTrue)
                *(u32*)(data->modifyArrows.modifiedValPtr) |= SIDE_STATUS_TAILWIND;
            else
                *(u32*)(data->modifyArrows.modifiedValPtr) &= ~SIDE_STATUS_TAILWIND;
            sideTimer->tailwindBattlerId = data->battlerId;
        }
        return &sideTimer->tailwindTimer;
    case LIST_SIDE_STEALTH_ROCK:
        if (changeStatus)
        {
            if (statusTrue)
                *(u32*)(data->modifyArrows.modifiedValPtr) |= SIDE_STATUS_STEALTH_ROCK;
            else
                *(u32*)(data->modifyArrows.modifiedValPtr) &= ~SIDE_STATUS_STEALTH_ROCK;
        }
        return &sideTimer->stealthRockAmount;
    case LIST_SIDE_TOXIC_SPIKES:
        if (changeStatus)
        {
            if (statusTrue)
                *(u32*)(data->modifyArrows.modifiedValPtr) |= SIDE_STATUS_TOXIC_SPIKES;
            else
                *(u32*)(data->modifyArrows.modifiedValPtr) &= ~SIDE_STATUS_TOXIC_SPIKES;
        }
        return &sideTimer->toxicSpikesAmount;
    case LIST_SIDE_STICKY_WEB:
        if (changeStatus)
        {
            if (statusTrue)
                *(u32*)(data->modifyArrows.modifiedValPtr) |= SIDE_STATUS_STICKY_WEB;
            else
                *(u32*)(data->modifyArrows.modifiedValPtr) &= ~SIDE_STATUS_STICKY_WEB;
        }
        return &sideTimer->stickyWebAmount;
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
        data->modifyArrows.maxValue = ABILITIES_COUNT_GEN8 - 1;
        data->modifyArrows.maxDigits = 3;
        data->modifyArrows.modifiedValPtr = &gBattleMons[data->battlerId].ability;
        data->modifyArrows.typeOfVal = VAL_U16;
        data->modifyArrows.currValue = gBattleMons[data->battlerId].ability;
        break;
    case LIST_ITEM_MOVES:
        data->modifyArrows.minValue = 0;
        data->modifyArrows.maxValue = MOVES_COUNT_GEN8 - 1;
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
        data->modifyArrows.typeOfVal = VAL_ITEM;
        if (data->currentSecondaryListItemId == 0)
            data->modifyArrows.currValue = gBattleMons[data->battlerId].item;
        else
            data->modifyArrows.currValue = gBattleStruct->debugHoldEffects[data->battlerId];
        break;
    case LIST_ITEM_TYPES:
        data->modifyArrows.minValue = 0;
        data->modifyArrows.maxValue = NUMBER_OF_MON_TYPES - 1;
        data->modifyArrows.maxDigits = 2;
        data->modifyArrows.modifiedValPtr = (u8*)((&gBattleMons[data->battlerId].type1) + data->currentSecondaryListItemId);
        data->modifyArrows.typeOfVal = VAL_U8;
        data->modifyArrows.currValue = *(u8*)((&gBattleMons[data->battlerId].type1) + data->currentSecondaryListItemId);
        break;
    case LIST_ITEM_STATS:
        data->modifyArrows.minValue = 0;
        data->modifyArrows.maxValue = 9999;
        data->modifyArrows.maxDigits = 4;
        if (data->currentSecondaryListItemId == 0)
        {
            data->modifyArrows.modifiedValPtr = &gBattleMons[data->battlerId].hp;
            data->modifyArrows.currValue = gBattleMons[data->battlerId].hp;
            data->modifyArrows.minValue = 1;
            data->modifyArrows.maxValue = gBattleMons[data->battlerId].maxHP;
        }
        else if (data->currentSecondaryListItemId == 1)
        {
            data->modifyArrows.modifiedValPtr = &gBattleMons[data->battlerId].maxHP;
            data->modifyArrows.minValue = gBattleMons[data->battlerId].hp;
            data->modifyArrows.currValue = gBattleMons[data->battlerId].maxHP;
        }
        else
        {
            data->modifyArrows.modifiedValPtr = (u16*)((&gBattleMons[data->battlerId].attack) + (data->currentSecondaryListItemId - 2));
            data->modifyArrows.currValue = *(u16*)((&gBattleMons[data->battlerId].attack) + (data->currentSecondaryListItemId - 2));
        }
        data->modifyArrows.typeOfVal = VAL_U16;
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
            data->modifyArrows.minValue = 0;
            data->modifyArrows.maxValue = 255;
            data->modifyArrows.maxDigits = 3;
            data->modifyArrows.modifiedValPtr = &gDisableStructs[data->battlerId].substituteHP;
            data->modifyArrows.typeOfVal = VAR_SUBSTITUTE;
            data->modifyArrows.currValue = gDisableStructs[data->battlerId].substituteHP;
        }
        else if (data->currentSecondaryListItemId == VARIOUS_IN_LOVE)
        {
            data->modifyArrows.minValue = 0;
            data->modifyArrows.maxValue = 1;
            data->modifyArrows.maxDigits = 1;
            data->modifyArrows.modifiedValPtr = NULL;
            data->modifyArrows.typeOfVal = VAR_IN_LOVE;
            data->modifyArrows.currValue = (gBattleMons[data->battlerId].status2 & STATUS2_INFATUATION) != 0;
        }
        break;
    case LIST_ITEM_STATUS1:
        data->modifyArrows.modifiedValPtr = &gBattleMons[data->battlerId].status1;
        data->modifyArrows.currValue = GetBitfieldValue(gBattleMons[data->battlerId].status1, data->bitfield[data->currentSecondaryListItemId].currBit, data->bitfield[data->currentSecondaryListItemId].bitsCount);
        data->modifyArrows.typeOfVal = VAL_BITFIELD_32;
        goto CASE_ITEM_STATUS;
    case LIST_ITEM_STATUS2:
        data->modifyArrows.modifiedValPtr = &gBattleMons[data->battlerId].status2;
        data->modifyArrows.currValue = GetBitfieldValue(gBattleMons[data->battlerId].status2, data->bitfield[data->currentSecondaryListItemId].currBit, data->bitfield[data->currentSecondaryListItemId].bitsCount);
        data->modifyArrows.typeOfVal = VAL_BITFIELD_32;
        goto CASE_ITEM_STATUS;
    case LIST_ITEM_STATUS3:
        data->modifyArrows.modifiedValPtr = &gStatuses3[data->battlerId];
        data->modifyArrows.currValue = GetBitfieldValue(gStatuses3[data->battlerId], data->bitfield[data->currentSecondaryListItemId].currBit, data->bitfield[data->currentSecondaryListItemId].bitsCount);
        data->modifyArrows.typeOfVal = VAL_BITFIELD_32;
        goto CASE_ITEM_STATUS;
    case LIST_ITEM_STATUS4:
        data->modifyArrows.modifiedValPtr = &gStatuses4[data->battlerId];
        data->modifyArrows.currValue = GetBitfieldValue(gStatuses4[data->battlerId], data->bitfield[data->currentSecondaryListItemId].currBit, data->bitfield[data->currentSecondaryListItemId].bitsCount);
        data->modifyArrows.typeOfVal = VAL_BITFIELD_32;
        goto CASE_ITEM_STATUS;
    case LIST_ITEM_AI:
        data->modifyArrows.modifiedValPtr = &gBattleResources->ai->aiFlags;
        data->modifyArrows.currValue = GetBitfieldValue(gBattleResources->ai->aiFlags, data->bitfield[data->currentSecondaryListItemId].currBit, data->bitfield[data->currentSecondaryListItemId].bitsCount);
        data->modifyArrows.typeOfVal = VAL_BITFIELD_32;
        goto CASE_ITEM_STATUS;
    CASE_ITEM_STATUS:
        data->modifyArrows.minValue = 0;
        data->modifyArrows.maxValue = (1 << data->bitfield[data->currentSecondaryListItemId].bitsCount) - 1;
        data->modifyArrows.maxDigits = sBitsToMaxDigit[data->bitfield[data->currentSecondaryListItemId].bitsCount];
        break;
    case LIST_ITEM_SIDE_STATUS:
        data->modifyArrows.minValue = 0;

        if (data->currentSecondaryListItemId == LIST_SIDE_SPIKES)
            data->modifyArrows.maxValue = 3;
        else if (data->currentSecondaryListItemId == LIST_SIDE_STEALTH_ROCK || data->currentSecondaryListItemId == LIST_SIDE_STICKY_WEB)
            data->modifyArrows.maxValue = 1;
        else
            data->modifyArrows.maxValue = 9;

        data->modifyArrows.maxDigits = 2;
        data->modifyArrows.modifiedValPtr = &gSideStatuses[GET_BATTLER_SIDE(data->battlerId)];
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
            struct Pokemon *mon;
            struct BattlePokemon *battleMon = &gBattleMons[i];

            if (GetBattlerSide(i) == B_SIDE_PLAYER)
                mon = &gPlayerParty[gBattlerPartyIndexes[i]];
            else
                mon = &gEnemyParty[gBattlerPartyIndexes[i]];

            SetMonData(mon, MON_DATA_HELD_ITEM, &battleMon->item);
            SetMonData(mon, MON_DATA_STATUS, &battleMon->status1);
            SetMonData(mon, MON_DATA_HP, &battleMon->hp);
            SetMonData(mon, MON_DATA_MAX_HP, &battleMon->maxHP);
            for (j = 0; j < 4; j++)
                SetMonData(mon, MON_DATA_MOVE1 + j, &battleMon->moves[j]);
        }
    }
}

static const u8 sText_HoldEffectNone[] = _("????????");
static const u8 sText_HoldEffectRestoreHp[] = _("Restore Hp");
static const u8 sText_HoldEffectCurePar[] = _("Cure Par");
static const u8 sText_HoldEffectCureSlp[] = _("Cure Slp");
static const u8 sText_HoldEffectCurePsn[] = _("Cure Psn");
static const u8 sText_HoldEffectCureBrn[] = _("Cure Brn");
static const u8 sText_HoldEffectCureFrz[] = _("Cure Frz");
static const u8 sText_HoldEffectRestorePp[] = _("Restore Pp");
static const u8 sText_HoldEffectCureConfusion[] = _("Cure Confusion");
static const u8 sText_HoldEffectCureStatus[] = _("Cure Status");
static const u8 sText_HoldEffectConfuseSpicy[] = _("Confuse Spicy");
static const u8 sText_HoldEffectConfuseDry[] = _("Confuse Dry");
static const u8 sText_HoldEffectConfuseSweet[] = _("Confuse Sweet");
static const u8 sText_HoldEffectConfuseBitter[] = _("Confuse Bitter");
static const u8 sText_HoldEffectConfuseSour[] = _("Confuse Sour");
static const u8 sText_HoldEffectAttackUp[] = _("Attack Up");
static const u8 sText_HoldEffectDefenseUp[] = _("Defense Up");
static const u8 sText_HoldEffectSpeedUp[] = _("Speed Up");
static const u8 sText_HoldEffectSpAttackUp[] = _("Sp Attack Up");
static const u8 sText_HoldEffectSpDefenseUp[] = _("Sp Defense Up");
static const u8 sText_HoldEffectCriticalUp[] = _("Critical Up");
static const u8 sText_HoldEffectRandomStatUp[] = _("Random Stat Up");
static const u8 sText_HoldEffectEvasionUp[] = _("Evasion Up");
static const u8 sText_HoldEffectRestoreStats[] = _("Restore Stats");
static const u8 sText_HoldEffectMachoBrace[] = _("Macho Brace");
static const u8 sText_HoldEffectExpShare[] = _("Exp Share");
static const u8 sText_HoldEffectQuickClaw[] = _("Quick Claw");
static const u8 sText_HoldEffectFriendshipUp[] = _("Friendship Up");
static const u8 sText_HoldEffectMentalHerb[] = _("Mental Herb");
static const u8 sText_HoldEffectChoiceBand[] = _("Choice Band");
static const u8 sText_HoldEffectFlinch[] = _("Flinch");
static const u8 sText_HoldEffectBugPower[] = _("Bug Power");
static const u8 sText_HoldEffectDoublePrize[] = _("Double Prize");
static const u8 sText_HoldEffectRepel[] = _("Repel");
static const u8 sText_HoldEffectSoulDew[] = _("Soul Dew");
static const u8 sText_HoldEffectDeepSeaTooth[] = _("Deep Sea Tooth");
static const u8 sText_HoldEffectDeepSeaScale[] = _("Deep Sea Scale");
static const u8 sText_HoldEffectCanAlwaysRun[] = _("Can Always Run");
static const u8 sText_HoldEffectPreventEvolve[] = _("Prevent Evolve");
static const u8 sText_HoldEffectFocusBand[] = _("Focus Band");
static const u8 sText_HoldEffectLuckyEgg[] = _("Lucky Egg");
static const u8 sText_HoldEffectScopeLens[] = _("Scope Lens");
static const u8 sText_HoldEffectSteelPower[] = _("Steel Power");
static const u8 sText_HoldEffectLeftovers[] = _("Leftovers");
static const u8 sText_HoldEffectDragonScale[] = _("Dragon Scale");
static const u8 sText_HoldEffectLightBall[] = _("Light Ball");
static const u8 sText_HoldEffectGroundPower[] = _("Ground Power");
static const u8 sText_HoldEffectRockPower[] = _("Rock Power");
static const u8 sText_HoldEffectGrassPower[] = _("Grass Power");
static const u8 sText_HoldEffectDarkPower[] = _("Dark Power");
static const u8 sText_HoldEffectFightingPower[] = _("Fighting Power");
static const u8 sText_HoldEffectElectricPower[] = _("Electric Power");
static const u8 sText_HoldEffectWaterPower[] = _("Water Power");
static const u8 sText_HoldEffectFlyingPower[] = _("Flying Power");
static const u8 sText_HoldEffectPoisonPower[] = _("Poison Power");
static const u8 sText_HoldEffectIcePower[] = _("Ice Power");
static const u8 sText_HoldEffectGhostPower[] = _("Ghost Power");
static const u8 sText_HoldEffectPsychicPower[] = _("Psychic Power");
static const u8 sText_HoldEffectFirePower[] = _("Fire Power");
static const u8 sText_HoldEffectDragonPower[] = _("Dragon Power");
static const u8 sText_HoldEffectNormalPower[] = _("Normal Power");
#ifdef ITEM_EXPANSION
static const u8 sText_HoldEffectUpgrade[] = _("Upgrade");
#else
static const u8 sText_HoldEffectUpgrade[] = _("Up Grade");
#endif
static const u8 sText_HoldEffectShellBell[] = _("Shell Bell");
static const u8 sText_HoldEffectLuckyPunch[] = _("Lucky Punch");
static const u8 sText_HoldEffectMetalPowder[] = _("Metal Powder");
static const u8 sText_HoldEffectThickClub[] = _("Thick Club");
#ifdef ITEM_EXPANSION
static const u8 sText_HoldEffectLeek[] = _("Leek");
#else
static const u8 sText_HoldEffectLeek[] = _("Stick");
#endif
static const u8 sText_HoldEffectChoiceScarf[] = _("Choice Scarf");
static const u8 sText_HoldEffectChoiceSpecs[] = _("Choice Specs");
static const u8 sText_HoldEffectDampRock[] = _("Damp Rock");
static const u8 sText_HoldEffectGripClaw[] = _("Grip Claw");
static const u8 sText_HoldEffectHeatRock[] = _("Heat Rock");
static const u8 sText_HoldEffectIcyRock[] = _("Icy Rock");
static const u8 sText_HoldEffectLightClay[] = _("Light Clay");
static const u8 sText_HoldEffectSmoothRock[] = _("Smooth Rock");
static const u8 sText_HoldEffectPowerHerb[] = _("Power Herb");
static const u8 sText_HoldEffectBigRoot[] = _("Big Root");
static const u8 sText_HoldEffectExpertBelt[] = _("Expert Belt");
static const u8 sText_HoldEffectLifeOrb[] = _("Life Orb");
static const u8 sText_HoldEffectMetronome[] = _("Metronome");
static const u8 sText_HoldEffectMuscleBand[] = _("Muscle Band");
static const u8 sText_HoldEffectWideLens[] = _("Wide Lens");
static const u8 sText_HoldEffectWiseGlasses[] = _("Wise Glasses");
static const u8 sText_HoldEffectZoomLens[] = _("Zoom Lens");
static const u8 sText_HoldEffectLaggingTail[] = _("Lagging Tail");
static const u8 sText_HoldEffectFocusSash[] = _("Focus Sash");
static const u8 sText_HoldEffectFlameOrb[] = _("Flame Orb");
static const u8 sText_HoldEffectToxicOrb[] = _("Toxic Orb");
static const u8 sText_HoldEffectStickyBarb[] = _("Sticky Barb");
static const u8 sText_HoldEffectIronBall[] = _("Iron Ball");
static const u8 sText_HoldEffectBlackSludge[] = _("Black Sludge");
static const u8 sText_HoldEffectDestinyKnot[] = _("Destiny Knot");
static const u8 sText_HoldEffectShedShell[] = _("Shed Shell");
static const u8 sText_HoldEffectQuickPowder[] = _("Quick Powder");
static const u8 sText_HoldEffectAdamantOrb[] = _("Adamant Orb");
static const u8 sText_HoldEffectLustrousOrb[] = _("Lustrous Orb");
static const u8 sText_HoldEffectGriseousOrb[] = _("Griseous Orb");
static const u8 sText_HoldEffectGracidea[] = _("Gracidea");
static const u8 sText_HoldEffectResistBerry[] = _("Resist Berry");
static const u8 sText_HoldEffectPowerItem[] = _("Power Item");
static const u8 sText_HoldEffectRestorePctHp[] = _("Restore Pct Hp");
static const u8 sText_HoldEffectMicleBerry[] = _("Micle Berry");
static const u8 sText_HoldEffectCustapBerry[] = _("Custap Berry");
static const u8 sText_HoldEffectJabocaBerry[] = _("Jaboca Berry");
static const u8 sText_HoldEffectRowapBerry[] = _("Rowap Berry");
static const u8 sText_HoldEffectKeeBerry[] = _("Kee Berry");
static const u8 sText_HoldEffectMarangaBerry[] = _("Maranga Berry");
static const u8 sText_HoldEffectFloatStone[] = _("Float Stone");
static const u8 sText_HoldEffectEviolite[] = _("Eviolite");
static const u8 sText_HoldEffectAssaultVest[] = _("Assault Vest");
static const u8 sText_HoldEffectDrive[] = _("Drive");
static const u8 sText_HoldEffectGems[] = _("Gems");
static const u8 sText_HoldEffectRockyHelmet[] = _("Rocky Helmet");
static const u8 sText_HoldEffectAirBalloon[] = _("Air Balloon");
static const u8 sText_HoldEffectRedCard[] = _("Red Card");
static const u8 sText_HoldEffectRingTarget[] = _("Ring Target");
static const u8 sText_HoldEffectBindingBand[] = _("Binding Band");
static const u8 sText_HoldEffectEjectButton[] = _("Eject Button");
static const u8 sText_HoldEffectAbsorbBulb[] = _("Absorb Bulb");
static const u8 sText_HoldEffectCellBattery[] = _("Cell Battery");
static const u8 sText_HoldEffectFairyPower[] = _("Fairy Power");
static const u8 sText_HoldEffectMegaStone[] = _("Mega Stone");
static const u8 sText_HoldEffectSafetyGoggles[] = _("Safety Goggles");
static const u8 sText_HoldEffectLuminousMoss[] = _("Luminous Moss");
static const u8 sText_HoldEffectSnowball[] = _("Snowball");
static const u8 sText_HoldEffectWeaknessPolicy[] = _("Weakness Policy");
static const u8 sText_HoldEffectProtectivePads[] = _("Protective Pads");
static const u8 sText_HoldEffectTerrainExtender[] = _("Terrain Extender");
static const u8 sText_HoldEffectSeeds[] = _("Seeds");
static const u8 sText_HoldEffectAdrenalineOrb[] = _("Adrenaline Orb");
static const u8 sText_HoldEffectMemory[] = _("Memory");
static const u8 sText_HoldEffectPlate[] = _("Plate");
static const u8 sText_HoldEffectUtilityUmbrella[] = _("Utility Umbrella");
static const u8 sText_HoldEffectEjectPack[] = _("Eject Pack");
static const u8 sText_HoldEffectRoomService[] = _("Room Service");
static const u8 sText_HoldEffectBlunderPolicy[] = _("Blunder Policy");
static const u8 sText_HoldEffectHeavyDutyBoots[] = _("Heavy Duty Boots");
static const u8 sText_HoldEffectThroatSpray[] = _("Throat Spray");
static const u8 *const sHoldEffectNames[] = 
{
    [HOLD_EFFECT_NONE] = sText_HoldEffectNone,
    [HOLD_EFFECT_RESTORE_HP] = sText_HoldEffectRestoreHp,
    [HOLD_EFFECT_CURE_PAR] = sText_HoldEffectCurePar,
    [HOLD_EFFECT_CURE_SLP] = sText_HoldEffectCureSlp,
    [HOLD_EFFECT_CURE_PSN] = sText_HoldEffectCurePsn,
    [HOLD_EFFECT_CURE_BRN] = sText_HoldEffectCureBrn,
    [HOLD_EFFECT_CURE_FRZ] = sText_HoldEffectCureFrz,
    [HOLD_EFFECT_RESTORE_PP] = sText_HoldEffectRestorePp,
    [HOLD_EFFECT_CURE_CONFUSION] = sText_HoldEffectCureConfusion,
    [HOLD_EFFECT_CURE_STATUS] = sText_HoldEffectCureStatus,
    [HOLD_EFFECT_CONFUSE_SPICY] = sText_HoldEffectConfuseSpicy,
    [HOLD_EFFECT_CONFUSE_DRY] = sText_HoldEffectConfuseDry,
    [HOLD_EFFECT_CONFUSE_SWEET] = sText_HoldEffectConfuseSweet,
    [HOLD_EFFECT_CONFUSE_BITTER] = sText_HoldEffectConfuseBitter,
    [HOLD_EFFECT_CONFUSE_SOUR] = sText_HoldEffectConfuseSour,
    [HOLD_EFFECT_ATTACK_UP] = sText_HoldEffectAttackUp,
    [HOLD_EFFECT_DEFENSE_UP] = sText_HoldEffectDefenseUp,
    [HOLD_EFFECT_SPEED_UP] = sText_HoldEffectSpeedUp,
    [HOLD_EFFECT_SP_ATTACK_UP] = sText_HoldEffectSpAttackUp,
    [HOLD_EFFECT_SP_DEFENSE_UP] = sText_HoldEffectSpDefenseUp,
    [HOLD_EFFECT_CRITICAL_UP] = sText_HoldEffectCriticalUp,
    [HOLD_EFFECT_RANDOM_STAT_UP] = sText_HoldEffectRandomStatUp,
    [HOLD_EFFECT_EVASION_UP] = sText_HoldEffectEvasionUp,
    [HOLD_EFFECT_RESTORE_STATS] = sText_HoldEffectRestoreStats,
    [HOLD_EFFECT_MACHO_BRACE] = sText_HoldEffectMachoBrace,
    [HOLD_EFFECT_EXP_SHARE] = sText_HoldEffectExpShare,
    [HOLD_EFFECT_QUICK_CLAW] = sText_HoldEffectQuickClaw,
    [HOLD_EFFECT_FRIENDSHIP_UP] = sText_HoldEffectFriendshipUp,
    //[HOLD_EFFECT_MENTAL_HERB] = sText_HoldEffectMentalHerb,
    [HOLD_EFFECT_CHOICE_BAND] = sText_HoldEffectChoiceBand,
    [HOLD_EFFECT_FLINCH] = sText_HoldEffectFlinch,
    [HOLD_EFFECT_BUG_POWER] = sText_HoldEffectBugPower,
    [HOLD_EFFECT_DOUBLE_PRIZE] = sText_HoldEffectDoublePrize,
    [HOLD_EFFECT_REPEL] = sText_HoldEffectRepel,
    [HOLD_EFFECT_SOUL_DEW] = sText_HoldEffectSoulDew,
    [HOLD_EFFECT_DEEP_SEA_TOOTH] = sText_HoldEffectDeepSeaTooth,
    [HOLD_EFFECT_DEEP_SEA_SCALE] = sText_HoldEffectDeepSeaScale,
    [HOLD_EFFECT_CAN_ALWAYS_RUN] = sText_HoldEffectCanAlwaysRun,
    [HOLD_EFFECT_PREVENT_EVOLVE] = sText_HoldEffectPreventEvolve,
    [HOLD_EFFECT_FOCUS_BAND] = sText_HoldEffectFocusBand,
    [HOLD_EFFECT_LUCKY_EGG] = sText_HoldEffectLuckyEgg,
    [HOLD_EFFECT_SCOPE_LENS] = sText_HoldEffectScopeLens,
    [HOLD_EFFECT_STEEL_POWER] = sText_HoldEffectSteelPower,
    [HOLD_EFFECT_LEFTOVERS] = sText_HoldEffectLeftovers,
    [HOLD_EFFECT_DRAGON_SCALE] = sText_HoldEffectDragonScale,
    [HOLD_EFFECT_LIGHT_BALL] = sText_HoldEffectLightBall,
    [HOLD_EFFECT_GROUND_POWER] = sText_HoldEffectGroundPower,
    [HOLD_EFFECT_ROCK_POWER] = sText_HoldEffectRockPower,
    [HOLD_EFFECT_GRASS_POWER] = sText_HoldEffectGrassPower,
    [HOLD_EFFECT_DARK_POWER] = sText_HoldEffectDarkPower,
    [HOLD_EFFECT_FIGHTING_POWER] = sText_HoldEffectFightingPower,
    [HOLD_EFFECT_ELECTRIC_POWER] = sText_HoldEffectElectricPower,
    [HOLD_EFFECT_WATER_POWER] = sText_HoldEffectWaterPower,
    [HOLD_EFFECT_FLYING_POWER] = sText_HoldEffectFlyingPower,
    [HOLD_EFFECT_POISON_POWER] = sText_HoldEffectPoisonPower,
    [HOLD_EFFECT_ICE_POWER] = sText_HoldEffectIcePower,
    [HOLD_EFFECT_GHOST_POWER] = sText_HoldEffectGhostPower,
    [HOLD_EFFECT_PSYCHIC_POWER] = sText_HoldEffectPsychicPower,
    [HOLD_EFFECT_FIRE_POWER] = sText_HoldEffectFirePower,
    [HOLD_EFFECT_DRAGON_POWER] = sText_HoldEffectDragonPower,
    [HOLD_EFFECT_NORMAL_POWER] = sText_HoldEffectNormalPower,
    [HOLD_EFFECT_UPGRADE] = sText_HoldEffectUpgrade,
    [HOLD_EFFECT_SHELL_BELL] = sText_HoldEffectShellBell,
    [HOLD_EFFECT_LUCKY_PUNCH] = sText_HoldEffectLuckyPunch,
    [HOLD_EFFECT_METAL_POWDER] = sText_HoldEffectMetalPowder,
    [HOLD_EFFECT_THICK_CLUB] = sText_HoldEffectThickClub,
    [HOLD_EFFECT_LEEK] = sText_HoldEffectLeek,
    [HOLD_EFFECT_CHOICE_SCARF] = sText_HoldEffectChoiceScarf,
    [HOLD_EFFECT_CHOICE_SPECS] = sText_HoldEffectChoiceSpecs,
    [HOLD_EFFECT_DAMP_ROCK] = sText_HoldEffectDampRock,
    [HOLD_EFFECT_GRIP_CLAW] = sText_HoldEffectGripClaw,
    [HOLD_EFFECT_HEAT_ROCK] = sText_HoldEffectHeatRock,
    [HOLD_EFFECT_ICY_ROCK] = sText_HoldEffectIcyRock,
    [HOLD_EFFECT_LIGHT_CLAY] = sText_HoldEffectLightClay,
    [HOLD_EFFECT_SMOOTH_ROCK] = sText_HoldEffectSmoothRock,
    [HOLD_EFFECT_POWER_HERB] = sText_HoldEffectPowerHerb,
    [HOLD_EFFECT_BIG_ROOT] = sText_HoldEffectBigRoot,
    [HOLD_EFFECT_EXPERT_BELT] = sText_HoldEffectExpertBelt,
    [HOLD_EFFECT_LIFE_ORB] = sText_HoldEffectLifeOrb,
    [HOLD_EFFECT_METRONOME] = sText_HoldEffectMetronome,
    [HOLD_EFFECT_MUSCLE_BAND] = sText_HoldEffectMuscleBand,
    [HOLD_EFFECT_WIDE_LENS] = sText_HoldEffectWideLens,
    [HOLD_EFFECT_WISE_GLASSES] = sText_HoldEffectWiseGlasses,
    [HOLD_EFFECT_ZOOM_LENS] = sText_HoldEffectZoomLens,
    [HOLD_EFFECT_LAGGING_TAIL] = sText_HoldEffectLaggingTail,
    [HOLD_EFFECT_FOCUS_SASH] = sText_HoldEffectFocusSash,
    [HOLD_EFFECT_FLAME_ORB] = sText_HoldEffectFlameOrb,
    [HOLD_EFFECT_TOXIC_ORB] = sText_HoldEffectToxicOrb,
    [HOLD_EFFECT_STICKY_BARB] = sText_HoldEffectStickyBarb,
    [HOLD_EFFECT_IRON_BALL] = sText_HoldEffectIronBall,
    [HOLD_EFFECT_BLACK_SLUDGE] = sText_HoldEffectBlackSludge,
    [HOLD_EFFECT_DESTINY_KNOT] = sText_HoldEffectDestinyKnot,
    [HOLD_EFFECT_SHED_SHELL] = sText_HoldEffectShedShell,
    [HOLD_EFFECT_QUICK_POWDER] = sText_HoldEffectQuickPowder,
    [HOLD_EFFECT_ADAMANT_ORB] = sText_HoldEffectAdamantOrb,
    [HOLD_EFFECT_LUSTROUS_ORB] = sText_HoldEffectLustrousOrb,
    [HOLD_EFFECT_GRISEOUS_ORB] = sText_HoldEffectGriseousOrb,
    [HOLD_EFFECT_GRACIDEA] = sText_HoldEffectGracidea,
    [HOLD_EFFECT_RESIST_BERRY] = sText_HoldEffectResistBerry,
    [HOLD_EFFECT_POWER_ITEM] = sText_HoldEffectPowerItem,
    [HOLD_EFFECT_RESTORE_PCT_HP] = sText_HoldEffectRestorePctHp,
    //[HOLD_EFFECT_MICLE_BERRY] = sText_HoldEffectMicleBerry,
    //[HOLD_EFFECT_CUSTAP_BERRY] = sText_HoldEffectCustapBerry,
    //[HOLD_EFFECT_JABOCA_BERRY] = sText_HoldEffectJabocaBerry,
    //[HOLD_EFFECT_ROWAP_BERRY] = sText_HoldEffectRowapBerry,
    //[HOLD_EFFECT_KEE_BERRY] = sText_HoldEffectKeeBerry,
    //[HOLD_EFFECT_MARANGA_BERRY] = sText_HoldEffectMarangaBerry,
    [HOLD_EFFECT_FLOAT_STONE] = sText_HoldEffectFloatStone,
    [HOLD_EFFECT_EVIOLITE] = sText_HoldEffectEviolite,
    [HOLD_EFFECT_ASSAULT_VEST] = sText_HoldEffectAssaultVest,
    [HOLD_EFFECT_DRIVE] = sText_HoldEffectDrive,
    [HOLD_EFFECT_GEMS] = sText_HoldEffectGems,
    [HOLD_EFFECT_ROCKY_HELMET] = sText_HoldEffectRockyHelmet,
    [HOLD_EFFECT_AIR_BALLOON] = sText_HoldEffectAirBalloon,
    [HOLD_EFFECT_RED_CARD] = sText_HoldEffectRedCard,
    [HOLD_EFFECT_RING_TARGET] = sText_HoldEffectRingTarget,
    [HOLD_EFFECT_BINDING_BAND] = sText_HoldEffectBindingBand,
    [HOLD_EFFECT_EJECT_BUTTON] = sText_HoldEffectEjectButton,
    [HOLD_EFFECT_ABSORB_BULB] = sText_HoldEffectAbsorbBulb,
    [HOLD_EFFECT_CELL_BATTERY] = sText_HoldEffectCellBattery,
    [HOLD_EFFECT_FAIRY_POWER] = sText_HoldEffectFairyPower,
    [HOLD_EFFECT_MEGA_STONE] = sText_HoldEffectMegaStone,
    [HOLD_EFFECT_SAFETY_GOGGLES] = sText_HoldEffectSafetyGoggles,
    [HOLD_EFFECT_LUMINOUS_MOSS] = sText_HoldEffectLuminousMoss,
    [HOLD_EFFECT_SNOWBALL] = sText_HoldEffectSnowball,
    [HOLD_EFFECT_WEAKNESS_POLICY] = sText_HoldEffectWeaknessPolicy,
    [HOLD_EFFECT_PROTECTIVE_PADS] = sText_HoldEffectProtectivePads,
    [HOLD_EFFECT_TERRAIN_EXTENDER] = sText_HoldEffectTerrainExtender,
    [HOLD_EFFECT_SEEDS] = sText_HoldEffectSeeds,
    [HOLD_EFFECT_ADRENALINE_ORB] = sText_HoldEffectAdrenalineOrb,
    [HOLD_EFFECT_MEMORY] = sText_HoldEffectMemory,
    [HOLD_EFFECT_PLATE] = sText_HoldEffectPlate,
    [HOLD_EFFECT_UTILITY_UMBRELLA] = sText_HoldEffectUtilityUmbrella,
    [HOLD_EFFECT_EJECT_PACK] = sText_HoldEffectEjectPack,
    [HOLD_EFFECT_ROOM_SERVICE] = sText_HoldEffectRoomService,
    [HOLD_EFFECT_BLUNDER_POLICY] = sText_HoldEffectBlunderPolicy,
    [HOLD_EFFECT_HEAVY_DUTY_BOOTS] = sText_HoldEffectHeavyDutyBoots,
    [HOLD_EFFECT_THROAT_SPRAY] = sText_HoldEffectThroatSpray,
};
static const u8 *GetHoldEffectName(u16 holdEffect)
{
    if (holdEffect > ARRAY_COUNT(sHoldEffectNames))
        return sHoldEffectNames[0];
    return sHoldEffectNames[holdEffect];
}
