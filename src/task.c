#include "global.h"
#include "task.h"

#define NUM_TASKS 16

#define HEAD_SENTINEL 0xFE
#define TAIL_SENTINEL 0xFF

struct Task gTasks[NUM_TASKS];

static void InsertTask(u8 newTaskId);
static u8 FindFirstActiveTask();

void ResetTasks()
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

#ifdef NONMATCHING
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

    for (;;)
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

        if (gTasks[taskId].next != TAIL_SENTINEL)
            taskId = gTasks[taskId].next;
        else
            break;
    }

    // We've reached the end.
    gTasks[newTaskId].prev = taskId;
    gTasks[newTaskId].next = gTasks[taskId].next;
    gTasks[taskId].next = newTaskId;
}
#else
__attribute__((naked))
static void InsertTask(u8 newTaskId)
{
    asm("push	{r4, r5, r6, r7, lr}\n\
	mov	r7, r8\n\
	push	{r7}\n\
	lsl	r0, r0, #24\n\
	lsr	r4, r0, #24\n\
	bl	FindFirstActiveTask\n\
	lsl	r0, r0, #24\n\
	lsr	r1, r0, #24\n\
	cmp	r1, #16\n\
	bne	.LInsertTask_foundActiveTask\n\
	ldr	r1, .LInsertTask_gTasks1\n\
	lsl	r0, r4, #2\n\
	add	r0, r0, r4\n\
	lsl	r0, r0, #3\n\
	add	r0, r0, r1\n\
	mov	r1, #254\n\
	strb	r1, [r0, #5]\n\
	mov	r1, #255\n\
	strb	r1, [r0, #6]\n\
	b	.LInsertTask_done\n\
	.align	2, 0\n\
.LInsertTask_gTasks1:\n\
	.word	gTasks\n\
.LInsertTask_foundActiveTask:\n\
	ldr	r6, .LInsertTask_gTasks2\n\
	lsl	r0, r4, #2\n\
	mov	r12, r0\n\
	mov	r8, r6\n\
	add	r0, r0, r4\n\
	lsl	r0, r0, #3\n\
	add	r2, r0, r6\n\
.LInsertTask_loop:\n\
	lsl	r0, r1, #2\n\
	add	r0, r0, r1\n\
	lsl	r5, r0, #3\n\
	mov	r7, r8\n\
	add	r3, r5, r7\n\
	ldrb	r0, [r2, #7]\n\
	ldrb	r7, [r3, #7]\n\
	cmp	r0, r7\n\
	bcs	.LInsertTask_next\n\
	ldrb	r0, [r3, #5]\n\
	strb	r0, [r2, #5]\n\
	strb	r1, [r2, #6]\n\
	ldrb	r0, [r3, #5]\n\
	cmp	r0, #254\n\
	beq	.LInsertTask_insertAtHead\n\
	add	r1, r0, #0\n\
	lsl	r0, r1, #2\n\
	add	r0, r0, r1\n\
	lsl	r0, r0, #3\n\
	add	r0, r0, r8\n\
	strb	r4, [r0, #6]\n\
.LInsertTask_insertAtHead:\n\
	strb	r4, [r3, #5]\n\
	b	.LInsertTask_done\n\
	.align	2, 0\n\
.LInsertTask_gTasks2:\n\
	.word	gTasks\n\
.LInsertTask_next:\n\
	ldrb	r0, [r3, #6]\n\
	cmp	r0, #255\n\
	beq	.LInsertTask_insertAtTail\n\
	add	r1, r0, #0\n\
	b	.LInsertTask_loop\n\
.LInsertTask_insertAtTail:\n\
	mov	r2, r12\n\
	add	r0, r2, r4\n\
	lsl	r0, r0, #3\n\
	add	r0, r0, r6\n\
	strb	r1, [r0, #5]\n\
	add	r2, r5, r6\n\
	ldrb	r1, [r2, #6]\n\
	strb	r1, [r0, #6]\n\
	strb	r4, [r2, #6]\n\
.LInsertTask_done:\n\
	pop	{r3}\n\
	mov	r8, r3\n\
	pop	{r4, r5, r6, r7}\n\
	pop	{r0}\n\
	bx	r0\n");
}
#endif // NONMATCHING

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

void RunTasks()
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

static u8 FindFirstActiveTask()
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

#define TASK_DATA_OP(taskId, offset, op)                    \
{                                                           \
    u32 tasksAddr = (u32)gTasks;                            \
    u32 addr = taskId * sizeof(struct Task) + offset;       \
    u32 dataAddr = tasksAddr + offsetof(struct Task, data); \
    addr += dataAddr;                                       \
    op;                                                     \
}

void SetTaskFuncWithFollowupFunc(u8 taskId, TaskFunc func, TaskFunc followupFunc)
{
    TASK_DATA_OP(taskId, 28, *((u16 *)addr) = (u32)followupFunc)
    TASK_DATA_OP(taskId, 30, *((u16 *)addr) = (u32)followupFunc >> 16)
    gTasks[taskId].func = func;
}

void SwitchTaskToFollowupFunc(u8 taskId)
{
    s32 func;

    gTasks[taskId].func = NULL;

    TASK_DATA_OP(taskId, 28, func = *((u16 *)addr))
    TASK_DATA_OP(taskId, 30, func |= *((s16 *)addr) << 16)

    gTasks[taskId].func = (TaskFunc)func;
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

    return -1;
}

u8 GetTaskCount()
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
    if (dataElem <= 14)
    {
        gTasks[taskId].data[dataElem] = value;
        gTasks[taskId].data[dataElem + 1] = value >> 16;
    }
}

u32 GetWordTaskArg(u8 taskId, u8 dataElem)
{
    if (dataElem <= 0xE)
        return (u16)gTasks[taskId].data[dataElem] | (gTasks[taskId].data[dataElem + 1] << 16);
    else
        return 0;
}
