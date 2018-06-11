#ifndef GUARD_FIELD_MAP_OBJ_H
#define GUARD_FIELD_MAP_OBJ_H

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

struct PairedPalettes {
    u16 tag;
    const u16 *data;
};

extern const struct SpriteFrameImage gFieldObjectPicTable_PechaBerryTree[];

void sub_808D438(void);
u8 get_go_image_anim_num(u8);
u8 GetFieldObjectIdByLocalIdAndMap(u8, u8, u8);
bool8 TryGetFieldObjectIdByLocalIdAndMap(u8, u8, u8, u8 *);
u8 GetFieldObjectIdByXY(s16, s16);
void FieldObjectSetDirection(struct MapObject *, u8);
u8 sub_808D4F4(void);
void RemoveFieldObjectByLocalIdAndMap(u8, u8, u8);
void npc_load_two_palettes__no_record(u16, u8);
void npc_load_two_palettes__and_record(u16, u8);
void sub_808EBA8(u8, u8, u8, s16, s16);
void pal_patch_for_npc(u16, u8);
void sub_808E16C(s16, s16);
void sub_808F28C(u8 localId, u8 mapNum, u8 mapGroup, u8 decorCat);
void sub_8092FF0(s16, s16, s16 *, s16 *);
u8 FieldObjectDirectionToImageAnimId(u8);
void sub_80930E0(s16 *, s16 *, s16, s16);
void FieldObjectClearAnim(struct MapObject *);
void FieldObjectClearAnimIfSpecialAnimActive(struct MapObject *);
void SpawnFieldObjectsInView(s16, s16);
u8 sprite_new(u8, u8, s16, s16, u8, u8);
u8 AddPseudoFieldObject(u16, void (*)(struct Sprite *), s16, s16, u8);
u8 show_sprite(u8, u8, u8);
u8 SpawnSpecialFieldObjectParametrized(u8, u8, u8, s16, s16, u8);
u8 SpawnSpecialFieldObject(struct MapObjectTemplate *);
void sub_8093038(s16, s16, s16 *, s16 *);
void CameraObjectReset1(void);
void FieldObjectSetGraphicsId(struct MapObject *, u8);
void FieldObjectTurn(struct MapObject *, u8);
void FieldObjectTurnByLocalIdAndMap(u8, u8, u8, u8);
const struct MapObjectGraphicsInfo *GetFieldObjectGraphicsInfo(u8);
void npc_by_local_id_and_map_set_field_1_bit_x20(u8, u8, u8, u8);
void gpu_pal_allocator_reset__manage_upper_four(void);
void sub_808E82C(u8, u8, u8, s16, s16);
void sub_808E7E4(u8, u8, u8);
void sub_808E78C(u8, u8, u8, u8);
void sub_808E75C(s16, s16);
void FieldObjectGetLocalIdAndMap(struct MapObject *mapObject, void *localId, void *mapNum, void *mapGroup);
void npc_coords_shift(struct MapObject *, s16, s16);
void sub_808EB08(struct MapObject *, s16, s16);
void sub_808F254(u8, u8, u8);
void FieldObjectStep(struct MapObject *, struct Sprite *, bool8(struct MapObject *, struct Sprite *));
u8 FieldObjectFaceOppositeDirection(struct MapObject *, u8);
u8 GetOppositeDirection(u8);
u8 GetStepInPlaceDelay4AnimId(u32);
u8 GetStepInPlaceDelay8AnimId(u32);
u8 GetStepInPlaceDelay16AnimId(u32);
u8 GetStepInPlaceDelay32AnimId(u32);
u8 npc_block_way(struct MapObject *, s16, s16, u32);
void MoveCoords(u8, s16 *, s16 *);
bool8 FieldObjectIsSpecialAnimActive(struct MapObject *);
u8 FieldObjectClearAnimIfSpecialAnimFinished(struct MapObject *);
u8 GetFieldObjectIdByXYZ(u16 x, u16 y, u8 z);
void npc_set_running_behaviour_etc(struct MapObject *mapObject, u8 movementType);
u8 npc_running_behaviour_by_direction(u8 direction);
const u8 *GetFieldObjectScriptPointerByFieldObjectId(u8 mapObjectId);
u8 sub_8092C8C(struct MapObject *mapObject, s16 x, s16 y, u8 direction);
u8 GetFaceDirectionAnimId(u32);
u8 GetGoSpeed0AnimId(u32);
u8 GetGoSpeed1AnimId(u32);
u8 GetGoSpeed3AnimId(u32);
u8 sub_80934BC(u32);
bool8 FieldObjectSetSpecialAnim(struct MapObject *mapObject, u8 specialAnimId);
bool8 FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive(struct MapObject *mapObject);
u8 FieldObjectCheckIfSpecialAnimFinishedOrInactive(struct MapObject *mapObject);
void sub_808F23C(const struct MapObject *mapObject, u8 movementType);
void sub_808F208(const struct MapObject *mapObject);
void npc_coords_shift_still(struct MapObject *pObject);
void FieldObjectMoveDestCoords(struct MapObject *pObject, u32 unk_19, s16 *pInt, s16 *pInt1);
u8 AddCameraObject(u8 linkedSpriteId);
void UpdateFieldObjectsForCameraUpdate(s16 x, s16 y);
u8 GetSimpleGoAnimId(u32);
u8 sub_8093514(u32);
bool8 AreZCoordsCompatible(u8, u8);
u8 ZCoordToPriority(u8);
void FieldObjectUpdateZCoord(struct MapObject *pObject);
void SetObjectSubpriorityByZCoord(u8, struct Sprite *, u8);
bool8 IsZCoordMismatchAt(u8, s16, s16);
void sub_8097AC8(struct Sprite *);
void npc_sync_anim_pause_bits(struct MapObject *);
void oamt_npc_ministep_reset(struct Sprite *, u8, u8);
u8 sub_8097F78(struct MapObject *);
bool8 obj_npc_ministep(struct Sprite *sprite);
bool8 sub_80976EC(struct Sprite *sprite);
void sub_80976DC(struct Sprite *, u8);
void sub_809783C(struct Sprite *, u8, u8, u8);
void DoShadowFieldEffect(struct MapObject *);
u8 sub_809785C(struct Sprite *);
u8 sub_80978E4(struct Sprite *);
void obj_anim_image_set_and_seek(struct Sprite *, u8, u8);
bool8 sub_80979BC(struct Sprite *);
void sub_8097750(struct Sprite *);
bool8 sub_8097758(struct Sprite *);
void sub_8097FA4(struct MapObject *);
void sub_8098044(u8);
void UnfreezeMapObjects(void);
void FreezeMapObjectsExceptOne(u8 mapObjectId);
void sub_8097B78(u8, u8);
void sub_8098074(u8 var1, u8 var2);
void FreezeMapObjects(void);
bool8 FreezeMapObject(struct MapObject *mapObject);
u8 get_go_fast_image_anim_num(u8);
u8 get_go_faster_image_anim_num(u8);
u8 get_go_fastest_image_anim_num(u8);

