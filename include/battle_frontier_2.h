#ifndef GUARD_BATTLE_FRONTIER_2_H
#define GUARD_BATTLE_FRONTIER_2_H

#define FRONTIER_BEFORE_TEXT 0
#define FRONTIER_WIN_TEXT 1
#define FRONTIER_LOSE_TEXT 2

void CopyFrontierTrainerText(u8 whichText, u16 trainerId);
void sub_81A8934(u8);
void sub_81A895C(void);
u16 sub_81A89A0(u8);
void sub_81A8AF8(void);
bool8 InBattlePike(void);
void sub_81AA078(u16*, u8);
void sub_81A4C30(void);
bool8 sub_81A6BF4(void);

#endif // GUARD_BATTLE_FRONTIER_2_H
