// Copyright (c) 2015 YamaArashi

#ifndef FONT_H
#define FONT_H

#include <stdbool.h>
#include "gfx.h"

void ReadLatinFont(char *path, struct Image *image);
void WriteLatinFont(char *path, struct Image *image);
void ReadHalfwidthJapaneseFont(char *path, struct Image *image);
void WriteHalfwidthJapaneseFont(char *path, struct Image *image);
void ReadFullwidthJapaneseFont(char *path, struct Image *image);
void WriteFullwidthJapaneseFont(char *path, struct Image *image);

#endif // FONT_H
