#include "global.h"
#include "sprite.h"
#include "fieldmap.h"
#include "metatile_behavior.h"
#include "sound.h"
#include "event_object_movement.h"
#include "field_camera.h"
#include "field_weather.h"
#include "field_effect.h"
#include "field_effect_helpers.h"
#include "constants/songs.h"

void objc_reflection_maybe(struct Sprite *);
void npc_pal_op(struct EventObject *eventObject, struct Sprite *sprite);
void npc_pal_op_A(struct EventObject *, u8);
void npc_pal_op_B(struct EventObject *, u8);
void sub_81561FC(struct Sprite *, u8, u8);

/*
static void FadeFootprintsTireTracks_Step0(struct Sprite *);
static void FadeFootprintsTireTracks_Step1(struct Sprite *);
static void UpdateAshFieldEffect_Step0(struct Sprite *);
static void UpdateAshFieldEffect_Step1(struct Sprite *);
static void UpdateAshFieldEffect_Step2(struct Sprite *);
static void UpdateFeetInFlowingWaterFieldEffect(struct Sprite *);
static void sub_8127FD4(struct EventObject *, struct Sprite *);
static void sub_812800C(struct EventObject *, struct Sprite *);
static void sub_81280A0(struct EventObject *, struct Sprite *, struct Sprite *);
static void sub_8128174(struct Sprite *);
static u32 ShowDisguiseFieldEffect(u8, u8, u8); */

void SetUpReflection(struct EventObject *eventObject, struct Sprite *sprite, bool8 stillReflection)
{
    struct Sprite *reflectionSprite;

    reflectionSprite = &gSprites[CreateCopySpriteAt(sprite, sprite->pos1.x, sprite->pos1.y, 0x98)];
    reflectionSprite->callback = objc_reflection_maybe;
    reflectionSprite->oam.priority = 3;
    reflectionSprite->oam.paletteNum = gReflectionEffectPaletteMap[reflectionSprite->oam.paletteNum];
    reflectionSprite->usingSheet = TRUE;
    reflectionSprite->anims = gDummySpriteAnimTable;
    StartSpriteAnim(reflectionSprite, 0);
    reflectionSprite->affineAnims = gDummySpriteAffineAnimTable;
    reflectionSprite->affineAnimBeginning = TRUE;
    reflectionSprite->subspriteMode = SUBSPRITES_OFF;
    reflectionSprite->data[0] = sprite->data[0];
    reflectionSprite->data[1] = eventObject->localId;
    reflectionSprite->data[7] = stillReflection;
    npc_pal_op(eventObject, reflectionSprite);

    if (!stillReflection)
        reflectionSprite->oam.affineMode = ST_OAM_AFFINE_NORMAL;
}

s16 sub_8153F98(struct EventObject *eventObject)
{
    return GetEventObjectGraphicsInfo(eventObject->graphicsId)->height - 2;
}

void npc_pal_op(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 bridgeType;
    u16 bridgeReflectionVerticalOffsets[] = { 12, 28, 44 };
    sprite->data[2] = 0;
    if (!GetEventObjectGraphicsInfo(eventObject->graphicsId)->disableReflectionPaletteLoad && ((bridgeType = MetatileBehavior_GetBridgeSth(eventObject->previousMetatileBehavior)) || (bridgeType = MetatileBehavior_GetBridgeSth(eventObject->currentMetatileBehavior))))
    {
        sprite->data[2] = bridgeReflectionVerticalOffsets[bridgeType - 1];
        npc_pal_op_A(eventObject, sprite->oam.paletteNum);
    }
    else
    {
        npc_pal_op_B(eventObject, sprite->oam.paletteNum);
    }
}

void npc_pal_op_B(struct EventObject *eventObject, u8 paletteIndex)
{
    const struct EventObjectGraphicsInfo *graphicsInfo;

    graphicsInfo = GetEventObjectGraphicsInfo(eventObject->graphicsId);
    if (graphicsInfo->paletteTag2 != 0x11ff)
    {
        if (graphicsInfo->paletteSlot == 0)
        {
            LoadPlayerObjectReflectionPalette(graphicsInfo->paletteTag1, paletteIndex);
        }
        else if (graphicsInfo->paletteSlot == 10)
        {
            LoadSpecialObjectReflectionPalette(graphicsInfo->paletteTag1, paletteIndex);
        }
        else
        {
            PatchObjectPalette(GetObjectPaletteTag(paletteIndex), paletteIndex);
        }
        UpdateSpritePaletteWithWeather(paletteIndex);
    }
}

