#include "global.h"
#include "event_object_movement.h"//Initializations
#include "fieldmap.h"//Added u8 MapGridGetZCoordAt
#include "metatile_behavior.h"//Added bool8 MetatileBehavior_IsATile
#include "field_ground_effect.h"
#include "field_effect.h"
#include "field_effect_helpers.h"//Added void SetUpReflection and u32 oe_exec_and_other_stuff

static void DoTracksGroundEffect_None(struct MapObject *mapObj, struct Sprite *sprite, u8);
static void DoTracksGroundEffect_Footprints(struct MapObject *mapObj, struct Sprite *sprite, u8);
static void DoTracksGroundEffect_BikeTireTracks(struct MapObject *mapObj, struct Sprite *sprite, u8);
void GroundEffect_SpawnOnTallGrass(struct MapObject *mapObj, struct Sprite *sprite);
void GroundEffect_StepOnTallGrass(struct MapObject *mapObj, struct Sprite *sprite);
void GroundEffect_SpawnOnLongGrass(struct MapObject *mapObj, struct Sprite *sprite);
void GroundEffect_StepOnLongGrass(struct MapObject *mapObj, struct Sprite *sprite);
void GroundEffect_WaterReflection(struct MapObject *mapObj, struct Sprite *sprite);
void GroundEffect_IceReflection(struct MapObject *mapObj, struct Sprite *sprite);
void GroundEffect_FlowingWater(struct MapObject *mapObj, struct Sprite *sprite);
void GroundEffect_SandTracks(struct MapObject *mapObj, struct Sprite *sprite);
void GroundEffect_DeepSandTracks(struct MapObject *mapObj, struct Sprite *sprite);
void GroundEffect_Ripple(struct MapObject *mapObj, struct Sprite *sprite);
void GroundEffect_StepOnPuddle(struct MapObject *mapObj, struct Sprite *sprite);
void GroundEffect_SandHeap(struct MapObject *mapObj, struct Sprite *sprite);
void GroundEffect_JumpOnTallGrass(struct MapObject *mapObj, struct Sprite *sprite);
void GroundEffect_JumpOnLongGrass(struct MapObject *mapObj, struct Sprite *sprite);
void GroundEffect_JumpOnShallowWater(struct MapObject *mapObj, struct Sprite *sprite);
void GroundEffect_JumpOnWater(struct MapObject *mapObj, struct Sprite *sprite);
void GroundEffect_JumpLandingDust(struct MapObject *mapObj, struct Sprite *sprite);
void GroundEffect_ShortGrass(struct MapObject *mapObj, struct Sprite *sprite);
void GroundEffect_HotSprings(struct MapObject *mapObj, struct Sprite *sprite);
void GroundEffect_Seaweed(struct MapObject *mapObj, struct Sprite *sprite);
u8 GetReflectionTypeByMetatileBehavior(u32 behavior);

static void GetAllGroundEffectFlags_OnSpawn(struct MapObject *mapObj, u32 *flags)
{
    FieldObjectUpdateMetatileBehaviors(mapObj);
    GetGroundEffectFlags_Reflection(mapObj, flags);
    GetGroundEffectFlags_TallGrassOnSpawn(mapObj, flags);
    GetGroundEffectFlags_LongGrassOnSpawn(mapObj, flags);
    GetGroundEffectFlags_SandPile(mapObj, flags);
    GetGroundEffectFlags_ShallowFlowingWater(mapObj, flags);
    GetGroundEffectFlags_ShortGrass(mapObj, flags);
    GetGroundEffectFlags_HotSprings(mapObj, flags);
}

static void GetAllGroundEffectFlags_OnBeginStep(struct MapObject *mapObj, u32 *flags)
{
    FieldObjectUpdateMetatileBehaviors(mapObj);
    GetGroundEffectFlags_Reflection(mapObj, flags);
    GetGroundEffectFlags_TallGrassOnBeginStep(mapObj, flags);
    GetGroundEffectFlags_LongGrassOnBeginStep(mapObj, flags);
    GetGroundEffectFlags_Tracks(mapObj, flags);
    GetGroundEffectFlags_SandPile(mapObj, flags);
    GetGroundEffectFlags_ShallowFlowingWater(mapObj, flags);
    GetGroundEffectFlags_Puddle(mapObj, flags);
    GetGroundEffectFlags_ShortGrass(mapObj, flags);
    GetGroundEffectFlags_HotSprings(mapObj, flags);
}

