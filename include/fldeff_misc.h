#ifndef GUARD_FLDEFF_MISC_H
#define GUARD_FLDEFF_MISC_H

void PopSecretBaseBalloon(s16 id, s16 x, s16 y);
void ShatterSecretBaseBreakableDoor(s16 x, s16 y);
u8 CreateRecordMixingSprite(void);
void DestroyRecordMixingSprite(void);
void FldEffPoison_Start(void);
void PlaySecretBaseMusicNoteMatSound(s16 metatileId);
void DoSecretBaseGlitterMatSparkle(void);
bool8 sub_80FADE4(u16, u8);

extern struct MapPosition gPlayerFacingPosition;
extern const struct SpriteTemplate *const gFieldEffectObjectTemplatePointers[];

extern u8 EventScript_275A86[];
extern u8 EventScript_275ADF[];
extern u8 EventScript_275B38[];

extern const struct OamData gEventObjectBaseOam_32x8;

extern const u16 gTilesetPalettes_SecretBase[][16];

#endif //GUARD_FLDEFF_MISC_H
