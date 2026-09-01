#include "global.h"
#include "datetime.h"
#include "rtc.h"


const struct DateTime gGen3Epoch =
{
    .year = 2000,
    .month = MONTH_JAN,
    .day = 1,
    .dayOfWeek = WEEKDAY_SAT,
    .hour = 0,
    .minute = 0,
    .second = 0,
};

void DateTime_AddDays(struct DateTime *dateTime, u32 days)
{
    while (days > 0)
    {
        u32 remainingDaysInMonth = (sNumDaysInMonths[dateTime->month - 1] + (dateTime->month == MONTH_FEB && IsLeapYear(dateTime->year)) - dateTime->day);

        if (days > remainingDaysInMonth)
        {
            dateTime->day = 1;
            dateTime->month++;
            if (dateTime->month > MONTH_DEC)
            {
                dateTime->month = MONTH_JAN;
                dateTime->year++;
            }
            days -= (remainingDaysInMonth + 1);
            dateTime->dayOfWeek = (dateTime->dayOfWeek + remainingDaysInMonth + 1) % WEEKDAY_COUNT;
        }
        else
        {
            dateTime->day += days;
            dateTime->dayOfWeek = (dateTime->dayOfWeek + days) % WEEKDAY_COUNT;
            days = 0;
        }
    }
}

void DateTime_AddHours(struct DateTime *dateTime, u32 hours)
{
    u32 days = 0;

    dateTime->hour += hours;
    while (dateTime->hour >= HOURS_PER_DAY)
    {
        days++;
        dateTime->hour -= HOURS_PER_DAY;
    }

    DateTime_AddDays(dateTime, days);
}

void DateTime_AddMinutes(struct DateTime *dateTime, u32 minutes)
{
    u32 hours = 0;

    dateTime->minute += minutes;
    while (dateTime->minute >= MINUTES_PER_HOUR)
    {
        hours++;
        dateTime->minute -= MINUTES_PER_HOUR;
    }

    DateTime_AddHours(dateTime, hours);
}

void DateTime_AddSeconds(struct DateTime *dateTime, u32 seconds)
{
    u32 minutes = 0;

    dateTime->second += seconds;
    while (dateTime->second >= SECONDS_PER_MINUTE)
    {
        minutes++;
        dateTime->second -= SECONDS_PER_MINUTE;
    }

    DateTime_AddMinutes(dateTime, minutes);
}

void ConvertDateTimeToRtc(struct SiiRtcInfo *result, struct DateTime *dateTime)
{
    result->second = dateTime->second;
    result->minute = dateTime->minute;
    result->hour = dateTime->hour;
    result->day = dateTime->day;
    result->dayOfWeek = dateTime->dayOfWeek;
    result->month = dateTime->month;
    result->year = dateTime->year - gGen3Epoch.year;
}

void ConvertRtcToDateTime(struct DateTime *result, struct SiiRtcInfo *rtc)
{
    result->second = rtc->second;
    result->minute = rtc->minute;
    result->hour = rtc->hour;
    result->day = rtc->day;
    result->dayOfWeek = rtc->dayOfWeek;
    result->month = rtc->month;
    result->year = gGen3Epoch.year + rtc->year;
}

void ConvertTimeToDateTime(struct DateTime *result, struct Time *timeSinceEpoch)
{
    result = memcpy(result, &gGen3Epoch, sizeof(struct DateTime));
    DateTime_AddSeconds(result, timeSinceEpoch->seconds);
    DateTime_AddMinutes(result, timeSinceEpoch->minutes);
    DateTime_AddHours(result, timeSinceEpoch->hours);
    DateTime_AddDays(result, timeSinceEpoch->days);
}