static void GetAllGroundEffectFlags_OnFinishStep(struct MapObject *mapObj, u32 *flags)
{
    FieldObjectUpdateMetatileBehaviors(mapObj);
    GetGroundEffectFlags_ShallowFlowingWater(mapObj, flags);
    GetGroundEffectFlags_SandPile(mapObj, flags);
    GetGroundEffectFlags_Puddle(mapObj, flags);
    GetGroundEffectFlags_Ripple(mapObj, flags);
    GetGroundEffectFlags_ShortGrass(mapObj, flags);
    GetGroundEffectFlags_HotSprings(mapObj, flags);
    GetGroundEffectFlags_Seaweed(mapObj, flags);
    GetGroundEffectFlags_JumpLanding(mapObj, flags);
}

void FieldObjectUpdateMetatileBehaviors(struct MapObject *mapObj)
{
    mapObj->mapobj_unk_1F = MapGridGetMetatileBehaviorAt(mapObj->coords3.x, mapObj->coords3.y);
    mapObj->mapobj_unk_1E = MapGridGetMetatileBehaviorAt(mapObj->coords2.x, mapObj->coords2.y);
}

void GetGroundEffectFlags_Reflection(struct MapObject *mapObj, u32 *flags)
{
    u32 reflectionFlags[2] = { 0x00000020, 0x00000010 };
    u8 type = FieldObjectCheckForReflectiveSurface(mapObj);

    if (type)
    {
        if (!mapObj->mapobj_bit_17)
        {
            mapObj->mapobj_bit_17 = 0;
            mapObj->mapobj_bit_17 = 1;
            *flags |= reflectionFlags[type - 1];
        }
    }
    else
    {
        mapObj->mapobj_bit_17 = 0;
    }
}

void GetGroundEffectFlags_TallGrassOnSpawn(struct MapObject *mapObj, u32 *flags)
{
    if (MetatileBehavior_IsTallGrass(mapObj->mapobj_unk_1E))
        *flags |= 0x1;
}

void GetGroundEffectFlags_TallGrassOnBeginStep(struct MapObject *mapObj, u32 *flags)
{
    if (MetatileBehavior_IsTallGrass(mapObj->mapobj_unk_1E))
        *flags |= 0x2;
}

void GetGroundEffectFlags_LongGrassOnSpawn(struct MapObject *mapObj, u32 *flags)
{
    if (MetatileBehavior_IsLongGrass(mapObj->mapobj_unk_1E))
        *flags |= 0x4;
}

void GetGroundEffectFlags_LongGrassOnBeginStep(struct MapObject *mapObj, u32 *flags)
{
    if (MetatileBehavior_IsLongGrass(mapObj->mapobj_unk_1E))
        *flags |= 0x8;
}

void GetGroundEffectFlags_Tracks(struct MapObject *mapObj, u32 *flags)
{
    if (MetatileBehavior_IsDeepSand(mapObj->mapobj_unk_1F))
    {
        *flags |= 0x100;
    }
    else if (MetatileBehavior_IsSandOrDeepSand(mapObj->mapobj_unk_1F)
             || MetatileBehavior_IsUnusedFootprintMetatile(mapObj->mapobj_unk_1F))
    {
        *flags |= 0x80;
    }
}

void GetGroundEffectFlags_SandPile(struct MapObject *mapObj, u32 *flags)
{
    if (MetatileBehavior_IsDeepSand(mapObj->mapobj_unk_1E)
        && MetatileBehavior_IsDeepSand(mapObj->mapobj_unk_1F))
    {
        if (!mapObj->mapobj_bit_20)
        {
            mapObj->mapobj_bit_20 = 0;
            mapObj->mapobj_bit_20 = 1;
            *flags |= 0x800;
        }
    }
    else
    {
        mapObj->mapobj_bit_20 = 0;
    }
}

