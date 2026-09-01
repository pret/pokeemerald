#ifndef GUARD_CONSTANTS_BATTLE_H
#define GUARD_CONSTANTS_BATTLE_H

#include "constants/moves.h"

/*
 * A battler may be in one of four positions on the field. The first bit determines
 * what side the battler is on, either the player's side or the opponent's side.
 * The second bit determines what flank the battler is on, either the left or right.
 * Note that the opponent's flanks are drawn corresponding to their perspective, so
 * their right mon appears on the left, and their left mon appears on the right.
 * The battler ID is usually the same as the position, except in the case of link battles.
 *
 *   + ------------------------- +
 *   |           Opponent's side |
 *   |            Right    Left  |
 *   |              3       1    |
 *   |                           |
 *   | Player's side             |
 *   |  Left   Right             |
 *   |   0       2               |
 *   +---------------------------+
 *   |                           |
 *   |                           |
 *   +---------------------------+
 */

/*
 * BattleTrainer is the identifier used to reference one of the four 6-mon battle parties
 * in gParties[MAX_BATTLE_TRAINERS]. gParties[B_TRAINER_PLAYER] is always the player's party.
 * gParties[B_TRAINER_OPPONENT_A] is always the first opponent trainer's party, or holds the first
 * wild mon during an encounter. gParties[B_TRAINER_PARTNER] is only used in multibattles where
 * the player's side has a second trainer such as Mossdeep Space Center tag battle with
 * trainer Steven. gParties[B_TRAINER_OPPONENT_B] is only used in battles with two opponent trainers.
 * In a double battle where the battle side only has a single trainer, both battlers on that battle
 * side will reside in the same party (gParties[B_TRAINER_PLAYER] for player side and
 * gParties[B_TRAINER_OPPONENT_A] for opponent side).
 * Note in link multi battles, parties are set locally on each player's device, meaning
 * even if a player is in the right position, on their device they will still occupy
 * gParties[B_TRAINER_PLAYER], with their link partner using gParties[B_TRAINER_PARTNER].
 *
 *          Regular battles              Link multi (player on left)         Link multi (player on right)
 *   + ------------------------- +      + ------------------------- +       + ------------------------- +
 *   |           Opponent's side |      |           Opponent's side |       |           Opponent's side |
 *   |            Right    Left  |      |            Right    Left  |       |            Right    Left  |
 *   | (1 trainer) opA     opA   |      |             opB     opA   |       |             opB     opA   |
 *   | (2 trainers)opB     opA   |      |                           |       |                           |
 *   |                           |      |                           |       |                           |
 *   | Player's side             |      |                           |       |                           |
 *   |  Left   Right             |      | Player's side             |       | Player's side             |
 *   |  pla     pla(double)      |      |  Left   Right             |       |  Left   Right             |
 *   |  pla     par(multi)       |      |  pla     par              |       |  par     pla              |
 *   +---------------------------+      +---------------------------+       +---------------------------+
 *   |                           |      |                           |       |                           |
 *   |                           |      |                           |       |                           |
 *   +---------------------------+      +---------------------------+       +---------------------------+
 */

enum BattlerPosition
{
    B_POSITION_PLAYER_LEFT,
    B_POSITION_OPPONENT_LEFT,
    B_POSITION_PLAYER_RIGHT,
    B_POSITION_OPPONENT_RIGHT,
    MAX_POSITION_COUNT,
    B_POSITION_ABSENT = 0xFF,
};

enum __attribute__((packed)) BattlerId
{
    B_BATTLER_0,
    B_BATTLER_1,
    B_BATTLER_2,
    B_BATTLER_3,
    MAX_BATTLERS_COUNT,
};

enum __attribute__((packed)) BattleTrainer
{
    B_TRAINER_PLAYER,
    B_TRAINER_OPPONENT_A,
    B_TRAINER_PARTNER,
    B_TRAINER_OPPONENT_B,
    MAX_BATTLE_TRAINERS,
};

enum BattleSide
{
    B_SIDE_PLAYER = 0,
    B_SIDE_OPPONENT = 1,
    NUM_BATTLE_SIDES = 2,
};

#define B_FLANK_LEFT  0
#define B_FLANK_RIGHT 1

#define BIT_SIDE        1
#define BIT_FLANK       2

// Battle Type Flags
#define BATTLE_TYPE_DOUBLE             (1 << 0)
#define BATTLE_TYPE_LINK               (1 << 1)
#define BATTLE_TYPE_IS_MASTER          (1 << 2) // In not-link battles, it's always set.
#define BATTLE_TYPE_TRAINER            (1 << 3)
#define BATTLE_TYPE_FIRST_BATTLE       (1 << 4)
#define BATTLE_TYPE_LINK_IN_BATTLE     (1 << 5) // Set on battle entry, cleared on exit. Checked rarely
#define BATTLE_TYPE_MULTI              (1 << 6)
#define BATTLE_TYPE_SAFARI             (1 << 7)
#define BATTLE_TYPE_BATTLE_TOWER       (1 << 8)
#define BATTLE_TYPE_CATCH_TUTORIAL     (1 << 9)
#define BATTLE_TYPE_ROAMER             (1 << 10)
#define BATTLE_TYPE_EREADER_TRAINER    (1 << 11)
#define BATTLE_TYPE_RAID               (1 << 12)
#define BATTLE_TYPE_LEGENDARY          (1 << 13)
#define BATTLE_TYPE_14                 (1 << 14)
#define BATTLE_TYPE_TWO_OPPONENTS      (1 << 15)
#define BATTLE_TYPE_DOME               (1 << 16)
#define BATTLE_TYPE_PALACE             (1 << 17)
#define BATTLE_TYPE_ARENA              (1 << 18)
#define BATTLE_TYPE_FACTORY            (1 << 19)
#define BATTLE_TYPE_PIKE               (1 << 20)
#define BATTLE_TYPE_PYRAMID            (1 << 21)
#define BATTLE_TYPE_INGAME_PARTNER     (1 << 22)
#define BATTLE_TYPE_TOWER_LINK_MULTI   (1 << 23)
#define BATTLE_TYPE_RECORDED           (1 << 24)
#define BATTLE_TYPE_RECORDED_LINK      (1 << 25)
#define BATTLE_TYPE_TRAINER_HILL       (1 << 26)
#define BATTLE_TYPE_TRAINER_TOWER      BATTLE_TYPE_TRAINER_HILL
#define BATTLE_TYPE_SECRET_BASE        (1 << 27)
#define BATTLE_TYPE_GHOST              (1 << 28)
#define BATTLE_TYPE_POKEDUDE           (1 << 29)
#define BATTLE_TYPE_30                 (1 << 30)
#define BATTLE_TYPE_RECORDED_IS_MASTER (1 << 31)
#define BATTLE_TYPE_FRONTIER                (BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_DOME | BATTLE_TYPE_PALACE | BATTLE_TYPE_ARENA | BATTLE_TYPE_FACTORY | BATTLE_TYPE_PIKE | BATTLE_TYPE_PYRAMID)
#define BATTLE_TYPE_FRONTIER_NO_PYRAMID     (BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_DOME | BATTLE_TYPE_PALACE | BATTLE_TYPE_ARENA | BATTLE_TYPE_FACTORY | BATTLE_TYPE_PIKE)
#define BATTLE_TYPE_RECORDED_INVALID        ((BATTLE_TYPE_LINK | BATTLE_TYPE_SAFARI | BATTLE_TYPE_FIRST_BATTLE                  \
                                             | BATTLE_TYPE_CATCH_TUTORIAL | BATTLE_TYPE_ROAMER | BATTLE_TYPE_EREADER_TRAINER    \
                                             | BATTLE_TYPE_LEGENDARY                                                            \
                                             | BATTLE_TYPE_RECORDED | BATTLE_TYPE_TRAINER_HILL | BATTLE_TYPE_SECRET_BASE))

