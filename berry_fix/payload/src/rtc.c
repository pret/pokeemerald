#include "gba/gba.h"
#include "siirtc.h"
#include "global.h"
#include "main.h"

struct Time gTimeSinceBerryUpdate;
struct Time gRtcUTCTime;

static u16 sRtcProbeStatus;
static struct SiiRtcInfo sRtcInfoBuffer;
static u8 sRtcProbeCode;
static u16 sImeBak;
static struct SiiRtcInfo sRtcInfoWork;

const struct SiiRtcInfo sDefaultRTC = {
    .year = 0, // 2000
    .month = 1, // January
    .day = 1, // 01
    .dayOfWeek = 0,
    .hour = 0,
    .minute = 0,
    .second = 0,
    .status = 0,
    .alarmHour = 0,
    .alarmMinute = 0
};
const s32 sDaysPerMonth[] = {
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31
};

void rtc_get_status_and_datetime(struct SiiRtcInfo *);
u16 rtc_validate_datetime(struct SiiRtcInfo *);


void rtc_intr_disable(void)
{
    sImeBak = REG_IME;
    REG_IME = 0;
}

void rtc_intr_enable(void)
{
    REG_IME = sImeBak;
}

s32 bcd_to_hex(u8 a0)
{
    if (a0 >= 0xa0 || (a0 & 0xF) >= 10)
        return 0xFF;
    return ((a0 >> 4) & 0xF) * 10 + (a0 & 0xF);
}

bool8 is_leap_year(u8 year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return TRUE;
    return FALSE;
}

u16 rtc_count_days_parameterized(u8 year, u8 month, u8 day)
{
    u16 numDays = 0;
    s32 i;
    for (i = year - 1; i > 0; i--)
    {
        numDays += 365;
        if (is_leap_year(i) == TRUE)
            numDays++;
    }
    for (i = 0; i < month - 1; i++)
        numDays += sDaysPerMonth[i];
    if (month > MONTH_FEB && is_leap_year(year) == TRUE)
        numDays++;
    numDays += day;
    return numDays;
}

u16 rtc_count_days_from_info(struct SiiRtcInfo *info)
{
    return rtc_count_days_parameterized(bcd_to_hex(info->year), bcd_to_hex(info->month), bcd_to_hex(info->day));
}

static void rtc_probe_status(void)
{
    sRtcProbeStatus = 0;
    rtc_intr_disable();
    SiiRtcUnprotect();
    sRtcProbeCode = SiiRtcProbe();
    rtc_intr_enable();
    if ((sRtcProbeCode & 0xF) != 1)
        sRtcProbeStatus = 1;
    else
    {
        if (sRtcProbeCode & 0xF0)
            sRtcProbeStatus = 2;
        else
            sRtcProbeStatus = 0;
        rtc_get_status_and_datetime(&sRtcInfoBuffer);
        sRtcProbeStatus = rtc_validate_datetime(&sRtcInfoBuffer);
    }
}

u16 rtc_get_probe_status(void)
{
    return sRtcProbeStatus;
}

void sub_020106EC(struct SiiRtcInfo * info)
{
    if (sRtcProbeStatus & 0xFF0)
        *info = sDefaultRTC;
    else
        rtc_get_status_and_datetime(info);
}

void rtc_get_datetime(struct SiiRtcInfo * info)
{
    rtc_intr_disable();
    SiiRtcGetDateTime(info);
    rtc_intr_enable();
}

void rtc_get_status(struct SiiRtcInfo * info)
{
    rtc_intr_disable();
    SiiRtcGetStatus(info);
    rtc_intr_enable();
}

void rtc_get_status_and_datetime(struct SiiRtcInfo * info)
{
    rtc_get_status(info);
    rtc_get_datetime(info);
}

u16 rtc_validate_datetime(struct SiiRtcInfo * info)
{
    s32 year, month, day;
    u16 r4 = (info->status & SIIRTCINFO_POWER) ? 0x20 : 0;
    if (!(info->status & SIIRTCINFO_24HOUR))
        r4 |= 0x10;
    year = bcd_to_hex(info->year);
    if (year == 0xFF)
        r4 |= 0x40;
    month = bcd_to_hex(info->month);
    if (month == 0xFF || month == 0 || month > 12)
        r4 |= 0x80;
    day = bcd_to_hex(info->day);
    if (day == 0xFF)
        r4 |= 0x100;
    if (month == MONTH_FEB)
    {
        if (day > is_leap_year(year) + sDaysPerMonth[1])
            r4 |= 0x100;
    }
    else
    {
        if (day > sDaysPerMonth[month - 1])
            r4 |= 0x100;
    }
    day = bcd_to_hex(info->hour);
    if (day > 24)
        r4 |= 0x200;
    day = bcd_to_hex(info->minute);
    if (day > 60)
        r4 |= 0x400;
    day = bcd_to_hex(info->second);
    if (day > 60)
        r4 |= 0x800;
    return r4;
}

void rtc_reset(void)
{
    rtc_intr_disable();
    SiiRtcReset();
    rtc_intr_enable();
}

