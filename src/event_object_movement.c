#include "global.h"
#include "event_object_movement.h"
#include "berry.h"
#include "decoration.h"
#include "event_data.h"
#include "event_scripts.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_effect_helpers.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "malloc.h"
#include "mauville_old_man.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "palette.h"
#include "pokenav.h"
#include "random.h"
#include "rom_818CFC8.h"
#include "rom_81BE66C.h"
#include "sprite.h"
#include "trainer_see.h"
#include "util.h"
#include "constants/event_objects.h"

// this file was known as evobjmv.c in Game Freak's original source

extern u8 gUnknown_020375B4;
extern u16 gUnknown_020375B6;
extern u8 *gUnknown_020375B8;

static void sub_808D450(void);
static u8 GetEventObjectIdByLocalId(u8);
static u8 GetEventObjectIdByLocalIdAndMapInternal(u8, u8, u8);
static bool8 GetAvailableEventObjectSlot(u16, u8, u8, u8 *);
static void EventObjectHandleDynamicGraphicsId(struct EventObject *);
static void RemoveEventObjectInternal (struct EventObject *);
static u16 GetEventObjectFlagIdByEventObjectId(u8);
static void sub_8096518(struct EventObject *, struct Sprite *);
static void MakeObjectTemplateFromEventObjectTemplate(struct EventObjectTemplate *, struct SpriteTemplate *, const struct SubspriteTable **);
static void GetEventObjectMovingCameraOffset(s16 *, s16 *);
static struct EventObjectTemplate *GetEventObjectTemplateByLocalIdAndMap(u8, u8, u8);
static void sub_808E894(u16);
static void RemoveEventObjectIfOutsideView(struct EventObject *);
static void sub_808E1B8(u8, s16, s16);
static void SetPlayerAvatarEventObjectIdAndObjectId(u8, u8);
static void sub_808E38C(struct EventObject *);
static u8 sub_808E8F4(const struct SpritePalette *);
static u8 FindEventObjectPaletteIndexByTag(u16);
static void sub_808EAB0(u16, u8);
static bool8 EventObjectDoesZCoordMatch(struct EventObject *, u8);
static void ObjectCB_CameraObject(struct Sprite *);
static void CameraObject_0(struct Sprite *);
static void CameraObject_1(struct Sprite *);
static void CameraObject_2(struct Sprite *);
static struct EventObjectTemplate *FindEventObjectTemplateInArrayByLocalId(u8 localId, struct EventObjectTemplate *templates, u8 count);
static void npc_reset(struct EventObject *, struct Sprite *);
static void EventObjectSetRegularAnim(struct EventObject *, struct Sprite *, u8);

u8 sub_8093438(u32);
u8 sub_80934BC(u32);
u8 sub_8093514(u32);
u8 GetJumpLedgeAnimId(u32);
void sub_8092F88(u32, s16 *, s16 *, s16, s16);

bool8 EventObjectExecRegularAnim(struct EventObject *, struct Sprite *);
static void SetEventObjectStepTimer(struct Sprite *, s16);
bool8 RunEventObjectStepTimer(struct Sprite *);
bool8 npc_block_way__next_tile(struct EventObject *, u8);
static u32 state_to_direction(u8, u32, u32);
/*static*/ void sub_80964E8(struct EventObject *, struct Sprite *);
static void EventObjectExecSpecialAnim(struct EventObject *, struct Sprite *);
/*static*/ void npc_obj_transfer_image_anim_pause_flag(struct EventObject *, struct Sprite *);

static bool8 IsCoordOutsideEventObjectMovementRect(struct EventObject *, s16, s16);
static bool8 IsMetatileDirectionallyImpassable(struct EventObject *, s16, s16, u8);
static bool8 CheckForCollisionBetweenEventObjects(struct EventObject *, s16, s16);
bool8 sub_809558C(struct EventObject *, struct Sprite *);
bool8 sub_8095B64(struct EventObject *, struct Sprite *);
static void sub_8096530(struct EventObject *, struct Sprite *);
static void npc_update_obj_anim_flag(struct EventObject *, struct Sprite *);
static void EventObjectUpdateMetatileBehaviors(struct EventObject*);
static void GetGroundEffectFlags_Reflection(struct EventObject*, u32*);
static void GetGroundEffectFlags_TallGrassOnSpawn(struct EventObject*, u32*);
static void GetGroundEffectFlags_LongGrassOnSpawn(struct EventObject*, u32*);
static void GetGroundEffectFlags_SandHeap(struct EventObject*, u32*);
static void GetGroundEffectFlags_ShallowFlowingWater(struct EventObject*, u32*);
static void GetGroundEffectFlags_ShortGrass(struct EventObject*, u32*);
static void GetGroundEffectFlags_HotSprings(struct EventObject*, u32*);
static void GetGroundEffectFlags_TallGrassOnBeginStep(struct EventObject*, u32*);
static void GetGroundEffectFlags_LongGrassOnBeginStep(struct EventObject*, u32*);
static void GetGroundEffectFlags_Tracks(struct EventObject*, u32*);
static void GetGroundEffectFlags_Puddle(struct EventObject*, u32*);
static void GetGroundEffectFlags_Ripple(struct EventObject*, u32*);
static void GetGroundEffectFlags_Seaweed(struct EventObject*, u32*);
static void GetGroundEffectFlags_JumpLanding(struct EventObject*, u32*);
static u8 EventObjectCheckForReflectiveSurface(struct EventObject*);
static u8 GetReflectionTypeByMetatileBehavior(u32);
static void InitObjectPriorityByZCoord(struct Sprite *sprite, u8 z);
static void EventObjectUpdateSubpriority(struct EventObject*, struct Sprite*);
static void DoTracksGroundEffect_None(struct EventObject*, struct Sprite*, u8);
static void DoTracksGroundEffect_Footprints(struct EventObject*, struct Sprite*, u8);
static void DoTracksGroundEffect_BikeTireTracks(struct EventObject*, struct Sprite*, u8);
static void DoRippleFieldEffect(struct EventObject*, struct Sprite*);
static void DoGroundEffects_OnSpawn(struct EventObject*, struct Sprite*);
static void DoGroundEffects_OnBeginStep(struct EventObject*, struct Sprite*);
static void DoGroundEffects_OnFinishStep(struct EventObject*, struct Sprite*);
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
    EventObjectCB_NoMovement1,
    EventObjectCB_LookRandomDirections,
    EventObjectCB_GoRandomDirections,
    EventObjectCB_RandomlyGoNorthOrSouth,
    EventObjectCB_RandomlyGoNorthOrSouth,
    EventObjectCB_RandomlyGoEastOrWest,
    EventObjectCB_RandomlyGoEastOrWest,
    EventObjectCB_FaceFixedDirection,
    EventObjectCB_FaceFixedDirection,
    EventObjectCB_FaceFixedDirection,
    EventObjectCB_FaceFixedDirection,
    EventObjectCB_NoMovement2,
    EventObjectCB_BerryTree,
    EventObjectCB_RandomlyLookNorthOrSouth,
    EventObjectCB_RandomlyLookEastOrWest,
    EventObjectCB_RandomlyLookNorthOrWest,
    EventObjectCB_RandomlyLookNorthOrEast,
    EventObjectCB_RandomlyLookSouthOrWest,
    EventObjectCB_RandomlyLookSouthOrEast,
    EventObjectCB_RandomlyLookNorthOrSouthOrWest,
    EventObjectCB_RandomlyLookNorthOrSouthOrEast,
    EventObjectCB_RandomlyLookNorthOrEastOrWest,
    EventObjectCB_RandomlyLookSouthOrEastOrWest,
    EventObjectCB_LookAroundCounterclockwise,
    EventObjectCB_LookAroundClockwise,
    EventObjectCB_AlternatelyGoInOppositeDirections,
    EventObjectCB_AlternatelyGoInOppositeDirections,
    EventObjectCB_AlternatelyGoInOppositeDirections,
    EventObjectCB_AlternatelyGoInOppositeDirections,
    EventObjectCB_GoInDirectionSequence1,
    EventObjectCB_GoInDirectionSequence2,
    EventObjectCB_GoInDirectionSequence3,
    EventObjectCB_GoInDirectionSequence4,
    EventObjectCB_GoInDirectionSequence5,
    EventObjectCB_GoInDirectionSequence6,
    EventObjectCB_GoInDirectionSequence7,
    EventObjectCB_GoInDirectionSequence8,
    EventObjectCB_GoInDirectionSequence9,
    EventObjectCB_GoInDirectionSequence10,
    EventObjectCB_GoInDirectionSequence11,
    EventObjectCB_GoInDirectionSequence12,
    EventObjectCB_GoInDirectionSequence13,
    EventObjectCB_GoInDirectionSequence14,
    EventObjectCB_GoInDirectionSequence15,
    EventObjectCB_GoInDirectionSequence16,
    EventObjectCB_GoInDirectionSequence17,
    EventObjectCB_GoInDirectionSequence18,
    EventObjectCB_GoInDirectionSequence19,
    EventObjectCB_GoInDirectionSequence20,
    EventObjectCB_GoInDirectionSequence21,
    EventObjectCB_GoInDirectionSequence22,
    EventObjectCB_GoInDirectionSequence23,
    EventObjectCB_GoInDirectionSequence24,
    EventObjectCB_CopyPlayer1,
    EventObjectCB_CopyPlayer1,
    EventObjectCB_CopyPlayer1,
    EventObjectCB_CopyPlayer1,
    EventObjectCB_TreeDisguise,
    EventObjectCB_MountainDisguise,
    EventObjectCB_CopyPlayer2,
    EventObjectCB_CopyPlayer2,
    EventObjectCB_CopyPlayer2,
    EventObjectCB_CopyPlayer2,
    EventObjectCB_Hidden1,
    EventObjectCB_WalkInPlace1,
    EventObjectCB_WalkInPlace1,
    EventObjectCB_WalkInPlace1,
    EventObjectCB_WalkInPlace1,
    EventObjectCB_WalkInPlace2,
    EventObjectCB_WalkInPlace2,
    EventObjectCB_WalkInPlace2,
    EventObjectCB_WalkInPlace2,
    EventObjectCB_WalkInPlace3,
    EventObjectCB_WalkInPlace3,
    EventObjectCB_WalkInPlace3,
    EventObjectCB_WalkInPlace3,
    EventObjectCB_Hidden2,
    EventObjectCB_WalkInPlace4,
    EventObjectCB_WalkInPlace4,
    EventObjectCB_WalkInPlace4,
    EventObjectCB_WalkInPlace4,
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
    {gEventObjectPalette0,  0x1103},
    {gEventObjectPalette1,  0x1104},
    {gEventObjectPalette2,  0x1105},
    {gEventObjectPalette3,  0x1106},
    {gEventObjectPalette4,  0x1107},
    {gEventObjectPalette5,  0x1108},
    {gEventObjectPalette6,  0x1109},
    {gEventObjectPalette7,  0x110A},
    {gEventObjectPalette8,  0x1100},
    {gEventObjectPalette9,  0x1101},
    {gEventObjectPalette10, 0x1102},
    {gEventObjectPalette11, 0x1115},
    {gEventObjectPalette12, 0x110B},
    {gEventObjectPalette13, 0x110C},
    {gEventObjectPalette14, 0x110D},
    {gEventObjectPalette15, 0x110E},
    {gEventObjectPalette16, 0x110F},
    {gEventObjectPalette17, 0x1110},
    {gEventObjectPalette18, 0x1111},
    {gEventObjectPalette19, 0x1112},
    {gEventObjectPalette20, 0x1113},
    {gEventObjectPalette21, 0x1114},
    {gEventObjectPalette22, 0x1116},
    {gEventObjectPalette23, 0x1117},
    {gEventObjectPalette24, 0x1118},
    {gEventObjectPalette25, 0x1119},
    {gEventObjectPalette26, 0x111B},
    {gEventObjectPalette27, 0x111C},
    {gEventObjectPalette28, 0x111D},
    {gEventObjectPalette29, 0x111E},
    {gEventObjectPalette30, 0x111F},
    {gEventObjectPalette31, 0x1120},
    {gEventObjectPalette32, 0x1121},
    {gEventObjectPalette33, 0x1122},
    {gEventObjectPalette34, 0x1123},
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

static void npc_clear_ids_and_state(struct EventObject *eventObject)
{
    *eventObject = (struct EventObject){};
    eventObject->localId = 0xFF;
    eventObject->mapNum = -1;
    eventObject->mapGroup = -1;
    eventObject->movementActionId = -1;
}

static void npcs_clear_ids_and_state(void)
{
    u8 i;

    for (i = 0; i < NUM_EVENT_OBJECTS; i ++)
    {
        npc_clear_ids_and_state(&gEventObjects[i]);
    }
}

void sub_808D438(void)
{
    ZeroAllLinkPlayerEventObjects();
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

    for (i = 0; i < NUM_EVENT_OBJECTS; i ++)
    {
        if (!gEventObjects[i].active)
        {
            break;
        }
    }
    return i;
}

u8 GetEventObjectIdByLocalIdAndMap(u8 localId, u8 mapId, u8 mapGroupId)
{
    if (localId < 0xff)
    {
        return GetEventObjectIdByLocalIdAndMapInternal(localId, mapId, mapGroupId);
    }
    return GetEventObjectIdByLocalId(localId);
}

bool8 TryGetEventObjectIdByLocalIdAndMap(u8 localId, u8 mapId, u8 mapGroupId, u8 *eventObjectId)
{
    *eventObjectId = GetEventObjectIdByLocalIdAndMap(localId, mapId, mapGroupId);
    if (*eventObjectId == NUM_EVENT_OBJECTS)
    {
        return TRUE;
    }
    return FALSE;
}

u8 GetEventObjectIdByXY(s16 x, s16 y)
{
    u8 i;

    for (i = 0; i < NUM_EVENT_OBJECTS; i ++)
    {
        if (gEventObjects[i].active && gEventObjects[i].currentCoords.x == x && gEventObjects[i].currentCoords.y == y)
        {
            break;
        }
    }
    return i;
}

static u8 GetEventObjectIdByLocalIdAndMapInternal(u8 localId, u8 mapId, u8 mapGroupId)
{
    u8 i;

    for (i = 0; i < NUM_EVENT_OBJECTS; i ++)
    {
        if (gEventObjects[i].active && gEventObjects[i].localId == localId && gEventObjects[i].mapNum == mapId && gEventObjects[i].mapGroup == mapGroupId)
        {
            return i;
        }
    }
    return NUM_EVENT_OBJECTS;
}

static u8 GetEventObjectIdByLocalId(u8 localId)
{
    u8 i;

    for (i = 0; i < NUM_EVENT_OBJECTS; i ++)
    {
        if (gEventObjects[i].active && gEventObjects[i].localId == localId)
        {
            return i;
        }
    }
    return NUM_EVENT_OBJECTS;
}

// This function has the same nonmatching quirk as in Ruby/Sapphire.
#ifdef NONMATCHING
static u8 InitEventObjectStateFromTemplate(struct EventObjectTemplate *template, u8 mapNum, u8 mapGroup)
{
    struct EventObject *eventObject;
    s16 x;
    s16 y;
    u8 slot;

    // mapNum and mapGroup are in the wrong registers (r7/r6 instead of r6/r7)
    if (GetAvailableEventObjectSlot(template->localId, mapNum, mapGroup, &slot))
    {
        return NUM_EVENT_OBJECTS;
    }
    eventObject = &gEventObjects[slot];
    npc_clear_ids_and_state(eventObject);
    x = template->x + 7;
    y = template->y + 7;
    eventObject->active = TRUE;
    eventObject->triggerGroundEffectsOnMove = TRUE;
    eventObject->graphicsId = template->graphicsId;
    eventObject->movementType = template->movementType;
    eventObject->localId = template->localId;
    eventObject->mapNum = mapNum;
    eventObject->mapGroup = mapGroup;
    eventObject->initialCoords.x = x;
    eventObject->initialCoords.y = y;
    eventObject->currentCoords.x = x;
    eventObject->currentCoords.y = y;
    eventObject->previousCoords.x = x;
    eventObject->previousCoords.y = y;
    eventObject->currentElevation = template->elevation;
    eventObject->previousElevation = template->elevation;
    // For some reason, 0x0F is placed in r9, to be used later
    eventObject->range.as_nybbles.x = template->movementRangeX;
    eventObject->range.as_nybbles.y = template->movementRangeY;
    eventObject->trainerType = template->trainerType;
    eventObject->trainerRange_berryTreeId = template->trainerRange_berryTreeId;
    eventObject->previousMovementDirection = gInitialMovementTypeFacingDirections[template->movementType];
    EventObjectSetDirection(eventObject, eventObject->previousMovementDirection);
    EventObjectHandleDynamicGraphicsId(eventObject);

    if (gRangedMovementTypes[eventObject->movementType])
    {
        if ((eventObject->range.as_nybbles.x) == 0)
        {
            // r9 is invoked here
            eventObject->range.as_nybbles.x ++;
        }
        if ((eventObject->range.as_nybbles.y) == 0)
        {
            eventObject->range.as_nybbles.y ++;
        }
    }
    return slot;
}
#else
static NAKED u8 InitEventObjectStateFromTemplate(struct EventObjectTemplate *template, u8 mapId, u8 mapGroupId)
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
                "\tbl GetAvailableEventObjectSlot\n"
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
                "\tldr r1, =gEventObjects\n"
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
                "\tbl EventObjectSetDirection\n"
                "\tadds r0, r4, 0\n"
                "\tbl EventObjectHandleDynamicGraphicsId\n"
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
    struct EventObjectTemplate *template;

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
            nObjects = gMapHeader.events->eventObjectCount;
        }
        for (i = 0; i < nObjects; i ++)
        {
            template = &gSaveBlock1Ptr->eventObjectTemplates[i];
            if (template->localId == localId && !FlagGet(template->flagId))
            {
                return InitEventObjectStateFromTemplate(template, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
            }
        }
    }
    return NUM_EVENT_OBJECTS;
}

