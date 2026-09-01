#ifndef GUARD_BATTLE_AI_COMPUTE_H
#define GUARD_BATTLE_AI_COMPUTE_H

void RecordLastUsedMoveBy(enum BattlerId battlerId, enum Move move);
void RecordKnownMove(enum BattlerId battlerId, enum Move move);
void RecordAllMoves(enum BattlerId battler);
void RecordAbilityBattle(enum BattlerId battlerId, enum Ability abilityId);
void RecordItemEffectBattle(enum BattlerId battlerId, enum HoldEffect itemEffect);
void ClearBattlerMoveHistory(enum BattlerId battlerId);
void ClearBattlerAbilityHistory(enum BattlerId battlerId);
void ClearBattlerItemEffectHistory(enum BattlerId battlerId);

#endif // GUARD_BATTLE_AI_COMPUTE_H
