#ifndef GUARD_BATTLE_AI_UTIL_H
#define GUARD_BATTLE_AI_UTIL_H

#include "battle_ai_main.h"
#include "battle_ai_field_statuses.h"

// Roll boundaries used by AI when scoring. Doesn't affect actual damage dealt.
#define MAX_ROLL_PERCENTAGE DMG_ROLL_PERCENT_HI
#define MIN_ROLL_PERCENTAGE DMG_ROLL_PERCENT_LO
#define DMG_ROLL_PERCENTAGE ((MAX_ROLL_PERCENTAGE + MIN_ROLL_PERCENTAGE + 1) / 2) // Controls the damage roll the AI sees for the median roll. By default the 9th roll is seen

enum DamageRollType
{
    DMG_ROLL_LOWEST,
    DMG_ROLL_MEDIAN,
    DMG_ROLL_HIGHEST,
    DMG_ROLL_RANDOM,
};

enum DamageCalcContext
{
    AI_DEFENDING,
    AI_ATTACKING,
    AI_SWITCHIN_DEFENDING,
    AI_SWITCHIN_ATTACKING,
    AI_SHOULD_SETUP_DEFENDING,
    AI_ATTACKING_PARTNER,
};

enum AiConsiderEndure
{
    CONSIDER_ENDURE,
    DONT_CONSIDER_ENDURE,
};

// Higher priority at the bottom; note that these are used in the formula MAX_MON_MOVES ^ AiCompareMovesPriority, which must fit within a u32.
// In expansion where MAX_MON_MOVES is 4, this means that AiCompareMovesPriority can range from 0 - 15 inclusive.
enum AiCompareMovesPriority
{
    PRIORITY_EFFECT,
    PRIORITY_ACCURACY,
    PRIORITY_GUARANTEE,
    PRIORITY_AVOID_SELF_SACRIFICE,
    PRIORITY_SPEED,
    PRIORITY_NOT_CHARGING,
    PRIORITY_RESIST_BERRY,
};

enum AIPivot
{
    DONT_PIVOT,
    CAN_TRY_PIVOT,
    SHOULD_PIVOT,
};

enum WeatherState
{
    WEATHER_INACTIVE,
    WEATHER_ACTIVE,
    WEATHER_ACTIVE_BUT_BLOCKED,
    WEATHER_INACTIVE_AND_BLOCKED,
};

enum AIConsiderGimmick
{
    NO_GIMMICK,
    USE_GIMMICK,
};

enum ConsiderPriority
{
    DONT_CONSIDER_PRIORITY,
    CONSIDER_PRIORITY,
};

enum AIConsiderWrapDamage
{
    DONT_CONSIDER_WRAP_DAMAGE,
    CONSIDER_WRAP_DAMAGE,
};

struct AiCalcValues
{
    enum Move move;
    uq4_12_t typeEffectiveness;
    u32 weather:8;
    enum BattleTerrain terrain:8;
    enum Gimmick gimmickAtk:8;
    enum Gimmick gimmickDef:8;
};

static inline bool32 IsMoveUnusable(u32 moveIndex, enum Move move, u32 moveLimitations)
{
    return move == MOVE_NONE
        || move == MOVE_UNAVAILABLE
        || moveLimitations & 1u << moveIndex;
}

typedef bool32 (*MoveFlag)(enum Move move);

