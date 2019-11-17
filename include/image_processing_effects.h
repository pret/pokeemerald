#ifndef GUARD_IMAGE_PROCESSING_EFFECTS_H
#define GUARD_IMAGE_PROCESSING_EFFECTS_H

enum
{
    IMAGE_EFFECT_POINTILLISM = 2,
    IMAGE_EFFECT_GRAYSCALE_LIGHT = 6,
    IMAGE_EFFECT_BLUR = 8,
    IMAGE_EFFECT_OUTLINE_COLORED = 9,
    IMAGE_EFFECT_INVERT_BLACK_WHITE = 10,
    IMAGE_EFFECT_THICK_BLACK_WHITE = 11,
    IMAGE_EFFECT_SHIMMER = 13,
    IMAGE_EFFECT_OUTLINE = 30,
    IMAGE_EFFECT_INVERT = 31,
    IMAGE_EFFECT_BLUR_RIGHT = 32,
    IMAGE_EFFECT_BLUR_DOWN = 33,
    IMAGE_EFFECT_CHARCOAL = 36,
};

enum
{
    QUANTIZE_EFFECT_STANDARD,
    QUANTIZE_EFFECT_STANDARD_LIMITED_COLORS,
    QUANTIZE_EFFECT_PRIMARY_COLORS,
    QUANTIZE_EFFECT_GRAYSCALE,
    QUANTIZE_EFFECT_GRAYSCALE_SMALL,
    QUANTIZE_EFFECT_BLACK_WHITE,
};

struct ImageProcessingContext
{
    u8 effect;
    void *canvasPixels;
    u16 *canvasPalette;
    u8 fillerC[0x4];
    void *dest;
    u16 quantizeEffect;
    u16 var_16;
    u8 paletteStart;
    u8 columnStart;
    u8 rowStart;
    u8 columnEnd;
    u8 rowEnd;
    u8 canvasWidth;
    u8 canvasHeight;
    u8 personality;
};

void ApplyImageProcessingEffects(struct ImageProcessingContext *);
void ApplyImageProcessingQuantization(struct ImageProcessingContext *);
void ConvertImageProcessingToGBA(struct ImageProcessingContext *);

#endif
