#include "global.h"
#include "dma3.h"

IWRAM_DATA struct {
    /* 0x00 */ const u8 *src;
    /* 0x04 */ u8 *dest;
    /* 0x08 */ u16 size;
    /* 0x0A */ u16 mode;
    /* 0x0C */ u32 value;
} gDma3Requests[128];

static bool8 gDma3ManagerLocked;
static u8 gDma3RequestCursor;

void ClearDma3Requests(void)
{
    int i;

    gDma3ManagerLocked = TRUE;
    gDma3RequestCursor = 0;

    for(i = 0; i < (u8)ARRAY_COUNT(gDma3Requests); i++)
    {
        gDma3Requests[i].size = 0;
        gDma3Requests[i].src = 0;
        gDma3Requests[i].dest = 0;
    }

    gDma3ManagerLocked = FALSE;
}

// Maximum amount of data will will transfer in one operation
#define DMA_MAX_BLOCK_SIZE 0x1000

#define Dma3CopyLarge_(src, dest, size, bit)               \
{                                                          \
    const void *_src = src;                                \
    void *_dest = dest;                                    \
    u32 _size = size;                                      \
    while (1)                                              \
    {                                                      \
        if (_size <= DMA_MAX_BLOCK_SIZE)                   \
        {                                                  \
            DmaCopy##bit(3, _src, _dest, _size);           \
            break;                                         \
        }                                                  \
        DmaCopy##bit(3, _src, _dest, DMA_MAX_BLOCK_SIZE);  \
        _src += DMA_MAX_BLOCK_SIZE;                        \
        _dest += DMA_MAX_BLOCK_SIZE;                       \
        _size -= DMA_MAX_BLOCK_SIZE;                       \
    }                                                      \
}

#define Dma3CopyLarge16_(src, dest, size) Dma3CopyLarge_(src, dest, size, 16)
#define Dma3CopyLarge32_(src, dest, size) Dma3CopyLarge_(src, dest, size, 32)

#define Dma3FillLarge_(value, dest, size, bit)             \
{                                                          \
    void *_dest = dest;                                    \
    u32 _size = size;                                      \
    while (1)                                              \
    {                                                      \
        if (_size <= DMA_MAX_BLOCK_SIZE)                   \
        {                                                  \
            DmaFill##bit(3, value, _dest, _size);          \
            break;                                         \
        }                                                  \
        DmaFill##bit(3, value, _dest, DMA_MAX_BLOCK_SIZE); \
        _dest += DMA_MAX_BLOCK_SIZE;                       \
        _size -= DMA_MAX_BLOCK_SIZE;                       \
    }                                                      \
}

#define Dma3FillLarge16_(value, dest, size) Dma3FillLarge_(value, dest, size, 16)
#define Dma3FillLarge32_(value, dest, size) Dma3FillLarge_(value, dest, size, 32)


void ProcessDma3Requests(void)
{
    u16 totalSize;

    if (gDma3ManagerLocked)
        return;

    totalSize = 0;

    // as long as there are DMA requests to process (unless size or vblank is an issue), do not exit
    while (gDma3Requests[gDma3RequestCursor].size != 0)
    {
        totalSize += gDma3Requests[gDma3RequestCursor].size;

        if (totalSize > 0xA000)
            return; // don't do too much at once
        if (*(u8 *)REG_ADDR_VCOUNT > 224)
            return; // we're about to leave vblank, stop

        switch (gDma3Requests[gDma3RequestCursor].mode)
        {
        case 1: // regular 32-bit copy
            Dma3CopyLarge32_(gDma3Requests[gDma3RequestCursor].src,
                             gDma3Requests[gDma3RequestCursor].dest,
                             gDma3Requests[gDma3RequestCursor].size);
            break;
        case 2: // repeat a single 32-bit value across RAM
            Dma3FillLarge32_(gDma3Requests[gDma3RequestCursor].value,
                             gDma3Requests[gDma3RequestCursor].dest,
                             gDma3Requests[gDma3RequestCursor].size);
            break;
        case 3:    // regular 16-bit copy
            Dma3CopyLarge16_(gDma3Requests[gDma3RequestCursor].src,
                             gDma3Requests[gDma3RequestCursor].dest,
                             gDma3Requests[gDma3RequestCursor].size);
            break;
        case 4: // repeat a single 16-bit value across RAM
            Dma3FillLarge16_(gDma3Requests[gDma3RequestCursor].value,
                             gDma3Requests[gDma3RequestCursor].dest,
                             gDma3Requests[gDma3RequestCursor].size);
            break;
        }
        gDma3Requests[gDma3RequestCursor].src = NULL;
        gDma3Requests[gDma3RequestCursor].dest = NULL;
        gDma3Requests[gDma3RequestCursor].size = 0;
        gDma3Requests[gDma3RequestCursor].mode = 0;
        gDma3Requests[gDma3RequestCursor].value = 0;
        gDma3RequestCursor++;

        if (gDma3RequestCursor >= 128) // loop back to the first DMA request
            gDma3RequestCursor = 0;
    }
}

int RequestDma3Copy(const void *src, void *dest, u16 size, u8 mode)
{
    int cursor;
    int var = 0;

    gDma3ManagerLocked = 1;

    cursor = gDma3RequestCursor;
    while(1)
    {
        if(!gDma3Requests[cursor].size) // an empty copy was found and the current cursor will be returned.
        {
            gDma3Requests[cursor].src = src;
            gDma3Requests[cursor].dest = dest;
            gDma3Requests[cursor].size = size;

            if(mode == 1)
                gDma3Requests[cursor].mode = mode;
            else
                gDma3Requests[cursor].mode = 3;

            gDma3ManagerLocked = FALSE;
            return (s16)cursor;
        }
        if(++cursor >= 0x80) // loop back to start.
        {
            cursor = 0;
        }
        if(++var >= 0x80) // max checks were made. all resulted in failure.
        {
            break;
        }
    }
    gDma3ManagerLocked = FALSE;
    return -1;
}

int RequestDma3Fill(s32 value, void *dest, u16 size, u8 mode)
{
    int cursor;
    int var = 0;

    cursor = gDma3RequestCursor;
    gDma3ManagerLocked = 1;

    while(1)
    {
        if(!gDma3Requests[cursor].size)
        {
            gDma3Requests[cursor].dest = dest;
            gDma3Requests[cursor].size = size;
            gDma3Requests[cursor].mode = mode;
            gDma3Requests[cursor].value = value;

            if(mode == 1)
                gDma3Requests[cursor].mode = 2;
            else
                gDma3Requests[cursor].mode = 4;

            gDma3ManagerLocked = FALSE;
            return (s16)cursor;
        }
        if(++cursor >= 0x80) // loop back to start.
        {
            cursor = 0;
        }
        if(++var >= 0x80) // max checks were made. all resulted in failure.
        {
            break;
        }
    }
    gDma3ManagerLocked = FALSE;
    return -1;
}

int CheckForSpaceForDma3Request(s16 index)
{
    int current = 0;

    if (index == -1)
    {
        for (; current < 0x80; current ++)
            if (gDma3Requests[current].size)
                return -1;

        return 0;
    }

    if (gDma3Requests[index].size)
        return -1;

    return 0;
}
