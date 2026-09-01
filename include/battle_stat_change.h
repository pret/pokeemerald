#ifndef GUARD_BATTLE_MOVE_STAT_CHANGE_H
#define GUARD_BATTLE_MOVE_STAT_CHANGE_H

#include "constants/battle_stat_change.h"

struct StatChange
{
    const u8 *script;
    const u8 *moveScript; // I'm pretty sure this is redundant at this point. Will clean up in a follow up
    struct StatStages *statStageQueue;

    enum Stat stat;
    s8 stage;
    u8 statStageAmount;

    // Flags
    u32 passiveStatChange:1;
    u32 certain:1;
    u32 setFailureFlags:1;
    u32 silentFailure:1;
    u32 onlyChecking:1;
    u32 ignoreMirrorArmored:1;
    u32 nextBattler:1;
    u32 intimidate:1;
    u32 additionalEffectTriggers:1;
    u32 itemMessage:1;
    u32 targetMissed:1;
    u32 stickyWeb:1;
    u32 ignoreCertainFailure:1; // for mirror armor and substitute
    u32 mirrorHerbActivation:1;
    u32 opportunistActivation:1;
    u32 padding:17;
};

extern enum Stat const sAccurateStatOrder[NUM_BATTLE_STATS];

bool32 CompareStat(enum BattlerId battler, enum Stat statId, u32 cmpTo, u32 cmpKind, enum Ability ability);
bool32 CanAnyStatChange(struct BattleCalcValues *cv, struct StatChange *st);
enum StatChangeResult TryStatChange(struct BattleCalcValues *cv, struct StatChange *st);
void SetStatChange(enum BattlerId battler, enum Stat stat, s32 stage);
void SetStatChange2(enum BattlerId battler, enum Stat stat, s32 stage);
void ClearStatChangeValues(void);
void ClearOtherStatChangeValues(enum BattlerId battler);
void ClearBothStatChangeQueues(void);
enum StatChangeResult TrySingleStatChange(struct BattleCalcValues *cv, struct StatChange *st);
u32 GetStatStage(enum Stat stat, const struct AdditionalEffect *additionalEffect);
bool32 ShouldDefiantCompetitiveActivate(enum BattlerId battler, enum Ability ability);
enum MoveResult DoStatChangeResolution(struct BattleCalcValues *cv);
bool32 CanStatChange(struct BattleCalcValues *cv, struct StatChange *st);
bool32 IsStatChangeStatusMove(enum Move move, bool32 (*isStatChange)(const struct AdditionalEffect *effect));
bool32 IsAtkStatUpMove(const struct AdditionalEffect *effect);
bool32 IsAtkSpAtkStatUpMove(const struct AdditionalEffect *effect);
bool32 IsDefSpDefStatUpMove(const struct AdditionalEffect *effect);
bool32 IsAccDownEvasionUpStatChangeMove(const struct AdditionalEffect *effect);

#endif // GUARD_BATTLE_MOVE_STAT_CHANGE_H
