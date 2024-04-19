#ifndef GUARD_TEST_RUNNER_H
#define GUARD_TEST_RUNNER_H

extern const bool8 gTestRunnerEnabled;
extern const bool8 gTestRunnerHeadless;
extern const bool8 gTestRunnerSkipIsFail;

#if TESTING

void TestRunner_Battle_RecordAbilityPopUp(u32 battlerId, u32 ability);
void TestRunner_Battle_RecordAnimation(u32 animType, u32 animId);
void TestRunner_Battle_RecordHP(u32 battlerId, u32 oldHP, u32 newHP);
void TestRunner_Battle_RecordExp(u32 battlerId, u32 oldExp, u32 newExp);
void TestRunner_Battle_RecordMessage(const u8 *message);
void TestRunner_Battle_RecordStatus1(u32 battlerId, u32 status1);
void TestRunner_Battle_AfterLastTurn(void);
void TestRunner_Battle_CheckChosenMove(u32 battlerId, u32 moveId, u32 target);
void TestRunner_Battle_CheckSwitch(u32 battlerId, u32 partyIndex);
void TestRunner_Battle_CheckAiMoveScores(u32 battlerId);
void TestRunner_Battle_AISetScore(const char *file, u32 line, u32 battlerId, u32 moveIndex, s32 score);
void TestRunner_Battle_AIAdjustScore(const char *file, u32 line, u32 battlerId, u32 moveIndex, s32 score);
void TestRunner_Battle_InvalidNoHPMon(u32 battlerId, u32 partyIndex);

void TestRunner_Battle_CheckBattleRecordActionType(u32 battlerId, u32 recordIndex, u32 actionType);

u32 TestRunner_Battle_GetForcedAbility(u32 side, u32 partyIndex);

#else

#define TestRunner_Battle_RecordAbilityPopUp(...) (void)0
#define TestRunner_Battle_RecordAnimation(...) (void)0
#define TestRunner_Battle_RecordHP(...) (void)0
#define TestRunner_Battle_RecordExp(...) (void)0
#define TestRunner_Battle_RecordMessage(...) (void)0
#define TestRunner_Battle_RecordStatus1(...) (void)0
#define TestRunner_Battle_AfterLastTurn(...) (void)0
#define TestRunner_Battle_CheckChosenMove(...) (void)0
#define TestRunner_Battle_CheckSwitch(...) (void)0
#define TestRunner_Battle_CheckAiMoveScores(...) (void)0
#define TestRunner_Battle_AISetScore(...) (void)0
#define TestRunner_Battle_AIAdjustScore(...) (void)0
#define TestRunner_Battle_InvalidNoHPMon(...) (void)0

#define TestRunner_Battle_CheckBattleRecordActionType(...) (void)0

#define TestRunner_Battle_GetForcedAbility(...) (u32)0

#endif

#endif
