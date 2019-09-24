#include "global.h"
#include "script_movement.h"
#include "event_object_movement.h"
#include "task.h"
#include "util.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement_constants.h"

// static functions
static void ScriptMovement_StartMoveObjects(u8 priority);
static u8 GetMoveObjectsTaskId(void);
static bool8 ScriptMovement_TryAddNewMovement(u8 taskId, u8 eventObjId, const u8 *movementScript);
static u8 GetMovementScriptIdFromEventObjectId(u8 taskId, u8 eventObjId);
static bool8 IsMovementScriptFinished(u8 taskId, u8 moveScrId);
static void ScriptMovement_AddNewMovement(u8 taskId, u8 moveScrId, u8 eventObjId, const u8 *movementScript);
static void ScriptMovement_UnfreezeActiveObjects(u8 taskId);
static void ScriptMovement_MoveObjects(u8 taskId);
static void ScriptMovement_TakeStep(u8 taskId, u8 moveScrId, u8 eventObjId, const u8 *movementScript);

// EWRAM_DATA
static EWRAM_DATA const u8 *gMovementScripts[EVENT_OBJECTS_COUNT] = {0};

// text
bool8 ScriptMovement_StartObjectMovementScript(u8 localId, u8 mapNum, u8 mapGroup, const u8 *movementScript)
{
    u8 eventObjId;

    if (TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &eventObjId))
        return TRUE;
    if (!FuncIsActiveTask(ScriptMovement_MoveObjects))
        ScriptMovement_StartMoveObjects(50);
    return ScriptMovement_TryAddNewMovement(GetMoveObjectsTaskId(), eventObjId, movementScript);
}

bool8 ScriptMovement_IsObjectMovementFinished(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 eventObjId;
    u8 taskId;
    u8 moveScrId;

    if (TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &eventObjId))
        return TRUE;
    taskId = GetMoveObjectsTaskId();
    moveScrId = GetMovementScriptIdFromEventObjectId(taskId, eventObjId);
    if (moveScrId == EVENT_OBJECTS_COUNT)
        return TRUE;
    return IsMovementScriptFinished(taskId, moveScrId);
}

void ScriptMovement_UnfreezeEventObjects(void)
{
    u8 taskId;

    taskId = GetMoveObjectsTaskId();
    if (taskId != 0xFF)
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

static bool8 ScriptMovement_TryAddNewMovement(u8 taskId, u8 eventObjId, const u8 *movementScript)
{
    u8 moveScrId;

    moveScrId = GetMovementScriptIdFromEventObjectId(taskId, eventObjId);
    if (moveScrId != EVENT_OBJECTS_COUNT)
    {
        if (IsMovementScriptFinished(taskId, moveScrId) == 0)
        {
            return TRUE;
        }
        else
        {
            ScriptMovement_AddNewMovement(taskId, moveScrId, eventObjId, movementScript);
            return FALSE;
        }
    }
    moveScrId = GetMovementScriptIdFromEventObjectId(taskId, EVENT_OBJ_ID_PLAYER);
    if (moveScrId == EVENT_OBJECTS_COUNT)
    {
        return TRUE;
    }
    else
    {
        ScriptMovement_AddNewMovement(taskId, moveScrId, eventObjId, movementScript);
        return FALSE;
    }
}

static u8 GetMovementScriptIdFromEventObjectId(u8 taskId, u8 eventObjId)
{
    u8 *moveScriptId;
    u8 i;

    moveScriptId = (u8 *)&gTasks[taskId].data[1];
    for (i = 0; i < EVENT_OBJECTS_COUNT; i++, moveScriptId++)
    {
        if (*moveScriptId == eventObjId)
            return i;
    }
    return EVENT_OBJECTS_COUNT;
}

static void LoadEventObjectIdPtrFromMovementScript(u8 taskId, u8 moveScrId, u8 **pEventObjId)
{
    u8 i;

    *pEventObjId = (u8 *)&gTasks[taskId].data[1];
    for (i = 0; i < moveScrId; i++, (*pEventObjId)++)
        ;
}

static void SetEventObjectIdAtMovementScript(u8 taskId, u8 moveScrId, u8 eventObjId)
{
    u8 *ptr;

    LoadEventObjectIdPtrFromMovementScript(taskId, moveScrId, &ptr);
    *ptr = eventObjId;
}

static void LoadEventObjectIdFromMovementScript(u8 taskId, u8 moveScrId, u8 *eventObjId)
{
    u8 *ptr;

    LoadEventObjectIdPtrFromMovementScript(taskId, moveScrId, &ptr);
    *eventObjId = *ptr;
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
    gMovementScripts[moveScrId] = movementScript;
}

static const u8 *GetMovementScript(u8 moveScrId)
{
    return gMovementScripts[moveScrId];
}

static void ScriptMovement_AddNewMovement(u8 taskId, u8 moveScrId, u8 eventObjId, const u8 *movementScript)
{
    ClearMovementScriptFinished(taskId, moveScrId);
    SetMovementScript(moveScrId, movementScript);
    SetEventObjectIdAtMovementScript(taskId, moveScrId, eventObjId);
}

static void ScriptMovement_UnfreezeActiveObjects(u8 taskId)
{
    u8 *pEventObjId;
    u8 i;

    pEventObjId = (u8 *)&gTasks[taskId].data[1];
    for (i = 0; i < EVENT_OBJECTS_COUNT; i++, pEventObjId++)
    {
        if (*pEventObjId != 0xFF)
            UnfreezeEventObject(&gEventObjects[*pEventObjId]);
    }
}

static void ScriptMovement_MoveObjects(u8 taskId)
{
    u8 i;
    u8 eventObjId;

    for (i = 0; i < EVENT_OBJECTS_COUNT; i++)
    {
        LoadEventObjectIdFromMovementScript(taskId, i, &eventObjId);
        if (eventObjId != 0xFF)
            ScriptMovement_TakeStep(taskId, i, eventObjId, GetMovementScript(i));
    }
}

static void ScriptMovement_TakeStep(u8 taskId, u8 moveScrId, u8 eventObjId, const u8 *movementScript)
{
    u8 nextMoveActionId;

    if (EventObjectIsHeldMovementActive(&gEventObjects[eventObjId])
     && !EventObjectClearHeldMovementIfFinished(&gEventObjects[eventObjId]))
        return;

    nextMoveActionId = *movementScript;
    if (nextMoveActionId == MOVEMENT_ACTION_STEP_END)
    {
        SetMovementScriptFinished(taskId, moveScrId);
        FreezeEventObject(&gEventObjects[eventObjId]);
    }
    else
    {
        if (!EventObjectSetHeldMovement(&gEventObjects[eventObjId], nextMoveActionId))
        {
            movementScript++;
            SetMovementScript(moveScrId, movementScript);
        }
    }
}

