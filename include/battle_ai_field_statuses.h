#ifndef GUARD_BATTLE_AI_FIELD_STATUSES_H
#define GUARD_BATTLE_AI_FIELD_STATUSES_H

#include "battle_ai_main.h"
#include "battle_ai_util.h"

enum FieldEffectOutcome
{
    FIELD_EFFECT_POSITIVE,
    FIELD_EFFECT_NEUTRAL,
    FIELD_EFFECT_NEGATIVE,
    FIELD_EFFECT_BLOCKED,
};

bool32 WeatherChecker(enum BattlerId battler, u32 weather, enum FieldEffectOutcome desiredResult);
bool32 TerrainChecker(enum BattlerId battler, enum BattleTerrain terrain, enum FieldEffectOutcome desiredResult);
bool32 FieldStatusChecker(enum BattlerId battler, u32 fieldStatus, enum FieldEffectOutcome desiredResult);
s32 CalcWeatherScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, struct AiLogicData *aiData);

#endif //GUARD_BATTLE_AI_FIELD_STATUSES_H