#define WILD_DOUBLE_BATTLE                  ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_TRAINER))))
#define RECORDED_WILD_BATTLE                ((gBattleTypeFlags & BATTLE_TYPE_RECORDED) && !(gBattleTypeFlags & (BATTLE_TYPE_TRAINER | BATTLE_TYPE_FRONTIER)))
#define BATTLE_TWO_VS_ONE_OPPONENT          ((gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && TRAINER_BATTLE_PARAM.opponentB == 0xFFFF))
#define BATTLE_TYPE_HAS_AI                  (BATTLE_TYPE_TRAINER | BATTLE_TYPE_FIRST_BATTLE | BATTLE_TYPE_SAFARI | BATTLE_TYPE_ROAMER | BATTLE_TYPE_INGAME_PARTNER)
#define BATTLE_TYPE_MORE_THAN_TWO_BATTLERS  (BATTLE_TYPE_DOUBLE | BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_TWO_OPPONENTS)
#define BATTLE_TYPE_PLAYER_HAS_PARTNER      (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_TOWER_LINK_MULTI)

// Multibattle test composite flags
#define BATTLE_MULTI_TEST                   (BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_TRAINER | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_MULTI | BATTLE_TYPE_TWO_OPPONENTS)
#define BATTLE_TWO_VS_ONE_TEST              (BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_TRAINER | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_MULTI)

#define RIVAL_BATTLE_HEAL_AFTER  1
#define RIVAL_BATTLE_TUTORIAL    3

// Battle Outcome defines
#define B_OUTCOME_WON                  1
#define B_OUTCOME_LOST                 2
#define B_OUTCOME_DREW                 3
#define B_OUTCOME_RAN                  4
#define B_OUTCOME_PLAYER_TELEPORTED    5
#define B_OUTCOME_MON_FLED             6
#define B_OUTCOME_CAUGHT               7
#define B_OUTCOME_NO_SAFARI_BALLS      8
#define B_OUTCOME_FORFEITED            9
#define B_OUTCOME_MON_TELEPORTED       10
#define B_OUTCOME_LINK_BATTLE_RAN      (1 << 7) // 128

// Non-volatile status conditions
// These remain outside of battle and after switching out.
// If a new STATUS1 is added here, it should also be added to
// sCompressedStatuses in src/pokemon.c or else it will be lost outside
// of battle.
// Stored in gBattleMons[n].status1, which is u32
#define STATUS1_NONE             0
#define STATUS1_SLEEP            (1 << 0 | 1 << 1 | 1 << 2) // First 3 bits (Number of turns to sleep)
#define STATUS1_SLEEP_TURN(num)  ((num) << 0) // Just for readability (or if rearranging statuses)
#define STATUS1_POISON           (1 << 3)
#define STATUS1_BURN             (1 << 4)
#define STATUS1_FREEZE           (1 << 5)
#define STATUS1_PARALYSIS        (1 << 6)
#define STATUS1_TOXIC_POISON     (1 << 7)
#define STATUS1_TOXIC_COUNTER    (1 << 8 | 1 << 9 | 1 << 10 | 1 << 11)
#define STATUS1_TOXIC_TURN(num)  ((num) << 8)
#define STATUS1_FROSTBITE        (1 << 12)
#define STATUS1_PSN_ANY          (STATUS1_POISON | STATUS1_TOXIC_POISON)
#define STATUS1_ANY              (STATUS1_SLEEP | STATUS1_POISON | STATUS1_BURN | STATUS1_FREEZE | STATUS1_PARALYSIS | STATUS1_TOXIC_POISON | STATUS1_FROSTBITE)

#define STATUS1_CAN_MOVE         (STATUS1_POISON | STATUS1_BURN | STATUS1_PARALYSIS | STATUS1_TOXIC_POISON | STATUS1_FROSTBITE)
#define STATUS1_INCAPACITATED    (STATUS1_SLEEP | STATUS1_FREEZE)
#define STATUS1_ICY_ANY          (STATUS1_FREEZE | STATUS1_FROSTBITE)
#define STATUS1_DAMAGING         (STATUS1_PSN_ANY | STATUS1_BURN | STATUS1_FROSTBITE)

#define PERMANENT_VOLATILE 16 // Indicates permanency for battler volatiles

enum VolatileFlags
{
    V_BATON_PASSABLE = (1 << 0),
};

/* Volatile status ailments
 * These are removed after exiting the battle or switching
 *  Enum,                                   Type                           Type, max value, flags */
