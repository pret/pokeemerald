#ifndef GUARD_BATTLE_H
#define GUARD_BATTLE_H

// should they be included here or included individually by every file?
#include "constants/battle.h"
#include "battle_main.h"
#include "battle_message.h"
#include "battle_util.h"
#include "battle_script_commands.h"
#include "battle_ai_switch_items.h"
#include "battle_gfx_sfx_util.h"
#include "battle_util2.h"
#include "battle_bg.h"
#include "pokeball.h"
#include "battle_debug.h"

#define GET_BATTLER_POSITION(battler)     (gBattlerPositions[battler])
#define GET_BATTLER_SIDE(battler)         (GetBattlerPosition(battler) & BIT_SIDE)
#define GET_BATTLER_SIDE2(battler)        (GET_BATTLER_POSITION(battler) & BIT_SIDE)

// Used to exclude moves learned temporarily by Transform or Mimic
#define MOVE_IS_PERMANENT(battler, moveSlot)                        \
   (!(gBattleMons[battler].status2 & STATUS2_TRANSFORMED)           \
 && !(gDisableStructs[battler].mimickedMoves & gBitTable[moveSlot]))

// Battle Actions
// These determine what each battler will do in a turn
#define B_ACTION_USE_MOVE               0
#define B_ACTION_USE_ITEM               1
#define B_ACTION_SWITCH                 2
#define B_ACTION_RUN                    3
#define B_ACTION_SAFARI_WATCH_CAREFULLY 4
#define B_ACTION_SAFARI_BALL            5
#define B_ACTION_SAFARI_POKEBLOCK       6
#define B_ACTION_SAFARI_GO_NEAR         7
#define B_ACTION_SAFARI_RUN             8
#define B_ACTION_WALLY_THROW            9
#define B_ACTION_EXEC_SCRIPT            10
#define B_ACTION_TRY_FINISH             11
#define B_ACTION_FINISHED               12
#define B_ACTION_CANCEL_PARTNER         12 // when choosing an action
#define B_ACTION_NOTHING_FAINTED        13 // when choosing an action
#define B_ACTION_DEBUG                  20
#define B_ACTION_THROW_BALL             21 // R to throw last used ball
#define B_ACTION_NONE                   0xFF

#define BATTLE_BUFFER_LINK_SIZE 0x1000

struct ResourceFlags
{
    u32 flags[4];
};

#define RESOURCE_FLAG_FLASH_FIRE        0x1
#define RESOURCE_FLAG_ROOST             0x2
#define RESOURCE_FLAG_UNBURDEN          0x4
#define RESOURCE_FLAG_INTIMIDATED       0x8
#define RESOURCE_FLAG_TRACED            0x10
#define RESOURCE_FLAG_EMERGENCY_EXIT    0x20
#define RESOURCE_FLAG_NEUTRALIZING_GAS  0x40

struct DisableStruct
{
    u32 transformedMonPersonality;
    u16 disabledMove;
    u16 encoredMove;
    u8 protectUses;
    u8 stockpileCounter;
    s8 stockpileDef;
    s8 stockpileSpDef;
    s8 stockpileBeforeDef;
    s8 stockpileBeforeSpDef;
    u8 substituteHP;
    u8 disableTimer:4;
    u8 disableTimerStartValue:4;
    u8 encoredMovePos;
    u8 encoreTimer:4;
    u8 encoreTimerStartValue:4;
    u8 perishSongTimer:4;
    u8 perishSongTimerStartValue:4;
    u8 furyCutterCounter;
    u8 rolloutTimer:4;
    u8 rolloutTimerStartValue:4;
    u8 chargeTimer:4;
    u8 chargeTimerStartValue:4;
    u8 tauntTimer:4;
    u8 tauntTimer2:4;
    u8 battlerPreventingEscape;
    u8 battlerWithSureHit;
    u8 isFirstTurn;
    u8 truantCounter:1;
    u8 truantSwitchInHack:1;
    u8 mimickedMoves:4;
    u8 rechargeTimer;
    u8 autotomizeCount;
    u8 slowStartTimer;
    u8 embargoTimer;
    u8 magnetRiseTimer;
    u8 telekinesisTimer;
    u8 healBlockTimer;
    u8 laserFocusTimer;
    u8 throatChopTimer;
    u8 usedMoves:4;
    u8 wrapTurns;
    u8 noRetreat:1;
    u8 tarShot:1;
    u8 octolock:1;
};

