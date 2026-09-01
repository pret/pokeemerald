#ifndef GUARD_MOVES_H
#define GUARD_MOVES_H

#include "config_changes.h"
#include "contest_effect.h"
#include "constants/battle.h"
#include "constants/battle_factory.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_string_ids.h"
#include "constants/battle_z_move_effects.h"
#include "constants/battle_set_effect.h"
#include "constants/moves.h"

#define STAT_CHANGE_FORCE_MAX 7 // Used for belly drum as a way to show that stats are maxed

// For defining EFFECT_HIT etc. with battle TV scores and flags etc.
struct __attribute__((packed, aligned(2))) BattleMoveEffect
{
    const u8 *battleScript;
    u16 battleTvScore:3;
    enum FactoryStyle battleFactoryStyle:4;
    u16 encourageEncore:1;
    u16 twoTurnEffect:1;
    u16 semiInvulnerableEffect:1;
    u16 usesProtectCounter:1;
    u16 padding:5;
};

#define EFFECTS_ARR(...) (const struct AdditionalEffect[]) {__VA_ARGS__}
#define ADDITIONAL_EFFECTS(...) EFFECTS_ARR( __VA_ARGS__ ), .numAdditionalEffects = ARRAY_COUNT(EFFECTS_ARR( __VA_ARGS__ ))

#define MAX_RANDOM_ADDITIONAL_EFFECTS   3

struct AdditionalEffect
{
    enum MoveEffect moveEffect;
    u8 self:1;
    u8 onlyIfTargetRaisedStats:1;
    u8 onChargeTurnOnly:1;
    u8 sheerForceOverride:1; // Handles edge cases for Sheer Force - if TRUE, boosts when it shouldn't, or doesn't boost when it should
    u8 preAttackEffect:1;
    u8 onSide:1; // Refers to moves that have an effect on both opposing targets on a single target (see dmax stat drops moves). Works on stat drop moves only
    u8 pledgeCombo:1; // If set the move effect only applies during a pledge combo attack
    u8 padding:1;

    union PACKED {
        enum MoveEffect randomMoveEffects[MAX_RANDOM_ADDITIONAL_EFFECTS]; // Used by MOVE_EFFECT_RANDOM_FROM_LIST
        enum WrappedStringID wrapped:8;
        enum BrokeProtectionStringID brokeProtect:8;
        u8 absorbPercentage;
    } argument; // argument field for MOVE_EFFECTS

    u8 chance; // 0% = effect certain, primary effect
    u8 stats;

    u32 attack:3;
    u32 defense:3;
    u32 spAtk:3;
    u32 spDef:3;
    u32 speed:3;
    u32 accuracy:3;
    u32 evasion:3;
    u32 padding2:11;
};

enum ProtectType
{
    PROTECT_TYPE_NONE,
    PROTECT_TYPE_SIDE,
    PROTECT_TYPE_SINGLE,
};

enum ProtectMethod
{
    PROTECT_NONE,
    PROTECT_NORMAL,
    PROTECT_SPIKY_SHIELD,
    PROTECT_KINGS_SHIELD,
    PROTECT_BANEFUL_BUNKER,
    PROTECT_BURNING_BULWARK,
    PROTECT_OBSTRUCT,
    PROTECT_SILK_TRAP,
    PROTECT_MAX_GUARD,
    PROTECT_WIDE_GUARD,
    PROTECT_QUICK_GUARD,
    PROTECT_CRAFTY_SHIELD,
    PROTECT_MAT_BLOCK,
};

enum TerrainGroundCheck
{
    GROUND_CHECK_NONE,
    GROUND_CHECK_USER,
    GROUND_CHECK_TARGET,
};

