#ifndef GUARD_DATETIME_H
#define GUARD_DATETIME_H

#include "global.h"
#include "siirtc.h"

struct DateTime
{
    u16 year;
    enum Month month;
    u8 day;
    enum Weekday dayOfWeek;
    u8 hour;
    u8 minute;
    u8 second;
};

extern const struct DateTime gGen3Epoch;

void ConvertTimeToDateTime(struct DateTime *result, struct Time *timeSinceEpoch);
void DateTime_AddDays(struct DateTime *dateTime, u32 days);
void DateTime_AddHours(struct DateTime *dateTime, u32 hours);
void DateTime_AddMinutes(struct DateTime *dateTime, u32 minutes);
void DateTime_AddSeconds(struct DateTime *dateTime, u32 seconds);
void ConvertDateTimeToRtc(struct SiiRtcInfo *result, struct DateTime *dateTime);
void ConvertRtcToDateTime(struct DateTime *result, struct SiiRtcInfo *rtc);

#endif // GUARD_DATETIME_H