void GetGroundEffectFlags_ShallowFlowingWater(struct MapObject *mapObj, u32 *flags)
{
    if ((MetatileBehavior_IsShallowFlowingWater(mapObj->mapobj_unk_1E)
         && MetatileBehavior_IsShallowFlowingWater(mapObj->mapobj_unk_1F))
        || (MetatileBehavior_IsPacifidlogLog(mapObj->mapobj_unk_1E)
            && MetatileBehavior_IsPacifidlogLog(mapObj->mapobj_unk_1F)))
    {
        if (!mapObj->mapobj_bit_19)
        {
            mapObj->mapobj_bit_19 = 0;
            mapObj->mapobj_bit_19 = 1;
            *flags |= 0x40;
        }
    }
    else
    {
        mapObj->mapobj_bit_19 = 0;
    }
}

void GetGroundEffectFlags_Puddle(struct MapObject *mapObj, u32 *flags)
{
    if (MetatileBehavior_IsPuddle(mapObj->mapobj_unk_1E)
        && MetatileBehavior_IsPuddle(mapObj->mapobj_unk_1F))
    {
        *flags |= 0x400;
    }
}

void GetGroundEffectFlags_Ripple(struct MapObject *mapObj, u32 *flags)
{
    if (MetatileBehavior_HasRipples(mapObj->mapobj_unk_1E))
        *flags |= 0x200;
}

void GetGroundEffectFlags_ShortGrass(struct MapObject *mapObj, u32 *flags)
{
    if (MetatileBehavior_IsShortGrass(mapObj->mapobj_unk_1E)
        && MetatileBehavior_IsShortGrass(mapObj->mapobj_unk_1F))
    {
        if (!mapObj->mapobj_bit_18)
        {
            mapObj->mapobj_bit_18 = 0;
            mapObj->mapobj_bit_18 = 1;
            *flags |= 0x20000;
        }
    }
    else
    {
        mapObj->mapobj_bit_18 = 0;
    }
}

void GetGroundEffectFlags_HotSprings(struct MapObject *mapObj, u32 *flags)
{
    if (MetatileBehavior_IsHotSprings(mapObj->mapobj_unk_1E)
        && MetatileBehavior_IsHotSprings(mapObj->mapobj_unk_1F))
    {
        if (!mapObj->mapobj_bit_21)
        {
            mapObj->mapobj_bit_21 = 0;
            mapObj->mapobj_bit_21 = 1;
            *flags |= 0x40000;
        }
    }
    else
    {
        mapObj->mapobj_bit_21 = 0;
    }
}

void GetGroundEffectFlags_Seaweed(struct MapObject *mapObj, u32 *flags)
{
    if (MetatileBehavior_IsSeaweed(mapObj->mapobj_unk_1E))
        *flags |= 0x80000;
}

void GetGroundEffectFlags_JumpLanding(struct MapObject *mapObj, u32 *flags)
{
    typedef bool8 (*MetatileFunc)(u8);

    static const MetatileFunc metatileFuncs[] = {
        MetatileBehavior_IsTallGrass,
        MetatileBehavior_IsLongGrass,
        MetatileBehavior_IsPuddle,
        MetatileBehavior_IsSurfableWaterOrUnderwater,
        MetatileBehavior_IsShallowFlowingWater,
        ShouldDoJumpLandingDustEffect,//MetatileBehavior_IsATile in ruby
    };

    static const u32 jumpLandingFlags[] = {
        0x00001000, // Landing in tall grass
        0x00002000, // Landing in long grass
        0x00004000, // Landing on puddle
        0x00008000, // Landing on surfable water or underwater
        0x00004000, // Landing on shallow flowing water
        0x00010000, // Landing on any other type of ground
    };

    if (mapObj->mapobj_bit_5 && !mapObj->mapobj_bit_25)
    {
        u8 i;

        for (i = 0; i < 6; i++)
        {
            if (metatileFuncs[i](mapObj->mapobj_unk_1E))
            {
                *flags |= jumpLandingFlags[i];
                return;
            }
        }
    }
}

