// Copyright (c) 2015 YamaArashi

#include <stdio.h>
#include <setjmp.h>
#include <png.h>
#include "global.h"
#include "convert_png.h"
#include "gfx.h"

static FILE *PngReadOpen(char *path, png_structp *pngStruct, png_infop *pngInfo)
{
    FILE *fp = fopen(path, "rb");

    if (fp == NULL)
        FATAL_ERROR("Failed to open \"%s\" for reading.\n", path);

    unsigned char sig[8];

    if (fread(sig, 8, 1, fp) != 1)
        FATAL_ERROR("Failed to read PNG signature from \"%s\".\n", path);

    if (png_sig_cmp(sig, 0, 8))
        FATAL_ERROR("\"%s\" does not have a valid PNG signature.\n", path);

    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    if (!png_ptr)
        FATAL_ERROR("Failed to create PNG read struct.\n");

    png_infop info_ptr = png_create_info_struct(png_ptr);

    if (!info_ptr)
        FATAL_ERROR("Failed to create PNG info struct.\n");

    if (setjmp(png_jmpbuf(png_ptr)))
        FATAL_ERROR("Failed to init I/O for reading \"%s\".\n", path);

    png_init_io(png_ptr, fp);
    png_set_sig_bytes(png_ptr, 8);
    png_read_info(png_ptr, info_ptr);

    *pngStruct = png_ptr;
    *pngInfo = info_ptr;

    return fp;
}

static unsigned char *ConvertBitDepth(unsigned char *src, int srcBitDepth, int destBitDepth, int numPixels)
{
    // Round the number of bits up to the next 8 and divide by 8 to get the number of bytes.
    int srcSize = ((numPixels * srcBitDepth + 7) & ~7) / 8;
    int destSize = ((numPixels * destBitDepth + 7) & ~7) / 8;
    unsigned char *output = calloc(destSize, 1);
    unsigned char *dest = output;
    int i;
    int j;
    int destBit = 8 - destBitDepth;

    for (i = 0; i < srcSize; i++)
    {
        unsigned char srcByte = src[i];

        for (j = 8 - srcBitDepth; j >= 0; j -= srcBitDepth)
        {
            unsigned char pixel = (srcByte >> j) % (1 << destBitDepth);
            *dest |= pixel << destBit;
            destBit -= destBitDepth;
            if (destBit < 0)
            {
                dest++;
                destBit = 8 - destBitDepth;
            }
        }
    }

    return output;
}

void ReadPng(char *path, struct Image *image)
{
    png_structp png_ptr;
    png_infop info_ptr;

    FILE *fp = PngReadOpen(path, &png_ptr, &info_ptr);

    int bit_depth = png_get_bit_depth(png_ptr, info_ptr);

    int color_type = png_get_color_type(png_ptr, info_ptr);

    if (color_type != PNG_COLOR_TYPE_GRAY && color_type != PNG_COLOR_TYPE_PALETTE)
        FATAL_ERROR("\"%s\" has an unsupported color type.\n", path);

    // Check if the image has a palette so that we can tell if the colors need to be inverted later.
    // Don't read the palette because it's not needed for now.
    image->hasPalette = (color_type == PNG_COLOR_TYPE_PALETTE);

    image->width = png_get_image_width(png_ptr, info_ptr);
    image->height = png_get_image_height(png_ptr, info_ptr);

    int rowbytes = png_get_rowbytes(png_ptr, info_ptr);

    image->pixels = malloc(image->height * rowbytes);

    if (image->pixels == NULL)
        FATAL_ERROR("Failed to allocate pixel buffer.\n");

    png_bytepp row_pointers = malloc(image->height * sizeof(png_bytep));

    if (row_pointers == NULL)
        FATAL_ERROR("Failed to allocate row pointers.\n");

    for (int i = 0; i < image->height; i++)
        row_pointers[i] = (png_bytep)(image->pixels + (i * rowbytes));

    if (setjmp(png_jmpbuf(png_ptr)))
        FATAL_ERROR("Error reading from \"%s\".\n", path);

    png_read_image(png_ptr, row_pointers);

    png_destroy_read_struct(&png_ptr, &info_ptr, NULL);

    free(row_pointers);
    fclose(fp);

    if (bit_depth != image->bitDepth && image->tilemap.data.affine == NULL)
    {
        unsigned char *src = image->pixels;

        if (bit_depth != 1 && bit_depth != 2 && bit_depth != 4 && bit_depth != 8)
            FATAL_ERROR("Bit depth of image must be 1, 2, 4, or 8.\n");
        image->pixels = ConvertBitDepth(image->pixels, bit_depth, image->bitDepth, image->width * image->height);
        free(src);
        image->bitDepth = bit_depth;
    }
}

