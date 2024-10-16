#include "global.h"
#include "image_processing_effects.h"
#include "contest_painting.h"
#include "constants/rgb.h"

// IWRAM common
COMMON_DATA u8 gCanvasColumnStart = 0;
COMMON_DATA u16 *gCanvasPixels = NULL;
COMMON_DATA u8 gCanvasRowEnd = 0;
COMMON_DATA u8 gCanvasHeight = 0;
COMMON_DATA u8 gCanvasColumnEnd = 0;
COMMON_DATA u8 gCanvasRowStart = 0;
COMMON_DATA u8 gCanvasMonPersonality = 0;
COMMON_DATA u8 gCanvasWidth = 0;
COMMON_DATA u16 *gCanvasPalette = NULL;
COMMON_DATA u16 gCanvasPaletteStart = 0;

static void ApplyImageEffect_Pointillism(void);
static void ApplyImageEffect_Blur(void);
static void ApplyImageEffect_BlackOutline(void);
static void ApplyImageEffect_Invert(void);
static void ApplyImageEffect_BlackAndWhite(void);
static void ApplyImageEffect_BlurRight(void);
static void ApplyImageEffect_BlurDown(void);
static void ApplyImageEffect_Shimmer(void);
static void ApplyImageEffect_Grayscale(void);
static void ApplyImageEffect_PersonalityColor(u8);
static void ApplyImageEffect_RedChannelGrayscale(u8);
static void ApplyImageEffect_RedChannelGrayscaleHighlight(u8);
static void AddPointillismPoints(u16);
static u16 ConvertColorToGrayscale(u16 *);
static u16 QuantizePixel_Blur(u16 *, u16 *, u16 *);
static u16 QuantizePixel_PersonalityColor(u16 *, u8);
static u16 QuantizePixel_BlackAndWhite(u16 *);
static u16 QuantizePixel_BlackOutline(u16 *, u16 *);
static u16 QuantizePixel_Invert(u16 *);
static u16 QuantizePixel_BlurHard(u16 *, u16 *, u16 *);
static u16 QuantizePixel_MotionBlur(u16 *, u16 *);
static u16 GetColorFromPersonality(u8);
static void QuantizePalette_Standard(bool8);
static void SetPresetPalette_PrimaryColors(void);
static void QuantizePalette_PrimaryColors(void);
static void SetPresetPalette_Grayscale(void);
static void QuantizePalette_Grayscale(void);
static void SetPresetPalette_GrayscaleSmall(void);
static void QuantizePalette_GrayscaleSmall(void);
static void SetPresetPalette_BlackAndWhite(void);
static void QuantizePalette_BlackAndWhite(void);
static u16 QuantizePixel_Standard(u16 *);
static u16 QuantizePixel_GrayscaleSmall(u16 *);
static u16 QuantizePixel_Grayscale(u16 *);
static u16 QuantizePixel_PrimaryColors(u16 *);

#define MAX_DIMENSION 64

#include "data/pointillism_points.h"

void ApplyImageProcessingEffects(struct ImageProcessingContext *context)
{
    gCanvasPixels = context->canvasPixels;
    gCanvasMonPersonality = context->personality;
    gCanvasColumnStart = context->columnStart;
    gCanvasRowStart = context->rowStart;
    gCanvasColumnEnd = context->columnEnd;
    gCanvasRowEnd = context->rowEnd;
    gCanvasWidth = context->canvasWidth;
    gCanvasHeight = context->canvasHeight;

    switch (context->effect)
    {
    case IMAGE_EFFECT_POINTILLISM:
        ApplyImageEffect_Pointillism();
        break;
    case IMAGE_EFFECT_BLUR:
        ApplyImageEffect_Blur();
        break;
    case IMAGE_EFFECT_OUTLINE_COLORED:
        ApplyImageEffect_BlackOutline();
        ApplyImageEffect_PersonalityColor(gCanvasMonPersonality);
        break;
    case IMAGE_EFFECT_INVERT_BLACK_WHITE:
        ApplyImageEffect_BlackOutline();
        ApplyImageEffect_Invert();
        ApplyImageEffect_BlackAndWhite();
    case IMAGE_EFFECT_INVERT:
        ApplyImageEffect_Invert();
        break;
    case IMAGE_EFFECT_THICK_BLACK_WHITE:
        ApplyImageEffect_BlackOutline();
        ApplyImageEffect_BlurRight();
        ApplyImageEffect_BlurRight();
        ApplyImageEffect_BlurDown();
        ApplyImageEffect_BlackAndWhite();
        break;
    case IMAGE_EFFECT_SHIMMER:
        ApplyImageEffect_Shimmer();
        break;
    case IMAGE_EFFECT_OUTLINE:
        ApplyImageEffect_BlackOutline();
        break;
    case IMAGE_EFFECT_BLUR_RIGHT:
        ApplyImageEffect_BlurRight();
        break;
    case IMAGE_EFFECT_BLUR_DOWN:
        ApplyImageEffect_BlurDown();
        break;
    case IMAGE_EFFECT_GRAYSCALE_LIGHT:
        ApplyImageEffect_Grayscale();
        ApplyImageEffect_RedChannelGrayscale(3);
        break;
    case IMAGE_EFFECT_CHARCOAL:
        ApplyImageEffect_BlackOutline();
        ApplyImageEffect_BlurRight();
        ApplyImageEffect_BlurDown();
        ApplyImageEffect_BlackAndWhite();
        ApplyImageEffect_Blur();
        ApplyImageEffect_Blur();
        ApplyImageEffect_RedChannelGrayscale(2);
        ApplyImageEffect_RedChannelGrayscaleHighlight(4);
        break;
    }
}

