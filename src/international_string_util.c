#include "global.h"
#include "international_string_util.h"
#include "text.h"

extern s32 convert_pixel_width_to_tile_width(s32 a0); // script menu

s32 GetStringCenterAlignXOffset(s32 fontId, const u8 *str, s32 totalWidth)
{
    return GetStringCenterAlignXOffsetWithLetterSpacing(fontId, str, totalWidth, 0);
}

s32 GetStringRightAlignXOffset(s32 fontId, const u8 *str, s32 totalWidth)
{
    return GetStringWidthDifference(fontId, str, totalWidth, 0);
}

s32 GetStringCenterAlignXOffsetWithLetterSpacing(s32 fontId, const u8 *str, s32 totalWidth, s32 letterSpacing)
{
    return GetStringWidthDifference(fontId, str, totalWidth, letterSpacing) / 2;
}

s32 GetStringWidthDifference(s32 fontId, const u8 *str, s32 totalWidth, s32 letterSpacing)
{
    s32 stringWidth = GetStringWidth(fontId, str, letterSpacing);
    if (totalWidth > stringWidth)
        return totalWidth - stringWidth;
    else
        return 0;
}

s32 GetMaxWidthInMenuTable(const u8 **str, s32 arg1)
{
    s32 i, var;

    for (var = 0, i = 0; i < arg1; i++)
    {
        s32 stringWidth = GetStringWidth(1, str[i * 2], 0);
        if (stringWidth > var)
            var = stringWidth;
    }

    return convert_pixel_width_to_tile_width(var);
}

s32 sub_81DB3D8(const u8 **str, u8* arg1, s32 arg2)
{
    s32 i, var;

    for (var = 0, i = 0; i < arg2; i++)
    {
        s32 stringWidth = GetStringWidth(1, str[arg1[i] * 2], 0);
        if (stringWidth > var)
            var = stringWidth;
    }

    return convert_pixel_width_to_tile_width(var);
}
