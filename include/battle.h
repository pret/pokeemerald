#ifndef GUARD_BATTLE_H
#define GUARD_BATTLE_H

// should they be included here or included individually by every file?
#include "battle_util.h"
#include "battle_script_commands.h"
#include "battle_2.h"
#include "battle_ai_switch_items.h"

/*
    Banks are a name given to what could be called a 'battlerId' or 'monControllerId'.
    Each bank has a value consisting of two bits.
    0x1 bit is responsible for the side, 0 = player's side, 1 = opponent's side.
    0x2 bit is responsible for the id of sent out pokemon. 0 means it's the first sent out pokemon, 1 it's the second one. (Triple battle didn't exist at the time yet.)
*/

#define BATTLE_BANKS_COUNT  4

#define IDENTITY_PLAYER_MON1        0
#define IDENTITY_OPPONENT_MON1      1
#define IDENTITY_PLAYER_MON2        2
#define IDENTITY_OPPONENT_MON2      3

#define SIDE_PLAYER     0x0
#define SIDE_OPPONENT   0x1

#define BIT_SIDE        0x1
#define BIT_MON         0x2

#define GET_BANK_SIDE(bank)((GetBankIdentity(bank) & BIT_SIDE))

#define BATTLE_TYPE_DOUBLE          0x0001
#define BATTLE_TYPE_LINK            0x0002
#define BATTLE_TYPE_WILD            0x0004
#define BATTLE_TYPE_TRAINER         0x0008
#define BATTLE_TYPE_FIRST_BATTLE    0x0010
#define BATTLE_TYPE_20              0x0020
#define BATTLE_TYPE_MULTI           0x0040
#define BATTLE_TYPE_SAFARI          0x0080
#define BATTLE_TYPE_BATTLE_TOWER    0x0100
#define BATTLE_TYPE_WALLY_TUTORIAL  0x0200
#define BATTLE_TYPE_ROAMER          0x0400
#define BATTLE_TYPE_EREADER_TRAINER 0x0800
#define BATTLE_TYPE_KYOGRE_GROUDON  0x1000
#define BATTLE_TYPE_LEGENDARY       0x2000
#define BATTLE_TYPE_REGI            0x4000
#define BATTLE_TYPE_TWO_OPPONENTS   0x8000
#define BATTLE_TYPE_DOME            0x10000
#define BATTLE_TYPE_PALACE          0x20000
#define BATTLE_TYPE_ARENA           0x40000
#define BATTLE_TYPE_FACTORY         0x80000
#define BATTLE_TYPE_x100000         0x100000
#define BATTLE_TYPE_PYRAMID         0x200000
#define BATTLE_TYPE_INGAME_PARTNER  0x400000
#define BATTLE_TYPE_x800000         0x800000
#define BATTLE_TYPE_RECORDED        0x1000000
#define BATTLE_TYPE_x2000000        0x2000000
#define BATTLE_TYPE_x4000000        0x4000000
#define BATTLE_TYPE_SECRET_BASE     0x8000000
#define BATTLE_TYPE_GROUDON         0x10000000
#define BATTLE_TYPE_KYORGE          0x20000000
#define BATTLE_TYPE_RAYQUAZA        0x40000000
#define BATTLE_TYPE_x80000000       0x80000000

#define TRAINER_OPPONENT_3FE        0x3FE
#define TRAINER_OPPONENT_C00        0xC00
#define TRAINER_OPPONENT_800        0x800
#define STEVEN_PARTNER_ID           0xC03
#define SECRET_BASE_OPPONENT        0x400

#define BATTLE_TYPE_FRONTIER                (BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_DOME | BATTLE_TYPE_PALACE | BATTLE_TYPE_ARENA | BATTLE_TYPE_FACTORY | BATTLE_TYPE_x100000 | BATTLE_TYPE_PYRAMID)
#define BATTLE_TYPE_FRONTIER_NO_PYRAMID     (BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_DOME | BATTLE_TYPE_PALACE | BATTLE_TYPE_ARENA | BATTLE_TYPE_FACTORY | BATTLE_TYPE_x100000)

#define BATTLE_WON                  0x1
#define BATTLE_LOST                 0x2
#define BATTLE_DREW                 0x3
#define BATTLE_RAN                  0x4
#define BATTLE_PLAYER_TELEPORTED    0x5
#define BATTLE_POKE_FLED            0x6
#define BATTLE_CAUGHT               0x7
#define BATTLE_SAFARI_OUT_OF_BALLS  0x8
#define BATTLE_FORFEITED            0x9
#define BATTLE_OPPONENT_TELEPORTED  0xA

#define BATTLE_OUTCOME_BIT_x80      0x80

#define STATUS_SLEEP            0x7
#define STATUS_POISON           0x8
#define STATUS_BURN             0x10
#define STATUS_FREEZE           0x20
#define STATUS_PARALYSIS        0x40
#define STATUS_TOXIC_POISON     0x80
#define STATUS_TOXIC_COUNTER    0xF00

#define STATUS_PSN_ANY          ((STATUS_POISON | STATUS_TOXIC_POISON))
#define STATUS_ANY              ((STATUS_SLEEP | STATUS_POISON | STATUS_BURN | STATUS_FREEZE | STATUS_PARALYSIS | STATUS_TOXIC_POISON))

