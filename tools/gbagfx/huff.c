#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include "global.h"
#include "huff.h"

static int cmp_tree(const void * a0, const void * b0) {
    return ((struct HuffData *)a0)->value - ((struct HuffData *)b0)->value;
}

typedef int (*cmpfun)(const void *, const void *);

int msort_r(void * data, size_t count, size_t size, cmpfun cmp, void * buffer) {
    /*
     * Out-of-place mergesort (stable sort)
     * Returns 1 on success, 0 on failure
     */
    void * leftPtr;
    void * rightPtr;
    void * leftEnd;
    void * rightEnd;
    int i;

    switch (count) {
    case 0:
        // Should never be here
        return 0;

    case 1:
        // Nothing to do here
        break;

    case 2:
        // Swap the two entries if the right one compares higher.
        if (cmp(data, data + size) > 0) {
            memcpy(buffer, data, size);
            memcpy(data, data + size, size);
            memcpy(data + size, buffer, size);
        }
        break;
    default:
        // Merge sort out-of-place.
        leftPtr = data;
        leftEnd = rightPtr = data + count / 2 * size;
        rightEnd = data + count * size;

        // Sort the left half
        if (!msort_r(leftPtr, count / 2, size, cmp, buffer))
            return 0;

        // Sort the right half
        if (!msort_r(rightPtr, count / 2 + (count & 1), size, cmp, buffer))
            return 0;

        // Merge the sorted halves out of place
        i = 0;
        do {
            if (cmp(leftPtr, rightPtr) <= 0) {
                memcpy(buffer + i * size, leftPtr, size);
                leftPtr += size;
            } else {
                memcpy(buffer + i * size, rightPtr, size);
                rightPtr += size;
            }

        } while (++i < count && leftPtr < leftEnd && rightPtr < rightEnd);

        // Copy the remainder
        if (i < count) {
            if (leftPtr < leftEnd) {
                memcpy(buffer + i * size, leftPtr, leftEnd - leftPtr);
            }
            else {
                memcpy(buffer + i * size, rightPtr, rightEnd - rightPtr);
            }
        }

        // Copy the merged data back
        memcpy(data, buffer, count * size);
        break;
    }

    return 1;
}

int msort(void * data, size_t count, size_t size, cmpfun cmp) {
    void * buffer = malloc(count * size);
    if (buffer == NULL) return 0;
    int result = msort_r(data, count, size, cmp, buffer);
    free(buffer);
    return result;
}

static void write_tree(unsigned char * dest, HuffNode_t * tree, int nitems, struct BitEncoding * encoding) {
    /*
     * The example used to guide this function encodes the tree in a
     * breadth-first manner.  We attempt to emulate that here.
     */

    int i, j, k;

    // There are (2 * nitems - 1) nodes in the binary tree.  Allocate that.
    HuffNode_t * traversal = calloc(2 * nitems - 1, sizeof(HuffNode_t));
    if (traversal == NULL)
        FATAL_ERROR("Fatal error while compressing Huff file.\n");

    // The first node is the root of the tree.
    traversal[0] = *tree;
    i = 1;

    // Copy the tree into a breadth-first ordering using brute force.
    for (int depth = 1; i < 2 * nitems - 1; depth++) {
        // Consider every possible path up to the current depth.
        for (j = 0; i < 2 * nitems - 1 && j < 1 << depth; j++) {
            // The index of the path is used to encode the path itself.
            // Start from the most significant relevant bit and work our way down.
            // Keep track of the current and previous nodes.
            HuffNode_t * currNode = traversal;
            HuffNode_t * parent = NULL;
            for (k = 0; k < depth; k++) {
                if (currNode->header.isLeaf)
                    break;
                parent = currNode;
                if ((j >> (depth - k - 1)) & 1)
                    currNode = currNode->branch.right;
                else
                    currNode = currNode->branch.left;
            }
            // Check that the length of the current path equals the current depth.
            if (k == depth) {
                // Make sure we can encode the current branch.
                // Bail here if we cannot.
                // This is only applicable for 8-bit encodings.
                if (traversal + i - parent > 128)
                    FATAL_ERROR("Fatal error while compressing Huff file: unable to encode binary tree.\n");
                // Copy the current node, and update its parent.
                traversal[i] = *currNode;
                if (parent != NULL) {
                    if ((j & 1) == 1)
                        parent->branch.right = traversal + i;
                    else
                        parent->branch.left = traversal + i;
                }
                // Encode the path through the tree in the lookup table
                if (traversal[i].header.isLeaf) {
                    encoding[traversal[i].leaf.key].nbits = depth;
                    encoding[traversal[i].leaf.key].bitstring = j;
                }
                i++;
            }
        }
    }

    // Encode the size of the tree.
    // This is used by the decompressor to skip the tree.
    dest[4] = nitems - 1;

    // Encode each node in the tree.
    for (i = 0; i < 2 * nitems - 1; i++) {
        HuffNode_t * currNode = traversal + i;
        if (currNode->header.isLeaf) {
            dest[5 + i] = traversal[i].leaf.key;
        } else {
            dest[5 + i] = (((currNode->branch.right - traversal - i) / 2) - 1);
            if (currNode->branch.left->header.isLeaf)
                dest[5 + i] |= 0x80;
            if (currNode->branch.right->header.isLeaf)
                dest[5 + i] |= 0x40;
        }
    }

    free(traversal);
}