static bool8 GetAvailableEventObjectSlot(u16 localId, u8 mapNum, u8 mapGroup, u8 *result)
// Looks for an empty slot.
// Returns FALSE and the location of the available slot
// in *result.
// If no slots are available, or if the object is already
// loaded, returns TRUE.
{
    u8 i = 0;

    for (i = 0; i < NUM_EVENT_OBJECTS; i ++)
    {
        if (!gEventObjects[i].active)
            break;
        if (gEventObjects[i].localId == localId && gEventObjects[i].mapNum == mapNum && gEventObjects[i].mapGroup == mapGroup)
            return TRUE;
    }
    if (i >= NUM_EVENT_OBJECTS)
        return TRUE;
    *result = i;
    do
    {
        if (gEventObjects[i].active && gEventObjects[i].localId == localId && gEventObjects[i].mapNum == mapNum && gEventObjects[i].mapGroup == mapGroup)
            return TRUE;
        i ++;
    } while (i < NUM_EVENT_OBJECTS);
    return FALSE;
}

static void RemoveEventObject(struct EventObject *eventObject)
{
    eventObject->active = FALSE;
    RemoveEventObjectInternal(eventObject);
}

void RemoveEventObjectByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 index;
    if (!TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &index))
    {
        FlagSet(GetEventObjectFlagIdByEventObjectId(index));
        RemoveEventObject(&gEventObjects[index]);
    }
}

static void RemoveEventObjectInternal(struct EventObject *eventObject)
{
    struct SpriteFrameImage image;
    image.size = GetEventObjectGraphicsInfo(eventObject->graphicsId)->size;
    gSprites[eventObject->spriteId].images = &image;
    DestroySprite(&gSprites[eventObject->spriteId]);
}

void unref_sub_808D958(void)
{
    u8 i;

    for (i = 0; i < NUM_EVENT_OBJECTS; i ++)
    {
        if (i != gPlayerAvatar.eventObjectId)
        {
            RemoveEventObject(&gEventObjects[i]);
        }
    }
}

static u8 SpawnEventObjectInternal(struct EventObjectTemplate *eventObjectTemplate, struct SpriteTemplate *spriteTemplate, u8 mapNum, u8 mapGroup, s16 cameraX, s16 cameraY)
{
    struct EventObject *eventObject;
    const struct EventObjectGraphicsInfo *graphicsInfo;
    struct Sprite *sprite;
    u8 eventObjectId;
    u8 paletteSlot;
    u8 spriteId;

    eventObjectId = InitEventObjectStateFromTemplate(eventObjectTemplate, mapNum, mapGroup);
    if (eventObjectId == NUM_EVENT_OBJECTS)
    {
        return NUM_EVENT_OBJECTS;
    }
    eventObject = &gEventObjects[eventObjectId];
    graphicsInfo = GetEventObjectGraphicsInfo(eventObject->graphicsId);
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
    if (eventObject->movementType == 0x4c)
    {
        eventObject->invisible = TRUE;
    }
    *(u16 *)&spriteTemplate->paletteTag = 0xFFFF;
    spriteId = CreateSprite(spriteTemplate, 0, 0, 0);
    if (spriteId == MAX_SPRITES)
    {
        gEventObjects[eventObjectId].active = FALSE;
        return NUM_EVENT_OBJECTS;
    }
    sprite = &gSprites[spriteId];
    sub_8092FF0(eventObject->currentCoords.x + cameraX, eventObject->currentCoords.y + cameraY, &sprite->pos1.x, &sprite->pos1.y);
    sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
    sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
    sprite->pos1.x += 8;
    sprite->pos1.y += 16 + sprite->centerToCornerVecY;
    sprite->oam.paletteNum = paletteSlot;
    sprite->coordOffsetEnabled = TRUE;
    sprite->data[0] = eventObjectId;
    eventObject->spriteId = spriteId;
    eventObject->inanimate = graphicsInfo->inanimate;
    if (!eventObject->inanimate)
    {
        StartSpriteAnim(sprite, EventObjectDirectionToImageAnimId(eventObject->facingDirection));
    }
    SetObjectSubpriorityByZCoord(eventObject->previousElevation, sprite, 1);
    sub_8096518(eventObject, sprite);
    return eventObjectId;
}

static u8 SpawnEventObject(struct EventObjectTemplate *eventObjectTemplate, u8 mapNum, u8 mapGroup, s16 cameraX, s16 cameraY)
{
    const struct EventObjectGraphicsInfo *graphicsInfo;
    struct SpriteTemplate spriteTemplate;
    const struct SubspriteTable *subspriteTables;
    struct SpriteFrameImage spriteFrameImage;
    u8 eventObjectId;

    subspriteTables = NULL;
    graphicsInfo = GetEventObjectGraphicsInfo(eventObjectTemplate->graphicsId);
    MakeObjectTemplateFromEventObjectTemplate(eventObjectTemplate, &spriteTemplate, &subspriteTables);
    spriteFrameImage.size = graphicsInfo->size;
    spriteTemplate.images = &spriteFrameImage;
    eventObjectId = SpawnEventObjectInternal(eventObjectTemplate, &spriteTemplate, mapNum, mapGroup, cameraX, cameraY);
    if (eventObjectId == NUM_EVENT_OBJECTS)
    {
        return NUM_EVENT_OBJECTS;
    }
    gSprites[gEventObjects[eventObjectId].spriteId].images = graphicsInfo->images;
    if (subspriteTables != NULL)
    {
        SetSubspriteTables(&gSprites[gEventObjects[eventObjectId].spriteId], subspriteTables);
    }
    return eventObjectId;
}

u8 SpawnSpecialEventObject(struct EventObjectTemplate *eventObjectTemplate)
{
    s16 cameraX;
    s16 cameraY;

    GetEventObjectMovingCameraOffset(&cameraX, &cameraY);
    return SpawnEventObject(eventObjectTemplate, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, cameraX, cameraY);
}

u8 SpawnSpecialEventObjectParametrized(u8 graphicsId, u8 movementBehavior, u8 localId, s16 x, s16 y, u8 z)
{
    struct EventObjectTemplate eventObjectTemplate;

    x -= 7;
    y -= 7;
    eventObjectTemplate.localId = localId;
    eventObjectTemplate.graphicsId = graphicsId;
    eventObjectTemplate.unk2 = 0;
    eventObjectTemplate.x = x;
    eventObjectTemplate.y = y;
    eventObjectTemplate.elevation = z;
    eventObjectTemplate.movementType = movementBehavior;
    eventObjectTemplate.movementRangeX = 0;
    eventObjectTemplate.movementRangeY = 0;
    eventObjectTemplate.trainerType = 0;
    eventObjectTemplate.trainerRange_berryTreeId = 0;
    return SpawnSpecialEventObject(&eventObjectTemplate);
}

u8 show_sprite(u8 localId, u8 mapNum, u8 mapGroup)
{
    struct EventObjectTemplate *eventObjectTemplate;
    s16 cameraX;
    s16 cameraY;

    eventObjectTemplate = GetEventObjectTemplateByLocalIdAndMap(localId, mapNum, mapGroup);
    if (eventObjectTemplate == NULL)
    {
        return NUM_EVENT_OBJECTS;
    }
    GetEventObjectMovingCameraOffset(&cameraX, &cameraY);
    return SpawnEventObject(eventObjectTemplate, mapNum, mapGroup, cameraX, cameraY);
}

static void MakeObjectTemplateFromEventObjectGraphicsInfo(u16 graphicsId, void (*callback)(struct Sprite *), struct SpriteTemplate *sprTemplate, const struct SubspriteTable **subspriteTables)
{
    const struct EventObjectGraphicsInfo *gfxInfo = GetEventObjectGraphicsInfo(graphicsId);

    sprTemplate->tileTag = gfxInfo->tileTag;
    sprTemplate->paletteTag = gfxInfo->paletteTag1;
    sprTemplate->oam = gfxInfo->oam;
    sprTemplate->anims = gfxInfo->anims;
    sprTemplate->images = gfxInfo->images;
    sprTemplate->affineAnims = gfxInfo->affineAnims;
    sprTemplate->callback = callback;
    *subspriteTables = gfxInfo->subspriteTables;
}

static void MakeObjectTemplateFromEventObjectGraphicsInfoWithCallbackIndex(u16 graphicsId, u16 callbackIndex, struct SpriteTemplate *sprTemplate, const struct SubspriteTable **subspriteTables)
{
    MakeObjectTemplateFromEventObjectGraphicsInfo(graphicsId, gUnknown_08505438[callbackIndex], sprTemplate, subspriteTables);
}

static void MakeObjectTemplateFromEventObjectTemplate(struct EventObjectTemplate *eventObjectTemplate, struct SpriteTemplate *spriteTemplate, const struct SubspriteTable **subspriteTables)
{
    MakeObjectTemplateFromEventObjectGraphicsInfoWithCallbackIndex(eventObjectTemplate->graphicsId, eventObjectTemplate->movementType, spriteTemplate, subspriteTables);
}

u8 AddPseudoEventObject(u16 graphicsId, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority)
{
    struct SpriteTemplate *spriteTemplate;
    const struct SubspriteTable *subspriteTables;
    struct Sprite *sprite;
    u8 spriteIdx;

    spriteTemplate = malloc(sizeof(struct SpriteTemplate));
    MakeObjectTemplateFromEventObjectGraphicsInfo(graphicsId, callback, spriteTemplate, &subspriteTables);
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
    const struct EventObjectGraphicsInfo *graphicsInfo;
    struct SpriteTemplate spriteTemplate;
    const struct SubspriteTable *subspriteTables;
    u8 spriteId;
    struct Sprite *sprite;

    graphicsInfo = GetEventObjectGraphicsInfo(graphicsId);
    MakeObjectTemplateFromEventObjectGraphicsInfo(graphicsId, sub_8097AC8, &spriteTemplate, &subspriteTables);
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
        StartSpriteAnim(sprite, EventObjectDirectionToImageAnimId(direction));
    }
    return spriteId;
}

void SpawnEventObjectsInView(s16 cameraX, s16 cameraY)
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
            objectCount = gMapHeader.events->eventObjectCount;
        }

        for (i = 0; i < objectCount; i++)
        {
            struct EventObjectTemplate *template = &gSaveBlock1Ptr->eventObjectTemplates[i];
            npcX = template->x + 7;
            npcY = template->y + 7;

            if (top <= npcY && bottom >= npcY && left <= npcX && right >= npcX
                && !FlagGet(template->flagId))
                SpawnEventObject(template, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, cameraX, cameraY);
        }
    }
}

/*static*/ void RemoveEventObjectsOutsideView(void)
{
    u8 i;
    u8 j;
    bool8 isActiveLinkPlayer;
    struct EventObject *eventObject;

    for (i = 0; i < NUM_EVENT_OBJECTS; i ++)
    {
        for (j = 0, isActiveLinkPlayer = FALSE; j < ARRAY_COUNT(gLinkPlayerEventObjects); j ++)
        {
            if (gLinkPlayerEventObjects[j].active && i == gLinkPlayerEventObjects[j].eventObjId)
                isActiveLinkPlayer = TRUE;
        }
        if (!isActiveLinkPlayer)
        {
            eventObject = &gEventObjects[i];

            if (eventObject->active && !eventObject->isPlayer)
                RemoveEventObjectIfOutsideView(eventObject);
        }
    }
}

static void RemoveEventObjectIfOutsideView(struct EventObject *eventObject)
{
    s16 left;
    s16 right;
    s16 top;
    s16 bottom;

    left = gSaveBlock1Ptr->pos.x - 2;
    right = gSaveBlock1Ptr->pos.x + 17;
    top = gSaveBlock1Ptr->pos.y;
    bottom = gSaveBlock1Ptr->pos.y + 16;

    if (eventObject->currentCoords.x >= left && eventObject->currentCoords.x <= right
        && eventObject->currentCoords.y >= top && eventObject->currentCoords.y <= bottom)
        return;
    if (eventObject->initialCoords.x >= left && eventObject->initialCoords.x <= right
        && eventObject->initialCoords.y >= top && eventObject->initialCoords.y <= bottom)
        return;
    RemoveEventObject(eventObject);
}

void sub_808E16C(s16 x, s16 y)
{
    u8 i;

    ClearPlayerAvatarInfo();
    for (i = 0; i < NUM_EVENT_OBJECTS; i ++)
    {
        if (gEventObjects[i].active)
        {
            sub_808E1B8(i, x, y);
        }
    }
    sub_808D450();
}

static void sub_808E1B8(u8 eventObjectId, s16 x, s16 y)
{
    u8 spriteId;
    u8 paletteSlot;
    struct EventObject *eventObject;
    const struct SubspriteTable *subspriteTables;
    const struct EventObjectGraphicsInfo *graphicsInfo;
    struct SpriteFrameImage spriteFrameImage;
    struct SpriteTemplate spriteTemplate;
    struct Sprite *sprite;

#define i spriteId
    for (i = 0; i < ARRAY_COUNT(gLinkPlayerEventObjects); i ++)
    {
        if (gLinkPlayerEventObjects[i].active && eventObjectId == gLinkPlayerEventObjects[i].eventObjId)
        {
            return;
        }
    }
#undef i

    eventObject = &gEventObjects[eventObjectId];
    subspriteTables = NULL;
    graphicsInfo = GetEventObjectGraphicsInfo(eventObject->graphicsId);
    spriteFrameImage.size = graphicsInfo->size;
    MakeObjectTemplateFromEventObjectGraphicsInfoWithCallbackIndex(eventObject->graphicsId, eventObject->movementType, &spriteTemplate, &subspriteTables);
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
        sub_8092FF0(x + eventObject->currentCoords.x, y + eventObject->currentCoords.y, &sprite->pos1.x, &sprite->pos1.y);
        sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
        sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
        sprite->pos1.x += 8;
        sprite->pos1.y += 16 + sprite->centerToCornerVecY;
        sprite->images = graphicsInfo->images;
        if (eventObject->movementType == 0x0b)
        {
            SetPlayerAvatarEventObjectIdAndObjectId(eventObjectId, spriteId);
            eventObject->warpArrowSpriteId = sub_8154228();
        }
        if (subspriteTables != NULL)
        {
            SetSubspriteTables(sprite, subspriteTables);
        }
        sprite->oam.paletteNum = paletteSlot;
        sprite->coordOffsetEnabled = TRUE;
        sprite->data[0] = eventObjectId;
        eventObject->spriteId = spriteId;
        if (!eventObject->inanimate && eventObject->movementType != 0x0b)
        {
            StartSpriteAnim(sprite, EventObjectDirectionToImageAnimId(eventObject->facingDirection));
        }
        sub_808E38C(eventObject);
        SetObjectSubpriorityByZCoord(eventObject->previousElevation, sprite, 1);
    }
}

static void sub_808E38C(struct EventObject *eventObject)
{
    eventObject->singleMovementActive = FALSE;
    eventObject->triggerGroundEffectsOnMove = TRUE;
    eventObject->hasShadow = FALSE;
    eventObject->hasReflection = FALSE;
    eventObject->inShortGrass = FALSE;
    eventObject->inShallowFlowingWater = FALSE;
    eventObject->inSandPile = FALSE;
    eventObject->inHotSprings = FALSE;
    EventObjectClearAnim(eventObject);
}

static void SetPlayerAvatarEventObjectIdAndObjectId(u8 eventObjectId, u8 spriteId)
{
    gPlayerAvatar.eventObjectId = eventObjectId;
    gPlayerAvatar.spriteId = spriteId;
    gPlayerAvatar.gender = GetPlayerAvatarGenderByGraphicsId(gEventObjects[eventObjectId].graphicsId);
    SetPlayerAvatarExtraStateTransition(gEventObjects[eventObjectId].graphicsId, 0x20);
}

