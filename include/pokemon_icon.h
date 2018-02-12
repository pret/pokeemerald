#ifndef GUARD_POKEMON_ICON_H
#define GUARD_POKEMON_ICON_H

const u8 *GetMonIconPtr(u16 speciesId, u32 personality, u32 frameNo);
const u16 *GetValidMonIconPalettePtr(u16 speciesId);
u16 GetUnownLetterByPersonality(u32 personality);
u16 sub_80D2E84(u16 speciesId);
void sub_80D2F04(void);
void sub_80D2F68(u16 iconId);
u8 sub_80D2D78(u16 iconId, void callback(struct Sprite *), u16 x, u16 y, u16 a4, u8 a5);
void sub_80D2FF0(u16 iconId);
void sub_80D2EF8(struct Sprite *sprite);
u8 CreateMonIcon(u16 species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority, u32 personality, int a7);

#endif // GUARD_POKEMON_ICON_H
