#ifndef GUARD_BATTLE_AI_MAIN_H
#define GUARD_BATTLE_AI_MAIN_H


typedef s32 (*AiScoreFunc)(u32, u32, u32, s32);

#define UNKNOWN_NO_OF_HITS UINT32_MAX

// for AI_WhoStrikesFirst
#define AI_IS_FASTER   1
#define AI_IS_SLOWER   -1

#define BEST_DAMAGE_MOVE         1  // Move with the most amount of hits with the best accuracy/effect
#define POWERFUL_STATUS_MOVE     10 // Moves with this score will be chosen over a move that faints target
#define NO_DAMAGE_OR_FAILS      -20 // Move fails or does no damage

// Scores given in AI_CalcMoveEffectScore and AI_CalcHoldEffectMoveScore
enum AIScore
{
    NO_INCREASE = 0,
    WEAK_EFFECT = 1,
    DECENT_EFFECT = 2,
    GOOD_EFFECT = 3,
    BEST_EFFECT = 4,
    PERFECT_EFFECT = 10,
    BAD_EFFECT = -1,
    AWFUL_EFFECT = -3,
    WORST_EFFECT = -10
};

enum MoveComparisonResult
{
    MOVE_NEUTRAL_COMPARISON,
    MOVE_WON_COMPARISON,
    MOVE_LOST_COMPARISON,
};

// AI_TryToFaint
#define FAST_KILL      6 // AI is faster and faints target
#define SLOW_KILL      4 // AI is slower and faints target
#define LAST_CHANCE    2 // AI faints to target. It should try and do damage with a priority move

// AI_Risky
#define STRONG_RISKY_EFFECT     3
#define AVERAGE_RISKY_EFFECT    2

#include "test_runner.h"

// Logs for debugging AI tests.
#define SET_SCORE(battler, movesetIndex, val) \
    do \
    { \
        if (TESTING) \
        { \
            TestRunner_Battle_AISetScore(__FILE__, __LINE__, battler, movesetIndex, val); \
        } \
        gAiThinkingStruct->score[movesetIndex] = val; \
    } while (0) \

#define ADJUST_SCORE(val) \
    do \
    { \
        if (TESTING) \
        { \
            TestRunner_Battle_AIAdjustScore(__FILE__, __LINE__, battlerAtk, gAiThinkingStruct->movesetIndex, val); \
        } \
        score += val; \
    } while (0) \

#define ADJUST_AND_RETURN_SCORE(val) \
    do \
    { \
    if (TESTING) \
        { \
            TestRunner_Battle_AIAdjustScore(__FILE__, __LINE__, battlerAtk, gAiThinkingStruct->movesetIndex, val); \
        } \
        score += val; \
        return score; \
    } while (0) \

#define ADJUST_SCORE_PTR(val) \
    do \
    { \
        if (TESTING) \
        { \
            TestRunner_Battle_AIAdjustScore(__FILE__, __LINE__, battlerAtk, gAiThinkingStruct->movesetIndex, val); \
        } \
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

void BattleAI_SetupAIData(u8 defaultScoreMoves, enum BattlerId battler);
void BattleAI_SetupItems(void);
void BattleAI_SetupFlags(void);
void ComputeAiBattlerDecisions(enum BattlerId battler);
u32 BattleAI_ChooseMoveIndex(enum BattlerId battler);
void Ai_InitPartyStruct(void);
void Ai_UpdateSwitchInData(enum BattlerId battler);
void Ai_UpdateFaintData(enum BattlerId battler);
void SetAiLogicDataForTurn(struct AiLogicData *aiData);
void ResetDynamicAiFunctions(void);
void AI_TrySwitchOrUseItem(enum BattlerId battler);
void CalcBattlerAiMovesData(struct AiLogicData *aiData, enum BattlerId battlerAtk, enum BattlerId battlerDef, u32 weather, enum BattleTerrain terrain);
void AIDebugTimerStart(void);
void AIDebugTimerEnd(void);

#endif // GUARD_BATTLE_AI_MAIN_H
