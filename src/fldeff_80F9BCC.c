#include "global.h"
#include "task.h"

//
void sub_80F9C90(u8);
void sub_80F9DFC(u8);
void sub_80F9C44(TaskFunc, u16, u16, u8);



// TODO: name these functions and arguments
void sub_80F9BCC(u16 a0, u16 a1, u8 a2)
{
    sub_80F9C44(sub_80F9C90, a0, a1, a2);
}

void sub_80F9BF4(u16 a0, u16 a1, u8 a2)
{
    sub_80F9C44(sub_80F9DFC, a0, a1, a2);
}

bool8 sub_80F9C1C(void)
{
    return FuncIsActiveTask(sub_80F9C90);
}

bool8 sub_80F9C30(void)
{
    return FuncIsActiveTask(sub_80F9DFC);
}

void sub_80F9C44(void (*a0) (u8), u16 a1, u16 a2, u8 a3)
{
    //
    u8 tempA, tempB;

    u8 taskId = CreateTask(a1, a3);
    struct Task *task = &gTasks[taskId];
    task->data[0] = 0;

    tempA = 16;
    if (a1 != 0)
    {
        tempA = a1;
    }
    task->data[1] = tempA;

    tempB = 20;
    if (a1 != 0)
    {
        tempB = a1;
    }
    task->data[2] = tempB;
}



































