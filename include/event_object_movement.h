#ifndef GUARD_EVENT_OBJECT_MOVEMENT_H
#define GUARD_EVENT_OBJECT_MOVEMENT_H

#include "constants/event_object_movement.h"

// Palette slots for overworld NPCs.
// The same standard set of palettes for overworld objects are normally always loaded at the same
// time while walking around the overworld. The only exceptions are the palettes for the player and
// the "special" NPC, which can be swapped out. This also means that e.g. two "special" NPCs
// with competing palettes cannot be properly loaded at the same time.
enum {
    PALSLOT_PLAYER,
    PALSLOT_PLAYER_REFLECTION,
    PALSLOT_NPC_1,
    PALSLOT_NPC_2,
    PALSLOT_NPC_3,
    PALSLOT_NPC_4,
    PALSLOT_NPC_1_REFLECTION,
    PALSLOT_NPC_2_REFLECTION,
    PALSLOT_NPC_3_REFLECTION,
    PALSLOT_NPC_4_REFLECTION,
    PALSLOT_NPC_SPECIAL,
    PALSLOT_NPC_SPECIAL_REFLECTION,
    OBJ_PALSLOT_COUNT
    // the remaining sprite palette slots (12-15) are used by field effects, the interface, etc.
};

enum SpinnerRunnerFollowPatterns
{
    RUNFOLLOW_ANY,
    RUNFOLLOW_NORTH_SOUTH,
    RUNFOLLOW_EAST_WEST,
    RUNFOLLOW_NORTH_WEST,
    RUNFOLLOW_NORTH_EAST,
    RUNFOLLOW_SOUTH_WEST,
    RUNFOLLOW_SOUTH_EAST,
    RUNFOLLOW_NORTH_SOUTH_WEST,
    RUNFOLLOW_NORTH_SOUTH_EAST,
    RUNFOLLOW_NORTH_EAST_WEST,
    RUNFOLLOW_SOUTH_EAST_WEST
};

enum ReflectionTypes
{
    REFL_TYPE_NONE,
    REFL_TYPE_ICE,
    REFL_TYPE_WATER,
    NUM_REFLECTION_TYPES
};

#define FIGURE_8_LENGTH 72

#define GROUND_EFFECT_FLAG_TALL_GRASS_ON_SPAWN   (1 << 0)
#define GROUND_EFFECT_FLAG_TALL_GRASS_ON_MOVE    (1 << 1)
#define GROUND_EFFECT_FLAG_LONG_GRASS_ON_SPAWN   (1 << 2)
#define GROUND_EFFECT_FLAG_LONG_GRASS_ON_MOVE    (1 << 3)
#define GROUND_EFFECT_FLAG_WATER_REFLECTION      (1 << 4)
#define GROUND_EFFECT_FLAG_ICE_REFLECTION        (1 << 5)
#define GROUND_EFFECT_FLAG_SHALLOW_FLOWING_WATER (1 << 6)
#define GROUND_EFFECT_FLAG_SAND                  (1 << 7)
#define GROUND_EFFECT_FLAG_DEEP_SAND             (1 << 8)
#define GROUND_EFFECT_FLAG_RIPPLES               (1 << 9)
#define GROUND_EFFECT_FLAG_PUDDLE                (1 << 10)
#define GROUND_EFFECT_FLAG_SAND_PILE             (1 << 11)
#define GROUND_EFFECT_FLAG_LAND_IN_TALL_GRASS    (1 << 12)
#define GROUND_EFFECT_FLAG_LAND_IN_LONG_GRASS    (1 << 13)
#define GROUND_EFFECT_FLAG_LAND_IN_SHALLOW_WATER (1 << 14)
#define GROUND_EFFECT_FLAG_LAND_IN_DEEP_WATER    (1 << 15)
#define GROUND_EFFECT_FLAG_LAND_ON_NORMAL_GROUND (1 << 16)
#define GROUND_EFFECT_FLAG_SHORT_GRASS           (1 << 17)
#define GROUND_EFFECT_FLAG_HOT_SPRINGS           (1 << 18)
#define GROUND_EFFECT_FLAG_SEAWEED               (1 << 19)

