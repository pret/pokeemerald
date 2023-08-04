// Copyright (c) 2015 YamaArashi

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "global.h"
#include "util.h"
#include "options.h"
#include "gfx.h"
#include "convert_png.h"
#include "jasc_pal.h"
#include "lz.h"
#include "rl.h"
#include "font.h"
#include "huff.h"

struct CommandHandler
{
    const char *inputFileExtension;
    const char *outputFileExtension;
    void(*function)(char *inputPath, char *outputPath, int argc, char **argv);
};

void ConvertGbaToPng(char *inputPath, char *outputPath, struct GbaToPngOptions *options)
{
    struct Image image;

    image.bitDepth = options->bitDepth;
    image.tilemap.data.affine = NULL;

    if (options->paletteFilePath != NULL)
    {
        char *paletteFileExtension = GetFileExtensionAfterDot(options->paletteFilePath);

        if (strcmp(paletteFileExtension, "gbapal") == 0)
        {
            ReadGbaPalette(options->paletteFilePath, &image.palette);
        }
        else
        {
            ReadJascPalette(options->paletteFilePath, &image.palette);
        }

        image.hasPalette = true;
    }
    else
    {
        image.hasPalette = false;
    }

    if (options->isTiled)
    {
        if (options->tilemapFilePath != NULL)
        {
            int fileSize;
            image.tilemap.data.affine = ReadWholeFile(options->tilemapFilePath, &fileSize);
            if (options->isAffineMap && options->bitDepth != 8)
                FATAL_ERROR("affine maps are necessarily 8bpp\n");
            image.isAffine = options->isAffineMap;
            image.tilemap.size = fileSize;
        }
        ReadTileImage(inputPath, options->width, options->metatileWidth, options->metatileHeight, &image, !image.hasPalette);
    }
    else
    {
        image.width = options->width;
        ReadPlainImage(inputPath, options->dataWidth, &image, !image.hasPalette);
    }

    image.hasTransparency = options->hasTransparency;

    WritePng(outputPath, &image);

    FreeImage(&image);
}

void ConvertPngToGba(char *inputPath, char *outputPath, struct PngToGbaOptions *options)
{
    struct Image image;

    image.bitDepth = options->bitDepth;
    image.tilemap.data.affine = NULL; // initialize to NULL to avoid issues in FreeImage

    ReadPng(inputPath, &image);

    if (options->isTiled)
        WriteTileImage(outputPath, options->numTilesMode, options->numTiles, options->metatileWidth, options->metatileHeight, &image, !image.hasPalette);
    else
        WritePlainImage(outputPath, options->dataWidth, &image, !image.hasPalette);

    FreeImage(&image);
}

void HandleGbaToPngCommand(char *inputPath, char *outputPath, int argc, char **argv)
{
    char *inputFileExtension = GetFileExtensionAfterDot(inputPath);
    struct GbaToPngOptions options;
    options.paletteFilePath = NULL;
    options.bitDepth = inputFileExtension[0] - '0';
    options.hasTransparency = false;
    options.width = 1;
    options.metatileWidth = 1;
    options.metatileHeight = 1;
    options.tilemapFilePath = NULL;
    options.isAffineMap = false;
    options.isTiled = true;
    options.dataWidth = 1;

    for (int i = 3; i < argc; i++)
    {
        char *option = argv[i];

        if (strcmp(option, "-palette") == 0)
        {
            if (i + 1 >= argc)
                FATAL_ERROR("No palette file path following \"-palette\".\n");

            i++;

            options.paletteFilePath = argv[i];
        }
        else if (strcmp(option, "-object") == 0)
        {
            options.hasTransparency = true;
        }
        else if (strcmp(option, "-width") == 0)
        {
            if (i + 1 >= argc)
                FATAL_ERROR("No width following \"-width\".\n");

            i++;

            if (!ParseNumber(argv[i], NULL, 10, &options.width))
                FATAL_ERROR("Failed to parse width.\n");

            if (options.width < 1)
                FATAL_ERROR("Width must be positive.\n");
        }
        else if (strcmp(option, "-mwidth") == 0)
        {
            if (i + 1 >= argc)
                FATAL_ERROR("No metatile width value following \"-mwidth\".\n");

            i++;

            if (!ParseNumber(argv[i], NULL, 10, &options.metatileWidth))
                FATAL_ERROR("Failed to parse metatile width.\n");

            if (options.metatileWidth < 1)
                FATAL_ERROR("metatile width must be positive.\n");
        }
        else if (strcmp(option, "-mheight") == 0)
        {
            if (i + 1 >= argc)
                FATAL_ERROR("No metatile height value following \"-mheight\".\n");

            i++;

            if (!ParseNumber(argv[i], NULL, 10, &options.metatileHeight))
                FATAL_ERROR("Failed to parse metatile height.\n");

            if (options.metatileHeight < 1)
                FATAL_ERROR("metatile height must be positive.\n");
        }
        else if (strcmp(option, "-tilemap") == 0)
        {
            if (i + 1 >= argc)
                FATAL_ERROR("No tilemap value following \"-tilemap\".\n");
            i++;
            options.tilemapFilePath = argv[i];
        }
        else if (strcmp(option, "-affine") == 0)
        {
            options.isAffineMap = true;
        }
        else if (strcmp(option, "-plain") == 0)
        {
            options.isTiled = false;
        }
        else if (strcmp(option, "-data_width") == 0)
        {
            if (i + 1 >= argc)
                FATAL_ERROR("No data width value following \"-data_width\".\n");
            i++;

            if (!ParseNumber(argv[i], NULL, 10, &options.dataWidth))
                FATAL_ERROR("Failed to parse data width.\n");

            if (options.dataWidth < 1)
                FATAL_ERROR("Data width must be positive.\n");
        }
        else
        {
            FATAL_ERROR("Unrecognized option \"%s\".\n", option);
        }
    }

    if (options.metatileWidth > options.width)
        options.width = options.metatileWidth;

    ConvertGbaToPng(inputPath, outputPath, &options);
}