#define VOLATILE_DEFINITIONS(F) \
    F(VOLATILE_CONFUSION,                   confusionTimer,                (u32, PERMANENT_VOLATILE), V_BATON_PASSABLE) \
    F(VOLATILE_FLINCHED,                    flinched,                      (u32, 1)) \
    F(VOLATILE_UPROAR,                      uproarTurns,                   (u32, 5)) \
    F(VOLATILE_TORMENT,                     torment,                       (u32, 1)) \
    F(VOLATILE_BIDE,                        bideTurns,                     (u32, 3)) \
    F(VOLATILE_RAMPAGE_TURNS,               rampageTurns,                  (u32, B_RAMPAGE_TURNS + 1)) \
    F(VOLATILE_MULTIPLETURNS,               multipleTurns,                 (u32, 1)) \
    F(VOLATILE_SKY_DROP_TARGET,             skyDropTarget,                 (enum BattlerId, MAX_BATTLERS_COUNT)) \
    F(VOLATILE_CONFUSE_AFTER_DROP,          confuseAfterDrop,              (u32, 1)) \
    F(VOLATILE_WRAPPED,                     wrapped,                       (u32, 1)) \
    F(VOLATILE_WRAPPED_BY,                  wrappedBy,                     (enum BattlerId, MAX_BITS(MAX_BATTLERS_COUNT))) \
    F(VOLATILE_WRAPPED_MOVE,                wrappedMove,                   (u32, MOVES_COUNT_ALL - 1)) \
    F(VOLATILE_WRAPPED_BINDING_BAND,        wrappedBindingBand,            (u32, 1)) \
    F(VOLATILE_POWDER,                      powder,                        (u32, 1)) \
    F(VOLATILE_UNUSED,                      padding,                       (u32, 1)) \
    F(VOLATILE_INFATUATION,                 infatuation,                   (enum BattlerId, MAX_BITS(MAX_BATTLERS_COUNT))) \
    F(VOLATILE_DEFENSE_CURL,                defenseCurl,                   (u32, 1)) \
    F(VOLATILE_TRANSFORMED,                 transformed,                   (u32, 1)) \
    F(VOLATILE_RAGE,                        rage,                          (u32, 1)) \
    F(VOLATILE_SUBSTITUTE,                  substitute,                    (u32, 1), V_BATON_PASSABLE) \
    F(VOLATILE_DESTINY_BOND,                destinyBond,                   (u32, 2)) \
    F(VOLATILE_ESCAPE_PREVENTION,           escapePrevention,              (u32, 1), V_BATON_PASSABLE) \
    F(VOLATILE_NIGHTMARE,                   nightmare,                     (u32, 1)) \
    F(VOLATILE_CURSED,                      cursed,                        (u32, 1), V_BATON_PASSABLE) \
    F(VOLATILE_FORESIGHT,                   foresight,                     (u32, 1)) \
    F(VOLATILE_DRAGON_CHEER,                dragonCheer,                   (u32, 1), V_BATON_PASSABLE) \
    F(VOLATILE_FOCUS_ENERGY,                focusEnergy,                   (u32, 1), V_BATON_PASSABLE) \
    F(VOLATILE_BONUS_CRIT_STAGES,           bonusCritStages,               (u32, 4)) \
    F(VOLATILE_SEMI_INVULNERABLE,           semiInvulnerable,              (enum SemiInvulnerableState, SEMI_INVULNERABLE_COUNT)) \
    F(VOLATILE_ELECTRIFIED,                 electrified,                   (u32, 1)) \
    F(VOLATILE_MUD_SPORT,                   mudSport,                      (u32, 1), V_BATON_PASSABLE) \
    F(VOLATILE_WATER_SPORT,                 waterSport,                    (u32, 1), V_BATON_PASSABLE) \
    F(VOLATILE_SALT_CURE,                   saltCure,                      (u32, 1)) \
    F(VOLATILE_SYRUP_BOMB,                  syrupBomb,                     (u32, 1)) \
    F(VOLATILE_STICKY_SYRUPED_BY,           stickySyrupedBy,               (enum BattlerId, MAX_BITS(MAX_BATTLERS_COUNT))) \
    F(VOLATILE_GLAIVE_RUSH,                 glaiveRush,                    (u32, 1)) \
    F(VOLATILE_LEECH_SEED,                  leechSeed,                     (enum BattlerId, MAX_BITS(MAX_BATTLERS_COUNT)), V_BATON_PASSABLE) \
    F(VOLATILE_LOCK_ON,                     lockOn,                        (u32, 2)) \
    F(VOLATILE_PERISH_SONG,                 perishSong,                    (u32, 1), V_BATON_PASSABLE) \
    F(VOLATILE_MINIMIZE,                    minimize,                      (u32, 1)) \
    F(VOLATILE_CHARGE_TIMER,                chargeTimer,                   (u32, 3)) \
    F(VOLATILE_ROOT,                        root,                          (u32, 1), V_BATON_PASSABLE) \
    F(VOLATILE_YAWN,                        yawn,                          (u32, 2)) \
    F(VOLATILE_IMPRISON,                    imprison,                      (u32, 1)) \
    F(VOLATILE_GRUDGE,                      grudge,                        (u32, 1)) \
    F(VOLATILE_GASTRO_ACID,                 gastroAcid,                    (u32, 1), V_BATON_PASSABLE) \
    F(VOLATILE_SMACK_DOWN,                  smackDown,                     (u32, 1)) \
    F(VOLATILE_TELEKINESIS,                 telekinesis,                   (u32, 1), V_BATON_PASSABLE) \
    F(VOLATILE_MIRACLE_EYE,                 miracleEye,                    (u32, 1)) \
    F(VOLATILE_AQUA_RING,                   aquaRing,                      (u32, 1), V_BATON_PASSABLE) \
    F(VOLATILE_POWER_TRICK,                 powerTrick,                    (u32, 1), V_BATON_PASSABLE) \
    F(VOLATILE_NO_RETREAT,                  noRetreat,                     (u32, 1), V_BATON_PASSABLE) \
    F(VOLATILE_VESSEL_OF_RUIN,              vesselOfRuin,                  (u32, 1)) \
    F(VOLATILE_SWORD_OF_RUIN,               swordOfRuin,                   (u32, 1)) \
    F(VOLATILE_TABLETS_OF_RUIN,             tabletsOfRuin,                 (u32, 1)) \
    F(VOLATILE_BEADS_OF_RUIN,               beadsOfRuin,                   (u32, 1)) \
    F(VOLATILE_IS_TRANSFORMED_MON_SHINY,    isTransformedMonShiny,         (u32, 1)) \
    F(VOLATILE_TRANSFORMED_MON_PID,         transformedMonPID,             (u32, UINT32_MAX)) \
    F(VOLATILE_TRANSFORMED_MON_SPECIES,     transformedMonSpecies,         (u32, NUM_SPECIES)) \
    F(VOLATILE_DISABLED_MOVE,               disabledMove,                  (u32, MOVES_COUNT_ALL)) \
    F(VOLATILE_ENCORED_MOVE,                encoredMove,                   (u32, MOVES_COUNT_ALL)) \
    F(VOLATILE_PROTECT_USES,                consecutiveMoveUses,           (u32, UINT8_MAX)) \
    F(VOLATILE_STOCKPILE_COUNTER,           stockpileCounter,              (u32, MAX_STAT_STAGE)) \
    F(VOLATILE_STOCKPILE_DEF,               stockpileDef,                  (u32, MAX_STAT_STAGE)) \
    F(VOLATILE_STOCKPILE_SP_DEF,            stockpileSpDef,                (u32, MAX_STAT_STAGE)) \
    F(VOLATILE_STOCKPILE_BEFORE_DEF,        stockpileBeforeDef,            (u32, MAX_STAT_STAGE)) \
    F(VOLATILE_STOCKPILE_BEFORE_SP_DEF,     stockpileBeforeSpDef,          (u32, MAX_STAT_STAGE)) \
    F(VOLATILE_SUBSTITUTE_HP,               substituteHP,                  (u32, UINT8_MAX)) \
    F(VOLATILE_ENCORED_MOVE_POS,            encoredMovePos,                (u32, MAX_BITS(MAX_MON_MOVES))) \
    F(VOLATILE_DISABLE_TIMER,               disableTimer,                  (u32, B_DISABLE_TIMER)) \
    F(VOLATILE_ENCORE_TIMER,                encoreTimer,                   (u32, B_ENCORE_TIMER)) \
    F(VOLATILE_PERISH_SONG_TIMER,           perishSongTimer,               (u32, B_PERISH_SONG_TIMER)) \
    F(VOLATILE_ROLLOUT_TIMER,               rolloutTimer,                  (u32, UINT8_MAX)) \
    F(VOLATILE_FURY_CUTTER_COUNTER,         furyCutterCounter,             (u32, UINT8_MAX)) \
    F(VOLATILE_METRONOME_ITEM_COUNTER,      metronomeItemCounter,          (u32, UINT8_MAX)) \
    F(VOLATILE_BATTLER_PREVENTING_ESCAPE,   battlerPreventingEscape,       (enum BattlerId, MAX_BITS(MAX_BATTLERS_COUNT))) \
    F(VOLATILE_BATTLER_WITH_SURE_HIT,       battlerWithSureHit,            (enum BattlerId, MAX_BATTLERS_COUNT)) \
    F(VOLATILE_MIMICKED_MOVES,              mimickedMoves,                 (u32, MAX_BITS(MAX_MON_MOVES))) \
    F(VOLATILE_RECHARGE_TIMER,              rechargeTimer,                 (u32, 2)) \
    F(VOLATILE_AUTOTOMIZE_COUNT,            autotomizeCount,               (u32, UINT8_MAX)) \
    F(VOLATILE_SLOW_START_TIMER,            slowStartTimer,                (u32, B_SLOW_START_TIMER)) \
    F(VOLATILE_EMBARGO_TIMER,               embargoTimer,                  (u32, B_EMBARGO_TIMER), V_BATON_PASSABLE) \
    F(VOLATILE_MAGNET_RISE_TIMER,           magnetRiseTimer,               (u32, B_MAGNET_RISE_TIMER), V_BATON_PASSABLE) \
    F(VOLATILE_TELEKINESIS_TIMER,           telekinesisTimer,              (u32, B_TELEKINESIS_TIMER)) \
    F(VOLATILE_HEAL_BLOCK_TIMER,            healBlockTimer,                (u32, B_HEAL_BLOCK_TIMER), V_BATON_PASSABLE) \
    F(VOLATILE_TAUNT_TIMER,                 tauntTimer,                    (u32, B_TAUNT_TIMER)) \
    F(VOLATILE_TORMENT_TIMER,               tormentTimer,                  (u32, B_TORMENT_TIMER)) \
    F(VOLATILE_LASER_FOCUS_TIMER,           laserFocusTimer,               (u32, B_LASER_FOCUS_TIMER)) \
    F(VOLATILE_THROAT_CHOP_TIMER,           throatChopTimer,               (u32, B_THROAT_CHOP_TIMER)) \
    F(VOLATILE_WRAP_TURNS,                  wrapTurns,                     (u32, B_WRAP_TURNS)) \
    F(VOLATILE_SYRUP_BOMB_TIMER,            syrupBombTimer,                (u32, B_SYRUP_BOMB_TIMER)) \
    F(VOLATILE_USED_MOVES,                  usedMoves,                     (u32, MAX_BITS(MAX_MON_MOVES))) \
    F(VOLATILE_TRUANT_COUNTER,              truantCounter,                 (u32, 1)) \
    F(VOLATILE_TRUANT_SWITCH_IN_HACK,       truantSwitchInHack,            (u32, 1)) \
    F(VOLATILE_TAR_SHOT,                    tarShot,                       (u32, 1)) \
    F(VOLATILE_OCTOLOCK,                    octolock,                      (u32, 1)) \
    F(VOLATILE_CUD_CHEW,                    cudChew,                       (u32, 1)) \
    F(VOLATILE_WEATHER_ABILITY_DONE,        weatherAbilityDone,            (u32, 1)) \
    F(VOLATILE_TERRAIN_ABILITY_DONE,        terrainAbilityDone,            (u32, 1)) \
    F(VOLATILE_SYRUP_BOMB_IS_SHINY,         syrupBombIsShiny,              (u32, 1)) \
    F(VOLATILE_USED_PROTEAN_LIBERO,         usedProteanLibero,             (u32, 1)) \
    F(VOLATILE_EMBODY_ASPECT_ACTIVATED,     embodyAspectActivated,         (u32, 1)) \
    F(VOLATILE_FLASH_FIRE_BOOSTED,          flashFireBoosted,              (u32, 1)) \
    F(VOLATILE_BOOSTER_ENERGY_ACTIVATED,    boosterEnergyActivated,        (u32, 1)) \
    F(VOLATILE_OVERWRITTEN_ABILITY,         overwrittenAbility,            (enum Ability, ABILITIES_COUNT)) \
    F(VOLATILE_ROOST_ACTIVE,                roostActive,                   (u32, 1)) \
    F(VOLATILE_UNBURDEN_ACTIVE,             unburdenActive,                (u32, 1)) \
    F(VOLATILE_NEUTRALIZING_GAS,            neutralizingGas,               (u32, 1)) \
    F(VOLATILE_UNNERVE_ACTIVATED,           unnerveActivated,              (u32, 1)) \
    F(VOLATILE_ENDURED,                     endured,                       (u32, 1)) \
    F(VOLATILE_TRY_EJECT_PACK,              tryEjectPack,                  (u32, 1)) \
    F(VOLATILE_OCTOLOCKED_BY,               octolockedBy,                  (enum BattlerId, MAX_BITS(MAX_BATTLERS_COUNT))) \
    F(VOLATILE_SUPREME_OVERLORD_COUNTER,    supremeOverlordCounter,        (enum BattlerId, MAX_BITS(MAX_BATTLERS_COUNT))) \
    F(VOLATILE_PARADOX_BOOSTED_STAT,        paradoxBoostedStat,            (enum Stat, NUM_STATS - 1)) \
    F(VOLATILE_UNABLE_TO_USE_MOVE,          unableToUseMove,               (u32, 1)) \
    F(VOLATILE_ACTIVATE_DANCER,             activateDancer,                (u32, 1)) \
    F(VOLATILE_TRACE_ACTIVATED,             traceActivated,                (u32, 1)) \
    F(VOLATILE_SPEED_SWAP,                  speedSwapped,                  (u32, 1))


