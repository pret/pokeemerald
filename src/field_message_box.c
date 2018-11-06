#include "global.h"
#include "menu.h"
#include "string.h"
#include "string_util.h"
#include "task.h"
#include "text.h"

extern bool32 sub_8196094(void);
extern void sub_8196080(u8*);

EWRAM_DATA u8 gUnknown_020375BC = 0;

void textbox_fdecode_auto_and_task_add(u8*, int);
void textbox_auto_and_task_add(void);

void sub_8098128(void)
{
    gUnknown_020375BC = 0;
    gTextFlags.canABSpeedUpPrint = 0;
    gTextFlags.flag_1 = 0;
    gTextFlags.flag_2 = 0;
    gTextFlags.flag_3 = 0;
}

void sub_8098154(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
        case 0:
           sub_81973A4();
           task->data[0]++;
           break;
        case 1:
           NewMenuHelpers_DrawDialogueFrame(0, 1);
           task->data[0]++;
           break;
        case 2:
            if (RunTextPrintersAndIsPrinter0Active() != 1)
            {
                gUnknown_020375BC = 0;
                DestroyTask(taskId);
            }
    }
}

void task_add_textbox(void)
{
    CreateTask(sub_8098154, 0x50);
}

void task_del_textbox(void)
{
    u8 taskId = FindTaskIdByFunc(sub_8098154);
    if (taskId != 0xFF)
        DestroyTask(taskId);
}

bool8 ShowFieldMessage(u8 *str)
{
    if (gUnknown_020375BC != 0)
        return FALSE;
    textbox_fdecode_auto_and_task_add(str, 1);
    gUnknown_020375BC = 2;
    return TRUE;
}

void sub_8098214(u8 taskId)
{
    if (!sub_8196094())
    {
        gUnknown_020375BC = 0;
        DestroyTask(taskId);
    }
}

bool8 sub_8098238(u8 *str)
{
    if (gUnknown_020375BC != 0)
        return FALSE;
    StringExpandPlaceholders(gStringVar4, str);
    CreateTask(sub_8098214, 0);
    sub_8196080(str);
    gUnknown_020375BC = 2;
    return TRUE;
}

bool8 ShowFieldAutoScrollMessage(u8 *str)
{
    if (gUnknown_020375BC != 0)
        return FALSE;
    gUnknown_020375BC = 3;
    textbox_fdecode_auto_and_task_add(str, 0);
    return TRUE;
}

bool8 sub_80982A0(u8 *str)
{
    gUnknown_020375BC = 3;
    textbox_fdecode_auto_and_task_add(str, 1);
    return TRUE;
}

bool8 sub_80982B8(void)
{
    if (gUnknown_020375BC != 0)
        return FALSE;
    gUnknown_020375BC = 2;
    textbox_auto_and_task_add();
    return TRUE;
}

void textbox_fdecode_auto_and_task_add(u8* str, int a)
{
    StringExpandPlaceholders(gStringVar4, str);
    AddTextPrinterForMessage(a);
    task_add_textbox();
}

void textbox_auto_and_task_add(void)
{
    AddTextPrinterForMessage(1);
    task_add_textbox();
}

void HideFieldMessageBox(void)
{
    task_del_textbox();
    sub_8197434(0, 1);
    gUnknown_020375BC = 0;
}

u8 GetFieldMessageBoxMode(void)
{
    return gUnknown_020375BC;
}

bool8 IsFieldMessageBoxHidden(void)
{
    if (gUnknown_020375BC == 0)
        return TRUE;
    return FALSE;
}

void sub_8098358(void)
{
    task_del_textbox();
    NewMenuHelpers_DrawStdWindowFrame(0, 1);
    gUnknown_020375BC = 0;
}

void sub_8098374(void)
{
    task_del_textbox();
    gUnknown_020375BC = 0;
}
