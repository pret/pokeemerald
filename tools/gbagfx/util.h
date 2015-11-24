// Copyright (c) 2015 YamaArashi

#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>

bool ParseNumber(char *s, char **end, int radix, int *intValue);
char *GetFileExtension(char *path);
unsigned char *ReadWholeFile(char *path, int *size);
void WriteWholeFile(char *path, void *buffer, int bufferSize);

#endif // UTIL_H