// When walking on a bridge high above water (Route 120), the reflection is a solid dark blue color.
// This is so the sprite blends in with the dark water metatile underneath the bridge.
void npc_pal_op_A(struct EventObject *eventObject, u8 paletteNum)
{
    const struct EventObjectGraphicsInfo *graphicsInfo;

    graphicsInfo = GetEventObjectGraphicsInfo(eventObject->graphicsId);
    if (graphicsInfo->paletteTag2 != 0x11ff)
    {
        PatchObjectPalette(graphicsInfo->paletteTag2, paletteNum);
        UpdateSpritePaletteWithWeather(paletteNum);
    }
}

void objc_reflection_maybe(struct Sprite *reflectionSprite)
{
    struct EventObject *eventObject;
    struct Sprite *mainSprite;

    eventObject = &gEventObjects[reflectionSprite->data[0]];
    mainSprite = &gSprites[eventObject->spriteId];
    if (!eventObject->active || !eventObject->hasReflection || eventObject->localId != reflectionSprite->data[1])
    {
        reflectionSprite->inUse = FALSE;
    }
    else
    {
        reflectionSprite->oam.paletteNum = gReflectionEffectPaletteMap[mainSprite->oam.paletteNum];
        reflectionSprite->oam.shape = mainSprite->oam.shape;
        reflectionSprite->oam.size = mainSprite->oam.size;
        reflectionSprite->oam.matrixNum = mainSprite->oam.matrixNum | 0x10;
        reflectionSprite->oam.tileNum = mainSprite->oam.tileNum;
        reflectionSprite->subspriteTables = mainSprite->subspriteTables;
        reflectionSprite->subspriteTableNum = mainSprite->subspriteTableNum;
        reflectionSprite->invisible = mainSprite->invisible;
        reflectionSprite->pos1.x = mainSprite->pos1.x;
        // reflectionSprite->data[2] holds an additional vertical offset, used by the high bridges on Route 120
        reflectionSprite->pos1.y = mainSprite->pos1.y + sub_8153F98(eventObject) + reflectionSprite->data[2];
        reflectionSprite->centerToCornerVecX = mainSprite->centerToCornerVecX;
        reflectionSprite->centerToCornerVecY = mainSprite->centerToCornerVecY;
        reflectionSprite->pos2.x = mainSprite->pos2.x;
        reflectionSprite->pos2.y = -mainSprite->pos2.y;
        reflectionSprite->coordOffsetEnabled = mainSprite->coordOffsetEnabled;
        
        if (eventObject->unk3_3 == TRUE)
            reflectionSprite->invisible = TRUE;

        // Check if the reflection is not still.
        if (reflectionSprite->data[7] == FALSE)
        {
            // Sets the reflection sprite's rot/scale matrix to the appropriate
            // matrix based on whether or not the main sprite is horizontally flipped.
            // If the sprite is facing to the east, then it is flipped, and its matrixNum is 8.
            reflectionSprite->oam.matrixNum = 0;
            if (mainSprite->oam.matrixNum & 0x8)
                reflectionSprite->oam.matrixNum = 1;
        }
    }
}

extern const struct SpriteTemplate *const gFieldEffectObjectTemplatePointers[];

u8 sub_8154228(void)
{
    u8 spriteId;
    struct Sprite *sprite;

    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[8], 0, 0, 0x52);
    if (spriteId != MAX_SPRITES)
    {
        sprite = &gSprites[spriteId];
        sprite->oam.priority = 1;
        sprite->coordOffsetEnabled = TRUE;
        sprite->invisible = TRUE;
    }
    return spriteId;
}

void objid_set_invisible(u8 spriteId)
{
    gSprites[spriteId].invisible = TRUE;
}

void sub_8154298(u8 spriteId, u8 direction, s16 x, s16 y)
{
    s16 x2;
    s16 y2;
    struct Sprite *sprite;

    sprite = &gSprites[spriteId];
    if (sprite->invisible || sprite->data[0] != x || sprite->data[1] != y)
    {
        sub_8093038(x, y, &x2, &y2);
        sprite = &gSprites[spriteId];
        sprite->pos1.x = x2 + 8;
        sprite->pos1.y = y2 + 8;
        sprite->invisible = FALSE;
        sprite->data[0] = x;
        sprite->data[1] = y;
        StartSpriteAnim(sprite, direction - 1);
    }
}

