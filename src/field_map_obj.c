// Includes

#include "global.h"
#include "malloc.h"
#include "sprite.h"
#include "rom4.h"
#include "rng.h"
#include "data3.h"
#include "event_scripts.h"
#include "berry.h"
#include "palette.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "event_data.h"
#include "rom_818CFC8.h"
#include "rom_81BE66C.h"
#include "field_ground_effect.h"
#include "map_obj_8097404.h"
#include "mauville_old_man.h"
#include "metatile_behavior.h"
#include "field_effect.h"
#include "field_effect_helpers.h"
#include "field_camera.h"
#include "field_map_obj.h"

#define NUM_FIELD_MAP_OBJECT_TEMPLATES 0x51

#define null_object_step(name, retval) \
static bool8 FieldObjectCB2_##name(struct MapObject *, struct Sprite *);\
void FieldObjectCB_##name(struct Sprite *sprite)\
{\
    FieldObjectStep(&gMapObjects[sprite->data0], sprite, FieldObjectCB2_##name);\
}\
static bool8 FieldObjectCB2_##name(struct MapObject *mapObject, struct Sprite *sprite)\
{\
    return (retval);\
}

#define field_object_step(name, table) \
extern bool8 (*const (table)[])(struct MapObject *, struct Sprite *);\
static bool8 FieldObjectCB2_##name(struct MapObject *, struct Sprite *);\
void FieldObjectCB_##name(struct Sprite *sprite)\
{\
    FieldObjectStep(&gMapObjects[sprite->data0], sprite, FieldObjectCB2_##name);\
}\
static bool8 FieldObjectCB2_##name(struct MapObject *mapObject, struct Sprite *sprite)\
{\
    return (table)[sprite->data1](mapObject, sprite);\
}

#define field_object_path(idx, table, sub, path, catch, coord)\
field_object_step(GoInDirectionSequence##idx, table)\
extern const u8 path[4];\
bool8 sub(struct MapObject *mapObject, struct Sprite *sprite)\
{\
    u8 route[sizeof(path)];\
    memcpy(route, path, sizeof(path));\
    if (mapObject->mapobj_unk_21 == (catch) && mapObject->coords1.coord == mapObject->coords2.coord)\
    {\
        mapObject->mapobj_unk_21 = (catch) + 1;\
    }\
    return MoveFieldObjectInNextDirectionInSequence(mapObject, sprite, route);\
}\

// Static struct declarations

// Static RAM declarations

extern u8 gUnknown_020375B4;
extern u16 gUnknown_020375B6;

// Static ROM declarations

static void sub_808D450(void);
static u8 GetFieldObjectIdByLocalId(u8);
static u8 GetFieldObjectIdByLocalIdAndMapInternal(u8, u8, u8);
static bool8 GetAvailableFieldObjectSlot(u16, u8, u8, u8 *);
static void FieldObjectHandleDynamicGraphicsId(struct MapObject *);
static void RemoveFieldObjectInternal (struct MapObject *);
/*static*/ u16 GetFieldObjectFlagIdByFieldObjectId(u8);
void sub_8096518(struct MapObject *, struct Sprite *);
static void MakeObjectTemplateFromFieldObjectTemplate(struct MapObjectTemplate *, struct SpriteTemplate *, const struct SubspriteTable **);
/*static*/ void GetFieldObjectMovingCameraOffset(s16 *, s16 *);
/*static*/ struct MapObjectTemplate *GetFieldObjectTemplateByLocalIdAndMap(u8, u8, u8);
static void sub_808E894(u16);
static void RemoveFieldObjectIfOutsideView(struct MapObject *);
static void sub_808E1B8(u8, s16, s16);
static void SetPlayerAvatarFieldObjectIdAndObjectId(u8, u8);
/*static*/ void sub_808E38C(struct MapObject *);
static u8 sub_808E8F4(const struct SpritePalette *);
static u8 FindFieldObjectPaletteIndexByTag(u16);
static void sub_808EAB0(u16, u8);
static bool8 FieldObjectDoesZCoordMatch(struct MapObject *, u8);
//static void CameraObject_0(struct Sprite *);
/*static*/ void CameraObject_1(struct Sprite *);
//static void CameraObject_2(struct Sprite *);
/*static*/ struct MapObjectTemplate *FindFieldObjectTemplateInArrayByLocalId(u8 localId, struct MapObjectTemplate *templates, u8 count);
void npc_reset(struct MapObject *, struct Sprite *);
void FieldObjectSetRegularAnim(struct MapObject *, struct Sprite *, u8);

u8 GetFaceDirectionAnimId(u32);
u8 GetGoSpeed0AnimId(u32);
u8 GetGoSpeed1AnimId(u32);
u8 GetGoSpeed3AnimId(u32);
u8 sub_8093438(u32);
u8 sub_80934BC(u32);
u8 sub_8093514(u32);
u8 GetJumpLedgeAnimId(u32);
void sub_8092F88(u32, s16 *, s16 *, s16, s16);

bool8 FieldObjectExecRegularAnim(struct MapObject *, struct Sprite *);
void SetFieldObjectStepTimer(struct Sprite *, s16);
bool8 RunFieldObjectStepTimer(struct Sprite *);
bool8 npc_block_way__next_tile(struct MapObject *, u8);
u32 state_to_direction(u8, u32, u32);
void DoGroundEffects_OnSpawn(struct MapObject *, struct Sprite *);
void sub_80964E8(struct MapObject *, struct Sprite *);
bool8 FieldObjectIsSpecialAnimActive(struct MapObject *);
void FieldObjectExecSpecialAnim(struct MapObject *, struct Sprite *);
void DoGroundEffects_OnBeginStep(struct MapObject *, struct Sprite *);
void DoGroundEffects_OnFinishStep(struct MapObject *, struct Sprite *);
void npc_obj_transfer_image_anim_pause_flag(struct MapObject *, struct Sprite *);
void FieldObjectUpdateSubpriority(struct MapObject *, struct Sprite *);

bool8 IsCoordOutsideFieldObjectMovementRect(struct MapObject2 *fieldObject, s16 x, s16 y);
bool8 IsMetatileDirectionallyImpassable(struct MapObject *, s16, s16, u8);
bool8 CheckForCollisionBetweenFieldObjects(struct MapObject *, s16, s16);

// ROM data

void (*const gUnknown_08505438[NUM_FIELD_MAP_OBJECT_TEMPLATES])(struct Sprite *);
const u8 gUnknown_0850557C[NUM_FIELD_MAP_OBJECT_TEMPLATES];
const u8 gUnknown_085055CD[NUM_FIELD_MAP_OBJECT_TEMPLATES];
const struct MapObjectGraphicsInfo *const gMauvilleOldManGraphicsInfoPointers[7];
const struct MapObjectGraphicsInfo *const gFieldObjectGraphicsInfoPointers[0xEF];
u8 (*const gUnknown_0850D714[11])(s16, s16, s16, s16);

// Code

static void npc_clear_ids_and_state(struct MapObject *mapObject)
{
    *mapObject = (struct MapObject){};
    mapObject->localId = 0xFF;
    mapObject->mapNum = -1;
    mapObject->mapGroup = -1;
    mapObject->mapobj_unk_1C = -1;
}

static void npcs_clear_ids_and_state(void)
{
    u8 i;

    for (i = 0; i < NUM_FIELD_OBJECTS; i ++)
    {
        npc_clear_ids_and_state(&gMapObjects[i]);
    }
}

void sub_808D438(void)
{
    strange_npc_table_clear();
    npcs_clear_ids_and_state();
    ClearPlayerAvatarInfo();
    sub_808D450();
}

static void sub_808D450(void)
{
    u8 spriteIdx;

    spriteIdx = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[21], 0, 0, 31);
    gSprites[spriteIdx].oam.affineMode = 1;
    InitSpriteAffineAnim(&gSprites[spriteIdx]);
    StartSpriteAffineAnim(&gSprites[spriteIdx], 0);
    gSprites[spriteIdx].invisible = TRUE;

    spriteIdx = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[21], 0, 0, 31);
    gSprites[spriteIdx].oam.affineMode = 1;
    InitSpriteAffineAnim(&gSprites[spriteIdx]);
    StartSpriteAffineAnim(&gSprites[spriteIdx], 1);
    gSprites[spriteIdx].invisible = TRUE;
}

u8 sub_808D4F4(void)
{
    u8 i;

    for (i = 0; i < NUM_FIELD_OBJECTS; i ++)
    {
        if (!gMapObjects[i].active)
        {
            break;
        }
    }
    return i;
}

u8 GetFieldObjectIdByLocalIdAndMap(u8 localId, u8 mapId, u8 mapGroupId)
{
    if (localId < 0xff)
    {
        return GetFieldObjectIdByLocalIdAndMapInternal(localId, mapId, mapGroupId);
    }
    return GetFieldObjectIdByLocalId(localId);
}

bool8 TryGetFieldObjectIdByLocalIdAndMap(u8 localId, u8 mapId, u8 mapGroupId, u8 *fieldObjectId)
{
    *fieldObjectId = GetFieldObjectIdByLocalIdAndMap(localId, mapId, mapGroupId);
    if (*fieldObjectId == NUM_FIELD_OBJECTS)
    {
        return TRUE;
    }
    return FALSE;
}

u8 GetFieldObjectIdByXY(s16 x, s16 y)
{
    u8 i;

    for (i = 0; i < NUM_FIELD_OBJECTS; i ++)
    {
        if (gMapObjects[i].active && gMapObjects[i].coords2.x == x && gMapObjects[i].coords2.y == y)
        {
            break;
        }
    }
    return i;
}

static u8 GetFieldObjectIdByLocalIdAndMapInternal(u8 localId, u8 mapId, u8 mapGroupId)
{
    u8 i;

    for (i = 0; i < NUM_FIELD_OBJECTS; i ++)
    {
        if (gMapObjects[i].active && gMapObjects[i].localId == localId && gMapObjects[i].mapNum == mapId && gMapObjects[i].mapGroup == mapGroupId)
        {
            return i;
        }
    }
    return NUM_FIELD_OBJECTS;
}

static u8 GetFieldObjectIdByLocalId(u8 localId)
{
    u8 i;

    for (i = 0; i < NUM_FIELD_OBJECTS; i ++)
    {
        if (gMapObjects[i].active && gMapObjects[i].localId == localId)
        {
            return i;
        }
    }
    return NUM_FIELD_OBJECTS;
}

// This function has the same nonmatching quirk as in Ruby/Sapphire.
#ifdef NONMATCHING
static u8 InitFieldObjectStateFromTemplate(struct MapObjectTemplate *template, u8 mapId, u8 mapGroupId)
{
    u8 slot;
    struct MapObject *mapObject;
    u16 x;
    u16 y;

    if (GetAvailableFieldObjectSlot(template->localId, mapId, mapGroupId, &slot))
    {
        return NUM_FIELD_OBJECTS;
    }
    mapObject = &gMapObjects[slot];
    npc_clear_ids_and_state(mapObject);
    x = template->x + 7;
    y = template->y + 7;
    mapObject->active = TRUE;
    mapObject->mapobj_bit_2 = TRUE;
    mapObject->graphicsId = template->graphicsId;
    mapObject->animPattern = template->movementType;
    mapObject->localId = template->localId;
    mapObject->mapNum = mapId;
    mapObject->mapGroup = mapGroupId;
    mapObject->coords1.x = x;
    mapObject->coords1.y = y;
    mapObject->coords2.x = x;
    mapObject->coords2.y = y;
    mapObject->coords3.x = x;
    mapObject->coords3.y = y;
    mapObject->mapobj_unk_0B_0 = template->elevation;
    mapObject->elevation = template->elevation;
    mapObject->mapobj_unk_19 = template->unkA_0;
    mapObject->mapobj_unk_19b = template->unkA_4;
    mapObject->trainerType = template->unkC;
    mapObject->trainerRange_berryTreeId = template->unkE;
    mapObject->mapobj_unk_20 = gUnknown_085055CD[template->movementType];
    FieldObjectSetDirection(mapObject, mapObject->mapobj_unk_20);
    FieldObjectHandleDynamicGraphicsId(mapObject);

    // This block is the culprit
    if (gUnknown_0850557C[mapObject->animPattern])
    {
        if (mapObject->mapobj_unk_19 == 0)
        {
            mapObject->mapobj_unk_19 ++;
        }
        if (mapObject->mapobj_unk_19b == 0)
        {
            mapObject->mapobj_unk_19b ++;
        }
    }
    return slot;
}
#else
static __attribute__((naked)) u8 InitFieldObjectStateFromTemplate(struct MapObjectTemplate *template, u8 mapId, u8 mapGroupId)
{
    asm_unified("\tpush {r4-r7,lr}\n"
                "\tmov r7, r9\n"
                "\tmov r6, r8\n"
                "\tpush {r6,r7}\n"
                "\tsub sp, 0x4\n"
                "\tadds r5, r0, 0\n"
                "\tlsls r1, 24\n"
                "\tlsrs r6, r1, 24\n"
                "\tlsls r2, 24\n"
                "\tlsrs r7, r2, 24\n"
                "\tldrb r0, [r5]\n"
                "\tadds r1, r6, 0\n"
                "\tadds r2, r7, 0\n"
                "\tmov r3, sp\n"
                "\tbl GetAvailableFieldObjectSlot\n"
                "\tlsls r0, 24\n"
                "\tcmp r0, 0\n"
                "\tbeq _0808D66E\n"
                "\tmovs r0, 0x10\n"
                "\tb _0808D762\n"
                "_0808D66E:\n"
                "\tmov r0, sp\n"
                "\tldrb r1, [r0]\n"
                "\tlsls r0, r1, 3\n"
                "\tadds r0, r1\n"
                "\tlsls r0, 2\n"
                "\tldr r1, =gMapObjects\n"
                "\tadds r4, r0, r1\n"
                "\tadds r0, r4, 0\n"
                "\tbl npc_clear_ids_and_state\n"
                "\tldrh r3, [r5, 0x4]\n"
                "\tadds r3, 0x7\n"
                "\tlsls r3, 16\n"
                "\tlsrs r3, 16\n"
                "\tldrh r2, [r5, 0x6]\n"
                "\tadds r2, 0x7\n"
                "\tlsls r2, 16\n"
                "\tlsrs r2, 16\n"
                "\tldrb r0, [r4]\n"
                "\tmovs r1, 0x1\n"
                "\torrs r0, r1\n"
                "\tmovs r1, 0x4\n"
                "\torrs r0, r1\n"
                "\tstrb r0, [r4]\n"
                "\tldrb r0, [r5, 0x1]\n"
                "\tstrb r0, [r4, 0x5]\n"
                "\tldrb r0, [r5, 0x9]\n"
                "\tstrb r0, [r4, 0x6]\n"
                "\tldrb r0, [r5]\n"
                "\tstrb r0, [r4, 0x8]\n"
                "\tstrb r6, [r4, 0x9]\n"
                "\tstrb r7, [r4, 0xA]\n"
                "\tstrh r3, [r4, 0xC]\n"
                "\tstrh r2, [r4, 0xE]\n"
                "\tstrh r3, [r4, 0x10]\n"
                "\tstrh r2, [r4, 0x12]\n"
                "\tstrh r3, [r4, 0x14]\n"
                "\tstrh r2, [r4, 0x16]\n"
                "\tldrb r0, [r5, 0x8]\n"
                "\tmovs r7, 0xF\n"
                "\tadds r1, r7, 0\n"
                "\tands r1, r0\n"
                "\tldrb r2, [r4, 0xB]\n"
                "\tmovs r0, 0x10\n"
                "\tnegs r0, r0\n"
                "\tmov r8, r0\n"
                "\tands r0, r2\n"
                "\torrs r0, r1\n"
                "\tstrb r0, [r4, 0xB]\n"
                "\tldrb r1, [r5, 0x8]\n"
                "\tlsls r1, 4\n"
                "\tands r0, r7\n"
                "\torrs r0, r1\n"
                "\tstrb r0, [r4, 0xB]\n"
                "\tldrb r1, [r5, 0xA]\n"
                "\tlsls r1, 28\n"
                "\tmovs r0, 0xF\n"
                "\tmov r9, r0\n"
                "\tlsrs r1, 28\n"
                "\tldrb r2, [r4, 0x19]\n"
                "\tmov r0, r8\n"
                "\tands r0, r2\n"
                "\torrs r0, r1\n"
                "\tstrb r0, [r4, 0x19]\n"
                "\tldrb r1, [r5, 0xA]\n"
                "\tlsrs r1, 4\n"
                "\tlsls r1, 4\n"
                "\tands r0, r7\n"
                "\torrs r0, r1\n"
                "\tstrb r0, [r4, 0x19]\n"
                "\tldrh r0, [r5, 0xC]\n"
                "\tstrb r0, [r4, 0x7]\n"
                "\tldrh r0, [r5, 0xE]\n"
                "\tstrb r0, [r4, 0x1D]\n"
                "\tldr r1, =gUnknown_085055CD\n"
                "\tldrb r0, [r5, 0x9]\n"
                "\tadds r0, r1\n"
                "\tldrb r1, [r0]\n"
                "\tadds r0, r4, 0\n"
                "\tadds r0, 0x20\n"
                "\tstrb r1, [r0]\n"
                "\tldrb r1, [r0]\n"
                "\tadds r0, r4, 0\n"
                "\tbl FieldObjectSetDirection\n"
                "\tadds r0, r4, 0\n"
                "\tbl FieldObjectHandleDynamicGraphicsId\n"
                "\tldr r1, =gUnknown_0850557C\n"
                "\tldrb r0, [r4, 0x6]\n"
                "\tadds r0, r1\n"
                "\tldrb r0, [r0]\n"
                "\tcmp r0, 0\n"
                "\tbeq _0808D75E\n"
                "\tldrb r2, [r4, 0x19]\n"
                "\tadds r0, r7, 0\n"
                "\tands r0, r2\n"
                "\tcmp r0, 0\n"
                "\tbne _0808D746\n"
                "\tlsls r0, r2, 28\n"
                "\tlsrs r0, 28\n"
                "\tadds r0, 0x1\n"
                "\tmov r1, r9\n"
                "\tands r0, r1\n"
                "\tmov r1, r8\n"
                "\tands r1, r2\n"
                "\torrs r1, r0\n"
                "\tstrb r1, [r4, 0x19]\n"
                "_0808D746:\n"
                "\tldrb r2, [r4, 0x19]\n"
                "\tmovs r0, 0xF0\n"
                "\tands r0, r2\n"
                "\tcmp r0, 0\n"
                "\tbne _0808D75E\n"
                "\tlsrs r1, r2, 4\n"
                "\tadds r1, 0x1\n"
                "\tlsls r1, 4\n"
                "\tadds r0, r7, 0\n"
                "\tands r0, r2\n"
                "\torrs r0, r1\n"
                "\tstrb r0, [r4, 0x19]\n"
                "_0808D75E:\n"
                "\tmov r0, sp\n"
                "\tldrb r0, [r0]\n"
                "_0808D762:\n"
                "\tadd sp, 0x4\n"
                "\tpop {r3,r4}\n"
                "\tmov r8, r3\n"
                "\tmov r9, r4\n"
                "\tpop {r4-r7}\n"
                "\tpop {r1}\n"
                "\tbx r1\n"
                ".pool");
}
#endif

u8 unref_sub_808D77C(u8 localId)
{
    u8 i;
    u8 nObjects;
    struct MapObjectTemplate *template;

    if (gMapHeader.events != NULL)
    {
        if (InBattlePyramid())
        {
            nObjects = sub_81AAA40();
        }
        else if (InTrainerHill())
        {
            nObjects = 2;
        }
        else
        {
            nObjects = gMapHeader.events->mapObjectCount;
        }
        for (i = 0; i < nObjects; i ++)
        {
            template = &gSaveBlock1Ptr->mapObjectTemplates[i];
            if (template->localId == localId && !FlagGet(template->flagId))
            {
                return InitFieldObjectStateFromTemplate(template, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
            }
        }
    }
    return NUM_FIELD_OBJECTS;
}

static bool8 GetAvailableFieldObjectSlot(u16 localId, u8 mapNum, u8 mapGroup, u8 *result)
// Looks for an empty slot.
// Returns FALSE and the location of the available slot
// in *result.
// If no slots are available, or if the object is already
// loaded, returns TRUE.
{
    u8 i = 0;

    for (i = 0; i < NUM_FIELD_OBJECTS; i ++)
    {
        if (!gMapObjects[i].active)
            break;
        if (gMapObjects[i].localId == localId && gMapObjects[i].mapNum == mapNum && gMapObjects[i].mapGroup == mapGroup)
            return TRUE;
    }
    if (i >= NUM_FIELD_OBJECTS)
        return TRUE;
    *result = i;
    do
    {
        if (gMapObjects[i].active && gMapObjects[i].localId == localId && gMapObjects[i].mapNum == mapNum && gMapObjects[i].mapGroup == mapGroup)
            return TRUE;
        i ++;
    } while (i < NUM_FIELD_OBJECTS);
    return FALSE;
}

static void RemoveFieldObject(struct MapObject *mapObject)
{
    mapObject->active = FALSE;
    RemoveFieldObjectInternal(mapObject);
}

void RemoveFieldObjectByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 index;
    if (!TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &index))
    {
        FlagSet(GetFieldObjectFlagIdByFieldObjectId(index));
        RemoveFieldObject(&gMapObjects[index]);
    }
}