static void ApplyImageEffect_RedChannelGrayscale(u8 delta)
{
    u8 i, j;

    for (j = 0; j < gCanvasRowEnd; j++)
    {
        u16 *pixelRow = &gCanvasPixels[(gCanvasRowStart + j) * gCanvasWidth];
        u16 *pixel = &pixelRow[gCanvasColumnStart];
        for (i = 0; i < gCanvasColumnEnd; i++, pixel++)
        {
            if (!IS_ALPHA(*pixel))
            {
                // Gets the grayscale value, based on the pixel's red channel.
                // Also adds a delta to skew lighter or darker.
                u8 grayValue = (*pixel & RGB_RED);
                grayValue += delta;
                if (grayValue > 31)
                    grayValue = 31;

                *pixel = RGB2(grayValue, grayValue, grayValue);
            }
        }
    }
}

static void ApplyImageEffect_RedChannelGrayscaleHighlight(u8 highlight)
{
    u8 i, j;

    for (j = 0; j < gCanvasRowEnd; j++)
    {
        u16 *pixelRow = &gCanvasPixels[(gCanvasRowStart + j) * gCanvasWidth];
        u16 *pixel = &pixelRow[gCanvasColumnStart];
        for (i = 0; i < gCanvasColumnEnd; i++, pixel++)
        {
            if (!IS_ALPHA(*pixel))
            {
                u8 grayValue = (*pixel & RGB_RED);
                if (grayValue > 31 - highlight)
                    grayValue = 31 - (highlight >> 1);

                *pixel = RGB2(grayValue, grayValue, grayValue);
            }
        }
    }
}

static void ApplyImageEffect_Pointillism(void)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sPointillismPoints); i++)
        AddPointillismPoints(i);
}

static void ApplyImageEffect_Grayscale(void)
{
    u8 i, j;

    for (j = 0; j < gCanvasRowEnd; j++)
    {
        u16 *pixelRow = &gCanvasPixels[(gCanvasRowStart + j) * gCanvasWidth];
        u16 *pixel = &pixelRow[gCanvasColumnStart];
        for (i = 0; i < gCanvasColumnEnd; i++, pixel++)
        {
            if (!IS_ALPHA(*pixel))
                *pixel = ConvertColorToGrayscale(pixel);
        }
    }
}

static void ApplyImageEffect_Blur(void)
{
    u8 i, j;

    for (i = 0; i < gCanvasColumnEnd; i++)
    {
        u16 *pixelRow = &gCanvasPixels[gCanvasRowStart * gCanvasWidth];
        u16 *pixel = &pixelRow[gCanvasColumnStart + i];
        u16 prevPixel = *pixel;

        j = 1;
        pixel += gCanvasWidth;
        while (j < gCanvasRowEnd - 1)
        {
            if (!IS_ALPHA(*pixel))
            {
                *pixel = QuantizePixel_Blur(&prevPixel, pixel, pixel + gCanvasWidth);
                prevPixel = *pixel;
            }

            j++;
            pixel += gCanvasWidth;
        }
    }
}

static void ApplyImageEffect_PersonalityColor(u8 personality)
{
    u8 i, j;

    for (j = 0; j < gCanvasRowEnd; j++)
    {
        u16 *pixelRow = &gCanvasPixels[(gCanvasRowStart + j) * gCanvasWidth];
        u16 *pixel = &pixelRow[gCanvasColumnStart];
        for (i = 0; i < gCanvasColumnEnd; i++, pixel++)
        {
            if (!IS_ALPHA(*pixel))
                *pixel = QuantizePixel_PersonalityColor(pixel, personality);
        }
    }
}

static void ApplyImageEffect_BlackAndWhite(void)
{
    u8 i, j;

    for (j = 0; j < gCanvasRowEnd; j++)
    {
        u16 *pixelRow = &gCanvasPixels[(gCanvasRowStart + j) * gCanvasWidth];
        u16 *pixel = &pixelRow[gCanvasColumnStart];
        for (i = 0; i < gCanvasColumnEnd; i++, pixel++)
        {
            if (!IS_ALPHA(*pixel))
                *pixel = QuantizePixel_BlackAndWhite(pixel);
        }
    }
}

