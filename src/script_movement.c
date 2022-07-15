#include "global.h"
#include "script_movement.h"
#include "event_object_movement.h"
#include "task.h"
#include "util.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"

static void ScriptMovement_StartMoveObjects(u8 priority);
static u8 GetMoveObjectsTaskId(void);
static bool8 ScriptMovement_TryAddNewMovement(u8 taskId, u8 objEventId, const u8 *movementScript);
static u8 GetMovementScriptIdFromObjectEventId(u8 taskId, u8 objEventId);
static bool8 IsMovementScriptFinished(u8 taskId, u8 moveScrId);
static void ScriptMovement_AddNewMovement(u8 taskId, u8 moveScrId, u8 objEventId, const u8 *movementScript);
static void ScriptMovement_UnfreezeActiveObjects(u8 taskId);
static void ScriptMovement_MoveObjects(u8 taskId);
static void ScriptMovement_TakeStep(u8 taskId, u8 moveScrId, u8 objEventId, const u8 *movementScript);

static EWRAM_DATA const u8 *sMovementScripts[OBJECT_EVENTS_COUNT] = {0};

bool8 ScriptMovement_StartObjectMovementScript(u8 localId, u8 mapNum, u8 mapGroup, const u8 *movementScript)
{
    u8 objEventId;

    if (TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objEventId))
        return TRUE;
    if (!FuncIsActiveTask(ScriptMovement_MoveObjects))
        ScriptMovement_StartMoveObjects(50);
    return ScriptMovement_TryAddNewMovement(GetMoveObjectsTaskId(), objEventId, movementScript);
}

bool8 ScriptMovement_IsObjectMovementFinished(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 objEventId;
    u8 taskId;
    u8 moveScrId;

    if (TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objEventId))
        return TRUE;
    taskId = GetMoveObjectsTaskId();
    moveScrId = GetMovementScriptIdFromObjectEventId(taskId, objEventId);
    if (moveScrId == OBJECT_EVENTS_COUNT)
        return TRUE;
    return IsMovementScriptFinished(taskId, moveScrId);
}

void ScriptMovement_UnfreezeObjectEvents(void)
{
    u8 taskId;

    taskId = GetMoveObjectsTaskId();
    if (taskId != TASK_NONE)
    {
        ScriptMovement_UnfreezeActiveObjects(taskId);
        DestroyTask(taskId);
    }
}

static void ScriptMovement_StartMoveObjects(u8 priority)
{
    u8 taskId;
    u8 i;

    taskId = CreateTask(ScriptMovement_MoveObjects, priority);

    for (i = 1; i < NUM_TASK_DATA; i++)
        gTasks[taskId].data[i] = 0xFFFF;
}

static u8 GetMoveObjectsTaskId(void)
{
    return FindTaskIdByFunc(ScriptMovement_MoveObjects);
}

static bool8 ScriptMovement_TryAddNewMovement(u8 taskId, u8 objEventId, const u8 *movementScript)
{
    u8 moveScrId;

    moveScrId = GetMovementScriptIdFromObjectEventId(taskId, objEventId);
    if (moveScrId != OBJECT_EVENTS_COUNT)
    {
        if (IsMovementScriptFinished(taskId, moveScrId) == 0)
        {
            return TRUE;
        }
        else
        {
            ScriptMovement_AddNewMovement(taskId, moveScrId, objEventId, movementScript);
            return FALSE;
        }
    }
    moveScrId = GetMovementScriptIdFromObjectEventId(taskId, OBJ_EVENT_ID_PLAYER);
    if (moveScrId == OBJECT_EVENTS_COUNT)
    {
        return TRUE;
    }
    else
    {
        ScriptMovement_AddNewMovement(taskId, moveScrId, objEventId, movementScript);
        return FALSE;
    }
}