static void RemoveFieldObjectInternal(struct MapObject *mapObject)
{
    struct SpriteFrameImage image;
    image.size = GetFieldObjectGraphicsInfo(mapObject->graphicsId)->size;
    gSprites[mapObject->spriteId].images = &image;
    DestroySprite(&gSprites[mapObject->spriteId]);
}

void unref_sub_808D958(void)
{
    u8 i;

    for (i = 0; i < NUM_FIELD_OBJECTS; i ++)
    {
        if (i != gPlayerAvatar.mapObjectId)
        {
            RemoveFieldObject(&gMapObjects[i]);
        }
    }
}

static u8 SpawnFieldObjectInternal(struct MapObjectTemplate *mapObjectTemplate, struct SpriteTemplate *spriteTemplate, u8 mapNum, u8 mapGroup, s16 cameraX, s16 cameraY)
{
    struct MapObject *mapObject;
    const struct MapObjectGraphicsInfo *graphicsInfo;
    struct Sprite *sprite;
    u8 mapObjectId;
    u8 paletteSlot;
    u8 spriteId;

    mapObjectId = InitFieldObjectStateFromTemplate(mapObjectTemplate, mapNum, mapGroup);
    if (mapObjectId == NUM_FIELD_OBJECTS)
    {
        return NUM_FIELD_OBJECTS;
    }
    mapObject = &gMapObjects[mapObjectId];
    graphicsInfo = GetFieldObjectGraphicsInfo(mapObject->graphicsId);
    paletteSlot = graphicsInfo->paletteSlot;
    if (paletteSlot == 0)
    {
        npc_load_two_palettes__no_record(graphicsInfo->paletteTag1, 0);
    }
    else if (paletteSlot == 10)
    {
        npc_load_two_palettes__and_record(graphicsInfo->paletteTag1, 10);
    }
    else if (paletteSlot >= 16)
    {
        paletteSlot -= 16;
        sub_808EAB0(graphicsInfo->paletteTag1, paletteSlot);
    }
    if (mapObject->animPattern == 0x4c)
    {
        mapObject->mapobj_bit_13 = TRUE;
    }
    *(u16 *)&spriteTemplate->paletteTag = 0xFFFF;
    spriteId = CreateSprite(spriteTemplate, 0, 0, 0);
    if (spriteId == MAX_SPRITES)
    {
        gMapObjects[mapObjectId].active = FALSE;
        return NUM_FIELD_OBJECTS;
    }
    sprite = &gSprites[spriteId];
    sub_8092FF0(mapObject->coords2.x + cameraX, mapObject->coords2.y + cameraY, &sprite->pos1.x, &sprite->pos1.y);
    sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
    sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
    sprite->pos1.x += 8;
    sprite->pos1.y += 16 + sprite->centerToCornerVecY;
    sprite->oam.paletteNum = paletteSlot;
    sprite->coordOffsetEnabled = TRUE;
    sprite->data0 = mapObjectId;
    mapObject->spriteId = spriteId;
    mapObject->mapobj_bit_12 = graphicsInfo->inanimate;
    if (!mapObject->mapobj_bit_12)
    {
        StartSpriteAnim(sprite, FieldObjectDirectionToImageAnimId(mapObject->mapobj_unk_18));
    }
    SetObjectSubpriorityByZCoord(mapObject->elevation, sprite, 1);
    sub_8096518(mapObject, sprite);
    return mapObjectId;
}

static u8 SpawnFieldObject(struct MapObjectTemplate *mapObjectTemplate, u8 mapNum, u8 mapGroup, s16 cameraX, s16 cameraY)
{
    const struct MapObjectGraphicsInfo *graphicsInfo;
    struct SpriteTemplate spriteTemplate;
    const struct SubspriteTable *subspriteTables;
    struct SpriteFrameImage spriteFrameImage;
    u8 mapObjectId;

    subspriteTables = NULL;
    graphicsInfo = GetFieldObjectGraphicsInfo(mapObjectTemplate->graphicsId);
    MakeObjectTemplateFromFieldObjectTemplate(mapObjectTemplate, &spriteTemplate, &subspriteTables);
    spriteFrameImage.size = graphicsInfo->size;
    spriteTemplate.images = &spriteFrameImage;
    mapObjectId = SpawnFieldObjectInternal(mapObjectTemplate, &spriteTemplate, mapNum, mapGroup, cameraX, cameraY);
    if (mapObjectId == NUM_FIELD_OBJECTS)
    {
        return NUM_FIELD_OBJECTS;
    }
    gSprites[gMapObjects[mapObjectId].spriteId].images = graphicsInfo->images;
    if (subspriteTables != NULL)
    {
        SetSubspriteTables(&gSprites[gMapObjects[mapObjectId].spriteId], subspriteTables);
    }
    return mapObjectId;
}

u8 SpawnSpecialFieldObject(struct MapObjectTemplate *mapObjectTemplate)
{
    s16 cameraX;
    s16 cameraY;

    GetFieldObjectMovingCameraOffset(&cameraX, &cameraY);
    return SpawnFieldObject(mapObjectTemplate, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, cameraX, cameraY);
}

u8 SpawnSpecialFieldObjectParametrized(u8 graphicsId, u8 movementBehavior, u8 localId, s16 x, s16 y, u8 z)
{
    struct MapObjectTemplate mapObjectTemplate;

    x -= 7;
    y -= 7;
    mapObjectTemplate.localId = localId;
    mapObjectTemplate.graphicsId = graphicsId;
    mapObjectTemplate.unk2 = 0;
    mapObjectTemplate.x = x;
    mapObjectTemplate.y = y;
    mapObjectTemplate.elevation = z;
    mapObjectTemplate.movementType = movementBehavior;
    mapObjectTemplate.unkA_0 = 0;
    mapObjectTemplate.unkA_4 = 0;
    mapObjectTemplate.unkC = 0;
    mapObjectTemplate.unkE = 0;
    return SpawnSpecialFieldObject(&mapObjectTemplate);
}

u8 show_sprite(u8 localId, u8 mapNum, u8 mapGroup)
{
    struct MapObjectTemplate *mapObjectTemplate;
    s16 cameraX;
    s16 cameraY;

    mapObjectTemplate = GetFieldObjectTemplateByLocalIdAndMap(localId, mapNum, mapGroup);
    if (mapObjectTemplate == NULL)
    {
        return NUM_FIELD_OBJECTS;
    }
    GetFieldObjectMovingCameraOffset(&cameraX, &cameraY);
    return SpawnFieldObject(mapObjectTemplate, mapNum, mapGroup, cameraX, cameraY);
}

static void MakeObjectTemplateFromFieldObjectGraphicsInfo(u16 graphicsId, void (*callback)(struct Sprite *), struct SpriteTemplate *sprTemplate, const struct SubspriteTable **subspriteTables)
{
    const struct MapObjectGraphicsInfo *gfxInfo = GetFieldObjectGraphicsInfo(graphicsId);

    sprTemplate->tileTag = gfxInfo->tileTag;
    sprTemplate->paletteTag = gfxInfo->paletteTag1;
    sprTemplate->oam = gfxInfo->oam;
    sprTemplate->anims = gfxInfo->anims;
    sprTemplate->images = gfxInfo->images;
    sprTemplate->affineAnims = gfxInfo->affineAnims;
    sprTemplate->callback = callback;
    *subspriteTables = gfxInfo->subspriteTables;
}

static void MakeObjectTemplateFromFieldObjectGraphicsInfoWithCallbackIndex(u16 graphicsId, u16 callbackIndex, struct SpriteTemplate *sprTemplate, const struct SubspriteTable **subspriteTables)
{
    MakeObjectTemplateFromFieldObjectGraphicsInfo(graphicsId, gUnknown_08505438[callbackIndex], sprTemplate, subspriteTables);
}

static void MakeObjectTemplateFromFieldObjectTemplate(struct MapObjectTemplate *mapObjectTemplate, struct SpriteTemplate *spriteTemplate, const struct SubspriteTable **subspriteTables)
{
    MakeObjectTemplateFromFieldObjectGraphicsInfoWithCallbackIndex(mapObjectTemplate->graphicsId, mapObjectTemplate->movementType, spriteTemplate, subspriteTables);
}

u8 AddPseudoFieldObject(u16 graphicsId, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority)
{
    struct SpriteTemplate *spriteTemplate;
    const struct SubspriteTable *subspriteTables;
    struct Sprite *sprite;
    u8 spriteIdx;

    spriteTemplate = malloc(sizeof(struct SpriteTemplate));
    MakeObjectTemplateFromFieldObjectGraphicsInfo(graphicsId, callback, spriteTemplate, &subspriteTables);
    if (spriteTemplate->paletteTag != 0xffff)
    {
        sub_808E894(spriteTemplate->paletteTag);
    }
    spriteIdx = CreateSprite(spriteTemplate, x, y, subpriority);
    free(spriteTemplate);

    if (spriteIdx != MAX_SPRITES && subspriteTables != NULL)
    {
        sprite = &gSprites[spriteIdx];
        SetSubspriteTables(sprite, subspriteTables);
        sprite->subspriteMode = 2;
    }
    return spriteIdx;
}