const u8 gShadowEffectTemplateIds[] = {
    0,
    1,
    2,
    3
};

const u16 gShadowVerticalOffsets[] = {
    4,
    4,
    4,
    16
};

u32 oei_shadow(void)
{
    u8 eventObjectId;
    const struct EventObjectGraphicsInfo *graphicsInfo;
    u8 spriteId;

    eventObjectId = GetEventObjectIdByLocalIdAndMap(gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    graphicsInfo = GetEventObjectGraphicsInfo(gEventObjects[eventObjectId].graphicsId);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[gShadowEffectTemplateIds[graphicsInfo->shadowSize]], 0, 0, 0x94);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].coordOffsetEnabled = TRUE;
        gSprites[spriteId].data[0] = gFieldEffectArguments[0];
        gSprites[spriteId].data[1] = gFieldEffectArguments[1];
        gSprites[spriteId].data[2] = gFieldEffectArguments[2];
        gSprites[spriteId].data[3] = (graphicsInfo->height >> 1) - gShadowVerticalOffsets[graphicsInfo->shadowSize];
    }
    return 0;
}

void oamc_shadow(struct Sprite *sprite)
{
    u8 eventObjectId;
    struct EventObject *eventObject;
    struct Sprite *linkedSprite;

    if (TryGetEventObjectIdByLocalIdAndMap(sprite->data[0], sprite->data[1], sprite->data[2], &eventObjectId))
    {
        FieldEffectStop(sprite, FLDEFF_SHADOW);
    }
    else
    {
        eventObject = &gEventObjects[eventObjectId];
        linkedSprite = &gSprites[eventObject->spriteId];
        sprite->oam.priority = linkedSprite->oam.priority;
        sprite->pos1.x = linkedSprite->pos1.x;
        sprite->pos1.y = linkedSprite->pos1.y + sprite->data[3];
        if (!eventObject->active || !eventObject->hasShadow
         || MetatileBehavior_IsPokeGrass(eventObject->currentMetatileBehavior)
         || MetatileBehavior_IsSurfableWaterOrUnderwater(eventObject->currentMetatileBehavior)
         || MetatileBehavior_IsSurfableWaterOrUnderwater(eventObject->previousMetatileBehavior)
         || MetatileBehavior_IsReflective(eventObject->currentMetatileBehavior)
         || MetatileBehavior_IsReflective(eventObject->previousMetatileBehavior))
        {
            FieldEffectStop(sprite, FLDEFF_SHADOW);
        }
    }
}

u32 oei_grass_normal(void)
{
    s16 x;
    s16 y;
    u8 spriteId;
    struct Sprite *sprite;

    x = gFieldEffectArguments[0];
    y = gFieldEffectArguments[1];
    sub_80930E0(&x, &y, 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[4], x, y, 0);
    if (spriteId != MAX_SPRITES)
    {
        sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gFieldEffectArguments[3];
        sprite->data[0] = gFieldEffectArguments[2];
        sprite->data[1] = gFieldEffectArguments[0];
        sprite->data[2] = gFieldEffectArguments[1];
        sprite->data[3] = gFieldEffectArguments[4];
        sprite->data[4] = gFieldEffectArguments[5];
        sprite->data[5] = gFieldEffectArguments[6];
        if (gFieldEffectArguments[7])
        {
            SeekSpriteAnim(sprite, 4);
        }
    }
    return 0;
}