#define STATUS2_CONFUSION           0x00000007
#define STATUS2_FLINCHED            0x00000008
#define STATUS2_UPROAR              0x00000070
#define STATUS2_BIDE                0x00000300  // two bits 0x100, 0x200
#define STATUS2_LOCK_CONFUSE        0x00000C00
#define STATUS2_MULTIPLETURNS       0x00001000
#define STATUS2_WRAPPED             0x0000E000
#define STATUS2_INFATUATION         0x000F0000  // 4 bits, one for every bank
#define STATUS2_INFATUATED_WITH(bank)((gBitTable[bank] << 16))
#define STATUS2_FOCUS_ENERGY        0x00100000
#define STATUS2_TRANSFORMED         0x00200000
#define STATUS2_RECHARGE            0x00400000
#define STATUS2_RAGE                0x00800000
#define STATUS2_SUBSTITUTE          0x01000000
#define STATUS2_DESTINY_BOND        0x02000000
#define STATUS2_ESCAPE_PREVENTION   0x04000000
#define STATUS2_NIGHTMARE           0x08000000
#define STATUS2_CURSED              0x10000000
#define STATUS2_FORESIGHT           0x20000000
#define STATUS2_DEFENSE_CURL        0x40000000
#define STATUS2_TORMENT             0x80000000

#define STATUS3_LEECHSEED_BANK          0x3
#define STATUS3_LEECHSEED               0x4
#define STATUS3_ALWAYS_HITS             0x18    // two bits
#define STATUS3_PERISH_SONG             0x20
#define STATUS3_ON_AIR                  0x40
#define STATUS3_UNDERGROUND             0x80
#define STATUS3_MINIMIZED               0x100
#define STATUS3_ROOTED                  0x400
#define STATUS3_CHARGED_UP              0x200
#define STATUS3_YAWN                    0x1800  // two bits
#define STATUS3_IMPRISONED_OTHERS       0x2000
#define STATUS3_GRUDGE                  0x4000
#define STATUS3_CANT_SCORE_A_CRIT       0x8000
#define STATUS3_MUDSPORT                0x10000
#define STATUS3_WATERSPORT              0x20000
#define STATUS3_UNDERWATER              0x40000
#define STATUS3_INTIMIDATE_POKES        0x80000
#define STATUS3_TRACE                   0x100000

#define STATUS3_SEMI_INVULNERABLE       ((STATUS3_UNDERGROUND | STATUS3_ON_AIR | STATUS3_UNDERWATER))

#define HITMARKER_x10                   0x00000010
#define HITMARKER_x20                   0x00000020
#define HITMARKER_DESTINYBOND           0x00000040
#define HITMARKER_NO_ANIMATIONS         0x00000080
#define HITMARKER_IGNORE_SUBSTITUTE     0x00000100
#define HITMARKER_NO_ATTACKSTRING       0x00000200
#define HITMARKER_ATTACKSTRING_PRINTED  0x00000400
#define HITMARKER_NO_PPDEDUCT           0x00000800
#define HITMARKER_PURSUIT_TRAP          0x00001000
#define HITMARKER_IGNORE_SAFEGUARD      0x00002000
#define HITMARKER_SYNCHRONISE_EFFECT    0x00004000
#define HITMARKER_RUN                   0x00008000
#define HITMARKER_IGNORE_ON_AIR         0x00010000
#define HITMARKER_IGNORE_UNDERGROUND    0x00020000
#define HITMARKER_IGNORE_UNDERWATER     0x00040000
#define HITMARKER_UNABLE_TO_USE_MOVE    0x00080000
#define HITMARKER_x100000               0x00100000
#define HITMARKER_x200000               0x00200000
#define HITMARKER_x400000               0x00400000
#define HITMARKER_x800000               0x00800000
#define HITMARKER_GRUDGE                0x01000000
#define HITMARKER_OBEYS                 0x02000000
#define HITMARKER_x4000000              0x04000000
#define HITMARKER_x8000000              0x08000000
#define HITMARKER_FAINTED(bank)         ((gBitTable[bank] << 0x1C))
#define HITMARKER_UNK(bank)             ((0x10000000 << bank))

#define SIDE_STATUS_REFLECT          (1 << 0)
#define SIDE_STATUS_LIGHTSCREEN      (1 << 1)
#define SIDE_STATUS_X4               (1 << 2)
#define SIDE_STATUS_SPIKES           (1 << 4)
#define SIDE_STATUS_SAFEGUARD        (1 << 5)
#define SIDE_STATUS_FUTUREATTACK     (1 << 6)
#define SIDE_STATUS_MIST             (1 << 8)
#define SIDE_STATUS_SPIKES_DAMAGED   (1 << 9)

