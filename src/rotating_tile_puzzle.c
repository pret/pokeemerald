#include "global.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "malloc.h"
#include "rotating_tile_puzzle.h"
#include "script_movement.h"
#include "constants/event_object_movement_constants.h"
#include "constants/event_objects.h"
#include "constants/metatile_labels.h"

// Movement scripts.
extern const u8 gUnknown_08612698[];
extern const u8 gUnknown_0861269C[];
extern const u8 gUnknown_086126A0[];
extern const u8 gUnknown_086126A4[];
extern const u8 MossdeepGym_Movement_FaceRight[];
extern const u8 MossdeepGym_Movement_FaceDown[];
extern const u8 MossdeepGym_Movement_FaceLeft[];
extern const u8 MossdeepGym_Movement_FaceUp[];

struct MossdeepSubStruct
{
    u8 unk0;
    u8 eventTemplateId;
};

struct RotatingTilePuzzle
{
    struct MossdeepSubStruct objects[EVENT_OBJECTS_COUNT];
    u8 count;
    bool8 isTrickHouse;
};

// This file's functions.
static void AddEventObject(u8 eventTemplateId, u8 arg1);
static void sub_81A8D94(u8 eventTemplateId, u8 arg1);

// EWRAM vars
EWRAM_DATA static struct RotatingTilePuzzle *sRotatingTilePuzzle = NULL;

// code
void InitRotatingTilePuzzle(bool8 isTrickHouse)
{
    if (sRotatingTilePuzzle == NULL)
        sRotatingTilePuzzle = AllocZeroed(sizeof(*sRotatingTilePuzzle));

    sRotatingTilePuzzle->isTrickHouse = isTrickHouse;
}

void FinishMossdeepGymTiles(void)
{
    u8 id;

    if (sRotatingTilePuzzle != NULL)
        FREE_AND_SET_NULL(sRotatingTilePuzzle);

    id = GetEventObjectIdByLocalIdAndMap(EVENT_OBJ_ID_PLAYER, 0, 0);
    EventObjectClearHeldMovementIfFinished(&gEventObjects[id]);
    ScriptMovement_UnfreezeEventObjects();
}

u16 MossdeepGym_MoveEvents(u8 puzzleNumber)
{
    u8 i;
    struct EventObjectTemplate *eventObjects = gSaveBlock1Ptr->eventObjectTemplates;
    u16 localId = 0;

    for (i = 0; i < EVENT_OBJECT_TEMPLATES_COUNT; i++)
    {
        s32 puzzleTileStart;
        u8 r5;
        s16 x = eventObjects[i].x + 7;
        s16 y = eventObjects[i].y + 7;
        u16 metatile = MapGridGetMetatileIdAt(x, y);

        if (!sRotatingTilePuzzle->isTrickHouse)
            puzzleTileStart = METATILE_MossdeepGym_YellowRightArrow;
        else
            puzzleTileStart = METATILE_TrickHousePuzzle_Arrow_YellowOnWhite_Right;

        if (metatile < METATILE_MossdeepGym_YellowRightArrow)
            continue;

        if ((u8)((metatile - puzzleTileStart) / 8) >= 5)
            continue;
        if ((u8)((metatile - puzzleTileStart) / 8) != puzzleNumber)
            continue;

        r5 = (u8)((metatile - puzzleTileStart) % 8);
        if (r5 < 4)
        {
            s8 x = 0;
            s8 y = 0;
            const u8 *movementScript;

            switch (r5)
            {
            case 0:
                movementScript = gUnknown_08612698;
                x = 1;
                break;
            case 1:
                movementScript = gUnknown_0861269C;
                y = 1;
                break;
            case 2:
                movementScript = gUnknown_086126A0;
                x = -1;
                break;
            case 3:
                movementScript = gUnknown_086126A4;
                y = -1;
                break;
            default:
                continue;
            }

            eventObjects[i].x += x;
            eventObjects[i].y += y;
            if (GetEventObjectIdByLocalIdAndMap(eventObjects[i].localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup) != EVENT_OBJECTS_COUNT)
            {
                AddEventObject(i, r5);
                localId = eventObjects[i].localId;
                ScriptMovement_StartObjectMovementScript(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, movementScript);
            }
            else
            {
                sub_81A8D94(i, r5);
            }
        }
    }

    return localId;
}

