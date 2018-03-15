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
u8 sub_81546C8(u8, u8, u8, s16, s16);

void SetUpReflection(struct MapObject *mapObj, struct Sprite *sprite, u8 a);//added
u32 oe_exec_and_other_stuff(u8 fieldEffectId, struct MapObject *mapObject);//added
#endif //GUARD_FIELD_EFFECT_HELPERS_H