static void ApplyImageEffect_BlackOutline(void)
{
    u8 i, j;
    u16 *pixel;

    // Handle top row of pixels first.
    for (j = 0; j < gCanvasRowEnd; j++)
    {
        u16 *pixelRow = &gCanvasPixels[(gCanvasRowStart + j) * gCanvasWidth];
        pixel = &pixelRow[gCanvasColumnStart];
        *pixel = QuantizePixel_BlackOutline(pixel, pixel + 1);
        for (i = 1, pixel++; i < gCanvasColumnEnd - 1; i++, pixel++)
        {
            *pixel = QuantizePixel_BlackOutline(pixel, pixel + 1);
            *pixel = QuantizePixel_BlackOutline(pixel, pixel - 1);
        }

        *pixel = QuantizePixel_BlackOutline(pixel, pixel - 1);
    }

    // Handle each column from left to right.
    for (i = 0; i < gCanvasColumnEnd; i++)
    {
        u16 *pixelRow = &gCanvasPixels[gCanvasRowStart * gCanvasWidth];
        pixel = &pixelRow[gCanvasColumnStart + i];
        *pixel = QuantizePixel_BlackOutline(pixel, pixel + gCanvasWidth);
        for (j = 1, pixel += gCanvasWidth; j < gCanvasRowEnd - 1; j++, pixel += gCanvasWidth)
        {
            *pixel = QuantizePixel_BlackOutline(pixel, pixel + gCanvasWidth);
            *pixel = QuantizePixel_BlackOutline(pixel, pixel - gCanvasWidth);
        }

        *pixel = QuantizePixel_BlackOutline(pixel, pixel - gCanvasWidth);
    }
}

static void ApplyImageEffect_Invert(void)
{
    u8 i, j;

    for (j = 0; j < gCanvasRowEnd; j++)
    {
        u16 *pixelRow = &gCanvasPixels[(gCanvasRowStart + j) * gCanvasWidth];
        u16 *pixel = &pixelRow[gCanvasColumnStart];
        for (i = 0; i < gCanvasColumnEnd; i++, pixel++)
        {
            if (!IS_ALPHA(*pixel))
                *pixel = QuantizePixel_Invert(pixel);
        }
    }
}

static void ApplyImageEffect_Shimmer(void)
{
    u8 i, j;
    u16 *pixel;
    u16 prevPixel;

    // First, invert all of the colors.
    pixel = gCanvasPixels;
    for (i = 0; i < MAX_DIMENSION; i++)
    {
        for (j = 0; j < MAX_DIMENSION; j++, pixel++)
        {
            if (!IS_ALPHA(*pixel))
                *pixel = QuantizePixel_Invert(pixel);
        }
    }

    // Blur the pixels twice.
    for (j = 0; j < MAX_DIMENSION; j++)
    {
        pixel = &gCanvasPixels[j];
        prevPixel = *pixel;
        *pixel = RGB_ALPHA;
        for (i = 1, pixel += MAX_DIMENSION; i < MAX_DIMENSION - 1; i++, pixel += MAX_DIMENSION)
        {
            if (!IS_ALPHA(*pixel))
            {
                *pixel = QuantizePixel_BlurHard(&prevPixel, pixel, pixel + MAX_DIMENSION);
                prevPixel = *pixel;
            }
        }

        *pixel = RGB_ALPHA;
        pixel = &gCanvasPixels[j];
        prevPixel = *pixel;
        *pixel = RGB_ALPHA;
        for (i = 1, pixel += MAX_DIMENSION; i < MAX_DIMENSION - 1; i++, pixel += MAX_DIMENSION)
        {
            if (!IS_ALPHA(*pixel))
            {
                *pixel = QuantizePixel_BlurHard(&prevPixel, pixel, pixel + MAX_DIMENSION);
                prevPixel = *pixel;
            }
        }

        *pixel = RGB_ALPHA;
    }

    // Finally, invert colors back to the original color space.
    // The above blur causes the outline areas to darken, which makes
    // this inversion give the effect of light outlines.
    pixel = gCanvasPixels;
    for (i = 0; i < MAX_DIMENSION; i++)
    {
        for (j = 0; j < MAX_DIMENSION; j++, pixel++)
        {
            if (!IS_ALPHA(*pixel))
                *pixel = QuantizePixel_Invert(pixel);
        }
    }
}

static void ApplyImageEffect_BlurRight(void)
{
    u8 i, j;

    for (j = 0; j < gCanvasRowEnd; j++)
    {
        u16 *pixelRow = &gCanvasPixels[(gCanvasRowStart + j) * gCanvasWidth];
        u16 *pixel = &pixelRow[gCanvasColumnStart];
        u16 prevPixel = *pixel;
        for (i = 1, pixel++; i < gCanvasColumnEnd - 1; i++, pixel++)
        {
            if (!IS_ALPHA(*pixel))
            {
                *pixel = QuantizePixel_MotionBlur(&prevPixel, pixel);
                prevPixel = *pixel;
            }
        }
    }
}