struct MoveInfo
{
    const u8 *name;
    const u8 *description;
    enum BattleMoveEffects effect:16;
    enum Type type:5;     // Up to 32
    enum DamageCategory category:2;
    u16 power:9;    // up to 511
    // end of word
    u16 accuracy:7;
    u16 target:9;
    u8 pp;
    union {
        u8 effect;
        u8 powerOverride;
    } zMove;
    // end of word
    s32 priority:4;
    u32 strikeCount:4; // Max 15 hits. Defaults to 1 if not set. May apply its effect on each hit.
    u32 multiHit:1; // Takes precedence over strikeCount
    u32 explosion:1;
    u32 criticalHitStage:2;
    bool32 alwaysCriticalHit:1;
    u32 numAdditionalEffects:3; // limited to 7

    // Flags
    bool32 makesContact:1;
    bool32 ignoresProtect:1;
    bool32 magicCoatAffected:1;
    bool32 snatchAffected:1;
    bool32 ignoresKingsRock:1;
    bool32 punchingMove:1;
    bool32 bitingMove:1;
    bool32 pulseMove:1;
    bool32 soundMove:1;
    bool32 ballisticMove:1;
    bool32 powderMove:1;
    bool32 danceMove:1;
    bool32 windMove:1;
    bool32 slicingMove:1;
    bool32 healingMove:1;
    bool32 minimizeDoubleDamage:1;
    // end of word
    bool32 ignoresTargetAbility:1;
    bool32 ignoresTargetDefenseEvasionStages:1;
    bool32 damagesUnderground:1;
    bool32 damagesUnderwater:1;
    bool32 damagesAirborne:1;
    bool32 damagesAirborneDoubleDamage:1;
    bool32 ignoreTypeIfFlyingAndUngrounded:1;
    bool32 thawsUser:1;
    bool32 ignoresSubstitute:1;
    bool32 forcePressure:1;
    bool32 cantUseTwice:1;
    bool32 alwaysHitsInRain:1;
    bool32 accuracy50InSun:1;
    bool32 alwaysHitsInHailSnow:1;
    bool32 alwaysHitsOnSameType:1; // Always hits if user is of same type as move
    bool32 noAffectOnSameTypeTarget:1; // Fails if target is of same type as move
    bool32 accDecreaseIfUserNotSameType:1; // Accuracy is increased by 10% if user is of same type as move
    bool32 padding1:15;
    // end of word

    // Ban flags
    bool32 gravityBanned:1;
    bool32 mirrorMoveBanned:1;
    bool32 meFirstBanned:1;
    bool32 mimicBanned:1;
    bool32 metronomeBanned:1;
    bool32 copycatBanned:1;
    bool32 assistBanned:1; // Matches same moves as copycatBanned + semi-invulnerable moves and Mirror Coat.
    bool32 sleepTalkBanned:1;
    bool32 instructBanned:1;
    bool32 encoreBanned:1;
    bool32 parentalBondBanned:1;
    bool32 skyBattleBanned:1;
    bool32 sketchBanned:1;
    bool32 dampBanned:1;
    //Other
    bool32 validApprenticeMove:1;
    u32 padding2:17;
    // end of word

    union {
        struct {
            u16 stringId;
            enum SemiInvulnerableState state:8;
            enum BattleWeather weather:8;
        } twoTurnAttack;
        struct {
            enum Species species;
            u16 power:9;
            u16 numOfHits:7;
        } speciesPowerOverride;
        struct {
            u16 damagePercent:12;
            u16 damageCategories:4; // bit field
        } reflectDamage;
        struct {
            enum BattleTerrain terrain:8;
            u32 percent:13;
            enum TerrainGroundCheck groundCheck:2;
            u32 hitsBothFoes:1;
            u32 padding:8;
        } terrainBoost;
        struct {
            u16 comboMove;
            u16 resultMove;
        } pledge;
        u32 protectMethod;
        u32 status;
        u32 moveProperty;
        u32 holdEffect;
        u32 type;
        u32 fixedDamage;
        u32 damagePercentage;
        u32 recoilPercentage;
        u32 nonVolatileStatus;
        u32 overwriteAbility;
        u32 weatherType;
        u32 terrainType;
    } argument; // argument field for EFFECTS

