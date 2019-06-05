#include "global.h"
#include "alloc.h"
#include "battle_pyramid.h"
#include "berry.h"
#include "decoration.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "faraway_island.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_effect_helpers.h"
#include "field_player_avatar.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "mauville_old_man.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "palette.h"
#include "random.h"
#include "sprite.h"
#include "task.h"
#include "trainer_see.h"
#include "trainer_hill.h"
#include "util.h"
#include "constants/event_object_movement_constants.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"
#include "constants/items.h"

// this file was known as evobjmv.c in Game Freak's original source

#define movement_type_def(setup, table) \
static u8 setup##_callback(struct EventObject *, struct Sprite *);\
void setup(struct Sprite *sprite)\
{\
    UpdateEventObjectCurrentMovement(&gEventObjects[sprite->data[0]], sprite, setup##_callback);\
}\
static u8 setup##_callback(struct EventObject *eventObject, struct Sprite *sprite)\
{\
    return table[sprite->data[1]](eventObject, sprite);\
}

#define movement_type_empty_callback(setup) \
static u8 setup##_callback(struct EventObject *, struct Sprite *);\
void setup(struct Sprite *sprite)\
{\
    UpdateEventObjectCurrentMovement(&gEventObjects[sprite->data[0]], sprite, setup##_callback);\
}\
static u8 setup##_callback(struct EventObject *eventObject, struct Sprite *sprite)\
{\
    return 0;\
}

EWRAM_DATA struct LockedAnimEventObjects *gLockedAnimEventObjects = {0};

static void MoveCoordsInDirection(u32, s16 *, s16 *, s16, s16);
static bool8 EventObjectExecSingleMovementAction(struct EventObject *, struct Sprite *);
static void SetMovementDelay(struct Sprite *, s16);
static bool8 WaitForMovementDelay(struct Sprite *);
static u8 GetCollisionInDirection(struct EventObject *, u8);
static u32 state_to_direction(u8, u32, u32);
static void TryEnableEventObjectAnim(struct EventObject *, struct Sprite *);
static void EventObjectExecHeldMovementAction(struct EventObject *, struct Sprite *);
static void UpdateEventObjectSpriteAnimPause(struct EventObject *, struct Sprite *);
static bool8 IsCoordOutsideEventObjectMovementRange(struct EventObject *, s16, s16);
static bool8 IsMetatileDirectionallyImpassable(struct EventObject *, s16, s16, u8);
static bool8 DoesObjectCollideWithObjectAt(struct EventObject *, s16, s16);
static void sub_8096530(struct EventObject *, struct Sprite *);
static void UpdateEventObjSpriteVisibility(struct EventObject *, struct Sprite *);
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
static void ApplyLevitateMovement(u8);
static bool8 MovementType_Disguise_Callback(struct EventObject *, struct Sprite *);
static bool8 MovementType_Hidden_Callback(struct EventObject *, struct Sprite *);
static void CreateReflectionEffectSprites(void);
static u8 GetEventObjectIdByLocalId(u8);
static u8 GetEventObjectIdByLocalIdAndMapInternal(u8, u8, u8);
static bool8 GetAvailableEventObjectId(u16, u8, u8, u8 *);
static void SetEventObjectDynamicGraphicsId(struct EventObject *);
static void RemoveEventObjectInternal(struct EventObject *);
static u16 GetEventObjectFlagIdByEventObjectId(u8);
static void UpdateEventObjectVisibility(struct EventObject *, struct Sprite *);
static void MakeObjectTemplateFromEventObjectTemplate(struct EventObjectTemplate *, struct SpriteTemplate *, const struct SubspriteTable **);
static void GetEventObjectMovingCameraOffset(s16 *, s16 *);
static struct EventObjectTemplate *GetEventObjectTemplateByLocalIdAndMap(u8, u8, u8);
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
static struct EventObjectTemplate *FindEventObjectTemplateByLocalId(u8 localId, struct EventObjectTemplate *templates, u8 count);
static void ClearEventObjectMovement(struct EventObject *, struct Sprite *);
static void EventObjectSetSingleMovement(struct EventObject *, struct Sprite *, u8);
static void oamt_npc_ministep_reset(struct Sprite *, u8, u8);
static void UpdateEventObjectSpriteSubpriorityAndVisibility(struct Sprite *);

const struct SpriteTemplate gCameraSpriteTemplate = {0, 0xFFFF, &gDummyOamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, ObjectCB_CameraObject};

void (*const gCameraObjectFuncs[])(struct Sprite *) = {
    CameraObject_0,
    CameraObject_1,
    CameraObject_2,
};

#include "data/field_event_obj/event_object_graphics.h"

// movement type callbacks
static void (*const sMovementTypeCallbacks[])(struct Sprite *) =
{
    [MOVEMENT_TYPE_NONE] = MovementType_None,
    [MOVEMENT_TYPE_LOOK_AROUND] = MovementType_LookAround,
    [MOVEMENT_TYPE_WANDER_AROUND] = MovementType_WanderAround,
    [MOVEMENT_TYPE_WANDER_UP_AND_DOWN] = MovementType_WanderUpAndDown,
    [MOVEMENT_TYPE_WANDER_DOWN_AND_UP] = MovementType_WanderUpAndDown,
    [MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT] = MovementType_WanderLeftAndRight,
    [MOVEMENT_TYPE_WANDER_RIGHT_AND_LEFT] = MovementType_WanderLeftAndRight,
    [MOVEMENT_TYPE_FACE_UP] = MovementType_FaceDirection,
    [MOVEMENT_TYPE_FACE_DOWN] = MovementType_FaceDirection,
    [MOVEMENT_TYPE_FACE_LEFT] = MovementType_FaceDirection,
    [MOVEMENT_TYPE_FACE_RIGHT] = MovementType_FaceDirection,
    [MOVEMENT_TYPE_PLAYER] = MovementType_Player,
    [MOVEMENT_TYPE_BERRY_TREE_GROWTH] = MovementType_BerryTreeGrowth,
    [MOVEMENT_TYPE_FACE_DOWN_AND_UP] = MovementType_FaceDownAndUp,
    [MOVEMENT_TYPE_FACE_LEFT_AND_RIGHT] = MovementType_FaceLeftAndRight,
    [MOVEMENT_TYPE_FACE_UP_AND_LEFT] = MovementType_FaceUpAndLeft,
    [MOVEMENT_TYPE_FACE_UP_AND_RIGHT] = MovementType_FaceUpAndRight,
    [MOVEMENT_TYPE_FACE_DOWN_AND_LEFT] = MovementType_FaceDownAndLeft,
    [MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT] = MovementType_FaceDownAndRight,
    [MOVEMENT_TYPE_FACE_DOWN_UP_AND_LEFT] = MovementType_FaceDownUpAndLeft,
    [MOVEMENT_TYPE_FACE_DOWN_UP_AND_RIGHT] = MovementType_FaceDownUpAndRight,
    [MOVEMENT_TYPE_FACE_UP_LEFT_AND_RIGHT] = MovementType_FaceUpRightAndLeft,
    [MOVEMENT_TYPE_FACE_DOWN_LEFT_AND_RIGHT] = MovementType_FaceDownRightAndLeft,
    [MOVEMENT_TYPE_ROTATE_COUNTERCLOCKWISE] = MovementType_RotateCounterclockwise,
    [MOVEMENT_TYPE_ROTATE_CLOCKWISE] = MovementType_RotateClockwise,
    [MOVEMENT_TYPE_WALK_UP_AND_DOWN] = MovementType_WalkBackAndForth,
    [MOVEMENT_TYPE_WALK_DOWN_AND_UP] = MovementType_WalkBackAndForth,
    [MOVEMENT_TYPE_WALK_LEFT_AND_RIGHT] = MovementType_WalkBackAndForth,
    [MOVEMENT_TYPE_WALK_RIGHT_AND_LEFT] = MovementType_WalkBackAndForth,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_RIGHT_LEFT_DOWN] = MovementType_WalkSequenceUpRightLeftDown,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_LEFT_DOWN_UP] = MovementType_WalkSequenceRightLeftDownUp,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_UP_RIGHT_LEFT] = MovementType_WalkSequenceDownUpRightLeft,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_DOWN_UP_RIGHT] = MovementType_WalkSequenceLeftDownUpRight,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_LEFT_RIGHT_DOWN] = MovementType_WalkSequenceUpLeftRightDown,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_RIGHT_DOWN_UP] = MovementType_WalkSequenceLeftRightDownUp,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_UP_LEFT_RIGHT] = MovementType_WalkSequenceDownUpLeftRight,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_DOWN_UP_LEFT] = MovementType_WalkSequenceRightDownUpLeft,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_DOWN_RIGHT] = MovementType_WalkSequenceLeftUpDownRight,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_DOWN_RIGHT_LEFT] = MovementType_WalkSequenceUpDownRightLeft,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_LEFT_UP_DOWN] = MovementType_WalkSequenceRightLeftUpDown,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_RIGHT_LEFT_UP] = MovementType_WalkSequenceDownRightLeftUp,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_UP_DOWN_LEFT] = MovementType_WalkSequenceRightUpDownLeft,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_DOWN_LEFT_RIGHT] = MovementType_WalkSequenceUpDownLeftRight,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_RIGHT_UP_DOWN] = MovementType_WalkSequenceLeftRightUpDown,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_RIGHT_UP] = MovementType_WalkSequenceDownLeftRightUp,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_LEFT_DOWN_RIGHT] = MovementType_WalkSequenceUpLeftDownRight,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_RIGHT_UP_LEFT] = MovementType_WalkSequenceDownRightUpLeft,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_DOWN_RIGHT_UP] = MovementType_WalkSequenceLeftDownRightUp,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_UP_LEFT_DOWN] = MovementType_WalkSequenceRightUpLeftDown,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_RIGHT_DOWN_LEFT] = MovementType_WalkSequenceUpRightDownLeft,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT] = MovementType_WalkSequenceDownLeftUpRight,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN] = MovementType_WalkSequenceLeftUpRightDown,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_DOWN_LEFT_UP] = MovementType_WalkSequenceRightDownLeftUp,
    [MOVEMENT_TYPE_COPY_PLAYER] = MovementType_CopyPlayer,
    [MOVEMENT_TYPE_COPY_PLAYER_OPPOSITE] = MovementType_CopyPlayer,
    [MOVEMENT_TYPE_COPY_PLAYER_COUNTERCLOCKWISE] = MovementType_CopyPlayer,
    [MOVEMENT_TYPE_COPY_PLAYER_CLOCKWISE] = MovementType_CopyPlayer,
    [MOVEMENT_TYPE_TREE_DISGUISE] = MovementType_TreeDisguise,
    [MOVEMENT_TYPE_MOUNTAIN_DISGUISE] = MovementType_MountainDisguise,
    [MOVEMENT_TYPE_COPY_PLAYER_IN_GRASS] = MovementType_CopyPlayerInGrass,
    [MOVEMENT_TYPE_COPY_PLAYER_OPPOSITE_IN_GRASS] = MovementType_CopyPlayerInGrass,
    [MOVEMENT_TYPE_COPY_PLAYER_COUNTERCLOCKWISE_IN_GRASS] = MovementType_CopyPlayerInGrass,
    [MOVEMENT_TYPE_COPY_PLAYER_CLOCKWISE_IN_GRASS] = MovementType_CopyPlayerInGrass,
    [MOVEMENT_TYPE_HIDDEN] = MovementType_Hidden,
    [MOVEMENT_TYPE_WALK_IN_PLACE_DOWN] = MovementType_WalkInPlace,
    [MOVEMENT_TYPE_WALK_IN_PLACE_UP] = MovementType_WalkInPlace,
    [MOVEMENT_TYPE_WALK_IN_PLACE_LEFT] = MovementType_WalkInPlace,
    [MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT] = MovementType_WalkInPlace,
    [MOVEMENT_TYPE_JOG_IN_PLACE_DOWN] = MovementType_JogInPlace,
    [MOVEMENT_TYPE_JOG_IN_PLACE_UP] = MovementType_JogInPlace,
    [MOVEMENT_TYPE_JOG_IN_PLACE_LEFT] = MovementType_JogInPlace,
    [MOVEMENT_TYPE_JOG_IN_PLACE_RIGHT] = MovementType_JogInPlace,
    [MOVEMENT_TYPE_RUN_IN_PLACE_DOWN] = MovementType_RunInPlace,
    [MOVEMENT_TYPE_RUN_IN_PLACE_UP] = MovementType_RunInPlace,
    [MOVEMENT_TYPE_RUN_IN_PLACE_LEFT] = MovementType_RunInPlace,
    [MOVEMENT_TYPE_RUN_IN_PLACE_RIGHT] = MovementType_RunInPlace,
    [MOVEMENT_TYPE_INVISIBLE] = MovementType_Invisible,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_DOWN] = MovementType_WalkSlowlyInPlace,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_UP] = MovementType_WalkSlowlyInPlace,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_LEFT] = MovementType_WalkSlowlyInPlace,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_RIGHT] = MovementType_WalkSlowlyInPlace,
};

const u8 gRangedMovementTypes[] = {
    [MOVEMENT_TYPE_NONE] = 0,
    [MOVEMENT_TYPE_LOOK_AROUND] = 0,
    [MOVEMENT_TYPE_WANDER_AROUND] = 1,
    [MOVEMENT_TYPE_WANDER_UP_AND_DOWN] = 1,
    [MOVEMENT_TYPE_WANDER_DOWN_AND_UP] = 1,
    [MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT] = 1,
    [MOVEMENT_TYPE_WANDER_RIGHT_AND_LEFT] = 1,
    [MOVEMENT_TYPE_FACE_UP] = 0,
    [MOVEMENT_TYPE_FACE_DOWN] = 0,
    [MOVEMENT_TYPE_FACE_LEFT] = 0,
    [MOVEMENT_TYPE_FACE_RIGHT] = 0,
    [MOVEMENT_TYPE_PLAYER] = 0,
    [MOVEMENT_TYPE_BERRY_TREE_GROWTH] = 0,
    [MOVEMENT_TYPE_FACE_DOWN_AND_UP] = 0,
    [MOVEMENT_TYPE_FACE_LEFT_AND_RIGHT] = 0,
    [MOVEMENT_TYPE_FACE_UP_AND_LEFT] = 0,
    [MOVEMENT_TYPE_FACE_UP_AND_RIGHT] = 0,
    [MOVEMENT_TYPE_FACE_DOWN_AND_LEFT] = 0,
    [MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT] = 0,
    [MOVEMENT_TYPE_FACE_DOWN_UP_AND_LEFT] = 0,
    [MOVEMENT_TYPE_FACE_DOWN_UP_AND_RIGHT] = 0,
    [MOVEMENT_TYPE_FACE_UP_LEFT_AND_RIGHT] = 0,
    [MOVEMENT_TYPE_FACE_DOWN_LEFT_AND_RIGHT] = 0,
    [MOVEMENT_TYPE_ROTATE_COUNTERCLOCKWISE] = 0,
    [MOVEMENT_TYPE_ROTATE_CLOCKWISE] = 0,
    [MOVEMENT_TYPE_WALK_UP_AND_DOWN] = 1,
    [MOVEMENT_TYPE_WALK_DOWN_AND_UP] = 1,
    [MOVEMENT_TYPE_WALK_LEFT_AND_RIGHT] = 1,
    [MOVEMENT_TYPE_WALK_RIGHT_AND_LEFT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_RIGHT_LEFT_DOWN] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_LEFT_DOWN_UP] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_UP_RIGHT_LEFT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_DOWN_UP_RIGHT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_LEFT_RIGHT_DOWN] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_RIGHT_DOWN_UP] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_UP_LEFT_RIGHT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_DOWN_UP_LEFT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_DOWN_RIGHT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_DOWN_RIGHT_LEFT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_LEFT_UP_DOWN] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_RIGHT_LEFT_UP] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_UP_DOWN_LEFT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_DOWN_LEFT_RIGHT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_RIGHT_UP_DOWN] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_RIGHT_UP] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_LEFT_DOWN_RIGHT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_RIGHT_UP_LEFT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_DOWN_RIGHT_UP] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_UP_LEFT_DOWN] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_RIGHT_DOWN_LEFT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_DOWN_LEFT_UP] = 1,
    [MOVEMENT_TYPE_COPY_PLAYER] = 1,
    [MOVEMENT_TYPE_COPY_PLAYER_OPPOSITE] = 1,
    [MOVEMENT_TYPE_COPY_PLAYER_COUNTERCLOCKWISE] = 1,
    [MOVEMENT_TYPE_COPY_PLAYER_CLOCKWISE] = 1,
    [MOVEMENT_TYPE_TREE_DISGUISE] = 0,
    [MOVEMENT_TYPE_MOUNTAIN_DISGUISE] = 0,
    [MOVEMENT_TYPE_COPY_PLAYER_IN_GRASS] = 1,
    [MOVEMENT_TYPE_COPY_PLAYER_OPPOSITE_IN_GRASS] = 1,
    [MOVEMENT_TYPE_COPY_PLAYER_COUNTERCLOCKWISE_IN_GRASS] = 1,
    [MOVEMENT_TYPE_COPY_PLAYER_CLOCKWISE_IN_GRASS] = 1,
    [MOVEMENT_TYPE_HIDDEN] = 0,
    [MOVEMENT_TYPE_WALK_IN_PLACE_DOWN] = 0,
    [MOVEMENT_TYPE_WALK_IN_PLACE_UP] = 0,
    [MOVEMENT_TYPE_WALK_IN_PLACE_LEFT] = 0,
    [MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT] = 0,
    [MOVEMENT_TYPE_JOG_IN_PLACE_DOWN] = 0,
    [MOVEMENT_TYPE_JOG_IN_PLACE_UP] = 0,
    [MOVEMENT_TYPE_JOG_IN_PLACE_LEFT] = 0,
    [MOVEMENT_TYPE_JOG_IN_PLACE_RIGHT] = 0,
    [MOVEMENT_TYPE_RUN_IN_PLACE_DOWN] = 0,
    [MOVEMENT_TYPE_RUN_IN_PLACE_UP] = 0,
    [MOVEMENT_TYPE_RUN_IN_PLACE_LEFT] = 0,
    [MOVEMENT_TYPE_RUN_IN_PLACE_RIGHT] = 0,
    [MOVEMENT_TYPE_INVISIBLE] = 0,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_DOWN] = 0,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_UP] = 0,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_LEFT] = 0,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_RIGHT] = 0,
};

const u8 gInitialMovementTypeFacingDirections[] = {
    [MOVEMENT_TYPE_NONE] = DIR_SOUTH,
    [MOVEMENT_TYPE_LOOK_AROUND] = DIR_SOUTH,
    [MOVEMENT_TYPE_WANDER_AROUND] = DIR_SOUTH,
    [MOVEMENT_TYPE_WANDER_UP_AND_DOWN] = DIR_NORTH,
    [MOVEMENT_TYPE_WANDER_DOWN_AND_UP] = DIR_SOUTH,
    [MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT] = DIR_WEST,
    [MOVEMENT_TYPE_WANDER_RIGHT_AND_LEFT] = DIR_EAST,
    [MOVEMENT_TYPE_FACE_UP] = DIR_NORTH,
    [MOVEMENT_TYPE_FACE_DOWN] = DIR_SOUTH,
    [MOVEMENT_TYPE_FACE_LEFT] = DIR_WEST,
    [MOVEMENT_TYPE_FACE_RIGHT] = DIR_EAST,
    [MOVEMENT_TYPE_PLAYER] = DIR_SOUTH,
    [MOVEMENT_TYPE_BERRY_TREE_GROWTH] = DIR_SOUTH,
    [MOVEMENT_TYPE_FACE_DOWN_AND_UP] = DIR_SOUTH,
    [MOVEMENT_TYPE_FACE_LEFT_AND_RIGHT] = DIR_WEST,
    [MOVEMENT_TYPE_FACE_UP_AND_LEFT] = DIR_NORTH,
    [MOVEMENT_TYPE_FACE_UP_AND_RIGHT] = DIR_NORTH,
    [MOVEMENT_TYPE_FACE_DOWN_AND_LEFT] = DIR_SOUTH,
    [MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT] = DIR_SOUTH,
    [MOVEMENT_TYPE_FACE_DOWN_UP_AND_LEFT] = DIR_SOUTH,
    [MOVEMENT_TYPE_FACE_DOWN_UP_AND_RIGHT] = DIR_SOUTH,
    [MOVEMENT_TYPE_FACE_UP_LEFT_AND_RIGHT] = DIR_NORTH,
    [MOVEMENT_TYPE_FACE_DOWN_LEFT_AND_RIGHT] = DIR_SOUTH,
    [MOVEMENT_TYPE_ROTATE_COUNTERCLOCKWISE] = DIR_SOUTH,
    [MOVEMENT_TYPE_ROTATE_CLOCKWISE] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_UP_AND_DOWN] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_DOWN_AND_UP] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_LEFT_AND_RIGHT] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_RIGHT_AND_LEFT] = DIR_EAST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_RIGHT_LEFT_DOWN] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_LEFT_DOWN_UP] = DIR_EAST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_UP_RIGHT_LEFT] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_DOWN_UP_RIGHT] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_LEFT_RIGHT_DOWN] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_RIGHT_DOWN_UP] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_UP_LEFT_RIGHT] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_DOWN_UP_LEFT] = DIR_EAST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_DOWN_RIGHT] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_DOWN_RIGHT_LEFT] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_LEFT_UP_DOWN] = DIR_EAST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_RIGHT_LEFT_UP] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_UP_DOWN_LEFT] = DIR_EAST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_DOWN_LEFT_RIGHT] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_RIGHT_UP_DOWN] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_RIGHT_UP] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_LEFT_DOWN_RIGHT] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_RIGHT_UP_LEFT] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_DOWN_RIGHT_UP] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_UP_LEFT_DOWN] = DIR_EAST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_RIGHT_DOWN_LEFT] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_DOWN_LEFT_UP] = DIR_EAST,
    [MOVEMENT_TYPE_COPY_PLAYER] = DIR_NORTH,
    [MOVEMENT_TYPE_COPY_PLAYER_OPPOSITE] = DIR_SOUTH,
    [MOVEMENT_TYPE_COPY_PLAYER_COUNTERCLOCKWISE] = DIR_WEST,
    [MOVEMENT_TYPE_COPY_PLAYER_CLOCKWISE] = DIR_EAST,
    [MOVEMENT_TYPE_TREE_DISGUISE] = DIR_SOUTH,
    [MOVEMENT_TYPE_MOUNTAIN_DISGUISE] = DIR_SOUTH,
    [MOVEMENT_TYPE_COPY_PLAYER_IN_GRASS] = DIR_NORTH,
    [MOVEMENT_TYPE_COPY_PLAYER_OPPOSITE_IN_GRASS] = DIR_SOUTH,
    [MOVEMENT_TYPE_COPY_PLAYER_COUNTERCLOCKWISE_IN_GRASS] = DIR_WEST,
    [MOVEMENT_TYPE_COPY_PLAYER_CLOCKWISE_IN_GRASS] = DIR_EAST,
    [MOVEMENT_TYPE_HIDDEN] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_IN_PLACE_DOWN] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_IN_PLACE_UP] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_IN_PLACE_LEFT] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT] = DIR_EAST,
    [MOVEMENT_TYPE_JOG_IN_PLACE_DOWN] = DIR_SOUTH,
    [MOVEMENT_TYPE_JOG_IN_PLACE_UP] = DIR_NORTH,
    [MOVEMENT_TYPE_JOG_IN_PLACE_LEFT] = DIR_WEST,
    [MOVEMENT_TYPE_JOG_IN_PLACE_RIGHT] = DIR_EAST,
    [MOVEMENT_TYPE_RUN_IN_PLACE_DOWN] = DIR_SOUTH,
    [MOVEMENT_TYPE_RUN_IN_PLACE_UP] = DIR_NORTH,
    [MOVEMENT_TYPE_RUN_IN_PLACE_LEFT] = DIR_WEST,
    [MOVEMENT_TYPE_RUN_IN_PLACE_RIGHT] = DIR_EAST,
    [MOVEMENT_TYPE_INVISIBLE] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_DOWN] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_UP] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_LEFT] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_RIGHT] = DIR_EAST,
};