static void ApplyImageEffect_BlurDown(void)
{
    u8 i, j;

    for (i = 0; i < gCanvasColumnEnd; i++)
    {
        u16 *pixelRow = &gCanvasPixels[gCanvasRowStart * gCanvasWidth];
        u16 *pixel = &pixelRow[gCanvasColumnStart + i];
        u16 prevPixel = *pixel;
        for (j = 1, pixel += gCanvasWidth; j < gCanvasRowEnd - 1; j++, pixel += gCanvasWidth)
        {
            if (!IS_ALPHA(*pixel))
            {
                *pixel = QuantizePixel_MotionBlur(&prevPixel, pixel);
                prevPixel = *pixel;
            }
        }
    }
}

struct PointillismPoint
{
    u8 column;
    u8 row;
    u16 delta;
};

static void AddPointillismPoints(u16 point)
{
    u8 i;
    bool8 offsetDownLeft;
    u8 colorType;
    struct PointillismPoint points[6];

    points[0].column = sPointillismPoints[point][0];
    points[0].row = sPointillismPoints[point][1];
    points[0].delta = GET_POINT_DELTA(sPointillismPoints[point][2]);

    colorType = GET_POINT_COLOR_TYPE(sPointillismPoints[point][2]);
    offsetDownLeft = GET_POINT_OFFSET_DL(sPointillismPoints[point][2]);
    for (i = 1; i < points[0].delta; i++)
    {
        if (!offsetDownLeft)
        {
            points[i].column = points[0].column - i;
            points[i].row = points[0].row + i;
        }
        else
        {
            points[i].column = points[0].column + 1;
            points[i].row = points[0].row - 1;
        }

        if (points[i].column >= MAX_DIMENSION || points[i].row >= MAX_DIMENSION)
        {
            points[0].delta = i - 1;
            break;
        }

        points[i].delta = points[0].delta - i;
    }

    for (i = 0; i < points[0].delta; i++)
    {
        u16 *pixel = &gCanvasPixels[points[i].row * MAX_DIMENSION] + points[i].column;

        if (!IS_ALPHA(*pixel))
        {
            u16 red =   GET_R(*pixel);
            u16 green = GET_G(*pixel);
            u16 blue =  GET_B(*pixel);

            switch (colorType)
            {
            case 0:
            case 1:
                switch (GET_POINT_DELTA(sPointillismPoints[point][2]) % 3)
                {
                case 0:
                    if (red >= points[i].delta)
                        red -= points[i].delta;
                    else
                        red = 0;
                    break;
                case 1:
                    if (green >= points[i].delta)
                        green -= points[i].delta;
                    else
                        green = 0;
                    break;
                case 2:
                    if (blue >= points[i].delta)
                        blue -= points[i].delta;
                    else
                        blue = 0;
                    break;
                }
                break;
            case 2:
            case 3:
                red += points[i].delta;
                green += points[i].delta;
                blue += points[i].delta;
                if (red > 31)
                    red = 31;
                if (green > 31)
                    green = 31;
                if (blue > 31)
                    blue = 31;
                break;
            }

            *pixel = RGB2(red, green, blue);
        }
    }
}

static u16 ConvertColorToGrayscale(u16 *color)
{
    s32 clr = *color;
    s32 r = GET_R(clr);
    s32 g = GET_G(clr);
    s32 b = GET_B(clr);
    s32 gray = (r * Q_8_8(0.3) + g * Q_8_8(0.59) + b * Q_8_8(0.1133)) >> 8;
    return RGB2(gray, gray, gray);
}

// The dark colors are the colored edges of the Cool painting effect.
// Everything else is white.
static u16 QuantizePixel_PersonalityColor(u16 *color, u8 personality)
{
    u16 red =   GET_R(*color);
    u16 green = GET_G(*color);
    u16 blue =  GET_B(*color);

    if (red < 17 && green < 17 && blue < 17)
        return GetColorFromPersonality(personality);
    else
        return RGB_WHITE;
}

// Based on the given value, which comes from the first 8 bits of
// the mon's personality value, return a color.
static u16 GetColorFromPersonality(u8 personality)
{
    u16 red =   0;
    u16 green = 0;
    u16 blue =  0;
    u8 strength = (personality / 6) % 3;
    u8 colorType = personality % 6;

    switch (colorType)
    {
    case 0:
        // Teal color
        green = 21 - strength;
        blue = green;
        red = 0;
        break;
    case 1:
        // Yellow color
        blue = 0;
        red = 21 - strength;
        green = red;
        break;
    case 2:
        // Purple color
        blue = 21 - strength;
        green = 0;
        red = blue;
        break;
    case 3:
        // Red color
        blue = 0;
        green = 0;
        red = 23 - strength;
        break;
    case 4:
        // Blue color
        blue = 23 - strength;
        green = 0;
        red = 0;
        break;
    case 5:
        // Green color
        blue = 0;
        green = 23 - strength;
        red = 0;
        break;
    }

    return RGB2(red, green, blue);
}