#define ACTION_USE_MOVE             0
#define ACTION_USE_ITEM             1
#define ACTION_SWITCH               2
#define ACTION_RUN                  3
#define ACTION_WATCHES_CAREFULLY    4
#define ACTION_SAFARI_ZONE_BALL     5
#define ACTION_POKEBLOCK_CASE       6
#define ACTION_GO_NEAR              7
#define ACTION_SAFARI_ZONE_RUN      8
#define ACTION_9                    9
#define ACTION_RUN_BATTLESCRIPT     10 // when executing an action
#define ACTION_CANCEL_PARTNER       12 // when choosing an action
#define ACTION_FINISHED             12 // when executing an action
#define ACTION_NOTHING_FAINTED      13 // when choosing an action
#define ACTION_INIT_VALUE           0xFF

#define MOVESTATUS_MISSED             (1 << 0)
#define MOVESTATUS_SUPEREFFECTIVE     (1 << 1)
#define MOVESTATUS_NOTVERYEFFECTIVE   (1 << 2)
#define MOVESTATUS_NOTAFFECTED        (1 << 3)
#define MOVESTATUS_ONEHITKO           (1 << 4)
#define MOVESTATUS_FAILED             (1 << 5)
#define MOVESTATUS_ENDURED            (1 << 6)
#define MOVESTATUS_HUNGON             (1 << 7)

#define MOVESTATUS_NOEFFECT ((MOVESTATUS_MISSED | MOVESTATUS_NOTAFFECTED | MOVESTATUS_FAILED))

#define MAX_TRAINER_ITEMS 4
#define MAX_MON_MOVES 4

#define WEATHER_RAIN_TEMPORARY      (1 << 0)
#define WEATHER_RAIN_DOWNPOUR       (1 << 1)
#define WEATHER_RAIN_PERMANENT      (1 << 2)
#define WEATHER_RAIN_ANY ((WEATHER_RAIN_TEMPORARY | WEATHER_RAIN_DOWNPOUR | WEATHER_RAIN_PERMANENT))
#define WEATHER_SANDSTORM_TEMPORARY (1 << 3)
#define WEATHER_SANDSTORM_PERMANENT (1 << 4)
#define WEATHER_SANDSTORM_ANY ((WEATHER_SANDSTORM_TEMPORARY | WEATHER_SANDSTORM_PERMANENT))
#define WEATHER_SUN_TEMPORARY       (1 << 5)
#define WEATHER_SUN_PERMANENT       (1 << 6)
#define WEATHER_SUN_ANY ((WEATHER_SUN_TEMPORARY | WEATHER_SUN_PERMANENT))
#define WEATHER_HAIL                (1 << 7)
#define WEATHER_HAIL_ANY ((WEATHER_HAIL))
#define WEATHER_ANY ((WEATHER_RAIN_ANY | WEATHER_SANDSTORM_ANY | WEATHER_SUN_ANY | WEATHER_HAIL_ANY))

#define BATTLE_TERRAIN_GRASS        0
#define BATTLE_TERRAIN_LONG_GRASS   1
#define BATTLE_TERRAIN_SAND         2
#define BATTLE_TERRAIN_UNDERWATER   3
#define BATTLE_TERRAIN_WATER        4
#define BATTLE_TERRAIN_POND         5
#define BATTLE_TERRAIN_ROCK         6
#define BATTLE_TERRAIN_CAVE         7
#define BATTLE_TERRAIN_INSIDE       8

// array entries for battle communication
#define MULTIUSE_STATE          0x0
#define CURSOR_POSITION         0x1
#define TASK_ID                 0x1 // task Id and cursor position share the same field
#define SPRITES_INIT_STATE1     0x1 // shares the Id as well
#define SPRITES_INIT_STATE2     0x2
#define MOVE_EFFECT_BYTE        0x3
#define ACTIONS_CONFIRMED_COUNT 0x4
#define MULTISTRING_CHOOSER     0x5
#define MSG_DISPLAY             0x7
#define BATTLE_COMMUNICATION_ENTRIES_COUNT  0x8

#define MOVE_TARGET_SELECTED        0x0
#define MOVE_TARGET_DEPENDS         0x1
#define MOVE_TARGET_USER            0x2
#define MOVE_TARGET_RANDOM          0x4
#define MOVE_TARGET_x10             0x10
#define MOVE_TARGET_BOTH            0x8
#define MOVE_TARGET_FOES_AND_ALLY   0x20
#define MOVE_TARGET_OPPONENTS_FIELD 0x40

#define TYPE_MUL_NO_EFFECT          0
#define TYPE_MUL_NOT_EFFECTIVE      5
#define TYPE_MUL_NORMAL             10
#define TYPE_MUL_SUPER_EFFECTIVE    20

#define BS_GET_TARGET                   0
#define BS_GET_ATTACKER                 1
#define BS_GET_EFFECT_BANK              2
#define BS_ATTACKER_WITH_PARTNER        4 // for atk98_status_icon_update
#define BS_GET_ATTACKER_SIDE            8 // for atk1E_jumpifability
#define BS_GET_NOT_ATTACKER_SIDE        9 // for atk1E_jumpifability
#define BS_GET_SCRIPTING_BANK           10
#define BS_GET_OPPONENT1                12
#define BS_GET_PLAYER2                  13
#define BS_GET_OPPONENT2                14

// for battle script commands
#define CMP_EQUAL               0x0
#define CMP_NOT_EQUAL           0x1
#define CMP_GREATER_THAN        0x2
#define CMP_LESS_THAN           0x3
#define CMP_COMMON_BITS         0x4
#define CMP_NO_COMMON_BITS      0x5

