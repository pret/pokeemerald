#include "global.h"
#include "window.h"
#include "malloc.h"

extern u8 gUnknown_03002F60;
extern void* gUnknown_03002F70[];
extern u32 gUnneededFireRedVariable;

#define WINDOWS_MAX  32

EWRAM_DATA struct Window gWindows[WINDOWS_MAX] = {0};
EWRAM_DATA static struct Window* sWindowPtr = NULL;
EWRAM_DATA static u16 sWindowSize = 0;

extern void* GetBgTilemapBuffer(u8 bg);
extern int DummiedOutFireRedLeafGreenTileAllocFunc(int, int, int, int);
extern u16 GetBgAttribute(u8 bg, u8 attributeId);
extern void SetBgTilemapBuffer(u8 bg, void *tilemap);
extern void CopyBgTilemapBufferToVram(u8 bg);
extern u8 LoadBgTiles(u8 bg, void *src, u16 size, u16 destOffset);
extern void WriteSequenceToBgTilemapBuffer(u8 bg, u16 firstTileNum, u8 x, u8 y, u8 width, u8 height, u8 paletteSlot, u16 tileNumDelta);
extern void FillBgTilemapBufferRect(u8 bg, u16 tileNum, u8 x, u8 y, u8 width, u8 height, u8 palette);
extern void BlitBitmapRect4Bit(struct Bitmap *src, struct Bitmap *dest, u16 srcX, u16 srcY, u16 destX, u16 destY, u16 width, u16 height, u8 colorKey);
extern void BlitBitmapRect4BitTo8Bit(struct Bitmap *src, struct Bitmap *dest, u16 srcX, u16 srcY, u16 destX, u16 destY, u16 width, u16 height, u8 colorKey, u8 paletteNum);
extern void FillBitmapRect4Bit(struct Bitmap *surface, u16 x, u16 y, u16 width, u16 height, u8 fillValue);
extern void FillBitmapRect8Bit(struct Bitmap *surface, u16 x, u16 y, u16 width, u16 height, u8 fillValue);

static u8 GetNumActiveWindowsOnBg(u8 bgId);
static u8 GetNumActiveWindowsOnBg8Bit(u8 bgId);

static const struct WindowTemplate sDummyWindowTemplate = {0xFF, 0, 0, 0, 0, 0, 0};

static void nullsub_8(void)
{

}

bool16 InitWindows(struct WindowTemplate *templates)
{
    int i;
    void *bgTilemapBuffer;
    int j;
    u8 bgLayer;
    u16 attrib;
    u8* allocatedTilemapBuffer;
    int allocatedBaseBlock;

    for (i = 0; i < 0x4; ++i)
    {
        bgTilemapBuffer = GetBgTilemapBuffer(i);
        if (bgTilemapBuffer != NULL)
            gUnknown_03002F70[i] = nullsub_8;
        else
            gUnknown_03002F70[i] = bgTilemapBuffer;
    }

    for (i = 0; i < 0x20; ++i)
    {
        gWindows[i].window = sDummyWindowTemplate;
        gWindows[i].tileData = NULL;
    }

    for (i = 0, allocatedBaseBlock = 0, bgLayer = templates[i].priority; bgLayer != 0xFF && i < 0x20; ++i, bgLayer = templates[i].priority)
    {
        if (gUnneededFireRedVariable == 1)
        {
            allocatedBaseBlock = DummiedOutFireRedLeafGreenTileAllocFunc(bgLayer, 0, templates[i].width * templates[i].height, 0);
            if (allocatedBaseBlock == -1)
                return FALSE;
        }

        if (gUnknown_03002F70[bgLayer] == NULL)
        {
            attrib = GetBgAttribute(bgLayer, 0x8);

            if (attrib != 0xFFFF)
            {
                allocatedTilemapBuffer = AllocZeroed(attrib);

                if (allocatedTilemapBuffer == NULL)
                {
                    FreeAllWindowBuffers();
                    return FALSE;
                }

                for (j = 0; j < attrib; ++j)
                    allocatedTilemapBuffer[j] = 0;

                gUnknown_03002F70[bgLayer] = allocatedTilemapBuffer;
                SetBgTilemapBuffer(bgLayer, allocatedTilemapBuffer);
            }
        }

        allocatedTilemapBuffer = AllocZeroed((u16)(0x20 * (templates[i].width * templates[i].height)));

        if (allocatedTilemapBuffer == NULL)
        {
            if ((GetNumActiveWindowsOnBg(bgLayer) == 0) && (gUnknown_03002F70[bgLayer] != nullsub_8))
            {
                Free(gUnknown_03002F70[bgLayer]);
                gUnknown_03002F70[bgLayer] = allocatedTilemapBuffer;
            }

            return FALSE;
        }

        gWindows[i].tileData = allocatedTilemapBuffer;
        gWindows[i].window = templates[i];

        if (gUnneededFireRedVariable == 1)
        {
            gWindows[i].window.baseBlock = allocatedBaseBlock;
            DummiedOutFireRedLeafGreenTileAllocFunc(bgLayer, allocatedBaseBlock, templates[i].width * templates[i].height, 1);
        }
    }

    gUnknown_03002F60 = 0;
    return TRUE;
}

