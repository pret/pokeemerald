#include "global.h"
#include "blit.h"

#define GET_PIXEL_POINTER_4BPP(pixels, x, y, widthTiles) \
    ((u8 *)((pixels) + (((x) >> 1) & 3) + (((x) >> 3) << 5) + ((((y) >> 3) * (widthTiles)) << 5) + ((u32)((y) << 29) >> 27)))

#define GET_PIXEL_POINTER_8BPP(pixels, x, y, widthTiles) \
    ((u8 *)((pixels) + ((x) & 7) + (((x) >> 3) << 6) + ((((y) >> 3) * (widthTiles)) << 6) + ((u32)((y) << 29) >> 26)))


void BlitBitmapRect4BitWithoutColorKey(const struct Bitmap *src, struct Bitmap *dst, u16 srcX, u16 srcY, u16 dstX, u16 dstY, u16 width, u16 height)
{
    BlitBitmapRect4Bit(src, dst, srcX, srcY, dstX, dstY, width, height, 0xFF);
}

void BlitBitmapRect4Bit(const struct Bitmap *src, struct Bitmap *dst, u16 srcX, u16 srcY, u16 dstX, u16 dstY, u16 width, u16 height, u8 colorKey)
{
    s32 xEnd;
    s32 yEnd;
    s32 multiplierSrcY;
    s32 multiplierDstY;
    s32 loopSrcY, loopDstY;
    s32 loopSrcX, loopDstX;
    s32 srcData;
    s32 toShift;
    const u8 *pixelsSrc;
    u8 *pixelsDst;

    if (dst->width - dstX < width)
        xEnd = dst->width - dstX + srcX;
    else
        xEnd = srcX + width;

    if (dst->height - dstY < height)
        yEnd = dst->height - dstY + srcY;
    else
        yEnd = height + srcY;

    multiplierSrcY = (src->width + (src->width & 7)) >> 3;
    multiplierDstY = (dst->width + (dst->width & 7)) >> 3;

    if (colorKey == 0xFF)
    {
        for (loopSrcY = srcY, loopDstY = dstY; loopSrcY < yEnd; loopSrcY++, loopDstY++)
        {
            for (loopSrcX = srcX, loopDstX = dstX; loopSrcX < xEnd; loopSrcX++, loopDstX++)
            {
                pixelsSrc = GET_PIXEL_POINTER_4BPP(src->pixels, loopSrcX, loopSrcY, multiplierSrcY);
                pixelsDst = GET_PIXEL_POINTER_4BPP(dst->pixels, loopDstX, loopDstY, multiplierDstY);

                srcData = ((*pixelsSrc >> ((loopSrcX & 1) * 4)) & 0xF);
                toShift = (loopDstX & 1) * 4;
                *pixelsDst = (srcData << toShift) | (*pixelsDst & (0xF0 >> (toShift)));
            }
        }
    }
    else
    {
        for (loopSrcY = srcY, loopDstY = dstY; loopSrcY < yEnd; loopSrcY++, loopDstY++)
        {
            for (loopSrcX = srcX, loopDstX = dstX; loopSrcX < xEnd; loopSrcX++, loopDstX++)
            {
                pixelsSrc = GET_PIXEL_POINTER_4BPP(src->pixels, loopSrcX, loopSrcY, multiplierSrcY);
                pixelsDst = GET_PIXEL_POINTER_4BPP(dst->pixels, loopDstX, loopDstY, multiplierDstY);

                srcData = ((*pixelsSrc >> ((loopSrcX & 1) * 4)) & 0xF);
                if (srcData != colorKey)
                {
                    toShift = ((loopDstX & 1) * 4);
                    *pixelsDst = (srcData << toShift) | (*pixelsDst & (0xF0 >> (toShift)));
                }
            }
        }
    }
}

void FillBitmapRect4Bit(struct Bitmap *surface, u16 x, u16 y, u16 width, u16 height, u8 fillValue)
{
    s32 xEnd;
    s32 yEnd;
    s32 multiplierY;
    s32 loopX, loopY;
    u8 toOrr1, toOrr2;

    xEnd = x + width;
    if (xEnd > surface->width)
        xEnd = surface->width;

    yEnd = y + height;
    if (yEnd > surface->height)
        yEnd = surface->height;

    multiplierY = (surface->width + (surface->width & 7)) >> 3;
    toOrr1 = fillValue << 4;
    toOrr2 = fillValue & 0xF;

    for (loopY = y; loopY < yEnd; loopY++)
    {
        for (loopX = x; loopX < xEnd; loopX++)
        {
            u8 *pixels = GET_PIXEL_POINTER_4BPP(surface->pixels, loopX, loopY, multiplierY);

            // This is just % 2 but with a shift.
            if ((loopX << 31) != 0)
                *pixels = toOrr1 | (*pixels & 0xF);
            else
                *pixels = toOrr2 | (*pixels & 0xF0);
        }
    }
}

