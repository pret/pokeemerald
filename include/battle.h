#ifndef GUARD_BATTLE_H
#define GUARD_BATTLE_H

// should they be included here or included individually by every file?
#include "constants/battle_end_turn.h"
#include "constants/battle_switch_in.h"
#include "constants/battle_stat_change.h"
#include "constants/abilities.h"
#include "constants/battle.h"
#include "constants/battle_move_resolution.h"
#include "constants/form_change_types.h"
#include "constants/hold_effects.h"
#include "constants/moves.h"
#include "battle_main.h"
#include "battle_message.h"
#include "battle_util.h"
#include "battle_script_commands.h"
#include "battle_gfx_sfx_util.h"
#include "battle_util2.h"
#include "battle_bg.h"
#include "pokeball.h"
#include "main.h"
#include "battle_debug.h"
#include "battle_dynamax.h"
#include "battle_terastal.h"
#include "battle_gimmick.h"
#include "config_changes.h"
#include "item.h"
#include "move.h"
#include "random.h" // for rng_value_t
#include "trainer_slide.h"

// Used to exclude moves learned temporarily by Transform or Mimic
#define MOVE_IS_PERMANENT(battler, moveSlot)                        \
   (!(gBattleMons[battler].volatiles.transformed)           \
 && !(gBattleMons[battler].volatiles.mimickedMoves & (1u << moveSlot)))

// Battle Actions
// These determine what each battler will do in a turn
enum BattleAction
{
    B_ACTION_USE_MOVE,
    B_ACTION_USE_ITEM,
    B_ACTION_SWITCH,
    B_ACTION_RUN,
    B_ACTION_SAFARI_WATCH_CAREFULLY,
    B_ACTION_SAFARI_BALL,
    B_ACTION_SAFARI_POKEBLOCK,
    B_ACTION_SAFARI_GO_NEAR,
    B_ACTION_SAFARI_RUN,
    B_ACTION_WALLY_THROW,
    B_ACTION_EXEC_SCRIPT,
    B_ACTION_TRY_FINISH,
    B_ACTION_FINISHED,
    B_ACTION_CANCEL_PARTNER = B_ACTION_FINISHED, // when choosing an action
    B_ACTION_NOTHING_FAINTED, // when choosing an action
    B_ACTION_UNK_14,
    B_ACTION_UNK_15,
    B_ACTION_DEBUG = 20,
    B_ACTION_THROW_BALL, // R to throw last used ball
    B_ACTION_NONE = 0xFF
};

#define BATTLE_BUFFER_LINK_SIZE 0x1000

// Fully Cleared each turn after end turn effects are done. A few things are cleared before end turn effects
struct ProtectStruct
{
    u32 protected:7; // 126 protect options
    u32 noValidMoves:1;
    u32 bounceMove:1;
    u32 stealMove:1;
    u32 chargingTurn:1;
    u32 fleeType:2; // 0: Normal, 1: FLEE_ITEM, 2: FLEE_ABILITY
    u32 laggingTail:1;
    u32 palaceUnableToUseMove:1;
    u32 statRaised:1;
    u32 usedCustapBerry:1;    // also quick claw
    u32 pranksterElevated:1;
    u32 quickDraw:1;
    u32 quash:1;
    u32 shellTrap:1;
    u32 eatMirrorHerb:1;
    u32 activateOpportunist:1;
    u32 usedAllySwitch:1;
    u32 lashOutAffected:1;
    u32 assuranceDoubled:1;
    u32 forcedSwitch:1;
    u32 myceliumMight:1;
    u32 survivedOHKO:1; // Used to keep track of effects that allow focus punch when surviving moves like Fissure
    u32 padding1:3;
    // End of 32-bit bitfield
    u16 helpingHand:3;
    u16 revengeDoubled:4;
    u16 padding2:9;
    // End of 16-bit bitfield
    u16 physicalDmg;
    u16 specialDmg;
    u8 physicalBattlerId:3;
    u8 specialBattlerId:3;
    u8 lastHitBySpecialMove:1;
    u8 padding3:1;
};

struct StatStages
{
    u8 stat:7;
    u8 done:1;
    s8 stage;
};

// Cleared at the start of HandleAction_ActionFinished
struct SpecialStatus
{
    u8 neutralizingGasRemoved:1;
    u8 berryReduced:1;
    u8 mindBlownRecoil:1;
    u8 updateStallMons:1;
    u8 poisonPuppeteer:1;
    u8 attackerInParty:1; // Fututre Sight / Doom Desire
    u8 abilityRedirected:1;
    u8 restoredBattlerSprite:1;
    // End of byte
    u8 faintedHasReplacement:1;
    u8 afterYou:1;
    u8 damagedByAttack:1;
    u8 dancerUsedMove:1;
    u8 criticalHit:1;
    u8 shellBellEmergencyExit:1;
    u8 breaksThroughProtectFully:1; // Unseen Fist, Piercing Drill
    u8 berryReducedMessagePrinted:1;
    // End of byte
    u8 gemParam:7;
    u8 gemBoost:1;
    // End of byte
    u8 parentalBondState:2;
    u8 multiHitOn:1;
    u8 teraShellAbilityDone:1;
    u8 backUpTarget:3;
    u8 padding1:1;
    // End of byte
    enum QueuedSwitch queuedSwitch;
    struct StatStages statStageQueue[NUM_BATTLE_STATS];
    struct StatStages statStageQueue2[NUM_BATTLE_STATS]; // For Mirror Armor, Defiant, Competitive and Rattled (avoids overwriting the first queue)
    u8 statStageAmount:4;
    u8 statStageAmount2:4;
    // End of byte
    uq4_12_t storedTypeEffectiveness;
};

