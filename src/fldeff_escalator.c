#include "global.h"
#include "field_camera.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "task.h"

static EWRAM_DATA u8 sEscalatorAnim_TaskId = 0;

static void sub_80E12E8(u8 taskId, const s16 *list, u16 isImpassableFlag)
{
    s16 r5 = gTasks[taskId].data[4] - 1;
    s16 r3 = gTasks[taskId].data[5] - 1;
    s16 r4 = gTasks[taskId].data[1];
    s16 y;
    s16 x;

    if (gTasks[taskId].data[2] == 0)
    {
        for (y = 0; y < 3; y++)
        {
            for (x = 0; x < 3; x++)
            {
                s16 metatileId = MapGridGetMetatileIdAt(r5 + x, r3 + y);

                if (list[r4] == metatileId)
                {
                    if (r4 != 2)
                        MapGridSetMetatileIdAt(r5 + x, r3 + y, isImpassableFlag | list[r4 + 1]);
                    else
                        MapGridSetMetatileIdAt(r5 + x, r3 + y, isImpassableFlag | list[0]);
                }
            }
        }
    }
    else
    {
        for (y = 0; y < 3; y++)
        {
            for (x = 0; x < 3; x++)
            {
                s16 metatileId = MapGridGetMetatileIdAt(r5 + x, r3 + y);

                if (list[2 - r4] == metatileId)
                {
                    if (r4 != 2)
                        MapGridSetMetatileIdAt(r5 + x, r3 + y, isImpassableFlag | list[1 - r4]);
                    else
                        MapGridSetMetatileIdAt(r5 + x, r3 + y, isImpassableFlag | list[2]);
                }
            }
        }
    }
}

static const u16 gUnknown_08589ABA[] = {0x284, 0x282, 0x280};
static const u16 gUnknown_08589AC0[] = {0x285, 0x283, 0x281};
static const u16 gUnknown_08589AC6[] = {0x28C, 0x28A, 0x288};
static const u16 gUnknown_08589ACC[] = {0x28D, 0x28B, 0x289};
static const u16 gUnknown_08589AD2[] = {0x2A0, 0x2A2, 0x2A4};
static const u16 gUnknown_08589AD8[] = {0x2A1, 0x2A3, 0x2A5};
static const u16 gUnknown_08589ADE[] = {0x2A8, 0x2AA, 0x2AC};

static void sub_80E1444(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    data[3] = 1;

    switch (data[0])
    {
        case 0:
            sub_80E12E8(taskId, gUnknown_08589ABA, 0);
            break;
        case 1:
            sub_80E12E8(taskId, gUnknown_08589AC0, 0);
            break;
        case 2:
            sub_80E12E8(taskId, gUnknown_08589AC6, METATILE_COLLISION_MASK);
            break;
        case 3:
            sub_80E12E8(taskId, gUnknown_08589ACC, 0);
            break;
        case 4:
            sub_80E12E8(taskId, gUnknown_08589AD2, METATILE_COLLISION_MASK);
            break;
        case 5:
            sub_80E12E8(taskId, gUnknown_08589AD8, 0);
            break;
        case 6:
            sub_80E12E8(taskId, gUnknown_08589ADE, 0);
            break;
    }

    data[0] = (data[0] + 1) & 7;
    if (!data[0])
    {
        DrawWholeMapView();
        data[1] = (data[1] + 1) % 3;
        data[3] = 0;
    }
}

static u8 sub_80E150C(u16 var)
{
    u8 taskId = CreateTask(sub_80E1444, 0);
    s16 *data = gTasks[taskId].data;

    PlayerGetDestCoords(&data[4], &data[5]);
    data[0] = 0;
    data[1] = 0;
    data[2] = var;
    sub_80E1444(taskId);
    return taskId;
}

void sub_80E1558(u8 var)
{
    sEscalatorAnim_TaskId = sub_80E150C(var);
}

void sub_80E1570(void)
{
    DestroyTask(sEscalatorAnim_TaskId);
}

bool8 sub_80E1584(void)
{
    if (gTasks[sEscalatorAnim_TaskId].data[3] == 0 && gTasks[sEscalatorAnim_TaskId].data[1] == 2)
        return FALSE;
    else
        return TRUE;
}
