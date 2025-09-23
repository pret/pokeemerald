#ifndef GUARD_BATTLE_AI_SCRIPT_COMMANDS_H
#define GUARD_BATTLE_AI_SCRIPT_COMMANDS_H

// return values for BattleAI_ChooseMoveOrAction
// 0 - 3 are move idx
#define AI_CHOICE_FLEE 4
#define AI_CHOICE_WATCH 5

void BattleAI_HandleItemUseBeforeAISetup(u8 defaultScoreMoves);
void BattleAI_SetupAIData(u8 defaultScoreMoves);
u8 BattleAI_ChooseMoveOrAction(void);
void ClearBattlerMoveHistory(u8 battler);
void RecordAbilityBattle(u8 battler, u8 abilityId);
void ClearBattlerAbilityHistory(u8 battler);
void RecordItemEffectBattle(u8 battler, u8 itemEffect);
void ClearBattlerItemEffectHistory(u8 battler);

#endif // GUARD_BATTLE_AI_SCRIPT_COMMANDS_H
