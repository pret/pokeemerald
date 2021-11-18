#include "global.h"
#include "bike.h"
#include "clock.h"
#include "event_data.h"
#include "field_camera.h"
#include "field_effect_helpers.h"
#include "field_player_avatar.h"
#include "field_special_scene.h"
#include "field_tasks.h"
#include "fieldmap.h"
#include "item.h"
#include "main.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "script.h"
#include "secret_base.h"
#include "sound.h"
#include "task.h"
#include "constants/field_tasks.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "constants/metatile_labels.h"

struct PacifidlogMetatileOffsets
{
    s8 x;
    s8 y;
    u16 tileId;
};

static void DummyPerStepCallback(u8 taskId);
static void AshGrassPerStepCallback(u8 taskId);
static void FortreeBridgePerStepCallback(u8 taskId);
static void PacifidlogBridgePerStepCallback(u8 taskId);
static void SootopolisGymIcePerStepCallback(u8 taskId);
static void CrackedFloorPerStepCallback(u8 taskId);
static void Task_MuddySlope(u8 taskId);

static const TaskFunc sPerStepCallbacks[] =
{
    [STEP_CB_DUMMY]             = DummyPerStepCallback,
    [STEP_CB_ASH]               = AshGrassPerStepCallback,
    [STEP_CB_FORTREE_BRIDGE]    = FortreeBridgePerStepCallback,
    [STEP_CB_PACIFIDLOG_BRIDGE] = PacifidlogBridgePerStepCallback,
    [STEP_CB_SOOTOPOLIS_ICE]    = SootopolisGymIcePerStepCallback,
    [STEP_CB_TRUCK]             = EndTruckSequence,
    [STEP_CB_SECRET_BASE]       = SecretBasePerStepCallback,
    [STEP_CB_CRACKED_FLOOR]     = CrackedFloorPerStepCallback
};

// they are in pairs but declared as 1D array
static const struct PacifidlogMetatileOffsets sHalfSubmergedBridgeMetatileOffsets[] =
{
    { 0,  0, METATILE_Pacifidlog_HalfSubmergedLogs_Vertical0}, {0, 1, METATILE_Pacifidlog_HalfSubmergedLogs_Vertical1},
    { 0, -1, METATILE_Pacifidlog_HalfSubmergedLogs_Vertical0}, {0, 0, METATILE_Pacifidlog_HalfSubmergedLogs_Vertical1},
    { 0,  0, METATILE_Pacifidlog_HalfSubmergedLogs_Horizontal0}, {1, 0, METATILE_Pacifidlog_HalfSubmergedLogs_Horizontal1},
    {-1,  0, METATILE_Pacifidlog_HalfSubmergedLogs_Horizontal0}, {0, 0, METATILE_Pacifidlog_HalfSubmergedLogs_Horizontal1}
};

static const struct PacifidlogMetatileOffsets sFullySubmergedBridgeMetatileOffsets[] =
{
    { 0,  0, METATILE_Pacifidlog_SubmergedLogs_Vertical0}, {0, 1, METATILE_Pacifidlog_SubmergedLogs_Vertical1},
    { 0, -1, METATILE_Pacifidlog_SubmergedLogs_Vertical0}, {0, 0, METATILE_Pacifidlog_SubmergedLogs_Vertical1},
    { 0,  0, METATILE_Pacifidlog_SubmergedLogs_Horizontal0}, {1, 0, METATILE_Pacifidlog_SubmergedLogs_Horizontal1},
    {-1,  0, METATILE_Pacifidlog_SubmergedLogs_Horizontal0}, {0, 0, METATILE_Pacifidlog_SubmergedLogs_Horizontal1}
};

static const struct PacifidlogMetatileOffsets sFloatingBridgeMetatileOffsets[] =
{
    { 0,  0, METATILE_Pacifidlog_FloatingLogs_Vertical0}, {0, 1, METATILE_Pacifidlog_FloatingLogs_Vertical1},
    { 0, -1, METATILE_Pacifidlog_FloatingLogs_Vertical0}, {0, 0, METATILE_Pacifidlog_FloatingLogs_Vertical1},
    { 0,  0, METATILE_Pacifidlog_FloatingLogs_Horizontal0}, {1, 0, METATILE_Pacifidlog_FloatingLogs_Horizontal1},
    {-1,  0, METATILE_Pacifidlog_FloatingLogs_Horizontal0}, {0, 0, METATILE_Pacifidlog_FloatingLogs_Horizontal1}
};