#define EVENT_OBJ_PAL_TAG_0  0x1103
#define EVENT_OBJ_PAL_TAG_1  0x1104
#define EVENT_OBJ_PAL_TAG_2  0x1105
#define EVENT_OBJ_PAL_TAG_3  0x1106
#define EVENT_OBJ_PAL_TAG_4  0x1107
#define EVENT_OBJ_PAL_TAG_5  0x1108
#define EVENT_OBJ_PAL_TAG_6  0x1109
#define EVENT_OBJ_PAL_TAG_7  0x110A
#define EVENT_OBJ_PAL_TAG_8  0x1100
#define EVENT_OBJ_PAL_TAG_9  0x1101
#define EVENT_OBJ_PAL_TAG_10 0x1102
#define EVENT_OBJ_PAL_TAG_11 0x1115
#define EVENT_OBJ_PAL_TAG_12 0x110B
#define EVENT_OBJ_PAL_TAG_13 0x110C
#define EVENT_OBJ_PAL_TAG_14 0x110D
#define EVENT_OBJ_PAL_TAG_15 0x110E
#define EVENT_OBJ_PAL_TAG_16 0x110F
#define EVENT_OBJ_PAL_TAG_17 0x1110
#define EVENT_OBJ_PAL_TAG_18 0x1111
#define EVENT_OBJ_PAL_TAG_19 0x1112
#define EVENT_OBJ_PAL_TAG_20 0x1113
#define EVENT_OBJ_PAL_TAG_21 0x1114
#define EVENT_OBJ_PAL_TAG_22 0x1116
#define EVENT_OBJ_PAL_TAG_23 0x1117
#define EVENT_OBJ_PAL_TAG_24 0x1118
#define EVENT_OBJ_PAL_TAG_25 0x1119
#define EVENT_OBJ_PAL_TAG_26 0x111B
#define EVENT_OBJ_PAL_TAG_27 0x111C
#define EVENT_OBJ_PAL_TAG_28 0x111D
#define EVENT_OBJ_PAL_TAG_29 0x111E
#define EVENT_OBJ_PAL_TAG_30 0x111F
#define EVENT_OBJ_PAL_TAG_31 0x1120
#define EVENT_OBJ_PAL_TAG_32 0x1121
#define EVENT_OBJ_PAL_TAG_33 0x1122
#define EVENT_OBJ_PAL_TAG_34 0x1123
#define EVENT_OBJ_PAL_TAG_NONE 0x11FF

#include "data/field_event_obj/field_effect_object_template_pointers.h"
#include "data/field_event_obj/event_object_pic_tables.h"
#include "data/field_event_obj/event_object_anims.h"
#include "data/field_event_obj/base_oam.h"
#include "data/field_event_obj/event_object_subsprites.h"
#include "data/field_event_obj/event_object_graphics_info.h"
#include "data/field_event_obj/event_object_graphics_info_pointers.h"

const struct SpritePalette sEventObjectSpritePalettes[] = {
    {gEventObjectPalette0,  EVENT_OBJ_PAL_TAG_0},
    {gEventObjectPalette1,  EVENT_OBJ_PAL_TAG_1},
    {gEventObjectPalette2,  EVENT_OBJ_PAL_TAG_2},
    {gEventObjectPalette3,  EVENT_OBJ_PAL_TAG_3},
    {gEventObjectPalette4,  EVENT_OBJ_PAL_TAG_4},
    {gEventObjectPalette5,  EVENT_OBJ_PAL_TAG_5},
    {gEventObjectPalette6,  EVENT_OBJ_PAL_TAG_6},
    {gEventObjectPalette7,  EVENT_OBJ_PAL_TAG_7},
    {gEventObjectPalette8,  EVENT_OBJ_PAL_TAG_8},
    {gEventObjectPalette9,  EVENT_OBJ_PAL_TAG_9},
    {gEventObjectPalette10, EVENT_OBJ_PAL_TAG_10},
    {gEventObjectPalette11, EVENT_OBJ_PAL_TAG_11},
    {gEventObjectPalette12, EVENT_OBJ_PAL_TAG_12},
    {gEventObjectPalette13, EVENT_OBJ_PAL_TAG_13},
    {gEventObjectPalette14, EVENT_OBJ_PAL_TAG_14},
    {gEventObjectPalette15, EVENT_OBJ_PAL_TAG_15},
    {gEventObjectPalette16, EVENT_OBJ_PAL_TAG_16},
    {gEventObjectPalette17, EVENT_OBJ_PAL_TAG_17},
    {gEventObjectPalette18, EVENT_OBJ_PAL_TAG_18},
    {gEventObjectPalette19, EVENT_OBJ_PAL_TAG_19},
    {gEventObjectPalette20, EVENT_OBJ_PAL_TAG_20},
    {gEventObjectPalette21, EVENT_OBJ_PAL_TAG_21},
    {gEventObjectPalette22, EVENT_OBJ_PAL_TAG_22},
    {gEventObjectPalette23, EVENT_OBJ_PAL_TAG_23},
    {gEventObjectPalette24, EVENT_OBJ_PAL_TAG_24},
    {gEventObjectPalette25, EVENT_OBJ_PAL_TAG_25},
    {gEventObjectPalette26, EVENT_OBJ_PAL_TAG_26},
    {gEventObjectPalette27, EVENT_OBJ_PAL_TAG_27},
    {gEventObjectPalette28, EVENT_OBJ_PAL_TAG_28},
    {gEventObjectPalette29, EVENT_OBJ_PAL_TAG_29},
    {gEventObjectPalette30, EVENT_OBJ_PAL_TAG_30},
    {gEventObjectPalette31, EVENT_OBJ_PAL_TAG_31},
    {gEventObjectPalette32, EVENT_OBJ_PAL_TAG_32},
    {gEventObjectPalette33, EVENT_OBJ_PAL_TAG_33},
    {gEventObjectPalette34, EVENT_OBJ_PAL_TAG_34},
    {NULL,                  0x0000},
};

#include "data/field_event_obj/berry_tree_graphics_tables.h"
#include "data/field_event_obj/field_effect_objects.h"

const s16 gMovementDelaysMedium[] = {32, 64,  96, 128};
const s16 gMovementDelaysLong[] =   {32, 64, 128, 192};
const s16 gMovementDelaysShort[] =  {32, 48,  64,  80};

#include "data/field_event_obj/movement_type_func_tables.h"

const u8 gFaceDirectionAnimNums[] = {
    [DIR_NONE] = 0,
    [DIR_SOUTH] = 0,
    [DIR_NORTH] = 1,
    [DIR_WEST] = 2,
    [DIR_EAST] = 3,
    [DIR_SOUTHWEST] = 0,
    [DIR_SOUTHEAST] = 0,
    [DIR_NORTHWEST] = 1,
    [DIR_NORTHEAST] = 1,
};
const u8 gMoveDirectionAnimNums[] = {
    [DIR_NONE] = 4,
    [DIR_SOUTH] = 4,
    [DIR_NORTH] = 5,
    [DIR_WEST] = 6,
    [DIR_EAST] = 7,
    [DIR_SOUTHWEST] = 4,
    [DIR_SOUTHEAST] = 4,
    [DIR_NORTHWEST] = 5,
    [DIR_NORTHEAST] = 5,
};
const u8 gMoveDirectionFastAnimNums[] = {
    [DIR_NONE] = 8,
    [DIR_SOUTH] = 8,
    [DIR_NORTH] = 9,
    [DIR_WEST] = 10,
    [DIR_EAST] = 11,
    [DIR_SOUTHWEST] = 8,
    [DIR_SOUTHEAST] = 8,
    [DIR_NORTHWEST] = 9,
    [DIR_NORTHEAST] = 9,
};
const u8 gMoveDirectionFasterAnimNums[] = {
    [DIR_NONE] = 12,
    [DIR_SOUTH] = 12,
    [DIR_NORTH] = 13,
    [DIR_WEST] = 14,
    [DIR_EAST] = 15,
    [DIR_SOUTHWEST] = 12,
    [DIR_SOUTHEAST] = 12,
    [DIR_NORTHWEST] = 13,
    [DIR_NORTHEAST] = 13,
};
const u8 gMoveDirectionFastestAnimNums[] = {
    [DIR_NONE] = 16,
    [DIR_SOUTH] = 16,
    [DIR_NORTH] = 17,
    [DIR_WEST] = 18,
    [DIR_EAST] = 19,
    [DIR_SOUTHWEST] = 16,
    [DIR_SOUTHEAST] = 16,
    [DIR_NORTHWEST] = 17,
    [DIR_NORTHEAST] = 17,
};
const u8 gJumpSpecialDirectionAnimNums[] = { // used for jumping onto surf mon
    [DIR_NONE] = 20,
    [DIR_SOUTH] = 20,
    [DIR_NORTH] = 21,
    [DIR_WEST] = 22,
    [DIR_EAST] = 23,
    [DIR_SOUTHWEST] = 20,
    [DIR_SOUTHEAST] = 20,
    [DIR_NORTHWEST] = 21,
    [DIR_NORTHEAST] = 21,
};
const u8 gAcroWheelieDirectionAnimNums[] = {
    [DIR_NONE] = 20,
    [DIR_SOUTH] = 20,
    [DIR_NORTH] = 21,
    [DIR_WEST] = 22,
    [DIR_EAST] = 23,
    [DIR_SOUTHWEST] = 20,
    [DIR_SOUTHEAST] = 20,
    [DIR_NORTHWEST] = 21,
    [DIR_NORTHEAST] = 21,
};
const u8 gUnrefAnimNums_08375633[] = {
    [DIR_NONE] = 24,
    [DIR_SOUTH] = 24,
    [DIR_NORTH] = 25,
    [DIR_WEST] = 26,
    [DIR_EAST] = 27,
    [DIR_SOUTHWEST] = 24,
    [DIR_SOUTHEAST] = 24,
    [DIR_NORTHWEST] = 25,
    [DIR_NORTHEAST] = 25,
};
const u8 gAcroEndWheelieDirectionAnimNums[] = {
    [DIR_NONE] = 28,
    [DIR_SOUTH] = 28,
    [DIR_NORTH] = 29,
    [DIR_WEST] = 30,
    [DIR_EAST] = 31,
    [DIR_SOUTHWEST] = 28,
    [DIR_SOUTHEAST] = 28,
    [DIR_NORTHWEST] = 29,
    [DIR_NORTHEAST] = 29,
};
const u8 gAcroUnusedActionDirectionAnimNums[] = {
    [DIR_NONE] = 32,
    [DIR_SOUTH] = 32,
    [DIR_NORTH] = 33,
    [DIR_WEST] = 34,
    [DIR_EAST] = 35,
    [DIR_SOUTHWEST] = 32,
    [DIR_SOUTHEAST] = 32,
    [DIR_NORTHWEST] = 33,
    [DIR_NORTHEAST] = 33,
};
const u8 gAcroWheeliePedalDirectionAnimNums[] = {
    [DIR_NONE] = 36,
    [DIR_SOUTH] = 36,
    [DIR_NORTH] = 37,
    [DIR_WEST] = 38,
    [DIR_EAST] = 39,
    [DIR_SOUTHWEST] = 36,
    [DIR_SOUTHEAST] = 36,
    [DIR_NORTHWEST] = 37,
    [DIR_NORTHEAST] = 37,
};
const u8 gFishingDirectionAnimNums[] = {
    [DIR_NONE] = 0,
    [DIR_SOUTH] = 0,
    [DIR_NORTH] = 1,
    [DIR_WEST] = 2,
    [DIR_EAST] = 3,
    [DIR_SOUTHWEST] = 0,
    [DIR_SOUTHEAST] = 0,
    [DIR_NORTHWEST] = 1,
    [DIR_NORTHEAST] = 1,
};
const u8 gFishingNoCatchDirectionAnimNums[] = {
    [DIR_NONE] = 4,
    [DIR_SOUTH] = 4,
    [DIR_NORTH] = 5,
    [DIR_WEST] = 6,
    [DIR_EAST] = 7,
    [DIR_SOUTHWEST] = 4,
    [DIR_SOUTHEAST] = 4,
    [DIR_NORTHWEST] = 5,
    [DIR_NORTHEAST] = 5,
};
const u8 gFishingBiteDirectionAnimNums[] = {
    [DIR_NONE] = 8,
    [DIR_SOUTH] = 8,
    [DIR_NORTH] = 9,
    [DIR_WEST] = 10,
    [DIR_EAST] = 11,
    [DIR_SOUTHWEST] = 8,
    [DIR_SOUTHEAST] = 8,
    [DIR_NORTHWEST] = 9,
    [DIR_NORTHEAST] = 9,
};
const u8 gRunningDirectionAnimNums[] = {
    [DIR_NONE] = 20,
    [DIR_SOUTH] = 20,
    [DIR_NORTH] = 21,
    [DIR_WEST] = 22,
    [DIR_EAST] = 23,
    [DIR_SOUTHWEST] = 20,
    [DIR_SOUTHEAST] = 20,
    [DIR_NORTHWEST] = 21,
    [DIR_NORTHEAST] = 21,
};

const u8 gTrainerFacingDirectionMovementTypes[] = {
    [DIR_NONE] = MOVEMENT_TYPE_FACE_DOWN,
    [DIR_SOUTH] = MOVEMENT_TYPE_FACE_DOWN,
    [DIR_NORTH] = MOVEMENT_TYPE_FACE_UP,
    [DIR_WEST] = MOVEMENT_TYPE_FACE_LEFT,
    [DIR_EAST] = MOVEMENT_TYPE_FACE_RIGHT,
    [DIR_SOUTHWEST] = MOVEMENT_TYPE_FACE_DOWN,
    [DIR_SOUTHEAST] = MOVEMENT_TYPE_FACE_DOWN,
    [DIR_NORTHWEST] = MOVEMENT_TYPE_FACE_UP,
    [DIR_NORTHEAST] = MOVEMENT_TYPE_FACE_UP,
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

static const struct Coords16 sDirectionToVectors[] = {
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

const u8 gFaceDirectionMovementActions[] = {
    MOVEMENT_ACTION_FACE_DOWN,
    MOVEMENT_ACTION_FACE_DOWN,
    MOVEMENT_ACTION_FACE_UP,
    MOVEMENT_ACTION_FACE_LEFT,
    MOVEMENT_ACTION_FACE_RIGHT,
};
const u8 gWalkSlowMovementActions[] = {
    MOVEMENT_ACTION_WALK_SLOW_DOWN,
    MOVEMENT_ACTION_WALK_SLOW_DOWN,
    MOVEMENT_ACTION_WALK_SLOW_UP,
    MOVEMENT_ACTION_WALK_SLOW_LEFT,
    MOVEMENT_ACTION_WALK_SLOW_RIGHT,
};
const u8 gWalkNormalMovementActions[] = {
    MOVEMENT_ACTION_WALK_NORMAL_DOWN,
    MOVEMENT_ACTION_WALK_NORMAL_DOWN,
    MOVEMENT_ACTION_WALK_NORMAL_UP,
    MOVEMENT_ACTION_WALK_NORMAL_LEFT,
    MOVEMENT_ACTION_WALK_NORMAL_RIGHT,
};
const u8 gWalkFastMovementActions[] = {
    MOVEMENT_ACTION_WALK_FAST_DOWN,
    MOVEMENT_ACTION_WALK_FAST_DOWN,
    MOVEMENT_ACTION_WALK_FAST_UP,
    MOVEMENT_ACTION_WALK_FAST_LEFT,
    MOVEMENT_ACTION_WALK_FAST_RIGHT,
};
const u8 gRideWaterCurrentMovementActions[] = {
    MOVEMENT_ACTION_RIDE_WATER_CURRENT_DOWN,
    MOVEMENT_ACTION_RIDE_WATER_CURRENT_DOWN,
    MOVEMENT_ACTION_RIDE_WATER_CURRENT_UP,
    MOVEMENT_ACTION_RIDE_WATER_CURRENT_LEFT,
    MOVEMENT_ACTION_RIDE_WATER_CURRENT_RIGHT,
};
const u8 gWalkFastestMovementActions[] = {
    MOVEMENT_ACTION_WALK_FASTEST_DOWN,
    MOVEMENT_ACTION_WALK_FASTEST_DOWN,
    MOVEMENT_ACTION_WALK_FASTEST_UP,
    MOVEMENT_ACTION_WALK_FASTEST_LEFT,
    MOVEMENT_ACTION_WALK_FASTEST_RIGHT,
};
const u8 gSlideMovementActions[] = {
    MOVEMENT_ACTION_SLIDE_DOWN,
    MOVEMENT_ACTION_SLIDE_DOWN,
    MOVEMENT_ACTION_SLIDE_UP,
    MOVEMENT_ACTION_SLIDE_LEFT,
    MOVEMENT_ACTION_SLIDE_RIGHT,
};
const u8 gPlayerRunMovementActions[] = {
    MOVEMENT_ACTION_PLAYER_RUN_DOWN,
    MOVEMENT_ACTION_PLAYER_RUN_DOWN,
    MOVEMENT_ACTION_PLAYER_RUN_UP,
    MOVEMENT_ACTION_PLAYER_RUN_LEFT,
    MOVEMENT_ACTION_PLAYER_RUN_RIGHT,
};
const u8 gJump2MovementActions[] = {
    MOVEMENT_ACTION_JUMP_2_DOWN,
    MOVEMENT_ACTION_JUMP_2_DOWN,
    MOVEMENT_ACTION_JUMP_2_UP,
    MOVEMENT_ACTION_JUMP_2_LEFT,
    MOVEMENT_ACTION_JUMP_2_RIGHT,
};
const u8 gJumpInPlaceMovementActions[] = {
    MOVEMENT_ACTION_JUMP_IN_PLACE_DOWN,
    MOVEMENT_ACTION_JUMP_IN_PLACE_DOWN,
    MOVEMENT_ACTION_JUMP_IN_PLACE_UP,
    MOVEMENT_ACTION_JUMP_IN_PLACE_LEFT,
    MOVEMENT_ACTION_JUMP_IN_PLACE_RIGHT,
};
const u8 gJumpInPlaceTurnAroundMovementActions[] = {
    MOVEMENT_ACTION_JUMP_IN_PLACE_UP_DOWN,
    MOVEMENT_ACTION_JUMP_IN_PLACE_UP_DOWN,
    MOVEMENT_ACTION_JUMP_IN_PLACE_DOWN_UP,
    MOVEMENT_ACTION_JUMP_IN_PLACE_RIGHT_LEFT,
    MOVEMENT_ACTION_JUMP_IN_PLACE_LEFT_RIGHT,
};
const u8 gJumpMovementActions[] = {
    MOVEMENT_ACTION_JUMP_DOWN,
    MOVEMENT_ACTION_JUMP_DOWN,
    MOVEMENT_ACTION_JUMP_UP,
    MOVEMENT_ACTION_JUMP_LEFT,
    MOVEMENT_ACTION_JUMP_RIGHT,
};
const u8 gJumpSpecialMovementActions[] = {
    MOVEMENT_ACTION_JUMP_SPECIAL_DOWN,
    MOVEMENT_ACTION_JUMP_SPECIAL_DOWN,
    MOVEMENT_ACTION_JUMP_SPECIAL_UP,
    MOVEMENT_ACTION_JUMP_SPECIAL_LEFT,
    MOVEMENT_ACTION_JUMP_SPECIAL_RIGHT,
};
const u8 gWalkInPlaceSlowMovementActions[] = {
    MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_DOWN,
    MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_DOWN,
    MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_UP,
    MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_LEFT,
    MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_RIGHT,
};
const u8 gWalkInPlaceNormalMovementActions[] = {
    MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_DOWN,
    MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_DOWN,
    MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_UP,
    MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_LEFT,
    MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_RIGHT,
};
const u8 gWalkInPlaceFastMovementActions[] = {
    MOVEMENT_ACTION_WALK_IN_PLACE_FAST_DOWN,
    MOVEMENT_ACTION_WALK_IN_PLACE_FAST_DOWN,
    MOVEMENT_ACTION_WALK_IN_PLACE_FAST_UP,
    MOVEMENT_ACTION_WALK_IN_PLACE_FAST_LEFT,
    MOVEMENT_ACTION_WALK_IN_PLACE_FAST_RIGHT,
};
const u8 gWalkInPlaceFastestMovementActions[] = {
    MOVEMENT_ACTION_WALK_IN_PLACE_FASTEST_DOWN,
    MOVEMENT_ACTION_WALK_IN_PLACE_FASTEST_DOWN,
    MOVEMENT_ACTION_WALK_IN_PLACE_FASTEST_UP,
    MOVEMENT_ACTION_WALK_IN_PLACE_FASTEST_LEFT,
    MOVEMENT_ACTION_WALK_IN_PLACE_FASTEST_RIGHT,
};
const u8 gAcroWheelieFaceDirectionMovementActions[] = {
    MOVEMENT_ACTION_ACRO_WHEELIE_FACE_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_FACE_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_FACE_UP,
    MOVEMENT_ACTION_ACRO_WHEELIE_FACE_LEFT,
    MOVEMENT_ACTION_ACRO_WHEELIE_FACE_RIGHT,
};
const u8 gAcroPopWheelieFaceDirectionMovementActions[] = {
    MOVEMENT_ACTION_ACRO_POP_WHEELIE_DOWN,
    MOVEMENT_ACTION_ACRO_POP_WHEELIE_DOWN,
    MOVEMENT_ACTION_ACRO_POP_WHEELIE_UP,
    MOVEMENT_ACTION_ACRO_POP_WHEELIE_LEFT,
    MOVEMENT_ACTION_ACRO_POP_WHEELIE_RIGHT,
};
const u8 gAcroEndWheelieFaceDirectionMovementActions[] = {
    MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_DOWN,
    MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_DOWN,
    MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_UP,
    MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_LEFT,
    MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_RIGHT,
};
const u8 gAcroWheelieHopFaceDirectionMovementActions[] = {
    MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_UP,
    MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_LEFT,
    MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_RIGHT,
};
const u8 gAcroWheelieHopDirectionMovementActions[] = {
    MOVEMENT_ACTION_ACRO_WHEELIE_HOP_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_HOP_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_HOP_UP,
    MOVEMENT_ACTION_ACRO_WHEELIE_HOP_LEFT,
    MOVEMENT_ACTION_ACRO_WHEELIE_HOP_RIGHT,
};
const u8 gAcroWheelieJumpDirectionMovementActions[] = {
    MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_UP,
    MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_LEFT,
    MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_RIGHT,
};
const u8 gAcroWheelieInPlaceDirectionMovementActions[] = {
    MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_UP,
    MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_LEFT,
    MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_RIGHT,
};
const u8 gAcroPopWheelieMoveDirectionMovementActions[] = {
    MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_DOWN,
    MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_DOWN,
    MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_UP,
    MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_LEFT,
    MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_RIGHT,
};
const u8 gAcroWheelieMoveDirectionMovementActions[] = {
    MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_UP,
    MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_LEFT,
    MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_RIGHT,
};
const u8 gAcroEndWheelieMoveDirectionMovementActions[] = {
    MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_DOWN,
    MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_DOWN,
    MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_UP,
    MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_LEFT,
    MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_RIGHT,
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

static void ClearEventObject(struct EventObject *eventObject)
{
    *eventObject = (struct EventObject){};
    eventObject->localId = 0xFF;
    eventObject->mapNum = 0xFF;
    eventObject->mapGroup = 0xFF;
    eventObject->movementActionId = 0xFF;
}

static void ClearAllEventObjects(void)
{
    u8 i;

    for (i = 0; i < EVENT_OBJECTS_COUNT; i++)
        ClearEventObject(&gEventObjects[i]);
}

void ResetEventObjects(void)
{
    ClearLinkPlayerEventObjects();
    ClearAllEventObjects();
    ClearPlayerAvatarInfo();
    CreateReflectionEffectSprites();
}

static void CreateReflectionEffectSprites(void)
{
    u8 spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[21], 0, 0, 31);
    gSprites[spriteId].oam.affineMode = 1;
    InitSpriteAffineAnim(&gSprites[spriteId]);
    StartSpriteAffineAnim(&gSprites[spriteId], 0);
    gSprites[spriteId].invisible = TRUE;

    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[21], 0, 0, 31);
    gSprites[spriteId].oam.affineMode = 1;
    InitSpriteAffineAnim(&gSprites[spriteId]);
    StartSpriteAffineAnim(&gSprites[spriteId], 1);
    gSprites[spriteId].invisible = TRUE;
}

u8 GetFirstInactiveEventObjectId(void)
{
    u8 i;
    for (i = 0; i < EVENT_OBJECTS_COUNT; i++)
    {
        if (!gEventObjects[i].active)
            break;
    }

    return i;
}

u8 GetEventObjectIdByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroupId)
{
    if (localId < EVENT_OBJ_ID_PLAYER)
    {
        return GetEventObjectIdByLocalIdAndMapInternal(localId, mapNum, mapGroupId);
    }
    return GetEventObjectIdByLocalId(localId);
}