bool32 AI_IsFaster(enum BattlerId battlerAi, enum BattlerId battlerDef, enum Move aiMove, enum Move playerMove, enum ConsiderPriority considerPriority);
bool32 AI_IsSlower(enum BattlerId battlerAi, enum BattlerId battlerDef, enum Move aiMove, enum Move playerMove, enum ConsiderPriority considerPriority);
bool32 AI_RandLessThan(u32 val);
bool32 AI_IsBattlerGrounded(enum BattlerId battler);
enum MoveTarget AI_GetBattlerMoveTargetType(enum BattlerId battler, enum Move move);
enum Ability AI_GetMoldBreakerSanitizedAbility(enum BattlerId battlerAtk, enum Ability abilityAtk, enum Ability abilityDef, enum HoldEffect holdEffectDef, enum Move move);
u32 AI_GetDamage(enum BattlerId battlerAtk, enum BattlerId battlerDef, u32 moveIndex, enum DamageCalcContext calcContext, struct AiLogicData *aiData);
bool32 IsAiFlagPresent(u64 flag);
bool32 IsAiBattlerAware(enum BattlerId battlerId);
bool32 IsAiBattlerAssumingStab(enum BattlerId battlerId);
bool32 IsAiBattlerAssumingStatusMoves(enum BattlerId battlerId);
bool32 IsAiBattlerPredictingAbility(enum BattlerId battlerId);
bool32 ShouldRecordStatusMove(enum Move move);
void SaveBattlerData(enum BattlerId battlerId);
void SetBattlerData(enum BattlerId battlerId);
void SetBattlerAiData(enum BattlerId battler, struct AiLogicData *aiData);
void RestoreBattlerData(enum BattlerId battlerId);
enum Move GetAIChosenMove(enum BattlerId battlerId);
u32 GetTotalBaseStat(enum Species species);
bool32 IsTruantMonVulnerable(enum BattlerId battlerAI, enum BattlerId opposingBattler);
bool32 AI_BattlerAtMaxHp(enum BattlerId battler);
u32 GetHealthPercentage(enum BattlerId battler);
bool32 AI_CanBattlerEscape(enum BattlerId battler);
bool32 IsBattlerTrapped(enum BattlerId battlerAtk, enum BattlerId battlerDef);
s32 AI_WhoStrikesFirst(enum BattlerId battlerAI, enum BattlerId battler, enum Move aiMoveConsidered, enum Move playerMoveConsidered, enum ConsiderPriority considerPriority);
bool32 CanTargetFaintAi(enum BattlerId battlerDef, enum BattlerId battlerAtk);
u32 NoOfHitsForTargetToFaintBattler(enum BattlerId battlerDef, enum BattlerId battlerAtk, enum DamageCalcContext calcContext, enum AiConsiderEndure considerEndure);
void GetBestDmgMovesFromBattler(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum DamageCalcContext calcContext, enum Move *bestMoves);
u32 GetMoveIndex(enum BattlerId battler, enum Move move);
bool32 IsBestDmgMove(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum DamageCalcContext calcContext, enum Move move);
bool32 BestDmgMoveHasEffect(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum DamageCalcContext calcContext, enum BattleMoveEffects moveEffect);
u32 GetBestDmgFromBattler(enum BattlerId battler, enum BattlerId battlerTarget, enum DamageCalcContext calcContext);
bool32 CanTargetMoveFaintAi(enum Move move, enum BattlerId battlerDef, enum BattlerId battlerAtk, u32 nHits);
bool32 CanTargetFaintAiWithMod(enum BattlerId battlerDef, enum BattlerId battlerAtk, s32 hpMod, s32 dmgMod);
enum Ability AI_DecideKnownAbilityForTurn(enum BattlerId battlerId);
enum HoldEffect AI_DecideHoldEffectForTurn(enum BattlerId battlerId);
bool32 DoesBattlerIgnoreAbilityChecks(enum BattlerId battlerAtk, enum Ability atkAbility, enum Move move);
u32 AI_GetWeather(void);
u32 AI_GetSwitchinWeather(enum BattlerId battler);
u32 AI_GetSwitchinTerrain(enum BattlerId battler);
enum WeatherState IsWeatherActive(u32 flags);
bool32 CanAIFaintTarget(enum BattlerId battlerAtk, enum BattlerId battlerDef, u32 numHits);
bool32 CanIndexMoveFaintTarget(enum BattlerId battlerAtk, enum BattlerId battlerDef, u32 index, enum DamageCalcContext calcContext);
bool32 HasDamagingMove(enum BattlerId battler);
bool32 HasDamagingMoveOfType(enum BattlerId battler, enum Type type);
u32 GetBattlerSecondaryDamage(enum BattlerId battlerId);
bool32 BattlerWillFaintFromWeather(enum BattlerId battler, enum Ability ability);
bool32 BattlerWillFaintFromSecondaryDamage(enum BattlerId battler, enum Ability ability);
bool32 ShouldTryOHKO(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability atkAbility, enum Ability defAbility, enum Move move);
bool32 ShouldAbsorb(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, u32 absorbPercentage);
bool32 ShouldRecover(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, u32 healPercent);
bool32 ShouldSetScreen(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum BattleMoveEffects moveEffect);
bool32 ShouldCureStatus(enum BattlerId battlerAtk, enum BattlerId battlerDef, struct AiLogicData *aiData);
bool32 ShouldCureStatusWithItem(enum BattlerId battlerAtk, enum BattlerId battlerDef, struct AiLogicData *aiData);
enum AIPivot ShouldPivot(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move);
bool32 IsRecycleEncouragedItem(enum Item item);
bool32 ShouldRestoreHpBerry(enum BattlerId battlerAtk, enum Item item);
bool32 IsStatBoostingBerry(enum Item item);
bool32 CanKnockOffItem(enum BattlerId fromBattler, enum BattlerId battler, enum Item item);
bool32 IsAbilityOfRating(enum Ability ability, s32 rating);
bool32 AI_IsAbilityOnSide(enum BattlerId battlerId, enum Ability ability);
bool32 AI_MoveMakesContact(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability ability, enum HoldEffect holdEffect, enum Move move);
bool32 AI_CanContactBypassProtect(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move);
bool32 IsConsideringZMove(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move);
bool32 ShouldUseZMove(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move chosenMove);
void SetAIUsingGimmick(enum BattlerId battler, enum AIConsiderGimmick use);
void DecideTerastal(enum BattlerId battler);
bool32 CanEndureHit(enum BattlerId battler, enum BattlerId battlerTarget, enum Move move);
bool32 ShouldFinalGambit(enum BattlerId battlerAtk, enum BattlerId battlerDef, bool32 aiIsFaster);
bool32 ShouldConsiderSelfSacrificeDamageEffect(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, bool32 aiIsFaster);