u16 AddWindow(const struct WindowTemplate *template)
{
    u16 win;
    u8 bgLayer;
    int allocatedBaseBlock;
    u16 attrib;
    u8 *allocatedTilemapBuffer;
    int i;

    for (win = 0; win < 0x20; ++win)
    {
        if ((bgLayer = gWindows[win].window.priority) == 0xFF)
            break;
    }

    if (win == 0x20)
        return 0xFF;

    bgLayer = template->priority;
    allocatedBaseBlock = 0;

    if (gUnneededFireRedVariable == 1)
    {
        allocatedBaseBlock = DummiedOutFireRedLeafGreenTileAllocFunc(bgLayer, 0, template->width * template->height, 0);

        if (allocatedBaseBlock == -1)
            return 0xFF;
    }

    if (gUnknown_03002F70[bgLayer] == NULL)
    {
        attrib = GetBgAttribute(bgLayer, 0x8);

        if (attrib != 0xFFFF)
        {
            allocatedTilemapBuffer = AllocZeroed(attrib);

            if (allocatedTilemapBuffer == NULL)
                return 0xFF;

            for (i = 0; i < attrib; ++i)
                allocatedTilemapBuffer[i] = 0;

            gUnknown_03002F70[bgLayer] = allocatedTilemapBuffer;
            SetBgTilemapBuffer(bgLayer, allocatedTilemapBuffer);
        }
    }

    allocatedTilemapBuffer = AllocZeroed((u16)(0x20 * (template->width * template->height)));

    if (allocatedTilemapBuffer == NULL)
    {
        if ((GetNumActiveWindowsOnBg(bgLayer) == 0) && (gUnknown_03002F70[bgLayer] != nullsub_8))
        {
            Free(gUnknown_03002F70[bgLayer]);
            gUnknown_03002F70[bgLayer] = allocatedTilemapBuffer;
        }
        return 0xFF;
    }

    gWindows[win].tileData = allocatedTilemapBuffer;
    gWindows[win].window = *template;

    if (gUnneededFireRedVariable == 1)
    {
        gWindows[win].window.baseBlock = allocatedBaseBlock;
        DummiedOutFireRedLeafGreenTileAllocFunc(bgLayer, allocatedBaseBlock, gWindows[win].window.width * gWindows[win].window.height, 1);
    }

    return win;
}

int AddWindowWithoutTileMap(struct WindowTemplate *template)
{
    u16 win;
    u8 bgLayer;
    int allocatedBaseBlock;

    for (win = 0; win < 0x20; ++win)
    {
        if (gWindows[win].window.priority == 0xFF)
            break;
    }

    if (win == 0x20)
        return 0xFF;

    bgLayer = template->priority;
    allocatedBaseBlock = 0;

    if (gUnneededFireRedVariable == 1)
    {
        allocatedBaseBlock = DummiedOutFireRedLeafGreenTileAllocFunc(bgLayer, 0, template->width * template->height, 0);

        if (allocatedBaseBlock == -1)
            return 0xFF;
    }

    gWindows[win].window = *template;

    if (gUnneededFireRedVariable == 1)
    {
        gWindows[win].window.baseBlock = allocatedBaseBlock;
        DummiedOutFireRedLeafGreenTileAllocFunc(bgLayer, allocatedBaseBlock, gWindows[win].window.width * gWindows[win].window.height, 1);
    }

    return win;
}

void RemoveWindow(u8 windowId)
{
    u8 bgLayer = gWindows[windowId].window.priority;

    if (gUnneededFireRedVariable == 1)
    {
        DummiedOutFireRedLeafGreenTileAllocFunc(bgLayer, gWindows[windowId].window.baseBlock, gWindows[windowId].window.width * gWindows[windowId].window.height, 2);
    }

    gWindows[windowId].window = sDummyWindowTemplate;

    if (GetNumActiveWindowsOnBg(bgLayer) == 0)
    {
        if (gUnknown_03002F70[bgLayer] != nullsub_8)
        {
            Free(gUnknown_03002F70[bgLayer]);
            gUnknown_03002F70[bgLayer] = 0;
        }
    }

    if (gWindows[windowId].tileData != NULL)
    {
        Free(gWindows[windowId].tileData);
        gWindows[windowId].tileData = NULL;
    }
}

void FreeAllWindowBuffers(void)
{
    int i;

    for (i = 0; i < 4; ++i)
    {
        if (gUnknown_03002F70[i] != NULL && gUnknown_03002F70[i] != nullsub_8)
        {
            Free(gUnknown_03002F70[i]);
            gUnknown_03002F70[i] = NULL;
        }
    }

    for (i = 0; i < 0x20; ++i)
    {
        if (gWindows[i].tileData != NULL)
        {
            Free(gWindows[i].tileData);
            gWindows[i].tileData = NULL;
        }
    }
}

void CopyWindowToVram(u8 windowId, u8 mode)
{
    struct Window windowLocal = gWindows[windowId];
    u16 windowSize = 32 * (windowLocal.window.width * windowLocal.window.height);

    switch (mode)
    {
        case 1:
            CopyBgTilemapBufferToVram(windowLocal.window.priority);
            break;
        case 2:
            LoadBgTiles(windowLocal.window.priority, windowLocal.tileData, windowSize, windowLocal.window.baseBlock);
            break;
        case 3:
            LoadBgTiles(windowLocal.window.priority, windowLocal.tileData, windowSize, windowLocal.window.baseBlock);
            CopyBgTilemapBufferToVram(windowLocal.window.priority);
            break;
    }
}

void CopyWindowRectToVram(u32 windowId, u32 mode, u32 x, u32 y, u32 w, u32 h)
{
    struct Window windowLocal;
    int rectSize;
    int rectPos;

    if (w != 0 && h != 0)
    {
        windowLocal = gWindows[windowId];

        rectSize = ((h - 1) * windowLocal.window.width);
        rectSize += (windowLocal.window.width - x);
        rectSize -= (windowLocal.window.width - (x + w));
        rectSize *= 32;

        rectPos = (y * windowLocal.window.width) + x;

        switch (mode)
        {
            case 1:
                CopyBgTilemapBufferToVram(windowLocal.window.priority);
                break;
            case 2:
                LoadBgTiles(windowLocal.window.priority, windowLocal.tileData + (rectPos * 32), rectSize, windowLocal.window.baseBlock + rectPos);
                break;
            case 3:
                LoadBgTiles(windowLocal.window.priority, windowLocal.tileData + (rectPos * 32), rectSize, windowLocal.window.baseBlock + rectPos);
                CopyBgTilemapBufferToVram(windowLocal.window.priority);
                break;
        }
    }
}

