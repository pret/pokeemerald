#include "preproc.h"
#include "io.h"
#include <string>
#include <cerrno>
#include <cstring>

char *ReadFileToBuffer(const char *filename, bool isStdin, long *size)
{
    FILE *fp;
    if (isStdin)
        fp = stdin;
    else
        fp = std::fopen(filename, "rb");

    if (fp == NULL)
        FATAL_ERROR("Failed to open \"%s\" for reading.\n", filename);

    *size = 0;
    char *buffer = (char *)malloc(CHUNK_SIZE + 1);
    if (buffer == NULL) {
        FATAL_ERROR("Failed to allocate memory to process file \"%s\"!", filename);
    }

    std::size_t numAllocatedBytes = CHUNK_SIZE + 1;
    std::size_t bufferOffset = 0;
    std::size_t count;

    while ((count = std::fread(buffer + bufferOffset, 1, CHUNK_SIZE, fp)) != 0) {
        if (!std::ferror(fp)) {
            *size += count;

            if (std::feof(fp)) {
                break;
            }

            numAllocatedBytes += CHUNK_SIZE;
            bufferOffset += CHUNK_SIZE;
            buffer = (char *)realloc(buffer, numAllocatedBytes);
            if (buffer == NULL) {
                FATAL_ERROR("Failed to allocate memory to process file \"%s\"!", filename);
            }
        } else {
            FATAL_ERROR("Failed to read \"%s\". (error: %s)", filename, std::strerror(errno));
        }
    }

    buffer[*size] = 0;

    std::fclose(fp);
    return buffer;
}
