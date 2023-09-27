#ifndef GUARD_BATTLE_AI_MAIN_H
#define GUARD_BATTLE_AI_MAIN_H

// return values for BattleAI_ChooseMoveOrAction
// 0 - 3 are move idx
#define AI_CHOICE_FLEE 4
#define AI_CHOICE_WATCH 5
#define AI_CHOICE_SWITCH 7

#define RETURN_SCORE_PLUS(val)      \
{                                   \
    score += val;                   \
    return score;                   \
}

#define RETURN_SCORE_MINUS(val)     \
{                                   \
    score -= val;                   \
    return score;                   \
}

u32 ComputeBattleAiScores(u32 battler);
void BattleAI_SetupItems(void);
void BattleAI_SetupFlags(void);
void BattleAI_SetupAIData(u8 defaultScoreMoves, u32 battler);
u32 BattleAI_ChooseMoveOrAction(void);
void Ai_InitPartyStruct(void);
void Ai_UpdateSwitchInData(u32 battler);
void Ai_UpdateFaintData(u32 battler);
void SetAiLogicDataForTurn(struct AiLogicData *aiData);

extern u8 sBattler_AI;

#endif // GUARD_BATTLE_AI_MAIN_H
