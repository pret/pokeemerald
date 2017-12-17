// Copyright (c) 2016 YamaArashi

#ifndef RL_H
#define RL_H

unsigned char *RLDecompress(unsigned char *src, int srcSize, int *uncompressedSize);
unsigned char *RLCompress(unsigned char *src, int srcSize, int *compressedSize);

#endif // RL_H
