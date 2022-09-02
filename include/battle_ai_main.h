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

u8 ComputeBattleAiScores(u8 battler);
void BattleAI_SetupItems(void);
void BattleAI_SetupFlags(void);
void BattleAI_SetupAIData(u8 defaultScoreMoves);
u8 BattleAI_ChooseMoveOrAction(void);
void GetAiLogicData(void);

extern u8 sBattler_AI;

#endif // GUARD_BATTLE_AI_MAIN_H
