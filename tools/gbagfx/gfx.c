// Copyright (c) 2015 YamaArashi

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "global.h"
#include "gfx.h"
#include "util.h"

#define GET_GBA_PAL_RED(x)   (((x) >>  0) & 0x1F)
#define GET_GBA_PAL_GREEN(x) (((x) >>  5) & 0x1F)
#define GET_GBA_PAL_BLUE(x)  (((x) >> 10) & 0x1F)

#define SET_GBA_PAL(r, g, b) (((b) << 10) | ((g) << 5) | (r))

#define UPCONVERT_BIT_DEPTH(x) (((x) * 255) / 31)

#define DOWNCONVERT_BIT_DEPTH(x) ((x) / 8)

static inline void swap_bytes(unsigned char * orig, unsigned char * dest) {
	unsigned char tmp = *orig;
	*orig = *dest;
	*dest = tmp;
}

static inline unsigned char swap_nybbles(unsigned char orig)
{
	return (orig >> 4) | (orig << 4);
}

static inline void swap_bytes_nybswap(unsigned char * orig, unsigned char * dest) {
	unsigned char tmp = swap_nybbles(*orig);
	*orig = swap_nybbles(*dest);
	*dest = tmp;
}

static inline unsigned char reverse_bits(unsigned char orig) {
	unsigned char dest = 0;
	for (int i = 0; i < 8; i++)
	{
		dest <<= 1;
		dest |= orig & 1;
		orig >>= 1;
	}
	return dest;
}

static void vflip(unsigned char * tile, int bitDepth) {
	for (int x = 0; x < bitDepth; x++)
	{
		unsigned char * col = tile + x;
		swap_bytes(col + 0 * bitDepth, col + 7 * bitDepth);
		swap_bytes(col + 1 * bitDepth, col + 6 * bitDepth);
		swap_bytes(col + 2 * bitDepth, col + 5 * bitDepth);
		swap_bytes(col + 3 * bitDepth, col + 4 * bitDepth);
	}
}

static void hflip(unsigned char * tile, int bitDepth) {
	for (int y = 0; y < 8; y++)
	{
		unsigned char * row = tile + y * bitDepth;
		switch (bitDepth)
		{
			case 1:
				*row = reverse_bits(*row);
				break;
			case 4:
				swap_bytes_nybswap(row + 0, row + 3);
				swap_bytes_nybswap(row + 1, row + 2);
				break;
			case 8:
				swap_bytes(row +  0, row + 56);
				swap_bytes(row +  8, row + 48);
				swap_bytes(row + 16, row + 40);
				swap_bytes(row + 24, row + 32);
				break;
		}
	}
}

static unsigned char * ApplyTilemap(struct Image *image, unsigned char * buffer, int bitDepth)
{
	int tileSize = bitDepth * 8;
	unsigned char * tiles = calloc(image->tileMap.numTiles, tileSize);
	int i;
	struct Tile tileInfo;

	for (i = 0; i < image->tileMap.numTiles; i++) {
		tileInfo = image->tileMap.data[i];
		unsigned char * tile = tiles + i * tileSize;
		memcpy(tile, buffer + tileInfo.index * tileSize, tileSize);
		if (tileInfo.xflip)
			hflip(tile, bitDepth);
		if (tileInfo.yflip)
			vflip(tile, bitDepth);
	}
	free(buffer);
	return tiles;
}