/* Use within a macro to get the maximum allowed value for a volatile. Requires _typeMaxValue as input. */
#define GET_VOLATILE_MAXIMUM(_typeMaxValue, ...) INVOKE_WITH_B(GET_VOLATILE_MAXIMUM_, _typeMaxValue)
#define GET_VOLATILE_MAXIMUM_(_type, ...) FIRST(__VA_OPT__(FIRST(__VA_ARGS__),) MAX_BITS((sizeof(_type) * 8)))

#define UNPACK_VOLATILE_ENUMS(_enum, ...) _enum,

enum Volatile
{
    VOLATILE_NONE,
    VOLATILE_DEFINITIONS(UNPACK_VOLATILE_ENUMS)
    /* Expands to VOLATILE_CONFUSION, VOLATILE_FLINCHED, etc. */
};

// Helper macros
#define INFATUATED_WITH(battler) (battler + 1)
#define LEECHSEEDED_BY(battler) (battler + 1)

enum SemiInvulnerableState
{
    STATE_NONE,
    STATE_UNDERGROUND,
    STATE_UNDERWATER,
    STATE_ON_AIR,
    STATE_PHANTOM_FORCE,
    STATE_SKY_DROP_ATTACKER,
    STATE_SKY_DROP_TARGET,
    STATE_COMMANDER,
    SEMI_INVULNERABLE_COUNT
};

enum SemiInvulnerableExclusion
{
    CHECK_ALL,
    EXCLUDE_COMMANDER,
};

enum QueuedSwitch
{
    NO_QUEUED_SWITCH,
    QUEUED_SWITCH_SEND_REPLACEMENT,
    QUEUED_SWITCH_OPEN_PARTY_SCREEN,
};

