#include "global.h"
#include "task.h"
#include "main.h"
#include "constants/vars.h"
#include "bike.h"
#include "item.h"
#include "constants/items.h"
#include "event_data.h"
#include "overworld.h"
#include "clock.h"
#include "script.h"
#include "field_special_scene.h"
#include "field_effect_helpers.h"
#include "secret_base.h"
#include "metatile_behavior.h"
#include "fieldmap.h"
#include "field_player_avatar.h"
#include "field_camera.h"
#include "constants/songs.h"
#include "sound.h"
#include "field_tasks.h"

struct MetatileOffset
{
    s8 x;
    s8 y;
    u16 tileId;
};

// this file's functions
static void DummyPerStepCallback(u8 taskId);
static void PerStepCallback_8069F64(u8 taskId);
static void PerStepCallback_8069AA0(u8 taskId);
static void PerStepCallback_8069864(u8 taskId);
static void PerStepCallback_8069DD4(u8 taskId);
static void PerStepCallback_806A07C(u8 taskId);
static void Task_MuddySlope(u8 taskId);

// const rom data
static void (*const gUnknown_08510348[])(u8) =
{
    DummyPerStepCallback,
    PerStepCallback_8069F64,
    PerStepCallback_8069AA0,
    PerStepCallback_8069864,
    PerStepCallback_8069DD4,
    EndTruckSequence,
    sub_80EA3E4,
    PerStepCallback_806A07C
};

// they are in pairs but declared as 1D array
static const struct MetatileOffset gUnknown_08510368[] =
{
    {  0,  0,0x259}, {  0,  1,0x261},
    {  0, -1,0x259}, {  0,  0,0x261},
    {  0,  0,0x252}, {  1,  0,0x253},
    { -1,  0,0x252}, {  0,  0,0x253}
};

static const struct MetatileOffset gUnknown_08510388[] =
{
    {  0,  0,0x25A}, {  0,  1,0x262},
    {  0, -1,0x25A}, {  0,  0,0x262},
    {  0,  0,0x254}, {  1,  0,0x255},
    { -1,  0,0x254}, {  0,  0,0x255}
};

static const struct MetatileOffset gUnknown_085103A8[] =
{
    {  0,  0,0x258}, {  0,  1,0x260},
    {  0, -1,0x258}, {  0,  0,0x260},
    {  0,  0,0x250}, {  1,  0,0x251},
    { -1,  0,0x250}, {  0,  0,0x251}
};

static const u16 gUnknown_085103C8[] =
{
    0,
    0,
    0,
    0,
    0,
    0,
    VAR_TEMP_1,
    VAR_TEMP_2,
    VAR_TEMP_3,
    VAR_TEMP_4,
    0,
    0,
    VAR_TEMP_5,
    VAR_TEMP_6,
    VAR_TEMP_7,
    0,
    0,
    VAR_TEMP_8,
    VAR_TEMP_9,
    VAR_TEMP_A,
    0,
    0,
    0,
    0,
    0,
    0
};

static const u16 gUnknown_085103FC[] = {0xe8, 0xeb, 0xea, 0xe9};

// code
static void Task_RunPerStepCallback(u8 taskId)
{
    int idx = gTasks[taskId].data[0];
    gUnknown_08510348[idx](taskId);
}

#define tState           data[0]
#define tAmbientCryState data[1]
#define tAmbientCryDelay data[2]

static void RunTimeBasedEvents(s16 *data)
{
    switch (tState)
    {
        case 0:
            if (gMain.vblankCounter1 & 0x1000)
            {
                DoTimeBasedEvents();
                tState++;
            }
            break;
        case 1:
            if (!(gMain.vblankCounter1 & 0x1000))
            {
                tState--;
            }
            break;
    }
}

static void Task_RunTimeBasedEvents(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!ScriptContext2_IsEnabled())
    {
        RunTimeBasedEvents(data);
        UpdateAmbientCry(&tAmbientCryState, &tAmbientCryDelay);
    }
}

#undef tState
#undef tAmbientCryState
#undef tAmbientCryDelay

