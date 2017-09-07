#ifndef POKEEMERALD_FIELD_MAP_OBJ_H
#define POKEEMERALD_FIELD_MAP_OBJ_H

// Exported struct declarations

// Exported RAM declarations



// Exported ROM declarations

void sub_808D438(void);
u8 GetFieldObjectIdByLocalIdAndMap(u8, u8, u8);
bool8 TryGetFieldObjectIdByLocalIdAndMap(u8, u8, u8, u8 *);
u8 GetFieldObjectIdByXY(s16, s16);
void FieldObjectSetDirection(struct MapObject *, u8);
u8 GetFieldObjectIdByXY(s16, s16);
u8 sub_808D4F4(void);
void RemoveFieldObject(struct MapObject *);
void RemoveFieldObjectByLocalIdAndMap(u8, u8, u8);
void npc_load_two_palettes__no_record(u16, u8);
void npc_load_two_palettes__and_record(u16, u8);
void sub_808EAB0(u16, u8);
void sub_8092FF0(s16, s16, s16 *, s16 *);
u8 FieldObjectDirectionToImageAnimId(u8);
void sub_80930E0(s16 *, s16 *, u8, u8);

// Exported data declarations

extern const struct SpriteTemplate *const gFieldEffectObjectTemplatePointers[];

#endif //POKEEMERALD_FIELD_MAP_OBJ_H
