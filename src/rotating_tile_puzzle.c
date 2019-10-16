#include "global.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "malloc.h"
#include "rotating_tile_puzzle.h"
#include "script_movement.h"
#include "constants/event_object_movement_constants.h"
#include "constants/event_objects.h"
#include "constants/metatile_labels.h"

extern const u8 RotatingTilePuzzle_Movement_ShiftRight[];
extern const u8 RotatingTilePuzzle_Movement_ShiftDown[];
extern const u8 RotatingTilePuzzle_Movement_ShiftLeft[];
extern const u8 RotatingTilePuzzle_Movement_ShiftUp[];
extern const u8 RotatingTilePuzzle_Movement_FaceRight[];
extern const u8 RotatingTilePuzzle_Movement_FaceDown[];
extern const u8 RotatingTilePuzzle_Movement_FaceLeft[];
extern const u8 RotatingTilePuzzle_Movement_FaceUp[];

#define ROTATE_COUNTERCLOCKWISE 0
#define ROTATE_CLOCKWISE        1
#define ROTATE_NONE             2 

struct RotatingTileObject
{
    u8 prevPuzzleTileNum;
    u8 eventTemplateId;
};

struct RotatingTilePuzzle
{
    struct RotatingTileObject objects[EVENT_OBJECTS_COUNT];
    u8 numObjects;
    bool8 isTrickHouse;
};

// This file's functions.
static void SaveRotatingTileObject(u8 eventTemplateId, u8 arg1);
static void TurnUnsavedRotatingTileObject(u8 eventTemplateId, u8 arg1);

// EWRAM vars
EWRAM_DATA static struct RotatingTilePuzzle *sRotatingTilePuzzle = NULL;

// code
void InitRotatingTilePuzzle(bool8 isTrickHouse)
{
    if (sRotatingTilePuzzle == NULL)
        sRotatingTilePuzzle = AllocZeroed(sizeof(*sRotatingTilePuzzle));

    sRotatingTilePuzzle->isTrickHouse = isTrickHouse;
}

void FreeRotatingTilePuzzle(void)
{
    u8 id;

    if (sRotatingTilePuzzle != NULL)
        FREE_AND_SET_NULL(sRotatingTilePuzzle);

    id = GetEventObjectIdByLocalIdAndMap(EVENT_OBJ_ID_PLAYER, 0, 0);
    EventObjectClearHeldMovementIfFinished(&gEventObjects[id]);
    ScriptMovement_UnfreezeEventObjects();
}