struct TrainerMonNoItemDefaultMoves
{
    u16 iv;
    u8 lvl;
    u16 species;
};

u8 AbilityBattleEffects(u8 caseID, u8 bank, u8 ability, u8 special, u16 moveArg);
u8 GetBankSide(u8 bank);

struct TrainerMonItemDefaultMoves
{
    u16 iv;
    u8 lvl;
    u16 species;
    u16 heldItem;
};

struct TrainerMonNoItemCustomMoves
{
    u16 iv;
    u8 lvl;
    u16 species;
    u16 moves[4];
};

struct TrainerMonItemCustomMoves
{
    u16 iv;
    u8 lvl;
    u16 species;
    u16 heldItem;
    u16 moves[4];
};

union TrainerMonPtr
{
    struct TrainerMonNoItemDefaultMoves* NoItemDefaultMoves;
    struct TrainerMonNoItemCustomMoves* NoItemCustomMoves;
    struct TrainerMonItemDefaultMoves* ItemDefaultMoves;
    struct TrainerMonItemCustomMoves* ItemCustomMoves;
};

struct Trainer
{
    /*0x00*/ u8 partyFlags;
    /*0x01*/ u8 trainerClass;
    /*0x02*/ u8 encounterMusic_gender; // last bit is gender
    /*0x03*/ u8 trainerPic;
    /*0x04*/ u8 trainerName[12];
    /*0x10*/ u16 items[4];
    /*0x18*/ bool8 doubleBattle;
    /*0x1C*/ u32 aiFlags;
    /*0x20*/ u8 partySize;
    /*0x24*/ union TrainerMonPtr party;
};

#define PARTY_FLAG_CUSTOM_MOVES     0x1
#define PARTY_FLAG_HAS_ITEM         0x2

extern const struct Trainer gTrainers[];

#define TRAINER_ENCOUNTER_MUSIC(trainer)((gTrainers[trainer].encounterMusic_gender & 0x7F))

struct UnknownFlags
{
    u32 flags[4];
};

#define UNKNOWN_FLAG_FLASH_FIRE 1

struct DisableStruct
{
    /*0x00*/ u32 unk0;
    /*0x04*/ u16 disabledMove;
    /*0x06*/ u16 encoredMove;
    /*0x08*/ u8 protectUses;
    /*0x09*/ u8 stockpileCounter;
    /*0x0A*/ u8 substituteHP;
    /*0x0B*/ u8 disableTimer1 : 4;
    /*0x0B*/ u8 disableTimer2 : 4;
    /*0x0C*/ u8 encoredMovePos;
    /*0x0D*/ u8 unkD;
    /*0x0E*/ u8 encoreTimer1 : 4;
    /*0x0E*/ u8 encoreTimer2 : 4;
    /*0x0F*/ u8 perishSong1 : 4;
    /*0x0F*/ u8 perishSong2 : 4;
    /*0x10*/ u8 furyCutterCounter;
    /*0x11*/ u8 rolloutCounter1 : 4;
    /*0x11*/ u8 rolloutCounter2 : 4;
    /*0x12*/ u8 chargeTimer1 : 4;
    /*0x12*/ u8 chargeTimer2 : 4;
    /*0x13*/ u8 tauntTimer1:4;
    /*0x13*/ u8 tauntTimer2:4;
    /*0x14*/ u8 bankPreventingEscape;
    /*0x15*/ u8 bankWithSureHit;
    /*0x16*/ u8 isFirstTurn;
    /*0x17*/ u8 unk17;
    /*0x18*/ u8 truantCounter : 1;
    /*0x18*/ u8 truantUnknownBit : 1;
    /*0x18*/ u8 unk18_a_2 : 2;
    /*0x18*/ u8 unk18_b : 4;
    /*0x19*/ u8 rechargeCounter;
    /*0x1A*/ u8 unk1A[2];
};

extern struct DisableStruct gDisableStructs[BATTLE_BANKS_COUNT];

struct ProtectStruct
{
    /* field_0 */
    u32 protected:1;
    u32 endured:1;
    u32 onlyStruggle:1;
    u32 helpingHand:1;
    u32 bounceMove:1;
    u32 stealMove:1;
    u32 flag0Unknown:1;
    u32 prlzImmobility:1;
    /* field_1 */
    u32 confusionSelfDmg:1;
    u32 targetNotAffected:1;
    u32 chargingTurn:1;
    u32 fleeFlag:2; // for RunAway and Smoke Ball
    u32 usedImprisionedMove:1;
    u32 loveImmobility:1;
    u32 usedDisabledMove:1;
    /* field_2 */
    u32 usedTauntedMove:1;      // 0x1
    u32 flag2Unknown:1;         // 0x2
    u32 flinchImmobility:1;     // 0x4
    u32 notFirstStrike:1;       // 0x8
    u32 flag_x10 : 1;           // 0x10
    u32 flag_x20 : 1;           // 0x20
    u32 flag_x40 : 1;           // 0x40
    u32 flag_x80 : 1;           // 0x80
    /* field_3 */
    u32 field3 : 8;

