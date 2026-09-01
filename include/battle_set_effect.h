#ifndef GUARD_BATTLE_SET_EFFECT_H
#define GUARD_BATTLE_SET_EFFECT_H

#include "constants/battle_set_effect.h"

struct SetEffect
{
    const u8 *script;
    const struct AdditionalEffect *additionalEffect;

    enum MoveEffect moveEffect:8;
    enum BattlerId effectBattler:3;

    u16 primary:1;
    u16 certain:1;
    u16 onSide:1;
};

void SetMoveEffect(struct BattleCalcValues *cv, struct SetEffect *se);
void SetMoveEffectHelper(enum BattlerId battlerAtk, enum BattlerId effectBattler, enum MoveEffect moveEffect, const u8 *battleScript, enum SetMoveEffectFlags effectFlags);
u32 NumAffectedSpreadMoveTargets(void);

#endif // GUARD_BATTLE_SET_EFFECT_H
