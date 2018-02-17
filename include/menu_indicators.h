#ifndef GUARD_MENU_INDICATORS_H
#define GUARD_MENU_INDICATORS_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations

struct ArrowStruct {
    u8 unk0[6];
    u16 unk6[4];
    u8 unkE;
};

void Task_ScrollIndicatorArrowPairOnMainMenu(u8);
u8 AddScrollIndicatorArrowPairParametrized(u8, u8, u8, u8, s32, u16, u16, u16 *);
void RemoveScrollIndicatorArrowPair(u8);
u8 AddScrollIndicatorArrowPair(const struct ArrowStruct*, void*);
void sub_81AF15C(u8, u8, u8);

#endif //GUARD_MENU_INDICATORS_H
