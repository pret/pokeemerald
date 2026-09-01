#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <limits>
#include "compressAlgo.h"

//  LO size 1, 964, 11 bits
//  LO size 2, 198, 9 bits
//  LO size 3, 286, 10 bits
//  4 bits mode
//  tilemap size 14 bits
//  symbol size 14 bits

struct VecSizes
{
    size_t tileSize;
    size_t flipSize;
    size_t palSize;
};

struct TileHeader
{
    CompressionMode mode;
    unsigned int tilemapSize;
    unsigned int symbolSize;
    unsigned int loSize;
    unsigned int header[2];
};

struct CompressVectors
{
    std::vector<unsigned char> loVec;
    std::vector<unsigned short> symVec;
};

struct CompressionResult
{
    size_t tilemapSize;
    size_t compressedSize = 0;
    CompressVectors vecs;
    TileHeader header;
    std::vector<unsigned int> writeVec;
    bool failed = false;
};

std::vector<unsigned short> readFileAsUS(std::string filePath);

CompressionResult compressTileset(std::string fileName);
void deltaEncodeTileNums(std::vector<unsigned short> *pTileNums);
void deltaDecodeTileNums(std::vector<unsigned short> *pTileNums);

CompressVectors compressVector(std::vector<unsigned short> *pVec);
std::vector<unsigned short> refineCompression(std::vector<unsigned short> *pVec);
std::vector<unsigned short> decompressVector(std::vector<unsigned short> *pVec);
size_t getTotalSize(std::vector<CompressVectors> *input);
TileHeader getHeader(CompressionResult compression);
TileHeader readTileHeader(unsigned int *data);
std::vector<unsigned int> getWriteVecs(CompressionResult compression);

bool verifyTileCompression(std::vector<unsigned int> compression, std::vector<unsigned short> input);