// Each element corresponds to a y coordinate row in the sootopolis gym 1F map.
static const u16 sSootopolisGymIceRowVars[] =
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

static const u16 sMuddySlopeMetatiles[] = {
    METATILE_General_MuddySlope_Frame0,
    METATILE_General_MuddySlope_Frame3,
    METATILE_General_MuddySlope_Frame2,
    METATILE_General_MuddySlope_Frame1
};

static void Task_RunPerStepCallback(u8 taskId)
{
    int idx = gTasks[taskId].data[0];
    sPerStepCallbacks[idx](taskId);
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
        CreateTask(Task_MuddySlope, 0x50);

    if (!FuncIsActiveTask(Task_RunTimeBasedEvents))
        CreateTask(Task_RunTimeBasedEvents, 0x50);
}

void ActivatePerStepCallback(u8 callbackId)
{
    u8 taskId = FindTaskIdByFunc(Task_RunPerStepCallback);
    if (taskId != TASK_NONE)
    {
        s32 i;
        s16 *data = gTasks[taskId].data;

        for (i = 0; i < 16; i++)
            data[i] = 0;

        if (callbackId >= ARRAY_COUNT(sPerStepCallbacks))
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
    if (taskId != TASK_NONE)
    {
        data = gTasks[taskId].data;
    }
    taskId = FindTaskIdByFunc(Task_RunTimeBasedEvents);
    if (taskId != TASK_NONE)
    {
        data = gTasks[taskId].data;
        data[1] = 0;
        data[2] = 0;
    }
}

static void DummyPerStepCallback(u8 taskId)
{

}

static const struct PacifidlogMetatileOffsets *GetPacifidlogBridgeMetatileOffsets(const struct PacifidlogMetatileOffsets *offsets, u16 metatileBehavior)
{
    if (MetatileBehavior_IsPacifidlogVerticalLog1(metatileBehavior))
        return &offsets[0 * 2];
    else if (MetatileBehavior_IsPacifidlogVerticalLog2(metatileBehavior))
        return &offsets[1 * 2];
    else if (MetatileBehavior_IsPacifidlogHorizontalLog1(metatileBehavior))
        return &offsets[2 * 2];
    else if (MetatileBehavior_IsPacifidlogHorizontalLog2(metatileBehavior))
        return &offsets[3 * 2];
    else
        return NULL;
}

static void SetPacifidlogBridgeMetatiles(const struct PacifidlogMetatileOffsets *offsets, s16 x, s16 y, bool32 redrawMap)
{
    offsets = GetPacifidlogBridgeMetatileOffsets(offsets, MapGridGetMetatileBehaviorAt(x, y));
    if (offsets)
    {
        MapGridSetMetatileIdAt(x + offsets[0].x, y + offsets[0].y, offsets[0].tileId);
        if (redrawMap)
            CurrentMapDrawMetatileAt(x + offsets[0].x, y + offsets[0].y);

        MapGridSetMetatileIdAt(x + offsets[1].x, y + offsets[1].y, offsets[1].tileId);
        if (redrawMap)
            CurrentMapDrawMetatileAt(x + offsets[1].x, y + offsets[1].y);
    }
}

static void UpdateHalfSubmergedBridgeMetatiles(s16 x, s16 y, bool32 redrawMap)
{
    SetPacifidlogBridgeMetatiles(sHalfSubmergedBridgeMetatileOffsets, x, y, redrawMap);
}

static void UpdateFullySubmergedBridgeMetatiles(s16 x, s16 y, bool32 redrawMap)
{
    SetPacifidlogBridgeMetatiles(sFullySubmergedBridgeMetatileOffsets, x, y, redrawMap);
}

static void UpdateFloatingBridgeMetatiles(s16 x, s16 y, bool32 redrawMap)
{
    SetPacifidlogBridgeMetatiles(sFloatingBridgeMetatileOffsets, x, y, redrawMap);
}

static bool32 StandingOnNewPacifidlogBridge(s16 x1, s16 y1, s16 x2, s16 y2)
{
    u16 metatileBehavior = MapGridGetMetatileBehaviorAt(x2, y2);

    if (MetatileBehavior_IsPacifidlogVerticalLog1(metatileBehavior))
    {
        if (y1 > y2)
            return FALSE;
    }
    else if (MetatileBehavior_IsPacifidlogVerticalLog2(metatileBehavior))
    {
        if (y1 < y2)
            return FALSE;
    }
    else if (MetatileBehavior_IsPacifidlogHorizontalLog1(metatileBehavior))
    {
        if (x1 > x2)
            return FALSE;
    }
    else if (MetatileBehavior_IsPacifidlogHorizontalLog2(metatileBehavior))
    {
        if (x1 < x2)
            return FALSE;
    }
    return TRUE;
}

static bool32 StandingOnSamePacifidlogBridge(s16 x1, s16 y1, s16 x2, s16 y2)
{
    u16 metatileBehavior = MapGridGetMetatileBehaviorAt(x1, y1);

    if (MetatileBehavior_IsPacifidlogVerticalLog1(metatileBehavior))
    {
        if (y1 < y2)
            return FALSE;
    }
    else if (MetatileBehavior_IsPacifidlogVerticalLog2(metatileBehavior))
    {
        if (y1 > y2)
            return FALSE;
    }
    else if (MetatileBehavior_IsPacifidlogHorizontalLog1(metatileBehavior))
    {
        if (x1 < x2)
            return FALSE;
    }
    else if (MetatileBehavior_IsPacifidlogHorizontalLog2(metatileBehavior))
    {
        if (x1 > x2)
            return FALSE;
    }
    return TRUE;
}

static void PacifidlogBridgePerStepCallback(u8 taskId)
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
            UpdateFullySubmergedBridgeMetatiles(x, y, TRUE);
            data[1] = 1;
            break;
        case 1:
            if (x != data[2] || y != data[3])
            {
                if (StandingOnNewPacifidlogBridge(x, y, data[2], data[3]))
                {
                    UpdateHalfSubmergedBridgeMetatiles(data[2], data[3], TRUE);
                    UpdateFloatingBridgeMetatiles(data[2], data[3], FALSE);
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

                if (StandingOnSamePacifidlogBridge(x, y, data[2], data[3]))
                {
                    UpdateHalfSubmergedBridgeMetatiles(x, y, TRUE);
                    data[1] = 2;
                    data[6] = 8;
                }

                data[2] = x;
                data[3] = y;
                if (MetatileBehavior_IsPacifidlogLog(MapGridGetMetatileBehaviorAt(x, y)))
                    PlaySE(SE_PUDDLE);
            }
            break;
        case 2:
            if ((--data[6]) == 0)
            {
                UpdateFullySubmergedBridgeMetatiles(x, y, TRUE);
                if (data[4] != -1 && data[5] != -1)
                    UpdateFloatingBridgeMetatiles(data[4], data[5], TRUE);

                data[1] = 1;
            }
            break;
    }
}