void SetUpFieldTasks(void)
{
    if (!FuncIsActiveTask(Task_RunPerStepCallback))
    {
        u8 taskId = CreateTask(Task_RunPerStepCallback, 0x50);
        gTasks[taskId].data[0] = 0;
    }
    if (!FuncIsActiveTask(Task_MuddySlope))
    {
        CreateTask(Task_MuddySlope, 0x50);
    }
    if (!FuncIsActiveTask(Task_RunTimeBasedEvents))
    {
        CreateTask(Task_RunTimeBasedEvents, 0x50);
    }
}

void ActivatePerStepCallback(u8 callbackId)
{
    u8 taskId = FindTaskIdByFunc(Task_RunPerStepCallback);
    if (taskId != 0xff)
    {
        s32 i;
        s16 *data = gTasks[taskId].data;

        for (i = 0; i < 16; i++)
            data[i] = 0;

        if (callbackId >= ARRAY_COUNT(gUnknown_08510348))
        {
            data[0] = 0;
        }
        else
        {
            data[0] = callbackId;
        }
    }
}

void ResetFieldTasksArgs(void)
{
    u8 taskId;
    s16 *data;

    taskId = FindTaskIdByFunc(Task_RunPerStepCallback);
    if (taskId != 0xff)
    {
        data = gTasks[taskId].data;
    }
    taskId = FindTaskIdByFunc(Task_RunTimeBasedEvents);
    if (taskId != 0xff)
    {
        data = gTasks[taskId].data;
        data[1] = 0;
        data[2] = 0;
    }
}

static void DummyPerStepCallback(u8 taskId)
{

}

static const struct MetatileOffset *sub_809DA30(const struct MetatileOffset *offsets, u16 metatileBehavior)
{
    if (MetatileBehavior_IsPacifilogVerticalLog1(metatileBehavior))
        return &offsets[0 * 2];
    else if (MetatileBehavior_IsPacifilogVerticalLog2(metatileBehavior))
        return &offsets[1 * 2];
    else if (MetatileBehavior_IsPacifilogHorizontalLog1(metatileBehavior))
        return &offsets[2 * 2];
    else if (MetatileBehavior_IsPacifilogHorizontalLog2(metatileBehavior))
        return &offsets[3 * 2];
    else
        return NULL;
}

static void sub_809DA88(const struct MetatileOffset *offsets, s16 x, s16 y, bool32 flag)
{
    offsets = sub_809DA30(offsets, MapGridGetMetatileBehaviorAt(x, y));

    if (offsets != NULL)
    {
        MapGridSetMetatileIdAt(x + offsets[0].x, y + offsets[0].y, offsets[0].tileId);
        if (flag)
            CurrentMapDrawMetatileAt(x + offsets[0].x, y + offsets[0].y);

        MapGridSetMetatileIdAt(x + offsets[1].x, y + offsets[1].y, offsets[1].tileId);
        if (flag)
            CurrentMapDrawMetatileAt(x + offsets[1].x, y + offsets[1].y);
    }
}

static void sub_809DB10(s16 x, s16 y, bool32 flag)
{
    sub_809DA88(gUnknown_08510368, x, y, flag);
}

static void sub_809DB34(s16 x, s16 y, bool32 flag)
{
    sub_809DA88(gUnknown_08510388, x, y, flag);
}

static void sub_809DB58(s16 x, s16 y, bool32 flag)
{
    sub_809DA88(gUnknown_085103A8, x, y, flag);
}

static bool32 sub_809DB7C(s16 x1, s16 y1, s16 x2, s16 y2)
{
    u16 metatileBehavior = MapGridGetMetatileBehaviorAt(x2, y2);

    if (MetatileBehavior_IsPacifilogVerticalLog1(metatileBehavior))
    {
        if (y1 > y2)
            return FALSE;
    }
    else if (MetatileBehavior_IsPacifilogVerticalLog2(metatileBehavior))
    {
        if (y1 < y2)
            return FALSE;
    }
    else if (MetatileBehavior_IsPacifilogHorizontalLog1(metatileBehavior))
    {
        if (x1 > x2)
            return FALSE;
    }
    else if (MetatileBehavior_IsPacifilogHorizontalLog2(metatileBehavior))
    {
        if (x1 < x2)
            return FALSE;
    }
    return TRUE;
}

