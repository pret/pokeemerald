
// Includes
#include "global.h"
#include "songs.h"
#include "sound.h"
#include "rom4.h"
#include "task.h"
#include "main.h"
#include "palette.h"
#include "easy_chat.h"

// Static type declarations

// Static RAM declarations
static void sub_811A2C0(u8);
static void sub_811A278(void);
/*static*/ bool8 sub_811A428(u8);
static void sub_811A2FC(u8);
/*static*/ u16 sub_811AAAC(void);
/*static*/ bool32 sub_811A88C(u16);
/*static*/ void sub_811C158(u16);
/*static*/ bool8 sub_811C170(void);
/*static*/ void sub_811A8A4(u16);
/*static*/ void sub_811A4D0(u32);

// Static ROM declarations

// .rodata

// .text

void sub_811A20C(u8 a0, u32 a1, u32 a2, u8 a3)
{
    u8 taskId;

    ResetTasks();
    taskId = CreateTask(sub_811A2C0, 0);
    gTasks[taskId].data[1] = a0;
    gTasks[taskId].data[7] = a3;
    SetWordTaskArg(taskId, 0x02, a1);
    SetWordTaskArg(taskId, 0x04, a2);
    SetMainCallback2(sub_811A278);
}

static void sub_811A278(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_811A290(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
}

static void sub_811A2A4(u8 taskId, TaskFunc taskFunc)
{
    gTasks[taskId].func = taskFunc;
    gTasks[taskId].data[0] = 0;
}

static void sub_811A2C0(u8 taskId)
{
    if (!is_c1_link_related_active())
    {
        while (sub_811A428(taskId));
    }
    else
    {
        if (sub_811A428(taskId) == TRUE)
        {
            return;
        }
    }
    sub_811A2A4(taskId, sub_811A2FC);
}

static void sub_811A2FC(u8 taskId)
{
    u16 v0;
    s16 *data;

    data = gTasks[taskId].data;
    switch (data[0])
    {
        case 0:
            SetVBlankCallback(sub_811A290);
            BlendPalettes(-1, 16, 0);
            BeginNormalPaletteFade(-1, -1, 16, 0, 0);
            data[0] = 5;
            break;
        case 1:
            v0 = sub_811AAAC();
            if (sub_811A88C(v0))
            {
                BeginNormalPaletteFade(-1, -2, 0, 16, 0);
                data[0] = 3;
                data[6] = v0;
            }
            else if (v0 == 0x18)
            {
                BeginNormalPaletteFade(-1, -1, 0, 16, 0);
                data[0] = 4;
            }
            else if (v0 != 0)
            {
                PlaySE(SE_SELECT);
                sub_811C158(v0);
                data[0] ++;
            }
            break;
        case 2:
            if (!sub_811C170())
            {
                data[0] = 1;
            }
            break;
        case 3:
            if (!gPaletteFade.active)
            {
                sub_811A8A4(data[6]);
            }
            break;
        case 4:
            if (!gPaletteFade.active)
            {
                sub_811A4D0(GetWordTaskArg(taskId, 0x04));
            }
            break;
        case 5:
            if (!gPaletteFade.active)
            {
                data[0] = 1;
            }
            break;
    }
}
