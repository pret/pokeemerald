#ifndef GUARD_ITEM_MENU_ICONS_H
#define GUARD_ITEM_MENU_ICONS_H

extern const struct CompressedSpriteSheet gBagMaleSpriteSheet;
extern const struct CompressedSpriteSheet gBagFemaleSpriteSheet;
extern const struct SpritePalette gBagPaletteTable;
extern const struct CompressedSpriteSheet gBerryCheckCircleSpriteSheet;
extern const struct SpritePalette gBerryCheckCirclePaletteTable;

void RemoveBagSprite(u8 id);
void AddBagVisualSprite(u8 bagPocketId);
void SetBagVisualPocketId(u8 bagPocketId, bool8 isSwitchingPockets);
void ShakeBagSprite(void);
void AddSwitchPocketRotatingBallSprite(s16 rotationDirection);
void AddBagItemIconSprite(enum Item itemId, u8 id);
void RemoveBagItemIconSprite(u8 id);
void CreateItemMenuSwapLine(void);
void SetItemMenuSwapLineInvisibility(bool8 invisible);
void UpdateItemMenuSwapLinePos(u8 y);

// Note: Because of removing gDecompressionBuffer and allowing to create more than one berry sprite at a time, the memory for gfx is allocated dynamically.
// For CreateBerryTagSprite and CreateSpinningBerrySprite, the allocated ptr is stored in two last data fields(data[6], data[7]), so make sure to NOT put anything in there!
// The corresponding code has already been edited in berry_tag_screen.c and berry_blender.c
#define BERRY_ICON_GFX_PTR_DATA_ID 6
u32 CreateBerryTagSprite(u32 id, s32 x, s32 y);
u32 CreateSpinningBerrySprite(u32 berryId, s32 x, s32 y, bool32 startAffine);
// Needs to always call either of these after creating a Berry Icon sprite, because it frees allocated memory!
void DestroyBerryIconSprite(u32 spriteId, u32 berryId, bool32 freePal);
void DestroyBerryIconSpritePtr(struct Sprite *sprite, u32 berryId, bool32 freePal);

void FreeBerryIconSpritePalette(u32 berryId); // Unused atm, because it's also handled by DestroyBerryIconSprite. Leaving it as it is, because it may still be useful in some custom cases.

u8 CreateBerryFlavorCircleSprite(s16 x);

#endif // GUARD_ITEM_MENU_ICONS_H
