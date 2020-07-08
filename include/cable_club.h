#ifndef GUARD_CABLE_CLUB_H
#define GUARD_CABLE_CLUB_H

#include "task.h"

void CreateTask_EnterCableClubSeat(TaskFunc taskFunc);
u8 CreateTask_ReestablishCableClubLink(void);
void CB2_ReturnFromCableClubBattle(void);
bool32 AreBattleTowerLinkSpeciesSame(u16 *speciesList1, u16 *speciesList2);
void sub_80B3AF8(u8 taskId);
void Task_WaitForLinkPlayerConnection(u8 taskId);
bool32 GetLinkTrainerCardColor(u8 linkPlayerIndex);

#endif //GUARD_CABLE_CLUB_H