void PutWindowTilemap(u8 windowId)
{
    struct Window windowLocal = gWindows[windowId];

    WriteSequenceToBgTilemapBuffer(
        windowLocal.window.priority,
        GetBgAttribute(windowLocal.window.priority, 0xA) + windowLocal.window.baseBlock,
        windowLocal.window.tilemapLeft,
        windowLocal.window.tilemapTop,
        windowLocal.window.width,
        windowLocal.window.height,
        windowLocal.window.paletteNum,
        1);
}

void PutWindowRectTilemapOverridePalette(u8 windowId, u8 x, u8 y, u8 width, u8 height, u8 palette)
{
    struct Window windowLocal = gWindows[windowId];
    u16 currentRow = windowLocal.window.baseBlock + (y * windowLocal.window.width) + x + GetBgAttribute(windowLocal.window.priority, 0xA);
    int i;

    for (i = 0; i < height; ++i)
    {
        WriteSequenceToBgTilemapBuffer(
            windowLocal.window.priority,
            currentRow,
            windowLocal.window.tilemapLeft + x,
            windowLocal.window.tilemapTop + y + i,
            width,
            1,
            palette,
            1);

        currentRow += windowLocal.window.width;
    }
}

void ClearWindowTilemap(u8 windowId)
{
    struct Window windowLocal = gWindows[windowId];

    FillBgTilemapBufferRect(
        windowLocal.window.priority,
        gUnknown_03002F60,
        windowLocal.window.tilemapLeft,
        windowLocal.window.tilemapTop,
        windowLocal.window.width,
        windowLocal.window.height,
        windowLocal.window.paletteNum);
}

void PutWindowRectTilemap(u8 windowId, u8 x, u8 y, u8 width, u8 height)
{
    struct Window windowLocal = gWindows[windowId];
    u16 currentRow = windowLocal.window.baseBlock + (y * windowLocal.window.width) + x + GetBgAttribute(windowLocal.window.priority, 0xA);
    int i;

    for (i = 0; i < height; ++i)
    {
        WriteSequenceToBgTilemapBuffer(
            windowLocal.window.priority,
            currentRow,
            windowLocal.window.tilemapLeft + x,
            windowLocal.window.tilemapTop + y + i,
            width,
            1,
            windowLocal.window.paletteNum,
            1);

        currentRow += windowLocal.window.width;
    }
}

void BlitBitmapToWindow(u8 windowId, u8 *pixels, u16 x, u16 y, u16 width, u16 height)
{
    BlitBitmapRectToWindow(windowId, pixels, 0, 0, width, height, x, y, width, height);
}

void BlitBitmapRectToWindow(u8 windowId, const u8 *pixels, u16 srcX, u16 srcY, u16 srcWidth, int srcHeight, u16 destX, u16 destY, u16 rectWidth, u16 rectHeight)
{
    struct Bitmap sourceRect;
    struct Bitmap destRect;

    sourceRect.pixels = (u8*)pixels;
    sourceRect.width = srcWidth;
    sourceRect.height = srcHeight;

    destRect.pixels = gWindows[windowId].tileData;
    destRect.width = 8 * gWindows[windowId].window.width;
    destRect.height = 8 * gWindows[windowId].window.height;

    BlitBitmapRect4Bit(&sourceRect, &destRect, srcX, srcY, destX, destY, rectWidth, rectHeight, 0);
}

static void BlitBitmapRectToWindowWithColorKey(u8 windowId, const u8 *pixels, u16 srcX, u16 srcY, u16 srcWidth, int srcHeight, u16 destX, u16 destY, u16 rectWidth, u16 rectHeight, u8 colorKey)
{
    struct Bitmap sourceRect;
    struct Bitmap destRect;

    sourceRect.pixels = (u8*)pixels;
    sourceRect.width = srcWidth;
    sourceRect.height = srcHeight;

    destRect.pixels = gWindows[windowId].tileData;
    destRect.width = 8 * gWindows[windowId].window.width;
    destRect.height = 8 * gWindows[windowId].window.height;

    BlitBitmapRect4Bit(&sourceRect, &destRect, srcX, srcY, destX, destY, rectWidth, rectHeight, colorKey);
}

void FillWindowPixelRect(u8 windowId, u8 fillValue, u16 x, u16 y, u16 width, u16 height)
{
    struct Bitmap pixelRect;

    pixelRect.pixels = gWindows[windowId].tileData;
    pixelRect.width = 8 * gWindows[windowId].window.width;
    pixelRect.height = 8 * gWindows[windowId].window.height;

    FillBitmapRect4Bit(&pixelRect, x, y, width, height, fillValue);
}

void CopyToWindowPixelBuffer(u8 windowId, u8 *src, u16 size, u16 tileOffset)
{
    if (size != 0)
        CpuCopy16(src, gWindows[windowId].tileData + (0x20 * tileOffset), size);
    else
        LZ77UnCompWram(src, gWindows[windowId].tileData + (0x20 * tileOffset));
}

void FillWindowPixelBuffer(u8 windowId, u8 fillValue)
{
    int fillSize = gWindows[windowId].window.width * gWindows[windowId].window.height;
    CpuFastFill8(fillValue, gWindows[windowId].tileData, 0x20 * fillSize);
}