struct ProtectStruct
{
    u32 protected:1;
    u32 spikyShielded:1;
    u32 kingsShielded:1;
    u32 banefulBunkered:1;
    u32 obstructed:1;
    u32 endured:1;
    u32 noValidMoves:1;
    u32 helpingHand:1;
    u32 bounceMove:1;
    u32 stealMove:1;
    u32 prlzImmobility:1;
    u32 confusionSelfDmg:1;
    u32 targetAffected:1;
    u32 chargingTurn:1;
    u32 fleeType:2; // 0: Normal, 1: FLEE_ITEM, 2: FLEE_ABILITY
    u32 usedImprisonedMove:1;
    u32 loveImmobility:1;
    u32 usedDisabledMove:1;
    u32 usedTauntedMove:1;
    u32 flag2Unknown:1; // Only set to 0 once. Checked in 'WasUnableToUseMove' function.
    u32 flinchImmobility:1;
    u32 notFirstStrike:1;
    u32 palaceUnableToUseMove:1;
    u32 usesBouncedMove:1;
    u32 usedHealBlockedMove:1;
    u32 usedGravityPreventedMove:1;
    u32 powderSelfDmg:1;
    u32 usedThroatChopPreventedMove:1;
    u32 statRaised:1;
    u32 usedMicleBerry:1;
    u32 usedCustapBerry:1;    // also quick claw
    u32 touchedProtectLike:1;
    u32 disableEjectPack:1;
    u32 statFell:1;
    u32 pranksterElevated:1;
    u32 quickDraw:1;
    u32 physicalDmg;
    u32 specialDmg;
    u8 physicalBattlerId;
    u8 specialBattlerId;
};

struct SpecialStatus
{
    u8 statLowered:1;
    u8 lightningRodRedirected:1;
    u8 restoredBattlerSprite: 1;
    u8 intimidatedMon:1;
    u8 traced:1;
    u8 ppNotAffectedByPressure:1;
    u8 faintedHasReplacement:1;
    u8 focusBanded:1;
    u8 focusSashed:1;
    u8 sturdied:1;
    u8 stormDrainRedirected:1;
    u8 switchInAbilityDone:1;
    u8 switchInItemDone:1;
    u8 instructedChosenTarget:3;
    u8 berryReduced:1;
    u8 gemBoost:1;
    u8 rototillerAffected:1;  // to be affected by rototiller
    u8 gemParam;
    u8 damagedMons:4; // Mons that have been damaged directly by using a move, includes substitute.
    u8 dancerUsedMove:1;
    u8 dancerOriginalTarget:3;
    u8 announceNeutralizingGas:1;   // See Cmd_switchineffects
    u8 neutralizingGasRemoved:1;    // See VARIOUS_TRY_END_NEUTRALIZING_GAS
    s32 dmg;
    s32 physicalDmg;
    s32 specialDmg;
    u8 physicalBattlerId;
    u8 specialBattlerId;
    u8 changedStatsBattlerId; // Battler that was responsible for the latest stat change. Can be self.
};

struct SideTimer
{
    u8 reflectTimer;
    u8 reflectBattlerId;
    u8 lightscreenTimer;
    u8 lightscreenBattlerId;
    u8 mistTimer;
    u8 mistBattlerId;
    u8 safeguardTimer;
    u8 safeguardBattlerId;
    u8 followmeTimer;
    u8 followmeTarget:3;
    u8 followmePowder:1; // Rage powder, does not affect grass type pokemon.
    u8 spikesAmount;
    u8 toxicSpikesAmount;
    u8 stealthRockAmount;
    u8 stickyWebAmount;
    u8 auroraVeilTimer;
    u8 auroraVeilBattlerId;
    u8 tailwindTimer;
    u8 tailwindBattlerId;
    u8 luckyChantTimer;
    u8 luckyChantBattlerId;
    u8 retaliateTimer;
};

struct FieldTimer
{
    u8 mudSportTimer;
    u8 waterSportTimer;
    u8 wonderRoomTimer;
    u8 magicRoomTimer;
    u8 trickRoomTimer;
    u8 terrainTimer;
    u8 gravityTimer;
    u8 fairyLockTimer;
};

struct WishFutureKnock
{
    u8 futureSightCounter[MAX_BATTLERS_COUNT];
    u8 futureSightAttacker[MAX_BATTLERS_COUNT];
    u16 futureSightMove[MAX_BATTLERS_COUNT];
    u8 wishCounter[MAX_BATTLERS_COUNT];
    u8 wishPartyId[MAX_BATTLERS_COUNT];
    u8 weatherDuration;
    u8 knockedOffMons[2]; // Each battler is represented by a bit. The array entry is dependent on the battler's side.
};

struct AI_SavedBattleMon
{
    u16 ability;
    u16 moves[MAX_MON_MOVES];
    u16 heldItem;
    u16 species;
};

struct AiLogicData
{
    //attacker data
    u16 atkAbility;
    u16 atkItem;
    u16 atkHoldEffect;
    u8 atkParam;
    u16 atkSpecies;
    // target data
    u16 defAbility;
    u16 defItem;
    u16 defHoldEffect;
    u8 defParam;
    u16 defSpecies;
    // attacker partner data
    u8 battlerAtkPartner;
    u16 partnerMove;
    u16 atkPartnerAbility;
    u16 atkPartnerHoldEffect;
    bool32 targetSameSide;
    // target partner data
    u8 battlerDefPartner;
    u16 defPartnerAbility;
    u16 defPartnerHoldEffect;
};