void rtc_sub_time_from_datetime(struct SiiRtcInfo * datetime, struct Time * dest, struct Time * timediff)
{
    u16 r4 = rtc_count_days_from_info(datetime);
    dest->seconds = bcd_to_hex(datetime->second) - timediff->seconds;
    dest->minutes = bcd_to_hex(datetime->minute) - timediff->minutes;
    dest->hours = bcd_to_hex(datetime->hour) - timediff->hours;
    dest->days = r4 - timediff->days;
    if (dest->seconds < 0)
    {
        dest->seconds += 60;
        dest->minutes--;
    }
    if (dest->minutes < 0)
    {
        dest->minutes += 60;
        dest->hours--;
    }
    if (dest->hours < 0)
    {
        dest->hours += 24;
        dest->days--;
    }
}

void rtc_sub_time_from_time(struct Time * dest, struct Time * diff, struct Time * src)
{
    dest->seconds = src->seconds - diff->seconds;
    dest->minutes = src->minutes - diff->minutes;
    dest->hours = src->hours - diff->hours;
    dest->days = src->days - diff->days;
    if (dest->seconds < 0)
    {
        dest->seconds += 60;
        dest->minutes--;
    }
    if (dest->minutes < 0)
    {
        dest->minutes += 60;
        dest->hours--;
    }
    if (dest->hours < 0)
    {
        dest->hours += 24;
        dest->days--;
    }
}

bool32 rtc_maincb_is_rtc_working(void)
{
    rtc_probe_status();
    if (rtc_get_probe_status() & 0xFF0)
        return FALSE;
    return TRUE;
}

void rtc_set_datetime(struct SiiRtcInfo * info)
{
    vu16 imeBak = REG_IME;
    REG_IME = 0;
    SiiRtcSetDateTime(info);
    REG_IME = imeBak;
}

bool32 rtc_maincb_is_time_since_last_berry_update_positive(u8 * a0)
{
    rtc_get_status_and_datetime(&sRtcInfoWork);
    *a0 = bcd_to_hex(sRtcInfoWork.year);
    rtc_sub_time_from_datetime(&sRtcInfoWork, &gRtcUTCTime, LocalTimeOffset);
    rtc_sub_time_from_time(&gTimeSinceBerryUpdate, LastBerryTreeUpdate, &gRtcUTCTime);
    if (gTimeSinceBerryUpdate.days * 1440 + gTimeSinceBerryUpdate.hours * 60 + gTimeSinceBerryUpdate.minutes >= 0)
        return TRUE;
    return FALSE;
}

u32 hex_to_bcd(u8 a0)
{
    u32 r4;
    if (a0 > 99)
        return 0xFF;
    r4 = Div(a0, 10) << 4;
    r4 |= Mod(a0, 10);
    return r4;
}

void sii_rtc_inc(u8 * a0)
{
    *a0 = hex_to_bcd(bcd_to_hex(*a0) + 1);
}

void sii_rtc_inc_month(struct SiiRtcInfo * a0)
{
    sii_rtc_inc(&a0->month);
    if (bcd_to_hex(a0->month) > 12)
    {
        sii_rtc_inc(&a0->year);
        a0->month = MONTH_JAN;
    }
}

void sii_rtc_inc_day(struct SiiRtcInfo * a0)
{
    sii_rtc_inc(&a0->day);
    if (bcd_to_hex(a0->day) > sDaysPerMonth[bcd_to_hex(a0->month) - 1])
    {
        if (!is_leap_year(bcd_to_hex(a0->year)) || bcd_to_hex(a0->month) != MONTH_FEB || bcd_to_hex(a0->day) != 29)
        {
            a0->day = 1;
            sii_rtc_inc_month(a0);
        }
    }
}

bool32 rtc_is_past_feb_28_2000(struct SiiRtcInfo * a0)
{
    if (bcd_to_hex(a0->year) == 0)
    {
        if (bcd_to_hex(a0->month) == MONTH_JAN)
            return FALSE;
        if (bcd_to_hex(a0->month) > MONTH_FEB)
            return TRUE;
        if (bcd_to_hex(a0->day) == 29)
            return TRUE;
        return FALSE;
    }
    if (bcd_to_hex(a0->year) == 1)
        return TRUE;
    return FALSE;
}

void rtc_maincb_fix_date(void)
{
    rtc_get_status_and_datetime(&sRtcInfoWork);
    if (bcd_to_hex(sRtcInfoWork.year) == 0 || bcd_to_hex(sRtcInfoWork.year) == 1)
    {
        if (bcd_to_hex(sRtcInfoWork.year) == 1)
        {
            sRtcInfoWork.year = 2;
            sRtcInfoWork.month = MONTH_JAN;
            sRtcInfoWork.day = 2;
            rtc_set_datetime(&sRtcInfoWork);
        }
        else
        {
            if (rtc_is_past_feb_28_2000(&sRtcInfoWork) == TRUE)
            {
                sii_rtc_inc_day(&sRtcInfoWork);
                sii_rtc_inc(&sRtcInfoWork.year);
            }
            else
            {
                sii_rtc_inc(&sRtcInfoWork.year);
            }
            rtc_set_datetime(&sRtcInfoWork);
        }
    }
}
