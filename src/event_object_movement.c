// Includes

#include "global.h"
#include "malloc.h"
#include "sprite.h"
#include "overworld.h"
#include "random.h"
#include "event_scripts.h"
#include "berry.h"
#include "palette.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "event_data.h"
#include "rom_818CFC8.h"
#include "rom_81BE66C.h"
#include "mauville_old_man.h"
#include "metatile_behavior.h"
#include "field_effect.h"
#include "field_effect_helpers.h"
#include "field_camera.h"
#include "trainer_see.h"
#include "decoration.h"
#include "event_object_movement.h"
#include "pokenav.h"
#include "util.h"
#include "constants/map_objects.h"

#define NUM_FIELD_MAP_OBJECT_TEMPLATES 0x51

#define null_object_step(name, retval) \
bool8 FieldObjectCB2_##name(struct MapObject *, struct Sprite *);\
void FieldObjectCB_##name(struct Sprite *sprite)\
{\
    FieldObjectStep(&gMapObjects[sprite->data[0]], sprite, FieldObjectCB2_##name);\
}\
bool8 FieldObjectCB2_##name(struct MapObject *mapObject, struct Sprite *sprite)\
{\
    return (retval);\
}

#define field_object_step(name, table) \
extern bool8 (*const (table)[])(struct MapObject *, struct Sprite *);\
bool8 FieldObjectCB2_##name(struct MapObject *, struct Sprite *);\
void FieldObjectCB_##name(struct Sprite *sprite)\
{\
    FieldObjectStep(&gMapObjects[sprite->data[0]], sprite, FieldObjectCB2_##name);\
}\
bool8 FieldObjectCB2_##name(struct MapObject *mapObject, struct Sprite *sprite)\
{\
    return (table)[sprite->data[1]](mapObject, sprite);\
}

#define field_object_path(idx, table, sub, path, catch, coord)\
field_object_step(GoInDirectionSequence##idx, table)\
extern const u8 path[4];\
bool8 sub(struct MapObject *mapObject, struct Sprite *sprite)\
{\
    u8 route[sizeof(path)];\
    memcpy(route, path, sizeof(path));\
    if (mapObject->directionSequenceIndex == (catch) && mapObject->initialCoords.coord == mapObject->currentCoords.coord)\
    {\
        mapObject->directionSequenceIndex = (catch) + 1;\
    }\
    return MoveFieldObjectInNextDirectionInSequence(mapObject, sprite, route);\
}\

// Static struct declarations

// Static RAM declarations

extern u8 gUnknown_020375B4;
extern u16 gUnknown_020375B6;
extern u8 *gUnknown_020375B8;

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
static void ObjectCB_CameraObject(struct Sprite *);
static void CameraObject_0(struct Sprite *);
static void CameraObject_1(struct Sprite *);
static void CameraObject_2(struct Sprite *);
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
static void SetFieldObjectStepTimer(struct Sprite *, s16);
bool8 RunFieldObjectStepTimer(struct Sprite *);
bool8 npc_block_way__next_tile(struct MapObject *, u8);
static u32 state_to_direction(u8, u32, u32);
/*static*/ void sub_80964E8(struct MapObject *, struct Sprite *);
static void FieldObjectExecSpecialAnim(struct MapObject *, struct Sprite *);
/*static*/ void npc_obj_transfer_image_anim_pause_flag(struct MapObject *, struct Sprite *);

static bool8 IsCoordOutsideFieldObjectMovementRect(struct MapObject *, s16, s16);
static bool8 IsMetatileDirectionallyImpassable(struct MapObject *, s16, s16, u8);
static bool8 CheckForCollisionBetweenFieldObjects(struct MapObject *, s16, s16);
bool8 sub_809558C(struct MapObject *, struct Sprite *);
bool8 sub_8095B64(struct MapObject *, struct Sprite *);
static void sub_8096530(struct MapObject *, struct Sprite *);
static void npc_update_obj_anim_flag(struct MapObject *, struct Sprite *);

// ROM data

struct PairedPalettes {
    u16 tag;
    const u16 *data;
};


typedef void (*SpriteStepFunc)(struct Sprite *sprite, u8 dir);

extern s16 gUnknown_0850E768[];
extern SpriteStepFunc *const gUnknown_0850E754[];
extern const s8 gUnknown_0850E772[];
extern const s8 gUnknown_0850E7BA[];
extern const s8 *const gUnknown_0850E834[];
extern s16 gUnknown_0850E840[];
extern u8 gUnknown_0850E846[];
extern s16 gUnknown_0850E84A[];
extern u8 gUnknown_0850E850[];

static void FieldObjectUpdateMetatileBehaviors(struct MapObject*);
static void GetGroundEffectFlags_Reflection(struct MapObject*, u32*);
static void GetGroundEffectFlags_TallGrassOnSpawn(struct MapObject*, u32*);
static void GetGroundEffectFlags_LongGrassOnSpawn(struct MapObject*, u32*);
static void GetGroundEffectFlags_SandHeap(struct MapObject*, u32*);
static void GetGroundEffectFlags_ShallowFlowingWater(struct MapObject*, u32*);
static void GetGroundEffectFlags_ShortGrass(struct MapObject*, u32*);
static void GetGroundEffectFlags_HotSprings(struct MapObject*, u32*);
static void GetGroundEffectFlags_TallGrassOnBeginStep(struct MapObject*, u32*);
static void GetGroundEffectFlags_LongGrassOnBeginStep(struct MapObject*, u32*);
static void GetGroundEffectFlags_Tracks(struct MapObject*, u32*);
static void GetGroundEffectFlags_Puddle(struct MapObject*, u32*);
static void GetGroundEffectFlags_Ripple(struct MapObject*, u32*);
static void GetGroundEffectFlags_Seaweed(struct MapObject*, u32*);
static void GetGroundEffectFlags_JumpLanding(struct MapObject*, u32*);
static u8 FieldObjectCheckForReflectiveSurface(struct MapObject*);
static u8 GetReflectionTypeByMetatileBehavior(u32);
static void InitObjectPriorityByZCoord(struct Sprite *sprite, u8 z);
static void FieldObjectUpdateSubpriority(struct MapObject*, struct Sprite*);
static void DoTracksGroundEffect_None(struct MapObject*, struct Sprite*, u8);
static void DoTracksGroundEffect_Footprints(struct MapObject*, struct Sprite*, u8);
static void DoTracksGroundEffect_BikeTireTracks(struct MapObject*, struct Sprite*, u8);
static void DoRippleFieldEffect(struct MapObject*, struct Sprite*);
static void DoGroundEffects_OnSpawn(struct MapObject*, struct Sprite*);
static void DoGroundEffects_OnBeginStep(struct MapObject*, struct Sprite*);
static void DoGroundEffects_OnFinishStep(struct MapObject*, struct Sprite*);
static void sub_8097D68(struct Sprite*);
static void sub_8097FE4(u8);

const u8 gUnknown_084975C4[] = {1, 1, 6, 7, 8, 9, 6, 7, 8, 9, 11, 11, 0, 0, 0, 0};

const struct SpriteTemplate gCameraSpriteTemplate = {0, 0xFFFF, &gDummyOamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, ObjectCB_CameraObject};

void (*const gCameraObjectFuncs[])(struct Sprite *) = {
    CameraObject_0,
    CameraObject_1,
    CameraObject_2,
};

#include "data/field_event_obj/event_object_graphics.h"

// movement type callbacks
void (*const gUnknown_08505438[])(struct Sprite *) =
{
    FieldObjectCB_NoMovement1,
    FieldObjectCB_LookRandomDirections,
    FieldObjectCB_GoRandomDirections,
    FieldObjectCB_RandomlyGoNorthOrSouth,
    FieldObjectCB_RandomlyGoNorthOrSouth,
    FieldObjectCB_RandomlyGoEastOrWest,
    FieldObjectCB_RandomlyGoEastOrWest,
    FieldObjectCB_FaceFixedDirection,
    FieldObjectCB_FaceFixedDirection,
    FieldObjectCB_FaceFixedDirection,
    FieldObjectCB_FaceFixedDirection,
    FieldObjectCB_NoMovement2,
    FieldObjectCB_BerryTree,
    FieldObjectCB_RandomlyLookNorthOrSouth,
    FieldObjectCB_RandomlyLookEastOrWest,
    FieldObjectCB_RandomlyLookNorthOrWest,
    FieldObjectCB_RandomlyLookNorthOrEast,
    FieldObjectCB_RandomlyLookSouthOrWest,
    FieldObjectCB_RandomlyLookSouthOrEast,
    FieldObjectCB_RandomlyLookNorthOrSouthOrWest,
    FieldObjectCB_RandomlyLookNorthOrSouthOrEast,
    FieldObjectCB_RandomlyLookNorthOrEastOrWest,
    FieldObjectCB_RandomlyLookSouthOrEastOrWest,
    FieldObjectCB_LookAroundCounterclockwise,
    FieldObjectCB_LookAroundClockwise,
    FieldObjectCB_AlternatelyGoInOppositeDirections,
    FieldObjectCB_AlternatelyGoInOppositeDirections,
    FieldObjectCB_AlternatelyGoInOppositeDirections,
    FieldObjectCB_AlternatelyGoInOppositeDirections,
    FieldObjectCB_GoInDirectionSequence1,
    FieldObjectCB_GoInDirectionSequence2,
    FieldObjectCB_GoInDirectionSequence3,
    FieldObjectCB_GoInDirectionSequence4,
    FieldObjectCB_GoInDirectionSequence5,
    FieldObjectCB_GoInDirectionSequence6,
    FieldObjectCB_GoInDirectionSequence7,
    FieldObjectCB_GoInDirectionSequence8,
    FieldObjectCB_GoInDirectionSequence9,
    FieldObjectCB_GoInDirectionSequence10,
    FieldObjectCB_GoInDirectionSequence11,
    FieldObjectCB_GoInDirectionSequence12,
    FieldObjectCB_GoInDirectionSequence13,
    FieldObjectCB_GoInDirectionSequence14,
    FieldObjectCB_GoInDirectionSequence15,
    FieldObjectCB_GoInDirectionSequence16,
    FieldObjectCB_GoInDirectionSequence17,
    FieldObjectCB_GoInDirectionSequence18,
    FieldObjectCB_GoInDirectionSequence19,
    FieldObjectCB_GoInDirectionSequence20,
    FieldObjectCB_GoInDirectionSequence21,
    FieldObjectCB_GoInDirectionSequence22,
    FieldObjectCB_GoInDirectionSequence23,
    FieldObjectCB_GoInDirectionSequence24,
    FieldObjectCB_CopyPlayer1,
    FieldObjectCB_CopyPlayer1,
    FieldObjectCB_CopyPlayer1,
    FieldObjectCB_CopyPlayer1,
    FieldObjectCB_TreeDisguise,
    FieldObjectCB_MountainDisguise,
    FieldObjectCB_CopyPlayer2,
    FieldObjectCB_CopyPlayer2,
    FieldObjectCB_CopyPlayer2,
    FieldObjectCB_CopyPlayer2,
    FieldObjectCB_Hidden1,
    FieldObjectCB_WalkInPlace1,
    FieldObjectCB_WalkInPlace1,
    FieldObjectCB_WalkInPlace1,
    FieldObjectCB_WalkInPlace1,
    FieldObjectCB_WalkInPlace2,
    FieldObjectCB_WalkInPlace2,
    FieldObjectCB_WalkInPlace2,
    FieldObjectCB_WalkInPlace2,
    FieldObjectCB_WalkInPlace3,
    FieldObjectCB_WalkInPlace3,
    FieldObjectCB_WalkInPlace3,
    FieldObjectCB_WalkInPlace3,
    FieldObjectCB_Hidden2,
    FieldObjectCB_WalkInPlace4,
    FieldObjectCB_WalkInPlace4,
    FieldObjectCB_WalkInPlace4,
    FieldObjectCB_WalkInPlace4,
};

const u8 gRangedMovementTypes[] = {
    0,
    0,
    1,
    1,
    1,
    1,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    0,
    0,
    1,
    1,
    1,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

const u8 gInitialMovementTypeFacingDirections[] = {
    DIR_SOUTH,
    DIR_SOUTH,
    DIR_SOUTH,
    DIR_NORTH,
    DIR_SOUTH,
    DIR_WEST,
    DIR_EAST,
    DIR_NORTH,
    DIR_SOUTH,
    DIR_WEST,
    DIR_EAST,
    DIR_SOUTH,
    DIR_SOUTH,
    DIR_SOUTH,
    DIR_WEST,
    DIR_NORTH,
    DIR_NORTH,
    DIR_SOUTH,
    DIR_SOUTH,
    DIR_SOUTH,
    DIR_SOUTH,
    DIR_NORTH,
    DIR_SOUTH,
    DIR_SOUTH,
    DIR_SOUTH,
    DIR_NORTH,
    DIR_SOUTH,
    DIR_WEST,
    DIR_EAST,
    DIR_NORTH,
    DIR_EAST,
    DIR_SOUTH,
    DIR_WEST,
    DIR_NORTH,
    DIR_WEST,
    DIR_SOUTH,
    DIR_EAST,
    DIR_WEST,
    DIR_NORTH,
    DIR_EAST,
    DIR_SOUTH,
    DIR_EAST,
    DIR_NORTH,
    DIR_WEST,
    DIR_SOUTH,
    DIR_NORTH,
    DIR_SOUTH,
    DIR_WEST,
    DIR_EAST,
    DIR_NORTH,
    DIR_SOUTH,
    DIR_WEST,
    DIR_EAST,
    DIR_NORTH,
    DIR_SOUTH,
    DIR_WEST,
    DIR_EAST,
    DIR_SOUTH,
    DIR_SOUTH,
    DIR_NORTH,
    DIR_SOUTH,
    DIR_WEST,
    DIR_EAST,
    DIR_SOUTH,
    DIR_SOUTH,
    DIR_NORTH,
    DIR_WEST,
    DIR_EAST,
    DIR_SOUTH,
    DIR_NORTH,
    DIR_WEST,
    DIR_EAST,
    DIR_SOUTH,
    DIR_NORTH,
    DIR_WEST,
    DIR_EAST,
    DIR_SOUTH,
    DIR_SOUTH,
    DIR_NORTH,
    DIR_WEST,
    DIR_EAST,
};

#include "data/field_event_obj/event_object_graphics_info_pointers.h"
#include "data/field_event_obj/field_effect_object_template_pointers.h"
#include "data/field_event_obj/event_object_pic_tables.h"
#include "data/field_event_obj/event_object_anims.h"
#include "data/field_event_obj/base_oam.h"
#include "data/field_event_obj/event_object_subsprites.h"
#include "data/field_event_obj/event_object_graphics_info.h"

const struct SpritePalette gUnknown_0850BBC8[] = {
    {gFieldObjectPalette0,  0x1103},
    {gFieldObjectPalette1,  0x1104},
    {gFieldObjectPalette2,  0x1105},
    {gFieldObjectPalette3,  0x1106},
    {gFieldObjectPalette4,  0x1107},
    {gFieldObjectPalette5,  0x1108},
    {gFieldObjectPalette6,  0x1109},
    {gFieldObjectPalette7,  0x110A},
    {gFieldObjectPalette8,  0x1100},
    {gFieldObjectPalette9,  0x1101},
    {gFieldObjectPalette10, 0x1102},
    {gFieldObjectPalette11, 0x1115},
    {gFieldObjectPalette12, 0x110B},
    {gFieldObjectPalette13, 0x110C},
    {gFieldObjectPalette14, 0x110D},
    {gFieldObjectPalette15, 0x110E},
    {gFieldObjectPalette16, 0x110F},
    {gFieldObjectPalette17, 0x1110},
    {gFieldObjectPalette18, 0x1111},
    {gFieldObjectPalette19, 0x1112},
    {gFieldObjectPalette20, 0x1113},
    {gFieldObjectPalette21, 0x1114},
    {gFieldObjectPalette22, 0x1116},
    {gFieldObjectPalette23, 0x1117},
    {gFieldObjectPalette24, 0x1118},
    {gFieldObjectPalette25, 0x1119},
    {gFieldObjectPalette26, 0x111B},
    {gFieldObjectPalette27, 0x111C},
    {gFieldObjectPalette28, 0x111D},
    {gFieldObjectPalette29, 0x111E},
    {gFieldObjectPalette30, 0x111F},
    {gFieldObjectPalette31, 0x1120},
    {gFieldObjectPalette32, 0x1121},
    {gFieldObjectPalette33, 0x1122},
    {gFieldObjectPalette34, 0x1123},
    {NULL,                  0x0000},
};

const u16 Unknown_0850BCE8[] = {
    0x1101,
    0x1101,
    0x1101,
    0x1101,
};

const u16 Unknown_0850BCF0[] = {
    0x1111,
    0x1111,
    0x1111,
    0x1111,
};

const u16 Unknown_0850BCF8[] = {
    0x1115,
    0x1115,
    0x1115,
    0x1115,
};

const struct PairedPalettes gUnknown_0850BD00[] = {
    {0x1100, Unknown_0850BCE8},
    {0x1110, Unknown_0850BCF0},
    {0x1115, Unknown_0850BCF8},
    {0x11FF, NULL},
};

const u16 Unknown_0850BD20[] = {
    0x110C,
    0x110C,
    0x110C,
    0x110C,
};

const u16 Unknown_0850BD28[] = {
    0x110D,
    0x110D,
    0x110D,
    0x110D,
};

const u16 Unknown_0850BD30[] = {
    0x110E,
    0x110E,
    0x110E,
    0x110E,
};

const u16 Unknown_0850BD38[] = {
    0x1112,
    0x1112,
    0x1112,
    0x1112,
};

const u16 Unknown_0850BD40[] = {
    0x1113,
    0x1113,
    0x1113,
    0x1113,
};

const u16 Unknown_0850BD48[] = {
    0x1114,
    0x1114,
    0x1114,
    0x1114,
};

const u16 Unknown_0850BD50[] = {
    0x111B,
    0x111B,
    0x111B,
    0x111B,
};

const u16 Unknown_0850BD58[] = {
    0x1117,
    0x1117,
    0x1117,
    0x1117,
};

const u16 Unknown_0850BD60[] = {
    0x1119,
    0x1119,
    0x1119,
    0x1119,
};

const u16 Unknown_0850BD68[] = {
    0x1109,
    0x1109,
    0x1109,
    0x1109,
};

const u16 Unknown_0850BD70[] = {
    0x111D,
    0x111D,
    0x111D,
    0x111D,
};

const struct PairedPalettes gUnknown_0850BD78[] = {
    {4352, Unknown_0850BCE8},
    {4368, Unknown_0850BCF0},
    {4363, Unknown_0850BD20},
    {4365, Unknown_0850BD28},
    {4366, Unknown_0850BD30},
    {4370, Unknown_0850BD38},
    {4371, Unknown_0850BD40},
    {4372, Unknown_0850BD48},
    {4374, Unknown_0850BD58},
    {4376, Unknown_0850BD60},
    {4357, Unknown_0850BD68},
    {4379, Unknown_0850BD50},
    {4381, Unknown_0850BD70},
    {4607, NULL},
};

const u16 gUnknown_0850BDE8[] = {
    0x1100,
    0x1101,
    0x1103,
    0x1104,
    0x1105,
    0x1106,
    0x1107,
    0x1108,
    0x1109,
    0x110A,
};

const u16 gUnknown_0850BDFC[] = {
    0x1100,
    0x1101,
    0x1103,
    0x1104,
    0x1105,
    0x1106,
    0x1107,
    0x1108,
    0x1109,
    0x110A,
};

const u16 gUnknown_0850BE10[] = {
    0x1100,
    0x1101,
    0x1103,
    0x1104,
    0x1105,
    0x1106,
    0x1107,
    0x1108,
    0x1109,
    0x110A,
};

const u16 gUnknown_0850BE24[] = {
     0x1100,
     0x1101,
     0x1103,
     0x1104,
     0x1105,
     0x1106,
     0x1107,
     0x1108,
     0x1109,
     0x110A,
};


const u16 *const gUnknown_0850BE38[] = {
    gUnknown_0850BDE8,
    gUnknown_0850BDFC,
    gUnknown_0850BE10,
    gUnknown_0850BE24,
};

#include "data/field_event_obj/berry_tree_graphics_tables.h"
#include "data/field_event_obj/field_effect_objects.h"

const s16 gMovementDelaysMedium[] = {32, 64,  96, 128};
const s16 gMovementDelaysLong[] =   {32, 64, 128, 192};
const s16 gMovementDelaysShort[] =  {32, 48,  64,  80};

#include "data/field_event_obj/movement_type_func_tables.h"

const u8 gUnknown_0850DACC[] = {
    0x00,
    0x00,
    0x01,
    0x02,
    0x03,
    0x00,
    0x00,
    0x01,
    0x01,
};

const u8 gUnknown_0850DAD5[] = {
    0x04,
    0x04,
    0x05,
    0x06,
    0x07,
    0x04,
    0x04,
    0x05,
    0x05,
};

const u8 gUnknown_0850DADE[] = {
    0x08,
    0x08,
    0x09,
    0x0a,
    0x0b,
    0x08,
    0x08,
    0x09,
    0x09,
};

const u8 gUnknown_0850DAE7[] = {
    0x0c,
    0x0c,
    0x0d,
    0x0e,
    0x0f,
    0x0c,
    0x0c,
    0x0d,
    0x0d,
};

const u8 gUnknown_0850DAF0[] = {
    0x10,
    0x10,
    0x11,
    0x12,
    0x13,
    0x10,
    0x10,
    0x11,
    0x11,
};

const u8 gUnknown_0850DAF9[] = {
    0x14,
    0x14,
    0x15,
    0x16,
    0x17,
    0x14,
    0x14,
    0x15,
    0x15,
};

const u8 gUnknown_0850DB02[] = {
    0x14,
    0x14,
    0x15,
    0x16,
    0x17,
    0x14,
    0x14,
    0x15,
    0x15,
};

const u8 gUnknown_0850DB0B[] = {
    0x18,
    0x18,
    0x19,
    0x1a,
    0x1b,
    0x18,
    0x18,
    0x19,
    0x19,
};

const u8 gUnknown_0850DB14[] = {
    0x1c,
    0x1c,
    0x1d,
    0x1e,
    0x1f,
    0x1c,
    0x1c,
    0x1d,
    0x1d,
};

const u8 gUnknown_0850DB1D[] = {
    0x20,
    0x20,
    0x21,
    0x22,
    0x23,
    0x20,
    0x20,
    0x21,
    0x21,
};

const u8 gUnknown_0850DB26[] = {
    0x24,
    0x24,
    0x25,
    0x26,
    0x27,
    0x24,
    0x24,
    0x25,
    0x25,
};

const u8 gUnknown_0850DB2F[] = {
    0x00,
    0x00,
    0x01,
    0x02,
    0x03,
    0x00,
    0x00,
    0x01,
    0x01,
};

const u8 gUnknown_0850DB38[] = {
    0x04,
    0x04,
    0x05,
    0x06,
    0x07,
    0x04,
    0x04,
    0x05,
    0x05,
};

const u8 gUnknown_0850DB41[] = {
    0x08,
    0x08,
    0x09,
    0x0a,
    0x0b,
    0x08,
    0x08,
    0x09,
    0x09,
};

const u8 gUnknown_0850DB4A[] = {
    0x14,
    0x14,
    0x15,
    0x16,
    0x17,
    0x14,
    0x14,
    0x15,
    0x15,
};

const u8 gUnknown_0850DB53[] = {
    0x08,
    0x08,
    0x07,
    0x09,
    0x0a,
    0x08,
    0x08,
    0x07,
    0x07,
};

bool8 (*const gOppositeDirectionBlockedMetatileFuncs[])(u8) = {
    MetatileBehavior_IsSouthBlocked,
    MetatileBehavior_IsNorthBlocked,
    MetatileBehavior_IsWestBlocked,
    MetatileBehavior_IsEastBlocked
};

bool8 (*const gDirectionBlockedMetatileFuncs[])(u8) = {
    MetatileBehavior_IsNorthBlocked,
    MetatileBehavior_IsSouthBlocked,
    MetatileBehavior_IsEastBlocked,
    MetatileBehavior_IsWestBlocked
};

const struct Coords16 gDirectionToVectors[] = {
    { 0,  0},
    { 0,  1},
    { 0, -1},
    {-1,  0},
    { 1,  0},
    {-1,  1},
    { 1,  1},
    {-1, -1},
    { 1, -1}
};

const u8 gUnknown_0850DBA0[] = {
    0x00,
    0x00,
    0x01,
    0x02,
    0x03,
};

const u8 gUnknown_0850DBA5[] = {
    0x04,
    0x04,
    0x05,
    0x06,
    0x07,
};

const u8 gUnknown_0850DBAA[] = {
    0x08,
    0x08,
    0x09,
    0x0a,
    0x0b,
};

const u8 gUnknown_0850DBAF[] = {
    0x15,
    0x15,
    0x16,
    0x17,
    0x18,
};

const u8 gUnknown_0850DBB4[] = {
    0x29,
    0x29,
    0x2a,
    0x2b,
    0x2c,
};

const u8 gUnknown_0850DBB9[] = {
    0x2d,
    0x2d,
    0x2e,
    0x2f,
    0x30,
};

const u8 gUnknown_0850DBBE[] = {
    0x31,
    0x31,
    0x32,
    0x33,
    0x34,
};

const u8 gUnknown_0850DBC3[] = {
    0x35,
    0x35,
    0x36,
    0x37,
    0x38,
};

const u8 gUnknown_0850DBC8[] = {
    0x0c,
    0x0c,
    0x0d,
    0x0e,
    0x0f,
};

const u8 gUnknown_0850DBCD[] = {
    0x46,
    0x46,
    0x47,
    0x48,
    0x49,
};

const u8 gUnknown_0850DBD2[] = {
    0x4b,
    0x4b,
    0x4a,
    0x4d,
    0x4c,
};

const u8 gUnknown_0850DBD7[] = {
    0x42,
    0x42,
    0x43,
    0x44,
    0x45,
};

const u8 gUnknown_0850DBDC[] = {
    0x3a,
    0x3a,
    0x3b,
    0x3c,
    0x3d,
};

const u8 gUnknown_0850DBE1[] = {
    0x19,
    0x19,
    0x1a,
    0x1b,
    0x1c,
};

const u8 gUnknown_0850DBE6[] = {
    0x1d,
    0x1d,
    0x1e,
    0x1f,
    0x20,
};

const u8 gUnknown_0850DBEB[] = {
    0x21,
    0x21,
    0x22,
    0x23,
    0x24,
};

const u8 gUnknown_0850DBF0[] = {
    0x25,
    0x25,
    0x26,
    0x27,
    0x28,
};

const u8 gUnknown_0850DBF5[] = {
    0x64,
    0x64,
    0x65,
    0x66,
    0x67,
};

const u8 gUnknown_0850DBFA[] = {
    0x68,
    0x68,
    0x69,
    0x6a,
    0x6b,
};

const u8 gUnknown_0850DBFF[] = {
    0x6c,
    0x6c,
    0x6d,
    0x6e,
    0x6f,
};

const u8 gUnknown_0850DC04[] = {
    0x70,
    0x70,
    0x71,
    0x72,
    0x73,
};

const u8 gUnknown_0850DC09[] = {
    0x74,
    0x74,
    0x75,
    0x76,
    0x77,
};

const u8 gUnknown_0850DC0E[] = {
    0x78,
    0x78,
    0x79,
    0x7a,
    0x7b,
};

const u8 gUnknown_0850DC13[] = {
    0x7c,
    0x7c,
    0x7d,
    0x7e,
    0x7f,
};

const u8 gUnknown_0850DC18[] = {
    0x80,
    0x80,
    0x81,
    0x82,
    0x83,
};

const u8 gUnknown_0850DC1D[] = {
    0x84,
    0x84,
    0x85,
    0x86,
    0x87,
};

const u8 gUnknown_0850DC22[] = {
    0x88,
    0x88,
    0x89,
    0x8a,
    0x8b,
};

const u8 gOppositeDirections[] = {
    DIR_NORTH,
    DIR_SOUTH,
    DIR_EAST,
    DIR_WEST,
    DIR_NORTHEAST,
    DIR_NORTHWEST,
    DIR_SOUTHEAST,
    DIR_SOUTHWEST,
};

const u8 gUnknown_0850DC2F[][4] = {
    {2, 1, 4, 3},
    {1, 2, 3, 4},
    {3, 4, 2, 1},
    {4, 3, 1, 2}
};

const u8 gUnknown_0850DC3F[][4] = {
    {2, 1, 4, 3},
    {1, 2, 3, 4},
    {4, 3, 1, 2},
    {3, 4, 2, 1}
};

#include "data/field_event_obj/movement_action_func_tables.h"

// Code

static void npc_clear_ids_and_state(struct MapObject *mapObject)
{
    *mapObject = (struct MapObject){};
    mapObject->localId = 0xFF;
    mapObject->mapNum = -1;
    mapObject->mapGroup = -1;
    mapObject->movementActionId = -1;
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
    ZeroAllLinkPlayerMapObjects();
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
        if (gMapObjects[i].active && gMapObjects[i].currentCoords.x == x && gMapObjects[i].currentCoords.y == y)
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
static u8 InitFieldObjectStateFromTemplate(struct MapObjectTemplate *template, u8 mapNum, u8 mapGroup)
{
    struct MapObject *mapObject;
    s16 x;
    s16 y;
    u8 slot;

    // mapNum and mapGroup are in the wrong registers (r7/r6 instead of r6/r7)
    if (GetAvailableFieldObjectSlot(template->localId, mapNum, mapGroup, &slot))
    {
        return NUM_FIELD_OBJECTS;
    }
    mapObject = &gMapObjects[slot];
    npc_clear_ids_and_state(mapObject);
    x = template->x + 7;
    y = template->y + 7;
    mapObject->active = TRUE;
    mapObject->triggerGroundEffectsOnMove = TRUE;
    mapObject->graphicsId = template->graphicsId;
    mapObject->movementType = template->movementType;
    mapObject->localId = template->localId;
    mapObject->mapNum = mapNum;
    mapObject->mapGroup = mapGroup;
    mapObject->initialCoords.x = x;
    mapObject->initialCoords.y = y;
    mapObject->currentCoords.x = x;
    mapObject->currentCoords.y = y;
    mapObject->previousCoords.x = x;
    mapObject->previousCoords.y = y;
    mapObject->currentElevation = template->elevation;
    mapObject->previousElevation = template->elevation;
    // For some reason, 0x0F is placed in r9, to be used later
    mapObject->range.as_nybbles.x = template->movementRangeX;
    mapObject->range.as_nybbles.y = template->movementRangeY;
    mapObject->trainerType = template->trainerType;
    mapObject->trainerRange_berryTreeId = template->trainerRange_berryTreeId;
    mapObject->previousMovementDirection = gInitialMovementTypeFacingDirections[template->movementType];
    FieldObjectSetDirection(mapObject, mapObject->previousMovementDirection);
    FieldObjectHandleDynamicGraphicsId(mapObject);

    if (gRangedMovementTypes[mapObject->movementType])
    {
        if ((mapObject->range.as_nybbles.x) == 0)
        {
            // r9 is invoked here
            mapObject->range.as_nybbles.x ++;
        }
        if ((mapObject->range.as_nybbles.y) == 0)
        {
            mapObject->range.as_nybbles.y ++;
        }
    }
    return slot;
}
#else
static NAKED u8 InitFieldObjectStateFromTemplate(struct MapObjectTemplate *template, u8 mapId, u8 mapGroupId)
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
                "\tldr r1, =gInitialMovementTypeFacingDirections\n"
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
                "\tldr r1, =gRangedMovementTypes\n"
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
    if (mapObject->movementType == 0x4c)
    {
        mapObject->invisible = TRUE;
    }
    *(u16 *)&spriteTemplate->paletteTag = 0xFFFF;
    spriteId = CreateSprite(spriteTemplate, 0, 0, 0);
    if (spriteId == MAX_SPRITES)
    {
        gMapObjects[mapObjectId].active = FALSE;
        return NUM_FIELD_OBJECTS;
    }
    sprite = &gSprites[spriteId];
    sub_8092FF0(mapObject->currentCoords.x + cameraX, mapObject->currentCoords.y + cameraY, &sprite->pos1.x, &sprite->pos1.y);
    sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
    sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
    sprite->pos1.x += 8;
    sprite->pos1.y += 16 + sprite->centerToCornerVecY;
    sprite->oam.paletteNum = paletteSlot;
    sprite->coordOffsetEnabled = TRUE;
    sprite->data[0] = mapObjectId;
    mapObject->spriteId = spriteId;
    mapObject->inanimate = graphicsInfo->inanimate;
    if (!mapObject->inanimate)
    {
        StartSpriteAnim(sprite, FieldObjectDirectionToImageAnimId(mapObject->facingDirection));
    }
    SetObjectSubpriorityByZCoord(mapObject->previousElevation, sprite, 1);
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
    mapObjectTemplate.movementRangeX = 0;
    mapObjectTemplate.movementRangeY = 0;
    mapObjectTemplate.trainerType = 0;
    mapObjectTemplate.trainerRange_berryTreeId = 0;
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
        sprite->data[0] = a1;
        sprite->data[1] = z;
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

            if (mapObject->active && !mapObject->isPlayer)
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

    if (mapObject->currentCoords.x >= left && mapObject->currentCoords.x <= right
        && mapObject->currentCoords.y >= top && mapObject->currentCoords.y <= bottom)
        return;
    if (mapObject->initialCoords.x >= left && mapObject->initialCoords.x <= right
        && mapObject->initialCoords.y >= top && mapObject->initialCoords.y <= bottom)
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
    MakeObjectTemplateFromFieldObjectGraphicsInfoWithCallbackIndex(mapObject->graphicsId, mapObject->movementType, &spriteTemplate, &subspriteTables);
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
        sub_8092FF0(x + mapObject->currentCoords.x, y + mapObject->currentCoords.y, &sprite->pos1.x, &sprite->pos1.y);
        sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
        sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
        sprite->pos1.x += 8;
        sprite->pos1.y += 16 + sprite->centerToCornerVecY;
        sprite->images = graphicsInfo->images;
        if (mapObject->movementType == 0x0b)
        {
            SetPlayerAvatarFieldObjectIdAndObjectId(mapObjectId, spriteId);
            mapObject->warpArrowSpriteId = sub_8154228();
        }
        if (subspriteTables != NULL)
        {
            SetSubspriteTables(sprite, subspriteTables);
        }
        sprite->oam.paletteNum = paletteSlot;
        sprite->coordOffsetEnabled = TRUE;
        sprite->data[0] = mapObjectId;
        mapObject->spriteId = spriteId;
        if (!mapObject->inanimate && mapObject->movementType != 0x0b)
        {
            StartSpriteAnim(sprite, FieldObjectDirectionToImageAnimId(mapObject->facingDirection));
        }
        sub_808E38C(mapObject);
        SetObjectSubpriorityByZCoord(mapObject->previousElevation, sprite, 1);
    }
}

/*static*/ void sub_808E38C(struct MapObject *mapObject)
{
    mapObject->singleMovementActive = FALSE;
    mapObject->triggerGroundEffectsOnMove = TRUE;
    mapObject->hasShadow = FALSE;
    mapObject->hasReflection = FALSE;
    mapObject->inShortGrass = FALSE;
    mapObject->inShallowFlowingWater = FALSE;
    mapObject->inSandPile = FALSE;
    mapObject->inHotSprings = FALSE;
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
    mapObject->inanimate = graphicsInfo->inanimate;
    mapObject->graphicsId = graphicsId;
    sub_8093038(mapObject->currentCoords.x, mapObject->currentCoords.y, &sprite->pos1.x, &sprite->pos1.y);
    sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
    sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
    sprite->pos1.x += 8;
    sprite->pos1.y += 16 + sprite->centerToCornerVecY;
    if (mapObject->trackedByCamera)
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
    if (!mapObject->inanimate)
    {
        StartSpriteAnim(&gSprites[mapObject->spriteId], FieldObjectDirectionToImageAnimId(mapObject->facingDirection));
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

    mapObject->invisible = TRUE;
    sprite->invisible = TRUE;
    berryStage = GetStageByBerryTreeId(mapObject->trainerRange_berryTreeId);
    if (berryStage != 0)
    {
        mapObject->invisible = FALSE;
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
        bard = GetCurrentMauvilleOldMan();
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
        gMapObjects[mapObjectId].invisible = state;
    }
}

void FieldObjectGetLocalIdAndMap(struct MapObject *mapObject, void *localId, void *mapNum, void *mapGroup)
{
    *(u8*)(localId) = mapObject->localId;
    *(u8*)(mapNum) = mapObject->mapNum;
    *(u8*)(mapGroup) = mapObject->mapGroup;
}

void sub_808E75C(s16 x, s16 y)
{
    u8 mapObjectId;
    struct MapObject *mapObject;

    mapObjectId = GetFieldObjectIdByXY(x, y);
    if (mapObjectId != NUM_FIELD_OBJECTS)
    {
        mapObject = &gMapObjects[mapObjectId];
        mapObject->triggerGroundEffectsOnMove = TRUE;
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
        mapObject->fixedPriority = TRUE;
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
        mapObject->fixedPriority = FALSE;
        mapObject->triggerGroundEffectsOnMove = TRUE;
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
    mapObject->previousCoords.x = mapObject->currentCoords.x;
    mapObject->previousCoords.y = mapObject->currentCoords.y;
    mapObject->currentCoords.x += x;
    mapObject->currentCoords.y += y;
}

void npc_coords_shift(struct MapObject *mapObject, s16 x, s16 y)
{
    mapObject->previousCoords.x = mapObject->currentCoords.x;
    mapObject->previousCoords.y = mapObject->currentCoords.y;
    mapObject->currentCoords.x = x;
    mapObject->currentCoords.y = y;
}

/*static*/ void npc_coords_set(struct MapObject *mapObject, s16 x, s16 y)
{
    mapObject->previousCoords.x = x;
    mapObject->previousCoords.y = y;
    mapObject->currentCoords.x = x;
    mapObject->currentCoords.y = y;
}

void sub_808EB08(struct MapObject *mapObject, s16 x, s16 y)
{
    struct Sprite *sprite;
    const struct MapObjectGraphicsInfo *graphicsInfo;

    sprite = &gSprites[mapObject->spriteId];
    graphicsInfo = GetFieldObjectGraphicsInfo(mapObject->graphicsId);
    npc_coords_set(mapObject, x, y);
    sub_8093038(mapObject->currentCoords.x, mapObject->currentCoords.y, &sprite->pos1.x, &sprite->pos1.y);
    sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
    sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
    sprite->pos1.x += 8;
    sprite->pos1.y += 16 + sprite->centerToCornerVecY;
    sub_808E38C(mapObject);
    if (mapObject->trackedByCamera)
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
    npc_coords_shift(mapObject, mapObject->currentCoords.x, mapObject->currentCoords.y);
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
                gMapObjects[i].initialCoords.x -= dx;
                gMapObjects[i].initialCoords.y -= dy;
                gMapObjects[i].currentCoords.x -= dx;
                gMapObjects[i].currentCoords.y -= dy;
                gMapObjects[i].previousCoords.x -= dx;
                gMapObjects[i].previousCoords.y -= dy;
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
            if (gMapObjects[i].currentCoords.x == x && gMapObjects[i].currentCoords.y == y && FieldObjectDoesZCoordMatch(&gMapObjects[i], z))
            {
                return i;
            }
        }
    }
    return NUM_FIELD_OBJECTS;
}

static bool8 FieldObjectDoesZCoordMatch(struct MapObject *mapObject, u8 z)
{
    if (mapObject->currentElevation != 0 && z != 0 && mapObject->currentElevation != z)
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

    spriteId = CreateSprite(&gCameraSpriteTemplate, 0, 0, 4);
    gSprites[spriteId].invisible = TRUE;
    gSprites[spriteId].data[0] = linkedSpriteId;
    return spriteId;
}

static void ObjectCB_CameraObject(struct Sprite *sprite)
{
    void (*callbacks[ARRAY_COUNT(gCameraObjectFuncs)])(struct Sprite *);

    memcpy(callbacks, gCameraObjectFuncs, sizeof gCameraObjectFuncs);
    callbacks[sprite->data[1]](sprite);
}

static void CameraObject_0(struct Sprite *sprite)
{
    sprite->pos1.x = gSprites[sprite->data[0]].pos1.x;
    sprite->pos1.y = gSprites[sprite->data[0]].pos1.y;
    sprite->invisible = TRUE;
    sprite->data[1] = 1;
    CameraObject_1(sprite);
}

static void CameraObject_1(struct Sprite *sprite)
{
    s16 x;
    s16 y;

    y = gSprites[sprite->data[0]].pos1.y;
    x = gSprites[sprite->data[0]].pos1.x;
    sprite->data[2] = x - sprite->pos1.x;
    sprite->data[3] = y - sprite->pos1.y;
    sprite->pos1.x = x;
    sprite->pos1.y = y;
}

static void CameraObject_2(struct Sprite *sprite)
{
    sprite->pos1.x = gSprites[sprite->data[0]].pos1.x;
    sprite->pos1.y = gSprites[sprite->data[0]].pos1.y;
    sprite->data[2] = 0;
    sprite->data[3] = 0;
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
        cameraObject->data[1] = 0;
        cameraObject->callback(cameraObject);
    }
}

void CameraObjectSetFollowedObjectId(u8 objectId)
{
    struct Sprite *cameraObject;

    cameraObject = FindCameraObject();
    if (cameraObject != NULL)
    {
        cameraObject->data[0] = objectId;
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
    return cameraObject->data[0];
}

void CameraObjectReset2(void)
{
    FindCameraObject()->data[1] = 2;
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
    mapObject->previousMovementDirection = mapObject->facingDirection;
    if (!mapObject->facingDirectionLocked)
    {
        d2 = direction;
        mapObject->facingDirection = d2;
    }
    mapObject->movementDirection = direction;
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
        mapHeader = Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum);
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
        mapObjectTemplate->x = mapObject->currentCoords.x - 7;
        mapObjectTemplate->y = mapObject->currentCoords.y - 7;
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

void sub_808F28C(u8 localId, u8 mapNum, u8 mapGroup, u8 decorCat)
{
    u8 mapObjectId;

    if (!TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &mapObjectId))
    {
        switch (decorCat)
        {
            case DECORCAT_DOLL:
                sub_808F228(&gMapObjects[mapObjectId], EventScript_2766A2);
                break;
            case DECORCAT_CUSHION:
                sub_808F228(&gMapObjects[mapObjectId], EventScript_2766A6);
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
// file boundary?

null_object_step(NoMovement1, FALSE)

field_object_step(GoRandomDirections, gUnknown_0850D6F4)

bool8 sub_808F44C(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_808F460(struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_808F48C(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (!FieldObjectExecRegularAnim(mapObject, sprite))
    {
        return FALSE;
    }
    SetFieldObjectStepTimer(sprite, gMovementDelaysMedium[Random() & 0x03]);
    sprite->data[1] = 3;
    return TRUE;
}

bool8 sub_808F4C8(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite))
    {
        sprite->data[1] = 4;
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
    sprite->data[1] = 5;
    if (npc_block_way__next_tile(mapObject, chosenDirection))
    {
        sprite->data[1] = 1;
    }
    return TRUE;
}

bool8 sub_808F534(struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetGoSpeed0AnimId(mapObject->movementDirection));
    mapObject->singleMovementActive = TRUE;
    sprite->data[1] = 6;
    return TRUE;
}

bool8 sub_808F564(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        mapObject->singleMovementActive = FALSE;
        sprite->data[1] = 1;
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
    objX = mapObject->currentCoords.x;
    objY = mapObject->currentCoords.y;
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
    dx -= mapObject->currentCoords.x;
    dy -= mapObject->currentCoords.y;
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
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_808F99C(struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_808F9C8(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, gMovementDelaysMedium[Random() & 0x03]);
        mapObject->singleMovementActive = FALSE;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_808FA0C(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data[1] = 4;
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
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(RandomlyGoNorthOrSouth, gUnknown_0850D754)

bool8 sub_808FAC8(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_808FADC(struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_808FB08(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (!FieldObjectExecRegularAnim(mapObject, sprite))
    {
        return FALSE;
    }
    SetFieldObjectStepTimer(sprite, gMovementDelaysMedium[Random() & 0x03]);
    sprite->data[1] = 3;
    return TRUE;
}

bool8 sub_808FB44(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite))
    {
        sprite->data[1] = 4;
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
    sprite->data[1] = 5;
    if (npc_block_way__next_tile(mapObject, direction))
    {
        sprite->data[1] = 1;
    }
    return TRUE;
}

bool8 sub_808FBB0(struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetGoSpeed0AnimId(mapObject->movementDirection));
    mapObject->singleMovementActive = TRUE;
    sprite->data[1] = 6;
    return TRUE;
}

bool8 sub_808FBE0(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        mapObject->singleMovementActive = FALSE;
        sprite->data[1] = 1;
    }
    return FALSE;
}

field_object_step(RandomlyGoEastOrWest, gUnknown_0850D774)

bool8 sub_808FC4C(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_808FC60(struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_808FC8C(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (!FieldObjectExecRegularAnim(mapObject, sprite))
    {
        return FALSE;
    }
    SetFieldObjectStepTimer(sprite, gMovementDelaysMedium[Random() & 0x03]);
    sprite->data[1] = 3;
    return TRUE;
}

bool8 sub_808FCC8(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite))
    {
        sprite->data[1] = 4;
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
    sprite->data[1] = 5;
    if (npc_block_way__next_tile(mapObject, direction))
    {
        sprite->data[1] = 1;
    }
    return TRUE;
}

bool8 sub_808FD34(struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetGoSpeed0AnimId(mapObject->movementDirection));
    mapObject->singleMovementActive = TRUE;
    sprite->data[1] = 6;
    return TRUE;
}

bool8 sub_808FD64(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        mapObject->singleMovementActive = FALSE;
        sprite->data[1] = 1;
    }
    return FALSE;
}

field_object_step(FaceFixedDirection, gUnknown_0850D794)

bool8 sub_808FDD0(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_808FDFC(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        sprite->data[1] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_808FE1C(struct MapObject *mapObject, struct Sprite *sprite)
{
    mapObject->singleMovementActive = FALSE;
    return FALSE;
}

static bool8 FieldObjectCB2_BerryTree(struct MapObject *mapObject, struct Sprite *sprite);
extern bool8 (*const gUnknown_0850D7A0[])(struct MapObject *mapObject, struct Sprite *sprite);
void FieldObjectCB_BerryTree(struct Sprite *sprite)
{
    struct MapObject *mapObject;

    mapObject = &gMapObjects[sprite->data[0]];
    if (!(sprite->data[7] & 0x0001))
    {
        get_berry_tree_graphics(mapObject, sprite);
        sprite->data[7] |= 0x0001;
    }
    FieldObjectStep(mapObject, sprite, FieldObjectCB2_BerryTree);
}
static bool8 FieldObjectCB2_BerryTree(struct MapObject *mapObject, struct Sprite *sprite)
{
    return gUnknown_0850D7A0[sprite->data[1]](mapObject, sprite);
}

bool8 do_berry_tree_growth_sparkle_1 (struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 berryStage;

    npc_reset(mapObject, sprite);
    mapObject->invisible = TRUE;
    sprite->invisible = TRUE;
    berryStage = GetStageByBerryTreeId(mapObject->trainerRange_berryTreeId);
    if (berryStage == 0)
    {
        if (!(sprite->data[7] & 0x0004) && sprite->animNum == 4)
        {
            gFieldEffectArguments[0] = mapObject->currentCoords.x;
            gFieldEffectArguments[1] = mapObject->currentCoords.y;
            gFieldEffectArguments[2] = sprite->subpriority - 1;
            gFieldEffectArguments[3] = sprite->oam.priority;
            FieldEffectStart(FLDEFF_BERRY_TREE_GROWTH_SPARKLE);
            sprite->animNum = berryStage;
        }
        return FALSE;
    }
    mapObject->invisible = FALSE;
    sprite->invisible = FALSE;
    berryStage --;
    if (sprite->animNum != berryStage)
    {
        sprite->data[1] = 2;
        return TRUE;
    }
    get_berry_tree_graphics(mapObject, sprite);
    FieldObjectSetRegularAnim(mapObject, sprite, 0x39);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_808FF48 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        sprite->data[1] = 0;
        return TRUE;
    }
    return FALSE;
}

bool8 do_berry_tree_growth_sparkle_2 (struct MapObject *mapObject, struct Sprite *sprite)
{
    mapObject->singleMovementActive = TRUE;
    sprite->data[1] = 3;
    sprite->data[2] = 0;
    sprite->data[7] |= 0x0002;
    gFieldEffectArguments[0] = mapObject->currentCoords.x;
    gFieldEffectArguments[1] = mapObject->currentCoords.y;
    gFieldEffectArguments[2] = sprite->subpriority - 1;
    gFieldEffectArguments[3] = sprite->oam.priority;
    FieldEffectStart(FLDEFF_BERRY_TREE_GROWTH_SPARKLE);
    return TRUE;
}

bool8 sub_808FFB4 (struct MapObject *mapObject, struct Sprite *sprite)
{
    sprite->data[2] ++;
    mapObject->invisible = (sprite->data[2] & 0x02) >> 1;
    sprite->animPaused = TRUE;
    if (sprite->data[2] > 64)
    {
        get_berry_tree_graphics(mapObject, sprite);
        sprite->data[1] = 4;
        sprite->data[2] = 0;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8090004 (struct MapObject *mapObject, struct Sprite *sprite)
{
    sprite->data[2] ++;
    mapObject->invisible = (sprite->data[2] & 0x02) >> 1;
    sprite->animPaused = TRUE;
    if (sprite->data[2] > 64)
    {
        sprite->data[1] = 0;
        sprite->data[7] &= ~0x0002;
        return TRUE;
    }
    return FALSE;
}

field_object_step(RandomlyLookNorthOrSouth, gUnknown_0850D7B4)

bool8 sub_8090094 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_80900A8 (struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_80900D4 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, gMovementDelaysMedium[Random() & 0x03]);
        mapObject->singleMovementActive = FALSE;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_8090118 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data[1] = 4;
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
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(RandomlyLookEastOrWest, gUnknown_0850D7C8)

bool8 sub_80901D4 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_80901E8 (struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8090214 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, gMovementDelaysMedium[Random() & 0x03]);
        mapObject->singleMovementActive = FALSE;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_8090258 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data[1] = 4;
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
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(RandomlyLookNorthOrWest, gUnknown_0850D7DC)

bool8 sub_8090314 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_8090328 (struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8090354 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, gMovementDelaysShort[Random() & 0x03]);
        mapObject->singleMovementActive = FALSE;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_8090398 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data[1] = 4;
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
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(RandomlyLookNorthOrEast, gUnknown_0850D7F4)

bool8 sub_8090454 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_8090468 (struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8090494 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, gMovementDelaysShort[Random() & 0x03]);
        mapObject->singleMovementActive = FALSE;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_80904D8 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data[1] = 4;
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
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(RandomlyLookSouthOrWest, gUnknown_0850D80C)

bool8 sub_8090594 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_80905A8 (struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_80905D4 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, gMovementDelaysShort[Random() & 0x03]);
        mapObject->singleMovementActive = FALSE;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_8090618 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data[1] = 4;
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
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(RandomlyLookSouthOrEast, gUnknown_0850D824)

bool8 sub_80906D4 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_80906E8 (struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8090714 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, gMovementDelaysShort[Random() & 0x03]);
        mapObject->singleMovementActive = FALSE;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_8090758 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data[1] = 4;
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
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(RandomlyLookNorthOrSouthOrWest, gUnknown_0850D83C)

bool8 sub_8090814 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_8090828 (struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8090854 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, gMovementDelaysShort[Random() & 0x03]);
        mapObject->singleMovementActive = FALSE;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_8090898 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data[1] = 4;
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
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(RandomlyLookNorthOrSouthOrEast, gUnknown_0850D854)

bool8 sub_8090954 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_8090968 (struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8090994 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, gMovementDelaysShort[Random() & 0x03]);
        mapObject->singleMovementActive = FALSE;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_80909D8 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data[1] = 4;
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
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(RandomlyLookNorthOrEastOrWest, gUnknown_0850D86C)

bool8 sub_8090A94 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_8090AA8 (struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8090AD4 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, gMovementDelaysShort[Random() & 0x03]);
        mapObject->singleMovementActive = FALSE;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_8090B18 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data[1] = 4;
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
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(RandomlyLookSouthOrEastOrWest, gUnknown_0850D884)

bool8 sub_8090BD4 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_8090BE8 (struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8090C14 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, gMovementDelaysShort[Random() & 0x03]);
        mapObject->singleMovementActive = FALSE;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_8090C58 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data[1] = 4;
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
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(LookAroundCounterclockwise, gUnknown_0850D89C)

bool8 sub_8090D14 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_8090D40 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, 48);
        sprite->data[1] = 2;
    }
    return FALSE;
}

bool8 sub_8090D64 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data[1] = 3;
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
        direction = directions[mapObject->facingDirection];
    }
    FieldObjectSetDirection(mapObject, direction);
    sprite->data[1] = 0;
    return TRUE;
}

field_object_step(LookAroundClockwise, gUnknown_0850D8B4)

bool8 sub_8090E18 (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_8090E44 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        SetFieldObjectStepTimer(sprite, 48);
        sprite->data[1] = 2;
    }
    return FALSE;
}

bool8 sub_8090E68 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (RunFieldObjectStepTimer(sprite) || FieldObjectIsTrainerAndCloseToPlayer(mapObject))
    {
        sprite->data[1] = 3;
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
        direction = directions[mapObject->facingDirection];
    }
    FieldObjectSetDirection(mapObject, direction);
    sprite->data[1] = 0;
    return TRUE;
}

field_object_step(AlternatelyGoInOppositeDirections, gUnknown_0850D8CC)

bool8 sub_8090F1C (struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_8090F30 (struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 direction;

    direction = gInitialMovementTypeFacingDirections[mapObject->movementType];
    if (mapObject->directionSequenceIndex)
    {
        direction = GetOppositeDirection(direction);
    }
    FieldObjectSetDirection(mapObject, direction);
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8090F68 (struct MapObject *mapObject, struct Sprite *sprite)
{
    bool8 blockingWay;
    u8 animId;

    if (mapObject->directionSequenceIndex && mapObject->initialCoords.x == mapObject->currentCoords.x && mapObject->initialCoords.y == mapObject->currentCoords.y)
    {
        mapObject->directionSequenceIndex = 0;
        FieldObjectSetDirection(mapObject, GetOppositeDirection(mapObject->movementDirection));
    }
    blockingWay = npc_block_way__next_tile(mapObject, mapObject->movementDirection);
    animId = GetGoSpeed0AnimId(mapObject->movementDirection);
    if (blockingWay == TRUE)
    {
        mapObject->directionSequenceIndex ++;
        FieldObjectSetDirection(mapObject, GetOppositeDirection(mapObject->movementDirection));
        animId = GetGoSpeed0AnimId(mapObject->movementDirection);
        blockingWay = npc_block_way__next_tile(mapObject, mapObject->movementDirection);
    }
    if (blockingWay)
    {
        animId = GetStepInPlaceDelay16AnimId(mapObject->facingDirection);
    }
    FieldObjectSetRegularAnim(mapObject, sprite, animId);
    mapObject->singleMovementActive = TRUE;
    sprite->data[1] = 3;
    return TRUE;
}

bool8 sub_8091020 (struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        mapObject->singleMovementActive = FALSE;
        sprite->data[1] = 1;
    }
    return FALSE;
}

bool8 sub_8091048(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MoveFieldObjectInNextDirectionInSequence(struct MapObject *mapObject, struct Sprite *sprite, u8 *route)
{
    u8 blockingWay;
    u8 animId;

    if (mapObject->directionSequenceIndex == 3 && mapObject->initialCoords.x == mapObject->currentCoords.x && mapObject->initialCoords.y == mapObject->currentCoords.y)
    {
        mapObject->directionSequenceIndex = 0;
    }
    FieldObjectSetDirection(mapObject, route[mapObject->directionSequenceIndex]);
    animId = GetGoSpeed0AnimId(mapObject->movementDirection);
    blockingWay = npc_block_way__next_tile(mapObject, mapObject->movementDirection);
    if (blockingWay == TRUE)
    {
        mapObject->directionSequenceIndex ++;
        FieldObjectSetDirection(mapObject, route[mapObject->directionSequenceIndex]);
        animId = GetGoSpeed0AnimId(mapObject->movementDirection);
        blockingWay = npc_block_way__next_tile(mapObject, mapObject->movementDirection);
    }
    if (blockingWay)
    {
        animId = GetStepInPlaceDelay16AnimId(mapObject->facingDirection);
    }
    FieldObjectSetRegularAnim(mapObject, sprite, animId);
    mapObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8091110(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        mapObject->singleMovementActive = FALSE;
        sprite->data[1] = 1;
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
    if (mapObject->directionSequenceIndex == 0)
    {
        mapObject->directionSequenceIndex = player_get_direction_lower_nybble();
    }
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_8091EC0(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (gMapObjects[gPlayerAvatar.mapObjectId].movementActionId == 0xFF || gPlayerAvatar.tileTransitionState == 2)
    {
        return FALSE;
    }
    return gUnknown_0850DA64[player_get_x22()](mapObject, sprite, player_get_direction_upper_nybble(), NULL);
}

bool8 sub_8091F20(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        mapObject->singleMovementActive = FALSE;
        sprite->data[1] = 1;
    }
    return FALSE;
}

bool8 sub_8091F48(struct MapObject *mapObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    return FALSE;
}

bool8 sub_8091F4C(struct MapObject *mapObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(state_to_direction(gInitialMovementTypeFacingDirections[mapObject->movementType], mapObject->directionSequenceIndex, playerDirection)));
    mapObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
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
            direction = state_to_direction(gInitialMovementTypeFacingDirections[mapObject->movementType], mapObject->directionSequenceIndex, direction);
            FieldObjectMoveDestCoords(mapObject, direction, &x, &y);
            FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(direction));
            mapObject->singleMovementActive = TRUE;
            sprite->data[1] = 2;
            return TRUE;
        }
    }
    else
    {
        direction = state_to_direction(gInitialMovementTypeFacingDirections[mapObject->movementType], mapObject->directionSequenceIndex, direction);
    }
    FieldObjectMoveDestCoords(mapObject, direction, &x, &y);
    FieldObjectSetRegularAnim(mapObject, sprite, GetGoSpeed0AnimId(direction));
    if (npc_block_way(mapObject, x, y, direction) || (tileCB != NULL && !tileCB(MapGridGetMetatileBehaviorAt(x, y))))
    {
        FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(direction));
    }
    mapObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_80920A4(struct MapObject *mapObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[mapObject->movementType], mapObject->directionSequenceIndex, direction);
    FieldObjectMoveDestCoords(mapObject, direction, &x, &y);
    FieldObjectSetRegularAnim(mapObject, sprite, GetGoSpeed1AnimId(direction));
    if (npc_block_way(mapObject, x, y, direction) || (tileCB != NULL && !tileCB(MapGridGetMetatileBehaviorAt(x, y))))
    {
        FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(direction));
    }
    mapObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_809215C(struct MapObject *mapObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[mapObject->movementType], mapObject->directionSequenceIndex, direction);
    FieldObjectMoveDestCoords(mapObject, direction, &x, &y);
    FieldObjectSetRegularAnim(mapObject, sprite, GetGoSpeed3AnimId(direction));
    if (npc_block_way(mapObject, x, y, direction) || (tileCB != NULL && !tileCB(MapGridGetMetatileBehaviorAt(x, y))))
    {
        FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(direction));
    }
    mapObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8092214(struct MapObject *mapObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[mapObject->movementType], mapObject->directionSequenceIndex, direction);
    FieldObjectMoveDestCoords(mapObject, direction, &x, &y);
    FieldObjectSetRegularAnim(mapObject, sprite, sub_8093438(direction));
    if (npc_block_way(mapObject, x, y, direction) || (tileCB != NULL && !tileCB(MapGridGetMetatileBehaviorAt(x, y))))
    {
        FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(direction));
    }
    mapObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 cph_IM_DIFFERENT(struct MapObject *mapObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    u32 direction;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[mapObject->movementType], mapObject->directionSequenceIndex, direction);
    FieldObjectSetRegularAnim(mapObject, sprite, sub_80934BC(direction));
    mapObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8092314(struct MapObject *mapObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[mapObject->movementType], mapObject->directionSequenceIndex, direction);
    FieldObjectMoveDestCoords(mapObject, direction, &x, &y);
    FieldObjectSetRegularAnim(mapObject, sprite, sub_8093514(direction));
    if (npc_block_way(mapObject, x, y, direction) || (tileCB != NULL && !tileCB(MapGridGetMetatileBehaviorAt(x, y))))
    {
        FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(direction));
    }
    mapObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 oac_hopping(struct MapObject *mapObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[mapObject->movementType], mapObject->directionSequenceIndex, direction);
    x = mapObject->currentCoords.x;
    y = mapObject->currentCoords.y;
    sub_8092F88(direction, &x, &y, 2, 2);
    FieldObjectSetRegularAnim(mapObject, sprite, GetJumpLedgeAnimId(direction));
    if (npc_block_way(mapObject, x, y, direction) || (tileCB != NULL && !tileCB(MapGridGetMetatileBehaviorAt(x, y))))
    {
        FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(direction));
    }
    mapObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