void HandlePngToGbaCommand(char *inputPath, char *outputPath, int argc, char **argv)
{
    char *outputFileExtension = GetFileExtensionAfterDot(outputPath);
    struct PngToGbaOptions options;
    options.numTilesMode = NUM_TILES_IGNORE;
    options.numTiles = 0;
    options.bitDepth = outputFileExtension[0] - '0';
    options.metatileWidth = 1;
    options.metatileHeight = 1;
    options.tilemapFilePath = NULL;
    options.isAffineMap = false;
    options.isTiled = true;
    options.dataWidth = 1;

    for (int i = 3; i < argc; i++)
    {
        char *option = argv[i];

        if (strcmp(option, "-num_tiles") == 0)
        {
            if (i + 1 >= argc)
                FATAL_ERROR("No number of tiles following \"-num_tiles\".\n");

            i++;

            if (!ParseNumber(argv[i], NULL, 10, &options.numTiles))
                FATAL_ERROR("Failed to parse number of tiles.\n");

            if (options.numTiles < 1)
                FATAL_ERROR("Number of tiles must be positive.\n");
        }
        else if (strcmp(option, "-Wnum_tiles") == 0) {
            options.numTilesMode = NUM_TILES_WARN;
        }
        else if (strcmp(option, "-Werror=num_tiles") == 0) {
            options.numTilesMode = NUM_TILES_ERROR;
        }
        else if (strcmp(option, "-mwidth") == 0)
        {
            if (i + 1 >= argc)
                FATAL_ERROR("No metatile width value following \"-mwidth\".\n");

            i++;

            if (!ParseNumber(argv[i], NULL, 10, &options.metatileWidth))
                FATAL_ERROR("Failed to parse metatile width.\n");

            if (options.metatileWidth < 1)
                FATAL_ERROR("metatile width must be positive.\n");
        }
        else if (strcmp(option, "-mheight") == 0)
        {
            if (i + 1 >= argc)
                FATAL_ERROR("No metatile height value following \"-mheight\".\n");

            i++;

            if (!ParseNumber(argv[i], NULL, 10, &options.metatileHeight))
                FATAL_ERROR("Failed to parse metatile height.\n");

            if (options.metatileHeight < 1)
                FATAL_ERROR("metatile height must be positive.\n");
        }
        else if (strcmp(option, "-plain") == 0)
        {
            options.isTiled = false;
        }
        else if (strcmp(option, "-data_width") == 0)
        {
            if (i + 1 >= argc)
                FATAL_ERROR("No data width value following \"-data_width\".\n");
            i++;

            if (!ParseNumber(argv[i], NULL, 10, &options.dataWidth))
                FATAL_ERROR("Failed to parse data width.\n");

            if (options.dataWidth < 1)
                FATAL_ERROR("Data width must be positive.\n");
        }
        else
        {
            FATAL_ERROR("Unrecognized option \"%s\".\n", option);
        }
    }

    ConvertPngToGba(inputPath, outputPath, &options);
}

