#include "global.h"
#include "data.h"
#include "international_string_util.h"
#include "list_menu.h"
#include "pokedex.h"
#include "script_menu.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "window.h"
#include "constants/trainers.h"

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

int GetMaxWidthInMenuTable(const struct MenuAction *actions, int numActions)
{
    int i, maxWidth;

    for (maxWidth = 0, i = 0; i < numActions; i++)
    {
        int stringWidth = GetStringWidth(FONT_NORMAL, actions[i].text, 0);
        if (stringWidth > maxWidth)
            maxWidth = stringWidth;
    }

    return ConvertPixelWidthToTileWidth(maxWidth);
}

int GetMaxWidthInSubsetOfMenuTable(const struct MenuAction *actions, const u8 *actionIds, int numActions)
{
    int i, maxWidth;

    for (maxWidth = 0, i = 0; i < numActions; i++)
    {
        int stringWidth = GetStringWidth(FONT_NORMAL, actions[actionIds[i]].text, 0);
        if (stringWidth > maxWidth)
            maxWidth = stringWidth;
    }

    return ConvertPixelWidthToTileWidth(maxWidth);
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
    finalWidth /= 8;
    if (finalWidth > 28)
        finalWidth = 28;

    return finalWidth;
}

void CopyMonCategoryText(int dexNum, u8 *dest)
{
#if FRENCH
    // Just category name in French
    u8 *str = StringCopy(dest, gPokedexEntries[dexNum].categoryName);
#elif ITALIAN || SPANISH
    const u8 *categoryName = gPokedexEntries[dexNum].categoryName;
    u8 *str = StringCopy(dest, gText_Pokemon);
    *str++ = CHAR_SPACE;
    StringCopy(str, categoryName);
#else //ENGLISH
    u8 *str = StringCopy(dest, gPokedexEntries[dexNum].categoryName);
    *str = CHAR_SPACE;
    StringCopy(str + 1, gText_Pokemon);
#endif
}

u8 *GetStringClearToWidth(u8 *dest, int fontId, const u8 *str, int totalStringWidth)
{
    u8 *buffer;
    int width;
    int clearWidth;

    if (str)
    {
        buffer = StringCopy(dest, str);
        width = GetStringWidth(fontId, str, 0);
    }
    else
    {
        buffer = dest;
        width = 0;
    }

    clearWidth = totalStringWidth - width;
    if (clearWidth > 0)
    {
        *(buffer++) = EXT_CTRL_CODE_BEGIN;
        *(buffer++) = EXT_CTRL_CODE_CLEAR;
        *(buffer++) = clearWidth;
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
            dest[length + 1] = EXT_CTRL_CODE_RESET_FONT;
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

void ConvertInternationalPlayerName(u8 *str)
{
    if (StringLength(str) < PLAYER_NAME_LENGTH - 1)
        ConvertInternationalString(str, LANGUAGE_JAPANESE);
    else
        StripExtCtrlCodes(str);
}

void ConvertInternationalPlayerNameStripChar(u8 *str, u8 removeChar)
{
    u8 *buffer;
    if (StringLength(str) < PLAYER_NAME_LENGTH - 1)
    {
        ConvertInternationalString(str, LANGUAGE_JAPANESE);
    }
    else if (removeChar == EXT_CTRL_CODE_BEGIN)
    {
        StripExtCtrlCodes(str);
    }
    else
    {
        buffer = str;
        while (buffer[1] != EOS)
            buffer++;

        while (buffer >= str && buffer[0] == removeChar)
        {
            buffer[0] = EOS;
            buffer--;
        }
    }
}

void ConvertInternationalContestantName(u8 *str)
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

// It's impossible to distinguish between Latin languages just from a string alone, so the function defaults to LANGUAGE_ENGLISH. This is the case in all of the versions of the game.
int GetNicknameLanguage(u8 *str)
{
    if (str[0] == EXT_CTRL_CODE_BEGIN && str[1] == EXT_CTRL_CODE_JPN)
        return LANGUAGE_JAPANESE;
    else
        return LANGUAGE_ENGLISH;
}

// Used by Pokénav's Match Call to erase the previous trainer's flavor text when switching between their info pages.
void FillWindowTilesByRow(int windowId, int columnStart, int rowStart, int numFillTiles, int numRows)
{
    u8 *windowTileData;
    int fillSize, windowRowSize, i;
    struct Window *window = &gWindows[windowId];

    fillSize = numFillTiles * TILE_SIZE_4BPP;
    windowRowSize = window->window.width * TILE_SIZE_4BPP;
    windowTileData = window->tileData + (rowStart * windowRowSize) + (columnStart * TILE_SIZE_4BPP);
    if (numRows > 0)
    {
        for (i = numRows; i != 0; i--)
        {
            CpuFastFill8(0x11, windowTileData, fillSize);
            windowTileData += windowRowSize;
        }
    }
}

#if EUROPE
u8 *StringAppendWithPlaceholder(u8 *dest, const u8 *src, u8 *placeholderStr)
{
    u8 text[32], c;

    StringCopyN(text, placeholderStr, 31);
    text[31] = EOS;
    placeholderStr = text;
    while ((c = *src++) != EOS)
    {
        if (c == PLACEHOLDER_BEGIN)
        {
            src++;
            dest = StringCopy(dest, placeholderStr);
        }
        else
        {
            *dest = c;
            dest++;
        }
    }
    *dest = EOS;
    return dest;
}

#if FRENCH
const u8 gText_TateLiza[] = _("LEVY&TATIA");
#elif ITALIAN
const u8 gText_TateLiza[] = _("TELL & PAT");
#elif SPANISH
const u8 gText_TateLiza[] = _("VITO-LETI");
#endif

const u8 *GetTrainerClassNameGenderSpecific(s32 trainerClassId, u32 trainerGender, const u8 *trainerName)
{
    switch (trainerClassId)
    {
    case TRAINER_CLASS_SCHOOL_KID:
        if (trainerGender != 0)
            return gText_SchoolKidFemale;
        return gTrainerClassNames[trainerClassId];
    case TRAINER_CLASS_RIVAL:
    case TRAINER_CLASS_RS_PROTAG:
        if (trainerGender != 0)
            return gText_TrainerFemale;
        break;
    case TRAINER_CLASS_LEADER:
        if (trainerName != NULL && StringCompare(trainerName, gText_TateLiza) == 0)
            return gText_LeaderPlural; // Returns the plural for Leader for Tate & Liza's battle
        break;
    }
    trainerName = gTrainerClassNames[trainerClassId];
    return trainerName;
}
#endif