static u16 QuantizePixel_BlackAndWhite(u16 *color)
{
    u16 red =   GET_R(*color);
    u16 green = GET_G(*color);
    u16 blue =  GET_B(*color);

    if (red < 17 && green < 17 && blue < 17)
        return RGB_BLACK;
    else
        return RGB_WHITE;
}

static u16 QuantizePixel_BlackOutline(u16 *pixelA, u16 *pixelB)
{
    if (*pixelA != RGB_BLACK)
    {
        if (IS_ALPHA(*pixelA))
            return RGB_ALPHA;
        if (IS_ALPHA(*pixelB))
            return RGB_BLACK;

        return *pixelA;
    }

    return RGB_BLACK;
}

static u16 QuantizePixel_Invert(u16 *color)
{
    u16 red =   GET_R(*color);
    u16 green = GET_G(*color);
    u16 blue =  GET_B(*color);

    red   = 31 - red;
    green = 31 - green;
    blue  = 31 - blue;

    return RGB2(red, green, blue);
}

static u16 QuantizePixel_MotionBlur(u16 *prevPixel, u16 *curPixel)
{
    u16 pixelChannels[2][3];
    u16 diffs[3];
    u8 i;
    u16 largestDiff;
    u16 red, green, blue;

    if (*prevPixel == *curPixel)
        return *curPixel;

    pixelChannels[0][0] = GET_R(*prevPixel);
    pixelChannels[0][1] = GET_G(*prevPixel);
    pixelChannels[0][2] = GET_B(*prevPixel);
    pixelChannels[1][0] = GET_R(*curPixel);
    pixelChannels[1][1] = GET_G(*curPixel);
    pixelChannels[1][2] = GET_B(*curPixel);

    // Don't blur light colors.
    if (pixelChannels[0][0] > 25 && pixelChannels[0][1] > 25 && pixelChannels[0][2] > 25)
        return *curPixel;
    if (pixelChannels[1][0] > 25 && pixelChannels[1][1] > 25 && pixelChannels[1][2] > 25)
        return *curPixel;

    for (i = 0; i < 3; i++)
    {
        if (pixelChannels[0][i] > pixelChannels[1][i])
            diffs[i] = pixelChannels[0][i] - pixelChannels[1][i];
        else
            diffs[i] = pixelChannels[1][i] - pixelChannels[0][i];
    }

    // Find the largest diff of any of the color channels.
    if (diffs[0] >= diffs[1])
    {
        if (diffs[0] >= diffs[2])
            largestDiff = diffs[0];
        else if (diffs[1] >= diffs[2])
            largestDiff = diffs[1];
        else
            largestDiff = diffs[2];
    }
    else
    {
        if (diffs[1] >= diffs[2])
            largestDiff = diffs[1];
        else if (diffs[2] >= diffs[0])
            largestDiff = diffs[2];
        else
            largestDiff = diffs[0];
    }

    red   = (pixelChannels[1][0] * (31 - largestDiff / 2)) / 31;
    green = (pixelChannels[1][1] * (31 - largestDiff / 2)) / 31;
    blue  = (pixelChannels[1][2] * (31 - largestDiff / 2)) / 31;
    return RGB2(red, green, blue);
}

static u16 QuantizePixel_Blur(u16 *prevPixel, u16 *curPixel, u16 *nextPixel)
{
    u16 red, green, blue;
    u16 prevAvg, curAvg, nextAvg;
    u16 prevDiff, nextDiff;
    u32 diff;
    u16 factor;

    if (*prevPixel == *curPixel && *nextPixel == *curPixel)
        return *curPixel;

    red   = GET_R(*curPixel);
    green = GET_G(*curPixel);
    blue  = GET_B(*curPixel);

    prevAvg = (GET_R(*prevPixel) + GET_G(*prevPixel) + GET_B(*prevPixel)) / 3;
    curAvg  = (GET_R(*curPixel)  + GET_G(*curPixel)  + GET_B(*curPixel))  / 3;
    nextAvg = (GET_R(*nextPixel) + GET_G(*nextPixel) + GET_B(*nextPixel)) / 3;

    if (prevAvg == curAvg && nextAvg == curAvg)
        return *curPixel;

    if (prevAvg > curAvg)
        prevDiff = prevAvg - curAvg;
    else
        prevDiff = curAvg - prevAvg;

    if (nextAvg > curAvg)
        nextDiff = nextAvg - curAvg;
    else
        nextDiff = curAvg - nextAvg;

    if (prevDiff >= nextDiff)
        diff = prevDiff;
    else
        diff = nextDiff;

    factor = 31 - diff / 2;
    red   = (red   * factor) / 31;
    green = (green * factor) / 31;
    blue  = (blue  * factor) / 31;
    return RGB2(red, green, blue);
}