void HandlePngToJascPaletteCommand(char *inputPath, char *outputPath, int argc UNUSED, char **argv UNUSED)
{
    struct Palette palette = {};

    ReadPngPalette(inputPath, &palette);
    WriteJascPalette(outputPath, &palette);
}

void HandlePngToGbaPaletteCommand(char *inputPath, char *outputPath, int argc UNUSED, char **argv UNUSED)
{
    struct Palette palette = {};

    ReadPngPalette(inputPath, &palette);
    WriteGbaPalette(outputPath, &palette);
}

void HandleGbaToJascPaletteCommand(char *inputPath, char *outputPath, int argc UNUSED, char **argv UNUSED)
{
    struct Palette palette = {};

    ReadGbaPalette(inputPath, &palette);
    WriteJascPalette(outputPath, &palette);
}

void HandleJascToGbaPaletteCommand(char *inputPath, char *outputPath, int argc, char **argv)
{
    int numColors = 0;

    for (int i = 3; i < argc; i++)
    {
        char *option = argv[i];

        if (strcmp(option, "-num_colors") == 0)
        {
            if (i + 1 >= argc)
                FATAL_ERROR("No number of colors following \"-num_colors\".\n");

            i++;

            if (!ParseNumber(argv[i], NULL, 10, &numColors))
                FATAL_ERROR("Failed to parse number of colors.\n");

            if (numColors < 1)
                FATAL_ERROR("Number of colors must be positive.\n");
        }
        else
        {
            FATAL_ERROR("Unrecognized option \"%s\".\n", option);
        }
    }

    struct Palette palette = {};

    ReadJascPalette(inputPath, &palette);

    if (numColors != 0)
        palette.numColors = numColors;

    WriteGbaPalette(outputPath, &palette);
}

void HandleLatinFontToPngCommand(char *inputPath, char *outputPath, int argc UNUSED, char **argv UNUSED)
{
    struct Image image;
    image.tilemap.data.affine = NULL; // initialize to NULL to avoid issues in FreeImage

    ReadLatinFont(inputPath, &image);
    WritePng(outputPath, &image);

    FreeImage(&image);
}

void HandlePngToLatinFontCommand(char *inputPath, char *outputPath, int argc UNUSED, char **argv UNUSED)
{
    struct Image image;
    image.tilemap.data.affine = NULL; // initialize to NULL to avoid issues in FreeImage

    image.bitDepth = 2;

    ReadPng(inputPath, &image);
    WriteLatinFont(outputPath, &image);

    FreeImage(&image);
}

void HandleHalfwidthJapaneseFontToPngCommand(char *inputPath, char *outputPath, int argc UNUSED, char **argv UNUSED)
{
    struct Image image;
    image.tilemap.data.affine = NULL; // initialize to NULL to avoid issues in FreeImage

    ReadHalfwidthJapaneseFont(inputPath, &image);
    WritePng(outputPath, &image);

    FreeImage(&image);
}

void HandlePngToHalfwidthJapaneseFontCommand(char *inputPath, char *outputPath, int argc UNUSED, char **argv UNUSED)
{
    struct Image image;
    image.tilemap.data.affine = NULL; // initialize to NULL to avoid issues in FreeImage

    image.bitDepth = 2;

    ReadPng(inputPath, &image);
    WriteHalfwidthJapaneseFont(outputPath, &image);

    FreeImage(&image);
}

void HandleFullwidthJapaneseFontToPngCommand(char *inputPath, char *outputPath, int argc UNUSED, char **argv UNUSED)
{
    struct Image image;
    image.tilemap.data.affine = NULL; // initialize to NULL to avoid issues in FreeImage

    ReadFullwidthJapaneseFont(inputPath, &image);
    WritePng(outputPath, &image);

    FreeImage(&image);
}

void HandlePngToFullwidthJapaneseFontCommand(char *inputPath, char *outputPath, int argc UNUSED, char **argv UNUSED)
{
    struct Image image;
    image.tilemap.data.affine = NULL; // initialize to NULL to avoid issues in FreeImage

    image.bitDepth = 2;

    ReadPng(inputPath, &image);
    WriteFullwidthJapaneseFont(outputPath, &image);

    FreeImage(&image);
}