static bool32 sub_809DC18(s16 x1, s16 y1, s16 x2, s16 y2)
{
    u16 metatileBehavior = MapGridGetMetatileBehaviorAt(x1, y1);

    if (MetatileBehavior_IsPacifilogVerticalLog1(metatileBehavior))
    {
        if (y1 < y2)
            return FALSE;
    }
    else if (MetatileBehavior_IsPacifilogVerticalLog2(metatileBehavior))
    {
        if (y1 > y2)
            return FALSE;
    }
    else if (MetatileBehavior_IsPacifilogHorizontalLog1(metatileBehavior))
    {
        if (x1 < x2)
            return FALSE;
    }
    else if (MetatileBehavior_IsPacifilogHorizontalLog2(metatileBehavior))
    {
        if (x1 > x2)
            return FALSE;
    }
    return TRUE;
}

static void PerStepCallback_8069864(u8 taskId)
{
    s16 *data;
    s16 x, y;
    data = gTasks[taskId].data;
    PlayerGetDestCoords(&x, &y);
    switch (data[1])
    {
        case 0:
            data[2] = x;
            data[3] = y;
            sub_809DB34(x, y, TRUE);
            data[1] = 1;
            break;
        case 1:
            if (x != data[2] || y != data[3])
            {
                if (sub_809DB7C(x, y, data[2], data[3]))
                {
                    sub_809DB10(data[2], data[3], TRUE);
                    sub_809DB58(data[2], data[3], FALSE);
                    data[4] = data[2];
                    data[5] = data[3];
                    data[1] = 2;
                    data[6] = 8;
                }
                else
                {
                    data[4] = -1;
                    data[5] = -1;
                }
                if (sub_809DC18(x, y, data[2], data[3]))
                {
                    sub_809DB10(x, y, TRUE);
                    data[1] = 2;
                    data[6] = 8;
                }
                data[2] = x;
                data[3] = y;
                if (MetatileBehavior_IsPacifidlogLog(MapGridGetMetatileBehaviorAt(x, y)))
                {
                    PlaySE(SE_MIZU);
                }
            }
            break;
        case 2:
            if ((--data[6]) == 0)
            {
                sub_809DB34(x, y, TRUE);
                if (data[4] != -1 && data[5] != -1)
                {
                    sub_809DB58(data[4], data[5], TRUE);
                }
                data[1] = 1;
            }
            break;
    }
}

static void sub_809DE28(s16 x, s16 y)
{
    u8 z = PlayerGetZCoord();
    if (!(z & 0x01))
    {
        switch (MapGridGetMetatileIdAt(x, y))
        {
            case 0x24e:
                MapGridSetMetatileIdAt(x, y, 0x24f);
                break;
            case 0x256:
                MapGridSetMetatileIdAt(x, y, 0x257);
                break;
        }
    }
}

static void sub_809DE8C(s16 x, s16 y)
{
    u8 z = PlayerGetZCoord();
    if (!(z & 0x01))
    {
        switch (MapGridGetMetatileIdAt(x, y))
        {
            case 0x24f:
                MapGridSetMetatileIdAt(x, y, 0x24e);
                break;
            case 0x257:
                MapGridSetMetatileIdAt(x, y, 0x256);
                break;
        }
    }
}

static void PerStepCallback_8069AA0(u8 taskId)
{
    bool8 isFortreeBridgeCur;
    bool8 isFortreeBridgePrev;
    u8 z, flag;
    s16 x, y, x2, y2;
    s16 *data = gTasks[taskId].data;
    PlayerGetDestCoords(&x, &y);
    switch (data[1])
    {
        default:
            break;
        case 0:
            data[2] = x;
            data[3] = y;
            if (MetatileBehavior_IsFortreeBridge(MapGridGetMetatileBehaviorAt(x, y)))
            {
                sub_809DE28(x, y);
                CurrentMapDrawMetatileAt(x, y);
            }
            data[1] = 1;
            break;
        case 1:
            x2 = data[2];
            y2 = data[3];
            if (x == x2 && y == y2)
            {
                break;
            }
            isFortreeBridgeCur = MetatileBehavior_IsFortreeBridge(MapGridGetMetatileBehaviorAt(x, y));
            isFortreeBridgePrev = MetatileBehavior_IsFortreeBridge(MapGridGetMetatileBehaviorAt(x2, y2));
            z = PlayerGetZCoord();
            flag = 0;
            if ((u8)(z & 1) == 0)
            {
                flag = 1;
            }
            if (flag && (isFortreeBridgeCur == 1 || isFortreeBridgePrev == 1))
            {
                PlaySE(SE_HASHI);
            }
            if (isFortreeBridgePrev)
            {
                sub_809DE8C(x2, y2);
                CurrentMapDrawMetatileAt(x2, y2);
                sub_809DE28(x, y);
                CurrentMapDrawMetatileAt(x, y);
            }
            data[4] = x2;
            data[5] = y2;
            data[2] = x;
            data[3] = y;
            if (!isFortreeBridgePrev)
            {
                break;
            }
            data[6] = 16;
            data[1] = 2;
            // fallthrough
        case 2:
            data[6]--;
            x2 = data[4];
            y2 = data[5];
            switch (data[6] % 7)
            {
                case 0:
                    CurrentMapDrawMetatileAt(x2, y2);
                case 1:
                case 2:
                case 3:
                    break;
                case 4:
                    sub_809DE28(x2, y2);
                    CurrentMapDrawMetatileAt(x2, y2);
                    sub_809DE8C(x2, y2);
                case 5:
                case 6:
                case 7:
                    break;
            }
            if (data[6] == 0)
            {
                data[1] = 1;
            }
            break;
    }
}