#define HITMARKER_NO_ANIMATIONS         (1 << 7)   // set from battleSceneOff. Never changed during battle
#define HITMARKER_UNUSED_8              (1 << 8)
#define HITMARKER_UNUSED_9              (1 << 9)
#define HITMARKER_UNUSED_10             (1 << 10)
#define HITMARKER_UNUSED_11             (1 << 11)
#define HITMARKER_UNUSED_12             (1 << 12)
#define HITMARKER_UNUSED_13             (1 << 13)
#define HITMARKER_UNUSED_14             (1 << 14)
#define HITMARKER_RUN                   (1 << 15)
#define HITMARKER_UNUSED_16             (1 << 16)
#define HITMARKER_DISABLE_ANIMATION     (1 << 17)   // disable animations during battle scripts, e.g. for Bug Bite
#define HITMARKER_UNUSED_18             (1 << 18)
#define HITMARKER_UNUSED_19             (1 << 19)
#define HITMARKER_UNUSED_20             (1 << 20)
#define HITMARKER_UNUSED_21             (1 << 21)
#define HITMARKER_PLAYER_FAINTED        (1 << 22)
#define HITMARKER_UNUSED_23             (1 << 23)
#define HITMARKER_UNUSED_24             (1 << 24)
#define HITMARKER_UNUSED_25             (1 << 25)
#define HITMARKER_UNUSED_26             (1 << 26)
#define HITMARKER_UNUSED_27             (1 << 27)
#define HITMARKER_FAINTED(battler)      (1u << (battler + 28)) // Also uses bits 29, 30 and 31

// Per-side statuses that affect an entire party.
// These select from gSideStatuses[n], which is a u32.
#define SIDE_STATUS_REFLECT                 (1 << 0)
#define SIDE_STATUS_LIGHTSCREEN             (1 << 1)
#define SIDE_STATUS_SAFEGUARD               (1 << 2)
#define SIDE_STATUS_MIST                    (1 << 3)
#define SIDE_STATUS_TAILWIND                (1 << 4)
#define SIDE_STATUS_AURORA_VEIL             (1 << 5)
#define SIDE_STATUS_LUCKY_CHANT             (1 << 6)
#define SIDE_STATUS_DAMAGE_NON_TYPES        (1 << 7)
#define SIDE_STATUS_RAINBOW                 (1 << 8)
#define SIDE_STATUS_SEA_OF_FIRE             (1 << 9)
#define SIDE_STATUS_SWAMP                   (1 << 10)

#define SIDE_STATUS_SCREEN_ANY     (SIDE_STATUS_REFLECT | SIDE_STATUS_LIGHTSCREEN | SIDE_STATUS_AURORA_VEIL)
#define SIDE_STATUS_PLEDGE_ANY     (SIDE_STATUS_RAINBOW | SIDE_STATUS_SEA_OF_FIRE | SIDE_STATUS_SWAMP)
#define SIDE_STATUS_GOOD_FOG       (SIDE_STATUS_SCREEN_ANY | SIDE_STATUS_SAFEGUARD | SIDE_STATUS_MIST)
#define SIDE_STATUS_GOOD_COURT     (SIDE_STATUS_GOOD_FOG | SIDE_STATUS_TAILWIND | SIDE_STATUS_LUCKY_CHANT | SIDE_STATUS_RAINBOW)
#define SIDE_STATUS_BAD_COURT      (SIDE_STATUS_DAMAGE_NON_TYPES | SIDE_STATUS_SEA_OF_FIRE | SIDE_STATUS_SWAMP)

enum Hazards
{
    HAZARDS_NONE,
    HAZARDS_SPIKES,
    HAZARDS_STICKY_WEB,
    HAZARDS_TOXIC_SPIKES,
    HAZARDS_STEALTH_ROCK,
    HAZARDS_STEELSURGE,
    HAZARDS_MAX_COUNT,
};

// Used for damaging entry hazards based on type
enum TypeSideHazard
{
    TYPE_SIDE_HAZARD_POINTED_STONES = TYPE_ROCK,
    TYPE_SIDE_HAZARD_SHARP_STEEL    = TYPE_STEEL,
};

enum BattleTerrain
{
    B_TERRAIN_NONE,
    B_TERRAIN_GRASSY,
    B_TERRAIN_MISTY,
    B_TERRAIN_ELECTRIC,
    B_TERRAIN_PSYCHIC,
    B_TERRAIN_COUNT,
};

// Field affecting statuses.
#define STATUS_FIELD_MAGIC_ROOM                     (1 << 0)
#define STATUS_FIELD_TRICK_ROOM                     (1 << 1)
#define STATUS_FIELD_WONDER_ROOM                    (1 << 2)
#define STATUS_FIELD_MUDSPORT                       (1 << 3)
#define STATUS_FIELD_WATERSPORT                     (1 << 4)
#define STATUS_FIELD_GRAVITY                        (1 << 5)
#define STATUS_FIELD_ION_DELUGE                     (1 << 6)
#define STATUS_FIELD_FAIRY_LOCK                     (1 << 7)

// Flags describing move's result
#define MOVE_RESULT_MISSED                 (1 << 0)
#define MOVE_RESULT_SUPER_EFFECTIVE        (1 << 1)
#define MOVE_RESULT_NOT_VERY_EFFECTIVE     (1 << 2)
#define MOVE_RESULT_DOESNT_AFFECT_FOE      (1 << 3)
#define MOVE_RESULT_ONE_HIT_KO             (1 << 4)
#define MOVE_RESULT_ONE_HIT_KO_NO_AFFECT   (1 << 5)
#define MOVE_RESULT_ONE_HIT_KO_STURDY      (1 << 6)
#define MOVE_RESULT_FAILED                 (1 << 7)
#define MOVE_RESULT_FOE_ENDURED            (1 << 8)
#define MOVE_RESULT_FOE_HUNG_ON            (1 << 9)
#define MOVE_RESULT_STURDIED               (1 << 10)
#define MOVE_RESULT_FOE_ENDURED_AFFECTION  (1 << 11)
#define MOVE_RESULT_ATTEMPT_STAT_CHANGE    (1 << 12)
#define MOVE_RESULT_STAT_CHANGE_PREVENTED  (1 << 13)
#define MOVE_RESULT_MIRROR_ARMOR_PENDING   (1 << 14)
#define MOVE_RESULT_STAT_CHANGED           (1 << 15)
#define MOVE_RESULT_PROTECTED              (1 << 16)
#define MOVE_RESULT_EXTREMELY_EFFECTIVE    (1 << 17)
#define MOVE_RESULT_MOSTLY_INEFFECTIVE     (1 << 18)
#define MOVE_RESULT_NOT_PRESENT            (1 << 19) // Battler not present at the start of move resolution
#define MOVE_RESULT_AVOIDED_ATTACK         (MOVE_RESULT_MISSED | MOVE_RESULT_FAILED | MOVE_RESULT_PROTECTED)
#define MOVE_RESULT_NO_EFFECT              (MOVE_RESULT_MISSED | MOVE_RESULT_FAILED | MOVE_RESULT_PROTECTED | MOVE_RESULT_DOESNT_AFFECT_FOE)
#define MOVE_RESULT_HIGH_EFFECTIVENESS     (MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_EXTREMELY_EFFECTIVE)
#define MOVE_RESULT_LOW_EFFECTIVENESS      (MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_MOSTLY_INEFFECTIVE)
#define MOVE_RESULT_INVALID_TARGET         (MOVE_RESULT_NO_EFFECT | MOVE_RESULT_NOT_PRESENT)