// functionally equivalent, its fucking hard to match
#ifdef NONMATCHING
void ScrollWindow(u8 windowId, u8 direction, u8 distance, u8 fillValue)
{
    s32 i, id1, id2, size;
    u32 distanceLoop, toFill, width;
    u8 *tileData;
    struct WindowTemplate window;

    tileData = gWindows[windowId].tileData;
    toFill = (fillValue << 0x18) | (fillValue << 0x10) | (fillValue << 8) | fillValue;
    window = gWindows[windowId].window;
    size = 0x20 * (window.height * window.width);
    width = window.width;
    if (direction != 1)
    {
        s32 signedDirection = direction;
        if (signedDirection <= 1)
        {
            if (signedDirection == 0)
            {
                for (i = 0; i < size; i += 0x20)
                {
                    distanceLoop = distance;
                    id1 = i + 0;
                    id2 = i + (((width * ((distanceLoop) & ~(7))) | ((distanceLoop) & 7)) * 4);
                    if (id2 < size)
                        *(u32*)(tileData + id1) = *(u32*)(tileData + id2);
                    else
                        *(u32*)(tileData + id1) = toFill;

                    distanceLoop++;
                    id1 = i + 4;
                    id2 = i + (((width * ((distanceLoop) & ~(7))) | ((distanceLoop) & 7)) * 4);
                    if (id2 < size)
                        *(u32*)(tileData + id1) = *(u32*)(tileData + id2);
                    else
                        *(u32*)(tileData + id1) = toFill;

                    distanceLoop++;
                    id1 = i + 8;
                    id2 = i + (((width * ((distanceLoop) & ~(7))) | ((distanceLoop) & 7)) * 4);
                    if (id2 < size)
                        *(u32*)(tileData + id1) = *(u32*)(tileData + id2);
                    else
                        *(u32*)(tileData + id1) = toFill;

                    distanceLoop++;
                    id1 = i + 12;
                    id2 = i + (((width * ((distanceLoop) & ~(7))) | ((distanceLoop) & 7)) * 4);
                    if (id2 < size)
                        *(u32*)(tileData + id1) = *(u32*)(tileData + id2);
                    else
                        *(u32*)(tileData + id1) = toFill;

                    distanceLoop++;
                    id1 = i + 16;
                    id2 = i + (((width * ((distanceLoop) & ~(7))) | ((distanceLoop) & 7)) * 4);
                    if (id2 < size)
                        *(u32*)(tileData + id1) = *(u32*)(tileData + id2);
                    else
                        *(u32*)(tileData + id1) = toFill;

                    distanceLoop++;
                    id1 = i + 20;
                    id2 = i + (((width * ((distanceLoop) & ~(7))) | ((distanceLoop) & 7)) * 4);
                    if (id2 < size)
                        *(u32*)(tileData + id1) = *(u32*)(tileData + id2);
                    else
                        *(u32*)(tileData + id1) = toFill;

                    distanceLoop++;
                    id1 = i + 24;
                    id2 = i + (((width * ((distanceLoop) & ~(7))) | ((distanceLoop) & 7)) * 4);
                    if (id2 < size)
                        *(u32*)(tileData + id1) = *(u32*)(tileData + id2);
                    else
                        *(u32*)(tileData + id1) = toFill;

                    distanceLoop++;
                    id1 = i + 28;
                    id2 = i + (((width * ((distanceLoop) & ~(7))) | ((distanceLoop) & 7)) * 4);
                    if (id2 < size)
                        *(u32*)(tileData + id1) = *(u32*)(tileData + id2);
                    else
                        *(u32*)(tileData + id1) = toFill;
                }
            }
        }
    }
    else
    {
        tileData += size - 4;
        for (i = 0; i < size; i += 0x20)
        {
            distanceLoop = distance;
            id1 = i + 0;
            id2 = i + (((width * ((distanceLoop) & ~(7))) | ((distanceLoop) & 7)) * 4);
            if (id2 < size)
                *(u32*)(tileData - id1) = *(u32*)(tileData - id2);
            else
                *(u32*)(tileData - id1)  = toFill;

            distanceLoop++;
            id1 = i + 4;
            id2 = i + (((width * ((distanceLoop) & ~(7))) | ((distanceLoop) & 7)) * 4);
            if (id2 < size)
                *(u32*)(tileData - id1) = *(u32*)(tileData - id2);
            else
                *(u32*)(tileData - id1)  = toFill;

            distanceLoop++;
            id1 = i + 8;
            id2 = i + (((width * ((distanceLoop) & ~(7))) | ((distanceLoop) & 7)) * 4);
            if (id2 < size)
                *(u32*)(tileData - id1) = *(u32*)(tileData - id2);
            else
                *(u32*)(tileData - id1)  = toFill;

            distanceLoop++;
            id1 = i + 12;
            id2 = i + (((width * ((distanceLoop) & ~(7))) | ((distanceLoop) & 7)) * 4);
            if (id2 < size)
                *(u32*)(tileData - id1) = *(u32*)(tileData - id2);
            else
                *(u32*)(tileData - id1)  = toFill;

            distanceLoop++;
            id1 = i + 16;
            id2 = i + (((width * ((distanceLoop) & ~(7))) | ((distanceLoop) & 7)) * 4);
            if (id2 < size)
                *(u32*)(tileData - id1) = *(u32*)(tileData - id2);
            else
                *(u32*)(tileData - id1)  = toFill;

            distanceLoop++;
            id1 = i + 20;
            id2 = i + (((width * ((distanceLoop) & ~(7))) | ((distanceLoop) & 7)) * 4);
            if (id2 < size)
                *(u32*)(tileData - id1) = *(u32*)(tileData - id2);
            else
                *(u32*)(tileData - id1)  = toFill;

            distanceLoop++;
            id1 = i + 24;
            id2 = i + (((width * ((distanceLoop) & ~(7))) | ((distanceLoop) & 7)) * 4);
            if (id2 < size)
                *(u32*)(tileData - id1) = *(u32*)(tileData - id2);
            else
                *(u32*)(tileData - id1)  = toFill;

            distanceLoop++;
            id1 = i + 28;
            id2 = i + (((width * ((distanceLoop) & ~(7))) | ((distanceLoop) & 7)) * 4);
            if (id2 < size)
                *(u32*)(tileData - id1) = *(u32*)(tileData - id2);
            else
                *(u32*)(tileData - id1)  = toFill;
        }
    }
}
#else
__attribute__((naked))
void ScrollWindow(u8 windowId, u8 direction, u8 distance, u8 fillValue)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0x8\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	lsls r1, 24\n\
	lsrs r1, 24\n\
	mov r8, r1\n\
	lsls r2, 24\n\
	lsrs r2, 24\n\
	str r2, [sp]\n\
	lsls r3, 24\n\
	lsrs r3, 24\n\
	ldr r2, =gWindows\n\
	lsls r1, r0, 1\n\
	adds r1, r0\n\
	lsls r1, 2\n\
	adds r4, r1, r2\n\
	adds r2, 0x8\n\
	adds r1, r2\n\
	ldr r5, [r1]\n\
	lsls r7, r3, 24\n\
	lsls r0, r3, 16\n\
	orrs r7, r0\n\
	lsls r0, r3, 8\n\
	orrs r7, r0\n\
	orrs r7, r3\n\
	ldr r1, [r4]\n\
	ldr r2, [r4, 0x4]\n\
	ldrb r3, [r4, 0x4]\n\
	lsrs r0, r1, 24\n\
	muls r0, r3\n\
	lsls r6, r0, 5\n\
	lsrs r1, 24\n\
	mov r12, r1\n\
	mov r0, r8\n\
	cmp r0, 0x1\n\
	bne _08003CE8\n\
	b _08003E9E\n\