struct AI_ThinkingStruct
{
    struct AiLogicData data;
    u8 aiState;
    u8 movesetIndex;
    u16 moveConsidered;
    s8 score[MAX_MON_MOVES];
    u32 funcResult;
    u32 aiFlags;
    u8 aiAction;
    u8 aiLogicId;
    s32 simulatedDmg[MAX_BATTLERS_COUNT][MAX_BATTLERS_COUNT][MAX_MON_MOVES]; // attacker, target, move
    struct AI_SavedBattleMon saved[4];
    bool8 switchMon; // Because all available moves have no/little effect.
};

#define AI_MOVE_HISTORY_COUNT 3

struct BattleHistory
{
    u16 abilities[MAX_BATTLERS_COUNT];
    u8 itemEffects[MAX_BATTLERS_COUNT];
    u16 usedMoves[MAX_BATTLERS_COUNT][MAX_MON_MOVES];
    u16 moveHistory[MAX_BATTLERS_COUNT][AI_MOVE_HISTORY_COUNT]; // 3 last used moves for each battler
    u8 moveHistoryIndex[MAX_BATTLERS_COUNT];
    u16 trainerItems[MAX_BATTLERS_COUNT];
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
    u16 stats[NUM_STATS];
};

struct BattleResources
{
    struct SecretBase* secretBase;
    struct ResourceFlags *flags;
    struct BattleScriptsStack* battleScriptsStack;
    struct BattleCallbacksStack* battleCallbackStack;
    struct StatsArray* beforeLvlUp;
    struct AI_ThinkingStruct *ai;
    struct BattleHistory *battleHistory;
    u8 bufferA[MAX_BATTLERS_COUNT][0x200];
    u8 bufferB[MAX_BATTLERS_COUNT][0x200];
};

#define AI_THINKING_STRUCT ((struct AI_ThinkingStruct *)(gBattleResources->ai))
#define AI_DATA ((struct AiLogicData *)(&gBattleResources->ai->data))
#define BATTLE_HISTORY ((struct BattleHistory *)(gBattleResources->battleHistory))

struct BattleResults
{
    u8 playerFaintCounter;    // 0x0
    u8 opponentFaintCounter;  // 0x1
    u8 playerSwitchesCounter; // 0x2
    u8 numHealingItemsUsed;   // 0x3
    u8 numRevivesUsed;        // 0x4
    u8 playerMonWasDamaged:1; // 0x5
    u8 caughtMonBall:4;       // 0x5
    u8 shinyWildMon:1;        // 0x5
    u16 playerMon1Species;    // 0x6
    u8 playerMon1Name[POKEMON_NAME_LENGTH + 1];    // 0x8
    u8 battleTurnCounter;     // 0x13
    u8 playerMon2Name[POKEMON_NAME_LENGTH + 1];    // 0x14
    u8 pokeblockThrows;       // 0x1F
    u16 lastOpponentSpecies;  // 0x20
    u16 lastUsedMovePlayer;   // 0x22
    u16 lastUsedMoveOpponent; // 0x24
    u16 playerMon2Species;    // 0x26
    u16 caughtMonSpecies;     // 0x28
    u8 caughtMonNick[POKEMON_NAME_LENGTH + 1];     // 0x2A
    u8 filler35;           // 0x35
    u8 catchAttempts[POKEBALL_COUNT];     // 0x36
};

struct BattleTv_Side
{
    u32 spikesMonId:3;
    u32 reflectMonId:3;
    u32 lightScreenMonId:3;
    u32 safeguardMonId:3;
    u32 mistMonId:3;
    u32 futureSightMonId:3;
    u32 doomDesireMonId:3;
    u32 perishSongMonId:3;
    u32 wishMonId:3;
    u32 grudgeMonId:3;
    u32 usedMoveSlot:2;
    u32 spikesMoveSlot:2;
    u32 reflectMoveSlot:2;
    u32 lightScreenMoveSlot:2;
    u32 safeguardMoveSlot:2;
    u32 mistMoveSlot:2;
    u32 futureSightMoveSlot:2;
    u32 doomDesireMoveSlot:2;
    u32 perishSongMoveSlot:2;
    u32 wishMoveSlot:2;
    u32 grudgeMoveSlot:2;
    u32 destinyBondMonId:3;
    u32 destinyBondMoveSlot:2;
    u32 faintCause:4;
    u32 faintCauseMonId:3;
    u32 explosion:1;
    u32 explosionMoveSlot:2;
    u32 explosionMonId:3;
    u32 perishSong:1;
};

struct BattleTv_Position
{
    u32 curseMonId:3;
    u32 leechSeedMonId:3;
    u32 nightmareMonId:3;
    u32 wrapMonId:3;
    u32 attractMonId:3;
    u32 confusionMonId:3;
    u32 curseMoveSlot:2;
    u32 leechSeedMoveSlot:2;
    u32 nightmareMoveSlot:2;
    u32 wrapMoveSlot:2;
    u32 attractMoveSlot:2;
    u32 confusionMoveSlot:2;
    u32 waterSportMoveSlot:2;
    u32 waterSportMonId:3;
    u32 mudSportMonId:3;
    u32 mudSportMoveSlot:2;
    u32 ingrainMonId:3;
    u32 ingrainMoveSlot:2;
    u32 attackedByMonId:3;
    u32 attackedByMoveSlot:2;
};

