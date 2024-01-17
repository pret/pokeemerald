#ifndef GUARD_VS_SEEKER_H
#define GUARD_VS_SEEKER_H

#include "global.h"

void Task_InitVsSeekerAndCheckForTrainersOnScreen(u8 taskId);
bool8 UpdateVsSeekerStepCounter(void);
void MapResetTrainerRematches(u16 mapGroup, u16 mapNum);
void ClearRematchMovementByTrainerId(void);
u16 GetRematchTrainerIdVSSeeker(u16 trainerId);

#define VSSEEKER_RECHARGE_STEPS 100

#endif //GUARD_VS_SEEKER_H
