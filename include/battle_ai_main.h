#ifndef GUARD_BATTLE_AI_MAIN_H
#define GUARD_BATTLE_AI_MAIN_H

// return vals for BattleAI_ChooseMoveOrAction
// 0 - 3 are move idx
#define AI_CHOICE_FLEE 4
#define AI_CHOICE_WATCH 5
#define AI_CHOICE_SWITCH 7

#include "test_runner.h"

// Logs for debugging AI tests.
#define SET_SCORE(battler, movesetIndex, val) \
    do \
    { \
        TestRunner_Battle_AISetScore(__FILE__, __LINE__, battler, movesetIndex, val); \
        AI_THINKING_STRUCT->score[movesetIndex] = val; \
    } while (0) \

#define ADJUST_SCORE(val) \
    do \
    { \
        TestRunner_Battle_AIAdjustScore(__FILE__, __LINE__, sBattler_AI, AI_THINKING_STRUCT->movesetIndex, val); \
        score += val; \
    } while (0) \

#define ADJUST_SCORE_PTR(val) \
    do \
    { \
        TestRunner_Battle_AIAdjustScore(__FILE__, __LINE__, sBattler_AI, AI_THINKING_STRUCT->movesetIndex, val); \
        (*score) += val; \
    } while (0) \

#define RETURN_SCORE_PLUS(val)      \
{                                   \
    ADJUST_SCORE(val);              \
    return score;                   \
}

#define RETURN_SCORE_MINUS(val)     \
{                                   \
    ADJUST_SCORE(-val);             \
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
