#ifndef GUARD_BATTLE_AI_UTIL_H
#define GUARD_BATTLE_AI_UTIL_H

// for AI_WhoStrikesFirst
#define AI_IS_FASTER   0
#define AI_IS_SLOWER   1

#define FOE(battler) ((battler ^ BIT_SIDE) & BIT_SIDE)

bool32 AI_RandLessThan(u8 val);
void RecordLastUsedMoveByTarget(void);
bool32 IsBattlerAIControlled(u32 battlerId);
void ClearBattlerMoveHistory(u8 battlerId);
void RecordLastUsedMoveBy(u32 battlerId, u32 move);
void RecordKnownMove(u8 battlerId, u32 move);
void RecordAbilityBattle(u8 battlerId, u16 abilityId);
void ClearBattlerAbilityHistory(u8 battlerId);
void RecordItemEffectBattle(u8 battlerId, u8 itemEffect);
void ClearBattlerItemEffectHistory(u8 battlerId);
void SaveBattlerData(u8 battlerId);
void SetBattlerData(u8 battlerId);
void RestoreBattlerData(u8 battlerId);

bool32 WillAIStrikeFirst(void);
u32 GetTotalBaseStat(u32 species);
bool32 IsTruantMonVulnerable(u32 battlerAI, u32 opposingBattler);
bool32 AtMaxHp(u8 battler);
u32 GetHealthPercentage(u8 battler);
bool32 IsBattlerTrapped(u8 battler, bool8 switching);
u8 AI_WhoStrikesFirst(u8 battlerAI, u8 battler2);
bool32 CanTargetFaintAi(u8 battlerDef, u8 battlerAtk);
bool32 CanMoveFaintBattler(u16 move, u8 battlerDef, u8 battlerAtk, u8 nHits);
bool32 CanTargetFaintAiWithMod(u8 battlerDef, u8 battlerAtk, s32 hpMod, s32 dmgMod);
s32 AI_GetAbility(u32 battlerId);
u16 AI_GetHoldEffect(u32 battlerId);
u32 AI_GetMoveAccuracy(u8 battlerAtk, u8 battlerDef, u16 atkAbility, u16 defAbility, u8 atkHoldEffect, u8 defHoldEffect, u16 move);
bool32 DoesBattlerIgnoreAbilityChecks(u16 atkAbility, u16 move);
bool32 AI_WeatherHasEffect(void);
bool32 CanAIFaintTarget(u8 battlerAtk, u8 battlerDef, u8 numHits);
bool32 CanIndexMoveFaintTarget(u8 battlerAtk, u8 battlerDef, u8 index, u8 numHits);
bool32 AI_IsTerrainAffected(u8 battlerId, u32 flags);
bool32 AI_IsBattlerGrounded(u8 battlerId);
bool32 HasDamagingMove(u8 battlerId);
bool32 HasDamagingMoveOfType(u8 battlerId, u8 type);
u32 GetBattlerSecondaryDamage(u8 battlerId);
bool32 BattlerWillFaintFromWeather(u8 battler, u16 ability);
bool32 BattlerWillFaintFromSecondaryDamage(u8 battler, u16 ability);
bool32 ShouldTryOHKO(u8 battlerAtk, u8 battlerDef, u16 atkAbility, u16 defAbility, u32 accuracy, u16 move);
bool32 ShouldUseRecoilMove(u8 battlerAtk, u8 battlerDef, u32 recoilDmg, u8 moveIndex);
u16 GetBattlerSideSpeedAverage(u8 battler);
bool32 ShouldAbsorb(u8 battlerAtk, u8 battlerDef, u16 move, s32 damage);
bool32 ShouldRecover(u8 battlerAtk, u8 battlerDef, u16 move, u8 healPercent);
bool32 ShouldSetScreen(u8 battlerAtk, u8 battlerDef, u16 moveEffect);
bool32 ShouldPivot(u8 battlerAtk, u8 battlerDef, u16 defAbility, u16 move, u8 moveIndex);
bool32 IsRecycleEncouragedItem(u16 item);
bool32 ShouldRestoreHpBerry(u8 battlerAtk, u16 item);
bool32 IsStatBoostingBerry(u16 item);
bool32 CanKnockOffItem(u8 battler, u16 item);
bool32 IsAbilityOfRating(u16 ability, s8 rating);
s8 GetAbilityRating(u16 ability);
bool32 AI_IsAbilityOnSide(u32 battlerId, u32 ability);
bool32 AI_MoveMakesContact(u32 ability, u32 holdEffect, u16 move);

