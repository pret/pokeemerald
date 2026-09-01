#ifndef GUARD_TEST_RUNNER_H
#define GUARD_TEST_RUNNER_H

extern const bool8 gTestRunnerEnabled;
#if TESTING
extern const bool8 gTestRunnerHeadless;
#else
#define gTestRunnerHeadless FALSE
#endif
extern const bool8 gTestRunnerSkipIsFail;

#if TESTING

enum Gimmick;

void TestRunner_Battle_RecordAbilityPopUp(enum BattlerId battlerId, enum Ability ability);
void TestRunner_Battle_RecordItemPopUp(enum BattlerId battlerId, enum Item item);
void TestRunner_Battle_RecordAnimation(u32 animType, u32 animId);
void TestRunner_Battle_RecordHP(enum BattlerId battlerId, u32 oldHP, u32 newHP);
void TestRunner_Battle_RecordSubHit(enum BattlerId battlerId, u32 damage, bool32 broke);
void TestRunner_Battle_RecordExp(enum BattlerId battlerId, u32 oldExp, u32 newExp);
void TestRunner_Battle_RecordMessage(const u8 *message);
void TestRunner_Battle_RecordStatus1(enum BattlerId battlerId, u32 status1);
void TestRunner_Battle_RecordCatchChance(u32 catchChance);
void TestRunner_Battle_AfterLastTurn(void);
void TestRunner_Battle_CheckChosenMove(enum BattlerId battlerId, enum Move moveId, u32 target, enum Gimmick gimmick);
void TestRunner_Battle_CheckSwitch(enum BattlerId battlerId, u32 partyIndex);
void TestRunner_Battle_CheckAiMoveScores(enum BattlerId battlerId);
void TestRunner_Battle_AISetScore(const char *file, u32 line, enum BattlerId battlerId, u32 moveIndex, s32 score);
void TestRunner_Battle_AIAdjustScore(const char *file, u32 line, enum BattlerId battlerId, u32 moveIndex, s32 score);
void TestRunner_CheckMemory(void);

void TestRunner_Battle_CheckBattleRecordActionType(enum BattlerId battlerId, u32 recordIndex, u32 actionType);

u32 TestRunner_Battle_GetForcedAbility(enum BattleTrainer trainer, u32 partyIndex);
u32 TestRunner_Battle_GetChosenGimmick(enum BattleTrainer trainer, u32 partyIndex);
u32 TestRunner_Battle_GetForcedEnvironment(void);
void TestRunner_Battle_RecordEffectivenessSound(u32 battlerId, u32 soundId);

#else

#define TestRunner_Battle_RecordAbilityPopUp(...) (void)0
#define TestRunner_Battle_RecordItemPopUp(...) (void)0
#define TestRunner_Battle_RecordAnimation(...) (void)0
#define TestRunner_Battle_RecordHP(...) (void)0
#define TestRunner_Battle_RecordSubHit(...) (void)0
#define TestRunner_Battle_RecordExp(...) (void)0
#define TestRunner_Battle_RecordMessage(...) (void)0
#define TestRunner_Battle_RecordStatus1(...) (void)0
#define TestRunner_Battle_RecordCatchChance(...) (void)0
#define TestRunner_Battle_AfterLastTurn(...) (void)0
#define TestRunner_Battle_CheckChosenMove(...) (void)0
#define TestRunner_Battle_CheckSwitch(...) (void)0
#define TestRunner_Battle_CheckAiMoveScores(...) (void)0
#define TestRunner_Battle_AISetScore(...) (void)0
#define TestRunner_Battle_AIAdjustScore(...) (void)0
#define TestRunner_Battle_CheckBattleRecordActionType(...) (void)0
#define TestRunner_Battle_GetForcedAbility(...) (u32)0
#define TestRunner_Battle_GetChosenGimmick(...) (u32)0
#define TestRunner_Battle_RecordEffectivenessSound(...) (u32)0

#define TestRunner_Battle_GetForcedEnvironment(...) (u8)0

#endif

#endif