bool8 TryGetEventObjectIdByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroupId, u8 *eventObjectId)
{
    *eventObjectId = GetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroupId);
    if (*eventObjectId == EVENT_OBJECTS_COUNT)
        return TRUE;
    else
        return FALSE;
}

u8 GetEventObjectIdByXY(s16 x, s16 y)
{
    u8 i;
    for (i = 0; i < EVENT_OBJECTS_COUNT; i++)
    {
        if (gEventObjects[i].active && gEventObjects[i].currentCoords.x == x && gEventObjects[i].currentCoords.y == y)
            break;
    }

    return i;
}

static u8 GetEventObjectIdByLocalIdAndMapInternal(u8 localId, u8 mapNum, u8 mapGroupId)
{
    u8 i;
    for (i = 0; i < EVENT_OBJECTS_COUNT; i++)
    {
        if (gEventObjects[i].active && gEventObjects[i].localId == localId && gEventObjects[i].mapNum == mapNum && gEventObjects[i].mapGroup == mapGroupId)
            return i;
    }

    return EVENT_OBJECTS_COUNT;
}

static u8 GetEventObjectIdByLocalId(u8 localId)
{
    u8 i;
    for (i = 0; i < EVENT_OBJECTS_COUNT; i++)
    {
        if (gEventObjects[i].active && gEventObjects[i].localId == localId)
            return i;
    }

    return EVENT_OBJECTS_COUNT;
}

// This function has the same nonmatching quirk as in Ruby/Sapphire.
#ifdef NONMATCHING
static u8 InitEventObjectStateFromTemplate(struct EventObjectTemplate *template, u8 mapNum, u8 mapGroup)
{
    struct EventObject *eventObject;
    u8 eventObjectId;
    s16 x;
    s16 y;

    // mapNum and mapGroup are in the wrong registers (r7/r6 instead of r6/r7)
    if (GetAvailableEventObjectId(template->localId, mapNum, mapGroup, &eventObjectId))
    {
        return EVENT_OBJECTS_COUNT;
    }
    eventObject = &gEventObjects[eventObjectId];
    ClearEventObject(eventObject);
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
    SetEventObjectDirection(eventObject, eventObject->previousMovementDirection);
    SetEventObjectDynamicGraphicsId(eventObject);

    if (gRangedMovementTypes[eventObject->movementType])
    {
        if ((eventObject->range.as_nybbles.x) == 0)
        {
            // r9 is invoked here
            eventObject->range.as_nybbles.x++;
        }
        if ((eventObject->range.as_nybbles.y) == 0)
        {
            eventObject->range.as_nybbles.y++;
        }
    }
    return eventObjectId;
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
                "\tbl GetAvailableEventObjectId\n"
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
                "\tbl ClearEventObject\n"
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
                "\tbl SetEventObjectDirection\n"
                "\tadds r0, r4, 0\n"
                "\tbl SetEventObjectDynamicGraphicsId\n"
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

u8 Unref_TryInitLocalEventObject(u8 localId)
{
    u8 i;
    u8 eventObjectCount;
    struct EventObjectTemplate *template;

    if (gMapHeader.events != NULL)
    {
        if (InBattlePyramid())
        {
            eventObjectCount = GetNumBattlePyramidEventObjects();
        }
        else if (InTrainerHill())
        {
            eventObjectCount = 2;
        }
        else
        {
            eventObjectCount = gMapHeader.events->eventObjectCount;
        }
        for (i = 0; i < eventObjectCount; i++)
        {
            template = &gSaveBlock1Ptr->eventObjectTemplates[i];
            if (template->localId == localId && !FlagGet(template->flagId))
            {
                return InitEventObjectStateFromTemplate(template, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
            }
        }
    }
    return EVENT_OBJECTS_COUNT;
}

static bool8 GetAvailableEventObjectId(u16 localId, u8 mapNum, u8 mapGroup, u8 *eventObjectId)
// Looks for an empty slot.
// Returns FALSE and the location of the available slot
// in *eventObjectId.
// If no slots are available, or if the object is already
// loaded, returns TRUE.
{
    u8 i = 0;

    for (i = 0; i < EVENT_OBJECTS_COUNT; i++)
    {
        if (!gEventObjects[i].active)
            break;
        if (gEventObjects[i].localId == localId && gEventObjects[i].mapNum == mapNum && gEventObjects[i].mapGroup == mapGroup)
            return TRUE;
    }
    if (i >= EVENT_OBJECTS_COUNT)
        return TRUE;
    *eventObjectId = i;
    do
    {
        if (gEventObjects[i].active && gEventObjects[i].localId == localId && gEventObjects[i].mapNum == mapNum && gEventObjects[i].mapGroup == mapGroup)
            return TRUE;
        i++;
    } while (i < EVENT_OBJECTS_COUNT);
    return FALSE;
}

static void RemoveEventObject(struct EventObject *eventObject)
{
    eventObject->active = FALSE;
    RemoveEventObjectInternal(eventObject);
}

void RemoveEventObjectByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 eventObjectId;
    if (!TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &eventObjectId))
    {
        FlagSet(GetEventObjectFlagIdByEventObjectId(eventObjectId));
        RemoveEventObject(&gEventObjects[eventObjectId]);
    }
}

static void RemoveEventObjectInternal(struct EventObject *eventObject)
{
    u8 paletteNum;

    struct SpriteFrameImage image;
    image.size = GetEventObjectGraphicsInfo(eventObject->graphicsId)->size;
    gSprites[eventObject->spriteId].images = &image;
    paletteNum = gSprites[eventObject->spriteId].oam.paletteNum;
    DestroySprite(&gSprites[eventObject->spriteId]);
    FieldEffectFreePaletteIfUnused(paletteNum);
}

void RemoveAllEventObjectsExceptPlayer(void)
{
    u8 i;

    for (i = 0; i < EVENT_OBJECTS_COUNT; i++)
    {
        if (i != gPlayerAvatar.eventObjectId)
            RemoveEventObject(&gEventObjects[i]);
    }
}

static u8 TrySetupEventObjectSprite(struct EventObjectTemplate *eventObjectTemplate, struct SpriteTemplate *spriteTemplate, u8 mapNum, u8 mapGroup, s16 cameraX, s16 cameraY)
{
    u8 spriteId;
    u8 paletteSlot;
    u8 eventObjectId;
    struct Sprite *sprite;
    struct EventObject *eventObject;
    const struct EventObjectGraphicsInfo *graphicsInfo;

    eventObjectId = InitEventObjectStateFromTemplate(eventObjectTemplate, mapNum, mapGroup);
    if (eventObjectId == EVENT_OBJECTS_COUNT)
        return EVENT_OBJECTS_COUNT;

    eventObject = &gEventObjects[eventObjectId];
    graphicsInfo = GetEventObjectGraphicsInfo(eventObject->graphicsId);
    if (spriteTemplate->paletteTag != 0xffff)
    {
        LoadEventObjectPalette(spriteTemplate->paletteTag);
        UpdatePaletteGammaType(IndexOfSpritePaletteTag(spriteTemplate->paletteTag), GAMMA_ALT);
    }

    if (eventObject->movementType == MOVEMENT_TYPE_INVISIBLE)
        eventObject->invisible = TRUE;

    spriteId = CreateSprite(spriteTemplate, 0, 0, 0);
    if (spriteId == MAX_SPRITES)
    {
        gEventObjects[eventObjectId].active = FALSE;
        return EVENT_OBJECTS_COUNT;
    }

    sprite = &gSprites[spriteId];
    sub_8092FF0(eventObject->currentCoords.x + cameraX, eventObject->currentCoords.y + cameraY, &sprite->pos1.x, &sprite->pos1.y);
    sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
    sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
    sprite->pos1.x += 8;
    sprite->pos1.y += 16 + sprite->centerToCornerVecY;
    sprite->coordOffsetEnabled = TRUE;
    sprite->data[0] = eventObjectId;
    eventObject->spriteId = spriteId;
    eventObject->inanimate = graphicsInfo->inanimate;
    if (!eventObject->inanimate)
        StartSpriteAnim(sprite, GetFaceDirectionAnimNum(eventObject->facingDirection));

    SetObjectSubpriorityByZCoord(eventObject->previousElevation, sprite, 1);
    UpdateEventObjectVisibility(eventObject, sprite);
    return eventObjectId;
}

static u8 TrySpawnEventObjectTemplate(struct EventObjectTemplate *eventObjectTemplate, u8 mapNum, u8 mapGroup, s16 cameraX, s16 cameraY)
{
    u8 eventObjectId;
    struct SpriteTemplate spriteTemplate;
    struct SpriteFrameImage spriteFrameImage;
    const struct EventObjectGraphicsInfo *graphicsInfo;
    const struct SubspriteTable *subspriteTables = NULL;

    graphicsInfo = GetEventObjectGraphicsInfo(eventObjectTemplate->graphicsId);
    MakeObjectTemplateFromEventObjectTemplate(eventObjectTemplate, &spriteTemplate, &subspriteTables);
    spriteFrameImage.size = graphicsInfo->size;
    spriteTemplate.images = &spriteFrameImage;
    eventObjectId = TrySetupEventObjectSprite(eventObjectTemplate, &spriteTemplate, mapNum, mapGroup, cameraX, cameraY);
    if (eventObjectId == EVENT_OBJECTS_COUNT)
        return EVENT_OBJECTS_COUNT;

    gSprites[gEventObjects[eventObjectId].spriteId].images = graphicsInfo->images;
    if (subspriteTables)
        SetSubspriteTables(&gSprites[gEventObjects[eventObjectId].spriteId], subspriteTables);

    return eventObjectId;
}

u8 SpawnSpecialEventObject(struct EventObjectTemplate *eventObjectTemplate)
{
    s16 cameraX;
    s16 cameraY;

    GetEventObjectMovingCameraOffset(&cameraX, &cameraY);
    return TrySpawnEventObjectTemplate(eventObjectTemplate, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, cameraX, cameraY);
}

u8 SpawnSpecialEventObjectParameterized(u8 graphicsId, u8 movementBehavior, u8 localId, s16 x, s16 y, u8 z)
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

u8 TrySpawnEventObject(u8 localId, u8 mapNum, u8 mapGroup)
{
    struct EventObjectTemplate *eventObjectTemplate;
    s16 cameraX, cameraY;

    eventObjectTemplate = GetEventObjectTemplateByLocalIdAndMap(localId, mapNum, mapGroup);
    if (!eventObjectTemplate)
        return EVENT_OBJECTS_COUNT;

    GetEventObjectMovingCameraOffset(&cameraX, &cameraY);
    return TrySpawnEventObjectTemplate(eventObjectTemplate, mapNum, mapGroup, cameraX, cameraY);
}

static void MakeObjectTemplateFromEventObjectGraphicsInfo(u16 graphicsId, void (*callback)(struct Sprite *), struct SpriteTemplate *spriteTemplate, const struct SubspriteTable **subspriteTables)
{
    const struct EventObjectGraphicsInfo *graphicsInfo = GetEventObjectGraphicsInfo(graphicsId);

    spriteTemplate->tileTag = graphicsInfo->tileTag;
    spriteTemplate->paletteTag = graphicsInfo->paletteTag1;
    spriteTemplate->oam = graphicsInfo->oam;
    spriteTemplate->anims = graphicsInfo->anims;
    spriteTemplate->images = graphicsInfo->images;
    spriteTemplate->affineAnims = graphicsInfo->affineAnims;
    spriteTemplate->callback = callback;
    *subspriteTables = graphicsInfo->subspriteTables;
}

static void MakeObjectTemplateFromEventObjectGraphicsInfoWithCallbackIndex(u16 graphicsId, u16 callbackIndex, struct SpriteTemplate *spriteTemplate, const struct SubspriteTable **subspriteTables)
{
    MakeObjectTemplateFromEventObjectGraphicsInfo(graphicsId, sMovementTypeCallbacks[callbackIndex], spriteTemplate, subspriteTables);
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
    u8 spriteId;

    spriteTemplate = malloc(sizeof(struct SpriteTemplate));
    MakeObjectTemplateFromEventObjectGraphicsInfo(graphicsId, callback, spriteTemplate, &subspriteTables);
    if (spriteTemplate->paletteTag != 0xFFFF)
    {
        LoadEventObjectPalette(spriteTemplate->paletteTag);
    }
    spriteId = CreateSprite(spriteTemplate, x, y, subpriority);
    free(spriteTemplate);

    if (spriteId != MAX_SPRITES && subspriteTables != NULL)
    {
        sprite = &gSprites[spriteId];
        SetSubspriteTables(sprite, subspriteTables);
        sprite->subspriteMode = 2;
    }
    return spriteId;
}

u8 sprite_new(u8 graphicsId, u8 a1, s16 x, s16 y, u8 z, u8 direction)
{
    u8 spriteId;
    struct Sprite *sprite;
    struct SpriteTemplate spriteTemplate;
    const struct SubspriteTable *subspriteTables;
    const struct EventObjectGraphicsInfo *graphicsInfo;

    graphicsInfo = GetEventObjectGraphicsInfo(graphicsId);
    MakeObjectTemplateFromEventObjectGraphicsInfo(graphicsId, UpdateEventObjectSpriteSubpriorityAndVisibility, &spriteTemplate, &subspriteTables);
    *(u16 *)&spriteTemplate.paletteTag = 0xFFFF;
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
        if (graphicsInfo->paletteSlot >= 16)
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
        StartSpriteAnim(sprite, GetFaceDirectionAnimNum(direction));
    }
    return spriteId;
}

void TrySpawnEventObjects(s16 cameraX, s16 cameraY)
{
    u8 i;
    u8 objectCount;

    if (gMapHeader.events != NULL)
    {
        s16 left = gSaveBlock1Ptr->pos.x - 2;
        s16 right = gSaveBlock1Ptr->pos.x + 17;
        s16 top = gSaveBlock1Ptr->pos.y;
        s16 bottom = gSaveBlock1Ptr->pos.y + 16;

        if (InBattlePyramid())
        {
            objectCount = GetNumBattlePyramidEventObjects();
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
            s16 npcX = template->x + 7;
            s16 npcY = template->y + 7;

            if (top <= npcY && bottom >= npcY && left <= npcX && right >= npcX
                && !FlagGet(template->flagId))
                TrySpawnEventObjectTemplate(template, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, cameraX, cameraY);
        }
    }
}

void RemoveEventObjectsOutsideView(void)
{
    u8 i, j;
    bool8 isActiveLinkPlayer;

    for (i = 0; i < EVENT_OBJECTS_COUNT; i++)
    {
        for (j = 0, isActiveLinkPlayer = FALSE; j < ARRAY_COUNT(gLinkPlayerEventObjects); j++)
        {
            if (gLinkPlayerEventObjects[j].active && i == gLinkPlayerEventObjects[j].eventObjId)
                isActiveLinkPlayer = TRUE;
        }
        if (!isActiveLinkPlayer)
        {
            struct EventObject *eventObject = &gEventObjects[i];

            if (eventObject->active && !eventObject->isPlayer)
                RemoveEventObjectIfOutsideView(eventObject);
        }
    }
}

static void RemoveEventObjectIfOutsideView(struct EventObject *eventObject)
{
    s16 left =   gSaveBlock1Ptr->pos.x - 2;
    s16 right =  gSaveBlock1Ptr->pos.x + 17;
    s16 top =    gSaveBlock1Ptr->pos.y;
    s16 bottom = gSaveBlock1Ptr->pos.y + 16;

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
    for (i = 0; i < EVENT_OBJECTS_COUNT; i++)
    {
        if (gEventObjects[i].active)
        {
            sub_808E1B8(i, x, y);
        }
    }
    CreateReflectionEffectSprites();
}

