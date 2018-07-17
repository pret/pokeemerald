#ifndef GUARD_FLDEFF_CUT_H
#define GUARD_FLDEFF_CUT_H

extern const struct SpritePalette gFieldEffectObjectPaletteInfo6;

bool8 SetUpFieldMove_Cut(void);
bool8 FldEff_UseCutOnGrass(void);
bool8 FldEff_UseCutOnTree(void);
bool8 FldEff_CutGrass(void);
void sub_80D423C(s16 x, s16 y);
void sub_80D42B8(s16 x, s16 y);

#endif // GUARD_FLDEFF_CUT_H