// stat stage checks
bool32 AnyStatIsRaised(enum BattlerId battlerId);
bool32 AnyUsefulStatIsRaised(enum BattlerId battlerId);
bool32 CanLowerStat(enum BattlerId battlerAtk, enum BattlerId battlerDef, struct AiLogicData *aiData, enum Stat stat);
bool32 BattlerStatCanRise(enum BattlerId battler, enum Ability battlerAbility, enum Stat stat);
bool32 AreBattlersStatsMaxed(enum BattlerId battler);
u32 CountPositiveStatStages(enum BattlerId battlerId);
u32 CountNegativeStatStages(enum BattlerId battlerId);

// move checks
bool32 Ai_IsPriorityBlocked(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, struct AiLogicData *aiData);
bool32 AI_CanMoveBeBlockedByTarget(struct DamageContext *ctx);
enum MoveComparisonResult CompareMoveEffects(enum Move move1, enum Move move2, enum BattlerId battlerAtk, enum BattlerId battlerDef, s32 noOfHitsToKo);
struct SimulatedDamage AI_CalcDamageSaveBattlers(enum Move move, enum BattlerId battlerAtk, enum BattlerId battlerDef, uq4_12_t *typeEffectiveness, enum Gimmick gimmickAtk, enum Gimmick gimmickDef);
bool32 IsAdditionalEffectBlocked(enum BattlerId battlerAtk, enum Ability abilityAtk, enum BattlerId battlerDef, enum Ability abilityDef, enum Move move);
struct SimulatedDamage AI_CalcDamage(struct AiCalcValues *aiCalc, enum BattlerId battlerAtk, enum BattlerId battlerDef);
bool32 AI_IsDamagedByRecoil(enum BattlerId battler);
u32 GetNoOfHitsToKO(u32 dmg, s32 hp);
u32 GetNoOfHitsToKOBattlerDmg(u32 dmg, enum BattlerId battlerDef);
u32 GetNoOfHitsToKOBattler(enum BattlerId battlerAtk, enum BattlerId battlerDef, u32 moveIndex, enum DamageCalcContext calcContext, enum AiConsiderEndure considerEndure);
u32 GetBestNoOfHitsToKO(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum DamageCalcContext calcContext);
uq4_12_t AI_GetMoveEffectiveness(enum Move move, enum BattlerId battlerAtk, enum BattlerId battlerDef);
enum Move *GetMovesArray(enum BattlerId battler);
bool32 IsConfusionMoveEffect(enum BattleMoveEffects moveEffect);
bool32 HasMove(enum BattlerId battlerId, enum Move move);
u32 GetBattlerMoveIndexWithEffect(enum BattlerId battler, enum BattleMoveEffects effect);
bool32 ShouldBeatUpForJustified(enum BattlerId battlerAtk, enum BattlerId battlerAtkPartner, enum Move move, enum Type moveType, bool32 wouldPartnerFaint, struct AiLogicData *aiData);
bool32 ShouldBeatUpForRageFist(enum BattlerId battlerAtk, enum BattlerId battlerAtkPartner, enum Move move, bool32 wouldPartnerFaint, struct AiLogicData *aiData);
bool32 ShouldTriggerSpicySprayForBurn(enum BattlerId battlerAtk, enum Move move, u32 noOfHitsToKOPartner, struct AiLogicData *aiData);
bool32 HasPhysicalBestMove(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum DamageCalcContext calcContext);
bool32 HasOnlyMovesWithCategory(enum BattlerId battlerId, enum DamageCategory category, bool32 onlyOffensive);
bool32 HasMoveWithCategory(enum BattlerId battler, enum DamageCategory category);
bool32 HasMoveWithType(enum BattlerId battler, enum Type type);
bool32 HasMoveWithEffect(enum BattlerId battler, enum BattleMoveEffects moveEffect);
bool32 HasMoveWithAIEffect(enum BattlerId battler, u32 aiEffect);
bool32 HasBattlerSideMoveWithEffect(enum BattlerId battler, enum BattleMoveEffects effect);
bool32 HasBattlerSideMoveWithAIEffect(enum BattlerId battler, u32 effect);
bool32 HasBattlerSideUsedMoveWithEffect(enum BattlerId battler, enum BattleMoveEffects effect);
bool32 HasNonVolatileMoveEffect(enum BattlerId battlerId, enum MoveEffect effect);
bool32 IsPowerBasedOnStatus(enum BattlerId battlerId, enum BattleMoveEffects effect, u32 argument);
bool32 HasMoveWithAdditionalEffect(enum BattlerId battlerId, enum MoveEffect moveEffect);
bool32 HasBattlerSideMoveWithAdditionalEffect(enum BattlerId battler, enum MoveEffect moveEffect);
bool32 HasMoveWithCriticalHitChance(enum BattlerId battlerId);
bool32 HasMoveWithMoveEffectExcept(enum BattlerId battlerId, enum MoveEffect moveEffect, enum BattleMoveEffects exception);
bool32 HasMoveThatLowersOwnStats(enum BattlerId battlerId);
bool32 HasMoveWithLowAccuracy(enum BattlerId battlerAtk, enum BattlerId battlerDef, u32 accCheck, bool32 ignoreStatus);
bool32 HasAnyKnownMove(enum BattlerId battlerId);
bool32 IsAromaVeilProtectedEffect(enum BattleMoveEffects moveEffect);
bool32 IsNonVolatileStatusMove(enum Move move);
bool32 IsMoveRedirectionPrevented(enum BattlerId battlerAtk, enum Move move, enum Ability atkAbility);
bool32 IsHazardMove(enum Move move);
bool32 IsTwoTurnNotSemiInvulnerableMove(enum BattlerId battlerAtk, enum Move move);
bool32 IsBattlerDamagedByStatus(enum BattlerId battler);
s32 ProtectChecks(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, enum Move predictedMove);
bool32 ShouldRaiseAnyStat(enum BattlerId battlerAtk, enum BattlerId battlerDef);
bool32 ShouldSetWeather(enum BattlerId battler, u32 weather);
bool32 ShouldClearWeather(enum BattlerId battler, u32 weather);
bool32 ShouldSetTerrain(enum BattlerId battler, enum BattleTerrain terrain);
bool32 ShouldClearTerrain(enum BattlerId battler, enum BattleTerrain terrain);
bool32 ShouldSetFieldStatus(enum BattlerId battler, u32 fieldStatus);
bool32 ShouldClearFieldStatus(enum BattlerId battler, u32 fieldStatus);
bool32 HasSleepMoveWithLowAccuracy(enum BattlerId battlerAtk, enum BattlerId battlerDef);
bool32 HasHealingEffect(enum BattlerId battler);
bool32 IsTrappingMove(enum Move move);
bool32 HasTrappingMoveEffect(enum BattlerId battler);
bool32 IsFlinchGuaranteed(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move);
bool32 HasChoiceEffect(enum BattlerId battler);
bool32 HasThawingMove(enum BattlerId battler);
bool32 HasMoveUsableWhileAsleep(enum BattlerId battler);
bool32 IsStatRaisingMove(enum Move move);
bool32 IsStatLoweringMove(enum Move move);
bool32 IsSwitchOutEffect(enum BattleMoveEffects effect);
bool32 IsChaseEffect(enum BattleMoveEffects effect);
bool32 HasMoveWithFlag(enum BattlerId battler, MoveFlag getFlag);
bool32 IsHazardClearingMove(enum Move move);
bool32 IsSelfSacrificeEffect(enum Move move);
bool32 IsRecoilDamageEffect(enum BattleMoveEffects effect);
u32 GetAIExplosionChanceFromHP(u32 hpPercent);

