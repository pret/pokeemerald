// mapjson.h

#ifndef MAPJSON_H
#define MAPJSON_H

#include <cstdio>
using std::fprintf; using std::exit;

#include <cstdlib>

#ifdef _MSC_VER

#define FATAL_ERROR(format, ...)          \
do                                        \
{                                         \
    fprintf(stderr, format, __VA_ARGS__); \
    exit(1);                              \
} while (FALSE)

#else

#define FATAL_ERROR(format, ...)            \
do                                          \
{                                           \
    fprintf(stderr, format, ##__VA_ARGS__); \
    exit(1);                                \
} while (FALSE)

#endif // _MSC_VER

#endif // MAPJSON_H
