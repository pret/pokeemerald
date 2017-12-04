// Copyright(c) 2015-2016 YamaArashi
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "global.h"
#include "font.h"
#include "gfx.h"
#include "util.h"

unsigned char gFontPalette[][3] =
{
    {0xFF, 0xFF, 0xFF}, // bg (white)
    {0x38, 0x38, 0x38}, // fg (dark grey)
    {0xD8, 0xD8, 0xD8}, // shadow (light grey)
};

void ConvertFromTiles1Bpp(unsigned char *src, unsigned char *dest, int numGlyphs, int layout)
{
    for (int glyph = 0; glyph < numGlyphs; glyph++)
    {
        if (layout == 0)
        {
            for (int i = 0; i < 8; i++)
            {
                uint8_t srcRow = src[(glyph * 8) + i];

                for (int j = 0; j < 8; j++)
                {
                    int x = ((glyph % 16) * 8) + j;
                    int y = ((glyph / 16) * 8) + i;
                    dest[(y * 128) + x] = (srcRow >> (7 - j)) & 1;
                }
            }
        }
        else
        {
            // layout type 1

            int tile1Offset = glyph * 16;
            int tile2Offset = tile1Offset + 8;

            for (int i = 0; i < 8; i++)
            {
                uint8_t srcRow = src[tile1Offset + i];

                for (int j = 0; j < 8; j++)
                {
                    int x = ((glyph % 16) * 8) + j;
                    int y = ((glyph / 16) * 16) + i;
                    dest[(y * 128) + x] = (srcRow >> (7 - j)) & 1;
                }
            }

            for (int i = 0; i < 8; i++)
            {
                uint8_t srcRow = src[tile2Offset + i];

                for (int j = 0; j < 8; j++)
                {
                    int x = ((glyph % 16) * 8) + j;
                    int y = ((glyph / 16) * 16) + 8 + i;
                    dest[(y * 128) + x] = (srcRow >> (7 - j)) & 1;
                }
            }
        }
    }
}

void ConvertToTiles1Bpp(unsigned char *src, unsigned char *dest, int numGlyphs, int layout)
{
    for (int glyph = 0; glyph < numGlyphs; glyph++)
    {
        if (layout == 0)
        {
            for (int i = 0; i < 8; i++)
            {
                uint8_t destRow = 0;

                for (int j = 0; j < 8; j++)
                {
                    int x = ((glyph % 16) * 8) + j;
                    int y = ((glyph / 16) * 8) + i;
                    unsigned char color = src[(y * 128) + x];

                    if (color > 1)
                        FATAL_ERROR("More than 2 colors in 1 BPP font.\n");

                    destRow <<= 1;
                    destRow |= color;
                }

                dest[(glyph * 8) + i] = destRow;
            }
        }
        else
        {
            // layout type 1

            int tile1Offset = glyph * 16;
            int tile2Offset = tile1Offset + 8;

            for (int i = 0; i < 8; i++)
            {
                uint8_t destRow = 0;

                for (int j = 0; j < 8; j++)
                {
                    int x = ((glyph % 16) * 8) + j;
                    int y = ((glyph / 16) * 16) + i;
                    unsigned char color = src[(y * 128) + x];

                    if (color > 1)
                        FATAL_ERROR("More than 2 colors in 1 BPP font.\n");

                    destRow <<= 1;
                    destRow |= color;
                }

                dest[tile1Offset + i] = destRow;
            }

            for (int i = 0; i < 8; i++)
            {
                uint8_t destRow = 0;

                for (int j = 0; j < 8; j++)
                {
                    int x = ((glyph % 16) * 8) + j;
                    int y = ((glyph / 16) * 16) + 8 + i;
                    unsigned char color = src[(y * 128) + x];

                    if (color > 1)
                        FATAL_ERROR("More than 2 colors in 1 BPP font.\n");

                    destRow <<= 1;
                    destRow |= color;
                }

                dest[tile2Offset + i] = destRow;
            }
        }
    }
}

