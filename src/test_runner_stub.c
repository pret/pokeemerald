#include "global.h"
#include "test_runner.h"

__attribute__((weak))
const bool8 gTestRunnerEnabled = FALSE;

// The Makefile patches gTestRunnerHeadless as part of make test.
// This allows us to open the ROM in an mgba with a UI and see the
// animations and messages play, which helps when debugging a test.
const bool8 gTestRunnerHeadless = FALSE;
const bool8 gTestRunnerSkipIsFail = FALSE;

__attribute__((weak))
void TestRunner_Battle_RecordAbilityPopUp(u32 battlerId, u32 ability)
{
}

__attribute__((weak))
void TestRunner_Battle_RecordAnimation(u32 animType, u32 animId)
{
}

__attribute__((weak))
void TestRunner_Battle_RecordHP(u32 battlerId, u32 oldHP, u32 newHP)
{
}

__attribute__((weak))
void TestRunner_Battle_RecordMessage(const u8 *string)
{
}

__attribute__((weak))
void TestRunner_Battle_RecordStatus1(u32 battlerId, u32 status1)
{
}

__attribute__((weak))
void TestRunner_Battle_AfterLastTurn(void)
{
}

__attribute__((weak))
void BattleTest_CheckBattleRecordActionType(u32 battlerId, u32 recordIndex, u32 actionType)
{
}
