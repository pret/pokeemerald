#ifndef GUARD_MENU_INDICATORS_H
#define GUARD_MENU_INDICATORS_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations
u8 AddScrollIndicatorArrowPairParametrized(u8, u8, u8, u8, s32, u16, u16, u16 *);
void RemoveScrollIndicatorArrowPair(u8);
u8 AddScrollIndicatorArrowPair(void*, void*);
void sub_81AF15C(u8, u8, u8);

#endif //GUARD_MENU_INDICATORS_H