    /* field_4 */ u32 physicalDmg;
    /* field_8 */ u32 specialDmg;
    /* field_C */ u8 physicalBank;
    /* field_D */ u8 specialBank;
    /* field_E */ u16 fieldE;
};

extern struct ProtectStruct gProtectStructs[BATTLE_BANKS_COUNT];

struct SpecialStatus
{
    u8 statLowered : 1;             // 0x1
    u8 lightningRodRedirected : 1;  // 0x2
    u8 restoredBankSprite: 1;       // 0x4
    u8 intimidatedPoke : 1;         // 0x8
    u8 traced : 1;                  // 0x10
    u8 flag20 : 1;
    u8 flag40 : 1;
    u8 focusBanded : 1;
    u8 field1[3];
    s32 moveturnLostHP;
    s32 moveturnLostHP_physical;
    s32 moveturnLostHP_special;
    u8 moveturnPhysicalBank;
    u8 moveturnSpecialBank;
    u8 field12;
    u8 field13;
};

extern struct SpecialStatus gSpecialStatuses[BATTLE_BANKS_COUNT];

struct SideTimer
{
    /*0x00*/ u8 reflectTimer;
    /*0x01*/ u8 reflectBank;
    /*0x02*/ u8 lightscreenTimer;
    /*0x03*/ u8 lightscreenBank;
    /*0x04*/ u8 mistTimer;
    /*0x05*/ u8 mistBank;
    /*0x06*/ u8 safeguardTimer;
    /*0x07*/ u8 safeguardBank;
    /*0x08*/ u8 followmeTimer;
    /*0x09*/ u8 followmeTarget;
    /*0x0A*/ u8 spikesAmount;
    /*0x0B*/ u8 fieldB;
};

extern struct SideTimer gSideTimers[];

struct WishFutureKnock
{
    u8 futureSightCounter[BATTLE_BANKS_COUNT];
    u8 futureSightAttacker[BATTLE_BANKS_COUNT];
    s32 futureSightDmg[BATTLE_BANKS_COUNT];
    u16 futureSightMove[BATTLE_BANKS_COUNT];
    u8 wishCounter[BATTLE_BANKS_COUNT];
    u8 wishUserID[BATTLE_BANKS_COUNT];
    u8 weatherDuration;
    u8 knockedOffPokes[2];
};

extern struct WishFutureKnock gWishFutureKnock;

struct AI_ThinkingStruct
{
    u8 aiState;
    u8 movesetIndex;
    u16 moveConsidered;
    s8 score[4];
    u32 funcResult;
    u32 aiFlags;
    u8 aiAction;
    u8 aiLogicId;
    u8 filler12[6];
    u8 simulatedRNG[4];
};

struct UsedMoves
{
    u16 moves[BATTLE_BANKS_COUNT];
    u16 unknown[BATTLE_BANKS_COUNT];
};

struct BattleHistory
{
    struct UsedMoves usedMoves[BATTLE_BANKS_COUNT];
    u8 abilities[BATTLE_BANKS_COUNT];
    u8 itemEffects[BATTLE_BANKS_COUNT];
    u16 trainerItems[BATTLE_BANKS_COUNT];
    u8 itemsNo;
};

struct BattleScriptsStack
{
    const u8 *ptr[8];
    u8 size;
};

struct BattleCallbacksStack
{
    void (*function[8])(void);
    u8 size;
};

struct StatsArray
{
    u16 hp;
    u16 atk;
    u16 def;
    u16 spd;
    u16 spAtk;
    u16 spDef;
};

struct BattleResources
{
    struct SecretBaseRecord* secretBase;
    struct UnknownFlags *flags;
    struct BattleScriptsStack* battleScriptsStack;
    struct BattleCallbacksStack* battleCallbackStack;
    struct StatsArray* statsBeforeLvlUp;
    struct AI_ThinkingStruct *ai;
    struct BattleHistory *battleHistory;
    struct BattleScriptsStack *AI_ScriptsStack;
};

extern struct BattleResources* gBattleResources;

#define BATTLESCRIPTS_STACK     (gBattleResources->battleScriptsStack)
#define BATTLE_CALLBACKS_STACK  (gBattleResources->battleCallbackStack)
#define BATTLE_LVLUP_STATS      (gBattleResources->statsBeforeLvlUp)

struct BattleResults
{
    u8 playerFaintCounter;    // 0x0
    u8 opponentFaintCounter;  // 0x1
    u8 playerSwitchesCounter; // 0x2
    u8 unk3;                  // 0x3
    u8 unk4;                  // 0x4
    u8 unk5_0:1;              // 0x5
    u8 usedMasterBall:1;      // 0x5
    u8 caughtMonBall:4;       // 0x5
    u8 unk5_6:1;              // 0x5
    u8 unk5_7:1;              // 0x5
    u16 playerMon1Species;    // 0x6
    u8 playerMon1Name[11];    // 0x8
    u8 battleTurnCounter;     // 0x13
    u8 playerMon2Name[11];    // 0x14
    u8 field_1F;              // 0x1F
    u16 lastOpponentSpecies;  // 0x20
    u16 lastUsedMovePlayer;   // 0x22
    u16 lastUsedMoveOpponent; // 0x24
    u16 playerMon2Species;    // 0x26
    u16 caughtMonSpecies;     // 0x28
    u8 caughtMonNick[10];     // 0x2A
    u8 filler34[2];
    u8 catchAttempts[11];     // 0x36
};