struct BattleTv_Mon
{
    u32 psnMonId:3;
    u32 badPsnMonId:3;
    u32 brnMonId:3;
    u32 prlzMonId:3;
    u32 slpMonId:3;
    u32 frzMonId:3;
    u32 psnMoveSlot:2;
    u32 badPsnMoveSlot:2;
    u32 brnMoveSlot:2;
    u32 prlzMoveSlot:2;
    u32 slpMoveSlot:2;
    u32 frzMoveSlot:2;
};

struct BattleTv
{
    struct BattleTv_Mon mon[2][PARTY_SIZE]; // [side][partyId]
    struct BattleTv_Position pos[2][2]; // [side][flank]
    struct BattleTv_Side side[2]; // [side]
};

struct BattleTvMovePoints
{
    s16 points[2][PARTY_SIZE * 4];
};

struct LinkBattlerHeader
{
    u8 versionSignatureLo;
    u8 versionSignatureHi;
    u8 vsScreenHealthFlagsLo;
    u8 vsScreenHealthFlagsHi;
    struct BattleEnigmaBerry battleEnigmaBerry;
};

struct MegaEvolutionData
{
    u8 toEvolve; // As flags using gBitTable.
    u8 evolvedPartyIds[2]; // As flags using gBitTable;
    bool8 alreadyEvolved[4]; // Array id is used for mon position.
    u16 evolvedSpecies[MAX_BATTLERS_COUNT];
    u16 playerEvolvedSpecies;
    u8 primalRevertedPartyIds[2]; // As flags using gBitTable;
    u16 primalRevertedSpecies[MAX_BATTLERS_COUNT];
    u16 playerPrimalRevertedSpecies;
    u8 battlerId;
    bool8 playerSelect;
    u8 triggerSpriteId;
    bool8 isWishMegaEvo;
    bool8 isPrimalReversion;
};

struct Illusion
{
    u8 on;
    u8 set;
    u8 broken;
    u8 partyId;
    struct Pokemon *mon;
};

struct StolenItem
{
    u16 originalItem:15;
    u16 stolen:1;
};

