#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_camera.h"
#include "field_screen_effect.h"
#include "field_specials.h"
#include "fieldmap.h"
#include "main.h"
#include "overworld.h"
#include "palette.h"
#include "script.h"
#include "script_movement.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/field_specials.h"
#include "constants/songs.h"
#include "constants/metatile_labels.h"

#define SECONDS(value) ((signed) (60.0 * value + 0.5))

// porthole states
enum
{
    INIT_PORTHOLE,
    IDLE_CHECK,
    EXECUTE_MOVEMENT,
    EXIT_PORTHOLE,
};

//. rodata
static const s8 gTruckCamera_HorizontalTable[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, -1, -1, -1, 0};

static const u8 sSSTidalSailEastMovementScript[] = 
{
    MOVEMENT_ACTION_WALK_FAST_RIGHT, 
    MOVEMENT_ACTION_STEP_END
};

static const u8 sSSTidalSailWestMovementScript[] = 
{
    MOVEMENT_ACTION_WALK_FAST_LEFT, 
    MOVEMENT_ACTION_STEP_END
};

// .text
static void Task_Truck3(u8);

s16 GetTruckCameraBobbingY(int a1)
{
    if (!(a1 % 120))
        return -1;
    else if ((a1 % 10) <= 4)
        return 1;

    return 0;
}

s16 GetTruckBoxMovement(int a1) // for the box movement?
{
    if (!((a1 + 120) % 180))
        return -1;

    return 0;
}

void Task_Truck1(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s16 cameraXpan = 0, cameraYpan = 0;
    s16 box1, box2, box3;

    box1 = GetTruckBoxMovement(data[0] + 30) * 4; // top box.
    SetObjectEventSpritePosByLocalIdAndMap(1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, 3 - cameraXpan, box1 + 3);
    box2 = GetTruckBoxMovement(data[0]) * 2; // bottom left box.
    SetObjectEventSpritePosByLocalIdAndMap(2, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, -cameraXpan, box2 - 3);
    box3 = GetTruckBoxMovement(data[0]) * 4; // bottom right box.
    SetObjectEventSpritePosByLocalIdAndMap(3, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, -3 - cameraXpan, box3);

    if (++data[0] == SECONDS(500)) // this will never run
        data[0] = 0; // reset the timer if it gets stuck.

    cameraYpan = GetTruckCameraBobbingY(data[0]);
    SetCameraPanning(cameraXpan, cameraYpan);
}

void Task_Truck2(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s16 cameraYpan;
    s16 cameraXpan;
    s16 box1;
    s16 box2;
    s16 box3;

    data[0]++;
    data[2]++;

    if (data[0] > 5)
    {
        data[0] = 0;
        data[1]++;
    }
    if ((u16)data[1] == 19)
    {
        DestroyTask(taskId);
    }
    else
    {
        if (gTruckCamera_HorizontalTable[data[1]] == 2)
            gTasks[taskId].func = Task_Truck3;

        cameraXpan = gTruckCamera_HorizontalTable[data[1]];
        cameraYpan = GetTruckCameraBobbingY(data[2]);
        SetCameraPanning(cameraXpan, cameraYpan);
        box1 = GetTruckBoxMovement(data[2] + 30) * 4;
        SetObjectEventSpritePosByLocalIdAndMap(1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, 3 - cameraXpan, box1 + 3);
        box2 = GetTruckBoxMovement(data[2]) * 2;
        SetObjectEventSpritePosByLocalIdAndMap(2, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, -cameraXpan, box2 - 3);
        box3 = GetTruckBoxMovement(data[2]) * 4;
        SetObjectEventSpritePosByLocalIdAndMap(3, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, -3 - cameraXpan, box3);
    }
}