static unsigned char * BuildTilemap(struct Image *image, unsigned char * buffer, int * bufferSize)
{
	int tileSize = image->bitDepth * 8;
	unsigned char * outputPixels = calloc(1024, tileSize);
	int nTilesIn = image->height * image->width / 64;
	image->tileMap.data = calloc(nTilesIn, sizeof(struct Tilemap));
	image->tileMap.numTiles = nTilesIn;
	int nTilesOut = 0;
	unsigned char curTile1[tileSize];
	unsigned char curTile2[tileSize];

	for (int i = 0; i < nTilesIn; i++) {
		bool xflip = false;
		bool yflip = false;
		int j;
		memcpy(curTile1, buffer + i * tileSize, tileSize);

		for (j = 0; j < nTilesOut; j++) {
			memcpy(curTile2, outputPixels + j * tileSize, tileSize);
			if (memcmp(curTile1, curTile2, tileSize) == 0)
				break;
			xflip = true;
			hflip(curTile2, image->bitDepth);
			if (memcmp(curTile1, curTile2, tileSize) == 0)
				break;
			yflip = true;
			vflip(curTile2, image->bitDepth);
			if (memcmp(curTile1, curTile2, tileSize) == 0)
				break;
			xflip = false;
			hflip(curTile2, image->bitDepth);
			if (memcmp(curTile1, curTile2, tileSize) == 0)
				break;
			yflip = false;
		}
		image->tileMap.data[i].index = j;
		image->tileMap.data[i].xflip = xflip;
		image->tileMap.data[i].yflip = yflip;
		image->tileMap.data[i].palno = 0;
		if (j >= nTilesOut) {
			if (nTilesOut >= 1024)
				FATAL_ERROR("Cannot reduce image to 1024 or fewer tiles.\n");
			memcpy(outputPixels + nTilesOut * tileSize, curTile1, tileSize);
			nTilesOut++;
		}
	}

	free(buffer);
	*bufferSize = nTilesOut * tileSize;
	return outputPixels;
}

static void AdvanceMetatilePosition(int *subTileX, int *subTileY, int *metatileX, int *metatileY, int metatilesWide, int metatileWidth, int metatileHeight)
{
	(*subTileX)++;
	if (*subTileX == metatileWidth) {
		*subTileX = 0;
		(*subTileY)++;
		if (*subTileY == metatileHeight) {
			*subTileY = 0;
			(*metatileX)++;
			if (*metatileX == metatilesWide) {
				*metatileX = 0;
				(*metatileY)++;
			}
		}
	}
}

static void ConvertFromTiles1Bpp(unsigned char *src, unsigned char *dest, int numTiles, int metatilesWide, int metatileWidth, int metatileHeight, bool invertColors)
{
	int subTileX = 0;
	int subTileY = 0;
	int metatileX = 0;
	int metatileY = 0;
	int pitch = metatilesWide * metatileWidth;

	for (int i = 0; i < numTiles; i++) {
		for (int j = 0; j < 8; j++) {
			int destY = (metatileY * metatileHeight + subTileY) * 8 + j;
			int destX = metatileX * metatileWidth + subTileX;
			unsigned char srcPixelOctet = *src++;
			unsigned char *destPixelOctet = &dest[destY * pitch + destX];

			for (int k = 0; k < 8; k++) {
				*destPixelOctet <<= 1;
				*destPixelOctet |= (srcPixelOctet & 1) ^ invertColors;
				srcPixelOctet >>= 1;
			}
		}

		AdvanceMetatilePosition(&subTileX, &subTileY, &metatileX, &metatileY, metatilesWide, metatileWidth, metatileHeight);
	}
}

static void ConvertFromTiles4Bpp(unsigned char *src, unsigned char *dest, int numTiles, int metatilesWide, int metatileWidth, int metatileHeight, bool invertColors)
{
	int subTileX = 0;
	int subTileY = 0;
	int metatileX = 0;
	int metatileY = 0;
	int pitch = (metatilesWide * metatileWidth) * 4;

	for (int i = 0; i < numTiles; i++) {
		for (int j = 0; j < 8; j++) {
			int destY = (metatileY * metatileHeight + subTileY) * 8 + j;

			for (int k = 0; k < 4; k++) {
				int destX = (metatileX * metatileWidth + subTileX) * 4 + k;
				unsigned char srcPixelPair = *src++;
				unsigned char leftPixel = srcPixelPair & 0xF;
				unsigned char rightPixel = srcPixelPair >> 4;

				if (invertColors) {
					leftPixel = 15 - leftPixel;
					rightPixel = 15 - rightPixel;
				}

				dest[destY * pitch + destX] = (leftPixel << 4) | rightPixel;
			}
		}

		AdvanceMetatilePosition(&subTileX, &subTileY, &metatileX, &metatileY, metatilesWide, metatileWidth, metatileHeight);
	}
}