extern struct BattleResults gBattleResults;

struct BattleStruct
{
    u8 turnEffectsTracker;
    u8 turnEffectsBank;
    u8 filler2;
    u8 turncountersTracker;
    u8 wrappedMove[8]; // ask gamefreak why they declared it that way
    u8 moveTarget[4];
    u8 expGetterId;
    u8 field_11;
    u8 wildVictorySong;
    u8 dynamicMoveType;
    u8 wrappedBy[4];
    u16 assistPossibleMoves[5 * 4]; // 5 mons, each of them knowing 4 moves
    u8 field_40;
    u8 field_41;
    u8 field_42;
    u8 field_43;
    u8 field_44;
    u8 field_45;
    u8 field_46;
    u8 field_47;
    u8 focusPunchBank;
    u8 field_49;
    u8 moneyMultiplier;
    u8 field_4B;
    u8 switchInAbilitiesCounter;
    u8 field_4D;
    u8 field_4E;
    u8 field_4F;
    u16 expValue;
    u8 field_52;
    u8 sentInPokes;
    bool8 selectionScriptFinished[BATTLE_BANKS_COUNT];
    u8 field_58[4];
    u8 field_5C[4];
    u8 field_60[4][3];
    u8 runTries;
    u8 caughtMonNick[11];
    u8 field_78;
    u8 field_79;
    u8 field_7A;
    u8 field_7B;
    u8 field_7C;
    u8 field_7D;
    u8 field_7E;
    u8 formToChangeInto;
    u8 chosenMovePositions[BATTLE_BANKS_COUNT];
    u8 stateIdAfterSelScript[BATTLE_BANKS_COUNT];
    u8 field_88;
    u8 field_89;
    u8 field_8A;
    u8 field_8B;
    u8 field_8C;
    u8 field_8D;
    u8 stringMoveType;
    u8 expGetterBank;
    u8 field_90;
    u8 field_91;
    u8 field_92;
    u8 field_93;
    u8 field_94;
    u8 field_95;
    u8 field_96;
    u8 field_97;
    u8 mirrorMoves[8]; // ask gamefreak why they declared it that way
    u8 field_A0;
    u8 field_A1;
    u8 field_A2;
    u8 field_A3;
    u8 field_A4;
    u8 field_A5;
    u8 field_A6;
    u8 field_A7;
    u16 hpOnSwitchout[2];
    u32 savedBattleTypeFlags;
    u8 field_B0;
    u8 hpScale;
    u8 synchronizeMoveEffect;
    u8 field_B3;
    void (*savedCallback)(void);
    u16 usedHeldItems[BATTLE_BANKS_COUNT];
    u8 field_C0[4];
    u8 AI_itemType[2];
    u8 AI_itemFlags[2];
    u16 choicedMove[BATTLE_BANKS_COUNT];
    u16 changedItems[BATTLE_BANKS_COUNT];
    u8 intimidateBank;
    u8 switchInItemsCounter;
    u8 field_DA;
    u8 turnSideTracker;
    u8 fillerDC[0xDF-0xDC];
    u8 field_DF;
    u8 mirrorMoveArrays[32];
    u16 castformPalette[4][16];
    u8 field_180;
    u8 field_181;
    u8 field_182;
    u8 field_183;
    struct BattleEnigmaBerry battleEnigmaBerry;
    u8 field_1A0;
    u8 field_1A1;
    bool8 overworldWeatherDone;
    u8 atkCancellerTracker;
    u8 field_1A4[240];
    u8 field_294[4];
    u8 field_298[8];
    u8 field_2A0;
    u8 field_2A1;
    u8 field_2A2;
};

extern struct BattleStruct* gBattleStruct;

#define MEME_ACCESS_U8(structName, structPtr, arrayId, offsetField, value)      \
{                                                                               \
    u8* var2 = (u8*)((u32)(arrayId));                                           \
    var2 = (u32)(structPtr) + var2;                                             \
    var2[offsetof(struct structName, offsetField)] = value;                     \
}

#define GET_MOVE_TYPE(move, typeArg)                        \
{                                                           \
    if (gBattleStruct->dynamicMoveType)                     \
        typeArg = gBattleStruct->dynamicMoveType & 0x3F;    \
    else                                                    \
        typeArg = gBattleMoves[move].type;                  \
}