void ConvertFromTiles4Bpp(unsigned char *src, unsigned char *dest, int numGlyphs, int layout)
{
    static unsigned char table[16] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1,
    };

    for (int glyph = 0; glyph < numGlyphs; glyph++)
    {
        if (layout == 0)
        {
            int offset = glyph * 32;

            for (int i = 0; i < 8; i++)
            {
                uint32_t srcRow = (src[offset + 3] << 24)
                    | (src[offset + 2] << 16)
                    | (src[offset + 1] << 8)
                    | src[offset];

                for (int j = 0; j < 8; j++)
                {
                    int x = ((glyph % 16) * 8) + j;
                    int y = ((glyph / 16) * 8) + i;
                    dest[(y * 128) + x] = table[srcRow & 0xF];
                    srcRow >>= 4;
                }

                offset += 4;
            }
        }
        else
        {
            int tile1Offset;
            int tile2Offset;

            if (layout == 1)
            {
                tile1Offset = glyph * 64;
                tile2Offset = tile1Offset + 32;
            }
            else
            {
                tile1Offset = ((glyph / 16) * 1024) + ((glyph % 16) * 32);
                tile2Offset = tile1Offset + 512;
            }

            for (int i = 0; i < 8; i++)
            {
                uint32_t srcRow = (src[tile1Offset + 3] << 24)
                    | (src[tile1Offset + 2] << 16)
                    | (src[tile1Offset + 1] << 8)
                    | src[tile1Offset];

                for (int j = 0; j < 8; j++)
                {
                    int x = ((glyph % 16) * 8) + j;
                    int y = ((glyph / 16) * 16) + i;
                    dest[(y * 128) + x] = table[srcRow & 0xF];
                    srcRow >>= 4;
                }

                tile1Offset += 4;
            }

            for (int i = 0; i < 8; i++)
            {
                uint32_t srcRow = (src[tile2Offset + 3] << 24)
                    | (src[tile2Offset + 2] << 16)
                    | (src[tile2Offset + 1] << 8)
                    | src[tile2Offset];

                for (int j = 0; j < 8; j++)
                {
                    int x = ((glyph % 16) * 8) + j;
                    int y = ((glyph / 16) * 16) + 8 + i;
                    dest[(y * 128) + x] = table[srcRow & 0xF];
                    srcRow >>= 4;
                }

                tile2Offset += 4;
            }
        }
    }
}

void ConvertToTiles4Bpp(unsigned char *src, unsigned char *dest, int numGlyphs, int layout)
{
    static unsigned char table[3] =
    {
        0, 15, 14,
    };

    for (int glyph = 0; glyph < numGlyphs; glyph++)
    {
        if (layout == 0)
        {
            int offset = glyph * 32;

            for (int i = 0; i < 8; i++)
            {
                uint32_t destRow = 0;

                for (int j = 0; j < 8; j++)
                {
                    int x = ((glyph % 16) * 8) + j;
                    int y = ((glyph / 16) * 8) + i;
                    unsigned char color = src[(y * 128) + x];

                    if (color > 2)
                        FATAL_ERROR("More than 3 colors in 4 BPP font.\n");

                    destRow >>= 4;
                    destRow |= (table[color] << 28);
                }

                dest[offset] = destRow & 0xFF;
                dest[offset + 1] = (destRow >> 8) & 0xFF;
                dest[offset + 2] = (destRow >> 16) & 0xFF;
                dest[offset + 3] = (destRow >> 24) & 0xFF;

                offset += 4;
            }
        }
        else
        {
            int tile1Offset;
            int tile2Offset;

            if (layout == 1)
            {
                tile1Offset = glyph * 64;
                tile2Offset = tile1Offset + 32;
            }
            else
            {
                tile1Offset = ((glyph / 16) * 1024) + ((glyph % 16) * 32);
                tile2Offset = tile1Offset + 512;
            }

            for (int i = 0; i < 8; i++)
            {
                uint32_t destRow = 0;

                for (int j = 0; j < 8; j++)
                {
                    int x = ((glyph % 16) * 8) + j;
                    int y = ((glyph / 16) * 16) + i;
                    unsigned char color = src[(y * 128) + x];

                    if (color > 2)
                        FATAL_ERROR("More than 3 colors in 4 BPP font.\n");

                    destRow >>= 4;
                    destRow |= (table[color] << 28);
                }

                dest[tile1Offset] = destRow & 0xFF;
                dest[tile1Offset + 1] = (destRow >> 8) & 0xFF;
                dest[tile1Offset + 2] = (destRow >> 16) & 0xFF;
                dest[tile1Offset + 3] = (destRow >> 24) & 0xFF;

                tile1Offset += 4;
            }

            for (int i = 0; i < 8; i++)
            {
                uint32_t destRow = 0;

                for (int j = 0; j < 8; j++)
                {
                    int x = ((glyph % 16) * 8) + j;
                    int y = ((glyph / 16) * 16) + 8 + i;
                    unsigned char color = src[(y * 128) + x];

                    if (color > 2)
                        FATAL_ERROR("More than 3 colors in 4 BPP font.\n");

                    destRow >>= 4;
                    destRow |= (table[color] << 28);
                }

                dest[tile2Offset] = destRow & 0xFF;
                dest[tile2Offset + 1] = (destRow >> 8) & 0xFF;
                dest[tile2Offset + 2] = (destRow >> 16) & 0xFF;
                dest[tile2Offset + 3] = (destRow >> 24) & 0xFF;

                tile2Offset += 4;
            }
        }
    }
}