static inline void write_32_le(unsigned char * dest, int * destPos, uint32_t * buff, int * buffPos) {
    dest[*destPos] = *buff;
    dest[*destPos + 1] = *buff >> 8;
    dest[*destPos + 2] = *buff >> 16;
    dest[*destPos + 3] = *buff >> 24;
    *destPos += 4;
    *buff = 0;
    *buffPos = 0;
}

static inline void read_32_le(unsigned char * src, int * srcPos, uint32_t * buff) {
    uint32_t tmp = src[*srcPos];
    tmp |= src[*srcPos + 1] << 8;
    tmp |= src[*srcPos + 2] << 16;
    tmp |= src[*srcPos + 3] << 24;
    *srcPos += 4;
    *buff = tmp;
}

static void write_bits(unsigned char * dest, int * destPos, struct BitEncoding * encoding, int value, uint32_t * buff, int * buffBits) {
    int nbits = encoding[value].nbits;
    uint32_t bitstring = encoding[value].bitstring;

    if (*buffBits + nbits >= 32) {
        int diff = *buffBits + nbits - 32;
        *buff <<= nbits - diff;
        *buff |= bitstring >> diff;
        bitstring &= ~(1 << diff);
        nbits = diff;
        write_32_le(dest, destPos, buff, buffBits);
    }
    if (nbits != 0) {
        *buff <<= nbits;
        *buff |= bitstring;
        *buffBits += nbits;
    }
}

/*
=======================================
MAIN COMPRESSION/DECOMPRESSION ROUTINES
=======================================
 */