static void Task_Truck3(u8 taskId)
{
   s16 *data = gTasks[taskId].data;
   s16 cameraXpan;
   s16 cameraYpan;

   data[0]++;

   if (data[0] > 5)
   {
       data[0] = 0;
       data[1]++;
   }

   if ((u16)data[1] == 19)
   {
       DestroyTask(taskId);
   }
   else
   {
       cameraXpan = gTruckCamera_HorizontalTable[data[1]];
       cameraYpan = 0;
       SetCameraPanning(cameraXpan, 0);
       SetObjectEventSpritePosByLocalIdAndMap(1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, 3 - cameraXpan, cameraYpan + 3);
       SetObjectEventSpritePosByLocalIdAndMap(2, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, -cameraXpan, cameraYpan - 3);
       SetObjectEventSpritePosByLocalIdAndMap(3, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, -3 - cameraXpan, cameraYpan);
   }
}

void Task_HandleTruckSequence(u8 taskId)
{
   s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
        /*
        Each case has a timer which is handled with data[1], incrementing
        until it reaches the if function's condition, which sets the next task up.
        */
    case 0:
        data[1]++;
        if (data[1] == SECONDS(1.5))
        {
            SetCameraPanningCallback(NULL);
            data[1] = 0; // reset the timer.
            data[2] = CreateTask(Task_Truck1, 0xA);
            data[0] = 1; // run the next case.
            PlaySE(SE_TRUCK_MOVE);
        }
        break;
    case 1:
        data[1]++;
        if (data[1] == SECONDS(2.5))
        {
            FadeInFromBlack();
            data[1] = 0;
            data[0] = 2;
        }
        break;
    case 2:
        data[1]++;
        if (!gPaletteFade.active && data[1] > SECONDS(5))
        {
            data[1] = 0;
            DestroyTask(data[2]);
            data[3] = CreateTask(Task_Truck2, 0xA);
            data[0] = 3;
            PlaySE(SE_TRUCK_STOP);
        }
        break;
    case 3:
        if (!gTasks[data[3]].isActive) // is Truck2 no longer active (is Truck3 active?)
        {
            InstallCameraPanAheadCallback();
            data[1] = 0;
            data[0] = 4;
        }
        break;
    case 4:
        data[1]++;
        if (data[1] == 90)
        {
            PlaySE(SE_TRUCK_UNLOAD);
            data[1] = 0;
            data[0] = 5;
        }
        break;
    case 5:
        data[1]++;
        if (data[1] == 120)
        {
            MapGridSetMetatileIdAt(11, 8, METATILE_InsideOfTruck_ExitLight_Top);
            MapGridSetMetatileIdAt(11, 9, METATILE_InsideOfTruck_ExitLight_Mid);
            MapGridSetMetatileIdAt(11, 10, METATILE_InsideOfTruck_ExitLight_Bottom);
            DrawWholeMapView();
            PlaySE(SE_TRUCK_DOOR);
            DestroyTask(taskId);
            ScriptContext2_Disable();
        }
        break;
    }
}

void ExecuteTruckSequence(void)
{
    MapGridSetMetatileIdAt(11, 8, METATILE_InsideOfTruck_DoorClosedFloor_Top);
    MapGridSetMetatileIdAt(11, 9, METATILE_InsideOfTruck_DoorClosedFloor_Mid);
    MapGridSetMetatileIdAt(11, 10, METATILE_InsideOfTruck_DoorClosedFloor_Bottom);
    DrawWholeMapView();
    ScriptContext2_Enable();
    CpuFastFill(0, gPlttBufferFaded, 0x400);
    CreateTask(Task_HandleTruckSequence, 0xA);
}

void EndTruckSequence(u8 taskId)
{
    if (!FuncIsActiveTask(Task_HandleTruckSequence))
    {
        SetObjectEventSpritePosByLocalIdAndMap(1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, 3, 3);
        SetObjectEventSpritePosByLocalIdAndMap(2, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, 0, -3);
        SetObjectEventSpritePosByLocalIdAndMap(3, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, -3, 0);
    }
}