// Sprite data for the CameraObject functions
#define sCamera_FollowSpriteId data[0]
#define sCamera_State          data[1]
#define sCamera_MoveX          data[2]
#define sCamera_MoveY          data[3]

struct StepAnimTable
{
    const union AnimCmd *const *anims;
    u8 animPos[4];
};

struct PairedPalettes
{
    u16 tag;
    const u16 *data;
};

struct LockedAnimObjectEvents
{
    u8 localIds[OBJECT_EVENTS_COUNT];
    u8 count;
};

extern const struct OamData gObjectEventBaseOam_32x8;
extern const struct OamData gObjectEventBaseOam_32x32;
extern const struct SpriteTemplate *const gFieldEffectObjectTemplatePointers[];
extern const u8 gReflectionEffectPaletteMap[];

extern const u8 *const gBerryTreeObjectEventGraphicsIdTablePointers[];
extern const struct SpriteFrameImage *const gBerryTreePicTablePointers[];
extern const u8 *const gBerryTreePaletteSlotTablePointers[];

void ResetObjectEvents(void);
u8 GetMoveDirectionAnimNum(u8 direction);
u8 GetObjectEventIdByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroupId);
bool8 TryGetObjectEventIdByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroupId, u8 *objectEventId);
u8 GetObjectEventIdByXY(s16 x, s16 y);
void SetObjectEventDirection(struct ObjectEvent *objectEvent, u8 direction);
u8 GetFirstInactiveObjectEventId(void);
void RemoveObjectEventByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup);
void LoadPlayerObjectReflectionPalette(u16 tag, u8 slot);
void LoadSpecialObjectReflectionPalette(u16 tag, u8 slot);
void TryMoveObjectEventToMapCoords(u8 localId, u8 mapNum, u8 mapGroup, s16 x, s16 y);
void PatchObjectPalette(u16 paletteTag, u8 paletteSlot);
void SpawnObjectEventsOnReturnToField(s16 x, s16 y);
void OverrideSecretBaseDecorationSpriteScript(u8 localId, u8 mapNum, u8 mapGroup, u8 decorationCategory);
void GetMapCoordsFromSpritePos(s16 x, s16 y, s16 *destX, s16 *destY);
u8 GetFaceDirectionAnimNum(u8 direction);
void SetSpritePosToOffsetMapCoords(s16 *x, s16 *y, s16 dx, s16 dy);
void ObjectEventClearHeldMovement(struct ObjectEvent *objectEvent);
void ObjectEventClearHeldMovementIfActive(struct ObjectEvent *objectEvent);
void TrySpawnObjectEvents(s16 cameraX, s16 cameraY);
u8 CreateObjectGraphicsSprite(u16 graphicsId, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority);
u8 TrySpawnObjectEvent(u8 localId, u8 mapNum, u8 mapGroup);
u8 SpawnSpecialObjectEventParameterized(u8 graphicsId, u8 movementBehavior, u8 localId, s16 x, s16 y, u8 elevation);
u8 SpawnSpecialObjectEvent(struct ObjectEventTemplate *objectEventTemplate);
void SetSpritePosToMapCoords(s16 mapX, s16 mapY, s16 *destX, s16 *destY);
void CameraObjectReset(void);
void ObjectEventSetGraphicsId(struct ObjectEvent *objectEvent, u8 graphicsId);
void ObjectEventTurn(struct ObjectEvent *objectEvent, u8 direction);
void ObjectEventTurnByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup, u8 direction);
const struct ObjectEventGraphicsInfo *GetObjectEventGraphicsInfo(u8 graphicsId);
void SetObjectInvisibility(u8 localId, u8 mapNum, u8 mapGroup, bool8 invisible);
void FreeAndReserveObjectSpritePalettes(void);
void SetObjectEventSpritePosByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup, s16 x, s16 y);
void ResetObjectSubpriority(u8 localId, u8 mapNum, u8 mapGroup);
void SetObjectSubpriority(u8 localId, u8 mapNum, u8 mapGroup, u8 subpriority);
void AllowObjectAtPosTriggerGroundEffects(s16 x, s16 y);
void ObjectEventGetLocalIdAndMap(struct ObjectEvent *objectEvent, void *localId, void *mapNum, void *mapGroup);
void ShiftObjectEventCoords(struct ObjectEvent *objectEvent, s16 x, s16 y);
void MoveObjectEventToMapCoords(struct ObjectEvent *objectEvent, s16 x, s16 y);
void TryOverrideObjectEventTemplateCoords(u8 localId, u8 mapNum, u8 mapGroup);
void InitObjectEventPalettes(u8 reflectionType);
void UpdateObjectEventCurrentMovement(struct ObjectEvent *objectEvent, struct Sprite *sprite, bool8 (*callback)(struct ObjectEvent *, struct Sprite *));
bool8 ObjectEventFaceOppositeDirection(struct ObjectEvent *objectEvent, u8 direction);
u8 GetOppositeDirection(u8 direction);
u8 GetWalkInPlaceFasterMovementAction(u32);
u8 GetWalkInPlaceFastMovementAction(u32);
u8 GetWalkInPlaceNormalMovementAction(u32);
u8 GetWalkInPlaceSlowMovementAction(u32);
u8 GetCollisionAtCoords(struct ObjectEvent *objectEvent, s16 x, s16 y, u32 dir);
void MoveCoords(u8 direction, s16 *x, s16 *y);
bool8 ObjectEventIsHeldMovementActive(struct ObjectEvent *objectEvent);
u8 ObjectEventClearHeldMovementIfFinished(struct ObjectEvent *objectEvent);
u8 GetObjectEventIdByPosition(u16 x, u16 y, u8 elevation);
void SetTrainerMovementType(struct ObjectEvent *objectEvent, u8 movementType);
u8 GetTrainerFacingDirectionMovementType(u8 direction);
const u8 *GetObjectEventScriptPointerByObjectEventId(u8 objectEventId);
u8 GetCollisionFlagsAtCoords(struct ObjectEvent *objectEvent, s16 x, s16 y, u8 direction);
u8 GetFaceDirectionMovementAction(u32);
u8 GetWalkNormalMovementAction(u32);
u8 GetWalkFastMovementAction(u32);
u8 GetRideWaterCurrentMovementAction(u32);
u8 GetWalkFasterMovementAction(u32);
u8 GetPlayerRunMovementAction(u32);
u8 GetJumpInPlaceMovementAction(u32);
u8 GetAcroWheelieFaceDirectionMovementAction(u32);
u8 GetAcroPopWheelieFaceDirectionMovementAction(u32);
u8 GetAcroEndWheelieFaceDirectionMovementAction(u32);
u8 GetAcroWheelieHopFaceDirectionMovementAction(u32);
u8 GetAcroWheelieHopDirectionMovementAction(u32);
u8 GetAcroWheelieJumpDirectionMovementAction(u32);
u8 GetJumpInPlaceTurnAroundMovementAction(u32);
u8 GetAcroWheelieInPlaceDirectionMovementAction(u32);
u8 GetAcroPopWheelieMoveDirectionMovementAction(u32);
u8 GetAcroWheelieMoveDirectionMovementAction(u32);
u8 GetAcroEndWheelieMoveDirectionMovementAction(u32);
u8 GetFishingDirectionAnimNum(u8 direction);
u8 GetAcroWheelieDirectionAnimNum(u8 direction);
u8 GetFishingBiteDirectionAnimNum(u8 direction);
u8 GetFishingNoCatchDirectionAnimNum(u8 direction);
bool8 ObjectEventSetHeldMovement(struct ObjectEvent *objectEvent, u8 specialAnimId);
void ObjectEventForceSetHeldMovement(struct ObjectEvent *objectEvent, u8 movementActionId);
bool8 ObjectEventIsMovementOverridden(struct ObjectEvent *objectEvent);
u8 ObjectEventCheckHeldMovementStatus(struct ObjectEvent *objectEvent);
u8 ObjectEventGetHeldMovementActionId(struct ObjectEvent *objectEvent);
void TryOverrideTemplateCoordsForObjectEvent(const struct ObjectEvent *objectEvent, u8 movementType);
void OverrideTemplateCoordsForObjectEvent(const struct ObjectEvent *objectEvent);
void ShiftStillObjectEventCoords(struct ObjectEvent *objEvent);
void ObjectEventMoveDestCoords(struct ObjectEvent *objEvent, u32 direction, s16 *x, s16 *y);
u8 AddCameraObject(u8 linkedSpriteId);
void UpdateObjectEventsForCameraUpdate(s16 x, s16 y);
u8 GetWalkSlowMovementAction(u32);
u8 GetJumpMovementAction(u32);
u8 ElevationToPriority(u8 elevation);
void ObjectEventUpdateElevation(struct ObjectEvent *objEvent);
void SetObjectSubpriorityByElevation(u8 elevation, struct Sprite *sprite, u8 subpriority);
void UnfreezeObjectEvent(struct ObjectEvent *objectEvent);
u8 FindLockedObjectEventIndex(struct ObjectEvent *objectEvent);
void SetAndStartSpriteAnim(struct Sprite *sprite, u8 animNum, u8 animCmdIndex);
bool8 SpriteAnimEnded(struct Sprite *sprite);
void UnfreezeObjectEvents(void);
void FreezeObjectEventsExceptOne(u8 objectEventId);
void FreezeObjectEventsExceptTwo(u8 objectEventId1, u8 objectEventId2);
void FreezeObjectEvents(void);
bool8 FreezeObjectEvent(struct ObjectEvent *objectEvent);
u8 GetMoveDirectionFastAnimNum(u8 direction);
u8 GetMoveDirectionFasterAnimNum(u8 direction);
u8 GetMoveDirectionFastestAnimNum(u8 direction);
u8 GetLedgeJumpDirection(s16 x, s16 y, u8 direction);
void CameraObjectSetFollowedSpriteId(u8 objectId);
u16 GetObjectPaletteTag(u8 palSlot);
void UpdateObjectEventSpriteInvisibility(struct Sprite *sprite, bool8 invisible);
s16 GetFigure8XOffset(s16 idx);
s16 GetFigure8YOffset(s16 idx);
void CameraObjectFreeze(void);
u8 GetObjectEventBerryTreeId(u8 objectEventId);
void SetBerryTreeJustPicked(u8 mapId, u8 mapNumber, u8 mapGroup);
bool8 IsBerryTreeSparkling(u8 localId, u8 mapNum, u8 mapGroup);

