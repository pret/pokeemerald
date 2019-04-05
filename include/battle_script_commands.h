#ifndef GUARD_BATTLE_SCRIPT_COMMANDS_H
#define GUARD_BATTLE_SCRIPT_COMMANDS_H

#define WINDOW_CLEAR            0x1
#define WINDOW_x80              0x80

s32 CalcCritChanceStage(u8 battlerAtk, u8 battlerDef, u32 move, bool32 recordAbility);
u8 GetBattlerTurnOrderNum(u8 battlerId);
void SetMoveEffect(bool32 primary, u32 certain);
void BattleDestroyYesNoCursorAt(u8 cursorPosition);
void BattleCreateYesNoCursorAt(u8 cursorPosition);
void BufferMoveToLearnIntoBattleTextBuff2(void);
void HandleBattleWindow(u8 xStart, u8 yStart, u8 xEnd, u8 yEnd, u8 flags);
bool8 UproarWakeUpCheck(u8 battlerId);
bool32 DoesSubstituteBlockMove(u8 battlerAtk, u8 battlerDef, u32 move);
bool32 CanUseLastResort(u8 battlerId);
u32 IsFlowerVeilProtected(u32 battler);

extern void (* const gBattleScriptingCommandsTable[])(void);
extern const u8 gUnknown_0831C494[][4];

#endif // GUARD_BATTLE_SCRIPT_COMMANDS_H