void unc_grass_normal(struct Sprite *sprite)
{
    u8 mapNum;
    u8 mapGroup;
    u8 metatileBehavior;
    u8 localId;
    u8 eventObjectId;
    struct EventObject *eventObject;

    mapNum = sprite->data[5] >> 8;
    mapGroup = sprite->data[5];
    if (gCamera.active && (gSaveBlock1Ptr->location.mapNum != mapNum || gSaveBlock1Ptr->location.mapGroup != mapGroup))
    {
        sprite->data[1] -= gCamera.x;
        sprite->data[2] -= gCamera.y;
        sprite->data[5] = ((u8)gSaveBlock1Ptr->location.mapNum << 8) | (u8)gSaveBlock1Ptr->location.mapGroup;
    }
    localId = sprite->data[3] >> 8;
    mapNum = sprite->data[3];
    mapGroup = sprite->data[4];
    metatileBehavior = MapGridGetMetatileBehaviorAt(sprite->data[1], sprite->data[2]);
    if (TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &eventObjectId) || !MetatileBehavior_IsTallGrass(metatileBehavior) || (sprite->data[7] && sprite->animEnded))
    {
        FieldEffectStop(sprite, FLDEFF_TALL_GRASS);
    }
    else
    {
        eventObject = &gEventObjects[eventObjectId];
        if ((eventObject->currentCoords.x != sprite->data[1] || eventObject->currentCoords.y != sprite->data[2]) && (eventObject->previousCoords.x != sprite->data[1] || eventObject->previousCoords.y != sprite->data[2]))
            sprite->data[7] = TRUE;

        metatileBehavior = 0;
        if (sprite->animCmdIndex == 0)
            metatileBehavior = 4;

        UpdateEventObjectSpriteVisibility(sprite, 0);
        sub_81561FC(sprite, sprite->data[0], metatileBehavior);
    }
}

u32 sub_8154658(void)
{
    u8 spriteId;
    struct Sprite *sprite;

    sub_80930E0((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 12);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[10], gFieldEffectArguments[0], gFieldEffectArguments[1], 0);
    if (spriteId != MAX_SPRITES)
    {
        sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gFieldEffectArguments[3];
        sprite->data[0] = gFieldEffectArguments[2];
        sprite->data[1] = 12;
    }
    return 0;
}

u8 sub_81546C8(u8 localId, u8 mapNum, u8 mapGroup, s16 x, s16 y)
{
    struct Sprite *sprite;
    u8 i;

    for (i = 0; i < MAX_SPRITES; i ++)
    {
        if (gSprites[i].inUse)
        {
            sprite = &gSprites[i];
            if (sprite->callback == unc_grass_normal && (x == sprite->data[1] && y == sprite->data[2]) && (localId == (u8)(sprite->data[3] >> 8) && mapNum == (sprite->data[3] & 0xFF) && mapGroup == sprite->data[4]))
                return i;
        }
    }

    return MAX_SPRITES;
}

u32 sub_8154758(void)
{
    s16 x;
    s16 y;
    u8 spriteId;
    struct Sprite *sprite;

    x = gFieldEffectArguments[0];
    y = gFieldEffectArguments[1];
    sub_80930E0(&x, &y, 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[15], x, y, 0);
    if (spriteId != MAX_SPRITES)
    {
        sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = ZCoordToPriority(gFieldEffectArguments[2]);
        sprite->data[0] = gFieldEffectArguments[2];
        sprite->data[1] = gFieldEffectArguments[0];
        sprite->data[2] = gFieldEffectArguments[1];
        sprite->data[3] = gFieldEffectArguments[4];
        sprite->data[4] = gFieldEffectArguments[5];
        sprite->data[5] = gFieldEffectArguments[6];
        if (gFieldEffectArguments[7])
        {
            SeekSpriteAnim(sprite, 6);
        }
    }
    return 0;
}

void unc_grass_tall(struct Sprite *sprite)
{
    u8 mapNum;
    u8 mapGroup;
    u8 metatileBehavior;
    u8 localId;
    u8 eventObjectId;
    struct EventObject *eventObject;

    mapNum = sprite->data[5] >> 8;
    mapGroup = sprite->data[5];
    if (gCamera.active && (gSaveBlock1Ptr->location.mapNum != mapNum || gSaveBlock1Ptr->location.mapGroup != mapGroup))
    {
        sprite->data[1] -= gCamera.x;
        sprite->data[2] -= gCamera.y;
        sprite->data[5] = ((u8)gSaveBlock1Ptr->location.mapNum << 8) | (u8)gSaveBlock1Ptr->location.mapGroup;
    }
    localId = sprite->data[3] >> 8;
    mapNum = sprite->data[3];
    mapGroup = sprite->data[4];
    metatileBehavior = MapGridGetMetatileBehaviorAt(sprite->data[1], sprite->data[2]);
    if (TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &eventObjectId) || !MetatileBehavior_IsLongGrass(metatileBehavior) || (sprite->data[7] && sprite->animEnded))
    {
        FieldEffectStop(sprite, FLDEFF_LONG_GRASS);
    }
    else
    {
        eventObject = &gEventObjects[eventObjectId];
        if ((eventObject->currentCoords.x != sprite->data[1] || eventObject->currentCoords.y != sprite->data[2]) && (eventObject->previousCoords.x != sprite->data[1] || eventObject->previousCoords.y != sprite->data[2]))
        {
            sprite->data[7] = TRUE;
        }
        UpdateEventObjectSpriteVisibility(sprite, 0);
        sub_81561FC(sprite, sprite->data[0], 0);
    }
}

