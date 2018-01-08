// Copyright(c) 2015-2016 YamaArashi
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

unsigned char *ReadWholeFile(char *path, int *size)
{
    FILE *fp = fopen(path, "rb");

    if (fp == NULL)
        FATAL_ERROR("Failed to open \"%s\" for reading.\n", path);

    fseek(fp, 0, SEEK_END);

    *size = ftell(fp);

    unsigned char *buffer = malloc(*size);

    if (buffer == NULL)
        FATAL_ERROR("Failed to allocate memory for reading \"%s\".\n", path);

    rewind(fp);

    if (fread(buffer, *size, 1, fp) != 1)
        FATAL_ERROR("Failed to read \"%s\".\n", path);

    fclose(fp);

    return buffer;
}

int ExtractData(unsigned char *buffer, int offset, int size)
{
    switch (size)
    {
    case 1:
        return buffer[offset];
    case 2:
        return (buffer[offset + 1] << 8)
             | buffer[offset];
    case 4:
        return (buffer[offset + 3] << 24)
             | (buffer[offset + 2] << 16)
             | (buffer[offset + 1] << 8)
             | buffer[offset];
    default:
        FATAL_ERROR("Invalid size passed to ExtractData.\n");
    }
}

int main(int argc, char **argv)
{
    if (argc < 3)
        FATAL_ERROR("Usage: bin2c INPUT_FILE VAR_NAME [OPTIONS...]\n");

    int fileSize;
    unsigned char *buffer = ReadWholeFile(argv[1], &fileSize);
    char *var_name = argv[2];
    int col = 1;
    int pad = 0;
    int size = 1;
    bool isSigned = false;
    bool isStatic = false;
    bool isDecimal = false;

    for (int i = 3; i < argc; i++)
    {
        if (!strcmp(argv[i], "-col"))
        {
            i++;

            if (i >= argc)
                FATAL_ERROR("Missing argument after '-col'.\n");

            col = atoi(argv[i]);
        }
        else if (!strcmp(argv[i], "-pad"))
        {
            i++;

            if (i >= argc)
                FATAL_ERROR("Missing argument after '-pad'.\n");

            pad = atoi(argv[i]);
        }
        else if (!strcmp(argv[i], "-size"))
        {
            i++;

            if (i >= argc)
                FATAL_ERROR("Missing argument after '-size'.\n");

            size = atoi(argv[i]);

            if (size != 1 && size != 2 && size != 4)
                FATAL_ERROR("Size must be 1, 2, or 4.\n");
        }
        else if (!strcmp(argv[i], "-signed"))
        {
            isSigned = true;
            isDecimal = true;
        }
        else if (!strcmp(argv[i], "-static"))
        {
            isStatic = true;
        }
        else if (!strcmp(argv[i], "-decimal"))
        {
            isDecimal = true;
        }
        else
        {
            FATAL_ERROR("Unrecognized option '%s'.\n", argv[i]);
        }
    }

    if ((fileSize & (size - 1)) != 0)
        FATAL_ERROR("Size %d doesn't evenly divide file size %d.\n", size, fileSize);

    printf("// Generated file. Do not edit.\n\n");

    if (isStatic)
        printf("static ");

    printf("const ");

    if (isSigned)
        printf("s%d ", 8 * size);
    else
        printf("u%d ", 8 * size);

    printf("%s[] =\n{", var_name);

    int count = fileSize / size;
    int offset = 0;

    for (int i = 0; i < count; i++)
    {
        if (i % col == 0)
            printf("\n    ");

        int data = ExtractData(buffer, offset, size);
        offset += size;

        if (isDecimal)
        {
            if (isSigned)
                printf("%*d, ", pad, data);
            else
                printf("%*uu, ", pad, data);
        }
        else
        {
            printf("%#*xu, ", pad, data);
        }
    }

    printf("\n};\n");

    return 0;
}