_08003CE8:\n\
	cmp r0, 0x1\n\
	ble _08003CEE\n\
	b _08004046\n\
_08003CEE:\n\
	cmp r0, 0\n\
	beq _08003CF4\n\
	b _08004046\n\
_08003CF4:\n\
	movs r4, 0\n\
	cmp r4, r6\n\
	blt _08003CFC\n\
	b _08004046\n\
_08003CFC:\n\
	movs r1, 0x8\n\
	negs r1, r1\n\
	mov r9, r1\n\
	movs r2, 0x7\n\
	mov r8, r2\n\
	mov r10, r5\n\
_08003D08:\n\
	ldr r3, [sp]\n\
	adds r0, r3, 0\n\
	mov r1, r9\n\
	ands r0, r1\n\
	mov r1, r12\n\
	muls r1, r0\n\
	adds r0, r3, 0\n\
	mov r2, r8\n\
	ands r0, r2\n\
	orrs r1, r0\n\
	lsls r1, 2\n\
	adds r1, r4, r1\n\
	cmp r1, r6\n\
	bge _08003D34\n\
	adds r0, r5, r1\n\
	ldr r0, [r0]\n\
	mov r1, r10\n\
	str r0, [r1]\n\
	b _08003D38\n\
	.pool\n\
_08003D34:\n\
	mov r2, r10\n\
	str r7, [r2]\n\
_08003D38:\n\
	adds r3, 0x1\n\
	adds r2, r4, 0x4\n\
	adds r0, r3, 0\n\
	mov r1, r9\n\
	ands r0, r1\n\
	mov r1, r12\n\
	muls r1, r0\n\
	str r1, [sp, 0x4]\n\
	adds r0, r3, 0\n\
	mov r1, r8\n\
	ands r0, r1\n\
	ldr r1, [sp, 0x4]\n\
	orrs r1, r0\n\
	lsls r1, 2\n\
	adds r1, r4, r1\n\
	cmp r1, r6\n\
	bge _08003D64\n\
	adds r0, r5, r2\n\
	adds r1, r5, r1\n\
	ldr r1, [r1]\n\
	str r1, [r0]\n\
	b _08003D68\n\
_08003D64:\n\
	adds r0, r5, r2\n\
	str r7, [r0]\n\
_08003D68:\n\
	adds r3, 0x1\n\
	adds r2, r4, 0\n\
	adds r2, 0x8\n\
	adds r0, r3, 0\n\
	mov r1, r9\n\
	ands r0, r1\n\
	mov r1, r12\n\
	muls r1, r0\n\
	str r1, [sp, 0x4]\n\
	adds r0, r3, 0\n\
	mov r1, r8\n\
	ands r0, r1\n\
	ldr r1, [sp, 0x4]\n\
	orrs r1, r0\n\
	lsls r1, 2\n\
	adds r1, r4, r1\n\
	cmp r1, r6\n\
	bge _08003D96\n\
	adds r0, r5, r2\n\
	adds r1, r5, r1\n\
	ldr r1, [r1]\n\
	str r1, [r0]\n\
	b _08003D9A\n\
_08003D96:\n\
	adds r0, r5, r2\n\
	str r7, [r0]\n\
_08003D9A:\n\
	adds r3, 0x1\n\
	adds r2, r4, 0\n\
	adds r2, 0xC\n\
	adds r0, r3, 0\n\
	mov r1, r9\n\
	ands r0, r1\n\
	mov r1, r12\n\
	muls r1, r0\n\
	str r1, [sp, 0x4]\n\
	adds r0, r3, 0\n\
	mov r1, r8\n\
	ands r0, r1\n\
	ldr r1, [sp, 0x4]\n\
	orrs r1, r0\n\
	lsls r1, 2\n\
	adds r1, r4, r1\n\
	cmp r1, r6\n\
	bge _08003DC8\n\
	adds r0, r5, r2\n\
	adds r1, r5, r1\n\
	ldr r1, [r1]\n\
	str r1, [r0]\n\
	b _08003DCC\n\
_08003DC8:\n\
	adds r0, r5, r2\n\
	str r7, [r0]\n\
_08003DCC:\n\
	adds r3, 0x1\n\
	adds r2, r4, 0\n\
	adds r2, 0x10\n\
	adds r0, r3, 0\n\
	mov r1, r9\n\
	ands r0, r1\n\
	mov r1, r12\n\
	muls r1, r0\n\
	str r1, [sp, 0x4]\n\
	adds r0, r3, 0\n\
	mov r1, r8\n\
	ands r0, r1\n\
	ldr r1, [sp, 0x4]\n\
	orrs r1, r0\n\
	lsls r1, 2\n\
	adds r1, r4, r1\n\
	cmp r1, r6\n\
	bge _08003DFA\n\
	adds r0, r5, r2\n\
	adds r1, r5, r1\n\
	ldr r1, [r1]\n\
	str r1, [r0]\n\
	b _08003DFE\n\
