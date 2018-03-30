#ifndef GUARD_ITEM_MENU_ICONS
#define GUARD_ITEM_MENU_ICONS

extern const struct CompressedSpriteSheet gUnknown_0857FB34;
extern const struct CompressedSpriteSheet gUnknown_0857FB3C;
extern const struct CompressedSpritePalette gUnknown_0857FB44;
extern const struct CompressedSpriteSheet gUnknown_0857FDEC;
extern const struct CompressedSpritePalette gUnknown_0857FDF4;

void RemoveBagSprite(u8 id);
void AddBagVisualSprite(u8 bagPocketId);
void SetBagVisualPocketId(u8 bagPocketId, bool8 isSwitchingPockets);
void ShakeBagVisual(void);
void AddSwitchPocketRotatingBallSprite(s16 rotationDirection);
void AddBagItemIconSprite(u16 itemId, u8 id);
void RemoveBagItemIconSprite(u8 id);
void sub_80D4FAC(void);
void sub_80D4FC8(u8 arg0);
void sub_80D4FEC(u8 arg0);
u8 CreateBerryTagSprite(u8 id, s16 x, s16 y);
void FreeBerryTagSpritePalette(void);
u8 sub_80D511C(u8 berryId, u8 x, u8 y, bool8 startAffine);
u8 CreateBerryFlavorCircleSprite(s16 x);

#endif // GUARD_ITEM_MENU_ICONS