static void SetFontPalette(struct Image *image)
{
    image->hasPalette = true;

    image->palette.numColors = 3;

    for (int i = 0; i < image->palette.numColors; i++)
    {
        image->palette.colors[i].red = gFontPalette[i][0];
        image->palette.colors[i].green = gFontPalette[i][1];
        image->palette.colors[i].blue = gFontPalette[i][2];
    }

    image->hasTransparency = false;
}

int CalcFileSize(int numGlyphs, int bpp, int layout)
{
    if (layout == 2)
    {
        // assume 4 BPP
        int numFullRows = numGlyphs / 16;
        int remainder = numGlyphs % 16;
        int fullRowsSize = numFullRows * 1024;
        int remainderSize = 0;

        if (remainder != 0)
            remainderSize = 1024 - (16 - remainder) * 32;

        return fullRowsSize + remainderSize;
    }
    else
    {
        int tilesPerGlyph = layout > 0 ? 2 : 1;
        int bytesPerTile = 8 * bpp;
        return numGlyphs * tilesPerGlyph * bytesPerTile;
    }
}

void ReadFont(char *path, struct Image *image, int numGlyphs, int bpp, int layout)
{
    int fileSize;
    unsigned char *buffer = ReadWholeFile(path, &fileSize);

    int expectedFileSize = CalcFileSize(numGlyphs, bpp, layout);

    if (fileSize != expectedFileSize)
        FATAL_ERROR("The file size is %d but should be %d.\n", fileSize, expectedFileSize);

    int numRows = (numGlyphs + 15) / 16;
    int rowHeight = layout > 0 ? 16 : 8;

    image->width = 128;
    image->height = numRows * rowHeight;
    image->bitDepth = 8;
    image->pixels = calloc(image->width * image->height, 1);

    if (image->pixels == NULL)
        FATAL_ERROR("Failed to allocate memory for font.\n");

    if (bpp == 1)
        ConvertFromTiles1Bpp(buffer, image->pixels, numGlyphs, layout);
    else
        ConvertFromTiles4Bpp(buffer, image->pixels, numGlyphs, layout);

    free(buffer);

    SetFontPalette(image);
}

void WriteFont(char *path, struct Image *image, int numGlyphs, int bpp, int layout)
{
    if (image->width != 128)
        FATAL_ERROR("The width of the font image (%d) is not 128.\n", image->width);

    int numRows = (numGlyphs + 15) / 16;
    int rowHeight = layout > 0 ? 16 : 8;
    int expectedHeight = numRows * rowHeight;

    if (image->height < expectedHeight)
        FATAL_ERROR("The height of the font image (%d) is less than %d.\n", image->height, expectedHeight);

    int fileSize = CalcFileSize(numGlyphs, bpp, layout);

    unsigned char *buffer = calloc(fileSize, 1);

    if (buffer == NULL)
        FATAL_ERROR("Failed to allocate memory for font.\n");

    if (bpp == 1)
        ConvertToTiles1Bpp(image->pixels, buffer, numGlyphs, layout);
    else
        ConvertToTiles4Bpp(image->pixels, buffer, numGlyphs, layout);

    WriteWholeFile(path, buffer, fileSize);

    free(buffer);
}