struct SideTimer
{
    u16 reflectTimer;
    u16 lightscreenTimer;
    u16 mistTimer;
    u16 safeguardTimer;
    u8 spikesAmount:4;
    u8 toxicSpikesAmount:4;
    u8 stickyWebBattlerId;
    u8 stickyWebBattlerSide; // Used for Court Change
    u16 auroraVeilTimer;
    u16 tailwindTimer;
    u16 luckyChantTimer;
    // Timers below this point are not swapped by Court Change
    u8 followmeTimer:4;
    u8 followmeTarget:3;
    u8 followmePowder:1; // Rage powder, does not affect grass type Pokémon.
    u8 retaliateTimer;
    u16 damageNonTypesTimer;
    enum Type damageNonTypesType;
    u16 rainbowTimer;
    u16 seaOfFireTimer;
    u16 swampTimer;
};

struct FieldTimer
{
    u8 mudSportTimer;
    u8 waterSportTimer;
    u8 wonderRoomTimer;
    u8 magicRoomTimer;
    u8 trickRoomTimer;
    u8 terrain;
    u8 terrainTimer;
    u8 gravityTimer;
    u8 fairyLockTimer;
};

struct AI_SavedBattleMon
{
    enum Ability ability;
    enum Move moves[MAX_MON_MOVES];
    enum Item heldItem;
    enum Species species:15;
    u16 saved:1;
    enum Type types[3];
};

struct AiPartyMon
{
    enum Species species;
    enum Item item;
    enum HoldEffect heldEffect;
    enum Ability ability;
    u16 level;
    enum Move moves[MAX_MON_MOVES];
    u32 status;
    u8 switchInCount; // Counts how many times this Pokemon has been sent out or switched into in a battle.
    u8 gender:2;
    u8 isFainted:1;
    u8 wasSentInBattle:1;
    u8 padding:4;
};

struct AiPartyData // Opposing battlers - party mons.
{
    struct AiPartyMon mons[MAX_BATTLE_TRAINERS][PARTY_SIZE]; // 4 parties(player, partner, and two opponent). Used to save information on opposing party.
    u8 count[MAX_BATTLE_TRAINERS];
};

struct SimulatedDamage
{
    u16 minimum;
    u16 median;
    u16 maximum;
    u16 random;
};

// Ai Data used when deciding which move to use, computed only once before each turn's start.
struct AiLogicData
{
    enum Ability abilities[MAX_BATTLERS_COUNT];
    enum Item items[MAX_BATTLERS_COUNT];
    enum HoldEffect holdEffects[MAX_BATTLERS_COUNT];
    enum Move lastUsedMove[MAX_BATTLERS_COUNT];
    u8 hpPercents[MAX_BATTLERS_COUNT];
    enum Move partnerMove;
    u16 speedStats[MAX_BATTLERS_COUNT]; // Speed stats for all battles, calculated only once, same way as damages
    struct SimulatedDamage simulatedDmg[MAX_BATTLERS_COUNT][MAX_BATTLERS_COUNT][MAX_MON_MOVES]; // attacker, target, moveIndex
    uq4_12_t effectiveness[MAX_BATTLERS_COUNT][MAX_BATTLERS_COUNT][MAX_MON_MOVES]; // attacker, target, moveIndex
    u8 moveAccuracy[MAX_BATTLERS_COUNT][MAX_BATTLERS_COUNT][MAX_MON_MOVES]; // attacker, target, moveIndex
    u8 moveLimitations[MAX_BATTLERS_COUNT];
    u8 monToSwitchInId[MAX_BATTLERS_COUNT]; // ID of the mon to switch in.
    u8 mostSuitableMonId[MAX_BATTLERS_COUNT]; // Stores result of GetMostSuitableMonToSwitchInto, which decides which generic mon the AI would switch into if they decide to switch. This can be overruled by specific mons found in ShouldSwitch; the final resulting mon is stored in AI_monToSwitchIntoId.
    enum Move predictedMove[MAX_BATTLERS_COUNT];
    u8 resistBerryAffected[MAX_BATTLERS_COUNT][MAX_BATTLERS_COUNT][MAX_MON_MOVES]; // Tracks whether currently calc'd move is affected by a resist berry into given target

    // Flags
    u32 ejectButtonSwitch:1; // Tracks whether current switch out was from Eject Button
    u32 ejectPackSwitch:1; // Tracks whether current switch out was from Eject Pack
    u32 predictingSwitch:1; // Determines whether AI will use switch predictions this turn or not
    u32 aiPredictionInProgress:1; // Tracks whether the AI is in the middle of running prediction calculations
    u32 aiCalcInProgress:1;
    u32 predictingMove:1; // Determines whether AI will use move predictions this turn or not
    u32 shouldConsiderExplosion:1; // Determines whether AI should consider explosion moves this turn
    u32 shouldSwitch:4; // Stores result of ShouldSwitch, which decides whether a mon should be switched out
    u32 shouldConsiderFinalGambit:1; // Determines whether AI should consider Final Gambit this turn
    u32 switchInCalc:1; // Indicates if we're doing switch in calcs, this is purely for Retaliate damage calcs
    u32 partnerMoveSimulation:1;
    u32 reverseBattlerLogicOrder:1;
    u32 dragonDartsHitsBothTarget:4;
    u32 battlerMovesScored:4; // Bitmask of battlers that have completed move scoring this turn, so a battler can check whether its ally has already committed to a chosen move regardless of AI processing order
    u32 padding2:9;
};

