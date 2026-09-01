#ifndef GUARD_POKEMON_ICON_H
#define GUARD_POKEMON_ICON_H

extern const struct SpritePalette gMonIconPaletteTable[];

enum SpeciesIconType {
    NORMAL_ICON,
    FEMALE_ICON,
    EGG_ICON
};

const u8 *GetMonIconTiles(enum Species species, u32 personality);
const u8 *GetMonIconTilesIsEgg(enum Species species, u32 personality, bool32 isEgg);
const u8 *GetMonIconTilesByIconType(enum Species species, enum SpeciesIconType iconType);
void TryLoadAllMonIconPalettesAtOffset(u16 offset);
u8 GetValidMonIconPalIndex(enum Species species);
const u8 *GetMonIconPtr(enum Species species, u32 personality);
const u8 *GetMonIconPtrIsEgg(enum Species species, u32 personality, bool32 isEgg);
const u16 *GetValidMonIconPalettePtr(enum Species species);
enum Species GetIconSpecies(enum Species species, u32 personality);
u16 GetUnownLetterByPersonality(u32 personality);
enum Species GetIconSpeciesNoPersonality(enum Species species);
void LoadMonIconPalettes(void);
void LoadMonIconPalette(enum Species species);
void FreeMonIconPalettes(void);
u8 CreateMonIconNoPersonality(enum Species species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority);
u8 CreateMonIconNoPersonalityIsEgg(enum Species species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority, bool32 isEgg);
void FreeMonIconPalette(enum Species species);
void FreeAndDestroyMonIconSprite(struct Sprite *sprite);
u8 CreateMonIcon(enum Species species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority, u32 personality);
u8 CreateMonIconIsEgg(enum Species species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority, u32 personality, bool32 isEgg);
u8 UpdateMonIconFrame(struct Sprite *sprite);
void LoadMonIconPalette(enum Species species);
void LoadMonIconPalettePersonality(enum Species species, u32 personality);
void SpriteCB_MonIcon(struct Sprite *sprite);
void SetPartyHPBarSprite(struct Sprite *sprite, u8 animNum);
u8 GetMonIconPaletteIndexFromSpecies(enum Species species);
void SafeFreeMonIconPalette(enum Species species);

u8 CreateTaggedMonIcon(u32 tileTag, u32 paletteTag, enum Species species);
#endif // GUARD_POKEMON_ICON_H