u8 FieldObjectCheckForReflectiveSurface(struct MapObject *mapObj)
{
    const struct MapObjectGraphicsInfo *info = GetFieldObjectGraphicsInfo(mapObj->graphicsId);

    // ceil div by tile width?
    s16 width = (info->width + 8) >> 4;
    s16 height = (info->height + 8) >> 4;
    s16 i;
    s16 j;
    u8 result;
    u8 b;
    s16 one;

#define RETURN_REFLECTION_TYPE_AT(x, y)              \
    b = MapGridGetMetatileBehaviorAt(x, y);          \
    result = GetReflectionTypeByMetatileBehavior(b); \
    if (result != 0)                                 \
        return result;

    for (i = 0, one = 1; i < height; i++)
    {
        RETURN_REFLECTION_TYPE_AT(mapObj->coords2.x, mapObj->coords2.y + one + i)
        RETURN_REFLECTION_TYPE_AT(mapObj->coords3.x, mapObj->coords3.y + one + i)
        for (j = 1; j < width; j++)
        {
            RETURN_REFLECTION_TYPE_AT(mapObj->coords2.x + j, mapObj->coords2.y + one + i)
            RETURN_REFLECTION_TYPE_AT(mapObj->coords2.x - j, mapObj->coords2.y + one + i)
            RETURN_REFLECTION_TYPE_AT(mapObj->coords3.x + j, mapObj->coords3.y + one + i)
            RETURN_REFLECTION_TYPE_AT(mapObj->coords3.x - j, mapObj->coords3.y + one + i)
        }
    }
    return 0;

#undef RETURN_REFLECTION_TYPE_AT
}

u8 GetReflectionTypeByMetatileBehavior(u32 behavior)
{
    if (MetatileBehavior_IsIce(behavior))
        return 1;
    else if (MetatileBehavior_IsReflective(behavior))
        return 2;
    else
        return 0;
}

u8 GetLedgeJumpDirection(s16 x, s16 y, u8 z)
{
    static bool8 (*const unknown_08376040[])(u8) = {
        MetatileBehavior_IsJumpSouth,
        MetatileBehavior_IsJumpNorth,
        MetatileBehavior_IsJumpWest,
        MetatileBehavior_IsJumpEast,
    };

    u8 b;
    u8 index = z;

    if (index == 0)
        return 0;
    else if (index > 4)
        index -= 4;

    index--;
    b = MapGridGetMetatileBehaviorAt(x, y);

    if (unknown_08376040[index](b) == 1)
        return index + 1;

    return 0;
}

void FieldObjectSetSpriteOamTableForLongGrass(struct MapObject *mapObj, struct Sprite *sprite)
{
    if (mapObj->mapobj_bit_4)
        return;

    if (!MetatileBehavior_IsLongGrass(mapObj->mapobj_unk_1E))
        return;

    if (!MetatileBehavior_IsLongGrass(mapObj->mapobj_unk_1F))
        return;

    sprite->subspriteTableNum = 4;

    if (ZCoordToPriority(mapObj->elevation) == 1)
        sprite->subspriteTableNum = 5;
}

bool8 IsZCoordMismatchAt(u8 z, s16 x, s16 y)
{
    u8 mapZ;

    if (z == 0)
        return FALSE;

    mapZ = MapGridGetZCoordAt(x, y);

    if (mapZ == 0 || mapZ == 0xF)
        return FALSE;

    if (mapZ != z)
        return TRUE;

    return FALSE;
}

static const u8 gUnknown_0850E624[] = {
    0x73, 0x73, 0x53, 0x73, 0x53, 0x73, 0x53, 0x73, 0x53, 0x73, 0x53, 0x73, 0x53, 0x00, 0x00, 0x73
};

// Each byte corresponds to a sprite priority for a field object.
// This is directly the inverse of gFieldObjectPriorities_08376070.
static const u8 gUnknown_0850E634[] = {
    2, 2, 2, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 0, 0, 2
};

// Each byte corresponds to a sprite priority for a field object.
// This is the inverse of gFieldObjectPriorities_08376060.
// 1 = Above player sprite
// 2 = Below player sprite
static const u8 gUnknown_0850E644[] = {
    1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 0, 0, 1,
};