// These select from gBattleWeather, which is a u16.
enum BattleWeather
{
    BATTLE_WEATHER_NONE,
    BATTLE_WEATHER_RAIN,
    BATTLE_WEATHER_RAIN_PRIMAL,
    BATTLE_WEATHER_RAIN_DOWNPOUR,
    BATTLE_WEATHER_SUN,
    BATTLE_WEATHER_SUN_PRIMAL,
    BATTLE_WEATHER_SANDSTORM,
    BATTLE_WEATHER_HAIL,
    BATTLE_WEATHER_SNOW,
    BATTLE_WEATHER_FOG,
    BATTLE_WEATHER_STRONG_WINDS,
    BATTLE_WEATHER_COUNT,
};

// Battle Weather flags
#define B_WEATHER_NONE          0
#define B_WEATHER_RAIN_NORMAL   (1 << BATTLE_WEATHER_RAIN)
#define B_WEATHER_RAIN_PRIMAL   (1 << BATTLE_WEATHER_RAIN_PRIMAL)
#define B_WEATHER_RAIN_DOWNPOUR (1 << BATTLE_WEATHER_RAIN_DOWNPOUR)  // unused
#define B_WEATHER_RAIN          (B_WEATHER_RAIN_NORMAL | B_WEATHER_RAIN_PRIMAL | B_WEATHER_RAIN_DOWNPOUR)
#define B_WEATHER_SUN_NORMAL    (1 << BATTLE_WEATHER_SUN)
#define B_WEATHER_SUN_PRIMAL    (1 << BATTLE_WEATHER_SUN_PRIMAL)
#define B_WEATHER_SUN           (B_WEATHER_SUN_NORMAL | B_WEATHER_SUN_PRIMAL)
#define B_WEATHER_SANDSTORM     (1 << BATTLE_WEATHER_SANDSTORM)
#define B_WEATHER_HAIL          (1 << BATTLE_WEATHER_HAIL)
#define B_WEATHER_SNOW          (1 << BATTLE_WEATHER_SNOW)
#define B_WEATHER_FOG           (1 << BATTLE_WEATHER_FOG)
#define B_WEATHER_STRONG_WINDS  (1 << BATTLE_WEATHER_STRONG_WINDS)

#define B_WEATHER_DAMAGING_ANY  (B_WEATHER_HAIL | B_WEATHER_SANDSTORM)
#define B_WEATHER_ICY_ANY       (B_WEATHER_HAIL | B_WEATHER_SNOW)
#define B_WEATHER_LOW_LIGHT     (B_WEATHER_FOG | B_WEATHER_ICY_ANY | B_WEATHER_RAIN | B_WEATHER_SANDSTORM)
#define B_WEATHER_PRIMAL_ANY    (B_WEATHER_RAIN_PRIMAL | B_WEATHER_SUN_PRIMAL | B_WEATHER_STRONG_WINDS)
#define B_WEATHER_ANY           (B_WEATHER_RAIN | B_WEATHER_SANDSTORM | B_WEATHER_SUN | B_WEATHER_ICY_ANY | B_WEATHER_STRONG_WINDS | B_WEATHER_FOG)

// Battle environment defines for gBattleEnvironment.
enum BattleEnvironments
{
    BATTLE_ENVIRONMENT_GRASS,
    BATTLE_ENVIRONMENT_LONG_GRASS,
    BATTLE_ENVIRONMENT_SAND,
    BATTLE_ENVIRONMENT_UNDERWATER,
    BATTLE_ENVIRONMENT_WATER,
    BATTLE_ENVIRONMENT_POND,
    BATTLE_ENVIRONMENT_MOUNTAIN,
    BATTLE_ENVIRONMENT_CAVE,
    BATTLE_ENVIRONMENT_BUILDING,
    BATTLE_ENVIRONMENT_PLAIN,
    BATTLE_ENVIRONMENT_FRONTIER,
    BATTLE_ENVIRONMENT_GYM,
    BATTLE_ENVIRONMENT_LEADER,
    BATTLE_ENVIRONMENT_MAGMA,
    BATTLE_ENVIRONMENT_AQUA,
    BATTLE_ENVIRONMENT_SIDNEY,
    BATTLE_ENVIRONMENT_PHOEBE,
    BATTLE_ENVIRONMENT_GLACIA,
    BATTLE_ENVIRONMENT_DRAKE,
    BATTLE_ENVIRONMENT_CHAMPION,
    BATTLE_ENVIRONMENT_GROUDON,
    BATTLE_ENVIRONMENT_KYOGRE,
    BATTLE_ENVIRONMENT_RAYQUAZA,
    // New battle environments are used for Secret Power and Nature Power but not fully implemented.
    BATTLE_ENVIRONMENT_SOARING,
    BATTLE_ENVIRONMENT_SKY_PILLAR,
    BATTLE_ENVIRONMENT_BURIAL_GROUND,
    BATTLE_ENVIRONMENT_PUDDLE,
    BATTLE_ENVIRONMENT_MARSH,
    BATTLE_ENVIRONMENT_SWAMP,
    BATTLE_ENVIRONMENT_SNOW,
    BATTLE_ENVIRONMENT_ICE,
    BATTLE_ENVIRONMENT_VOLCANO,
    BATTLE_ENVIRONMENT_DISTORTION_WORLD,
    BATTLE_ENVIRONMENT_SPACE,
    BATTLE_ENVIRONMENT_ULTRA_SPACE,
    BATTLE_ENVIRONMENT_COUNT,
};

#define B_WAIT_TIME_LONG        (B_WAIT_TIME_MULTIPLIER * 4)
#define B_WAIT_TIME_MED         (B_WAIT_TIME_MULTIPLIER * 3)
#define B_WAIT_TIME_SHORT       (B_WAIT_TIME_MULTIPLIER * 2)
#define B_WAIT_TIME_SHORTEST    (B_WAIT_TIME_MULTIPLIER)

#define FLEE_ITEM    1
#define FLEE_ABILITY 2

// Return value for IsRunningFromBattleImpossible.
#define BATTLE_RUN_SUCCESS        0
#define BATTLE_RUN_FORBIDDEN      1
#define BATTLE_RUN_FAILURE        2

#define B_WIN_TYPE_NORMAL         0
#define B_WIN_TYPE_ARENA          1
#define B_WIN_TYPE_KANTO_TUTORIAL 2

// Window Ids for sStandardBattleWindowTemplates / sBattleArenaWindowTemplates
#define B_WIN_MSG                 0
#define B_WIN_ACTION_PROMPT       1 // "What will {x} do?"
#define B_WIN_ACTION_MENU         2 // "Fight/Pokémon/Bag/Run" menu
#define B_WIN_MOVE_NAME_1         3 // Top left
#define B_WIN_MOVE_NAME_2         4 // Top right
#define B_WIN_MOVE_NAME_3         5 // Bottom left
#define B_WIN_MOVE_NAME_4         6 // Bottom right
#define B_WIN_PP                  7
#define B_WIN_DUMMY               8
#define B_WIN_PP_REMAINING        9
#define B_WIN_MOVE_TYPE          10
#define B_WIN_SWITCH_PROMPT      11 // "Switch which?"
#define B_WIN_YESNO              12
#define B_WIN_LEVEL_UP_BOX       13
#define B_WIN_LEVEL_UP_BANNER    14
#define B_WIN_VS_PLAYER          15
#define B_WIN_VS_OPPONENT        16
#define B_WIN_VS_MULTI_PLAYER_1  17
#define B_WIN_VS_MULTI_PLAYER_2  18
#define B_WIN_VS_MULTI_PLAYER_3  19
#define B_WIN_VS_MULTI_PLAYER_4  20
#define B_WIN_VS_OUTCOME_DRAW    21
#define B_WIN_VS_OUTCOME_LEFT    22
#define B_WIN_VS_OUTCOME_RIGHT   23
#define B_WIN_MOVE_DESCRIPTION   24
#define B_WIN_OAK_OLD_MAN        25
#define B_CATCH_OR_NOT           26

