// jsonproc.h

#ifndef JSONPROC_H
#define JSONPROC_H

#include <cstdlib>
#include <cstdio>
using std::fprintf; using std::exit;

#include <cstdlib>

#ifdef _MSC_VER

#define FATAL_ERROR(format, ...)          \
do                                        \
{                                         \
    fprintf(stderr, format, __VA_ARGS__); \
    exit(1);                              \
} while (0)

#else

#define FATAL_ERROR(format, ...)            \
do                                          \
{                                           \
    fprintf(stderr, format, ##__VA_ARGS__); \
    exit(1);                                \
} while (0)

#endif // _MSC_VER

#endif // JSONPROC_H
