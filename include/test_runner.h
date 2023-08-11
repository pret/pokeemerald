#ifndef GUARD_TEST_RUNNER_H
#define GUARD_TEST_RUNNER_H

extern const bool8 gTestRunnerEnabled;
extern const bool8 gTestRunnerHeadless;
extern const bool8 gTestRunnerSkipIsFail;

#if TESTING

void TestRunner_Battle_RecordAbilityPopUp(u32 battlerId, u32 ability);
void TestRunner_Battle_RecordAnimation(u32 animType, u32 animId);
void TestRunner_Battle_RecordHP(u32 battlerId, u32 oldHP, u32 newHP);
void TestRunner_Battle_RecordMessage(const u8 *message);
void TestRunner_Battle_RecordStatus1(u32 battlerId, u32 status1);
void TestRunner_Battle_AfterLastTurn(void);

void TestRunner_Battle_CheckBattleRecordActionType(u32 battlerId, u32 recordIndex, u32 actionType);

u32 TestRunner_Battle_GetForcedAbility(u32 side, u32 partyIndex);

#else

#define TestRunner_Battle_RecordAbilityPopUp(...) (void)0
#define TestRunner_Battle_RecordAnimation(...) (void)0
#define TestRunner_Battle_RecordHP(...) (void)0
#define TestRunner_Battle_RecordMessage(...) (void)0
#define TestRunner_Battle_RecordStatus1(...) (void)0
#define TestRunner_Battle_AfterLastTurn(...) (void)0

#define TestRunner_Battle_CheckBattleRecordActionType(...) (void)0

#define TestRunner_Battle_GetForcedAbility(...) (u32)0

#endif

#endif
