#ifndef GUARD_BATTLE_AI_UTIL_H
#define GUARD_BATTLE_AI_UTIL_H

// for AI_WhoStrikesFirst
#define AI_IS_FASTER   0
#define AI_IS_SLOWER   1

#define FOE(battler) ((BATTLE_OPPOSITE(battler)) & BIT_SIDE)

bool32 AI_RandLessThan(u8 val);
bool32 IsAiVsAiBattle(void);
bool32 BattlerHasAi(u32 battlerId);
bool32 IsAiBattlerAware(u32 battlerId);
void ClearBattlerMoveHistory(u8 battlerId);
void RecordLastUsedMoveBy(u32 battlerId, u32 move);
void RecordKnownMove(u8 battlerId, u32 move);
void RecordAbilityBattle(u8 battlerId, u16 abilityId);
void ClearBattlerAbilityHistory(u8 battlerId);
void RecordItemEffectBattle(u8 battlerId, u8 itemEffect);
void ClearBattlerItemEffectHistory(u8 battlerId);
void SaveBattlerData(u32 battlerId);
void SetBattlerData(u32 battlerId);
void RestoreBattlerData(u32 battlerId);
u16 GetAIChosenMove(u8 battlerId);

bool32 WillAIStrikeFirst(void);
u32 GetTotalBaseStat(u32 species);
bool32 IsTruantMonVulnerable(u32 battlerAI, u32 opposingBattler);
bool32 AtMaxHp(u8 battler);
u32 GetHealthPercentage(u8 battler);
bool32 IsBattlerTrapped(u8 battler, bool8 switching);
u8 AI_WhoStrikesFirst(u8 battlerAI, u8 battler2, u16 consideredMove);
bool32 CanTargetFaintAi(u32 battlerDef, u32 battlerAtk);
bool32 CanMoveFaintBattler(u16 move, u32 battlerDef, u32 battlerAtk, u8 nHits);
bool32 CanTargetFaintAiWithMod(u32 battlerDef, u32 battlerAtk, s32 hpMod, s32 dmgMod);
s32 AI_GetAbility(u32 battlerId);
u16 AI_GetHoldEffect(u32 battlerId);
u32 AI_GetMoveAccuracy(u32 battlerAtk, u32 battlerDef, u16 move);
bool32 DoesBattlerIgnoreAbilityChecks(u16 atkAbility, u16 move);
bool32 AI_WeatherHasEffect(void);
bool32 CanAIFaintTarget(u32 battlerAtk, u32 battlerDef, u8 numHits);
bool32 CanIndexMoveFaintTarget(u32 battlerAtk, u32 battlerDef, u8 index, u8 numHits);
bool32 AI_IsTerrainAffected(u8 battlerId, u32 flags);
bool32 AI_IsBattlerGrounded(u8 battlerId);
bool32 HasDamagingMove(u8 battlerId);
bool32 HasDamagingMoveOfType(u8 battlerId, u8 type);
u32 GetBattlerSecondaryDamage(u8 battlerId);
bool32 BattlerWillFaintFromWeather(u8 battler, u16 ability);
bool32 BattlerWillFaintFromSecondaryDamage(u8 battler, u16 ability);
bool32 ShouldTryOHKO(u32 battlerAtk, u32 battlerDef, u16 atkAbility, u16 defAbility, u16 move);
bool32 ShouldUseRecoilMove(u32 battlerAtk, u32 battlerDef, u32 recoilDmg, u8 moveIndex);
u16 GetBattlerSideSpeedAverage(u8 battler);
bool32 ShouldAbsorb(u32 battlerAtk, u32 battlerDef, u16 move, s32 damage);
bool32 ShouldRecover(u32 battlerAtk, u32 battlerDef, u16 move, u8 healPercent);
bool32 ShouldSetScreen(u32 battlerAtk, u32 battlerDef, u16 moveEffect);
bool32 ShouldPivot(u32 battlerAtk, u32 battlerDef, u16 defAbility, u16 move, u8 moveIndex);
bool32 IsRecycleEncouragedItem(u16 item);
bool32 ShouldRestoreHpBerry(u32 battlerAtk, u16 item);
bool32 IsStatBoostingBerry(u16 item);
bool32 CanKnockOffItem(u8 battler, u16 item);
bool32 IsAbilityOfRating(u16 ability, s8 rating);
s8 GetAbilityRating(u16 ability);
bool32 AI_IsAbilityOnSide(u32 battlerId, u32 ability);
bool32 AI_MoveMakesContact(u32 ability, u32 holdEffect, u16 move);
u32 AI_GetBattlerMoveTargetType(u8 battlerId, u16 move);
bool32 ShouldUseZMove(u32 battlerAtk, u32 battlerDef, u16 chosenMove);