u8 sprite_new(u8 graphicsId, u8 a1, s16 x, s16 y, u8 z, u8 direction)
{
    const struct MapObjectGraphicsInfo *graphicsInfo;
    struct SpriteTemplate spriteTemplate;
    const struct SubspriteTable *subspriteTables;
    u8 spriteId;
    struct Sprite *sprite;

    graphicsInfo = GetFieldObjectGraphicsInfo(graphicsId);
    MakeObjectTemplateFromFieldObjectGraphicsInfo(graphicsId, sub_8097AC8, &spriteTemplate, &subspriteTables);
    *(u16 *)&spriteTemplate.paletteTag = 0xffff;
    x += 7;
    y += 7;
    sub_80930E0(&x, &y, 8, 16);
    spriteId = CreateSpriteAtEnd(&spriteTemplate, x, y, 0);
    if (spriteId != MAX_SPRITES)
    {
        sprite = &gSprites[spriteId];
        sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
        sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
        sprite->pos1.y += sprite->centerToCornerVecY;
        sprite->oam.paletteNum = graphicsInfo->paletteSlot;
        if (sprite->oam.paletteNum >= 16)
        {
            sprite->oam.paletteNum -= 16;
        }
        sprite->coordOffsetEnabled = TRUE;
        sprite->data0 = a1;
        sprite->data1 = z;
        if (graphicsInfo->paletteSlot == 10)
        {
            npc_load_two_palettes__and_record(graphicsInfo->paletteTag1, graphicsInfo->paletteSlot);
        }
        else if (graphicsInfo->paletteSlot >= 16)
        {
            sub_808EAB0(graphicsInfo->paletteTag1, graphicsInfo->paletteSlot | 0xf0);
        }
        if (subspriteTables != NULL)
        {
            SetSubspriteTables(sprite, subspriteTables);
            sprite->subspriteMode = 2;
        }
        InitObjectPriorityByZCoord(sprite, z);
        SetObjectSubpriorityByZCoord(z, sprite, 1);
        StartSpriteAnim(sprite, FieldObjectDirectionToImageAnimId(direction));
    }
    return spriteId;
}

void SpawnFieldObjectsInView(s16 cameraX, s16 cameraY)
{
    u8 i;
    s16 left;
    s16 right;
    s16 top;
    s16 bottom;
    u8 objectCount;
    s16 npcX;
    s16 npcY;

    if (gMapHeader.events != NULL)
    {
        left = gSaveBlock1Ptr->pos.x - 2;
        right = gSaveBlock1Ptr->pos.x + 17;
        top = gSaveBlock1Ptr->pos.y;
        bottom = gSaveBlock1Ptr->pos.y + 16;

        if (InBattlePyramid())
        {
            objectCount = sub_81AAA40();
        }
        else if (InTrainerHill())
        {
            objectCount = 2;
        }
        else
        {
            objectCount = gMapHeader.events->mapObjectCount;
        }

        for (i = 0; i < objectCount; i++)
        {
            struct MapObjectTemplate *template = &gSaveBlock1Ptr->mapObjectTemplates[i];
            npcX = template->x + 7;
            npcY = template->y + 7;

            if (top <= npcY && bottom >= npcY && left <= npcX && right >= npcX
                && !FlagGet(template->flagId))
                SpawnFieldObject(template, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, cameraX, cameraY);
        }
    }
}

/*static*/ void RemoveFieldObjectsOutsideView(void)
{
    u8 i;
    u8 j;
    bool8 isActiveLinkPlayer;
    struct MapObject *mapObject;

    for (i = 0; i < NUM_FIELD_OBJECTS; i ++)
    {
        for (j = 0, isActiveLinkPlayer = FALSE; j < ARRAY_COUNT(gLinkPlayerMapObjects); j ++)
        {
            if (gLinkPlayerMapObjects[j].active && i == gLinkPlayerMapObjects[j].mapObjId)
                isActiveLinkPlayer = TRUE;
        }
        if (!isActiveLinkPlayer)
        {
            mapObject = &gMapObjects[i];

            if (mapObject->active && !mapObject->mapobj_bit_16)
                RemoveFieldObjectIfOutsideView(mapObject);
        }
    }
}

static void RemoveFieldObjectIfOutsideView(struct MapObject *mapObject)
{
    s16 left;
    s16 right;
    s16 top;
    s16 bottom;

    left = gSaveBlock1Ptr->pos.x - 2;
    right = gSaveBlock1Ptr->pos.x + 17;
    top = gSaveBlock1Ptr->pos.y;
    bottom = gSaveBlock1Ptr->pos.y + 16;

    if (mapObject->coords2.x >= left && mapObject->coords2.x <= right
        && mapObject->coords2.y >= top && mapObject->coords2.y <= bottom)
        return;
    if (mapObject->coords1.x >= left && mapObject->coords1.x <= right
        && mapObject->coords1.y >= top && mapObject->coords1.y <= bottom)
        return;
    RemoveFieldObject(mapObject);
}

void sub_808E16C(s16 x, s16 y)
{
    u8 i;

    ClearPlayerAvatarInfo();
    for (i = 0; i < NUM_FIELD_OBJECTS; i ++)
    {
        if (gMapObjects[i].active)
        {
            sub_808E1B8(i, x, y);
        }
    }
    sub_808D450();
}

static void sub_808E1B8(u8 mapObjectId, s16 x, s16 y)
{
    u8 spriteId;
    u8 paletteSlot;
    struct MapObject *mapObject;
    const struct SubspriteTable *subspriteTables;
    const struct MapObjectGraphicsInfo *graphicsInfo;
    struct SpriteFrameImage spriteFrameImage;
    struct SpriteTemplate spriteTemplate;
    struct Sprite *sprite;

#define i spriteId
    for (i = 0; i < ARRAY_COUNT(gLinkPlayerMapObjects); i ++)
    {
        if (gLinkPlayerMapObjects[i].active && mapObjectId == gLinkPlayerMapObjects[i].mapObjId)
        {
            return;
        }
    }
#undef i

    mapObject = &gMapObjects[mapObjectId];
    subspriteTables = NULL;
    graphicsInfo = GetFieldObjectGraphicsInfo(mapObject->graphicsId);
    spriteFrameImage.size = graphicsInfo->size;
    MakeObjectTemplateFromFieldObjectGraphicsInfoWithCallbackIndex(mapObject->graphicsId, mapObject->animPattern, &spriteTemplate, &subspriteTables);
    spriteTemplate.images = &spriteFrameImage;
    *(u16 *)&spriteTemplate.paletteTag = 0xffff;
    paletteSlot = graphicsInfo->paletteSlot;
    if (paletteSlot == 0)
    {
        npc_load_two_palettes__no_record(graphicsInfo->paletteTag1, graphicsInfo->paletteSlot);
    }
    else if (paletteSlot == 10)
    {
        npc_load_two_palettes__and_record(graphicsInfo->paletteTag1, graphicsInfo->paletteSlot);
    }
    else if (paletteSlot >= 16)
    {
        paletteSlot -= 16;
        sub_808EAB0(graphicsInfo->paletteTag1, paletteSlot);
    }
    *(u16 *)&spriteTemplate.paletteTag = 0xffff;
    spriteId = CreateSprite(&spriteTemplate, 0, 0, 0);
    if (spriteId != MAX_SPRITES)
    {
        sprite = &gSprites[spriteId];
        sub_8092FF0(x + mapObject->coords2.x, y + mapObject->coords2.y, &sprite->pos1.x, &sprite->pos1.y);
        sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
        sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
        sprite->pos1.x += 8;
        sprite->pos1.y += 16 + sprite->centerToCornerVecY;
        sprite->images = graphicsInfo->images;
        if (mapObject->animPattern == 0x0b)
        {
            SetPlayerAvatarFieldObjectIdAndObjectId(mapObjectId, spriteId);
            mapObject->mapobj_unk_1B = sub_8154228();
        }
        if (subspriteTables != NULL)
        {
            SetSubspriteTables(sprite, subspriteTables);
        }
        sprite->oam.paletteNum = paletteSlot;
        sprite->coordOffsetEnabled = TRUE;
        sprite->data0 = mapObjectId;
        mapObject->spriteId = spriteId;
        if (!mapObject->mapobj_bit_12 && mapObject->animPattern != 0x0b)
        {
            StartSpriteAnim(sprite, FieldObjectDirectionToImageAnimId(mapObject->mapobj_unk_18));
        }
        sub_808E38C(mapObject);
        SetObjectSubpriorityByZCoord(mapObject->elevation, sprite, 1);
    }
}

/*static*/ void sub_808E38C(struct MapObject *mapObject)
{
    mapObject->mapobj_bit_1 = FALSE;
    mapObject->mapobj_bit_2 = TRUE;
    mapObject->mapobj_bit_22 = FALSE;
    mapObject->mapobj_bit_17 = FALSE;
    mapObject->mapobj_bit_18 = FALSE;
    mapObject->mapobj_bit_19 = FALSE;
    mapObject->mapobj_bit_20 = FALSE;
    mapObject->mapobj_bit_21 = FALSE;
    FieldObjectClearAnim(mapObject);
}

static void SetPlayerAvatarFieldObjectIdAndObjectId(u8 mapObjectId, u8 spriteId)
{
    gPlayerAvatar.mapObjectId = mapObjectId;
    gPlayerAvatar.spriteId = spriteId;
    gPlayerAvatar.gender = GetPlayerAvatarGenderByGraphicsId(gMapObjects[mapObjectId].graphicsId);
    SetPlayerAvatarExtraStateTransition(gMapObjects[mapObjectId].graphicsId, 0x20);
}

void FieldObjectSetGraphicsId(struct MapObject *mapObject, u8 graphicsId)
{
    const struct MapObjectGraphicsInfo *graphicsInfo;
    struct Sprite *sprite;
    u8 paletteSlot;

    graphicsInfo = GetFieldObjectGraphicsInfo(graphicsId);
    sprite = &gSprites[mapObject->spriteId];
    paletteSlot = graphicsInfo->paletteSlot;
    if (paletteSlot == 0)
    {
        pal_patch_for_npc(graphicsInfo->paletteTag1, graphicsInfo->paletteSlot);
    }
    else if (paletteSlot == 10)
    {
        npc_load_two_palettes__and_record(graphicsInfo->paletteTag1, graphicsInfo->paletteSlot);
    }
    else if (paletteSlot >= 16)
    {
        paletteSlot -= 16;
        sub_808EAB0(graphicsInfo->paletteTag1, paletteSlot);
    }
    sprite->oam.shape = graphicsInfo->oam->shape;
    sprite->oam.size = graphicsInfo->oam->size;
    sprite->images = graphicsInfo->images;
    sprite->anims = graphicsInfo->anims;
    sprite->subspriteTables = graphicsInfo->subspriteTables;
    sprite->oam.paletteNum = paletteSlot;
    mapObject->mapobj_bit_12 = graphicsInfo->inanimate;
    mapObject->graphicsId = graphicsId;
    sub_8093038(mapObject->coords2.x, mapObject->coords2.y, &sprite->pos1.x, &sprite->pos1.y);
    sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
    sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
    sprite->pos1.x += 8;
    sprite->pos1.y += 16 + sprite->centerToCornerVecY;
    if (mapObject->mapobj_bit_15)
    {
        CameraObjectReset1();
    }
}

void FieldObjectSetGraphicsIdByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup, u8 graphicsId)
{
    u8 mapObjectId;

    if (!TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &mapObjectId))
    {
        FieldObjectSetGraphicsId(&gMapObjects[mapObjectId], graphicsId);
    }
}

void FieldObjectTurn(struct MapObject *mapObject, u8 direction)
{
    FieldObjectSetDirection(mapObject, direction);
    if (!mapObject->mapobj_bit_12)
    {
        StartSpriteAnim(&gSprites[mapObject->spriteId], FieldObjectDirectionToImageAnimId(mapObject->mapobj_unk_18));
        SeekSpriteAnim(&gSprites[mapObject->spriteId], 0);
    }
}

void FieldObjectTurnByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup, u8 direction)
{
    u8 mapObjectId;

    if (!TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &mapObjectId))
    {
        FieldObjectTurn(&gMapObjects[mapObjectId], direction);
    }
}

void PlayerObjectTurn(struct PlayerAvatar *playerAvatar, u8 direction)
{
    FieldObjectTurn(&gMapObjects[playerAvatar->mapObjectId], direction);
}

/*static*/ void get_berry_tree_graphics(struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 berryStage;
    u8 berryId;

    mapObject->mapobj_bit_13 = TRUE;
    sprite->invisible = TRUE;
    berryStage = GetStageByBerryTreeId(mapObject->trainerRange_berryTreeId);
    if (berryStage != 0)
    {
        mapObject->mapobj_bit_13 = FALSE;
        sprite->invisible = FALSE;
        berryId = GetBerryTypeByBerryTreeId(mapObject->trainerRange_berryTreeId) - 1;
        berryStage -= 1;
        if (berryId >= NUM_BERRIES)
        {
            berryId = 0;
        }
        FieldObjectSetGraphicsId(mapObject, gBerryTreeFieldObjectGraphicsIdTablePointers[berryId][berryStage]);
        sprite->images = gBerryTreePicTablePointers[berryId];
        sprite->oam.paletteNum = gBerryTreePaletteSlotTablePointers[berryId][berryStage];
        StartSpriteAnim(sprite, berryStage);
    }
}

const struct MapObjectGraphicsInfo *GetFieldObjectGraphicsInfo(u8 graphicsId)
{
    u8 bard;

    if (graphicsId >= SPRITE_VAR)
    {
        graphicsId = VarGetFieldObjectGraphicsId(graphicsId - SPRITE_VAR);
    }
    if (graphicsId == 0x45)
    {
        bard = sub_81201C8();
        return gMauvilleOldManGraphicsInfoPointers[bard];
    }
    if (graphicsId >= NUM_OBJECT_GRAPHICS_INFO)
    {
        graphicsId = 0x05; // LittleBoy1
    }
    return gFieldObjectGraphicsInfoPointers[graphicsId];
}

static void FieldObjectHandleDynamicGraphicsId(struct MapObject *mapObject)
{
    if (mapObject->graphicsId >= SPRITE_VAR)
    {
        mapObject->graphicsId = VarGetFieldObjectGraphicsId(mapObject->graphicsId - SPRITE_VAR);
    }
}

void npc_by_local_id_and_map_set_field_1_bit_x20(u8 localId, u8 mapNum, u8 mapGroup, u8 state)
{
    u8 mapObjectId;

    if (!TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &mapObjectId))
    {
        gMapObjects[mapObjectId].mapobj_bit_13 = state;
    }
}

void FieldObjectGetLocalIdAndMap(struct MapObject *mapObject, u8 *localId, u8 *mapNum, u8 *mapGroup)
{
    *localId = mapObject->localId;
    *mapNum = mapObject->mapNum;
    *mapGroup = mapObject->mapGroup;
}

void sub_808E75C(s16 x, s16 y)
{
    u8 mapObjectId;
    struct MapObject *mapObject;

    mapObjectId = GetFieldObjectIdByXY(x, y);
    if (mapObjectId != NUM_FIELD_OBJECTS)
    {
        mapObject = &gMapObjects[mapObjectId];
        mapObject->mapobj_bit_2 = TRUE;
    }
}