// The following are duplicate id values for windows that Battle Arena uses differently.
#define ARENA_WIN_PLAYER_NAME      15
#define ARENA_WIN_VS               16
#define ARENA_WIN_OPPONENT_NAME    17
#define ARENA_WIN_MIND             18
#define ARENA_WIN_SKILL            19
#define ARENA_WIN_BODY             20
#define ARENA_WIN_JUDGMENT_TITLE   21
#define ARENA_WIN_JUDGMENT_TEXT    22

// Flag for BattlePutTextOnWindow. Never set
#define B_WIN_COPYTOVRAM (1 << 7)

// Indicator for the party summary bar to display an empty slot.
#define HP_EMPTY_SLOT 0xFFFF

enum MoveTarget
{
    TARGET_NONE,
    TARGET_SELECTED,
    TARGET_SMART, // Like target select but can also smartly redirect to partner. Works only with strikeCount > 1 moves
    TARGET_DEPENDS,
    TARGET_OPPONENT,
    TARGET_RANDOM,
    TARGET_BOTH,
    TARGET_USER,
    TARGET_ALLY,
    TARGET_USER_AND_ALLY,
    TARGET_USER_OR_ALLY, // Acupressure
    TARGET_FOES_AND_ALLY,
    TARGET_FIELD, // Moves that target the field, e.g. Rain Dance
    TARGET_OPPONENTS_FIELD, // Targets all other battlers and self, e.g. Teatime
    TARGET_ALL_BATTLERS,
};

// Constants for Parental Bond
#define PARENTAL_BOND_1ST_HIT 2
#define PARENTAL_BOND_2ND_HIT 1
#define PARENTAL_BOND_OFF     0

// Constants for Torment
#define PERMANENT_TORMENT   0xF

enum FaintedActions
{
    FAINTED_ACTIONS_NO_MONS_TO_SWITCH,
    FAINTED_ACTIONS_GIVE_EXP,
    FAINTED_ACTIONS_SET_ABSENT_FLAGS,
    FAINTED_ACTIONS_WAIT_STATE,
    FAINTED_ACTIONS_HANDLE_FAINTED_MON,
    FAINTED_ACTIONS_HANDLE_NEXT_BATTLER,
    FAINTED_ACTIONS_MAX_CASE,
};