void MovementType_None(struct Sprite *sprite);
void MovementType_LookAround(struct Sprite *sprite);
void MovementType_WanderAround(struct Sprite *sprite);
void MovementType_WanderUpAndDown(struct Sprite *sprite);
void MovementType_WanderLeftAndRight(struct Sprite *sprite);
void MovementType_FaceDirection(struct Sprite *sprite);
void MovementType_Player(struct Sprite *sprite);
void MovementType_BerryTreeGrowth(struct Sprite *sprite);
void MovementType_FaceDownAndUp(struct Sprite *sprite);
void MovementType_FaceLeftAndRight(struct Sprite *sprite);
void MovementType_FaceUpAndLeft(struct Sprite *sprite);
void MovementType_FaceUpAndRight(struct Sprite *sprite);
void MovementType_FaceDownAndLeft(struct Sprite *sprite);
void MovementType_FaceDownAndRight(struct Sprite *sprite);
void MovementType_FaceDownUpAndLeft(struct Sprite *sprite);
void MovementType_FaceDownUpAndRight(struct Sprite *sprite);
void MovementType_FaceUpRightAndLeft(struct Sprite *sprite);
void MovementType_FaceDownRightAndLeft(struct Sprite *sprite);
void MovementType_RotateCounterclockwise(struct Sprite *sprite);
void MovementType_RotateClockwise(struct Sprite *sprite);
void MovementType_WalkBackAndForth(struct Sprite *sprite);
void MovementType_WalkSequenceUpRightLeftDown(struct Sprite *sprite);
void MovementType_WalkSequenceRightLeftDownUp(struct Sprite *sprite);
void MovementType_WalkSequenceDownUpRightLeft(struct Sprite *sprite);
void MovementType_WalkSequenceLeftDownUpRight(struct Sprite *sprite);
void MovementType_WalkSequenceUpLeftRightDown(struct Sprite *sprite);
void MovementType_WalkSequenceLeftRightDownUp(struct Sprite *sprite);
void MovementType_WalkSequenceDownUpLeftRight(struct Sprite *sprite);
void MovementType_WalkSequenceRightDownUpLeft(struct Sprite *sprite);
void MovementType_WalkSequenceLeftUpDownRight(struct Sprite *sprite);
void MovementType_WalkSequenceUpDownRightLeft(struct Sprite *sprite);
void MovementType_WalkSequenceRightLeftUpDown(struct Sprite *sprite);
void MovementType_WalkSequenceDownRightLeftUp(struct Sprite *sprite);
void MovementType_WalkSequenceRightUpDownLeft(struct Sprite *sprite);
void MovementType_WalkSequenceUpDownLeftRight(struct Sprite *sprite);
void MovementType_WalkSequenceLeftRightUpDown(struct Sprite *sprite);
void MovementType_WalkSequenceDownLeftRightUp(struct Sprite *sprite);
void MovementType_WalkSequenceUpLeftDownRight(struct Sprite *sprite);
void MovementType_WalkSequenceDownRightUpLeft(struct Sprite *sprite);
void MovementType_WalkSequenceLeftDownRightUp(struct Sprite *sprite);
void MovementType_WalkSequenceRightUpLeftDown(struct Sprite *sprite);
void MovementType_WalkSequenceUpRightDownLeft(struct Sprite *sprite);
void MovementType_WalkSequenceDownLeftUpRight(struct Sprite *sprite);
void MovementType_WalkSequenceLeftUpRightDown(struct Sprite *sprite);
void MovementType_WalkSequenceRightDownLeftUp(struct Sprite *sprite);
void MovementType_CopyPlayer(struct Sprite *sprite);
void MovementType_TreeDisguise(struct Sprite *sprite);
void MovementType_MountainDisguise(struct Sprite *sprite);
void MovementType_CopyPlayerInGrass(struct Sprite *sprite);
void MovementType_Buried(struct Sprite *sprite);
void MovementType_WalkInPlace(struct Sprite *sprite);
void MovementType_JogInPlace(struct Sprite *sprite);
void MovementType_RunInPlace(struct Sprite *sprite);
void MovementType_Invisible(struct Sprite *sprite);
void MovementType_WalkSlowlyInPlace(struct Sprite *sprite);
u8 GetSlideMovementAction(u32);
u8 GetJumpMovementAction(u32);
u8 GetJump2MovementAction(u32);
u8 CreateCopySpriteAt(struct Sprite *sprite, s16 x, s16 y, u8 subpriority);