// status checks
bool32 AI_CanBeConfused(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, enum Ability ability);
bool32 IsBattlerIncapacitated(enum BattlerId battler, enum Ability ability);
bool32 AI_CanPutToSleep(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability defAbility, enum Move move, enum Move partnerMove);
bool32 ShouldPoison(enum BattlerId battlerAtk, enum BattlerId battlerDef);
bool32 AI_CanPoison(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability defAbility, enum Move move, enum Move partnerMove);
bool32 AI_CanParalyze(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability defAbility, enum Move move, enum Move partnerMove);
bool32 AI_CanConfuse(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability defAbility, enum BattlerId battlerAtkPartner, enum Move move, enum Move partnerMove);
bool32 ShouldBurn(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability abilityDef);
bool32 ShouldFreezeOrFrostbite(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability abilityDef);
bool32 ShouldParalyze(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability abilityDef);
bool32 AI_CanBurn(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability defAbility, enum BattlerId battlerAtkPartner, enum Move move, enum Move partnerMove);
bool32 AI_CanGiveFrostbite(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability defAbility, enum BattlerId battlerAtkPartner, enum Move move, enum Move partnerMove);
bool32 AI_CanBeInfatuated(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability defAbility);
bool32 AnyPartyMemberStatused(enum BattlerId battlerId, bool32 checkSoundproof);
bool32 ShouldTryToFlinch(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability atkAbility, enum Ability defAbility, enum Move move);
bool32 ShouldTrap(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, enum AIConsiderWrapDamage considerWrapDamage);
bool32 IsWakeupTurn(enum BattlerId battler);

