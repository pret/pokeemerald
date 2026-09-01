#include "global.h"
#include "decompress.h"
#include "main.h"
#include "malloc.h"
#include "random.h"
#include "sprite.h"
#include "test/test.h"
#include "config/test.h"
#include "config/general.h"

#define ENABLE_ALL_COMPRESSION_TESTS FALSE

#ifdef NDEBUG
void CycleCountStart();
u32 CycleCountEnd();
#endif

enum
{
    COMPRESSION_SMOL,
    COMPRESSION_FASTSMOL,
    COMPRESSION_LZ,
    COMPRESSION_FASTLZ,
    COMPRESSION_SMOL_TILEMAP,
};

static bool32 DecompressImgPrintResults(const u32 *img, const u32 *orgImg, const char *imgName, s32 mode, s32 size)
{
    u32 imageSize = GetDecompressedDataSize(img);
    u32 *compBuffer = Alloc(imageSize);
#ifndef NDEBUG
    if (T_COMPRESSION_SHOULD_PRINT)
        CycleCountStart();
#endif
    if (mode == COMPRESSION_FASTLZ)
        FastLZ77UnCompWram(img, compBuffer);
    else if (mode == COMPRESSION_LZ)
        LZ77UnCompWram(img, compBuffer);
    else
        DecompressDataWithHeaderWram(img, compBuffer);

#ifndef NDEBUG
    if (T_COMPRESSION_SHOULD_PRINT)
    {
        s32 timeTaken = CycleCountEnd();
        const char *compModeStr;
        if (mode == COMPRESSION_SMOL)
            compModeStr = "Smol";
        else if (mode == COMPRESSION_FASTSMOL)
            compModeStr = "fastSmol";
        else if (mode == COMPRESSION_LZ)
            compModeStr = "LZ";
        else if (mode == COMPRESSION_SMOL_TILEMAP)
            compModeStr = "smolTilemap";
        else
            compModeStr = "fastLZ";

        DebugPrintf("Time %s %s: %d         Size: %d", imgName, compModeStr, timeTaken, size);
    }
#endif

    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        if (orgImg[i] != compBuffer[i])
        {
            areEqual = FALSE;
            break;
        }
    }

    Free(compBuffer);

    return areEqual;
}

static bool32 DecompressImgPrintResultsVram(const u32 *img, const u32 *orgImg, const char *imgName, s32 mode, s32 size)
{
    u32 imageSize = GetDecompressedDataSize(img);
    u32 *compBuffer = (u32 *)VRAM;
#ifndef NDEBUG
    if (T_COMPRESSION_SHOULD_PRINT)
        CycleCountStart();
#endif
    if (mode == COMPRESSION_FASTLZ)
        FastLZ77UnCompWram(img, compBuffer);    //  There is no Vram version of this
    else if (mode == COMPRESSION_LZ)
        LZ77UnCompVram(img, compBuffer);
    else
        DecompressDataWithHeaderVram(img, compBuffer);

#ifndef NDEBUG
    if (T_COMPRESSION_SHOULD_PRINT)
    {
        s32 timeTaken = CycleCountEnd();
        const char *compModeStr;
        if (mode == COMPRESSION_SMOL)
            compModeStr = "Smol";
        else if (mode == COMPRESSION_FASTSMOL)
            compModeStr = "fastSmol";
        else if (mode == COMPRESSION_LZ)
            compModeStr = "LZ";
        else if (mode == COMPRESSION_SMOL_TILEMAP)
            compModeStr = "smolTilemap";
        else
            compModeStr = "fastLZ";

        DebugPrintf("Time %s %s: %d         Size: %d", imgName, compModeStr, timeTaken, size);
    }
#endif

    bool32 areEqual = TRUE;
    for (u32 i = 0; i < imageSize/4; i++)
    {
        if (orgImg[i] != compBuffer[i])
        {
            areEqual = FALSE;
            break;
        }
    }

    return areEqual;
}

static bool32 DecompressTilemapPrintResults(const u32 *tilemap, const u16 *orgTilemap, const char *tilemapName, s32 mode, s32 size)
{
    u32 tilemapSize = GetDecompressedDataSize(tilemap);
    u16 *compBuffer = Alloc(tilemapSize);
#ifndef NDEBUG
    if (T_COMPRESSION_SHOULD_PRINT)
        CycleCountStart();
#endif
    if (mode == COMPRESSION_FASTLZ)
        FastLZ77UnCompWram(tilemap, compBuffer);
    else if (mode == COMPRESSION_LZ)
        LZ77UnCompWram(tilemap, compBuffer);
    else
        DecompressDataWithHeaderWram(tilemap, compBuffer);

#ifndef NDEBUG
    if (T_COMPRESSION_SHOULD_PRINT)
    {
        s32 timeTaken = CycleCountEnd();
        const char *compModeStr;
        if (mode == COMPRESSION_SMOL)
            compModeStr = "Smol";
        else if (mode == COMPRESSION_FASTSMOL)
            compModeStr = "fastSmol";
        else if (mode == COMPRESSION_LZ)
            compModeStr = "LZ";
        else if (mode == COMPRESSION_SMOL_TILEMAP)
            compModeStr = "smolTilemap";
        else
            compModeStr = "fastLZ";

        DebugPrintf("Time %s %s: %d         Size: %d", tilemapName, compModeStr, timeTaken, size);
    }
#endif

    bool32 areEqual = TRUE;
    for (u32 i = 0; i < tilemapSize/2; i++)
    {
        if (orgTilemap[i] != compBuffer[i])
        {
            areEqual = FALSE;
            break;
        }
    }

    Free(compBuffer);

    return areEqual;
}

static bool32 DecompressTilemapPrintResultsVram(const u32 *tilemap, const u16 *orgTilemap, const char *tilemapName, s32 mode, s32 size)
{
    u32 tilemapSize = GetDecompressedDataSize(tilemap);
    u16 *compBuffer = (u16 *)VRAM;
#ifndef NDEBUG
    if (T_COMPRESSION_SHOULD_PRINT)
        CycleCountStart();
#endif
    if (mode == COMPRESSION_FASTLZ)
        FastLZ77UnCompWram(tilemap, compBuffer);
    else if (mode == COMPRESSION_LZ)
        LZ77UnCompVram(tilemap, compBuffer);
    else
        DecompressDataWithHeaderVram(tilemap, compBuffer);

#ifndef NDEBUG
    if (T_COMPRESSION_SHOULD_PRINT)
    {
        s32 timeTaken = CycleCountEnd();
        const char *compModeStr;
        if (mode == COMPRESSION_SMOL)
            compModeStr = "Smol";
        else if (mode == COMPRESSION_FASTSMOL)
            compModeStr = "fastSmol";
        else if (mode == COMPRESSION_LZ)
            compModeStr = "LZ";
        else if (mode == COMPRESSION_SMOL_TILEMAP)
            compModeStr = "smolTilemap";
        else
            compModeStr = "fastLZ";

        DebugPrintf("Time %s %s: %d         Size: %d", tilemapName, compModeStr, timeTaken, size);
    }
#endif

    bool32 areEqual = TRUE;
    for (u32 i = 0; i < tilemapSize/2; i++)
    {
        if (orgTilemap[i] != compBuffer[i])
        {
            areEqual = FALSE;
            break;
        }
    }

    return areEqual;
}