static void sub_808E1B8(u8 eventObjectId, s16 x, s16 y)
{
    u8 spriteId;
    struct Sprite *sprite;
    struct EventObject *eventObject;
    struct SpriteTemplate spriteTemplate;
    struct SpriteFrameImage spriteFrameImage;
    const struct SubspriteTable *subspriteTables;
    const struct EventObjectGraphicsInfo *graphicsInfo;

#define i spriteId
    for (i = 0; i < ARRAY_COUNT(gLinkPlayerEventObjects); i++)
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
    if (spriteTemplate.paletteTag != 0xffff)
    {
        LoadEventObjectPalette(spriteTemplate.paletteTag);
        UpdatePaletteGammaType(IndexOfSpritePaletteTag(spriteTemplate.paletteTag), GAMMA_ALT);
    }
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
        if (eventObject->movementType == MOVEMENT_TYPE_PLAYER)
        {
            SetPlayerAvatarEventObjectIdAndObjectId(eventObjectId, spriteId);
            eventObject->warpArrowSpriteId = CreateWarpArrowSprite();
        }
        if (subspriteTables != NULL)
        {
            SetSubspriteTables(sprite, subspriteTables);
        }
        sprite->coordOffsetEnabled = TRUE;
        sprite->data[0] = eventObjectId;
        eventObject->spriteId = spriteId;
        if (!eventObject->inanimate && eventObject->movementType != MOVEMENT_TYPE_PLAYER)
        {
            StartSpriteAnim(sprite, GetFaceDirectionAnimNum(eventObject->facingDirection));
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
    EventObjectClearHeldMovement(eventObject);
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
        PatchObjectPalette(graphicsInfo->paletteTag1, graphicsInfo->paletteSlot);
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
    SetSpritePosToMapCoords(eventObject->currentCoords.x, eventObject->currentCoords.y, &sprite->pos1.x, &sprite->pos1.y);
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
    SetEventObjectDirection(eventObject, direction);
    if (!eventObject->inanimate)
    {
        StartSpriteAnim(&gSprites[eventObject->spriteId], GetFaceDirectionAnimNum(eventObject->facingDirection));
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

static void get_berry_tree_graphics(struct EventObject *eventObject, struct Sprite *sprite)
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
        berryStage--;
        if (berryId > ITEM_TO_BERRY(LAST_BERRY_INDEX))
            berryId = 0;

        LoadEventObjectPalette(gBerryTreePaletteTagTablePointers[berryId][berryStage]);
        EventObjectSetGraphicsId(eventObject, gBerryTreeEventObjectGraphicsIdTablePointers[berryId][berryStage]);
        sprite->images = gBerryTreePicTablePointers[berryId];
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(gBerryTreePaletteTagTablePointers[berryId][berryStage]);
        UpdatePaletteGammaType(sprite->oam.paletteNum, GAMMA_ALT);
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
    if (graphicsId == EVENT_OBJ_GFX_BARD)
    {
        bard = GetCurrentMauvilleOldMan();
        return gMauvilleOldManGraphicsInfoPointers[bard];
    }
    if (graphicsId >= NUM_OBJECT_GRAPHICS_INFO)
    {
        graphicsId = EVENT_OBJ_GFX_NINJA_BOY;
    }
    return gEventObjectGraphicsInfoPointers[graphicsId];
}

static void SetEventObjectDynamicGraphicsId(struct EventObject *eventObject)
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
    if (eventObjectId != EVENT_OBJECTS_COUNT)
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

void FreeAndReserveObjectSpritePalettes(void)
{
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = 12;
}

void LoadEventObjectPalette(u16 paletteTag)
{
    u16 i = FindEventObjectPaletteIndexByTag(paletteTag);

    if (i != EVENT_OBJ_PAL_TAG_NONE) // always true
    {
        sub_808E8F4(&sEventObjectSpritePalettes[i]);
    }
}

void Unused_LoadEventObjectPaletteSet(u16 *paletteTags)
{
    u8 i;

    for (i = 0; paletteTags[i] != EVENT_OBJ_PAL_TAG_NONE; i++)
    {
        LoadEventObjectPalette(paletteTags[i]);
    }
}

static u8 sub_808E8F4(const struct SpritePalette *spritePalette)
{
    if (IndexOfSpritePaletteTag(spritePalette->tag) != 0xFF)
    {
        return 0xFF;
    }
    return LoadSpritePalette(spritePalette);
}

void PatchObjectPalette(u16 paletteTag, u8 paletteSlot)
{
    u8 paletteIndex = FindEventObjectPaletteIndexByTag(paletteTag);

    LoadPalette(sEventObjectSpritePalettes[paletteIndex].data, 16 * paletteSlot + 0x100, 0x20);
}

void PatchObjectPaletteRange(const u16 *paletteTags, u8 minSlot, u8 maxSlot)
{
    while (minSlot < maxSlot)
    {
        PatchObjectPalette(*paletteTags, minSlot);
        paletteTags++;
        minSlot++;
    }
}

static u8 FindEventObjectPaletteIndexByTag(u16 tag)
{
    u8 i;

    for (i = 0; sEventObjectSpritePalettes[i].tag != EVENT_OBJ_PAL_TAG_NONE; i++)
    {
        if (sEventObjectSpritePalettes[i].tag == tag)
        {
            return i;
        }
    }
    return 0xFF;
}

static void sub_808EAB0(u16 tag, u8 slot)
{
    PatchObjectPalette(tag, slot);
}

void unref_sub_808EAC4(struct EventObject *eventObject, s16 x, s16 y)
{
    eventObject->previousCoords.x = eventObject->currentCoords.x;
    eventObject->previousCoords.y = eventObject->currentCoords.y;
    eventObject->currentCoords.x += x;
    eventObject->currentCoords.y += y;
}

void ShiftEventObjectCoords(struct EventObject *eventObject, s16 x, s16 y)
{
    eventObject->previousCoords.x = eventObject->currentCoords.x;
    eventObject->previousCoords.y = eventObject->currentCoords.y;
    eventObject->currentCoords.x = x;
    eventObject->currentCoords.y = y;
}

static void SetEventObjectCoords(struct EventObject *eventObject, s16 x, s16 y)
{
    eventObject->previousCoords.x = x;
    eventObject->previousCoords.y = y;
    eventObject->currentCoords.x = x;
    eventObject->currentCoords.y = y;
}

void MoveEventObjectToMapCoords(struct EventObject *eventObject, s16 x, s16 y)
{
    struct Sprite *sprite;
    const struct EventObjectGraphicsInfo *graphicsInfo;

    sprite = &gSprites[eventObject->spriteId];
    graphicsInfo = GetEventObjectGraphicsInfo(eventObject->graphicsId);
    SetEventObjectCoords(eventObject, x, y);
    SetSpritePosToMapCoords(eventObject->currentCoords.x, eventObject->currentCoords.y, &sprite->pos1.x, &sprite->pos1.y);
    sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
    sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
    sprite->pos1.x += 8;
    sprite->pos1.y += 16 + sprite->centerToCornerVecY;
    sub_808E38C(eventObject);
    if (eventObject->trackedByCamera)
        CameraObjectReset1();
}

void TryMoveEventObjectToMapCoords(u8 localId, u8 mapNum, u8 mapGroup, s16 x, s16 y)
{
    u8 eventObjectId;
    if (!TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &eventObjectId))
    {
        x += 7;
        y += 7;
        MoveEventObjectToMapCoords(&gEventObjects[eventObjectId], x, y);
    }
}

void ShiftStillEventObjectCoords(struct EventObject *eventObject)
{
    ShiftEventObjectCoords(eventObject, eventObject->currentCoords.x, eventObject->currentCoords.y);
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
        for (i = 0; i < EVENT_OBJECTS_COUNT; i++)
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

    for (i = 0; i < EVENT_OBJECTS_COUNT; i++)
    {
        if (gEventObjects[i].active)
        {
            if (gEventObjects[i].currentCoords.x == x && gEventObjects[i].currentCoords.y == y && EventObjectDoesZCoordMatch(&gEventObjects[i], z))
            {
                return i;
            }
        }
    }
    return EVENT_OBJECTS_COUNT;
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
    TrySpawnEventObjects(x, y);
    RemoveEventObjectsOutsideView();
}

u8 AddCameraObject(u8 linkedSpriteId)
{
    u8 spriteId = CreateSprite(&gCameraSpriteTemplate, 0, 0, 4);

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
    s16 x = gSprites[sprite->data[0]].pos1.x;
    s16 y = gSprites[sprite->data[0]].pos1.y;

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
    u8 i;

    for (i = 0; i < MAX_SPRITES; i++)
    {
        if (gSprites[i].inUse && gSprites[i].callback == ObjectCB_CameraObject)
        {
            return &gSprites[i];
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

    for (i = 0; i < MAX_SPRITES; i++)
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

u8 CreateCopySpriteAt(struct Sprite *sprite, s16 x, s16 y, u8 subpriority)
{
    s16 i;

    for (i = MAX_SPRITES - 1; i > -1; i--)
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

void SetEventObjectDirection(struct EventObject *eventObject, u8 direction)
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
    return FindEventObjectTemplateByLocalId(localId, templates, count);
}

static struct EventObjectTemplate *FindEventObjectTemplateByLocalId(u8 localId, struct EventObjectTemplate *templates, u8 count)
{
    u8 i;

    for (i = 0; i < count; i++)
    {
        if (templates[i].localId == localId)
        {
            return &templates[i];
        }
    }
    return NULL;
}

struct EventObjectTemplate *GetBaseTemplateForEventObject(const struct EventObject *eventObject)
{
    int i;

    if (eventObject->mapNum != gSaveBlock1Ptr->location.mapNum || eventObject->mapGroup != gSaveBlock1Ptr->location.mapGroup)
    {
        return NULL;
    }
    for (i = 0; i < EVENT_OBJECT_TEMPLATES_COUNT; i++)
    {
        if (eventObject->localId == gSaveBlock1Ptr->eventObjectTemplates[i].localId)
        {
            return &gSaveBlock1Ptr->eventObjectTemplates[i];
        }
    }
    return NULL;
}

void OverrideTemplateCoordsForEventObject(const struct EventObject *eventObject)
{
    struct EventObjectTemplate *eventObjectTemplate;

    eventObjectTemplate = GetBaseTemplateForEventObject(eventObject);
    if (eventObjectTemplate != NULL)
    {
        eventObjectTemplate->x = eventObject->currentCoords.x - 7;
        eventObjectTemplate->y = eventObject->currentCoords.y - 7;
    }
}

static void OverrideEventObjectTemplateScript(const struct EventObject *eventObject, const u8 *script)
{
    struct EventObjectTemplate *eventObjectTemplate;

    eventObjectTemplate = GetBaseTemplateForEventObject(eventObject);
    if (eventObjectTemplate)
        eventObjectTemplate->script = script;
}

void TryOverrideTemplateCoordsForEventObject(const struct EventObject *eventObject, u8 movementType)
{
    struct EventObjectTemplate *eventObjectTemplate;

    eventObjectTemplate = GetBaseTemplateForEventObject(eventObject);
    if (eventObjectTemplate != NULL)
    {
        eventObjectTemplate->movementType = movementType;
    }
}

void TryOverrideEventObjectTemplateCoords(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 eventObjectId;
    if (!TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &eventObjectId))
        OverrideTemplateCoordsForEventObject(&gEventObjects[eventObjectId]);
}

void OverrideSecretBaseDecorationSpriteScript(u8 localId, u8 mapNum, u8 mapGroup, u8 decorationCategory)
{
    u8 eventObjectId;
    if (!TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &eventObjectId))
    {
        switch (decorationCategory)
        {
        case DECORCAT_DOLL:
            OverrideEventObjectTemplateScript(&gEventObjects[eventObjectId], SecretBase_EventScript_DollInteract);
            break;
        case DECORCAT_CUSHION:
            OverrideEventObjectTemplateScript(&gEventObjects[eventObjectId], SecretBase_EventScript_CushionInteract);
            break;
        }
    }
}

movement_type_empty_callback(MovementType_None)
movement_type_def(MovementType_WanderAround, gMovementTypeFuncs_WanderAround)

bool8 MovementType_WanderAround_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_WanderAround_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_WanderAround_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (!EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        return FALSE;
    }
    SetMovementDelay(sprite, gMovementDelaysMedium[Random() & 3]);
    sprite->data[1] = 3;
    return TRUE;
}

bool8 MovementType_WanderAround_Step3(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_WanderAround_Step4(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[4];
    u8 chosenDirection;

    memcpy(directions, gStandardDirections, sizeof directions);
    chosenDirection = directions[Random() & 3];
    SetEventObjectDirection(eventObject, chosenDirection);
    sprite->data[1] = 5;
    if (GetCollisionInDirection(eventObject, chosenDirection))
    {
        sprite->data[1] = 1;
    }
    return TRUE;
}

bool8 MovementType_WanderAround_Step5(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetSingleMovement(eventObject, sprite, GetWalkNormalMovementAction(eventObject->movementDirection));
    eventObject->singleMovementActive = 1;
    sprite->data[1] = 6;
    return TRUE;
}

bool8 MovementType_WanderAround_Step6(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        eventObject->singleMovementActive = 0;
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

    if (!TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_DASH))
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

u8 GetVectorDirection(s16 dx, s16 dy, s16 absdx, s16 absdy)
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

u8 GetLimitedVectorDirection_SouthNorth(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = DIR_SOUTH;
    if (dy < 0)
    {
        direction = DIR_NORTH;
    }
    return direction;
}

u8 GetLimitedVectorDirection_WestEast(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = DIR_EAST;
    if (dx < 0)
    {
        direction = DIR_WEST;
    }
    return direction;
}

u8 GetLimitedVectorDirection_WestNorth(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_SOUTH)
    {
        direction = GetLimitedVectorDirection_WestEast(dx, dy, absdx, absdy);
        if (direction == DIR_EAST)
        {
            direction = DIR_NORTH;
        }
    }
    else if (direction == DIR_EAST)
    {
        direction = GetLimitedVectorDirection_SouthNorth(dx, dy, absdx, absdy);
        if (direction == DIR_SOUTH)
        {
            direction = DIR_NORTH;
        }
    }
    return direction;
}

u8 GetLimitedVectorDirection_EastNorth(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_SOUTH)
    {
        direction = GetLimitedVectorDirection_WestEast(dx, dy, absdx, absdy);
        if (direction == DIR_WEST)
        {
            direction = DIR_NORTH;
        }
    }
    else if (direction == DIR_WEST)
    {
        direction = GetLimitedVectorDirection_SouthNorth(dx, dy, absdx, absdy);
        if (direction == DIR_SOUTH)
        {
            direction = DIR_NORTH;
        }
    }
    return direction;
}

u8 GetLimitedVectorDirection_WestSouth(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_NORTH)
    {
        direction = GetLimitedVectorDirection_WestEast(dx, dy, absdx, absdy);
        if (direction == DIR_EAST)
        {
            direction = DIR_SOUTH;
        }
    }
    else if (direction == DIR_EAST)
    {
        direction = GetLimitedVectorDirection_SouthNorth(dx, dy, absdx, absdy);
        if (direction == DIR_NORTH)
        {
            direction = DIR_SOUTH;
        }
    }
    return direction;
}

u8 GetLimitedVectorDirection_EastSouth(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_NORTH)
    {
        direction = GetLimitedVectorDirection_WestEast(dx, dy, absdx, absdy);
        if (direction == DIR_WEST)
        {
            direction = DIR_SOUTH;
        }
    }
    else if (direction == DIR_WEST)
    {
        direction = GetLimitedVectorDirection_SouthNorth(dx, dy, absdx, absdy);
        if (direction == DIR_NORTH)
        {
            direction = DIR_SOUTH;
        }
    }
    return direction;
}

u8 GetLimitedVectorDirection_SouthNorthWest(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_EAST)
    {
        direction = GetLimitedVectorDirection_SouthNorth(dx, dy, absdx, absdy);
    }
    return direction;
}

u8 GetLimitedVectorDirection_SouthNorthEast(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_WEST)
    {
        direction = GetLimitedVectorDirection_SouthNorth(dx, dy, absdx, absdy);
    }
    return direction;
}

u8 GetLimitedVectorDirection_NorthWestEast(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_SOUTH)
    {
        direction = GetLimitedVectorDirection_WestEast(dx, dy, absdx, absdy);
    }
    return direction;
}

u8 GetLimitedVectorDirection_SouthWestEast(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_NORTH)
    {
        direction = GetLimitedVectorDirection_WestEast(dx, dy, absdx, absdy);
    }
    return direction;
}

u8 TryGetTrainerEncounterDirection(struct EventObject *eventObject, u8 movementType)
{
    s16 dx, dy;
    s16 absdx, absdy;

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
    return gGetVectorDirectionFuncs[movementType](dx, dy, absdx, absdy);
}

movement_type_def(MovementType_LookAround, gMovementTypeFuncs_LookAround)

bool8 MovementType_LookAround_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_LookAround_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_LookAround_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        SetMovementDelay(sprite, gMovementDelaysMedium[Random() & 3]);
        eventObject->singleMovementActive = 0;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_LookAround_Step3(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_LookAround_Step4(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[4];
    memcpy(directions, gStandardDirections, sizeof directions);
    direction = TryGetTrainerEncounterDirection(eventObject, RUNFOLLOW_ANY);
    if (direction == DIR_NONE)
        direction = directions[Random() & 3];

    SetEventObjectDirection(eventObject, direction);
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_WanderUpAndDown, gMovementTypeFuncs_WanderUpAndDown)

bool8 MovementType_WanderUpAndDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_WanderUpAndDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_WanderUpAndDown_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (!EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        return FALSE;
    }
    SetMovementDelay(sprite, gMovementDelaysMedium[Random() & 3]);
    sprite->data[1] = 3;
    return TRUE;
}

bool8 MovementType_WanderUpAndDown_Step3(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_WanderUpAndDown_Step4(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gUpAndDownDirections, sizeof directions);
    direction = directions[Random() & 1];
    SetEventObjectDirection(eventObject, direction);
    sprite->data[1] = 5;
    if (GetCollisionInDirection(eventObject, direction))
    {
        sprite->data[1] = 1;
    }
    return TRUE;
}

bool8 MovementType_WanderUpAndDown_Step5(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetSingleMovement(eventObject, sprite, GetWalkNormalMovementAction(eventObject->movementDirection));
    eventObject->singleMovementActive = 1;
    sprite->data[1] = 6;
    return TRUE;
}

bool8 MovementType_WanderUpAndDown_Step6(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        eventObject->singleMovementActive = 0;
        sprite->data[1] = 1;
    }
    return FALSE;
}

movement_type_def(MovementType_WanderLeftAndRight, gMovementTypeFuncs_WanderLeftAndRight)

bool8 MovementType_WanderLeftAndRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_WanderLeftAndRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_WanderLeftAndRight_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (!EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        return FALSE;
    }
    SetMovementDelay(sprite, gMovementDelaysMedium[Random() & 3]);
    sprite->data[1] = 3;
    return TRUE;
}

bool8 MovementType_WanderLeftAndRight_Step3(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_WanderLeftAndRight_Step4(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gLeftAndRightDirections, sizeof directions);
    direction = directions[Random() & 1];
    SetEventObjectDirection(eventObject, direction);
    sprite->data[1] = 5;
    if (GetCollisionInDirection(eventObject, direction))
    {
        sprite->data[1] = 1;
    }
    return TRUE;
}

bool8 MovementType_WanderLeftAndRight_Step5(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetSingleMovement(eventObject, sprite, GetWalkNormalMovementAction(eventObject->movementDirection));
    eventObject->singleMovementActive = 1;
    sprite->data[1] = 6;
    return TRUE;
}

bool8 MovementType_WanderLeftAndRight_Step6(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        eventObject->singleMovementActive = 0;
        sprite->data[1] = 1;
    }
    return FALSE;
}

movement_type_def(MovementType_FaceDirection, gMovementTypeFuncs_FaceDirection)

bool8 MovementType_FaceDirection_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(eventObject->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_FaceDirection_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        sprite->data[1] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceDirection_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->singleMovementActive = 0;
    return FALSE;
}

static bool8 EventObjectCB2_BerryTree(struct EventObject *eventObject, struct Sprite *sprite);
extern bool8 (*const gMovementTypeFuncs_BerryTreeGrowth[])(struct EventObject *eventObject, struct Sprite *sprite);
void MovementType_BerryTreeGrowth(struct Sprite *sprite)
{
    struct EventObject *eventObject;

    eventObject = &gEventObjects[sprite->data[0]];
    if (!(sprite->data[7] & 1))
    {
        get_berry_tree_graphics(eventObject, sprite);
        sprite->data[7] |= 1;
    }
    UpdateEventObjectCurrentMovement(eventObject, sprite, EventObjectCB2_BerryTree);
}
static bool8 EventObjectCB2_BerryTree(struct EventObject *eventObject, struct Sprite *sprite)
{
    return gMovementTypeFuncs_BerryTreeGrowth[sprite->data[1]](eventObject, sprite);
}

bool8 MovementType_BerryTreeGrowth_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 berryStage;
    ClearEventObjectMovement(eventObject, sprite);
    eventObject->invisible = TRUE;
    sprite->invisible = TRUE;
    berryStage = GetStageByBerryTreeId(eventObject->trainerRange_berryTreeId);
    if (berryStage == 0)
    {
        if (!(sprite->data[7] & 4) && sprite->animNum == 4)
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
    EventObjectSetSingleMovement(eventObject, sprite, MOVEMENT_ACTION_START_ANIM_IN_DIRECTION);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_BerryTreeGrowth_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        sprite->data[1] = 0;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_BerryTreeGrowth_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->singleMovementActive = 1;
    sprite->data[1] = 3;
    sprite->data[2] = 0;
    sprite->data[7] |= 2;
    gFieldEffectArguments[0] = eventObject->currentCoords.x;
    gFieldEffectArguments[1] = eventObject->currentCoords.y;
    gFieldEffectArguments[2] = sprite->subpriority - 1;
    gFieldEffectArguments[3] = sprite->oam.priority;
    FieldEffectStart(FLDEFF_BERRY_TREE_GROWTH_SPARKLE);
    return TRUE;
}

bool8 MovementType_BerryTreeGrowth_Step3(struct EventObject *eventObject, struct Sprite *sprite)
{
    sprite->data[2]++;
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

bool8 MovementType_BerryTreeGrowth_Step4(struct EventObject *eventObject, struct Sprite *sprite)
{
    sprite->data[2]++;
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

movement_type_def(MovementType_FaceDownAndUp, gMovementTypeFuncs_FaceDownAndUp)

bool8 MovementType_FaceDownAndUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_FaceDownAndUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_FaceDownAndUp_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        SetMovementDelay(sprite, gMovementDelaysMedium[Random() & 3]);
        eventObject->singleMovementActive = 0;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_FaceDownAndUp_Step3(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceDownAndUp_Step4(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gUpAndDownDirections, sizeof gUpAndDownDirections);
    direction = TryGetTrainerEncounterDirection(eventObject, RUNFOLLOW_NORTH_SOUTH);
    if (direction == 0)
    {
        direction = directions[Random() & 1];
    }
    SetEventObjectDirection(eventObject, direction);
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_FaceLeftAndRight, gMovementTypeFuncs_FaceLeftAndRight)

bool8 MovementType_FaceLeftAndRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_FaceLeftAndRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_FaceLeftAndRight_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        SetMovementDelay(sprite, gMovementDelaysMedium[Random() & 3]);
        eventObject->singleMovementActive = 0;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_FaceLeftAndRight_Step3(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceLeftAndRight_Step4(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gLeftAndRightDirections, sizeof gLeftAndRightDirections);
    direction = TryGetTrainerEncounterDirection(eventObject, RUNFOLLOW_EAST_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 1];
    }
    SetEventObjectDirection(eventObject, direction);
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_FaceUpAndLeft, gMovementTypeFuncs_FaceUpAndLeft)

bool8 MovementType_FaceUpAndLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_FaceUpAndLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_FaceUpAndLeft_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        SetMovementDelay(sprite, gMovementDelaysShort[Random() & 3]);
        eventObject->singleMovementActive = 0;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_FaceUpAndLeft_Step3(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceUpAndLeft_Step4(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gUpAndLeftDirections, sizeof gUpAndLeftDirections);
    direction = TryGetTrainerEncounterDirection(eventObject, RUNFOLLOW_NORTH_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 1];
    }
    SetEventObjectDirection(eventObject, direction);
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_FaceUpAndRight, gMovementTypeFuncs_FaceUpAndRight)

bool8 MovementType_FaceUpAndRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_FaceUpAndRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_FaceUpAndRight_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        SetMovementDelay(sprite, gMovementDelaysShort[Random() & 3]);
        eventObject->singleMovementActive = 0;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_FaceUpAndRight_Step3(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceUpAndRight_Step4(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gUpAndRightDirections, sizeof gUpAndRightDirections);
    direction = TryGetTrainerEncounterDirection(eventObject, RUNFOLLOW_NORTH_EAST);
    if (direction == 0)
    {
        direction = directions[Random() & 1];
    }
    SetEventObjectDirection(eventObject, direction);
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_FaceDownAndLeft, gMovementTypeFuncs_FaceDownAndLeft)

bool8 MovementType_FaceDownAndLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_FaceDownAndLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_FaceDownAndLeft_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        SetMovementDelay(sprite, gMovementDelaysShort[Random() & 3]);
        eventObject->singleMovementActive = 0;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_FaceDownAndLeft_Step3(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceDownAndLeft_Step4(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gDownAndLeftDirections, sizeof gDownAndLeftDirections);
    direction = TryGetTrainerEncounterDirection(eventObject, RUNFOLLOW_SOUTH_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 1];
    }
    SetEventObjectDirection(eventObject, direction);
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_FaceDownAndRight, gMovementTypeFuncs_FaceDownAndRight)

bool8 MovementType_FaceDownAndRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_FaceDownAndRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_FaceDownAndRight_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        SetMovementDelay(sprite, gMovementDelaysShort[Random() & 3]);
        eventObject->singleMovementActive = 0;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_FaceDownAndRight_Step3(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceDownAndRight_Step4(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gDownAndRightDirections, sizeof gDownAndRightDirections);
    direction = TryGetTrainerEncounterDirection(eventObject, RUNFOLLOW_SOUTH_EAST);
    if (direction == 0)
    {
        direction = directions[Random() & 1];
    }
    SetEventObjectDirection(eventObject, direction);
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_FaceDownUpAndLeft, gMovementTypeFuncs_FaceDownUpAndLeft)

bool8 MovementType_FaceDownUpAndLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_FaceDownUpAndLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_FaceDownUpAndLeft_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        SetMovementDelay(sprite, gMovementDelaysShort[Random() & 3]);
        eventObject->singleMovementActive = 0;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_FaceDownUpAndLeft_Step3(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceDownUpAndLeft_Step4(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[4];
    memcpy(directions, gDownUpAndLeftDirections, sizeof gDownUpAndLeftDirections);
    direction = TryGetTrainerEncounterDirection(eventObject, RUNFOLLOW_NORTH_SOUTH_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 3];
    }
    SetEventObjectDirection(eventObject, direction);
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_FaceDownUpAndRight, gMovementTypeFuncs_FaceDownUpAndRight)

bool8 MovementType_FaceDownUpAndRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_FaceDownUpAndRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_FaceDownUpAndRight_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        SetMovementDelay(sprite, gMovementDelaysShort[Random() & 3]);
        eventObject->singleMovementActive = 0;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_FaceDownUpAndRight_Step3(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceDownUpAndRight_Step4(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[4];
    memcpy(directions, gDownUpAndRightDirections, sizeof gDownUpAndRightDirections);
    direction = TryGetTrainerEncounterDirection(eventObject, RUNFOLLOW_NORTH_SOUTH_EAST);
    if (direction == 0)
    {
        direction = directions[Random() & 3];
    }
    SetEventObjectDirection(eventObject, direction);
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_FaceUpRightAndLeft, gMovementTypeFuncs_FaceUpLeftAndRight)

bool8 MovementType_FaceUpLeftAndRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_FaceUpLeftAndRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_FaceUpLeftAndRight_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        SetMovementDelay(sprite, gMovementDelaysShort[Random() & 3]);
        eventObject->singleMovementActive = 0;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_FaceUpLeftAndRight_Step3(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceUpLeftAndRight_Step4(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[4];
    memcpy(directions, gUpLeftAndRightDirections, sizeof gUpLeftAndRightDirections);
    direction = TryGetTrainerEncounterDirection(eventObject, RUNFOLLOW_NORTH_EAST_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 3];
    }
    SetEventObjectDirection(eventObject, direction);
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_FaceDownRightAndLeft, gMovementTypeFuncs_FaceDownLeftAndRight)

bool8 MovementType_FaceDownLeftAndRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_FaceDownLeftAndRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(eventObject->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_FaceDownLeftAndRight_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        SetMovementDelay(sprite, gMovementDelaysShort[Random() & 3]);
        eventObject->singleMovementActive = 0;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_FaceDownLeftAndRight_Step3(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceDownLeftAndRight_Step4(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[4];
    memcpy(directions, gDownLeftAndRightDirections, sizeof gDownLeftAndRightDirections);
    direction = TryGetTrainerEncounterDirection(eventObject, RUNFOLLOW_SOUTH_EAST_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 3];
    }
    SetEventObjectDirection(eventObject, direction);
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_RotateCounterclockwise, gMovementTypeFuncs_RotateCounterclockwise)

bool8 MovementType_RotateCounterclockwise_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(eventObject->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_RotateCounterclockwise_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        SetMovementDelay(sprite, 48);
        sprite->data[1] = 2;
    }
    return FALSE;
}

bool8 MovementType_RotateCounterclockwise_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_RotateCounterclockwise_Step3(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[5];
    memcpy(directions, gCounterclockwiseDirections, sizeof gCounterclockwiseDirections);
    direction = TryGetTrainerEncounterDirection(eventObject, RUNFOLLOW_ANY);
    if (direction == 0)
    {
        direction = directions[eventObject->facingDirection];
    }
    SetEventObjectDirection(eventObject, direction);
    sprite->data[1] = 0;
    return TRUE;
}

movement_type_def(MovementType_RotateClockwise, gMovementTypeFuncs_RotateClockwise)

bool8 MovementType_RotateClockwise_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(eventObject->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_RotateClockwise_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        SetMovementDelay(sprite, 48);
        sprite->data[1] = 2;
    }
    return FALSE;
}