#define MOVE_EFFECT_SLEEP               0x1
#define MOVE_EFFECT_POISON              0x2
#define MOVE_EFFECT_BURN                0x3
#define MOVE_EFFECT_FREEZE              0x4
#define MOVE_EFFECT_PARALYSIS           0x5
#define MOVE_EFFECT_TOXIC               0x6
#define MOVE_EFFECT_CONFUSION           0x7
#define MOVE_EFFECT_FLINCH              0x8
#define MOVE_EFFECT_TRI_ATTACK          0x9
#define MOVE_EFFECT_UPROAR              0xA
#define MOVE_EFFECT_PAYDAY              0xB
#define MOVE_EFFECT_CHARGING            0xC
#define MOVE_EFFECT_WRAP                0xD
#define MOVE_EFFECT_RECOIL_25           0xE
#define MOVE_EFFECT_ATK_PLUS_1          0xF
#define MOVE_EFFECT_DEF_PLUS_1          0x10
#define MOVE_EFFECT_SPD_PLUS_1          0x11
#define MOVE_EFFECT_SP_ATK_PLUS_1       0x12
#define MOVE_EFFECT_SP_DEF_PLUS_1       0x13
#define MOVE_EFFECT_ACC_PLUS_1          0x14
#define MOVE_EFFECT_EVS_PLUS_1          0x15
#define MOVE_EFFECT_ATK_MINUS_1         0x16
#define MOVE_EFFECT_DEF_MINUS_1         0x17
#define MOVE_EFFECT_SPD_MINUS_1         0x18
#define MOVE_EFFECT_SP_ATK_MINUS_1      0x19
#define MOVE_EFFECT_SP_DEF_MINUS_1      0x1A
#define MOVE_EFFECT_ACC_MINUS_1         0x1B
#define MOVE_EFFECT_EVS_MINUS_1         0x1C
#define MOVE_EFFECT_RECHARGE            0x1D
#define MOVE_EFFECT_RAGE                0x1E
#define MOVE_EFFECT_STEAL_ITEM          0x1F
#define MOVE_EFFECT_PREVENT_ESCAPE      0x20
#define MOVE_EFFECT_NIGHTMARE           0x21
#define MOVE_EFFECT_ALL_STATS_UP        0x22
#define MOVE_EFFECT_RAPIDSPIN           0x23
#define MOVE_EFFECT_REMOVE_PARALYSIS    0x24
#define MOVE_EFFECT_ATK_DEF_DOWN        0x25
#define MOVE_EFFECT_RECOIL_33_PARALYSIS 0x26
#define MOVE_EFFECT_ATK_PLUS_2          0x27
#define MOVE_EFFECT_DEF_PLUS_2          0x28
#define MOVE_EFFECT_SPD_PLUS_2          0x29
#define MOVE_EFFECT_SP_ATK_PLUS_2       0x2A
#define MOVE_EFFECT_SP_DEF_PLUS_2       0x2B
#define MOVE_EFFECT_ACC_PLUS_2          0x2C
#define MOVE_EFFECT_EVS_PLUS_2          0x2D
#define MOVE_EFFECT_ATK_MINUS_2         0x2E
#define MOVE_EFFECT_DEF_MINUS_2         0x2F
#define MOVE_EFFECT_SPD_MINUS_2         0x30
#define MOVE_EFFECT_SP_ATK_MINUS_2      0x31
#define MOVE_EFFECT_SP_DEF_MINUS_2      0x32
#define MOVE_EFFECT_ACC_MINUS_2         0x33
#define MOVE_EFFECT_EVS_MINUS_2         0x34
#define MOVE_EFFECT_THRASH              0x35
#define MOVE_EFFECT_KNOCK_OFF           0x36
#define MOVE_EFFECT_NOTHING_37          0x37
#define MOVE_EFFECT_NOTHING_38          0x38
#define MOVE_EFFECT_NOTHING_39          0x39
#define MOVE_EFFECT_NOTHING_3A          0x3A
#define MOVE_EFFECT_SP_ATK_TWO_DOWN     0x3B
#define MOVE_EFFECT_NOTHING_3C          0x3C
#define MOVE_EFFECT_NOTHING_3D          0x3D
#define MOVE_EFFECT_NOTHING_3E          0x3E
#define MOVE_EFFECT_NOTHING_3F          0x3F
#define MOVE_EFFECT_AFFECTS_USER        0x40
#define MOVE_EFFECT_CERTAIN             0x80

// battle animations ids

#define B_ANIM_CASTFORM_CHANGE      0x0
#define B_ANIM_STATS_CHANGE         0x1
#define B_ANIM_SUBSTITUTE_FADE      0x2
#define B_ANIM_SUBSTITUTE_APPEAR    0x3
#define B_ANIM_x4                   0x4
#define B_ANIM_ITEM_KNOCKOFF        0x5
#define B_ANIM_TURN_TRAP            0x6
#define B_ANIM_ITEM_EFFECT          0x7
#define B_ANIM_SMOKEBALL_ESCAPE     0x8
#define B_ANIM_HANGED_ON            0x9
#define B_ANIM_RAIN_CONTINUES       0xA
#define B_ANIM_SUN_CONTINUES        0xB
#define B_ANIM_SANDSTORM_CONTINUES  0xC
#define B_ANIM_HAIL_CONTINUES       0xD
#define B_ANIM_LEECH_SEED_DRAIN     0xE
#define B_ANIM_MON_HIT              0xF
#define B_ANIM_ITEM_STEAL           0x10
#define B_ANIM_SNATCH_MOVE          0x11
#define B_ANIM_FUTURE_SIGHT_HIT     0x12
#define B_ANIM_x13                  0x13
#define B_ANIM_x14                  0x14
#define B_ANIM_INGRAIN_HEAL         0x15
#define B_ANIM_WISH_HEAL            0x16
#define B_ANIM_x17                  0x17
#define B_ANIM_x18                  0x18
#define B_ANIM_x19                  0x19
#define B_ANIM_x1A                  0x1A
#define B_ANIM_x1B                  0x1B
#define B_ANIM_x1C                  0x1C
#define B_ANIM_x1D                  0x1D

