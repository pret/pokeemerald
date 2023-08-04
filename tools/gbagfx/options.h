// Copyright (c) 2018 huderlem

#ifndef OPTIONS_H
#define OPTIONS_H

#include <stdbool.h>
#include "gfx.h"

struct GbaToPngOptions {
    char *paletteFilePath;
    int bitDepth;
    bool hasTransparency;
    int width;
    int metatileWidth;
    int metatileHeight;
    char *tilemapFilePath;
    bool isAffineMap;
    bool isTiled;
    int dataWidth;
};

struct PngToGbaOptions {
    int numTiles;
    enum NumTilesMode numTilesMode;
    int bitDepth;
    int metatileWidth;
    int metatileHeight;
    char *tilemapFilePath;
    bool isAffineMap;
    bool isTiled;
    int dataWidth;
};

#endif // OPTIONS_H
