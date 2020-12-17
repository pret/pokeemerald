#ifndef GUARD_BATTLE_AI_UTIL_H
#define GUARD_BATTLE_AI_UTIL_H

// for IsBattlerFaster
#define AI_CHECK_FASTER   0       // if_user_faster
#define AI_CHECK_SLOWER   1       // if_target_faster

#define FOE(battler) ((battler ^ BIT_SIDE) & BIT_SIDE)

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

u32 GetHealthPercentage(u8 battler);
bool32 IsBattlerTrapped(u8 battler, bool8 switching);
bool32 IsBattlerFaster(u8 battler);
bool32 CanTargetFaintAi(u8 battlerDef, u8 battlerAtk);
bool32 CanTargetFaintAiWithMod(u8 battlerDef, u8 battlerAtk, s32 hpMod, s32 dmgMod);
s32 AI_GetAbility(u32 battlerId);
u16 AI_GetHoldEffect(u32 battlerId);
u32 AI_GetMoveAccuracy(u8 battlerAtk, u8 battlerDef, u16 atkAbility, u16 defAbility, u8 atkHoldEffect, u8 defHoldEffect, u16 move);
bool32 DoesBattlerIgnoreAbilityChecks(u16 atkAbility, u16 move);
bool32 AI_WeatherHasEffect(void);
bool32 CanAttackerFaintTarget(u8 battlerAtk, u8 battlerDef, u8 index);
bool32 AI_IsBattlerGrounded(u8 battlerId);
bool32 BattlerHasDamagingMove(u8 battlerId);
bool32 BattlerHasSecondaryDamage(u8 battlerId);
bool32 BattlerWillFaintFromWeather(u8 battler, u16 ability);
bool32 ShouldTryOHKO(u8 battlerAtk, u8 battlerDef, u16 atkAbility, u16 defAbility, u32 accuracy, u16 move);
bool32 ShouldUseRecoilMove(u8 battlerAtk, u8 battlerDef, u32 recoilDmg, u8 moveIndex);
u16 GetBattlerSideSpeedAverage(u8 battler);
bool32 ShouldRecover(u8 battlerAtk, u8 battlerDef, u16 move, s32 damage);

// stat stage checks
bool32 AnyStatIsRaised(u8 battlerId);
bool32 BattlerStatCanFall(u8 battler, u16 battlerAbility, u8 stat);
bool32 BattlerStatCanRise(u8 battler, u16 battlerAbility, u8 stat);
bool32 AreBattlersStatsMaxed(u8 battler);
bool32 BattlerHasAnyStatRaised(u8 battlerId);
u32 CountPositiveStatStages(u8 battlerId);
u32 CountNegativeStatStages(u8 battlerId);
bool32 BattlerShouldRaiseAttacks(u8 battlerId, u16 ability);
bool32 ShouldLowerAttack(u8 battlerAtk, u8 battlerDef, u16 defAbility, u8 moveIndex);

// move checks
bool32 MovesWithSplitUnusable(u32 attacker, u32 target, u32 split);
s32 AI_CalcDamage(u16 move, u8 battlerAtk, u8 battlerDef);
u8 GetMoveDamageResult(u16 move);
u16 AI_GetTypeEffectiveness(u16 move, u8 battlerAtk, u8 battlerDef);
u8 AI_GetMoveEffectiveness(u16 move);
u16 *GetMovesArray(u32 battler);
bool32 IsConfusionMoveEffect(u16 moveEffect);
bool32 HasMoveWithSplit(u32 battler, u32 split);
bool32 HasMoveWithType(u32 battler, u8 type);
bool32 HasMoveEffect(u32 battlerId, u16 moveEffect);
bool32 HasMoveWithLowAccuracy(u8, u8, u8, bool32, u16, u16, u16, u16, u16);
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

// status checks
bool32 AI_CanPutToSleep(u8 battlerAtk, u8 battlerDef, u16 defAbility, u16 move, u16 partnerMove);
bool32 AI_CanPoison(u8 battlerAtk, u8 battlerDef, u16 defAbility, u16 move, u16 partnerMove);
bool32 AI_CanParalyze(u8 battlerAtk, u8 battlerDef, u16 defAbility, u16 move, u16 partnerMove);
bool32 AI_CanConfuse(u8 battlerAtk, u8 battlerDef, u16 defAbility, u8 battlerAtkPartner, u16 move, u16 partnerMove);
bool32 AI_CanBurn(u8 battlerAtk, u8 battlerDef, u16 defAbility, u8 battlerAtkPartner, u16 move, u16 partnerMove);
bool32 AI_CanBeInfatuated(u8 battlerAtk, u8 battlerDef, u16 defAbility, u8 atkGender, u8 defGender);
bool32 AnyPartyMemberStatused(u8 battlerId, bool32 checkSoundproof);

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

// party logic
s32 AI_CalcPartyMonDamage(u16 move, u8 battlerAtk, u8 battlerDef, struct Pokemon *mon);
s32 CountUsablePartyMons(u8 battlerId);
bool32 IsPartyFullyHealedExceptBattler(u8 battler);

#endif //GUARD_BATTLE_AI_UTIL_H