    // primary/secondary effects
    const struct AdditionalEffect *additionalEffects;

    // contest parameters
    u8 contestEffect;
    u8 contestCategory:3;
    u8 contestComboStarterId;
    u8 contestComboMoves[MAX_COMBO_MOVES];
    const u8 *battleAnimScript;
};

extern const struct MoveInfo gMovesInfo[MOVES_COUNT_ALL];
extern const u8 gNotDoneYetDescription[];
extern const struct BattleMoveEffect gBattleMoveEffects[];

// The argument field in MovesInfo is limited to 4 bytes on purpose to not waste space unnecessarily.
// Downstream projects are free to remove this limitation.
_Static_assert(sizeof(gMovesInfo[0].argument) == 4, "MovesInfo argument does not fit into 4 bytes");

// The additional effect argument field is limited to 6 bytes on purpose to not waste space unnecessarily.
// Downstream projects are free to remove this limitation.
_Static_assert(sizeof(gMovesInfo[0].additionalEffects[0].argument) == 3, "AdditionalEffect argument does not fit into 6 bytes");

static inline enum Move SanitizeMoveId(enum Move moveId)
{
    assertf(moveId < MOVES_COUNT_ALL, "invalid move: %d", moveId)
    {
        return MOVE_NONE;
    }

    return moveId;
}

static inline const u8 *GetMoveName(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].name;
}

static inline enum BattleMoveEffects GetMoveEffect(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].effect;
}

static inline const u8 *GetMoveDescription(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    if (GetMoveEffect(moveId) == EFFECT_PLACEHOLDER)
        return gNotDoneYetDescription;
    return gMovesInfo[moveId].description;
}

static inline enum Type GetMoveType(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].type;
}

static inline enum DamageCategory GetMoveCategory(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].category;
}

static inline u32 GetMovePower(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].power;
}

static inline u32 GetMoveAccuracy(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].accuracy;
}

static inline enum MoveTarget GetMoveTarget(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    enum MoveTarget target = gMovesInfo[moveId].target;
    assertf(target != TARGET_SMART || gMovesInfo[moveId].strikeCount > 1, "Smart target requires strikeCount > 1: %S", gMovesInfo[moveId].name);
    return target;
}

static inline u32 GetMovePP(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].pp;
}

static inline enum ZEffect GetMoveZEffect(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    assertf(GetMoveCategory(moveId) == DAMAGE_CATEGORY_STATUS, "not a status move: %S", gMovesInfo[moveId].name);
    return gMovesInfo[moveId].zMove.effect;
}

static inline u32 GetMoveZPowerOverride(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    assertf(GetMoveCategory(moveId) != DAMAGE_CATEGORY_STATUS, "not a damaging move: %S", gMovesInfo[moveId].name);
    return gMovesInfo[moveId].zMove.powerOverride;
}

static inline s32 GetMovePriority(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].priority;
}

static inline u32 GetMoveStrikeCount(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].strikeCount;
}

static inline u32 IsMultiHitMove(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].multiHit;
}

static inline u32 IsExplosionMove(enum Move move)
{
    return gMovesInfo[SanitizeMoveId(move)].explosion;
}

static inline u32 GetMoveCriticalHitStage(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].criticalHitStage;
}

static inline bool32 MoveAlwaysCrits(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].alwaysCriticalHit;
}

static inline u32 GetMoveAdditionalEffectCount(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].numAdditionalEffects;
}

static inline bool32 MoveMakesContact(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].makesContact;
}

static inline bool32 MoveIgnoresProtect(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].ignoresProtect;
}

static inline bool32 MoveCanBeBouncedBack(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].magicCoatAffected;
}

static inline bool32 MoveCanBeSnatched(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].snatchAffected;
}

static inline bool32 MoveIgnoresKingsRock(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].ignoresKingsRock;
}

static inline bool32 IsPunchingMove(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].punchingMove;
}