void FieldObjectUpdateZCoordAndPriority(struct MapObject *mapObj, struct Sprite *sprite)
{
    if (mapObj->mapobj_bit_26)
        return;

    FieldObjectUpdateZCoord(mapObj);

    sprite->subspriteTableNum = gUnknown_0850E644[mapObj->elevation];
    sprite->oam.priority = gUnknown_0850E634[mapObj->elevation];
}

void InitObjectPriorityByZCoord(struct Sprite *sprite, u8 z)
{
    sprite->subspriteTableNum = gUnknown_0850E644[z];
    sprite->oam.priority = gUnknown_0850E634[z];
}

u8 ZCoordToPriority(u8 z)
{
    return gUnknown_0850E634[z];
}

void FieldObjectUpdateZCoord(struct MapObject *mapObj)
{
    u8 z = MapGridGetZCoordAt(mapObj->coords2.x, mapObj->coords2.y);
    u8 z2 = MapGridGetZCoordAt(mapObj->coords3.x, mapObj->coords3.y);

    if (z == 0xF || z2 == 0xF)
        return;

    mapObj->mapobj_unk_0B_0 = z;

    if (z != 0 && z != 0xF)
        mapObj->elevation = z;
}

void SetObjectSubpriorityByZCoord(u8 a, struct Sprite *sprite, u8 b)
{
    s32 tmp = sprite->centerToCornerVecY;
    u32 tmpa = *(u16 *)&sprite->pos1.y;
    u32 tmpb = *(u16 *)&gSpriteCoordOffsetY;
    s32 tmp2 = (tmpa - tmp) + tmpb;
    u16 tmp3 = (0x10 - ((((u32)tmp2 + 8) & 0xFF) >> 4)) * 2;
    sprite->subpriority = tmp3 + gUnknown_0850E624[a] + b;
}

void FieldObjectUpdateSubpriority(struct MapObject *mapObj, struct Sprite *sprite)
{
    if (mapObj->mapobj_bit_26)
        return;

    SetObjectSubpriorityByZCoord(mapObj->elevation, sprite, 1);
}

bool8 AreZCoordsCompatible(u8 a, u8 b)
{
    if (a == 0 || b == 0)
        return TRUE;

    if (a != b)
        return FALSE;

    return TRUE;
}

void GroundEffect_SpawnOnTallGrass(struct MapObject *mapObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = mapObj->coords2.x;
    gFieldEffectArguments[1] = mapObj->coords2.y;
    gFieldEffectArguments[2] = mapObj->elevation;
    gFieldEffectArguments[3] = 2;
    gFieldEffectArguments[4] = mapObj->localId << 8 | mapObj->mapNum;
    gFieldEffectArguments[5] = mapObj->mapGroup;
    gFieldEffectArguments[6] = (u8)gSaveBlock1Ptr->location.mapNum << 8 | (u8)gSaveBlock1Ptr->location.mapGroup;
    gFieldEffectArguments[7] = 1;
    FieldEffectStart(FLDEFF_TALL_GRASS);
}

void GroundEffect_StepOnTallGrass(struct MapObject *mapObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = mapObj->coords2.x;
    gFieldEffectArguments[1] = mapObj->coords2.y;
    gFieldEffectArguments[2] = mapObj->elevation;
    gFieldEffectArguments[3] = 2;
    gFieldEffectArguments[4] = mapObj->localId << 8 | mapObj->mapNum;
    gFieldEffectArguments[5] = mapObj->mapGroup;
    gFieldEffectArguments[6] = (u8)gSaveBlock1Ptr->location.mapNum << 8 | (u8)gSaveBlock1Ptr->location.mapGroup;
    gFieldEffectArguments[7] = 0;
    FieldEffectStart(FLDEFF_TALL_GRASS);
}

