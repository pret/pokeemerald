#include "global.h"
#include "event_data.h"
#include "field_map_obj.h"
#include "field_map_obj_helpers.h"
#include "field_player_avatar.h"
#include "map_obj_lock.h"
#include "script_movement.h"
#include "task.h"
#include "trainer_see.h"

bool8 walkrun_is_standing_still(void)
{
    if (gPlayerAvatar.tileTransitionState == T_TILE_TRANSITION)
        return FALSE;
    else
        return TRUE;
}

static void sub_80983A4(u8 taskId)
{
    if (walkrun_is_standing_still())
    {
        sub_808B864();
        DestroyTask(taskId);
    }
}

bool8 sub_80983C4(void)
{
    if (FuncIsActiveTask(sub_80983A4))
    {
        return FALSE;
    }
    else
    {
        sub_808BCF4();
        return TRUE;
    }
}


void ScriptFreezeMapObjects(void)
{
    FreezeMapObjects();
    CreateTask(sub_80983A4, 80);
}

static void sub_8098400(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (!task->data[0] && walkrun_is_standing_still() == TRUE)
    {
        sub_808B864();
        task->data[0] = 1;
    }
    if (!task->data[1] && !gMapObjects[gSelectedMapObject].mapobj_bit_1)
    {
        FreezeMapObject(&gMapObjects[gSelectedMapObject]);
        task->data[1] = 1;
    }
    if (task->data[0] && task->data[1])
        DestroyTask(taskId);
}

bool8 sub_809847C(void)
{
    if (FuncIsActiveTask(sub_8098400))
    {
        return FALSE;
    }
    else
    {
        sub_808BCF4();
        return TRUE;
    }
}

void LockSelectedMapObject(void)
{
    u8 taskId;
    FreezeMapObjectsExceptOne(gSelectedMapObject);
    taskId = CreateTask(sub_8098400, 80);
    if (!gMapObjects[gSelectedMapObject].mapobj_bit_1)
    {
        FreezeMapObject(&gMapObjects[gSelectedMapObject]);
        gTasks[taskId].data[1] = 1;
    }
}

void sub_80984F4(void)
{
    u8 objectId = GetFieldObjectIdByLocalIdAndMap(0xFF, 0, 0);
    FieldObjectClearAnimIfSpecialAnimFinished(&gMapObjects[objectId]);
    sub_80D338C();
    UnfreezeMapObjects();
}

void sub_8098524(void)
{
    u8 objectId;

    if (gMapObjects[gSelectedMapObject].active)
        FieldObjectClearAnimIfSpecialAnimFinished(&gMapObjects[gSelectedMapObject]);
    objectId = GetFieldObjectIdByLocalIdAndMap(0xFF, 0, 0);
    FieldObjectClearAnimIfSpecialAnimFinished(&gMapObjects[objectId]);
    sub_80D338C();
    UnfreezeMapObjects();
}

void sub_8098574(void)
{
    FieldObjectFaceOppositeDirection(&gMapObjects[gSelectedMapObject], gSpecialVar_Facing);
}

void sub_809859C(void)
{
    FieldObjectClearAnimIfSpecialAnimActive(&gMapObjects[gSelectedMapObject]);
}

static void sub_80985BC(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 mapObjectId = task->data[2];

    if (!task->data[0] && walkrun_is_standing_still() == TRUE)
    {
        sub_808B864();
        task->data[0] = 1;
    }
    if (!task->data[1] && !gMapObjects[mapObjectId].mapobj_bit_1)
    {
        FreezeMapObject(&gMapObjects[mapObjectId]);
        task->data[1] = 1;
    }
    if (task->data[0] && task->data[1])
        DestroyTask(taskId);
}

void sub_8098630(void)
{
    u8 trainerObjectId1, trainerObjectId2, taskId;
    trainerObjectId1 = GetChosenApproachingTrainerMapObjectId(0);
    if(gNoOfApproachingTrainers == 2)
    {
        trainerObjectId2 = GetChosenApproachingTrainerMapObjectId(1);
        sub_8098074(trainerObjectId1, trainerObjectId2);
        taskId = CreateTask(sub_80985BC, 80);
        gTasks[taskId].data[2] = trainerObjectId1;
        if(!gMapObjects[trainerObjectId1].mapobj_bit_1)
        {
            FreezeMapObject(&gMapObjects[trainerObjectId1]);
            gTasks[taskId].data[1] = 1;
        }
        taskId = CreateTask(sub_80985BC, 81);
        gTasks[taskId].data[2] = trainerObjectId2;
        if(!gMapObjects[trainerObjectId2].mapobj_bit_1)
        {
            FreezeMapObject(&gMapObjects[trainerObjectId2]);
            gTasks[taskId].data[1] = 1;
        }
    }
    else
    {
        FreezeMapObjectsExceptOne(trainerObjectId1);
        taskId = CreateTask(sub_80985BC, 80);
        gTasks[taskId].data[2] = trainerObjectId1;
        if(!gMapObjects[trainerObjectId1].mapobj_bit_1)
        {
            FreezeMapObject(&gMapObjects[trainerObjectId1]);
            gTasks[taskId].data[1] = 1;
        }
    }
}

bool8 sub_8098734(void)
{
    if (FuncIsActiveTask(sub_80985BC))
    {
        return FALSE;
    }
    else
    {
        sub_808BCF4();
        return TRUE;
    }
}
