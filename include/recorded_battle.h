#ifndef GUARD_RECORDED_BATTLE_H
#define GUARD_RECORDED_BATTLE_H

extern u32 gRecordedBattleRngSeed;

void sub_8184DA4(u8 arg0);
void sub_8185F84(void);
void sub_8184E58(void);
u8 RecordedBattle_ReadBankAction(u8 bank);
void RecordedBattle_SetBankAction(u8 bank, u8 action);
void RecordedBattle_ClearBankAction(u8 bank, u8 bytesToClear);
void sub_8185F90(u16 arg0);
bool8 sub_8186450(void);
u8 sub_8185FAC(void);
u8 sub_8185FB8(void);
u8 MoveRecordedBattleToSaveData(void);
void sub_818603C(u8);
void sub_8185FD0(void);
void sub_8186444(void);
void sub_8185EB8(void);
u8 sub_81850DC(u8 *arg0);
u8 sub_8185F40(void);

#endif // GUARD_RECORDED_BATTLE_H