u16 MoveRotatingTileObjects(u8 puzzleNumber)
{
    u8 i;
    struct EventObjectTemplate *eventObjects = gSaveBlock1Ptr->eventObjectTemplates;
    u16 localId = 0;

    for (i = 0; i < EVENT_OBJECT_TEMPLATES_COUNT; i++)
    {
        s32 puzzleTileStart;
        u8 puzzleTileNum;
        s16 x = eventObjects[i].x + 7;
        s16 y = eventObjects[i].y + 7;
        u16 metatile = MapGridGetMetatileIdAt(x, y);

        if (!sRotatingTilePuzzle->isTrickHouse)
            puzzleTileStart = METATILE_MossdeepGym_YellowArrow_Right;
        else
            puzzleTileStart = METATILE_TrickHousePuzzle_Arrow_YellowOnWhite_Right;

        // Object is on a metatile before the puzzle tile section
        // UB: Because this is not if (metatile < puzzleTileStart), for the trick house (metatile - puzzleTileStart) below can result in casting a negative value to u8 
        if (metatile < METATILE_MossdeepGym_YellowArrow_Right)
            continue;

        // Object is on a metatile after the puzzle tile section (never occurs, in both cases the puzzle tiles are last)
        if ((u8)((metatile - puzzleTileStart) / 8) >= 5)
            continue;

        // Object is on a metatile in puzzle tile section, but not one of the currently rotating color
        if ((u8)((metatile - puzzleTileStart) / 8) != puzzleNumber)
            continue;

        puzzleTileNum = (u8)((metatile - puzzleTileStart) % 8);

        // First 4 puzzle tiles are the colored arrows
        if (puzzleTileNum < 4)
        {
            s8 x = 0;
            s8 y = 0;
            const u8 *movementScript;

            switch (puzzleTileNum)
            {
            case 0: // Right Arrow
                movementScript = RotatingTilePuzzle_Movement_ShiftRight;
                x = 1;
                break;
            case 1: // Down Arrow
                movementScript = RotatingTilePuzzle_Movement_ShiftDown;
                y = 1;
                break;
            case 2: // Left Arrow
                movementScript = RotatingTilePuzzle_Movement_ShiftLeft;
                x = -1;
                break;
            case 3: // Up Arrow
                movementScript = RotatingTilePuzzle_Movement_ShiftUp;
                y = -1;
                break;
            default:
                continue;
            }

            eventObjects[i].x += x;
            eventObjects[i].y += y;
            if (GetEventObjectIdByLocalIdAndMap(eventObjects[i].localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup) != EVENT_OBJECTS_COUNT)
            {
                SaveRotatingTileObject(i, puzzleTileNum);
                localId = eventObjects[i].localId;
                ScriptMovement_StartObjectMovementScript(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, movementScript);
            }
            // Never reached in normal gameplay
            else
            {
                TurnUnsavedRotatingTileObject(i, puzzleTileNum);
            }
        }
    }

    return localId;
}

