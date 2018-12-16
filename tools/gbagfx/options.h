// Copyright (c) 2018 huderlem

#ifndef OPTIONS_H
#define OPTIONS_H

#include <stdbool.h>

struct GbaToPngOptions {
    char *paletteFilePath;
    char *tilemapFilePath;
    int bitDepth;
    bool hasTransparency;
    int width;
    int metatileWidth;
    int metatileHeight;
};

struct PngToGbaOptions {
    char *tilemapFilePath;
    int numTiles;
    int bitDepth;
    int metatileWidth;
    int metatileHeight;
};

#endif // OPTIONS_H