void HandleLZCompressCommand(char *inputPath, char *outputPath, int argc, char **argv)
{
    int overflowSize = 0;
    int minDistance = 2; // default, for compatibility with LZ77UnCompVram()

    for (int i = 3; i < argc; i++)
    {
        char *option = argv[i];

        if (strcmp(option, "-overflow") == 0)
        {
            if (i + 1 >= argc)
                FATAL_ERROR("No size following \"-overflow\".\n");

            i++;

            if (!ParseNumber(argv[i], NULL, 10, &overflowSize))
                FATAL_ERROR("Failed to parse overflow size.\n");

            if (overflowSize < 1)
                FATAL_ERROR("Overflow size must be positive.\n");
        }
        else if (strcmp(option, "-search") == 0)
        {
            if (i + 1 >= argc)
                FATAL_ERROR("No size following \"-search\".\n");

            i++;

            if (!ParseNumber(argv[i], NULL, 10, &minDistance))
                FATAL_ERROR("Failed to parse LZ min search distance.\n");

            if (minDistance < 1)
                FATAL_ERROR("LZ min search distance must be positive.\n");
        }
        else
        {
            FATAL_ERROR("Unrecognized option \"%s\".\n", option);
        }
    }

    // The overflow option allows a quirk in some of Ruby/Sapphire's tilesets
    // to be reproduced. It works by appending a number of zeros to the data
    // before compressing it and then amending the LZ header's size field to
    // reflect the expected size. This will cause an overflow when decompressing
    // the data.

    int fileSize;
    unsigned char *buffer = ReadWholeFileZeroPadded(inputPath, &fileSize, overflowSize);

    int compressedSize;
    unsigned char *compressedData = LZCompress(buffer, fileSize + overflowSize, &compressedSize, minDistance);

    compressedData[1] = (unsigned char)fileSize;
    compressedData[2] = (unsigned char)(fileSize >> 8);
    compressedData[3] = (unsigned char)(fileSize >> 16);

    free(buffer);

    WriteWholeFile(outputPath, compressedData, compressedSize);

    free(compressedData);
}

void HandleLZDecompressCommand(char *inputPath, char *outputPath, int argc UNUSED, char **argv UNUSED)
{
    int fileSize;
    unsigned char *buffer = ReadWholeFile(inputPath, &fileSize);

    int uncompressedSize;
    unsigned char *uncompressedData = LZDecompress(buffer, fileSize, &uncompressedSize);

    free(buffer);

    WriteWholeFile(outputPath, uncompressedData, uncompressedSize);

    free(uncompressedData);
}

void HandleRLCompressCommand(char *inputPath, char *outputPath, int argc UNUSED, char **argv UNUSED)
{
    int fileSize;
    unsigned char *buffer = ReadWholeFile(inputPath, &fileSize);

    int compressedSize;
    unsigned char *compressedData = RLCompress(buffer, fileSize, &compressedSize);

    free(buffer);

    WriteWholeFile(outputPath, compressedData, compressedSize);

    free(compressedData);
}

void HandleRLDecompressCommand(char *inputPath, char *outputPath, int argc UNUSED, char **argv UNUSED)
{
    int fileSize;
    unsigned char *buffer = ReadWholeFile(inputPath, &fileSize);

    int uncompressedSize;
    unsigned char *uncompressedData = RLDecompress(buffer, fileSize, &uncompressedSize);

    free(buffer);

    WriteWholeFile(outputPath, uncompressedData, uncompressedSize);

    free(uncompressedData);
}

void HandleHuffCompressCommand(char *inputPath, char *outputPath, int argc, char **argv)
{
    int fileSize;
    int bitDepth = 4;

    for (int i = 3; i < argc; i++)
    {
        char *option = argv[i];

        if (strcmp(option, "-depth") == 0)
        {
            if (i + 1 >= argc)
                FATAL_ERROR("No size following \"-depth\".\n");

            i++;

            if (!ParseNumber(argv[i], NULL, 10, &bitDepth))
                FATAL_ERROR("Failed to parse bit depth.\n");

            if (bitDepth != 4 && bitDepth != 8)
                FATAL_ERROR("GBA only supports bit depth of 4 or 8.\n");
        }
        else
        {
            FATAL_ERROR("Unrecognized option \"%s\".\n", option);
        }
    }

    unsigned char *buffer = ReadWholeFile(inputPath, &fileSize);

    int compressedSize;
    unsigned char *compressedData = HuffCompress(buffer, fileSize, &compressedSize, bitDepth);

    free(buffer);

    WriteWholeFile(outputPath, compressedData, compressedSize);

    free(compressedData);
}