static inline bool32 IsBitingMove(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].bitingMove;
}

static inline bool32 IsPulseMove(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].pulseMove;
}

static inline bool32 IsSoundMove(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].soundMove;
}

static inline bool32 IsBallisticMove(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].ballisticMove;
}

static inline bool32 IsPowderMove(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].powderMove;
}

static inline bool32 IsDanceMove(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].danceMove;
}

static inline bool32 IsWindMove(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].windMove;
}

static inline bool32 IsSlicingMove(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].slicingMove;
}

static inline bool32 IsHealingMove(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].healingMove;
}

static inline bool32 MoveIncreasesPowerToMinimizedTargets(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].minimizeDoubleDamage;
}

static inline bool32 MoveIgnoresTargetAbility(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].ignoresTargetAbility;
}

static inline bool32 MoveIgnoresDefenseEvasionStages(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].ignoresTargetDefenseEvasionStages;
}

static inline bool32 MoveDamagesUnderground(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].damagesUnderground;
}

static inline bool32 MoveDamagesUnderWater(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].damagesUnderwater;
}

static inline bool32 MoveDamagesAirborne(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].damagesAirborne;
}

static inline bool32 MoveDamagesAirborneDoubleDamage(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].damagesAirborneDoubleDamage;
}

static inline bool32 MoveIgnoresTypeIfFlyingAndUngrounded(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].ignoreTypeIfFlyingAndUngrounded;
}

static inline bool32 MoveThawsUser(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].thawsUser;
}

static inline bool32 MoveIgnoresSubstitute(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].ignoresSubstitute;
}

static inline bool32 MoveForcesPressure(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].forcePressure;
}

static inline bool32 MoveCantBeUsedTwice(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].cantUseTwice;
}

static inline bool32 MoveAlwaysHitsInRain(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].alwaysHitsInRain;
}

static inline bool32 MoveHas50AccuracyInSun(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].accuracy50InSun;
}

static inline bool32 MoveAlwaysHitsInHailSnow(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].alwaysHitsInHailSnow;
}

static inline bool32 MoveAlwaysHitsOnSameType(enum Move moveId)
{
    #if TESTING
    if (moveId == MOVE_TOXIC && GetConfig(B_TOXIC_NEVER_MISS) < GEN_6)
       return FALSE;
    #endif
    return gMovesInfo[SanitizeMoveId(moveId)].alwaysHitsOnSameType;
}

static inline bool32 MoveHasNoEffectOnSameType(enum Move moveId)
{
    #if TESTING
    if (moveId == MOVE_SHEER_COLD && GetConfig(B_SHEER_COLD_IMMUNITY) < GEN_7)
       return FALSE;
    #endif
    return gMovesInfo[SanitizeMoveId(moveId)].noAffectOnSameTypeTarget;
}

static inline bool32 MoveDecreasesAccIfUserNotSameType(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].accDecreaseIfUserNotSameType;
}

static inline bool32 IsMoveGravityBanned(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].gravityBanned;
}

static inline bool32 IsMoveMirrorMoveBanned(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].mirrorMoveBanned;
}

static inline bool32 IsMoveMeFirstBanned(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].meFirstBanned;
}

static inline bool32 IsMoveMimicBanned(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].mimicBanned;
}

static inline bool32 IsMoveMetronomeBanned(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].metronomeBanned;
}

static inline bool32 IsMoveCopycatBanned(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].copycatBanned;
}

static inline bool32 IsMoveAssistBanned(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].assistBanned;
}

static inline bool32 IsMoveSleepTalkBanned(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].sleepTalkBanned;
}

static inline bool32 IsMoveInstructBanned(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].instructBanned;
}

static inline bool32 IsMoveEncoreBanned(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].encoreBanned;
}

static inline bool32 IsMoveParentalBondBanned(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].parentalBondBanned;
}

static inline bool32 IsMoveSkyBattleBanned(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].skyBattleBanned;
}

static inline bool32 IsMoveSketchBanned(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].sketchBanned;
}