void sub_808E78C(u8 localId, u8 mapNum, u8 mapGroup, u8 subpriority)
{
    u8 mapObjectId;
    struct MapObject *mapObject;
    struct Sprite *sprite;

    if (!TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &mapObjectId))
    {
        mapObject = &gMapObjects[mapObjectId];
        sprite = &gSprites[mapObject->spriteId];
        mapObject->mapobj_bit_26 = TRUE;
        sprite->subpriority = subpriority;
    }
}

void sub_808E7E4(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 mapObjectId;
    struct MapObject *mapObject;

    if (!TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &mapObjectId))
    {
        mapObject = &gMapObjects[mapObjectId];
        mapObject->mapobj_bit_26 = FALSE;
        mapObject->mapobj_bit_2 = TRUE;
    }
}

void sub_808E82C(u8 localId, u8 mapNum, u8 mapGroup, s16 x, s16 y)
{
    u8 mapObjectId;
    struct Sprite *sprite;

    if (!TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &mapObjectId))
    {
        sprite = &gSprites[gMapObjects[mapObjectId].spriteId];
        sprite->pos2.x = x;
        sprite->pos2.y = y;
    }
}

void gpu_pal_allocator_reset__manage_upper_four(void)
{
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = 12;
}

static void sub_808E894(u16 paletteTag)
{
    u16 paletteSlot;

    paletteSlot = FindFieldObjectPaletteIndexByTag(paletteTag);
    if (paletteSlot != 0x11ff) // always true
    {
        sub_808E8F4(&gUnknown_0850BBC8[paletteSlot]);
    }
}

void sub_808E8C0(u16 *paletteTags)
{
    u8 i;

    for (i = 0; paletteTags[i] != 0x11ff; i ++)
    {
        sub_808E894(paletteTags[i]);
    }
}

static u8 sub_808E8F4(const struct SpritePalette *spritePalette)
{
    if (IndexOfSpritePaletteTag(spritePalette->tag) != 0xff)
    {
        return 0xff;
    }
    return LoadSpritePalette(spritePalette);
}

void pal_patch_for_npc(u16 paletteTag, u8 paletteSlot)
{
    u16 paletteIdx;

    paletteIdx = FindFieldObjectPaletteIndexByTag(paletteTag);
    LoadPalette(gUnknown_0850BBC8[paletteIdx].data, 16 * paletteSlot + 256, 0x20);
}

void pal_patch_for_npc_range(const u16 *paletteTags, u8 minSlot, u8 maxSlot)
{
    while (minSlot < maxSlot)
    {
        pal_patch_for_npc(*paletteTags, minSlot);
        paletteTags ++;
        minSlot ++;
    }
}

static u8 FindFieldObjectPaletteIndexByTag(u16 tag)
{
    u8 i;

    for (i = 0; gUnknown_0850BBC8[i].tag != 0x11ff; i ++)
    {
        if (gUnknown_0850BBC8[i].tag == tag)
        {
            return i;
        }
    }
    return 0xff;
}

void npc_load_two_palettes__no_record(u16 tag, u8 slot)
{
    u8 i;

    pal_patch_for_npc(tag, slot);
    for (i = 0; gUnknown_0850BD00[i].tag != 0x11ff; i ++)
    {
        if (gUnknown_0850BD00[i].tag == tag)
        {
            pal_patch_for_npc(gUnknown_0850BD00[i].data[gUnknown_020375B4], gUnknown_084975C4[slot]);
            return;
        }
    }
}

void npc_load_two_palettes__and_record(u16 tag, u8 slot)
{
    u8 i;

    gUnknown_020375B6 = tag;
    pal_patch_for_npc(tag, slot);
    for (i = 0; gUnknown_0850BD78[i].tag != 0x11ff; i ++)
    {
        if (gUnknown_0850BD78[i].tag == tag)
        {
            pal_patch_for_npc(gUnknown_0850BD78[i].data[gUnknown_020375B4], gUnknown_084975C4[slot]);
            return;
        }
    }
}

static void sub_808EAB0(u16 tag, u8 slot)
{
    pal_patch_for_npc(tag, slot);
}

void unref_sub_808EAC4(struct MapObject *mapObject, s16 x, s16 y)
{
    mapObject->coords3.x = mapObject->coords2.x;
    mapObject->coords3.y = mapObject->coords2.y;
    mapObject->coords2.x += x;
    mapObject->coords2.y += y;
}

void npc_coords_shift(struct MapObject *mapObject, s16 x, s16 y)
{
    mapObject->coords3.x = mapObject->coords2.x;
    mapObject->coords3.y = mapObject->coords2.y;
    mapObject->coords2.x = x;
    mapObject->coords2.y = y;
}

/*static*/ void npc_coords_set(struct MapObject *mapObject, s16 x, s16 y)
{
    mapObject->coords3.x = x;
    mapObject->coords3.y = y;
    mapObject->coords2.x = x;
    mapObject->coords2.y = y;
}

void sub_808EB08(struct MapObject *mapObject, s16 x, s16 y)
{
    struct Sprite *sprite;
    const struct MapObjectGraphicsInfo *graphicsInfo;

    sprite = &gSprites[mapObject->spriteId];
    graphicsInfo = GetFieldObjectGraphicsInfo(mapObject->graphicsId);
    npc_coords_set(mapObject, x, y);
    sub_8093038(mapObject->coords2.x, mapObject->coords2.y, &sprite->pos1.x, &sprite->pos1.y);
    sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
    sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
    sprite->pos1.x += 8;
    sprite->pos1.y += 16 + sprite->centerToCornerVecY;
    sub_808E38C(mapObject);
    if (mapObject->mapobj_bit_15)
    {
        CameraObjectReset1();
    }
}

void sub_808EBA8(u8 localId, u8 mapNum, u8 mapGroup, s16 x, s16 y)
{
    u8 mapObjectId;

    if (!TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &mapObjectId))
    {
        x += 7;
        y += 7;
        sub_808EB08(&gMapObjects[mapObjectId], x, y);
    }
}

void npc_coords_shift_still(struct MapObject *mapObject)
{
    npc_coords_shift(mapObject, mapObject->coords2.x, mapObject->coords2.y);
}

void UpdateFieldObjectCoordsForCameraUpdate(void)
{
    u8 i;
    s16 dx;
    s16 dy;

    if (gCamera.active)
    {
        dx = gCamera.x;
        dy = gCamera.y;
        for (i = 0; i < NUM_FIELD_OBJECTS; i ++)
        {
            if (gMapObjects[i].active)
            {
                gMapObjects[i].coords1.x -= dx;
                gMapObjects[i].coords1.y -= dy;
                gMapObjects[i].coords2.x -= dx;
                gMapObjects[i].coords2.y -= dy;
                gMapObjects[i].coords3.x -= dx;
                gMapObjects[i].coords3.y -= dy;
            }
        }
    }
}

u8 GetFieldObjectIdByXYZ(u16 x, u16 y, u8 z)
{
    u8 i;
    for (i = 0; i < NUM_FIELD_OBJECTS; i ++)
    {
        if (gMapObjects[i].active)
        {
            if (gMapObjects[i].coords2.x == x && gMapObjects[i].coords2.y == y && FieldObjectDoesZCoordMatch(&gMapObjects[i], z))
            {
                return i;
            }
        }
    }
    return NUM_FIELD_OBJECTS;
}

static bool8 FieldObjectDoesZCoordMatch(struct MapObject *mapObject, u8 z)
{
    if (mapObject->mapobj_unk_0B_0 != 0 && z != 0 && mapObject->mapobj_unk_0B_0 != z)
    {
        return FALSE;
    }
    return TRUE;
}

void UpdateFieldObjectsForCameraUpdate(s16 x, s16 y)
{
    UpdateFieldObjectCoordsForCameraUpdate();
    SpawnFieldObjectsInView(x, y);
    RemoveFieldObjectsOutsideView();
}

u8 AddCameraObject(u8 linkedSpriteId)
{
    u8 spriteId;

    spriteId = CreateSprite(&gUnknown_084975D4, 0, 0, 4);
    gSprites[spriteId].invisible = TRUE;
    gSprites[spriteId].data0 = linkedSpriteId;
    return spriteId;
}

void ObjectCB_CameraObject(struct Sprite *sprite)
{
    void (*callbacks[ARRAY_COUNT(gUnknown_084975EC)])(struct Sprite *);

    memcpy(callbacks, gUnknown_084975EC, sizeof gUnknown_084975EC);
    callbacks[sprite->data1](sprite);
}

/*static*/ void CameraObject_0(struct Sprite *sprite)
{
    sprite->pos1.x = gSprites[sprite->data0].pos1.x;
    sprite->pos1.y = gSprites[sprite->data0].pos1.y;
    sprite->invisible = TRUE;
    sprite->data1 = 1;
    CameraObject_1(sprite);
}

/*static*/ void CameraObject_1(struct Sprite *sprite)
{
    s16 x;
    s16 y;

    y = gSprites[sprite->data0].pos1.y;
    x = gSprites[sprite->data0].pos1.x;
    sprite->data2 = x - sprite->pos1.x;
    sprite->data3 = y - sprite->pos1.y;
    sprite->pos1.x = x;
    sprite->pos1.y = y;
}

/*static*/ void CameraObject_2(struct Sprite *sprite)
{
    sprite->pos1.x = gSprites[sprite->data0].pos1.x;
    sprite->pos1.y = gSprites[sprite->data0].pos1.y;
    sprite->data2 = 0;
    sprite->data3 = 0;
}

static struct Sprite *FindCameraObject(void)
{
    u8 spriteId;

    for (spriteId = 0; spriteId < MAX_SPRITES; spriteId ++)
    {
        if (gSprites[spriteId].inUse && gSprites[spriteId].callback == ObjectCB_CameraObject)
        {
            return &gSprites[spriteId];
        }
    }
    return NULL;
}

void CameraObjectReset1(void)
{
    struct Sprite *cameraObject;

    cameraObject = FindCameraObject();
    if (cameraObject != NULL)
    {
        cameraObject->data1 = 0;
        cameraObject->callback(cameraObject);
    }
}

void CameraObjectSetFollowedObjectId(u8 objectId)
{
    struct Sprite *cameraObject;

    cameraObject = FindCameraObject();
    if (cameraObject != NULL)
    {
        cameraObject->data0 = objectId;
        CameraObjectReset1();
    }
}

u8 CameraObjectGetFollowedObjectId(void)
{
    struct Sprite *cameraObject;

    cameraObject = FindCameraObject();
    if (cameraObject == NULL)
    {
        return MAX_SPRITES;
    }
    return cameraObject->data0;
}

void CameraObjectReset2(void)
{
    FindCameraObject()->data1 = 2;
}

u8 CopySprite(struct Sprite *sprite, s16 x, s16 y, u8 subpriority)
{
    u8 i;

    for (i = 0; i < MAX_SPRITES; i ++)
    {
        if (!gSprites[i].inUse)
        {
            gSprites[i] = *sprite;
            gSprites[i].pos1.x = x;
            gSprites[i].pos1.y = y;
            gSprites[i].subpriority = subpriority;
            break;
        }
    }
    return i;
}

u8 obj_unfreeze(struct Sprite *sprite, s16 x, s16 y, u8 subpriority)
{
    s16 i;

    for (i = MAX_SPRITES - 1; i > -1; i --)
    {
        if (!gSprites[i].inUse)
        {
            gSprites[i] = *sprite;
            gSprites[i].pos1.x = x;
            gSprites[i].pos1.y = y;
            gSprites[i].subpriority = subpriority;
            return i;
        }
    }
    return MAX_SPRITES;
}

void FieldObjectSetDirection(struct MapObject *mapObject, u8 direction)
{
    s8 d2;
    mapObject->mapobj_unk_20 = mapObject->mapobj_unk_18;
    if (!mapObject->mapobj_bit_9)
    {
        d2 = direction;
        mapObject->mapobj_unk_18 = d2;
    }
    mapObject->placeholder18 = direction;
}

static const u8 *GetFieldObjectScriptPointerByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    return GetFieldObjectTemplateByLocalIdAndMap(localId, mapNum, mapGroup)->script;
}

const u8 *GetFieldObjectScriptPointerByFieldObjectId(u8 mapObjectId)
{
    return GetFieldObjectScriptPointerByLocalIdAndMap(gMapObjects[mapObjectId].localId, gMapObjects[mapObjectId].mapNum, gMapObjects[mapObjectId].mapGroup);
}

static u16 GetFieldObjectFlagIdByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    return GetFieldObjectTemplateByLocalIdAndMap(localId, mapNum, mapGroup)->flagId;
}

u16 GetFieldObjectFlagIdByFieldObjectId(u8 mapObjectId)
{
    return GetFieldObjectFlagIdByLocalIdAndMap(gMapObjects[mapObjectId].localId, gMapObjects[mapObjectId].mapNum, gMapObjects[mapObjectId].mapGroup);
}

u8 sub_808F080(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 mapObjectId;

    if (TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &mapObjectId))
    {
        return 0xFF;
    }
    return gMapObjects[mapObjectId].trainerType;
}

u8 sub_808F0BC(u8 mapObjectId)
{
    return gMapObjects[mapObjectId].trainerType;
}

u8 sub_808F0D4(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 mapObjectId;

    if (TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &mapObjectId))
    {
        return 0xFF;
    }
    return gMapObjects[mapObjectId].trainerRange_berryTreeId;
}

u8 FieldObjectGetBerryTreeId(u8 mapObjectId)
{
    return gMapObjects[mapObjectId].trainerRange_berryTreeId;
}

struct MapObjectTemplate *GetFieldObjectTemplateByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    struct MapObjectTemplate *templates;
    const struct MapHeader *mapHeader;
    u8 count;

    if (gSaveBlock1Ptr->location.mapNum == mapNum && gSaveBlock1Ptr->location.mapGroup == mapGroup)
    {
        templates = gSaveBlock1Ptr->mapObjectTemplates;
        count = gMapHeader.events->mapObjectCount;
    }
    else
    {
        mapHeader = get_mapheader_by_bank_and_number(mapGroup, mapNum);
        templates = mapHeader->events->mapObjects;
        count = mapHeader->events->mapObjectCount;
    }
    return FindFieldObjectTemplateInArrayByLocalId(localId, templates, count);
}

struct MapObjectTemplate *FindFieldObjectTemplateInArrayByLocalId(u8 localId, struct MapObjectTemplate *templates, u8 count)
{
    u8 i;

    for (i = 0; i < count; i ++)
    {
        if (templates[i].localId == localId)
        {
            return &templates[i];
        }
    }
    return NULL;
}

struct MapObjectTemplate *sub_808F1B4(const struct MapObject *mapObject)
{
    int i;

    if (mapObject->mapNum != gSaveBlock1Ptr->location.mapNum || mapObject->mapGroup != gSaveBlock1Ptr->location.mapGroup)
    {
        return NULL;
    }
    for (i = 0; i < 64; i ++) // Using ARRAY_COUNT here results in the wrong conditional branch instruction (bls instead of ble)
    {
        if (mapObject->localId == gSaveBlock1Ptr->mapObjectTemplates[i].localId)
        {
            return &gSaveBlock1Ptr->mapObjectTemplates[i];
        }
    }
    return NULL;
}

