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

// Freeze player once their movement is finished
static void Task_FreezePlayer(u8 taskId)
{
    if (IsPlayerStandingStill())
    {
        PlayerFreeze();
        DestroyTask(taskId);
    }
}

bool8 IsFreezePlayerFinished(void)
{
    if (FuncIsActiveTask(Task_FreezePlayer))
    {
        return FALSE;
    }
    else
    {
        StopPlayerAvatar();
        return TRUE;
    }
}


void FreezeObjects_WaitForPlayer(void)
{
    FreezeObjectEvents();
    CreateTask(Task_FreezePlayer, 80);
}

#define tPlayerFrozen data[0]
#define tObjectFrozen data[1]
#define tObjectId     data[2]

// Freeze selected object and player once their movement is finished
static void Task_FreezeSelectedObjectAndPlayer(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (!task->tPlayerFrozen && IsPlayerStandingStill() == TRUE)
    {
        PlayerFreeze();
        task->tPlayerFrozen = TRUE;
    }
    if (!task->tObjectFrozen && !gObjectEvents[gSelectedObjectEvent].singleMovementActive)
    {
        FreezeObjectEvent(&gObjectEvents[gSelectedObjectEvent]);
        task->tObjectFrozen = TRUE;
    }
    if (task->tPlayerFrozen && task->tObjectFrozen)
        DestroyTask(taskId);
}

bool8 IsFreezeSelectedObjectAndPlayerFinished(void)
{
    if (FuncIsActiveTask(Task_FreezeSelectedObjectAndPlayer))
    {
        return FALSE;
    }
    else
    {
        StopPlayerAvatar();
        return TRUE;
    }
}

// Freeze all objects immediately except the selected object and the player.
// The selected object and player are frozen once their movement is finished.
void FreezeObjects_WaitForPlayerAndSelected(void)
{
    u8 taskId;
    FreezeObjectEventsExceptOne(gSelectedObjectEvent);
    taskId = CreateTask(Task_FreezeSelectedObjectAndPlayer, 80);
    if (!gObjectEvents[gSelectedObjectEvent].singleMovementActive)
    {
        FreezeObjectEvent(&gObjectEvents[gSelectedObjectEvent]);
        gTasks[taskId].tObjectFrozen = TRUE;
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

// Freeze designated object and player once their movement is finished
static void Task_FreezeObjectAndPlayer(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 objectEventId = task->tObjectId;

    if (!task->tPlayerFrozen && IsPlayerStandingStill() == TRUE)
    {
        PlayerFreeze();
        task->tPlayerFrozen = TRUE;
    }
    if (!task->tObjectFrozen && !gObjectEvents[objectEventId].singleMovementActive)
    {
        FreezeObjectEvent(&gObjectEvents[objectEventId]);
        task->tObjectFrozen = TRUE;
    }
    if (task->tPlayerFrozen && task->tObjectFrozen)
        DestroyTask(taskId);
}

// Freeze all objects immediately except the player and the approaching trainers.
// The approaching trainers and player are frozen once their movement is finished
void FreezeForApproachingTrainers(void)
{
    u8 trainerObjectId1, trainerObjectId2, taskId;
    trainerObjectId1 = GetChosenApproachingTrainerObjectEventId(0);

    if (gNoOfApproachingTrainers == 2)
    {
        // Get second trainer, freeze all other objects
        trainerObjectId2 = GetChosenApproachingTrainerObjectEventId(1);
        FreezeObjectEventsExceptTwo(trainerObjectId1, trainerObjectId2);

        // Start task to freeze trainer 1 (and player) after movement
        taskId = CreateTask(Task_FreezeObjectAndPlayer, 80);
        gTasks[taskId].tObjectId = trainerObjectId1;
        if (!gObjectEvents[trainerObjectId1].singleMovementActive)
        {
            FreezeObjectEvent(&gObjectEvents[trainerObjectId1]);
            gTasks[taskId].tObjectFrozen = TRUE;
        }

        // Start task to freeze trainer 2 after movement
        taskId = CreateTask(Task_FreezeObjectAndPlayer, 81);
        gTasks[taskId].tObjectId = trainerObjectId2;
        if (!gObjectEvents[trainerObjectId2].singleMovementActive)
        {
            FreezeObjectEvent(&gObjectEvents[trainerObjectId2]);
            gTasks[taskId].tObjectFrozen = TRUE;
        }
    }
    else
    {
        FreezeObjectEventsExceptOne(trainerObjectId1);
        taskId = CreateTask(Task_FreezeObjectAndPlayer, 80);
        gTasks[taskId].tObjectId = trainerObjectId1;
        if (!gObjectEvents[trainerObjectId1].singleMovementActive)
        {
            FreezeObjectEvent(&gObjectEvents[trainerObjectId1]);
            gTasks[taskId].tObjectFrozen = TRUE;
        }
    }
}

bool8 IsFreezeObjectAndPlayerFinished(void)
{
    if (FuncIsActiveTask(Task_FreezeObjectAndPlayer))
    {
        return FALSE;
    }
    else
    {
        StopPlayerAvatar();
        return TRUE;
    }
}

#undef tPlayerFrozen
#undef tObjectFrozen
#undef tObjectId
