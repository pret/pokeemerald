#include "global.h"
#include "main.h"
#include "international_string_util.h"
#include "link.h"
#include "menu.h"
#include "task.h"
#include "string_util.h"
#include "strings.h"

extern void sub_80B2634(u8 taskId);
extern void sub_80B2CEC(u8 taskId);
extern void sub_80B2D2C(u8 taskId);

void sub_80B236C(u8 arg0, u8 arg1)
{
    if (FindTaskIdByFunc(sub_80B2634) == 0xFF)
    {
        u8 taskId1;

        taskId1 = CreateTask(sub_80B2634, 80);
        gTasks[taskId1].data[1] = arg0;
        gTasks[taskId1].data[2] = arg1;
    }
}

void sub_80B23B0(u16 windowId, u32 value)
{
    u8 xPos;

    ConvertIntToDecimalStringN(gStringVar1, value, STR_CONV_MODE_LEFT_ALIGN, 1);
    SetStandardWindowBorderStyle(windowId, 0);
    StringExpandPlaceholders(gStringVar4, gText_XPLink);
    xPos = GetStringCenterAlignXOffset(1, gStringVar4, 88);
    AddTextPrinterParameterized(windowId, 1, gStringVar4, xPos, 1, 0xFF, NULL);
    CopyWindowToVram(windowId, 3);
}

void sub_80B241C(u16 windowId)
{
    sub_819746C(windowId, FALSE);
    CopyWindowToVram(windowId, 3);
}

void sub_80B243C(u8 taskId, u8 arg1)
{
    s16 *data = gTasks[taskId].data;

    if (arg1 != data[3])
    {
        if (arg1 <= 1)
            sub_80B241C(data[5]);
        else
            sub_80B23B0(data[5], arg1);
        data[3] = arg1;
    }
}

u32 sub_80B2478(u8 lower, u8 upper)
{
    int playerCount;

    switch (GetLinkPlayerDataExchangeStatusTimed(lower, upper))
    {
    case EXCHANGE_COMPLETE:
        return 1;
    case EXCHANGE_IN_PROGRESS:
        return 3;
    case EXCHANGE_STAT_4:
        return 7;
    case EXCHANGE_STAT_5:
        return 9;
    case EXCHANGE_STAT_6:
        ConvertIntToDecimalStringN(gStringVar1, GetLinkPlayerCount_2(), STR_CONV_MODE_LEFT_ALIGN, 1);
        return 4;
    case EXCHANGE_STAT_7:
        return 10;
    case EXCHANGE_TIMED_OUT:
    default:
        return 0;
    }
}

bool32 sub_80B24F8(u8 taskId)
{
    if (HasLinkErrorOccurred() == TRUE)
    {
        gTasks[taskId].func = sub_80B2D2C;
        return TRUE;
    }
    return FALSE;
}

bool32 sub_80B252C(u8 taskId)
{
    if ((gMain.newKeys & B_BUTTON)
     && IsLinkConnectionEstablished() == FALSE)
    {
        gLinkType = 0;
        gTasks[taskId].func = sub_80B2CEC;
        return TRUE;
    }
    return FALSE;
}

bool32 sub_80B2578(u8 taskId)
{
    if (IsLinkConnectionEstablished())
        SetSuppressLinkErrorMessage(TRUE);

    if (gMain.newKeys & B_BUTTON)
    {
        gLinkType = 0;
        gTasks[taskId].func = sub_80B2CEC;
        return TRUE;
    }
    return FALSE;
}

bool32 sub_80B25CC(u8 taskId)
{
    if (GetSioMultiSI() == 1)
    {
        gTasks[taskId].func = sub_80B2D2C;
        return TRUE;
    }
    return FALSE;
}

void sub_80B2600(u8 taskId)
{
    gTasks[taskId].data[0]++;
    if (gTasks[taskId].data[0] == 10)
    {
        sub_800A4D8(2);
        DestroyTask(taskId);
    }
}