static bool32 sub_809E108(s16 x, s16 y)
{
    if ((u16)(x - 3) < 11 && (u16)(y - 6) < 14 && gUnknown_085103C8[y])
        return TRUE;
    else
        return FALSE;
}

static void sub_809E14C(s16 x, s16 y)
{
    if (sub_809E108(x, y))
        *GetVarPointer(gUnknown_085103C8[y]) |= (1 << (x - 3));
}

static bool32 sub_809E184(s16 x, s16 y)
{
    u32 var;
    if (!sub_809E108(x, y))
        return FALSE;

    var = VarGet(gUnknown_085103C8[y]) << 16;
    if (((1 << 16) << (x - 3)) & var) // TODO: fix that if
        return TRUE;
    else
        return FALSE;
}

void SetSootopolisGymCrackedIceMetatiles(void)
{
    s32 x, y;
    s32 width = gMapHeader.mapLayout->width;
    s32 height = gMapHeader.mapLayout->height;
    for (x = 0; x < width; x++)
    {
        for (y = 0; y < height; y++)
        {
            if (sub_809E184(x, y) == TRUE)
            {
                MapGridSetMetatileIdAt(x + 7, y + 7, 0x20e);
            }
        }
    }
}

static void PerStepCallback_8069DD4(u8 taskId)
{
    s16 x, y;
    u16 tileBehavior;
    u16 *var;
    s16 *data = gTasks[taskId].data;
    switch (data[1])
    {
        case 0:
            PlayerGetDestCoords(&x, &y);
            data[2] = x;
            data[3] = y;
            data[1] = 1;
            break;
        case 1:
            PlayerGetDestCoords(&x, &y);
            if (x != data[2] || y != data[3])
            {
                data[2] = x;
                data[3] = y;
                tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
                var = GetVarPointer(VAR_ICE_STEP_COUNT);
                if (MetatileBehavior_IsThinIce(tileBehavior) == TRUE)
                {
                    (*var)++;
                    data[6] = 4;
                    data[1] = 2;
                    data[4] = x;
                    data[5] = y;
                }
                else if (MetatileBehavior_IsCrackedIce(tileBehavior) == TRUE)
                {
                    *var = 0;
                    data[6] = 4;
                    data[1] = 3;
                    data[4] = x;
                    data[5] = y;
                }
            }
            break;
        case 2:
            if (data[6] != 0)
            {
                data[6]--;
            }
            else
            {
                x = data[4];
                y = data[5];
                PlaySE(SE_RU_BARI);
                MapGridSetMetatileIdAt(x, y, 0x20e);
                CurrentMapDrawMetatileAt(x, y);
                sub_809E14C(x - 7, y - 7);
                data[1] = 1;
            }
            break;
        case 3:
            if (data[6] != 0)
            {
                data[6]--;
            }
            else
            {
                x = data[4];
                y = data[5];
                PlaySE(SE_RU_GASYAN);
                MapGridSetMetatileIdAt(x, y, 0x206);
                CurrentMapDrawMetatileAt(x, y);
                data[1] = 1;
            }
            break;
    }
}

