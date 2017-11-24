#include "global.h"
#include "rom6.h"
#include "event_data.h"
#include "rtc.h"
#include "lottery_corner.h"
#include "dewford_trend.h"
#include "tv.h"
#include "field_screen.h"
#include "berry.h"
#include "main.h"
#include "overworld.h"
#include "wallclock.h"

// static types

// static declarations

static void sub_809E7E8(struct Time *localTime);
static void sub_809E858(struct Time *localTime);

// rodata

// text

static void sub_809E778(void)
{
    FlagSet(FLAG_SYS_CLOCK_SET);
    RtcCalcLocalTime();
    gSaveBlock2Ptr->lastBerryTreeUpdate = gLocalTime;
    VarSet(VAR_DAYS, gLocalTime.days);
}

void DoTimeBasedEvents(void)
{
    if (FlagGet(FLAG_SYS_CLOCK_SET) && !sub_813B9C0())
    {
        RtcCalcLocalTime();
        sub_809E7E8(&gLocalTime);
        sub_809E858(&gLocalTime);
    }
}

static void sub_809E7E8(struct Time *localTime)
{
    u16 *days = GetVarPointer(VAR_DAYS);
    u16 daysSince;

    if (*days != localTime->days)
    {
        if (*days <= localTime->days)
        {
            daysSince = localTime->days - *days;
            ClearUpperFlags();
            sub_8122580(daysSince);
            sub_80ED888(daysSince);
            sub_80AEFBC(daysSince);
            UpdatePartyPokerusTime(daysSince);
            sub_8137904(daysSince);
            sub_8137A20(daysSince);
            sub_8139EF4(daysSince);
            sub_813A7F4(daysSince);
            sub_813945C(daysSince);
            SetRandomLotteryNumber(daysSince);
            *days = localTime->days;
        }
    }
}

static void sub_809E858(struct Time *localTime)
{
    struct Time difference;
    int minutes;

    CalcTimeDifference(&difference, &gSaveBlock2Ptr->lastBerryTreeUpdate, localTime);
    minutes = 24 * 60 * difference.days + 60 * difference.hours + difference.minutes;
    if (minutes != 0)
    {
        if (minutes >= 0)
        {
            BerryTreeTimeUpdate(minutes);
            gSaveBlock2Ptr->lastBerryTreeUpdate = *localTime;
        }
    }
}

void sub_809E8B4(void)
{
    sub_809E778();
    SetMainCallback2(c2_exit_to_overworld_1_continue_scripts_restart_music);
}

void Special_StartWallClock(void)
{
    SetMainCallback2(Cb2_StartWallClock);
    gMain.savedCallback = sub_809E8B4;
}