_08003DFA:\n\
	adds r0, r5, r2\n\
	str r7, [r0]\n\
_08003DFE:\n\
	adds r3, 0x1\n\
	adds r2, r4, 0\n\
	adds r2, 0x14\n\
	adds r0, r3, 0\n\
	mov r1, r9\n\
	ands r0, r1\n\
	mov r1, r12\n\
	muls r1, r0\n\
	str r1, [sp, 0x4]\n\
	adds r0, r3, 0\n\
	mov r1, r8\n\
	ands r0, r1\n\
	ldr r1, [sp, 0x4]\n\
	orrs r1, r0\n\
	lsls r1, 2\n\
	adds r1, r4, r1\n\
	cmp r1, r6\n\
	bge _08003E2C\n\
	adds r0, r5, r2\n\
	adds r1, r5, r1\n\
	ldr r1, [r1]\n\
	str r1, [r0]\n\
	b _08003E30\n\
_08003E2C:\n\
	adds r0, r5, r2\n\
	str r7, [r0]\n\
_08003E30:\n\
	adds r3, 0x1\n\
	adds r2, r4, 0\n\
	adds r2, 0x18\n\
	adds r0, r3, 0\n\
	mov r1, r9\n\
	ands r0, r1\n\
	mov r1, r12\n\
	muls r1, r0\n\
	str r1, [sp, 0x4]\n\
	adds r0, r3, 0\n\
	mov r1, r8\n\
	ands r0, r1\n\
	ldr r1, [sp, 0x4]\n\
	orrs r1, r0\n\
	lsls r1, 2\n\
	adds r1, r4, r1\n\
	cmp r1, r6\n\
	bge _08003E5E\n\
	adds r0, r5, r2\n\
	adds r1, r5, r1\n\
	ldr r1, [r1]\n\
	str r1, [r0]\n\
	b _08003E62\n\
_08003E5E:\n\
	adds r0, r5, r2\n\
	str r7, [r0]\n\
_08003E62:\n\
	adds r3, 0x1\n\
	adds r2, r4, 0\n\
	adds r2, 0x1C\n\
	adds r0, r3, 0\n\
	mov r1, r9\n\
	ands r0, r1\n\
	mov r1, r12\n\
	muls r1, r0\n\
	adds r0, r1, 0\n\
	mov r1, r8\n\
	ands r3, r1\n\
	orrs r0, r3\n\
	lsls r0, 2\n\
	adds r1, r4, r0\n\
	cmp r1, r6\n\
	bge _08003E8C\n\
	adds r0, r5, r2\n\
	adds r1, r5, r1\n\
	ldr r1, [r1]\n\
	str r1, [r0]\n\
	b _08003E90\n\
_08003E8C:\n\
	adds r0, r5, r2\n\
	str r7, [r0]\n\
_08003E90:\n\
	movs r2, 0x20\n\
	add r10, r2\n\
	adds r4, 0x20\n\
	cmp r4, r6\n\
	bge _08003E9C\n\
	b _08003D08\n\
_08003E9C:\n\
	b _08004046\n\
_08003E9E:\n\
	subs r0, r6, 0x4\n\
	adds r5, r0\n\
	movs r4, 0\n\
	cmp r4, r6\n\
	blt _08003EAA\n\
	b _08004046\n\
_08003EAA:\n\
	movs r0, 0x8\n\
	negs r0, r0\n\
	mov r9, r0\n\
	movs r1, 0x7\n\
	mov r8, r1\n\
	mov r10, r5\n\
_08003EB6:\n\
	ldr r3, [sp]\n\
	adds r0, r3, 0\n\
	mov r2, r9\n\
	ands r0, r2\n\
	mov r1, r12\n\
	muls r1, r0\n\
	adds r0, r3, 0\n\
	mov r2, r8\n\
	ands r0, r2\n\
	orrs r1, r0\n\
	lsls r1, 2\n\
	adds r1, r4, r1\n\
	cmp r1, r6\n\
	bge _08003EDC\n\
	subs r0, r5, r1\n\
	ldr r0, [r0]\n\
	mov r1, r10\n\
	str r0, [r1]\n\
	b _08003EE0\n\
_08003EDC:\n\
	mov r2, r10\n\
	str r7, [r2]\n\
_08003EE0:\n\
	adds r3, 0x1\n\
	adds r2, r4, 0x4\n\
	adds r0, r3, 0\n\
	mov r1, r9\n\
	ands r0, r1\n\
	mov r1, r12\n\
	muls r1, r0\n\
	str r1, [sp, 0x4]\n\
	adds r0, r3, 0\n\
	mov r1, r8\n\
	ands r0, r1\n\
	ldr r1, [sp, 0x4]\n\
	orrs r1, r0\n\
	lsls r1, 2\n\
	adds r1, r4, r1\n\
	cmp r1, r6\n\
	bge _08003F0C\n\
	subs r0, r5, r2\n\
	subs r1, r5, r1\n\
	ldr r1, [r1]\n\
	str r1, [r0]\n\
	b _08003F10\n\
_08003F0C:\n\
	subs r0, r5, r2\n\
	str r7, [r0]\n\
_08003F10:\n\
	adds r3, 0x1\n\
	adds r2, r4, 0\n\
	adds r2, 0x8\n\
	adds r0, r3, 0\n\
	mov r1, r9\n\
	ands r0, r1\n\
	mov r1, r12\n\
	muls r1, r0\n\
	str r1, [sp, 0x4]\n\
	adds r0, r3, 0\n\
	mov r1, r8\n\
	ands r0, r1\n\
	ldr r1, [sp, 0x4]\n\
	orrs r1, r0\n\
	lsls r1, 2\n\
	adds r1, r4, r1\n\
	cmp r1, r6\n\
	bge _08003F3E\n\
	subs r0, r5, r2\n\
	subs r1, r5, r1\n\
	ldr r1, [r1]\n\
	str r1, [r0]\n\
	b _08003F42\n\