static inline bool32 IsMoveDampBanned(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].dampBanned;
}

static inline bool32 IsValidApprenticeMove(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].validApprenticeMove;
}

static inline u32 GetMoveTwoTurnAttackStringId(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    enum BattleMoveEffects effect = gMovesInfo[moveId].effect;
    assertf(gBattleMoveEffects[effect].twoTurnEffect, "not a two-turn move: %S", gMovesInfo[moveId].name);
    return gMovesInfo[moveId].argument.twoTurnAttack.stringId;
}

static inline u32 GetTwoTurnMoveSemiInvulnerability(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    enum BattleMoveEffects effect = gMovesInfo[moveId].effect;
    assertf(effect == EFFECT_SEMI_INVULNERABLE || effect == EFFECT_SKY_DROP, "not a two-turn move with status: %S", gMovesInfo[moveId].name);
    return gMovesInfo[moveId].argument.twoTurnAttack.state;
}

static inline u32 GetTwoTurnMoveWeather(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    enum BattleMoveEffects effect = gMovesInfo[moveId].effect;
    assertf(effect == EFFECT_TWO_TURNS_ATTACK || effect == EFFECT_SOLAR_BEAM, "not a two-turn move with weather: %S", gMovesInfo[moveId].name);
    return gMovesInfo[moveId].argument.twoTurnAttack.weather;
}

static inline enum Species GetMoveSpeciesPowerOverride_Species(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    assertf(gMovesInfo[moveId].effect == EFFECT_SPECIES_POWER_OVERRIDE, "not a species power override move: %S", GetMoveName(moveId));
    return gMovesInfo[SanitizeMoveId(moveId)].argument.speciesPowerOverride.species;
}

static inline u32 GetMoveSpeciesPowerOverride_Power(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    assertf(gMovesInfo[moveId].effect == EFFECT_SPECIES_POWER_OVERRIDE, "not a species power override move: %S", GetMoveName(moveId));
    return gMovesInfo[SanitizeMoveId(moveId)].argument.speciesPowerOverride.power;
}

static inline u32 GetMoveSpeciesPowerOverride_NumOfHits(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    assertf(gMovesInfo[moveId].effect == EFFECT_SPECIES_POWER_OVERRIDE, "not a species power override move: %S", GetMoveName(moveId));
    return gMovesInfo[SanitizeMoveId(moveId)].argument.speciesPowerOverride.numOfHits;
}

static inline u32 GetMoveReflectDamage_DamagePercent(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    assertf(gMovesInfo[moveId].effect == EFFECT_REFLECT_DAMAGE, "not a damage reflection move: %S", GetMoveName(moveId));
    return gMovesInfo[SanitizeMoveId(moveId)].argument.reflectDamage.damagePercent;
}

static inline u32 GetMoveReflectDamage_DamageCategories(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    assertf(gMovesInfo[moveId].effect == EFFECT_REFLECT_DAMAGE, "not a damage reflection move: %S", GetMoveName(moveId));
    return gMovesInfo[SanitizeMoveId(moveId)].argument.reflectDamage.damageCategories;
}

static inline enum BattleTerrain GetMoveTerrainBoost_Terrain(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    assertf(gMovesInfo[moveId].effect == EFFECT_TERRAIN_BOOST, "not a terrain boosted move: %S", GetMoveName(moveId));
    return gMovesInfo[moveId].argument.terrainBoost.terrain;
}

static inline u32 GetMoveTerrainBoost_Percent(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    assertf(gMovesInfo[moveId].effect == EFFECT_TERRAIN_BOOST, "not a terrain boosted move: %S", GetMoveName(moveId));
    return gMovesInfo[moveId].argument.terrainBoost.percent;
}

static inline enum TerrainGroundCheck GetMoveTerrainBoost_GroundCheck(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    assertf(gMovesInfo[moveId].effect == EFFECT_TERRAIN_BOOST, "not a terrain boosted move: %S", GetMoveName(moveId));
    return gMovesInfo[moveId].argument.terrainBoost.groundCheck;
}