struct AiThinkingStruct
{
    u8 aiState;
    u8 movesetIndex;
    enum Move moveConsidered;
    s32 score[MAX_MON_MOVES];
    u64 aiFlags[MAX_BATTLERS_COUNT];
    u8 aiAction;
    u8 aiLogicId;
    struct AI_SavedBattleMon saved[MAX_BATTLERS_COUNT];
};

#define AI_MOVE_HISTORY_COUNT 3

struct BattleHistory
{
    enum Ability abilities[MAX_BATTLERS_COUNT];
    u8 itemEffects[MAX_BATTLERS_COUNT];
    enum Move usedMoves[MAX_BATTLERS_COUNT][MAX_MON_MOVES];
    enum Move moveHistory[MAX_BATTLERS_COUNT][AI_MOVE_HISTORY_COUNT]; // 3 last used moves for each battler
    u8 moveHistoryIndex[MAX_BATTLERS_COUNT];
    enum Item trainerItems[MAX_BATTLERS_COUNT];
    u8 itemsNo;
    enum Item heldItems[MAX_BATTLERS_COUNT];
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
    u16 level:15;
    u16 learnMultipleMoves:1;
};

struct BattleResources
{
    struct SecretBase *secretBase;
    struct BattleScriptsStack *battleScriptsStack;
    struct BattleCallbacksStack *battleCallbackStack;
    struct StatsArray *beforeLvlUp;
    u8 bufferA[MAX_BATTLERS_COUNT][0x200];
    u8 bufferB[MAX_BATTLERS_COUNT][0x200];
    u8 transferBuffer[0x100];
};

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
    enum Species playerMon1Species;    // 0x6
    u8 playerMon1Name[POKEMON_NAME_LENGTH + 1];    // 0x8
    u8 battleTurnCounter;     // 0x13
    u8 playerMon2Name[POKEMON_NAME_LENGTH + 1];    // 0x14
    u8 pokeblockThrows;       // 0x1F
    enum Species lastOpponentSpecies;  // 0x20
    u16 lastUsedMovePlayer;   // 0x22
    u16 lastUsedMoveOpponent; // 0x24
    enum Species playerMon2Species;    // 0x26
    enum Species caughtMonSpecies;     // 0x28
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
    struct BattleTv_Mon mon[NUM_BATTLE_SIDES][PARTY_SIZE];
    struct BattleTv_Position pos[NUM_BATTLE_SIDES][2]; // [side][flank]
    struct BattleTv_Side side[NUM_BATTLE_SIDES];
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

enum IllusionState
{
    ILLUSION_NOT_SET,
    ILLUSION_OFF,
    ILLUSION_ON
};

struct Illusion
{
    enum IllusionState state;
    struct Pokemon *mon;
};

struct ZMoveData
{
    u8 viable:1;   // current move can become a z move
    u8 viewing:1;  // if player is viewing the z move name instead of regular moves
    u8 healReplacement:6;
    u8 possibleZMoves[MAX_BATTLERS_COUNT];
    u16 baseMoves[MAX_BATTLERS_COUNT];
};

struct DynamaxData
{
    u16 dynamaxTurns[MAX_BATTLERS_COUNT];
    u16 baseMoves[MAX_BATTLERS_COUNT]; // base move of Max Move
    u16 lastUsedBaseMove;
};

struct BattleGimmickData
{
    u8 usableGimmick[MAX_BATTLERS_COUNT];                // first usable gimmick that can be selected for each battler
    bool8 playerSelect;                                  // used to toggle trigger and update battle UI
    u8 triggerSpriteId;
    u8 indicatorSpriteId[MAX_BATTLERS_COUNT];
    u8 toActivate;                                       // stores whether a battler should transform at start of turn as bitfield
    u8 activeGimmick[MAX_BATTLE_TRAINERS][PARTY_SIZE];   // stores the active gimmick for each party member
    bool8 activated[MAX_BATTLERS_COUNT][GIMMICKS_COUNT]; // stores whether a trainer has used gimmick
};

struct LostItem
{
    enum Item originalItem:15;
    u16 stolen:1;
};

struct BattleVideo {
    u32 battleTypeFlags;
    rng_value_t rngSeed;
};

struct Wish
{
    u16 counter;
    u8 partyId;
};

struct FutureSight
{
    enum Move move;
    u16 counter:10;
    u16 battlerIndex:3;
    u16 partyIndex:3;
};

struct SleepClause
{
    enum BattleTrainer trainer:3;
    u8 partyIndex:3;
    u8 padding:2;
};

struct BattlerState
{
    u8 targetsDone[MAX_BATTLERS_COUNT];

    u32 commandingDondozo:1;
    u32 focusPunchBattlers:1;
    u32 multipleSwitchInBattlers:1;
    u32 alreadyStatusedMoveAttempt:1; // For example when using Thunder Wave on an already paralyzed Pokémon.
    u32 activeAbilityPopUps:1;
    u32 forcedSwitch:1;
    u32 storedHealingWish:1;
    u32 storedLunarDance:1;
    u32 usedEjectItem:1;
    u32 sleepClauseEffectExempt:1; // Stores whether effect should be exempt from triggering Sleep Clause (Effect Spore)
    u32 usedMicleBerry:1;
    u32 pursuitTarget:1;
    u32 stompingTantrumTimer:2;
    u32 canPickupItem:1;
    u32 ateBoost:1;
    u32 wasAboveHalfHp:1; // For Berserk, Emergency Exit, Wimp Out and Anger Shell.
    enum Species commanderSpecies:11;
    u32 selectionScriptFinished:1;
    u32 lastMoveTarget:3; // The last target on which each mon used a move, for the sake of Instruct
    // End of Word
    u16 hpOnSwitchout;
    u16 switchIn:1;
    u16 notOnField:1;
    u16 originalBattlerPartyId:4;
    u16 isFirstTurn:2; // Starts at 2 on switch in and counts down during end turn
    u16 padding:8;
    // End of Word
};