u32 sub_81548FC(void)
{
    u8 spriteId;
    struct Sprite *sprite;

    sub_80930E0((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[16], gFieldEffectArguments[0], gFieldEffectArguments[1], 0);
    if (spriteId != MAX_SPRITES)
    {
        sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gFieldEffectArguments[3];
        sprite->data[0] = gFieldEffectArguments[2];
        sprite->data[1] = 18;
    }
    return 0;
}

u32 sub_815496C(void)
{
    u8 eventObjectId;
    struct EventObject *eventObject;
    u8 spriteId;
    struct Sprite *sprite;

    eventObjectId = GetEventObjectIdByLocalIdAndMap(gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    eventObject = &gEventObjects[eventObjectId];
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[30], 0, 0, 0);
    if (spriteId != MAX_SPRITES)
    {
        sprite = &(gSprites[spriteId]);
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gSprites[eventObject->spriteId].oam.priority;
        sprite->data[0] = gFieldEffectArguments[0];
        sprite->data[1] = gFieldEffectArguments[1];
        sprite->data[2] = gFieldEffectArguments[2];
        sprite->data[3] = gSprites[eventObject->spriteId].pos1.x;
        sprite->data[4] = gSprites[eventObject->spriteId].pos1.y;
    }
    return 0;
}

void sub_8154A10(struct Sprite *sprite)
{
    u8 eventObjectId;
    s16 x;
    s16 y;
    const struct EventObjectGraphicsInfo *graphicsInfo;
    struct Sprite *linkedSprite;

    if (TryGetEventObjectIdByLocalIdAndMap(sprite->data[0], sprite->data[1], sprite->data[2], &eventObjectId) || !gEventObjects[eventObjectId].inShortGrass)
    {
        FieldEffectStop(sprite, FLDEFF_SHORT_GRASS);
    }
    else
    {
        graphicsInfo = GetEventObjectGraphicsInfo(gEventObjects[eventObjectId].graphicsId);
        linkedSprite = &gSprites[gEventObjects[eventObjectId].spriteId];
        y = linkedSprite->pos1.y;
        x = linkedSprite->pos1.x;
        if (x != sprite->data[3] || y != sprite->data[4])
        {
            sprite->data[3] = x;
            sprite->data[4] = y;
            if (sprite->animEnded)
            {
                StartSpriteAnim(sprite, 0);
            }
        }
        sprite->pos1.x = x;
        sprite->pos1.y = y;
        sprite->pos2.y = (graphicsInfo->height >> 1) - 8;
        sprite->subpriority = linkedSprite->subpriority - 1;
        sprite->oam.priority = linkedSprite->oam.priority;
        UpdateEventObjectSpriteVisibility(sprite, linkedSprite->invisible);
    }
}

u32 sub_8154B04(void)
{
    u8 spriteId;
    struct Sprite *sprite;

    sub_80930E0((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[11], gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    if (spriteId != MAX_SPRITES)
    {
        sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gFieldEffectArguments[3];
        sprite->data[7] = FLDEFF_SAND_FOOTPRINTS;
        StartSpriteAnim(sprite, gFieldEffectArguments[4]);
    }
    return 0;
}

u32 sub_8154B78(void)
{
    u8 spriteId;
    struct Sprite *sprite;

    sub_80930E0((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[23], gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    if (spriteId != MAX_SPRITES)
    {
        sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gFieldEffectArguments[3];
        sprite->data[7] = FLDEFF_DEEP_SAND_FOOTPRINTS;
        StartSpriteAnim(sprite, gFieldEffectArguments[4]);
    }
    return spriteId;
}

u32 sub_8154BEC(void)
{
    u8 spriteId;
    struct Sprite *sprite;

    sub_80930E0((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[27], gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    if (spriteId != MAX_SPRITES)
    {
        sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gFieldEffectArguments[3];
        sprite->data[7] = FLDEFF_BIKE_TIRE_TRACKS;
        StartSpriteAnim(sprite, gFieldEffectArguments[4]);
    }
    return spriteId;
}