// stat stage checks
bool32 AnyStatIsRaised(u8 battlerId);
bool32 ShouldLowerStat(u8 battler, u16 battlerAbility, u8 stat);
bool32 BattlerStatCanRise(u8 battler, u16 battlerAbility, u8 stat);
bool32 AreBattlersStatsMaxed(u8 battler);
bool32 BattlerHasAnyStatRaised(u8 battlerId);
u32 CountPositiveStatStages(u8 battlerId);
u32 CountNegativeStatStages(u8 battlerId);
bool32 ShouldLowerAttack(u32 battlerAtk, u32 battlerDef, u16 defAbility);
bool32 ShouldLowerDefense(u32 battlerAtk, u32 battlerDef, u16 defAbility);
bool32 ShouldLowerSpeed(u32 battlerAtk, u32 battlerDef, u16 defAbility);
bool32 ShouldLowerSpAtk(u32 battlerAtk, u32 battlerDef, u16 defAbility);
bool32 ShouldLowerSpDef(u32 battlerAtk, u32 battlerDef, u16 defAbility);
bool32 ShouldLowerAccuracy(u32 battlerAtk, u32 battlerDef, u16 defAbility);
bool32 ShouldLowerEvasion(u32 battlerAtk, u32 battlerDef, u16 defAbility);

// move checks
bool32 IsAffectedByPowder(u8 battler, u16 ability, u16 holdEffect);
bool32 MovesWithSplitUnusable(u32 attacker, u32 target, u32 split);
s32 AI_CalcDamageSaveBattlers(u32 move, u32 battlerAtk, u32 battlerDef, u8 *typeEffectiveness, bool32 considerZPower);
s32 AI_CalcDamage(u32 move, u32 battlerAtk, u32 battlerDef, u8 *typeEffectiveness, bool32 considerZPower);
u32 GetNoOfHitsToKO(u32 dmg, s32 hp);
u8 GetMoveDamageResult(u16 move);
u32 GetCurrDamageHpPercent(u32 battlerAtk, u32 battlerDef);
uq4_12_t AI_GetTypeEffectiveness(u16 move, u32 battlerAtk, u32 battlerDef);
u32 AI_GetMoveEffectiveness(u16 move, u32 battlerAtk, u32 battlerDef);
u16 *GetMovesArray(u32 battler);
bool32 IsConfusionMoveEffect(u16 moveEffect);
bool32 HasMove(u32 battlerId, u32 move);
bool32 HasOnlyMovesWithSplit(u32 battlerId, u32 split, bool32 onlyOffensive);
bool32 HasMoveWithSplit(u32 battler, u32 split);
bool32 HasMoveWithType(u32 battler, u8 type);
bool32 HasMoveWithTypeAndSplit(u32 battler, u8 type, u8 split);
bool32 HasMoveEffect(u32 battlerId, u16 moveEffect);
bool32 HasMoveWithLowAccuracy(u32 battlerAtk, u32 battlerDef, u8 accCheck, bool32 ignoreStatus, u16 atkAbility, u16 defAbility, u16 atkHoldEffect, u16 defHoldEffect);
bool32 IsAromaVeilProtectedMove(u16 move);
bool32 IsNonVolatileStatusMoveEffect(u16 moveEffect);
bool32 IsStatLoweringMoveEffect(u16 moveEffect);
bool32 IsMoveRedirectionPrevented(u16 move, u16 atkAbility);
bool32 IsMoveEncouragedToHit(u32 battlerAtk, u32 battlerDef, u16 move);
bool32 IsHazardMoveEffect(u16 moveEffect);
bool32 MoveCallsOtherMove(u16 move);
bool32 MoveRequiresRecharging(u16 move);
bool32 IsEncoreEncouragedEffect(u16 moveEffect);
void ProtectChecks(u32 battlerAtk, u32 battlerDef, u16 move, u16 predictedMove, s16 *score);
bool32 ShouldSetSandstorm(u8 battler, u16 ability, u16 holdEffect);
bool32 ShouldSetHail(u8 battler, u16 ability, u16 holdEffect);
bool32 ShouldSetSnow(u8 battler, u16 ability, u16 holdEffect);
bool32 ShouldSetRain(u32 battlerAtk, u16 ability, u16 holdEffect);
bool32 ShouldSetSun(u32 battlerAtk, u16 atkAbility, u16 holdEffect);
bool32 HasSleepMoveWithLowAccuracy(u32 battlerAtk, u32 battlerDef);
bool32 IsHealingMoveEffect(u16 effect);
bool32 HasHealingEffect(u32 battler);
bool32 IsTrappingMoveEffect(u16 effect);
bool32 HasTrappingMoveEffect(u8 battler);
bool32 ShouldFakeOut(u32 battlerAtk, u32 battlerDef, u16 move);
bool32 HasThawingMove(u8 battler);
bool32 IsStatRaisingEffect(u16 effect);
bool32 IsStatLoweringEffect(u16 effect);
bool32 IsStatRaisingEffect(u16 effect);
bool32 IsAttackBoostMoveEffect(u16 effect);
bool32 IsUngroundingEffect(u16 effect);
bool32 IsSemiInvulnerable(u32 battlerDef, u16 move);
bool32 HasSoundMove(u8 battler);
bool32 HasHighCritRatioMove(u8 battler);
bool32 HasMagicCoatAffectedMove(u8 battler);
bool32 HasSnatchAffectedMove(u8 battler);

