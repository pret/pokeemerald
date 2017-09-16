//
// Created by scott on 9/6/2017.
//

#ifndef GUARD_FIELD_GROUND_EFFECT_H
#define GUARD_FIELD_GROUND_EFFECT_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations
void SetObjectSubpriorityByZCoord(u8, struct Sprite *, u8);
void InitObjectPriorityByZCoord(struct Sprite *, u8);
bool8 IsZCoordMismatchAt(u8, s16, s16);

#endif //GUARD_FIELD_GROUND_EFFECT_H
