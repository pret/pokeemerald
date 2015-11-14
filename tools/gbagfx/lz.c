// Copyright (c) 2015 YamaArashi

#include <stdlib.h>
#include <stdbool.h>
#include "global.h"
#include "lz.h"

unsigned char *LZDecompress(unsigned char *src, int srcSize, int *uncompressedSize)
{
	if (srcSize < 4)
		return NULL;

	int destSize = (src[3] << 16) | (src[2] << 8) | src[1];

	unsigned char *dest = malloc(destSize);

	if (dest == NULL)
		return NULL;

	int srcPos = 4;
	int destPos = 0;

	for (;;) {
		if (srcPos >= srcSize)
			return NULL;

		unsigned char flags = src[srcPos++];

		for (int i = 0; i < 8; i++) {
			if (flags & 0x80) {
				if (srcPos + 1 >= srcSize)
					return NULL;

				int blockSize = (src[srcPos] >> 4) + 3;
				int blockDistance = (((src[srcPos] & 0xF) << 8) | src[srcPos + 1]) + 1;

				srcPos += 2;

				int blockPos = destPos - blockDistance;

				if (destPos + blockSize > destSize || blockPos < 0)
					return NULL;

				for (int j = 0; j < blockSize; j++)
					dest[destPos++] = dest[blockPos + j];
			} else {
				if (srcPos >= srcSize || destPos >= destSize)
					return NULL;

				dest[destPos++] = src[srcPos++];
			}

			if (destPos == destSize) {
				*uncompressedSize = destSize;
				return dest;
			}

			flags <<= 1;
		}
	}
}

unsigned char *LZCompress(unsigned char *src, int srcSize, int *compressedSize)
{
	const int minDistance = 2; // for compatibility with LZ77UnCompVram()

	if (srcSize <= 0)
		return NULL;

	int worstCaseDestSize = 4 + srcSize + ((srcSize + 7) / 8);

	// Round up to the next multiple of four.
	worstCaseDestSize = (worstCaseDestSize + 3) & ~3;

	unsigned char *dest = malloc(worstCaseDestSize);

	if (dest == NULL)
		return NULL;

	// header
	dest[0] = 0x10; // LZ compression type
	dest[1] = (unsigned char)srcSize;
	dest[2] = (unsigned char)(srcSize >> 8);
	dest[3] = (unsigned char)(srcSize >> 16);

	int srcPos = 0;
	int destPos = 4;

	for (;;) {
		unsigned char *flags = &dest[destPos++];
		*flags = 0;

		for (int i = 0; i < 8; i++) {
			int bestBlockDistance = 0;
			int bestBlockSize = 0;
			int blockDistance = minDistance;

			while (blockDistance <= srcPos && blockDistance <= 0x1000) {
				int blockStart = srcPos - blockDistance;
				int blockSize = 0;

				while (blockSize < 18
				    && srcPos + blockSize < srcSize
				    && src[blockStart + blockSize] == src[srcPos + blockSize])
					blockSize++;

				if (blockSize > bestBlockSize) {
					bestBlockDistance = blockDistance;
					bestBlockSize = blockSize;

					if (blockSize == 18)
						break;
				}

				blockDistance++;
			}

			if (bestBlockSize >= 3) {
				*flags |= (0x80 >> i);
				srcPos += bestBlockSize;
				bestBlockSize -= 3;
				bestBlockDistance--;
				dest[destPos++] = (bestBlockSize << 4) | ((unsigned int)bestBlockDistance >> 8);
				dest[destPos++] = (unsigned char)bestBlockDistance;
			} else {
				dest[destPos++] = src[srcPos++];
			}

			if (srcPos == srcSize) {
				// Pad to multiple of 4 bytes.
				int remainder = destPos % 4;

				if (remainder != 0) {
					for (int i = 0; i < 4 - remainder; i++)
						dest[destPos++] = 0;
				}

				*compressedSize = destPos;
				return dest;
			}
		}
	}
}
