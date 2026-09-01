#ifndef GUARD_BATTLE_ARENA_H
#define GUARD_BATTLE_ARENA_H

#include "constants/battle_arena.h"

void CallBattleArenaFunction(void);
u8 BattleArena_ShowJudgmentWindow(u8 *state);
void BattleArena_InitPoints(void);
void BattleArena_AddMindPoints(enum BattlerId battler);
void BattleArena_AddSkillPoints(enum BattlerId battlerAtk);
void BattleArena_DeductSkillPoints(enum BattlerId battler, enum StringID stringId);
void DrawArenaRefereeTextBox(void);
void EraseArenaRefereeTextBox(void);

#endif //GUARD_BATTLE_ARENA_H