void sub_808F208(const struct MapObject *mapObject)
{
    struct MapObjectTemplate *mapObjectTemplate;

    mapObjectTemplate = sub_808F1B4(mapObject);
    if (mapObjectTemplate != NULL)
    {
        mapObjectTemplate->x = mapObject->coords2.x - 7;
        mapObjectTemplate->y = mapObject->coords2.y - 7;
    }
}

void sub_808F228(const struct MapObject *mapObject, const u8 *script)
{
    struct MapObjectTemplate *mapObjectTemplate;

    mapObjectTemplate = sub_808F1B4(mapObject);
    if (mapObjectTemplate != NULL)
    {
        mapObjectTemplate->script = script;
    }
}

void sub_808F23C(const struct MapObject *mapObject, u8 movementType)
{
    struct MapObjectTemplate *mapObjectTemplate;

    mapObjectTemplate = sub_808F1B4(mapObject);
    if (mapObjectTemplate != NULL)
    {
        mapObjectTemplate->movementType = movementType;
    }
}

void sub_808F254(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 mapObjectId;

    if (!TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &mapObjectId))
    {
        sub_808F208(&gMapObjects[mapObjectId]);
    }
}

void sub_808F28C(u8 localId, u8 mapNum, u8 mapGroup, u8 action)
{
    u8 mapObjectId;

    if (!TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &mapObjectId))
    {
        switch (action)
        {
            case 6:
                sub_808F228(&gMapObjects[mapObjectId], gUnknown_082766A2);
                break;
            case 7:
                sub_808F228(&gMapObjects[mapObjectId], gUnknown_082766A6);
                break;
        }
    }
}

void npc_paltag_set_load(u8 palSlot)
{
    gpu_pal_allocator_reset__manage_upper_four();
    gUnknown_020375B6 = 0x11ff;
    gUnknown_020375B4 = palSlot;
    if (palSlot == 1)
    {
        pal_patch_for_npc_range(gUnknown_0850BE38[gUnknown_020375B4], 0, 6);
        gReservedSpritePaletteCount = 8;
    }
    else
    {
        pal_patch_for_npc_range(gUnknown_0850BE38[gUnknown_020375B4], 0, 10);
    }
}

u16 npc_paltag_by_palslot(u8 palSlot)
{
    u8 i;

    if (palSlot < 10)
    {
        return gUnknown_0850BE38[gUnknown_020375B4][palSlot];
    }
    for (i = 0; gUnknown_0850BD78[i].tag != 0x11ff; i ++)
    {
        if (gUnknown_0850BD78[i].tag == gUnknown_020375B6)
        {
            return gUnknown_0850BD78[i].data[gUnknown_020375B4];
        }
    }
    return 0x11ff;
}

// Map Object Step Callbacks

null_object_step(NoMovement1, FALSE)

field_object_step(GoRandomDirections, gUnknown_0850D6F4)

bool8 sub_808F44C(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data1 = 1;
    return TRUE;
}

bool8 sub_808F460(struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->mapobj_unk_18));
    sprite->data1 = 2;
    return TRUE;
}

bool8 sub_808F48C(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (!FieldObjectExecRegularAnim(mapObject, sprite))
    {
        return FALSE;
    }
    SetFieldObjectStepTimer(sprite, gUnknown_0850D6DC[Random() & 0x03]);
    sprite->data1 = 3;
    return TRUE;
}

bool8 sub_808F4C8(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite))
    {
        sprite->data1 = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_808F4E8(struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 directions[4];
    u8 chosenDirection;

    memcpy(directions, gUnknown_0850D710, sizeof directions);
    chosenDirection = directions[Random() & 0x03];
    FieldObjectSetDirection(mapObject, chosenDirection);
    sprite->data1 = 5;
    if (npc_block_way__next_tile(mapObject, chosenDirection))
    {
        sprite->data1 = 1;
    }
    return TRUE;
}

bool8 sub_808F534(struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetGoSpeed0AnimId(mapObject->placeholder18));
    mapObject->mapobj_bit_1 = TRUE;
    sprite->data1 = 6;
    return TRUE;
}

bool8 sub_808F564(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        mapObject->mapobj_bit_1 = FALSE;
        sprite->data1 = 1;
    }
    return FALSE;
}

bool8 FieldObjectIsTrainerAndCloseToPlayer(struct MapObject *mapObject)
{
    s16 playerX;
    s16 playerY;
    s16 objX;
    s16 objY;
    s16 minX;
    s16 maxX;
    s16 minY;
    s16 maxY;

    if (!TestPlayerAvatarFlags(0x80))
    {
        return FALSE;
    }
    if (mapObject->trainerType != 1 && mapObject->trainerType != 3)
    {
        return FALSE;
    }
    PlayerGetDestCoords(&playerX, &playerY);
    objX = mapObject->coords2.x;
    objY = mapObject->coords2.y;
    minX = objX - mapObject->trainerRange_berryTreeId;
    minY = objY - mapObject->trainerRange_berryTreeId;
    maxX = objX + mapObject->trainerRange_berryTreeId;
    maxY = objY + mapObject->trainerRange_berryTreeId;
    if (minX > playerX || maxX < playerX || minY > playerY || maxY < playerY)
    {
        return FALSE;
    }
    return TRUE;
}

u8 GetRegularRunningPastFacingDirection(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    if (absdx > absdy)
    {
        direction = DIR_EAST;
        if (dx < 0)
        {
            direction = DIR_WEST;
        }
    }
    else
    {
        direction = DIR_SOUTH;
        if (dy < 0)
        {
            direction = DIR_NORTH;
        }
    }
    return direction;
}

u8 GetNorthSouthRunningPastFacingDirection(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = DIR_SOUTH;
    if (dy < 0)
    {
        direction = DIR_NORTH;
    }
    return direction;
}

u8 GetEastWestRunningPastFacingDirection(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = DIR_EAST;
    if (dx < 0)
    {
        direction = DIR_WEST;
    }
    return direction;
}

u8 GetNorthEastRunningPastFacingDirection(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetRegularRunningPastFacingDirection(dx, dy, absdx, absdy);
    if (direction == DIR_SOUTH)
    {
        direction = GetEastWestRunningPastFacingDirection(dx, dy, absdx, absdy);
        if (direction == DIR_EAST)
        {
            direction = DIR_NORTH;
        }
    }
    else if (direction == DIR_EAST)
    {
        direction = GetNorthSouthRunningPastFacingDirection(dx, dy, absdx, absdy);
        if (direction == DIR_SOUTH)
        {
            direction = DIR_NORTH;
        }
    }
    return direction;
}

u8 GetNorthWestRunningPastFacingDirection(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetRegularRunningPastFacingDirection(dx, dy, absdx, absdy);
    if (direction == DIR_SOUTH)
    {
        direction = GetEastWestRunningPastFacingDirection(dx, dy, absdx, absdy);
        if (direction == DIR_WEST)
        {
            direction = DIR_NORTH;
        }
    }
    else if (direction == DIR_WEST)
    {
        direction = GetNorthSouthRunningPastFacingDirection(dx, dy, absdx, absdy);
        if (direction == DIR_SOUTH)
        {
            direction = DIR_NORTH;
        }
    }
    return direction;
}

u8 GetSouthEastRunningPastFacingDirection(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetRegularRunningPastFacingDirection(dx, dy, absdx, absdy);
    if (direction == DIR_NORTH)
    {
        direction = GetEastWestRunningPastFacingDirection(dx, dy, absdx, absdy);
        if (direction == DIR_EAST)
        {
            direction = DIR_SOUTH;
        }
    }
    else if (direction == DIR_EAST)
    {
        direction = GetNorthSouthRunningPastFacingDirection(dx, dy, absdx, absdy);
        if (direction == DIR_NORTH)
        {
            direction = DIR_SOUTH;
        }
    }
    return direction;
}

u8 GetSouthWestRunningPastFacingDirection(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetRegularRunningPastFacingDirection(dx, dy, absdx, absdy);
    if (direction == DIR_NORTH)
    {
        direction = GetEastWestRunningPastFacingDirection(dx, dy, absdx, absdy);
        if (direction == DIR_WEST)
        {
            direction = DIR_SOUTH;
        }
    }
    else if (direction == DIR_WEST)
    {
        direction = GetNorthSouthRunningPastFacingDirection(dx, dy, absdx, absdy);
        if (direction == DIR_NORTH)
        {
            direction = DIR_SOUTH;
        }
    }
    return direction;
}

u8 GetNonEastRunningPastFacingDirection(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetRegularRunningPastFacingDirection(dx, dy, absdx, absdy);
    if (direction == DIR_EAST)
    {
        direction = GetNorthSouthRunningPastFacingDirection(dx, dy, absdx, absdy);
    }
    return direction;
}

u8 GetNonWestRunningPastFacingDirection(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetRegularRunningPastFacingDirection(dx, dy, absdx, absdy);
    if (direction == DIR_WEST)
    {
        direction = GetNorthSouthRunningPastFacingDirection(dx, dy, absdx, absdy);
    }
    return direction;
}

u8 GetNonSouthRunningPastFacingDirection(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetRegularRunningPastFacingDirection(dx, dy, absdx, absdy);
    if (direction == DIR_SOUTH)
    {
        direction = GetEastWestRunningPastFacingDirection(dx, dy, absdx, absdy);
    }
    return direction;
}

u8 GetNonNorthRunningPastFacingDirection(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetRegularRunningPastFacingDirection(dx, dy, absdx, absdy);
    if (direction == DIR_NORTH)
    {
        direction = GetEastWestRunningPastFacingDirection(dx, dy, absdx, absdy);
    }
    return direction;
}

u8 GetRunningPastFacingDirection(struct MapObject *mapObject, u8 movementType)
{
    s16 dx;
    s16 dy;
    s16 absdx;
    s16 absdy;

    if (!FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        return 0;
    }
    PlayerGetDestCoords(&dx, &dy);
    dx -= mapObject->coords2.x;
    dy -= mapObject->coords2.y;
    absdx = dx;
    absdy = dy;
    if (absdx < 0)
    {
        absdx = -absdx;
    }
    if (absdy < 0)
    {
        absdy = -absdy;
    }
    return gUnknown_0850D714[movementType](dx, dy, absdx, absdy);
}

field_object_step(LookRandomDirections, gUnknown_0850D740)

bool8 sub_808F988(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data1 = 1;
    return TRUE;
}

bool8 sub_808F99C(struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->mapobj_unk_18));
    sprite->data1 = 2;
    return TRUE;
}

bool8 sub_808F9C8(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, gUnknown_0850D6DC[Random() & 0x03]);
        mapObject->mapobj_bit_1 = FALSE;
        sprite->data1 = 3;
    }
    return FALSE;
}

bool8 sub_808FA0C(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data1 = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_808FA3C(struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 directions[4];
    u8 direction;

    memcpy(directions, gUnknown_0850D710, sizeof directions);
    direction = GetRunningPastFacingDirection(mapObject, RUNFOLLOW_ANY);
    if (direction == 0)
    {
        direction = directions[Random() & 0x03];
    }
    FieldObjectSetDirection(mapObject, direction);
    sprite->data1 = 1;
    return TRUE;
}

field_object_step(RandomlyGoNorthOrSouth, gUnknown_0850D754)

bool8 sub_808FAC8(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data1 = 1;
    return TRUE;
}

bool8 sub_808FADC(struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->mapobj_unk_18));
    sprite->data1 = 2;
    return TRUE;
}

bool8 sub_808FB08(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (!FieldObjectExecRegularAnim(mapObject, sprite))
    {
        return FALSE;
    }
    SetFieldObjectStepTimer(sprite, gUnknown_0850D6DC[Random() & 0x03]);
    sprite->data1 = 3;
    return TRUE;
}

bool8 sub_808FB44(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite))
    {
        sprite->data1 = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_808FB64(struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 directions[2];
    u8 direction;

    memcpy(directions, gUnknown_0850D770, sizeof directions);
    direction = directions[Random() & 0x01];
    FieldObjectSetDirection(mapObject, direction);
    sprite->data1 = 5;
    if (npc_block_way__next_tile(mapObject, direction))
    {
        sprite->data1 = 1;
    }
    return TRUE;
}

bool8 sub_808FBB0(struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetGoSpeed0AnimId(mapObject->placeholder18));
    mapObject->mapobj_bit_1 = TRUE;
    sprite->data1 = 6;
    return TRUE;
}

bool8 sub_808FBE0(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        mapObject->mapobj_bit_1 = FALSE;
        sprite->data1 = 1;
    }
    return FALSE;
}

field_object_step(RandomlyGoEastOrWest, gUnknown_0850D774)

bool8 sub_808FC4C(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data1 = 1;
    return TRUE;
}

bool8 sub_808FC60(struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->mapobj_unk_18));
    sprite->data1 = 2;
    return TRUE;
}

bool8 sub_808FC8C(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (!FieldObjectExecRegularAnim(mapObject, sprite))
    {
        return FALSE;
    }
    SetFieldObjectStepTimer(sprite, gUnknown_0850D6DC[Random() & 0x03]);
    sprite->data1 = 3;
    return TRUE;
}

bool8 sub_808FCC8(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite))
    {
        sprite->data1 = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_808FCE8(struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 directions[2];
    u8 direction;

    memcpy(directions, gUnknown_0850D790, sizeof directions);
    direction = directions[Random() & 0x01];
    FieldObjectSetDirection(mapObject, direction);
    sprite->data1 = 5;
    if (npc_block_way__next_tile(mapObject, direction))
    {
        sprite->data1 = 1;
    }
    return TRUE;
}

bool8 sub_808FD34(struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetGoSpeed0AnimId(mapObject->placeholder18));
    mapObject->mapobj_bit_1 = TRUE;
    sprite->data1 = 6;
    return TRUE;
}

bool8 sub_808FD64(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        mapObject->mapobj_bit_1 = FALSE;
        sprite->data1 = 1;
    }
    return FALSE;
}

field_object_step(FaceFixedDirection, gUnknown_0850D794)

bool8 sub_808FDD0(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->mapobj_unk_18));
    sprite->data1 = 1;
    return TRUE;
}