struct BattleStruct
{
    u8 turnEffectsTracker;
    u8 turnEffectsBattlerId;
    u8 turnCountersTracker;
    u16 wrappedMove[MAX_BATTLERS_COUNT];
    u16 moveTarget[MAX_BATTLERS_COUNT];
    u8 expGetterMonId;
    u8 wildVictorySong;
    u8 dynamicMoveType;
    u8 wrappedBy[MAX_BATTLERS_COUNT];
    u16 assistPossibleMoves[PARTY_SIZE * MAX_MON_MOVES]; // Each of mons can know max 4 moves.
    u8 focusPunchBattlerId;
    u8 battlerPreventingSwitchout;
    u8 moneyMultiplier:6;
    u8 moneyMultiplierItem:1;
    u8 moneyMultiplierMove:1;
    u8 savedTurnActionNumber;
    u8 switchInAbilitiesCounter;
    u8 faintedActionsState;
    u8 faintedActionsBattlerId;
    u32 expValue;
    u8 field_52;
    u8 sentInPokes;
    bool8 selectionScriptFinished[MAX_BATTLERS_COUNT];
    u8 battlerPartyIndexes[MAX_BATTLERS_COUNT];
    u8 monToSwitchIntoId[MAX_BATTLERS_COUNT];
    u8 battlerPartyOrders[MAX_BATTLERS_COUNT][PARTY_SIZE / 2];
    u8 runTries;
    u8 caughtMonNick[POKEMON_NAME_LENGTH + 1];
    u8 safariGoNearCounter;
    u8 safariPkblThrowCounter;
    u8 safariEscapeFactor;
    u8 safariCatchFactor;
    u8 linkBattleVsSpriteId_V; // The letter "V"
    u8 linkBattleVsSpriteId_S; // The letter "S"
    u8 formToChangeInto;
    u8 chosenMovePositions[MAX_BATTLERS_COUNT];
    u8 stateIdAfterSelScript[MAX_BATTLERS_COUNT];
    u8 prevSelectedPartySlot;
    u8 stringMoveType;
    u8 expGetterBattlerId;
    u8 absentBattlerFlags;
    u8 palaceFlags; // First 4 bits are "is < 50% HP and not asleep" for each battler, last 4 bits are selected moves to pass to AI
    u8 field_93; // related to choosing pokemon?
    u8 wallyBattleState;
    u8 wallyMovesState;
    u8 wallyWaitFrames;
    u8 wallyMoveFrames;
    u16 lastTakenMove[MAX_BATTLERS_COUNT]; // Last move that a battler was hit with.
    u16 hpOnSwitchout[2];
    u32 savedBattleTypeFlags;
    u16 abilityPreventingSwitchout;
    u8 hpScale;
    u16 synchronizeMoveEffect;
    bool8 anyMonHasTransformed;
    void (*savedCallback)(void);
    u16 usedHeldItems[PARTY_SIZE][2];   // For each party member and side. For harvest, recycle
    u16 chosenItem[MAX_BATTLERS_COUNT];
    u8 AI_itemType[2];
    u8 AI_itemFlags[2];
    u16 choicedMove[MAX_BATTLERS_COUNT];
    u16 changedItems[MAX_BATTLERS_COUNT];
    u8 intimidateBattler;
    u8 switchInItemsCounter;
    u8 arenaTurnCounter;
    u8 turnSideTracker;
    u8 givenExpMons; // Bits for enemy party's pokemon that gave exp to player's party.
    u16 lastTakenMoveFrom[MAX_BATTLERS_COUNT][MAX_BATTLERS_COUNT]; // a 2-D array [target][attacker]
    u16 castformPalette[NUM_CASTFORM_FORMS][16];
    union {
        struct LinkBattlerHeader linkBattlerHeader;
        u32 battleVideo[2];
    } multiBuffer;
    u8 wishPerishSongState;
    u8 wishPerishSongBattlerId;
    bool8 overworldWeatherDone;
    bool8 terrainDone;
    u8 atkCancellerTracker;
    struct BattleTvMovePoints tvMovePoints;
    struct BattleTv tv;
    u8 AI_monToSwitchIntoId[MAX_BATTLERS_COUNT];
    s8 arenaMindPoints[2];
    s8 arenaSkillPoints[2];
    u16 arenaStartHp[2];
    u8 arenaLostPlayerMons; // Bits for party member, lost as in referee's decision, not by fainting.
    u8 arenaLostOpponentMons;
    u8 alreadyStatusedMoveAttempt; // As bits for battlers; For example when using Thunder Wave on an already paralyzed pokemon.
    u8 debugBattler;
    u8 magnitudeBasePower;
    u8 presentBasePower;
    u8 roostTypes[MAX_BATTLERS_COUNT][3];
    u8 savedBattlerTarget;
    bool8 ateBoost[MAX_BATTLERS_COUNT];
    u8 activeAbilityPopUps; // as bits for each battler
    u8 abilityPopUpSpriteIds[MAX_BATTLERS_COUNT][2];    // two per battler
    bool8 throwingPokeBall;
    struct MegaEvolutionData mega;
    const u8 *trainerSlideMsg;
    bool8 trainerSlideLowHpMsgDone;
    u8 introState;
    u8 ateBerry[2]; // array id determined by side, each party pokemon as bit
    u8 stolenStats[NUM_BATTLE_STATS]; // hp byte is used for which stats to raise, other inform about by how many stages
    u8 lastMoveFailed; // as bits for each battler, for the sake of Stomping Tantrum
    u8 lastMoveTarget[MAX_BATTLERS_COUNT]; // The last target on which each mon used a move, for the sake of Instruct
    u8 debugHoldEffects[MAX_BATTLERS_COUNT]; // These override actual items' hold effects.
    u16 tracedAbility[MAX_BATTLERS_COUNT];
    u16 hpBefore[MAX_BATTLERS_COUNT]; // Hp of battlers before using a move. For Berserk
    bool8 spriteIgnore0Hp;
    struct Illusion illusion[MAX_BATTLERS_COUNT];
    s8 aiFinalScore[MAX_BATTLERS_COUNT][MAX_BATTLERS_COUNT][MAX_MON_MOVES]; // AI, target, moves to make debugging easier
    s32 aiSimulatedDamage[MAX_BATTLERS_COUNT][MAX_BATTLERS_COUNT][MAX_MON_MOVES]; // attacker, target, move to make debugging easier
    u8 soulheartBattlerId;
    u8 friskedBattler; // Frisk needs to identify 2 battlers in double battles.
    bool8 friskedAbility; // If identifies two mons, show the ability pop-up only once.
    u8 sameMoveTurns[MAX_BATTLERS_COUNT]; // For Metronome, number of times the same moves has been SUCCESFULLY used.
    u16 moveEffect2; // For Knock Off
    u16 changedSpecies[PARTY_SIZE]; // For Zygarde or future forms when multiple mons can change into the same pokemon.
    u8 quickClawBattlerId;
    struct StolenItem itemStolen[PARTY_SIZE];  // Player's team that had items stolen (two bytes per party member)
    u8 blunderPolicy:1; // should blunder policy activate
    u8 ballSpriteIds[2];    // item gfx, window gfx
    u8 stickyWebUser;
};

#define F_DYNAMIC_TYPE_1 (1 << 6)
#define F_DYNAMIC_TYPE_2 (1 << 7)
#define DYNAMIC_TYPE_MASK (F_DYNAMIC_TYPE_1 - 1)