void FieldObjectCB_NoMovement1(struct Sprite *);
void FieldObjectCB_LookRandomDirections(struct Sprite *);
void FieldObjectCB_GoRandomDirections(struct Sprite *);
void FieldObjectCB_RandomlyGoNorthOrSouth(struct Sprite *);
void FieldObjectCB_RandomlyGoNorthOrSouth(struct Sprite *);
void FieldObjectCB_RandomlyGoEastOrWest(struct Sprite *);
void FieldObjectCB_RandomlyGoEastOrWest(struct Sprite *);
void FieldObjectCB_FaceFixedDirection(struct Sprite *);
void FieldObjectCB_FaceFixedDirection(struct Sprite *);
void FieldObjectCB_FaceFixedDirection(struct Sprite *);
void FieldObjectCB_FaceFixedDirection(struct Sprite *);
void FieldObjectCB_NoMovement2(struct Sprite *);
void FieldObjectCB_BerryTree(struct Sprite *);
void FieldObjectCB_RandomlyLookNorthOrSouth(struct Sprite *);
void FieldObjectCB_RandomlyLookEastOrWest(struct Sprite *);
void FieldObjectCB_RandomlyLookNorthOrWest(struct Sprite *);
void FieldObjectCB_RandomlyLookNorthOrEast(struct Sprite *);
void FieldObjectCB_RandomlyLookSouthOrWest(struct Sprite *);
void FieldObjectCB_RandomlyLookSouthOrEast(struct Sprite *);
void FieldObjectCB_RandomlyLookNorthOrSouthOrWest(struct Sprite *);
void FieldObjectCB_RandomlyLookNorthOrSouthOrEast(struct Sprite *);
void FieldObjectCB_RandomlyLookNorthOrEastOrWest(struct Sprite *);
void FieldObjectCB_RandomlyLookSouthOrEastOrWest(struct Sprite *);
void FieldObjectCB_LookAroundCounterclockwise(struct Sprite *);
void FieldObjectCB_LookAroundClockwise(struct Sprite *);
void FieldObjectCB_AlternatelyGoInOppositeDirections(struct Sprite *);
void FieldObjectCB_AlternatelyGoInOppositeDirections(struct Sprite *);
void FieldObjectCB_AlternatelyGoInOppositeDirections(struct Sprite *);
void FieldObjectCB_AlternatelyGoInOppositeDirections(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence1(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence2(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence3(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence4(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence5(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence6(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence7(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence8(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence9(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence10(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence11(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence12(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence13(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence14(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence15(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence16(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence17(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence18(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence19(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence20(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence21(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence22(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence23(struct Sprite *);
void FieldObjectCB_GoInDirectionSequence24(struct Sprite *);
void FieldObjectCB_CopyPlayer1(struct Sprite *);
void FieldObjectCB_CopyPlayer1(struct Sprite *);
void FieldObjectCB_CopyPlayer1(struct Sprite *);
void FieldObjectCB_CopyPlayer1(struct Sprite *);
void FieldObjectCB_TreeDisguise(struct Sprite *);
void FieldObjectCB_MountainDisguise(struct Sprite *);
void FieldObjectCB_CopyPlayer2(struct Sprite *);
void FieldObjectCB_CopyPlayer2(struct Sprite *);
void FieldObjectCB_CopyPlayer2(struct Sprite *);
void FieldObjectCB_CopyPlayer2(struct Sprite *);
void FieldObjectCB_Hidden1(struct Sprite *);
void FieldObjectCB_WalkInPlace1(struct Sprite *);
void FieldObjectCB_WalkInPlace1(struct Sprite *);
void FieldObjectCB_WalkInPlace1(struct Sprite *);
void FieldObjectCB_WalkInPlace1(struct Sprite *);
void FieldObjectCB_WalkInPlace2(struct Sprite *);
void FieldObjectCB_WalkInPlace2(struct Sprite *);
void FieldObjectCB_WalkInPlace2(struct Sprite *);
void FieldObjectCB_WalkInPlace2(struct Sprite *);
void FieldObjectCB_WalkInPlace3(struct Sprite *);
void FieldObjectCB_WalkInPlace3(struct Sprite *);
void FieldObjectCB_WalkInPlace3(struct Sprite *);
void FieldObjectCB_WalkInPlace3(struct Sprite *);
void FieldObjectCB_Hidden2(struct Sprite *);
void FieldObjectCB_WalkInPlace4(struct Sprite *);
void FieldObjectCB_WalkInPlace4(struct Sprite *);
void FieldObjectCB_WalkInPlace4(struct Sprite *);
void FieldObjectCB_WalkInPlace4(struct Sprite *);

u8 sub_808F44C(struct MapObject *, struct Sprite *);
u8 sub_808F460(struct MapObject *, struct Sprite *);
u8 sub_808F48C(struct MapObject *, struct Sprite *);
u8 sub_808F4C8(struct MapObject *, struct Sprite *);
u8 sub_808F4E8(struct MapObject *, struct Sprite *);
u8 sub_808F534(struct MapObject *, struct Sprite *);
u8 sub_808F564(struct MapObject *, struct Sprite *);
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
u8 sub_808F988(struct MapObject *, struct Sprite *);
u8 sub_808F99C(struct MapObject *, struct Sprite *);
u8 sub_808F9C8(struct MapObject *, struct Sprite *);
u8 sub_808FA0C(struct MapObject *, struct Sprite *);
u8 sub_808FA3C(struct MapObject *, struct Sprite *);
u8 sub_808FAC8(struct MapObject *, struct Sprite *);
u8 sub_808FADC(struct MapObject *, struct Sprite *);
u8 sub_808FB08(struct MapObject *, struct Sprite *);
u8 sub_808FB44(struct MapObject *, struct Sprite *);
u8 sub_808FB64(struct MapObject *, struct Sprite *);
u8 sub_808FBB0(struct MapObject *, struct Sprite *);
u8 sub_808FBE0(struct MapObject *, struct Sprite *);
u8 sub_808FC4C(struct MapObject *, struct Sprite *);
u8 sub_808FC60(struct MapObject *, struct Sprite *);
u8 sub_808FC8C(struct MapObject *, struct Sprite *);
u8 sub_808FCC8(struct MapObject *, struct Sprite *);
u8 sub_808FCE8(struct MapObject *, struct Sprite *);
u8 sub_808FD34(struct MapObject *, struct Sprite *);
u8 sub_808FD64(struct MapObject *, struct Sprite *);
u8 sub_808FDD0(struct MapObject *, struct Sprite *);
u8 sub_808FDFC(struct MapObject *, struct Sprite *);
u8 sub_808FE1C(struct MapObject *, struct Sprite *);
u8 do_berry_tree_growth_sparkle_1(struct MapObject *, struct Sprite *);
u8 sub_808FF48(struct MapObject *, struct Sprite *);
u8 do_berry_tree_growth_sparkle_2(struct MapObject *, struct Sprite *);
u8 sub_808FFB4(struct MapObject *, struct Sprite *);
u8 sub_8090004(struct MapObject *, struct Sprite *);
u8 sub_8090094(struct MapObject *, struct Sprite *);
u8 sub_80900A8(struct MapObject *, struct Sprite *);
u8 sub_80900D4(struct MapObject *, struct Sprite *);
u8 sub_8090118(struct MapObject *, struct Sprite *);
u8 sub_8090148(struct MapObject *, struct Sprite *);
u8 sub_80901D4(struct MapObject *, struct Sprite *);
u8 sub_80901E8(struct MapObject *, struct Sprite *);
u8 sub_8090214(struct MapObject *, struct Sprite *);
u8 sub_8090258(struct MapObject *, struct Sprite *);
u8 sub_8090288(struct MapObject *, struct Sprite *);
u8 sub_8090314(struct MapObject *, struct Sprite *);
u8 sub_8090328(struct MapObject *, struct Sprite *);
u8 sub_8090354(struct MapObject *, struct Sprite *);
u8 sub_8090398(struct MapObject *, struct Sprite *);
u8 sub_80903C8(struct MapObject *, struct Sprite *);
u8 sub_8090454(struct MapObject *, struct Sprite *);
u8 sub_8090468(struct MapObject *, struct Sprite *);
u8 sub_8090494(struct MapObject *, struct Sprite *);
u8 sub_80904D8(struct MapObject *, struct Sprite *);
u8 sub_8090508(struct MapObject *, struct Sprite *);
u8 sub_8090594(struct MapObject *, struct Sprite *);
u8 sub_80905A8(struct MapObject *, struct Sprite *);
u8 sub_80905D4(struct MapObject *, struct Sprite *);
u8 sub_8090618(struct MapObject *, struct Sprite *);
u8 sub_8090648(struct MapObject *, struct Sprite *);
u8 sub_80906D4(struct MapObject *, struct Sprite *);
u8 sub_80906E8(struct MapObject *, struct Sprite *);
u8 sub_8090714(struct MapObject *, struct Sprite *);
u8 sub_8090758(struct MapObject *, struct Sprite *);
u8 sub_8090788(struct MapObject *, struct Sprite *);
u8 sub_8090814(struct MapObject *, struct Sprite *);
u8 sub_8090828(struct MapObject *, struct Sprite *);
u8 sub_8090854(struct MapObject *, struct Sprite *);
u8 sub_8090898(struct MapObject *, struct Sprite *);
u8 sub_80908C8(struct MapObject *, struct Sprite *);
u8 sub_8090954(struct MapObject *, struct Sprite *);
u8 sub_8090968(struct MapObject *, struct Sprite *);
u8 sub_8090994(struct MapObject *, struct Sprite *);
u8 sub_80909D8(struct MapObject *, struct Sprite *);
u8 sub_8090A08(struct MapObject *, struct Sprite *);
u8 sub_8090A94(struct MapObject *, struct Sprite *);
u8 sub_8090AA8(struct MapObject *, struct Sprite *);
u8 sub_8090AD4(struct MapObject *, struct Sprite *);
u8 sub_8090B18(struct MapObject *, struct Sprite *);
u8 sub_8090B48(struct MapObject *, struct Sprite *);
u8 sub_8090BD4(struct MapObject *, struct Sprite *);
u8 sub_8090BE8(struct MapObject *, struct Sprite *);
u8 sub_8090C14(struct MapObject *, struct Sprite *);
u8 sub_8090C58(struct MapObject *, struct Sprite *);
u8 sub_8090C88(struct MapObject *, struct Sprite *);
u8 sub_8090D14(struct MapObject *, struct Sprite *);
u8 sub_8090D40(struct MapObject *, struct Sprite *);
u8 sub_8090D64(struct MapObject *, struct Sprite *);
u8 sub_8090D90(struct MapObject *, struct Sprite *);
u8 sub_8090E18(struct MapObject *, struct Sprite *);
u8 sub_8090E44(struct MapObject *, struct Sprite *);
u8 sub_8090E68(struct MapObject *, struct Sprite *);
u8 sub_8090E94(struct MapObject *, struct Sprite *);
u8 sub_8090F1C(struct MapObject *, struct Sprite *);
u8 sub_8090F30(struct MapObject *, struct Sprite *);
u8 sub_8090F68(struct MapObject *, struct Sprite *);
u8 sub_8091020(struct MapObject *, struct Sprite *);
u8 sub_8091048(struct MapObject *, struct Sprite *);
u8 sub_809117C(struct MapObject *, struct Sprite *);
u8 sub_8091110(struct MapObject *, struct Sprite *);
u8 sub_8091208(struct MapObject *, struct Sprite *);
u8 sub_8091294(struct MapObject *, struct Sprite *);
u8 sub_8091320(struct MapObject *, struct Sprite *);
u8 sub_80913AC(struct MapObject *, struct Sprite *);
u8 sub_8091438(struct MapObject *, struct Sprite *);
u8 sub_80914C4(struct MapObject *, struct Sprite *);
u8 sub_8091550(struct MapObject *, struct Sprite *);
u8 sub_80915DC(struct MapObject *, struct Sprite *);
u8 sub_8091668(struct MapObject *, struct Sprite *);
u8 sub_80916F4(struct MapObject *, struct Sprite *);
u8 sub_8091780(struct MapObject *, struct Sprite *);
u8 sub_809180C(struct MapObject *, struct Sprite *);
u8 sub_8091898(struct MapObject *, struct Sprite *);
u8 sub_8091924(struct MapObject *, struct Sprite *);
u8 sub_80919B0(struct MapObject *, struct Sprite *);
u8 sub_8091A3C(struct MapObject *, struct Sprite *);
u8 sub_8091AC8(struct MapObject *, struct Sprite *);
u8 sub_8091B54(struct MapObject *, struct Sprite *);
u8 sub_8091BE0(struct MapObject *, struct Sprite *);
u8 sub_8091C6C(struct MapObject *, struct Sprite *);
u8 sub_8091CF8(struct MapObject *, struct Sprite *);
u8 sub_8091D84(struct MapObject *, struct Sprite *);
u8 sub_8091E10(struct MapObject *, struct Sprite *);
u8 mss_npc_reset_oampriv3_1_unk2_unk3(struct MapObject *, struct Sprite *);
u8 sub_8091EC0(struct MapObject *, struct Sprite *);
u8 sub_8091F20(struct MapObject *, struct Sprite *);
bool8 sub_8091F48(struct MapObject *, struct Sprite *, u8, bool8(u8));
bool8 sub_8091F4C(struct MapObject *, struct Sprite *, u8, bool8(u8));
bool8 sub_8091F94(struct MapObject *, struct Sprite *, u8, bool8(u8));
bool8 sub_80920A4(struct MapObject *, struct Sprite *, u8, bool8(u8));
bool8 sub_809215C(struct MapObject *, struct Sprite *, u8, bool8(u8));
bool8 sub_8092214(struct MapObject *, struct Sprite *, u8, bool8(u8));
bool8 cph_IM_DIFFERENT(struct MapObject *, struct Sprite *, u8, bool8(u8));
bool8 sub_8092314(struct MapObject *, struct Sprite *, u8, bool8(u8));
bool8 oac_hopping(struct MapObject *, struct Sprite *, u8, bool8(u8));
u8 mss_08062EA4(struct MapObject *, struct Sprite *);
u8 sub_80926AC(struct MapObject *, struct Sprite *);
u8 sub_8092718(struct MapObject *, struct Sprite *);
u8 sub_80926B8(struct MapObject *, struct Sprite *);
u8 sub_8092788(struct MapObject *, struct Sprite *);
u8 sub_80927F8(struct MapObject *, struct Sprite *);
u8 sub_8092868(struct MapObject *, struct Sprite *);
u8 sub_80928D8(struct MapObject *, struct Sprite *);
u8 sub_809290C(struct MapObject *, struct Sprite *);
u8 sub_809292C(struct MapObject *, struct Sprite *);

// Exported data declarations

extern const struct SpriteTemplate *const gFieldEffectObjectTemplatePointers[];

#endif //GUARD_FIELD_MAP_OBJ_H
