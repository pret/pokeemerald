#include "global.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "malloc.h"
#include "mossdeep_gym.h"
#include "script_movement.h"
#include "constants/event_object_movement_constants.h"
#include "constants/event_objects.h"

// Movement scripts.
extern const u8 gUnknown_08612698[];
extern const u8 gUnknown_0861269C[];
extern const u8 gUnknown_086126A0[];
extern const u8 gUnknown_086126A4[];
extern const u8 gUnknown_086126A8[];
extern const u8 gUnknown_086126AA[];
extern const u8 gUnknown_086126AC[];
extern const u8 gUnknown_086126AE[];

struct MossdeepSubStruct
{
    u8 unk0;
    u8 eventTemplateId;
};

struct MossdeepStruct
{
    struct MossdeepSubStruct objects[EVENT_OBJECTS_COUNT];
    u8 count;
    bool8 unk41;
};

// This file's functions.
static void AddEventObject(u8 eventTemplateId, u8 arg1);
static void sub_81A8D94(u8 eventTemplateId, u8 arg1);

// EWRAM vars
EWRAM_DATA static struct MossdeepStruct *gUnknown_0203CE50 = NULL;

// code
void InitMossdeepGymTiles(bool8 arg0)
{
    if (gUnknown_0203CE50 == NULL)
        gUnknown_0203CE50 = AllocZeroed(sizeof(*gUnknown_0203CE50));

    gUnknown_0203CE50->unk41 = arg0;
}

void FinishMossdeepGymTiles(void)
{
    u8 id;

    if (gUnknown_0203CE50 != NULL)
        FREE_AND_SET_NULL(gUnknown_0203CE50);

    id = GetEventObjectIdByLocalIdAndMap(EVENT_OBJ_ID_PLAYER, 0, 0);
    EventObjectClearHeldMovementIfFinished(&gEventObjects[id]);
    ScriptMovement_UnfreezeEventObjects();
}