static void SetLoweredForetreeBridgeMetatile(s16 x, s16 y)
{
    u8 z = PlayerGetZCoord();
    if (!(z & 1))
    {
        switch (MapGridGetMetatileIdAt(x, y))
        {
            case METATILE_Fortree_BridgeOverGrass_Raised:
                MapGridSetMetatileIdAt(x, y, METATILE_Fortree_BridgeOverGrass_Lowered);
                break;
            case METATILE_Fortree_BridgeOverTrees_Raised:
                MapGridSetMetatileIdAt(x, y, METATILE_Fortree_BridgeOverTrees_Lowered);
                break;
        }
    }
}

static void SetNormalFortreeBridgeMetatile(s16 x, s16 y)
{
    u8 z = PlayerGetZCoord();
    if (!(z & 1))
    {
        switch (MapGridGetMetatileIdAt(x, y))
        {
            case METATILE_Fortree_BridgeOverGrass_Lowered:
                MapGridSetMetatileIdAt(x, y, METATILE_Fortree_BridgeOverGrass_Raised);
                break;
            case METATILE_Fortree_BridgeOverTrees_Lowered:
                MapGridSetMetatileIdAt(x, y, METATILE_Fortree_BridgeOverTrees_Raised);
                break;
        }
    }
}

static void FortreeBridgePerStepCallback(u8 taskId)
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
                SetLoweredForetreeBridgeMetatile(x, y);
                CurrentMapDrawMetatileAt(x, y);
            }
            data[1] = 1;
            break;
        case 1:
            x2 = data[2];
            y2 = data[3];
            if (x == x2 && y == y2)
                break;

            isFortreeBridgeCur = MetatileBehavior_IsFortreeBridge(MapGridGetMetatileBehaviorAt(x, y));
            isFortreeBridgePrev = MetatileBehavior_IsFortreeBridge(MapGridGetMetatileBehaviorAt(x2, y2));
            z = PlayerGetZCoord();
            flag = 0;
            if ((u8)(z & 1) == 0)
                flag = 1;

            if (flag && (isFortreeBridgeCur == 1 || isFortreeBridgePrev == 1))
                PlaySE(SE_BRIDGE_WALK);

            if (isFortreeBridgePrev)
            {
                SetNormalFortreeBridgeMetatile(x2, y2);
                CurrentMapDrawMetatileAt(x2, y2);
                SetLoweredForetreeBridgeMetatile(x, y);
                CurrentMapDrawMetatileAt(x, y);
            }

            data[4] = x2;
            data[5] = y2;
            data[2] = x;
            data[3] = y;
            if (!isFortreeBridgePrev)
                break;

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
                    SetLoweredForetreeBridgeMetatile(x2, y2);
                    CurrentMapDrawMetatileAt(x2, y2);
                    SetNormalFortreeBridgeMetatile(x2, y2);
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

