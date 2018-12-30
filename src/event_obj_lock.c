#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "event_obj_lock.h"
#include "script_movement.h"
#include "task.h"
#include "trainer_see.h"
#include "constants/event_objects.h"

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


void ScriptFreezeEventObjects(void)
{
    FreezeEventObjects();
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
    if (!task->data[1] && !gEventObjects[gSelectedEventObject].singleMovementActive)
    {
        FreezeEventObject(&gEventObjects[gSelectedEventObject]);
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

void LockSelectedEventObject(void)
{
    u8 taskId;
    FreezeEventObjectsExceptOne(gSelectedEventObject);
    taskId = CreateTask(sub_8098400, 80);
    if (!gEventObjects[gSelectedEventObject].singleMovementActive)
    {
        FreezeEventObject(&gEventObjects[gSelectedEventObject]);
        gTasks[taskId].data[1] = 1;
    }
}

void ScriptUnfreezeEventObjects(void)
{
    u8 playerObjectId = GetEventObjectIdByLocalIdAndMap(EVENT_OBJ_ID_PLAYER, 0, 0);
    EventObjectClearHeldMovementIfFinished(&gEventObjects[playerObjectId]);
    sub_80D338C();
    UnfreezeEventObjects();
}

void sub_8098524(void)
{
    u8 playerObjectId;

    if (gEventObjects[gSelectedEventObject].active)
        EventObjectClearHeldMovementIfFinished(&gEventObjects[gSelectedEventObject]);
    playerObjectId = GetEventObjectIdByLocalIdAndMap(EVENT_OBJ_ID_PLAYER, 0, 0);
    EventObjectClearHeldMovementIfFinished(&gEventObjects[playerObjectId]);
    sub_80D338C();
    UnfreezeEventObjects();
}

void sub_8098574(void)
{
    EventObjectFaceOppositeDirection(&gEventObjects[gSelectedEventObject], gSpecialVar_Facing);
}

void sub_809859C(void)
{
    EventObjectClearHeldMovementIfActive(&gEventObjects[gSelectedEventObject]);
}

static void sub_80985BC(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 eventObjectId = task->data[2];

    if (!task->data[0] && walkrun_is_standing_still() == TRUE)
    {
        sub_808B864();
        task->data[0] = 1;
    }
    if (!task->data[1] && !gEventObjects[eventObjectId].singleMovementActive)
    {
        FreezeEventObject(&gEventObjects[eventObjectId]);
        task->data[1] = 1;
    }
    if (task->data[0] && task->data[1])
        DestroyTask(taskId);
}

void sub_8098630(void)
{
    u8 trainerObjectId1, trainerObjectId2, taskId;
    trainerObjectId1 = GetChosenApproachingTrainerEventObjectId(0);
    if(gNoOfApproachingTrainers == 2)
    {
        trainerObjectId2 = GetChosenApproachingTrainerEventObjectId(1);
        sub_8098074(trainerObjectId1, trainerObjectId2);
        taskId = CreateTask(sub_80985BC, 80);
        gTasks[taskId].data[2] = trainerObjectId1;
        if(!gEventObjects[trainerObjectId1].singleMovementActive)
        {
            FreezeEventObject(&gEventObjects[trainerObjectId1]);
            gTasks[taskId].data[1] = 1;
        }
        taskId = CreateTask(sub_80985BC, 81);
        gTasks[taskId].data[2] = trainerObjectId2;
        if(!gEventObjects[trainerObjectId2].singleMovementActive)
        {
            FreezeEventObject(&gEventObjects[trainerObjectId2]);
            gTasks[taskId].data[1] = 1;
        }
    }
    else
    {
        FreezeEventObjectsExceptOne(trainerObjectId1);
        taskId = CreateTask(sub_80985BC, 80);
        gTasks[taskId].data[2] = trainerObjectId1;
        if(!gEventObjects[trainerObjectId1].singleMovementActive)
        {
            FreezeEventObject(&gEventObjects[trainerObjectId1]);
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
