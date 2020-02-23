#include "global.h"
#include "menu.h"
#include "string.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "match_call.h"

static EWRAM_DATA u8 sFieldMessageBoxMode = 0;

static void textbox_fdecode_auto_and_task_add(u8*, bool32);
static void textbox_auto_and_task_add(void);

void InitFieldMessageBox(void)
{
    sFieldMessageBoxMode = 0;
    gTextFlags.canABSpeedUpPrint = 0;
    gTextFlags.useAlternateDownArrow = 0;
    gTextFlags.autoScroll = 0;
    gTextFlags.forceMidTextSpeed = 0;
}

static void sub_8098154(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
        case 0:
           LoadMessageBoxAndBorderGfx();
           task->data[0]++;
           break;
        case 1:
           DrawDialogueFrame(0, 1);
           task->data[0]++;
           break;
        case 2:
            if (RunTextPrintersAndIsPrinter0Active() != 1)
            {
                sFieldMessageBoxMode = 0;
                DestroyTask(taskId);
            }
    }
}

static void task_add_textbox(void)
{
    CreateTask(sub_8098154, 0x50);
}

static void task_del_textbox(void)
{
    u8 taskId = FindTaskIdByFunc(sub_8098154);
    if (taskId != 0xFF)
        DestroyTask(taskId);
}

bool8 ShowFieldMessage(u8 *str)
{
    if (sFieldMessageBoxMode != 0)
        return FALSE;
    textbox_fdecode_auto_and_task_add(str, 1);
    sFieldMessageBoxMode = 2;
    return TRUE;
}

void sub_8098214(u8 taskId)
{
    if (!IsMatchCallTaskActive())
    {
        sFieldMessageBoxMode = 0;
        DestroyTask(taskId);
    }
}

bool8 sub_8098238(u8 *str)
{
    if (sFieldMessageBoxMode != 0)
        return FALSE;
    StringExpandPlaceholders(gStringVar4, str);
    CreateTask(sub_8098214, 0);
    StartMatchCallFromScript(str);
    sFieldMessageBoxMode = 2;
    return TRUE;
}

bool8 ShowFieldAutoScrollMessage(u8 *str)
{
    if (sFieldMessageBoxMode != 0)
        return FALSE;
    sFieldMessageBoxMode = 3;
    textbox_fdecode_auto_and_task_add(str, 0);
    return TRUE;
}

bool8 sub_80982A0(u8 *str)
{
    sFieldMessageBoxMode = 3;
    textbox_fdecode_auto_and_task_add(str, 1);
    return TRUE;
}

bool8 sub_80982B8(void)
{
    if (sFieldMessageBoxMode != 0)
        return FALSE;
    sFieldMessageBoxMode = 2;
    textbox_auto_and_task_add();
    return TRUE;
}

static void textbox_fdecode_auto_and_task_add(u8* str, bool32 allowSkippingDelayWithButtonPress)
{
    StringExpandPlaceholders(gStringVar4, str);
    AddTextPrinterForMessage(allowSkippingDelayWithButtonPress);
    task_add_textbox();
}

static void textbox_auto_and_task_add(void)
{
    AddTextPrinterForMessage(TRUE);
    task_add_textbox();
}

void HideFieldMessageBox(void)
{
    task_del_textbox();
    ClearDialogWindowAndFrame(0, 1);
    sFieldMessageBoxMode = 0;
}

u8 GetFieldMessageBoxMode(void)
{
    return sFieldMessageBoxMode;
}

bool8 IsFieldMessageBoxHidden(void)
{
    if (sFieldMessageBoxMode == 0)
        return TRUE;
    return FALSE;
}

void sub_8098358(void)
{
    task_del_textbox();
    DrawStdWindowFrame(0, 1);
    sFieldMessageBoxMode = 0;
}

void sub_8098374(void)
{
    task_del_textbox();
    sFieldMessageBoxMode = 0;
}
