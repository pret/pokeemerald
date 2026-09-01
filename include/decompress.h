#ifndef GUARD_DECOMPRESS_H
#define GUARD_DECOMPRESS_H

#include "sprite.h"

#define MAX_DECOMPRESSION_BUFFER_SIZE 0x4000

#define TANS_TABLE_SIZE     64
#define PACKED_FREQ_MASK    0x3F
#define PARTIAL_FREQ_MASK   0xC0000000

#define FIRST_LO_MASK   0x7f
#define CONTINUE_BIT    0x80

#define SMOL_IMAGE_SIZE_MULTIPLIER 4

struct LZ77Header {
    u32 lz77IdBits:5;
    u32 padding:3;
    u32 size:24;
};

struct SmolHeader {
    u32 mode:4;
    u32 imageSize:14;
    u32 symSize:14;
    u32 initialState:6;
    u32 bitstreamSize:13;
    u32 loSize:13;
};

struct SpriteSheetHeader {
    u32 mode:4;
    u32 numComponents:12;
    u32 framesPerComponent:16;
};

struct SmolTilemapHeader {
    u32 mode:4;
    u32 tilemapSize:14;
    u32 symSize:14;
    u32 tileNumberSize;
};

union CompressionHeader {
    struct LZ77Header lz77;
    struct SmolHeader smol;
    struct SmolTilemapHeader smolTilemap;
};

enum CompressionMode {
    MODE_LZ77 = 0,
    BASE_ONLY = 1,
    ENCODE_SYMS = 2,
    ENCODE_DELTA_SYMS = 3,
    ENCODE_LO = 4,
    ENCODE_BOTH = 5,
    ENCODE_BOTH_DELTA_SYMS = 6,
    IS_FRAME_CONTAINER = 7,
    IS_TILEMAP = 8,
};

void DecompressDataWithHeaderVram(const u32 *src, void *dest);
void DecompressDataWithHeaderWram(const u32 *src, void *dest);

// Lucky's fast lz decompression function
void FastLZ77UnCompWram(const u32 *src, void *dest);

//  Default Decompression functions are below here
u32 IsLZ77Data(const void *ptr, u32 minSize, u32 maxSize);

u32 LoadCompressedSpriteSheet(const struct CompressedSpriteSheet *src);
u32 LoadCompressedSpriteSheetByTemplate(const struct SpriteTemplate *template, s32 offset);
u32 LoadCompressedSpriteSheetOverrideBuffer(const struct CompressedSpriteSheet *src, void *buffer);
bool8 LoadCompressedSpriteSheetUsingHeap(const struct CompressedSpriteSheet *src);

void HandleLoadSpecialPokePic(bool32 isFrontPic, void *dest, enum Species species, u32 personality);
void HandleLoadSpecialPokePicIsEgg(bool32 isFrontPic, void *dest, enum Species species, u32 personality, bool32 isEgg);

void LoadSpecialPokePic(void *dest, enum Species species, u32 personality, bool8 isFrontPic);
void LoadSpecialPokePicIsEgg(void *dest, enum Species species, u32 personality, bool8 isFrontPic, bool32 isEgg);

u32 GetDecompressedDataSize(const u32 *ptr);
bool32 IsCompressedData(const u32 *ptr);

#endif // GUARD_DECOMPRESS_H