bool8 MovementType_RotateClockwise_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(eventObject))
    {
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_RotateClockwise_Step3(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[5];
    memcpy(directions, gClockwiseDirections, sizeof gClockwiseDirections);
    direction = TryGetTrainerEncounterDirection(eventObject, RUNFOLLOW_ANY);
    if (direction == 0)
    {
        direction = directions[eventObject->facingDirection];
    }
    SetEventObjectDirection(eventObject, direction);
    sprite->data[1] = 0;
    return TRUE;
}

movement_type_def(MovementType_WalkBackAndForth, gMovementTypeFuncs_WalkBackAndForth)

bool8 MovementType_WalkBackAndForth_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_WalkBackAndForth_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 direction;

    direction = gInitialMovementTypeFacingDirections[eventObject->movementType];
    if (eventObject->directionSequenceIndex)
    {
        direction = GetOppositeDirection(direction);
    }
    SetEventObjectDirection(eventObject, direction);
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_WalkBackAndForth_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    bool8 collisionState;
    u8 movementActionId;

    if (eventObject->directionSequenceIndex && eventObject->initialCoords.x == eventObject->currentCoords.x && eventObject->initialCoords.y == eventObject->currentCoords.y)
    {
        eventObject->directionSequenceIndex = 0;
        SetEventObjectDirection(eventObject, GetOppositeDirection(eventObject->movementDirection));
    }
    collisionState = GetCollisionInDirection(eventObject, eventObject->movementDirection);
    movementActionId = GetWalkNormalMovementAction(eventObject->movementDirection);
    if (collisionState == TRUE)
    {
        eventObject->directionSequenceIndex++;
        SetEventObjectDirection(eventObject, GetOppositeDirection(eventObject->movementDirection));
        movementActionId = GetWalkNormalMovementAction(eventObject->movementDirection);
        collisionState = GetCollisionInDirection(eventObject, eventObject->movementDirection);
    }
    if (collisionState)
    {
        movementActionId = GetWalkInPlaceNormalMovementAction(eventObject->facingDirection);
    }
    EventObjectSetSingleMovement(eventObject, sprite, movementActionId);
    eventObject->singleMovementActive = 1;
    sprite->data[1] = 3;
    return TRUE;
}

bool8 MovementType_WalkBackAndForth_Step3(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        eventObject->singleMovementActive = 0;
        sprite->data[1] = 1;
    }
    return FALSE;
}

bool8 MovementType_WalkSequence_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MoveNextDirectionInSequence(struct EventObject *eventObject, struct Sprite *sprite, u8 *route)
{
    u8 collisionState;
    u8 movementActionId;

    if (eventObject->directionSequenceIndex == 3 && eventObject->initialCoords.x == eventObject->currentCoords.x && eventObject->initialCoords.y == eventObject->currentCoords.y)
    {
        eventObject->directionSequenceIndex = 0;
    }
    SetEventObjectDirection(eventObject, route[eventObject->directionSequenceIndex]);
    movementActionId = GetWalkNormalMovementAction(eventObject->movementDirection);
    collisionState = GetCollisionInDirection(eventObject, eventObject->movementDirection);
    if (collisionState == TRUE)
    {
        eventObject->directionSequenceIndex++;
        SetEventObjectDirection(eventObject, route[eventObject->directionSequenceIndex]);
        movementActionId = GetWalkNormalMovementAction(eventObject->movementDirection);
        collisionState = GetCollisionInDirection(eventObject, eventObject->movementDirection);
    }
    if (collisionState)
    {
        movementActionId = GetWalkInPlaceNormalMovementAction(eventObject->facingDirection);
    }
    EventObjectSetSingleMovement(eventObject, sprite, movementActionId);
    eventObject->singleMovementActive = 1;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_WalkSequence_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        eventObject->singleMovementActive = 0;
        sprite->data[1] = 1;
    }
    return FALSE;
}

movement_type_def(MovementType_WalkSequenceUpRightLeftDown, gMovementTypeFuncs_WalkSequenceUpRightLeftDown)

u8 MovementType_WalkSequenceUpRightLeftDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gUpRightLeftDownDirections)];
    memcpy(directions, gUpRightLeftDownDirections, sizeof(gUpRightLeftDownDirections));
    if (eventObject->directionSequenceIndex == 2 && eventObject->initialCoords.x == eventObject->currentCoords.x)
    {
        eventObject->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceRightLeftDownUp, gMovementTypeFuncs_WalkSequenceRightLeftDownUp)

u8 MovementType_WalkSequenceRightLeftDownUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gRightLeftDownUpDirections)];
    memcpy(directions, gRightLeftDownUpDirections, sizeof(gRightLeftDownUpDirections));
    if (eventObject->directionSequenceIndex == 1 && eventObject->initialCoords.x == eventObject->currentCoords.x)
    {
        eventObject->directionSequenceIndex = 2;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceDownUpRightLeft, gMovementTypeFuncs_WalkSequenceDownUpRightLeft)

u8 MovementType_WalkSequenceDownUpRightLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gDownUpRightLeftDirections)];
    memcpy(directions, gDownUpRightLeftDirections, sizeof(gDownUpRightLeftDirections));
    if (eventObject->directionSequenceIndex == 1 && eventObject->initialCoords.y == eventObject->currentCoords.y)
    {
        eventObject->directionSequenceIndex = 2;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceLeftDownUpRight, gMovementTypeFuncs_WalkSequenceLeftDownUpRight)

u8 MovementType_WalkSequenceLeftDownUpRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gLeftDownUpRightDirections)];
    memcpy(directions, gLeftDownUpRightDirections, sizeof(gLeftDownUpRightDirections));
    if (eventObject->directionSequenceIndex == 2 && eventObject->initialCoords.y == eventObject->currentCoords.y)
    {
        eventObject->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceUpLeftRightDown, gMovementTypeFuncs_WalkSequenceUpLeftRightDown)

u8 MovementType_WalkSequenceUpLeftRightDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gUpLeftRightDownDirections)];
    memcpy(directions, gUpLeftRightDownDirections, sizeof(gUpLeftRightDownDirections));
    if (eventObject->directionSequenceIndex == 2 && eventObject->initialCoords.x == eventObject->currentCoords.x)
    {
        eventObject->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceLeftRightDownUp, gMovementTypeFuncs_WalkSequenceLeftRightDownUp)

u8 MovementType_WalkSequenceLeftRightDownUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gLeftRightDownUpDirections)];
    memcpy(directions, gLeftRightDownUpDirections, sizeof(gLeftRightDownUpDirections));
    if (eventObject->directionSequenceIndex == 1 && eventObject->initialCoords.x == eventObject->currentCoords.x)
    {
        eventObject->directionSequenceIndex = 2;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceDownUpLeftRight, gMovementTypeFuncs_WalkSequenceDownUpLeftRight)

u8 MovementType_WalkSequenceDownUpLeftRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gStandardDirections)];
    memcpy(directions, gStandardDirections, sizeof(gStandardDirections));
    if (eventObject->directionSequenceIndex == 1 && eventObject->initialCoords.y == eventObject->currentCoords.y)
    {
        eventObject->directionSequenceIndex = 2;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceRightDownUpLeft, gMovementTypeFuncs_WalkSequenceRightDownUpLeft)

u8 MovementType_WalkSequenceRightDownUpLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gRightDownUpLeftDirections)];
    memcpy(directions, gRightDownUpLeftDirections, sizeof(gRightDownUpLeftDirections));
    if (eventObject->directionSequenceIndex == 2 && eventObject->initialCoords.y == eventObject->currentCoords.y)
    {
        eventObject->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceLeftUpDownRight, gMovementTypeFuncs_WalkSequenceLeftUpDownRight)

u8 MovementType_WalkSequenceLeftUpDownRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gLeftUpDownRightDirections)];
    memcpy(directions, gLeftUpDownRightDirections, sizeof(gLeftUpDownRightDirections));
    if (eventObject->directionSequenceIndex == 2 && eventObject->initialCoords.y == eventObject->currentCoords.y)
    {
        eventObject->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceUpDownRightLeft, gMovementTypeFuncs_WalkSequenceUpDownRightLeft)

u8 MovementType_WalkSequenceUpDownRightLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gUpDownRightLeftDirections)];
    memcpy(directions, gUpDownRightLeftDirections, sizeof(gUpDownRightLeftDirections));
    if (eventObject->directionSequenceIndex == 1 && eventObject->initialCoords.y == eventObject->currentCoords.y)
    {
        eventObject->directionSequenceIndex = 2;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceRightLeftUpDown, gMovementTypeFuncs_WalkSequenceRightLeftUpDown)

u8 MovementType_WalkSequenceRightLeftUpDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gRightLeftUpDownDirections)];
    memcpy(directions, gRightLeftUpDownDirections, sizeof(gRightLeftUpDownDirections));
    if (eventObject->directionSequenceIndex == 1 && eventObject->initialCoords.x == eventObject->currentCoords.x)
    {
        eventObject->directionSequenceIndex = 2;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceDownRightLeftUp, gMovementTypeFuncs_WalkSequenceDownRightLeftUp)

u8 MovementType_WalkSequenceDownRightLeftUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gDownRightLeftUpDirections)];
    memcpy(directions, gDownRightLeftUpDirections, sizeof(gDownRightLeftUpDirections));
    if (eventObject->directionSequenceIndex == 2 && eventObject->initialCoords.x == eventObject->currentCoords.x)
    {
        eventObject->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceRightUpDownLeft, gMovementTypeFuncs_WalkSequenceRightUpDownLeft)

u8 MovementType_WalkSequenceRightUpDownLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gRightUpDownLeftDirections)];
    memcpy(directions, gRightUpDownLeftDirections, sizeof(gRightUpDownLeftDirections));
    if (eventObject->directionSequenceIndex == 2 && eventObject->initialCoords.y == eventObject->currentCoords.y)
    {
        eventObject->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceUpDownLeftRight, gMovementTypeFuncs_WalkSequenceUpDownLeftRight)

u8 MovementType_WalkSequenceUpDownLeftRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gUpDownLeftRightDirections)];
    memcpy(directions, gUpDownLeftRightDirections, sizeof(gUpDownLeftRightDirections));
    if (eventObject->directionSequenceIndex == 1 && eventObject->initialCoords.y == eventObject->currentCoords.y)
    {
        eventObject->directionSequenceIndex = 2;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceLeftRightUpDown, gMovementTypeFuncs_WalkSequenceLeftRightUpDown)

u8 MovementType_WalkSequenceLeftRightUpDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gLeftRightUpDownDirections)];
    memcpy(directions, gLeftRightUpDownDirections, sizeof(gLeftRightUpDownDirections));
    if (eventObject->directionSequenceIndex == 1 && eventObject->initialCoords.x == eventObject->currentCoords.x)
    {
        eventObject->directionSequenceIndex = 2;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceDownLeftRightUp, gMovementTypeFuncs_WalkSequenceDownLeftRightUp)

u8 MovementType_WalkSequenceDownLeftRightUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gDownLeftRightUpDirections)];
    memcpy(directions, gDownLeftRightUpDirections, sizeof(gDownLeftRightUpDirections));
    if (eventObject->directionSequenceIndex == 2 && eventObject->initialCoords.x == eventObject->currentCoords.x)
    {
        eventObject->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceUpLeftDownRight, gMovementTypeFuncs_WalkSequenceUpLeftDownRight)

u8 MovementType_WalkSequenceUpLeftDownRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gUpLeftDownRightDirections)];
    memcpy(directions, gUpLeftDownRightDirections, sizeof(gUpLeftDownRightDirections));
    if (eventObject->directionSequenceIndex == 2 && eventObject->initialCoords.y == eventObject->currentCoords.y)
    {
        eventObject->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceDownRightUpLeft, gMovementTypeFuncs_WalkSequenceDownRightUpLeft)

u8 MovementType_WalkSequenceDownRightUpLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gDownRightUpLeftDirections)];
    memcpy(directions, gDownRightUpLeftDirections, sizeof(gDownRightUpLeftDirections));
    if (eventObject->directionSequenceIndex == 2 && eventObject->initialCoords.y == eventObject->currentCoords.y)
    {
        eventObject->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceLeftDownRightUp, gMovementTypeFuncs_WalkSequenceLeftDownRightUp)

u8 MovementType_WalkSequenceLeftDownRightUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gLeftDownRightUpDirections)];
    memcpy(directions, gLeftDownRightUpDirections, sizeof(gLeftDownRightUpDirections));
    if (eventObject->directionSequenceIndex == 2 && eventObject->initialCoords.x == eventObject->currentCoords.x)
    {
        eventObject->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceRightUpLeftDown, gMovementTypeFuncs_WalkSequenceRightUpLeftDown)

u8 MovementType_WalkSequenceRightUpLeftDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gRightUpLeftDownDirections)];
    memcpy(directions, gRightUpLeftDownDirections, sizeof(gRightUpLeftDownDirections));
    if (eventObject->directionSequenceIndex == 2 && eventObject->initialCoords.x == eventObject->currentCoords.x)
    {
        eventObject->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceUpRightDownLeft, gMovementTypeFuncs_WalkSequenceUpRightDownLeft)

u8 MovementType_WalkSequenceUpRightDownLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gUpRightDownLeftDirections)];
    memcpy(directions, gUpRightDownLeftDirections, sizeof(gUpRightDownLeftDirections));
    if (eventObject->directionSequenceIndex == 2 && eventObject->initialCoords.y == eventObject->currentCoords.y)
    {
        eventObject->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceDownLeftUpRight, gMovementTypeFuncs_WalkSequenceDownLeftUpRight)

u8 MovementType_WalkSequenceDownLeftUpRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gDownLeftUpRightDirections)];
    memcpy(directions, gDownLeftUpRightDirections, sizeof(gDownLeftUpRightDirections));
    if (eventObject->directionSequenceIndex == 2 && eventObject->initialCoords.y == eventObject->currentCoords.y)
    {
        eventObject->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceLeftUpRightDown, gMovementTypeFuncs_WalkSequenceLeftUpRightDown)

u8 MovementType_WalkSequenceLeftUpRightDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gLeftUpRightDownDirections)];
    memcpy(directions, gLeftUpRightDownDirections, sizeof(gLeftUpRightDownDirections));
    if (eventObject->directionSequenceIndex == 2 && eventObject->initialCoords.x == eventObject->currentCoords.x)
    {
        eventObject->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceRightDownLeftUp, gMovementTypeFuncs_WalkSequenceRightDownLeftUp)

u8 MovementType_WalkSequenceRightDownLeftUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 directions[sizeof(gRightDownLeftUpDirections)];
    memcpy(directions, gRightDownLeftUpDirections, sizeof(gRightDownLeftUpDirections));
    if (eventObject->directionSequenceIndex == 2 && eventObject->initialCoords.x == eventObject->currentCoords.x)
    {
        eventObject->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(eventObject, sprite, directions);
}

movement_type_def(MovementType_CopyPlayer, gMovementTypeFuncs_CopyPlayer)

bool8 MovementType_CopyPlayer_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    if (eventObject->directionSequenceIndex == 0)
    {
        eventObject->directionSequenceIndex = GetPlayerFacingDirection();
    }
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_CopyPlayer_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (gEventObjects[gPlayerAvatar.eventObjectId].movementActionId == 0xFF || gPlayerAvatar.tileTransitionState == T_TILE_CENTER)
    {
        return FALSE;
    }
    return gCopyPlayerMovementFuncs[PlayerGetCopyableMovement()](eventObject, sprite, GetPlayerMovementDirection(), NULL);
}

bool8 MovementType_CopyPlayer_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        eventObject->singleMovementActive = 0;
        sprite->data[1] = 1;
    }
    return FALSE;
}

bool8 CopyablePlayerMovement_None(struct EventObject *eventObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    return FALSE;
}

bool8 CopyablePlayerMovement_FaceDirection(struct EventObject *eventObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(state_to_direction(gInitialMovementTypeFacingDirections[eventObject->movementType], eventObject->directionSequenceIndex, playerDirection)));
    eventObject->singleMovementActive = 1;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 CopyablePlayerMovement_GoSpeed0(struct EventObject *eventObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    if (EventObjectIsFarawayIslandMew(eventObject))
    {
        direction = GetMewMoveDirection();
        if (direction == DIR_NONE)
        {
            direction = playerDirection;
            direction = state_to_direction(gInitialMovementTypeFacingDirections[eventObject->movementType], eventObject->directionSequenceIndex, direction);
            EventObjectMoveDestCoords(eventObject, direction, &x, &y);
            EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(direction));
            eventObject->singleMovementActive = 1;
            sprite->data[1] = 2;
            return TRUE;
        }
    }
    else
    {
        direction = state_to_direction(gInitialMovementTypeFacingDirections[eventObject->movementType], eventObject->directionSequenceIndex, direction);
    }
    EventObjectMoveDestCoords(eventObject, direction, &x, &y);
    EventObjectSetSingleMovement(eventObject, sprite, GetWalkNormalMovementAction(direction));
    if (GetCollisionAtCoords(eventObject, x, y, direction) || (tileCallback != NULL && !tileCallback(MapGridGetMetatileBehaviorAt(x, y))))
    {
        EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(direction));
    }
    eventObject->singleMovementActive = 1;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 CopyablePlayerMovement_GoSpeed1(struct EventObject *eventObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[eventObject->movementType], eventObject->directionSequenceIndex, direction);
    EventObjectMoveDestCoords(eventObject, direction, &x, &y);
    EventObjectSetSingleMovement(eventObject, sprite, GetWalkFastMovementAction(direction));
    if (GetCollisionAtCoords(eventObject, x, y, direction) || (tileCallback != NULL && !tileCallback(MapGridGetMetatileBehaviorAt(x, y))))
    {
        EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(direction));
    }
    eventObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 CopyablePlayerMovement_GoSpeed2(struct EventObject *eventObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[eventObject->movementType], eventObject->directionSequenceIndex, direction);
    EventObjectMoveDestCoords(eventObject, direction, &x, &y);
    EventObjectSetSingleMovement(eventObject, sprite, GetWalkFastestMovementAction(direction));
    if (GetCollisionAtCoords(eventObject, x, y, direction) || (tileCallback != NULL && !tileCallback(MapGridGetMetatileBehaviorAt(x, y))))
    {
        EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(direction));
    }
    eventObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 CopyablePlayerMovement_Slide(struct EventObject *eventObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[eventObject->movementType], eventObject->directionSequenceIndex, direction);
    EventObjectMoveDestCoords(eventObject, direction, &x, &y);
    EventObjectSetSingleMovement(eventObject, sprite, GetSlideMovementAction(direction));
    if (GetCollisionAtCoords(eventObject, x, y, direction) || (tileCallback != NULL && !tileCallback(MapGridGetMetatileBehaviorAt(x, y))))
    {
        EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(direction));
    }
    eventObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 cph_IM_DIFFERENT(struct EventObject *eventObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    u32 direction;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[eventObject->movementType], eventObject->directionSequenceIndex, direction);
    EventObjectSetSingleMovement(eventObject, sprite, GetJumpInPlaceMovementAction(direction));
    eventObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 CopyablePlayerMovement_GoSpeed4(struct EventObject *eventObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[eventObject->movementType], eventObject->directionSequenceIndex, direction);
    EventObjectMoveDestCoords(eventObject, direction, &x, &y);
    EventObjectSetSingleMovement(eventObject, sprite, GetJumpMovementAction(direction));
    if (GetCollisionAtCoords(eventObject, x, y, direction) || (tileCallback != NULL && !tileCallback(MapGridGetMetatileBehaviorAt(x, y))))
    {
        EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(direction));
    }
    eventObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 CopyablePlayerMovement_Jump(struct EventObject *eventObject, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[eventObject->movementType], eventObject->directionSequenceIndex, direction);
    x = eventObject->currentCoords.x;
    y = eventObject->currentCoords.y;
    MoveCoordsInDirection(direction, &x, &y, 2, 2);
    EventObjectSetSingleMovement(eventObject, sprite, GetJump2MovementAction(direction));
    if (GetCollisionAtCoords(eventObject, x, y, direction) || (tileCallback != NULL && !tileCallback(MapGridGetMetatileBehaviorAt(x, y))))
    {
        EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(direction));
    }
    eventObject->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

movement_type_def(MovementType_CopyPlayerInGrass, gMovementTypeFuncs_CopyPlayerInGrass)

bool8 MovementType_CopyPlayerInGrass_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (gEventObjects[gPlayerAvatar.eventObjectId].movementActionId == 0xFF || gPlayerAvatar.tileTransitionState == T_TILE_CENTER)
    {
        return FALSE;
    }
    return gCopyPlayerMovementFuncs[PlayerGetCopyableMovement()](eventObject, sprite, GetPlayerMovementDirection(), MetatileBehavior_IsPokeGrass);
}

void MovementType_TreeDisguise(struct Sprite *sprite)
{
    struct EventObject *eventObject;

    eventObject = &gEventObjects[sprite->data[0]];
    if (eventObject->directionSequenceIndex == 0 || (eventObject->directionSequenceIndex == 1 && !sprite->data[7]))
    {
        EventObjectGetLocalIdAndMap(eventObject, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
        eventObject->fieldEffectSpriteId = FieldEffectStart(FLDEFF_TREE_DISGUISE);
        eventObject->directionSequenceIndex = 1;
        sprite->data[7]++;
    }
    UpdateEventObjectCurrentMovement(&gEventObjects[sprite->data[0]], sprite, MovementType_Disguise_Callback);
}

static bool8 MovementType_Disguise_Callback(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    return FALSE;
}

void MovementType_MountainDisguise(struct Sprite *sprite)
{
    struct EventObject *eventObject;

    eventObject = &gEventObjects[sprite->data[0]];
    if (eventObject->directionSequenceIndex == 0 || (eventObject->directionSequenceIndex == 1 && !sprite->data[7]))
    {
        EventObjectGetLocalIdAndMap(eventObject, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
        eventObject->fieldEffectSpriteId = FieldEffectStart(FLDEFF_MOUNTAIN_DISGUISE);
        eventObject->directionSequenceIndex = 1;
        sprite->data[7]++;
    }
    UpdateEventObjectCurrentMovement(&gEventObjects[sprite->data[0]], sprite, MovementType_Disguise_Callback);
}

void MovementType_Hidden(struct Sprite *sprite)
{
    if (!sprite->data[7])
    {
        gEventObjects[sprite->data[0]].fixedPriority = TRUE;
        sprite->subspriteMode = 2;
        sprite->oam.priority = 3;
        sprite->data[7]++;
    }
    UpdateEventObjectCurrentMovement(&gEventObjects[sprite->data[0]], sprite, MovementType_Hidden_Callback);
}

static bool8 MovementType_Hidden_Callback(struct EventObject *eventObject, struct Sprite *sprite)
{
    return gMovementTypeFuncs_Hidden[sprite->data[1]](eventObject, sprite);
}

bool8 MovementType_Hidden_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    return FALSE;
}

bool8 MovementType_MoveInPlace_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        sprite->data[1] = 0;
    }
    return FALSE;
}