// status checks
bool32 AI_CanBeBurned(u8 battler, u16 ability);
bool32 AI_CanGetFrostbite(u8 battler, u16 ability);
bool32 AI_CanBeConfused(u8 battler, u16 ability);
bool32 AI_CanSleep(u8 battler, u16 ability);
bool32 IsBattlerIncapacitated(u8 battler, u16 ability);
bool32 AI_CanPutToSleep(u32 battlerAtk, u32 battlerDef, u16 defAbility, u16 move, u16 partnerMove);
bool32 ShouldPoisonSelf(u8 battler, u16 ability);
bool32 AI_CanPoison(u32 battlerAtk, u32 battlerDef, u16 defAbility, u16 move, u16 partnerMove);
bool32 AI_CanParalyze(u32 battlerAtk, u32 battlerDef, u16 defAbility, u16 move, u16 partnerMove);
bool32 AI_CanConfuse(u32 battlerAtk, u32 battlerDef, u16 defAbility, u32 battlerAtkPartner, u16 move, u16 partnerMove);
bool32 ShouldBurnSelf(u8 battler, u16 ability);
bool32 AI_CanBurn(u32 battlerAtk, u32 battlerDef, u16 defAbility, u32 battlerAtkPartner, u16 move, u16 partnerMove);
bool32 AI_CanGiveFrostbite(u32 battlerAtk, u32 battlerDef, u16 defAbility, u32 battlerAtkPartner, u16 move, u16 partnerMove);
bool32 AI_CanBeInfatuated(u32 battlerAtk, u32 battlerDef, u16 defAbility);
bool32 AnyPartyMemberStatused(u8 battlerId, bool32 checkSoundproof);
u32 ShouldTryToFlinch(u32 battlerAtk, u32 battlerDef, u16 atkAbility, u16 defAbility, u16 move);
bool32 ShouldTrap(u32 battlerAtk, u32 battlerDef, u16 move);
bool32 IsWakeupTurn(u8 battler);
bool32 AI_IsBattlerAsleepOrComatose(u8 battlerId);

// partner logic
u16 GetAllyChosenMove(u8 battlerId);
bool32 IsValidDoubleBattle(u32 battlerAtk);
bool32 IsTargetingPartner(u32 battlerAtk, u32 battlerDef);
bool32 DoesPartnerHaveSameMoveEffect(u32 battlerAtkPartner, u32 battlerDef, u16 move, u16 partnerMove);
bool32 PartnerHasSameMoveEffectWithoutTarget(u32 battlerAtkPartner, u16 move, u16 partnerMove);
bool32 PartnerMoveEffectIsStatusSameTarget(u32 battlerAtkPartner, u32 battlerDef, u16 partnerMove);
bool32 PartnerMoveEffectIsWeather(u32 battlerAtkPartner, u16 partnerMove);
bool32 PartnerMoveEffectIsTerrain(u32 battlerAtkPartner, u16 partnerMove);
bool32 PartnerMoveIs(u32 battlerAtkPartner, u16 partnerMove, u16 moveCheck);
bool32 PartnerMoveIsSameAsAttacker(u32 battlerAtkPartner, u32 battlerDef, u16 move, u16 partnerMove);
bool32 PartnerMoveIsSameNoTarget(u32 battlerAtkPartner, u16 move, u16 partnerMove);
bool32 ShouldUseWishAromatherapy(u32 battlerAtk, u32 battlerDef, u16 move);

// party logic
struct BattlePokemon *AllocSaveBattleMons(void);
void FreeRestoreBattleMons(struct BattlePokemon *savedBattleMons);
s32 AI_CalcPartyMonBestMoveDamage(u32 battlerAtk, u32 battlerDef, struct Pokemon *attackerMon, struct Pokemon *targetMon);
s32 CountUsablePartyMons(u8 battlerId);
bool32 IsPartyFullyHealedExceptBattler(u8 battler);
bool32 PartyHasMoveSplit(u8 battlerId, u8 split);
bool32 SideHasMoveSplit(u8 battlerId, u8 split);

// score increases
void IncreaseStatUpScore(u32 battlerAtk, u32 battlerDef, u8 statId, s16 *score);
void IncreasePoisonScore(u32 battlerAtk, u32 battlerDef, u16 move, s16 *score);
void IncreaseBurnScore(u32 battlerAtk, u32 battlerDef, u16 move, s16 *score);
void IncreaseParalyzeScore(u32 battlerAtk, u32 battlerDef, u16 move, s16 *score);
void IncreaseSleepScore(u32 battlerAtk, u32 battlerDef, u16 move, s16 *score);
void IncreaseConfusionScore(u32 battlerAtk, u32 battlerDef, u16 move, s16 *score);
void IncreaseFrostbiteScore(u32 battlerAtk, u32 battlerDef, u16 move, s16 *score);

#endif //GUARD_BATTLE_AI_UTIL_H