static inline bool32 GetMoveTerrainBoost_HitsBothFoes(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    assertf(gMovesInfo[moveId].effect == EFFECT_TERRAIN_BOOST, "not a terrain boosted move: %S", GetMoveName(moveId));
    return gMovesInfo[moveId].argument.terrainBoost.hitsBothFoes;
}

static inline enum Move GetPledgeComboMove(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    assertf(gMovesInfo[moveId].effect == EFFECT_PLEDGE, "not a pledge move: %S", GetMoveName(moveId));
    return gMovesInfo[moveId].argument.pledge.comboMove;
}

static inline enum Move GetPledgeResultMove(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    assertf(gMovesInfo[moveId].effect == EFFECT_PLEDGE, "not a pledge move: %S", GetMoveName(moveId));
    return gMovesInfo[moveId].argument.pledge.resultMove;
}

static inline enum ProtectMethod GetMoveProtectMethod(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    enum BattleMoveEffects effect = gMovesInfo[moveId].effect;
    assertf(effect == EFFECT_PROTECT || effect == EFFECT_ENDURE || effect == EFFECT_MAT_BLOCK, "not a protect move: %S", GetMoveName(moveId));
    return gMovesInfo[moveId].argument.protectMethod;
}

static inline u32 GetMoveEffectArg_Status(enum Move moveId)
{
    // Forward-declared here because 'include/battle_util.h' includes
    // this file.
    extern bool32 MoveHasAdditionalEffect(enum Move move, enum MoveEffect moveEffect);

    moveId = SanitizeMoveId(moveId);
    enum BattleMoveEffects effect = gMovesInfo[moveId].effect;
    assertf(effect == EFFECT_FOCUS_ENERGY || effect == EFFECT_DOUBLE_POWER_ON_ARG_STATUS || MoveHasAdditionalEffect(moveId, MOVE_EFFECT_REMOVE_STATUS), "not a move with status: %S", gMovesInfo[moveId].name);
    return gMovesInfo[moveId].argument.status;
}

static inline u32 GetMoveStatusOnStatChange(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    assertf(gMovesInfo[moveId].effect == EFFECT_STAT_CHANGE_ON_STATUS, "not a stat change on status move: %S", gMovesInfo[moveId].name);
    return gMovesInfo[moveId].argument.status;
}

static inline u32 GetMoveEffectArg_MoveProperty(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    enum BattleMoveEffects effect = gMovesInfo[moveId].effect;
    assertf(effect == EFFECT_FIRST_TURN_ONLY || effect == EFFECT_HEAL_PULSE, "not a move with moveProperty: %S", gMovesInfo[moveId].name);
    return gMovesInfo[SanitizeMoveId(moveId)].argument.moveProperty;
}

static inline enum HoldEffect GetMoveEffectArg_HoldEffect(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    enum BattleMoveEffects effect = gMovesInfo[moveId].effect;
    assertf(effect == EFFECT_CHANGE_TYPE_ON_ITEM, "not a move with a hold effect: %S", gMovesInfo[moveId].name);
    return gMovesInfo[moveId].argument.holdEffect;
}

static inline enum Type GetMoveArgType(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    enum BattleMoveEffects effect = gMovesInfo[moveId].effect;
    assertf(effect == EFFECT_SOAK
         || effect == EFFECT_TWO_TYPED_MOVE
         || effect == EFFECT_THIRD_TYPE
         || effect == EFFECT_SUPER_EFFECTIVE_ON_ARG
         || effect == EFFECT_FAIL_IF_NOT_ARG_TYPE
         || effect == EFFECT_FLOWER_SHIELD
         || effect == EFFECT_ROTOTILLER, "not a move with a type: %S", gMovesInfo[moveId].name);
    return gMovesInfo[moveId].argument.type;
}