bool8 MovementType_WanderAround_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WanderAround_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WanderAround_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WanderAround_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WanderAround_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WanderAround_Step5(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WanderAround_Step6(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 GetVectorDirection(s16 dx, s16 dy, s16 absdx, s16 absdy);
u8 GetLimitedVectorDirection_SouthNorth(s16 dx, s16 dy, s16 absdx, s16 absdy);
u8 GetLimitedVectorDirection_WestEast(s16 dx, s16 dy, s16 absdx, s16 absdy);
u8 GetLimitedVectorDirection_WestNorth(s16 dx, s16 dy, s16 absdx, s16 absdy);
u8 GetLimitedVectorDirection_EastNorth(s16 dx, s16 dy, s16 absdx, s16 absdy);
u8 GetLimitedVectorDirection_WestSouth(s16 dx, s16 dy, s16 absdx, s16 absdy);
u8 GetLimitedVectorDirection_EastSouth(s16 dx, s16 dy, s16 absdx, s16 absdy);
u8 GetLimitedVectorDirection_SouthNorthWest(s16 dx, s16 dy, s16 absdx, s16 absdy);
u8 GetLimitedVectorDirection_SouthNorthEast(s16 dx, s16 dy, s16 absdx, s16 absdy);
u8 GetLimitedVectorDirection_NorthWestEast(s16 dx, s16 dy, s16 absdx, s16 absdy);
u8 GetLimitedVectorDirection_SouthWestEast(s16 dx, s16 dy, s16 absdx, s16 absdy);
bool8 MovementType_LookAround_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_LookAround_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_LookAround_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_LookAround_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_LookAround_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WanderUpAndDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WanderUpAndDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WanderUpAndDown_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WanderUpAndDown_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WanderUpAndDown_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WanderUpAndDown_Step5(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WanderUpAndDown_Step6(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WanderLeftAndRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WanderLeftAndRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WanderLeftAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WanderLeftAndRight_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WanderLeftAndRight_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WanderLeftAndRight_Step5(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WanderLeftAndRight_Step6(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDirection_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDirection_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDirection_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_BerryTreeGrowth_Normal(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_BerryTreeGrowth_Move(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_BerryTreeGrowth_SparkleStart(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_BerryTreeGrowth_Sparkle(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_BerryTreeGrowth_SparkleEnd(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownAndUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownAndUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownAndUp_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownAndUp_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownAndUp_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceLeftAndRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceLeftAndRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceLeftAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceLeftAndRight_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceLeftAndRight_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceUpAndLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceUpAndLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceUpAndLeft_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceUpAndLeft_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceUpAndLeft_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceUpAndRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceUpAndRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceUpAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceUpAndRight_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceUpAndRight_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownAndLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownAndLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownAndLeft_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownAndLeft_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownAndLeft_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownAndRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownAndRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownAndRight_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownAndRight_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownUpAndLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownUpAndLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownUpAndLeft_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownUpAndLeft_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownUpAndLeft_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownUpAndRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownUpAndRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownUpAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownUpAndRight_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownUpAndRight_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceUpLeftAndRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceUpLeftAndRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceUpLeftAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceUpLeftAndRight_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceUpLeftAndRight_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownLeftAndRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownLeftAndRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownLeftAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownLeftAndRight_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_FaceDownLeftAndRight_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_RotateCounterclockwise_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_RotateCounterclockwise_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_RotateCounterclockwise_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_RotateCounterclockwise_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_RotateClockwise_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_RotateClockwise_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_RotateClockwise_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_RotateClockwise_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WalkBackAndForth_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WalkBackAndForth_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WalkBackAndForth_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WalkBackAndForth_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WalkSequence_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WalkSequence_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceUpRightLeftDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceRightLeftDownUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceDownUpRightLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceLeftDownUpRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceUpLeftRightDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceLeftRightDownUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceDownUpLeftRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceRightDownUpLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceLeftUpDownRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceUpDownRightLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceRightLeftUpDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceDownRightLeftUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceRightUpDownLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceUpDownLeftRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceLeftRightUpDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceDownLeftRightUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceUpLeftDownRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceDownRightUpLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceLeftDownRightUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceRightUpLeftDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceUpRightDownLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceDownLeftUpRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceLeftUpRightDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementType_WalkSequenceRightDownLeftUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_CopyPlayer_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_CopyPlayer_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_CopyPlayer_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 CopyablePlayerMovement_None(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8));
bool8 CopyablePlayerMovement_FaceDirection(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8));
bool8 CopyablePlayerMovement_WalkNormal(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8));
bool8 CopyablePlayerMovement_WalkFast(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8));
bool8 CopyablePlayerMovement_WalkFaster(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8));
bool8 CopyablePlayerMovement_Slide(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8));
bool8 CopyablePlayerMovement_JumpInPlace(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8));
bool8 CopyablePlayerMovement_Jump(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8));
bool8 CopyablePlayerMovement_Jump2(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8));
bool8 MovementType_CopyPlayerInGrass_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_Buried_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WalkInPlace_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_MoveInPlace_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_WalkSlowlyInPlace_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_JogInPlace_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_RunInPlace_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_Invisible_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_Invisible_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_Invisible_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);

u8 CreateVirtualObject(u8 graphicsId, u8 virtualObjId, s16 x, s16 y, u8 elevation, u8 direction);
void TurnVirtualObject(u8 virtualObjId, u8 direction);
void SetVirtualObjectGraphics(u8 virtualObjId, u8 graphicsId);
void SetVirtualObjectInvisibility(u8 virtualObjId, bool32 invisible);
bool32 IsVirtualObjectInvisible(u8 virtualObjId);
void SetVirtualObjectSpriteAnim(u8 virtualObjId, u8 animNum);
bool32 IsVirtualObjectAnimating(u8 virtualObjId);

#endif //GUARD_EVENT_OBJECT_MOVEMENT_H