struct PartyState
{
    u32 intrepidSwordBoost:1;
    u32 dauntlessShieldBoost:1;
    u32 ateBerry:1;
    u32 battleBondBoost:1;
    u32 transformZeroToHero:1;
    u32 supersweetSyrup:1;
    u32 timesGotHit:8;
    enum Species changedSpecies:11; // For forms when multiple mons can change into the same Pokémon.
    u32 sentOut:1;
    u32 isKnockedOff:1;
    u32 freezeTurns:2;
    u32 padding:3;
    enum Item usedHeldItem;
};

struct EventStates
{
    enum EndTurnResolutionOrder endTurn:8;
    u32 endTurnBlock:8; // FirstEventBlock, SecondEventBlock, ThirdEventBlock
    enum BattlerId endTurnBattler:4;
    u32 arenaTurn:8;
    enum BattleSide battlerSide:4;
    enum BattlerId moveEndBattler:4;
    enum FirstTurnEventsStates beforeFirstTurn:8;
    enum FaintedActions faintedAction:8;
    enum BattlerId faintedActionBattler:4;
    enum CancelerState atkCanceler:8;
    enum BattlerId atkCancelerBattler:4;
    enum BattleIntroStates battleIntro:8;
    enum SwitchInEvents switchIn:8;
    u32 battlerSwitchIn:8; // SwitchInFirstEventBlock, SwitchInSecondEventBlock
    u32 moveEndBlock:8;
    enum StatChangeResolution resolution:8;
};

