#ifndef GUARD_BATTLE_AI_MAIN_H
#define GUARD_BATTLE_AI_MAIN_H

#define UNKNOWN_NO_OF_HITS UINT32_MAX

// return vals for BattleAI_ChooseMoveOrAction
// 0 - 3 are move idx
#define AI_CHOICE_FLEE 4
#define AI_CHOICE_WATCH 5
#define AI_CHOICE_SWITCH 7

// for AI_WhoStrikesFirst
#define AI_IS_FASTER   1
#define AI_IS_SLOWER   -1

// for stat increasing / decreasing scores
#define STAT_CHANGE_ATK        0
#define STAT_CHANGE_DEF        1
#define STAT_CHANGE_SPEED      2
#define STAT_CHANGE_SPATK      3
#define STAT_CHANGE_SPDEF      4

#define STAT_CHANGE_ATK_2      5
#define STAT_CHANGE_DEF_2      6
#define STAT_CHANGE_SPEED_2    7
#define STAT_CHANGE_SPATK_2    8
#define STAT_CHANGE_SPDEF_2    9

#define STAT_CHANGE_ACC        10
#define STAT_CHANGE_EVASION    11

#define BEST_DAMAGE_MOVE     1  // Move with the most amount of hits with the best accuracy/effect
#define POWERFUL_STATUS_MOVE 10 // Moves with this score will be chosen over a move that faints target

// Temporary scores that are added together to determine a final score at the at of AI_CalcMoveEffectScore
#define WEAK_EFFECT      1
#define DECENT_EFFECT    2
#define GOOD_EFFECT      4
#define BEST_EFFECT      6

// AI_CalcMoveEffectScore final score
#define NOT_GOOD_ENOUGH           0 // Not worth using over a damaging move
#define GOOD_MOVE_EFFECTS         2 // Worth using over a damaging move
#define PREFERRED_MOVE_EFFECTS    3 // Worth using over a damagin move and is better then DECENT_EFFECT
#define BEST_MOVE_EFFECTS         4 // Best possible move effects. E.g. stat boosting moves that boost multiply moves

// AI_TryToFaint
#define FAST_KILL      6 // AI is faster and faints target
#define SLOW_KILL      4 // AI is slower and faints target
#define LAST_CHANCE    2 // AI faints to target. It should try and do damage with a priority move

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