void GroundEffect_SpawnOnLongGrass(struct MapObject *mapObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = mapObj->coords2.x;
    gFieldEffectArguments[1] = mapObj->coords2.y;
    gFieldEffectArguments[2] = mapObj->elevation;
    gFieldEffectArguments[3] = 2;
    gFieldEffectArguments[4] = mapObj->localId << 8 | mapObj->mapNum;
    gFieldEffectArguments[5] = mapObj->mapGroup;
    gFieldEffectArguments[6] = (u8)gSaveBlock1Ptr->location.mapNum << 8 | (u8)gSaveBlock1Ptr->location.mapGroup;
    gFieldEffectArguments[7] = 1;
    FieldEffectStart(FLDEFF_LONG_GRASS);
}

void GroundEffect_StepOnLongGrass(struct MapObject *mapObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = mapObj->coords2.x;
    gFieldEffectArguments[1] = mapObj->coords2.y;
    gFieldEffectArguments[2] = mapObj->elevation;
    gFieldEffectArguments[3] = 2;
    gFieldEffectArguments[4] = (mapObj->localId << 8) | mapObj->mapNum;
    gFieldEffectArguments[5] = mapObj->mapGroup;
    gFieldEffectArguments[6] = (u8)gSaveBlock1Ptr->location.mapNum << 8 | (u8)gSaveBlock1Ptr->location.mapGroup;
    gFieldEffectArguments[7] = 0;
    FieldEffectStart(FLDEFF_LONG_GRASS);
}

void GroundEffect_WaterReflection(struct MapObject *mapObj, struct Sprite *sprite)
{
    SetUpReflection(mapObj, sprite, 0);
}

void GroundEffect_IceReflection(struct MapObject *mapObj, struct Sprite *sprite)
{
    SetUpReflection(mapObj, sprite, 1);
}

void GroundEffect_FlowingWater(struct MapObject *mapObj, struct Sprite *sprite)
{
    oe_exec_and_other_stuff(FLDEFF_FEET_IN_FLOWING_WATER, mapObj);
}

static void (*const gUnknown_0850E654[])(struct MapObject *mapObj, struct Sprite *sprite, u8 a) = 
{
    DoTracksGroundEffect_None, DoTracksGroundEffect_Footprints, DoTracksGroundEffect_BikeTireTracks,
};

void GroundEffect_SandTracks(struct MapObject *mapObj, struct Sprite *sprite)
{
    const struct MapObjectGraphicsInfo *info = GetFieldObjectGraphicsInfo(mapObj->graphicsId);
    gUnknown_0850E654[info->tracks](mapObj, sprite, 0);
}

void GroundEffect_DeepSandTracks(struct MapObject *mapObj, struct Sprite *sprite)
{
    const struct MapObjectGraphicsInfo *info = GetFieldObjectGraphicsInfo(mapObj->graphicsId);
    gUnknown_0850E654[info->tracks](mapObj, sprite, 1);
}

static void DoTracksGroundEffect_None(struct MapObject *mapObj, struct Sprite *sprite, u8 a)
{
}

static void DoTracksGroundEffect_Footprints(struct MapObject *mapObj, struct Sprite *sprite, u8 a)
{
    // First half-word is a Field Effect script id. (gFieldEffectScriptPointers)
    u16 gUnknown_0850E660[2] = {//sandFootprints_FieldEffectData
            FLDEFF_SAND_FOOTPRINTS,
            FLDEFF_DEEP_SAND_FOOTPRINTS
    };

    gFieldEffectArguments[0] = mapObj->coords3.x;
    gFieldEffectArguments[1] = mapObj->coords3.y;
    gFieldEffectArguments[2] = 149;
    gFieldEffectArguments[3] = 2;
    gFieldEffectArguments[4] = mapObj->mapobj_unk_18;
    FieldEffectStart(gUnknown_0850E660[a]);//sandFootprints_FieldEffectData
}

static void DoTracksGroundEffect_BikeTireTracks(
    struct MapObject *mapObj, struct Sprite *sprite, u8 a)
{
    //  Specifies which bike track shape to show next.
    //  For example, when the bike turns from up to right, it will show
    //  a track that curves to the right.
    //  Each 4-byte row corresponds to the initial direction of the bike, and
    //  each byte in that row is for the next direction of the bike in the order
    //  of down, up, left, right.
    static const u8 gUnknown_0850E664[4][4] = {//bikeTireTracks_Transitions
        1, 2, 7, 8,
        1, 2, 6, 5,
        5, 8, 3, 4,
        6, 7, 3, 4,
    };