// Cleared at the beginning of the battle. Fields need to be cleared when needed manually otherwise.
struct BattleStruct
{
    struct BattlerState battlerState[MAX_BATTLERS_COUNT];
    struct PartyState partyState[MAX_BATTLE_TRAINERS][PARTY_SIZE];
    struct EventStates eventState;
    struct FutureSight futureSight[MAX_BATTLERS_COUNT];
    struct Wish wish[MAX_BATTLERS_COUNT];
    u16 moveTarget[MAX_BATTLERS_COUNT];
    u8 faintCounter[MAX_BATTLE_TRAINERS]; // Supreme Overload / Last Respects
    u32 expShareExpValue;
    u32 expValue;
    u8 weatherDuration;
    u8 expGettersOrder[PARTY_SIZE]; // First battlers which were sent out, then via exp-share
    u8 expGetterMonId;
    u8 expOrderId:3;
    u8 teamGotExpMsgPrinted:1; // The 'Rest of your team got msg' has been printed.
    u8 padding0:4;
    u8 givenExpMons[2]; // Bits for enemy party's Pokémon that gave exp to player's party.
    u8 expSentInMons; // As bits for player party mons - not including exp share mons.
    u8 wildVictorySong;
    enum Type dynamicMoveType;
    enum BattlerId battlerPreventingSwitchout;
    u8 moneyMultiplier:6;
    u8 moneyMultiplierItem:1;
    u8 moneyMultiplierMove:1;
    u8 savedTurnActionNumber;
    u8 scriptPartyIdx; // for printing the nickname
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
    u8 chosenMovePositions[MAX_BATTLERS_COUNT];
    u8 stateIdAfterSelScript[MAX_BATTLERS_COUNT];
    u8 prevSelectedPartySlot;
    u8 stringMoveType;
    u8 palaceFlags; // First 4 bits are "is <= 50% HP and not asleep" for each battler, last 4 bits are selected moves to pass to AI
    u8 recordedActionSet; // related to choosing Pokémon?
    u8 wallyBattleState;
    u8 wallyMovesState;
    u8 wallyWaitFrames;
    u8 wallyMoveFrames;
    u16 lastTakenMove[MAX_BATTLERS_COUNT]; // Last move that a battler was hit with.
    u32 savedBattleTypeFlags;
    enum Ability abilityPreventingSwitchout;
    u8 hpScale;
    u8 anyMonHasTransformed:1; // Only used in battle_tv.c
    u8 sleepClauseNotBlocked:1;
    u8 isSkyBattle:1;
    u8 unableToUseMove:1; // for the current action only, to check if the battler failed to act at end turn use the DisableStruct member
    u8 triAttackBurn:1;
    enum SynchronizeState synchronizeState:3;
    void (*savedCallback)(void);
    enum Item chosenItem[MAX_BATTLERS_COUNT];
    enum Move choicedMove[MAX_BATTLERS_COUNT];
    u8 switchInBattlerCounter;
    u16 lastTakenMoveFrom[MAX_BATTLERS_COUNT][MAX_BATTLERS_COUNT]; // a 2-D array [target][attacker]
    union {
        struct LinkBattlerHeader linkBattlerHeader;
        struct BattleVideo battleVideo;
    } multiBuffer;
    u8 battlerKOAnimsRunning:3;
    u8 fickleBeamBoosted:1;
    u8 unused2:1;
    u8 toxicChainPriority:1; // If Toxic Chain will trigger on target, all other non volatiles will be blocked
    u8 battlersSorted:1; // To avoid unnessasery computation
    u8 unused1:1;
    struct BattleTvMovePoints tvMovePoints;
    struct BattleTv tv;
    u8 AI_monToSwitchIntoId[MAX_BATTLERS_COUNT];
    s8 arenaMindPoints[NUM_BATTLE_SIDES];
    s8 arenaSkillPoints[NUM_BATTLE_SIDES];
    u16 arenaStartHp[NUM_BATTLE_SIDES];
    u8 arenaLostPlayerMons; // Bits for party member, lost as in referee's decision, not by fainting.
    u8 arenaLostOpponentMons;
    u8 debugBattler;
    u8 magnitudeBasePower;
    u8 presentBasePower;
    u8 savedBattlerTarget[5];
    u8 savedBattlerAttacker[5];
    u8 savedTargetCount:4;
    u8 savedAttackerCount:4;
    u8 abilityPopUpSpriteIds[MAX_BATTLERS_COUNT][NUM_BATTLE_SIDES];    // two per battler
    enum Move baseMove; // z-move / dynamax base move
    struct ZMoveData zmove;
    struct DynamaxData dynamax;
    struct BattleGimmickData gimmick;
    const u8 *trainerSlideMsg;
    enum Ability tracedAbility[MAX_BATTLERS_COUNT];
    struct Illusion illusion[MAX_BATTLERS_COUNT];
    enum BattlerId soulheartBattlerId;
    struct LostItem itemLost[MAX_BATTLE_TRAINERS][PARTY_SIZE];  // Pokemon that had items consumed or stolen (two bytes per party member per side)
    u8 blunderPolicy:1; // should blunder policy activate
    u8 redCardActivated :1;
    u8 snatchedMoveIsUsed:1;
    u8 descriptionSubmenu:1; // For Move Description window in move selection screen
    u8 ackBallUseBtn:1; // Used for the last used ball feature
    u8 ballSwapped:1; // Used for the last used ball feature
    u8 effectsBeforeUsingMoveDone:1; // Mega Evo and Focus Punch/Shell Trap effects.
    u8 throwingPokeBall:1;
    u8 ballSpriteIds[2];    // item gfx, window gfx
    u8 moveInfoSpriteId; // move info, window gfx
    // When using a move which hits multiple opponents which is then bounced by a target, we need to make sure, the move hits both opponents, the one with bounce, and the one without.
    enum Species beatUpSpecies[PARTY_SIZE]; // Species for Gen5+ Beat Up, otherwise party indexes
    u8 beatUpSlot:3;
    enum PledgeCombo pledgeState:2;
    enum DamageCategory dynamicMoveCategory:3;
    enum Item flingItem:14;
    enum FlungItem flungItem:2;
    u8 itemPartyIndex[MAX_BATTLERS_COUNT];
    u8 itemMoveIndex[MAX_BATTLERS_COUNT];
    s32 aiDelayTimer; // Counts number of frames AI takes to choose an action.
    s32 aiDelayFrames; // Number of frames it took to choose an action.
    s32 aiDelayCycles; // Number of cycles it took to choose an action.
    u8 shellSideArmCategory[MAX_BATTLERS_COUNT][MAX_BATTLERS_COUNT];
    u8 speedTieBreaks; // MAX_BATTLERS_COUNT! values.
    u32 stellarBoostFlags[MAX_BATTLE_TRAINERS]; // bitfield
    struct SleepClause monCausingSleepClause[NUM_BATTLE_SIDES]; // Stores which Pokémon on a given side is causing Sleep Clause to be active as the mon's index in the party
    u8 additionalEffectsCounter:4; // A counter for the additionalEffects applied by the current move in Cmd_setadditionaleffects
    u8 pursuitStoredSwitch:4; // Stored id for the Pursuit target's switch (value between 0 and PARTY_SIZE included)
    s32 battlerExpReward;
    enum Species prevTurnSpecies[MAX_BATTLERS_COUNT]; // Stores species the AI has in play at start of turn
    s16 passiveHpUpdate[MAX_BATTLERS_COUNT]; // non-move damage and healing
    s16 moveDamage[MAX_BATTLERS_COUNT];
    u16 innardsOutHpLost[MAX_BATTLERS_COUNT];
    u32 moveResultFlags[MAX_BATTLERS_COUNT];
    u32 savedMoveResultFlags[MAX_BATTLERS_COUNT]; // for Bounced moves
    u8 numSpreadTargets:3;
    u8 moldBreakerActive:1;
    u8 unused4:4;
    struct MessageStatus slideMessageStatus;
    u8 trainerSlideSpriteIds[MAX_BATTLERS_COUNT];
    u8 hazardsQueue[NUM_BATTLE_SIDES][HAZARDS_MAX_COUNT];
    u8 numHazards[NUM_BATTLE_SIDES];
    u8 hazardsCounter:4; // Counter for applying hazard on switch in
    enum SubmoveState submoveAnnouncement:2;
    enum VictoryCatch victoryCatchState:2;
    u32 incrementEchoedVoice:1;
    u32 echoedVoiceCounter:3;
    u32 attackAnimPlayed:1;
    u32 magicCoatPending:6;
    u32 magicBouncePending:6;
    u32 bouncedMoveIsUsed:1;
    u32 dancerSavedAttacker:3;
    u32 dancerSavedTarget:3;
    u32 statChangeBattler:3;
    u32 overworldWeatherPresent:1;
    u32 padding5:4;
    u8 statChangeMoveAnim:1;
    u8 tidyUpActivates:1;
    u8 positiveAnimPlayed:1;
    u8 negativeAnimPlayed:1;
    u8 ignoreDefiant:1;
    u8 intimidateActivated:1;
    u8 allowPartingShot:1;
    u8 adrenalineOrbActivated:1; // prevents looping after an adrenaline stat changed
};

struct AiBattleData
{
    s32 finalScore[MAX_BATTLERS_COUNT][MAX_BATTLERS_COUNT][MAX_MON_MOVES]; // AI, target, moves to make debugging easier
    u8 playerStallMons[PARTY_SIZE];
    u8 chosenMoveIndex[MAX_BATTLERS_COUNT];
    u8 chosenTarget[MAX_BATTLERS_COUNT];
    u16 aiUsingGimmick:6;
    u8 actionFlee:1;
    u8 choiceWatch:1;
    u8 padding:6;
};