void HandleHuffDecompressCommand(char *inputPath, char *outputPath, int argc UNUSED, char **argv UNUSED)
{
    int fileSize;
    unsigned char *buffer = ReadWholeFile(inputPath, &fileSize);

    int uncompressedSize;
    unsigned char *uncompressedData = HuffDecompress(buffer, fileSize, &uncompressedSize);

    free(buffer);

    WriteWholeFile(outputPath, uncompressedData, uncompressedSize);

    free(uncompressedData);
}

int main(int argc, char **argv)
{
    char converted = 0;

    if (argc < 3)
        FATAL_ERROR("Usage: gbagfx INPUT_PATH OUTPUT_PATH [options...]\n");

    struct CommandHandler handlers[] =
    {
        { "1bpp", "png", HandleGbaToPngCommand },
        { "4bpp", "png", HandleGbaToPngCommand },
        { "8bpp", "png", HandleGbaToPngCommand },
        { "png", "1bpp", HandlePngToGbaCommand },
        { "png", "4bpp", HandlePngToGbaCommand },
        { "png", "8bpp", HandlePngToGbaCommand },
        { "png", "gbapal", HandlePngToGbaPaletteCommand },
        { "png", "pal", HandlePngToJascPaletteCommand },
        { "gbapal", "pal", HandleGbaToJascPaletteCommand },
        { "pal", "gbapal", HandleJascToGbaPaletteCommand },
        { "latfont", "png", HandleLatinFontToPngCommand },
        { "png", "latfont", HandlePngToLatinFontCommand },
        { "hwjpnfont", "png", HandleHalfwidthJapaneseFontToPngCommand },
        { "png", "hwjpnfont", HandlePngToHalfwidthJapaneseFontCommand },
        { "fwjpnfont", "png", HandleFullwidthJapaneseFontToPngCommand },
        { "png", "fwjpnfont", HandlePngToFullwidthJapaneseFontCommand },
        { NULL, "huff", HandleHuffCompressCommand },
        { NULL, "lz", HandleLZCompressCommand },
        { "huff", NULL, HandleHuffDecompressCommand },
        { "lz", NULL, HandleLZDecompressCommand },
        { NULL, "rl", HandleRLCompressCommand },
        { "rl", NULL, HandleRLDecompressCommand },
        { NULL, NULL, NULL }
    };

    char *inputPath = argv[1];
    char *outputPath = argv[2];
    char *inputFileExtension = GetFileExtensionAfterDot(inputPath);
    char *outputFileExtension = GetFileExtensionAfterDot(outputPath);

    if (inputFileExtension == NULL)
        FATAL_ERROR("Input file \"%s\" has no extension.\n", inputPath);

    if (outputFileExtension == NULL)
    {
        outputFileExtension = GetFileExtension(outputPath);

        if (*outputFileExtension == '.')
            outputFileExtension++;

        if (*outputFileExtension == 0)
            FATAL_ERROR("Output file \"%s\" has no extension.\n", outputPath);

        size_t newOutputPathSize = strlen(inputPath) - strlen(inputFileExtension) + strlen(outputFileExtension);
        outputPath = malloc(newOutputPathSize);

        if (outputPath == NULL)
            FATAL_ERROR("Failed to allocate memory for new output path.\n");

        for (int i = 0; i < newOutputPathSize; i++)
        {
            outputPath[i] = inputPath[i];

            if (outputPath[i] == '.')
            {
                strcpy(&outputPath[i + 1], outputFileExtension);
                break;
            }
        }
    }

    for (int i = 0; handlers[i].function != NULL; i++)
    {
        if ((handlers[i].inputFileExtension == NULL || strcmp(handlers[i].inputFileExtension, inputFileExtension) == 0)
            && (handlers[i].outputFileExtension == NULL || strcmp(handlers[i].outputFileExtension, outputFileExtension) == 0))
        {
            handlers[i].function(inputPath, outputPath, argc, argv);
            converted = 1;
            break;
        }
    }

    if (outputPath != argv[2])
        free(outputPath);

    if (!converted)
        FATAL_ERROR("Don't know how to convert \"%s\" to \"%s\".\n", argv[1], argv[2]);

    return 0;
}