static u16 QuantizePixel_BlurHard(u16 *prevPixel, u16 *curPixel, u16 *nextPixel)
{
    u16 red, green, blue;
    u16 prevAvg, curAvg, nextAvg;
    u16 prevDiff, nextDiff;
    u32 diff;
    u16 factor;

    if (*prevPixel == *curPixel && *nextPixel == *curPixel)
        return *curPixel;

    red   = GET_R(*curPixel);
    green = GET_G(*curPixel);
    blue  = GET_B(*curPixel);

    prevAvg = (GET_R(*prevPixel) + GET_G(*prevPixel) + GET_B(*prevPixel)) / 3;
    curAvg  = (GET_R(*curPixel)  + GET_G(*curPixel)  + GET_B(*curPixel))  / 3;
    nextAvg = (GET_R(*nextPixel) + GET_G(*nextPixel) + GET_B(*nextPixel)) / 3;

    if (prevAvg == curAvg && nextAvg == curAvg)
        return *curPixel;

    if (prevAvg > curAvg)
        prevDiff = prevAvg - curAvg;
    else
        prevDiff = curAvg - prevAvg;

    if (nextAvg > curAvg)
        nextDiff = nextAvg - curAvg;
    else
        nextDiff = curAvg - nextAvg;

    if (prevDiff >= nextDiff)
        diff = prevDiff;
    else
        diff = nextDiff;

    factor = 31 - diff;
    red   = (red   * factor) / 31;
    green = (green * factor) / 31;
    blue  = (blue  * factor) / 31;
    return RGB2(red, green, blue);
}

void ConvertImageProcessingToGBA(struct ImageProcessingContext *context)
{
    u16 i, j, k;
    u16 *src, *dest, *src_, *dest_;
    u16 width, height;

    width = context->canvasWidth >> 3;
    height = context->canvasHeight >> 3;
    src_ = context->canvasPixels;
    dest_ = context->dest;

    if (context->var_16 == 2)
    {
        for (i = 0; i < height; i++)
        {
            for (j = 0; j < width; j++)
            {
                for (k = 0; k < 8; k++)
                {
                    dest = dest_ + ((i * width + j) << 5) + (k << 2);
                    src = src_ + ((((i << 3) + k) << 3) * width) + (j << 3);

                    dest[0] = src[0] | (src[1] << 8);
                    dest[1] = src[2] | (src[3] << 8);
                    dest[2] = src[4] | (src[5] << 8);
                    dest[3] = src[6] | (src[7] << 8);
                }
            }
        }
    }
    else
    {
        for (i = 0; i < height; i++)
        {
            for (j = 0; j < width; j++)
            {
                for (k = 0; k < 8; k++)
                {
                    dest = dest_ + ((i * width + j) << 4) + (k << 1);
                    src = src_ + ((((i << 3) + k) << 3) * width) + (j << 3);

                    dest[0] = src[0] | (src[1] << 4) | (src[2] << 8) | (src[3] << 12);
                    dest[1] = src[4] | (src[5] << 4) | (src[6] << 8) | (src[7] << 12);
                }
            }
        }
    }
}

void ApplyImageProcessingQuantization(struct ImageProcessingContext *context)
{
    gCanvasPaletteStart = context->paletteStart * 16;
    gCanvasPalette = &context->canvasPalette[gCanvasPaletteStart];
    gCanvasPixels = context->canvasPixels;
    gCanvasColumnStart = context->columnStart;
    gCanvasRowStart = context->rowStart;
    gCanvasColumnEnd = context->columnEnd;
    gCanvasRowEnd = context->rowEnd;
    gCanvasWidth = context->canvasWidth;
    gCanvasHeight = context->canvasHeight;

    switch (context->quantizeEffect)
    {
    case QUANTIZE_EFFECT_STANDARD:
        QuantizePalette_Standard(FALSE);
        break;
    case QUANTIZE_EFFECT_STANDARD_LIMITED_COLORS:
        QuantizePalette_Standard(TRUE);
        break;
    case QUANTIZE_EFFECT_PRIMARY_COLORS:
        SetPresetPalette_PrimaryColors();
        QuantizePalette_PrimaryColors();
        break;
    case QUANTIZE_EFFECT_GRAYSCALE:
        SetPresetPalette_Grayscale();
        QuantizePalette_Grayscale();
        break;
    case QUANTIZE_EFFECT_GRAYSCALE_SMALL:
        SetPresetPalette_GrayscaleSmall();
        QuantizePalette_GrayscaleSmall();
        break;
    case QUANTIZE_EFFECT_BLACK_WHITE:
        SetPresetPalette_BlackAndWhite();
        QuantizePalette_BlackAndWhite();
        break;
    }
}