#define GET_MOVE_TYPE(move, typeArg)                                  \
{                                                                     \
    if (gBattleStruct->dynamicMoveType)                               \
        typeArg = gBattleStruct->dynamicMoveType & DYNAMIC_TYPE_MASK; \
    else                                                              \
        typeArg = gBattleMoves[move].type;                            \
}

#define IS_MOVE_PHYSICAL(move)(GetBattleMoveSplit(move) == SPLIT_PHYSICAL)
#define IS_MOVE_SPECIAL(move)(GetBattleMoveSplit(move) == SPLIT_SPECIAL)
#define IS_MOVE_STATUS(move)(gBattleMoves[move].split == SPLIT_STATUS)

#define BATTLER_MAX_HP(battlerId)(gBattleMons[battlerId].hp == gBattleMons[battlerId].maxHP)
#define TARGET_TURN_DAMAGED ((gSpecialStatuses[gBattlerTarget].physicalDmg != 0 || gSpecialStatuses[gBattlerTarget].specialDmg != 0))
#define BATTLER_DAMAGED(battlerId) ((gSpecialStatuses[battlerId].physicalDmg != 0 || gSpecialStatuses[battlerId].specialDmg != 0))

#define IS_BATTLER_OF_TYPE(battlerId, type)((gBattleMons[battlerId].type1 == type || gBattleMons[battlerId].type2 == type || gBattleMons[battlerId].type3 == type))
#define SET_BATTLER_TYPE(battlerId, type)           \
{                                                   \
    gBattleMons[battlerId].type1 = type;            \
    gBattleMons[battlerId].type2 = type;            \
    gBattleMons[battlerId].type3 = TYPE_MYSTERY;    \
}

#define IS_BATTLER_PROTECTED(battlerId)(gProtectStructs[battlerId].protected                                           \
                                        || gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_WIDE_GUARD           \
                                        || gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_QUICK_GUARD          \
                                        || gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_CRAFTY_SHIELD        \
                                        || gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_MAT_BLOCK            \
                                        || gProtectStructs[battlerId].spikyShielded                                    \
                                        || gProtectStructs[battlerId].kingsShielded                                    \
                                        || gProtectStructs[battlerId].banefulBunkered                                  \
                                        || gProtectStructs[battlerId].obstructed)                                      \

#define GET_STAT_BUFF_ID(n)((n & 7))              // first three bits 0x1, 0x2, 0x4
#define GET_STAT_BUFF_VALUE_WITH_SIGN(n)((n & 0xF8))
#define GET_STAT_BUFF_VALUE(n)(((n >> 3) & 0xF))      // 0x8, 0x10, 0x20, 0x40
#define STAT_BUFF_NEGATIVE 0x80                     // 0x80, the sign bit

#define SET_STAT_BUFF_VALUE(n)((((n) << 3) & 0xF8))

#define SET_STATCHANGER(statId, stage, goesDown)(gBattleScripting.statChanger = (statId) + ((stage) << 3) + (goesDown << 7))
#define SET_STATCHANGER2(dst, statId, stage, goesDown)(dst = (statId) + ((stage) << 3) + (goesDown << 7))

// NOTE: The members of this struct have hard-coded offsets 
//       in include/constants/battle_script_commands.h
struct BattleScripting
{
    s32 painSplitHp;
    s32 bideDmg;
    u8 multihitString[6];
    bool8 expOnCatch;
    u8 twoTurnsMoveStringId;
    u8 animArg1;
    u8 animArg2;
    u16 tripleKickPower;
    u8 moveendState;
    u8 savedStatChanger; // For further use, if attempting to change stat two times(ex. Moody)
    u8 shiftSwitched; // When the game tells you the next enemy's pokemon and you switch. Option for noobs but oh well.
    u8 battler;
    u8 animTurn;
    u8 animTargetsHit;
    u8 statChanger;
    bool8 statAnimPlayed;
    u8 getexpState;
    u8 battleStyle;
    u8 drawlvlupboxState;
    u8 learnMoveState;
    u8 savedBattler;
    u8 reshowMainState;
    u8 reshowHelperState;
    u8 levelUpHP;
    u8 windowsType; // B_WIN_TYPE_*
    u8 multiplayerId;
    u8 specialTrainerBattleType;
    bool8 monCaught;
    s32 savedDmg;
    u16 savedMoveEffect; // For moves hitting multiple targets.
    u16 moveEffect;
    u16 multihitMoveEffect;
    u8 illusionNickHack; // To properly display nick in STRINGID_ENEMYABOUTTOSWITCHPKMN.
    bool8 fixedPopup;   // Force ability popup to stick until manually called back
    u16 abilityPopupOverwrite;
    u8 switchCase;  // Special switching conditions, eg. red card
    u8 overrideBerryRequirements;
};

struct BattleSpriteInfo
{
    u16 invisible:1; // 0x1
    u16 lowHpSong:1; // 0x2
    u16 behindSubstitute:1; // 0x4
    u16 flag_x8:1; // 0x8
    u16 hpNumbersNoBars:1; // 0x10
    u16 transformSpecies;
};