void TurnRotatingTileObjects(void)
{
    u8 i;
    s32 puzzleTileStart;
    struct EventObjectTemplate *eventObjects;

    if (sRotatingTilePuzzle == NULL)
        return;

    if (!sRotatingTilePuzzle->isTrickHouse)
        puzzleTileStart = METATILE_MossdeepGym_YellowArrow_Right;
    else
        puzzleTileStart = METATILE_TrickHousePuzzle_Arrow_YellowOnWhite_Right;

    eventObjects = gSaveBlock1Ptr->eventObjectTemplates;
    for (i = 0; i < sRotatingTilePuzzle->numObjects; i++)
    {
        s32 rotation;
        s8 tileDifference;
        u8 eventObjectId;
        s16 x = eventObjects[sRotatingTilePuzzle->objects[i].eventTemplateId].x + 7;
        s16 y = eventObjects[sRotatingTilePuzzle->objects[i].eventTemplateId].y + 7;
        u16 metatile = MapGridGetMetatileIdAt(x, y);

        // NOTE: The following 2 assignments and if else could all be replaced with rotation = ROTATE_COUNTERCLOCKWISE
        // For an object to be saved in sRotatingTilePuzzle->objects, it must have been on a colored arrow tile
        // After the first assignment, tileDifference will always be a number [0-3] representing which arrow tile the object is on now (0: right, 1: down, 2: left, 3: up)
        // prevPuzzleTileNum will similarly be a number [0-3] representing the arrow tile the object just moved from
        // All the puzzles are oriented counter-clockwise and can only move 1 step at a time, so the difference between the current tile and the previous tile will always either be -1 or 3 (0-1, 1-2, 2-3, 3-0)
        // Which means tileDifference will always either be -1 or 3 after the below subtraction, and rotation will always be ROTATE_COUNTERCLOCKWISE after the following conditionals
        tileDifference = (u8)((metatile - puzzleTileStart) % 8);
        tileDifference -= (sRotatingTilePuzzle->objects[i].prevPuzzleTileNum);
        
        // Always true, see above
        if (tileDifference < 0 || tileDifference == 3)
        {
            // Always false, see above
            if (tileDifference == -3)
                rotation = ROTATE_CLOCKWISE;
            else
                rotation = ROTATE_COUNTERCLOCKWISE;
        }
        else
        {
            if (tileDifference > 0)
                rotation = ROTATE_CLOCKWISE;
            else
                rotation = ROTATE_NONE;
        }

        eventObjectId = GetEventObjectIdByLocalIdAndMap(eventObjects[sRotatingTilePuzzle->objects[i].eventTemplateId].localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
        if (eventObjectId != EVENT_OBJECTS_COUNT)
        {
            const u8 *movementScript;
            u8 direction = gEventObjects[eventObjectId].facingDirection;
            if (rotation == ROTATE_COUNTERCLOCKWISE)
            {
                switch (direction)
                {
                case DIR_EAST:
                    movementScript = RotatingTilePuzzle_Movement_FaceUp;
                    eventObjects[sRotatingTilePuzzle->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_UP;
                    break;
                case DIR_SOUTH:
                    movementScript = RotatingTilePuzzle_Movement_FaceRight;
                    eventObjects[sRotatingTilePuzzle->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_RIGHT;
                    break;
                case DIR_WEST:
                    movementScript = RotatingTilePuzzle_Movement_FaceDown;
                    eventObjects[sRotatingTilePuzzle->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_DOWN;
                    break;
                case DIR_NORTH:
                    movementScript = RotatingTilePuzzle_Movement_FaceLeft;
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
            // Never reached
            else if (rotation == ROTATE_CLOCKWISE)
            {
                switch (direction)
                {
                case DIR_EAST:
                    movementScript = RotatingTilePuzzle_Movement_FaceDown;
                    eventObjects[sRotatingTilePuzzle->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_DOWN;
                    break;
                case DIR_SOUTH:
                    movementScript = RotatingTilePuzzle_Movement_FaceLeft;
                    eventObjects[sRotatingTilePuzzle->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_LEFT;
                    break;
                case DIR_WEST:
                    movementScript = RotatingTilePuzzle_Movement_FaceUp;
                    eventObjects[sRotatingTilePuzzle->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_UP;
                    break;
                case DIR_NORTH:
                    movementScript = RotatingTilePuzzle_Movement_FaceRight;
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

static void SaveRotatingTileObject(u8 eventTemplateId, u8 puzzleTileNum)
{
    sRotatingTilePuzzle->objects[sRotatingTilePuzzle->numObjects].eventTemplateId = eventTemplateId;
    sRotatingTilePuzzle->objects[sRotatingTilePuzzle->numObjects].prevPuzzleTileNum = puzzleTileNum;
    sRotatingTilePuzzle->numObjects++;
}

// Functionally unused
static void TurnUnsavedRotatingTileObject(u8 eventTemplateId, u8 puzzleTileNum)
{
    s8 tileDifference;
    s32 rotation;
    s32 puzzleTileStart;
    u16 movementType;
    struct EventObjectTemplate *eventObjects = gSaveBlock1Ptr->eventObjectTemplates;
    s16 x = eventObjects[eventTemplateId].x + 7;
    s16 y = eventObjects[eventTemplateId].y + 7;
    u16 metatile = MapGridGetMetatileIdAt(x, y);

    if (!sRotatingTilePuzzle->isTrickHouse)
        puzzleTileStart = METATILE_MossdeepGym_YellowArrow_Right;
    else
        puzzleTileStart = METATILE_TrickHousePuzzle_Arrow_YellowOnWhite_Right;

    tileDifference = (u8)((metatile - puzzleTileStart) % 8);
    tileDifference -= puzzleTileNum;

    if (tileDifference < 0 || tileDifference == 3)
        rotation = ROTATE_COUNTERCLOCKWISE;
    else if (tileDifference > 0 || tileDifference == -3)
        rotation = ROTATE_CLOCKWISE;
    else
        rotation = ROTATE_NONE;

    movementType = eventObjects[eventTemplateId].movementType;
    if (rotation == ROTATE_COUNTERCLOCKWISE)
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
    else if (rotation == ROTATE_CLOCKWISE)
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
