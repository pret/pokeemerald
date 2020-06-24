#ifndef GUARD_FIELD_EFFECTS_H
#define GUARD_FIELD_EFFECTS_H

extern const struct SpritePalette gNewGameBirchObjectPaletteInfo;
extern const struct SpriteTemplate gNewGameBirchObjectTemplate;
extern const struct OamData gNewGameBirchOamAttributes;

extern s32 gFieldEffectArguments[8];
extern void (*gPostMenuFieldCallback)(void);
extern bool8 (*gFieldCallback2)(void);

u32 FieldEffectStart(u8);
bool8 FieldEffectActiveListContains(u8 id);
void FieldEffectActiveListClear(void);
void ReturnToFieldFromFlyMapSelect(void);
u8 AddNewGameBirchObject(s16, s16, u8);
void FieldEffectStop(struct Sprite *sprite, u8 id);
u8 CreateTrainerSprite(u8 trainerSpriteID, s16 x, s16 y, u8 subpriority, u8 *buffer);
void FldEff_TeleportWarpOut(void);
void FieldEffectActiveListRemove(u8 id);
void MultiplyInvertedPaletteRGBComponents(u16, u8, u8, u8);
void FieldEffectActiveListAdd(u8 id);
void FieldEffectScript_LoadTiles(u8 **script);
void FieldEffectScript_LoadFadedPalette(u8 **script);
void FieldEffectScript_LoadPalette(u8 **script);
void FieldEffectScript_CallNative(u8 **script, u32 *val);
void FieldEffectFreeTilesIfUnused(u16 tileStart);
void FieldEffectFreePaletteIfUnused(u8 paletteNum);
bool8 FieldEffectCmd_loadtiles(u8 **script, u32 *val);
bool8 FieldEffectCmd_loadfadedpal(u8 **script, u32 *val);
bool8 FieldEffectCmd_loadpal(u8 **script, u32 *val);
bool8 FieldEffectCmd_callnative(u8 **script, u32 *val);
bool8 FieldEffectCmd_end(u8 **script, u32 *val);
bool8 FieldEffectCmd_loadgfx_callnative(u8 **script, u32 *val);
bool8 FieldEffectCmd_loadtiles_callnative(u8 **script, u32 *val);
bool8 FieldEffectCmd_loadfadedpal_callnative(u8 **script, u32 *val);
void FieldCB_FallWarpExit(void);
void StartEscalatorWarp(u8 metatileBehavior, u8 priority);
void StartLavaridgeGymB1FWarp(u8 priority);
void StartLavaridgeGym1FWarp(u8 priority);

void SpriteCB_AshPuff(struct Sprite*);
void SpriteCB_AshLaunch(struct Sprite*);

void MultiplyPaletteRGBComponents(u16 i, u8 r, u8 g, u8 b);
void FreeResourcesAndDestroySprite(struct Sprite *sprite, u8 spriteId);
u8 CreateMonSprite_PicBox(u16 species, s16 x, s16 y, u8 subpriority);
void StartEscapeRopeFieldEffect(void);

#endif // GUARD_FIELD_EFFECTS_H