// ability logic
bool32 IsMoxieTypeAbility(enum Ability ability);
bool32 DoesAbilityRaiseStatsWhenLowered(enum Ability ability);
bool32 DoesIntimidateRaiseStats(enum Ability ability);
bool32 ShouldTriggerAbility(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability ability);
bool32 CanEffectChangeAbility(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, struct AiLogicData *aiData);
void AbilityChangeScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 *score, struct AiLogicData *aiData);
enum AIScore BattlerBenefitsFromAbilityScore(enum BattlerId battler, enum Ability ability, struct AiLogicData *aiData);

// partner logic
// IsTargetingPartner includes a check to make sure the adjacent pokemon is truly a partner.
bool32 IsTargetingPartner(enum BattlerId battlerAtk, enum BattlerId battlerDef);
// IsBattle1v1 is distinct from !IsDoubleBattle. If the player is fighting Maxie and Tabitha, with Steven as their partner, and both Tabitha and Steven have run out of Pokemon, the battle is 1v1, even though mechanically it is a Double Battle for how battlers and flags are set.
// Most AI checks should be using IsBattle1v1; most engine checks should be using !IsDoubleBattle
bool32 IsBattle1v1(void);
bool32 HasTwoOpponents(enum BattlerId battler);
// HasTwoOpponents checks if the opposing side has two Pokémon. Partner state is irrelevant. e.g., Dragon Darts hits one time with two opponents and twice with one opponent.
bool32 HasPartner(enum BattlerId battler);
bool32 HasPartnerIgnoreFlags(enum BattlerId battler);
// HasPartner respects the Attacks Partner AI flag; HasPartnerIgnoreFlags checks only if a live Pokémon is adjacent.
bool32 AreMovesEquivalent(enum BattlerId battlerAtk, enum BattlerId battlerAtkPartner, enum Move move, enum Move partnerMove);
bool32 DoesPartnerHaveSameMoveEffect(enum BattlerId battlerAtkPartner, enum BattlerId battlerDef, enum Move move, enum Move partnerMove);
bool32 PartnerMoveEffectIsStatusSameTarget(enum BattlerId battlerAtkPartner, enum BattlerId battlerDef, enum Move partnerMove);
bool32 PartnerMoveEffectIs(enum BattlerId battlerAtkPartner, enum Move partnerMove, enum BattleMoveEffects effectCheck);
bool32 PartnerMoveIs(enum BattlerId battlerAtkPartner, enum Move partnerMove, enum Move moveCheck);
bool32 PartnerMoveIsSameAsAttacker(enum BattlerId battlerAtkPartner, enum BattlerId battlerDef, enum Move move, enum Move partnerMove);
bool32 PartnerMoveIsSameNoTarget(enum BattlerId battlerAtkPartner, enum Move move, enum Move partnerMove);
bool32 PartnerMoveActivatesSleepClause(enum Move partnerMove);
bool32 ShouldUseWishAromatherapy(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move);
u32 GetFriendlyFireKOThreshold(enum BattlerId battler);
bool32 IsAllyProtectingFromMove(enum BattlerId battlerAtk, enum Move attackerMove, enum Move allyMove);

