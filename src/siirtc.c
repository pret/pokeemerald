// Ruby/Sapphire/Emerald cartridges contain a Seiko Instruments Inc. (SII)
// S-3511A real-time clock (RTC). This library ("SIIRTC_V001") is for
// communicating with the RTC.

#include "gba/gba.h"
#include "siirtc.h"

#define STATUS_INTFE  0x02 // frequency interrupt enable
#define STATUS_INTME  0x08 // per-minute interrupt enable
#define STATUS_INTAE  0x20 // alarm interrupt enable
#define STATUS_24HOUR 0x40 // 0: 12-hour mode, 1: 24-hour mode
#define STATUS_POWER  0x80 // power on or power failure occurred

#define TEST_MODE 0x80 // flag in the "second" byte

#define ALARM_AM 0x00
#define ALARM_PM 0x80

#define OFFSET_YEAR         offsetof(struct SiiRtcInfo, year)
#define OFFSET_MONTH        offsetof(struct SiiRtcInfo, month)
#define OFFSET_DAY          offsetof(struct SiiRtcInfo, day)
#define OFFSET_DAY_OF_WEEK  offsetof(struct SiiRtcInfo, dayOfWeek)
#define OFFSET_HOUR         offsetof(struct SiiRtcInfo, hour)
#define OFFSET_MINUTE       offsetof(struct SiiRtcInfo, minute)
#define OFFSET_SECOND       offsetof(struct SiiRtcInfo, second)
#define OFFSET_STATUS       offsetof(struct SiiRtcInfo, status)
#define OFFSET_ALARM_HOUR   offsetof(struct SiiRtcInfo, alarmHour)
#define OFFSET_ALARM_MINUTE offsetof(struct SiiRtcInfo, alarmMinute)

#define INFO_BUF(info, index) (*((u8 *)(info) + (index)))

#define DATETIME_BUF(info, index) INFO_BUF(info, OFFSET_YEAR + index)
#define DATETIME_BUF_LEN (OFFSET_SECOND - OFFSET_YEAR + 1)

#define TIME_BUF(info, index) INFO_BUF(info, OFFSET_HOUR + index)
#define TIME_BUF_LEN (OFFSET_SECOND - OFFSET_HOUR + 1)

#define WR 0 // command for writing data
#define RD 1 // command for reading data

#define CMD(n) (0x60 | (n << 1))

#define CMD_RESET    CMD(0)
#define CMD_STATUS   CMD(1)
#define CMD_DATETIME CMD(2)
#define CMD_TIME     CMD(3)
#define CMD_ALARM    CMD(4)

#define SCK_HI      1
#define SIO_HI      2
#define CS_HI       4

#define DIR_0_IN    0
#define DIR_0_OUT   1
#define DIR_1_IN    0
#define DIR_1_OUT   2
#define DIR_2_IN    0
#define DIR_2_OUT   4
#define DIR_ALL_IN  (DIR_0_IN | DIR_1_IN | DIR_2_IN)
#define DIR_ALL_OUT (DIR_0_OUT | DIR_1_OUT | DIR_2_OUT)

#define GPIO_PORT_DATA        (*(vu16 *)0x80000C4)
#define GPIO_PORT_DIRECTION   (*(vu16 *)0x80000C6)
#define GPIO_PORT_READ_ENABLE (*(vu16 *)0x80000C8)

extern vu16 GPIOPortDirection;

static u16 sDummy; // unused variable
static bool8 sLocked;

static int WriteCommand(u8 value);
static int WriteData(u8 value);
static u8 ReadData();

static void EnableGpioPortRead();
static void DisableGpioPortRead();

static const char AgbLibRtcVersion[] = "SIIRTC_V001";

void SiiRtcUnprotect(void)
{
    EnableGpioPortRead();
    sLocked = FALSE;
}

void SiiRtcProtect(void)
{
    DisableGpioPortRead();
    sLocked = TRUE;
}

u8 SiiRtcProbe(void)
{
    u8 errorCode;
    struct SiiRtcInfo rtc;

    if (!SiiRtcGetStatus(&rtc))
        return 0;

    errorCode = 0;

#ifdef BUGFIX
    if (!(rtc.status & SIIRTCINFO_24HOUR) || (rtc.status & SIIRTCINFO_POWER))
#else
    if ((rtc.status & (SIIRTCINFO_POWER | SIIRTCINFO_24HOUR)) == SIIRTCINFO_POWER
     || (rtc.status & (SIIRTCINFO_POWER | SIIRTCINFO_24HOUR)) == 0)
#endif
    {
        // The RTC is in 12-hour mode. Reset it and switch to 24-hour mode.

        // Note that the conditions are redundant and equivalent to simply
        // "(rtc.status & SIIRTCINFO_24HOUR) == 0". It's possible that this
        // was also intended to handle resetting the clock after power failure
        // but a mistake was made.

        if (!SiiRtcReset())
            return 0;

        errorCode++;
    }

    SiiRtcGetTime(&rtc);

    if (rtc.second & TEST_MODE)
    {
        // The RTC is in test mode. Reset it to leave test mode.

        if (!SiiRtcReset())
            return (errorCode << 4) & 0xF0;

        errorCode++;
    }

    return (errorCode << 4) | 1;
}

