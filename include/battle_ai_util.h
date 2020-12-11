#ifndef GUARD_BATTLE_AI_UTIL_H
#define GUARD_BATTLE_AI_UTIL_H

// for IsBattlerFaster
#define AI_CHECK_FASTER   0       // if_user_faster
#define AI_CHECK_SLOWER   1       // if_target_faster

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
u8 GetMovePowerResult(u16 move);
u16 AI_GetTypeEffectiveness(u16 move, u8 battlerAtk, u8 battlerDef);
u8 GetMoveEffectiveness(u16 move);
bool32 IsBattlerFaster(u8 battler);
bool32 CanTargetFaintAi(void);
s32 AI_GetAbility(u32 battlerId, bool32 guess);

#endif //GUARD_BATTLE_AI_UTIL_H