static void ConvertFromTiles8Bpp(unsigned char *src, unsigned char *dest, int numTiles, int metatilesWide, int metatileWidth, int metatileHeight, bool invertColors)
{
	int subTileX = 0;
	int subTileY = 0;
	int metatileX = 0;
	int metatileY = 0;
	int pitch = (metatilesWide * metatileWidth) * 8;

	for (int i = 0; i < numTiles; i++) {
		for (int j = 0; j < 8; j++) {
			int destY = (metatileY * metatileHeight + subTileY) * 8 + j;

			for (int k = 0; k < 8; k++) {
				int destX = (metatileX * metatileWidth + subTileX) * 8 + k;
				unsigned char srcPixel = *src++;

				if (invertColors)
					srcPixel = 255 - srcPixel;

				dest[destY * pitch + destX] = srcPixel;
			}
		}

		AdvanceMetatilePosition(&subTileX, &subTileY, &metatileX, &metatileY, metatilesWide, metatileWidth, metatileHeight);
	}
}

static void ConvertToTiles1Bpp(unsigned char *src, unsigned char *dest, int numTiles, int metatilesWide, int metatileWidth, int metatileHeight, bool invertColors)
{
	int subTileX = 0;
	int subTileY = 0;
	int metatileX = 0;
	int metatileY = 0;
	int pitch = metatilesWide * metatileWidth;

	for (int i = 0; i < numTiles; i++) {
		for (int j = 0; j < 8; j++) {
			int srcY = (metatileY * metatileHeight + subTileY) * 8 + j;
			int srcX = metatileX * metatileWidth + subTileX;
			unsigned char srcPixelOctet = src[srcY * pitch + srcX];
			unsigned char *destPixelOctet = dest++;

			for (int k = 0; k < 8; k++) {
				*destPixelOctet <<= 1;
				*destPixelOctet |= (srcPixelOctet & 1) ^ invertColors;
				srcPixelOctet >>= 1;
			}
		}

		AdvanceMetatilePosition(&subTileX, &subTileY, &metatileX, &metatileY, metatilesWide, metatileWidth, metatileHeight);
	}
}

static void ConvertToTiles4Bpp(unsigned char *src, unsigned char *dest, int numTiles, int metatilesWide, int metatileWidth, int metatileHeight, bool invertColors)
{
	int subTileX = 0;
	int subTileY = 0;
	int metatileX = 0;
	int metatileY = 0;
	int pitch = (metatilesWide * metatileWidth) * 4;

	for (int i = 0; i < numTiles; i++) {
		for (int j = 0; j < 8; j++) {
			int srcY = (metatileY * metatileHeight + subTileY) * 8 + j;

			for (int k = 0; k < 4; k++) {
				int srcX = (metatileX * metatileWidth + subTileX) * 4 + k;
				unsigned char srcPixelPair = src[srcY * pitch + srcX];
				unsigned char leftPixel = srcPixelPair >> 4;
				unsigned char rightPixel = srcPixelPair & 0xF;

				if (invertColors) {
					leftPixel = 15 - leftPixel;
					rightPixel = 15 - rightPixel;
				}

				*dest++ = (rightPixel << 4) | leftPixel;
			}
		}

		AdvanceMetatilePosition(&subTileX, &subTileY, &metatileX, &metatileY, metatilesWide, metatileWidth, metatileHeight);
	}
}

static void ConvertToTiles8Bpp(unsigned char *src, unsigned char *dest, int numTiles, int metatilesWide, int metatileWidth, int metatileHeight, bool invertColors)
{
	int subTileX = 0;
	int subTileY = 0;
	int metatileX = 0;
	int metatileY = 0;
	int pitch = (metatilesWide * metatileWidth) * 8;

	for (int i = 0; i < numTiles; i++) {
		for (int j = 0; j < 8; j++) {
			int srcY = (metatileY * metatileHeight + subTileY) * 8 + j;

			for (int k = 0; k < 8; k++) {
				int srcX = (metatileX * metatileWidth + subTileX) * 8 + k;
				unsigned char srcPixel = src[srcY * pitch + srcX];

				if (invertColors)
					srcPixel = 255 - srcPixel;

				*dest++ = srcPixel;
			}
		}

		AdvanceMetatilePosition(&subTileX, &subTileY, &metatileX, &metatileY, metatilesWide, metatileWidth, metatileHeight);
	}
}

