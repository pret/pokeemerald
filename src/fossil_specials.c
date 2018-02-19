#include "global.h"
#include "constants/flags.h"
#include "constants/songs.h"
#include "bg.h"
#include "event_data.h"
#include "field_camera.h"
#include "field_map_obj.h"
#include "fieldmap.h"
#include "fldeff_groundshake.h"
#include "global.fieldmap.h"
#include "gpu_regs.h"
#include "malloc.h"
#include "random.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "window.h"

//struct StructUnknown_0203CF14

struct Struct8617DA4 {
    u8 x;
    u8 y;
    u16 tileId;
};


extern const struct Struct8617DA4 gUnknown_08617DA4[];
extern const u8 gUnknown_08617274[]; //mirage tower
extern const u8 gUnknown_08617B94[]; //mirage tower tilemap

extern void * gUnknown_0203CF04;
extern void * gUnknown_0203CF08;
extern u16 (*gUnknown_0203CF14)[2];

/*static*/ void sub_81BED50(u8 taskId);
/*static*/ void sub_81BEBF4(u8 taskId);
/*static*/ void sub_81BF028(u8 taskId);

void sub_81BEB24(void)
{
    u8 count;
    for(count = 0; count <= 0x11; count++)
        MapGridSetMetatileIdAt(gUnknown_08617DA4[count].x + 7, gUnknown_08617DA4[count].y + 7, gUnknown_08617DA4[count].tileId);
    DrawWholeMapView();
}

void sub_81BEB54(void)
{
    CreateTask(sub_81BED50, 0x9);
}

void sub_81BEB68(void)
{
    CreateTask(sub_81BEBF4, 0x9);
}

void sub_81BEB7C(void)
{
    CreateTask(sub_81BF028, 0x9);
}

void sub_81BEB90(void)
{
    SetGpuReg(REG_OFFSET_BG0HOFS, (*gUnknown_0203CF14)[0]);
    SetGpuReg(REG_OFFSET_BG0VOFS, (*gUnknown_0203CF14)[1]);
}

void sub_81BEBB4(u8 taskId)
{
    if(!(gTasks[taskId].data[0]))
    {
        (*gUnknown_0203CF14)[0] = -(*gUnknown_0203CF14)[0];
        gTasks[taskId].data[0] = 2;
        sub_81BEB90();
    }
    else
        gTasks[taskId].data[0]--;
}

void sub_81BEBF4(u8 taskId)
{
    u8 zero;

    switch(gTasks[taskId].data[0])
    {
    case 0:
        FreeAllWindowBuffers();
        SetBgAttribute(0, BG_CTRL_ATTR_MOSAIC, 2);
        gTasks[taskId].data[0]++;
        break;
    case 1:
        gUnknown_0203CF04 = (u8 **) AllocZeroed(0x920);
        gUnknown_0203CF08 = (u8 **) AllocZeroed(0x800);
        ChangeBgX(0, 0, 0);
        ChangeBgY(0, 0, 0);
        gTasks[taskId].data[0]++;
        break;
    case 2:
        CpuSet(gUnknown_08617274, gUnknown_0203CF04, 0x490);
        LoadBgTiles(0, gUnknown_0203CF04, 0x920, 0);
        gTasks[taskId].data[0]++;
        break;
    case 3:
        SetBgTilemapBuffer(0, gUnknown_0203CF08);
        CopyToBgTilemapBufferRect_ChangePalette(0, &gUnknown_08617B94, 12, 29, 6, 12, 17);
        CopyBgTilemapBufferToVram(0);
        gTasks[taskId].data[0]++;
        break;
    case 4:
        ShowBg(0);
        gTasks[taskId].data[0]++;
        break;
    case 5:
        sub_81BEB24();
        gTasks[taskId].data[0]++;
        break;
    case 6:
        gUnknown_0203CF14 = (u16(*)[2]) Alloc(4);
        zero = 0;
        (*gUnknown_0203CF14)[0] = 2;
        (*gUnknown_0203CF14)[1] = zero;
        CreateTask(sub_81BEBB4, 0xA);
        DestroyTask(taskId);
        EnableBothScriptContexts();
        break;
    }
}