bool8 sub_808FDFC(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        sprite->data1 = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_808FE1C(struct MapObject *mapObject, struct Sprite *sprite)
{
    mapObject->mapobj_bit_1 = FALSE;
    return FALSE;
}

static bool8 FieldObjectCB2_BerryTree(struct MapObject *mapObject, struct Sprite *sprite);
extern bool8 (*const gUnknown_0850D7A0[])(struct MapObject *mapObject, struct Sprite *sprite);
void FieldObjectCB_BerryTree(struct Sprite *sprite)
{
    struct MapObject *mapObject;

    mapObject = &gMapObjects[sprite->data0];
    if (!(sprite->data7 & 0x0001))
    {
        get_berry_tree_graphics(mapObject, sprite);
        sprite->data7 |= 0x0001;
    }
    FieldObjectStep(mapObject, sprite, FieldObjectCB2_BerryTree);
}
static bool8 FieldObjectCB2_BerryTree(struct MapObject *mapObject, struct Sprite *sprite)
{
    return gUnknown_0850D7A0[sprite->data1](mapObject, sprite);
}

bool8 do_berry_tree_growth_sparkle_1 (struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 berryStage;

    npc_reset(mapObject, sprite);
    mapObject->mapobj_bit_13 = TRUE;
    sprite->invisible = TRUE;
    berryStage = GetStageByBerryTreeId(mapObject->trainerRange_berryTreeId);
    if (berryStage == 0)
    {
        if (!(sprite->data7 & 0x0004) && sprite->animNum == 4)
        {
            gFieldEffectSpawnParams[0] = mapObject->coords2.x;
            gFieldEffectSpawnParams[1] = mapObject->coords2.y;
            gFieldEffectSpawnParams[2] = sprite->subpriority - 1;
            gFieldEffectSpawnParams[3] = sprite->oam.priority;
            FieldEffectStart(FLDEFF_BERRY_TREE_GROWTH_SPARKLE);
            sprite->animNum = berryStage;
        }
        return FALSE;
    }
    mapObject->mapobj_bit_13 = FALSE;
    sprite->invisible = FALSE;
    berryStage --;
    if (sprite->animNum != berryStage)
    {
        sprite->data1 = 2;
        return TRUE;
    }
    get_berry_tree_graphics(mapObject, sprite);
    FieldObjectSetRegularAnim(mapObject, sprite, 0x39);
    sprite->data1 = 1;
    return TRUE;
}

bool8 sub_808FF48 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        sprite->data1 = 0;
        return TRUE;
    }
    return FALSE;
}

bool8 do_berry_tree_growth_sparkle_2 (struct MapObject *mapObject, struct Sprite *sprite)
{
    mapObject->mapobj_bit_1 = TRUE;
    sprite->data1 = 3;
    sprite->data2 = 0;
    sprite->data7 |= 0x0002;
    gFieldEffectSpawnParams[0] = mapObject->coords2.x;
    gFieldEffectSpawnParams[1] = mapObject->coords2.y;
    gFieldEffectSpawnParams[2] = sprite->subpriority - 1;
    gFieldEffectSpawnParams[3] = sprite->oam.priority;
    FieldEffectStart(FLDEFF_BERRY_TREE_GROWTH_SPARKLE);
    return TRUE;
}

bool8 sub_808FFB4 (struct MapObject *mapObject, struct Sprite *sprite)
{
    sprite->data2 ++;
    mapObject->mapobj_bit_13 = (sprite->data2 & 0x02) >> 1;
    sprite->animPaused = TRUE;
    if (sprite->data2 > 64)
    {
        get_berry_tree_graphics(mapObject, sprite);
        sprite->data1 = 4;
        sprite->data2 = 0;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8090004 (struct MapObject *mapObject, struct Sprite *sprite)
{
    sprite->data2 ++;
    mapObject->mapobj_bit_13 = (sprite->data2 & 0x02) >> 1;
    sprite->animPaused = TRUE;
    if (sprite->data2 > 64)
    {
        sprite->data1 = 0;
        sprite->data7 &= ~0x0002;
        return TRUE;
    }
    return FALSE;
}

field_object_step(RandomlyLookNorthOrSouth, gUnknown_0850D7B4)

bool8 sub_8090094 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data1 = 1;
    return TRUE;
}

bool8 sub_80900A8 (struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->mapobj_unk_18));
    sprite->data1 = 2;
    return TRUE;
}

bool8 sub_80900D4 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, gUnknown_0850D6DC[Random() & 0x03]);
        mapObject->mapobj_bit_1 = FALSE;
        sprite->data1 = 3;
    }
    return FALSE;
}

bool8 sub_8090118 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data1 = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8090148 (struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 directions[2];
    u8 direction;

    memcpy(directions, gUnknown_0850D770, sizeof gUnknown_0850D770);
    direction = GetRunningPastFacingDirection(mapObject, RUNFOLLOW_NORTH_SOUTH);
    if (direction == 0)
    {
        direction = directions[Random() & 0x01];
    }
    FieldObjectSetDirection(mapObject, direction);
    sprite->data1 = 1;
    return TRUE;
}

field_object_step(RandomlyLookEastOrWest, gUnknown_0850D7C8)

bool8 sub_80901D4 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data1 = 1;
    return TRUE;
}

bool8 sub_80901E8 (struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->mapobj_unk_18));
    sprite->data1 = 2;
    return TRUE;
}

bool8 sub_8090214 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, gUnknown_0850D6DC[Random() & 0x03]);
        mapObject->mapobj_bit_1 = FALSE;
        sprite->data1 = 3;
    }
    return FALSE;
}

bool8 sub_8090258 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data1 = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8090288 (struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 directions[2];
    u8 direction;

    memcpy(directions, gUnknown_0850D790, sizeof gUnknown_0850D790);
    direction = GetRunningPastFacingDirection(mapObject, RUNFOLLOW_EAST_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 0x01];
    }
    FieldObjectSetDirection(mapObject, direction);
    sprite->data1 = 1;
    return TRUE;
}

field_object_step(RandomlyLookNorthOrWest, gUnknown_0850D7DC)

bool8 sub_8090314 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data1 = 1;
    return TRUE;
}

bool8 sub_8090328 (struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->mapobj_unk_18));
    sprite->data1 = 2;
    return TRUE;
}

bool8 sub_8090354 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, gUnknown_0850D6EC[Random() & 0x03]);
        mapObject->mapobj_bit_1 = FALSE;
        sprite->data1 = 3;
    }
    return FALSE;
}

bool8 sub_8090398 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data1 = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_80903C8 (struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 directions[2];
    u8 direction;

    memcpy(directions, gUnknown_0850D7F0, sizeof gUnknown_0850D7F0);
    direction = GetRunningPastFacingDirection(mapObject, RUNFOLLOW_NORTH_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 0x01];
    }
    FieldObjectSetDirection(mapObject, direction);
    sprite->data1 = 1;
    return TRUE;
}

field_object_step(RandomlyLookNorthOrEast, gUnknown_0850D7F4)

bool8 sub_8090454 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data1 = 1;
    return TRUE;
}

bool8 sub_8090468 (struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->mapobj_unk_18));
    sprite->data1 = 2;
    return TRUE;
}

bool8 sub_8090494 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, gUnknown_0850D6EC[Random() & 0x03]);
        mapObject->mapobj_bit_1 = FALSE;
        sprite->data1 = 3;
    }
    return FALSE;
}

bool8 sub_80904D8 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data1 = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8090508 (struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 directions[2];
    u8 direction;

    memcpy(directions, gUnknown_0850D808, sizeof gUnknown_0850D808);
    direction = GetRunningPastFacingDirection(mapObject, RUNFOLLOW_NORTH_EAST);
    if (direction == 0)
    {
        direction = directions[Random() & 0x01];
    }
    FieldObjectSetDirection(mapObject, direction);
    sprite->data1 = 1;
    return TRUE;
}

field_object_step(RandomlyLookSouthOrWest, gUnknown_0850D80C)

bool8 sub_8090594 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data1 = 1;
    return TRUE;
}

bool8 sub_80905A8 (struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->mapobj_unk_18));
    sprite->data1 = 2;
    return TRUE;
}

bool8 sub_80905D4 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, gUnknown_0850D6EC[Random() & 0x03]);
        mapObject->mapobj_bit_1 = FALSE;
        sprite->data1 = 3;
    }
    return FALSE;
}

bool8 sub_8090618 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data1 = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8090648 (struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 directions[2];
    u8 direction;

    memcpy(directions, gUnknown_0850D820, sizeof gUnknown_0850D820);
    direction = GetRunningPastFacingDirection(mapObject, RUNFOLLOW_SOUTH_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 0x01];
    }
    FieldObjectSetDirection(mapObject, direction);
    sprite->data1 = 1;
    return TRUE;
}

field_object_step(RandomlyLookSouthOrEast, gUnknown_0850D824)

bool8 sub_80906D4 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data1 = 1;
    return TRUE;
}

bool8 sub_80906E8 (struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->mapobj_unk_18));
    sprite->data1 = 2;
    return TRUE;
}

bool8 sub_8090714 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, gUnknown_0850D6EC[Random() & 0x03]);
        mapObject->mapobj_bit_1 = FALSE;
        sprite->data1 = 3;
    }
    return FALSE;
}

bool8 sub_8090758 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data1 = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8090788 (struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 directions[2];
    u8 direction;

    memcpy(directions, gUnknown_0850D838, sizeof gUnknown_0850D838);
    direction = GetRunningPastFacingDirection(mapObject, RUNFOLLOW_SOUTH_EAST);
    if (direction == 0)
    {
        direction = directions[Random() & 0x01];
    }
    FieldObjectSetDirection(mapObject, direction);
    sprite->data1 = 1;
    return TRUE;
}

field_object_step(RandomlyLookNorthOrSouthOrWest, gUnknown_0850D83C)

bool8 sub_8090814 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data1 = 1;
    return TRUE;
}

bool8 sub_8090828 (struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->mapobj_unk_18));
    sprite->data1 = 2;
    return TRUE;
}

bool8 sub_8090854 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, gUnknown_0850D6EC[Random() & 0x03]);
        mapObject->mapobj_bit_1 = FALSE;
        sprite->data1 = 3;
    }
    return FALSE;
}

bool8 sub_8090898 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data1 = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_80908C8 (struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 directions[4];
    u8 direction;

    memcpy(directions, gUnknown_0850D850, sizeof gUnknown_0850D850);
    direction = GetRunningPastFacingDirection(mapObject, RUNFOLLOW_NORTH_SOUTH_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 0x03];
    }
    FieldObjectSetDirection(mapObject, direction);
    sprite->data1 = 1;
    return TRUE;
}

field_object_step(RandomlyLookNorthOrSouthOrEast, gUnknown_0850D854)

bool8 sub_8090954 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data1 = 1;
    return TRUE;
}

bool8 sub_8090968 (struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->mapobj_unk_18));
    sprite->data1 = 2;
    return TRUE;
}

bool8 sub_8090994 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, gUnknown_0850D6EC[Random() & 0x03]);
        mapObject->mapobj_bit_1 = FALSE;
        sprite->data1 = 3;
    }
    return FALSE;
}

bool8 sub_80909D8 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data1 = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8090A08 (struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 directions[4];
    u8 direction;

    memcpy(directions, gUnknown_0850D868, sizeof gUnknown_0850D868);
    direction = GetRunningPastFacingDirection(mapObject, RUNFOLLOW_NORTH_SOUTH_EAST);
    if (direction == 0)
    {
        direction = directions[Random() & 0x03];
    }
    FieldObjectSetDirection(mapObject, direction);
    sprite->data1 = 1;
    return TRUE;
}

field_object_step(RandomlyLookNorthOrEastOrWest, gUnknown_0850D86C)

bool8 sub_8090A94 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data1 = 1;
    return TRUE;
}

bool8 sub_8090AA8 (struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->mapobj_unk_18));
    sprite->data1 = 2;
    return TRUE;
}

bool8 sub_8090AD4 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, gUnknown_0850D6EC[Random() & 0x03]);
        mapObject->mapobj_bit_1 = FALSE;
        sprite->data1 = 3;
    }
    return FALSE;
}

bool8 sub_8090B18 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data1 = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8090B48 (struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 directions[4];
    u8 direction;

    memcpy(directions, gUnknown_0850D880, sizeof gUnknown_0850D880);
    direction = GetRunningPastFacingDirection(mapObject, RUNFOLLOW_NORTH_EAST_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 0x03];
    }
    FieldObjectSetDirection(mapObject, direction);
    sprite->data1 = 1;
    return TRUE;
}

field_object_step(RandomlyLookSouthOrEastOrWest, gUnknown_0850D884)

bool8 sub_8090BD4 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data1 = 1;
    return TRUE;
}

bool8 sub_8090BE8 (struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->mapobj_unk_18));
    sprite->data1 = 2;
    return TRUE;
}

bool8 sub_8090C14 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, gUnknown_0850D6EC[Random() & 0x03]);
        mapObject->mapobj_bit_1 = FALSE;
        sprite->data1 = 3;
    }
    return FALSE;
}

bool8 sub_8090C58 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data1 = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8090C88 (struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 directions[4];
    u8 direction;

    memcpy(directions, gUnknown_0850D898, sizeof gUnknown_0850D898);
    direction = GetRunningPastFacingDirection(mapObject, RUNFOLLOW_SOUTH_EAST_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 0x03];
    }
    FieldObjectSetDirection(mapObject, direction);
    sprite->data1 = 1;
    return TRUE;
}

field_object_step(LookAroundCounterclockwise, gUnknown_0850D89C)

bool8 sub_8090D14 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->mapobj_unk_18));
    sprite->data1 = 1;
    return TRUE;
}

bool8 sub_8090D40 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, 48);
        sprite->data1 = 2;
    }
    return FALSE;
}

bool8 sub_8090D64 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data1 = 3;
    }
    return FALSE;
}

bool8 sub_8090D90 (struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 directions[5];
    u8 direction;

    memcpy(directions, gUnknown_0850D8AC, sizeof gUnknown_0850D8AC);
    direction = GetRunningPastFacingDirection(mapObject, RUNFOLLOW_ANY);
    if (direction == 0)
    {
        direction = directions[mapObject->mapobj_unk_18];
    }
    FieldObjectSetDirection(mapObject, direction);
    sprite->data1 = 0;
    return TRUE;
}

field_object_step(LookAroundClockwise, gUnknown_0850D8B4)

bool8 sub_8090E18 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->mapobj_unk_18));
    sprite->data1 = 1;
    return TRUE;
}

bool8 sub_8090E44 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, 48);
        sprite->data1 = 2;
    }
    return FALSE;
}

bool8 sub_8090E68 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data1 = 3;
    }
    return FALSE;
}

bool8 sub_8090E94 (struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 directions[5];
    u8 direction;

    memcpy(directions, gUnknown_0850D8C4, sizeof gUnknown_0850D8C4);
    direction = GetRunningPastFacingDirection(mapObject, RUNFOLLOW_ANY);
    if (direction == 0)
    {
        direction = directions[mapObject->mapobj_unk_18];
    }
    FieldObjectSetDirection(mapObject, direction);
    sprite->data1 = 0;
    return TRUE;
}

field_object_step(AlternatelyGoInOppositeDirections, gUnknown_0850D8CC)

bool8 sub_8090F1C (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data1 = 1;
    return TRUE;
}

bool8 sub_8090F30 (struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 direction;

    direction = gUnknown_085055CD[mapObject->animPattern];
    if (mapObject->mapobj_unk_21)
    {
        direction = GetOppositeDirection(direction);
    }
    FieldObjectSetDirection(mapObject, direction);
    sprite->data1 = 2;
    return TRUE;
}

