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

struct CommandHandler
{
    const char *inputFileExtension;
    const char *outputFileExtension;
    void(*function)(char *inputPath, char *outputPath, int argc, char **argv);
};

void ConvertGbaToPng(char *inputPath, char *outputPath, struct GbaToPngOptions *options)
{
    struct Image image;

    if (options->paletteFilePath != NULL)
    {
        ReadGbaPalette(options->paletteFilePath, &image.palette);
        image.hasPalette = true;
    }
    else
    {
        image.hasPalette = false;
    }

    ReadImage(inputPath, options->width, options->bitDepth, options->metatileWidth, options->metatileHeight, &image, !image.hasPalette);

    image.hasTransparency = options->hasTransparency;

    WritePng(outputPath, &image);

    FreeImage(&image);
}

void ConvertPngToGba(char *inputPath, char *outputPath, struct PngToGbaOptions *options)
{
    struct Image image;

    image.bitDepth = options->bitDepth;

    ReadPng(inputPath, &image);

    WriteImage(outputPath, options->numTiles, options->bitDepth, options->metatileWidth, options->metatileHeight, &image, !image.hasPalette);

    FreeImage(&image);
}

void HandleGbaToPngCommand(char *inputPath, char *outputPath, int argc, char **argv)
{
    char *inputFileExtension = GetFileExtension(inputPath);
    struct GbaToPngOptions options;
    options.paletteFilePath = NULL;
    options.bitDepth = inputFileExtension[0] - '0';
    options.hasTransparency = false;
    options.width = 1;
    options.metatileWidth = 1;
    options.metatileHeight = 1;

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
    char *outputFileExtension = GetFileExtension(outputPath);
    int bitDepth = outputFileExtension[0] - '0';
    struct PngToGbaOptions options;
    options.numTiles = 0;
    options.bitDepth = bitDepth;
    options.metatileWidth = 1;
    options.metatileHeight = 1;

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
        else
        {
            FATAL_ERROR("Unrecognized option \"%s\".\n", option);
        }
    }

    ConvertPngToGba(inputPath, outputPath, &options);
}

void HandlePngToGbaPaletteCommand(char *inputPath, char *outputPath, int argc UNUSED, char **argv UNUSED)
{
    struct Palette palette;

    ReadPngPalette(inputPath, &palette);
    WriteGbaPalette(outputPath, &palette);
}

void HandleGbaToJascPaletteCommand(char *inputPath, char *outputPath, int argc UNUSED, char **argv UNUSED)
{
    struct Palette palette;

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

    struct Palette palette;

    ReadJascPalette(inputPath, &palette);

    if (numColors != 0)
        palette.numColors = numColors;

    WriteGbaPalette(outputPath, &palette);
}

void HandleLatinFontToPngCommand(char *inputPath, char *outputPath, int argc UNUSED, char **argv UNUSED)
{
    struct Image image;

    ReadLatinFont(inputPath, &image);
    WritePng(outputPath, &image);

    FreeImage(&image);
}

void HandlePngToLatinFontCommand(char *inputPath, char *outputPath, int argc UNUSED, char **argv UNUSED)
{
    struct Image image;

    image.bitDepth = 2;

    ReadPng(inputPath, &image);
    WriteLatinFont(outputPath, &image);

    FreeImage(&image);
}

void HandleHalfwidthJapaneseFontToPngCommand(char *inputPath, char *outputPath, int argc UNUSED, char **argv UNUSED)
{
    struct Image image;

    ReadHalfwidthJapaneseFont(inputPath, &image);
    WritePng(outputPath, &image);

    FreeImage(&image);
}

void HandlePngToHalfwidthJapaneseFontCommand(char *inputPath, char *outputPath, int argc UNUSED, char **argv UNUSED)
{
    struct Image image;

    image.bitDepth = 2;

    ReadPng(inputPath, &image);
    WriteHalfwidthJapaneseFont(outputPath, &image);

    FreeImage(&image);
}

void HandleFullwidthJapaneseFontToPngCommand(char *inputPath, char *outputPath, int argc UNUSED, char **argv UNUSED)
{
    struct Image image;

    ReadFullwidthJapaneseFont(inputPath, &image);
    WritePng(outputPath, &image);

    FreeImage(&image);
}

void HandlePngToFullwidthJapaneseFontCommand(char *inputPath, char *outputPath, int argc UNUSED, char **argv UNUSED)
{
    struct Image image;

    image.bitDepth = 2;

    ReadPng(inputPath, &image);
    WriteFullwidthJapaneseFont(outputPath, &image);

    FreeImage(&image);
}

void HandleLZCompressCommand(char *inputPath, char *outputPath, int argc, char **argv)
{
    int overflowSize = 0;

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
    unsigned char *compressedData = LZCompress(buffer, fileSize + overflowSize, &compressedSize);

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

int main(int argc, char **argv)
{
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
        { "gbapal", "pal", HandleGbaToJascPaletteCommand },
        { "pal", "gbapal", HandleJascToGbaPaletteCommand },
        { "latfont", "png", HandleLatinFontToPngCommand },
        { "png", "latfont", HandlePngToLatinFontCommand },
        { "hwjpnfont", "png", HandleHalfwidthJapaneseFontToPngCommand },
        { "png", "hwjpnfont", HandlePngToHalfwidthJapaneseFontCommand },
        { "fwjpnfont", "png", HandleFullwidthJapaneseFontToPngCommand },
        { "png", "fwjpnfont", HandlePngToFullwidthJapaneseFontCommand },
        { NULL, "lz", HandleLZCompressCommand },
        { "lz", NULL, HandleLZDecompressCommand },
        { NULL, "rl", HandleRLCompressCommand },
        { "rl", NULL, HandleRLDecompressCommand },
        { NULL, NULL, NULL }
    };

    char *inputPath = argv[1];
    char *outputPath = argv[2];
    char *inputFileExtension = GetFileExtension(inputPath);
    char *outputFileExtension = GetFileExtension(outputPath);

    if (inputFileExtension == NULL)
        FATAL_ERROR("Input file \"%s\" has no extension.\n", inputPath);

    if (outputFileExtension == NULL)
        FATAL_ERROR("Output file \"%s\" has no extension.\n", outputPath);

    for (int i = 0; handlers[i].function != NULL; i++)
    {
        if ((handlers[i].inputFileExtension == NULL || strcmp(handlers[i].inputFileExtension, inputFileExtension) == 0)
            && (handlers[i].outputFileExtension == NULL || strcmp(handlers[i].outputFileExtension, outputFileExtension) == 0))
        {
            handlers[i].function(inputPath, outputPath, argc, argv);
            return 0;
        }
    }

    FATAL_ERROR("Don't know how to convert \"%s\" to \"%s\".\n", inputPath, outputPath);
}