bool8 SiiRtcReset(void)
{
    bool8 result;
    struct SiiRtcInfo rtc;

    if (sLocked == TRUE)
        return FALSE;

    sLocked = TRUE;

    GPIO_PORT_DATA = SCK_HI;
    GPIO_PORT_DATA = SCK_HI | CS_HI;

    GPIO_PORT_DIRECTION = DIR_ALL_OUT;

    WriteCommand(CMD_RESET | WR);

    GPIO_PORT_DATA = SCK_HI;
    GPIO_PORT_DATA = SCK_HI;

    sLocked = FALSE;

    rtc.status = SIIRTCINFO_24HOUR;

    result = SiiRtcSetStatus(&rtc);

    return result;
}

bool8 SiiRtcGetStatus(struct SiiRtcInfo *rtc)
{
    u8 statusData;

    if (sLocked == TRUE)
        return FALSE;

    sLocked = TRUE;

    GPIO_PORT_DATA = SCK_HI;
    GPIO_PORT_DATA = SCK_HI | CS_HI;

    GPIO_PORT_DIRECTION = DIR_ALL_OUT;

    WriteCommand(CMD_STATUS | RD);

    GPIO_PORT_DIRECTION = DIR_0_OUT | DIR_1_IN | DIR_2_OUT;

    statusData = ReadData();

    rtc->status = (statusData & (STATUS_POWER | STATUS_24HOUR))
                | ((statusData & STATUS_INTAE) >> 3)
                | ((statusData & STATUS_INTME) >> 2)
                | ((statusData & STATUS_INTFE) >> 1);

    GPIO_PORT_DATA = SCK_HI;
    GPIO_PORT_DATA = SCK_HI;

    sLocked = FALSE;

    return TRUE;
}

bool8 SiiRtcSetStatus(struct SiiRtcInfo *rtc)
{
    u8 statusData;

    if (sLocked == TRUE)
        return FALSE;

    sLocked = TRUE;

    GPIO_PORT_DATA = SCK_HI;
    GPIO_PORT_DATA = SCK_HI | CS_HI;

    statusData = STATUS_24HOUR
               | ((rtc->status & SIIRTCINFO_INTAE) << 3)
               | ((rtc->status & SIIRTCINFO_INTME) << 2)
               | ((rtc->status & SIIRTCINFO_INTFE) << 1);

    GPIO_PORT_DIRECTION = DIR_ALL_OUT;

    WriteCommand(CMD_STATUS | WR);

    WriteData(statusData);

    GPIO_PORT_DATA = SCK_HI;
    GPIO_PORT_DATA = SCK_HI;

    sLocked = FALSE;

    return TRUE;
}

bool8 SiiRtcGetDateTime(struct SiiRtcInfo *rtc)
{
    u8 i;

    if (sLocked == TRUE)
        return FALSE;

    sLocked = TRUE;

    GPIO_PORT_DATA = SCK_HI;
    GPIO_PORT_DATA = SCK_HI | CS_HI;

    GPIO_PORT_DIRECTION = DIR_ALL_OUT;

    WriteCommand(CMD_DATETIME | RD);

    GPIO_PORT_DIRECTION = DIR_0_OUT | DIR_1_IN | DIR_2_OUT;

    for (i = 0; i < DATETIME_BUF_LEN; i++)
        DATETIME_BUF(rtc, i) = ReadData();

    INFO_BUF(rtc, OFFSET_HOUR) &= 0x7F;

    GPIO_PORT_DATA = SCK_HI;
    GPIO_PORT_DATA = SCK_HI;

    sLocked = FALSE;

    return TRUE;
}

bool8 SiiRtcSetDateTime(struct SiiRtcInfo *rtc)
{
    u8 i;

    if (sLocked == TRUE)
        return FALSE;

    sLocked = TRUE;

    GPIO_PORT_DATA = SCK_HI;
    GPIO_PORT_DATA = SCK_HI | CS_HI;

    GPIO_PORT_DIRECTION = DIR_ALL_OUT;

    WriteCommand(CMD_DATETIME | WR);

    for (i = 0; i < DATETIME_BUF_LEN; i++)
        WriteData(DATETIME_BUF(rtc, i));

    GPIO_PORT_DATA = SCK_HI;
    GPIO_PORT_DATA = SCK_HI;

    sLocked = FALSE;

    return TRUE;
}