void MossdeepGym_TurnEvents(void)
{
    u8 i;
    s32 puzzleTileStart;
    struct EventObjectTemplate *eventObjects;

    if (sRotatingTilePuzzle == NULL)
        return;

    if (!sRotatingTilePuzzle->isTrickHouse)
        puzzleTileStart = METATILE_MossdeepGym_YellowRightArrow;
    else
        puzzleTileStart = METATILE_TrickHousePuzzle_Arrow_YellowOnWhite_Right;

    eventObjects = gSaveBlock1Ptr->eventObjectTemplates;
    for (i = 0; i < sRotatingTilePuzzle->count; i++)
    {
        s32 r6;
        s8 r0;
        u8 eventObjectId;
        s16 x = eventObjects[sRotatingTilePuzzle->objects[i].eventTemplateId].x + 7;
        s16 y = eventObjects[sRotatingTilePuzzle->objects[i].eventTemplateId].y + 7;
        u16 metatile = MapGridGetMetatileIdAt(x, y);

        r0 = (u8)((metatile - puzzleTileStart) % 8);
        r0 -= (sRotatingTilePuzzle->objects[i].unk0);
        if (r0 < 0 || r0 == 3)
        {
            if (r0 == -3)
                r6 = 1;
            else
                r6 = 0;
        }
        else
        {
            if (r0 > 0)
                r6 = 1;
            else
                r6 = 2;
        }

        eventObjectId = GetEventObjectIdByLocalIdAndMap(eventObjects[sRotatingTilePuzzle->objects[i].eventTemplateId].localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
        if (eventObjectId != EVENT_OBJECTS_COUNT)
        {
            const u8 *movementScript;
            u8 direction = gEventObjects[eventObjectId].facingDirection;
            if (r6 == 0)
            {
                switch (direction)
                {
                case DIR_EAST:
                    movementScript = MossdeepGym_Movement_FaceUp;
                    eventObjects[sRotatingTilePuzzle->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_UP;
                    break;
                case DIR_SOUTH:
                    movementScript = MossdeepGym_Movement_FaceRight;
                    eventObjects[sRotatingTilePuzzle->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_RIGHT;
                    break;
                case DIR_WEST:
                    movementScript = MossdeepGym_Movement_FaceDown;
                    eventObjects[sRotatingTilePuzzle->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_DOWN;
                    break;
                case DIR_NORTH:
                    movementScript = MossdeepGym_Movement_FaceLeft;
                    eventObjects[sRotatingTilePuzzle->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_LEFT;
                    break;
                default:
                    continue;
                }
                ScriptMovement_StartObjectMovementScript(eventObjects[sRotatingTilePuzzle->objects[i].eventTemplateId].localId,
                                                         gSaveBlock1Ptr->location.mapNum,
                                                         gSaveBlock1Ptr->location.mapGroup,
                                                         movementScript);
            }
            else if (r6 == 1)
            {
                switch (direction)
                {
                case DIR_EAST:
                    movementScript = MossdeepGym_Movement_FaceDown;
                    eventObjects[sRotatingTilePuzzle->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_DOWN;
                    break;
                case DIR_SOUTH:
                    movementScript = MossdeepGym_Movement_FaceLeft;
                    eventObjects[sRotatingTilePuzzle->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_LEFT;
                    break;
                case DIR_WEST:
                    movementScript = MossdeepGym_Movement_FaceUp;
                    eventObjects[sRotatingTilePuzzle->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_UP;
                    break;
                case DIR_NORTH:
                    movementScript = MossdeepGym_Movement_FaceRight;
                    eventObjects[sRotatingTilePuzzle->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_RIGHT;
                    break;
                default:
                    continue;
                }
                ScriptMovement_StartObjectMovementScript(eventObjects[sRotatingTilePuzzle->objects[i].eventTemplateId].localId,
                                                         gSaveBlock1Ptr->location.mapNum,
                                                         gSaveBlock1Ptr->location.mapGroup,
                                                         movementScript);
            }
        }
    }
}

static void AddEventObject(u8 eventTemplateId, u8 arg1)
{
    sRotatingTilePuzzle->objects[sRotatingTilePuzzle->count].eventTemplateId = eventTemplateId;
    sRotatingTilePuzzle->objects[sRotatingTilePuzzle->count].unk0 = arg1;
    sRotatingTilePuzzle->count++;
}

static void sub_81A8D94(u8 eventTemplateId, u8 arg1)
{
    s8 r0;
    s32 r6;
    s32 puzzleTileStart;
    u16 movementType;
    struct EventObjectTemplate *eventObjects = gSaveBlock1Ptr->eventObjectTemplates;
    s16 x = eventObjects[eventTemplateId].x + 7;
    s16 y = eventObjects[eventTemplateId].y + 7;
    u16 metatile = MapGridGetMetatileIdAt(x, y);

    if (!sRotatingTilePuzzle->isTrickHouse)
        puzzleTileStart = METATILE_MossdeepGym_YellowRightArrow;
    else
        puzzleTileStart = METATILE_TrickHousePuzzle_Arrow_YellowOnWhite_Right;

    r0 = (u8)((metatile - puzzleTileStart) % 8);
    r0 -= arg1;
    if (r0 < 0 || r0 == 3)
        r6 = 0;
    else if (r0 > 0 || r0 == -3)
        r6 = 1;
    else
        r6 = 2;

    movementType = eventObjects[eventTemplateId].movementType;
    if (r6 == 0)
    {
        switch (movementType)
        {
        case MOVEMENT_TYPE_FACE_RIGHT:
            eventObjects[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_UP;
            break;
        case MOVEMENT_TYPE_FACE_DOWN:
            eventObjects[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_RIGHT;
            break;
        case MOVEMENT_TYPE_FACE_LEFT:
            eventObjects[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_DOWN;
            break;
        case MOVEMENT_TYPE_FACE_UP:
            eventObjects[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_LEFT;
            break;
        default:
            break;
        }
    }
    else if (r6 == 1)
    {
        switch (movementType)
        {
        case MOVEMENT_TYPE_FACE_RIGHT:
            eventObjects[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_DOWN;
            break;
        case MOVEMENT_TYPE_FACE_DOWN:
            eventObjects[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_LEFT;
            break;
        case MOVEMENT_TYPE_FACE_LEFT:
            eventObjects[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_UP;
            break;
        case MOVEMENT_TYPE_FACE_UP:
            eventObjects[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_RIGHT;
            break;
        default:
            break;
        }
    }
}