struct BattleAnimationInfo
{
    u16 animArg; // to fill up later
    u8 field_2;
    u8 field_3;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u8 ballThrowCaseId:6;
    u8 isCriticalCapture:1;
    u8 criticalCaptureSuccess:1;
    u8 introAnimActive:1;
    u8 wildMonInvisible:1;
    u8 field_9_x1C:3;
    u8 field_9_x20:1;
    u8 field_9_x40:1;
    u8 field_9_x80:1;
    u8 numBallParticles;
    u8 field_B;
    s16 ballSubpx;
    u8 field_E;
    u8 field_F;
};

struct BattleHealthboxInfo
{
    u8 partyStatusSummaryShown:1;
    u8 healthboxIsBouncing:1;
    u8 battlerIsBouncing:1;
    u8 ballAnimActive:1; // 0x8
    u8 statusAnimActive:1; // x10
    u8 animFromTableActive:1; // x20
    u8 specialAnimActive:1; // x40
    u8 triedShinyMonAnim:1;
    u8 finishedShinyMonAnim:1;
    u8 field_1_x1E:4;
    u8 bgmRestored:1;
    u8 waitForCry:1;
    u8 healthboxSlideInStarted:1;
    u8 healthboxBounceSpriteId;
    u8 battlerBounceSpriteId;
    u8 animationState;
    u8 partyStatusDelayTimer;
    u8 matrixNum;
    u8 shadowSpriteId;
    u8 soundTimer;
    u8 introEndDelay;
    u8 field_A;
    u8 field_B;
};

struct BattleBarInfo
{
    u8 healthboxSpriteId;
    s32 maxValue;
    s32 oldValue;
    s32 receivedValue;
    s32 currValue;
};

struct BattleSpriteData
{
    struct BattleSpriteInfo *battlerData;
    struct BattleHealthboxInfo *healthBoxesData;
    struct BattleAnimationInfo *animationData;
    struct BattleBarInfo *battleBars;
};

#include "sprite.h"

struct MonSpritesGfx
{
    void* firstDecompressed; // ptr to the decompressed sprite of the first pokemon
    union {
    	void* ptr[MAX_BATTLERS_COUNT];
    	u8* byte[MAX_BATTLERS_COUNT];
    } sprites;
    struct SpriteTemplate templates[MAX_BATTLERS_COUNT];
    struct SpriteFrameImage frameImages[MAX_BATTLERS_COUNT][4];
    u8 unusedArr[0x80];
    u8 *barFontGfx;
    void *unusedPtr;
    u16 *buffer;
};

struct TotemBoost
{
    u8 stats;   // bitfield for each battle stat that is set if the stat changes
    s8 statChanges[NUM_BATTLE_STATS - 1];    // highest bit being set decreases the stat
}; /* size = 8 */