#define GET_STAT_BUFF_ID(n)((n & 0xF))              // first four bits 0x1, 0x2, 0x4, 0x8
#define GET_STAT_BUFF_VALUE(n)(((n >> 4) & 7))      // 0x10, 0x20, 0x40
#define STAT_BUFF_NEGATIVE 0x80                     // 0x80, the sign bit

#define SET_STAT_BUFF_ID(n)((n & 0xF))
#define SET_STAT_BUFF_VALUE(n)(((s8)(((s8)(n) << 4)) & 0xF0))

struct BattleScripting
{
    s32 painSplitHp;
    s32 bideDmg;
    u8 multihitString[6];
    u8 dmgMultiplier;
    u8 field_F;
    u8 animArg1;
    u8 animArg2;
    u8 field_12;
    u8 field_13;
    u8 atk49_state;
    u8 field_15;
    u8 field_16;
    u8 bank;
    u8 animTurn;
    u8 animTargetsHit;
    u8 statChanger;
    u8 field_1B;
    u8 atk23_state;
    u8 battleStyle;
    u8 atk6C_state;
    u8 learnMoveState;
    u8 field_20;
    u8 reshowMainState;
    u8 reshowHelperState;
    u8 field_23;
    u8 field_24;
    u8 multiplayerId;
};

extern struct BattleScripting gBattleScripting;

// functions

// battle_1
void LoadBattleTextboxAndBackground(void);
void LoadBattleEntryBackground(void);
void ApplyPlayerChosenFrameToBattleMenu(void);
bool8 LoadChosenBattleElement(u8 caseId);
void task00_0800F6FC(u8 taskId);

// battle_5
void AllocateBattleResrouces(void);
void FreeBattleResources(void);
void AdjustFriendshipOnBattleFaint(u8 bank);
void sub_80571DC(u8 bank, u8 arg1);
u32 sub_805725C(u8 bank);

// battle 7
void AllocateBattleSpritesData(void);
void FreeBattleSpritesData(void);
void AllocateMonSpritesGfx(void);
void FreeMonSpritesGfx(void);
void BattleMusicStop(void);
void sub_805E990(struct Pokemon *mon, u8 bank);
void sub_805EF14(void);
bool8 BattleInitAllSprites(u8 *state1, u8 *state2);
void sub_805E350(void);
bool8 BattleLoadAllHealthBoxesGfx(u8 state);
void LoadAndCreateEnemyShadowSprites(void);
void SetBankEnemyShadowSpriteCallback(u8 bank, u16 species);
void BattleLoadPlayerMonSpriteGfx(struct Pokemon *mon, u8 bank);
void BattleLoadOpponentMonSpriteGfx(struct Pokemon *mon, u8 bank);
void BattleLoadSubstituteSpriteGfx(u8 bank, bool8 arg1);

enum
{
    BACK_PIC_BRENDAN,
    BACK_PIC_MAY,
    BACK_PIC_RED,
    BACK_PIC_LEAF,
    BACK_PIC_RS_BRENDAN,
    BACK_PIC_RS_MAY,
    BACK_PIC_WALLY,
    BACK_PIC_STEVEN
};
void LoadBackTrainerBankSpriteGfx(u8 backPicId, u8 bank);

// rom_80A5C6C
u8 GetBankSide(u8 bank);
u8 GetBankIdentity(u8 bank);
u8 GetBankByIdentity(u8 bank);

struct BattleSpriteInfo
{
    u16 invisible : 1; // 0x1
    u16 flag_x2 : 1; // 0x2
    u16 behindSubstitute : 1; // 0x4
    u16 flag_x8 : 1; // 0x8
    u16 hpNumbersNoBars : 1; // 0x10
    u16 transformSpecies;
};

struct BattleAnimationInfo
{
    u16 field; // to fill up later
};

struct BattleHealthboxInfo
{
    u8 flag_x1 : 1;
    u8 flag_x2 : 1;
    u8 flag_x4 : 1;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u8 field_8;
    u8 field_9;
    u8 field_A;
    u8 field_B;
};

struct BattleSpriteData
{
    struct BattleSpriteInfo *bankData;
    struct BattleHealthboxInfo *healthBoxesData;
    struct BattleAnimationInfo *animationData;
};

extern struct BattleSpriteData *gBattleSpritesDataPtr;

// Move this somewhere else

#include "sprite.h"

struct MonSpritesGfx
{
    void* firstDecompressed; // ptr to the decompressed sprite of the first pokemon
    void* sprites[4];
    struct SpriteTemplate templates[4];
};

extern struct BattleSpritesGfx* gMonSpritesGfx;
extern u8 gBattleOutcome;
extern u16 gLastUsedItem;
extern u32 gBattleTypeFlags;
extern struct MonSpritesGfx* gMonSpritesGfxPtr;

#endif // GUARD_BATTLE_H