static bool32 CoordInIcePuzzleRegion(s16 x, s16 y)
{
    if ((u16)(x - 3) < 11 && (u16)(y - 6) < 14 && sSootopolisGymIceRowVars[y])
        return TRUE;
    else
        return FALSE;
}

static void MarkIcePuzzleCoordVisited(s16 x, s16 y)
{
    if (CoordInIcePuzzleRegion(x, y))
        *GetVarPointer(sSootopolisGymIceRowVars[y]) |= (1 << (x - 3));
}

static bool32 IsIcePuzzleCoordVisited(s16 x, s16 y)
{
    u32 var;
    if (!CoordInIcePuzzleRegion(x, y))
        return FALSE;

    var = VarGet(sSootopolisGymIceRowVars[y]) << 16;
    if ((0x10000 << (x - 3)) & var) // TODO: fix that if
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
            if (IsIcePuzzleCoordVisited(x, y) == TRUE)
                MapGridSetMetatileIdAt(x + MAP_OFFSET, y + MAP_OFFSET, METATILE_SootopolisGym_Ice_Cracked);
        }
    }
}

static void SootopolisGymIcePerStepCallback(u8 taskId)
{
    s16 x, y;
    u16 tileBehavior;
    u16 *iceStepCount;
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
                iceStepCount = GetVarPointer(VAR_ICE_STEP_COUNT);
                if (MetatileBehavior_IsThinIce(tileBehavior) == TRUE)
                {
                    (*iceStepCount)++;
                    data[6] = 4;
                    data[1] = 2;
                    data[4] = x;
                    data[5] = y;
                }
                else if (MetatileBehavior_IsCrackedIce(tileBehavior) == TRUE)
                {
                    *iceStepCount = 0;
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
                PlaySE(SE_ICE_CRACK);
                MapGridSetMetatileIdAt(x, y, METATILE_SootopolisGym_Ice_Cracked);
                CurrentMapDrawMetatileAt(x, y);
                MarkIcePuzzleCoordVisited(x - MAP_OFFSET, y - MAP_OFFSET);
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
                PlaySE(SE_ICE_BREAK);
                MapGridSetMetatileIdAt(x, y, METATILE_SootopolisGym_Ice_Broken);
                CurrentMapDrawMetatileAt(x, y);
                data[1] = 1;
            }
            break;
    }
}