// party logic
struct BattlePokemon *AllocSaveBattleMons(void);
void FreeRestoreBattleMons(struct BattlePokemon *savedBattleMons);
struct AiLogicData *AllocSaveAiLogicData(void);
void FreeRestoreAiLogicData(struct AiLogicData *savedAiLogicData);
s32 CountUsablePartyMons(enum BattlerId battlerId);
s32 CountUsableSideMons(enum BattlerId battlerId);
bool32 IsPartyFullyHealedExceptBattler(enum BattlerId battler);
s32 GetAILastPartyIndex(enum BattlerId battler);
u32 GetActiveBattlerIds(enum BattlerId battler, enum BattlerId *battlerIn1, enum BattlerId *battlerIn2);
bool32 IsPartyMonOnFieldOrChosenToSwitch(enum BattlerId battler, u32 partyIndex, enum BattlerId battlerIn1, enum BattlerId battlerIn2);
bool32 IsPartyMonPlannedToBeSwitchedInByPartner(u32 partyIndex, enum BattlerId battler);
s32 AI_GetAdjustedStatStage(enum BattlerId battler, enum Move move, s32 stage);
s32 GetStatChangeScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move);
s32 GetSelfStatChangeScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move);
s32 GetFoeStatChangeScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move);
s32 GetAllyStatChangeScore(enum BattlerId battlerAtk, enum BattlerId partner, enum Move move);

