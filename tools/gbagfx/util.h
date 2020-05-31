// Copyright (c) 2015 YamaArashi

#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>

bool ParseNumber(char *s, char **end, int radix, int *intValue);
char *GetFileExtension(char *path);
char *GetFileExtensionAfterDot(char *path);
unsigned char *ReadWholeFile(char *path, int *size);
unsigned char *ReadWholeFileZeroPadded(char *path, int *size, int padAmount);
void WriteWholeFile(char *path, void *buffer, int bufferSize);

#endif // UTIL_H
