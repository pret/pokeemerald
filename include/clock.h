#ifndef GUARD_CLOCK_H
#define GUARD_CLOCK_H

// TODO: time of day and seconds in a day defines

void InitTimeBasedEvents(void);
void DoTimeBasedEvents(void);
void FormChangeTimeUpdate();
void UpdateDailySeed(void);
void DoDailyEvents(u32 daysSince); //Should only be called outside of clock.c for debug purposes

#endif // GUARD_CLOCK_H
