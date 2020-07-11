// Copyright (c) 2018 huderlem

#ifndef OPTIONS_H
#define OPTIONS_H

#include <stdbool.h>

struct GbaToPngOptions {
    char *paletteFilePath;
    int bitDepth;
    bool hasTransparency;
    int width;
    int metatileWidth;
    int metatileHeight;
    char *tilemapFilePath;
    bool isAffineMap;
};

struct PngToGbaOptions {
    int numTiles;
    int bitDepth;
    int metatileWidth;
    int metatileHeight;
    char *tilemapFilePath;
    bool isAffineMap;
};

#endif // OPTIONS_H
