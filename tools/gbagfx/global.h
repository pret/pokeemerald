// Copyright (c) 2015 YamaArashi

#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <stdlib.h>

#ifdef _MSC_VER

#define FATAL_ERROR(format, ...)          \
do {                                      \
	fprintf(stderr, format, __VA_ARGS__); \
	exit(1);                              \
} while (0)

#else

#define FATAL_ERROR(format, ...)            \
do {                                        \
	fprintf(stderr, format, ##__VA_ARGS__); \
	exit(1);                                \
} while (0)

#endif // _MSC_VER

#define GBAGFX_MAX_PATH 255

#define CHECK_PATH_LENGTH(path)                            \
do {                                                       \
	if (strlen(path) > GBAGFX_MAX_PATH)                    \
		FATAL_ERROR("\"%s\" is too long a path.\n", path); \
} while (0)

#endif // GLOBAL_H
