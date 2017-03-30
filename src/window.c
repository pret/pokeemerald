#include "global.h"
#include "window.h"

extern u8 gUnknown_03002F60;
extern void* gUnknown_03002F70[];
extern u32 gUnneededFireRedVariable;
EWRAM_DATA struct Window gWindows[20];

extern void* GetBgTilemapBuffer(u8 bg);
extern int DummiedOutFireRedLeafGreenTileAllocFunc(int, int, int, int);
extern u16 GetBgAttribute(u8 bg, u8 attributeId);
extern void *AllocZeroed(u16 size);
extern void FreeAllWindowBuffers(void);
extern void SetBgTilemapBuffer(u8 bg, void *tilemap);
extern u8 GetNumActiveWindowsOnBg(u8 bgId);
extern void Free(void *pointer);
extern void CopyBgTilemapBufferToVram(u8 bg);
extern u8 LoadBgTiles(u8 bg, void *src, u16 size, u16 destOffset);
extern void WriteSequenceToBgTilemapBuffer(u8 bg, u16 firstTileNum, u8 x, u8 y, u8 width, u8 height, u8 paletteSlot, u16 tileNumDelta);
extern void FillBgTilemapBufferRect(u8 bg, u16 tileNum, u8 x, u8 y, u8 width, u8 height, u8 palette);
extern void BlitBitmapRect4Bit(struct Bitmap *src, struct Bitmap *dest, u16 srcX, u16 srcY, u16 destX, u16 destY, u16 width, u16 height, u8 colorKey);
extern void FillBitmapRect4Bit(struct Bitmap *surface, u16 x, u16 y, u16 width, u16 height, u8 fillValue);

void BlitBitmapRectToWindow(u8 windowId, const u8 *pixels, u16 srcX, u16 srcY, u16 srcWidth, int srcHeight, u16 destX, u16 destY, u16 rectWidth, u16 rectHeight);

extern const struct WindowTemplate gDummyWindowTemplate;

void nullsub_8(void)
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
        gWindows[i].window = gDummyWindowTemplate;
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
        
        allocatedTilemapBuffer = AllocZeroed(0x20 * (templates[i].width * templates[i].height));
        
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

u16 AddWindow(struct WindowTemplate *template)
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
    
    allocatedTilemapBuffer = AllocZeroed(0x20 * (template->width * template->height));
    
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
    
    gWindows[windowId].window = gDummyWindowTemplate;
    
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

void BlitBitmapRectToWindowWithColorKey(u8 windowId, const u8 *pixels, u16 srcX, u16 srcY, u16 srcWidth, int srcHeight, u16 destX, u16 destY, u16 rectWidth, u16 rectHeight, u8 colorKey)
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