u16 MossdeepGym_MoveEvents(u8 arg0)
{
    u8 i;
    struct EventObjectTemplate *events = gSaveBlock1Ptr->eventObjectTemplates;
    u16 localId = 0;

    for (i = 0; i < EVENT_OBJECT_TEMPLATES_COUNT; i++)
    {
        s32 var;
        u8 r5;
        s16 x = events[i].x + 7;
        s16 y = events[i].y + 7;
        u16 metatile = MapGridGetMetatileIdAt(x, y);

        if (!gUnknown_0203CE50->unk41)
            var = 0x250;
        else
            var = 0x298;

        if (metatile < 0x250)
            continue;

        if ((u8)((metatile - var) / 8) >= 5)
            continue;
        if ((u8)((metatile - var) / 8) != arg0)
            continue;

        r5 = (u8)((metatile - var) % 8);
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

            events[i].x += x;
            events[i].y += y;
            if (GetEventObjectIdByLocalIdAndMap(events[i].localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup) != EVENT_OBJECTS_COUNT)
            {
                AddEventObject(i, r5);
                localId = events[i].localId;
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
    s32 var;
    struct EventObjectTemplate *events;

    if (gUnknown_0203CE50 == NULL)
        return;

    if (!gUnknown_0203CE50->unk41)
        var = 0x250;
    else
        var = 0x298;

    events = gSaveBlock1Ptr->eventObjectTemplates;
    for (i = 0; i < gUnknown_0203CE50->count; i++)
    {
        s32 r6;
        s8 r0;
        u8 eventObjectId;
        s16 x = events[gUnknown_0203CE50->objects[i].eventTemplateId].x + 7;
        s16 y = events[gUnknown_0203CE50->objects[i].eventTemplateId].y + 7;
        u16 metatile = MapGridGetMetatileIdAt(x, y);

        r0 = (u8)((metatile - var) % 8);
        r0 -= (gUnknown_0203CE50->objects[i].unk0);
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

        eventObjectId = GetEventObjectIdByLocalIdAndMap(events[gUnknown_0203CE50->objects[i].eventTemplateId].localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
        if (eventObjectId != EVENT_OBJECTS_COUNT)
        {
            const u8 *movementScript;
            u8 direction = gEventObjects[eventObjectId].facingDirection;
            if (r6 == 0)
            {
                switch (direction)
                {
                case DIR_EAST:
                    movementScript = gUnknown_086126AE;
                    events[gUnknown_0203CE50->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_UP;
                    break;
                case DIR_SOUTH:
                    movementScript = gUnknown_086126A8;
                    events[gUnknown_0203CE50->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_RIGHT;
                    break;
                case DIR_WEST:
                    movementScript = gUnknown_086126AA;
                    events[gUnknown_0203CE50->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_DOWN;
                    break;
                case DIR_NORTH:
                    movementScript = gUnknown_086126AC;
                    events[gUnknown_0203CE50->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_LEFT;
                    break;
                default:
                    continue;
                }
                ScriptMovement_StartObjectMovementScript(events[gUnknown_0203CE50->objects[i].eventTemplateId].localId,
                                                         gSaveBlock1Ptr->location.mapNum,
                                                         gSaveBlock1Ptr->location.mapGroup,
                                                         movementScript);
            }
            else if (r6 == 1)
            {
                switch (direction)
                {
                case DIR_EAST:
                    movementScript = gUnknown_086126AA;
                    events[gUnknown_0203CE50->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_DOWN;
                    break;
                case DIR_SOUTH:
                    movementScript = gUnknown_086126AC;
                    events[gUnknown_0203CE50->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_LEFT;
                    break;
                case DIR_WEST:
                    movementScript = gUnknown_086126AE;
                    events[gUnknown_0203CE50->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_UP;
                    break;
                case DIR_NORTH:
                    movementScript = gUnknown_086126A8;
                    events[gUnknown_0203CE50->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_RIGHT;
                    break;
                default:
                    continue;
                }
                ScriptMovement_StartObjectMovementScript(events[gUnknown_0203CE50->objects[i].eventTemplateId].localId,
                                                         gSaveBlock1Ptr->location.mapNum,
                                                         gSaveBlock1Ptr->location.mapGroup,
                                                         movementScript);
            }
        }
    }
}

static void AddEventObject(u8 eventTemplateId, u8 arg1)
{
    gUnknown_0203CE50->objects[gUnknown_0203CE50->count].eventTemplateId = eventTemplateId;
    gUnknown_0203CE50->objects[gUnknown_0203CE50->count].unk0 = arg1;
    gUnknown_0203CE50->count++;
}

static void sub_81A8D94(u8 eventTemplateId, u8 arg1)
{
    s8 r0;
    s32 r6;
    s32 var;
    u16 movementType;
    struct EventObjectTemplate *events = gSaveBlock1Ptr->eventObjectTemplates;
    s16 x = events[eventTemplateId].x + 7;
    s16 y = events[eventTemplateId].y + 7;
    u16 metatile = MapGridGetMetatileIdAt(x, y);

    if (!gUnknown_0203CE50->unk41)
        var = 0x250;
    else
        var = 0x298;

    r0 = (u8)((metatile - var) % 8);
    r0 -= arg1;
    if (r0 < 0 || r0 == 3)
        r6 = 0;
    else if (r0 > 0 || r0 == -3)
        r6 = 1;
    else
        r6 = 2;

    movementType = events[eventTemplateId].movementType;
    if (r6 == 0)
    {
        switch (movementType)
        {
        case MOVEMENT_TYPE_FACE_RIGHT:
            events[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_UP;
            break;
        case MOVEMENT_TYPE_FACE_DOWN:
            events[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_RIGHT;
            break;
        case MOVEMENT_TYPE_FACE_LEFT:
            events[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_DOWN;
            break;
        case MOVEMENT_TYPE_FACE_UP:
            events[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_LEFT;
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
            events[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_DOWN;
            break;
        case MOVEMENT_TYPE_FACE_DOWN:
            events[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_LEFT;
            break;
        case MOVEMENT_TYPE_FACE_LEFT:
            events[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_UP;
            break;
        case MOVEMENT_TYPE_FACE_UP:
            events[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_RIGHT;
            break;
        default:
            break;
        }
    }
}
