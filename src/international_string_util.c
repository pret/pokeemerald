#include "global.h"
#include "international_string_util.h"
#include "list_menu.h"
#include "pokedex.h"
#include "script_menu.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "window.h"

extern const struct PokedexEntry gPokedexEntries[];

int GetStringCenterAlignXOffset(int fontId, const u8 *str, int totalWidth)
{
    return GetStringCenterAlignXOffsetWithLetterSpacing(fontId, str, totalWidth, 0);
}

int GetStringRightAlignXOffset(int fontId, const u8 *str, int totalWidth)
{
    return GetStringWidthDifference(fontId, str, totalWidth, 0);
}

int GetStringCenterAlignXOffsetWithLetterSpacing(int fontId, const u8 *str, int totalWidth, int letterSpacing)
{
    return GetStringWidthDifference(fontId, str, totalWidth, letterSpacing) / 2;
}

int GetStringWidthDifference(int fontId, const u8 *str, int totalWidth, int letterSpacing)
{
    int stringWidth = GetStringWidth(fontId, str, letterSpacing);
    if (totalWidth > stringWidth)
        return totalWidth - stringWidth;
    else
        return 0;
}

int GetMaxWidthInMenuTable(const struct MenuAction *str, int arg1)
{
    int i, var;

    for (var = 0, i = 0; i < arg1; i++)
    {
        int stringWidth = GetStringWidth(1, str[i].text, 0);
        if (stringWidth > var)
            var = stringWidth;
    }

    return ConvertPixelWidthToTileWidth(var);
}

int sub_81DB3D8(const struct MenuAction *str, const u8* arg1, int arg2)
{
    int i, var;

    for (var = 0, i = 0; i < arg2; i++)
    {
        int stringWidth = GetStringWidth(1, str[arg1[i]].text, 0);
        if (stringWidth > var)
            var = stringWidth;
    }

    return ConvertPixelWidthToTileWidth(var);
}

int Intl_GetListMenuWidth(const struct ListMenuTemplate *listMenu)
{
    int i, maxWidth, finalWidth;
    const struct ListMenuItem *items = listMenu->items;

    maxWidth = 0;
    for (i = 0; i < listMenu->totalItems; i++)
    {
        int width = GetStringWidth(listMenu->fontId, items[i].name, 0);
        if (width > maxWidth)
            maxWidth = width;
    }

    finalWidth = maxWidth + listMenu->item_X + 9;
    if (finalWidth < 0)
        finalWidth += 7;

    finalWidth >>= 3;
    if (finalWidth > 28)
        finalWidth = 28;

    return finalWidth;
}

void CopyMonCategoryText(int dexNum, u8 *dest)
{
    u8 *str = StringCopy(dest, gPokedexEntries[dexNum].categoryName);
    *str = CHAR_SPACE;
    StringCopy(str + 1, gText_Pokemon);
}

u8 *sub_81DB494(u8 *str, int fontId, const u8 *str2, int totalStringWidth)
{
    u8 *buffer;
    int width;
    int clearWidth;

    if (str2)
    {
        buffer = StringCopy(str, str2);
        width = GetStringWidth(fontId, str2, 0);
    }
    else
    {
        buffer = str;
        width = 0;
    }

    clearWidth = totalStringWidth - width;
    if (clearWidth > 0)
    {
        *buffer = EXT_CTRL_CODE_BEGIN;
        buffer++;
        *buffer = EXT_CTRL_CODE_CLEAR;
        buffer++;
        *buffer = clearWidth;
        buffer++;
        *buffer = EOS;
    }

    return buffer;
}

void PadNameString(u8 *dest, u8 padChar)
{
    u8 length;

    StripExtCtrlCodes(dest);
    length = StringLength(dest);
    if (padChar == EXT_CTRL_CODE_BEGIN)
    {
        while (length < PLAYER_NAME_LENGTH - 1)
        {
            dest[length] = EXT_CTRL_CODE_BEGIN;
            dest[length + 1] = EXT_CTRL_CODE_RESET_SIZE;
            length += 2;
        }
    }
    else
    {
        while (length < PLAYER_NAME_LENGTH - 1)
        {
            dest[length] = padChar;
            length++;
        }
    }

    dest[length] = EOS;
}

void sub_81DB52C(u8 *str)
{
    if (StringLength(str) < PLAYER_NAME_LENGTH - 1)
        ConvertInternationalString(str, LANGUAGE_JAPANESE);
    else
        StripExtCtrlCodes(str);
}

void sub_81DB554(u8 *str, u8 arg1)
{
    u8 *buffer;
    if (StringLength(str) < PLAYER_NAME_LENGTH - 1)
    {
        ConvertInternationalString(str, LANGUAGE_JAPANESE);
    }
    else if (arg1 == EXT_CTRL_CODE_BEGIN)
    {
        StripExtCtrlCodes(str);
    }
    else
    {
        buffer = str;
        while (buffer[1] != EOS)
            buffer++;

        while (buffer >= str && buffer[0] == arg1)
        {
            buffer[0] = EOS;
            buffer--;
        }
    }
}

void sub_81DB5AC(u8 *str)
{
    if (*str++ == EXT_CTRL_CODE_BEGIN && *str++ == EXT_CTRL_CODE_JPN)
    {
        while (*str != EOS)
        {
            if (str[0] == EXT_CTRL_CODE_BEGIN && str[1] == EXT_CTRL_CODE_ENG)
                return;

            str++;
        }

        *str++ = EXT_CTRL_CODE_BEGIN;
        *str++ = EXT_CTRL_CODE_ENG;
        *str = EOS;
    }
}

void TVShowConvertInternationalString(u8 *dest, const u8 *src, int language)
{
    StringCopy(dest, src);
    ConvertInternationalString(dest, language);
}

int sub_81DB604(u8 *str)
{
    if (str[0] == EXT_CTRL_CODE_BEGIN && str[1] == EXT_CTRL_CODE_JPN)
        return LANGUAGE_JAPANESE;
    else
        return LANGUAGE_ENGLISH;
}

void sub_81DB620(int windowId, int columnStart, int rowStart, int numFillTiles, int numRows)
{
    u8 *windowTileData;
    int fillSize, windowRowSize, rowsToFill;
    struct Window *window = &gWindows[windowId];

    fillSize = numFillTiles * TILE_SIZE_4BPP;
    windowRowSize = window->window.width * TILE_SIZE_4BPP;
    windowTileData = window->tileData + (rowStart * windowRowSize) + (columnStart * TILE_SIZE_4BPP);
    if (numRows > 0)
    {
        rowsToFill = numRows;
        while (rowsToFill)
        {
            CpuFastFill8(0x11, windowTileData, fillSize);
            windowTileData += windowRowSize;
            rowsToFill--;
        }
    }
}
