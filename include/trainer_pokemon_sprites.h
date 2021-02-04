#ifndef GUARD_TRAINER_POKEMON_SPRITES_H
#define GUARD_TRAINER_POKEMON_SPRITES_H

bool16 ResetAllPicSprites(void);
u16 CreatePicSprite2(u16 species, u32 otId, u32 personality, u8 flags, s16 x, s16 y, u8 paletteSlot, u16 paletteTag);
u16 CreateMonPicSprite(u16 species, u32 otId, u32 personality, bool8 isFrontPic, s16 x, s16 y, u8 paletteSlot, u16 paletteTag);
u16 FreeAndDestroyMonPicSprite(u16 spriteId);
u16 CreateTrainerPicSprite(u16 species, bool8 isFrontPic, s16 x, s16 y, u8 paletteSlot, u16 paletteTag);
u16 FreeAndDestroyTrainerPicSprite(u16 spriteId);
u16 CreateTrainerCardTrainerPicSprite(u16 species, bool8 isFrontPic, u16 destX, u16 destY, u8 paletteSlot, u8 windowId);
u16 PlayerGenderToFrontTrainerPicId_Debug(u8 gender, bool8 getClass);

#endif // GUARD_TRAINER_POKEMON_SPRITES_H
