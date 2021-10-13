#ifndef POKEEMERALD_MON_MARKINGS_H
#define POKEEMERALD_MON_MARKINGS_H

#define NUM_MON_MARKINGS 4

struct PokemonMarkMenu
{
    /*0x0000*/ u16 baseTileTag;
    /*0x0002*/ u16 basePaletteTag;
    /*0x0004*/ u8 markings; // bit flags
    /*0x0005*/ s8 cursorPos;
    /*0x0006*/ bool8 markingsArray[NUM_MON_MARKINGS];
    /*0x000A*/ u8 cursorBaseY;
    /*0x000B*/ bool8 spriteSheetLoadRequired;
    /*0x000C*/ struct Sprite *menuWindowSprites[2]; // upper and lower halves of menu window
    /*0x0014*/ struct Sprite *menuMarkingSprites[NUM_MON_MARKINGS];
    /*0x0024*/ struct Sprite *unkSprite;
    /*0x0028*/ struct Sprite *menuTextSprite;
    /*0x002C*/ const u8 *frameTiles;
    /*0x0030*/ const u16 *framePalette;
    /*0x0034*/ u8 menuWindowSpriteTiles[0x1000];
    /*0x1034*/ u8 filler1030[0x80];
    /*0x10B4*/ u8 tileLoadState;
}; // 10b8

void sub_811F90C(struct PokemonMarkMenu *ptr);
void sub_811F918(void);
bool8 sub_811F960(void);
void sub_811FA90(void);
void sub_811FAA4(u8 markings, s16 x, s16 y);
void sub_811FAF8(void);
bool8 MonMarkingsMenuHandleInput(void);
struct Sprite *CreateMonMarkingsSpriteWithPal(u16 tileTag, u16 paletteTag, const u16 *palette);
struct Sprite *sub_811FFB4(u16 tileTag, u16 paletteTag, const u16 *palette);
void sub_8120084(u8 markings, void *dest);

#endif //POKEEMERALD_MON_MARKINGS_H