static void SetPresetPalette_PrimaryColors(void)
{
    gCanvasPalette[0]  = RGB_BLACK;
    gCanvasPalette[1]  = RGB(6, 6, 6);
    gCanvasPalette[2]  = RGB(29, 29, 29);
    gCanvasPalette[3]  = RGB(11, 11, 11);
    gCanvasPalette[4]  = RGB(29, 6, 6);
    gCanvasPalette[5]  = RGB(6, 29, 6);
    gCanvasPalette[6]  = RGB(6, 6, 29);
    gCanvasPalette[7]  = RGB(29, 29, 6);
    gCanvasPalette[8]  = RGB(29, 6, 29);
    gCanvasPalette[9]  = RGB(6, 29, 29);
    gCanvasPalette[10] = RGB(29, 11, 6);
    gCanvasPalette[11] = RGB(11, 29, 6);
    gCanvasPalette[12] = RGB(6, 11, 29);
    gCanvasPalette[13] = RGB(29, 6, 11);
    gCanvasPalette[14] = RGB(6, 29, 11);
    gCanvasPalette[15] = RGB(11, 6, 29);
}

static void SetPresetPalette_BlackAndWhite(void)
{
    gCanvasPalette[0] = RGB_BLACK;
    gCanvasPalette[1] = RGB_BLACK;
    gCanvasPalette[2] = RGB_WHITE;
}

static void SetPresetPalette_GrayscaleSmall(void)
{
    u8 i;

    gCanvasPalette[0] = RGB_BLACK;
    gCanvasPalette[1] = RGB_BLACK;
    for (i = 0; i < 14; i++)
        gCanvasPalette[i + 2] = RGB2(2 * (i + 2), 2 * (i + 2), 2 * (i + 2));
}

static void SetPresetPalette_Grayscale(void)
{
    u8 i;

    gCanvasPalette[0] = RGB_BLACK;
    for (i = 0; i < 32; i++)
        gCanvasPalette[i + 1] = RGB2(i, i, i);
}

static void QuantizePalette_Standard(bool8 useLimitedPalette)
{
    u8 i, j;
    u16 maxIndex;

    maxIndex = 0xDF;
    if (!useLimitedPalette)
        maxIndex = 0xFF;

    for (i = 0; i < maxIndex; i++)
        gCanvasPalette[i] = RGB_BLACK;

    gCanvasPalette[maxIndex] = RGB2(15, 15, 15);
    for (j = 0; j < gCanvasRowEnd; j++)
    {
        u16 *pixelRow = &gCanvasPixels[(gCanvasRowStart + j) * gCanvasWidth];
        u16 *pixel = &pixelRow[gCanvasColumnStart];
        for (i = 0; i < gCanvasColumnEnd; i++, pixel++)
        {
            if (IS_ALPHA(*pixel))
            {
                *pixel = gCanvasPaletteStart;
            }
            else
            {
                u16 quantizedColor = QuantizePixel_Standard(pixel);
                u8 curIndex = 1;
                if (curIndex < maxIndex)
                {
                    if (gCanvasPalette[curIndex] == RGB_BLACK)
                    {
                        // The quantized color does not match any existing color in the
                        // palette, so we add it to the palette.
                        // This if block seems pointless because the below while loop handles
                        // this same logic.
                        gCanvasPalette[curIndex] = quantizedColor;
                        *pixel = gCanvasPaletteStart + curIndex;
                    }
                    else
                    {
                        while (curIndex < maxIndex)
                        {
                            if (gCanvasPalette[curIndex] == RGB_BLACK)
                            {
                                // The quantized color does not match any existing color in the
                                // palette, so we add it to the palette.
                                gCanvasPalette[curIndex] = quantizedColor;
                                *pixel = gCanvasPaletteStart + curIndex;
                                break;
                            }

                            if (gCanvasPalette[curIndex] == quantizedColor)
                            {
                                // The quantized color matches this existing color in the
                                // palette, so we use this existing color for the pixel.
                                *pixel = gCanvasPaletteStart + curIndex;
                                break;
                            }

                            curIndex++;
                        }
                    }
                }

                if (curIndex == maxIndex)
                {
                    // The entire palette's colors are already in use, which means
                    // the base image has too many colors to handle. This error is handled
                    // by marking such pixels as gray color.
                    curIndex = maxIndex;
                    *pixel = curIndex;
                }
            }
        }
    }
}

static void QuantizePalette_BlackAndWhite(void)
{
    u8 i, j;

    for (j = 0; j < gCanvasRowEnd; j++)
    {
        u16 *pixelRow = &gCanvasPixels[(gCanvasRowStart + j) * gCanvasWidth];
        u16 *pixel = &pixelRow[gCanvasColumnStart];
        for (i = 0; i < gCanvasColumnEnd; i++, pixel++)
        {
            if (IS_ALPHA(*pixel))
            {
                *pixel = gCanvasPaletteStart;
            }
            else
            {
                if (QuantizePixel_BlackAndWhite(pixel) == RGB_BLACK)
                {
                    // Black is the first color in the quantized palette.
                    *pixel = gCanvasPaletteStart + 1;
                }
                else
                {
                    // White is the second color in the quantized palette.
                    *pixel = gCanvasPaletteStart + 2;
                }
            }
        }
    }
}