    if (mapObj->coords2.x != mapObj->coords3.x || mapObj->coords2.y != mapObj->coords3.y)
    {
        gFieldEffectArguments[0] = mapObj->coords3.x;
        gFieldEffectArguments[1] = mapObj->coords3.y;
        gFieldEffectArguments[2] = 149;
        gFieldEffectArguments[3] = 2;
        gFieldEffectArguments[4] =
            gUnknown_0850E664[mapObj->mapobj_unk_20][mapObj->mapobj_unk_18 - 5];//bikeTireTracks_Transitions
        FieldEffectStart(FLDEFF_BIKE_TIRE_TRACKS);
    }
}

void GroundEffect_Ripple(struct MapObject *mapObj, struct Sprite *sprite)
{
    DoRippleFieldEffect(mapObj, sprite);
}

void GroundEffect_StepOnPuddle(struct MapObject *mapObj, struct Sprite *sprite)
{
    oe_exec_and_other_stuff(FLDEFF_SPLASH, mapObj);
}

void GroundEffect_SandHeap(struct MapObject *mapObj, struct Sprite *sprite)
{
    oe_exec_and_other_stuff(FLDEFF_SAND_PILE, mapObj);
}

void GroundEffect_JumpOnTallGrass(struct MapObject *mapObj, struct Sprite *sprite)
{
    u8 spriteId;

    gFieldEffectArguments[0] = mapObj->coords2.x;
    gFieldEffectArguments[1] = mapObj->coords2.y;
    gFieldEffectArguments[2] = mapObj->elevation;
    gFieldEffectArguments[3] = 2;
    FieldEffectStart(FLDEFF_JUMP_TALL_GRASS);

    spriteId = sub_81546C8(
        mapObj->localId, mapObj->mapNum, mapObj->mapGroup, mapObj->coords2.x, mapObj->coords2.y);

    if (spriteId == MAX_SPRITES)
        GroundEffect_SpawnOnTallGrass(mapObj, sprite);
}

void GroundEffect_JumpOnLongGrass(struct MapObject *mapObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = mapObj->coords2.x;
    gFieldEffectArguments[1] = mapObj->coords2.y;
    gFieldEffectArguments[2] = mapObj->elevation;
    gFieldEffectArguments[3] = 2;
    FieldEffectStart(FLDEFF_JUMP_LONG_GRASS);
}

void GroundEffect_JumpOnShallowWater(struct MapObject *mapObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = mapObj->coords2.x;
    gFieldEffectArguments[1] = mapObj->coords2.y;
    gFieldEffectArguments[2] = mapObj->elevation;
    gFieldEffectArguments[3] = sprite->oam.priority;
    FieldEffectStart(FLDEFF_JUMP_SMALL_SPLASH);
}

void GroundEffect_JumpOnWater(struct MapObject *mapObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = mapObj->coords2.x;
    gFieldEffectArguments[1] = mapObj->coords2.y;
    gFieldEffectArguments[2] = mapObj->elevation;
    gFieldEffectArguments[3] = sprite->oam.priority;
    FieldEffectStart(FLDEFF_JUMP_BIG_SPLASH);
}

void GroundEffect_JumpLandingDust(struct MapObject *mapObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = mapObj->coords2.x;
    gFieldEffectArguments[1] = mapObj->coords2.y;
    gFieldEffectArguments[2] = mapObj->elevation;
    gFieldEffectArguments[3] = sprite->oam.priority;
    FieldEffectStart(FLDEFF_DUST);
}

void GroundEffect_ShortGrass(struct MapObject *mapObj, struct Sprite *sprite)
{
    oe_exec_and_other_stuff(FLDEFF_SHORT_GRASS, mapObj);
}

void GroundEffect_HotSprings(struct MapObject *mapObj, struct Sprite *sprite)
{
    oe_exec_and_other_stuff(FLDEFF_HOT_SPRINGS_WATER, mapObj);
}

