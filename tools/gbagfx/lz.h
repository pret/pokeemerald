// Copyright (c) 2015 YamaArashi

#ifndef LZ_H
#define LZ_H

unsigned char *LZDecompress(unsigned char *src, int srcSize, int *uncompressedSize);
unsigned char *LZCompress(unsigned char *src, int srcSize, int *compressedSize, const int minDistance);

#endif // LZ_H
