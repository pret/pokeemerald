#ifndef GUARD_FIELD_EVENT_OBJ_H
#define GUARD_FIELD_EVENT_OBJ_H

#define NUM_OBJECT_GRAPHICS_INFO 239
#define SPRITE_VAR 240

// Exported struct declarations

enum SpinnerRunnerFollowPatterns {
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

struct UnkStruct_085094AC {
    const union AnimCmd *const *anims;
    u8 animPos[4];
};

#define GROUND_EFFECT_FLAG_TALL_GRASS_ON_SPAWN   (1 << 0)
#define GROUND_EFFECT_FLAG_TALL_GRASS_ON_MOVE    (1 << 1)
#define GROUND_EFFECT_FLAG_LONG_GRASS_ON_SPAWN   (1 << 2)
#define GROUND_EFFECT_FLAG_LONG_GRASS_ON_MOVE    (1 << 3)
#define GROUND_EFFECT_FLAG_ICE_REFLECTION        (1 << 4)
#define GROUND_EFFECT_FLAG_REFLECTION            (1 << 5)
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

#define null_object_step(name, retval) \
bool8 EventObjectCB2_##name(struct EventObject *, struct Sprite *);\
void EventObjectCB_##name(struct Sprite *sprite)\
{\
    EventObjectStep(&gEventObjects[sprite->data[0]], sprite, EventObjectCB2_##name);\
}\
bool8 EventObjectCB2_##name(struct EventObject *eventObject, struct Sprite *sprite)\
{\
    return (retval);\
}

#define field_object_step(name, table) \
extern bool8 (*const (table)[])(struct EventObject *, struct Sprite *);\
bool8 EventObjectCB2_##name(struct EventObject *, struct Sprite *);\
void EventObjectCB_##name(struct Sprite *sprite)\
{\
    EventObjectStep(&gEventObjects[sprite->data[0]], sprite, EventObjectCB2_##name);\
}\
bool8 EventObjectCB2_##name(struct EventObject *eventObject, struct Sprite *sprite)\
{\
    return (table)[sprite->data[1]](eventObject, sprite);\
}

#define field_object_path(idx, table, sub, path, catch, coord)\
field_object_step(GoInDirectionSequence##idx, table)\
extern const u8 path[4];\
bool8 sub(struct EventObject *eventObject, struct Sprite *sprite)\
{\
    u8 route[sizeof(path)];\
    memcpy(route, path, sizeof(path));\
    if (eventObject->directionSequenceIndex == (catch) && eventObject->initialCoords.coord == eventObject->currentCoords.coord)\
    {\
        eventObject->directionSequenceIndex = (catch) + 1;\
    }\
    return MoveEventObjectInNextDirectionInSequence(eventObject, sprite, route);\
}\

struct PairedPalettes {
    u16 tag;
    const u16 *data;
};

extern const struct SpriteFrameImage gEventObjectPicTable_PechaBerryTree[];

void sub_808D438(void);
u8 get_go_image_anim_num(u8);
u8 GetEventObjectIdByLocalIdAndMap(u8, u8, u8);
bool8 TryGetEventObjectIdByLocalIdAndMap(u8, u8, u8, u8 *);
u8 GetEventObjectIdByXY(s16, s16);
void EventObjectSetDirection(struct EventObject *, u8);
u8 sub_808D4F4(void);
void RemoveEventObjectByLocalIdAndMap(u8, u8, u8);
void npc_load_two_palettes__no_record(u16, u8);
void npc_load_two_palettes__and_record(u16, u8);
void sub_808EBA8(u8, u8, u8, s16, s16);
void pal_patch_for_npc(u16, u8);
void sub_808E16C(s16, s16);
void sub_808F28C(u8 localId, u8 mapNum, u8 mapGroup, u8 decorCat);
void sub_8092FF0(s16, s16, s16 *, s16 *);
u8 EventObjectDirectionToImageAnimId(u8);
void sub_80930E0(s16 *, s16 *, s16, s16);
void EventObjectClearAnim(struct EventObject *);
void EventObjectClearAnimIfSpecialAnimActive(struct EventObject *);
void SpawnEventObjectsInView(s16, s16);
u8 sprite_new(u8, u8, s16, s16, u8, u8);
u8 AddPseudoEventObject(u16, void (*)(struct Sprite *), s16, s16, u8);
u8 show_sprite(u8, u8, u8);
u8 SpawnSpecialEventObjectParametrized(u8, u8, u8, s16, s16, u8);
u8 SpawnSpecialEventObject(struct EventObjectTemplate *);
void sub_8093038(s16, s16, s16 *, s16 *);
void CameraObjectReset1(void);
void EventObjectSetGraphicsId(struct EventObject *, u8);
void EventObjectTurn(struct EventObject *, u8);
void EventObjectTurnByLocalIdAndMap(u8, u8, u8, u8);
const struct EventObjectGraphicsInfo *GetEventObjectGraphicsInfo(u8);
void npc_by_local_id_and_map_set_field_1_bit_x20(u8, u8, u8, u8);
void gpu_pal_allocator_reset__manage_upper_four(void);
void sub_808E82C(u8, u8, u8, s16, s16);
void sub_808E7E4(u8, u8, u8);
void sub_808E78C(u8, u8, u8, u8);
void sub_808E75C(s16, s16);
void EventObjectGetLocalIdAndMap(struct EventObject *eventObject, void *localId, void *mapNum, void *mapGroup);
void npc_coords_shift(struct EventObject *, s16, s16);
void sub_808EB08(struct EventObject *, s16, s16);
void sub_808F254(u8, u8, u8);
void EventObjectStep(struct EventObject *, struct Sprite *, bool8(struct EventObject *, struct Sprite *));
u8 EventObjectFaceOppositeDirection(struct EventObject *, u8);
u8 GetOppositeDirection(u8);
u8 GetStepInPlaceDelay4AnimId(u32);
u8 GetStepInPlaceDelay8AnimId(u32);
u8 GetStepInPlaceDelay16AnimId(u32);
u8 GetStepInPlaceDelay32AnimId(u32);
u8 npc_block_way(struct EventObject *, s16, s16, u32);
void MoveCoords(u8, s16 *, s16 *);
bool8 EventObjectIsSpecialAnimActive(struct EventObject *);
u8 EventObjectClearAnimIfSpecialAnimFinished(struct EventObject *);
u8 GetEventObjectIdByXYZ(u16 x, u16 y, u8 z);
void npc_set_running_behaviour_etc(struct EventObject *eventObject, u8 movementType);
u8 npc_running_behaviour_by_direction(u8 direction);
const u8 *GetEventObjectScriptPointerByEventObjectId(u8 eventObjectId);
u8 sub_8092C8C(struct EventObject *eventObject, s16 x, s16 y, u8 direction);
u8 GetFaceDirectionAnimId(u32);
u8 GetGoSpeed0AnimId(u32);
u8 GetGoSpeed1AnimId(u32);
u8 GetGoSpeed3AnimId(u32);
u8 sub_80934BC(u32);
bool8 EventObjectSetSpecialAnim(struct EventObject *eventObject, u8 specialAnimId);
bool8 EventObjectIsSpecialAnimOrDirectionSequenceAnimActive(struct EventObject *eventObject);
u8 EventObjectCheckIfSpecialAnimFinishedOrInactive(struct EventObject *eventObject);
void sub_808F23C(const struct EventObject *eventObject, u8 movementType);
void sub_808F208(const struct EventObject *eventObject);
void npc_coords_shift_still(struct EventObject *pObject);
void EventObjectMoveDestCoords(struct EventObject *pObject, u32 unk_19, s16 *pInt, s16 *pInt1);
u8 AddCameraObject(u8 linkedSpriteId);
void UpdateEventObjectsForCameraUpdate(s16 x, s16 y);
u8 GetSimpleGoAnimId(u32);
u8 sub_8093514(u32);
bool8 AreZCoordsCompatible(u8, u8);
u8 ZCoordToPriority(u8);
void EventObjectUpdateZCoord(struct EventObject *pObject);
void SetObjectSubpriorityByZCoord(u8, struct Sprite *, u8);
bool8 IsZCoordMismatchAt(u8, s16, s16);
void sub_8097AC8(struct Sprite *);
void npc_sync_anim_pause_bits(struct EventObject *);
void oamt_npc_ministep_reset(struct Sprite *, u8, u8);
u8 sub_8097F78(struct EventObject *);
bool8 obj_npc_ministep(struct Sprite *sprite);
bool8 sub_80976EC(struct Sprite *sprite);
void sub_80976DC(struct Sprite *, u8);
void sub_809783C(struct Sprite *, u8, u8, u8);
void DoShadowFieldEffect(struct EventObject *);
u8 sub_809785C(struct Sprite *);
u8 sub_80978E4(struct Sprite *);
void obj_anim_image_set_and_seek(struct Sprite *, u8, u8);
bool8 sub_80979BC(struct Sprite *);
void sub_8097750(struct Sprite *);
bool8 sub_8097758(struct Sprite *);
void sub_8097FA4(struct EventObject *);
void sub_8098044(u8);
void UnfreezeEventObjects(void);
void FreezeEventObjectsExceptOne(u8 eventObjectId);
void sub_8097B78(u8, u8);
void sub_8098074(u8 var1, u8 var2);
void FreezeEventObjects(void);
bool8 FreezeEventObject(struct EventObject *eventObject);
u8 get_go_fast_image_anim_num(u8);
u8 get_go_faster_image_anim_num(u8);
u8 get_go_fastest_image_anim_num(u8);

void EventObjectCB_NoMovement1(struct Sprite *);
void EventObjectCB_LookRandomDirections(struct Sprite *);
void EventObjectCB_GoRandomDirections(struct Sprite *);
void EventObjectCB_RandomlyGoNorthOrSouth(struct Sprite *);
void EventObjectCB_RandomlyGoNorthOrSouth(struct Sprite *);
void EventObjectCB_RandomlyGoEastOrWest(struct Sprite *);
void EventObjectCB_RandomlyGoEastOrWest(struct Sprite *);
void EventObjectCB_FaceFixedDirection(struct Sprite *);
void EventObjectCB_FaceFixedDirection(struct Sprite *);
void EventObjectCB_FaceFixedDirection(struct Sprite *);
void EventObjectCB_FaceFixedDirection(struct Sprite *);
void EventObjectCB_NoMovement2(struct Sprite *);
void EventObjectCB_BerryTree(struct Sprite *);
void EventObjectCB_RandomlyLookNorthOrSouth(struct Sprite *);
void EventObjectCB_RandomlyLookEastOrWest(struct Sprite *);
void EventObjectCB_RandomlyLookNorthOrWest(struct Sprite *);
void EventObjectCB_RandomlyLookNorthOrEast(struct Sprite *);
void EventObjectCB_RandomlyLookSouthOrWest(struct Sprite *);
void EventObjectCB_RandomlyLookSouthOrEast(struct Sprite *);
void EventObjectCB_RandomlyLookNorthOrSouthOrWest(struct Sprite *);
void EventObjectCB_RandomlyLookNorthOrSouthOrEast(struct Sprite *);
void EventObjectCB_RandomlyLookNorthOrEastOrWest(struct Sprite *);
void EventObjectCB_RandomlyLookSouthOrEastOrWest(struct Sprite *);
void EventObjectCB_LookAroundCounterclockwise(struct Sprite *);
void EventObjectCB_LookAroundClockwise(struct Sprite *);
void EventObjectCB_AlternatelyGoInOppositeDirections(struct Sprite *);
void EventObjectCB_AlternatelyGoInOppositeDirections(struct Sprite *);
void EventObjectCB_AlternatelyGoInOppositeDirections(struct Sprite *);
void EventObjectCB_AlternatelyGoInOppositeDirections(struct Sprite *);
void EventObjectCB_GoInDirectionSequence1(struct Sprite *);
void EventObjectCB_GoInDirectionSequence2(struct Sprite *);
void EventObjectCB_GoInDirectionSequence3(struct Sprite *);
void EventObjectCB_GoInDirectionSequence4(struct Sprite *);
void EventObjectCB_GoInDirectionSequence5(struct Sprite *);
void EventObjectCB_GoInDirectionSequence6(struct Sprite *);
void EventObjectCB_GoInDirectionSequence7(struct Sprite *);
void EventObjectCB_GoInDirectionSequence8(struct Sprite *);
void EventObjectCB_GoInDirectionSequence9(struct Sprite *);
void EventObjectCB_GoInDirectionSequence10(struct Sprite *);
void EventObjectCB_GoInDirectionSequence11(struct Sprite *);
void EventObjectCB_GoInDirectionSequence12(struct Sprite *);
void EventObjectCB_GoInDirectionSequence13(struct Sprite *);
void EventObjectCB_GoInDirectionSequence14(struct Sprite *);
void EventObjectCB_GoInDirectionSequence15(struct Sprite *);
void EventObjectCB_GoInDirectionSequence16(struct Sprite *);
void EventObjectCB_GoInDirectionSequence17(struct Sprite *);
void EventObjectCB_GoInDirectionSequence18(struct Sprite *);
void EventObjectCB_GoInDirectionSequence19(struct Sprite *);
void EventObjectCB_GoInDirectionSequence20(struct Sprite *);
void EventObjectCB_GoInDirectionSequence21(struct Sprite *);
void EventObjectCB_GoInDirectionSequence22(struct Sprite *);
void EventObjectCB_GoInDirectionSequence23(struct Sprite *);
void EventObjectCB_GoInDirectionSequence24(struct Sprite *);
void EventObjectCB_CopyPlayer1(struct Sprite *);
void EventObjectCB_CopyPlayer1(struct Sprite *);
void EventObjectCB_CopyPlayer1(struct Sprite *);
void EventObjectCB_CopyPlayer1(struct Sprite *);
void EventObjectCB_TreeDisguise(struct Sprite *);
void EventObjectCB_MountainDisguise(struct Sprite *);
void EventObjectCB_CopyPlayer2(struct Sprite *);
void EventObjectCB_CopyPlayer2(struct Sprite *);
void EventObjectCB_CopyPlayer2(struct Sprite *);
void EventObjectCB_CopyPlayer2(struct Sprite *);
void EventObjectCB_Hidden1(struct Sprite *);
void EventObjectCB_WalkInPlace1(struct Sprite *);
void EventObjectCB_WalkInPlace1(struct Sprite *);
void EventObjectCB_WalkInPlace1(struct Sprite *);
void EventObjectCB_WalkInPlace1(struct Sprite *);
void EventObjectCB_WalkInPlace2(struct Sprite *);
void EventObjectCB_WalkInPlace2(struct Sprite *);
void EventObjectCB_WalkInPlace2(struct Sprite *);
void EventObjectCB_WalkInPlace2(struct Sprite *);
void EventObjectCB_WalkInPlace3(struct Sprite *);
void EventObjectCB_WalkInPlace3(struct Sprite *);
void EventObjectCB_WalkInPlace3(struct Sprite *);
void EventObjectCB_WalkInPlace3(struct Sprite *);
void EventObjectCB_Hidden2(struct Sprite *);
void EventObjectCB_WalkInPlace4(struct Sprite *);
void EventObjectCB_WalkInPlace4(struct Sprite *);
void EventObjectCB_WalkInPlace4(struct Sprite *);
void EventObjectCB_WalkInPlace4(struct Sprite *);

u8 sub_808F44C(struct EventObject *, struct Sprite *);
u8 sub_808F460(struct EventObject *, struct Sprite *);
u8 sub_808F48C(struct EventObject *, struct Sprite *);
u8 sub_808F4C8(struct EventObject *, struct Sprite *);
u8 sub_808F4E8(struct EventObject *, struct Sprite *);
u8 sub_808F534(struct EventObject *, struct Sprite *);
u8 sub_808F564(struct EventObject *, struct Sprite *);
u8 GetRegularRunningPastFacingDirection(s16, s16, s16, s16);
u8 GetNorthSouthRunningPastFacingDirection(s16, s16, s16, s16);
u8 GetEastWestRunningPastFacingDirection(s16, s16, s16, s16);
u8 GetNorthEastRunningPastFacingDirection(s16, s16, s16, s16);
u8 GetNorthWestRunningPastFacingDirection(s16, s16, s16, s16);
u8 GetSouthEastRunningPastFacingDirection(s16, s16, s16, s16);
u8 GetSouthWestRunningPastFacingDirection(s16, s16, s16, s16);
u8 GetNonEastRunningPastFacingDirection(s16, s16, s16, s16);
u8 GetNonWestRunningPastFacingDirection(s16, s16, s16, s16);
u8 GetNonSouthRunningPastFacingDirection(s16, s16, s16, s16);
u8 GetNonNorthRunningPastFacingDirection(s16, s16, s16, s16);
u8 sub_808F988(struct EventObject *, struct Sprite *);
u8 sub_808F99C(struct EventObject *, struct Sprite *);
u8 sub_808F9C8(struct EventObject *, struct Sprite *);
u8 sub_808FA0C(struct EventObject *, struct Sprite *);
u8 sub_808FA3C(struct EventObject *, struct Sprite *);
u8 sub_808FAC8(struct EventObject *, struct Sprite *);
u8 sub_808FADC(struct EventObject *, struct Sprite *);
u8 sub_808FB08(struct EventObject *, struct Sprite *);
u8 sub_808FB44(struct EventObject *, struct Sprite *);
u8 sub_808FB64(struct EventObject *, struct Sprite *);
u8 sub_808FBB0(struct EventObject *, struct Sprite *);
u8 sub_808FBE0(struct EventObject *, struct Sprite *);
u8 sub_808FC4C(struct EventObject *, struct Sprite *);
u8 sub_808FC60(struct EventObject *, struct Sprite *);
u8 sub_808FC8C(struct EventObject *, struct Sprite *);
u8 sub_808FCC8(struct EventObject *, struct Sprite *);
u8 sub_808FCE8(struct EventObject *, struct Sprite *);
u8 sub_808FD34(struct EventObject *, struct Sprite *);
u8 sub_808FD64(struct EventObject *, struct Sprite *);
u8 sub_808FDD0(struct EventObject *, struct Sprite *);
u8 sub_808FDFC(struct EventObject *, struct Sprite *);
u8 sub_808FE1C(struct EventObject *, struct Sprite *);
u8 do_berry_tree_growth_sparkle_1(struct EventObject *, struct Sprite *);
u8 sub_808FF48(struct EventObject *, struct Sprite *);
u8 do_berry_tree_growth_sparkle_2(struct EventObject *, struct Sprite *);
u8 sub_808FFB4(struct EventObject *, struct Sprite *);
u8 sub_8090004(struct EventObject *, struct Sprite *);
u8 sub_8090094(struct EventObject *, struct Sprite *);
u8 sub_80900A8(struct EventObject *, struct Sprite *);
u8 sub_80900D4(struct EventObject *, struct Sprite *);
u8 sub_8090118(struct EventObject *, struct Sprite *);
u8 sub_8090148(struct EventObject *, struct Sprite *);
u8 sub_80901D4(struct EventObject *, struct Sprite *);
u8 sub_80901E8(struct EventObject *, struct Sprite *);
u8 sub_8090214(struct EventObject *, struct Sprite *);
u8 sub_8090258(struct EventObject *, struct Sprite *);
u8 sub_8090288(struct EventObject *, struct Sprite *);
u8 sub_8090314(struct EventObject *, struct Sprite *);
u8 sub_8090328(struct EventObject *, struct Sprite *);
u8 sub_8090354(struct EventObject *, struct Sprite *);
u8 sub_8090398(struct EventObject *, struct Sprite *);
u8 sub_80903C8(struct EventObject *, struct Sprite *);
u8 sub_8090454(struct EventObject *, struct Sprite *);
u8 sub_8090468(struct EventObject *, struct Sprite *);
u8 sub_8090494(struct EventObject *, struct Sprite *);
u8 sub_80904D8(struct EventObject *, struct Sprite *);
u8 sub_8090508(struct EventObject *, struct Sprite *);
u8 sub_8090594(struct EventObject *, struct Sprite *);
u8 sub_80905A8(struct EventObject *, struct Sprite *);
u8 sub_80905D4(struct EventObject *, struct Sprite *);
u8 sub_8090618(struct EventObject *, struct Sprite *);
u8 sub_8090648(struct EventObject *, struct Sprite *);
u8 sub_80906D4(struct EventObject *, struct Sprite *);
u8 sub_80906E8(struct EventObject *, struct Sprite *);
u8 sub_8090714(struct EventObject *, struct Sprite *);
u8 sub_8090758(struct EventObject *, struct Sprite *);
u8 sub_8090788(struct EventObject *, struct Sprite *);
u8 sub_8090814(struct EventObject *, struct Sprite *);
u8 sub_8090828(struct EventObject *, struct Sprite *);
u8 sub_8090854(struct EventObject *, struct Sprite *);
u8 sub_8090898(struct EventObject *, struct Sprite *);
u8 sub_80908C8(struct EventObject *, struct Sprite *);
u8 sub_8090954(struct EventObject *, struct Sprite *);
u8 sub_8090968(struct EventObject *, struct Sprite *);
u8 sub_8090994(struct EventObject *, struct Sprite *);
u8 sub_80909D8(struct EventObject *, struct Sprite *);
u8 sub_8090A08(struct EventObject *, struct Sprite *);
u8 sub_8090A94(struct EventObject *, struct Sprite *);
u8 sub_8090AA8(struct EventObject *, struct Sprite *);
u8 sub_8090AD4(struct EventObject *, struct Sprite *);
u8 sub_8090B18(struct EventObject *, struct Sprite *);
u8 sub_8090B48(struct EventObject *, struct Sprite *);
u8 sub_8090BD4(struct EventObject *, struct Sprite *);
u8 sub_8090BE8(struct EventObject *, struct Sprite *);
u8 sub_8090C14(struct EventObject *, struct Sprite *);
u8 sub_8090C58(struct EventObject *, struct Sprite *);
u8 sub_8090C88(struct EventObject *, struct Sprite *);
u8 sub_8090D14(struct EventObject *, struct Sprite *);
u8 sub_8090D40(struct EventObject *, struct Sprite *);
u8 sub_8090D64(struct EventObject *, struct Sprite *);
u8 sub_8090D90(struct EventObject *, struct Sprite *);
u8 sub_8090E18(struct EventObject *, struct Sprite *);
u8 sub_8090E44(struct EventObject *, struct Sprite *);
u8 sub_8090E68(struct EventObject *, struct Sprite *);
u8 sub_8090E94(struct EventObject *, struct Sprite *);
u8 sub_8090F1C(struct EventObject *, struct Sprite *);
u8 sub_8090F30(struct EventObject *, struct Sprite *);
u8 sub_8090F68(struct EventObject *, struct Sprite *);
u8 sub_8091020(struct EventObject *, struct Sprite *);
u8 sub_8091048(struct EventObject *, struct Sprite *);
u8 sub_809117C(struct EventObject *, struct Sprite *);
u8 sub_8091110(struct EventObject *, struct Sprite *);
u8 sub_8091208(struct EventObject *, struct Sprite *);
u8 sub_8091294(struct EventObject *, struct Sprite *);
u8 sub_8091320(struct EventObject *, struct Sprite *);
u8 sub_80913AC(struct EventObject *, struct Sprite *);
u8 sub_8091438(struct EventObject *, struct Sprite *);
u8 sub_80914C4(struct EventObject *, struct Sprite *);
u8 sub_8091550(struct EventObject *, struct Sprite *);
u8 sub_80915DC(struct EventObject *, struct Sprite *);
u8 sub_8091668(struct EventObject *, struct Sprite *);
u8 sub_80916F4(struct EventObject *, struct Sprite *);
u8 sub_8091780(struct EventObject *, struct Sprite *);
u8 sub_809180C(struct EventObject *, struct Sprite *);
u8 sub_8091898(struct EventObject *, struct Sprite *);
u8 sub_8091924(struct EventObject *, struct Sprite *);
u8 sub_80919B0(struct EventObject *, struct Sprite *);
u8 sub_8091A3C(struct EventObject *, struct Sprite *);
u8 sub_8091AC8(struct EventObject *, struct Sprite *);
u8 sub_8091B54(struct EventObject *, struct Sprite *);
u8 sub_8091BE0(struct EventObject *, struct Sprite *);
u8 sub_8091C6C(struct EventObject *, struct Sprite *);
u8 sub_8091CF8(struct EventObject *, struct Sprite *);
u8 sub_8091D84(struct EventObject *, struct Sprite *);
u8 sub_8091E10(struct EventObject *, struct Sprite *);
u8 mss_npc_reset_oampriv3_1_unk2_unk3(struct EventObject *, struct Sprite *);
u8 sub_8091EC0(struct EventObject *, struct Sprite *);
u8 sub_8091F20(struct EventObject *, struct Sprite *);
bool8 sub_8091F48(struct EventObject *, struct Sprite *, u8, bool8(u8));
bool8 sub_8091F4C(struct EventObject *, struct Sprite *, u8, bool8(u8));
bool8 sub_8091F94(struct EventObject *, struct Sprite *, u8, bool8(u8));
bool8 sub_80920A4(struct EventObject *, struct Sprite *, u8, bool8(u8));
bool8 sub_809215C(struct EventObject *, struct Sprite *, u8, bool8(u8));
bool8 sub_8092214(struct EventObject *, struct Sprite *, u8, bool8(u8));
bool8 cph_IM_DIFFERENT(struct EventObject *, struct Sprite *, u8, bool8(u8));
bool8 sub_8092314(struct EventObject *, struct Sprite *, u8, bool8(u8));
bool8 oac_hopping(struct EventObject *, struct Sprite *, u8, bool8(u8));
u8 mss_08062EA4(struct EventObject *, struct Sprite *);
u8 sub_80926AC(struct EventObject *, struct Sprite *);
u8 sub_8092718(struct EventObject *, struct Sprite *);
u8 sub_80926B8(struct EventObject *, struct Sprite *);
u8 sub_8092788(struct EventObject *, struct Sprite *);
u8 sub_80927F8(struct EventObject *, struct Sprite *);
u8 sub_8092868(struct EventObject *, struct Sprite *);
u8 sub_80928D8(struct EventObject *, struct Sprite *);
u8 sub_809290C(struct EventObject *, struct Sprite *);
u8 sub_809292C(struct EventObject *, struct Sprite *);

// Exported data declarations

extern const struct SpriteTemplate *const gFieldEffectObjectTemplatePointers[];

#endif //GUARD_FIELD_EVENT_OBJ_H