_08003F3E:\n\
	subs r0, r5, r2\n\
	str r7, [r0]\n\
_08003F42:\n\
	adds r3, 0x1\n\
	adds r2, r4, 0\n\
	adds r2, 0xC\n\
	adds r0, r3, 0\n\
	mov r1, r9\n\
	ands r0, r1\n\
	mov r1, r12\n\
	muls r1, r0\n\
	str r1, [sp, 0x4]\n\
	adds r0, r3, 0\n\
	mov r1, r8\n\
	ands r0, r1\n\
	ldr r1, [sp, 0x4]\n\
	orrs r1, r0\n\
	lsls r1, 2\n\
	adds r1, r4, r1\n\
	cmp r1, r6\n\
	bge _08003F70\n\
	subs r0, r5, r2\n\
	subs r1, r5, r1\n\
	ldr r1, [r1]\n\
	str r1, [r0]\n\
	b _08003F74\n\
_08003F70:\n\
	subs r0, r5, r2\n\
	str r7, [r0]\n\
_08003F74:\n\
	adds r3, 0x1\n\
	adds r2, r4, 0\n\
	adds r2, 0x10\n\
	adds r0, r3, 0\n\
	mov r1, r9\n\
	ands r0, r1\n\
	mov r1, r12\n\
	muls r1, r0\n\
	str r1, [sp, 0x4]\n\
	adds r0, r3, 0\n\
	mov r1, r8\n\
	ands r0, r1\n\
	ldr r1, [sp, 0x4]\n\
	orrs r1, r0\n\
	lsls r1, 2\n\
	adds r1, r4, r1\n\
	cmp r1, r6\n\
	bge _08003FA2\n\
	subs r0, r5, r2\n\
	subs r1, r5, r1\n\
	ldr r1, [r1]\n\
	str r1, [r0]\n\
	b _08003FA6\n\
_08003FA2:\n\
	subs r0, r5, r2\n\
	str r7, [r0]\n\
_08003FA6:\n\
	adds r3, 0x1\n\
	adds r2, r4, 0\n\
	adds r2, 0x14\n\
	adds r0, r3, 0\n\
	mov r1, r9\n\
	ands r0, r1\n\
	mov r1, r12\n\
	muls r1, r0\n\
	str r1, [sp, 0x4]\n\
	adds r0, r3, 0\n\
	mov r1, r8\n\
	ands r0, r1\n\
	ldr r1, [sp, 0x4]\n\
	orrs r1, r0\n\
	lsls r1, 2\n\
	adds r1, r4, r1\n\
	cmp r1, r6\n\
	bge _08003FD4\n\
	subs r0, r5, r2\n\
	subs r1, r5, r1\n\
	ldr r1, [r1]\n\
	str r1, [r0]\n\
	b _08003FD8\n\
_08003FD4:\n\
	subs r0, r5, r2\n\
	str r7, [r0]\n\
_08003FD8:\n\
	adds r3, 0x1\n\
	adds r2, r4, 0\n\
	adds r2, 0x18\n\
	adds r0, r3, 0\n\
	mov r1, r9\n\
	ands r0, r1\n\
	mov r1, r12\n\
	muls r1, r0\n\
	str r1, [sp, 0x4]\n\
	adds r0, r3, 0\n\
	mov r1, r8\n\
	ands r0, r1\n\
	ldr r1, [sp, 0x4]\n\
	orrs r1, r0\n\
	lsls r1, 2\n\
	adds r1, r4, r1\n\
	cmp r1, r6\n\
	bge _08004006\n\
	subs r0, r5, r2\n\
	subs r1, r5, r1\n\
	ldr r1, [r1]\n\
	str r1, [r0]\n\
	b _0800400A\n\
_08004006:\n\
	subs r0, r5, r2\n\
	str r7, [r0]\n\
_0800400A:\n\
	adds r3, 0x1\n\
	adds r2, r4, 0\n\
	adds r2, 0x1C\n\
	adds r0, r3, 0\n\
	mov r1, r9\n\
	ands r0, r1\n\
	mov r1, r12\n\
	muls r1, r0\n\
	adds r0, r1, 0\n\
	mov r1, r8\n\
	ands r3, r1\n\
	orrs r0, r3\n\
	lsls r0, 2\n\
	adds r1, r4, r0\n\
	cmp r1, r6\n\
	bge _08004034\n\
	subs r0, r5, r2\n\
	subs r1, r5, r1\n\
	ldr r1, [r1]\n\
	str r1, [r0]\n\
	b _08004038\n\
_08004034:\n\
	subs r0, r5, r2\n\
	str r7, [r0]\n\
_08004038:\n\
	movs r2, 0x20\n\
	negs r2, r2\n\
	add r10, r2\n\
	adds r4, 0x20\n\
	cmp r4, r6\n\
	bge _08004046\n\
	b _08003EB6\n\
_08004046:\n\
	add sp, 0x8\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
        .syntax divided");
}
#endif // NONMATCHING

void CallWindowFunction(u8 windowId, void ( *func)(u8, u8, u8, u8, u8, u8))
{
    struct WindowTemplate window = gWindows[windowId].window;
    func(window.priority, window.tilemapLeft, window.tilemapTop, window.width, window.height, window.paletteNum);
}

bool8 SetWindowAttribute(u8 windowId, u8 attributeId, u32 value)
{
    switch (attributeId)
    {
    case WINDOW_TILEMAP_LEFT:
        gWindows[windowId].window.tilemapLeft = value;
        return FALSE;
    case WINDOW_TILEMAP_TOP:
        gWindows[windowId].window.tilemapTop = value;
        return FALSE;
    case WINDOW_PALETTE_NUM:
        gWindows[windowId].window.paletteNum = value;
        return FALSE;
    case WINDOW_BASE_BLOCK:
        gWindows[windowId].window.baseBlock = value;
        return FALSE;
    case WINDOW_TILE_DATA:
        gWindows[windowId].tileData = (u8*)(value);
        return TRUE;
    case WINDOW_PRIORITY:
    case WINDOW_WIDTH:
    case WINDOW_HEIGHT:
    default:
        return TRUE;
    }
}