void EventObjectSetGraphicsId(struct EventObject *eventObject, u8 graphicsId)
{
    const struct EventObjectGraphicsInfo *graphicsInfo;
    struct Sprite *sprite;
    u8 paletteSlot;

    graphicsInfo = GetEventObjectGraphicsInfo(graphicsId);
    sprite = &gSprites[eventObject->spriteId];
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
    eventObject->inanimate = graphicsInfo->inanimate;
    eventObject->graphicsId = graphicsId;
    sub_8093038(eventObject->currentCoords.x, eventObject->currentCoords.y, &sprite->pos1.x, &sprite->pos1.y);
    sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
    sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
    sprite->pos1.x += 8;
    sprite->pos1.y += 16 + sprite->centerToCornerVecY;
    if (eventObject->trackedByCamera)
    {
        CameraObjectReset1();
    }
}

void EventObjectSetGraphicsIdByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup, u8 graphicsId)
{
    u8 eventObjectId;

    if (!TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &eventObjectId))
    {
        EventObjectSetGraphicsId(&gEventObjects[eventObjectId], graphicsId);
    }
}

void EventObjectTurn(struct EventObject *eventObject, u8 direction)
{
    EventObjectSetDirection(eventObject, direction);
    if (!eventObject->inanimate)
    {
        StartSpriteAnim(&gSprites[eventObject->spriteId], EventObjectDirectionToImageAnimId(eventObject->facingDirection));
        SeekSpriteAnim(&gSprites[eventObject->spriteId], 0);
    }
}

void EventObjectTurnByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup, u8 direction)
{
    u8 eventObjectId;

    if (!TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &eventObjectId))
    {
        EventObjectTurn(&gEventObjects[eventObjectId], direction);
    }
}

void PlayerObjectTurn(struct PlayerAvatar *playerAvatar, u8 direction)
{
    EventObjectTurn(&gEventObjects[playerAvatar->eventObjectId], direction);
}

/*static*/ void get_berry_tree_graphics(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 berryStage;
    u8 berryId;

    eventObject->invisible = TRUE;
    sprite->invisible = TRUE;
    berryStage = GetStageByBerryTreeId(eventObject->trainerRange_berryTreeId);
    if (berryStage != 0)
    {
        eventObject->invisible = FALSE;
        sprite->invisible = FALSE;
        berryId = GetBerryTypeByBerryTreeId(eventObject->trainerRange_berryTreeId) - 1;
        berryStage -= 1;
        if (berryId >= NUM_BERRIES)
        {
            berryId = 0;
        }
        EventObjectSetGraphicsId(eventObject, gBerryTreeEventObjectGraphicsIdTablePointers[berryId][berryStage]);
        sprite->images = gBerryTreePicTablePointers[berryId];
        sprite->oam.paletteNum = gBerryTreePaletteSlotTablePointers[berryId][berryStage];
        StartSpriteAnim(sprite, berryStage);
    }
}

const struct EventObjectGraphicsInfo *GetEventObjectGraphicsInfo(u8 graphicsId)
{
    u8 bard;

    if (graphicsId >= SPRITE_VAR)
    {
        graphicsId = VarGetEventObjectGraphicsId(graphicsId - SPRITE_VAR);
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
    return gEventObjectGraphicsInfoPointers[graphicsId];
}

static void EventObjectHandleDynamicGraphicsId(struct EventObject *eventObject)
{
    if (eventObject->graphicsId >= SPRITE_VAR)
    {
        eventObject->graphicsId = VarGetEventObjectGraphicsId(eventObject->graphicsId - SPRITE_VAR);
    }
}

void npc_by_local_id_and_map_set_field_1_bit_x20(u8 localId, u8 mapNum, u8 mapGroup, u8 state)
{
    u8 eventObjectId;

    if (!TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &eventObjectId))
    {
        gEventObjects[eventObjectId].invisible = state;
    }
}

void EventObjectGetLocalIdAndMap(struct EventObject *eventObject, void *localId, void *mapNum, void *mapGroup)
{
    *(u8*)(localId) = eventObject->localId;
    *(u8*)(mapNum) = eventObject->mapNum;
    *(u8*)(mapGroup) = eventObject->mapGroup;
}

void sub_808E75C(s16 x, s16 y)
{
    u8 eventObjectId;
    struct EventObject *eventObject;

    eventObjectId = GetEventObjectIdByXY(x, y);
    if (eventObjectId != NUM_EVENT_OBJECTS)
    {
        eventObject = &gEventObjects[eventObjectId];
        eventObject->triggerGroundEffectsOnMove = TRUE;
    }
}

void sub_808E78C(u8 localId, u8 mapNum, u8 mapGroup, u8 subpriority)
{
    u8 eventObjectId;
    struct EventObject *eventObject;
    struct Sprite *sprite;

    if (!TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &eventObjectId))
    {
        eventObject = &gEventObjects[eventObjectId];
        sprite = &gSprites[eventObject->spriteId];
        eventObject->fixedPriority = TRUE;
        sprite->subpriority = subpriority;
    }
}

void sub_808E7E4(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 eventObjectId;
    struct EventObject *eventObject;

    if (!TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &eventObjectId))
    {
        eventObject = &gEventObjects[eventObjectId];
        eventObject->fixedPriority = FALSE;
        eventObject->triggerGroundEffectsOnMove = TRUE;
    }
}

void sub_808E82C(u8 localId, u8 mapNum, u8 mapGroup, s16 x, s16 y)
{
    u8 eventObjectId;
    struct Sprite *sprite;

    if (!TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &eventObjectId))
    {
        sprite = &gSprites[gEventObjects[eventObjectId].spriteId];
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

    paletteSlot = FindEventObjectPaletteIndexByTag(paletteTag);
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

    paletteIdx = FindEventObjectPaletteIndexByTag(paletteTag);
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

static u8 FindEventObjectPaletteIndexByTag(u16 tag)
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

void unref_sub_808EAC4(struct EventObject *eventObject, s16 x, s16 y)
{
    eventObject->previousCoords.x = eventObject->currentCoords.x;
    eventObject->previousCoords.y = eventObject->currentCoords.y;
    eventObject->currentCoords.x += x;
    eventObject->currentCoords.y += y;
}

void npc_coords_shift(struct EventObject *eventObject, s16 x, s16 y)
{
    eventObject->previousCoords.x = eventObject->currentCoords.x;
    eventObject->previousCoords.y = eventObject->currentCoords.y;
    eventObject->currentCoords.x = x;
    eventObject->currentCoords.y = y;
}

/*static*/ void npc_coords_set(struct EventObject *eventObject, s16 x, s16 y)
{
    eventObject->previousCoords.x = x;
    eventObject->previousCoords.y = y;
    eventObject->currentCoords.x = x;
    eventObject->currentCoords.y = y;
}

void sub_808EB08(struct EventObject *eventObject, s16 x, s16 y)
{
    struct Sprite *sprite;
    const struct EventObjectGraphicsInfo *graphicsInfo;

    sprite = &gSprites[eventObject->spriteId];
    graphicsInfo = GetEventObjectGraphicsInfo(eventObject->graphicsId);
    npc_coords_set(eventObject, x, y);
    sub_8093038(eventObject->currentCoords.x, eventObject->currentCoords.y, &sprite->pos1.x, &sprite->pos1.y);
    sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
    sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
    sprite->pos1.x += 8;
    sprite->pos1.y += 16 + sprite->centerToCornerVecY;
    sub_808E38C(eventObject);
    if (eventObject->trackedByCamera)
    {
        CameraObjectReset1();
    }
}

void sub_808EBA8(u8 localId, u8 mapNum, u8 mapGroup, s16 x, s16 y)
{
    u8 eventObjectId;

    if (!TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &eventObjectId))
    {
        x += 7;
        y += 7;
        sub_808EB08(&gEventObjects[eventObjectId], x, y);
    }
}

void npc_coords_shift_still(struct EventObject *eventObject)
{
    npc_coords_shift(eventObject, eventObject->currentCoords.x, eventObject->currentCoords.y);
}

void UpdateEventObjectCoordsForCameraUpdate(void)
{
    u8 i;
    s16 dx;
    s16 dy;

    if (gCamera.active)
    {
        dx = gCamera.x;
        dy = gCamera.y;
        for (i = 0; i < NUM_EVENT_OBJECTS; i ++)
        {
            if (gEventObjects[i].active)
            {
                gEventObjects[i].initialCoords.x -= dx;
                gEventObjects[i].initialCoords.y -= dy;
                gEventObjects[i].currentCoords.x -= dx;
                gEventObjects[i].currentCoords.y -= dy;
                gEventObjects[i].previousCoords.x -= dx;
                gEventObjects[i].previousCoords.y -= dy;
            }
        }
    }
}

u8 GetEventObjectIdByXYZ(u16 x, u16 y, u8 z)
{
    u8 i;
    for (i = 0; i < NUM_EVENT_OBJECTS; i ++)
    {
        if (gEventObjects[i].active)
        {
            if (gEventObjects[i].currentCoords.x == x && gEventObjects[i].currentCoords.y == y && EventObjectDoesZCoordMatch(&gEventObjects[i], z))
            {
                return i;
            }
        }
    }
    return NUM_EVENT_OBJECTS;
}

static bool8 EventObjectDoesZCoordMatch(struct EventObject *eventObject, u8 z)
{
    if (eventObject->currentElevation != 0 && z != 0 && eventObject->currentElevation != z)
    {
        return FALSE;
    }
    return TRUE;
}

void UpdateEventObjectsForCameraUpdate(s16 x, s16 y)
{
    UpdateEventObjectCoordsForCameraUpdate();
    SpawnEventObjectsInView(x, y);
    RemoveEventObjectsOutsideView();
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

void EventObjectSetDirection(struct EventObject *eventObject, u8 direction)
{
    s8 d2;
    eventObject->previousMovementDirection = eventObject->facingDirection;
    if (!eventObject->facingDirectionLocked)
    {
        d2 = direction;
        eventObject->facingDirection = d2;
    }
    eventObject->movementDirection = direction;
}

static const u8 *GetEventObjectScriptPointerByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    return GetEventObjectTemplateByLocalIdAndMap(localId, mapNum, mapGroup)->script;
}

const u8 *GetEventObjectScriptPointerByEventObjectId(u8 eventObjectId)
{
    return GetEventObjectScriptPointerByLocalIdAndMap(gEventObjects[eventObjectId].localId, gEventObjects[eventObjectId].mapNum, gEventObjects[eventObjectId].mapGroup);
}

static u16 GetEventObjectFlagIdByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    return GetEventObjectTemplateByLocalIdAndMap(localId, mapNum, mapGroup)->flagId;
}

static u16 GetEventObjectFlagIdByEventObjectId(u8 eventObjectId)
{
    return GetEventObjectFlagIdByLocalIdAndMap(gEventObjects[eventObjectId].localId, gEventObjects[eventObjectId].mapNum, gEventObjects[eventObjectId].mapGroup);
}

u8 sub_808F080(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 eventObjectId;

    if (TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &eventObjectId))
    {
        return 0xFF;
    }
    return gEventObjects[eventObjectId].trainerType;
}

u8 sub_808F0BC(u8 eventObjectId)
{
    return gEventObjects[eventObjectId].trainerType;
}

u8 sub_808F0D4(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 eventObjectId;

    if (TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &eventObjectId))
    {
        return 0xFF;
    }
    return gEventObjects[eventObjectId].trainerRange_berryTreeId;
}

u8 EventObjectGetBerryTreeId(u8 eventObjectId)
{
    return gEventObjects[eventObjectId].trainerRange_berryTreeId;
}

static struct EventObjectTemplate *GetEventObjectTemplateByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    struct EventObjectTemplate *templates;
    const struct MapHeader *mapHeader;
    u8 count;

    if (gSaveBlock1Ptr->location.mapNum == mapNum && gSaveBlock1Ptr->location.mapGroup == mapGroup)
    {
        templates = gSaveBlock1Ptr->eventObjectTemplates;
        count = gMapHeader.events->eventObjectCount;
    }
    else
    {
        mapHeader = Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum);
        templates = mapHeader->events->eventObjects;
        count = mapHeader->events->eventObjectCount;
    }
    return FindEventObjectTemplateInArrayByLocalId(localId, templates, count);
}

static struct EventObjectTemplate *FindEventObjectTemplateInArrayByLocalId(u8 localId, struct EventObjectTemplate *templates, u8 count)
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

struct EventObjectTemplate *sub_808F1B4(const struct EventObject *eventObject)
{
    int i;

    if (eventObject->mapNum != gSaveBlock1Ptr->location.mapNum || eventObject->mapGroup != gSaveBlock1Ptr->location.mapGroup)
    {
        return NULL;
    }
    for (i = 0; i < 64; i ++) // Using ARRAY_COUNT here results in the wrong conditional branch instruction (bls instead of ble)
    {
        if (eventObject->localId == gSaveBlock1Ptr->eventObjectTemplates[i].localId)
        {
            return &gSaveBlock1Ptr->eventObjectTemplates[i];
        }
    }
    return NULL;
}

void sub_808F208(const struct EventObject *eventObject)
{
    struct EventObjectTemplate *eventObjectTemplate;

    eventObjectTemplate = sub_808F1B4(eventObject);
    if (eventObjectTemplate != NULL)
    {
        eventObjectTemplate->x = eventObject->currentCoords.x - 7;
        eventObjectTemplate->y = eventObject->currentCoords.y - 7;
    }
}

void sub_808F228(const struct EventObject *eventObject, const u8 *script)
{
    struct EventObjectTemplate *eventObjectTemplate;

    eventObjectTemplate = sub_808F1B4(eventObject);
    if (eventObjectTemplate != NULL)
    {
        eventObjectTemplate->script = script;
    }
}

void sub_808F23C(const struct EventObject *eventObject, u8 movementType)
{
    struct EventObjectTemplate *eventObjectTemplate;

    eventObjectTemplate = sub_808F1B4(eventObject);
    if (eventObjectTemplate != NULL)
    {
        eventObjectTemplate->movementType = movementType;
    }
}

void sub_808F254(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 eventObjectId;

    if (!TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &eventObjectId))
    {
        sub_808F208(&gEventObjects[eventObjectId]);
    }
}

