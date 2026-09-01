#ifndef COMPRES_SMOL
#define COMPRES_SMOL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <bitset>
#include "fileDispatcher.h"
#include "tANS.h"

#define OVERWORLD_16X16         256
#define OVERWORLD_32X32         1024

#define TANS_TABLE_SIZE         64
#define LO_CONTINUE_BIT         0x80
#define LO_LOW_BITS_MASK        0x7f
#define LO_NUM_LOW_BITS         0x7
#define BYTE_MASK               0xff
#define SHORT_MASK              0xffff
#define NIBBLE_MASK             0xf
#define NUM_SHORT_BITS          0xf
#define LENGTH_MOD_MASK         0xf
#define INITIAL_STATE_MASK      0x3f
#define MODE_MASK               0x1f
#define IMAGE_SIZE_MASK         0x3fff
#define IMAGE_SIZE_OFFSET       4
#define SYM_SIZE_MASK           0x3fff
#define SYM_SIZE_OFFSET         18
#define BITSTREAM_SIZE_MASK     0x1fff
#define BITSTREAM_SIZE_OFFSET   6
#define LO_SIZE_MASK            0x1fff
#define LO_SIZE_OFFSET          19

#define IMAGE_SIZE_MODIFIER     4

enum CompressionMode {
    LZ77 = 0,
    BASE_ONLY = 1,
    ENCODE_SYMS = 2,
    ENCODE_DELTA_SYMS = 3,
    ENCODE_LO = 4,
    ENCODE_BOTH = 5,
    ENCODE_BOTH_DELTA_SYMS = 6,
    IS_FRAME_CONTAINER = 7,
    IS_TILEMAP = 8,
};

struct ShortCopy {
    size_t index;
    size_t length;
    size_t offset;
    unsigned short firstSymbol;
    ShortCopy(size_t index, size_t length, size_t offset, unsigned short firstSymbol);
};

struct ShortCompressionInstruction {
    size_t length;
    size_t offset;
    size_t index;
    unsigned short firstSymbol;
    std::vector<unsigned char> loBytes;
    std::vector<unsigned short> symShorts;
    void buildBytes(std::vector<unsigned short> *pInput);
};

struct CompressedImage {
    std::string fileName;
    CompressionMode mode;
    size_t lzSize;
    size_t loSize;
    size_t symSize;
    size_t bitreamSize = 0;
    size_t rawNumBytes;
    int initialState;
    std::vector<unsigned int> headers;
    unsigned int loFreqs[3];
    unsigned int symFreqs[3];
    size_t compressedSize;
    bool isValid = false;
    std::vector<unsigned int> writeVec;
    std::vector<unsigned int> tANSbits;
    std::vector<unsigned int> otherBits;
    std::vector<unsigned short> symVec;
    std::vector<unsigned char> loVec;
};

struct InputSettings {
    bool canEncodeLO = true;
    bool canEncodeSyms = true;
    bool canDeltaSyms = true;
    bool useFrames = false;
    InputSettings();
    InputSettings(bool canEncodeLO, bool canEncodeSyms, bool canDeltaSyms);
};

struct DataVecs {
    std::vector<unsigned char> loVec;
    std::vector<unsigned short> symVec;
};

CompressedImage processImage(std::string fileName, InputSettings settings);
CompressedImage processImageFrames(std::string fileName, InputSettings settings);
bool processImageData(std::vector<unsigned char> *pInput, CompressedImage *pImage, InputSettings settings, std::string fileName);

bool readFileAsUInt(std::string filePath, std::vector<unsigned int> *pFileData);

bool getShortCopies(std::vector<unsigned short> *pInput, size_t minLength, std::vector<ShortCopy> *pShortCopies);
bool verifyShortCopies(std::vector<ShortCopy> *pCopies, std::vector<unsigned short> *pImage);

std::vector<int> getNormalizedCounts(std::vector<size_t> input);
std::vector<unsigned int> getFreqWriteInts(std::vector<int> input);
std::vector<unsigned int> getNewHeaders(CompressionMode mode, size_t imageSize, size_t symLength, int initialState, size_t bitstreamSize, size_t loLength);
int findInitialState(EncodeCol *encodeCol, unsigned char firstSymbol);

bool fillCompressVec(std::vector<unsigned char> *pLoVec, std::vector<unsigned short> *pSymVec, CompressionMode mode, size_t imageBytes, std::string name, CompressedImage *pOutput);

bool getShortInstructions(std::vector<ShortCopy> *pCopies, std::vector<ShortCompressionInstruction> *pInstructions, std::vector<unsigned short> *pInput);
void getLosFromInstructions(std::vector<ShortCompressionInstruction> *pInstructions, std::vector<unsigned char> *pOutput);
void getSymsFromInstructions(std::vector<ShortCompressionInstruction> *pInstructions, std::vector<unsigned short> *pOutput);
std::vector<int> unpackFrequencies(unsigned int pInts[3]);
void readNewHeader(std::vector<unsigned int> *pInput, CompressedImage *pOutput);
void getUIntVecFromData(CompressedImage *pImage, std::vector<unsigned int> *pOutput);

std::vector<unsigned short> decodeBytesShort(std::vector<unsigned char> *pLoVec, std::vector<unsigned short> *pSymVec);
std::vector<unsigned short> decodeImageShort(CompressedImage *pInput);
DataVecs decodeDataVectorsNew(CompressedImage *pInput);
bool compareVectorsShort(std::vector<unsigned short> *pVec1, std::vector<unsigned short> *pVec2);

bool verifyCompressionShort(CompressedImage *pInput, std::vector<unsigned short> *pImage);

bool verifyBytesShort(std::vector<unsigned char> *pLoVec, std::vector<unsigned short> *pSymVec, std::vector<unsigned short> *pImage);
void readRawDataVecs(std::vector<unsigned int> *pInput, std::vector<unsigned short> *pOutput);

bool isModeLoEncoded(CompressionMode mode);
bool isModeSymEncoded(CompressionMode mode);
bool isModeSymDelta(CompressionMode mode);

void deltaEncode(std::vector<unsigned char> *buffer, int length);
void deltaDecode(std::vector<unsigned char> *buffer, int length);

std::vector<int> getTestFreqs(std::vector<int> freqs, std::string name);

#endif