u32 GetWindowAttribute(u8 windowId, u8 attributeId)
{
    switch (attributeId)
    {
    case WINDOW_PRIORITY:
        return gWindows[windowId].window.priority;
    case WINDOW_TILEMAP_LEFT:
        return gWindows[windowId].window.tilemapLeft;
    case WINDOW_TILEMAP_TOP:
        return gWindows[windowId].window.tilemapTop;
    case WINDOW_WIDTH:
        return gWindows[windowId].window.width;
    case WINDOW_HEIGHT:
        return gWindows[windowId].window.height;
    case WINDOW_PALETTE_NUM:
        return gWindows[windowId].window.paletteNum;
    case WINDOW_BASE_BLOCK:
        return gWindows[windowId].window.baseBlock;
    case WINDOW_TILE_DATA:
        return (u32)(gWindows[windowId].tileData);
    default:
        return 0;
    }
}

static u8 GetNumActiveWindowsOnBg(u8 bgId)
{
    u8 windowsNum = 0;
    s32 i;
    for (i = 0; i < WINDOWS_MAX; i++)
    {
        if (gWindows[i].window.priority == bgId)
            windowsNum++;
    }
    return windowsNum;
}

static void nullsub_9(void)
{

}

u16 AddWindow8Bit(struct WindowTemplate *template)
{
    u16 windowId;
    u8* memAddress;
    u8 bgLayer;

    for (windowId = 0; windowId < 32; windowId++)
    {
        if (gWindows[windowId].window.priority == 0xFF)
            break;
    }
    if (windowId == WINDOWS_MAX)
        return 0xFF;
    bgLayer = template->priority;
    if (gUnknown_03002F70[bgLayer] == 0)
    {
        u16 attribute = GetBgAttribute(bgLayer, 8);
        if (attribute != 0xFFFF)
        {
            s32 i;
            memAddress = Alloc(attribute);
            if (memAddress == NULL)
                return 0xFF;
            for (i = 0; i < attribute; i++) // if we're going to zero out the memory anyway, why not call AllocZeroed?
                memAddress[i] = 0;
            gUnknown_03002F70[bgLayer] = memAddress;
            SetBgTilemapBuffer(bgLayer, memAddress);
        }
    }
    memAddress = Alloc((u16)(0x40 * (template->width * template->height)));
    if (memAddress == NULL)
    {
        if (GetNumActiveWindowsOnBg8Bit(bgLayer) == 0 && gUnknown_03002F70[bgLayer] != nullsub_9)
        {
            Free(gUnknown_03002F70[bgLayer]);
            gUnknown_03002F70[bgLayer] = NULL;
        }
        return 0xFF;
    }
    else
    {
        gWindows[windowId].tileData = memAddress;
        gWindows[windowId].window = *template;
        return windowId;
    }
}

void FillWindowPixelBuffer8Bit(u8 windowId, u8 fillValue)
{
    s32 i;
    s32 size;

    size = (u16)(0x40 * (gWindows[windowId].window.width * gWindows[windowId].window.height));
    for (i = 0; i < size; i++)
        gWindows[windowId].tileData[i] = fillValue;
}

void FillWindowPixelRect8Bit(u8 windowId, u8 fillValue, u16 x, u16 y, u16 width, u16 height)
{
    struct Bitmap pixelRect;

    pixelRect.pixels = gWindows[windowId].tileData;
    pixelRect.width = 8 * gWindows[windowId].window.width;
    pixelRect.height = 8 * gWindows[windowId].window.height;

    FillBitmapRect8Bit(&pixelRect, x, y, width, height, fillValue);
}

void BlitBitmapRectToWindow4BitTo8Bit(u8 windowId, u8 *pixels, u16 srcX, u16 srcY, u16 srcWidth, int srcHeight, u16 destX, u16 destY, u16 rectWidth, u16 rectHeight, u8 paletteNum)
{
    struct Bitmap sourceRect;
    struct Bitmap destRect;

    sourceRect.pixels = (u8*)pixels;
    sourceRect.width = srcWidth;
    sourceRect.height = srcHeight;

    destRect.pixels = gWindows[windowId].tileData;
    destRect.width = 8 * gWindows[windowId].window.width;
    destRect.height = 8 * gWindows[windowId].window.height;

    BlitBitmapRect4BitTo8Bit(&sourceRect, &destRect, srcX, srcY, destX, destY, rectWidth, rectHeight, 0, paletteNum);
}

void CopyWindowToVram8Bit(u8 windowId, u8 mode)
{
    sWindowPtr = &gWindows[windowId];
    sWindowSize = 0x40 * (sWindowPtr->window.width * sWindowPtr->window.height);

    switch (mode)
    {
        case 1:
            CopyBgTilemapBufferToVram(sWindowPtr->window.priority);
            break;
        case 2:
            LoadBgTiles(sWindowPtr->window.priority, sWindowPtr->tileData, sWindowSize, sWindowPtr->window.baseBlock);
            break;
        case 3:
            LoadBgTiles(sWindowPtr->window.priority, sWindowPtr->tileData, sWindowSize, sWindowPtr->window.baseBlock);
            CopyBgTilemapBufferToVram(sWindowPtr->window.priority);
            break;
    }
}

static u8 GetNumActiveWindowsOnBg8Bit(u8 bgId)
{
    u8 windowsNum = 0;
    s32 i;
    for (i = 0; i < WINDOWS_MAX; i++)
    {
        if (gWindows[i].window.priority == bgId)
            windowsNum++;
    }
    return windowsNum;
}