void ReadImage(char *path, int tilesWidth, int bitDepth, int metatileWidth, int metatileHeight, struct Image *image, bool invertColors)
{
	int tileSize = bitDepth * 8;

	int fileSize;
	unsigned char *buffer = ReadWholeFile(path, &fileSize);

	int numTiles;
	if (image->hasTilemap) {
		buffer = ApplyTilemap(image, buffer, bitDepth);
		numTiles = image->tileMap.numTiles;
	}
	else
		numTiles = fileSize / tileSize;

	int tilesHeight = (numTiles + tilesWidth - 1) / tilesWidth;

	if (tilesWidth % metatileWidth != 0)
		FATAL_ERROR("The width in tiles (%d) isn't a multiple of the specified metatile width (%d)\n", tilesWidth, metatileWidth);

	if (tilesHeight % metatileHeight != 0)
		FATAL_ERROR("The height in tiles (%d) isn't a multiple of the specified metatile height (%d)\n", tilesHeight, metatileHeight);

	image->width = tilesWidth * 8;
	image->height = tilesHeight * 8;
	image->bitDepth = bitDepth;
	image->pixels = calloc(tilesWidth * tilesHeight, tileSize);

	if (image->pixels == NULL)
		FATAL_ERROR("Failed to allocate memory for pixels.\n");

	int metatilesWide = tilesWidth / metatileWidth;

	switch (bitDepth) {
	case 1:
		ConvertFromTiles1Bpp(buffer, image->pixels, numTiles, metatilesWide, metatileWidth, metatileHeight, invertColors);
		break;
	case 4:
		ConvertFromTiles4Bpp(buffer, image->pixels, numTiles, metatilesWide, metatileWidth, metatileHeight, invertColors);
		break;
	case 8:
		ConvertFromTiles8Bpp(buffer, image->pixels, numTiles, metatilesWide, metatileWidth, metatileHeight, invertColors);
		break;
	}

	free(buffer);
}

void WriteImage(char *path, int numTiles, int bitDepth, int metatileWidth, int metatileHeight, struct Image *image, bool invertColors)
{
	int tileSize = bitDepth * 8;

	if (image->width % 8 != 0)
		FATAL_ERROR("The width in pixels (%d) isn't a multiple of 8.\n", image->width);

	if (image->height % 8 != 0)
		FATAL_ERROR("The height in pixels (%d) isn't a multiple of 8.\n", image->height);

	int tilesWidth = image->width / 8;
	int tilesHeight = image->height / 8;

	if (tilesWidth % metatileWidth != 0)
		FATAL_ERROR("The width in tiles (%d) isn't a multiple of the specified metatile width (%d)", tilesWidth, metatileWidth);

	if (tilesHeight % metatileHeight != 0)
		FATAL_ERROR("The height in tiles (%d) isn't a multiple of the specified metatile height (%d)", tilesHeight, metatileHeight);

	int maxNumTiles = tilesWidth * tilesHeight;

	if (numTiles == 0)
		numTiles = maxNumTiles;
	else if (numTiles > maxNumTiles)
		FATAL_ERROR("The specified number of tiles (%d) is greater than the maximum possible value (%d).\n", numTiles, maxNumTiles);

	int bufferSize = numTiles * tileSize;
	unsigned char *buffer = malloc(bufferSize);

	if (buffer == NULL)
		FATAL_ERROR("Failed to allocate memory for pixels.\n");

	int metatilesWide = tilesWidth / metatileWidth;

	switch (bitDepth) {
	case 1:
		ConvertToTiles1Bpp(image->pixels, buffer, numTiles, metatilesWide, metatileWidth, metatileHeight, invertColors);
		break;
	case 4:
		ConvertToTiles4Bpp(image->pixels, buffer, numTiles, metatilesWide, metatileWidth, metatileHeight, invertColors);
		break;
	case 8:
		ConvertToTiles8Bpp(image->pixels, buffer, numTiles, metatilesWide, metatileWidth, metatileHeight, invertColors);
		break;
	}

	if (image->hasTilemap)
		buffer = BuildTilemap(image, buffer, &bufferSize);

	WriteWholeFile(path, buffer, bufferSize);

	free(buffer);
}