static void AshGrassPerStepCallback(u8 taskId)
{
    s16 x, y;
    u16 *ashGatherCount;
    s16 *data = gTasks[taskId].data;
    PlayerGetDestCoords(&x, &y);
    if (x != data[1] || y != data[2])
    {
        data[1] = x;
        data[2] = y;
        if (MetatileBehavior_IsAshGrass(MapGridGetMetatileBehaviorAt(x, y)))
        {
            if (MapGridGetMetatileIdAt(x, y) == METATILE_Fallarbor_AshGrass)
                StartAshFieldEffect(x, y, METATILE_Fallarbor_NormalGrass, 4);
            else
                StartAshFieldEffect(x, y, METATILE_Lavaridge_NormalGrass, 4);

            if (CheckBagHasItem(ITEM_SOOT_SACK, 1))
            {
                ashGatherCount = GetVarPointer(VAR_ASH_GATHER_COUNT);
                if (*ashGatherCount < 9999)
                    (*ashGatherCount)++;
            }
        }
    }
}

// This function uses the constants for gTileset_Cave's metatile labels, but other tilesets with
// the CrackedFloorPerStepCallback callback use the same metatile numbers for the cracked floor
// and hole metatiles, such as gTileset_MirageTower.
static void SetCrackedFloorHoleMetatile(s16 x, s16 y)
{
    MapGridSetMetatileIdAt(x, y, MapGridGetMetatileIdAt(x, y) == METATILE_Cave_CrackedFloor ? METATILE_Cave_CrackedFloor_Hole : METATILE_Pacifidlog_SkyPillar_CrackedFloor_Hole);
    CurrentMapDrawMetatileAt(x, y);
}

static void CrackedFloorPerStepCallback(u8 taskId)
{
    s16 x, y;
    u16 behavior;
    s16 *data = gTasks[taskId].data;
    PlayerGetDestCoords(&x, &y);
    behavior = MapGridGetMetatileBehaviorAt(x, y);
    if (data[4] != 0 && (--data[4]) == 0)
        SetCrackedFloorHoleMetatile(data[5], data[6]);

    if (data[7] != 0 && (--data[7]) == 0)
        SetCrackedFloorHoleMetatile(data[8], data[9]);

    if (MetatileBehavior_IsCrackedFloorHole(behavior))
        VarSet(VAR_ICE_STEP_COUNT, 0); // this var does double duty

    if ((x != data[2] || y != data[3]))
    {
        data[2] = x;
        data[3] = y;
        if (MetatileBehavior_IsCrackedFloor(behavior))
        {
            if (GetPlayerSpeed() != 4)
                VarSet(VAR_ICE_STEP_COUNT, 0); // this var does double duty

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

static void SetMuddySlopeMetatile(s16 *data, s16 x, s16 y)
{
    u16 tile;
    if ((--data[0]) == 0)
        tile = METATILE_General_MuddySlope_Frame0;
    else
        tile = sMuddySlopeMetatiles[data[0] / 8];

    MapGridSetMetatileIdAt(x, y, tile);
    CurrentMapDrawMetatileAt(x, y);
    MapGridSetMetatileIdAt(x, y, METATILE_General_MuddySlope_Frame0);
}

static void Task_MuddySlope(u8 taskId)
{
    s16 x, y, x2, y2;
    int i;
    u16 mapId;
    s16 *data = gTasks[taskId].data;
    PlayerGetDestCoords(&x, &y);
    mapId = (gSaveBlock1Ptr->location.mapGroup << 8) | gSaveBlock1Ptr->location.mapNum;
    switch (data[1])
    {
        case 0:
            data[0] = mapId;
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
                    for (i = 4; i < 14; i += 3)
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
    if (gCamera.active && mapId != data[0])
    {
        data[0] = mapId;
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
            SetMuddySlopeMetatile(&data[i], data[i + 1], data[i + 2]);
        }
    }
}
