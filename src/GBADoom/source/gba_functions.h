#ifndef GBA_FUNCTIONS_H
#define GBA_FUNCTIONS_H

#include <string.h>
#include "doomtype.h"
#include "m_fixed.h"

//#define __arm__

#ifdef __arm__
    #include "gba_systemcalls.h"
    #include "gba_dma.h"
#endif

//***********************************************************************
//The following math functions were taken from the Jaguar Port of Doom
//here: https://github.com/Arc0re/jaguardoom/blob/master/jagonly.c
//
//There may be a licence incompatibility with the iD release
//and the GPL that prBoom (and this as derived work) is under.
//***********************************************************************

static CONSTFUNC unsigned UDiv32 (unsigned aa, unsigned bb)
{
#ifdef __arm__
    unsigned int udiv32_arm(unsigned int a, unsigned int b);

    return udiv32_arm(aa, bb);
#else
    if(bb == 0)
        return UINT_MAX;

    return aa / bb;
#endif
}

inline static CONSTFUNC int IDiv32 (int a, int b)
{

    //use bios divide on gba.
#ifdef __arm__
    return Div(a, b);
#else
    return a / b;
#endif
}

inline static void BlockCopy(void* dest, const void* src, const unsigned int len)
{
#ifdef __arm__
    const int words = len >> 2;

    DMA3COPY(src, dest, DMA_DST_INC | DMA_SRC_INC | DMA32 | DMA_IMMEDIATE | words)
#else
    memcpy(dest, src, len & 0xfffffffc);
#endif
}

inline static void CpuBlockCopy(void* dest, const void* src, const unsigned int len)
{
#ifdef __arm__
    const unsigned int words = len >> 2;

    CpuFastSet(src, dest, words);
#else
    BlockCopy(dest, src, len);
#endif
}

inline static void BlockSet(void* dest, volatile unsigned int val, const unsigned int len)
{
#ifdef __arm__
    const int words = len >> 2;

    DMA3COPY(&val, dest, DMA_SRC_FIXED | DMA_DST_INC | DMA32 | DMA_IMMEDIATE | words)
#else
    memset(dest, val, len & 0xfffffffc);
#endif
}

inline static void ByteCopy(byte* dest, const byte* src, unsigned int count)
{
    do
    {
        *dest++ = *src++;
    } while(--count);
}

inline static void ByteSet(byte* dest, byte val, unsigned int count)
{
    do
    {
        *dest++ = val;
    } while(--count);
}

inline static void* ByteFind(byte* mem, byte val, unsigned int count)
{
    do
    {
        if(*mem == val)
            return mem;

        mem++;
    } while(--count);

    return NULL;
}

inline static void SaveSRAM(const byte* eeprom, unsigned int size, unsigned int offset)
{
#ifdef __arm__
    ByteCopy(0xE000000 + offset, eeprom, size);
#endif
}

inline static void LoadSRAM(byte* eeprom, unsigned int size, unsigned int offset)
{
#ifdef __arm__
    ByteCopy(eeprom, 0xE000000 + offset, size);
#endif
}

//Cheap mul by 120. Not sure if faster.
#define ScreenYToOffset(x) ((x << 7) - (x << 3))

#endif // GBA_FUNCTIONS_H