// stat stage checks
bool32 AnyStatIsRaised(u8 battlerId);
bool32 ShouldLowerStat(u8 battler, u16 battlerAbility, u8 stat);
bool32 BattlerStatCanRise(u8 battler, u16 battlerAbility, u8 stat);
bool32 AreBattlersStatsMaxed(u8 battler);
bool32 BattlerHasAnyStatRaised(u8 battlerId);
u32 CountPositiveStatStages(u8 battlerId);
u32 CountNegativeStatStages(u8 battlerId);
bool32 ShouldLowerAttack(u8 battlerAtk, u8 battlerDef, u16 defAbility);
bool32 ShouldLowerDefense(u8 battlerAtk, u8 battlerDef, u16 defAbility);
bool32 ShouldLowerSpeed(u8 battlerAtk, u8 battlerDef, u16 defAbility);
bool32 ShouldLowerSpAtk(u8 battlerAtk, u8 battlerDef, u16 defAbility);
bool32 ShouldLowerSpDef(u8 battlerAtk, u8 battlerDef, u16 defAbility);
bool32 ShouldLowerAccuracy(u8 battlerAtk, u8 battlerDef, u16 defAbility);
bool32 ShouldLowerEvasion(u8 battlerAtk, u8 battlerDef, u16 defAbility);

// move checks
bool32 IsAffectedByPowder(u8 battler, u16 ability, u16 holdEffect);
bool32 MovesWithSplitUnusable(u32 attacker, u32 target, u32 split);
s32 AI_CalcDamage(u16 move, u8 battlerAtk, u8 battlerDef);
u8 GetMoveDamageResult(u16 move);
u32 GetCurrDamageHpPercent(u8 battlerAtk, u8 battlerDef);
u16 AI_GetTypeEffectiveness(u16 move, u8 battlerAtk, u8 battlerDef);
u8 AI_GetMoveEffectiveness(u16 move, u8 battlerAtk, u8 battlerDef);
u16 *GetMovesArray(u32 battler);
bool32 IsConfusionMoveEffect(u16 moveEffect);
bool32 HasMove(u32 battlerId, u32 move);
bool32 HasOnlyMovesWithSplit(u32 battlerId, u32 split, bool32 onlyOffensive);
bool32 HasMoveWithSplit(u32 battler, u32 split);
bool32 HasMoveWithType(u32 battler, u8 type);
bool32 HasMoveWithTypeAndSplit(u32 battler, u8 type, u8 split);
bool32 HasMoveEffect(u32 battlerId, u16 moveEffect);
bool32 HasMoveWithLowAccuracy(u8, u8, u8, bool32, u16, u16, u16, u16);
bool32 TestMoveFlagsInMoveset(u8 battler, u32 flags);
bool32 IsAromaVeilProtectedMove(u16 move);
bool32 IsNonVolatileStatusMoveEffect(u16 moveEffect);
bool32 IsStatLoweringMoveEffect(u16 moveEffect);
bool32 IsMoveRedirectionPrevented(u16 move, u16 atkAbility);
bool32 IsMoveEncouragedToHit(u8 battlerAtk, u8 battlerDef, u16 move);
bool32 IsHazardMoveEffect(u16 moveEffect);
bool32 MoveCallsOtherMove(u16 move);
bool32 MoveRequiresRecharging(u16 move);
bool32 IsInstructBannedMove(u16 move);
bool32 IsEncoreEncouragedEffect(u16 moveEffect);
void ProtectChecks(u8 battlerAtk, u8 battlerDef, u16 move, u16 predictedMove, s16 *score);
bool32 ShouldSetSandstorm(u8 battler, u16 ability, u16 holdEffect);
bool32 ShouldSetHail(u8 battler, u16 ability, u16 holdEffect);
bool32 ShouldSetRain(u8 battlerAtk, u16 ability, u16 holdEffect);
bool32 ShouldSetSun(u8 battlerAtk, u16 atkAbility, u16 holdEffect);
bool32 HasSleepMoveWithLowAccuracy(u8 battlerAtk, u8 battlerDef);
bool32 IsHealingMoveEffect(u16 effect);
bool32 HasHealingEffect(u32 battler);
bool32 IsTrappingMoveEffect(u16 effect);
bool32 HasTrappingMoveEffect(u8 battler);
bool32 ShouldFakeOut(u8 battlerAtk, u8 battlerDef, u16 move);
bool32 HasThawingMove(u8 battlerId);
bool32 IsStatRaisingEffect(u16 effect);
bool32 IsStatLoweringEffect(u16 effect);
bool32 IsStatRaisingEffect(u16 effect);
bool32 IsAttackBoostMoveEffect(u16 effect);
bool32 IsUngroundingEffect(u16 effect);
bool32 IsSemiInvulnerable(u8 battlerDef, u16 move);

