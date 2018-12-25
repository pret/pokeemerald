#ifndef GUARD_FLDEFF_MISC_H
#define GUARD_FLDEFF_MISC_H

void sub_80F9BCC(u16 a0, u16 a1, u8 a2);
void sub_80F9BF4(u16 a0, u16 a1, u8 a2);
bool8 sub_80F9C1C(void);
bool8 sub_80F9C30(void);
bool8 SetUpFieldMove_SecretPower(void);
bool8 FldEff_UseSecretPowerCave(void);
bool8 FldEff_SecretPowerCave(void);
bool8 FldEff_UseSecretPowerTree(void);
bool8 FldEff_SecretPowerTree(void);
bool8 FldEff_UseSecretPowerShrub(void);
bool8 FldEff_SecretPowerShrub(void);
bool8 FldEff_SecretBasePCTurnOn(void);
void DoSecretBasePCTurnOffEffect(void);
void PopSecretBaseBalloon(s16 metatileId, s16 x, s16 y);
bool8 FldEff_NopA6FC(void);
bool8 FldEff_NopA700(void);
void ShatterSecretBaseBreakableDoor(s16 x, s16 y);
void PlaySecretBaseMusicNoteMatSound(s16 metatileId);
void DoSecretBaseGlitterMatSparkle(void);
bool8 FldEff_SandPillar(void);
void GetShieldToyTVDecorationInfo(void);
bool8 sub_80FADE4(u16 arg0, u8 arg1);
void FldEffPoison_Start(void);
bool32 FldEffPoison_IsActive(void);
void DoWateringBerryTreeAnim(void);
u8 CreateRecordMixingSprite(void);
void DestroyRecordMixingSprite(void);

extern const struct SpritePalette gFieldEffectObjectPaletteInfo7;
extern const struct SpritePalette gFieldEffectObjectPaletteInfo8;
extern const struct SpritePalette gFieldEffectObjectPaletteInfo9;
extern const u16 gTilesetPalettes_SecretBase[][16];

#endif //GUARD_FLDEFF_MISC_H
