#ifndef GUARD_DECOMPRESS_H
#define GUARD_DECOMPRESS_H

#include "sprite.h"

void LZDecompressWram(const void *src, void *dest);
void LZDecompressVram(const void *src, void *dest);
u16 LoadCompressedObjectPic(const struct CompressedSpriteSheet *src);
void LoadCompressedObjectPicOverrideBuffer(const struct CompressedSpriteSheet *src, void *buffer);
void LoadCompressedObjectPalette(const struct CompressedSpritePalette *src);
void LoadCompressedObjectPaletteOverrideBuffer(const struct CompressedSpritePalette *a, void *buffer);
void DecompressPicFromTable(const struct CompressedSpriteSheet *src, void* buffer, s32 species);
void HandleLoadSpecialPokePic(const struct CompressedSpriteSheet *src, void *dest, s32 species, u32 personality);
void LoadSpecialPokePic_2(const struct CompressedSpriteSheet *src, void *dest, s32 species, u32 personality, bool8 isFrontPic);
void LoadSpecialPokePic_DontHandleDeoxys(const struct CompressedSpriteSheet *src, void *dest, s32 species, u32 personality, bool8 isFrontPic);

#endif // GUARD_DECOMPRESS_H