void FreeImage(struct Image *image)
{
	free(image->pixels);
	image->pixels = NULL;
	if (image->hasTilemap && image->tileMap.data != NULL) {
		free(image->tileMap.data);
		image->tileMap.data = NULL;
		image->tileMap.numTiles = 0;
	}
}

void ReadGbaPalette(char *path, struct Palette *palette)
{
	int fileSize;
	unsigned char *data = ReadWholeFile(path, &fileSize);

	if (fileSize % 2 != 0)
		FATAL_ERROR("The file size (%d) is not a multiple of 2.\n", fileSize);

	palette->numColors = fileSize / 2;

	for (int i = 0; i < palette->numColors; i++) {
		uint16_t paletteEntry = (data[i * 2 + 1] << 8) | data[i * 2];
		palette->colors[i].red = UPCONVERT_BIT_DEPTH(GET_GBA_PAL_RED(paletteEntry));
		palette->colors[i].green = UPCONVERT_BIT_DEPTH(GET_GBA_PAL_GREEN(paletteEntry));
		palette->colors[i].blue = UPCONVERT_BIT_DEPTH(GET_GBA_PAL_BLUE(paletteEntry));
	}

	free(data);
}

void WriteGbaPalette(char *path, struct Palette *palette)
{
	FILE *fp = fopen(path, "wb");

	if (fp == NULL)
		FATAL_ERROR("Failed to open \"%s\" for writing.\n", path);

	for (int i = 0; i < palette->numColors; i++) {
		unsigned char red = DOWNCONVERT_BIT_DEPTH(palette->colors[i].red);
		unsigned char green = DOWNCONVERT_BIT_DEPTH(palette->colors[i].green);
		unsigned char blue = DOWNCONVERT_BIT_DEPTH(palette->colors[i].blue);

		uint16_t paletteEntry = SET_GBA_PAL(red, green, blue);

		fputc(paletteEntry & 0xFF, fp);
		fputc(paletteEntry >> 8, fp);
	}

	fclose(fp);
}

void ReadGbaTilemap(char *path, struct Tilemap *tileMap)
{
	int fileSize;
	unsigned char *data = ReadWholeFile(path, &fileSize);

	if (fileSize % 2 != 0)
		FATAL_ERROR("The file size (%d) is not a multiple of 2.\n", fileSize);

	tileMap->numTiles = fileSize / 2;
	tileMap->data = malloc(tileMap->numTiles * sizeof(struct Tile));

	for (int i = 0; i < tileMap->numTiles; i++)
	{
		uint16_t raw = data[2 * i + 0] | (data[2 * i + 1] << 8);
		tileMap->data[i].index = raw & 0x3FF;
		tileMap->data[i].xflip = raw & 0x400 ? 1 : 0;
		tileMap->data[i].yflip = raw & 0x800 ? 1 : 0;
		tileMap->data[i].palno = raw >> 12;
	}

	free(data);
}

void WriteGbaTilemap(char *path, struct Tilemap *tileMap)
{
	FILE *fp = fopen(path, "wb");

	if (fp == NULL)
		FATAL_ERROR("Failed to open \"%s\" for writing.\n", path);

	for (int i = 0; i < tileMap->numTiles; i++) {
		uint16_t raw =    tileMap->data[i].index
			           | (tileMap->data[i].xflip << 10)
			           | (tileMap->data[i].yflip << 11)
			           | (tileMap->data[i].palno << 12);
		fputc(raw & 0xFF, fp);
		fputc(raw >> 8, fp);
	}

	fclose(fp);
}
