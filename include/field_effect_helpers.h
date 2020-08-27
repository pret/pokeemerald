#ifndef GUARD_FIELD_EFFECT_HELPERS_H
#define GUARD_FIELD_EFFECT_HELPERS_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations
u8 CreateWarpArrowSprite(void);
u8 sub_8155800(u8 oldSpriteId);
void SetSurfBobState(u8 spriteId, u8 value);
void SetSurfBobWhileFlyingOutState(u8 spriteId, u8 value);
void SetSurfBobWhileFishingState(u8 spriteId, u8 value, s16 data1);
bool8 sub_8155DA0(struct ObjectEvent *);
void sub_8155D78(struct ObjectEvent *);
void StartAshFieldEffect(s16, s16, u16, s16);
void SetUpReflection(struct ObjectEvent*, struct Sprite*, u8);
u32 StartFieldEffectForObjectEvent(u8, struct ObjectEvent*);
u8 FindTallGrassFieldEffectSpriteId(u8 localId, u8 mapNum, u8 mapGroup, s16 x, s16 y);
void UpdateRayquazaSpotlightEffect(struct Sprite*);
void UpdateShadowFieldEffect(struct Sprite*);
void UpdateTallGrassFieldEffect(struct Sprite*);
void WaitFieldEffectSpriteAnim(struct Sprite*);
void UpdateAshFieldEffect(struct Sprite*);
void UpdateSurfBlobFieldEffect(struct Sprite*);
void UpdateJumpImpactEffect(struct Sprite*);
void UpdateFootprintsTireTracksFieldEffect(struct Sprite*);
void UpdateSplashFieldEffect(struct Sprite*);
void UpdateLongGrassFieldEffect(struct Sprite*);
void UpdateSandPileFieldEffect(struct Sprite*);
void UpdateDisguiseFieldEffect(struct Sprite*);
void UpdateShortGrassFieldEffect(struct Sprite*);
void UpdateHotSpringsWaterFieldEffect(struct Sprite*);
void UpdateBubblesFieldEffect(struct Sprite*);
void UpdateSparkleFieldEffect(struct Sprite*);
void SetSpriteInvisible(u8 spriteId);
void ShowWarpArrowSprite(u8 spriteId, u8 direction, s16 x, s16 y);

#endif //GUARD_FIELD_EFFECT_HELPERS_H