TEST("Compression test: tileset smol VRAM")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/tilesetTest.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/tilesetTest.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResultsVram(compFile, origFile, "Tileset", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: tileset smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/tilesetTest.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/tilesetTest.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Tileset", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: tileset LZ")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/tilesetTest.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/tilesetTest.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Tileset", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: tileset fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/tilesetTest.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/tilesetTest.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Tileset", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: tileset fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/tilesetTest.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/tilesetTest.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Tileset", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: simple battle sprite smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/simple_battle_sprite.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/simple_battle_sprite.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "simple battle sprite", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: simple battle sprite LZ")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/simple_battle_sprite.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/simple_battle_sprite.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "simple battle sprite", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: simple battle sprite fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/simple_battle_sprite.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/simple_battle_sprite.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "simple battle sprite", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: simple battle sprite fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/simple_battle_sprite.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/simple_battle_sprite.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "simple battle sprite", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: complex battle sprite smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/complex_battle_sprite.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/complex_battle_sprite.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "complex battle sprite", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: complex battle sprite LZ")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/complex_battle_sprite.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/complex_battle_sprite.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "complex battle sprite", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: complex battle sprite fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/complex_battle_sprite.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/complex_battle_sprite.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "complex battle sprite", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: complex battle sprite fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/complex_battle_sprite.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/complex_battle_sprite.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "complex battle sprite", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Gossifleur Smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/gossifleur.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/gossifleur.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Gossifleur", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Gossifleur LZ")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/gossifleur.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/gossifleur.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Gossifleur", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Gossifleur fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/gossifleur.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/gossifleur.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Gossifleur", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Gossifleur fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/gossifleur.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/gossifleur.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Gossifleur", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Ledian Smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/ledian.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/ledian.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ledian", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Ledian LZ")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/ledian.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/ledian.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ledian", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Ledian fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/ledian.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/ledian.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ledian", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Ledian fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/ledian.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/ledian.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ledian", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Mr. Mime Smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/mr_mime.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/mr_mime.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Mr. Mime", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Mr. Mime LZ")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/mr_mime.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/mr_mime.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Mr. Mime", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Mr. Mime fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/mr_mime.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/mr_mime.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Mr. Mime", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Mr. Mime fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/mr_mime.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/mr_mime.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Mr. Mime", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: bubbles Smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/small_bubbles.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/small_bubbles.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "bubbles", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: bubbles LZ")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/small_bubbles.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/small_bubbles.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "bubbles", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: bubbles fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/small_bubbles.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/small_bubbles.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "bubbles", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: bubbles fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/small_bubbles.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/small_bubbles.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "bubbles", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: small mode 0 smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/small_mode_0.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/small_mode_0.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "small mode 0", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: small mode 0 lz")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/small_mode_0.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/small_mode_0.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "small mode 0", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: medium mode 0 smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/medium_mode_0.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/medium_mode_0.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "medium mode 0", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: medium mode 0 lz")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/medium_mode_0.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/medium_mode_0.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "medium mode 0", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: large mode 0 smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/large_mode_0.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/large_mode_0.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "large mode 0", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: large mode 0 lz")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/large_mode_0.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/large_mode_0.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "large mode 0", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: small mode 1 smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/small_mode_1.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/small_mode_1.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "small mode 1", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: small mode 1 lz")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/small_mode_1.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/small_mode_1.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "small mode 1", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: medium mode 1 smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/medium_mode_1.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/medium_mode_1.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "medium mode 1", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: medium mode 1 lz")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/medium_mode_1.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/medium_mode_1.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "medium mode 1", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: large mode 1 smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/large_mode_1.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/large_mode_1.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "large mode 1", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: large mode 1 lz")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/large_mode_1.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/large_mode_1.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "large mode 1", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: small mode 2 smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/small_mode_2.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/small_mode_2.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "small mode 2", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: small mode 2 lz")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/small_mode_2.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/small_mode_2.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "small mode 2", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: medium mode 2 smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/medium_mode_2.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/medium_mode_2.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "medium mode 2", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: medium mode 2 lz")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/medium_mode_2.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/medium_mode_2.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "medium mode 2", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: large mode 2 smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/large_mode_2.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/large_mode_2.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "large mode 2", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: large mode 2 lz")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/large_mode_2.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/large_mode_2.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "large mode 2", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: small mode 3 smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/small_mode_3.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/small_mode_3.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "small mode 3", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: small mode 3 lz")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/small_mode_3.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/small_mode_3.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "small mode 3", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: medium mode 3 smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/medium_mode_3.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/medium_mode_3.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "medium mode 3", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: medium mode 3 lz")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/medium_mode_3.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/medium_mode_3.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "medium mode 3", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: large mode 3 smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/large_mode_3.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/large_mode_3.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "large mode 3", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: large mode 3 lz")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/large_mode_3.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/large_mode_3.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "large mode 3", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: small mode 4 smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/small_mode_4.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/small_mode_4.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "small mode 4", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: small mode 4 lz")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/small_mode_4.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/small_mode_4.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "small mode 4", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: medium mode 4 smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/medium_mode_4.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/medium_mode_4.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "medium mode 4", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: medium mode 4 lz")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/medium_mode_4.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/medium_mode_4.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "medium mode 4", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: large mode 4 smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/large_mode_4.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/large_mode_4.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "large mode 4", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: large mode 4 lz")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/large_mode_4.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/large_mode_4.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "large mode 4", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: small mode 5 smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/small_mode_5.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/small_mode_5.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "small mode 5", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: small mode 5 lz")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/small_mode_5.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/small_mode_5.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "small mode 5", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: medium mode 5 smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/medium_mode_5.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/medium_mode_5.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "medium mode 5", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: medium mode 5 lz")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/medium_mode_5.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/medium_mode_5.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "medium mode 5", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: large mode 5 smol")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/large_mode_5.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/large_mode_5.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "large mode 5", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: large mode 5 lz")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/large_mode_5.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/large_mode_5.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "large mode 5", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 63 1")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_63_1.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_63_1.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 62 2")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_62_2.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_62_2.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 61 3")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_61_3.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_61_3.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 60 4")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_60_4.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_60_4.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 59 5")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_59_5.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_59_5.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 58 6")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_58_6.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_58_6.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 57 7")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_57_7.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_57_7.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 56 8")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_56_8.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_56_8.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 55 9")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_55_9.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_55_9.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 54 10")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_54_10.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_54_10.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 53 11")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_53_11.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_53_11.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 52 12")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_52_12.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_52_12.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 51 13")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_51_13.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_51_13.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 50 14")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_50_14.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_50_14.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 49 15")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_49_15.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_49_15.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 48 16")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_48_16.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_48_16.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 47 17")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_47_17.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_47_17.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 46 18")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_46_18.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_46_18.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 45 19")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_45_19.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_45_19.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 44 20")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_44_20.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_44_20.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 43 21")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_43_21.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_43_21.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 42 22")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_42_22.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_42_22.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 41 23")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_41_23.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_41_23.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 40 24")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_40_24.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_40_24.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 39 25")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_39_25.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_39_25.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 38 26")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_38_26.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_38_26.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 37 27")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_37_27.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_37_27.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 36 28")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_36_28.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_36_28.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 35 29")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_35_29.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_35_29.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 34 30")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_34_30.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_34_30.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 33 31")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_33_31.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_33_31.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: table generation 32 32")
{
    static const u32 origFile[] = INCGFX_U32("test/compression/table_32_32.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("test/compression/table_32_32.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

#if ENABLE_ALL_COMPRESSION_TESTS
TEST("Compression test: Bulbasaur Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/bulbasaur/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/bulbasaur/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Bulbasaur", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Bulbasaur LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/bulbasaur/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/bulbasaur/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Bulbasaur", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Bulbasaur fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/bulbasaur/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/bulbasaur/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Bulbasaur", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Bulbasaur fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/bulbasaur/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/bulbasaur/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Bulbasaur", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Ivysaur Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/ivysaur/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/ivysaur/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ivysaur", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Ivysaur LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/ivysaur/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/ivysaur/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ivysaur", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Ivysaur fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/ivysaur/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/ivysaur/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ivysaur", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Ivysaur fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/ivysaur/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/ivysaur/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ivysaur", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Venusaur Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/venusaur/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/venusaur/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Venusaur", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Venusaur LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/venusaur/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/venusaur/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Venusaur", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Venusaur fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/venusaur/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/venusaur/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Venusaur", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Venusaur fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/venusaur/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/venusaur/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Venusaur", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Charmander Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/charmander/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/charmander/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Charmander", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Charmander LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/charmander/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/charmander/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Charmander", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Charmander fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/charmander/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/charmander/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Charmander", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Charmander fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/charmander/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/charmander/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Charmander", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Charmeleon Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/charmeleon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/charmeleon/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Charmeleon", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Charmeleon LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/charmeleon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/charmeleon/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Charmeleon", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Charmeleon fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/charmeleon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/charmeleon/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Charmeleon", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Charmeleon fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/charmeleon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/charmeleon/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Charmeleon", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Charizard Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/charizard/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/charizard/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Charizard", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Charizard LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/charizard/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/charizard/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Charizard", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Charizard fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/charizard/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/charizard/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Charizard", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Charizard fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/charizard/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/charizard/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Charizard", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Squirtle Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/squirtle/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/squirtle/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Squirtle", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Squirtle LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/squirtle/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/squirtle/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Squirtle", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Squirtle fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/squirtle/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/squirtle/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Squirtle", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Squirtle fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/squirtle/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/squirtle/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Squirtle", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Wartortle Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/wartortle/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/wartortle/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Wartortle", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Wartortle LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/wartortle/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/wartortle/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Wartortle", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Wartortle fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/wartortle/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/wartortle/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Wartortle", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Wartortle fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/wartortle/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/wartortle/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Wartortle", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Blastoise Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/blastoise/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/blastoise/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Blastoise", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Blastoise LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/blastoise/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/blastoise/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Blastoise", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Blastoise fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/blastoise/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/blastoise/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Blastoise", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Blastoise fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/blastoise/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/blastoise/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Blastoise", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Caterpie Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/caterpie/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/caterpie/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Caterpie", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Caterpie LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/caterpie/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/caterpie/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Caterpie", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Caterpie fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/caterpie/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/caterpie/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Caterpie", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Caterpie fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/caterpie/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/caterpie/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Caterpie", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Metapod Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/metapod/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/metapod/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Metapod", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Metapod LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/metapod/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/metapod/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Metapod", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Metapod fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/metapod/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/metapod/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Metapod", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Metapod fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/metapod/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/metapod/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Metapod", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Butterfree Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/butterfree/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/butterfree/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Butterfree", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Butterfree LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/butterfree/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/butterfree/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Butterfree", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Butterfree fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/butterfree/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/butterfree/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Butterfree", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Butterfree fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/butterfree/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/butterfree/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Butterfree", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Weedle Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/weedle/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/weedle/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Weedle", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Weedle LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/weedle/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/weedle/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Weedle", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Weedle fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/weedle/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/weedle/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Weedle", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Weedle fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/weedle/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/weedle/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Weedle", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Kakuna Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kakuna/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kakuna/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kakuna", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Kakuna LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kakuna/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kakuna/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kakuna", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Kakuna fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kakuna/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kakuna/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kakuna", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Kakuna fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kakuna/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kakuna/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kakuna", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Beedrill Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/beedrill/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/beedrill/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Beedrill", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Beedrill LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/beedrill/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/beedrill/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Beedrill", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Beedrill fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/beedrill/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/beedrill/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Beedrill", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Beedrill fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/beedrill/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/beedrill/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Beedrill", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Pidgey Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/pidgey/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/pidgey/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Pidgey", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Pidgey LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/pidgey/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/pidgey/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Pidgey", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Pidgey fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/pidgey/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/pidgey/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Pidgey", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Pidgey fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/pidgey/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/pidgey/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Pidgey", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Pidgeotto Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/pidgeotto/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/pidgeotto/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Pidgeotto", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Pidgeotto LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/pidgeotto/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/pidgeotto/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Pidgeotto", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Pidgeotto fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/pidgeotto/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/pidgeotto/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Pidgeotto", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Pidgeotto fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/pidgeotto/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/pidgeotto/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Pidgeotto", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Pidgeot Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/pidgeot/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/pidgeot/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Pidgeot", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Pidgeot LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/pidgeot/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/pidgeot/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Pidgeot", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Pidgeot fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/pidgeot/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/pidgeot/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Pidgeot", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Pidgeot fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/pidgeot/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/pidgeot/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Pidgeot", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Rattata Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/rattata/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/rattata/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Rattata", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Rattata LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/rattata/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/rattata/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Rattata", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Rattata fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/rattata/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/rattata/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Rattata", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Rattata fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/rattata/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/rattata/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Rattata", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Raticate Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/raticate/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/raticate/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Raticate", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Raticate LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/raticate/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/raticate/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Raticate", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Raticate fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/raticate/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/raticate/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Raticate", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Raticate fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/raticate/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/raticate/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Raticate", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Spearow Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/spearow/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/spearow/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Spearow", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Spearow LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/spearow/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/spearow/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Spearow", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Spearow fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/spearow/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/spearow/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Spearow", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Spearow fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/spearow/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/spearow/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Spearow", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Fearow Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/fearow/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/fearow/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Fearow", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Fearow LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/fearow/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/fearow/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Fearow", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Fearow fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/fearow/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/fearow/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Fearow", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Fearow fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/fearow/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/fearow/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Fearow", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Ekans Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/ekans/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/ekans/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ekans", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Ekans LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/ekans/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/ekans/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ekans", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Ekans fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/ekans/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/ekans/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ekans", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Ekans fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/ekans/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/ekans/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ekans", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Arbok Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/arbok/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/arbok/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Arbok", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Arbok LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/arbok/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/arbok/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Arbok", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Arbok fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/arbok/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/arbok/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Arbok", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Arbok fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/arbok/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/arbok/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Arbok", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Pikachu Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/pikachu/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/pikachu/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Pikachu", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Pikachu LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/pikachu/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/pikachu/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Pikachu", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Pikachu fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/pikachu/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/pikachu/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Pikachu", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Pikachu fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/pikachu/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/pikachu/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Pikachu", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Raichu Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/raichu/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/raichu/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Raichu", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Raichu LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/raichu/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/raichu/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Raichu", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Raichu fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/raichu/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/raichu/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Raichu", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Raichu fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/raichu/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/raichu/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Raichu", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Sandshrew Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/sandshrew/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/sandshrew/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Sandshrew", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Sandshrew LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/sandshrew/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/sandshrew/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Sandshrew", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Sandshrew fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/sandshrew/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/sandshrew/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Sandshrew", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Sandshrew fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/sandshrew/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/sandshrew/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Sandshrew", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Sandslash Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/sandslash/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/sandslash/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Sandslash", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Sandslash LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/sandslash/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/sandslash/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Sandslash", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Sandslash fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/sandslash/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/sandslash/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Sandslash", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Sandslash fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/sandslash/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/sandslash/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Sandslash", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Nidorina Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/nidorina/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/nidorina/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Nidorina", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Nidorina LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/nidorina/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/nidorina/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Nidorina", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Nidorina fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/nidorina/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/nidorina/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Nidorina", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Nidorina fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/nidorina/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/nidorina/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Nidorina", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Nidoqueen Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/nidoqueen/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/nidoqueen/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Nidoqueen", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Nidoqueen LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/nidoqueen/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/nidoqueen/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Nidoqueen", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Nidoqueen fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/nidoqueen/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/nidoqueen/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Nidoqueen", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Nidoqueen fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/nidoqueen/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/nidoqueen/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Nidoqueen", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Nidorino Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/nidorino/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/nidorino/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Nidorino", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Nidorino LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/nidorino/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/nidorino/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Nidorino", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Nidorino fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/nidorino/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/nidorino/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Nidorino", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Nidorino fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/nidorino/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/nidorino/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Nidorino", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Nidoking Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/nidoking/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/nidoking/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Nidoking", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Nidoking LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/nidoking/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/nidoking/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Nidoking", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Nidoking fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/nidoking/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/nidoking/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Nidoking", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Nidoking fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/nidoking/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/nidoking/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Nidoking", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Clefairy Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/clefairy/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/clefairy/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Clefairy", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Clefairy LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/clefairy/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/clefairy/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Clefairy", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Clefairy fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/clefairy/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/clefairy/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Clefairy", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Clefairy fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/clefairy/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/clefairy/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Clefairy", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Clefable Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/clefable/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/clefable/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Clefable", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Clefable LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/clefable/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/clefable/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Clefable", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Clefable fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/clefable/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/clefable/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Clefable", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Clefable fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/clefable/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/clefable/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Clefable", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Vulpix Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/vulpix/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/vulpix/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Vulpix", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Vulpix LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/vulpix/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/vulpix/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Vulpix", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Vulpix fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/vulpix/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/vulpix/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Vulpix", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Vulpix fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/vulpix/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/vulpix/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Vulpix", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Ninetales Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/ninetales/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/ninetales/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ninetales", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Ninetales LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/ninetales/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/ninetales/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ninetales", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Ninetales fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/ninetales/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/ninetales/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ninetales", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Ninetales fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/ninetales/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/ninetales/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ninetales", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Jigglypuff Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/jigglypuff/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/jigglypuff/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Jigglypuff", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Jigglypuff LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/jigglypuff/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/jigglypuff/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Jigglypuff", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Jigglypuff fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/jigglypuff/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/jigglypuff/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Jigglypuff", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Jigglypuff fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/jigglypuff/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/jigglypuff/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Jigglypuff", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Wigglytuff Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/wigglytuff/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/wigglytuff/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Wigglytuff", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Wigglytuff LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/wigglytuff/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/wigglytuff/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Wigglytuff", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Wigglytuff fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/wigglytuff/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/wigglytuff/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Wigglytuff", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Wigglytuff fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/wigglytuff/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/wigglytuff/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Wigglytuff", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Zubat Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/zubat/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/zubat/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Zubat", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Zubat LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/zubat/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/zubat/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Zubat", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Zubat fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/zubat/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/zubat/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Zubat", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Zubat fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/zubat/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/zubat/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Zubat", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Golbat Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/golbat/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/golbat/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Golbat", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Golbat LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/golbat/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/golbat/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Golbat", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Golbat fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/golbat/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/golbat/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Golbat", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Golbat fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/golbat/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/golbat/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Golbat", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Oddish Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/oddish/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/oddish/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Oddish", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Oddish LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/oddish/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/oddish/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Oddish", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Oddish fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/oddish/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/oddish/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Oddish", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Oddish fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/oddish/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/oddish/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Oddish", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Gloom Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/gloom/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/gloom/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Gloom", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Gloom LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/gloom/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/gloom/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Gloom", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Gloom fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/gloom/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/gloom/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Gloom", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Gloom fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/gloom/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/gloom/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Gloom", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Vileplume Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/vileplume/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/vileplume/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Vileplume", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Vileplume LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/vileplume/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/vileplume/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Vileplume", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Vileplume fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/vileplume/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/vileplume/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Vileplume", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Vileplume fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/vileplume/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/vileplume/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Vileplume", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Paras Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/paras/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/paras/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Paras", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Paras LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/paras/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/paras/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Paras", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Paras fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/paras/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/paras/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Paras", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Paras fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/paras/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/paras/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Paras", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Parasect Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/parasect/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/parasect/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Parasect", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Parasect LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/parasect/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/parasect/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Parasect", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Parasect fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/parasect/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/parasect/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Parasect", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Parasect fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/parasect/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/parasect/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Parasect", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Venonat Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/venonat/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/venonat/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Venonat", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Venonat LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/venonat/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/venonat/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Venonat", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Venonat fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/venonat/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/venonat/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Venonat", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Venonat fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/venonat/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/venonat/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Venonat", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Venomoth Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/venomoth/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/venomoth/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Venomoth", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Venomoth LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/venomoth/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/venomoth/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Venomoth", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Venomoth fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/venomoth/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/venomoth/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Venomoth", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Venomoth fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/venomoth/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/venomoth/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Venomoth", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Diglett Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/diglett/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/diglett/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Diglett", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Diglett LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/diglett/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/diglett/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Diglett", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Diglett fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/diglett/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/diglett/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Diglett", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Diglett fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/diglett/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/diglett/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Diglett", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Dugtrio Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dugtrio/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dugtrio/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dugtrio", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Dugtrio LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dugtrio/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dugtrio/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dugtrio", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Dugtrio fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dugtrio/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dugtrio/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dugtrio", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Dugtrio fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dugtrio/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dugtrio/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dugtrio", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Meowth Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/meowth/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/meowth/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Meowth", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Meowth LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/meowth/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/meowth/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Meowth", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Meowth fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/meowth/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/meowth/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Meowth", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Meowth fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/meowth/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/meowth/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Meowth", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Persian Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/persian/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/persian/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Persian", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Persian LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/persian/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/persian/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Persian", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Persian fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/persian/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/persian/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Persian", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Persian fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/persian/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/persian/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Persian", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Psyduck Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/psyduck/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/psyduck/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Psyduck", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Psyduck LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/psyduck/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/psyduck/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Psyduck", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Psyduck fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/psyduck/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/psyduck/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Psyduck", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Psyduck fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/psyduck/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/psyduck/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Psyduck", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Golduck Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/golduck/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/golduck/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Golduck", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Golduck LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/golduck/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/golduck/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Golduck", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Golduck fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/golduck/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/golduck/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Golduck", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Golduck fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/golduck/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/golduck/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Golduck", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Mankey Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/mankey/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/mankey/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Mankey", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Mankey LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/mankey/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/mankey/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Mankey", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Mankey fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/mankey/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/mankey/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Mankey", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Mankey fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/mankey/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/mankey/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Mankey", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Primeape Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/primeape/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/primeape/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Primeape", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Primeape LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/primeape/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/primeape/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Primeape", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Primeape fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/primeape/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/primeape/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Primeape", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Primeape fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/primeape/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/primeape/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Primeape", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Growlithe Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/growlithe/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/growlithe/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Growlithe", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Growlithe LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/growlithe/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/growlithe/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Growlithe", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Growlithe fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/growlithe/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/growlithe/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Growlithe", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Growlithe fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/growlithe/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/growlithe/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Growlithe", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Arcanine Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/arcanine/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/arcanine/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Arcanine", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Arcanine LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/arcanine/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/arcanine/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Arcanine", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Arcanine fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/arcanine/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/arcanine/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Arcanine", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Arcanine fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/arcanine/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/arcanine/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Arcanine", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Poliwag Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/poliwag/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/poliwag/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Poliwag", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Poliwag LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/poliwag/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/poliwag/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Poliwag", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Poliwag fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/poliwag/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/poliwag/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Poliwag", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Poliwag fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/poliwag/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/poliwag/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Poliwag", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Poliwhirl Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/poliwhirl/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/poliwhirl/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Poliwhirl", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Poliwhirl LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/poliwhirl/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/poliwhirl/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Poliwhirl", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Poliwhirl fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/poliwhirl/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/poliwhirl/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Poliwhirl", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Poliwhirl fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/poliwhirl/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/poliwhirl/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Poliwhirl", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Poliwrath Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/poliwrath/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/poliwrath/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Poliwrath", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Poliwrath LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/poliwrath/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/poliwrath/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Poliwrath", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Poliwrath fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/poliwrath/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/poliwrath/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Poliwrath", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Poliwrath fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/poliwrath/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/poliwrath/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Poliwrath", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Abra Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/abra/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/abra/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Abra", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Abra LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/abra/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/abra/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Abra", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Abra fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/abra/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/abra/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Abra", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Abra fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/abra/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/abra/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Abra", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Kadabra Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kadabra/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kadabra/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kadabra", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Kadabra LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kadabra/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kadabra/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kadabra", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Kadabra fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kadabra/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kadabra/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kadabra", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Kadabra fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kadabra/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kadabra/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kadabra", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Alakazam Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/alakazam/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/alakazam/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Alakazam", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Alakazam LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/alakazam/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/alakazam/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Alakazam", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Alakazam fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/alakazam/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/alakazam/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Alakazam", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Alakazam fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/alakazam/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/alakazam/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Alakazam", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Machop Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/machop/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/machop/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Machop", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Machop LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/machop/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/machop/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Machop", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Machop fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/machop/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/machop/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Machop", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Machop fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/machop/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/machop/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Machop", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Machoke Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/machoke/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/machoke/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Machoke", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Machoke LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/machoke/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/machoke/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Machoke", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Machoke fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/machoke/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/machoke/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Machoke", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Machoke fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/machoke/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/machoke/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Machoke", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Machamp Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/machamp/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/machamp/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Machamp", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Machamp LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/machamp/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/machamp/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Machamp", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Machamp fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/machamp/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/machamp/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Machamp", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Machamp fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/machamp/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/machamp/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Machamp", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Bellsprout Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/bellsprout/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/bellsprout/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Bellsprout", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Bellsprout LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/bellsprout/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/bellsprout/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Bellsprout", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Bellsprout fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/bellsprout/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/bellsprout/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Bellsprout", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Bellsprout fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/bellsprout/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/bellsprout/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Bellsprout", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Weepinbell Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/weepinbell/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/weepinbell/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Weepinbell", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Weepinbell LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/weepinbell/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/weepinbell/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Weepinbell", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Weepinbell fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/weepinbell/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/weepinbell/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Weepinbell", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Weepinbell fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/weepinbell/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/weepinbell/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Weepinbell", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Victreebel Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/victreebel/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/victreebel/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Victreebel", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Victreebel LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/victreebel/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/victreebel/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Victreebel", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Victreebel fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/victreebel/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/victreebel/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Victreebel", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Victreebel fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/victreebel/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/victreebel/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Victreebel", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Tentacool Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/tentacool/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/tentacool/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Tentacool", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Tentacool LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/tentacool/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/tentacool/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Tentacool", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Tentacool fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/tentacool/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/tentacool/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Tentacool", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Tentacool fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/tentacool/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/tentacool/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Tentacool", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Tentacruel Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/tentacruel/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/tentacruel/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Tentacruel", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Tentacruel LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/tentacruel/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/tentacruel/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Tentacruel", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Tentacruel fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/tentacruel/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/tentacruel/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Tentacruel", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Tentacruel fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/tentacruel/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/tentacruel/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Tentacruel", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Geodude Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/geodude/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/geodude/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Geodude", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Geodude LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/geodude/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/geodude/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Geodude", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Geodude fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/geodude/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/geodude/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Geodude", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Geodude fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/geodude/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/geodude/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Geodude", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Graveler Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/graveler/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/graveler/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Graveler", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Graveler LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/graveler/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/graveler/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Graveler", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Graveler fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/graveler/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/graveler/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Graveler", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Graveler fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/graveler/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/graveler/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Graveler", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Golem Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/golem/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/golem/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Golem", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Golem LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/golem/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/golem/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Golem", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Golem fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/golem/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/golem/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Golem", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Golem fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/golem/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/golem/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Golem", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Ponyta Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/ponyta/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/ponyta/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ponyta", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Ponyta LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/ponyta/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/ponyta/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ponyta", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Ponyta fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/ponyta/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/ponyta/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ponyta", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Ponyta fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/ponyta/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/ponyta/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ponyta", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Rapidash Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/rapidash/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/rapidash/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Rapidash", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Rapidash LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/rapidash/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/rapidash/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Rapidash", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Rapidash fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/rapidash/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/rapidash/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Rapidash", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Rapidash fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/rapidash/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/rapidash/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Rapidash", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Slowpoke Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/slowpoke/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/slowpoke/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Slowpoke", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Slowpoke LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/slowpoke/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/slowpoke/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Slowpoke", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Slowpoke fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/slowpoke/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/slowpoke/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Slowpoke", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Slowpoke fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/slowpoke/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/slowpoke/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Slowpoke", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Slowbro Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/slowbro/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/slowbro/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Slowbro", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Slowbro LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/slowbro/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/slowbro/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Slowbro", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Slowbro fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/slowbro/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/slowbro/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Slowbro", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Slowbro fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/slowbro/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/slowbro/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Slowbro", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Magnemite Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/magnemite/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/magnemite/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Magnemite", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Magnemite LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/magnemite/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/magnemite/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Magnemite", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Magnemite fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/magnemite/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/magnemite/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Magnemite", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Magnemite fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/magnemite/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/magnemite/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Magnemite", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Magneton Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/magneton/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/magneton/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Magneton", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Magneton LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/magneton/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/magneton/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Magneton", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Magneton fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/magneton/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/magneton/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Magneton", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Magneton fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/magneton/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/magneton/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Magneton", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Doduo Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/doduo/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/doduo/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Doduo", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Doduo LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/doduo/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/doduo/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Doduo", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Doduo fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/doduo/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/doduo/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Doduo", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Doduo fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/doduo/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/doduo/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Doduo", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Dodrio Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dodrio/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dodrio/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dodrio", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Dodrio LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dodrio/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dodrio/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dodrio", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Dodrio fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dodrio/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dodrio/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dodrio", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Dodrio fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dodrio/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dodrio/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dodrio", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Seel Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/seel/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/seel/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Seel", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Seel LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/seel/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/seel/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Seel", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Seel fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/seel/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/seel/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Seel", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Seel fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/seel/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/seel/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Seel", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Dewgong Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dewgong/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dewgong/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dewgong", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Dewgong LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dewgong/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dewgong/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dewgong", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Dewgong fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dewgong/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dewgong/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dewgong", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Dewgong fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dewgong/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dewgong/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dewgong", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Grimer Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/grimer/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/grimer/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Grimer", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Grimer LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/grimer/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/grimer/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Grimer", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Grimer fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/grimer/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/grimer/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Grimer", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Grimer fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/grimer/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/grimer/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Grimer", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Muk Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/muk/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/muk/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Muk", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Muk LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/muk/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/muk/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Muk", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Muk fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/muk/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/muk/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Muk", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Muk fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/muk/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/muk/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Muk", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Shellder Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/shellder/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/shellder/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Shellder", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Shellder LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/shellder/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/shellder/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Shellder", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Shellder fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/shellder/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/shellder/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Shellder", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Shellder fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/shellder/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/shellder/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Shellder", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Cloyster Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/cloyster/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/cloyster/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Cloyster", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Cloyster LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/cloyster/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/cloyster/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Cloyster", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Cloyster fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/cloyster/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/cloyster/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Cloyster", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Cloyster fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/cloyster/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/cloyster/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Cloyster", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Gastly Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/gastly/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/gastly/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Gastly", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Gastly LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/gastly/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/gastly/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Gastly", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Gastly fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/gastly/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/gastly/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Gastly", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Gastly fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/gastly/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/gastly/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Gastly", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Haunter Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/haunter/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/haunter/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Haunter", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Haunter LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/haunter/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/haunter/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Haunter", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Haunter fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/haunter/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/haunter/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Haunter", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Haunter fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/haunter/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/haunter/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Haunter", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Gengar Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/gengar/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/gengar/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Gengar", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Gengar LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/gengar/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/gengar/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Gengar", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Gengar fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/gengar/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/gengar/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Gengar", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Gengar fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/gengar/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/gengar/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Gengar", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Onix Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/onix/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/onix/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Onix", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Onix LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/onix/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/onix/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Onix", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Onix fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/onix/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/onix/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Onix", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Onix fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/onix/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/onix/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Onix", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Drowzee Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/drowzee/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/drowzee/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Drowzee", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Drowzee LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/drowzee/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/drowzee/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Drowzee", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Drowzee fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/drowzee/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/drowzee/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Drowzee", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Drowzee fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/drowzee/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/drowzee/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Drowzee", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Hypno Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/hypno/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/hypno/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Hypno", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Hypno LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/hypno/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/hypno/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Hypno", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Hypno fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/hypno/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/hypno/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Hypno", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Hypno fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/hypno/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/hypno/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Hypno", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Krabby Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/krabby/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/krabby/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Krabby", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Krabby LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/krabby/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/krabby/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Krabby", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Krabby fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/krabby/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/krabby/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Krabby", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Krabby fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/krabby/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/krabby/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Krabby", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Kingler Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kingler/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kingler/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kingler", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Kingler LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kingler/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kingler/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kingler", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Kingler fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kingler/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kingler/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kingler", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Kingler fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kingler/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kingler/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kingler", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Voltorb Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/voltorb/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/voltorb/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Voltorb", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Voltorb LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/voltorb/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/voltorb/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Voltorb", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Voltorb fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/voltorb/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/voltorb/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Voltorb", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Voltorb fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/voltorb/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/voltorb/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Voltorb", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Electrode Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/electrode/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/electrode/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Electrode", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Electrode LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/electrode/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/electrode/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Electrode", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Electrode fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/electrode/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/electrode/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Electrode", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Electrode fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/electrode/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/electrode/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Electrode", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Exeggcute Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/exeggcute/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/exeggcute/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Exeggcute", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Exeggcute LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/exeggcute/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/exeggcute/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Exeggcute", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Exeggcute fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/exeggcute/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/exeggcute/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Exeggcute", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Exeggcute fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/exeggcute/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/exeggcute/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Exeggcute", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Exeggutor Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/exeggutor/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/exeggutor/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Exeggutor", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Exeggutor LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/exeggutor/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/exeggutor/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Exeggutor", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Exeggutor fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/exeggutor/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/exeggutor/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Exeggutor", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Exeggutor fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/exeggutor/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/exeggutor/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Exeggutor", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Cubone Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/cubone/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/cubone/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Cubone", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Cubone LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/cubone/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/cubone/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Cubone", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Cubone fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/cubone/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/cubone/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Cubone", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Cubone fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/cubone/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/cubone/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Cubone", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Marowak Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/marowak/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/marowak/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Marowak", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Marowak LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/marowak/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/marowak/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Marowak", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Marowak fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/marowak/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/marowak/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Marowak", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Marowak fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/marowak/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/marowak/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Marowak", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Hitmonlee Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/hitmonlee/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/hitmonlee/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Hitmonlee", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Hitmonlee LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/hitmonlee/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/hitmonlee/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Hitmonlee", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Hitmonlee fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/hitmonlee/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/hitmonlee/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Hitmonlee", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Hitmonlee fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/hitmonlee/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/hitmonlee/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Hitmonlee", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Hitmonchan Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/hitmonchan/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/hitmonchan/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Hitmonchan", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Hitmonchan LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/hitmonchan/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/hitmonchan/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Hitmonchan", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Hitmonchan fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/hitmonchan/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/hitmonchan/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Hitmonchan", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Hitmonchan fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/hitmonchan/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/hitmonchan/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Hitmonchan", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Lickitung Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/lickitung/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/lickitung/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Lickitung", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Lickitung LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/lickitung/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/lickitung/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Lickitung", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Lickitung fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/lickitung/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/lickitung/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Lickitung", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Lickitung fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/lickitung/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/lickitung/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Lickitung", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Koffing Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/koffing/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/koffing/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Koffing", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Koffing LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/koffing/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/koffing/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Koffing", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Koffing fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/koffing/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/koffing/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Koffing", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Koffing fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/koffing/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/koffing/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Koffing", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Weezing Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/weezing/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/weezing/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Weezing", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Weezing LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/weezing/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/weezing/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Weezing", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Weezing fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/weezing/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/weezing/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Weezing", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Weezing fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/weezing/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/weezing/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Weezing", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Rhyhorn Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/rhyhorn/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/rhyhorn/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Rhyhorn", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Rhyhorn LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/rhyhorn/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/rhyhorn/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Rhyhorn", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Rhyhorn fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/rhyhorn/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/rhyhorn/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Rhyhorn", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Rhyhorn fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/rhyhorn/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/rhyhorn/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Rhyhorn", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Rhydon Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/rhydon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/rhydon/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Rhydon", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Rhydon LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/rhydon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/rhydon/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Rhydon", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Rhydon fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/rhydon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/rhydon/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Rhydon", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Rhydon fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/rhydon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/rhydon/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Rhydon", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Chansey Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/chansey/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/chansey/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Chansey", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Chansey LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/chansey/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/chansey/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Chansey", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Chansey fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/chansey/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/chansey/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Chansey", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Chansey fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/chansey/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/chansey/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Chansey", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Tangela Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/tangela/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/tangela/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Tangela", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Tangela LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/tangela/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/tangela/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Tangela", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Tangela fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/tangela/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/tangela/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Tangela", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Tangela fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/tangela/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/tangela/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Tangela", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Kangaskhan Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kangaskhan/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kangaskhan/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kangaskhan", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Kangaskhan LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kangaskhan/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kangaskhan/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kangaskhan", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Kangaskhan fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kangaskhan/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kangaskhan/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kangaskhan", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Kangaskhan fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kangaskhan/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kangaskhan/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kangaskhan", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Horsea Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/horsea/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/horsea/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Horsea", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Horsea LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/horsea/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/horsea/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Horsea", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Horsea fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/horsea/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/horsea/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Horsea", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Horsea fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/horsea/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/horsea/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Horsea", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Seadra Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/seadra/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/seadra/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Seadra", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Seadra LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/seadra/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/seadra/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Seadra", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Seadra fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/seadra/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/seadra/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Seadra", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Seadra fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/seadra/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/seadra/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Seadra", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Goldeen Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/goldeen/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/goldeen/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Goldeen", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Goldeen LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/goldeen/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/goldeen/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Goldeen", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Goldeen fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/goldeen/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/goldeen/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Goldeen", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Goldeen fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/goldeen/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/goldeen/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Goldeen", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Seaking Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/seaking/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/seaking/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Seaking", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Seaking LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/seaking/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/seaking/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Seaking", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Seaking fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/seaking/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/seaking/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Seaking", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Seaking fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/seaking/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/seaking/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Seaking", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Staryu Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/staryu/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/staryu/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Staryu", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Staryu LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/staryu/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/staryu/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Staryu", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Staryu fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/staryu/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/staryu/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Staryu", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Staryu fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/staryu/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/staryu/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Staryu", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Starmie Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/starmie/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/starmie/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Starmie", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Starmie LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/starmie/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/starmie/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Starmie", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Starmie fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/starmie/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/starmie/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Starmie", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Starmie fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/starmie/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/starmie/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Starmie", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Scyther Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/scyther/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/scyther/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Scyther", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Scyther LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/scyther/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/scyther/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Scyther", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Scyther fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/scyther/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/scyther/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Scyther", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Scyther fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/scyther/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/scyther/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Scyther", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Jynx Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/jynx/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/jynx/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Jynx", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Jynx LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/jynx/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/jynx/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Jynx", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Jynx fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/jynx/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/jynx/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Jynx", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Jynx fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/jynx/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/jynx/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Jynx", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Electabuzz Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/electabuzz/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/electabuzz/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Electabuzz", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Electabuzz LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/electabuzz/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/electabuzz/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Electabuzz", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Electabuzz fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/electabuzz/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/electabuzz/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Electabuzz", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Electabuzz fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/electabuzz/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/electabuzz/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Electabuzz", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Magmar Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/magmar/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/magmar/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Magmar", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Magmar LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/magmar/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/magmar/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Magmar", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Magmar fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/magmar/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/magmar/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Magmar", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Magmar fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/magmar/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/magmar/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Magmar", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Pinsir Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/pinsir/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/pinsir/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Pinsir", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Pinsir LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/pinsir/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/pinsir/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Pinsir", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Pinsir fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/pinsir/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/pinsir/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Pinsir", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Pinsir fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/pinsir/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/pinsir/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Pinsir", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Tauros Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/tauros/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/tauros/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Tauros", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Tauros LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/tauros/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/tauros/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Tauros", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Tauros fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/tauros/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/tauros/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Tauros", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Tauros fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/tauros/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/tauros/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Tauros", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Magikarp Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/magikarp/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/magikarp/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Magikarp", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Magikarp LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/magikarp/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/magikarp/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Magikarp", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Magikarp fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/magikarp/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/magikarp/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Magikarp", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Magikarp fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/magikarp/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/magikarp/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Magikarp", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Gyarados Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/gyarados/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/gyarados/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Gyarados", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Gyarados LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/gyarados/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/gyarados/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Gyarados", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Gyarados fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/gyarados/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/gyarados/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Gyarados", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Gyarados fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/gyarados/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/gyarados/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Gyarados", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Lapras Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/lapras/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/lapras/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Lapras", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Lapras LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/lapras/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/lapras/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Lapras", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Lapras fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/lapras/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/lapras/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Lapras", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Lapras fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/lapras/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/lapras/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Lapras", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Ditto Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/ditto/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/ditto/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ditto", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Ditto LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/ditto/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/ditto/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ditto", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Ditto fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/ditto/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/ditto/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ditto", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Ditto fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/ditto/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/ditto/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Ditto", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Eevee Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/eevee/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/eevee/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Eevee", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Eevee LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/eevee/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/eevee/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Eevee", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Eevee fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/eevee/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/eevee/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Eevee", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Eevee fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/eevee/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/eevee/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Eevee", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Vaporeon Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/vaporeon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/vaporeon/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Vaporeon", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Vaporeon LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/vaporeon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/vaporeon/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Vaporeon", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Vaporeon fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/vaporeon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/vaporeon/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Vaporeon", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Vaporeon fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/vaporeon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/vaporeon/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Vaporeon", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Jolteon Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/jolteon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/jolteon/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Jolteon", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Jolteon LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/jolteon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/jolteon/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Jolteon", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Jolteon fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/jolteon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/jolteon/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Jolteon", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Jolteon fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/jolteon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/jolteon/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Jolteon", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Flareon Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/flareon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/flareon/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Flareon", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Flareon LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/flareon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/flareon/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Flareon", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Flareon fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/flareon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/flareon/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Flareon", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Flareon fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/flareon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/flareon/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Flareon", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Porygon Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/porygon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/porygon/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Porygon", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Porygon LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/porygon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/porygon/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Porygon", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Porygon fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/porygon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/porygon/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Porygon", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Porygon fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/porygon/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/porygon/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Porygon", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Omanyte Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/omanyte/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/omanyte/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Omanyte", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Omanyte LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/omanyte/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/omanyte/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Omanyte", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Omanyte fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/omanyte/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/omanyte/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Omanyte", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Omanyte fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/omanyte/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/omanyte/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Omanyte", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Omastar Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/omastar/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/omastar/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Omastar", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Omastar LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/omastar/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/omastar/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Omastar", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Omastar fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/omastar/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/omastar/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Omastar", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Omastar fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/omastar/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/omastar/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Omastar", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Kabuto Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kabuto/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kabuto/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kabuto", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Kabuto LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kabuto/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kabuto/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kabuto", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Kabuto fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kabuto/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kabuto/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kabuto", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Kabuto fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kabuto/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kabuto/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kabuto", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Kabutops Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kabutops/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kabutops/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kabutops", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Kabutops LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kabutops/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kabutops/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kabutops", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Kabutops fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kabutops/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kabutops/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kabutops", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Kabutops fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/kabutops/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/kabutops/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Kabutops", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Aerodactyl Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/aerodactyl/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/aerodactyl/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Aerodactyl", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Aerodactyl LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/aerodactyl/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/aerodactyl/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Aerodactyl", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Aerodactyl fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/aerodactyl/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/aerodactyl/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Aerodactyl", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Aerodactyl fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/aerodactyl/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/aerodactyl/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Aerodactyl", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Snorlax Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/snorlax/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/snorlax/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Snorlax", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Snorlax LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/snorlax/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/snorlax/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Snorlax", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Snorlax fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/snorlax/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/snorlax/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Snorlax", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Snorlax fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/snorlax/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/snorlax/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Snorlax", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Articuno Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/articuno/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/articuno/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Articuno", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Articuno LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/articuno/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/articuno/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Articuno", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Articuno fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/articuno/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/articuno/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Articuno", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Articuno fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/articuno/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/articuno/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Articuno", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Zapdos Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/zapdos/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/zapdos/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Zapdos", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Zapdos LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/zapdos/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/zapdos/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Zapdos", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Zapdos fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/zapdos/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/zapdos/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Zapdos", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Zapdos fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/zapdos/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/zapdos/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Zapdos", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Moltres Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/moltres/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/moltres/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Moltres", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Moltres LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/moltres/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/moltres/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Moltres", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Moltres fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/moltres/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/moltres/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Moltres", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Moltres fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/moltres/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/moltres/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Moltres", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Dratini Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dratini/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dratini/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dratini", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Dratini LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dratini/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dratini/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dratini", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Dratini fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dratini/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dratini/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dratini", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Dratini fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dratini/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dratini/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dratini", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Dragonair Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dragonair/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dragonair/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dragonair", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Dragonair LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dragonair/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dragonair/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dragonair", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Dragonair fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dragonair/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dragonair/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dragonair", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Dragonair fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dragonair/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dragonair/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dragonair", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Dragonite Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dragonite/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dragonite/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dragonite", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Dragonite LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dragonite/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dragonite/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dragonite", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Dragonite fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dragonite/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dragonite/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dragonite", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Dragonite fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/dragonite/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/dragonite/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Dragonite", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Mewtwo Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/mewtwo/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/mewtwo/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Mewtwo", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Mewtwo LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/mewtwo/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/mewtwo/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Mewtwo", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Mewtwo fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/mewtwo/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/mewtwo/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Mewtwo", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Mewtwo fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/mewtwo/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/mewtwo/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Mewtwo", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
TEST("Compression test: Mew Smol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/mew/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/mew/anim_front.png", ".4bpp.smol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Mew", COMPRESSION_SMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Mew LZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/mew/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/mew/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Mew", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Mew fastLZ")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/mew/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/mew/anim_front.png", ".4bpp.lz");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Mew", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: Mew fastSmol")
{
    static const u32 origFile[] = INCGFX_U32("graphics/pokemon/mew/anim_front.png", ".4bpp");
    static const u32 compFile[] = INCGFX_U32("graphics/pokemon/mew/anim_front.png", ".4bpp.fastSmol");

    bool32 areEqual = DecompressImgPrintResults(compFile, origFile, "Mew", COMPRESSION_FASTSMOL, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
#endif // ENABLE_ALL_COMPRESSION_TESTS

TEST("Compression test: tilemap small smolTM")
{
    static const u16 origFile[] = INCBIN_U16("test/compression/tilemap.bin");
    static const u32 compFile[] = INCGFX_U32("test/compression/tilemap.bin", ".smolTM");

    bool32 areEqual = DecompressTilemapPrintResults(compFile, origFile, "Tilemap", COMPRESSION_SMOL_TILEMAP, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: tilemap small LZ")
{
    static const u16 origFile[] = INCBIN_U16("test/compression/tilemap.bin");
    static const u32 compFile[] = INCGFX_U32("test/compression/tilemap.bin", ".lz");

    bool32 areEqual = DecompressTilemapPrintResults(compFile, origFile, "Tilemap", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: tilemap small fastLZ")
{
    static const u16 origFile[] = INCBIN_U16("test/compression/tilemap.bin");
    static const u32 compFile[] = INCGFX_U32("test/compression/tilemap.bin", ".lz");

    bool32 areEqual = DecompressTilemapPrintResults(compFile, origFile, "Tilemap", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: tilemap large smolTM")
{
    static const u16 origFile[] = INCBIN_U16("test/compression/tilemapLarge.bin");
    static const u32 compFile[] = INCGFX_U32("test/compression/tilemapLarge.bin", ".smolTM");

    bool32 areEqual = DecompressTilemapPrintResults(compFile, origFile, "Tilemap", COMPRESSION_SMOL_TILEMAP, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: tilemap large LZ")
{
    static const u16 origFile[] = INCBIN_U16("test/compression/tilemapLarge.bin");
    static const u32 compFile[] = INCGFX_U32("test/compression/tilemapLarge.bin", ".lz");

    bool32 areEqual = DecompressTilemapPrintResults(compFile, origFile, "Tilemap", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: tilemap large fastLZ")
{
    static const u16 origFile[] = INCBIN_U16("test/compression/tilemapLarge.bin");
    static const u32 compFile[] = INCGFX_U32("test/compression/tilemapLarge.bin", ".lz");

    bool32 areEqual = DecompressTilemapPrintResults(compFile, origFile, "Tilemap", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: tilemap small smolTM VRAM")
{
    static const u16 origFile[] = INCBIN_U16("test/compression/tilemap.bin");
    static const u32 compFile[] = INCGFX_U32("test/compression/tilemap.bin", ".smolTM");

    bool32 areEqual = DecompressTilemapPrintResultsVram(compFile, origFile, "Tilemap", COMPRESSION_SMOL_TILEMAP, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: tilemap small LZ VRAM")
{
    static const u16 origFile[] = INCBIN_U16("test/compression/tilemap.bin");
    static const u32 compFile[] = INCGFX_U32("test/compression/tilemap.bin", ".lz");

    bool32 areEqual = DecompressTilemapPrintResultsVram(compFile, origFile, "Tilemap", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

//  The fastLZ function for this doesn't exist
/*
TEST("Compression test: tilemap small fastLZ VRAM")
{
    static const u16 origFile[] = INCBIN_U16("test/compression/tilemap.bin");
    static const u32 compFile[] = INCGFX_U32("test/compression/tilemap.bin", ".lz");

    bool32 areEqual = DecompressTilemapPrintResultsVram(compFile, origFile, "Tilemap", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
*/

TEST("Compression test: tilemap large smolTM VRAM")
{
    static const u16 origFile[] = INCBIN_U16("test/compression/tilemapLarge.bin");
    static const u32 compFile[] = INCGFX_U32("test/compression/tilemapLarge.bin", ".smolTM");

    bool32 areEqual = DecompressTilemapPrintResultsVram(compFile, origFile, "Tilemap", COMPRESSION_SMOL_TILEMAP, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

TEST("Compression test: tilemap large LZ VRAM")
{
    static const u16 origFile[] = INCBIN_U16("test/compression/tilemapLarge.bin");
    static const u32 compFile[] = INCGFX_U32("test/compression/tilemapLarge.bin", ".lz");

    bool32 areEqual = DecompressTilemapPrintResultsVram(compFile, origFile, "Tilemap", COMPRESSION_LZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}

//  The fastLZ function for this doesn't exist
/*
TEST("Compression test: tilemap large fastLZ VRAM")
{
    static const u16 origFile[] = INCBIN_U16("test/compression/tilemapLarge.bin");
    static const u32 compFile[] = INCGFX_U32("test/compression/tilemapLarge.bin", ".lz");

    bool32 areEqual = DecompressTilemapPrintResultsVram(compFile, origFile, "Tilemap", COMPRESSION_FASTLZ, sizeof(compFile));
    EXPECT_EQ(areEqual, TRUE);
}
*/