bool8 sub_8090F68 (struct MapObject *mapObject, struct Sprite *sprite)
{
    bool8 blockingWay;
    u8 animId;

    if (mapObject->mapobj_unk_21 && mapObject->coords1.x == mapObject->coords2.x && mapObject->coords1.y == mapObject->coords2.y)
    {
        mapObject->mapobj_unk_21 = 0;
        FieldObjectSetDirection(mapObject, GetOppositeDirection(mapObject->placeholder18));
    }
    blockingWay = npc_block_way__next_tile(mapObject, mapObject->placeholder18);
    animId = GetGoSpeed0AnimId(mapObject->placeholder18);
    if (blockingWay == TRUE)
    {
        mapObject->mapobj_unk_21 ++;
        FieldObjectSetDirection(mapObject, GetOppositeDirection(mapObject->placeholder18));
        animId = GetGoSpeed0AnimId(mapObject->placeholder18);
        blockingWay = npc_block_way__next_tile(mapObject, mapObject->placeholder18);
    }
    if (blockingWay)
    {
        animId = GetStepInPlaceDelay16AnimId(mapObject->mapobj_unk_18);
    }
    FieldObjectSetRegularAnim(mapObject, sprite, animId);
    mapObject->mapobj_bit_1 = TRUE;
    sprite->data1 = 3;
    return TRUE;
}

bool8 sub_8091020 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        mapObject->mapobj_bit_1 = FALSE;
        sprite->data1 = 1;
    }
    return FALSE;
}

bool8 sub_8091048(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data1 = 1;
    return TRUE;
}

bool8 MoveFieldObjectInNextDirectionInSequence(struct MapObject *mapObject, struct Sprite *sprite, u8 *route)
{
    u8 blockingWay;
    u8 animId;

    if (mapObject->mapobj_unk_21 == 3 && mapObject->coords1.x == mapObject->coords2.x && mapObject->coords1.y == mapObject->coords2.y)
    {
        mapObject->mapobj_unk_21 = 0;
    }
    FieldObjectSetDirection(mapObject, route[mapObject->mapobj_unk_21]);
    animId = GetGoSpeed0AnimId(mapObject->placeholder18);
    blockingWay = npc_block_way__next_tile(mapObject, mapObject->placeholder18);
    if (blockingWay == TRUE)
    {
        mapObject->mapobj_unk_21 ++;
        FieldObjectSetDirection(mapObject, route[mapObject->mapobj_unk_21]);
        animId = GetGoSpeed0AnimId(mapObject->placeholder18);
        blockingWay = npc_block_way__next_tile(mapObject, mapObject->placeholder18);
    }
    if (blockingWay)
    {
        animId = GetStepInPlaceDelay16AnimId(mapObject->mapobj_unk_18);
    }
    FieldObjectSetRegularAnim(mapObject, sprite, animId);
    mapObject->mapobj_bit_1 = TRUE;
    sprite->data1 = 2;
    return TRUE;
}

bool8 sub_8091110(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        mapObject->mapobj_bit_1 = FALSE;
        sprite->data1 = 1;
    }
    return FALSE;
}

field_object_path( 1, gUnknown_0850D8DC, sub_809117C, gUnknown_0850D8E8, 2, x)
field_object_path( 2, gUnknown_0850D8EC, sub_8091208, gUnknown_0850D8F8, 1, x)
field_object_path( 3, gUnknown_0850D8FC, sub_8091294, gUnknown_0850D908, 1, y)
field_object_path( 4, gUnknown_0850D90C, sub_8091320, gUnknown_0850D918, 2, y)
field_object_path( 5, gUnknown_0850D91C, sub_80913AC, gUnknown_0850D928, 2, x)
field_object_path( 6, gUnknown_0850D92C, sub_8091438, gUnknown_0850D938, 1, x)
field_object_path( 7, gUnknown_0850D93C, sub_80914C4, gUnknown_0850D710, 1, y)
field_object_path( 8, gUnknown_0850D948, sub_8091550, gUnknown_0850D954, 2, y)
field_object_path( 9, gUnknown_0850D958, sub_80915DC, gUnknown_0850D964, 2, y)
field_object_path(10, gUnknown_0850D968, sub_8091668, gUnknown_0850D974, 1, y)
field_object_path(11, gUnknown_0850D978, sub_80916F4, gUnknown_0850D984, 1, x)
field_object_path(12, gUnknown_0850D988, sub_8091780, gUnknown_0850D994, 2, x)
field_object_path(13, gUnknown_0850D998, sub_809180C, gUnknown_0850D9A4, 2, y)
field_object_path(14, gUnknown_0850D9A8, sub_8091898, gUnknown_0850D9B4, 1, y)
field_object_path(15, gUnknown_0850D9B8, sub_8091924, gUnknown_0850D9C4, 1, x)
field_object_path(16, gUnknown_0850D9C8, sub_80919B0, gUnknown_0850D9D4, 2, x)
field_object_path(17, gUnknown_0850D9D8, sub_8091A3C, gUnknown_0850D9E4, 2, y)
field_object_path(18, gUnknown_0850D9E8, sub_8091AC8, gUnknown_0850D9F4, 2, y)
field_object_path(19, gUnknown_0850D9F8, sub_8091B54, gUnknown_0850DA04, 2, x)
field_object_path(20, gUnknown_0850DA08, sub_8091BE0, gUnknown_0850DA14, 2, x)
field_object_path(21, gUnknown_0850DA18, sub_8091C6C, gUnknown_0850DA24, 2, y)
field_object_path(22, gUnknown_0850DA28, sub_8091CF8, gUnknown_0850DA34, 2, y)
field_object_path(23, gUnknown_0850DA38, sub_8091D84, gUnknown_0850DA44, 2, x)
field_object_path(24, gUnknown_0850DA48, sub_8091E10, gUnknown_0850DA54, 2, x)

field_object_step(CopyPlayer1, gUnknown_0850DA58)

bool8 mss_npc_reset_oampriv3_1_unk2_unk3(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    if (mapObject->mapobj_unk_21 == 0)
    {
        mapObject->mapobj_unk_21 = player_get_direction_lower_nybble();
    }
    sprite->data1 = 1;
    return TRUE;
}

bool8 sub_8091EC0(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (gMapObjects[gPlayerAvatar.mapObjectId].mapobj_unk_1C == 0xFF || gPlayerAvatar.running1 == 2)
    {
        return FALSE;
    }
    return gUnknown_0850DA64[player_get_x22()](mapObject, sprite, player_get_direction_upper_nybble(), NULL);
}

bool8 sub_8091F20(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        mapObject->mapobj_bit_1 = FALSE;
        sprite->data1 = 1;
    }
    return FALSE;
}

bool8 sub_8091F48(struct MapObject *mapObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    return FALSE;
}

bool8 sub_8091F4C(struct MapObject *mapObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(state_to_direction(gUnknown_085055CD[mapObject->animPattern], mapObject->mapobj_unk_21, playerDirection)));
    mapObject->mapobj_bit_1 = TRUE;
    sprite->data1 = 2;
    return TRUE;
}

bool8 sub_8091F94(struct MapObject *mapObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    if (FieldObjectIsFarawayIslandMew(mapObject))
    {
        direction = sub_81D427C();
        if (direction == 0)
        {
            direction = playerDirection;
            direction = state_to_direction(gUnknown_085055CD[mapObject->animPattern], mapObject->mapobj_unk_21, direction);
            FieldObjectMoveDestCoords(mapObject, direction, &x, &y);
            FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(direction));
            mapObject->mapobj_bit_1 = TRUE;
            sprite->data1 = 2;
            return TRUE;
        }
    }
    else
    {
        direction = state_to_direction(gUnknown_085055CD[mapObject->animPattern], mapObject->mapobj_unk_21, direction);
    }
    FieldObjectMoveDestCoords(mapObject, direction, &x, &y);
    FieldObjectSetRegularAnim(mapObject, sprite, GetGoSpeed0AnimId(direction));
    if (npc_block_way(mapObject, x, y, direction) || (tileCB != NULL && !tileCB(MapGridGetMetatileBehaviorAt(x, y))))
    {
        FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(direction));
    }
    mapObject->mapobj_bit_1 = TRUE;
    sprite->data1 = 2;
    return TRUE;
}

bool8 sub_80920A4(struct MapObject *mapObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gUnknown_085055CD[mapObject->animPattern], mapObject->mapobj_unk_21, direction);
    FieldObjectMoveDestCoords(mapObject, direction, &x, &y);
    FieldObjectSetRegularAnim(mapObject, sprite, GetGoSpeed1AnimId(direction));
    if (npc_block_way(mapObject, x, y, direction) || (tileCB != NULL && !tileCB(MapGridGetMetatileBehaviorAt(x, y))))
    {
        FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(direction));
    }
    mapObject->mapobj_bit_1 = TRUE;
    sprite->data1 = 2;
    return TRUE;
}

bool8 sub_809215C(struct MapObject *mapObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gUnknown_085055CD[mapObject->animPattern], mapObject->mapobj_unk_21, direction);
    FieldObjectMoveDestCoords(mapObject, direction, &x, &y);
    FieldObjectSetRegularAnim(mapObject, sprite, GetGoSpeed3AnimId(direction));
    if (npc_block_way(mapObject, x, y, direction) || (tileCB != NULL && !tileCB(MapGridGetMetatileBehaviorAt(x, y))))
    {
        FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(direction));
    }
    mapObject->mapobj_bit_1 = TRUE;
    sprite->data1 = 2;
    return TRUE;
}

bool8 sub_8092214(struct MapObject *mapObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gUnknown_085055CD[mapObject->animPattern], mapObject->mapobj_unk_21, direction);
    FieldObjectMoveDestCoords(mapObject, direction, &x, &y);
    FieldObjectSetRegularAnim(mapObject, sprite, sub_8093438(direction));
    if (npc_block_way(mapObject, x, y, direction) || (tileCB != NULL && !tileCB(MapGridGetMetatileBehaviorAt(x, y))))
    {
        FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(direction));
    }
    mapObject->mapobj_bit_1 = TRUE;
    sprite->data1 = 2;
    return TRUE;
}

bool8 cph_IM_DIFFERENT(struct MapObject *mapObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    u32 direction;

    direction = playerDirection;
    direction = state_to_direction(gUnknown_085055CD[mapObject->animPattern], mapObject->mapobj_unk_21, direction);
    FieldObjectSetRegularAnim(mapObject, sprite, sub_80934BC(direction));
    mapObject->mapobj_bit_1 = TRUE;
    sprite->data1 = 2;
    return TRUE;
}

bool8 sub_8092314(struct MapObject *mapObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gUnknown_085055CD[mapObject->animPattern], mapObject->mapobj_unk_21, direction);
    FieldObjectMoveDestCoords(mapObject, direction, &x, &y);
    FieldObjectSetRegularAnim(mapObject, sprite, sub_8093514(direction));
    if (npc_block_way(mapObject, x, y, direction) || (tileCB != NULL && !tileCB(MapGridGetMetatileBehaviorAt(x, y))))
    {
        FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(direction));
    }
    mapObject->mapobj_bit_1 = TRUE;
    sprite->data1 = 2;
    return TRUE;
}

bool8 oac_hopping(struct MapObject *mapObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gUnknown_085055CD[mapObject->animPattern], mapObject->mapobj_unk_21, direction);
    x = mapObject->coords2.x;
    y = mapObject->coords2.y;
    sub_8092F88(direction, &x, &y, 2, 2);
    FieldObjectSetRegularAnim(mapObject, sprite, GetJumpLedgeAnimId(direction));
    if (npc_block_way(mapObject, x, y, direction) || (tileCB != NULL && !tileCB(MapGridGetMetatileBehaviorAt(x, y))))
    {
        FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(direction));
    }
    mapObject->mapobj_bit_1 = TRUE;
    sprite->data1 = 2;
    return TRUE;
}

field_object_step(CopyPlayer2, gUnknown_0850DA90)

bool8 mss_08062EA4(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (gMapObjects[gPlayerAvatar.mapObjectId].mapobj_unk_1C == 0xFF || gPlayerAvatar.running1 == 2)
    {
        return FALSE;
    }
    return gUnknown_0850DA64[player_get_x22()](mapObject, sprite, player_get_direction_upper_nybble(), sub_8088E64);
}

bool8 sub_80925AC(struct MapObject *, struct Sprite *);

void FieldObjectCB_TreeDisguise(struct Sprite *sprite)
{
    struct MapObject *mapObject;

    mapObject = &gMapObjects[sprite->data0];
    if (mapObject->mapobj_unk_21 == 0 || (mapObject->mapobj_unk_21 == 1 && !sprite->data7))
    {
        FieldObjectGetLocalIdAndMap(mapObject, (u8 *)&gFieldEffectSpawnParams[0], (u8 *)&gFieldEffectSpawnParams[1], (u8 *)&gFieldEffectSpawnParams[2]);
        mapObject->mapobj_unk_1A = FieldEffectStart(FLDEFF_TREE_DISGUISE);
        mapObject->mapobj_unk_21 = 1;
        sprite->data7 ++;
    }
    FieldObjectStep(&gMapObjects[sprite->data0], sprite, sub_80925AC);
}

bool8 sub_80925AC(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    return FALSE;
}

void FieldObjectCB_MountainDisguise(struct Sprite *sprite)
{
    struct MapObject *mapObject;

    mapObject = &gMapObjects[sprite->data0];
    if (mapObject->mapobj_unk_21 == 0 || (mapObject->mapobj_unk_21 == 1 && !sprite->data7))
    {
        FieldObjectGetLocalIdAndMap(mapObject, (u8 *)&gFieldEffectSpawnParams[0], (u8 *)&gFieldEffectSpawnParams[1], (u8 *)&gFieldEffectSpawnParams[2]);
        mapObject->mapobj_unk_1A = FieldEffectStart(FLDEFF_MOUNTAIN_DISGUISE);
        mapObject->mapobj_unk_21 = 1;
        sprite->data7 ++;
    }
    FieldObjectStep(&gMapObjects[sprite->data0], sprite, sub_80925AC);
}

extern bool8 (*const gUnknown_0850DA9C[])(struct MapObject *, struct Sprite *);
bool8 sub_809268C(struct MapObject *, struct Sprite *);

void FieldObjectCB_Hidden1(struct Sprite *sprite)
{
    if (!sprite->data7)
    {
        gMapObjects[sprite->data0].mapobj_bit_26 = TRUE;
        sprite->subspriteMode = 2;
        sprite->oam.priority = 3;
        sprite->data7 ++;
    }
    FieldObjectStep(&gMapObjects[sprite->data0], sprite, sub_809268C);
}

bool8 sub_809268C(struct MapObject *mapObject, struct Sprite *sprite)
{
    return gUnknown_0850DA9C[sprite->data1](mapObject, sprite);
}

bool8 sub_80926AC (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    return FALSE;
}
bool8 sub_80926B8 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        sprite->data1 = 0;
    }
    return FALSE;
}

field_object_step(WalkInPlace1, gUnknown_0850DAA0)

bool8 sub_8092718(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    FieldObjectSetRegularAnim(mapObject, sprite, GetStepInPlaceDelay16AnimId(mapObject->mapobj_unk_18));
    sprite->data1 = 1;
    return TRUE;
}

field_object_step(WalkInPlace4, gUnknown_0850DAA8)

bool8 sub_8092788(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    FieldObjectSetRegularAnim(mapObject, sprite, GetStepInPlaceDelay32AnimId(mapObject->mapobj_unk_18));
    sprite->data1 = 1;
    return TRUE;
}

field_object_step(WalkInPlace2, gUnknown_0850DAB0)