static void PerStepCallback_8069F64(u8 taskId)
{
    s16 x, y;
    u16 *var;
    s16 *data = gTasks[taskId].data;
    PlayerGetDestCoords(&x, &y);
    if (x != data[1] || y != data[2])
    {
        data[1] = x;
        data[2] = y;
        if (MetatileBehavior_IsAshGrass(MapGridGetMetatileBehaviorAt(x, y)))
        {
            if (MapGridGetMetatileIdAt(x, y) == 0x20a)
            {
                StartAshFieldEffect(x, y, 0x212, 4);
            }
            else
            {
                StartAshFieldEffect(x, y, 0x206, 4);
            }
            if (CheckBagHasItem(ITEM_SOOT_SACK, 1))
            {
                var = GetVarPointer(VAR_ASH_GATHER_COUNT);
                if (*var < 9999)
                {
                    (*var)++;
                }
            }
        }
    }
}

static void sub_809E490(s16 x, s16 y)
{
    MapGridSetMetatileIdAt(x, y, MapGridGetMetatileIdAt(x, y) == 0x22f ? 0x206 : 0x237);
    CurrentMapDrawMetatileAt(x, y);
}

static void PerStepCallback_806A07C(u8 taskId)
{
    s16 x, y;
    u16 behavior;
    s16 *data = gTasks[taskId].data;
    PlayerGetDestCoords(&x, &y);
    behavior = MapGridGetMetatileBehaviorAt(x, y);
    if (data[4] != 0 && (--data[4]) == 0)
    {
        sub_809E490(data[5], data[6]);
    }
    if (data[7] != 0 && (--data[7]) == 0)
    {
        sub_809E490(data[8], data[9]);
    }
    if (MetatileBehavior_IsCrackedFloorHole(behavior))
    {
        VarSet(VAR_ICE_STEP_COUNT, 0); // this var does double duty
    }
    if ((x != data[2] || y != data[3]))
    {
        data[2] = x;
        data[3] = y;
        if (MetatileBehavior_IsCrackedFloor(behavior))
        {
            if (GetPlayerSpeed() != 4)
            {
                VarSet(VAR_ICE_STEP_COUNT, 0); // this var does double duty
            }
            if (data[4] == 0)
            {
                data[4] = 3;
                data[5] = x;
                data[6] = y;
            }
            else if (data[7] == 0)
            {
                data[7] = 3;
                data[8] = x;
                data[9] = y;
            }
        }
    }
}

static void sub_809E5DC(s16 *data, s16 x, s16 y)
{
    u16 tile;
    if ((--data[0]) == 0)
    {
        tile = 0xe8;
    }
    else
    {
        tile = gUnknown_085103FC[data[0] / 8];
    }
    MapGridSetMetatileIdAt(x, y, tile);
    CurrentMapDrawMetatileAt(x, y);
    MapGridSetMetatileIdAt(x, y, 0xe8);
}

static void Task_MuddySlope(u8 taskId)
{
    s16 x, y, x2, y2;
    int i;
    u16 mapIndices;
    s16 *data = gTasks[taskId].data;
    PlayerGetDestCoords(&x, &y);
    mapIndices = (gSaveBlock1Ptr->location.mapGroup << 8) | gSaveBlock1Ptr->location.mapNum;
    switch (data[1])
    {
        case 0:
            data[0] = mapIndices;
            data[2] = x;
            data[3] = y;
            data[1] = 1;
            data[4] = 0;
            data[7] = 0;
            data[10] = 0;
            data[13] = 0;
            break;
        case 1:
            if (data[2] != x || data[3] != y)
            {
                data[2] = x;
                data[3] = y;
                if (MetatileBehavior_IsMuddySlope(MapGridGetMetatileBehaviorAt(x, y)))
                {
                    for (i=4; i<14; i+=3)
                    {
                        if (data[i] == 0)
                        {
                            data[i] = 32;
                            data[i + 1] = x;
                            data[i + 2] = y;
                            break;
                        }
                    }
                }
            }
            break;
    }
    if (gCamera.active && mapIndices != data[0])
    {
        data[0] = mapIndices;
        x2 = gCamera.x;
        y2 = gCamera.y;
    }
    else
    {
        x2 = 0;
        y2 = 0;
    }
    for (i = 4; i < 14; i += 3)
    {
        if (data[i])
        {
            data[i + 1] -= x2;
            data[i + 2] -= y2;
            sub_809E5DC(&data[i], data[i + 1], data[i + 2]);
        }
    }
}