unsigned char * HuffCompress(unsigned char * src, int srcSize, int * compressedSize_p, int bitDepth) {
    if (srcSize <= 0)
        goto fail;

    int worstCaseDestSize = 4 + (2 << bitDepth) + srcSize * 3;

    unsigned char *dest = malloc(worstCaseDestSize);
    if (dest == NULL)
        goto fail;

    int nitems = 1 << bitDepth;

    HuffNode_t * freqs = calloc(nitems, sizeof(HuffNode_t));
    if (freqs == NULL)
        goto fail;

    struct BitEncoding * encoding = calloc(nitems, sizeof(struct BitEncoding));
    if (encoding == NULL)
        goto fail;

    // Set up the frequencies table.  This will inform the tree.
    for (int i = 0; i < nitems; i++) {
        freqs[i].header.isLeaf = 1;
        freqs[i].header.value = 0;
        freqs[i].leaf.key = i;
    }

    // Count each nybble or byte.
    for (int i = 0; i < srcSize; i++) {
        if (bitDepth == 8) {
            freqs[src[i]].header.value++;
        } else {
            freqs[src[i] >> 4].header.value++;
            freqs[src[i] & 0xF].header.value++;
        }
    }

#ifdef DEBUG
    for (int i = 0; i < nitems; i++) {
        fprintf(stderr, "%d: %d\n", i, freqs[i].header.value);
    }
#endif // DEBUG

    // Sort the frequency table.
    if (!msort(freqs, nitems, sizeof(HuffNode_t), cmp_tree))
        goto fail;

    // Prune zero-frequency values.
    for (int i = 0; i < nitems; i++) {
        if (freqs[i].header.value != 0) {
            if (i > 0) {
                for (int j = i; j < nitems; j++) {
                    freqs[j - i] = freqs[j];
                }
                nitems -= i;
            }
            break;
        }
        // This should never happen:
        if (i == nitems - 1)
            goto fail;
    }

    HuffNode_t * tree = calloc(nitems * 2 - 1, sizeof(HuffNode_t));
    if (tree == NULL)
        goto fail;

    // Iteratively collapse the two least frequent nodes.
    HuffNode_t * endptr = freqs + nitems - 2;

    for (int i = 0; i < nitems - 1; i++) {
        HuffNode_t * left = freqs;
        HuffNode_t * right = freqs + 1;
        tree[i * 2] = *right;
        tree[i * 2 + 1] = *left;
        for (int j = 0; j < nitems - i - 2; j++)
            freqs[j] = freqs[j + 2];
        endptr->header.isLeaf = 0;
        endptr->header.value = tree[i * 2].header.value + tree[i * 2 + 1].header.value;
        endptr->branch.left = tree + i * 2;
        endptr->branch.right = tree + i * 2 + 1;
        endptr--;
        if (i < nitems - 2 && !msort(freqs, nitems - i - 1, sizeof(HuffNode_t), cmp_tree))
            goto fail;
    }

    // Write the tree breadth-first, and create the path lookup table.
    write_tree(dest, freqs, nitems, encoding);

    free(tree);
    free(freqs);

    // Encode the data itself.
    int destPos = 4 + nitems * 2;
    uint32_t destBuf = 0;
    uint32_t srcBuf = 0;
    int destBitPos = 0;

    for (int srcPos = 0; srcPos < srcSize;) {
        read_32_le(src, &srcPos, &srcBuf);
        for (int i = 0; i < 32 / bitDepth; i++) {
            write_bits(dest, &destPos, encoding, srcBuf & (0xFF >> (8 - bitDepth)), &destBuf, &destBitPos);
            srcBuf >>= bitDepth;
        }
    }

    if (destBitPos != 0) {
        write_32_le(dest, &destPos, &destBuf, &destBitPos);
    }

    free(encoding);

    // Write the header.
    dest[0] = bitDepth | 0x20;
    dest[1] = srcSize;
    dest[2] = srcSize >> 8;
    dest[3] = srcSize >> 16;
    *compressedSize_p = (destPos + 3) & ~3;
    return dest;

fail:
    FATAL_ERROR("Fatal error while compressing Huff file.\n");
}

unsigned char * HuffDecompress(unsigned char * src, int srcSize, int * uncompressedSize_p) {
    if (srcSize < 4)
        goto fail;

    int bitDepth = *src & 15;
    if (bitDepth != 4 && bitDepth != 8)
        goto fail;

    int destSize = (src[3] << 16) | (src[2] << 8) | src[1];

    unsigned char *dest = malloc(destSize);

    if (dest == NULL)
        goto fail;

    int treePos = 5;
    int treeSize = (src[4] + 1) * 2;
    int srcPos = 4 + treeSize;
    int destPos = 0;
    int curValPos = 0;
    uint32_t destTmp = 0;
    uint32_t window;

    for (;;)
    {
        if (srcPos >= srcSize)
            goto fail;
        read_32_le(src, &srcPos, &window);
        for (int i = 0; i < 32; i++) {
            int curBit = (window >> 31) & 1;
            unsigned char treeView = src[treePos];
            bool isLeaf = ((treeView << curBit) & 0x80) != 0;
            treePos &= ~1; // align
            treePos += ((treeView & 0x3F) + 1) * 2 + curBit;
            if (isLeaf) {
                destTmp >>= bitDepth;
                destTmp |= (src[treePos] << (32 - bitDepth));
                curValPos++;
                if (curValPos == 32 / bitDepth) {
                    write_32_le(dest, &destPos, &destTmp, &curValPos);
                    if (destPos == destSize) {
                        *uncompressedSize_p = destSize;
                        return dest;
                    }
                }
                treePos = 5;
            }
            window <<= 1;
        }
    }

fail:
    FATAL_ERROR("Fatal error while decompressing Huff file.\n");
}
