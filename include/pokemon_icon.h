#ifndef GUARD_POKEMON_ICON_H
#define GUARD_POKEMON_ICON_H

const u8 *GetMonIconPtr(u16 speciesId, u32 personality, u32 frameNo);
const u16 *GetValidMonIconPalettePtr(u16 speciesId);
u16 sub_80D2E84(u16 speciesId);
void sub_80D2F68(u16 iconId);
u8 sub_80D2D78(u16 iconId, void callback(struct Sprite *), u16 x, u16 y, u16 a4, u8 a5);

#endif // GUARD_POKEMON_ICON_H