// status checks
bool32 AI_CanBeBurned(u8 battler, u16 ability);
bool32 AI_CanBeConfused(u8 battler, u16 ability);
bool32 AI_CanSleep(u8 battler, u16 ability);
bool32 IsBattlerIncapacitated(u8 battler, u16 ability);
bool32 AI_CanPutToSleep(u8 battlerAtk, u8 battlerDef, u16 defAbility, u16 move, u16 partnerMove);
bool32 ShouldPoisonSelf(u8 battler, u16 ability);
bool32 AI_CanPoison(u8 battlerAtk, u8 battlerDef, u16 defAbility, u16 move, u16 partnerMove);
bool32 AI_CanParalyze(u8 battlerAtk, u8 battlerDef, u16 defAbility, u16 move, u16 partnerMove);
bool32 AI_CanConfuse(u8 battlerAtk, u8 battlerDef, u16 defAbility, u8 battlerAtkPartner, u16 move, u16 partnerMove);
bool32 ShouldBurnSelf(u8 battler, u16 ability);
bool32 AI_CanBurn(u8 battlerAtk, u8 battlerDef, u16 defAbility, u8 battlerAtkPartner, u16 move, u16 partnerMove);
bool32 AI_CanBeInfatuated(u8 battlerAtk, u8 battlerDef, u16 defAbility, u8 atkGender, u8 defGender);
bool32 AnyPartyMemberStatused(u8 battlerId, bool32 checkSoundproof);
u32 ShouldTryToFlinch(u8 battlerAtk, u8 battlerDef, u16 atkAbility, u16 defAbility, u16 move);
bool32 ShouldTrap(u8 battlerAtk, u8 battlerDef, u16 move);
bool32 IsWakeupTurn(u8 battler);

// partner logic
u16 GetAllyChosenMove(void);
bool32 IsValidDoubleBattle(u8 battlerAtk);
bool32 IsTargetingPartner(u8 battlerAtk, u8 battlerDef);
bool32 DoesPartnerHaveSameMoveEffect(u8 battlerAtkPartner, u8 battlerDef, u16 move, u16 partnerMove);
bool32 PartnerHasSameMoveEffectWithoutTarget(u8 battlerAtkPartner, u16 move, u16 partnerMove);
bool32 PartnerMoveEffectIsStatusSameTarget(u8 battlerAtkPartner, u8 battlerDef, u16 partnerMove);
bool32 PartnerMoveEffectIsWeather(u8 battlerAtkPartner, u16 partnerMove);
bool32 PartnerMoveEffectIsTerrain(u8 battlerAtkPartner, u16 partnerMove);
bool32 PartnerMoveIs(u8 battlerAtkPartner, u16 partnerMove, u16 moveCheck);
bool32 PartnerMoveIsSameAsAttacker(u8 battlerAtkPartner, u8 battlerDef, u16 move, u16 partnerMove);
bool32 PartnerMoveIsSameNoTarget(u8 battlerAtkPartner, u16 move, u16 partnerMove);
bool32 ShouldUseWishAromatherapy(u8 battlerAtk, u8 battlerDef, u16 move);

// party logic
s32 AI_CalcPartyMonDamage(u16 move, u8 battlerAtk, u8 battlerDef, struct Pokemon *mon);
s32 CountUsablePartyMons(u8 battlerId);
bool32 IsPartyFullyHealedExceptBattler(u8 battler);
bool32 PartyHasMoveSplit(u8 battlerId, u8 split);
bool32 SideHasMoveSplit(u8 battlerId, u8 split);

// score increases
void IncreaseStatUpScore(u8 battlerAtk, u8 battlerDef, u8 statId, s16 *score);
void IncreasePoisonScore(u8 battlerAtk, u8 battlerdef, u16 move, s16 *score);
void IncreaseBurnScore(u8 battlerAtk, u8 battlerdef, u16 move, s16 *score);
void IncreaseParalyzeScore(u8 battlerAtk, u8 battlerDef, u16 move, s16 *score);
void IncreaseSleepScore(u8 battlerAtk, u8 battlerDef, u16 move, s16 *score);
void IncreaseConfusionScore(u8 battlerAtk, u8 battlerDef, u16 move, s16 *score);

#endif //GUARD_BATTLE_AI_UTIL_H