movement_type_def(MovementType_WalkInPlace, gMovementTypeFuncs_WalkInPlace)

bool8 MovementType_WalkInPlace_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    EventObjectSetSingleMovement(eventObject, sprite, GetWalkInPlaceNormalMovementAction(eventObject->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_WalkSlowlyInPlace, gMovementTypeFuncs_WalkSlowlyInPlace)

bool8 MovementType_WalkSlowlyInPlace_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    EventObjectSetSingleMovement(eventObject, sprite, GetWalkInPlaceSlowMovementAction(eventObject->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_JogInPlace, gMovementTypeFuncs_JogInPlace)

bool8 MovementType_JogInPlace_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    EventObjectSetSingleMovement(eventObject, sprite, GetWalkInPlaceFastMovementAction(eventObject->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_RunInPlace, gMovementTypeFuncs_RunInPlace)

bool8 MovementType_RunInPlace_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    EventObjectSetSingleMovement(eventObject, sprite, GetWalkInPlaceFastestMovementAction(eventObject->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_Invisible, gMovementTypeFuncs_Invisible)

bool8 MovementType_Invisible_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    ClearEventObjectMovement(eventObject, sprite);
    EventObjectSetSingleMovement(eventObject, sprite, GetFaceDirectionMovementAction(eventObject->facingDirection));
    eventObject->invisible = TRUE;
    sprite->data[1] = 1;
    return TRUE;
}
bool8 MovementType_Invisible_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (EventObjectExecSingleMovementAction(eventObject, sprite))
    {
        sprite->data[1] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_Invisible_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->singleMovementActive = 0;
    return FALSE;
}

static void ClearEventObjectMovement(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->singleMovementActive = 0;
    eventObject->heldMovementActive = FALSE;
    eventObject->heldMovementFinished = FALSE;
    eventObject->movementActionId = 0xFF;
    sprite->data[1] = 0;
}

u8 GetFaceDirectionAnimNum(u8 direction)
{
    return gFaceDirectionAnimNums[direction];
}

u8 GetMoveDirectionAnimNum(u8 direction)
{
    return gMoveDirectionAnimNums[direction];
}

u8 GetMoveDirectionFastAnimNum(u8 direction)
{
    return gMoveDirectionFastAnimNums[direction];
}

u8 GetMoveDirectionFasterAnimNum(u8 direction)
{
    return gMoveDirectionFasterAnimNums[direction];
}

u8 GetMoveDirectionFastestAnimNum(u8 direction)
{
    return gMoveDirectionFastestAnimNums[direction];
}

u8 GetJumpSpecialDirectionAnimNum(u8 direction)
{
    return gJumpSpecialDirectionAnimNums[direction];
}

u8 GetAcroWheelieDirectionAnimNum(u8 direction)
{
    return gAcroWheelieDirectionAnimNums[direction];
}

u8 Unref_GetAnimNums_08375633(u8 direction)
{
    return gUnrefAnimNums_08375633[direction];
}

u8 GetAcroEndWheelieDirectionAnimNum(u8 direction)
{
    return gAcroEndWheelieDirectionAnimNums[direction];
}

u8 GetAcroUnusedActionDirectionAnimNum(u8 direction)
{
    return gAcroUnusedActionDirectionAnimNums[direction];
}

u8 GetAcroWheeliePedalDirectionAnimNum(u8 direction)
{
    return gAcroWheeliePedalDirectionAnimNums[direction];
}

u8 GetFishingDirectionAnimNum(u8 direction)
{
    return gFishingDirectionAnimNums[direction];
}

u8 GetFishingNoCatchDirectionAnimNum(u8 direction)
{
    return gFishingNoCatchDirectionAnimNums[direction];
}

u8 GetFishingBiteDirectionAnimNum(u8 direction)
{
    return gFishingBiteDirectionAnimNums[direction];
}

u8 GetRunningDirectionAnimNum(u8 direction)
{
    return gRunningDirectionAnimNums[direction];
}

static const struct UnkStruct_085094AC *sub_8092A4C(const union AnimCmd *const *anims)
{
    const struct UnkStruct_085094AC *retval;

    for (retval = gUnknown_085094AC; retval->anims != NULL; retval++)
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

u8 GetDirectionToFace(s16 x1, s16 y1, s16 x2, s16 y2)
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

void SetTrainerMovementType(struct EventObject *eventObject, u8 movementType)
{
    eventObject->movementType = movementType;
    eventObject->directionSequenceIndex = 0;
    eventObject->playerCopyableMovement = 0;
    gSprites[eventObject->spriteId].callback = sMovementTypeCallbacks[movementType];
    gSprites[eventObject->spriteId].data[1] = 0;
}

u8 GetTrainerFacingDirectionMovementType(u8 direction)
{
    return gTrainerFacingDirectionMovementTypes[direction];
}

static u8 GetCollisionInDirection(struct EventObject *eventObject, u8 direction)
{
    s16 x;
    s16 y;
    x = eventObject->currentCoords.x;
    y = eventObject->currentCoords.y;
    MoveCoords(direction, &x, &y);
    return GetCollisionAtCoords(eventObject, x, y, direction);
}

u8 GetCollisionAtCoords(struct EventObject *eventObject, s16 x, s16 y, u32 dirn)
{
    u8 direction;

    direction = dirn;
    if (IsCoordOutsideEventObjectMovementRange(eventObject, x, y))
        return 1;
    else if (MapGridIsImpassableAt(x, y) || GetMapBorderIdAt(x, y) == -1 || IsMetatileDirectionallyImpassable(eventObject, x, y, direction))
        return 2;
    else if (eventObject->trackedByCamera && !CanCameraMoveInDirection(direction))
        return 2;
    else if (IsZCoordMismatchAt(eventObject->currentElevation, x, y))
        return 3;
    else if (DoesObjectCollideWithObjectAt(eventObject, x, y))
        return 4;
    return 0;
}

u8 GetCollisionFlagsAtCoords(struct EventObject *eventObject, s16 x, s16 y, u8 direction)
{
    u8 flags = 0;

    if (IsCoordOutsideEventObjectMovementRange(eventObject, x, y))
        flags |= 1;
    if (MapGridIsImpassableAt(x, y) || GetMapBorderIdAt(x, y) == -1 || IsMetatileDirectionallyImpassable(eventObject, x, y, direction) || (eventObject->trackedByCamera && !CanCameraMoveInDirection(direction)))
        flags |= 2;
    if (IsZCoordMismatchAt(eventObject->currentElevation, x, y))
        flags |= 4;
    if (DoesObjectCollideWithObjectAt(eventObject, x, y))
        flags |= 8;
    return flags;
}

static bool8 IsCoordOutsideEventObjectMovementRange(struct EventObject *eventObject, s16 x, s16 y)
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
    if (gOppositeDirectionBlockedMetatileFuncs[direction - 1](eventObject->currentMetatileBehavior)
        || gDirectionBlockedMetatileFuncs[direction - 1](MapGridGetMetatileBehaviorAt(x, y)))
    {
        return TRUE;
    }
    return FALSE;
}

static bool8 DoesObjectCollideWithObjectAt(struct EventObject *eventObject, s16 x, s16 y)
{
    u8 i;
    struct EventObject *curObject;

    for (i = 0; i < EVENT_OBJECTS_COUNT; i++)
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

bool8 IsBerryTreeSparkling(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 eventObjectId;

    if (!TryGetEventObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &eventObjectId)
        && gSprites[gEventObjects[eventObjectId].spriteId].data[7] & 2)
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
    *x += sDirectionToVectors[direction].x;
    *y += sDirectionToVectors[direction].y;
}

void sub_8092F60(u8 direction, s16 *x, s16 *y)
{
    *x += sDirectionToVectors[direction].x << 4;
    *y += sDirectionToVectors[direction].y << 4;
}

static void MoveCoordsInDirection(u32 dir, s16 *x, s16 *y, s16 deltaX, s16 deltaY)
{
    u8 direction = dir;
    s16 dx2 = (u16)deltaX;
    s16 dy2 = (u16)deltaY;
    if (sDirectionToVectors[direction].x > 0)
        *x += dx2;
    if (sDirectionToVectors[direction].x < 0)
        *x -= dx2;
    if (sDirectionToVectors[direction].y > 0)
        *y += dy2;
    if (sDirectionToVectors[direction].y < 0)
        *y -= dy2;
}

void sub_8092FF0(s16 x, s16 y, s16 *destX, s16 *destY)
{
    *destX = (x - gSaveBlock1Ptr->pos.x) << 4;
    *destY = (y - gSaveBlock1Ptr->pos.y) << 4;
    *destX -= gTotalCameraPixelOffsetX;
    *destY -= gTotalCameraPixelOffsetY;
}

void SetSpritePosToMapCoords(s16 mapX, s16 mapY, s16 *destX, s16 *destY)
{
    s16 dx = -gTotalCameraPixelOffsetX - gFieldCamera.x;
    s16 dy = -gTotalCameraPixelOffsetY - gFieldCamera.y;
    if (gFieldCamera.x > 0)
        dx += 1 << 4;

    if (gFieldCamera.x < 0)
        dx -= 1 << 4;

    if (gFieldCamera.y > 0)
        dy += 1 << 4;

    if (gFieldCamera.y < 0)
        dy -= 1 << 4;

    *destX = ((mapX - gSaveBlock1Ptr->pos.x) << 4) + dx;
    *destY = ((mapY - gSaveBlock1Ptr->pos.y) << 4) + dy;
}

void sub_80930E0(s16 *x, s16 *y, s16 dx, s16 dy)
{
    SetSpritePosToMapCoords(*x, *y, x, y);
    *x += dx;
    *y += dy;
}

static void GetEventObjectMovingCameraOffset(s16 *x, s16 *y)
{
    *x = 0;
    *y = 0;
    if (gFieldCamera.x > 0)
    {
        (*x)++;
    }
    if (gFieldCamera.x < 0)
    {
        (*x) --;
    }
    if (gFieldCamera.y > 0)
    {
        (*y)++;
    }
    if (gFieldCamera.y < 0)
    {
        (*y) --;
    }
}

void EventObjectMoveDestCoords(struct EventObject *eventObject, u32 direction, s16 *x, s16 *y)
{
    u8 newDirn = direction;
    *x = eventObject->currentCoords.x;
    *y = eventObject->currentCoords.y;
    MoveCoords(newDirn, x, y);
}

bool8 EventObjectIsMovementOverridden(struct EventObject *eventObject)
{
    if (eventObject->singleMovementActive || eventObject->heldMovementActive)
        return TRUE;

    return FALSE;
}

bool8 EventObjectIsHeldMovementActive(struct EventObject *eventObject)
{
    if (eventObject->heldMovementActive && eventObject->movementActionId != 0xFF)
        return TRUE;

    return FALSE;
}

bool8 EventObjectSetHeldMovement(struct EventObject *eventObject, u8 movementActionId)
{
    if (EventObjectIsMovementOverridden(eventObject))
        return TRUE;

    UnfreezeEventObject(eventObject);
    eventObject->movementActionId = movementActionId;
    eventObject->heldMovementActive = TRUE;
    eventObject->heldMovementFinished = FALSE;
    gSprites[eventObject->spriteId].data[2] = 0;
    return FALSE;
}

void EventObjectForceSetHeldMovement(struct EventObject *eventObject, u8 movementActionId)
{
    EventObjectClearHeldMovementIfActive(eventObject);
    EventObjectSetHeldMovement(eventObject, movementActionId);
}

void EventObjectClearHeldMovementIfActive(struct EventObject *eventObject)
{
    if (eventObject->heldMovementActive)
        EventObjectClearHeldMovement(eventObject);
}

void EventObjectClearHeldMovement(struct EventObject *eventObject)
{
    eventObject->movementActionId = 0xFF;
    eventObject->heldMovementActive = FALSE;
    eventObject->heldMovementFinished = FALSE;
    gSprites[eventObject->spriteId].data[1] = 0;
    gSprites[eventObject->spriteId].data[2] = 0;
}

u8 EventObjectCheckHeldMovementStatus(struct EventObject *eventObject)
{
    if (eventObject->heldMovementActive)
        return eventObject->heldMovementFinished;

    return 16;
}

u8 EventObjectClearHeldMovementIfFinished(struct EventObject *eventObject)
{
    u8 heldMovementStatus = EventObjectCheckHeldMovementStatus(eventObject);
    if (heldMovementStatus != 0 && heldMovementStatus != 16)
        EventObjectClearHeldMovementIfActive(eventObject);

    return heldMovementStatus;
}

u8 EventObjectGetHeldMovementActionId(struct EventObject *eventObject)
{
    if (eventObject->heldMovementActive)
        return eventObject->movementActionId;

    return 0xFF;
}

void UpdateEventObjectCurrentMovement(struct EventObject *eventObject, struct Sprite *sprite, bool8 (*callback)(struct EventObject *, struct Sprite *))
{
    DoGroundEffects_OnSpawn(eventObject, sprite);
    TryEnableEventObjectAnim(eventObject, sprite);
    if (EventObjectIsHeldMovementActive(eventObject))
    {
        EventObjectExecHeldMovementAction(eventObject, sprite);
    }
    else if (!eventObject->frozen)
    {
        while (callback(eventObject, sprite));
    }
    DoGroundEffects_OnBeginStep(eventObject, sprite);
    DoGroundEffects_OnFinishStep(eventObject, sprite);
    UpdateEventObjectSpriteAnimPause(eventObject, sprite);
    UpdateEventObjectVisibility(eventObject, sprite);
    EventObjectUpdateSubpriority(eventObject, sprite);
}

#define dirn_to_anim(name, table)\
u8 name(u32 idx)\
{\
    u8 direction;\
    u8 animIds[sizeof(table)];\
    direction = idx;\
    memcpy(animIds, (table), sizeof(table));\
    if (direction > DIR_EAST) direction = 0;\
    return animIds[direction];\
}

dirn_to_anim(GetFaceDirectionMovementAction, gFaceDirectionMovementActions);
dirn_to_anim(GetWalkSlowMovementAction, gWalkSlowMovementActions);
dirn_to_anim(GetWalkNormalMovementAction, gWalkNormalMovementActions);
dirn_to_anim(GetWalkFastMovementAction, gWalkFastMovementActions);
dirn_to_anim(GetRideWaterCurrentMovementAction, gRideWaterCurrentMovementActions);
dirn_to_anim(GetWalkFastestMovementAction, gWalkFastestMovementActions);
dirn_to_anim(GetSlideMovementAction, gSlideMovementActions);
dirn_to_anim(GetPlayerRunMovementAction, gPlayerRunMovementActions);
dirn_to_anim(GetJump2MovementAction, gJump2MovementActions);
dirn_to_anim(GetJumpInPlaceMovementAction, gJumpInPlaceMovementActions);
dirn_to_anim(GetJumpInPlaceTurnAroundMovementAction, gJumpInPlaceTurnAroundMovementActions);
dirn_to_anim(GetJumpMovementAction, gJumpMovementActions);
dirn_to_anim(GetJumpSpecialMovementAction, gJumpSpecialMovementActions);
dirn_to_anim(GetWalkInPlaceSlowMovementAction, gWalkInPlaceSlowMovementActions);
dirn_to_anim(GetWalkInPlaceNormalMovementAction, gWalkInPlaceNormalMovementActions);
dirn_to_anim(GetWalkInPlaceFastMovementAction, gWalkInPlaceFastMovementActions);
dirn_to_anim(GetWalkInPlaceFastestMovementAction, gWalkInPlaceFastestMovementActions);

bool8 EventObjectFaceOppositeDirection(struct EventObject *eventObject, u8 direction)
{
    return EventObjectSetHeldMovement(eventObject, GetFaceDirectionMovementAction(GetOppositeDirection(direction)));
}

dirn_to_anim(GetAcroWheelieFaceDirectionMovementAction, gAcroWheelieFaceDirectionMovementActions);
dirn_to_anim(GetAcroPopWheelieFaceDirectionMovementAction, gAcroPopWheelieFaceDirectionMovementActions);
dirn_to_anim(GetAcroEndWheelieFaceDirectionMovementAction, gAcroEndWheelieFaceDirectionMovementActions);
dirn_to_anim(GetAcroWheelieHopFaceDirectionMovementAction, gAcroWheelieHopFaceDirectionMovementActions);
dirn_to_anim(GetAcroWheelieHopDirectionMovementAction, gAcroWheelieHopDirectionMovementActions);
dirn_to_anim(GetAcroWheelieJumpDirectionMovementAction, gAcroWheelieJumpDirectionMovementActions);
dirn_to_anim(GetAcroWheelieInPlaceDirectionMovementAction, gAcroWheelieInPlaceDirectionMovementActions);
dirn_to_anim(GetAcroPopWheelieMoveDirectionMovementAction, gAcroPopWheelieMoveDirectionMovementActions);
dirn_to_anim(GetAcroWheelieMoveDirectionMovementAction, gAcroWheelieMoveDirectionMovementActions);
dirn_to_anim(GetAcroEndWheelieMoveDirectionMovementAction, gAcroEndWheelieMoveDirectionMovementActions);

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

static void EventObjectExecHeldMovementAction(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (gMovementActionFuncs[eventObject->movementActionId][sprite->data[2]](eventObject, sprite))
    {
        eventObject->heldMovementFinished = TRUE;
    }
}

static bool8 EventObjectExecSingleMovementAction(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (gMovementActionFuncs[eventObject->movementActionId][sprite->data[2]](eventObject, sprite))
    {
        eventObject->movementActionId = 0xFF;
        sprite->data[2] = 0;
        return TRUE;
    }
    return FALSE;
}

static void EventObjectSetSingleMovement(struct EventObject *eventObject, struct Sprite *sprite, u8 animId)
{
    eventObject->movementActionId = animId;
    sprite->data[2] = 0;
}

static void FaceDirection(struct EventObject *eventObject, struct Sprite *sprite, u8 direction)
{
    SetEventObjectDirection(eventObject, direction);
    ShiftStillEventObjectCoords(eventObject);
    obj_npc_animation_step(eventObject, sprite, GetMoveDirectionAnimNum(eventObject->facingDirection));
    sprite->animPaused = TRUE;
    sprite->data[2] = 1;
}

bool8 MovementAction_FaceDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    FaceDirection(eventObject, sprite, DIR_SOUTH);
    return TRUE;
}

bool8 MovementAction_FaceUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    FaceDirection(eventObject, sprite, DIR_NORTH);
    return TRUE;
}

bool8 MovementAction_FaceLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    FaceDirection(eventObject, sprite, DIR_WEST);
    return TRUE;
}

bool8 MovementAction_FaceRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    FaceDirection(eventObject, sprite, DIR_EAST);
    return TRUE;
}

void npc_apply_direction(struct EventObject *eventObject, struct Sprite *sprite, u8 direction, u8 speed)
{
    s16 x;
    s16 y;

    x = eventObject->currentCoords.x;
    y = eventObject->currentCoords.y;
    SetEventObjectDirection(eventObject, direction);
    MoveCoords(direction, &x, &y);
    ShiftEventObjectCoords(eventObject, x, y);
    oamt_npc_ministep_reset(sprite, direction, speed);
    sprite->animPaused = FALSE;
    if (gLockedAnimEventObjects != NULL && FindLockedEventObjectIndex(eventObject) != EVENT_OBJECTS_COUNT)
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

void StartRunningAnim(struct EventObject *eventObject, struct Sprite *sprite, u8 direction)
{
    npc_apply_direction(eventObject, sprite, direction, 1);
    npc_apply_anim_looping(eventObject, sprite, GetRunningDirectionAnimNum(eventObject->facingDirection));
}

bool8 npc_obj_ministep_stop_on_arrival(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (obj_npc_ministep(sprite))
    {
        ShiftStillEventObjectCoords(eventObject);
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
    SetEventObjectDirection(eventObject, direction);
    MoveCoords(direction, &x, &y);
    ShiftEventObjectCoords(eventObject, x, y);
    sub_80976DC(sprite, direction);
    sprite->animPaused = FALSE;
    eventObject->triggerGroundEffectsOnMove = TRUE;
    sprite->data[2] = 1;
}

void sub_8093B60(struct EventObject *eventObject, struct Sprite *sprite, u8 direction)
{
    sub_8093AF0(eventObject, sprite, direction);
    npc_apply_anim_looping(eventObject, sprite, GetMoveDirectionAnimNum(eventObject->facingDirection));
}

bool8 an_walk_any_2(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80976EC(sprite))
    {
        ShiftStillEventObjectCoords(eventObject);
        eventObject->triggerGroundEffectsOnStop = TRUE;
        sprite->animPaused = TRUE;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkSlowDiagonalUpLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8093B60(eventObject, sprite, DIR_NORTHWEST);
    return MovementAction_WalkSlowDiagonalUpLeft_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkSlowDiagonalUpLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (an_walk_any_2(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkSlowDiagonalUpRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8093B60(eventObject, sprite, DIR_NORTHEAST);
    return MovementAction_WalkSlowDiagonalUpRight_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkSlowDiagonalUpRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (an_walk_any_2(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkSlowDiagonalDownLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8093B60(eventObject, sprite, DIR_SOUTHWEST);
    return MovementAction_WalkSlowDiagonalDownLeft_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkSlowDiagonalDownLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (an_walk_any_2(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkSlowDiagonalDownRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8093B60(eventObject, sprite, DIR_SOUTHEAST);
    return MovementAction_WalkSlowDiagonalDownRight_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkSlowDiagonalDownRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (an_walk_any_2(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkSlowDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8093B60(eventObject, sprite, DIR_SOUTH);
    return MovementAction_WalkSlowDown_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkSlowDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (an_walk_any_2(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkSlowUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8093B60(eventObject, sprite, DIR_NORTH);
    return MovementAction_WalkSlowUp_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkSlowUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (an_walk_any_2(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkSlowLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8093B60(eventObject, sprite, DIR_WEST);
    return MovementAction_WalkSlowLeft_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkSlowLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (an_walk_any_2(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkSlowRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8093B60(eventObject, sprite, DIR_EAST);
    return MovementAction_WalkSlowRight_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkSlowRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (an_walk_any_2(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalDiagonalUpLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_NORTHWEST, 0);
    return MovementAction_WalkNormalDiagonalUpLeft_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkNormalDiagonalUpLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalDiagonalUpRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_NORTHEAST, 0);
    return MovementAction_WalkNormalDiagonalUpRight_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkNormalDiagonalUpRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalDiagonalDownLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_SOUTHWEST, 0);
    return MovementAction_WalkNormalDiagonalDownLeft_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkNormalDiagonalDownLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalDiagonalDownRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_SOUTHEAST, 0);
    return MovementAction_WalkNormalDiagonalDownRight_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkNormalDiagonalDownRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_SOUTH, 0);
    return MovementAction_WalkNormalDown_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkNormalDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_NORTH, 0);
    return MovementAction_WalkNormalUp_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkNormalUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_WEST, 0);
    return MovementAction_WalkNormalLeft_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkNormalLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_EAST, 0);
    return MovementAction_WalkNormalRight_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkNormalRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

void sub_8093FC4(struct EventObject *eventObject, struct Sprite *sprite, u8 direction, u8 speed, u8 a5)
{
    s16 displacements[ARRAY_COUNT(gUnknown_0850DFBC)];
    s16 x;
    s16 y;

    memcpy(displacements, gUnknown_0850DFBC, sizeof gUnknown_0850DFBC);
    x = 0;
    y = 0;
    SetEventObjectDirection(eventObject, direction);
    MoveCoordsInDirection(direction, &x, &y, displacements[speed], displacements[speed]);
    ShiftEventObjectCoords(eventObject, eventObject->currentCoords.x + x, eventObject->currentCoords.y + y);
    sub_809783C(sprite, direction, speed, a5);
    sprite->data[2] = 1;
    sprite->animPaused = 0;
    eventObject->triggerGroundEffectsOnMove = 1;
    eventObject->disableCoveringGroundEffects = 1;
}

void maybe_shadow_1(struct EventObject *eventObject, struct Sprite *sprite, u8 direction, u8 speed, u8 a4)
{
    sub_8093FC4(eventObject, sprite, direction, speed, a4);
    npc_apply_anim_looping(eventObject, sprite, GetMoveDirectionAnimNum(eventObject->facingDirection));
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
        MoveCoordsInDirection(eventObject->movementDirection, &x, &y, displacements[sprite->data[4]], displacements[sprite->data[4]]);
        ShiftEventObjectCoords(eventObject, eventObject->currentCoords.x + x, eventObject->currentCoords.y + y);
        eventObject->triggerGroundEffectsOnMove = TRUE;
        eventObject->disableCoveringGroundEffects = TRUE;
    }
    else if (result == 0xFF)
    {
        ShiftStillEventObjectCoords(eventObject);
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
            SetEventObjectDirection(eventObject, GetOppositeDirection(eventObject->movementDirection));
            obj_npc_animation_step(eventObject, sprite, GetMoveDirectionAnimNum(eventObject->facingDirection));
        default:
            return FALSE;
    }
}

bool8 MovementAction_Jump2Down_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    maybe_shadow_1(eventObject, sprite, DIR_SOUTH, 2, 0);
    return MovementAction_Jump2Down_Step1(eventObject, sprite);
}

bool8 MovementAction_Jump2Down_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_Jump2Up_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    maybe_shadow_1(eventObject, sprite, DIR_NORTH, 2, 0);
    return MovementAction_Jump2Up_Step1(eventObject, sprite);
}

bool8 MovementAction_Jump2Up_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_Jump2Left_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    maybe_shadow_1(eventObject, sprite, DIR_WEST, 2, 0);
    return MovementAction_Jump2Left_Step1(eventObject, sprite);
}

bool8 MovementAction_Jump2Left_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_Jump2Right_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    maybe_shadow_1(eventObject, sprite, DIR_EAST, 2, 0);
    return MovementAction_Jump2Right_Step1(eventObject, sprite);
}

bool8 MovementAction_Jump2Right_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}


void sub_8094390(struct Sprite *sprite, u16 duration)
{
    sprite->data[2] = 1;
    sprite->data[3] = duration;
}

bool8 MovementAction_Delay_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (-- sprite->data[3] == 0)
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_Delay1_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094390(sprite, 1);
    return MovementAction_Delay_Step1(eventObject, sprite);
}

bool8 MovementAction_Delay2_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094390(sprite, 2);
    return MovementAction_Delay_Step1(eventObject, sprite);
}

bool8 MovementAction_Delay4_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094390(sprite, 4);
    return MovementAction_Delay_Step1(eventObject, sprite);
}

bool8 MovementAction_Delay8_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094390(sprite, 8);
    return MovementAction_Delay_Step1(eventObject, sprite);
}

bool8 MovementAction_Delay16_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094390(sprite, 16);
    return MovementAction_Delay_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkFastDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_SOUTH, 1);
    return MovementAction_WalkFastDown_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkFastDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkFastUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_NORTH, 1);
    return MovementAction_WalkFastUp_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkFastUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkFastLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_WEST, 1);
    return MovementAction_WalkFastLeft_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkFastLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkFastRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_EAST, 1);
    return MovementAction_WalkFastRight_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkFastRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}