void sub_808F28C(u8 localId, u8 mapNum, u8 mapGroup, u8 decorCat)
{
    u8 eventObjectId;

    if (!TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &eventObjectId))
    {
        switch (decorCat)
        {
            case DECORCAT_DOLL:
                sub_808F228(&gEventObjects[eventObjectId], EventScript_2766A2);
                break;
            case DECORCAT_CUSHION:
                sub_808F228(&gEventObjects[eventObjectId], EventScript_2766A6);
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

bool8 sub_808F44C(struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_808F460(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_808F48C(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (!EventObjectExecRegularAnim(eventObject, sprite))
    {
        return FALSE;
    }
    SetEventObjectStepTimer(sprite, gMovementDelaysMedium[Random() & 0x03]);
    sprite->data[1] = 3;
    return TRUE;
}

bool8 sub_808F4C8(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (RunEventObjectStepTimer(sprite))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_808F4E8(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[4];
    u8 chosenDirection;

    memcpy(directions, gUnknown_0850D710, sizeof directions);
    chosenDirection = directions[Random() & 0x03];
    EventObjectSetDirection(eventObject, chosenDirection);
    sprite->data[1] = 5;
    if (npc_block_way__next_tile(eventObject, chosenDirection))
    {
        sprite->data[1] = 1;
    }
    return TRUE;
}

bool8 sub_808F534(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetRegularAnim(eventObject, sprite, GetGoSpeed0AnimId(eventObject->movementDirection));
    eventObject->singleMovementActive = TRUE;
    sprite->data[1] = 6;
    return TRUE;
}

bool8 sub_808F564(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        eventObject->singleMovementActive = FALSE;
        sprite->data[1] = 1;
    }
    return FALSE;
}

bool8 EventObjectIsTrainerAndCloseToPlayer(struct EventObject *eventObject)
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
    if (eventObject->trainerType != 1 && eventObject->trainerType != 3)
    {
        return FALSE;
    }
    PlayerGetDestCoords(&playerX, &playerY);
    objX = eventObject->currentCoords.x;
    objY = eventObject->currentCoords.y;
    minX = objX - eventObject->trainerRange_berryTreeId;
    minY = objY - eventObject->trainerRange_berryTreeId;
    maxX = objX + eventObject->trainerRange_berryTreeId;
    maxY = objY + eventObject->trainerRange_berryTreeId;
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

u8 GetRunningPastFacingDirection(struct EventObject *eventObject, u8 movementType)
{
    s16 dx;
    s16 dy;
    s16 absdx;
    s16 absdy;

    if (!EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        return 0;
    }
    PlayerGetDestCoords(&dx, &dy);
    dx -= eventObject->currentCoords.x;
    dy -= eventObject->currentCoords.y;
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

bool8 sub_808F988(struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_808F99C(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_808F9C8(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        SetEventObjectStepTimer(sprite, gMovementDelaysMedium[Random() & 0x03]);
        eventObject->singleMovementActive = FALSE;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_808FA0C(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (RunEventObjectStepTimer(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_808FA3C(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[4];
    u8 direction;

    memcpy(directions, gUnknown_0850D710, sizeof directions);
    direction = GetRunningPastFacingDirection(eventObject, RUNFOLLOW_ANY);
    if (direction == 0)
    {
        direction = directions[Random() & 0x03];
    }
    EventObjectSetDirection(eventObject, direction);
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(RandomlyGoNorthOrSouth, gUnknown_0850D754)

bool8 sub_808FAC8(struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_808FADC(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_808FB08(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (!EventObjectExecRegularAnim(eventObject, sprite))
    {
        return FALSE;
    }
    SetEventObjectStepTimer(sprite, gMovementDelaysMedium[Random() & 0x03]);
    sprite->data[1] = 3;
    return TRUE;
}

bool8 sub_808FB44(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (RunEventObjectStepTimer(sprite))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_808FB64(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[2];
    u8 direction;

    memcpy(directions, gUnknown_0850D770, sizeof directions);
    direction = directions[Random() & 0x01];
    EventObjectSetDirection(eventObject, direction);
    sprite->data[1] = 5;
    if (npc_block_way__next_tile(eventObject, direction))
    {
        sprite->data[1] = 1;
    }
    return TRUE;
}

bool8 sub_808FBB0(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetRegularAnim(eventObject, sprite, GetGoSpeed0AnimId(eventObject->movementDirection));
    eventObject->singleMovementActive = TRUE;
    sprite->data[1] = 6;
    return TRUE;
}

bool8 sub_808FBE0(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        eventObject->singleMovementActive = FALSE;
        sprite->data[1] = 1;
    }
    return FALSE;
}

field_object_step(RandomlyGoEastOrWest, gUnknown_0850D774)

bool8 sub_808FC4C(struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_808FC60(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_808FC8C(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (!EventObjectExecRegularAnim(eventObject, sprite))
    {
        return FALSE;
    }
    SetEventObjectStepTimer(sprite, gMovementDelaysMedium[Random() & 0x03]);
    sprite->data[1] = 3;
    return TRUE;
}

bool8 sub_808FCC8(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (RunEventObjectStepTimer(sprite))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_808FCE8(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[2];
    u8 direction;

    memcpy(directions, gUnknown_0850D790, sizeof directions);
    direction = directions[Random() & 0x01];
    EventObjectSetDirection(eventObject, direction);
    sprite->data[1] = 5;
    if (npc_block_way__next_tile(eventObject, direction))
    {
        sprite->data[1] = 1;
    }
    return TRUE;
}

bool8 sub_808FD34(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetRegularAnim(eventObject, sprite, GetGoSpeed0AnimId(eventObject->movementDirection));
    eventObject->singleMovementActive = TRUE;
    sprite->data[1] = 6;
    return TRUE;
}

bool8 sub_808FD64(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        eventObject->singleMovementActive = FALSE;
        sprite->data[1] = 1;
    }
    return FALSE;
}

field_object_step(FaceFixedDirection, gUnknown_0850D794)

bool8 sub_808FDD0(struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(eventObject->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_808FDFC(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        sprite->data[1] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_808FE1C(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->singleMovementActive = FALSE;
    return FALSE;
}

static bool8 EventObjectCB2_BerryTree(struct EventObject *eventObject, struct Sprite *sprite);
extern bool8 (*const gUnknown_0850D7A0[])(struct EventObject *eventObject, struct Sprite *sprite);
void EventObjectCB_BerryTree(struct Sprite *sprite)
{
    struct EventObject *eventObject;

    eventObject = &gEventObjects[sprite->data[0]];
    if (!(sprite->data[7] & 0x0001))
    {
        get_berry_tree_graphics(eventObject, sprite);
        sprite->data[7] |= 0x0001;
    }
    EventObjectStep(eventObject, sprite, EventObjectCB2_BerryTree);
}
static bool8 EventObjectCB2_BerryTree(struct EventObject *eventObject, struct Sprite *sprite)
{
    return gUnknown_0850D7A0[sprite->data[1]](eventObject, sprite);
}

bool8 do_berry_tree_growth_sparkle_1 (struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 berryStage;

    npc_reset(eventObject, sprite);
    eventObject->invisible = TRUE;
    sprite->invisible = TRUE;
    berryStage = GetStageByBerryTreeId(eventObject->trainerRange_berryTreeId);
    if (berryStage == 0)
    {
        if (!(sprite->data[7] & 0x0004) && sprite->animNum == 4)
        {
            gFieldEffectArguments[0] = eventObject->currentCoords.x;
            gFieldEffectArguments[1] = eventObject->currentCoords.y;
            gFieldEffectArguments[2] = sprite->subpriority - 1;
            gFieldEffectArguments[3] = sprite->oam.priority;
            FieldEffectStart(FLDEFF_BERRY_TREE_GROWTH_SPARKLE);
            sprite->animNum = berryStage;
        }
        return FALSE;
    }
    eventObject->invisible = FALSE;
    sprite->invisible = FALSE;
    berryStage --;
    if (sprite->animNum != berryStage)
    {
        sprite->data[1] = 2;
        return TRUE;
    }
    get_berry_tree_graphics(eventObject, sprite);
    EventObjectSetRegularAnim(eventObject, sprite, 0x39);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_808FF48 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        sprite->data[1] = 0;
        return TRUE;
    }
    return FALSE;
}

bool8 do_berry_tree_growth_sparkle_2 (struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->singleMovementActive = TRUE;
    sprite->data[1] = 3;
    sprite->data[2] = 0;
    sprite->data[7] |= 0x0002;
    gFieldEffectArguments[0] = eventObject->currentCoords.x;
    gFieldEffectArguments[1] = eventObject->currentCoords.y;
    gFieldEffectArguments[2] = sprite->subpriority - 1;
    gFieldEffectArguments[3] = sprite->oam.priority;
    FieldEffectStart(FLDEFF_BERRY_TREE_GROWTH_SPARKLE);
    return TRUE;
}

bool8 sub_808FFB4 (struct EventObject *eventObject, struct Sprite *sprite)
{
    sprite->data[2] ++;
    eventObject->invisible = (sprite->data[2] & 0x02) >> 1;
    sprite->animPaused = TRUE;
    if (sprite->data[2] > 64)
    {
        get_berry_tree_graphics(eventObject, sprite);
        sprite->data[1] = 4;
        sprite->data[2] = 0;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8090004 (struct EventObject *eventObject, struct Sprite *sprite)
{
    sprite->data[2] ++;
    eventObject->invisible = (sprite->data[2] & 0x02) >> 1;
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

bool8 sub_8090094 (struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_80900A8 (struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_80900D4 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        SetEventObjectStepTimer(sprite, gMovementDelaysMedium[Random() & 0x03]);
        eventObject->singleMovementActive = FALSE;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_8090118 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (RunEventObjectStepTimer(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8090148 (struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[2];
    u8 direction;

    memcpy(directions, gUnknown_0850D770, sizeof gUnknown_0850D770);
    direction = GetRunningPastFacingDirection(eventObject, RUNFOLLOW_NORTH_SOUTH);
    if (direction == 0)
    {
        direction = directions[Random() & 0x01];
    }
    EventObjectSetDirection(eventObject, direction);
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(RandomlyLookEastOrWest, gUnknown_0850D7C8)

bool8 sub_80901D4 (struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_80901E8 (struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8090214 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        SetEventObjectStepTimer(sprite, gMovementDelaysMedium[Random() & 0x03]);
        eventObject->singleMovementActive = FALSE;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_8090258 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (RunEventObjectStepTimer(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8090288 (struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[2];
    u8 direction;

    memcpy(directions, gUnknown_0850D790, sizeof gUnknown_0850D790);
    direction = GetRunningPastFacingDirection(eventObject, RUNFOLLOW_EAST_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 0x01];
    }
    EventObjectSetDirection(eventObject, direction);
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(RandomlyLookNorthOrWest, gUnknown_0850D7DC)

bool8 sub_8090314 (struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_8090328 (struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8090354 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        SetEventObjectStepTimer(sprite, gMovementDelaysShort[Random() & 0x03]);
        eventObject->singleMovementActive = FALSE;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_8090398 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (RunEventObjectStepTimer(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_80903C8 (struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[2];
    u8 direction;

    memcpy(directions, gUnknown_0850D7F0, sizeof gUnknown_0850D7F0);
    direction = GetRunningPastFacingDirection(eventObject, RUNFOLLOW_NORTH_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 0x01];
    }
    EventObjectSetDirection(eventObject, direction);
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(RandomlyLookNorthOrEast, gUnknown_0850D7F4)

bool8 sub_8090454 (struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_8090468 (struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8090494 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        SetEventObjectStepTimer(sprite, gMovementDelaysShort[Random() & 0x03]);
        eventObject->singleMovementActive = FALSE;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_80904D8 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (RunEventObjectStepTimer(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8090508 (struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[2];
    u8 direction;

    memcpy(directions, gUnknown_0850D808, sizeof gUnknown_0850D808);
    direction = GetRunningPastFacingDirection(eventObject, RUNFOLLOW_NORTH_EAST);
    if (direction == 0)
    {
        direction = directions[Random() & 0x01];
    }
    EventObjectSetDirection(eventObject, direction);
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(RandomlyLookSouthOrWest, gUnknown_0850D80C)

bool8 sub_8090594 (struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_80905A8 (struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_80905D4 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        SetEventObjectStepTimer(sprite, gMovementDelaysShort[Random() & 0x03]);
        eventObject->singleMovementActive = FALSE;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_8090618 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (RunEventObjectStepTimer(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8090648 (struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[2];
    u8 direction;

    memcpy(directions, gUnknown_0850D820, sizeof gUnknown_0850D820);
    direction = GetRunningPastFacingDirection(eventObject, RUNFOLLOW_SOUTH_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 0x01];
    }
    EventObjectSetDirection(eventObject, direction);
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(RandomlyLookSouthOrEast, gUnknown_0850D824)

bool8 sub_80906D4 (struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_80906E8 (struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8090714 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        SetEventObjectStepTimer(sprite, gMovementDelaysShort[Random() & 0x03]);
        eventObject->singleMovementActive = FALSE;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_8090758 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (RunEventObjectStepTimer(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8090788 (struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[2];
    u8 direction;

    memcpy(directions, gUnknown_0850D838, sizeof gUnknown_0850D838);
    direction = GetRunningPastFacingDirection(eventObject, RUNFOLLOW_SOUTH_EAST);
    if (direction == 0)
    {
        direction = directions[Random() & 0x01];
    }
    EventObjectSetDirection(eventObject, direction);
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(RandomlyLookNorthOrSouthOrWest, gUnknown_0850D83C)

bool8 sub_8090814 (struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_8090828 (struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8090854 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        SetEventObjectStepTimer(sprite, gMovementDelaysShort[Random() & 0x03]);
        eventObject->singleMovementActive = FALSE;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_8090898 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (RunEventObjectStepTimer(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_80908C8 (struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[4];
    u8 direction;

    memcpy(directions, gUnknown_0850D850, sizeof gUnknown_0850D850);
    direction = GetRunningPastFacingDirection(eventObject, RUNFOLLOW_NORTH_SOUTH_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 0x03];
    }
    EventObjectSetDirection(eventObject, direction);
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(RandomlyLookNorthOrSouthOrEast, gUnknown_0850D854)

bool8 sub_8090954 (struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_8090968 (struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8090994 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        SetEventObjectStepTimer(sprite, gMovementDelaysShort[Random() & 0x03]);
        eventObject->singleMovementActive = FALSE;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_80909D8 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (RunEventObjectStepTimer(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8090A08 (struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[4];
    u8 direction;

    memcpy(directions, gUnknown_0850D868, sizeof gUnknown_0850D868);
    direction = GetRunningPastFacingDirection(eventObject, RUNFOLLOW_NORTH_SOUTH_EAST);
    if (direction == 0)
    {
        direction = directions[Random() & 0x03];
    }
    EventObjectSetDirection(eventObject, direction);
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(RandomlyLookNorthOrEastOrWest, gUnknown_0850D86C)

bool8 sub_8090A94 (struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_8090AA8 (struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8090AD4 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        SetEventObjectStepTimer(sprite, gMovementDelaysShort[Random() & 0x03]);
        eventObject->singleMovementActive = FALSE;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_8090B18 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (RunEventObjectStepTimer(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8090B48 (struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[4];
    u8 direction;

    memcpy(directions, gUnknown_0850D880, sizeof gUnknown_0850D880);
    direction = GetRunningPastFacingDirection(eventObject, RUNFOLLOW_NORTH_EAST_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 0x03];
    }
    EventObjectSetDirection(eventObject, direction);
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(RandomlyLookSouthOrEastOrWest, gUnknown_0850D884)

bool8 sub_8090BD4 (struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_8090BE8 (struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8090C14 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        SetEventObjectStepTimer(sprite, gMovementDelaysShort[Random() & 0x03]);
        eventObject->singleMovementActive = FALSE;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_8090C58 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (RunEventObjectStepTimer(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8090C88 (struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[4];
    u8 direction;

    memcpy(directions, gUnknown_0850D898, sizeof gUnknown_0850D898);
    direction = GetRunningPastFacingDirection(eventObject, RUNFOLLOW_SOUTH_EAST_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 0x03];
    }
    EventObjectSetDirection(eventObject, direction);
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(LookAroundCounterclockwise, gUnknown_0850D89C)

bool8 sub_8090D14 (struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(eventObject->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_8090D40 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        SetEventObjectStepTimer(sprite, 48);
        sprite->data[1] = 2;
    }
    return FALSE;
}

bool8 sub_8090D64 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (RunEventObjectStepTimer(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_8090D90 (struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[5];
    u8 direction;

    memcpy(directions, gUnknown_0850D8AC, sizeof gUnknown_0850D8AC);
    direction = GetRunningPastFacingDirection(eventObject, RUNFOLLOW_ANY);
    if (direction == 0)
    {
        direction = directions[eventObject->facingDirection];
    }
    EventObjectSetDirection(eventObject, direction);
    sprite->data[1] = 0;
    return TRUE;
}

field_object_step(LookAroundClockwise, gUnknown_0850D8B4)

bool8 sub_8090E18 (struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(eventObject->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_8090E44 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        SetEventObjectStepTimer(sprite, 48);
        sprite->data[1] = 2;
    }
    return FALSE;
}

bool8 sub_8090E68 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (RunEventObjectStepTimer(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 sub_8090E94 (struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[5];
    u8 direction;

    memcpy(directions, gUnknown_0850D8C4, sizeof gUnknown_0850D8C4);
    direction = GetRunningPastFacingDirection(eventObject, RUNFOLLOW_ANY);
    if (direction == 0)
    {
        direction = directions[eventObject->facingDirection];
    }
    EventObjectSetDirection(eventObject, direction);
    sprite->data[1] = 0;
    return TRUE;
}

field_object_step(AlternatelyGoInOppositeDirections, gUnknown_0850D8CC)

bool8 sub_8090F1C (struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_8090F30 (struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 direction;

    direction = gInitialMovementTypeFacingDirections[eventObject->movementType];
    if (eventObject->directionSequenceIndex)
    {
        direction = GetOppositeDirection(direction);
    }
    EventObjectSetDirection(eventObject, direction);
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8090F68 (struct EventObject *eventObject, struct Sprite *sprite)
{
    bool8 blockingWay;
    u8 animId;

    if (eventObject->directionSequenceIndex && eventObject->initialCoords.x == eventObject->currentCoords.x && eventObject->initialCoords.y == eventObject->currentCoords.y)
    {
        eventObject->directionSequenceIndex = 0;
        EventObjectSetDirection(eventObject, GetOppositeDirection(eventObject->movementDirection));
    }
    blockingWay = npc_block_way__next_tile(eventObject, eventObject->movementDirection);
    animId = GetGoSpeed0AnimId(eventObject->movementDirection);
    if (blockingWay == TRUE)
    {
        eventObject->directionSequenceIndex ++;
        EventObjectSetDirection(eventObject, GetOppositeDirection(eventObject->movementDirection));
        animId = GetGoSpeed0AnimId(eventObject->movementDirection);
        blockingWay = npc_block_way__next_tile(eventObject, eventObject->movementDirection);
    }
    if (blockingWay)
    {
        animId = GetStepInPlaceDelay16AnimId(eventObject->facingDirection);
    }
    EventObjectSetRegularAnim(eventObject, sprite, animId);
    eventObject->singleMovementActive = TRUE;
    sprite->data[1] = 3;
    return TRUE;
}

bool8 sub_8091020 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        eventObject->singleMovementActive = FALSE;
        sprite->data[1] = 1;
    }
    return FALSE;
}

bool8 sub_8091048(struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MoveEventObjectInNextDirectionInSequence(struct EventObject *eventObject, struct Sprite *sprite, u8 *route)
{
    u8 blockingWay;
    u8 animId;

    if (eventObject->directionSequenceIndex == 3 && eventObject->initialCoords.x == eventObject->currentCoords.x && eventObject->initialCoords.y == eventObject->currentCoords.y)
    {
        eventObject->directionSequenceIndex = 0;
    }
    EventObjectSetDirection(eventObject, route[eventObject->directionSequenceIndex]);
    animId = GetGoSpeed0AnimId(eventObject->movementDirection);
    blockingWay = npc_block_way__next_tile(eventObject, eventObject->movementDirection);
    if (blockingWay == TRUE)
    {
        eventObject->directionSequenceIndex ++;
        EventObjectSetDirection(eventObject, route[eventObject->directionSequenceIndex]);
        animId = GetGoSpeed0AnimId(eventObject->movementDirection);
        blockingWay = npc_block_way__next_tile(eventObject, eventObject->movementDirection);
    }
    if (blockingWay)
    {
        animId = GetStepInPlaceDelay16AnimId(eventObject->facingDirection);
    }
    EventObjectSetRegularAnim(eventObject, sprite, animId);
    eventObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8091110(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        eventObject->singleMovementActive = FALSE;
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

bool8 mss_npc_reset_oampriv3_1_unk2_unk3(struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    if (eventObject->directionSequenceIndex == 0)
    {
        eventObject->directionSequenceIndex = player_get_direction_lower_nybble();
    }
    sprite->data[1] = 1;
    return TRUE;
}

bool8 sub_8091EC0(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (gEventObjects[gPlayerAvatar.eventObjectId].movementActionId == 0xFF || gPlayerAvatar.tileTransitionState == 2)
    {
        return FALSE;
    }
    return gUnknown_0850DA64[player_get_x22()](eventObject, sprite, player_get_direction_upper_nybble(), NULL);
}

bool8 sub_8091F20(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        eventObject->singleMovementActive = FALSE;
        sprite->data[1] = 1;
    }
    return FALSE;
}

bool8 sub_8091F48(struct EventObject *eventObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    return FALSE;
}

bool8 sub_8091F4C(struct EventObject *eventObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(state_to_direction(gInitialMovementTypeFacingDirections[eventObject->movementType], eventObject->directionSequenceIndex, playerDirection)));
    eventObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8091F94(struct EventObject *eventObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    if (EventObjectIsFarawayIslandMew(eventObject))
    {
        direction = sub_81D427C();
        if (direction == 0)
        {
            direction = playerDirection;
            direction = state_to_direction(gInitialMovementTypeFacingDirections[eventObject->movementType], eventObject->directionSequenceIndex, direction);
            EventObjectMoveDestCoords(eventObject, direction, &x, &y);
            EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(direction));
            eventObject->singleMovementActive = TRUE;
            sprite->data[1] = 2;
            return TRUE;
        }
    }
    else
    {
        direction = state_to_direction(gInitialMovementTypeFacingDirections[eventObject->movementType], eventObject->directionSequenceIndex, direction);
    }
    EventObjectMoveDestCoords(eventObject, direction, &x, &y);
    EventObjectSetRegularAnim(eventObject, sprite, GetGoSpeed0AnimId(direction));
    if (npc_block_way(eventObject, x, y, direction) || (tileCB != NULL && !tileCB(MapGridGetMetatileBehaviorAt(x, y))))
    {
        EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(direction));
    }
    eventObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_80920A4(struct EventObject *eventObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[eventObject->movementType], eventObject->directionSequenceIndex, direction);
    EventObjectMoveDestCoords(eventObject, direction, &x, &y);
    EventObjectSetRegularAnim(eventObject, sprite, GetGoSpeed1AnimId(direction));
    if (npc_block_way(eventObject, x, y, direction) || (tileCB != NULL && !tileCB(MapGridGetMetatileBehaviorAt(x, y))))
    {
        EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(direction));
    }
    eventObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_809215C(struct EventObject *eventObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[eventObject->movementType], eventObject->directionSequenceIndex, direction);
    EventObjectMoveDestCoords(eventObject, direction, &x, &y);
    EventObjectSetRegularAnim(eventObject, sprite, GetGoSpeed3AnimId(direction));
    if (npc_block_way(eventObject, x, y, direction) || (tileCB != NULL && !tileCB(MapGridGetMetatileBehaviorAt(x, y))))
    {
        EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(direction));
    }
    eventObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8092214(struct EventObject *eventObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[eventObject->movementType], eventObject->directionSequenceIndex, direction);
    EventObjectMoveDestCoords(eventObject, direction, &x, &y);
    EventObjectSetRegularAnim(eventObject, sprite, sub_8093438(direction));
    if (npc_block_way(eventObject, x, y, direction) || (tileCB != NULL && !tileCB(MapGridGetMetatileBehaviorAt(x, y))))
    {
        EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(direction));
    }
    eventObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 cph_IM_DIFFERENT(struct EventObject *eventObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    u32 direction;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[eventObject->movementType], eventObject->directionSequenceIndex, direction);
    EventObjectSetRegularAnim(eventObject, sprite, sub_80934BC(direction));
    eventObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 sub_8092314(struct EventObject *eventObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[eventObject->movementType], eventObject->directionSequenceIndex, direction);
    EventObjectMoveDestCoords(eventObject, direction, &x, &y);
    EventObjectSetRegularAnim(eventObject, sprite, sub_8093514(direction));
    if (npc_block_way(eventObject, x, y, direction) || (tileCB != NULL && !tileCB(MapGridGetMetatileBehaviorAt(x, y))))
    {
        EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(direction));
    }
    eventObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 oac_hopping(struct EventObject *eventObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCB(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[eventObject->movementType], eventObject->directionSequenceIndex, direction);
    x = eventObject->currentCoords.x;
    y = eventObject->currentCoords.y;
    sub_8092F88(direction, &x, &y, 2, 2);
    EventObjectSetRegularAnim(eventObject, sprite, GetJumpLedgeAnimId(direction));
    if (npc_block_way(eventObject, x, y, direction) || (tileCB != NULL && !tileCB(MapGridGetMetatileBehaviorAt(x, y))))
    {
        EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(direction));
    }
    eventObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

field_object_step(CopyPlayer2, gUnknown_0850DA90)

bool8 mss_08062EA4(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (gEventObjects[gPlayerAvatar.eventObjectId].movementActionId == 0xFF || gPlayerAvatar.tileTransitionState == 2)
    {
        return FALSE;
    }
    return gUnknown_0850DA64[player_get_x22()](eventObject, sprite, player_get_direction_upper_nybble(), MetatileBehavior_IsPokeGrass);
}

bool8 sub_80925AC(struct EventObject *, struct Sprite *);

void EventObjectCB_TreeDisguise(struct Sprite *sprite)
{
    struct EventObject *eventObject;

    eventObject = &gEventObjects[sprite->data[0]];
    if (eventObject->directionSequenceIndex == 0 || (eventObject->directionSequenceIndex == 1 && !sprite->data[7]))
    {
        EventObjectGetLocalIdAndMap(eventObject, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
        eventObject->fieldEffectSpriteId = FieldEffectStart(FLDEFF_TREE_DISGUISE);
        eventObject->directionSequenceIndex = 1;
        sprite->data[7] ++;
    }
    EventObjectStep(&gEventObjects[sprite->data[0]], sprite, sub_80925AC);
}

bool8 sub_80925AC(struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    return FALSE;
}

void EventObjectCB_MountainDisguise(struct Sprite *sprite)
{
    struct EventObject *eventObject;

    eventObject = &gEventObjects[sprite->data[0]];
    if (eventObject->directionSequenceIndex == 0 || (eventObject->directionSequenceIndex == 1 && !sprite->data[7]))
    {
        EventObjectGetLocalIdAndMap(eventObject, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
        eventObject->fieldEffectSpriteId = FieldEffectStart(FLDEFF_MOUNTAIN_DISGUISE);
        eventObject->directionSequenceIndex = 1;
        sprite->data[7] ++;
    }
    EventObjectStep(&gEventObjects[sprite->data[0]], sprite, sub_80925AC);
}

extern bool8 (*const gUnknown_0850DA9C[])(struct EventObject *, struct Sprite *);
bool8 sub_809268C(struct EventObject *, struct Sprite *);

void EventObjectCB_Hidden1(struct Sprite *sprite)
{
    if (!sprite->data[7])
    {
        gEventObjects[sprite->data[0]].fixedPriority = TRUE;
        sprite->subspriteMode = 2;
        sprite->oam.priority = 3;
        sprite->data[7] ++;
    }
    EventObjectStep(&gEventObjects[sprite->data[0]], sprite, sub_809268C);
}

bool8 sub_809268C(struct EventObject *eventObject, struct Sprite *sprite)
{
    return gUnknown_0850DA9C[sprite->data[1]](eventObject, sprite);
}

bool8 sub_80926AC (struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    return FALSE;
}
bool8 sub_80926B8 (struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        sprite->data[1] = 0;
    }
    return FALSE;
}

field_object_step(WalkInPlace1, gUnknown_0850DAA0)

bool8 sub_8092718(struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    EventObjectSetRegularAnim(eventObject, sprite, GetStepInPlaceDelay16AnimId(eventObject->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(WalkInPlace4, gUnknown_0850DAA8)

bool8 sub_8092788(struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    EventObjectSetRegularAnim(eventObject, sprite, GetStepInPlaceDelay32AnimId(eventObject->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(WalkInPlace2, gUnknown_0850DAB0)

bool8 sub_80927F8(struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    EventObjectSetRegularAnim(eventObject, sprite, GetStepInPlaceDelay8AnimId(eventObject->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(WalkInPlace3, gUnknown_0850DAB8)

bool8 sub_8092868(struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    EventObjectSetRegularAnim(eventObject, sprite, GetStepInPlaceDelay4AnimId(eventObject->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

field_object_step(Hidden2, gUnknown_0850DAC0)

bool8 sub_80928D8(struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_reset(eventObject, sprite);
    EventObjectSetRegularAnim(eventObject, sprite, GetFaceDirectionAnimId(eventObject->facingDirection));
    eventObject->invisible = TRUE;
    sprite->data[1] = 1;
    return TRUE;
}
bool8 sub_809290C(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecRegularAnim(eventObject, sprite))
    {
        sprite->data[1] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_809292C(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->singleMovementActive = FALSE;
    return FALSE;
}

static void npc_reset(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->singleMovementActive = FALSE;
    eventObject->heldMovementActive = FALSE;
    eventObject->heldMovementFinished = FALSE;
    eventObject->movementActionId = 0xFF;
    sprite->data[1] = 0;
}

#define dirn2anim(name, table)\
u8 name(u8 direction)\
{\
    return table[direction];\
}

dirn2anim(EventObjectDirectionToImageAnimId, gUnknown_0850DACC)
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

void npc_apply_anim_looping(struct EventObject *eventObject, struct Sprite *sprite, u8 animNum)
{
    const struct UnkStruct_085094AC *unk85094AC;

    if (!eventObject->inanimate)
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

void obj_npc_animation_step(struct EventObject *eventObject, struct Sprite *sprite, u8 animNum)
{
    const struct UnkStruct_085094AC *unk85094AC;

    if (!eventObject->inanimate)
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

void npc_set_running_behaviour_etc(struct EventObject *eventObject, u8 movementType)
{
    eventObject->movementType = movementType;
    eventObject->directionSequenceIndex = 0;
    eventObject->playerCopyableMovement = 0;
    gSprites[eventObject->spriteId].callback = gUnknown_08505438[movementType];
    gSprites[eventObject->spriteId].data[1] = 0;
}

dirn2anim(npc_running_behaviour_by_direction, gUnknown_0850DB53)

u8 npc_block_way__next_tile(struct EventObject *eventObject, u8 direction)
{
    s16 x;
    s16 y;

    x = eventObject->currentCoords.x;
    y = eventObject->currentCoords.y;
    MoveCoords(direction, &x, &y);
    return npc_block_way(eventObject, x, y, direction);
}

u8 npc_block_way(struct EventObject *eventObject, s16 x, s16 y, u32 dirn)
{
    u8 direction;

    direction = dirn;
    if (IsCoordOutsideEventObjectMovementRect(eventObject, x, y))
    {
        return 1;
    }
    if (MapGridIsImpassableAt(x, y) || GetMapBorderIdAt(x, y) == -1 || IsMetatileDirectionallyImpassable(eventObject, x, y, direction))
    {
        return 2;
    }
    if (eventObject->trackedByCamera && !CanCameraMoveInDirection(direction))
    {
        return 2;
    }
    if (IsZCoordMismatchAt(eventObject->currentElevation, x, y))
    {
        return 3;
    }
    if (CheckForCollisionBetweenEventObjects(eventObject, x, y))
    {
        return 4;
    }
    return 0;
}

u8 sub_8092C8C(struct EventObject *eventObject, s16 x, s16 y, u8 direction)
{
    u8 retval;

    retval = 0x00;
    if (IsCoordOutsideEventObjectMovementRect(eventObject, x, y))
    {
        retval |= 1;
    }
    if (MapGridIsImpassableAt(x, y) || GetMapBorderIdAt(x, y) == -1 || IsMetatileDirectionallyImpassable(eventObject, x, y, direction) || (eventObject->trackedByCamera && !CanCameraMoveInDirection(direction)))
    {
        retval |= 2;
    }
    if (IsZCoordMismatchAt(eventObject->currentElevation, x, y))
    {
        retval |= 4;
    }
    if (CheckForCollisionBetweenEventObjects(eventObject, x, y))
    {
        retval |= 8;
    }
    return retval;
}

static bool8 IsCoordOutsideEventObjectMovementRect(struct EventObject *eventObject, s16 x, s16 y)
{
    s16 left;
    s16 right;
    s16 top;
    s16 bottom;

    if (eventObject->range.as_nybbles.x != 0)
    {
        left = eventObject->initialCoords.x - eventObject->range.as_nybbles.x;
        right = eventObject->initialCoords.x + eventObject->range.as_nybbles.x;
        if (left > x || right < x)
        {
            return TRUE;
        }
    }
    if (eventObject->range.as_nybbles.y != 0)
    {
        top = eventObject->initialCoords.y - eventObject->range.as_nybbles.y;
        bottom = eventObject->initialCoords.y + eventObject->range.as_nybbles.y;
        if (top > y || bottom < y)
        {
            return TRUE;
        }
    }
    return FALSE;
}

static bool8 IsMetatileDirectionallyImpassable(struct EventObject *eventObject, s16 x, s16 y, u8 direction)
{
    if (gOppositeDirectionBlockedMetatileFuncs[direction - 1](eventObject->currentMetatileBehavior) || gDirectionBlockedMetatileFuncs[direction - 1](MapGridGetMetatileBehaviorAt(x, y)))
    {
        return TRUE;
    }
    return FALSE;
}

static bool8 CheckForCollisionBetweenEventObjects(struct EventObject *eventObject, s16 x, s16 y)
{
    u8 i;
    struct EventObject *curObject;

    for (i = 0; i < NUM_EVENT_OBJECTS; i ++)
    {
        curObject = &gEventObjects[i];
        if (curObject->active && curObject != eventObject)
        {
            if ((curObject->currentCoords.x == x && curObject->currentCoords.y == y) || (curObject->previousCoords.x == x && curObject->previousCoords.y == y))
            {
                if (AreZCoordsCompatible(eventObject->currentElevation, curObject->currentElevation))
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
    u8 eventObjectId;

    if (!TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &eventObjectId) && gSprites[gEventObjects[eventObjectId].spriteId].data[7] & 0x02)
    {
        return TRUE;
    }
    return FALSE;
}

void sub_8092EF0(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 eventObjectId;

    if (!TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &eventObjectId))
    {
        gSprites[gEventObjects[eventObjectId].spriteId].data[7] |= 0x04;
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

static void GetEventObjectMovingCameraOffset(s16 *x, s16 *y)
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

void EventObjectMoveDestCoords(struct EventObject *eventObject, u32 dirn, s16 *x, s16 *y)
{
    u8 direction;

    direction = dirn;
    *x = eventObject->currentCoords.x;
    *y = eventObject->currentCoords.y;
    MoveCoords(direction, x, y);
}

// file boundary?

bool8 EventObjectIsSpecialAnimOrDirectionSequenceAnimActive(struct EventObject *eventObject)
{
    if (eventObject->singleMovementActive || eventObject->heldMovementActive)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 EventObjectIsSpecialAnimActive(struct EventObject *eventObject)
{
    if (eventObject->heldMovementActive && eventObject->movementActionId != 0xFF)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 EventObjectSetSpecialAnim(struct EventObject *eventObject, u8 specialAnimId)
{
    if (EventObjectIsSpecialAnimOrDirectionSequenceAnimActive(eventObject))
    {
        return TRUE;
    }
    npc_sync_anim_pause_bits(eventObject);
    eventObject->movementActionId = specialAnimId;
    eventObject->heldMovementActive = TRUE;
    eventObject->heldMovementFinished = FALSE;
    gSprites[eventObject->spriteId].data[2] = 0;
    return FALSE;
}

void EventObjectForceSetSpecialAnim(struct EventObject *eventObject, u8 specialAnimId)
{
    EventObjectClearAnimIfSpecialAnimActive(eventObject);
    EventObjectSetSpecialAnim(eventObject, specialAnimId);
}

void EventObjectClearAnimIfSpecialAnimActive(struct EventObject *eventObject)
{
    if (eventObject->heldMovementActive)
    {
        EventObjectClearAnim(eventObject);
    }
}

void EventObjectClearAnim(struct EventObject *eventObject)
{
    eventObject->movementActionId = 0xFF;
    eventObject->heldMovementActive = FALSE;
    eventObject->heldMovementFinished = FALSE;
    gSprites[eventObject->spriteId].data[1] = 0;
    gSprites[eventObject->spriteId].data[2] = 0;
}

u8 EventObjectCheckIfSpecialAnimFinishedOrInactive(struct EventObject *eventObject)
{
    if (eventObject->heldMovementActive)
    {
        return eventObject->heldMovementFinished;
    }
    return 0x10;
}

u8 EventObjectClearAnimIfSpecialAnimFinished(struct EventObject *eventObject)
{
    u8 specialAnimState;

    specialAnimState = EventObjectCheckIfSpecialAnimFinishedOrInactive(eventObject);
    if (specialAnimState != 0 && specialAnimState != 16)
    {
        EventObjectClearAnimIfSpecialAnimActive(eventObject);
    }
    return specialAnimState;
}

u8 EventObjectGetSpecialAnim(struct EventObject *eventObject)
{
    if (eventObject->heldMovementActive)
    {
        return eventObject->movementActionId;
    }
    return 0xFF;
}

void EventObjectStep(struct EventObject *eventObject, struct Sprite *sprite, bool8 (*callback)(struct EventObject *, struct Sprite *))
{
    DoGroundEffects_OnSpawn(eventObject, sprite);
    sub_80964E8(eventObject, sprite);
    if (EventObjectIsSpecialAnimActive(eventObject))
    {
        EventObjectExecSpecialAnim(eventObject, sprite);
    }
    else if (!eventObject->frozen)
    {
        while (callback(eventObject, sprite));
    }
    DoGroundEffects_OnBeginStep(eventObject, sprite);
    DoGroundEffects_OnFinishStep(eventObject, sprite);
    npc_obj_transfer_image_anim_pause_flag(eventObject, sprite);
    sub_8096518(eventObject, sprite);
    EventObjectUpdateSubpriority(eventObject, sprite);
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

bool8 EventObjectFaceOppositeDirection(struct EventObject *eventObject, u8 direction)
{
    return EventObjectSetSpecialAnim(eventObject, GetFaceDirectionAnimId(GetOppositeDirection(direction)));
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

static void EventObjectExecSpecialAnim(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (gUnknown_0850DC50[eventObject->movementActionId][sprite->data[2]](eventObject, sprite))
    {
        eventObject->heldMovementFinished = TRUE;
    }
}

bool8 EventObjectExecRegularAnim(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (gUnknown_0850DC50[eventObject->movementActionId][sprite->data[2]](eventObject, sprite))
    {
        eventObject->movementActionId = 0xFF;
        sprite->data[2] = 0;
        return TRUE;
    }
    return FALSE;
}

static void EventObjectSetRegularAnim(struct EventObject *eventObject, struct Sprite *sprite, u8 animId)
{
    eventObject->movementActionId = animId;
    sprite->data[2] = 0;
}

// file boundary?

void an_look_any(struct EventObject *eventObject, struct Sprite *sprite, u8 direction)
{
    EventObjectSetDirection(eventObject, direction);
    npc_coords_shift_still(eventObject);
    obj_npc_animation_step(eventObject, sprite, get_go_image_anim_num(eventObject->facingDirection));
    sprite->animPaused = TRUE;
    sprite->data[2] = 1;
}

bool8 sub_8093950(struct EventObject *eventObject, struct Sprite *sprite)
{
    an_look_any(eventObject, sprite, DIR_SOUTH);
    return TRUE;
}

bool8 sub_8093960(struct EventObject *eventObject, struct Sprite *sprite)
{
    an_look_any(eventObject, sprite, DIR_NORTH);
    return TRUE;
}

bool8 sub_8093970(struct EventObject *eventObject, struct Sprite *sprite)
{
    an_look_any(eventObject, sprite, DIR_WEST);
    return TRUE;
}

bool8 sub_8093980(struct EventObject *eventObject, struct Sprite *sprite)
{
    an_look_any(eventObject, sprite, DIR_EAST);
    return TRUE;
}

void npc_apply_direction(struct EventObject *eventObject, struct Sprite *sprite, u8 direction, u8 speed)
{
    s16 x;
    s16 y;

    x = eventObject->currentCoords.x;
    y = eventObject->currentCoords.y;
    EventObjectSetDirection(eventObject, direction);
    MoveCoords(direction, &x, &y);
    npc_coords_shift(eventObject, x, y);
    oamt_npc_ministep_reset(sprite, direction, speed);
    sprite->animPaused = FALSE;
    if (gUnknown_020375B8 != NULL && sub_8097F78(eventObject) != 0x10)
    {
        sprite->animPaused = TRUE;
    }
    eventObject->triggerGroundEffectsOnMove = TRUE;
    sprite->data[2] = 1;
}

void do_go_anim(struct EventObject *eventObject, struct Sprite *sprite, u8 direction, u8 speed)
{
    u8 (*functions[ARRAY_COUNT(gUnknown_0850DEE8)])(u8);

    memcpy(functions, gUnknown_0850DEE8, sizeof gUnknown_0850DEE8);
    npc_apply_direction(eventObject, sprite, direction, speed);
    npc_apply_anim_looping(eventObject, sprite, functions[speed](eventObject->facingDirection));
}

void do_run_anim(struct EventObject *eventObject, struct Sprite *sprite, u8 direction)
{
    npc_apply_direction(eventObject, sprite, direction, 1);
    npc_apply_anim_looping(eventObject, sprite, get_run_image_anim_num(eventObject->facingDirection));
}

bool8 npc_obj_ministep_stop_on_arrival(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (obj_npc_ministep(sprite))
    {
        npc_coords_shift_still(eventObject);
        eventObject->triggerGroundEffectsOnStop = TRUE;
        sprite->animPaused = TRUE;
        return TRUE;
    }
    return FALSE;
}

void sub_8093AF0(struct EventObject *eventObject, struct Sprite *sprite, u8 direction)
{
    s16 x;
    s16 y;

    x = eventObject->currentCoords.x;
    y = eventObject->currentCoords.y;
    EventObjectSetDirection(eventObject, direction);
    MoveCoords(direction, &x, &y);
    npc_coords_shift(eventObject, x, y);
    sub_80976DC(sprite, direction);
    sprite->animPaused = FALSE;
    eventObject->triggerGroundEffectsOnMove = TRUE;
    sprite->data[2] = 1;
}

void sub_8093B60(struct EventObject *eventObject, struct Sprite *sprite, u8 direction)
{
    sub_8093AF0(eventObject, sprite, direction);
    npc_apply_anim_looping(eventObject, sprite, get_go_image_anim_num(eventObject->facingDirection));
}

bool8 an_walk_any_2(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80976EC(sprite))
    {
        npc_coords_shift_still(eventObject);
        eventObject->triggerGroundEffectsOnStop = TRUE;
        sprite->animPaused = TRUE;
        return TRUE;
    }
    return FALSE;
}

#define an_walk_any_2_macro(name, fn1, fn2, ...) \
bool8 name##_2(struct EventObject *, struct Sprite *);\
bool8 name(struct EventObject *eventObject, struct Sprite *sprite)\
{\
    fn1(eventObject, sprite, __VA_ARGS__);\
    return name##_2(eventObject, sprite);\
}\
bool8 name##_2(struct EventObject *eventObject, struct Sprite *sprite)\
{\
    if (fn2(eventObject, sprite))\
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

void sub_8093FC4(struct EventObject *eventObject, struct Sprite *sprite, u8 direction, u8 speed, u8 a5)
{
    s16 displacements[ARRAY_COUNT(gUnknown_0850DFBC)];
    s16 x;
    s16 y;

    memcpy(displacements, gUnknown_0850DFBC, sizeof gUnknown_0850DFBC);
    x = 0;
    y = 0;
    EventObjectSetDirection(eventObject, direction);
    sub_8092F88(direction, &x, &y, displacements[speed], displacements[speed]);
    npc_coords_shift(eventObject, eventObject->currentCoords.x + x, eventObject->currentCoords.y + y);
    sub_809783C(sprite, direction, speed, a5);
    sprite->data[2] = 1;
    sprite->animPaused = 0;
    eventObject->triggerGroundEffectsOnMove = 1;
    eventObject->disableCoveringGroundEffects = 1;
}

void maybe_shadow_1(struct EventObject *eventObject, struct Sprite *sprite, u8 direction, u8 speed, u8 a4)
{
    sub_8093FC4(eventObject, sprite, direction, speed, a4);
    npc_apply_anim_looping(eventObject, sprite, get_go_image_anim_num(eventObject->facingDirection));
    DoShadowFieldEffect(eventObject);
}

u8 sub_80940C4(struct EventObject *eventObject, struct Sprite *sprite, u8 callback(struct Sprite *))
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
        sub_8092F88(eventObject->movementDirection, &x, &y, displacements[sprite->data[4]], displacements[sprite->data[4]]);
        npc_coords_shift(eventObject, eventObject->currentCoords.x + x, eventObject->currentCoords.y + y);
        eventObject->triggerGroundEffectsOnMove = TRUE;
        eventObject->disableCoveringGroundEffects = TRUE;
    }
    else if (result == 0xFF)
    {
        npc_coords_shift_still(eventObject);
        eventObject->triggerGroundEffectsOnStop = TRUE;
        eventObject->landingJump = TRUE;
        sprite->animPaused = TRUE;
    }
    return result;
}

u8 sub_8094188(struct EventObject *eventObject, struct Sprite *sprite)
{
    return sub_80940C4(eventObject, sprite, sub_809785C);
}

u8 sub_809419C(struct EventObject *eventObject, struct Sprite *sprite)
{
    return sub_80940C4(eventObject, sprite, sub_80978E4);
}

bool8 sub_80941B0(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_8094188(eventObject, sprite) == 0xFF)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 sub_80941C8(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_809419C(eventObject, sprite) == 0xFF)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 sub_80941E0(struct EventObject *eventObject, struct Sprite *sprite)
{
    switch (sub_8094188(eventObject, sprite))
    {
        case 255:
            return TRUE;
        case   1:
            EventObjectSetDirection(eventObject, GetOppositeDirection(eventObject->movementDirection));
            obj_npc_animation_step(eventObject, sprite, get_go_image_anim_num(eventObject->facingDirection));
        default:
            return FALSE;
    }
}

#define maybe_shadow_1_macro(name, fn1, fn2, ...) \
bool8 name##_2(struct EventObject *, struct Sprite *);\
bool8 name(struct EventObject *eventObject, struct Sprite *sprite)\
{\
    fn1(eventObject, sprite, __VA_ARGS__);\
    return name##_2(eventObject, sprite);\
}\
bool8 name##_2(struct EventObject *eventObject, struct Sprite *sprite)\
{\
    if (fn2(eventObject, sprite))\
    {\
        eventObject->hasShadow = FALSE;\
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

bool8 sub_8094398(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (-- sprite->data[3] == 0)
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

#define special_anim_with_timer(name, duration)\
bool8 name(struct EventObject *eventObject, struct Sprite *sprite)\
{\
    sub_8094390(sprite, duration);\
    return sub_8094398(eventObject, sprite);\
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

void sub_8094554(struct EventObject *eventObject, struct Sprite *sprite, u8 direction, u8 animNum, u16 duration)
{
    EventObjectSetDirection(eventObject, direction);
    npc_apply_anim_looping(eventObject, sprite, animNum);
    sprite->animPaused = FALSE;
    sprite->data[2] = 1;
    sprite->data[3] = duration;
}

bool8 sub_809459C(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (-- sprite->data[3] == 0)
    {
        sprite->data[2] = 2;
        sprite->animPaused = TRUE;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_80945C4(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sprite->data[3] & 1)
    {
        sprite->animDelayCounter ++;
    }
    return sub_809459C(eventObject, sprite);
}

#define special_anim_with_timer_2(name, direction, images, duration, timer) \
bool8 name(struct EventObject *eventObject, struct Sprite *sprite)\
{\
    u8 animId;\
    animId = images(DIR_##direction);\
    sub_8094554(eventObject, sprite, DIR_##direction, animId, duration);\
    return timer(eventObject, sprite);\
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

void npc_set_direction_and_anim__an_proceed(struct EventObject *eventObject, struct Sprite *sprite, u8 direction, u8 animNum)
{
    obj_anim_image_set_and_seek(sprite, animNum, 0);
    EventObjectSetDirection(eventObject, direction);
    sprite->data[2] = 1;
}

bool8 sub_8094DAC(struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_set_direction_and_anim__an_proceed(eventObject, sprite, eventObject->movementDirection, sprite->animNum);
    return FALSE;
}

bool8 sub_8094DC4(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80979BC(sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

void sub_8094DE4(struct EventObject *eventObject, struct Sprite *sprite, u8 direction)
{
    sub_8093FC4(eventObject, sprite, direction, 1, 0);
    StartSpriteAnim(sprite, sub_80929AC(direction));
}

#define unk_macro_8094E18(name, direction)\
bool8 name##_2(struct EventObject *, struct Sprite *);\
bool8 name(struct EventObject *eventObject, struct Sprite *sprite)\
{\
    sub_8094DE4(eventObject, sprite, direction);\
    return name##_2(eventObject, sprite);\
}\
bool8 name##_2(struct EventObject *eventObject, struct Sprite *sprite)\
{\
    if (sub_80941C8(eventObject, sprite))\
    {\
        sprite->data[2] = 2;\
        eventObject->landingJump = FALSE;\
        return TRUE;\
    }\
    return FALSE;\
}

unk_macro_8094E18(sub_8094E18, DIR_SOUTH)
unk_macro_8094E18(sub_8094E60, DIR_NORTH)
unk_macro_8094E18(sub_8094EB8, DIR_WEST)
unk_macro_8094E18(sub_8094710, DIR_EAST)

bool8 sub_8094F38(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 eventObjectId;

    if (!TryGetEventObjectIdByLocalIdAndMap(0xFF, 0, 0, &eventObjectId))
    {
        an_look_any(eventObject, sprite, sub_8092AF8(eventObject->currentCoords.x, eventObject->currentCoords.y, gEventObjects[eventObjectId].currentCoords.x, gEventObjects[eventObjectId].currentCoords.y));
    }
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_8094F94(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 eventObjectId;

    if (!TryGetEventObjectIdByLocalIdAndMap(0xFF, 0, 0, &eventObjectId))
    {
        an_look_any(eventObject, sprite, GetOppositeDirection(sub_8092AF8(eventObject->currentCoords.x, eventObject->currentCoords.y, gEventObjects[eventObjectId].currentCoords.x, gEventObjects[eventObjectId].currentCoords.y)));
    }
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_8094FF8(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->facingDirectionLocked = TRUE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_8095008(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->facingDirectionLocked = FALSE;
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

bool8 sub_8095438(struct EventObject *eventObject, struct Sprite *sprite)
{
    an_look_any(eventObject, sprite, gInitialMovementTypeFacingDirections[eventObject->movementType]);
    return TRUE;
}

bool8 sub_8095450(struct EventObject *eventObject, struct Sprite *sprite)
{
    npc_set_direction_and_anim__an_proceed(eventObject, sprite, DIR_SOUTH, 0x14);
    return FALSE;
}

bool8 sub_8095460(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->disableJumpLandingGroundEffect = FALSE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_8095470(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->disableJumpLandingGroundEffect = TRUE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_8095480(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->inanimate = TRUE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_8095490(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->inanimate = GetEventObjectGraphicsInfo(eventObject->graphicsId)->inanimate;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_80954BC(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->invisible = TRUE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_80954CC(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->invisible = FALSE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 do_exclamation_mark_bubble_1(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectGetLocalIdAndMap(eventObject, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    FieldEffectStart(FLDEFF_EXCLAMATION_MARK_ICON_1);
    sprite->data[2] = 1;
    return TRUE;
}

bool8 do_exclamation_mark_bubble_2(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectGetLocalIdAndMap(eventObject, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    FieldEffectStart(FLDEFF_EXCLAMATION_MARK_ICON_2);
    sprite->data[2] = 1;
    return TRUE;
}

bool8 do_heart_bubble(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectGetLocalIdAndMap(eventObject, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    FieldEffectStart(FLDEFF_HEART_ICON);
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_8095548(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (eventObject->movementType == 0x3F)
    {
        sub_80B4578(eventObject);
        return FALSE;
    }
    if (eventObject->movementType != 0x39 && eventObject->movementType != 0x3A)
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    sub_8155D78(eventObject);
    sprite->data[2] = 1;
    return sub_809558C(eventObject, sprite);
}

bool8 sub_809558C(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_8155DA0(eventObject))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_80955AC(struct EventObject *eventObject, struct Sprite *sprite)
{
    obj_anim_image_set_and_seek(sprite, 1, 0);
    sprite->data[2] = 1;
    return FALSE;
}

bool8 sub_80955C8(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80979BC(sprite))
    {
        SetEventObjectStepTimer(sprite, 32);
        sprite->data[2] = 2;
    }
    return FALSE;
}

bool8 sub_80955EC(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->invisible ^= TRUE;
    if (RunEventObjectStepTimer(sprite))
    {
        eventObject->invisible = TRUE;
        sprite->data[2] = 3;
    }
    return FALSE;
}

bool8 sub_8095628(struct EventObject *eventObject, struct Sprite *sprite)
{
    obj_anim_image_set_and_seek(sprite, 1, 0);
    sprite->data[2] = 1;
    return FALSE;
}

bool8 sub_8095644(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80979BC(sprite))
    {
        SetEventObjectStepTimer(sprite, 32);
        sprite->data[2] = 2;
    }
    return FALSE;
}

bool8 sub_8095668(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->invisible ^= TRUE;
    if (RunEventObjectStepTimer(sprite))
    {
        eventObject->invisible = TRUE;
        sprite->data[2] = 3;
    }
    return FALSE;
}

bool8 sub_80956A4(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->fixedPriority = TRUE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_80956B4(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->fixedPriority = FALSE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_80956C4(struct EventObject *eventObject, struct Sprite *sprite)
{
    sprite->oam.affineMode = 3;
    InitSpriteAffineAnim(sprite);
    sprite->affineAnimPaused = TRUE;
    sprite->subspriteMode = 0;
    return TRUE;
}

bool8 sub_80956F4(struct EventObject *eventObject, struct Sprite *sprite)
{
    FreeOamMatrix(sprite->oam.matrixNum);
    sprite->oam.affineMode = 0;
    CalcCenterToCornerVec(sprite, sprite->oam.shape, sprite->oam.size, sprite->oam.affineMode);
    return TRUE;
}

bool8 sub_8095724(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->unk3_3 = TRUE;
    return TRUE;
}

bool8 sub_8095730(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->unk3_3 = FALSE;
    return TRUE;
}

#define affine_an_walk_any_2_macro(name, fn, fn2, action, anim, ...)\
bool8 name##_2(struct EventObject *, struct Sprite *);\
bool8 name(struct EventObject *eventObject, struct Sprite *sprite)\
{\
    fn(eventObject, sprite, __VA_ARGS__);\
    sprite->affineAnimPaused = FALSE;\
    action(sprite, anim);\
    return name##_2(eventObject, sprite);\
}\
bool8 name##_2(struct EventObject *eventObject, struct Sprite *sprite)\
{\
    if (fn2(eventObject, sprite))\
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

static void sub_80958C0(struct EventObject *eventObject, struct Sprite *sprite, u8 direction)
{
    EventObjectSetDirection(eventObject, direction);
    npc_coords_shift_still(eventObject);
    obj_npc_animation_step(eventObject, sprite, sub_80929FC(direction));
    sprite->animPaused = TRUE;
    sprite->data[2] = 1;
}

bool8 sub_8095900(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_80958C0(eventObject, sprite, DIR_SOUTH);
    return TRUE;
}

bool8 sub_8095910(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_80958C0(eventObject, sprite, DIR_NORTH);
    return TRUE;
}

bool8 sub_8095920(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_80958C0(eventObject, sprite, DIR_WEST);
    return TRUE;
}

bool8 sub_8095930(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_80958C0(eventObject, sprite, DIR_EAST);
    return TRUE;
}

#define set_dirn_and_anim__an_proceed(name, direction, anims)\
bool8 name(struct EventObject *eventObject, struct Sprite *sprite)\
{\
    npc_set_direction_and_anim__an_proceed(eventObject, sprite, direction, anims(direction));\
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

void sub_8095AF0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8097750(sprite);
    sprite->animPaused = FALSE;
}

bool8 sub_8095B0C(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_8097758(sprite))
    {
        npc_coords_shift_still(eventObject);
        eventObject->triggerGroundEffectsOnStop = TRUE;
        sprite->animPaused = TRUE;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8095B44(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8095AF0(eventObject, sprite);
    sprite->data[2] = 1;
    return sub_8095B64(eventObject, sprite);
}

bool8 sub_8095B64(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_8095B0C(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

void sub_8095B84(struct EventObject *eventObject, struct Sprite *sprite, u8 direction, u8 speed, u8 a4)
{
    sub_8093FC4(eventObject, sprite, direction, speed, a4);
    StartSpriteAnimIfDifferent(sprite, sub_80929BC(direction));
    DoShadowFieldEffect(eventObject);
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

void sub_80960C8(struct EventObject *eventObject, struct Sprite *sprite, u8 direction, u8 speed)
{
    npc_apply_direction(eventObject, sprite, direction, speed);
    StartSpriteAnim(sprite, sub_80929BC(eventObject->facingDirection));
    SeekSpriteAnim(sprite, 0);
}

an_walk_any_2_macro(sub_8096100, sub_80960C8, npc_obj_ministep_stop_on_arrival, DIR_SOUTH, 1)
an_walk_any_2_macro(sub_8096140, sub_80960C8, npc_obj_ministep_stop_on_arrival, DIR_NORTH, 1)
an_walk_any_2_macro(sub_8096180, sub_80960C8, npc_obj_ministep_stop_on_arrival, DIR_WEST,  1)
an_walk_any_2_macro(sub_80961C0, sub_80960C8, npc_obj_ministep_stop_on_arrival, DIR_EAST,  1)

void sub_8096200(struct EventObject *eventObject, struct Sprite *sprite, u8 direction, u8 speed)
{
    npc_apply_direction(eventObject, sprite, direction, speed);
    npc_apply_anim_looping(eventObject, sprite, sub_80929FC(eventObject->facingDirection));
}

an_walk_any_2_macro(sub_8096230, sub_8096200, npc_obj_ministep_stop_on_arrival, DIR_SOUTH, 1)
an_walk_any_2_macro(sub_8096270, sub_8096200, npc_obj_ministep_stop_on_arrival, DIR_NORTH, 1)
an_walk_any_2_macro(sub_80962B0, sub_8096200, npc_obj_ministep_stop_on_arrival, DIR_WEST,  1)
an_walk_any_2_macro(sub_80962F0, sub_8096200, npc_obj_ministep_stop_on_arrival, DIR_EAST,  1)

void sub_8096330(struct EventObject *eventObject, struct Sprite *sprite, u8 direction, u8 speed)
{
    npc_apply_direction(eventObject, sprite, direction, speed);
    StartSpriteAnim(sprite, sub_80929DC(eventObject->facingDirection));
    SeekSpriteAnim(sprite, 0);
}
an_walk_any_2_macro(sub_8096368, sub_8096330, npc_obj_ministep_stop_on_arrival, DIR_SOUTH, 1)
an_walk_any_2_macro(sub_80963A8, sub_8096330, npc_obj_ministep_stop_on_arrival, DIR_NORTH, 1)
an_walk_any_2_macro(sub_80963E8, sub_8096330, npc_obj_ministep_stop_on_arrival, DIR_WEST,  1)
an_walk_any_2_macro(sub_8096428, sub_8096330, npc_obj_ministep_stop_on_arrival, DIR_EAST,  1)

bool8 sub_8096468(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8097FA4(eventObject);
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_809647C(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8098044(eventObject->warpArrowSpriteId);
    sprite->pos2.y = 0;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 sub_8096494(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sprite->pos2.y == 0)
    {
        sub_8098044(eventObject->warpArrowSpriteId);
        sprite->data[2] = 1;
        return TRUE;
    }
    return FALSE;
}

u8 sub_80964B8(struct EventObject *eventObject, struct Sprite *sprite)
{
    return TRUE;
}

bool8 sub_80964BC(struct EventObject *eventObject, struct Sprite *sprite)
{
    sprite->animPaused = TRUE;
    return TRUE;
}

void npc_obj_transfer_image_anim_pause_flag(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (eventObject->disableAnim)
    {
        sprite->animPaused = TRUE;
    }
}

void sub_80964E8(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (eventObject->enableAnim)
    {
        sprite->animPaused = FALSE;
        eventObject->disableAnim = FALSE;
        eventObject->enableAnim = FALSE;
    }
}

static void sub_8096518(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8096530(eventObject, sprite);
    npc_update_obj_anim_flag(eventObject, sprite);
}

static void sub_8096530(struct EventObject *eventObject, struct Sprite *sprite)
{
    u16 x;
    u16 y;
    u16 x2;
    u16 y2;
    const struct EventObjectGraphicsInfo *graphicsInfo;

    eventObject->offScreen = FALSE;
    graphicsInfo = GetEventObjectGraphicsInfo(eventObject->graphicsId);
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
        eventObject->offScreen = TRUE;
    }
    if ((s16)y >= 0xB0 || (s16)y2 < -0x10)
    {
        eventObject->offScreen = TRUE;
    }
}

static void npc_update_obj_anim_flag(struct EventObject *eventObject, struct Sprite *sprite)
{
    sprite->invisible = FALSE;
    if (eventObject->invisible || eventObject->offScreen)
    {
        sprite->invisible = TRUE;
    }
}

/*static*/ void GetAllGroundEffectFlags_OnSpawn(struct EventObject *eventObj, u32 *flags)
{
    EventObjectUpdateMetatileBehaviors(eventObj);
    GetGroundEffectFlags_Reflection(eventObj, flags);
    GetGroundEffectFlags_TallGrassOnSpawn(eventObj, flags);
    GetGroundEffectFlags_LongGrassOnSpawn(eventObj, flags);
    GetGroundEffectFlags_SandHeap(eventObj, flags);
    GetGroundEffectFlags_ShallowFlowingWater(eventObj, flags);
    GetGroundEffectFlags_ShortGrass(eventObj, flags);
    GetGroundEffectFlags_HotSprings(eventObj, flags);
}

static void GetAllGroundEffectFlags_OnBeginStep(struct EventObject *eventObj, u32 *flags)
{
    EventObjectUpdateMetatileBehaviors(eventObj);
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

/*static*/ void GetAllGroundEffectFlags_OnFinishStep(struct EventObject *eventObj, u32 *flags)
{
    EventObjectUpdateMetatileBehaviors(eventObj);
    GetGroundEffectFlags_ShallowFlowingWater(eventObj, flags);
    GetGroundEffectFlags_SandHeap(eventObj, flags);
    GetGroundEffectFlags_Puddle(eventObj, flags);
    GetGroundEffectFlags_Ripple(eventObj, flags);
    GetGroundEffectFlags_ShortGrass(eventObj, flags);
    GetGroundEffectFlags_HotSprings(eventObj, flags);
    GetGroundEffectFlags_Seaweed(eventObj, flags);
    GetGroundEffectFlags_JumpLanding(eventObj, flags);
}

static void EventObjectUpdateMetatileBehaviors(struct EventObject *eventObj)
{
    eventObj->previousMetatileBehavior = MapGridGetMetatileBehaviorAt(eventObj->previousCoords.x, eventObj->previousCoords.y);
    eventObj->currentMetatileBehavior = MapGridGetMetatileBehaviorAt(eventObj->currentCoords.x, eventObj->currentCoords.y);
}

static void GetGroundEffectFlags_Reflection(struct EventObject *eventObj, u32 *flags)
{
    u32 reflectionFlags[2] = { GROUND_EFFECT_FLAG_REFLECTION, GROUND_EFFECT_FLAG_ICE_REFLECTION };
    u8 type = EventObjectCheckForReflectiveSurface(eventObj);

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

static void GetGroundEffectFlags_TallGrassOnSpawn(struct EventObject *eventObj, u32 *flags)
{
    if (MetatileBehavior_IsTallGrass(eventObj->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_TALL_GRASS_ON_SPAWN;
}

static void GetGroundEffectFlags_TallGrassOnBeginStep(struct EventObject *eventObj, u32 *flags)
{
    if (MetatileBehavior_IsTallGrass(eventObj->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_TALL_GRASS_ON_MOVE;
}

static void GetGroundEffectFlags_LongGrassOnSpawn(struct EventObject *eventObj, u32 *flags)
{
    if (MetatileBehavior_IsLongGrass(eventObj->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_LONG_GRASS_ON_SPAWN;
}

static void GetGroundEffectFlags_LongGrassOnBeginStep(struct EventObject *eventObj, u32 *flags)
{
    if (MetatileBehavior_IsLongGrass(eventObj->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_LONG_GRASS_ON_MOVE;
}

static void GetGroundEffectFlags_Tracks(struct EventObject *eventObj, u32 *flags)
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

static void GetGroundEffectFlags_SandHeap(struct EventObject *eventObj, u32 *flags)
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

static void GetGroundEffectFlags_ShallowFlowingWater(struct EventObject *eventObj, u32 *flags)
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

static void GetGroundEffectFlags_Puddle(struct EventObject *eventObj, u32 *flags)
{
    if (MetatileBehavior_IsPuddle(eventObj->currentMetatileBehavior)
        && MetatileBehavior_IsPuddle(eventObj->previousMetatileBehavior))
    {
        *flags |= GROUND_EFFECT_FLAG_PUDDLE;
    }
}

static void GetGroundEffectFlags_Ripple(struct EventObject *eventObj, u32 *flags)
{
    if (MetatileBehavior_HasRipples(eventObj->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_RIPPLES;
}

static void GetGroundEffectFlags_ShortGrass(struct EventObject *eventObj, u32 *flags)
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

static void GetGroundEffectFlags_HotSprings(struct EventObject *eventObj, u32 *flags)
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

static void GetGroundEffectFlags_Seaweed(struct EventObject *eventObj, u32 *flags)
{
    if (MetatileBehavior_IsSeaweed(eventObj->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_SEAWEED;
}

static void GetGroundEffectFlags_JumpLanding(struct EventObject *eventObj, u32 *flags)
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

static u8 EventObjectCheckForReflectiveSurface(struct EventObject *eventObj)
{
    const struct EventObjectGraphicsInfo *info = GetEventObjectGraphicsInfo(eventObj->graphicsId);

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

void EventObjectSetSpriteOamTableForLongGrass(struct EventObject *eventObj, struct Sprite *sprite)
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

void EventObjectUpdateZCoordAndPriority(struct EventObject *eventObj, struct Sprite *sprite)
{
    if (eventObj->fixedPriority)
        return;

    EventObjectUpdateZCoord(eventObj);

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

void EventObjectUpdateZCoord(struct EventObject *eventObj)
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

static void EventObjectUpdateSubpriority(struct EventObject *eventObj, struct Sprite *sprite)
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

void GroundEffect_SpawnOnTallGrass(struct EventObject *eventObj, struct Sprite *sprite)
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

void GroundEffect_StepOnTallGrass(struct EventObject *eventObj, struct Sprite *sprite)
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

void GroundEffect_SpawnOnLongGrass(struct EventObject *eventObj, struct Sprite *sprite)
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

void GroundEffect_StepOnLongGrass(struct EventObject *eventObj, struct Sprite *sprite)
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

void GroundEffect_WaterReflection(struct EventObject *eventObj, struct Sprite *sprite)
{
    SetUpReflection(eventObj, sprite, 0);
}

void GroundEffect_IceReflection(struct EventObject *eventObj, struct Sprite *sprite)
{
    SetUpReflection(eventObj, sprite, 1);
}

void GroundEffect_FlowingWater(struct EventObject *eventObj, struct Sprite *sprite)
{
    StartFieldEffectForEventObject(FLDEFF_FEET_IN_FLOWING_WATER, eventObj);
}

static void (*const sGroundEffectTracksFuncs[])(struct EventObject *eventObj, struct Sprite *sprite, u8 a) = {
    DoTracksGroundEffect_None,
    DoTracksGroundEffect_Footprints,
    DoTracksGroundEffect_BikeTireTracks,
};

void GroundEffect_SandTracks(struct EventObject *eventObj, struct Sprite *sprite)
{
    const struct EventObjectGraphicsInfo *info = GetEventObjectGraphicsInfo(eventObj->graphicsId);
    sGroundEffectTracksFuncs[info->tracks](eventObj, sprite, 0);
}

void GroundEffect_DeepSandTracks(struct EventObject *eventObj, struct Sprite *sprite)
{
    const struct EventObjectGraphicsInfo *info = GetEventObjectGraphicsInfo(eventObj->graphicsId);
    sGroundEffectTracksFuncs[info->tracks](eventObj, sprite, 1);
}

static void DoTracksGroundEffect_None(struct EventObject *eventObj, struct Sprite *sprite, u8 a)
{
}

static void DoTracksGroundEffect_Footprints(struct EventObject *eventObj, struct Sprite *sprite, u8 a)
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

static void DoTracksGroundEffect_BikeTireTracks(struct EventObject *eventObj, struct Sprite *sprite, u8 a)
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

void GroundEffect_Ripple(struct EventObject *eventObj, struct Sprite *sprite)
{
    DoRippleFieldEffect(eventObj, sprite);
}

void GroundEffect_StepOnPuddle(struct EventObject *eventObj, struct Sprite *sprite)
{
    StartFieldEffectForEventObject(FLDEFF_SPLASH, eventObj);
}

void GroundEffect_SandHeap(struct EventObject *eventObj, struct Sprite *sprite)
{
    StartFieldEffectForEventObject(FLDEFF_SAND_PILE, eventObj);
}

void GroundEffect_JumpOnTallGrass(struct EventObject *eventObj, struct Sprite *sprite)
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

void GroundEffect_JumpOnLongGrass(struct EventObject *eventObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = eventObj->currentCoords.x;
    gFieldEffectArguments[1] = eventObj->currentCoords.y;
    gFieldEffectArguments[2] = eventObj->previousElevation;
    gFieldEffectArguments[3] = 2;
    FieldEffectStart(FLDEFF_JUMP_LONG_GRASS);
}

void GroundEffect_JumpOnShallowWater(struct EventObject *eventObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = eventObj->currentCoords.x;
    gFieldEffectArguments[1] = eventObj->currentCoords.y;
    gFieldEffectArguments[2] = eventObj->previousElevation;
    gFieldEffectArguments[3] = sprite->oam.priority;
    FieldEffectStart(FLDEFF_JUMP_SMALL_SPLASH);
}

void GroundEffect_JumpOnWater(struct EventObject *eventObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = eventObj->currentCoords.x;
    gFieldEffectArguments[1] = eventObj->currentCoords.y;
    gFieldEffectArguments[2] = eventObj->previousElevation;
    gFieldEffectArguments[3] = sprite->oam.priority;
    FieldEffectStart(FLDEFF_JUMP_BIG_SPLASH);
}

void GroundEffect_JumpLandingDust(struct EventObject *eventObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = eventObj->currentCoords.x;
    gFieldEffectArguments[1] = eventObj->currentCoords.y;
    gFieldEffectArguments[2] = eventObj->previousElevation;
    gFieldEffectArguments[3] = sprite->oam.priority;
    FieldEffectStart(FLDEFF_DUST);
}

void GroundEffect_ShortGrass(struct EventObject *eventObj, struct Sprite *sprite)
{
    StartFieldEffectForEventObject(FLDEFF_SHORT_GRASS, eventObj);
}

void GroundEffect_HotSprings(struct EventObject *eventObj, struct Sprite *sprite)
{
    StartFieldEffectForEventObject(FLDEFF_HOT_SPRINGS_WATER, eventObj);
}

void GroundEffect_Seaweed(struct EventObject *eventObj, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = eventObj->currentCoords.x;
    gFieldEffectArguments[1] = eventObj->currentCoords.y;
    FieldEffectStart(FLDEFF_BUBBLES);
}

static void (*const sGroundEffectFuncs[])(struct EventObject *eventObj, struct Sprite *sprite) = {
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

/*static*/ void DoFlaggedGroundEffects(struct EventObject *eventObj, struct Sprite *sprite, u32 flags)
{
    u8 i;

    if (EventObjectIsFarawayIslandMew(eventObj) == TRUE && !sub_81D4A58(eventObj))
        return;

    for (i = 0; i < ARRAY_COUNT(sGroundEffectFuncs); i++, flags >>= 1)
        if (flags & 1)
            sGroundEffectFuncs[i](eventObj, sprite);
}

void filters_out_some_ground_effects(struct EventObject *eventObj, u32 *flags)
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

void FilterOutStepOnPuddleGroundEffectIfJumping(struct EventObject *eventObj, u32 *flags)
{
    if (eventObj->landingJump)
        *flags &= ~GROUND_EFFECT_FLAG_PUDDLE;
}

static void DoGroundEffects_OnSpawn(struct EventObject *eventObj, struct Sprite *sprite)
{
    u32 flags;

    if (eventObj->triggerGroundEffectsOnMove)
    {
        flags = 0;
        EventObjectUpdateZCoordAndPriority(eventObj, sprite);
        GetAllGroundEffectFlags_OnSpawn(eventObj, &flags);
        EventObjectSetSpriteOamTableForLongGrass(eventObj, sprite);
        DoFlaggedGroundEffects(eventObj, sprite, flags);
        eventObj->triggerGroundEffectsOnMove = 0;
        eventObj->disableCoveringGroundEffects = 0;
    }
}

static void DoGroundEffects_OnBeginStep(struct EventObject *eventObj, struct Sprite *sprite)
{
    u32 flags;

    if (eventObj->triggerGroundEffectsOnMove)
    {
        flags = 0;
        EventObjectUpdateZCoordAndPriority(eventObj, sprite);
        GetAllGroundEffectFlags_OnBeginStep(eventObj, &flags);
        EventObjectSetSpriteOamTableForLongGrass(eventObj, sprite);
        filters_out_some_ground_effects(eventObj, &flags);
        DoFlaggedGroundEffects(eventObj, sprite, flags);
        eventObj->triggerGroundEffectsOnMove = 0;
        eventObj->disableCoveringGroundEffects = 0;
    }
}

static void DoGroundEffects_OnFinishStep(struct EventObject *eventObj, struct Sprite *sprite)
{
    u32 flags;

    if (eventObj->triggerGroundEffectsOnStop)
    {
        flags = 0;
        EventObjectUpdateZCoordAndPriority(eventObj, sprite);
        GetAllGroundEffectFlags_OnFinishStep(eventObj, &flags);
        EventObjectSetSpriteOamTableForLongGrass(eventObj, sprite);
        FilterOutStepOnPuddleGroundEffectIfJumping(eventObj, &flags);
        DoFlaggedGroundEffects(eventObj, sprite, flags);
        eventObj->triggerGroundEffectsOnStop = 0;
        eventObj->landingJump = 0;
    }
}

bool8 FreezeEventObject(struct EventObject *eventObject)
{
    if (eventObject->heldMovementActive || eventObject->frozen)
    {
        return TRUE;
    }
    else
    {
        eventObject->frozen = 1;
        eventObject->spriteAnimPausedBackup = gSprites[eventObject->spriteId].animPaused;
        eventObject->spriteAffineAnimPausedBackup = gSprites[eventObject->spriteId].affineAnimPaused;
        gSprites[eventObject->spriteId].animPaused = 1;
        gSprites[eventObject->spriteId].affineAnimPaused = 1;
        return FALSE;
    }
}

void FreezeEventObjects(void)
{
    u8 i;
    for (i = 0; i < EVENT_OBJECTS_COUNT; i++)
        if (gEventObjects[i].active && i != gPlayerAvatar.eventObjectId)
            FreezeEventObject(&gEventObjects[i]);
}

void FreezeEventObjectsExceptOne(u8 a1)
{
    u8 i;
    for (i = 0; i < EVENT_OBJECTS_COUNT; i++)
        if (i != a1 && gEventObjects[i].active && i != gPlayerAvatar.eventObjectId)
            FreezeEventObject(&gEventObjects[i]);
}

void npc_sync_anim_pause_bits(struct EventObject *eventObject)
{
    if (eventObject->active && eventObject->frozen)
    {
        eventObject->frozen = 0;
        gSprites[eventObject->spriteId].animPaused = eventObject->spriteAnimPausedBackup;
        gSprites[eventObject->spriteId].affineAnimPaused = eventObject->spriteAffineAnimPausedBackup;
    }
}

void UnfreezeEventObjects(void)
{
    u8 i;
    for (i = 0; i < EVENT_OBJECTS_COUNT; i++)
        if (gEventObjects[i].active)
            npc_sync_anim_pause_bits(&gEventObjects[i]);
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

typedef void (*SpriteStepFunc)(struct Sprite *sprite, u8 dir);

static const SpriteStepFunc gUnknown_0850E6C4[] = {
    little_step,
    little_step,
    little_step,
    little_step,
    little_step,
    little_step,
    little_step,
    little_step,
    little_step,
    little_step,
    little_step,
    little_step,
    little_step,
    little_step,
    little_step,
    little_step,
};

static const SpriteStepFunc gUnknown_0850E704[] = {
    double_little_steps,
    double_little_steps,
    double_little_steps,
    double_little_steps,
    double_little_steps,
    double_little_steps,
    double_little_steps,
    double_little_steps,
};

static const SpriteStepFunc gUnknown_0850E724[] = {
    double_little_steps,
    triple_little_steps,
    triple_little_steps,
    double_little_steps,
    triple_little_steps,
    triple_little_steps,
};

static const SpriteStepFunc gUnknown_0850E73C[] = {
    quad_little_steps,
    quad_little_steps,
    quad_little_steps,
    quad_little_steps,
};

static const SpriteStepFunc gUnknown_0850E74C[] = {
    oct_little_steps,
    oct_little_steps,
};

static const SpriteStepFunc *const gUnknown_0850E754[] = {
    gUnknown_0850E6C4,
    gUnknown_0850E704,
    gUnknown_0850E724,
    gUnknown_0850E73C,
    gUnknown_0850E74C,
};

static const s16 gUnknown_0850E768[] = {
    16, 8, 6, 4, 2
};

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

const s8 gUnknown_0850E772[] = {
    1, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 1, 2, 2, 1, 2,
    2, 1, 2, 2, 1, 2, 1, 1,
    2, 1, 1, 2, 1, 1, 2, 1,
    1, 2, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 1, 1, 1, 0, 1, 1, 0,
    1, 0, 1, 0, 1, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0,
};

const s8 gUnknown_0850E7BA[] = {
     0,  0,  1,  0,  0,  1,  0,  0,
     1,  0,  1,  1,  0,  1,  1,  0,
     1,  1,  0,  1,  1,  0,  1,  1,
     0,  0,  1,  0,  0,  1,  0,  0,
     1,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,
     0,  0, -1,  0,  0, -1,  0,  0,
    -1,  0, -1, -1,  0, -1, -1,  0,
    -1, -1, -1, -1, -1, -1, -1, -2,
};

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

static const s8 gUnknown_0850E802[] = {
    -4,  -6,  -8, -10, -11, -12, -12, -12, -11, -10,  -9,  -8,  -6,  -4,   0,   0
};

static const s8 gUnknown_0850E812[] = {
    0,  -2,  -3,  -4,  -5,  -6,  -6,  -6,  -5,  -5,  -4,  -3,  -2,   0,   0,   0
};

static const s8 gUnknown_0850E822[] = {
    -2,  -4,  -6,  -8,  -9, -10, -10, -10,  -9,  -8,  -6,  -5,  -3,  -2,   0,   0
};

static const s8 *const gUnknown_0850E834[] = {
    gUnknown_0850E802,
    gUnknown_0850E812,
    gUnknown_0850E822
};

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

static const s16 gUnknown_0850E840[] = {
    16, 16, 32,
};

static const u8 gUnknown_0850E846[] = {
    0, 0, 1,
};

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

static const s16 gUnknown_0850E84A[] = {
    32, 32, 64,
};

static const u8 gUnknown_0850E850[] = {
    1, 1, 2,
};

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

void SetEventObjectStepTimer(struct Sprite *sprite, s16 timer)
{
    sprite->data[3] = timer;
}

bool8 RunEventObjectStepTimer(struct Sprite *sprite)
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
        StartSpriteAnim(&gSprites[spriteId], EventObjectDirectionToImageAnimId(var2));
}

void sub_8097BB4(u8 var1, u8 var2)
{
    int spriteId = sub_8097B2C(var1);

    if(spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        const struct EventObjectGraphicsInfo *gfxInfo = GetEventObjectGraphicsInfo(var2);
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

u32 StartFieldEffectForEventObject(u8 fieldEffectId, struct EventObject *eventObject)
{
    EventObjectGetLocalIdAndMap(eventObject, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    return FieldEffectStart(fieldEffectId);
}

void DoShadowFieldEffect(struct EventObject *eventObject)
{
    if (!eventObject->hasShadow)
    {
        eventObject->hasShadow = 1;
        StartFieldEffectForEventObject(FLDEFF_SHADOW, eventObject);
    }
}

static void DoRippleFieldEffect(struct EventObject *eventObject, struct Sprite *sprite)
{
    const struct EventObjectGraphicsInfo *gfxInfo = GetEventObjectGraphicsInfo(eventObject->graphicsId);
    gFieldEffectArguments[0] = sprite->pos1.x;
    gFieldEffectArguments[1] = sprite->pos1.y + (gfxInfo->height >> 1) - 2;
    gFieldEffectArguments[2] = 151;
    gFieldEffectArguments[3] = 3;
    FieldEffectStart(FLDEFF_RIPPLE);
}

u8 (*const gUnknown_0850E854[])(struct EventObject *, struct Sprite *) = {
    sub_8097E50,
    sub_80964B8,
};

u8 (*const gUnknown_0850E85C[])(struct EventObject *, struct Sprite *) = {
    sub_8097EF0,
    sub_80964B8,
};

u8 (*const gUnknown_0850E864[])(struct EventObject *, struct Sprite *) = {
    sub_80980C0,
    sub_80980D0,
    sub_8098124,
};

u8 (*const gUnknown_0850E870[])(struct EventObject *, struct Sprite *) = {
    sub_80980F4,
    sub_8098108,
    sub_8098124,
};

u8 sub_8097E50(struct EventObject *eventObject, struct Sprite *sprite)
{
    u32 one;
    bool32 ableToStore = FALSE;
    if (gUnknown_020375B8 == NULL)
    {
        gUnknown_020375B8 = AllocZeroed(0x14);
        gUnknown_020375B8[0] = eventObject->localId;
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

            if (gUnknown_020375B8[i] == eventObject->localId)
            {
                found = TRUE;
                break;
            }
        }

        if (!found && firstFreeSlot != 16)
        {
            gUnknown_020375B8[firstFreeSlot] = eventObject->localId;
            gUnknown_020375B8[16]++;
            ableToStore = TRUE;
        }
    }

    if (ableToStore == TRUE)
    {
        eventObject->inanimate = TRUE;
        eventObject->facingDirectionLocked = TRUE;
    }

    sprite->data[2] = 1;
    return TRUE;
}

u8 sub_8097EF0(struct EventObject *eventObject, struct Sprite *sprite)
{
    bool32 ableToStore;
    u8 id;

    sprite->data[2] = 1;
    if (gUnknown_020375B8 != NULL)
    {
        ableToStore = FALSE;
        id = sub_8097F78(eventObject);
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
            eventObject->inanimate = GetEventObjectGraphicsInfo(eventObject->graphicsId)->inanimate;
            eventObject->facingDirectionLocked = 0;
            sprite->animPaused = 0;
        }
    }

    return TRUE;
}

u8 sub_8097F78(struct EventObject *eventObject)
{
    u8 i;

    for(i = 0; i < EVENT_OBJECTS_COUNT; i++)
    {
        if(gUnknown_020375B8[i] == eventObject->localId)
            return i;
    }
    return EVENT_OBJECTS_COUNT;
}

void sub_8097FA4(struct EventObject *eventObject)
{
    u8 taskId = CreateTask(sub_8097FE4, 0xFF);
    struct Task *task = &gTasks[taskId];

    StoreWordInTwoHalfwords(&task->data[0], (u32)eventObject);
    eventObject->warpArrowSpriteId = taskId;
    task->data[3] = 0xFFFF;
}

static void sub_8097FE4(u8 taskId)
{
    struct EventObject *eventObject;
    struct Sprite *sprite;
    struct Task *task = &gTasks[taskId];

    LoadWordFromTwoHalfwords(&task->data[0], (u32 *)&eventObject); // load the map object pointer.
    sprite = &gSprites[eventObject->spriteId];

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

    for(i = 0; i < EVENT_OBJECTS_COUNT; i++)
    {
        if(i != var1 && i != var2 &&
            gEventObjects[i].active && i != gPlayerAvatar.eventObjectId)
                FreezeEventObject(&gEventObjects[i]);
    }
}

u8 sub_80980C0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sprite->pos2.y = 0;
    sprite->data[2]++;
    return FALSE;
}

u8 sub_80980D0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sprite->pos2.y -= 8;

    if(sprite->pos2.y == -160)
        sprite->data[2]++;
    return FALSE;
}

u8 sub_80980F4(struct EventObject *eventObject, struct Sprite *sprite)
{
    sprite->pos2.y = -160;
    sprite->data[2]++;
    return FALSE;
}

u8 sub_8098108(struct EventObject *eventObject, struct Sprite *sprite)
{
    sprite->pos2.y += 8;

    if(!sprite->pos2.y)
        sprite->data[2]++;
    return FALSE;
}

// though this function returns TRUE without doing anything, this header is required due to being in an array of functions which needs it.
u8 sub_8098124(struct EventObject *eventObject, struct Sprite *sprite)
{
    return TRUE;
}