static void QuantizePalette_GrayscaleSmall(void)
{
    u8 i, j;

    for (j = 0; j < gCanvasRowEnd; j++)
    {
        u16 *pixelRow = &gCanvasPixels[(gCanvasRowStart + j) * gCanvasWidth];
        u16 *pixel = &pixelRow[gCanvasColumnStart];
        for (i = 0; i < gCanvasColumnEnd; i++, pixel++)
        {
            if (IS_ALPHA(*pixel))
                *pixel = gCanvasPaletteStart;
            else
                *pixel = QuantizePixel_GrayscaleSmall(pixel) + gCanvasPaletteStart;
        }
    }
}

static void QuantizePalette_Grayscale(void)
{
    u8 i, j;

    for (j = 0; j < gCanvasRowEnd; j++)
    {
        u16 *pixelRow = &gCanvasPixels[(gCanvasRowStart + j) * gCanvasWidth];
        u16 *pixel = &pixelRow[gCanvasColumnStart];
        for (i = 0; i < gCanvasColumnEnd; i++, pixel++)
        {
            if (IS_ALPHA(*pixel))
                *pixel = gCanvasPaletteStart;
            else
                *pixel = QuantizePixel_Grayscale(pixel) + gCanvasPaletteStart;
        }
    }
}

static void QuantizePalette_PrimaryColors(void)
{
    u8 i, j;

    for (j = 0; j < gCanvasRowEnd; j++)
    {
        u16 *pixelRow = &gCanvasPixels[(gCanvasRowStart + j) * gCanvasWidth];
        u16 *pixel = &pixelRow[gCanvasColumnStart];
        for (i = 0; i < gCanvasColumnEnd; i++, pixel++)
        {
            if (IS_ALPHA(*pixel))
                *pixel = gCanvasPaletteStart;
            else
                *pixel = QuantizePixel_PrimaryColors(pixel) + gCanvasPaletteStart;
        }
    }
}

// Quantizes the pixel's color channels to nearest multiple of 4, and clamps to [6, 30].
static u16 QuantizePixel_Standard(u16 *pixel)
{
    u16 red =   GET_R(*pixel);
    u16 green = GET_G(*pixel);
    u16 blue =  GET_B(*pixel);

    // Quantize color channels to muliples of 4, rounding up.
    if (red & 3)
        red = (red & 0x1C) + 4;
    if (green & 3)
        green = (green & 0x1C) + 4;
    if (blue & 3)
        blue = (blue & 0x1C) + 4;

    // Clamp channels to [6, 30].
    if (red < 6)
        red = 6;
    if (red > 30)
        red = 30;
    if (green < 6)
        green = 6;
    if (green > 30)
        green = 30;
    if (blue < 6)
        blue = 6;
    if (blue > 30)
        blue = 30;

    return RGB2(red, green, blue);
}

static u16 QuantizePixel_PrimaryColors(u16 *color)
{
    u16 red =   GET_R(*color);
    u16 green = GET_G(*color);
    u16 blue =  GET_B(*color);

    if (red < 12 && green < 11 && blue < 11)
        return 1;

    if (red > 19 && green > 19 && blue > 19)
        return 2;

    if (red > 19)
    {
        if (green > 19)
        {
            if (blue > 14)
                return 2;
            else
                return 7;
        }
        else if (blue > 19)
        {
            if (green > 14)
                return 2;
            else
                return 8;
        }
    }

    if (green > 19 && blue > 19)
    {
        if (red > 14)
            return 2;
        else
            return 9;
    }

    if (red > 19)
    {
        if (green > 11)
        {
            if (blue > 11)
            {
                if (green < blue)
                    return 8;
                else
                    return 7;
            }
            else
            {
                return 10;
            }
        }
        else if (blue > 11)
        {
            return 13;
        }
        else
        {
            return 4;
        }
    }

    if (green > 19)
    {
        if (red > 11)
        {
            if (blue > 11)
            {
                if (red < blue)
                    return 9;
                else
                    return 7;
            }
            else
            {
                return 11;
            }
        }
        else
        {
            if (blue > 11)
                return 14;
            else
                return 5;
        }
    }

    if (blue > 19)
    {
        if (red > 11)
        {
            if (green > 11)
            {
                if (red < green)
                    return 9;
                else
                    return 8;
            }
        }
        else if (green > 11)
        {
            return 12;
        }

        if (blue > 11)
            return 15;
        else
            return 6;
    }

    return 3;
}

static u16 QuantizePixel_GrayscaleSmall(u16 *color)
{
    u16 red =   GET_R(*color);
    u16 green = GET_G(*color);
    u16 blue =  GET_B(*color);
    u16 average = ((red + green + blue) / 3) & 0x1E;
    if (average == 0)
        return 1;
    else
        return average / 2;
}

static u16 QuantizePixel_Grayscale(u16 *color)
{
    u16 red =   GET_R(*color);
    u16 green = GET_G(*color);
    u16 blue =  GET_B(*color);
    u16 average = (red + green + blue) / 3;
    return average + 1;
}
