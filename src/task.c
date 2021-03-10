#include "global.h"
#include "task.h"

struct Task gTasks[NUM_TASKS];

static void InsertTask(u8 newTaskId);
static u8 FindFirstActiveTask(void);

void ResetTasks(void)
{
    u8 i;

    for (i = 0; i < NUM_TASKS; i++)
    {
        gTasks[i].isActive = FALSE;
        gTasks[i].func = TaskDummy;
        gTasks[i].prev = i;
        gTasks[i].next = i + 1;
        gTasks[i].priority = -1;
        memset(gTasks[i].data, 0, sizeof(gTasks[i].data));
    }

    gTasks[0].prev = HEAD_SENTINEL;
    gTasks[NUM_TASKS - 1].next = TAIL_SENTINEL;
}

u8 CreateTask(TaskFunc func, u8 priority)
{
    u8 i;

    for (i = 0; i < NUM_TASKS; i++)
    {
        if (!gTasks[i].isActive)
        {
            gTasks[i].func = func;
            gTasks[i].priority = priority;
            InsertTask(i);
            memset(gTasks[i].data, 0, sizeof(gTasks[i].data));
            gTasks[i].isActive = TRUE;
            return i;
        }
    }

    return 0;
}

static void InsertTask(u8 newTaskId)
{
    u8 taskId = FindFirstActiveTask();

    if (taskId == NUM_TASKS)
    {
        // The new task is the only task.
        gTasks[newTaskId].prev = HEAD_SENTINEL;
        gTasks[newTaskId].next = TAIL_SENTINEL;
        return;
    }

    while (1)
    {
        if (gTasks[newTaskId].priority < gTasks[taskId].priority)
        {
            // We've found a task with a higher priority value,
            // so we insert the new task before it.
            gTasks[newTaskId].prev = gTasks[taskId].prev;
            gTasks[newTaskId].next = taskId;
            if (gTasks[taskId].prev != HEAD_SENTINEL)
                gTasks[gTasks[taskId].prev].next = newTaskId;
            gTasks[taskId].prev = newTaskId;
            return;
        }
        if (gTasks[taskId].next == TAIL_SENTINEL)
        {
            // We've reached the end.
            gTasks[newTaskId].prev = taskId;
            gTasks[newTaskId].next = gTasks[taskId].next;
            gTasks[taskId].next = newTaskId;
            return;
        }
        taskId = gTasks[taskId].next;
    }
}

void DestroyTask(u8 taskId)
{
    if (gTasks[taskId].isActive)
    {
        gTasks[taskId].isActive = FALSE;

        if (gTasks[taskId].prev == HEAD_SENTINEL)
        {
            if (gTasks[taskId].next != TAIL_SENTINEL)
                gTasks[gTasks[taskId].next].prev = HEAD_SENTINEL;
        }
        else
        {
            if (gTasks[taskId].next == TAIL_SENTINEL)
            {
                gTasks[gTasks[taskId].prev].next = TAIL_SENTINEL;
            }
            else
            {
                gTasks[gTasks[taskId].prev].next = gTasks[taskId].next;
                gTasks[gTasks[taskId].next].prev = gTasks[taskId].prev;
            }
        }
    }
}

void RunTasks(void)
{
    u8 taskId = FindFirstActiveTask();

    if (taskId != NUM_TASKS)
    {
        do
        {
            gTasks[taskId].func(taskId);
            taskId = gTasks[taskId].next;
        } while (taskId != TAIL_SENTINEL);
    }
}

static u8 FindFirstActiveTask(void)
{
    u8 taskId;

    for (taskId = 0; taskId < NUM_TASKS; taskId++)
        if (gTasks[taskId].isActive == TRUE && gTasks[taskId].prev == HEAD_SENTINEL)
            break;

    return taskId;
}

void TaskDummy(u8 taskId)
{
}

void SetTaskFuncWithFollowupFunc(u8 taskId, TaskFunc func, TaskFunc followupFunc)
{
    u8 followupFuncIndex = NUM_TASK_DATA - 2; // Should be const.

    gTasks[taskId].data[followupFuncIndex] = (s16)((u32)followupFunc);
    gTasks[taskId].data[followupFuncIndex + 1] = (s16)((u32)followupFunc >> 16); // Store followupFunc as two half-words in the data array.
    gTasks[taskId].func = func;
}

void SwitchTaskToFollowupFunc(u8 taskId)
{
    u8 followupFuncIndex = NUM_TASK_DATA - 2; // Should be const.

    gTasks[taskId].func = (TaskFunc)((u16)(gTasks[taskId].data[followupFuncIndex]) | (gTasks[taskId].data[followupFuncIndex + 1] << 16));
}

bool8 FuncIsActiveTask(TaskFunc func)
{
    u8 i;

    for (i = 0; i < NUM_TASKS; i++)
        if (gTasks[i].isActive == TRUE && gTasks[i].func == func)
            return TRUE;

    return FALSE;
}

u8 FindTaskIdByFunc(TaskFunc func)
{
    s32 i;

    for (i = 0; i < NUM_TASKS; i++)
        if (gTasks[i].isActive == TRUE && gTasks[i].func == func)
            return (u8)i;

    return TAIL_SENTINEL; // No task was found.
}

u8 GetTaskCount(void)
{
    u8 i;
    u8 count = 0;

    for (i = 0; i < NUM_TASKS; i++)
        if (gTasks[i].isActive == TRUE)
            count++;

    return count;
}

void SetWordTaskArg(u8 taskId, u8 dataElem, u32 value)
{
    if (dataElem < NUM_TASK_DATA - 1)
    {
        gTasks[taskId].data[dataElem] = value;
        gTasks[taskId].data[dataElem + 1] = value >> 16;
    }
}

u32 GetWordTaskArg(u8 taskId, u8 dataElem)
{
    if (dataElem < NUM_TASK_DATA - 1)
        return (u16)gTasks[taskId].data[dataElem] | (gTasks[taskId].data[dataElem + 1] << 16);
    else
        return 0;
}