// score increases
enum AIScore IncreaseStatUpScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Stat stat, s32 stage);
enum AIScore IncreaseStatUpScoreContrary(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Stat stat, s32 stage);
enum AIScore IncreaseStatDownScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Stat stat);
void IncreasePoisonScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 *score);
void IncreaseBurnScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 *score);
void IncreaseParalyzeScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 *score);
void IncreaseSleepScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 *score);
void IncreaseConfusionScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 *score);
void IncreaseFrostbiteScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 *score);
bool32 HasHPForDamagingSetup(enum BattlerId battlerAtk, enum BattlerId battlerDef, u32 hpThreshold);

s32 AI_TryToClearStats(enum BattlerId battlerAtk, enum BattlerId battlerDef, bool32 isDoubleBattle);
bool32 AI_ShouldCopyStatChanges(enum BattlerId battlerAtk, enum BattlerId battlerDef);
bool32 AI_ShouldSetUpHazards(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, struct AiLogicData *aiData);
void IncreaseTidyUpScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 *score);
u32 IncreaseSubstituteMoveScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move);
bool32 IsBattlerItemEnabled(enum BattlerId battler);
bool32 IsBattlerPredictedToSwitch(enum BattlerId battler);
enum Move GetIncomingMove(enum BattlerId battler, enum BattlerId opposingBattler, struct AiLogicData *aiData);
enum Move GetPredictedMove(enum BattlerId battler, enum BattlerId opposingBattler, struct AiLogicData *aiData);
bool32 AI_OpponentCanFaintAiWithMod(enum BattlerId battler, u32 healAmount);
bool32 ShouldInstructPartner(enum BattlerId partner, enum Move move);
bool32 CanMoveBeBouncedBack(enum BattlerId battler, enum Move move);
bool32 AI_CanAnyStatChange(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move);
bool32 ShouldUseFusionMove(enum BattlerId battler);
bool32 ShouldUseRound(enum BattlerId battler, enum BattleMoveEffects moveEffect);
bool32 ShouldUsePledgeMove(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move);
void AI_SetBattlerTurnOrder(u8 *aiTurnOrder);

// Switching and item helpers
bool32 AiExpectsToFaintPlayer(enum BattlerId battler);

// These are for the purpose of not doubling up on moves during double battles.
// Used in GetAIEffectGroup for move effects and GetAIEffectGroupFromMove for additional effects
#define AI_EFFECT_NONE                        0
#define AI_EFFECT_WEATHER              (1 <<  0)
#define AI_EFFECT_TERRAIN              (1 <<  1)
#define AI_EFFECT_CLEAR_HAZARDS        (1 <<  2)
#define AI_EFFECT_BREAK_SCREENS        (1 <<  3)
#define AI_EFFECT_RESET_STATS          (1 <<  4)
#define AI_EFFECT_FORCE_SWITCH         (1 <<  5)
#define AI_EFFECT_TORMENT              (1 <<  6)
#define AI_EFFECT_LIGHT_SCREEN         (1 <<  7)
#define AI_EFFECT_REFLECT              (1 <<  8)
#define AI_EFFECT_GRAVITY              (1 <<  9)
#define AI_EFFECT_CHANGE_ABILITY       (1 << 10)

// As Aurora Veil should almost never be used alongside the other screens, we save the bit.
#define AI_EFFECT_AURORA_VEIL          (AI_EFFECT_LIGHT_SCREEN | AI_EFFECT_REFLECT)

#endif //GUARD_BATTLE_AI_UTIL_H