struct TerrainInfo
{
    const u8 *secretPowerAnimation;
    u16 secretPowerEffect:10;
    enum Type type:6;
    enum Move naturePowerMove;
    u8 battleBackground;
    enum Stat seedStat:4;
    u8 seedHoldEffect:4;
    u8 startMessage:4;
    u8 endMessage:4;
};

extern const struct TerrainInfo gBattleTerrainInfo[B_TERRAIN_COUNT];

struct BattleWeatherInfo
{
    u16 flag;
    u8 rock;
    u8 padding;

    u32 abilityStartMessage:5;
    u32 moveStartMessage:5;
    u32 endMessage:5;
    u32 continuesMessage:5;
    u32 animation:8;
    u32 type:4; // used when weather is similar (e.g. Desolate Land and Drought)
};

extern const struct BattleWeatherInfo gBattleWeatherInfo[BATTLE_WEATHER_COUNT];

// The palaceFlags member of struct BattleStruct contains 1 flag per move to indicate which moves the AI should consider,
// and 1 flag per battler to indicate whether the battler is awake and at <= 50% HP (which affects move choice).
// The assert below is to ensure palaceFlags is large enough to store these flags without overlap.
STATIC_ASSERT(sizeof(((struct BattleStruct *)0)->palaceFlags) * 8 >= MAX_BATTLERS_COUNT + MAX_MON_MOVES, PalaceFlagsTooSmall)

static inline bool32 IsBattleMovePhysical(enum Move move)
{
    return GetBattleMoveCategory(move) == DAMAGE_CATEGORY_PHYSICAL;
}

static inline bool32 IsBattleMoveSpecial(enum Move move)
{
    return GetBattleMoveCategory(move) == DAMAGE_CATEGORY_SPECIAL;
}

static inline bool32 IsBattleMoveStatus(enum Move move)
{
    return GetBattleMoveCategory(move) == DAMAGE_CATEGORY_STATUS;
}

/* Checks if 'battler' is any of the types.
 * Passing multiple types is more efficient than calling this multiple
 * times with one type because it shares the 'GetBattlerTypes' result. */
#define _IS_BATTLER_ANY_TYPE(battler, ignoreTera, ...)                           \
    ({                                                                           \
        enum Type types[3];                                                      \
        GetBattlerTypes(battler, ignoreTera, types);                             \
        RECURSIVELY(R_FOR_EACH(_IS_BATTLER_ANY_TYPE_HELPER, __VA_ARGS__)) FALSE; \
    })

#define _IS_BATTLER_ANY_TYPE_HELPER(type) (types[0] == type) || (types[1] == type) || (types[2] == type) ||

#define IS_BATTLER_ANY_TYPE(battler, ...) _IS_BATTLER_ANY_TYPE(battler, FALSE, __VA_ARGS__)
#define IS_BATTLER_OF_TYPE IS_BATTLER_ANY_TYPE
#define IS_BATTLER_ANY_BASE_TYPE(battler, ...) _IS_BATTLER_ANY_TYPE(battler, TRUE, __VA_ARGS__)
#define IS_BATTLER_OF_BASE_TYPE IS_BATTLER_ANY_BASE_TYPE

#define IS_BATTLER_TYPELESS(battlerId)                                                    \
    ({                                                                                    \
        enum Type types[3];                                                               \
        GetBattlerTypes(battlerId, FALSE, types);                                         \
        types[0] == TYPE_MYSTERY && types[1] == TYPE_MYSTERY && types[2] == TYPE_MYSTERY; \
    })

#define SET_BATTLER_TYPE(battler, type)              \
{                                                    \
    gBattleMons[battler].types[0] = type;            \
    gBattleMons[battler].types[1] = type;            \
    gBattleMons[battler].types[2] = TYPE_MYSTERY;    \
}

#define RESTORE_BATTLER_TYPE(battler)                                                \
{                                                                                    \
    gBattleMons[battler].types[0] = GetSpeciesType(gBattleMons[battler].species, 0); \
    gBattleMons[battler].types[1] = GetSpeciesType(gBattleMons[battler].species, 1); \
    gBattleMons[battler].types[2] = TYPE_MYSTERY;                                    \
}

// NOTE: The members of this struct have hard-coded offsets
//       in include/constants/battle_script_commands.h
struct BattleScripting
{
    s32 unused_0x00;
    s32 unused_0x04;
    u8 multihitString[6];
    bool8 expOnCatch;
    u8 unused2;
    u8 animArg1;
    u8 animArg2;
    u16 savedStringId;
    u8 moveendState;
    u8 unused_0x15;
    u8 shiftSwitched; // When the game tells you the next enemy's pokemon and you switch.
    enum BattlerId battler;
    u8 animTurn;
    u8 animTargetsHit;
    u8 unused_0x1a;
    u8 unused_0x1b;
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
    u16 unused_0x2c;
    u16 moveEffect;
    u16 unused_0x30;
    u8 illusionNickHack; // To properly display nick in STRINGID_ENEMYABOUTTOSWITCHPKMN.
    bool8 fixedPopup;   // Force ability popup to stick until manually called back
    enum Ability abilityPopupOverwrite;
    u8 switchCase;  // Special switching conditions, eg. red card
    u8 overrideBerryRequirements;
    u8 stickyWebStatDrop; // To prevent Defiant activating on a Court Change'd Sticky Web
};