void sub_8094554(struct EventObject *eventObject, struct Sprite *sprite, u8 direction, u8 animNum, u16 duration)
{
    SetEventObjectDirection(eventObject, direction);
    npc_apply_anim_looping(eventObject, sprite, animNum);
    sprite->animPaused = FALSE;
    sprite->data[2] = 1;
    sprite->data[3] = duration;
}

bool8 MovementAction_WalkInPlace_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (-- sprite->data[3] == 0)
    {
        sprite->data[2] = 2;
        sprite->animPaused = TRUE;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkInPlaceSlow_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sprite->data[3] & 1)
    {
        sprite->animDelayCounter++;
    }
    return MovementAction_WalkInPlace_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkInPlaceSlowDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094554(eventObject, sprite, DIR_SOUTH, GetMoveDirectionAnimNum(DIR_SOUTH), 32);
    return MovementAction_WalkInPlaceSlow_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkInPlaceSlowUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094554(eventObject, sprite, DIR_NORTH, GetMoveDirectionAnimNum(DIR_NORTH), 32);
    return MovementAction_WalkInPlaceSlow_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkInPlaceSlowLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094554(eventObject, sprite, DIR_WEST, GetMoveDirectionAnimNum(DIR_WEST), 32);
    return MovementAction_WalkInPlaceSlow_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkInPlaceSlowRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094554(eventObject, sprite, DIR_EAST, GetMoveDirectionAnimNum(DIR_EAST), 32);
    return MovementAction_WalkInPlaceSlow_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkInPlaceNormalDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094554(eventObject, sprite, DIR_SOUTH, GetMoveDirectionAnimNum(DIR_SOUTH), 16);
    return MovementAction_WalkInPlace_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkInPlaceNormalUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094554(eventObject, sprite, DIR_NORTH, GetMoveDirectionAnimNum(DIR_NORTH), 16);
    return MovementAction_WalkInPlace_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkInPlaceNormalLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094554(eventObject, sprite, DIR_WEST, GetMoveDirectionAnimNum(DIR_WEST), 16);
    return MovementAction_WalkInPlace_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkInPlaceNormalRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094554(eventObject, sprite, DIR_EAST, GetMoveDirectionAnimNum(DIR_EAST), 16);
    return MovementAction_WalkInPlace_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkInPlaceFastDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094554(eventObject, sprite, DIR_SOUTH, GetMoveDirectionFastAnimNum(DIR_SOUTH), 8);
    return MovementAction_WalkInPlace_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkInPlaceFastUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094554(eventObject, sprite, DIR_NORTH, GetMoveDirectionFastAnimNum(DIR_NORTH), 8);
    return MovementAction_WalkInPlace_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkInPlaceFastLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094554(eventObject, sprite, DIR_WEST, GetMoveDirectionFastAnimNum(DIR_WEST), 8);
    return MovementAction_WalkInPlace_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkInPlaceFastRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094554(eventObject, sprite, DIR_EAST, GetMoveDirectionFastAnimNum(DIR_EAST), 8);
    return MovementAction_WalkInPlace_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkInPlaceFastestDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094554(eventObject, sprite, DIR_SOUTH, GetMoveDirectionFasterAnimNum(DIR_SOUTH), 4);
    return MovementAction_WalkInPlace_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkInPlaceFastestUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094554(eventObject, sprite, DIR_NORTH, GetMoveDirectionFasterAnimNum(DIR_NORTH), 4);
    return MovementAction_WalkInPlace_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkInPlaceFastestLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094554(eventObject, sprite, DIR_WEST, GetMoveDirectionFasterAnimNum(DIR_WEST), 4);
    return MovementAction_WalkInPlace_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkInPlaceFastestRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094554(eventObject, sprite, DIR_EAST, GetMoveDirectionFasterAnimNum(DIR_EAST), 4);
    return MovementAction_WalkInPlace_Step1(eventObject, sprite);
}

bool8 MovementAction_RideWaterCurrentDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_SOUTH, 2);
    return MovementAction_RideWaterCurrentDown_Step1(eventObject, sprite);
}

bool8 MovementAction_RideWaterCurrentDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_RideWaterCurrentUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_NORTH, 2);
    return MovementAction_RideWaterCurrentUp_Step1(eventObject, sprite);
}

bool8 MovementAction_RideWaterCurrentUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_RideWaterCurrentLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_WEST, 2);
    return MovementAction_RideWaterCurrentLeft_Step1(eventObject, sprite);
}

bool8 MovementAction_RideWaterCurrentLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_RideWaterCurrentRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_EAST, 2);
    return MovementAction_RideWaterCurrentRight_Step1(eventObject, sprite);
}

bool8 MovementAction_RideWaterCurrentRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkFastestDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_SOUTH, 3);
    return MovementAction_WalkFastestDown_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkFastestDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkFastestUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_NORTH, 3);
    return MovementAction_WalkFastestUp_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkFastestUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkFastestLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_WEST, 3);
    return MovementAction_WalkFastestLeft_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkFastestLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkFastestRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_EAST, 3);
    return MovementAction_WalkFastestRight_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkFastestRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_SlideDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_SOUTH, 4);
    return MovementAction_SlideDown_Step1(eventObject, sprite);
}

bool8 MovementAction_SlideDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_SlideUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_NORTH, 4);
    return MovementAction_SlideUp_Step1(eventObject, sprite);
}

bool8 MovementAction_SlideUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_SlideLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_WEST, 4);
    return MovementAction_SlideLeft_Step1(eventObject, sprite);
}

bool8 MovementAction_SlideLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_SlideRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_EAST, 4);
    return MovementAction_SlideRight_Step1(eventObject, sprite);
}

bool8 MovementAction_SlideRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_PlayerRunDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    StartRunningAnim(eventObject, sprite, DIR_SOUTH);
    return MovementAction_PlayerRunDown_Step1(eventObject, sprite);
}

bool8 MovementAction_PlayerRunDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_PlayerRunUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    StartRunningAnim(eventObject, sprite, DIR_NORTH);
    return MovementAction_PlayerRunUp_Step1(eventObject, sprite);
}

bool8 MovementAction_PlayerRunUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_PlayerRunLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    StartRunningAnim(eventObject, sprite, DIR_WEST);
    return MovementAction_PlayerRunLeft_Step1(eventObject, sprite);
}

bool8 MovementAction_PlayerRunLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_PlayerRunRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    StartRunningAnim(eventObject, sprite, DIR_EAST);
    return MovementAction_PlayerRunRight_Step1(eventObject, sprite);
}

bool8 MovementAction_PlayerRunRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

void StartSpriteAnimInDirection(struct EventObject *eventObject, struct Sprite *sprite, u8 direction, u8 animNum)
{
    SetAndStartSpriteAnim(sprite, animNum, 0);
    SetEventObjectDirection(eventObject, direction);
    sprite->data[2] = 1;
}

bool8 MovementAction_StartAnimInDirection_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(eventObject, sprite, eventObject->movementDirection, sprite->animNum);
    return FALSE;
}

bool8 MovementAction_WaitSpriteAnim(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (SpriteAnimEnded(sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

void sub_8094DE4(struct EventObject *eventObject, struct Sprite *sprite, u8 direction)
{
    sub_8093FC4(eventObject, sprite, direction, 1, 0);
    StartSpriteAnim(sprite, GetJumpSpecialDirectionAnimNum(direction));
}

bool8 MovementAction_JumpSpecialDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094DE4(eventObject, sprite, DIR_SOUTH);
    return MovementAction_JumpSpecialDown_Step1(eventObject, sprite);
}

bool8 MovementAction_JumpSpecialDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941C8(eventObject, sprite))
    {
        sprite->data[2] = 2;
        eventObject->landingJump = FALSE;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpSpecialUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094DE4(eventObject, sprite, DIR_NORTH);
    return MovementAction_JumpSpecialUp_Step1(eventObject, sprite);
}

bool8 MovementAction_JumpSpecialUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941C8(eventObject, sprite))
    {
        sprite->data[2] = 2;
        eventObject->landingJump = FALSE;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpSpecialLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094DE4(eventObject, sprite, DIR_WEST);
    return MovementAction_JumpSpecialLeft_Step1(eventObject, sprite);
}

bool8 MovementAction_JumpSpecialLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941C8(eventObject, sprite))
    {
        sprite->data[2] = 2;
        eventObject->landingJump = FALSE;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpSpecialRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094DE4(eventObject, sprite, DIR_EAST);
    return MovementAction_JumpSpecialRight_Step1(eventObject, sprite);
}

bool8 MovementAction_JumpSpecialRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941C8(eventObject, sprite))
    {
        sprite->data[2] = 2;
        eventObject->landingJump = FALSE;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_FacePlayer_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 playerObjectId;

    if (!TryGetEventObjectIdByLocalIdAndMap(EVENT_OBJ_ID_PLAYER, 0, 0, &playerObjectId))
    {
        FaceDirection(eventObject, sprite, GetDirectionToFace(eventObject->currentCoords.x, eventObject->currentCoords.y, gEventObjects[playerObjectId].currentCoords.x, gEventObjects[playerObjectId].currentCoords.y));
    }
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_FaceAwayPlayer_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    u8 playerObjectId;

    if (!TryGetEventObjectIdByLocalIdAndMap(EVENT_OBJ_ID_PLAYER, 0, 0, &playerObjectId))
    {
        FaceDirection(eventObject, sprite, GetOppositeDirection(GetDirectionToFace(eventObject->currentCoords.x, eventObject->currentCoords.y, gEventObjects[playerObjectId].currentCoords.x, gEventObjects[playerObjectId].currentCoords.y)));
    }
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_LockFacingDirection_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->facingDirectionLocked = TRUE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_UnlockFacingDirection_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->facingDirectionLocked = FALSE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_JumpDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    maybe_shadow_1(eventObject, sprite, DIR_SOUTH, 1, 2);
    return MovementAction_JumpDown_Step1(eventObject, sprite);
}

bool8 MovementAction_JumpDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    maybe_shadow_1(eventObject, sprite, DIR_NORTH, 1, 2);
    return MovementAction_JumpUp_Step1(eventObject, sprite);
}

bool8 MovementAction_JumpUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    maybe_shadow_1(eventObject, sprite, DIR_WEST, 1, 2);
    return MovementAction_JumpLeft_Step1(eventObject, sprite);
}

bool8 MovementAction_JumpLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    maybe_shadow_1(eventObject, sprite, DIR_EAST, 1, 2);
    return MovementAction_JumpRight_Step1(eventObject, sprite);
}

bool8 MovementAction_JumpRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    maybe_shadow_1(eventObject, sprite, DIR_SOUTH, 0, 0);
    return MovementAction_JumpInPlaceDown_Step1(eventObject, sprite);
}

bool8 MovementAction_JumpInPlaceDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    maybe_shadow_1(eventObject, sprite, DIR_NORTH, 0, 0);
    return MovementAction_JumpInPlaceUp_Step1(eventObject, sprite);
}

bool8 MovementAction_JumpInPlaceUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    maybe_shadow_1(eventObject, sprite, DIR_WEST, 0, 0);
    return MovementAction_JumpInPlaceLeft_Step1(eventObject, sprite);
}

bool8 MovementAction_JumpInPlaceLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    maybe_shadow_1(eventObject, sprite, DIR_EAST, 0, 0);
    return MovementAction_JumpInPlaceRight_Step1(eventObject, sprite);
}

bool8 MovementAction_JumpInPlaceRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceDownUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    maybe_shadow_1(eventObject, sprite, DIR_SOUTH, 0, 2);
    return MovementAction_JumpInPlaceDownUp_Step1(eventObject, sprite);
}

bool8 MovementAction_JumpInPlaceDownUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941E0(eventObject, sprite))
    {
        eventObject->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceUpDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    maybe_shadow_1(eventObject, sprite, DIR_NORTH, 0, 2);
    return MovementAction_JumpInPlaceUpDown_Step1(eventObject, sprite);
}

bool8 MovementAction_JumpInPlaceUpDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941E0(eventObject, sprite))
    {
        eventObject->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceLeftRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    maybe_shadow_1(eventObject, sprite, DIR_WEST, 0, 2);
    return MovementAction_JumpInPlaceLeftRight_Step1(eventObject, sprite);
}

bool8 MovementAction_JumpInPlaceLeftRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941E0(eventObject, sprite))
    {
        eventObject->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceRightLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    maybe_shadow_1(eventObject, sprite, DIR_EAST, 0, 2);
    return MovementAction_JumpInPlaceRightLeft_Step1(eventObject, sprite);
}

bool8 MovementAction_JumpInPlaceRightLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941E0(eventObject, sprite))
    {
        eventObject->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_FaceOriginalDirection_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    FaceDirection(eventObject, sprite, gInitialMovementTypeFacingDirections[eventObject->movementType]);
    return TRUE;
}

bool8 MovementAction_NurseJoyBowDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(eventObject, sprite, DIR_SOUTH, 0x14);
    return FALSE;
}

bool8 MovementAction_EnableJumpLandingGroundEffect_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->disableJumpLandingGroundEffect = FALSE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_DisableJumpLandingGroundEffect_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->disableJumpLandingGroundEffect = TRUE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_DisableAnimation_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->inanimate = TRUE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_RestoreAnimation_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->inanimate = GetEventObjectGraphicsInfo(eventObject->graphicsId)->inanimate;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_SetInvisible_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->invisible = TRUE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_SetVisible_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->invisible = FALSE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_EmoteExclamationMark_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectGetLocalIdAndMap(eventObject, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    FieldEffectStart(FLDEFF_EXCLAMATION_MARK_ICON);
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_EmoteQuestionMark_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectGetLocalIdAndMap(eventObject, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    FieldEffectStart(FLDEFF_QUESTION_MARK_ICON);
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_EmoteHeart_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    EventObjectGetLocalIdAndMap(eventObject, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    FieldEffectStart(FLDEFF_HEART_ICON);
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_RevealTrainer_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (eventObject->movementType == MOVEMENT_TYPE_HIDDEN)
    {
        sub_80B4578(eventObject);
        return FALSE;
    }
    if (eventObject->movementType != MOVEMENT_TYPE_TREE_DISGUISE && eventObject->movementType != MOVEMENT_TYPE_MOUNTAIN_DISGUISE)
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    sub_8155D78(eventObject);
    sprite->data[2] = 1;
    return MovementAction_RevealTrainer_Step1(eventObject, sprite);
}

bool8 MovementAction_RevealTrainer_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_8155DA0(eventObject))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_RockSmashBreak_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    SetAndStartSpriteAnim(sprite, 1, 0);
    sprite->data[2] = 1;
    return FALSE;
}

bool8 MovementAction_RockSmashBreak_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (SpriteAnimEnded(sprite))
    {
        SetMovementDelay(sprite, 32);
        sprite->data[2] = 2;
    }
    return FALSE;
}

bool8 MovementAction_RockSmashBreak_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->invisible ^= TRUE;
    if (WaitForMovementDelay(sprite))
    {
        eventObject->invisible = TRUE;
        sprite->data[2] = 3;
    }
    return FALSE;
}

bool8 MovementAction_CutTree_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    SetAndStartSpriteAnim(sprite, 1, 0);
    sprite->data[2] = 1;
    return FALSE;
}

bool8 MovementAction_CutTree_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (SpriteAnimEnded(sprite))
    {
        SetMovementDelay(sprite, 32);
        sprite->data[2] = 2;
    }
    return FALSE;
}

bool8 MovementAction_CutTree_Step2(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->invisible ^= TRUE;
    if (WaitForMovementDelay(sprite))
    {
        eventObject->invisible = TRUE;
        sprite->data[2] = 3;
    }
    return FALSE;
}

bool8 MovementAction_SetFixedPriority_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->fixedPriority = TRUE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_ClearFixedPriority_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->fixedPriority = FALSE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_InitAffineAnim_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sprite->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
    InitSpriteAffineAnim(sprite);
    sprite->affineAnimPaused = TRUE;
    sprite->subspriteMode = 0;
    return TRUE;
}

bool8 MovementAction_ClearAffineAnim_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    FreeOamMatrix(sprite->oam.matrixNum);
    sprite->oam.affineMode = ST_OAM_AFFINE_OFF;
    CalcCenterToCornerVec(sprite, sprite->oam.shape, sprite->oam.size, sprite->oam.affineMode);
    return TRUE;
}

bool8 MovementAction_Unknown1_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->unk3_3 = TRUE;
    return TRUE;
}

bool8 MovementAction_Unknown2_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    eventObject->unk3_3 = FALSE;
    return TRUE;
}

bool8 MovementAction_WalkDownStartAffine_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8093B60(eventObject, sprite, DIR_SOUTH);
    sprite->affineAnimPaused = FALSE;
    StartSpriteAffineAnimIfDifferent(sprite, 0);
    return MovementAction_WalkDownStartAffine_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkDownStartAffine_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (an_walk_any_2(eventObject, sprite))
    {
        sprite->affineAnimPaused = TRUE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkDownAffine_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8093B60(eventObject, sprite, DIR_SOUTH);
    sprite->affineAnimPaused = FALSE;
    ChangeSpriteAffineAnimIfDifferent(sprite, 1);
    return MovementAction_WalkDownAffine_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkDownAffine_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (an_walk_any_2(eventObject, sprite))
    {
        sprite->affineAnimPaused = TRUE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkLeftAffine_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_WEST, 1);
    sprite->affineAnimPaused = FALSE;
    ChangeSpriteAffineAnimIfDifferent(sprite, 2);
    return MovementAction_WalkLeftAffine_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkLeftAffine_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->affineAnimPaused = TRUE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkRightAffine_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    do_go_anim(eventObject, sprite, DIR_EAST, 1);
    sprite->affineAnimPaused = FALSE;
    ChangeSpriteAffineAnimIfDifferent(sprite, 3);
    return MovementAction_WalkRightAffine_Step1(eventObject, sprite);
}

bool8 MovementAction_WalkRightAffine_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->affineAnimPaused = TRUE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

static void sub_80958C0(struct EventObject *eventObject, struct Sprite *sprite, u8 direction)
{
    SetEventObjectDirection(eventObject, direction);
    ShiftStillEventObjectCoords(eventObject);
    obj_npc_animation_step(eventObject, sprite, GetAcroWheeliePedalDirectionAnimNum(direction));
    sprite->animPaused = TRUE;
    sprite->data[2] = 1;
}

bool8 MovementAction_AcroWheelieFaceDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_80958C0(eventObject, sprite, DIR_SOUTH);
    return TRUE;
}

bool8 MovementAction_AcroWheelieFaceUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_80958C0(eventObject, sprite, DIR_NORTH);
    return TRUE;
}

bool8 MovementAction_AcroWheelieFaceLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_80958C0(eventObject, sprite, DIR_WEST);
    return TRUE;
}

bool8 MovementAction_AcroWheelieFaceRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_80958C0(eventObject, sprite, DIR_EAST);
    return TRUE;
}

bool8 MovementAction_AcroPopWheelieDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(eventObject, sprite, DIR_SOUTH, GetAcroWheelieDirectionAnimNum(DIR_SOUTH));
    return FALSE;
}

bool8 MovementAction_AcroPopWheelieUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(eventObject, sprite, DIR_NORTH, GetAcroWheelieDirectionAnimNum(DIR_NORTH));
    return FALSE;
}

bool8 MovementAction_AcroPopWheelieLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(eventObject, sprite, DIR_WEST, GetAcroWheelieDirectionAnimNum(DIR_WEST));
    return FALSE;
}

bool8 MovementAction_AcroPopWheelieRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(eventObject, sprite, DIR_EAST, GetAcroWheelieDirectionAnimNum(DIR_EAST));
    return FALSE;
}

bool8 MovementAction_AcroEndWheelieFaceDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(eventObject, sprite, DIR_SOUTH, GetAcroEndWheelieDirectionAnimNum(DIR_SOUTH));
    return FALSE;
}

bool8 MovementAction_AcroEndWheelieFaceUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(eventObject, sprite, DIR_NORTH, GetAcroEndWheelieDirectionAnimNum(DIR_NORTH));
    return FALSE;
}

