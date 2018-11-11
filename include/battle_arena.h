#ifndef GUARD_BATTLE_ARENA_H
#define GUARD_BATTLE_ARENA_H

void CallBattleArenaFunction(void);
u8 BattleArena_ShowJudgmentWindow(u8 *state);
void BattleArena_InitPoints(void);
void BattleArena_AddMindPoints(u8 battler);
void BattleArena_AddSkillPoints(u8 battler);
void BattleArena_DeductMindPoints(u8 battler, u16 stringId);
void sub_81A586C(u8 battler);
void sub_81A5BF8(void);
void sub_81A5D44(void);

#endif //GUARD_BATTLE_ARENA_H
