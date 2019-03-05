#ifndef GUARD_CABLE_CLUB_H
#define GUARD_CABLE_CLUB_H

#include "task.h"

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations

void sub_80B37D4(TaskFunc taskFunc);
u8 sub_80B3050(void);
void sub_80B360C(void);
bool32 sub_80B2AF4(u16 *arg0, u16 *arg1);
void sub_80B3AF8(u8 taskId);
void task00_08081A90(u8 taskId);
bool32 GetLinkTrainerCardColor(u8 linkPlayerIndex);

#endif //GUARD_CABLE_CLUB_H