static u8 GetMovementScriptIdFromObjectEventId(u8 taskId, u8 objEventId)
{
    u8 *moveScriptId;
    u8 i;

    moveScriptId = (u8 *)&gTasks[taskId].data[1];
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++, moveScriptId++)
    {
        if (*moveScriptId == objEventId)
            return i;
    }
    return OBJECT_EVENTS_COUNT;
}

static void LoadObjectEventIdPtrFromMovementScript(u8 taskId, u8 moveScrId, u8 **pObjEventId)
{
    u8 i;

    *pObjEventId = (u8 *)&gTasks[taskId].data[1];
    for (i = 0; i < moveScrId; i++, (*pObjEventId)++)
        ;
}

static void SetObjectEventIdAtMovementScript(u8 taskId, u8 moveScrId, u8 objEventId)
{
    u8 *ptr;

    LoadObjectEventIdPtrFromMovementScript(taskId, moveScrId, &ptr);
    *ptr = objEventId;
}

static void LoadObjectEventIdFromMovementScript(u8 taskId, u8 moveScrId, u8 *objEventId)
{
    u8 *ptr;

    LoadObjectEventIdPtrFromMovementScript(taskId, moveScrId, &ptr);
    *objEventId = *ptr;
}

static void ClearMovementScriptFinished(u8 taskId, u8 moveScrId)
{
    u16 mask = ~gBitTable[moveScrId];

    gTasks[taskId].data[0] &= mask;
}

static void SetMovementScriptFinished(u8 taskId, u8 moveScrId)
{
    gTasks[taskId].data[0] |= gBitTable[moveScrId];
}

static bool8 IsMovementScriptFinished(u8 taskId, u8 moveScrId)
{
    u16 moveScriptFinished = (u16)gTasks[taskId].data[0] & gBitTable[moveScrId];

    if (moveScriptFinished != 0)
        return TRUE;
    else
        return FALSE;
}

static void SetMovementScript(u8 moveScrId, const u8 *movementScript)
{
    sMovementScripts[moveScrId] = movementScript;
}

static const u8 *GetMovementScript(u8 moveScrId)
{
    return sMovementScripts[moveScrId];
}

static void ScriptMovement_AddNewMovement(u8 taskId, u8 moveScrId, u8 objEventId, const u8 *movementScript)
{
    ClearMovementScriptFinished(taskId, moveScrId);
    SetMovementScript(moveScrId, movementScript);
    SetObjectEventIdAtMovementScript(taskId, moveScrId, objEventId);
}

static void ScriptMovement_UnfreezeActiveObjects(u8 taskId)
{
    u8 *pObjEventId;
    u8 i;

    pObjEventId = (u8 *)&gTasks[taskId].data[1];
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++, pObjEventId++)
    {
        if (*pObjEventId != 0xFF)
            UnfreezeObjectEvent(&gObjectEvents[*pObjEventId]);
    }
}

static void ScriptMovement_MoveObjects(u8 taskId)
{
    u8 i;
    u8 objEventId;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        LoadObjectEventIdFromMovementScript(taskId, i, &objEventId);
        if (objEventId != 0xFF)
            ScriptMovement_TakeStep(taskId, i, objEventId, GetMovementScript(i));
    }
}

static void ScriptMovement_TakeStep(u8 taskId, u8 moveScrId, u8 objEventId, const u8 *movementScript)
{
    u8 nextMoveActionId;

    if (ObjectEventIsHeldMovementActive(&gObjectEvents[objEventId])
     && !ObjectEventClearHeldMovementIfFinished(&gObjectEvents[objEventId]))
        return;

    nextMoveActionId = *movementScript;
    if (nextMoveActionId == MOVEMENT_ACTION_STEP_END)
    {
        SetMovementScriptFinished(taskId, moveScrId);
        FreezeObjectEvent(&gObjectEvents[objEventId]);
    }
    else
    {
        if (!ObjectEventSetHeldMovement(&gObjectEvents[objEventId], nextMoveActionId))
        {
            movementScript++;
            SetMovementScript(moveScrId, movementScript);
        }
    }
}

