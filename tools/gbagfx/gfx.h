// Copyright (c) 2015 YamaArashi

#ifndef GFX_H
#define GFX_H

#include <stdint.h>
#include <stdbool.h>

struct Color {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
};

struct Palette {
	struct Color colors[256];
	int numColors;
};

struct NonAffineTile {
    unsigned short index:10;
    unsigned short hflip:1;
    unsigned short vflip:1;
    unsigned short palno:4;
} __attribute__((packed));

struct Tilemap {
    union {
        struct NonAffineTile *non_affine;
        unsigned char *affine;
    } data;
    int size;
};

struct Image {
	int width;
	int height;
	int bitDepth;
	unsigned char *pixels;
	bool hasPalette;
	struct Palette palette;
	bool hasTransparency;
	struct Tilemap tilemap;
	bool isAffine;
};

enum NumTilesMode {
    NUM_TILES_IGNORE,
    NUM_TILES_WARN,
    NUM_TILES_ERROR,
};

void ReadImage(char *path, int tilesWidth, int bitDepth, int metatileWidth, int metatileHeight, struct Image *image, bool invertColors);
void WriteImage(char *path, enum NumTilesMode numTilesMode, int numTiles, int bitDepth, int metatileWidth, int metatileHeight, struct Image *image, bool invertColors);
void FreeImage(struct Image *image);
void ReadGbaPalette(char *path, struct Palette *palette);
void WriteGbaPalette(char *path, struct Palette *palette);

#endif // GFX_H
