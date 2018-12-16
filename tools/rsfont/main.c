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
#include <string.h>
#include <stdbool.h>
#include "global.h"
#include "util.h"
#include "gfx.h"
#include "convert_png.h"
#include "font.h"

int ExtensionToBpp(const char *extension)
{
    if (!strcmp(extension, "1bpp"))
        return 1;
    else if (!strcmp(extension, "4bpp"))
        return 4;
    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 5)
        FATAL_ERROR("Usage: rsfont INPUT_FILE OUTPUT_FILE NUM_GLYPHS LAYOUT_TYPE\n");

    char *inputPath = argv[1];
    char *outputPath = argv[2];
    char *inputFileExtension = GetFileExtension(inputPath);
    char *outputFileExtension = GetFileExtension(outputPath);

    if (inputFileExtension == NULL)
        FATAL_ERROR("Input file \"%s\" has no extension.\n", inputPath);

    if (outputFileExtension == NULL)
        FATAL_ERROR("Output file \"%s\" has no extension.\n", outputPath);

    int numGlyphs;
    int bpp;
    int layout;

    if (!ParseNumber(argv[3], NULL, 10, &numGlyphs))
        FATAL_ERROR("Failed to parse number of glyphs.\n");

    if (!ParseNumber(argv[4], NULL, 10, &layout))
        FATAL_ERROR("Failed to parse layout type.\n");

    if (layout < 0 || layout > 2)
        FATAL_ERROR("Layout type %d is invalid. Layout type must be 0, 1, or 2.\n", layout);

    bool toPng;

    if (!strcmp(inputFileExtension, "png") && (bpp = ExtensionToBpp(outputFileExtension)) != 0)
        toPng = false;
    else if ((bpp = ExtensionToBpp(inputFileExtension)) != 0 && !strcmp(outputFileExtension, "png"))
        toPng = true;
    else
        FATAL_ERROR("Don't know how to convert \"%s\" to \"%s\".\n", inputPath, outputPath);

    if (bpp == 1 && layout == 2)
        FATAL_ERROR("Layout type 2 is not supported with 1 BPP fonts.\n");

    struct Image image;

    if (toPng)
    {
        ReadFont(inputPath, &image, numGlyphs, bpp, layout);
        WritePng(outputPath, &image);
    }
    else
    {
        image.bitDepth = 8;
        ReadPng(inputPath, &image);
        WriteFont(outputPath, &image, numGlyphs, bpp, layout);
    }
}