//  Enum,                                             fieldName,               Type, max value
#define STARTING_STATUS_DEFINITIONS(F) \
    /* Terrains */                                                                                                                         \
    F(STARTING_STATUS_ELECTRIC_TERRAIN,               electricTerrain,            (u32, 1)) /* Electric Terrain (Permanent) */             \
    F(STARTING_STATUS_ELECTRIC_TERRAIN_TEMPORARY,     electricTerrainTemporary,   (u32, 1)) /* Electric Terrain Temporary (5 turns) */     \
    F(STARTING_STATUS_MISTY_TERRAIN,                  mistyTerrain,               (u32, 1)) /* Misty Terrain (Permanent) */                \
    F(STARTING_STATUS_MISTY_TERRAIN_TEMPORARY,        mistyTerrainTemporary,      (u32, 1)) /* Misty Terrain Temporary (5 turns) */        \
    F(STARTING_STATUS_GRASSY_TERRAIN,                 grassyTerrain,              (u32, 1)) /* Grassy Terrain (Permanent) */               \
    F(STARTING_STATUS_GRASSY_TERRAIN_TEMPORARY,       grassyTerrainTemporary,     (u32, 1)) /* Grassy Terrain Temporary (5 turns) */       \
    F(STARTING_STATUS_PSYCHIC_TERRAIN,                psychicTerrain,             (u32, 1)) /* Psychic Terrain (Permanent) */              \
    F(STARTING_STATUS_PSYCHIC_TERRAIN_TEMPORARY,      psychicTerrainTemporary,    (u32, 1)) /* Psychic Terrain Temporary (5 turns) */      \
    /* Rooms */                                                                                                                            \
    F(STARTING_STATUS_TRICK_ROOM,                     trickRoom,                  (u32, 1)) /* Trick Room (Permanent) */                   \
    F(STARTING_STATUS_TRICK_ROOM_TEMPORARY,           trickRoomTemporary,         (u32, 1)) /* Trick Room Temporary (5 turns) */           \
    F(STARTING_STATUS_MAGIC_ROOM,                     magicRoom,                  (u32, 1)) /* Magic Room (Permanent) */                   \
    F(STARTING_STATUS_MAGIC_ROOM_TEMPORARY,           magicRoomTemporary,         (u32, 1)) /* Magic Room Temporary (5 turns) */           \
    F(STARTING_STATUS_WONDER_ROOM,                    wonderRoom,                 (u32, 1)) /* Wonder Room (Permanent) */                  \
    F(STARTING_STATUS_WONDER_ROOM_TEMPORARY,          wonderRoomTemporary,        (u32, 1)) /* Wonder Room Temporary (5 turns) */          \
    /* Tailwind */                                                                                                                         \
    F(STARTING_STATUS_TAILWIND_PLAYER,                tailwindPlayer,             (u32, 1)) /* Tailwind Player (Permanent) */              \
    F(STARTING_STATUS_TAILWIND_PLAYER_TEMPORARY,      tailwindPlayerTemporary,    (u32, 1)) /* Tailwind Player Temporary (4/3 turns) */    \
    F(STARTING_STATUS_TAILWIND_OPPONENT,              tailwindOpponent,           (u32, 1)) /* Tailwind Opponent (Permanent) */            \
    F(STARTING_STATUS_TAILWIND_OPPONENT_TEMPORARY,    tailwindOpponentTemporary,  (u32, 1)) /* Tailwind Opponent Temporary (4/3 turns) */  \
    /* Pledge */                                                                                                                           \
    F(STARTING_STATUS_RAINBOW_PLAYER,                 rainbowPlayer,              (u32, 1)) /* Rainbow Player (Permanent) */               \
    F(STARTING_STATUS_RAINBOW_PLAYER_TEMPORARY,       rainbowPlayerTemporary,     (u32, 1)) /* Rainbow Player Temporary (4 turns) */       \
    F(STARTING_STATUS_RAINBOW_OPPONENT,               rainbowOpponent,            (u32, 1)) /* Rainbow Opponent (Permanent) */             \
    F(STARTING_STATUS_RAINBOW_OPPONENT_TEMPORARY,     rainbowOpponentTemporary,   (u32, 1)) /* Rainbow Opponent Temporary (4 turns) */     \
    F(STARTING_STATUS_SEA_OF_FIRE_PLAYER,             seaOfFirePlayer,            (u32, 1)) /* Sea Of Fire Player (Permanent) */           \
    F(STARTING_STATUS_SEA_OF_FIRE_PLAYER_TEMPORARY,   seaOfFirePlayerTemporary,   (u32, 1)) /* Sea Of Fire Player Temporary (4 turns) */   \
    F(STARTING_STATUS_SEA_OF_FIRE_OPPONENT,           seaOfFireOpponent,          (u32, 1)) /* Sea Of Fire Opponent (Permanent) */         \
    F(STARTING_STATUS_SEA_OF_FIRE_OPPONENT_TEMPORARY, seaOfFireOpponentTemporary, (u32, 1)) /* Sea Of Fire Opponent Temporary (4 turns) */ \
    F(STARTING_STATUS_SWAMP_PLAYER,                   swampPlayer,                (u32, 1)) /* Swamp Player (Permanent) */                 \
    F(STARTING_STATUS_SWAMP_PLAYER_TEMPORARY,         swampPlayerTemporary,       (u32, 1)) /* Swamp Player Temporary (4 turns) */         \
    F(STARTING_STATUS_SWAMP_OPPONENT,                 swampOpponent,              (u32, 1)) /* Swamp Opponent (Permanent) */               \
    F(STARTING_STATUS_SWAMP_OPPONENT_TEMPORARY,       swampOpponentTemporary,     (u32, 1)) /* Swamp Opponent Temporary (4 turns) */       \
    /* Hazards */                                                                                                                          \
    F(STARTING_STATUS_SPIKES_PLAYER_L1,               spikesPlayerL1,             (u32, 1)) /* Spikes Player Layer 1 */                    \
    F(STARTING_STATUS_SPIKES_PLAYER_L2,               spikesPlayerL2,             (u32, 1)) /* Spikes Player Layer 2 */                    \
    F(STARTING_STATUS_SPIKES_PLAYER_L3,               spikesPlayerL3,             (u32, 1)) /* Spikes Player Layer 3 */                    \
    F(STARTING_STATUS_SPIKES_OPPONENT_L1,             spikesOpponentL1,           (u32, 1)) /* Spikes Opponent Layer 1 */                  \
    F(STARTING_STATUS_SPIKES_OPPONENT_L2,             spikesOpponentL2,           (u32, 1)) /* Spikes Opponent Layer 2 */                  \
    F(STARTING_STATUS_SPIKES_OPPONENT_L3,             spikesOpponentL3,           (u32, 1)) /* Spikes Opponent Layer 3 */                  \
    F(STARTING_STATUS_TOXIC_SPIKES_PLAYER_L1,         toxicSpikesPlayerL1,        (u32, 1)) /* Toxic Spikes Player Layer 1 */              \
    F(STARTING_STATUS_TOXIC_SPIKES_PLAYER_L2,         toxicSpikesPlayerL2,        (u32, 1)) /* Toxic Spikes Player Layer 2 */              \
    F(STARTING_STATUS_TOXIC_SPIKES_OPPONENT_L1,       toxicSpikesOpponentL1,      (u32, 1)) /* Toxic Spikes Opponent Layer 1 */            \
    F(STARTING_STATUS_TOXIC_SPIKES_OPPONENT_L2,       toxicSpikesOpponentL2,      (u32, 1)) /* Toxic Spikes Opponent Layer 2 */            \
    F(STARTING_STATUS_STICKY_WEB_PLAYER,              stickyWebPlayer,            (u32, 1)) /* Sticky Web Player */                        \
    F(STARTING_STATUS_STICKY_WEB_OPPONENT,            stickyWebOpponent,          (u32, 1)) /* Sticky Web Opponent */                      \
    F(STARTING_STATUS_STEALTH_ROCK_PLAYER,            stealthRockPlayer,          (u32, 1)) /* Stealth Rock Player */                      \
    F(STARTING_STATUS_STEALTH_ROCK_OPPONENT,          stealthRockOpponent,        (u32, 1)) /* Stealth Rock Opponent */                    \
    F(STARTING_STATUS_SHARP_STEEL_PLAYER,             sharpSteelPlayer,           (u32, 1)) /* Sharp Steel Player */                       \
    F(STARTING_STATUS_SHARP_STEEL_OPPONENT,           sharpSteelOpponent,         (u32, 1)) /* Sharp Steel Opponent */                     \
    /* Weathers */                                                                                                                         \
    F(STARTING_STATUS_WEATHER_SUN,                    weatherSun,                 (u32, 1)) /* Permanent Sun */                            \
    F(STARTING_STATUS_WEATHER_SUN_TEMPORARY,          weatherSunTemporary,        (u32, 1)) /* Temporary Sun */                            \
    F(STARTING_STATUS_WEATHER_RAIN,                   weatherRain,                (u32, 1)) /* Permanent Rain */                           \
    F(STARTING_STATUS_WEATHER_RAIN_TEMPORARY,         weatherRainTemporary,       (u32, 1)) /* Temporary Rain */                           \
    F(STARTING_STATUS_WEATHER_SANDSTORM,              weatherSandstorm,           (u32, 1)) /* Permanent Sandstorm */                      \
    F(STARTING_STATUS_WEATHER_SANDSTORM_TEMPORARY,    weatherSandstormTemporary,  (u32, 1)) /* Temporary Sandstorm */                      \
    F(STARTING_STATUS_WEATHER_HAIL,                   weatherHail,                (u32, 1)) /* Permanent Hail */                           \
    F(STARTING_STATUS_WEATHER_HAIL_TEMPORARY,         weatherHailTemporary,       (u32, 1)) /* Temporary Hail */                           \
    F(STARTING_STATUS_WEATHER_SNOW,                   weatherSnow,                (u32, 1)) /* Permanent Snow */                           \
    F(STARTING_STATUS_WEATHER_SNOW_TEMPORARY,         weatherSnowTemporary,       (u32, 1)) /* Temporary Snow */                           \
    F(STARTING_STATUS_WEATHER_FOG,                    weatherFog,                 (u32, 1)) /* Permanent Fog */                            \
    F(STARTING_STATUS_WEATHER_FOG_TEMPORARY,          weatherFogTemporary,        (u32, 1)) /* Temporary Fog */                            \

#define UNPACK_STARTING_STATUS_ENUMS(_enum, ...) _enum,

// Constants for SetStartingStatus
enum StartingStatus
{
    STARTING_STATUS_DEFINITIONS(UNPACK_STARTING_STATUS_ENUMS)
};

enum SlideMsgStates
{
    PRINT_SLIDE_MESSAGE,
    RESTORE_BATTLER_SLIDE_CONTROL,
};

enum MonState
{
    MON_IN_BATTLE,
    MON_OUTSIDE_BATTLE,
};

enum __attribute__((packed)) CalcDamageState
{
    CAN_DAMAGE,
    WILL_FAIL,
    CHECK_ACCURACY,
};

enum SubmoveState
{
    SUBMOVE_NO_EFFECT,
    SUBMOVE_SUCCESS,
    SUBMOVE_FAILURE,
};

enum VictoryCatch
{
    VICTORY_CATCH_START,
    VICTORY_CATCH_OPEN_BAG,
    VICTORY_CATCH_FAINTED,
};

#endif // GUARD_CONSTANTS_BATTLE_H
