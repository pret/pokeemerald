#ifndef GUARD_RTC_UTIL_H
#define GUARD_RTC_UTIL_H

#include "siirtc.h"

#define RTC_INIT_ERROR         0x0001
#define RTC_INIT_WARNING       0x0002

#define RTC_ERR_12HOUR_CLOCK   0x0010
#define RTC_ERR_POWER_FAILURE  0x0020
#define RTC_ERR_INVALID_YEAR   0x0040
#define RTC_ERR_INVALID_MONTH  0x0080
#define RTC_ERR_INVALID_DAY    0x0100
#define RTC_ERR_INVALID_HOUR   0x0200
#define RTC_ERR_INVALID_MINUTE 0x0400
#define RTC_ERR_INVALID_SECOND 0x0800

#define RTC_ERR_FLAG_MASK      0x0FF0

//Morning and evening don't exist in Gen 3
#if OW_TIMES_OF_DAY == GEN_3
    #define MORNING_HOUR_BEGIN 0
    #define MORNING_HOUR_END   0

    #define DAY_HOUR_BEGIN     12
    #define DAY_HOUR_END       HOURS_PER_DAY

    #define EVENING_HOUR_BEGIN 0
    #define EVENING_HOUR_END   0

    #define NIGHT_HOUR_BEGIN   0
    #define NIGHT_HOUR_END     12
//Evening doesn't exist in Gen 4
#elif OW_TIMES_OF_DAY == GEN_4
    #define MORNING_HOUR_BEGIN 4
    #define MORNING_HOUR_END   10

    #define DAY_HOUR_BEGIN     10
    #define DAY_HOUR_END       20

    #define EVENING_HOUR_BEGIN 0
    #define EVENING_HOUR_END   0

    #define NIGHT_HOUR_BEGIN   20
    #define NIGHT_HOUR_END     4
//Gen 5 currently not included as the seasons change the times of day
#elif OW_TIMES_OF_DAY <= GEN_6
    #define MORNING_HOUR_BEGIN 4
    #define MORNING_HOUR_END   11

    #define DAY_HOUR_BEGIN     11
    #define DAY_HOUR_END       18

    #define EVENING_HOUR_BEGIN 18
    #define EVENING_HOUR_END   21

    #define NIGHT_HOUR_BEGIN   21
    #define NIGHT_HOUR_END     4
//These are the Sun/Ultra Sun times
#elif OW_TIMES_OF_DAY == GEN_7
    #define MORNING_HOUR_BEGIN 6
    #define MORNING_HOUR_END   10

    #define DAY_HOUR_BEGIN     10
    #define DAY_HOUR_END       17

    #define EVENING_HOUR_BEGIN 17
    #define EVENING_HOUR_END   18

    #define NIGHT_HOUR_BEGIN   18
    #define NIGHT_HOUR_END     6
#elif OW_TIMES_OF_DAY >= GEN_8
    #define MORNING_HOUR_BEGIN 6
    #define MORNING_HOUR_END   10

    #define DAY_HOUR_BEGIN     10
    #define DAY_HOUR_END       19

    #define EVENING_HOUR_BEGIN 19
    #define EVENING_HOUR_END   20

    #define NIGHT_HOUR_BEGIN   20
    #define NIGHT_HOUR_END     6
#endif

#define TIME_MORNING           0
#define TIME_DAY               1
#define TIME_EVENING           2
#define TIME_NIGHT             3

extern struct Time gLocalTime;

void RtcDisableInterrupts(void);
void RtcRestoreInterrupts(void);
u32 ConvertBcdToBinary(u8 bcd);
bool8 IsLeapYear(u32 year);
u16 ConvertDateToDayCount(u8 year, u8 month, u8 day);
u16 RtcGetDayCount(struct SiiRtcInfo *rtc);
void RtcInit(void);
u16 RtcGetErrorStatus(void);
void RtcGetInfo(struct SiiRtcInfo *rtc);
void RtcGetDateTime(struct SiiRtcInfo *rtc);
void RtcGetStatus(struct SiiRtcInfo *rtc);
void RtcGetRawInfo(struct SiiRtcInfo *rtc);
u16 RtcCheckInfo(struct SiiRtcInfo *rtc);
void RtcReset(void);
void FormatDecimalTime(u8 *dest, s32 hour, s32 minute, s32 second);
void FormatHexTime(u8 *dest, s32 hour, s32 minute, s32 second);
void FormatHexRtcTime(u8 *dest);
void FormatDecimalDate(u8 *dest, s32 year, s32 month, s32 day);
void FormatHexDate(u8 *dest, s32 year, s32 month, s32 day);
void RtcCalcTimeDifference(struct SiiRtcInfo *rtc, struct Time *result, struct Time *t);
void RtcCalcLocalTime(void);
bool8 IsBetweenHours(s32 hours, s32 begin, s32 end);
u8 GetTimeOfDay(void);
void RtcInitLocalTimeOffset(s32 hour, s32 minute);
void RtcCalcLocalTimeOffset(s32 days, s32 hours, s32 minutes, s32 seconds);
void CalcTimeDifference(struct Time *result, struct Time *t1, struct Time *t2);
u32 RtcGetMinuteCount(void);
u32 RtcGetLocalDayCount(void);

#endif // GUARD_RTC_UTIL_H