bool8 sub_80927F8(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    FieldObjectSetRegularAnim(mapObject, sprite, GetStepInPlaceDelay8AnimId(mapObject->mapobj_unk_18));
    sprite->data1 = 1;
    return TRUE;
}

field_object_step(WalkInPlace3, gUnknown_0850DAB8)

bool8 sub_8092868(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    FieldObjectSetRegularAnim(mapObject, sprite, GetStepInPlaceDelay4AnimId(mapObject->mapobj_unk_18));
    sprite->data1 = 1;
    return TRUE;
}

field_object_step(Hidden2, gUnknown_0850DAC0)

bool8 sub_80928D8(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->mapobj_unk_18));
    mapObject->mapobj_bit_13 = TRUE;
    sprite->data1 = 1;
    return TRUE;
}
bool8 sub_809290C(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        sprite->data1 = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_809292C(struct MapObject *mapObject, struct Sprite *sprite)
{
    mapObject->mapobj_bit_1 = FALSE;
    return FALSE;
}

void npc_reset(struct MapObject *mapObject, struct Sprite *sprite)
{
    mapObject->mapobj_bit_1 = FALSE;
    mapObject->mapobj_bit_6 = FALSE;
    mapObject->mapobj_bit_7 = FALSE;
    mapObject->mapobj_unk_1C = 0xFF;
    sprite->data1 = 0;
}

#define dirn2anim(name, table)\
extern const u8 table[4];\
u8 name(u8 direction)\
{\
    return table[direction];\
}

dirn2anim(FieldObjectDirectionToImageAnimId, gUnknown_0850DACC)
dirn2anim(get_go_image_anim_num, gUnknown_0850DAD5)
dirn2anim(get_go_fast_image_anim_num, gUnknown_0850DADE)
dirn2anim(get_go_faster_image_anim_num, gUnknown_0850DAE7)
dirn2anim(get_go_fastest_image_anim_num, gUnknown_0850DAF0)
dirn2anim(sub_80929AC, gUnknown_0850DAF9)
dirn2anim(sub_80929BC, gUnknown_0850DB02)
dirn2anim(sub_80929CC, gUnknown_0850DB0B)
dirn2anim(sub_80929DC, gUnknown_0850DB14)
dirn2anim(sub_80929EC, gUnknown_0850DB1D)
dirn2anim(sub_80929FC, gUnknown_0850DB26)
dirn2anim(sub_8092A0C, gUnknown_0850DB2F)
dirn2anim(sub_8092A1C, gUnknown_0850DB38)
dirn2anim(sub_8092A2C, gUnknown_0850DB41)
dirn2anim(get_run_image_anim_num, gUnknown_0850DB4A)

// file boundary?

struct UnkStruct_085094AC {
    const union AnimCmd *const *anims;
    u8 animPos[4];
};

extern const struct UnkStruct_085094AC gUnknown_085094AC[];

static const struct UnkStruct_085094AC *sub_8092A4C(const union AnimCmd *const *anims)
{
    const struct UnkStruct_085094AC *retval;

    for (retval = gUnknown_085094AC; retval->anims != NULL; retval ++)
    {
        if (retval->anims == anims)
        {
            return retval;
        }
    }
    return NULL;
}

void npc_apply_anim_looping(struct MapObject *mapObject, struct Sprite *sprite, u8 animNum)
{
    const struct UnkStruct_085094AC *unk85094AC;

    if (!mapObject->mapobj_bit_12)
    {
        sprite->animNum = animNum;
        unk85094AC = sub_8092A4C(sprite->anims);
        if (unk85094AC != NULL)
        {
            if (sprite->animCmdIndex == unk85094AC->animPos[0])
            {
                sprite->animCmdIndex = unk85094AC->animPos[3];
            }
            else if (sprite->animCmdIndex == unk85094AC->animPos[1])
            {
                sprite->animCmdIndex = unk85094AC->animPos[2];
            }
        }
        SeekSpriteAnim(sprite, sprite->animCmdIndex);
    }
}

void obj_npc_animation_step(struct MapObject *mapObject, struct Sprite *sprite, u8 animNum)
{
    const struct UnkStruct_085094AC *unk85094AC;

    if (!mapObject->mapobj_bit_12)
    {
        u8 animPos;

        sprite->animNum = animNum;
        unk85094AC = sub_8092A4C(sprite->anims);
        if (unk85094AC != NULL)
        {
            animPos = unk85094AC->animPos[1];
            if (sprite->animCmdIndex <= unk85094AC->animPos[0])
            {
                animPos = unk85094AC->animPos[0];
            }
            SeekSpriteAnim(sprite, animPos);
        }
    }
}

// file boundary?

u8 sub_8092AF8(s16 x1, s16 y1, s16 x2, s16 y2)
{
    if (x1 > x2)
    {
        return DIR_WEST;
    }
    if (x1 < x2)
    {
        return DIR_EAST;
    }
    if (y1 > y2)
    {
        return DIR_NORTH;
    }
    return DIR_SOUTH;
}

void npc_set_running_behaviour_etc(struct MapObject *mapObject, u8 animPattern)
{
    mapObject->animPattern = animPattern;
    mapObject->mapobj_unk_21 = 0;
    mapObject->animId = 0;
    gSprites[mapObject->spriteId].callback = gUnknown_08505438[animPattern];
    gSprites[mapObject->spriteId].data1 = 0;
}

dirn2anim(npc_running_behaviour_by_direction, gUnknown_0850DB53)

u8 npc_block_way__next_tile(struct MapObject *mapObject, u8 direction)
{
    s16 x;
    s16 y;

    x = mapObject->coords2.x;
    y = mapObject->coords2.y;
    MoveCoords(direction, &x, &y);
    return npc_block_way(mapObject, x, y, direction);
}

u8 npc_block_way(struct MapObject *mapObject, s16 x, s16 y, u32 dirn)
{
    u8 direction;

    direction = dirn;
    if (IsCoordOutsideFieldObjectMovementRect((struct MapObject2 *)mapObject, x, y))
    {
        return 1;
    }
    if (MapGridIsImpassableAt(x, y) || GetMapBorderIdAt(x, y) == -1 || IsMetatileDirectionallyImpassable(mapObject, x, y, direction))
    {
        return 2;
    }
    if (mapObject->mapobj_bit_15 && !CanCameraMoveInDirection(direction))
    {
        return 2;
    }
    if (IsZCoordMismatchAt(mapObject->mapobj_unk_0B_0, x, y))
    {
        return 3;
    }
    if (CheckForCollisionBetweenFieldObjects(mapObject, x, y))
    {
        return 4;
    }
    return 0;
}

u8 sub_8092C8C(struct MapObject *mapObject, s16 x, s16 y, u8 direction)
{
    u8 retval;

    retval = 0x00;
    if (IsCoordOutsideFieldObjectMovementRect((struct MapObject2 *)mapObject, x, y))
    {
        retval |= 1;
    }
    if (MapGridIsImpassableAt(x, y) || GetMapBorderIdAt(x, y) == -1 || IsMetatileDirectionallyImpassable(mapObject, x, y, direction) || (mapObject->mapobj_bit_15 && !CanCameraMoveInDirection(direction)))
    {
        retval |= 2;
    }
    if (IsZCoordMismatchAt(mapObject->mapobj_unk_0B_0, x, y))
    {
        retval |= 4;
    }
    if (CheckForCollisionBetweenFieldObjects(mapObject, x, y))
    {
        retval |= 8;
    }
    return retval;
}

bool8 IsCoordOutsideFieldObjectMovementRect(struct MapObject2 *mapObject, s16 x, s16 y)
{
    s16 left;
    s16 right;
    s16 top;
    s16 bottom;

    if (mapObject->mapobj_unk_19 != 0)
    {
        left = mapObject->coords1.x - mapObject->mapobj_unk_19;
        right = mapObject->coords1.x + mapObject->mapobj_unk_19;
        if (left > x || right < x)
        {
            return TRUE;
        }
    }
    if (mapObject->mapobj_unk_19b != 0)
    {
        top = mapObject->coords1.y - mapObject->mapobj_unk_19b;
        bottom = mapObject->coords1.y + mapObject->mapobj_unk_19b;
        if (top > y || bottom < y)
        {
            return TRUE;
        }
    }
    return FALSE;
}

bool8 IsMetatileDirectionallyImpassable(struct MapObject *mapObject, s16 x, s16 y, u8 direction)
{
    if (gUnknown_0850DB5C[direction - 1](mapObject->mapobj_unk_1E) || gUnknown_0850DB6C[direction - 1](MapGridGetMetatileBehaviorAt(x, y)))
    {
        return TRUE;
    }
    return FALSE;
}

bool8 CheckForCollisionBetweenFieldObjects(struct MapObject *mapObject, s16 x, s16 y)
{
    u8 i;
    struct MapObject *curObject;

    for (i = 0; i < NUM_FIELD_OBJECTS; i ++)
    {
        curObject = &gMapObjects[i];
        if (curObject->active && curObject != mapObject)
        {
            if ((curObject->coords2.x == x && curObject->coords2.y == y) || (curObject->coords3.x == x && curObject->coords3.y == y))
            {
                if (AreZCoordsCompatible(mapObject->mapobj_unk_0B_0, curObject->mapobj_unk_0B_0))
                {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

bool8 sub_8092E9C(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 mapObjectId;

    if (!TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &mapObjectId) && gSprites[gMapObjects[mapObjectId].spriteId].data7 & 0x02)
    {
        return TRUE;
    }
    return FALSE;
}

void sub_8092EF0(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 mapObjectId;

    if (!TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &mapObjectId))
    {
        gSprites[gMapObjects[mapObjectId].spriteId].data7 |= 0x04;
    }
}

void MoveCoords(u8 direction, s16 *x, s16 *y)
{
    *x += gUnknown_0850DB7C[direction].x;
    *y += gUnknown_0850DB7C[direction].y;
}

void sub_8092F60(u8 direction, s16 *x, s16 *y)
{
    *x += gUnknown_0850DB7C[direction].x << 4;
    *y += gUnknown_0850DB7C[direction].y << 4;
}

void sub_8092F88(u32 dirn, s16 *x, s16 *y, s16 dx, s16 dy)
{
    u8 direction;
    s16 dx_2;
    s16 dy_2;
    s16 cur_x;
    s16 cur_y;

    direction = dirn;
    dx_2 = dx;
    dy_2 = dy;
    cur_x = gUnknown_0850DB7C[direction].x;
    if (cur_x > 0)
    {
        *x += dx_2;
    }
    if (cur_x < 0)
    {
        *x -= dx_2;
    }
    cur_y = gUnknown_0850DB7C[direction].y;
    if (cur_y > 0)
    {
        *y += dy_2;
    }
    if (cur_y < 0)
    {
        *y -= dy_2;
    }
}

void sub_8092FF0(s16 x, s16 y, s16 *dest_x, s16 *dest_y)
{
    *dest_x = (x - gSaveBlock1Ptr->pos.x) << 4;
    *dest_y = (y - gSaveBlock1Ptr->pos.y) << 4;
    *dest_x -= gUnknown_03005DEC;
    *dest_y -= gUnknown_03005DE8;
}

void sub_8093038(s16 x, s16 y, s16 *dest_x, s16 *dest_y)
{
    s16 dx;
    s16 dy;

    dx = -gUnknown_03005DEC - gUnknown_03005DD0.x;
    dy = -gUnknown_03005DE8 - gUnknown_03005DD0.y;
    if (gUnknown_03005DD0.x > 0)
    {
        dx += 0x10;
    }
    if (gUnknown_03005DD0.x < 0)
    {
        dx -= 0x10;
    }
    if (gUnknown_03005DD0.y > 0)
    {
        dy += 0x10;
    }
    if (gUnknown_03005DD0.y < 0)
    {
        dy -= 0x10;
    }
    *dest_x = ((x - gSaveBlock1Ptr->pos.x) << 4) + dx;
    *dest_y = ((y - gSaveBlock1Ptr->pos.y) << 4) + dy;
}

void sub_80930E0(s16 *x, s16 *y, s16 dx, s16 dy)
{
    sub_8093038(*x, *y, x, y);
    *x += dx;
    *y += dy;
}

void GetFieldObjectMovingCameraOffset(s16 *x, s16 *y)
{
    *x = 0;
    *y = 0;
    if (gUnknown_03005DD0.x > 0)
    {
        (*x) ++;
    }
    if (gUnknown_03005DD0.x < 0)
    {
        (*x) --;
    }
    if (gUnknown_03005DD0.y > 0)
    {
        (*y) ++;
    }
    if (gUnknown_03005DD0.y < 0)
    {
        (*y) --;
    }
}

void FieldObjectMoveDestCoords(struct MapObject *mapObject, u32 dirn, s16 *x, s16 *y)
{
    u8 direction;

    direction = dirn;
    *x = mapObject->coords2.x;
    *y = mapObject->coords2.y;
    MoveCoords(direction, x, y);
}

asm(".section .text.get_face_direction_anim_id");

void FieldObjectClearAnimIfSpecialAnimActive(struct MapObject *);

u8 FieldObjectCheckIfSpecialAnimFinishedOrInactive(struct MapObject *mapObject)
{
    if (mapObject->mapobj_bit_6)
    {
        return mapObject->mapobj_bit_7;
    }
    return 0x10;
}

u8 FieldObjectClearAnimIfSpecialAnimFinished(struct MapObject *mapObject)
{
    u8 specialAnimState;

    specialAnimState = FieldObjectCheckIfSpecialAnimFinishedOrInactive(mapObject);
    if (specialAnimState != 0 && specialAnimState != 16)
    {
        FieldObjectClearAnimIfSpecialAnimActive(mapObject);
    }
    return specialAnimState;
}

u8 FieldObjectGetSpecialAnim(struct MapObject *mapObject)
{
    if (mapObject->mapobj_bit_6)
    {
        return mapObject->mapobj_unk_1C;
    }
    return 0xFF;
}

void FieldObjectStep(struct MapObject *mapObject, struct Sprite *sprite, bool8 (*callback)(struct MapObject *, struct Sprite *))
{
    DoGroundEffects_OnSpawn(mapObject, sprite);
    sub_80964E8(mapObject, sprite);
    if (FieldObjectIsSpecialAnimActive(mapObject))
    {
        FieldObjectExecSpecialAnim(mapObject, sprite);
    }
    else if (!mapObject->mapobj_bit_8)
    {
        while (callback(mapObject, sprite));
    }
    DoGroundEffects_OnBeginStep(mapObject, sprite);
    DoGroundEffects_OnFinishStep(mapObject, sprite);
    npc_obj_transfer_image_anim_pause_flag(mapObject, sprite);
    sub_8096518(mapObject, sprite);
    FieldObjectUpdateSubpriority(mapObject, sprite);
}

#define dirn2anim_2(name, table) \
extern const u8 table[5];      \
u8 name(u32 direction)         \
{                              \
    u8 dirn2;                  \
    u8 animIds[5];             \
    dirn2 = direction;         \
    memcpy(animIds, table, 5); \
    if (dirn2 > DIR_EAST)      \
    {                          \
        dirn2 = 0;             \
    }                          \
    return animIds[dirn2];     \
}

dirn2anim_2(GetFaceDirectionAnimId, gUnknown_0850DBA0);
