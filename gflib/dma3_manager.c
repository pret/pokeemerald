#include "global.h"
#include "dma3.h"

#define MAX_DMA_REQUESTS 128

#define DMA_REQUEST_COPY32 1
#define DMA_REQUEST_FILL32 2
#define DMA_REQUEST_COPY16 3
#define DMA_REQUEST_FILL16 4

BSS_DATA struct
{
    const u8 *src;
    u8 *dest;
    u16 size;
    u16 mode;
    u32 value;
} gDma3Requests[MAX_DMA_REQUESTS];

static volatile bool8 gDma3ManagerLocked;
static u8 gDma3RequestCursor;

void ClearDma3Requests(void)
{
    int i;

    gDma3ManagerLocked = TRUE;
    gDma3RequestCursor = 0;

    for (i = 0; i < MAX_DMA_REQUESTS; i++)
    {
        gDma3Requests[i].size = 0;
        gDma3Requests[i].src = NULL;
        gDma3Requests[i].dest = NULL;
    }

    gDma3ManagerLocked = FALSE;
}

void ProcessDma3Requests(void)
{
    u16 bytesTransferred;

    if (gDma3ManagerLocked)
        return;

    bytesTransferred = 0;

    // as long as there are DMA requests to process (unless size or vblank is an issue), do not exit
    while (gDma3Requests[gDma3RequestCursor].size != 0)
    {
        bytesTransferred += gDma3Requests[gDma3RequestCursor].size;

        if (bytesTransferred > 40 * 1024)
            return; // don't transfer more than 40 KiB
        if (*(u8 *)REG_ADDR_VCOUNT > 224)
            return; // we're about to leave vblank, stop

        switch (gDma3Requests[gDma3RequestCursor].mode)
        {
        case DMA_REQUEST_COPY32: // regular 32-bit copy
            Dma3CopyLarge32_(gDma3Requests[gDma3RequestCursor].src,
                             gDma3Requests[gDma3RequestCursor].dest,
                             gDma3Requests[gDma3RequestCursor].size);
            break;
        case DMA_REQUEST_FILL32: // repeat a single 32-bit value across RAM
            Dma3FillLarge32_(gDma3Requests[gDma3RequestCursor].value,
                             gDma3Requests[gDma3RequestCursor].dest,
                             gDma3Requests[gDma3RequestCursor].size);
            break;
        case DMA_REQUEST_COPY16:    // regular 16-bit copy
            Dma3CopyLarge16_(gDma3Requests[gDma3RequestCursor].src,
                             gDma3Requests[gDma3RequestCursor].dest,
                             gDma3Requests[gDma3RequestCursor].size);
            break;
        case DMA_REQUEST_FILL16: // repeat a single 16-bit value across RAM
            Dma3FillLarge16_(gDma3Requests[gDma3RequestCursor].value,
                             gDma3Requests[gDma3RequestCursor].dest,
                             gDma3Requests[gDma3RequestCursor].size);
            break;
        }

        // Free the request
        gDma3Requests[gDma3RequestCursor].src = NULL;
        gDma3Requests[gDma3RequestCursor].dest = NULL;
        gDma3Requests[gDma3RequestCursor].size = 0;
        gDma3Requests[gDma3RequestCursor].mode = 0;
        gDma3Requests[gDma3RequestCursor].value = 0;
        gDma3RequestCursor++;

        if (gDma3RequestCursor >= MAX_DMA_REQUESTS) // loop back to the first DMA request
            gDma3RequestCursor = 0;
    }
}

s16 RequestDma3Copy(const void *src, void *dest, u16 size, u8 mode)
{
    int cursor;
    int i = 0;

    gDma3ManagerLocked = TRUE;
    cursor = gDma3RequestCursor;

    while (i < MAX_DMA_REQUESTS)
    {
        if (gDma3Requests[cursor].size == 0) // an empty request was found.
        {
            gDma3Requests[cursor].src = src;
            gDma3Requests[cursor].dest = dest;
            gDma3Requests[cursor].size = size;

            if (mode == 1)
                gDma3Requests[cursor].mode = DMA_REQUEST_COPY32;
            else
                gDma3Requests[cursor].mode = DMA_REQUEST_COPY16;

            gDma3ManagerLocked = FALSE;
            return cursor;
        }
        if (++cursor >= MAX_DMA_REQUESTS) // loop back to start.
            cursor = 0;
        i++;
    }
    gDma3ManagerLocked = FALSE;
    return -1;  // no free DMA request was found
}

s16 RequestDma3Fill(s32 value, void *dest, u16 size, u8 mode)
{
    int cursor;
    int i = 0;

    cursor = gDma3RequestCursor;
    gDma3ManagerLocked = TRUE;

    while (i < MAX_DMA_REQUESTS)
    {
        if (gDma3Requests[cursor].size == 0) // an empty request was found.
        {
            gDma3Requests[cursor].dest = dest;
            gDma3Requests[cursor].size = size;
            gDma3Requests[cursor].mode = mode;
            gDma3Requests[cursor].value = value;

            if(mode == 1)
                gDma3Requests[cursor].mode = DMA_REQUEST_FILL32;
            else
                gDma3Requests[cursor].mode = DMA_REQUEST_FILL16;

            gDma3ManagerLocked = FALSE;
            return cursor;
        }
        if (++cursor >= MAX_DMA_REQUESTS) // loop back to start.
            cursor = 0;
        i++;
    }
    gDma3ManagerLocked = FALSE;
    return -1;  // no free DMA request was found
}

s16 CheckForSpaceForDma3Request(s16 index)
{
    int i = 0;

    if (index == -1)  // check if all requests are free
    {
        while (i < MAX_DMA_REQUESTS)
        {
            if (gDma3Requests[i].size != 0)
                return -1;
            i++;
        }
        return 0;
    }
    else  // check the specified request
    {
        if (gDma3Requests[index].size != 0)
            return -1;
        return 0;
    }
}