// All battle variables are declared in battle_main.c
extern u16 gBattle_BG0_X;
extern u16 gBattle_BG0_Y;
extern u16 gBattle_BG1_X;
extern u16 gBattle_BG1_Y;
extern u16 gBattle_BG2_X;
extern u16 gBattle_BG2_Y;
extern u16 gBattle_BG3_X;
extern u16 gBattle_BG3_Y;
extern u16 gBattle_WIN0H;
extern u16 gBattle_WIN0V;
extern u16 gBattle_WIN1H;
extern u16 gBattle_WIN1V;
extern u8 gDisplayedStringBattle[400];
extern u8 gBattleTextBuff1[TEXT_BUFF_ARRAY_COUNT];
extern u8 gBattleTextBuff2[TEXT_BUFF_ARRAY_COUNT];
extern u8 gBattleTextBuff3[TEXT_BUFF_ARRAY_COUNT];
extern u32 gBattleTypeFlags;
extern u8 gBattleTerrain;
extern u32 gUnusedFirstBattleVar1;
extern u8 *gBattleAnimBgTileBuffer;
extern u8 *gBattleAnimBgTilemapBuffer;
extern u8 gActiveBattler;
extern u32 gBattleControllerExecFlags;
extern u8 gBattlersCount;
extern u16 gBattlerPartyIndexes[MAX_BATTLERS_COUNT];
extern u8 gBattlerPositions[MAX_BATTLERS_COUNT];
extern u8 gActionsByTurnOrder[MAX_BATTLERS_COUNT];
extern u8 gBattlerByTurnOrder[MAX_BATTLERS_COUNT];
extern u8 gCurrentTurnActionNumber;
extern u8 gCurrentActionFuncId;
extern struct BattlePokemon gBattleMons[MAX_BATTLERS_COUNT];
extern u8 gBattlerSpriteIds[MAX_BATTLERS_COUNT];
extern u8 gCurrMovePos;
extern u8 gChosenMovePos;
extern u16 gCurrentMove;
extern u16 gChosenMove;
extern u16 gCalledMove;
extern s32 gBattleMoveDamage;
extern s32 gHpDealt;
extern s32 gTakenDmg[MAX_BATTLERS_COUNT];
extern u16 gLastUsedItem;
extern u16 gLastUsedAbility;
extern u8 gBattlerAttacker;
extern u8 gBattlerTarget;
extern u8 gBattlerFainted;
extern u8 gEffectBattler;
extern u8 gPotentialItemEffectBattler;
extern u8 gAbsentBattlerFlags;
extern u8 gIsCriticalHit;
extern u8 gMultiHitCounter;
extern const u8 *gBattlescriptCurrInstr;
extern u8 gChosenActionByBattler[MAX_BATTLERS_COUNT];
extern const u8 *gSelectionBattleScripts[MAX_BATTLERS_COUNT];
extern const u8 *gPalaceSelectionBattleScripts[MAX_BATTLERS_COUNT];
extern u16 gLastPrintedMoves[MAX_BATTLERS_COUNT];
extern u16 gLastMoves[MAX_BATTLERS_COUNT];
extern u16 gLastLandedMoves[MAX_BATTLERS_COUNT];
extern u16 gLastHitByType[MAX_BATTLERS_COUNT];
extern u16 gLastResultingMoves[MAX_BATTLERS_COUNT];
extern u16 gLockedMoves[MAX_BATTLERS_COUNT];
extern u16 gLastUsedMove;
extern u8 gLastHitBy[MAX_BATTLERS_COUNT];
extern u16 gChosenMoveByBattler[MAX_BATTLERS_COUNT];
extern u16 gMoveResultFlags;
extern u32 gHitMarker;
extern u8 gTakenDmgByBattler[MAX_BATTLERS_COUNT];
extern u8 gUnusedFirstBattleVar2;
extern u32 gSideStatuses[2];
extern struct SideTimer gSideTimers[2];
extern u32 gStatuses3[MAX_BATTLERS_COUNT];
extern u32 gStatuses4[MAX_BATTLERS_COUNT];
extern struct DisableStruct gDisableStructs[MAX_BATTLERS_COUNT];
extern u16 gPauseCounterBattle;
extern u16 gPaydayMoney;
extern u16 gRandomTurnNumber;
extern u8 gBattleCommunication[BATTLE_COMMUNICATION_ENTRIES_COUNT];
extern u8 gBattleOutcome;
extern struct ProtectStruct gProtectStructs[MAX_BATTLERS_COUNT];
extern struct SpecialStatus gSpecialStatuses[MAX_BATTLERS_COUNT];
extern u16 gBattleWeather;
extern struct WishFutureKnock gWishFutureKnock;
extern u16 gIntroSlideFlags;
extern u8 gSentPokesToOpponent[2];
extern u16 gExpShareExp;
extern struct BattleEnigmaBerry gEnigmaBerries[MAX_BATTLERS_COUNT];
extern struct BattleScripting gBattleScripting;
extern struct BattleStruct *gBattleStruct;
extern u8 *gLinkBattleSendBuffer;
extern u8 *gLinkBattleRecvBuffer;
extern struct BattleResources *gBattleResources;
extern u8 gActionSelectionCursor[MAX_BATTLERS_COUNT];
extern u8 gMoveSelectionCursor[MAX_BATTLERS_COUNT];
extern u8 gBattlerStatusSummaryTaskId[MAX_BATTLERS_COUNT];
extern u8 gBattlerInMenuId;
extern bool8 gDoingBattleAnim;
extern u32 gTransformedPersonalities[MAX_BATTLERS_COUNT];
extern u8 gPlayerDpadHoldFrames;
extern struct BattleSpriteData *gBattleSpritesDataPtr;
extern struct MonSpritesGfx *gMonSpritesGfxPtr;
extern struct BattleHealthboxInfo *gBattleControllerOpponentHealthboxData;
extern struct BattleHealthboxInfo *gBattleControllerOpponentFlankHealthboxData;
extern u16 gBattleMovePower;
extern u16 gMoveToLearn;
extern u8 gBattleMonForms[MAX_BATTLERS_COUNT];
extern u32 gFieldStatuses;
extern struct FieldTimer gFieldTimers;
extern u8 gBattlerAbility;
extern u16 gPartnerSpriteId;
extern struct TotemBoost gTotemBoosts[MAX_BATTLERS_COUNT];

extern void (*gPreBattleCallback1)(void);
extern void (*gBattleMainFunc)(void);
extern struct BattleResults gBattleResults;
extern u8 gLeveledUpInBattle;
extern void (*gBattlerControllerFuncs[MAX_BATTLERS_COUNT])(void);
extern u8 gHealthboxSpriteIds[MAX_BATTLERS_COUNT];
extern u8 gMultiUsePlayerCursor;
extern u8 gNumberOfMovesToChoose;
extern u8 gBattleControllerData[MAX_BATTLERS_COUNT];
extern bool8 gHasFetchedBall;
extern u8 gLastUsedBall;
extern u16 gLastThrownBall;
extern bool8 gSwapDamageCategory; // Photon Geyser, Shell Side Arm, Light That Burns the Sky

#endif // GUARD_BATTLE_H
