#ifndef HUFF_H
#define HUFF_H

union HuffNode;

struct HuffData {
    unsigned value:31;
    unsigned isLeaf:1;
};

struct HuffLeaf {
    struct HuffData header;
    unsigned char key;
};

struct HuffBranch {
    struct HuffData header;
    union HuffNode * left;
    union HuffNode * right;
};

union HuffNode {
    struct HuffData header;
    struct HuffLeaf leaf;
    struct HuffBranch branch;
};

typedef union HuffNode HuffNode_t;

struct BitEncoding {
    unsigned long long nbits:6;
    unsigned long long bitstring:58;
};

unsigned char * HuffCompress(unsigned char * buffer, int srcSize, int * compressedSize_p, int bitDepth);
unsigned char * HuffDecompress(unsigned char * buffer, int srcSize, int * uncompressedSize_p);

#endif //HUFF_H
