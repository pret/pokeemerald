#include "global.h"
#include "event_data.h"
#include "event_object_lock.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "script_movement.h"
#include "task.h"
#include "trainer_see.h"
#include "constants/event_objects.h"

bool8 IsPlayerStandingStill(void)
{
    if (gPlayerAvatar.tileTransitionState == T_TILE_TRANSITION)
        return FALSE;
    else
        return TRUE;
}

static void sub_80983A4(u8 taskId)
{
    if (IsPlayerStandingStill())
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


void ScriptFreezeObjectEvents(void)
{
    FreezeObjectEvents();
    CreateTask(sub_80983A4, 80);
}

static void sub_8098400(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (!task->data[0] && IsPlayerStandingStill() == TRUE)
    {
        sub_808B864();
        task->data[0] = 1;
    }
    if (!task->data[1] && !gObjectEvents[gSelectedObjectEvent].singleMovementActive)
    {
        FreezeObjectEvent(&gObjectEvents[gSelectedObjectEvent]);
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

void LockSelectedObjectEvent(void)
{
    u8 taskId;
    FreezeObjectEventsExceptOne(gSelectedObjectEvent);
    taskId = CreateTask(sub_8098400, 80);
    if (!gObjectEvents[gSelectedObjectEvent].singleMovementActive)
    {
        FreezeObjectEvent(&gObjectEvents[gSelectedObjectEvent]);
        gTasks[taskId].data[1] = 1;
    }
}

void ScriptUnfreezeObjectEvents(void)
{
    u8 playerObjectId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
    ObjectEventClearHeldMovementIfFinished(&gObjectEvents[playerObjectId]);
    ScriptMovement_UnfreezeObjectEvents();
    UnfreezeObjectEvents();
}

void UnionRoom_UnlockPlayerAndChatPartner(void)
{
    u8 playerObjectId;

    if (gObjectEvents[gSelectedObjectEvent].active)
        ObjectEventClearHeldMovementIfFinished(&gObjectEvents[gSelectedObjectEvent]);
    playerObjectId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
    ObjectEventClearHeldMovementIfFinished(&gObjectEvents[playerObjectId]);
    ScriptMovement_UnfreezeObjectEvents();
    UnfreezeObjectEvents();
}

void Script_FacePlayer(void)
{
    ObjectEventFaceOppositeDirection(&gObjectEvents[gSelectedObjectEvent], gSpecialVar_Facing);
}

void Script_ClearHeldMovement(void)
{
    ObjectEventClearHeldMovementIfActive(&gObjectEvents[gSelectedObjectEvent]);
}

static void sub_80985BC(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 objectEventId = task->data[2];

    if (!task->data[0] && IsPlayerStandingStill() == TRUE)
    {
        sub_808B864();
        task->data[0] = 1;
    }
    if (!task->data[1] && !gObjectEvents[objectEventId].singleMovementActive)
    {
        FreezeObjectEvent(&gObjectEvents[objectEventId]);
        task->data[1] = 1;
    }
    if (task->data[0] && task->data[1])
        DestroyTask(taskId);
}

void sub_8098630(void)
{
    u8 trainerObjectId1, trainerObjectId2, taskId;
    trainerObjectId1 = GetChosenApproachingTrainerObjectEventId(0);
    if(gNoOfApproachingTrainers == 2)
    {
        trainerObjectId2 = GetChosenApproachingTrainerObjectEventId(1);
        sub_8098074(trainerObjectId1, trainerObjectId2);
        taskId = CreateTask(sub_80985BC, 80);
        gTasks[taskId].data[2] = trainerObjectId1;
        if(!gObjectEvents[trainerObjectId1].singleMovementActive)
        {
            FreezeObjectEvent(&gObjectEvents[trainerObjectId1]);
            gTasks[taskId].data[1] = 1;
        }
        taskId = CreateTask(sub_80985BC, 81);
        gTasks[taskId].data[2] = trainerObjectId2;
        if(!gObjectEvents[trainerObjectId2].singleMovementActive)
        {
            FreezeObjectEvent(&gObjectEvents[trainerObjectId2]);
            gTasks[taskId].data[1] = 1;
        }
    }
    else
    {
        FreezeObjectEventsExceptOne(trainerObjectId1);
        taskId = CreateTask(sub_80985BC, 80);
        gTasks[taskId].data[2] = trainerObjectId1;
        if(!gObjectEvents[trainerObjectId1].singleMovementActive)
        {
            FreezeObjectEvent(&gObjectEvents[trainerObjectId1]);
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
