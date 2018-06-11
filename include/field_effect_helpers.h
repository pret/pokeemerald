//
// Created by scott on 9/7/2017.
//

#ifndef GUARD_FIELD_EFFECT_HELPERS_H
#define GUARD_FIELD_EFFECT_HELPERS_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations
u8 sub_8154228(void);
bool8 sub_8155DA0(struct MapObject *);
void sub_8155D78(struct MapObject *);
void sub_81555AC(u8, u8);
void ash(s16, s16, u16, s16);
void SetUpReflection(struct MapObject*, struct Sprite*, u8);
u32 StartFieldEffectForEventObject(u8, struct MapObject*);
u8 sub_81546C8(u8, u8, u8, s16, s16);
void sub_8155F80(struct Sprite*);
void oamc_shadow(struct Sprite*);
void unc_grass_normal(struct Sprite*);
void sub_81561D0(struct Sprite*);
void sub_8155460(struct Sprite*);
void sub_8155658(struct Sprite*);
void sub_8156194(struct Sprite*);
void sub_8154C60(struct Sprite*);
void sub_8154D90(struct Sprite*);
void unc_grass_tall(struct Sprite*);
void sub_81559BC(struct Sprite*);
void sub_8155C88(struct Sprite*);
void sub_8154A10(struct Sprite*);
void sub_8155158(struct Sprite*);
void sub_8155AEC(struct Sprite*);
void sub_8155E50(struct Sprite*);

#endif //GUARD_FIELD_EFFECT_HELPERS_H
