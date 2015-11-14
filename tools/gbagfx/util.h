// Copyright (c) 2015 YamaArashi

#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>

bool ParseNumber(char *s, char **end, int radix, int *intValue);
char *GetFileExtension(char *path);
void ExpectFileExtension(char *path, char *expectedExtension);
void AddFileExtension(char *path, char *extension);
void RemoveFileExtension(char *path);
void ChangeFileExtension(char *path, char *extension);
unsigned char *ReadWholeFile(char *path, int *size);
void WriteWholeFile(char *path, void *buffer, int bufferSize);

#endif // UTIL_H