void BlitBitmapRect4BitTo8Bit(const struct Bitmap *src, struct Bitmap *dst, u16 srcX, u16 srcY, u16 dstX, u16 dstY, u16 width, u16 height, u8 colorKey, u8 paletteOffset)
{
    s32 xEnd;
    s32 yEnd;
    s32 multiplierSrcY;
    s32 multiplierDstY;
    s32 loopSrcY, loopDstY;
    s32 loopSrcX, loopDstX;
    const u8 *pixelsSrc;
    u8 *pixelsDst;
    u8 colorKeyBits;

    paletteOffset <<= 4;
    colorKeyBits = (colorKey << 4);

    if (dst->width - dstX < width)
        xEnd = (dst->width - dstX) + srcX;
    else
        xEnd = width + srcX;

    if (dst->height - dstY < height)
        yEnd = (srcY + dst->height) - dstY;
    else
        yEnd = srcY + height;

    multiplierSrcY = (src->width + (src->width & 7)) >> 3;
    multiplierDstY = (dst->width + (dst->width & 7)) >> 3;

    if (colorKey == 0xFF)
    {
        for (loopSrcY = srcY, loopDstY = dstY; loopSrcY < yEnd; loopSrcY++, loopDstY++)
        {
            pixelsSrc = GET_PIXEL_POINTER_4BPP(src->pixels, srcX, loopSrcY, multiplierSrcY);
            for (loopSrcX = srcX, loopDstX = dstX; loopSrcX < xEnd; loopSrcX++, loopDstX++)
            {
                pixelsDst = GET_PIXEL_POINTER_8BPP(dst->pixels, loopDstX, loopDstY, multiplierDstY);
                if (loopSrcX & 1)
                {
                    *pixelsDst = paletteOffset + (*pixelsSrc >> 4);
                }
                else
                {
                    pixelsSrc = GET_PIXEL_POINTER_4BPP(src->pixels, loopSrcX, loopSrcY, multiplierSrcY);
                    *pixelsDst = paletteOffset + (*pixelsSrc & 0xF);
                }
            }
        }
    }
    else
    {
        for (loopSrcY = srcY, loopDstY = dstY; loopSrcY < yEnd; loopSrcY++, loopDstY++)
        {
            pixelsSrc = GET_PIXEL_POINTER_4BPP(src->pixels, srcX, loopSrcY, multiplierSrcY);
            for (loopSrcX = srcX, loopDstX = dstX; loopSrcX < xEnd; loopSrcX++, loopDstX++)
            {
                if (loopSrcX & 1)
                {
                    if ((*pixelsSrc & 0xF0) != colorKeyBits)
                    {
                        pixelsDst = GET_PIXEL_POINTER_8BPP(dst->pixels, loopDstX, loopDstY, multiplierDstY);
                        *pixelsDst = paletteOffset + (*pixelsSrc >> 4);
                    }
                }
                else
                {
                    pixelsSrc = GET_PIXEL_POINTER_4BPP(src->pixels, loopSrcX, loopSrcY, multiplierSrcY);
                    if ((*pixelsSrc & 0xF) != colorKey)
                    {
                        pixelsDst = GET_PIXEL_POINTER_8BPP(dst->pixels, loopDstX, loopDstY, multiplierDstY);
                        *pixelsDst = paletteOffset + (*pixelsSrc & 0xF);
                    }
                }
            }
        }
    }
}

void FillBitmapRect8Bit(struct Bitmap *surface, u16 x, u16 y, u16 width, u16 height, u8 fillValue)
{
    s32 xEnd;
    s32 yEnd;
    s32 multiplierY;
    s32 loopX, loopY;

    xEnd = x + width;
    if (xEnd > surface->width)
        xEnd = surface->width;

    yEnd = y + height;
    if (yEnd > surface->height)
        yEnd = surface->height;

    multiplierY = (surface->width + (surface->width & 7)) >> 3;

    for (loopY = y; loopY < yEnd; loopY++)
    {
        for (loopX = x; loopX < xEnd; loopX++)
        {
            u8 *pixels = GET_PIXEL_POINTER_8BPP(surface->pixels, loopX, loopY, multiplierY);
            *pixels = fillValue;
        }
    }
}