struct BattleSpriteInfo
{
    u16 invisible:1; // 0x1
    u16 lowHpSong:1; // 0x2
    u16 behindSubstitute:1; // 0x4
    u16 flag_x8:1; // 0x8
    u16 hpNumbersNoBars:1; // 0x10
    enum Species transformSpecies;
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
    u8 opponentDrawPartyStatusSummaryDelay:4;
    u8 bgmRestored:1;
    u8 waitForCry:1;
    u8 healthboxSlideInStarted:1;
    u8 healthboxBounceSpriteId;
    u8 battlerBounceSpriteId;
    u8 animationState;
    u8 partyStatusDelayTimer;
    u8 matrixNum;

    u8 shadowSpriteIdPrimary;
    u8 shadowSpriteIdSecondary;

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
    void *firstDecompressed; // ptr to the decompressed sprite of the first Pokémon
    u8 *spritesGfx[MAX_BATTLERS_COUNT];
    struct SpriteTemplate templates[MAX_BATTLERS_COUNT];
    struct SpriteFrameImage frameImages[MAX_BATTLERS_COUNT][MAX_MON_PIC_FRAMES];
    u8 *barFontGfx;
    u16 *buffer;
};

struct QueuedStatBoost
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
extern u8 gDisplayedStringBattle[425];
extern u8 gBattleTextBuff1[TEXT_BUFF_ARRAY_COUNT];
extern u8 gBattleTextBuff2[TEXT_BUFF_ARRAY_COUNT];
extern u8 gBattleTextBuff3[TEXT_BUFF_ARRAY_COUNT + 13]; //to handle stupidly large z move names
extern u32 gBattleTypeFlags;
extern u8 gBattleEnvironment;
extern u8 *gBattleAnimBgTileBuffer;
extern u8 *gBattleAnimBgTilemapBuffer;
extern u32 gBattleControllerExecFlags;
extern u8 gBattlersCount;
extern u16 gBattlerPartyIndexes[MAX_BATTLERS_COUNT];
extern u8 gBattlerPositions[MAX_BATTLERS_COUNT];
extern u8 gActionsByTurnOrder[MAX_BATTLERS_COUNT];
extern enum BattlerId gBattlerByTurnOrder[MAX_BATTLERS_COUNT];
extern enum BattlerId gBattlersBySpeed[MAX_BATTLERS_COUNT];
extern enum BattlerId gBattlersByRawSpeed[MAX_BATTLERS_COUNT];
extern u8 gCurrentTurnActionNumber;
extern u8 gCurrentActionFuncId;
extern struct BattlePokemon gBattleMons[MAX_BATTLERS_COUNT];
extern u8 gBattlerSpriteIds[MAX_BATTLERS_COUNT];
extern u8 gCurrMovePos;
extern u8 gChosenMovePos;
extern u16 gCurrentMove;
extern u16 gChosenMove;
extern u16 gCalledMove;
extern s32 gBideDmg[MAX_BATTLERS_COUNT];
extern enum Item gLastUsedItem;
extern enum Ability gLastUsedAbility;
extern enum BattlerId gBattlerAttacker;
extern enum BattlerId gBattlerTarget;
extern enum BattlerId gBattlerFainted;
extern enum BattlerId gEffectBattler;
extern enum BattlerId gPotentialItemEffectBattler;
extern u8 gAbsentBattlerFlags;
extern u8 gMultiHitCounter;
extern const u8 *gBattlescriptCurrInstr;
extern u8 gChosenActionByBattler[MAX_BATTLERS_COUNT];
extern const u8 *gSelectionBattleScripts[MAX_BATTLERS_COUNT];
extern const u8 *gPalaceSelectionBattleScripts[MAX_BATTLERS_COUNT];
extern u16 gLastPrintedMoves[MAX_BATTLERS_COUNT];
extern u16 gLastMoves[MAX_BATTLERS_COUNT];
extern u16 gLastLandedMoves[MAX_BATTLERS_COUNT];
extern u16 gLastHitByType[MAX_BATTLERS_COUNT];
extern u16 gLastUsedMoveType[MAX_BATTLERS_COUNT];
extern u16 gLastResultingMoves[MAX_BATTLERS_COUNT];
extern u16 gLockedMoves[MAX_BATTLERS_COUNT];
extern u16 gLastUsedMove;
extern u8 gLastHitBy[MAX_BATTLERS_COUNT];
extern u16 gChosenMoveByBattler[MAX_BATTLERS_COUNT];
extern u32 gHitMarker;
extern u8 gBideTarget[MAX_BATTLERS_COUNT];
extern u32 gSideStatuses[NUM_BATTLE_SIDES];
extern struct SideTimer gSideTimers[NUM_BATTLE_SIDES];
extern u16 gPauseCounterBattle;
extern u16 gPaydayMoney;
extern u8 gBattleCommunication[BATTLE_COMMUNICATION_ENTRIES_COUNT];
extern u8 gBattleOutcome;
extern struct ProtectStruct gProtectStructs[MAX_BATTLERS_COUNT];
extern struct SpecialStatus gSpecialStatuses[MAX_BATTLERS_COUNT];
extern u16 gBattleWeather;
extern u16 gIntroSlideFlags;
extern u8 gSentPokesToOpponent[2];
extern struct BattleEnigmaBerry gEnigmaBerries[MAX_BATTLERS_COUNT];
extern struct BattleScripting gBattleScripting;
extern struct BattleStruct *gBattleStruct;
extern struct StartingStatuses gStartingStatuses;
extern struct AiBattleData *gAiBattleData;
extern struct AiThinkingStruct *gAiThinkingStruct;
extern struct AiLogicData *gAiLogicData;
extern struct AiPartyData *gAiPartyData;
extern struct BattleHistory *gBattleHistory;
extern u8 *gLinkBattleSendBuffer;
extern u8 *gLinkBattleRecvBuffer;
extern struct BattleResources *gBattleResources;
extern u8 gActionSelectionCursor[MAX_BATTLERS_COUNT];
extern u8 gMoveSelectionCursor[MAX_BATTLERS_COUNT];
extern u8 gBattlerStatusSummaryTaskId[MAX_BATTLERS_COUNT];
extern u8 gBattlerInMenuId;
extern bool8 gDoingBattleAnim;
extern u32 gTransformedPersonalities[MAX_BATTLERS_COUNT];
extern bool8 gTransformedShininess[MAX_BATTLERS_COUNT];
extern u8 gPlayerDpadHoldFrames;
extern struct BattleSpriteData *gBattleSpritesDataPtr;
extern struct MonSpritesGfx *gMonSpritesGfxPtr;
extern u16 gBattleMovePower;
extern u16 gMoveToLearn;
extern u32 gFieldStatuses;
extern struct FieldTimer gFieldTimers;
extern u16 gBattleTurnCounter;
extern enum BattlerId gBattlerAbility;
extern struct QueuedStatBoost gQueuedStatBoosts[MAX_BATTLERS_COUNT];