bool8 SiiRtcGetTime(struct SiiRtcInfo *rtc)
{
    u8 i;

    if (sLocked == TRUE)
        return FALSE;

    sLocked = TRUE;

    GPIO_PORT_DATA = SCK_HI;
    GPIO_PORT_DATA = SCK_HI | CS_HI;

    GPIO_PORT_DIRECTION = DIR_ALL_OUT;

    WriteCommand(CMD_TIME | RD);

    GPIO_PORT_DIRECTION = DIR_0_OUT | DIR_1_IN | DIR_2_OUT;

    for (i = 0; i < TIME_BUF_LEN; i++)
        TIME_BUF(rtc, i) = ReadData();

    INFO_BUF(rtc, OFFSET_HOUR) &= 0x7F;

    GPIO_PORT_DATA = SCK_HI;
    GPIO_PORT_DATA = SCK_HI;

    sLocked = FALSE;

    return TRUE;
}

bool8 SiiRtcSetTime(struct SiiRtcInfo *rtc)
{
    u8 i;

    if (sLocked == TRUE)
        return FALSE;

    sLocked = TRUE;

    GPIO_PORT_DATA = SCK_HI;
    GPIO_PORT_DATA = SCK_HI | CS_HI;

    GPIO_PORT_DIRECTION = DIR_ALL_OUT;

    WriteCommand(CMD_TIME | WR);

    for (i = 0; i < TIME_BUF_LEN; i++)
        WriteData(TIME_BUF(rtc, i));

    GPIO_PORT_DATA = SCK_HI;
    GPIO_PORT_DATA = SCK_HI;

    sLocked = FALSE;

    return TRUE;
}

bool8 SiiRtcSetAlarm(struct SiiRtcInfo *rtc)
{
    u8 i;
    u8 alarmData[2];

    if (sLocked == TRUE)
        return FALSE;

    sLocked = TRUE;

    // Decode BCD.
    alarmData[0] = (rtc->alarmHour & 0xF) + 10 * ((rtc->alarmHour >> 4) & 0xF);

    // The AM/PM flag must be set correctly even in 24-hour mode.

    if (alarmData[0] < 12)
        alarmData[0] = rtc->alarmHour | ALARM_AM;
    else
        alarmData[0] = rtc->alarmHour | ALARM_PM;

    alarmData[1] = rtc->alarmMinute;

    GPIO_PORT_DATA = SCK_HI;
    GPIO_PORT_DATA = SCK_HI | CS_HI;

    GPIOPortDirection = DIR_ALL_OUT; // Why is this the only instance that uses a symbol?

    WriteCommand(CMD_ALARM | WR);

    for (i = 0; i < 2; i++)
        WriteData(alarmData[i]);

    GPIO_PORT_DATA = SCK_HI;
    GPIO_PORT_DATA = SCK_HI;

    sLocked = FALSE;

    return TRUE;
}

static int WriteCommand(u8 value)
{
    u8 i;
    u8 temp;

    for (i = 0; i < 8; i++)
    {
        temp = ((value >> (7 - i)) & 1);
        GPIO_PORT_DATA = (temp << 1) | CS_HI;
        GPIO_PORT_DATA = (temp << 1) | CS_HI;
        GPIO_PORT_DATA = (temp << 1) | CS_HI;
        GPIO_PORT_DATA = (temp << 1) | SCK_HI | CS_HI;
    }

    // Nothing uses the returned value from this function,
    // so the undefined behavior is harmless in the vanilla game.
#ifdef UBFIX
    return 0;
#endif
}

static int WriteData(u8 value)
{
    u8 i;
    u8 temp;

    for (i = 0; i < 8; i++)
    {
        temp = ((value >> i) & 1);
        GPIO_PORT_DATA = (temp << 1) | CS_HI;
        GPIO_PORT_DATA = (temp << 1) | CS_HI;
        GPIO_PORT_DATA = (temp << 1) | CS_HI;
        GPIO_PORT_DATA = (temp << 1) | SCK_HI | CS_HI;
    }

    // Nothing uses the returned value from this function,
    // so the undefined behavior is harmless in the vanilla game.
#ifdef UBFIX
    return 0;
#endif
}

static u8 ReadData()
{
    u8 i;
    u8 temp;
    u8 value;

#ifdef UBFIX
    value = 0;
#endif

    for (i = 0; i < 8; i++)
    {
        GPIO_PORT_DATA = CS_HI;
        GPIO_PORT_DATA = CS_HI;
        GPIO_PORT_DATA = CS_HI;
        GPIO_PORT_DATA = CS_HI;
        GPIO_PORT_DATA = CS_HI;
        GPIO_PORT_DATA = SCK_HI | CS_HI;

        temp = ((GPIO_PORT_DATA & SIO_HI) >> 1);
        value = (value >> 1) | (temp << 7);
    }

    return value;
}

static void EnableGpioPortRead()
{
    GPIO_PORT_READ_ENABLE = TRUE;
}

static void DisableGpioPortRead()
{
    GPIO_PORT_READ_ENABLE = FALSE;
}
