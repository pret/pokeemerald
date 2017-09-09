#ifndef POKEEMERALD_FIELD_MAP_OBJ_H
#define POKEEMERALD_FIELD_MAP_OBJ_H

#define NUM_OBJECT_GRAPHICS_INFO 239
#define SPRITE_VAR 240

// Exported struct declarations

// Exported RAM declarations

// Exported ROM declarations

void sub_808D438(void);
u8 GetFieldObjectIdByLocalIdAndMap(u8, u8, u8);
bool8 TryGetFieldObjectIdByLocalIdAndMap(u8, u8, u8, u8 *);
u8 GetFieldObjectIdByXY(s16, s16);
void FieldObjectSetDirection(struct MapObject *, u8);
u8 sub_808D4F4(void);
void RemoveFieldObjectByLocalIdAndMap(u8, u8, u8);
void npc_load_two_palettes__no_record(u16, u8);
void npc_load_two_palettes__and_record(u16, u8);
void pal_patch_for_npc(u16, u8);
void sub_808E16C(s16, s16);
void sub_8092FF0(s16, s16, s16 *, s16 *);
u8 FieldObjectDirectionToImageAnimId(u8);
void sub_80930E0(s16 *, s16 *, u8, u8);
void FieldObjectClearAnim(struct MapObject *);
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
void FieldObjectGetLocalIdAndMap(struct MapObject *, u8 *, u8 *, u8 *);
void npc_coords_shift(struct MapObject *, s16, s16);
void sub_808EB08(struct MapObject *, s16, s16);

// Exported data declarations

extern const struct SpriteTemplate *const gFieldEffectObjectTemplatePointers[];

#endif //POKEEMERALD_FIELD_MAP_OBJ_H
