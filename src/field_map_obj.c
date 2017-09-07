// Includes

#include "global.h"
#include "sprite.h"
#include "rom4.h"
#include "field_player_avatar.h"
#include "event_data.h"
#include "rom_818CFC8.h"
#include "rom_81BE66C.h"
#include "field_ground_effect.h"
#include "field_map_obj.h"

#define NUM_FIELD_MAP_OBJECT_TEMPLATES 0x51

// Static struct declarations

// Static RAM declarations

// Static ROM declarations

void sub_808D450(void);
static u8 GetFieldObjectIdByLocalId(u8);
static u8 GetFieldObjectIdByLocalIdAndMapInternal(u8, u8, u8);
static bool8 GetAvailableFieldObjectSlot(u16, u8, u8, u8 *);
/*static*/ void FieldObjectHandleDynamicGraphicsId(struct MapObject *);
static void RemoveFieldObjectInternal (struct MapObject *);
/*static*/ u16 GetFieldObjectFlagIdByFieldObjectId(u8);
/*static*/ const struct MapObjectGraphicsInfo *GetFieldObjectGraphicsInfo(u8);
void sub_8096518(struct MapObject *, struct Sprite *);
/*static*/ void MakeObjectTemplateFromFieldObjectTemplate(struct MapObjectTemplate *, struct SpriteTemplate *, const struct SubspriteTable **);
/*static*/ void GetFieldObjectMovingCameraOffset(s16 *, s16 *);
/*static*/ struct MapObjectTemplate *GetFieldObjectTemplateByLocalIdAndMap(u8, u8, u8);

// ROM data

void (*const gUnknown_08505438[NUM_FIELD_MAP_OBJECT_TEMPLATES])(struct Sprite *);
const u8 gUnknown_0850557C[NUM_FIELD_MAP_OBJECT_TEMPLATES];
const u8 gUnknown_085055CD[NUM_FIELD_MAP_OBJECT_TEMPLATES];

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

    for (i = 0; i < ARRAY_COUNT(gMapObjects); i ++)
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

/*static*/ void sub_808D450(void)
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

    for (i = 0; i < ARRAY_COUNT(gMapObjects); i ++)
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
    if (*fieldObjectId == ARRAY_COUNT(gMapObjects))
    {
        return TRUE;
    }
    return FALSE;
}

u8 GetFieldObjectIdByXY(s16 x, s16 y)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(gMapObjects); i ++)
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

    for (i = 0; i < ARRAY_COUNT(gMapObjects); i ++)
    {
        if (gMapObjects[i].active && gMapObjects[i].localId == localId && gMapObjects[i].mapNum == mapId && gMapObjects[i].mapGroup == mapGroupId)
        {
            return i;
        }
    }
    return ARRAY_COUNT(gMapObjects);
}

static u8 GetFieldObjectIdByLocalId(u8 localId)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(gMapObjects); i ++)
    {
        if (gMapObjects[i].active && gMapObjects[i].localId == localId)
        {
            return i;
        }
    }
    return ARRAY_COUNT(gMapObjects);
}

// This function has the same nonmatching quirk as in Ruby/Sapphire.
#ifdef NONMATCHING
/*static*/ u8 InitFieldObjectStateFromTemplate(struct MapObjectTemplate *template, u8 mapId, u8 mapGroupId)
{
    u8 slot;
    struct MapObject *mapObject;
    u16 x;
    u16 y;

    if (GetAvailableFieldObjectSlot(template->localId, mapId, mapGroupId, &slot))
    {
        return ARRAY_COUNT(gMapObjects);
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
/*static*/ __attribute__((naked)) u8 InitFieldObjectStateFromTemplate(struct MapObjectTemplate *template, u8 mapId, u8 mapGroupId)
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
    return ARRAY_COUNT(gMapObjects);
}

static bool8 GetAvailableFieldObjectSlot(u16 localId, u8 mapNum, u8 mapGroup, u8 *result)
// Looks for an empty slot.
// Returns FALSE and the location of the available slot
// in *result.
// If no slots are available, or if the object is already
// loaded, returns TRUE.
{
    u8 i = 0;

    for (i = 0; i < ARRAY_COUNT(gMapObjects); i ++)
    {
        if (!gMapObjects[i].active)
            break;
        if (gMapObjects[i].localId == localId && gMapObjects[i].mapNum == mapNum && gMapObjects[i].mapGroup == mapGroup)
            return TRUE;
    }
    if (i >= ARRAY_COUNT(gMapObjects))
        return TRUE;
    *result = i;
    do
    {
        if (gMapObjects[i].active && gMapObjects[i].localId == localId && gMapObjects[i].mapNum == mapNum && gMapObjects[i].mapGroup == mapGroup)
            return TRUE;
        i ++;
    } while (i < ARRAY_COUNT(gMapObjects));
    return FALSE;
}

void RemoveFieldObject(struct MapObject *mapObject)
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

    for (i = 0; i < ARRAY_COUNT(gMapObjects); i ++)
    {
        if (i != gPlayerAvatar.mapObjectId)
        {
            RemoveFieldObject(&gMapObjects[i]);
        }
    }
}

u8 SpawnFieldObjectInternal(struct MapObjectTemplate *mapObjectTemplate, struct SpriteTemplate *spriteTemplate, u8 mapNum, u8 mapGroup, s16 cameraX, s16 cameraY)
{
    struct MapObject *mapObject;
    const struct MapObjectGraphicsInfo *graphicsInfo;
    struct Sprite *sprite;
    u8 mapObjectId;
    u8 paletteSlot;
    u8 spriteId;

    mapObjectId = InitFieldObjectStateFromTemplate(mapObjectTemplate, mapNum, mapGroup);
    if (mapObjectId == ARRAY_COUNT(gMapObjects))
    {
        return ARRAY_COUNT(gMapObjects);
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
        return ARRAY_COUNT(gMapObjects);
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

u8 SpawnFieldObject(struct MapObjectTemplate *mapObjectTemplate, u8 mapNum, u8 mapGroup, s16 cameraX, s16 cameraY)
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
    if (mapObjectId == ARRAY_COUNT(gMapObjects))
    {
        return ARRAY_COUNT(gMapObjects);
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
        return ARRAY_COUNT(gMapObjects);
    }
    GetFieldObjectMovingCameraOffset(&cameraX, &cameraY);
    return SpawnFieldObject(mapObjectTemplate, mapNum, mapGroup, cameraX, cameraY);
}

void MakeObjectTemplateFromFieldObjectGraphicsInfo(u16 graphicsId, void (*callback)(struct Sprite *), struct SpriteTemplate *sprTemplate, const struct SubspriteTable **subspriteTables)
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

void MakeObjectTemplateFromFieldObjectGraphicsInfoWithCallbackIndex(u16 graphicsId, u16 callbackIndex, struct SpriteTemplate *sprTemplate, const struct SubspriteTable **subspriteTables)
{
    MakeObjectTemplateFromFieldObjectGraphicsInfo(graphicsId, gUnknown_08505438[callbackIndex], sprTemplate, subspriteTables);
}