void GroundEffect_Seaweed(struct MapObject *mapObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = mapObj->coords2.x;
    gFieldEffectArguments[1] = mapObj->coords2.y;
    FieldEffectStart(FLDEFF_BUBBLES);
}

static void (*const gUnknown_0850E674[])(struct MapObject *mapObj, struct Sprite *sprite) = {
    GroundEffect_SpawnOnTallGrass,
    GroundEffect_StepOnTallGrass,
    GroundEffect_SpawnOnLongGrass,
    GroundEffect_StepOnLongGrass,
    GroundEffect_WaterReflection,
    GroundEffect_IceReflection,
    GroundEffect_FlowingWater,
    GroundEffect_SandTracks,
    GroundEffect_DeepSandTracks,
    GroundEffect_Ripple,
    GroundEffect_StepOnPuddle,
    GroundEffect_SandHeap,
    GroundEffect_JumpOnTallGrass,
    GroundEffect_JumpOnLongGrass,
    GroundEffect_JumpOnShallowWater,
    GroundEffect_JumpOnWater,
    GroundEffect_JumpLandingDust,
    GroundEffect_ShortGrass,
    GroundEffect_HotSprings,
    GroundEffect_Seaweed
};

void DoFlaggedGroundEffects(struct MapObject *mapObj, struct Sprite *sprite, u32 flags)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(gUnknown_0850E674); i++, flags >>= 1)//gUnknown_083760A0
        if (flags & 1)
            gUnknown_0850E674[i](mapObj, sprite);
}

void filters_out_some_ground_effects(struct MapObject *mapObj, u32 *flags)
{
    if (mapObj->mapobj_bit_4)
    {
        mapObj->mapobj_bit_18 = 0;
        mapObj->mapobj_bit_20 = 0;
        mapObj->mapobj_bit_19 = 0;
        mapObj->mapobj_bit_21 = 0;
        *flags &= 0xFFF9F7BD;
    }
}

void FilterOutStepOnPuddleGroundEffectIfJumping(struct MapObject *mapObj, u32 *flags)
{
    if (mapObj->mapobj_bit_5)
        *flags &= 0xFFFFFBFF;
}

void DoGroundEffects_OnSpawn(struct MapObject *mapObj, struct Sprite *sprite)
{
    u32 flags;

    if (mapObj->mapobj_bit_2)
    {
        flags = 0;
        FieldObjectUpdateZCoordAndPriority(mapObj, sprite);
        GetAllGroundEffectFlags_OnSpawn(mapObj, &flags);
        FieldObjectSetSpriteOamTableForLongGrass(mapObj, sprite);
        DoFlaggedGroundEffects(mapObj, sprite, flags);
        mapObj->mapobj_bit_2 = 0;
        mapObj->mapobj_bit_4 = 0;
    }
}

void DoGroundEffects_OnBeginStep(struct MapObject *mapObj, struct Sprite *sprite)
{
    u32 flags;

    if (mapObj->mapobj_bit_2)
    {
        flags = 0;
        FieldObjectUpdateZCoordAndPriority(mapObj, sprite);
        GetAllGroundEffectFlags_OnBeginStep(mapObj, &flags);
        FieldObjectSetSpriteOamTableForLongGrass(mapObj, sprite);
        filters_out_some_ground_effects(mapObj, &flags);
        DoFlaggedGroundEffects(mapObj, sprite, flags);
        mapObj->mapobj_bit_2 = 0;
        mapObj->mapobj_bit_4 = 0;
    }
}

void DoGroundEffects_OnFinishStep(struct MapObject *mapObj, struct Sprite *sprite)
{
    u32 flags;

    if (mapObj->mapobj_bit_3)
    {
        flags = 0;
        FieldObjectUpdateZCoordAndPriority(mapObj, sprite);
        GetAllGroundEffectFlags_OnFinishStep(mapObj, &flags);
        FieldObjectSetSpriteOamTableForLongGrass(mapObj, sprite);
        FilterOutStepOnPuddleGroundEffectIfJumping(mapObj, &flags);
        DoFlaggedGroundEffects(mapObj, sprite, flags);
        mapObj->mapobj_bit_3 = 0;
        mapObj->mapobj_bit_5 = 0;
    }
}
