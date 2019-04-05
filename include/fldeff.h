#ifndef GUARD_FLDEFF_H
#define GUARD_FLDEFF_H

// cut
bool8 SetUpFieldMove_Cut(void);
bool8 FldEff_UseCutOnGrass(void);
bool8 FldEff_UseCutOnTree(void);
bool8 FldEff_CutGrass(void);
void FixLongGrassMetatilesWindowTop(s16 x, s16 y);
void FixLongGrassMetatilesWindowBottom(s16 x, s16 y);

extern const struct SpritePalette gFieldEffectObjectPaletteInfo6;
extern struct MapPosition gPlayerFacingPosition;

// groundshake
bool8 sub_81BE66C(void);
void sub_81BE6AC(void);
void sub_81BE6B8(void);
void sub_81BE72C(void);
void sub_81BE79C(void);
void sub_81BE7F4(void);
void sub_81BE994(void);

// escalator
void sub_80E1558(u8 var);
void sub_80E1570(void);
bool8 sub_80E1584(void);

// soft-boiled
bool8 SetUpFieldMove_SoftBoiled(void);
void sub_81615A8(u8 taskId);
void sub_8161560(u8 taskId);

// flash
bool8 SetUpFieldMove_Flash(void);
void c2_change_map(void);
bool8 GetMapPairFadeToType(u8 a1, u8 a2);
bool8 GetMapPairFadeFromType(u8 a1, u8 a2);

// strength
bool8 SetUpFieldMove_Strength(void);
bool8 sub_8145E2C(void);

// sweet scent
bool8 SetUpFieldMove_SweetScent(void);
bool8 FldEff_SweetScent(void);

// teleport
bool8 SetUpFieldMove_Teleport(void);
bool8 FldEff_UseTeleport(void);

// dig
bool8 SetUpFieldMove_Dig(void);
bool8 FldEff_UseDig(void);

// rock smash
bool8 CheckObjectGraphicsInFrontOfPlayer(u8 graphicsId);
u8 oei_task_add(void);
bool8 SetUpFieldMove_RockSmash(void);
bool8 FldEff_UseRockSmash(void);

#endif // GUARD_FLDEFF_H