void ReadPngPalette(char *path, struct Palette *palette)
{
    png_structp png_ptr;
    png_infop info_ptr;
    png_colorp colors;
    int numColors;

    FILE *fp = PngReadOpen(path, &png_ptr, &info_ptr);

    if (png_get_color_type(png_ptr, info_ptr) != PNG_COLOR_TYPE_PALETTE)
        FATAL_ERROR("The image \"%s\" does not contain a palette.\n", path);

    if (png_get_PLTE(png_ptr, info_ptr, &colors, &numColors) != PNG_INFO_PLTE)
        FATAL_ERROR("Failed to retrieve palette from \"%s\".\n", path);

    if (numColors > 256)
        FATAL_ERROR("Images with more than 256 colors are not supported.\n");

    palette->numColors = numColors;
    for (int i = 0; i < numColors; i++) {
        palette->colors[i].red = colors[i].red;
        palette->colors[i].green = colors[i].green;
        palette->colors[i].blue = colors[i].blue;
    }

    png_destroy_read_struct(&png_ptr, &info_ptr, NULL);

    fclose(fp);
}

void SetPngPalette(png_structp png_ptr, png_infop info_ptr, struct Palette *palette)
{
    png_colorp colors = malloc(palette->numColors * sizeof(png_color));

    if (colors == NULL)
        FATAL_ERROR("Failed to allocate PNG palette.\n");

    for (int i = 0; i < palette->numColors; i++) {
        colors[i].red = palette->colors[i].red;
        colors[i].green = palette->colors[i].green;
        colors[i].blue = palette->colors[i].blue;
    }

    png_set_PLTE(png_ptr, info_ptr, colors, palette->numColors);

    free(colors);
}

void WritePng(char *path, struct Image *image)
{
    FILE *fp = fopen(path, "wb");

    if (fp == NULL)
        FATAL_ERROR("Failed to open \"%s\" for writing.\n", path);

    png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    if (!png_ptr)
        FATAL_ERROR("Failed to create PNG write struct.\n");

    png_infop info_ptr = png_create_info_struct(png_ptr);

    if (!info_ptr)
        FATAL_ERROR("Failed to create PNG info struct.\n");

    if (setjmp(png_jmpbuf(png_ptr)))
        FATAL_ERROR("Failed to init I/O for writing \"%s\".\n", path);

    png_init_io(png_ptr, fp);

    if (setjmp(png_jmpbuf(png_ptr)))
        FATAL_ERROR("Error writing header for \"%s\".\n", path);

    int color_type = image->hasPalette ? PNG_COLOR_TYPE_PALETTE : PNG_COLOR_TYPE_GRAY;

    png_set_IHDR(png_ptr, info_ptr, image->width, image->height,
        image->bitDepth, color_type, PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

    if (image->hasPalette) {
        SetPngPalette(png_ptr, info_ptr, &image->palette);

        if (image->hasTransparency) {
            png_byte trans = 0;
            png_set_tRNS(png_ptr, info_ptr, &trans, 1, 0);
        }
    }

    png_write_info(png_ptr, info_ptr);

    png_bytepp row_pointers = malloc(image->height * sizeof(png_bytep));

    if (row_pointers == NULL)
        FATAL_ERROR("Failed to allocate row pointers.\n");

    int rowbytes = png_get_rowbytes(png_ptr, info_ptr);

    for (int i = 0; i < image->height; i++)
        row_pointers[i] = (png_bytep)(image->pixels + (i * rowbytes));

    if (setjmp(png_jmpbuf(png_ptr)))
        FATAL_ERROR("Error writing \"%s\".\n", path);

    png_write_image(png_ptr, row_pointers);

    if (setjmp(png_jmpbuf(png_ptr)))
        FATAL_ERROR("Error ending write of \"%s\".\n", path);

    png_write_end(png_ptr, NULL);

    fclose(fp);

    png_destroy_write_struct(&png_ptr, &info_ptr);
    free(row_pointers);
}
