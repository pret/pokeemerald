// Copyright (c) 2016 YamaArashi

#include <stdlib.h>
#include <stdbool.h>
#include "global.h"
#include "rl.h"

unsigned char *RLDecompress(unsigned char *src, int srcSize, int *uncompressedSize)
{
    if (srcSize < 4)
        goto fail;

    int destSize = (src[3] << 16) | (src[2] << 8) | src[1];

    unsigned char *dest = malloc(destSize);

    if (dest == NULL)
        goto fail;

    int srcPos = 4;
    int destPos = 0;

    for (;;)
    {
        if (srcPos >= srcSize)
            goto fail;

        unsigned char flags = src[srcPos++];
        bool compressed = ((flags & 0x80) != 0);

        if (compressed)
        {
            int length = (flags & 0x7F) + 3;
            unsigned char data = src[srcPos++];

            if (destPos + length > destSize)
                goto fail;

            for (int i = 0; i < length; i++)
                dest[destPos++] = data;
        }
        else
        {
            int length = (flags & 0x7F) + 1;

            if (destPos + length > destSize)
                goto fail;

            for (int i = 0; i < length; i++)
                dest[destPos++] = src[srcPos++];
        }

        if (destPos == destSize)
        {
            *uncompressedSize = destSize;
            return dest;
        }
    }

fail:
    FATAL_ERROR("Fatal error while decompressing RL file.\n");
}

unsigned char *RLCompress(unsigned char *src, int srcSize, int *compressedSize)
{
    if (srcSize <= 0)
        goto fail;

    int worstCaseDestSize = 4 + srcSize * 2;

    // Round up to the next multiple of four.
    worstCaseDestSize = (worstCaseDestSize + 3) & ~3;

    unsigned char *dest = malloc(worstCaseDestSize);

    if (dest == NULL)
        goto fail;

    // header
    dest[0] = 0x30; // RL compression type
    dest[1] = (unsigned char)srcSize;
    dest[2] = (unsigned char)(srcSize >> 8);
    dest[3] = (unsigned char)(srcSize >> 16);

    int srcPos = 0;
    int destPos = 4;

    for (;;)
    {
        bool compress = false;
        int uncompressedStart = srcPos;
        int uncompressedLength = 0;

        while (srcPos < srcSize && uncompressedLength < (0x7F + 1))
        {
            compress = (srcPos + 2 < srcSize && src[srcPos] == src[srcPos + 1] && src[srcPos] == src[srcPos + 2]);

            if (compress)
                break;

            srcPos++;
            uncompressedLength++;
        }
        
        if (uncompressedLength > 0)
        {
            dest[destPos++] = uncompressedLength - 1;

            for (int i = 0; i < uncompressedLength; i++)
                dest[destPos++] = src[uncompressedStart + i];
        }

        if (compress)
        {
            unsigned char data = src[srcPos];
            int compressedLength = 0;

            while (compressedLength < (0x7F + 3)
                && srcPos + compressedLength < srcSize
                && src[srcPos + compressedLength] == data)
            {
                compressedLength++;
            }

            dest[destPos++] = 0x80 | (compressedLength - 3);
            dest[destPos++] = data;

            srcPos += compressedLength;
        }

        if (srcPos == srcSize)
        {
            // Pad to multiple of 4 bytes.
            int remainder = destPos % 4;

            if (remainder != 0)
            {
                for (int i = 0; i < 4 - remainder; i++)
                    dest[destPos++] = 0;
            }

            *compressedSize = destPos;
            return dest;
        }
    }

fail:
    FATAL_ERROR("Fatal error while compressing RL file.\n");
}