static inline u32 GetMoveFixedHPDamage(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    assertf(gMovesInfo[moveId].effect == EFFECT_FIXED_HP_DAMAGE, "not a fixed-damage move: %S", gMovesInfo[moveId].name);
    return gMovesInfo[moveId].argument.fixedDamage;
}

static inline u32 GetMoveRecoil(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    assertf(gMovesInfo[moveId].effect == EFFECT_RECOIL, "not a recoil move: %S", gMovesInfo[moveId].name);
    return gMovesInfo[moveId].argument.recoilPercentage;
}

static inline enum MoveEffect GetMoveNonVolatileStatus(enum Move move)
{
    move = SanitizeMoveId(move);
    switch (GetMoveEffect(move))
    {
    case EFFECT_NON_VOLATILE_STATUS:
    case EFFECT_YAWN:
    case EFFECT_DARK_VOID:
        return gMovesInfo[move].argument.nonVolatileStatus;
    default:
        return MOVE_EFFECT_NONE;
    }
}

static inline u32 GetMoveDamagePercentage(enum Move move)
{
    move = SanitizeMoveId(move);
    assertf(gMovesInfo[move].effect == EFFECT_FIXED_PERCENT_DAMAGE, "not a percentage-damage move: %S", gMovesInfo[move].name);
    return gMovesInfo[move].argument.damagePercentage;
}

static inline enum Ability GetMoveOverwriteAbility(enum Move move)
{
    move = SanitizeMoveId(move);
    assertf(gMovesInfo[move].effect == EFFECT_OVERWRITE_ABILITY, "not a move that overwrites abilities: %S", gMovesInfo[move].name);
    return gMovesInfo[move].argument.overwriteAbility;
}

static inline enum BattleWeather GetMoveWeatherType(enum Move move)
{
    assertf(gMovesInfo[move].effect == EFFECT_WEATHER || gMovesInfo[move].effect == EFFECT_WEATHER_AND_SWITCH, "not a move that sets weather: %S", gMovesInfo[move].name);
    return gMovesInfo[SanitizeMoveId(move)].argument.weatherType;
}

static inline enum BattleTerrain GetMoveTerrainType(enum Move move)
{
    assertf(gMovesInfo[move].effect == EFFECT_TERRAIN, "not a move that sets terrain: %S", gMovesInfo[move].name);
    return gMovesInfo[SanitizeMoveId(move)].argument.terrainType;
}

static inline const struct AdditionalEffect *GetMoveAdditionalEffectById(enum Move moveId, u32 effect)
{
    return &gMovesInfo[SanitizeMoveId(moveId)].additionalEffects[effect];
}

static inline u32 GetMoveContestEffect(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].contestEffect;
}

static inline enum ContestCategories GetMoveContestCategory(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].contestCategory;
}

static inline u32 GetMoveContestComboStarter(enum Move moveId)
{
    return gMovesInfo[SanitizeMoveId(moveId)].contestComboStarterId;
}

static inline u32 GetMoveContestComboMoves(enum Move moveId, u32 comboMove)
{
    return gMovesInfo[SanitizeMoveId(moveId)].contestComboMoves[comboMove];
}

static inline const u8 *GetMoveAnimationScript(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    assertf(gMovesInfo[moveId].battleAnimScript, "No animation for %S", gMovesInfo[moveId].name)
    {
        return gMovesInfo[MOVE_NONE].battleAnimScript;
    }
    return gMovesInfo[moveId].battleAnimScript;
}

static inline const u8 *GetMoveBattleScript(enum Move moveId)
{
    moveId = SanitizeMoveId(moveId);
    assertf(gBattleMoveEffects[GetMoveEffect(moveId)].battleScript, "No battle script for %S", gMovesInfo[moveId].name)
    {
        return gBattleMoveEffects[EFFECT_PLACEHOLDER].battleScript;
    }
    return gBattleMoveEffects[GetMoveEffect(moveId)].battleScript;
}

#endif // GUARD_MOVES_H