bool8 MovementAction_AcroEndWheelieFaceLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(eventObject, sprite, DIR_WEST, GetAcroEndWheelieDirectionAnimNum(DIR_WEST));
    return FALSE;
}

bool8 MovementAction_AcroEndWheelieFaceRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(eventObject, sprite, DIR_EAST, GetAcroEndWheelieDirectionAnimNum(DIR_EAST));
    return FALSE;
}

bool8 MovementAction_UnusedAcroActionDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(eventObject, sprite, DIR_SOUTH, GetAcroUnusedActionDirectionAnimNum(DIR_SOUTH));
    return FALSE;
}

bool8 MovementAction_UnusedAcroActionUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(eventObject, sprite, DIR_NORTH, GetAcroUnusedActionDirectionAnimNum(DIR_NORTH));
    return FALSE;
}

bool8 MovementAction_UnusedAcroActionLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(eventObject, sprite, DIR_WEST, GetAcroUnusedActionDirectionAnimNum(DIR_WEST));
    return FALSE;
}

bool8 MovementAction_UnusedAcroActionRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(eventObject, sprite, DIR_EAST, GetAcroUnusedActionDirectionAnimNum(DIR_EAST));
    return FALSE;
}

void sub_8095AF0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8097750(sprite);
    sprite->animPaused = FALSE;
}

bool8 sub_8095B0C(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_8097758(sprite))
    {
        ShiftStillEventObjectCoords(eventObject);
        eventObject->triggerGroundEffectsOnStop = TRUE;
        sprite->animPaused = TRUE;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_Figure8_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8095AF0(eventObject, sprite);
    sprite->data[2] = 1;
    return MovementAction_Figure8_Step1(eventObject, sprite);
}

bool8 MovementAction_Figure8_Step1(struct EventObject *eventObject, struct Sprite *sprite)
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
    StartSpriteAnimIfDifferent(sprite, GetAcroWheelieDirectionAnimNum(direction));
    DoShadowFieldEffect(eventObject);
}

bool8 MovementAction_AcroWheelieHopFaceDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8095B84(eventObject, sprite, DIR_SOUTH, 0, 1);
    return MovementAction_AcroWheelieHopFaceDown_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroWheelieHopFaceDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieHopFaceUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8095B84(eventObject, sprite, DIR_NORTH, 0, 1);
    return MovementAction_AcroWheelieHopFaceUp_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroWheelieHopFaceUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieHopFaceLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8095B84(eventObject, sprite, DIR_WEST,  0, 1);
    return MovementAction_AcroWheelieHopFaceLeft_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroWheelieHopFaceLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieHopFaceRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8095B84(eventObject, sprite, DIR_EAST,  0, 1);
    return MovementAction_AcroWheelieHopFaceRight_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroWheelieHopFaceRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieHopDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8095B84(eventObject, sprite, DIR_SOUTH, 1, 1);
    return MovementAction_AcroWheelieHopDown_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroWheelieHopDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieHopUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8095B84(eventObject, sprite, DIR_NORTH, 1, 1);
    return MovementAction_AcroWheelieHopUp_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroWheelieHopUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieHopLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8095B84(eventObject, sprite, DIR_WEST,  1, 1);
    return MovementAction_AcroWheelieHopLeft_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroWheelieHopLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieHopRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8095B84(eventObject, sprite, DIR_EAST,  1, 1);
    return MovementAction_AcroWheelieHopRight_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroWheelieHopRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieJumpDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8095B84(eventObject, sprite, DIR_SOUTH, 2, 0);
    return MovementAction_AcroWheelieJumpDown_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroWheelieJumpDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieJumpUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8095B84(eventObject, sprite, DIR_NORTH, 2, 0);
    return MovementAction_AcroWheelieJumpUp_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroWheelieJumpUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieJumpLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8095B84(eventObject, sprite, DIR_WEST,  2, 0);
    return MovementAction_AcroWheelieJumpLeft_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroWheelieJumpLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieJumpRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8095B84(eventObject, sprite, DIR_EAST,  2, 0);
    return MovementAction_AcroWheelieJumpRight_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroWheelieJumpRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sub_80941B0(eventObject, sprite))
    {
        eventObject->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieInPlaceDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094554(eventObject, sprite, DIR_SOUTH, GetAcroWheeliePedalDirectionAnimNum(DIR_SOUTH), 8);
    return MovementAction_WalkInPlace_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroWheelieInPlaceUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094554(eventObject, sprite, DIR_NORTH, GetAcroWheeliePedalDirectionAnimNum(DIR_NORTH), 8);
    return MovementAction_WalkInPlace_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroWheelieInPlaceLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094554(eventObject, sprite, DIR_WEST, GetAcroWheeliePedalDirectionAnimNum(DIR_WEST), 8);
    return MovementAction_WalkInPlace_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroWheelieInPlaceRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8094554(eventObject, sprite, DIR_EAST, GetAcroWheeliePedalDirectionAnimNum(DIR_EAST), 8);
    return MovementAction_WalkInPlace_Step1(eventObject, sprite);
}

void sub_80960C8(struct EventObject *eventObject, struct Sprite *sprite, u8 direction, u8 speed)
{
    npc_apply_direction(eventObject, sprite, direction, speed);
    StartSpriteAnim(sprite, GetAcroWheelieDirectionAnimNum(eventObject->facingDirection));
    SeekSpriteAnim(sprite, 0);
}

bool8 MovementAction_AcroPopWheelieMoveDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_80960C8(eventObject, sprite, DIR_SOUTH, 1);
    return MovementAction_AcroPopWheelieMoveDown_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroPopWheelieMoveDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroPopWheelieMoveUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_80960C8(eventObject, sprite, DIR_NORTH, 1);
    return MovementAction_AcroPopWheelieMoveUp_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroPopWheelieMoveUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroPopWheelieMoveLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_80960C8(eventObject, sprite, DIR_WEST,  1);
    return MovementAction_AcroPopWheelieMoveLeft_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroPopWheelieMoveLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroPopWheelieMoveRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_80960C8(eventObject, sprite, DIR_EAST,  1);
    return MovementAction_AcroPopWheelieMoveRight_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroPopWheelieMoveRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

void sub_8096200(struct EventObject *eventObject, struct Sprite *sprite, u8 direction, u8 speed)
{
    npc_apply_direction(eventObject, sprite, direction, speed);
    npc_apply_anim_looping(eventObject, sprite, GetAcroWheeliePedalDirectionAnimNum(eventObject->facingDirection));
}

bool8 MovementAction_AcroWheelieMoveDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8096200(eventObject, sprite, DIR_SOUTH, 1);
    return MovementAction_AcroWheelieMoveDown_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroWheelieMoveDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieMoveUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8096200(eventObject, sprite, DIR_NORTH, 1);
    return MovementAction_AcroWheelieMoveUp_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroWheelieMoveUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieMoveLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8096200(eventObject, sprite, DIR_WEST,  1);
    return MovementAction_AcroWheelieMoveLeft_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroWheelieMoveLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieMoveRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8096200(eventObject, sprite, DIR_EAST, 1);
    return MovementAction_AcroWheelieMoveRight_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroWheelieMoveRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

void sub_8096330(struct EventObject *eventObject, struct Sprite *sprite, u8 direction, u8 speed)
{
    npc_apply_direction(eventObject, sprite, direction, speed);
    StartSpriteAnim(sprite, GetAcroEndWheelieDirectionAnimNum(eventObject->facingDirection));
    SeekSpriteAnim(sprite, 0);
}

bool8 MovementAction_AcroEndWheelieMoveDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8096330(eventObject, sprite, DIR_SOUTH, 1);
    return MovementAction_AcroEndWheelieMoveDown_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroEndWheelieMoveDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroEndWheelieMoveUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8096330(eventObject, sprite, DIR_NORTH, 1);
    return MovementAction_AcroEndWheelieMoveUp_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroEndWheelieMoveUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroEndWheelieMoveLeft_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8096330(eventObject, sprite, DIR_WEST, 1);
    return MovementAction_AcroEndWheelieMoveLeft_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroEndWheelieMoveLeft_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroEndWheelieMoveRight_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8096330(eventObject, sprite, DIR_EAST, 1);
    return MovementAction_AcroEndWheelieMoveRight_Step1(eventObject, sprite);
}

bool8 MovementAction_AcroEndWheelieMoveRight_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(eventObject, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_Levitate_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    CreateLevitateMovementTask(eventObject);
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_StopLevitate_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    DestroyExtraMovementTask(eventObject->warpArrowSpriteId);
    sprite->pos2.y = 0;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_DestroyExtraTaskIfAtTop_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (sprite->pos2.y == 0)
    {
        DestroyExtraMovementTask(eventObject->warpArrowSpriteId);
        sprite->data[2] = 1;
        return TRUE;
    }
    return FALSE;
}

u8 MovementAction_Finish(struct EventObject *eventObject, struct Sprite *sprite)
{
    return TRUE;
}

bool8 MovementAction_PauseSpriteAnim(struct EventObject *eventObject, struct Sprite *sprite)
{
    sprite->animPaused = TRUE;
    return TRUE;
}

static void UpdateEventObjectSpriteAnimPause(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (eventObject->disableAnim)
    {
        sprite->animPaused = TRUE;
    }
}

static void TryEnableEventObjectAnim(struct EventObject *eventObject, struct Sprite *sprite)
{
    if (eventObject->enableAnim)
    {
        sprite->animPaused = FALSE;
        eventObject->disableAnim = FALSE;
        eventObject->enableAnim = FALSE;
    }
}

static void UpdateEventObjectVisibility(struct EventObject *eventObject, struct Sprite *sprite)
{
    sub_8096530(eventObject, sprite);
    UpdateEventObjSpriteVisibility(eventObject, sprite);
}

static void sub_8096530(struct EventObject *eventObject, struct Sprite *sprite)
{
    u16 x, y;
    u16 x2, y2;
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

static void UpdateEventObjSpriteVisibility(struct EventObject *eventObject, struct Sprite *sprite)
{
    sprite->invisible = FALSE;
    if (eventObject->invisible || eventObject->offScreen)
    {
        sprite->invisible = TRUE;
    }
}

static void GetAllGroundEffectFlags_OnSpawn(struct EventObject *eventObj, u32 *flags)
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

static void GetAllGroundEffectFlags_OnFinishStep(struct EventObject *eventObj, u32 *flags)
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
             || MetatileBehavior_IsFootprints(eventObj->previousMetatileBehavior))
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

static void SetEventObjectSpriteOamTableForLongGrass(struct EventObject *eventObj, struct Sprite *sprite)
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

void UpdateEventObjectZCoordAndPriority(struct EventObject *eventObj, struct Sprite *sprite)
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
    SetUpReflection(eventObj, sprite, FALSE);
}

void GroundEffect_IceReflection(struct EventObject *eventObj, struct Sprite *sprite)
{
    SetUpReflection(eventObj, sprite, TRUE);
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

    spriteId = FindTallGrassFieldEffectSpriteId(
        eventObj->localId,
        eventObj->mapNum,
        eventObj->mapGroup,
        eventObj->currentCoords.x,
        eventObj->currentCoords.y);

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

static void DoFlaggedGroundEffects(struct EventObject *eventObj, struct Sprite *sprite, u32 flags)
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
        UpdateEventObjectZCoordAndPriority(eventObj, sprite);
        GetAllGroundEffectFlags_OnSpawn(eventObj, &flags);
        SetEventObjectSpriteOamTableForLongGrass(eventObj, sprite);
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
        UpdateEventObjectZCoordAndPriority(eventObj, sprite);
        GetAllGroundEffectFlags_OnBeginStep(eventObj, &flags);
        SetEventObjectSpriteOamTableForLongGrass(eventObj, sprite);
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
        UpdateEventObjectZCoordAndPriority(eventObj, sprite);
        GetAllGroundEffectFlags_OnFinishStep(eventObj, &flags);
        SetEventObjectSpriteOamTableForLongGrass(eventObj, sprite);
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

void FreezeEventObjectsExceptOne(u8 eventObjectId)
{
    u8 i;
    for (i = 0; i < EVENT_OBJECTS_COUNT; i++)
        if (i != eventObjectId && gEventObjects[i].active && i != gPlayerAvatar.eventObjectId)
            FreezeEventObject(&gEventObjects[i]);
}

void UnfreezeEventObject(struct EventObject *eventObject)
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
            UnfreezeEventObject(&gEventObjects[i]);
}

static void Step1(struct Sprite *sprite, u8 dir)
{
    sprite->pos1.x += sDirectionToVectors[dir].x;
    sprite->pos1.y += sDirectionToVectors[dir].y;
}

static void Step2(struct Sprite *sprite, u8 dir)
{
    sprite->pos1.x += 2 * (u16) sDirectionToVectors[dir].x;
    sprite->pos1.y += 2 * (u16) sDirectionToVectors[dir].y;
}

static void Step3(struct Sprite *sprite, u8 dir)
{
    sprite->pos1.x += 2 * (u16) sDirectionToVectors[dir].x + (u16) sDirectionToVectors[dir].x;
    sprite->pos1.y += 2 * (u16) sDirectionToVectors[dir].y + (u16) sDirectionToVectors[dir].y;
}

static void Step4(struct Sprite *sprite, u8 dir)
{
    sprite->pos1.x += 4 * (u16) sDirectionToVectors[dir].x;
    sprite->pos1.y += 4 * (u16) sDirectionToVectors[dir].y;
}

static void Step8(struct Sprite *sprite, u8 dir)
{
    sprite->pos1.x += 8 * (u16) sDirectionToVectors[dir].x;
    sprite->pos1.y += 8 * (u16) sDirectionToVectors[dir].y;
}

static void oamt_npc_ministep_reset(struct Sprite *sprite, u8 direction, u8 a3)
{
    sprite->data[3] = direction;
    sprite->data[4] = a3;
    sprite->data[5] = 0;
}

typedef void (*SpriteStepFunc)(struct Sprite *sprite, u8 direction);

static const SpriteStepFunc gUnknown_0850E6C4[] = {
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
};

static const SpriteStepFunc gUnknown_0850E704[] = {
    Step2,
    Step2,
    Step2,
    Step2,
    Step2,
    Step2,
    Step2,
    Step2,
};

static const SpriteStepFunc gUnknown_0850E724[] = {
    Step2,
    Step3,
    Step3,
    Step2,
    Step3,
    Step3,
};

static const SpriteStepFunc gUnknown_0850E73C[] = {
    Step4,
    Step4,
    Step4,
    Step4,
};

static const SpriteStepFunc gUnknown_0850E74C[] = {
    Step8,
    Step8,
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

void sub_80976DC(struct Sprite *sprite, u8 direction)
{
    sprite->data[3] = direction;
    sprite->data[4] = 0;
    sprite->data[5] = 0;
}

bool8 sub_80976EC(struct Sprite *sprite)
{
    if (!(sprite->data[4] & 1))
    {
        Step1(sprite, sprite->data[3]);
        sprite->data[5]++;
    }

    sprite->data[4]++;

    if (sprite->data[5] > 15)
        return TRUE;
    else
        return FALSE;
}

static const s8 gUnknown_0850E772[] = {
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

static const s8 gUnknown_0850E7BA[] = {
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
        Step1(sprite, sprite->data[3]);

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
        Step1(sprite, sprite->data[3]);

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

static void SetMovementDelay(struct Sprite *sprite, s16 timer)
{
    sprite->data[3] = timer;
}

static bool8 WaitForMovementDelay(struct Sprite *sprite)
{
    sprite->data[3]--;

    if (sprite->data[3] == 0)
        return TRUE;
    else
        return FALSE;
}

void SetAndStartSpriteAnim(struct Sprite *sprite, u8 animNum, u8 animCmdIndex)
{
    sprite->animNum = animNum;
    sprite->animPaused = FALSE;
    SeekSpriteAnim(sprite, animCmdIndex);
}

bool8 SpriteAnimEnded(struct Sprite *sprite)
{
    if (sprite->animEnded)
        return TRUE;
    else
        return FALSE;
}

void UpdateEventObjectSpriteVisibility(struct Sprite *sprite, bool8 invisible)
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
        sprite->invisible = TRUE;
    if ((s16)y > 175 || y2 < -16)
        sprite->invisible = TRUE;
}

static void UpdateEventObjectSpriteSubpriorityAndVisibility(struct Sprite *sprite)
{
    sub_8097D68(sprite);
    SetObjectSubpriorityByZCoord(sprite->data[1], sprite, 1);
    UpdateEventObjectSpriteVisibility(sprite, sprite->data[2]);
}

void sub_8097AF0(void)
{
    int i;

    for(i = 0; i < MAX_SPRITES; i++)
    {
        struct Sprite *sprite = &gSprites[i];
        if(sprite->inUse && sprite->callback == UpdateEventObjectSpriteSubpriorityAndVisibility)
            DestroySprite(sprite);
    }
}

int sub_8097B2C(u8 var) // this should return a u8, because all that call this shifts to u8, but it wont match because it doesnt shift u8 at the end.
{
    int i;

    for(i = 0; i < MAX_SPRITES; i++)
    {
        struct Sprite *sprite = &gSprites[i];
        if(sprite->inUse && sprite->callback == UpdateEventObjectSpriteSubpriorityAndVisibility && (u8)sprite->data[0] == var)
            return i;
    }
    return MAX_SPRITES;
}

void sub_8097B78(u8 var1, u8 var2)
{
    u8 spriteId = sub_8097B2C(var1);

    if(spriteId != MAX_SPRITES)
        StartSpriteAnim(&gSprites[spriteId], GetFaceDirectionAnimNum(var2));
}

void sub_8097BB4(u8 var1, u8 graphicsId)
{
    int spriteId = sub_8097B2C(var1);

    if(spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        const struct EventObjectGraphicsInfo *graphicsInfo = GetEventObjectGraphicsInfo(graphicsId);
        u16 tileNum = sprite->oam.tileNum;

        sprite->oam = *graphicsInfo->oam;
        sprite->oam.tileNum = tileNum;
        sprite->oam.paletteNum = graphicsInfo->paletteSlot;
        sprite->images = graphicsInfo->images;

        if(graphicsInfo->subspriteTables == NULL)
        {
            sprite->subspriteTables = NULL;
            sprite->subspriteTableNum = 0;
            sprite->subspriteMode = 0;
        }
        else
        {
            SetSubspriteTables(sprite, graphicsInfo->subspriteTables);
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
    const struct EventObjectGraphicsInfo *graphicsInfo = GetEventObjectGraphicsInfo(eventObject->graphicsId);
    gFieldEffectArguments[0] = sprite->pos1.x;
    gFieldEffectArguments[1] = sprite->pos1.y + (graphicsInfo->height >> 1) - 2;
    gFieldEffectArguments[2] = 151;
    gFieldEffectArguments[3] = 3;
    FieldEffectStart(FLDEFF_RIPPLE);
}

u8 (*const gMovementActionFuncs_StoreAndLockAnim[])(struct EventObject *, struct Sprite *) = {
    MovementAction_StoreAndLockAnim_Step0,
    MovementAction_Finish,
};

u8 (*const gMovementActionFuncs_FreeAndUnlockAnim[])(struct EventObject *, struct Sprite *) = {
    MovementAction_FreeAndUnlockAnim_Step0,
    MovementAction_Finish,
};

u8 (*const gMovementActionFuncs_FlyUp[])(struct EventObject *, struct Sprite *) = {
    MovementAction_FlyUp_Step0,
    MovementAction_FlyUp_Step1,
    MovementAction_Fly_Finish,
};

u8 (*const gMovementActionFuncs_FlyDown[])(struct EventObject *, struct Sprite *) = {
    MovementAction_FlyDown_Step0,
    MovementAction_FlyDown_Step1,
    MovementAction_Fly_Finish,
};

u8 MovementAction_StoreAndLockAnim_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    u32 one;
    bool32 ableToStore = FALSE;
    if (gLockedAnimEventObjects == NULL)
    {
        gLockedAnimEventObjects = AllocZeroed(sizeof(struct LockedAnimEventObjects));
        gLockedAnimEventObjects->eventObjectIds[0] = eventObject->localId;
        // needed to match
        gLockedAnimEventObjects->count = (one = 1);
        ableToStore = one;
    }
    else
    {
        u8 i;
        u8 firstFreeSlot;
        bool32 found;
        for (firstFreeSlot = 16, found = FALSE, i = 0; i < 16; i++)
        {
            if (firstFreeSlot == 16 && gLockedAnimEventObjects->eventObjectIds[i] == 0)
                firstFreeSlot = i;

            if (gLockedAnimEventObjects->eventObjectIds[i] == eventObject->localId)
            {
                found = TRUE;
                break;
            }
        }

        if (!found && firstFreeSlot != 16)
        {
            gLockedAnimEventObjects->eventObjectIds[firstFreeSlot] = eventObject->localId;
            gLockedAnimEventObjects->count++;
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

u8 MovementAction_FreeAndUnlockAnim_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    bool32 ableToStore;
    u8 index;

    sprite->data[2] = 1;
    if (gLockedAnimEventObjects != NULL)
    {
        ableToStore = FALSE;
        index = FindLockedEventObjectIndex(eventObject);
        if (index != 16)
        {
            gLockedAnimEventObjects->eventObjectIds[index] = 0;
            gLockedAnimEventObjects->count--;
            ableToStore = TRUE;
        }
        if (gLockedAnimEventObjects->count == 0)
            FREE_AND_SET_NULL(gLockedAnimEventObjects);
        if (ableToStore == TRUE)
        {
            eventObject->inanimate = GetEventObjectGraphicsInfo(eventObject->graphicsId)->inanimate;
            eventObject->facingDirectionLocked = FALSE;
            sprite->animPaused = 0;
        }
    }

    return TRUE;
}

u8 FindLockedEventObjectIndex(struct EventObject *eventObject)
{
    u8 i;

    for (i = 0; i < EVENT_OBJECTS_COUNT; i++)
    {
        if (gLockedAnimEventObjects->eventObjectIds[i] == eventObject->localId)
            return i;
    }
    return EVENT_OBJECTS_COUNT;
}

void CreateLevitateMovementTask(struct EventObject *eventObject)
{
    u8 taskId = CreateTask(ApplyLevitateMovement, 0xFF);
    struct Task *task = &gTasks[taskId];

    StoreWordInTwoHalfwords(&task->data[0], (u32)eventObject);
    eventObject->warpArrowSpriteId = taskId;
    task->data[3] = 0xFFFF;
}

static void ApplyLevitateMovement(u8 taskId)
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

void DestroyExtraMovementTask(u8 taskId)
{
    struct EventObject *eventObject;
    struct Task *task = &gTasks[taskId];

    LoadWordFromTwoHalfwords(&task->data[0], (u32 *)&eventObject); // unused eventObject
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

u8 MovementAction_FlyUp_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sprite->pos2.y = 0;
    sprite->data[2]++;
    return FALSE;
}

u8 MovementAction_FlyUp_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    sprite->pos2.y -= 8;

    if(sprite->pos2.y == -160)
        sprite->data[2]++;
    return FALSE;
}

u8 MovementAction_FlyDown_Step0(struct EventObject *eventObject, struct Sprite *sprite)
{
    sprite->pos2.y = -160;
    sprite->data[2]++;
    return FALSE;
}

u8 MovementAction_FlyDown_Step1(struct EventObject *eventObject, struct Sprite *sprite)
{
    sprite->pos2.y += 8;

    if(!sprite->pos2.y)
        sprite->data[2]++;
    return FALSE;
}

// though this function returns TRUE without doing anything, this header is required due to being in an array of functions which needs it.
u8 MovementAction_Fly_Finish(struct EventObject *eventObject, struct Sprite *sprite)
{
    return TRUE;
}
