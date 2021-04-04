#ifndef MON_MARKINGS_H
#define MON_MARKINGS_H

#define NUM_MON_MARKINGS 4

struct MonMarkingsMenu
{
    u16 baseTileTag;
    u16 basePaletteTag;
    u8 markings; // bit flags
    s8 cursorPos;
    bool8 markingsArray[NUM_MON_MARKINGS];
    u8 cursorBaseY;
    bool8 spriteSheetLoadRequired;
    struct Sprite *windowSprites[2]; // upper and lower halves of menu window
    struct Sprite *markingSprites[NUM_MON_MARKINGS];
    struct Sprite *cursorSprite;
    struct Sprite *textSprite;
    const u8 *frameTiles;
    const u16 *framePalette;
    u8 windowSpriteTiles[0x1000];
    u8 unused[0x80];
    u8 tileLoadState;
};

void InitMonMarkingsMenu(struct MonMarkingsMenu *ptr);
void BufferMonMarkingsMenuTiles(void);
void OpenMonMarkingsMenu(u8 markings, s16 x, s16 y);
void FreeMonMarkingsMenu(void);
bool8 HandleMonMarkingsMenuInput(void);
struct Sprite *CreateMonMarkingAllCombosSprite(u16 tileTag, u16 paletteTag, const u16 *palette);
struct Sprite *CreateMonMarkingComboSprite(u16 tileTag, u16 paletteTag, const u16 *palette);
void UpdateMonMarkingTiles(u8 markings, void *dest);

#endif //MON_MARKINGS_H
