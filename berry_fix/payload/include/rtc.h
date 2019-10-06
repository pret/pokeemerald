#ifndef GUARD_RTC_H
#define GUARD_RTC_H

#include "gba/gba.h"
#include "siirtc.h"
#include "global.h"

extern struct Time gTimeSinceBerryUpdate;
extern struct Time gRtcUTCTime;

bool32 rtc_maincb_is_rtc_working(void);
bool32 rtc_maincb_is_time_since_last_berry_update_positive(u8 *);
void rtc_maincb_fix_date(void);

#endif //GUARD_RTC_H