extern MainCallback gPreBattleCallback1;
extern void (*gBattleMainFunc)(void);
extern struct BattleResults gBattleResults;
extern u8 gLeveledUpInBattle;
extern u8 gHealthboxSpriteIds[MAX_BATTLERS_COUNT];
extern u8 gMultiUsePlayerCursor;
extern u8 gNumberOfMovesToChoose;
extern bool8 gHasFetchedBall;
extern u16 gLastUsedBall;
extern u16 gLastThrownBall;
extern u16 gBallToDisplay;
extern bool8 gLastUsedBallMenuPresent;
extern u8 gPartyCriticalHits[PARTY_SIZE];
extern u8 gCategoryIconSpriteId;
struct Pokemon *GetBattlerParty(enum BattlerId battler);
struct Pokemon *GetTrainerParty(enum BattleTrainer trainer);
struct Pokemon* GetBattlerMon(enum BattlerId battler);

enum BattlerId GetBattlerAtPosition(enum BattlerPosition position);
enum BattlerId GetPartnerBattler(enum BattlerId battler);
enum BattlerId GetOppositeBattler(enum BattlerId battler);
enum BattlerPosition GetPartnerPosition(enum BattlerPosition position);
enum BattlerPosition GetOppositePosition(enum BattlerPosition position);
enum BattlerId GetBattlerLeftFoe(enum BattlerId battler);
enum BattlerId GetBattlerRightFoe(enum BattlerId battler);
enum BattlerId GetDefaultSelectionTarget(enum BattlerId battler, enum MoveTarget moveTarget);

static inline bool32 IsBattlerAlive(enum BattlerId battler)
{
    if (battler >= gBattlersCount)
        return FALSE;
    else if (gBattleMons[battler].hp == 0)
        return FALSE;
    else if (gAbsentBattlerFlags & (1u << battler))
        return FALSE;
    else
        return TRUE;
}

// Some effects, like most end of turn effects only activate on active battlers (on the field)
// IsBattlerAlive doesn't check for queued switches, so IsBattlerPresent is used in these cases
static inline bool32 IsBattlerPresent(enum BattlerId battler)
{
    if (!IsBattlerAlive(battler))
        return FALSE;
    else if (gBattleStruct->battlerState[battler].notOnField)
        return FALSE;
    else
        return TRUE;
}

static inline bool32 IsBattlerTurnDamaged(enum BattlerId battler, enum SubCheck subCheck)
{
    return gSpecialStatuses[battler].damagedByAttack || ((subCheck == INCLUDING_SUBSTITUTES) && gBattleStruct->moveDamage[battler] > 0);
}

static inline bool32 IsBattlerAtMaxHp(enum BattlerId battler)
{
    return gBattleMons[battler].hp == gBattleMons[battler].maxHP;
}

static inline enum BattlerPosition GetBattlerPosition(enum BattlerId battler)
{
    return gBattlerPositions[battler];
}

static inline enum BattleSide GetBattlerSide(enum BattlerId battler)
{
    return GetBattlerPosition(battler) & BIT_SIDE;
}

static inline bool32 IsOnPlayerSide(enum BattlerId battler)
{
    return GetBattlerSide(battler) == B_SIDE_PLAYER;
}

static inline bool32 IsBattlerAlly(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    return GetBattlerSide(battlerAtk) == GetBattlerSide(battlerDef);
}

static inline bool32 IsDoubleBattle(void)
{
    return !!(gBattleTypeFlags & BATTLE_TYPE_MORE_THAN_TWO_BATTLERS);
}

static inline bool32 IsSpreadMove(enum MoveTarget moveTarget)
{
    if (!IsDoubleBattle())
        return FALSE;
    return moveTarget == TARGET_BOTH || moveTarget == TARGET_FOES_AND_ALLY;
}

static inline enum Move GetBattlerChosenMove(enum BattlerId battler)
{
    return gBattleMons[battler].moves[gBattleStruct->chosenMovePositions[battler]];
}

static inline void SetPassiveDamageAmount(enum BattlerId battler, s32 value)
{
    if (value == 0)
        value = 1;
    gBattleStruct->passiveHpUpdate[battler] = value;
}

static inline void SetHealAmount(enum BattlerId battler, s32 value)
{
    if (value == 0)
        value = 1;
    gBattleStruct->passiveHpUpdate[battler] = -1 * value;
}

static inline bool32 IsGhostBattleWithoutScope(void)
{
    return (gBattleTypeFlags & BATTLE_TYPE_GHOST) && !CheckBagHasItem(ITEM_SILPH_SCOPE, 1);
}

#endif // GUARD_BATTLE_H