bool8 TrySetPortholeWarpDestination(void)
{
    s8 mapGroup, mapNum;
    s16 x, y;

    if (GetSSTidalLocation(&mapGroup, &mapNum, &x, &y) != SS_TIDAL_LOCATION_CURRENTS)
    {
        return FALSE;
    }
    else
    {
        SetWarpDestination(mapGroup, mapNum, -1, x, y);
        return TRUE;
    }
}

void Task_HandlePorthole(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *cruiseState = GetVarPointer(VAR_SS_TIDAL_STATE);
    struct WarpData *location = &gSaveBlock1Ptr->location;

    switch (data[0])
    {
    case INIT_PORTHOLE: // finish fading before making porthole finish.
        if (!gPaletteFade.active)
        {
            data[1] = 0;
            data[0] = EXECUTE_MOVEMENT; // execute movement before checking if should be exited. strange?
        }
        break;
    case IDLE_CHECK:
        if (JOY_NEW(A_BUTTON))
            data[1] = 1;
        if (!ScriptMovement_IsObjectMovementFinished(OBJ_EVENT_ID_PLAYER, location->mapNum, location->mapGroup))
            return;
        if (CountSSTidalStep(1) == TRUE)
        {
            if (*cruiseState == SS_TIDAL_DEPART_SLATEPORT)
                *cruiseState = SS_TIDAL_EXIT_CURRENTS_RIGHT;
            else
                *cruiseState = SS_TIDAL_EXIT_CURRENTS_LEFT;
            data[0] = EXIT_PORTHOLE;
            return;
        }
        data[0] = EXECUTE_MOVEMENT;
        //fallthrough
    case EXECUTE_MOVEMENT:
        if (data[1])
        {
            data[0] = EXIT_PORTHOLE;
            return;
        }

        if (*cruiseState == SS_TIDAL_DEPART_SLATEPORT)
        {
            ScriptMovement_StartObjectMovementScript(OBJ_EVENT_ID_PLAYER, location->mapNum, location->mapGroup, sSSTidalSailEastMovementScript);
            data[0] = IDLE_CHECK;
        }
        else
        {
            ScriptMovement_StartObjectMovementScript(OBJ_EVENT_ID_PLAYER, location->mapNum, location->mapGroup, sSSTidalSailWestMovementScript);
            data[0] = IDLE_CHECK;
        }
        break;
    case EXIT_PORTHOLE:
        FlagClear(FLAG_DONT_TRANSITION_MUSIC);
        FlagClear(FLAG_HIDE_MAP_NAME_POPUP);
        SetWarpDestinationToDynamicWarp(0);
        DoDiveWarp();
        DestroyTask(taskId);
        break;
    }
}

static void ShowSSTidalWhileSailing(void)
{
    u8 spriteId = AddPseudoObjectEvent(OBJ_EVENT_GFX_SS_TIDAL, SpriteCallbackDummy, 112, 80, 0);

    gSprites[spriteId].coordOffsetEnabled = FALSE;

    if (VarGet(VAR_SS_TIDAL_STATE) == SS_TIDAL_DEPART_SLATEPORT)
        StartSpriteAnim(&gSprites[spriteId], GetFaceDirectionAnimNum(DIR_EAST));
    else
        StartSpriteAnim(&gSprites[spriteId], GetFaceDirectionAnimNum(DIR_WEST));
}

void FieldCB_ShowPortholeView(void)
{
    ShowSSTidalWhileSailing();
    gObjectEvents[gPlayerAvatar.objectEventId].invisible = TRUE;
    FadeInFromBlack();
    CreateTask(Task_HandlePorthole, 80);
    ScriptContext2_Enable();
}

void LookThroughPorthole(void)
{
    FlagSet(FLAG_SYS_CRUISE_MODE);
    FlagSet(FLAG_DONT_TRANSITION_MUSIC);
    FlagSet(FLAG_HIDE_MAP_NAME_POPUP);
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
    TrySetPortholeWarpDestination();
    DoPortholeWarp();
}