field_object_step(CopyPlayer2, gUnknown_0850DA90)

bool8 mss_08062EA4(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (gMapObjects[gPlayerAvatar.mapObjectId].movementActionId == 0xFF || gPlayerAvatar.tileTransitionState == 2)
    {
        return FALSE;
    }
    return gUnknown_0850DA64[player_get_x22()](mapObject, sprite, player_get_direction_upper_nybble(), MetatileBehavior_IsPokeGrass);
}

bool8 sub_80925AC(struct MapObject *, struct Sprite *);

void FieldObjectCB_TreeDisguise(struct Sprite *sprite)
{
    struct MapObject *mapObject;

    mapObject = &gMapObjects[sprite->data[0]];
    if (mapObject->directionSequenceIndex == 0 || (mapObject->directionSequenceIndex == 1 && !sprite->data[7]))
    {
        FieldObjectGetLocalIdAndMap(mapObject, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
        mapObject->fieldEffectSpriteId = FieldEffectStart(FLDEFF_TREE_DISGUISE);
        mapObject->directionSequenceIndex = 1;
        sprite->data[7] ++;
    }
    FieldObjectStep(&gMapObjects[sprite->data[0]], sprite, sub_80925AC);
}

bool8 sub_80925AC(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    return FALSE;
}

void FieldObjectCB_MountainDisguise(struct Sprite *sprite)
{
    struct MapObject *mapObject;

    mapObject = &gMapObjects[sprite->data[0]];
    if (mapObject->directionSequenceIndex == 0 || (mapObject->directionSequenceIndex == 1 && !sprite->data[7]))
    {
        FieldObjectGetLocalIdAndMap(mapObject, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
        mapObject->fieldEffectSpriteId = FieldEffectStart(FLDEFF_MOUNTAIN_DISGUISE);
        mapObject->directionSequenceIndex = 1;
        sprite->data[7] ++;
    }
    FieldObjectStep(&gMapObjects[sprite->data[0]], sprite, sub_80925AC);
}

extern bool8 (*const gUnknown_0850DA9C[])(struct MapObject *, struct Sprite *);
bool8 sub_809268C(struct MapObject *, struct Sprite *);

void FieldObjectCB_Hidden1(struct Sprite *sprite)
{
    if (!sprite->data[7])
    {
        gMapObjects[sprite->data[0]].fixedPriority = TRUE;
        sprite->subspriteMode = 2;
        sprite->oam.priority = 3;
        sprite->data[7] ++;
    }
    FieldObjectStep(&gMapObjects[sprite->data[0]], sprite, sub_809268C);
}

bool8 sub_809268C(struct MapObject *mapObject, struct Sprite *sprite)
{
    return gUnknown_0850DA9C[sprite->data[1]](mapObject, sprite);
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
        sprite->data[1] = 0;
    }
    return FALSE;
}

field_object_step(WalkInPlace1, gUnknown_0850DAA0)

bool8 sub_8092718(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    FieldObjectSetRegularAnim(mapObject, sprite, GetStepInPlaceDelay16AnimId(mapObject->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(WalkInPlace4, gUnknown_0850DAA8)

bool8 sub_8092788(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    FieldObjectSetRegularAnim(mapObject, sprite, GetStepInPlaceDelay32AnimId(mapObject->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(WalkInPlace2, gUnknown_0850DAB0)

bool8 sub_80927F8(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    FieldObjectSetRegularAnim(mapObject, sprite, GetStepInPlaceDelay8AnimId(mapObject->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(WalkInPlace3, gUnknown_0850DAB8)

bool8 sub_8092868(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    FieldObjectSetRegularAnim(mapObject, sprite, GetStepInPlaceDelay4AnimId(mapObject->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(Hidden2, gUnknown_0850DAC0)

bool8 sub_80928D8(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_reset(mapObject, sprite);
    FieldObjectSetRegularAnim(mapObject, sprite, GetFaceDirectionAnimId(mapObject->facingDirection));
    mapObject->invisible = TRUE;
    sprite->data[1] = 1;
    return TRUE;
}
bool8 sub_809290C(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (FieldObjectExecRegularAnim(mapObject, sprite))
    {
        sprite->data[1] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_809292C(struct MapObject *mapObject, struct Sprite *sprite)
{
    mapObject->singleMovementActive = FALSE;
    return FALSE;
}

void npc_reset(struct MapObject *mapObject, struct Sprite *sprite)
{
    mapObject->singleMovementActive = FALSE;
    mapObject->heldMovementActive = FALSE;
    mapObject->heldMovementFinished = FALSE;
    mapObject->movementActionId = 0xFF;
    sprite->data[1] = 0;
}

#define dirn2anim(name, table)\
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

    if (!mapObject->inanimate)
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

    if (!mapObject->inanimate)
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

void npc_set_running_behaviour_etc(struct MapObject *mapObject, u8 movementType)
{
    mapObject->movementType = movementType;
    mapObject->directionSequenceIndex = 0;
    mapObject->playerCopyableMovement = 0;
    gSprites[mapObject->spriteId].callback = gUnknown_08505438[movementType];
    gSprites[mapObject->spriteId].data[1] = 0;
}

dirn2anim(npc_running_behaviour_by_direction, gUnknown_0850DB53)

u8 npc_block_way__next_tile(struct MapObject *mapObject, u8 direction)
{
    s16 x;
    s16 y;

    x = mapObject->currentCoords.x;
    y = mapObject->currentCoords.y;
    MoveCoords(direction, &x, &y);
    return npc_block_way(mapObject, x, y, direction);
}

u8 npc_block_way(struct MapObject *mapObject, s16 x, s16 y, u32 dirn)
{
    u8 direction;

    direction = dirn;
    if (IsCoordOutsideFieldObjectMovementRect(mapObject, x, y))
    {
        return 1;
    }
    if (MapGridIsImpassableAt(x, y) || GetMapBorderIdAt(x, y) == -1 || IsMetatileDirectionallyImpassable(mapObject, x, y, direction))
    {
        return 2;
    }
    if (mapObject->trackedByCamera && !CanCameraMoveInDirection(direction))
    {
        return 2;
    }
    if (IsZCoordMismatchAt(mapObject->currentElevation, x, y))
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
    if (IsCoordOutsideFieldObjectMovementRect(mapObject, x, y))
    {
        retval |= 1;
    }
    if (MapGridIsImpassableAt(x, y) || GetMapBorderIdAt(x, y) == -1 || IsMetatileDirectionallyImpassable(mapObject, x, y, direction) || (mapObject->trackedByCamera && !CanCameraMoveInDirection(direction)))
    {
        retval |= 2;
    }
    if (IsZCoordMismatchAt(mapObject->currentElevation, x, y))
    {
        retval |= 4;
    }
    if (CheckForCollisionBetweenFieldObjects(mapObject, x, y))
    {
        retval |= 8;
    }
    return retval;
}

static bool8 IsCoordOutsideFieldObjectMovementRect(struct MapObject *mapObject, s16 x, s16 y)
{
    s16 left;
    s16 right;
    s16 top;
    s16 bottom;

    if (mapObject->range.as_nybbles.x != 0)
    {
        left = mapObject->initialCoords.x - mapObject->range.as_nybbles.x;
        right = mapObject->initialCoords.x + mapObject->range.as_nybbles.x;
        if (left > x || right < x)
        {
            return TRUE;
        }
    }
    if (mapObject->range.as_nybbles.y != 0)
    {
        top = mapObject->initialCoords.y - mapObject->range.as_nybbles.y;
        bottom = mapObject->initialCoords.y + mapObject->range.as_nybbles.y;
        if (top > y || bottom < y)
        {
            return TRUE;
        }
    }
    return FALSE;
}

static bool8 IsMetatileDirectionallyImpassable(struct MapObject *mapObject, s16 x, s16 y, u8 direction)
{
    if (gOppositeDirectionBlockedMetatileFuncs[direction - 1](mapObject->currentMetatileBehavior) || gDirectionBlockedMetatileFuncs[direction - 1](MapGridGetMetatileBehaviorAt(x, y)))
    {
        return TRUE;
    }
    return FALSE;
}

static bool8 CheckForCollisionBetweenFieldObjects(struct MapObject *mapObject, s16 x, s16 y)
{
    u8 i;
    struct MapObject *curObject;

    for (i = 0; i < NUM_FIELD_OBJECTS; i ++)
    {
        curObject = &gMapObjects[i];
        if (curObject->active && curObject != mapObject)
        {
            if ((curObject->currentCoords.x == x && curObject->currentCoords.y == y) || (curObject->previousCoords.x == x && curObject->previousCoords.y == y))
            {
                if (AreZCoordsCompatible(mapObject->currentElevation, curObject->currentElevation))
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

    if (!TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &mapObjectId) && gSprites[gMapObjects[mapObjectId].spriteId].data[7] & 0x02)
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
        gSprites[gMapObjects[mapObjectId].spriteId].data[7] |= 0x04;
    }
}

void MoveCoords(u8 direction, s16 *x, s16 *y)
{
    *x += gDirectionToVectors[direction].x;
    *y += gDirectionToVectors[direction].y;
}

void sub_8092F60(u8 direction, s16 *x, s16 *y)
{
    *x += gDirectionToVectors[direction].x << 4;
    *y += gDirectionToVectors[direction].y << 4;
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
    cur_x = gDirectionToVectors[direction].x;
    if (cur_x > 0)
    {
        *x += dx_2;
    }
    if (cur_x < 0)
    {
        *x -= dx_2;
    }
    cur_y = gDirectionToVectors[direction].y;
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
    *x = mapObject->currentCoords.x;
    *y = mapObject->currentCoords.y;
    MoveCoords(direction, x, y);
}

// file boundary?

bool8 FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive(struct MapObject *mapObject)
{
    if (mapObject->singleMovementActive || mapObject->heldMovementActive)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 FieldObjectIsSpecialAnimActive(struct MapObject *mapObject)
{
    if (mapObject->heldMovementActive && mapObject->movementActionId != 0xFF)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 FieldObjectSetSpecialAnim(struct MapObject *mapObject, u8 specialAnimId)
{
    if (FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive(mapObject))
    {
        return TRUE;
    }
    npc_sync_anim_pause_bits(mapObject);
    mapObject->movementActionId = specialAnimId;
    mapObject->heldMovementActive = TRUE;
    mapObject->heldMovementFinished = FALSE;
    gSprites[mapObject->spriteId].data[2] = 0;
    return FALSE;
}

void FieldObjectForceSetSpecialAnim(struct MapObject *mapObject, u8 specialAnimId)
{
    FieldObjectClearAnimIfSpecialAnimActive(mapObject);
    FieldObjectSetSpecialAnim(mapObject, specialAnimId);
}

void FieldObjectClearAnimIfSpecialAnimActive(struct MapObject *mapObject)
{
    if (mapObject->heldMovementActive)
    {
        FieldObjectClearAnim(mapObject);
    }
}

void FieldObjectClearAnim(struct MapObject *mapObject)
{
    mapObject->movementActionId = 0xFF;
    mapObject->heldMovementActive = FALSE;
    mapObject->heldMovementFinished = FALSE;
    gSprites[mapObject->spriteId].data[1] = 0;
    gSprites[mapObject->spriteId].data[2] = 0;
}

u8 FieldObjectCheckIfSpecialAnimFinishedOrInactive(struct MapObject *mapObject)
{
    if (mapObject->heldMovementActive)
    {
        return mapObject->heldMovementFinished;
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
    if (mapObject->heldMovementActive)
    {
        return mapObject->movementActionId;
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
    else if (!mapObject->frozen)
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
dirn2anim_2(GetSimpleGoAnimId, gUnknown_0850DBA5);
dirn2anim_2(GetGoSpeed0AnimId, gUnknown_0850DBAA);
dirn2anim_2(GetGoSpeed1AnimId, gUnknown_0850DBAF);
dirn2anim_2(GetGoSpeed2AnimId, gUnknown_0850DBB4);
dirn2anim_2(GetGoSpeed3AnimId, gUnknown_0850DBB9);
dirn2anim_2(sub_8093438, gUnknown_0850DBBE);
dirn2anim_2(GetRunAnimId, gUnknown_0850DBC3);
dirn2anim_2(GetJumpLedgeAnimId, gUnknown_0850DBC8);
dirn2anim_2(sub_80934BC, gUnknown_0850DBCD);
dirn2anim_2(sub_80934E8, gUnknown_0850DBD2);
dirn2anim_2(sub_8093514, gUnknown_0850DBD7);
dirn2anim_2(sub_8093540, gUnknown_0850DBDC);
dirn2anim_2(GetStepInPlaceDelay32AnimId, gUnknown_0850DBE1);
dirn2anim_2(GetStepInPlaceDelay16AnimId, gUnknown_0850DBE6);
dirn2anim_2(GetStepInPlaceDelay8AnimId, gUnknown_0850DBEB);
dirn2anim_2(GetStepInPlaceDelay4AnimId, gUnknown_0850DBF0);

bool8 FieldObjectFaceOppositeDirection(struct MapObject *mapObject, u8 direction)
{
    return FieldObjectSetSpecialAnim(mapObject, GetFaceDirectionAnimId(GetOppositeDirection(direction)));
}

dirn2anim_2(sub_8093648, gUnknown_0850DBF5);
dirn2anim_2(sub_8093674, gUnknown_0850DBFA);
dirn2anim_2(sub_80936A0, gUnknown_0850DBFF);
dirn2anim_2(sub_80936CC, gUnknown_0850DC04);
dirn2anim_2(sub_80936F8, gUnknown_0850DC09);
dirn2anim_2(sub_8093724, gUnknown_0850DC0E);
dirn2anim_2(sub_8093750, gUnknown_0850DC13);
dirn2anim_2(sub_809377C, gUnknown_0850DC18);
dirn2anim_2(sub_80937A8, gUnknown_0850DC1D);
dirn2anim_2(d2s_08064034, gUnknown_0850DC22);

u8 GetOppositeDirection(u8 direction)
{
    u8 directions[sizeof gOppositeDirections];

    memcpy(directions, gOppositeDirections, sizeof gOppositeDirections);
    if (direction < 1 || direction > (sizeof gOppositeDirections))
    {
        return direction;
    }
    return directions[direction - 1];
}

static u32 zffu_offset_calc(u8 a0, u8 a1)
{
    return gUnknown_0850DC2F[a0 - 1][a1 - 1];
}

static u32 state_to_direction(u8 a0, u32 a1, u32 a2)
{
    u32 zffuOffset;
    u8 a1_2;
    u8 a2_2;

    a1_2 = a1;
    a2_2 = a2;
    if (a1_2 == 0 || a2_2 == 0 || a1_2 > DIR_EAST || a2_2 > DIR_EAST)
    {
        return 0;
    }
    zffuOffset = zffu_offset_calc(a1_2, a2);
    return gUnknown_0850DC3F[a0 - 1][zffuOffset - 1];
}

static void FieldObjectExecSpecialAnim(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (gUnknown_0850DC50[mapObject->movementActionId][sprite->data[2]](mapObject, sprite))
    {
        mapObject->heldMovementFinished = TRUE;
    }
}

bool8 FieldObjectExecRegularAnim(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (gUnknown_0850DC50[mapObject->movementActionId][sprite->data[2]](mapObject, sprite))
    {
        mapObject->movementActionId = 0xFF;
        sprite->data[2] = 0;
        return TRUE;
    }
    return FALSE;
}

void FieldObjectSetRegularAnim(struct MapObject *mapObject, struct Sprite *sprite, u8 animId)
{
    mapObject->movementActionId = animId;
    sprite->data[2] = 0;
}

// file boundary?

void an_look_any(struct MapObject *mapObject, struct Sprite *sprite, u8 direction)
{
    FieldObjectSetDirection(mapObject, direction);
    npc_coords_shift_still(mapObject);
    obj_npc_animation_step(mapObject, sprite, get_go_image_anim_num(mapObject->facingDirection));
    sprite->animPaused = TRUE;
    sprite->data[2] = 1;
}

bool8 sub_8093950(struct MapObject *mapObject, struct Sprite *sprite)
{
    an_look_any(mapObject, sprite, DIR_SOUTH);
    return TRUE;
}

bool8 sub_8093960(struct MapObject *mapObject, struct Sprite *sprite)
{
    an_look_any(mapObject, sprite, DIR_NORTH);
    return TRUE;
}

bool8 sub_8093970(struct MapObject *mapObject, struct Sprite *sprite)
{
    an_look_any(mapObject, sprite, DIR_WEST);
    return TRUE;
}

bool8 sub_8093980(struct MapObject *mapObject, struct Sprite *sprite)
{
    an_look_any(mapObject, sprite, DIR_EAST);
    return TRUE;
}

void npc_apply_direction(struct MapObject *mapObject, struct Sprite *sprite, u8 direction, u8 speed)
{
    s16 x;
    s16 y;

    x = mapObject->currentCoords.x;
    y = mapObject->currentCoords.y;
    FieldObjectSetDirection(mapObject, direction);
    MoveCoords(direction, &x, &y);
    npc_coords_shift(mapObject, x, y);
    oamt_npc_ministep_reset(sprite, direction, speed);
    sprite->animPaused = FALSE;
    if (gUnknown_020375B8 != NULL && sub_8097F78(mapObject) != 0x10)
    {
        sprite->animPaused = TRUE;
    }
    mapObject->triggerGroundEffectsOnMove = TRUE;
    sprite->data[2] = 1;
}

void do_go_anim(struct MapObject *mapObject, struct Sprite *sprite, u8 direction, u8 speed)
{
    u8 (*functions[ARRAY_COUNT(gUnknown_0850DEE8)])(u8);

    memcpy(functions, gUnknown_0850DEE8, sizeof gUnknown_0850DEE8);
    npc_apply_direction(mapObject, sprite, direction, speed);
    npc_apply_anim_looping(mapObject, sprite, functions[speed](mapObject->facingDirection));
}

void do_run_anim(struct MapObject *mapObject, struct Sprite *sprite, u8 direction)
{
    npc_apply_direction(mapObject, sprite, direction, 1);
    npc_apply_anim_looping(mapObject, sprite, get_run_image_anim_num(mapObject->facingDirection));
}

bool8 npc_obj_ministep_stop_on_arrival(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (obj_npc_ministep(sprite))
    {
        npc_coords_shift_still(mapObject);
        mapObject->triggerGroundEffectsOnStop = TRUE;
        sprite->animPaused = TRUE;
        return TRUE;
    }
    return FALSE;
}

void sub_8093AF0(struct MapObject *mapObject, struct Sprite *sprite, u8 direction)
{
    s16 x;
    s16 y;

    x = mapObject->currentCoords.x;
    y = mapObject->currentCoords.y;
    FieldObjectSetDirection(mapObject, direction);
    MoveCoords(direction, &x, &y);
    npc_coords_shift(mapObject, x, y);
    sub_80976DC(sprite, direction);
    sprite->animPaused = FALSE;
    mapObject->triggerGroundEffectsOnMove = TRUE;
    sprite->data[2] = 1;
}

void sub_8093B60(struct MapObject *mapObject, struct Sprite *sprite, u8 direction)
{
    sub_8093AF0(mapObject, sprite, direction);
    npc_apply_anim_looping(mapObject, sprite, get_go_image_anim_num(mapObject->facingDirection));
}

bool8 an_walk_any_2(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (sub_80976EC(sprite))
    {
        npc_coords_shift_still(mapObject);
        mapObject->triggerGroundEffectsOnStop = TRUE;
        sprite->animPaused = TRUE;
        return TRUE;
    }
    return FALSE;
}

#define an_walk_any_2_macro(name, fn1, fn2, ...) \
bool8 name##_2(struct MapObject *, struct Sprite *);\
bool8 name(struct MapObject *mapObject, struct Sprite *sprite)\
{\
    fn1(mapObject, sprite, __VA_ARGS__);\
    return name##_2(mapObject, sprite);\
}\
bool8 name##_2(struct MapObject *mapObject, struct Sprite *sprite)\
{\
    if (fn2(mapObject, sprite))\
    {\
        sprite->data[2] = 2;\
        return TRUE;\
    }\
    return FALSE;\
}

an_walk_any_2_macro(sub_8093BC4, sub_8093B60, an_walk_any_2, 7)
an_walk_any_2_macro(sub_8093C04, sub_8093B60, an_walk_any_2, 8)
an_walk_any_2_macro(sub_8093C44, sub_8093B60, an_walk_any_2, 5)
an_walk_any_2_macro(sub_8093C84, sub_8093B60, an_walk_any_2, 6)
an_walk_any_2_macro(sub_8093CC4, sub_8093B60, an_walk_any_2, 1)
an_walk_any_2_macro(sub_8093D04, sub_8093B60, an_walk_any_2, 2)
an_walk_any_2_macro(sub_8093D44, sub_8093B60, an_walk_any_2, 3)
an_walk_any_2_macro(sub_8093D84, sub_8093B60, an_walk_any_2, 4)
an_walk_any_2_macro(sub_8093DC4, do_go_anim, npc_obj_ministep_stop_on_arrival, 7, 0)
an_walk_any_2_macro(sub_8093E04, do_go_anim, npc_obj_ministep_stop_on_arrival, 8, 0)
an_walk_any_2_macro(sub_8093E44, do_go_anim, npc_obj_ministep_stop_on_arrival, 5, 0)
an_walk_any_2_macro(sub_8093E84, do_go_anim, npc_obj_ministep_stop_on_arrival, 6, 0)
an_walk_any_2_macro(sub_8093EC4, do_go_anim, npc_obj_ministep_stop_on_arrival, 1, 0)
an_walk_any_2_macro(sub_8093F04, do_go_anim, npc_obj_ministep_stop_on_arrival, 2, 0)
an_walk_any_2_macro(sub_8093F44, do_go_anim, npc_obj_ministep_stop_on_arrival, 3, 0)
an_walk_any_2_macro(sub_8093F84, do_go_anim, npc_obj_ministep_stop_on_arrival, 4, 0)

void sub_8093FC4(struct MapObject *mapObject, struct Sprite *sprite, u8 direction, u8 speed, u8 a5)
{
    s16 displacements[ARRAY_COUNT(gUnknown_0850DFBC)];
    s16 x;
    s16 y;

    memcpy(displacements, gUnknown_0850DFBC, sizeof gUnknown_0850DFBC);
    x = 0;
    y = 0;
    FieldObjectSetDirection(mapObject, direction);
    sub_8092F88(direction, &x, &y, displacements[speed], displacements[speed]);
    npc_coords_shift(mapObject, mapObject->currentCoords.x + x, mapObject->currentCoords.y + y);
    sub_809783C(sprite, direction, speed, a5);
    sprite->data[2] = 1;
    sprite->animPaused = 0;
    mapObject->triggerGroundEffectsOnMove = 1;
    mapObject->disableCoveringGroundEffects = 1;
}

void maybe_shadow_1(struct MapObject *mapObject, struct Sprite *sprite, u8 direction, u8 speed, u8 a4)
{
    sub_8093FC4(mapObject, sprite, direction, speed, a4);
    npc_apply_anim_looping(mapObject, sprite, get_go_image_anim_num(mapObject->facingDirection));
    DoShadowFieldEffect(mapObject);
}

u8 sub_80940C4(struct MapObject *mapObject, struct Sprite *sprite, u8 callback(struct Sprite *))
{
    s16 displacements[ARRAY_COUNT(gUnknown_0850DFC2)];
    s16 x;
    s16 y;
    u8 result;

    memcpy(displacements, gUnknown_0850DFC2, sizeof gUnknown_0850DFC2);
    result = callback(sprite);
    if (result == 1 && displacements[sprite->data[4]] != 0)
    {
        x = 0;
        y = 0;
        sub_8092F88(mapObject->movementDirection, &x, &y, displacements[sprite->data[4]], displacements[sprite->data[4]]);
        npc_coords_shift(mapObject, mapObject->currentCoords.x + x, mapObject->currentCoords.y + y);
        mapObject->triggerGroundEffectsOnMove = TRUE;
        mapObject->disableCoveringGroundEffects = TRUE;
    }
    else if (result == 0xFF)
    {
        npc_coords_shift_still(mapObject);
        mapObject->triggerGroundEffectsOnStop = TRUE;
        mapObject->landingJump = TRUE;
        sprite->animPaused = TRUE;
    }
    return result;
}

u8 sub_8094188(struct MapObject *mapObject, struct Sprite *sprite)
{
    return sub_80940C4(mapObject, sprite, sub_809785C);
}

u8 sub_809419C(struct MapObject *mapObject, struct Sprite *sprite)
{
    return sub_80940C4(mapObject, sprite, sub_80978E4);
}

bool8 sub_80941B0(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (sub_8094188(mapObject, sprite) == 0xFF)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 sub_80941C8(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (sub_809419C(mapObject, sprite) == 0xFF)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 sub_80941E0(struct MapObject *mapObject, struct Sprite *sprite)
{
    switch (sub_8094188(mapObject, sprite))
    {
        case 255:
            return TRUE;
        case   1:
            FieldObjectSetDirection(mapObject, GetOppositeDirection(mapObject->movementDirection));
            obj_npc_animation_step(mapObject, sprite, get_go_image_anim_num(mapObject->facingDirection));
        default:
            return FALSE;
    }
}

#define maybe_shadow_1_macro(name, fn1, fn2, ...) \
bool8 name##_2(struct MapObject *, struct Sprite *);\
bool8 name(struct MapObject *mapObject, struct Sprite *sprite)\
{\
    fn1(mapObject, sprite, __VA_ARGS__);\
    return name##_2(mapObject, sprite);\
}\
bool8 name##_2(struct MapObject *mapObject, struct Sprite *sprite)\
{\
    if (fn2(mapObject, sprite))\
    {\
        mapObject->hasShadow = FALSE;\
        sprite->data[2] = 2;\
        return TRUE;\
    }\
    return FALSE;\
}

maybe_shadow_1_macro(sub_8094230, maybe_shadow_1, sub_80941B0, DIR_SOUTH, 2, 0)
maybe_shadow_1_macro(sub_8094288, maybe_shadow_1, sub_80941B0, DIR_NORTH, 2, 0)
maybe_shadow_1_macro(sub_80942E0, maybe_shadow_1, sub_80941B0, DIR_WEST,  2, 0)
maybe_shadow_1_macro(sub_8094338, maybe_shadow_1, sub_80941B0, DIR_EAST,  2, 0)

void sub_8094390(struct Sprite *sprite, u16 duration)
{
    sprite->data[2] = 1;
    sprite->data[3] = duration;
}

bool8 sub_8094398(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (-- sprite->data[3] == 0)
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

#define special_anim_with_timer(name, duration)\
bool8 name(struct MapObject *mapObject, struct Sprite *sprite)\
{\
    sub_8094390(sprite, duration);\
    return sub_8094398(mapObject, sprite);\
}

special_anim_with_timer(sub_80943B4,  1)
special_anim_with_timer(sub_80943D4,  2)
special_anim_with_timer(sub_80943F4,  4)
special_anim_with_timer(sub_8094414,  8)
special_anim_with_timer(sub_8094434, 16)

an_walk_any_2_macro(sub_8094454, do_go_anim, npc_obj_ministep_stop_on_arrival, 1, 1)
an_walk_any_2_macro(sub_8094494, do_go_anim, npc_obj_ministep_stop_on_arrival, 2, 1)
an_walk_any_2_macro(sub_80944D4, do_go_anim, npc_obj_ministep_stop_on_arrival, 3, 1)
an_walk_any_2_macro(sub_8094514, do_go_anim, npc_obj_ministep_stop_on_arrival, 4, 1)

void sub_8094554(struct MapObject *mapObject, struct Sprite *sprite, u8 direction, u8 animNum, u16 duration)
{
    FieldObjectSetDirection(mapObject, direction);
    npc_apply_anim_looping(mapObject, sprite, animNum);
    sprite->animPaused = FALSE;
    sprite->data[2] = 1;
    sprite->data[3] = duration;
}

bool8 sub_809459C(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (-- sprite->data[3] == 0)
    {
        sprite->data[2] = 2;
        sprite->animPaused = TRUE;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_80945C4(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (sprite->data[3] & 1)
    {
        sprite->animDelayCounter ++;
    }
    return sub_809459C(mapObject, sprite);
}

#define special_anim_with_timer_2(name, direction, images, duration, timer) \
bool8 name(struct MapObject *mapObject, struct Sprite *sprite)\
{\
    u8 animId;\
    animId = images(DIR_##direction);\
    sub_8094554(mapObject, sprite, DIR_##direction, animId, duration);\
    return timer(mapObject, sprite);\
}

special_anim_with_timer_2(sub_8094600, SOUTH, get_go_image_anim_num,        32, sub_80945C4)
special_anim_with_timer_2(sub_8094638, NORTH, get_go_image_anim_num,        32, sub_80945C4)
special_anim_with_timer_2(sub_8094670, WEST,  get_go_image_anim_num,        32, sub_80945C4)
special_anim_with_timer_2(sub_80946A8, EAST,  get_go_image_anim_num,        32, sub_80945C4)
special_anim_with_timer_2(sub_80946E0, SOUTH, get_go_image_anim_num,        16, sub_809459C)
special_anim_with_timer_2(sub_8094718, NORTH, get_go_image_anim_num,        16, sub_809459C)
special_anim_with_timer_2(sub_8094750, WEST,  get_go_image_anim_num,        16, sub_809459C)
special_anim_with_timer_2(sub_8094788, EAST,  get_go_image_anim_num,        16, sub_809459C)
special_anim_with_timer_2(sub_80947C0, SOUTH, get_go_fast_image_anim_num,    8, sub_809459C)
special_anim_with_timer_2(sub_80947F8, NORTH, get_go_fast_image_anim_num,    8, sub_809459C)
special_anim_with_timer_2(sub_8094830, WEST,  get_go_fast_image_anim_num,    8, sub_809459C)
special_anim_with_timer_2(sub_8094868, EAST,  get_go_fast_image_anim_num,    8, sub_809459C)
special_anim_with_timer_2(sub_80948A0, SOUTH, get_go_faster_image_anim_num,  4, sub_809459C)
special_anim_with_timer_2(sub_80948D8, NORTH, get_go_faster_image_anim_num,  4, sub_809459C)
special_anim_with_timer_2(sub_8094910, WEST,  get_go_faster_image_anim_num,  4, sub_809459C)
special_anim_with_timer_2(sub_8094948, EAST,  get_go_faster_image_anim_num,  4, sub_809459C)

an_walk_any_2_macro(sub_8094980, do_go_anim, npc_obj_ministep_stop_on_arrival, DIR_SOUTH, 2)
an_walk_any_2_macro(sub_80949C0, do_go_anim, npc_obj_ministep_stop_on_arrival, DIR_NORTH, 2)
an_walk_any_2_macro(sub_8094A00, do_go_anim, npc_obj_ministep_stop_on_arrival, DIR_WEST,  2)
an_walk_any_2_macro(sub_8094A40, do_go_anim, npc_obj_ministep_stop_on_arrival, DIR_EAST,  2)
an_walk_any_2_macro(sub_8094A80, do_go_anim, npc_obj_ministep_stop_on_arrival, DIR_SOUTH, 3)
an_walk_any_2_macro(sub_8094AC0, do_go_anim, npc_obj_ministep_stop_on_arrival, DIR_NORTH, 3)
an_walk_any_2_macro(sub_8094B00, do_go_anim, npc_obj_ministep_stop_on_arrival, DIR_WEST,  3)
an_walk_any_2_macro(sub_8094B40, do_go_anim, npc_obj_ministep_stop_on_arrival, DIR_EAST,  3)
an_walk_any_2_macro(sub_8094B80, do_go_anim, npc_obj_ministep_stop_on_arrival, DIR_SOUTH, 4)
an_walk_any_2_macro(sub_8094BC0, do_go_anim, npc_obj_ministep_stop_on_arrival, DIR_NORTH, 4)
an_walk_any_2_macro(sub_8094C00, do_go_anim, npc_obj_ministep_stop_on_arrival, DIR_WEST,  4)
an_walk_any_2_macro(sub_8094C40, do_go_anim, npc_obj_ministep_stop_on_arrival, DIR_EAST,  4)
an_walk_any_2_macro(sub_8094C80, do_run_anim, npc_obj_ministep_stop_on_arrival, DIR_SOUTH)
an_walk_any_2_macro(sub_8094CC0, do_run_anim, npc_obj_ministep_stop_on_arrival, DIR_NORTH)
an_walk_any_2_macro(sub_8094D00, do_run_anim, npc_obj_ministep_stop_on_arrival, DIR_WEST)
an_walk_any_2_macro(sub_8094D40, do_run_anim, npc_obj_ministep_stop_on_arrival, DIR_EAST)

void npc_set_direction_and_anim__an_proceed(struct MapObject *mapObject, struct Sprite *sprite, u8 direction, u8 animNum)
{
    obj_anim_image_set_and_seek(sprite, animNum, 0);
    FieldObjectSetDirection(mapObject, direction);
    sprite->data[2] = 1;
}

bool8 sub_8094DAC(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_set_direction_and_anim__an_proceed(mapObject, sprite, mapObject->movementDirection, sprite->animNum);
    return FALSE;
}

bool8 sub_8094DC4(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (sub_80979BC(sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

void sub_8094DE4(struct MapObject *mapObject, struct Sprite *sprite, u8 direction)
{
    sub_8093FC4(mapObject, sprite, direction, 1, 0);
    StartSpriteAnim(sprite, sub_80929AC(direction));
}

#define unk_macro_8094E18(name, direction)\
bool8 name##_2(struct MapObject *, struct Sprite *);\
bool8 name(struct MapObject *mapObject, struct Sprite *sprite)\
{\
    sub_8094DE4(mapObject, sprite, direction);\
    return name##_2(mapObject, sprite);\
}\
bool8 name##_2(struct MapObject *mapObject, struct Sprite *sprite)\
{\
    if (sub_80941C8(mapObject, sprite))\
    {\
        sprite->data[2] = 2;\
        mapObject->landingJump = FALSE;\
        return TRUE;\
    }\
    return FALSE;\
}

unk_macro_8094E18(sub_8094E18, DIR_SOUTH)
unk_macro_8094E18(sub_8094E60, DIR_NORTH)
unk_macro_8094E18(sub_8094EB8, DIR_WEST)
unk_macro_8094E18(sub_8094710, DIR_EAST)

bool8 sub_8094F38(struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 mapObjectId;

    if (!TryGetFieldObjectIdByLocalIdAndMap(0xFF, 0, 0, &mapObjectId))
    {
        an_look_any(mapObject, sprite, sub_8092AF8(mapObject->currentCoords.x, mapObject->currentCoords.y, gMapObjects[mapObjectId].currentCoords.x, gMapObjects[mapObjectId].currentCoords.y));
    }
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_8094F94(struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 mapObjectId;

    if (!TryGetFieldObjectIdByLocalIdAndMap(0xFF, 0, 0, &mapObjectId))
    {
        an_look_any(mapObject, sprite, GetOppositeDirection(sub_8092AF8(mapObject->currentCoords.x, mapObject->currentCoords.y, gMapObjects[mapObjectId].currentCoords.x, gMapObjects[mapObjectId].currentCoords.y)));
    }
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_8094FF8(struct MapObject *mapObject, struct Sprite *sprite)
{
    mapObject->facingDirectionLocked = TRUE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_8095008(struct MapObject *mapObject, struct Sprite *sprite)
{
    mapObject->facingDirectionLocked = FALSE;
    sprite->data[2] = 1;
    return TRUE;
}

maybe_shadow_1_macro(sub_8095018, maybe_shadow_1, sub_80941B0, DIR_SOUTH, 1, 2)
maybe_shadow_1_macro(sub_8095070, maybe_shadow_1, sub_80941B0, DIR_NORTH, 1, 2)
maybe_shadow_1_macro(sub_80950C8, maybe_shadow_1, sub_80941B0, DIR_WEST,  1, 2)
maybe_shadow_1_macro(sub_8095120, maybe_shadow_1, sub_80941B0, DIR_EAST,  1, 2)
maybe_shadow_1_macro(sub_8095178, maybe_shadow_1, sub_80941B0, DIR_SOUTH, 0, 0)
maybe_shadow_1_macro(sub_80951D0, maybe_shadow_1, sub_80941B0, DIR_NORTH, 0, 0)
maybe_shadow_1_macro(sub_8095228, maybe_shadow_1, sub_80941B0, DIR_WEST,  0, 0)
maybe_shadow_1_macro(sub_8095280, maybe_shadow_1, sub_80941B0, DIR_EAST,  0, 0)
maybe_shadow_1_macro(sub_80952D8, maybe_shadow_1, sub_80941E0, DIR_SOUTH, 0, 2)
maybe_shadow_1_macro(sub_8095330, maybe_shadow_1, sub_80941E0, DIR_NORTH, 0, 2)
maybe_shadow_1_macro(sub_8095388, maybe_shadow_1, sub_80941E0, DIR_WEST,  0, 2)
maybe_shadow_1_macro(sub_80953E0, maybe_shadow_1, sub_80941E0, DIR_EAST,  0, 2)

bool8 sub_8095438(struct MapObject *mapObject, struct Sprite *sprite)
{
    an_look_any(mapObject, sprite, gInitialMovementTypeFacingDirections[mapObject->movementType]);
    return TRUE;
}

bool8 sub_8095450(struct MapObject *mapObject, struct Sprite *sprite)
{
    npc_set_direction_and_anim__an_proceed(mapObject, sprite, DIR_SOUTH, 0x14);
    return FALSE;
}

bool8 sub_8095460(struct MapObject *mapObject, struct Sprite *sprite)
{
    mapObject->disableJumpLandingGroundEffect = FALSE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_8095470(struct MapObject *mapObject, struct Sprite *sprite)
{
    mapObject->disableJumpLandingGroundEffect = TRUE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_8095480(struct MapObject *mapObject, struct Sprite *sprite)
{
    mapObject->inanimate = TRUE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_8095490(struct MapObject *mapObject, struct Sprite *sprite)
{
    mapObject->inanimate = GetFieldObjectGraphicsInfo(mapObject->graphicsId)->inanimate;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_80954BC(struct MapObject *mapObject, struct Sprite *sprite)
{
    mapObject->invisible = TRUE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_80954CC(struct MapObject *mapObject, struct Sprite *sprite)
{
    mapObject->invisible = FALSE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 do_exclamation_mark_bubble_1(struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectGetLocalIdAndMap(mapObject, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    FieldEffectStart(FLDEFF_EXCLAMATION_MARK_ICON_1);
    sprite->data[2] = 1;
    return TRUE;
}

bool8 do_exclamation_mark_bubble_2(struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectGetLocalIdAndMap(mapObject, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    FieldEffectStart(FLDEFF_EXCLAMATION_MARK_ICON_2);
    sprite->data[2] = 1;
    return TRUE;
}

bool8 do_heart_bubble(struct MapObject *mapObject, struct Sprite *sprite)
{
    FieldObjectGetLocalIdAndMap(mapObject, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    FieldEffectStart(FLDEFF_HEART_ICON);
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_8095548(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (mapObject->movementType == 0x3F)
    {
        sub_80B4578(mapObject);
        return FALSE;
    }
    if (mapObject->movementType != 0x39 && mapObject->movementType != 0x3A)
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    sub_8155D78(mapObject);
    sprite->data[2] = 1;
    return sub_809558C(mapObject, sprite);
}

bool8 sub_809558C(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (sub_8155DA0(mapObject))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_80955AC(struct MapObject *mapObject, struct Sprite *sprite)
{
    obj_anim_image_set_and_seek(sprite, 1, 0);
    sprite->data[2] = 1;
    return FALSE;
}

bool8 sub_80955C8(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (sub_80979BC(sprite))
    {
        SetFieldObjectStepTimer(sprite, 32);
        sprite->data[2] = 2;
    }
    return FALSE;
}

bool8 sub_80955EC(struct MapObject *mapObject, struct Sprite *sprite)
{
    mapObject->invisible ^= TRUE;
    if (RunFieldObjectStepTimer(sprite))
    {
        mapObject->invisible = TRUE;
        sprite->data[2] = 3;
    }
    return FALSE;
}

bool8 sub_8095628(struct MapObject *mapObject, struct Sprite *sprite)
{
    obj_anim_image_set_and_seek(sprite, 1, 0);
    sprite->data[2] = 1;
    return FALSE;
}

bool8 sub_8095644(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (sub_80979BC(sprite))
    {
        SetFieldObjectStepTimer(sprite, 32);
        sprite->data[2] = 2;
    }
    return FALSE;
}

bool8 sub_8095668(struct MapObject *mapObject, struct Sprite *sprite)
{
    mapObject->invisible ^= TRUE;
    if (RunFieldObjectStepTimer(sprite))
    {
        mapObject->invisible = TRUE;
        sprite->data[2] = 3;
    }
    return FALSE;
}

bool8 sub_80956A4(struct MapObject *mapObject, struct Sprite *sprite)
{
    mapObject->fixedPriority = TRUE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_80956B4(struct MapObject *mapObject, struct Sprite *sprite)
{
    mapObject->fixedPriority = FALSE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_80956C4(struct MapObject *mapObject, struct Sprite *sprite)
{
    sprite->oam.affineMode = 3;
    InitSpriteAffineAnim(sprite);
    sprite->affineAnimPaused = TRUE;
    sprite->subspriteMode = 0;
    return TRUE;
}

bool8 sub_80956F4(struct MapObject *mapObject, struct Sprite *sprite)
{
    FreeOamMatrix(sprite->oam.matrixNum);
    sprite->oam.affineMode = 0;
    CalcCenterToCornerVec(sprite, sprite->oam.shape, sprite->oam.size, sprite->oam.affineMode);
    return TRUE;
}

bool8 sub_8095724(struct MapObject *mapObject, struct Sprite *sprite)
{
    mapObject->unk3_3 = TRUE;
    return TRUE;
}

bool8 sub_8095730(struct MapObject *mapObject, struct Sprite *sprite)
{
    mapObject->unk3_3 = FALSE;
    return TRUE;
}

#define affine_an_walk_any_2_macro(name, fn, fn2, action, anim, ...)\
bool8 name##_2(struct MapObject *, struct Sprite *);\
bool8 name(struct MapObject *mapObject, struct Sprite *sprite)\
{\
    fn(mapObject, sprite, __VA_ARGS__);\
    sprite->affineAnimPaused = FALSE;\
    action(sprite, anim);\
    return name##_2(mapObject, sprite);\
}\
bool8 name##_2(struct MapObject *mapObject, struct Sprite *sprite)\
{\
    if (fn2(mapObject, sprite))\
    {\
        sprite->affineAnimPaused = TRUE;\
        sprite->data[2] = 2;\
        return TRUE;\
    }\
    return FALSE;\
}\

affine_an_walk_any_2_macro(sub_8095740, sub_8093B60, an_walk_any_2, StartSpriteAffineAnimIfDifferent, 0, DIR_SOUTH)
affine_an_walk_any_2_macro(sub_80957A0, sub_8093B60, an_walk_any_2, ChangeSpriteAffineAnimIfDifferent, 1, DIR_SOUTH)
affine_an_walk_any_2_macro(sub_8095800, do_go_anim, npc_obj_ministep_stop_on_arrival, ChangeSpriteAffineAnimIfDifferent, 2, DIR_WEST, 1)
affine_an_walk_any_2_macro(sub_8095860, do_go_anim, npc_obj_ministep_stop_on_arrival, ChangeSpriteAffineAnimIfDifferent, 3, DIR_EAST, 1)

static void sub_80958C0(struct MapObject *mapObject, struct Sprite *sprite, u8 direction)
{
    FieldObjectSetDirection(mapObject, direction);
    npc_coords_shift_still(mapObject);
    obj_npc_animation_step(mapObject, sprite, sub_80929FC(direction));
    sprite->animPaused = TRUE;
    sprite->data[2] = 1;
}

bool8 sub_8095900(struct MapObject *mapObject, struct Sprite *sprite)
{
    sub_80958C0(mapObject, sprite, DIR_SOUTH);
    return TRUE;
}

bool8 sub_8095910(struct MapObject *mapObject, struct Sprite *sprite)
{
    sub_80958C0(mapObject, sprite, DIR_NORTH);
    return TRUE;
}

bool8 sub_8095920(struct MapObject *mapObject, struct Sprite *sprite)
{
    sub_80958C0(mapObject, sprite, DIR_WEST);
    return TRUE;
}

bool8 sub_8095930(struct MapObject *mapObject, struct Sprite *sprite)
{
    sub_80958C0(mapObject, sprite, DIR_EAST);
    return TRUE;
}

#define set_dirn_and_anim__an_proceed(name, direction, anims)\
bool8 name(struct MapObject *mapObject, struct Sprite *sprite)\
{\
    npc_set_direction_and_anim__an_proceed(mapObject, sprite, direction, anims(direction));\
    return FALSE;\
}

set_dirn_and_anim__an_proceed(sub_8095940, DIR_SOUTH, sub_80929BC)
set_dirn_and_anim__an_proceed(sub_8095964, DIR_NORTH, sub_80929BC)
set_dirn_and_anim__an_proceed(sub_8095988, DIR_WEST,  sub_80929BC)
set_dirn_and_anim__an_proceed(sub_80959AC, DIR_EAST,  sub_80929BC)
set_dirn_and_anim__an_proceed(sub_80959D0, DIR_SOUTH, sub_80929DC)
set_dirn_and_anim__an_proceed(sub_80959F4, DIR_NORTH, sub_80929DC)
set_dirn_and_anim__an_proceed(sub_8095A18, DIR_WEST,  sub_80929DC)
set_dirn_and_anim__an_proceed(sub_8095A3C, DIR_EAST,  sub_80929DC)
set_dirn_and_anim__an_proceed(sub_8095A60, DIR_SOUTH, sub_80929EC)
set_dirn_and_anim__an_proceed(sub_8095A84, DIR_NORTH, sub_80929EC)
set_dirn_and_anim__an_proceed(sub_8095AA8, DIR_WEST,  sub_80929EC)
set_dirn_and_anim__an_proceed(sub_8095ACC, DIR_EAST,  sub_80929EC)

void sub_8095AF0(struct MapObject *mapObject, struct Sprite *sprite)
{
    sub_8097750(sprite);
    sprite->animPaused = FALSE;
}

bool8 sub_8095B0C(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (sub_8097758(sprite))
    {
        npc_coords_shift_still(mapObject);
        mapObject->triggerGroundEffectsOnStop = TRUE;
        sprite->animPaused = TRUE;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8095B44(struct MapObject *mapObject, struct Sprite *sprite)
{
    sub_8095AF0(mapObject, sprite);
    sprite->data[2] = 1;
    return sub_8095B64(mapObject, sprite);
}

bool8 sub_8095B64(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (sub_8095B0C(mapObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

void sub_8095B84(struct MapObject *mapObject, struct Sprite *sprite, u8 direction, u8 speed, u8 a4)
{
    sub_8093FC4(mapObject, sprite, direction, speed, a4);
    StartSpriteAnimIfDifferent(sprite, sub_80929BC(direction));
    DoShadowFieldEffect(mapObject);
}

maybe_shadow_1_macro(sub_8095BC8, sub_8095B84, sub_80941B0, DIR_SOUTH, 0, 1)
maybe_shadow_1_macro(sub_8095C20, sub_8095B84, sub_80941B0, DIR_NORTH, 0, 1)
maybe_shadow_1_macro(sub_8095C78, sub_8095B84, sub_80941B0, DIR_WEST,  0, 1)
maybe_shadow_1_macro(sub_8095CD0, sub_8095B84, sub_80941B0, DIR_EAST,  0, 1)
maybe_shadow_1_macro(sub_8095D28, sub_8095B84, sub_80941B0, DIR_SOUTH, 1, 1)
maybe_shadow_1_macro(sub_8095D80, sub_8095B84, sub_80941B0, DIR_NORTH, 1, 1)
maybe_shadow_1_macro(sub_8095DD8, sub_8095B84, sub_80941B0, DIR_WEST,  1, 1)
maybe_shadow_1_macro(sub_8095E30, sub_8095B84, sub_80941B0, DIR_EAST,  1, 1)
maybe_shadow_1_macro(sub_8095E88, sub_8095B84, sub_80941B0, DIR_SOUTH, 2, 0)
maybe_shadow_1_macro(sub_8095EE0, sub_8095B84, sub_80941B0, DIR_NORTH, 2, 0)
maybe_shadow_1_macro(sub_8095F38, sub_8095B84, sub_80941B0, DIR_WEST,  2, 0)
maybe_shadow_1_macro(sub_8095F90, sub_8095B84, sub_80941B0, DIR_EAST,  2, 0)

special_anim_with_timer_2(sub_8095FE8, SOUTH, sub_80929FC, 8, sub_809459C)
special_anim_with_timer_2(sub_8096020, NORTH, sub_80929FC, 8, sub_809459C)
special_anim_with_timer_2(sub_8096058, WEST,  sub_80929FC, 8, sub_809459C)
special_anim_with_timer_2(sub_8096090, EAST,  sub_80929FC, 8, sub_809459C)

void sub_80960C8(struct MapObject *mapObject, struct Sprite *sprite, u8 direction, u8 speed)
{
    npc_apply_direction(mapObject, sprite, direction, speed);
    StartSpriteAnim(sprite, sub_80929BC(mapObject->facingDirection));
    SeekSpriteAnim(sprite, 0);
}

an_walk_any_2_macro(sub_8096100, sub_80960C8, npc_obj_ministep_stop_on_arrival, DIR_SOUTH, 1)
an_walk_any_2_macro(sub_8096140, sub_80960C8, npc_obj_ministep_stop_on_arrival, DIR_NORTH, 1)
an_walk_any_2_macro(sub_8096180, sub_80960C8, npc_obj_ministep_stop_on_arrival, DIR_WEST,  1)
an_walk_any_2_macro(sub_80961C0, sub_80960C8, npc_obj_ministep_stop_on_arrival, DIR_EAST,  1)

void sub_8096200(struct MapObject *mapObject, struct Sprite *sprite, u8 direction, u8 speed)
{
    npc_apply_direction(mapObject, sprite, direction, speed);
    npc_apply_anim_looping(mapObject, sprite, sub_80929FC(mapObject->facingDirection));
}

an_walk_any_2_macro(sub_8096230, sub_8096200, npc_obj_ministep_stop_on_arrival, DIR_SOUTH, 1)
an_walk_any_2_macro(sub_8096270, sub_8096200, npc_obj_ministep_stop_on_arrival, DIR_NORTH, 1)
an_walk_any_2_macro(sub_80962B0, sub_8096200, npc_obj_ministep_stop_on_arrival, DIR_WEST,  1)
an_walk_any_2_macro(sub_80962F0, sub_8096200, npc_obj_ministep_stop_on_arrival, DIR_EAST,  1)

void sub_8096330(struct MapObject *mapObject, struct Sprite *sprite, u8 direction, u8 speed)
{
    npc_apply_direction(mapObject, sprite, direction, speed);
    StartSpriteAnim(sprite, sub_80929DC(mapObject->facingDirection));
    SeekSpriteAnim(sprite, 0);
}
an_walk_any_2_macro(sub_8096368, sub_8096330, npc_obj_ministep_stop_on_arrival, DIR_SOUTH, 1)
an_walk_any_2_macro(sub_80963A8, sub_8096330, npc_obj_ministep_stop_on_arrival, DIR_NORTH, 1)
an_walk_any_2_macro(sub_80963E8, sub_8096330, npc_obj_ministep_stop_on_arrival, DIR_WEST,  1)
an_walk_any_2_macro(sub_8096428, sub_8096330, npc_obj_ministep_stop_on_arrival, DIR_EAST,  1)

bool8 sub_8096468(struct MapObject *mapObject, struct Sprite *sprite)
{
    sub_8097FA4(mapObject);
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_809647C(struct MapObject *mapObject, struct Sprite *sprite)
{
    sub_8098044(mapObject->warpArrowSpriteId);
    sprite->pos2.y = 0;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_8096494(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (sprite->pos2.y == 0)
    {
        sub_8098044(mapObject->warpArrowSpriteId);
        sprite->data[2] = 1;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_80964B8(struct MapObject *mapObject, struct Sprite *sprite)
{
    return TRUE;
}

bool8 sub_80964BC(struct MapObject *mapObject, struct Sprite *sprite)
{
    sprite->animPaused = TRUE;
    return TRUE;
}

void npc_obj_transfer_image_anim_pause_flag(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (mapObject->disableAnim)
    {
        sprite->animPaused = TRUE;
    }
}

void sub_80964E8(struct MapObject *mapObject, struct Sprite *sprite)
{
    if (mapObject->enableAnim)
    {
        sprite->animPaused = FALSE;
        mapObject->disableAnim = FALSE;
        mapObject->enableAnim = FALSE;
    }
}

void sub_8096518(struct MapObject *mapObject, struct Sprite *sprite)
{
    sub_8096530(mapObject, sprite);
    npc_update_obj_anim_flag(mapObject, sprite);
}

static void sub_8096530(struct MapObject *mapObject, struct Sprite *sprite)
{
    u16 x;
    u16 y;
    u16 x2;
    u16 y2;
    const struct MapObjectGraphicsInfo *graphicsInfo;

    mapObject->offScreen = FALSE;
    graphicsInfo = GetFieldObjectGraphicsInfo(mapObject->graphicsId);
    if (sprite->coordOffsetEnabled)
    {
        x = sprite->pos1.x + sprite->pos2.x + sprite->centerToCornerVecX + gSpriteCoordOffsetX;
        y = sprite->pos1.y + sprite->pos2.y + sprite->centerToCornerVecY + gSpriteCoordOffsetY;
    }
    else
    {
        x = sprite->pos1.x + sprite->pos2.x + sprite->centerToCornerVecX;
        y = sprite->pos1.y + sprite->pos2.y + sprite->centerToCornerVecY;
    }
    x2 = graphicsInfo->width;
    x2 += x;
    y2 = y;
    y2 += graphicsInfo->height;
    if ((s16)x >= 0x100 || (s16)x2 < -0x10)
    {
        mapObject->offScreen = TRUE;
    }
    if ((s16)y >= 0xB0 || (s16)y2 < -0x10)
    {
        mapObject->offScreen = TRUE;
    }
}

static void npc_update_obj_anim_flag(struct MapObject *mapObject, struct Sprite *sprite)
{
    sprite->invisible = FALSE;
    if (mapObject->invisible || mapObject->offScreen)
    {
        sprite->invisible = TRUE;
    }
}

/*static*/ void GetAllGroundEffectFlags_OnSpawn(struct MapObject *eventObj, u32 *flags)
{
    FieldObjectUpdateMetatileBehaviors(eventObj);
    GetGroundEffectFlags_Reflection(eventObj, flags);
    GetGroundEffectFlags_TallGrassOnSpawn(eventObj, flags);
    GetGroundEffectFlags_LongGrassOnSpawn(eventObj, flags);
    GetGroundEffectFlags_SandHeap(eventObj, flags);
    GetGroundEffectFlags_ShallowFlowingWater(eventObj, flags);
    GetGroundEffectFlags_ShortGrass(eventObj, flags);
    GetGroundEffectFlags_HotSprings(eventObj, flags);
}

static void GetAllGroundEffectFlags_OnBeginStep(struct MapObject *eventObj, u32 *flags)
{
    FieldObjectUpdateMetatileBehaviors(eventObj);
    GetGroundEffectFlags_Reflection(eventObj, flags);
    GetGroundEffectFlags_TallGrassOnBeginStep(eventObj, flags);
    GetGroundEffectFlags_LongGrassOnBeginStep(eventObj, flags);
    GetGroundEffectFlags_Tracks(eventObj, flags);
    GetGroundEffectFlags_SandHeap(eventObj, flags);
    GetGroundEffectFlags_ShallowFlowingWater(eventObj, flags);
    GetGroundEffectFlags_Puddle(eventObj, flags);
    GetGroundEffectFlags_ShortGrass(eventObj, flags);
    GetGroundEffectFlags_HotSprings(eventObj, flags);
}

/*static*/ void GetAllGroundEffectFlags_OnFinishStep(struct MapObject *eventObj, u32 *flags)
{
    FieldObjectUpdateMetatileBehaviors(eventObj);
    GetGroundEffectFlags_ShallowFlowingWater(eventObj, flags);
    GetGroundEffectFlags_SandHeap(eventObj, flags);
    GetGroundEffectFlags_Puddle(eventObj, flags);
    GetGroundEffectFlags_Ripple(eventObj, flags);
    GetGroundEffectFlags_ShortGrass(eventObj, flags);
    GetGroundEffectFlags_HotSprings(eventObj, flags);
    GetGroundEffectFlags_Seaweed(eventObj, flags);
    GetGroundEffectFlags_JumpLanding(eventObj, flags);
}

static void FieldObjectUpdateMetatileBehaviors(struct MapObject *eventObj)
{
    eventObj->previousMetatileBehavior = MapGridGetMetatileBehaviorAt(eventObj->previousCoords.x, eventObj->previousCoords.y);
    eventObj->currentMetatileBehavior = MapGridGetMetatileBehaviorAt(eventObj->currentCoords.x, eventObj->currentCoords.y);
}

static void GetGroundEffectFlags_Reflection(struct MapObject *eventObj, u32 *flags)
{
    u32 reflectionFlags[2] = { GROUND_EFFECT_FLAG_REFLECTION, GROUND_EFFECT_FLAG_ICE_REFLECTION };
    u8 type = FieldObjectCheckForReflectiveSurface(eventObj);

    if (type)
    {
        if (!eventObj->hasReflection)
        {
            eventObj->hasReflection = 0;
            eventObj->hasReflection = 1;
            *flags |= reflectionFlags[type - 1];
        }
    }
    else
    {
        eventObj->hasReflection = 0;
    }
}

static void GetGroundEffectFlags_TallGrassOnSpawn(struct MapObject *eventObj, u32 *flags)
{
    if (MetatileBehavior_IsTallGrass(eventObj->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_TALL_GRASS_ON_SPAWN;
}

static void GetGroundEffectFlags_TallGrassOnBeginStep(struct MapObject *eventObj, u32 *flags)
{
    if (MetatileBehavior_IsTallGrass(eventObj->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_TALL_GRASS_ON_MOVE;
}

static void GetGroundEffectFlags_LongGrassOnSpawn(struct MapObject *eventObj, u32 *flags)
{
    if (MetatileBehavior_IsLongGrass(eventObj->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_LONG_GRASS_ON_SPAWN;
}

static void GetGroundEffectFlags_LongGrassOnBeginStep(struct MapObject *eventObj, u32 *flags)
{
    if (MetatileBehavior_IsLongGrass(eventObj->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_LONG_GRASS_ON_MOVE;
}

static void GetGroundEffectFlags_Tracks(struct MapObject *eventObj, u32 *flags)
{
    if (MetatileBehavior_IsDeepSand(eventObj->previousMetatileBehavior))
    {
        *flags |= GROUND_EFFECT_FLAG_DEEP_SAND;
    }
    else if (MetatileBehavior_IsSandOrDeepSand(eventObj->previousMetatileBehavior)
             || MetatileBehavior_IsUnusedFootprintMetatile(eventObj->previousMetatileBehavior))
    {
        *flags |= GROUND_EFFECT_FLAG_SAND;
    }
}

static void GetGroundEffectFlags_SandHeap(struct MapObject *eventObj, u32 *flags)
{
    if (MetatileBehavior_IsDeepSand(eventObj->currentMetatileBehavior)
        && MetatileBehavior_IsDeepSand(eventObj->previousMetatileBehavior))
    {
        if (!eventObj->inSandPile)
        {
            eventObj->inSandPile = 0;
            eventObj->inSandPile = 1;
            *flags |= GROUND_EFFECT_FLAG_SAND_PILE;
        }
    }
    else
    {
        eventObj->inSandPile = 0;
    }
}

static void GetGroundEffectFlags_ShallowFlowingWater(struct MapObject *eventObj, u32 *flags)
{
    if ((MetatileBehavior_IsShallowFlowingWater(eventObj->currentMetatileBehavior)
         && MetatileBehavior_IsShallowFlowingWater(eventObj->previousMetatileBehavior))
        || (MetatileBehavior_IsPacifidlogLog(eventObj->currentMetatileBehavior)
            && MetatileBehavior_IsPacifidlogLog(eventObj->previousMetatileBehavior)))
    {
        if (!eventObj->inShallowFlowingWater)
        {
            eventObj->inShallowFlowingWater = 0;
            eventObj->inShallowFlowingWater = 1;
            *flags |= GROUND_EFFECT_FLAG_SHALLOW_FLOWING_WATER;
        }
    }
    else
    {
        eventObj->inShallowFlowingWater = 0;
    }
}

static void GetGroundEffectFlags_Puddle(struct MapObject *eventObj, u32 *flags)
{
    if (MetatileBehavior_IsPuddle(eventObj->currentMetatileBehavior)
        && MetatileBehavior_IsPuddle(eventObj->previousMetatileBehavior))
    {
        *flags |= GROUND_EFFECT_FLAG_PUDDLE;
    }
}

static void GetGroundEffectFlags_Ripple(struct MapObject *eventObj, u32 *flags)
{
    if (MetatileBehavior_HasRipples(eventObj->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_RIPPLES;
}

static void GetGroundEffectFlags_ShortGrass(struct MapObject *eventObj, u32 *flags)
{
    if (MetatileBehavior_IsShortGrass(eventObj->currentMetatileBehavior)
        && MetatileBehavior_IsShortGrass(eventObj->previousMetatileBehavior))
    {
        if (!eventObj->inShortGrass)
        {
            eventObj->inShortGrass = 0;
            eventObj->inShortGrass = 1;
            *flags |= GROUND_EFFECT_FLAG_SHORT_GRASS;
        }
    }
    else
    {
        eventObj->inShortGrass = 0;
    }
}

static void GetGroundEffectFlags_HotSprings(struct MapObject *eventObj, u32 *flags)
{
    if (MetatileBehavior_IsHotSprings(eventObj->currentMetatileBehavior)
        && MetatileBehavior_IsHotSprings(eventObj->previousMetatileBehavior))
    {
        if (!eventObj->inHotSprings)
        {
            eventObj->inHotSprings = 0;
            eventObj->inHotSprings = 1;
            *flags |= GROUND_EFFECT_FLAG_HOT_SPRINGS;
        }
    }
    else
    {
        eventObj->inHotSprings = 0;
    }
}

static void GetGroundEffectFlags_Seaweed(struct MapObject *eventObj, u32 *flags)
{
    if (MetatileBehavior_IsSeaweed(eventObj->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_SEAWEED;
}

static void GetGroundEffectFlags_JumpLanding(struct MapObject *eventObj, u32 *flags)
{
    typedef bool8 (*MetatileFunc)(u8);

    static const MetatileFunc metatileFuncs[] = {
        MetatileBehavior_IsTallGrass,
        MetatileBehavior_IsLongGrass,
        MetatileBehavior_IsPuddle,
        MetatileBehavior_IsSurfableWaterOrUnderwater,
        MetatileBehavior_IsShallowFlowingWater,
        MetatileBehavior_IsATile,
    };

    static const u32 jumpLandingFlags[] = {
        GROUND_EFFECT_FLAG_LAND_IN_TALL_GRASS,
        GROUND_EFFECT_FLAG_LAND_IN_LONG_GRASS,
        GROUND_EFFECT_FLAG_LAND_IN_SHALLOW_WATER,
        GROUND_EFFECT_FLAG_LAND_IN_DEEP_WATER,
        GROUND_EFFECT_FLAG_LAND_IN_SHALLOW_WATER,
        GROUND_EFFECT_FLAG_LAND_ON_NORMAL_GROUND,
    };

    if (eventObj->landingJump && !eventObj->disableJumpLandingGroundEffect)
    {
        u8 i;

        for (i = 0; i < ARRAY_COUNT(metatileFuncs); i++)
        {
            if (metatileFuncs[i](eventObj->currentMetatileBehavior))
            {
                *flags |= jumpLandingFlags[i];
                return;
            }
        }
    }
}

static u8 FieldObjectCheckForReflectiveSurface(struct MapObject *eventObj)
{
    const struct MapObjectGraphicsInfo *info = GetFieldObjectGraphicsInfo(eventObj->graphicsId);

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
        RETURN_REFLECTION_TYPE_AT(eventObj->currentCoords.x, eventObj->currentCoords.y + one + i)
        RETURN_REFLECTION_TYPE_AT(eventObj->previousCoords.x, eventObj->previousCoords.y + one + i)
        for (j = 1; j < width; j++)
        {
            RETURN_REFLECTION_TYPE_AT(eventObj->currentCoords.x + j, eventObj->currentCoords.y + one + i)
            RETURN_REFLECTION_TYPE_AT(eventObj->currentCoords.x - j, eventObj->currentCoords.y + one + i)
            RETURN_REFLECTION_TYPE_AT(eventObj->previousCoords.x + j, eventObj->previousCoords.y + one + i)
            RETURN_REFLECTION_TYPE_AT(eventObj->previousCoords.x - j, eventObj->previousCoords.y + one + i)
        }
    }
    return 0;

#undef RETURN_REFLECTION_TYPE_AT
}

static u8 GetReflectionTypeByMetatileBehavior(u32 behavior)
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

void FieldObjectSetSpriteOamTableForLongGrass(struct MapObject *eventObj, struct Sprite *sprite)
{
    if (eventObj->disableCoveringGroundEffects)
        return;

    if (!MetatileBehavior_IsLongGrass(eventObj->currentMetatileBehavior))
        return;

    if (!MetatileBehavior_IsLongGrass(eventObj->previousMetatileBehavior))
        return;

    sprite->subspriteTableNum = 4;

    if (ZCoordToPriority(eventObj->previousElevation) == 1)
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

static const u8 sUnknown_08376050[] = {
    0x73, 0x73, 0x53, 0x73, 0x53, 0x73, 0x53, 0x73, 0x53, 0x73, 0x53, 0x73, 0x53, 0x00, 0x00, 0x73
};

// Each byte corresponds to a sprite priority for an event object.
// This is directly the inverse of gEventObjectPriorities_08376070.
static const u8 sEventObjectPriorities_08376060[] = {
    2, 2, 2, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 0, 0, 2
};

// Each byte corresponds to a sprite priority for an event object.
// This is the inverse of gEventObjectPriorities_08376060.
// 1 = Above player sprite
// 2 = Below player sprite
static const u8 sEventObjectPriorities_08376070[] = {
    1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 0, 0, 1,
};

void FieldObjectUpdateZCoordAndPriority(struct MapObject *eventObj, struct Sprite *sprite)
{
    if (eventObj->fixedPriority)
        return;

    FieldObjectUpdateZCoord(eventObj);

    sprite->subspriteTableNum = sEventObjectPriorities_08376070[eventObj->previousElevation];
    sprite->oam.priority = sEventObjectPriorities_08376060[eventObj->previousElevation];
}

static void InitObjectPriorityByZCoord(struct Sprite *sprite, u8 z)
{
    sprite->subspriteTableNum = sEventObjectPriorities_08376070[z];
    sprite->oam.priority = sEventObjectPriorities_08376060[z];
}

u8 ZCoordToPriority(u8 z)
{
    return sEventObjectPriorities_08376060[z];
}

void FieldObjectUpdateZCoord(struct MapObject *eventObj)
{
    u8 z = MapGridGetZCoordAt(eventObj->currentCoords.x, eventObj->currentCoords.y);
    u8 z2 = MapGridGetZCoordAt(eventObj->previousCoords.x, eventObj->previousCoords.y);

    if (z == 0xF || z2 == 0xF)
        return;

    eventObj->currentElevation = z;

    if (z != 0 && z != 0xF)
        eventObj->previousElevation = z;
}

void SetObjectSubpriorityByZCoord(u8 a, struct Sprite *sprite, u8 b)
{
    s32 tmp = sprite->centerToCornerVecY;
    u32 tmpa = *(u16 *)&sprite->pos1.y;
    u32 tmpb = *(u16 *)&gSpriteCoordOffsetY;
    s32 tmp2 = (tmpa - tmp) + tmpb;
    u16 tmp3 = (0x10 - ((((u32)tmp2 + 8) & 0xFF) >> 4)) * 2;
    sprite->subpriority = tmp3 + sUnknown_08376050[a] + b;
}

static void FieldObjectUpdateSubpriority(struct MapObject *eventObj, struct Sprite *sprite)
{
    if (eventObj->fixedPriority)
        return;

    SetObjectSubpriorityByZCoord(eventObj->previousElevation, sprite, 1);
}

bool8 AreZCoordsCompatible(u8 a, u8 b)
{
    if (a == 0 || b == 0)
        return TRUE;

    if (a != b)
        return FALSE;

    return TRUE;
}

void GroundEffect_SpawnOnTallGrass(struct MapObject *eventObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = eventObj->currentCoords.x;
    gFieldEffectArguments[1] = eventObj->currentCoords.y;
    gFieldEffectArguments[2] = eventObj->previousElevation;
    gFieldEffectArguments[3] = 2;
    gFieldEffectArguments[4] = eventObj->localId << 8 | eventObj->mapNum;
    gFieldEffectArguments[5] = eventObj->mapGroup;
    gFieldEffectArguments[6] = (u8)gSaveBlock1Ptr->location.mapNum << 8 | (u8)gSaveBlock1Ptr->location.mapGroup;
    gFieldEffectArguments[7] = 1;
    FieldEffectStart(FLDEFF_TALL_GRASS);
}

void GroundEffect_StepOnTallGrass(struct MapObject *eventObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = eventObj->currentCoords.x;
    gFieldEffectArguments[1] = eventObj->currentCoords.y;
    gFieldEffectArguments[2] = eventObj->previousElevation;
    gFieldEffectArguments[3] = 2;
    gFieldEffectArguments[4] = eventObj->localId << 8 | eventObj->mapNum;
    gFieldEffectArguments[5] = eventObj->mapGroup;
    gFieldEffectArguments[6] = (u8)gSaveBlock1Ptr->location.mapNum << 8 | (u8)gSaveBlock1Ptr->location.mapGroup;
    gFieldEffectArguments[7] = 0;
    FieldEffectStart(FLDEFF_TALL_GRASS);
}

void GroundEffect_SpawnOnLongGrass(struct MapObject *eventObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = eventObj->currentCoords.x;
    gFieldEffectArguments[1] = eventObj->currentCoords.y;
    gFieldEffectArguments[2] = eventObj->previousElevation;
    gFieldEffectArguments[3] = 2;
    gFieldEffectArguments[4] = eventObj->localId << 8 | eventObj->mapNum;
    gFieldEffectArguments[5] = eventObj->mapGroup;
    gFieldEffectArguments[6] = (u8)gSaveBlock1Ptr->location.mapNum << 8 | (u8)gSaveBlock1Ptr->location.mapGroup;
    gFieldEffectArguments[7] = 1;
    FieldEffectStart(FLDEFF_LONG_GRASS);
}

void GroundEffect_StepOnLongGrass(struct MapObject *eventObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = eventObj->currentCoords.x;
    gFieldEffectArguments[1] = eventObj->currentCoords.y;
    gFieldEffectArguments[2] = eventObj->previousElevation;
    gFieldEffectArguments[3] = 2;
    gFieldEffectArguments[4] = (eventObj->localId << 8) | eventObj->mapNum;
    gFieldEffectArguments[5] = eventObj->mapGroup;
    gFieldEffectArguments[6] = (u8)gSaveBlock1Ptr->location.mapNum << 8 | (u8)gSaveBlock1Ptr->location.mapGroup;
    gFieldEffectArguments[7] = 0;
    FieldEffectStart(FLDEFF_LONG_GRASS);
}

void GroundEffect_WaterReflection(struct MapObject *eventObj, struct Sprite *sprite)
{
    SetUpReflection(eventObj, sprite, 0);
}

void GroundEffect_IceReflection(struct MapObject *eventObj, struct Sprite *sprite)
{
    SetUpReflection(eventObj, sprite, 1);
}

void GroundEffect_FlowingWater(struct MapObject *eventObj, struct Sprite *sprite)
{
    StartFieldEffectForEventObject(FLDEFF_FEET_IN_FLOWING_WATER, eventObj);
}

static void (*const sGroundEffectTracksFuncs[])(struct MapObject *eventObj, struct Sprite *sprite, u8 a) = {
    DoTracksGroundEffect_None,
    DoTracksGroundEffect_Footprints,
    DoTracksGroundEffect_BikeTireTracks,
};

void GroundEffect_SandTracks(struct MapObject *eventObj, struct Sprite *sprite)
{
    const struct MapObjectGraphicsInfo *info = GetFieldObjectGraphicsInfo(eventObj->graphicsId);
    sGroundEffectTracksFuncs[info->tracks](eventObj, sprite, 0);
}

void GroundEffect_DeepSandTracks(struct MapObject *eventObj, struct Sprite *sprite)
{
    const struct MapObjectGraphicsInfo *info = GetFieldObjectGraphicsInfo(eventObj->graphicsId);
    sGroundEffectTracksFuncs[info->tracks](eventObj, sprite, 1);
}

static void DoTracksGroundEffect_None(struct MapObject *eventObj, struct Sprite *sprite, u8 a)
{
}

static void DoTracksGroundEffect_Footprints(struct MapObject *eventObj, struct Sprite *sprite, u8 a)
{
    // First half-word is a Field Effect script id. (gFieldEffectScriptPointers)
    u16 sandFootprints_FieldEffectData[2] = {
        FLDEFF_SAND_FOOTPRINTS,
        FLDEFF_DEEP_SAND_FOOTPRINTS
    };

    gFieldEffectArguments[0] = eventObj->previousCoords.x;
    gFieldEffectArguments[1] = eventObj->previousCoords.y;
    gFieldEffectArguments[2] = 149;
    gFieldEffectArguments[3] = 2;
    gFieldEffectArguments[4] = eventObj->facingDirection;
    FieldEffectStart(sandFootprints_FieldEffectData[a]);
}

static void DoTracksGroundEffect_BikeTireTracks(struct MapObject *eventObj, struct Sprite *sprite, u8 a)
{
    //  Specifies which bike track shape to show next.
    //  For example, when the bike turns from up to right, it will show
    //  a track that curves to the right.
    //  Each 4-byte row corresponds to the initial direction of the bike, and
    //  each byte in that row is for the next direction of the bike in the order
    //  of down, up, left, right.
    static const u8 bikeTireTracks_Transitions[4][4] = {
        1, 2, 7, 8,
        1, 2, 6, 5,
        5, 8, 3, 4,
        6, 7, 3, 4,
    };

    if (eventObj->currentCoords.x != eventObj->previousCoords.x || eventObj->currentCoords.y != eventObj->previousCoords.y)
    {
        gFieldEffectArguments[0] = eventObj->previousCoords.x;
        gFieldEffectArguments[1] = eventObj->previousCoords.y;
        gFieldEffectArguments[2] = 149;
        gFieldEffectArguments[3] = 2;
        gFieldEffectArguments[4] =
            bikeTireTracks_Transitions[eventObj->previousMovementDirection][eventObj->facingDirection - 5];
        FieldEffectStart(FLDEFF_BIKE_TIRE_TRACKS);
    }
}

void GroundEffect_Ripple(struct MapObject *eventObj, struct Sprite *sprite)
{
    DoRippleFieldEffect(eventObj, sprite);
}

void GroundEffect_StepOnPuddle(struct MapObject *eventObj, struct Sprite *sprite)
{
    StartFieldEffectForEventObject(FLDEFF_SPLASH, eventObj);
}

void GroundEffect_SandHeap(struct MapObject *eventObj, struct Sprite *sprite)
{
    StartFieldEffectForEventObject(FLDEFF_SAND_PILE, eventObj);
}

void GroundEffect_JumpOnTallGrass(struct MapObject *eventObj, struct Sprite *sprite)
{
    u8 spriteId;

    gFieldEffectArguments[0] = eventObj->currentCoords.x;
    gFieldEffectArguments[1] = eventObj->currentCoords.y;
    gFieldEffectArguments[2] = eventObj->previousElevation;
    gFieldEffectArguments[3] = 2;
    FieldEffectStart(FLDEFF_JUMP_TALL_GRASS);

    spriteId = sub_81546C8(
        eventObj->localId, eventObj->mapNum, eventObj->mapGroup, eventObj->currentCoords.x, eventObj->currentCoords.y);

    if (spriteId == MAX_SPRITES)
        GroundEffect_SpawnOnTallGrass(eventObj, sprite);
}

void GroundEffect_JumpOnLongGrass(struct MapObject *eventObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = eventObj->currentCoords.x;
    gFieldEffectArguments[1] = eventObj->currentCoords.y;
    gFieldEffectArguments[2] = eventObj->previousElevation;
    gFieldEffectArguments[3] = 2;
    FieldEffectStart(FLDEFF_JUMP_LONG_GRASS);
}

void GroundEffect_JumpOnShallowWater(struct MapObject *eventObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = eventObj->currentCoords.x;
    gFieldEffectArguments[1] = eventObj->currentCoords.y;
    gFieldEffectArguments[2] = eventObj->previousElevation;
    gFieldEffectArguments[3] = sprite->oam.priority;
    FieldEffectStart(FLDEFF_JUMP_SMALL_SPLASH);
}

void GroundEffect_JumpOnWater(struct MapObject *eventObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = eventObj->currentCoords.x;
    gFieldEffectArguments[1] = eventObj->currentCoords.y;
    gFieldEffectArguments[2] = eventObj->previousElevation;
    gFieldEffectArguments[3] = sprite->oam.priority;
    FieldEffectStart(FLDEFF_JUMP_BIG_SPLASH);
}

void GroundEffect_JumpLandingDust(struct MapObject *eventObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = eventObj->currentCoords.x;
    gFieldEffectArguments[1] = eventObj->currentCoords.y;
    gFieldEffectArguments[2] = eventObj->previousElevation;
    gFieldEffectArguments[3] = sprite->oam.priority;
    FieldEffectStart(FLDEFF_DUST);
}

void GroundEffect_ShortGrass(struct MapObject *eventObj, struct Sprite *sprite)
{
    StartFieldEffectForEventObject(FLDEFF_SHORT_GRASS, eventObj);
}

void GroundEffect_HotSprings(struct MapObject *eventObj, struct Sprite *sprite)
{
    StartFieldEffectForEventObject(FLDEFF_HOT_SPRINGS_WATER, eventObj);
}

void GroundEffect_Seaweed(struct MapObject *eventObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = eventObj->currentCoords.x;
    gFieldEffectArguments[1] = eventObj->currentCoords.y;
    FieldEffectStart(FLDEFF_BUBBLES);
}

static void (*const sGroundEffectFuncs[])(struct MapObject *eventObj, struct Sprite *sprite) = {
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

/*static*/ void DoFlaggedGroundEffects(struct MapObject *eventObj, struct Sprite *sprite, u32 flags)
{
    u8 i;

    if (FieldObjectIsFarawayIslandMew(eventObj) == TRUE && !sub_81D4A58(eventObj))
        return;

    for (i = 0; i < ARRAY_COUNT(sGroundEffectFuncs); i++, flags >>= 1)
        if (flags & 1)
            sGroundEffectFuncs[i](eventObj, sprite);
}

void filters_out_some_ground_effects(struct MapObject *eventObj, u32 *flags)
{
    if (eventObj->disableCoveringGroundEffects)
    {
        eventObj->inShortGrass = 0;
        eventObj->inSandPile = 0;
        eventObj->inShallowFlowingWater = 0;
        eventObj->inHotSprings = 0;
        *flags &= ~(GROUND_EFFECT_FLAG_HOT_SPRINGS
                  | GROUND_EFFECT_FLAG_SHORT_GRASS
                  | GROUND_EFFECT_FLAG_SAND_PILE
                  | GROUND_EFFECT_FLAG_SHALLOW_FLOWING_WATER
                  | GROUND_EFFECT_FLAG_TALL_GRASS_ON_MOVE);
    }
}

void FilterOutStepOnPuddleGroundEffectIfJumping(struct MapObject *eventObj, u32 *flags)
{
    if (eventObj->landingJump)
        *flags &= ~GROUND_EFFECT_FLAG_PUDDLE;
}

static void DoGroundEffects_OnSpawn(struct MapObject *eventObj, struct Sprite *sprite)
{
    u32 flags;

    if (eventObj->triggerGroundEffectsOnMove)
    {
        flags = 0;
        FieldObjectUpdateZCoordAndPriority(eventObj, sprite);
        GetAllGroundEffectFlags_OnSpawn(eventObj, &flags);
        FieldObjectSetSpriteOamTableForLongGrass(eventObj, sprite);
        DoFlaggedGroundEffects(eventObj, sprite, flags);
        eventObj->triggerGroundEffectsOnMove = 0;
        eventObj->disableCoveringGroundEffects = 0;
    }
}

static void DoGroundEffects_OnBeginStep(struct MapObject *eventObj, struct Sprite *sprite)
{
    u32 flags;

    if (eventObj->triggerGroundEffectsOnMove)
    {
        flags = 0;
        FieldObjectUpdateZCoordAndPriority(eventObj, sprite);
        GetAllGroundEffectFlags_OnBeginStep(eventObj, &flags);
        FieldObjectSetSpriteOamTableForLongGrass(eventObj, sprite);
        filters_out_some_ground_effects(eventObj, &flags);
        DoFlaggedGroundEffects(eventObj, sprite, flags);
        eventObj->triggerGroundEffectsOnMove = 0;
        eventObj->disableCoveringGroundEffects = 0;
    }
}

static void DoGroundEffects_OnFinishStep(struct MapObject *eventObj, struct Sprite *sprite)
{
    u32 flags;

    if (eventObj->triggerGroundEffectsOnStop)
    {
        flags = 0;
        FieldObjectUpdateZCoordAndPriority(eventObj, sprite);
        GetAllGroundEffectFlags_OnFinishStep(eventObj, &flags);
        FieldObjectSetSpriteOamTableForLongGrass(eventObj, sprite);
        FilterOutStepOnPuddleGroundEffectIfJumping(eventObj, &flags);
        DoFlaggedGroundEffects(eventObj, sprite, flags);
        eventObj->triggerGroundEffectsOnStop = 0;
        eventObj->landingJump = 0;
    }
}

bool8 FreezeMapObject(struct MapObject *mapObject)
{
    if (mapObject->heldMovementActive || mapObject->frozen)
    {
        return TRUE;
    }
    else
    {
        mapObject->frozen = 1;
        mapObject->spriteAnimPausedBackup = gSprites[mapObject->spriteId].animPaused;
        mapObject->spriteAffineAnimPausedBackup = gSprites[mapObject->spriteId].affineAnimPaused;
        gSprites[mapObject->spriteId].animPaused = 1;
        gSprites[mapObject->spriteId].affineAnimPaused = 1;
        return FALSE;
    }
}

void FreezeMapObjects(void)
{
    u8 i;
    for (i = 0; i < MAP_OBJECTS_COUNT; i++)
        if (gMapObjects[i].active && i != gPlayerAvatar.mapObjectId)
            FreezeMapObject(&gMapObjects[i]);
}

void FreezeMapObjectsExceptOne(u8 a1)
{
    u8 i;
    for (i = 0; i < MAP_OBJECTS_COUNT; i++)
        if (i != a1 && gMapObjects[i].active && i != gPlayerAvatar.mapObjectId)
            FreezeMapObject(&gMapObjects[i]);
}

void npc_sync_anim_pause_bits(struct MapObject *mapObject)
{
    if (mapObject->active && mapObject->frozen)
    {
        mapObject->frozen = 0;
        gSprites[mapObject->spriteId].animPaused = mapObject->spriteAnimPausedBackup;
        gSprites[mapObject->spriteId].affineAnimPaused = mapObject->spriteAffineAnimPausedBackup;
    }
}

void UnfreezeMapObjects(void)
{
    u8 i;
    for (i = 0; i < MAP_OBJECTS_COUNT; i++)
        if (gMapObjects[i].active)
            npc_sync_anim_pause_bits(&gMapObjects[i]);
}

void little_step(struct Sprite *sprite, u8 dir)
{
    sprite->pos1.x += gDirectionToVectors[dir].x;
    sprite->pos1.y += gDirectionToVectors[dir].y;
}

void double_little_steps(struct Sprite *sprite, u8 dir)
{
    sprite->pos1.x += 2 * (u16) gDirectionToVectors[dir].x;
    sprite->pos1.y += 2 * (u16) gDirectionToVectors[dir].y;
}

void triple_little_steps(struct Sprite *sprite, u8 dir)
{
    sprite->pos1.x += 2 * (u16) gDirectionToVectors[dir].x + (u16) gDirectionToVectors[dir].x;
    sprite->pos1.y += 2 * (u16) gDirectionToVectors[dir].y + (u16) gDirectionToVectors[dir].y;
}

void quad_little_steps(struct Sprite *sprite, u8 dir)
{
    sprite->pos1.x += 4 * (u16) gDirectionToVectors[dir].x;
    sprite->pos1.y += 4 * (u16) gDirectionToVectors[dir].y;
}

void oct_little_steps(struct Sprite *sprite, u8 dir)
{
    sprite->pos1.x += 8 * (u16) gDirectionToVectors[dir].x;
    sprite->pos1.y += 8 * (u16) gDirectionToVectors[dir].y;
}

void oamt_npc_ministep_reset(struct Sprite *sprite, u8 a2, u8 a3)
{
    sprite->data[3] = a2;
    sprite->data[4] = a3;
    sprite->data[5] = 0;
}

bool8 obj_npc_ministep(struct Sprite *sprite)
{
    if (sprite->data[5] >= gUnknown_0850E768[sprite->data[4]])
        return FALSE;

    gUnknown_0850E754[sprite->data[4]][sprite->data[5]](sprite, sprite->data[3]);

    sprite->data[5]++;

    if (sprite->data[5] < gUnknown_0850E768[sprite->data[4]])
        return FALSE;

    return TRUE;
}

void sub_80976DC(struct Sprite *sprite, u8 a2)
{
    sprite->data[3] = a2;
    sprite->data[4] = 0;
    sprite->data[5] = 0;
}

bool8 sub_80976EC(struct Sprite *sprite)
{
    if (!(sprite->data[4] & 1))
    {
        little_step(sprite, sprite->data[3]);
        sprite->data[5]++;
    }

    sprite->data[4]++;

    if (sprite->data[5] > 15)
        return TRUE;
    else
        return FALSE;
}

// new helper added here in the middle. Perhaps Game Freak kept these organized in alphebetical order or some other heirarchy?

s16 sub_8097728(s16 a1)
{
    return gUnknown_0850E7BA[a1];
}

s16 sub_809773C(s16 a1)
{
    return gUnknown_0850E772[a1];
}

void sub_8097750(struct Sprite *sprite)
{
    sprite->data[6] = 0;
    sprite->data[7] = 0;
}

bool8 sub_8097758(struct Sprite *sprite)
{
    bool8 result = FALSE;

    switch(sprite->data[7])
    {
        case 0:
            sprite->pos2.x += sub_809773C(sprite->data[6]);
            sprite->pos2.y += sub_8097728(sprite->data[6]);
            break;
        case 1:
            sprite->pos2.x -= sub_809773C(0x47 - sprite->data[6]);
            sprite->pos2.y += sub_8097728(0x47 - sprite->data[6]);
            break;
        case 2:
            sprite->pos2.x -= sub_809773C(sprite->data[6]);
            sprite->pos2.y += sub_8097728(sprite->data[6]);
            break;
        case 3:
            sprite->pos2.x += sub_809773C(0x47 - sprite->data[6]);
            sprite->pos2.y += sub_8097728(0x47 - sprite->data[6]);
            break;
    }
    if(++sprite->data[6] == 0x48)
    {
        sprite->data[6] = 0;
        sprite->data[7]++;
    }
    if(sprite->data[7] == 0x4)
    {
        sprite->pos2.y = 0;
        sprite->pos2.x = 0;
        result = TRUE;
    }
    return result;
}

s16 sub_8097820(s16 a1, u8 a2)
{
    return gUnknown_0850E834[a2][a1];
}

void sub_809783C(struct Sprite *sprite, u8 a2, u8 a3, u8 a4)
{
    sprite->data[3] = a2;
    sprite->data[4] = a3;
    sprite->data[5] = a4;
    sprite->data[6] = 0;
}

u8 sub_809785C(struct Sprite *sprite)
{
    s16 v5[3];
    u8 v6[3];
    u8 v2;

    memcpy(v5, gUnknown_0850E840, 6); // TODO: get rid of memcpy
    memcpy(v6, gUnknown_0850E846, 3);
    v2 = 0;

    if (sprite->data[4])
        little_step(sprite, sprite->data[3]);

    sprite->pos2.y = sub_8097820(sprite->data[6] >> v6[sprite->data[4]], sprite->data[5]);

    sprite->data[6]++;

    if (sprite->data[6] == (v5[sprite->data[4]] >> 1))
        v2 = 1;

    if (sprite->data[6] >= v5[sprite->data[4]])
    {
        sprite->pos2.y = 0;
        v2 = -1;
    }

    return v2;
}

u8 sub_80978E4(struct Sprite *sprite)
{
    s16 v5[3];
    u8 v6[3];
    u8 v2;

    memcpy(v5, gUnknown_0850E84A, 6);
    memcpy(v6, gUnknown_0850E850, 3);
    v2 = 0;

    if (sprite->data[4] && !(sprite->data[6] & 1))
        little_step(sprite, sprite->data[3]);

    sprite->pos2.y = sub_8097820(sprite->data[6] >> v6[sprite->data[4]], sprite->data[5]);

    sprite->data[6]++;

    if (sprite->data[6] == (v5[sprite->data[4]] >> 1))
        v2 = 1;

    if (sprite->data[6] >= v5[sprite->data[4]])
    {
        sprite->pos2.y = 0;
        v2 = -1;
    }

    return v2;
}

void SetFieldObjectStepTimer(struct Sprite *sprite, s16 timer)
{
    sprite->data[3] = timer;
}

bool8 RunFieldObjectStepTimer(struct Sprite *sprite)
{
    sprite->data[3]--;

    if (sprite->data[3] == 0)
        return TRUE;
    else
        return FALSE;
}

void obj_anim_image_set_and_seek(struct Sprite *sprite, u8 a2, u8 a3)
{
    sprite->animNum = a2;
    sprite->animPaused = 0 ;
    SeekSpriteAnim(sprite, a3);
}

bool8 sub_80979BC(struct Sprite *sprite)
{
    if (sprite->animEnded)
        return TRUE;
    else
        return FALSE;
}

void sub_80979D4(struct Sprite *sprite, bool8 invisible)
{
    u16 x, y;
    s16 x2, y2;

    sprite->invisible = invisible;

    if (sprite->coordOffsetEnabled)
    {
        x = sprite->pos1.x + sprite->pos2.x + sprite->centerToCornerVecX + gSpriteCoordOffsetX;
        y = sprite->pos1.y + sprite->pos2.y + sprite->centerToCornerVecY + gSpriteCoordOffsetY;
    }
    else
    {
        x = sprite->pos1.x + sprite->pos2.x + sprite->centerToCornerVecX;
        y = sprite->pos1.y + sprite->pos2.y + sprite->centerToCornerVecY;
    }

    x2 = x - (sprite->centerToCornerVecX >> 1);
    y2 = y - (sprite->centerToCornerVecY >> 1);

    if ((s16)x > 255 || x2 < -16)
        sprite->invisible = 1;
    if ((s16)y > 175 || y2 < -16)
        sprite->invisible = 1;
}

void sub_8097AC8(struct Sprite *sprite)
{
    sub_8097D68(sprite);
    SetObjectSubpriorityByZCoord(sprite->data[1], sprite, 1);
    sub_80979D4(sprite, sprite->data[2]);
}

void sub_8097AF0(void)
{
    int i;

    for(i = 0; i < MAX_SPRITES; i++)
    {
        struct Sprite *sprite = &gSprites[i];
        if(sprite->inUse && sprite->callback == sub_8097AC8)
            DestroySprite(sprite);
    }
}

int sub_8097B2C(u8 var) // this should return a u8, because all that call this shifts to u8, but it wont match because it doesnt shift u8 at the end.
{
    int i;

    for(i = 0; i < MAX_SPRITES; i++)
    {
        struct Sprite *sprite = &gSprites[i];
        if(sprite->inUse && sprite->callback == sub_8097AC8 && (u8)sprite->data[0] == var)
            return i;
    }
    return MAX_SPRITES;
}

void sub_8097B78(u8 var1, u8 var2)
{
    u8 spriteId = sub_8097B2C(var1);

    if(spriteId != MAX_SPRITES)
        StartSpriteAnim(&gSprites[spriteId], FieldObjectDirectionToImageAnimId(var2));
}

void sub_8097BB4(u8 var1, u8 var2)
{
    int spriteId = sub_8097B2C(var1);

    if(spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        const struct MapObjectGraphicsInfo *gfxInfo = GetFieldObjectGraphicsInfo(var2);
        u16 tileNum = sprite->oam.tileNum;

        sprite->oam = *gfxInfo->oam;
        sprite->oam.tileNum = tileNum;
        sprite->oam.paletteNum = gfxInfo->paletteSlot;
        sprite->images = gfxInfo->images;

        if(gfxInfo->subspriteTables == NULL)
        {
            sprite->subspriteTables = NULL;
            sprite->subspriteTableNum = 0;
            sprite->subspriteMode = 0;
        }
        else
        {
            SetSubspriteTables(sprite, gfxInfo->subspriteTables);
            sprite->subspriteMode = 2;
        }
        StartSpriteAnim(sprite, 0);
    }
}

void sub_8097C44(u8 var, bool32 var2)
{
    u8 spriteId = sub_8097B2C(var);

    if(spriteId == MAX_SPRITES)
        return;

    if(var2)
        gSprites[spriteId].data[2] = 1;
    else
        gSprites[spriteId].data[2] = 0;
}

bool32 sub_8097C8C(u8 var)
{
    u8 spriteId = sub_8097B2C(var);

    if(spriteId == MAX_SPRITES)
        return FALSE;

    return (gSprites[spriteId].data[2] == TRUE);
}

void sub_8097CC4(u8 var1, u8 var2)
{
    u8 spriteId = sub_8097B2C(var1);

    if(spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].data[3] = var2;
        gSprites[spriteId].data[4] = 0;
    }
}

void sub_8097CF4(struct Sprite *sprite)
{
    switch(sprite->data[4])
    {
        case 0:
            sprite->pos2.y = 0;
            sprite->data[4]++;
        case 1:
            sprite->pos2.y -= 8;
            if(sprite->pos2.y == -160)
            {
                sprite->pos2.y = 0;
                sprite->data[2] = 1;
                sprite->data[3] = 0;
                sprite->data[4] = 0;
            }
    }
}

void sub_8097D30(struct Sprite *sprite)
{
    switch(sprite->data[4])
    {
        case 0:
            sprite->pos2.y = -160;
            sprite->data[4]++;
        case 1:
            sprite->pos2.y += 8;
            if(sprite->pos2.y == 0)
            {
                sprite->data[3] = 0;
                sprite->data[4] = 0;
            }
    }
}

static void sub_8097D68(struct Sprite *sprite)
{
    switch(sprite->data[3])
    {
        case 1:
            sub_8097D30(sprite);
            break;
        case 2:
            sub_8097CF4(sprite);
            break;
        case 0:
            break;
        default:
            sprite->data[3] = 0;
            break;
    }
}

bool32 sub_8097D9C(u8 var)
{
    u8 spriteId = sub_8097B2C(var);

    if(spriteId == MAX_SPRITES)
        return FALSE;

    if(gSprites[spriteId].data[3] != FALSE)
        return TRUE;

    return FALSE;
}

u32 StartFieldEffectForEventObject(u8 fieldEffectId, struct MapObject *mapObject)
{
    FieldObjectGetLocalIdAndMap(mapObject, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    return FieldEffectStart(fieldEffectId);
}

void DoShadowFieldEffect(struct MapObject *mapObject)
{
    if (!mapObject->hasShadow)
    {
        mapObject->hasShadow = 1;
        StartFieldEffectForEventObject(FLDEFF_SHADOW, mapObject);
    }
}

static void DoRippleFieldEffect(struct MapObject *mapObject, struct Sprite *sprite)
{
    const struct MapObjectGraphicsInfo *gfxInfo = GetFieldObjectGraphicsInfo(mapObject->graphicsId);
    gFieldEffectArguments[0] = sprite->pos1.x;
    gFieldEffectArguments[1] = sprite->pos1.y + (gfxInfo->height >> 1) - 2;
    gFieldEffectArguments[2] = 151;
    gFieldEffectArguments[3] = 3;
    FieldEffectStart(FLDEFF_RIPPLE);
}

bool32 sub_8097E50(struct MapObject *mapObject, struct Sprite *sprite)
{
    u32 one;
    bool32 ableToStore = FALSE;
    if (gUnknown_020375B8 == NULL)
    {
        gUnknown_020375B8 = AllocZeroed(0x14);
        gUnknown_020375B8[0] = mapObject->localId;
        // needed to match
        gUnknown_020375B8[16] = (one = 1);
        ableToStore = one;
    }
    else
    {
        u8 i;
        u8 firstFreeSlot;
        bool32 found;
        for (firstFreeSlot = 16, found = FALSE, i = 0; i < 16; i++)
        {
            if (firstFreeSlot == 16 && gUnknown_020375B8[i] == 0)
                firstFreeSlot = i;

            if (gUnknown_020375B8[i] == mapObject->localId)
            {
                found = TRUE;
                break;
            }
        }

        if (!found && firstFreeSlot != 16)
        {
            gUnknown_020375B8[firstFreeSlot] = mapObject->localId;
            gUnknown_020375B8[16]++;
            ableToStore = TRUE;
        }
    }

    if (ableToStore == TRUE)
    {
        mapObject->inanimate = TRUE;
        mapObject->facingDirectionLocked = TRUE;
    }

    sprite->data[2] = 1;
    return TRUE;
}

bool32 sub_8097EF0(struct MapObject *mapObject, struct Sprite *sprite)
{
    bool32 ableToStore;
    u8 id;

    sprite->data[2] = 1;
    if (gUnknown_020375B8 != NULL)
    {
        ableToStore = FALSE;
        id = sub_8097F78(mapObject);
        if (id != 16)
        {
            gUnknown_020375B8[id] = 0;
            gUnknown_020375B8[16]--;
            ableToStore = TRUE;
        }
        if (gUnknown_020375B8[16] == 0)
            FREE_AND_SET_NULL(gUnknown_020375B8);
        if (ableToStore == TRUE)
        {
            mapObject->inanimate = GetFieldObjectGraphicsInfo(mapObject->graphicsId)->inanimate;
            mapObject->facingDirectionLocked = 0;
            sprite->animPaused = 0;
        }
    }

    return TRUE;
}

u8 sub_8097F78(struct MapObject *mapObject)
{
    u8 i;

    for(i = 0; i < MAP_OBJECTS_COUNT; i++)
    {
        if(gUnknown_020375B8[i] == mapObject->localId)
            return i;
    }
    return MAP_OBJECTS_COUNT;
}

void sub_8097FA4(struct MapObject *mapObject)
{
    u8 taskId = CreateTask(sub_8097FE4, 0xFF);
    struct Task *task = &gTasks[taskId];

    StoreWordInTwoHalfwords(&task->data[0], (u32)mapObject);
    mapObject->warpArrowSpriteId = taskId;
    task->data[3] = 0xFFFF;
}

static void sub_8097FE4(u8 taskId)
{
    struct MapObject *mapObject;
    struct Sprite *sprite;
    struct Task *task = &gTasks[taskId];

    LoadWordFromTwoHalfwords(&task->data[0], (u32 *)&mapObject); // load the map object pointer.
    sprite = &gSprites[mapObject->spriteId];

    if(!(task->data[2] & 0x3))
        sprite->pos2.y += task->data[3];

    if(!(task->data[2] & 0xF))
        task->data[3] = -task->data[3];

    task->data[2]++;
}

void sub_8098044(u8 taskId)
{
    u32 word;
    struct Task *task = &gTasks[taskId];

    LoadWordFromTwoHalfwords(&task->data[0], &word); // huh??? why does it load a word that never gets used???
    DestroyTask(taskId);
}

void sub_8098074(u8 var1, u8 var2)
{
    u8 i;

    for(i = 0; i < MAP_OBJECTS_COUNT; i++)
    {
        if(i != var1 && i != var2 &&
            gMapObjects[i].active && i != gPlayerAvatar.mapObjectId)
                FreezeMapObject(&gMapObjects[i]);
    }
}

bool32 sub_80980C0(struct MapObject *mapObject, struct Sprite *sprite)
{
    sprite->pos2.y = 0;
    sprite->data[2]++;
    return FALSE;
}

bool32 sub_80980D0(struct MapObject *mapObject, struct Sprite *sprite)
{
    sprite->pos2.y -= 8;

    if(sprite->pos2.y == -160)
        sprite->data[2]++;
    return FALSE;
}

bool32 sub_80980F4(struct MapObject *mapObject, struct Sprite *sprite)
{
    sprite->pos2.y = -160;
    sprite->data[2]++;
    return FALSE;
}

bool32 sub_8098108(struct MapObject *mapObject, struct Sprite *sprite)
{
    sprite->pos2.y += 8;

    if(!sprite->pos2.y)
        sprite->data[2]++;
    return FALSE;
}

// though this function returns TRUE without doing anything, this header is required due to being in an array of functions which needs it.
bool32 sub_8098124(struct MapObject *mapObject, struct Sprite *sprite)
{
    return TRUE;
}
