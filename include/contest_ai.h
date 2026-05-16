#ifndef GUARD_CONTESTAI_H
#define GUARD_CONTESTAI_H

// AI states
enum
{
    CONTESTAI_SETTING_UP,
    CONTESTAI_PROCESSING,
    CONTESTAI_FINISHED,
    CONTESTAI_DO_NOT_PROCESS
};

void ContestAI_ResetAI(u8 contestantAI);
u8 ContestAI_GetActionToUse(void);

#endif // GUARD_CONTESTAI_H
