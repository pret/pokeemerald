#include "global.h"
#include "battle.h"
#include "blit.h"
#include "dynamic_placeholder_text_util.h"
#include "event_data.h"
#include "field_name_box.h"
#include "fonts.h"
#include "m4a.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "palette.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "text.h"
#include "window.h"
#include "constants/songs.h"
#include "constants/speaker_names.h"

static u16 RenderText(struct TextPrinter *);
static u32 RenderFont(struct TextPrinter *);
static u16 FontFunc_Small(struct TextPrinter *);
static u16 FontFunc_Normal(struct TextPrinter *);
static u16 FontFunc_Short(struct TextPrinter *);
static u16 FontFunc_ShortCopy1(struct TextPrinter *);
static u16 FontFunc_ShortCopy2(struct TextPrinter *);
static u16 FontFunc_ShortCopy3(struct TextPrinter *);
static u16 FontFunc_Narrow(struct TextPrinter *);
static u16 FontFunc_SmallNarrow(struct TextPrinter *);
static u16 FontFunc_Narrower(struct TextPrinter *);
static u16 FontFunc_SmallNarrower(struct TextPrinter *);
static u16 FontFunc_ShortNarrow(struct TextPrinter *);
static u16 FontFunc_ShortNarrower(struct TextPrinter *);
static void DecompressGlyph_Small(u16, bool32);
static void DecompressGlyph_Normal(u16, bool32);
static void DecompressGlyph_Short(u16, bool32);
static void DecompressGlyph_Narrow(u16, bool32);
static void DecompressGlyph_SmallNarrow(u16, bool32);
static void DecompressGlyph_Bold(u16);
static void DecompressGlyph_Narrower(u16, bool32);
static void DecompressGlyph_SmallNarrower(u16, bool32);
static void DecompressGlyph_ShortNarrow(u16, bool32);
static void DecompressGlyph_ShortNarrower(u16, bool32);
static u32 GetGlyphWidth_Small(u16, bool32);
static u32 GetGlyphWidth_Normal(u16, bool32);
static u32 GetGlyphWidth_Short(u16, bool32);
static u32 GetGlyphWidth_Narrow(u16, bool32);
static u32 GetGlyphWidth_SmallNarrow(u16, bool32);
static u32 GetGlyphWidth_Narrower(u16, bool32);
static u32 GetGlyphWidth_SmallNarrower(u16, bool32);
static u32 GetGlyphWidth_ShortNarrow(u16, bool32);
static u32 GetGlyphWidth_ShortNarrower(u16, bool32);
static struct TextPrinter *AllocateTextPrinter(void);
static u32 GetNumTextPrinters(void);
static void FreeFinishedTextPrinters(void);
static void SpriteCB_TextCursor(struct Sprite *sprite);

static EWRAM_DATA struct TextPrinter *sFirstTextPrinter = NULL;

static EWRAM_DATA u16 sFontHalfRowLookupTable[0x100];
static EWRAM_DATA union TextColor sLastTextColor;

EWRAM_DATA const struct FontInfo *gFonts = NULL;
EWRAM_DATA bool8 gDisableTextPrinters = FALSE;
EWRAM_DATA TextFlags gTextFlags = {0};
IWRAM_DATA struct TextGlyph gCurGlyph = {0};

static const u8 sDownArrowTiles[] = INCGFX_U8("graphics/fonts/down_arrow.png", ".4bpp");
static const u8 sDarkDownArrowTiles[] = INCGFX_U8("graphics/fonts/down_arrow_alt.png", ".4bpp");
static const u8 sUnusedFRLGBlankedDownArrow[] = INCGFX_U8("graphics/fonts/unused_frlg_blanked_down_arrow.png", ".4bpp");
static const u8 sUnusedFRLGDownArrow[] = INCGFX_U8("graphics/fonts/unused_frlg_down_arrow.png", ".4bpp");
static const u8 sDownArrowYCoords[] = { 0, 1, 2, 1 };

static const struct GlyphWidthFunc sGlyphWidthFuncs[] =
{
    { FONT_SMALL,          GetGlyphWidth_Small },
    { FONT_NORMAL,         GetGlyphWidth_Normal },
    { FONT_SHORT,          GetGlyphWidth_Short },
    { FONT_SHORT_COPY_1,   GetGlyphWidth_Short },
    { FONT_SHORT_COPY_2,   GetGlyphWidth_Short },
    { FONT_SHORT_COPY_3,   GetGlyphWidth_Short },
    { FONT_BRAILLE,        GetGlyphWidth_Braille },
    { FONT_NARROW,         GetGlyphWidth_Narrow },
    { FONT_SMALL_NARROW,   GetGlyphWidth_SmallNarrow },
    { FONT_NARROWER,       GetGlyphWidth_Narrower },
    { FONT_SMALL_NARROWER, GetGlyphWidth_SmallNarrower },
    { FONT_SHORT_NARROW,   GetGlyphWidth_ShortNarrow },
    { FONT_SHORT_NARROWER, GetGlyphWidth_ShortNarrower },
};

struct
{
    u16 tileOffset;
    u8 width;
    u8 height;
} static const sKeypadIcons[] =
{
    [CHAR_A_BUTTON]       = { 0x00,  8, 12 },
    [CHAR_B_BUTTON]       = { 0x01,  8, 12 },
    [CHAR_L_BUTTON]       = { 0x02, 16, 12 },
    [CHAR_R_BUTTON]       = { 0x04, 16, 12 },
    [CHAR_START_BUTTON]   = { 0x06, 24, 12 },
    [CHAR_SELECT_BUTTON]  = { 0x09, 24, 12 },
    [CHAR_DPAD_UP]        = { 0x0C,  8, 12 },
    [CHAR_DPAD_DOWN]      = { 0x0D,  8, 12 },
    [CHAR_DPAD_LEFT]      = { 0x0E,  8, 12 },
    [CHAR_DPAD_RIGHT]     = { 0x0F,  8, 12 },
    [CHAR_DPAD_UPDOWN]    = { 0x20,  8, 12 },
    [CHAR_DPAD_LEFTRIGHT] = { 0x21,  8, 12 },
    [CHAR_DPAD_NONE]      = { 0x22,  8, 12 }
};

static const u8 sKeypadIconTiles[] = INCGFX_U8("graphics/fonts/keypad_icons.png", ".4bpp");

static const struct FontInfo sFontInfos[] =
{
    [FONT_SMALL] = {
        .fontFunction = FontFunc_Small,
        .maxLetterWidth = 5,
        .maxLetterHeight = 12,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .color.foreground = 2,
        .color.background = 1,
        .color.accent = 1,
        .color.shadow = 3,
    },
    [FONT_NORMAL] = {
        .fontFunction = FontFunc_Normal,
        .maxLetterWidth = 6,
        .maxLetterHeight = 16,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .color.foreground = 2,
        .color.background = 1,
        .color.accent = 1,
        .color.shadow = 3,
    },
    [FONT_SHORT] = {
        .fontFunction = FontFunc_Short,
        .maxLetterWidth = 6,
        .maxLetterHeight = 14,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .color.foreground = 2,
        .color.background = 1,
        .color.accent = 1,
        .color.shadow = 3,
    },
    [FONT_SHORT_COPY_1] = {
        .fontFunction = FontFunc_ShortCopy1,
        .maxLetterWidth = 6,
        .maxLetterHeight =  14,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .color.foreground = 2,
        .color.background = 1,
        .color.accent = 1,
        .color.shadow = 3,
    },
    [FONT_SHORT_COPY_2] = {
        .fontFunction = FontFunc_ShortCopy2,
        .maxLetterWidth = 6,
        .maxLetterHeight =  14,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .color.foreground = 2,
        .color.background = 1,
        .color.accent = 1,
        .color.shadow = 3,
    },
    [FONT_SHORT_COPY_3] = {
        .fontFunction = FontFunc_ShortCopy3,
        .maxLetterWidth = 6,
        .maxLetterHeight =  14,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .color.foreground = 2,
        .color.background = 1,
        .color.accent = 1,
        .color.shadow = 3,
    },
    [FONT_BRAILLE] = {
        .fontFunction = FontFunc_Braille,
        .maxLetterWidth = 8,
        .maxLetterHeight = 16,
        .letterSpacing = 0,
        .lineSpacing = 8,
        .color.foreground = 2,
        .color.background = 1,
        .color.accent = 1,
        .color.shadow = 3,
    },
    [FONT_NARROW] = {
        .fontFunction = FontFunc_Narrow,
        .maxLetterWidth = 5,
        .maxLetterHeight = 16,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .color.foreground = 2,
        .color.background = 1,
        .color.accent = 1,
        .color.shadow = 3,
    },
    [FONT_SMALL_NARROW] = {
        .fontFunction = FontFunc_SmallNarrow,
        .maxLetterWidth = 5,
        .maxLetterHeight = 8,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .color.foreground = 2,
        .color.background = 1,
        .color.accent = 1,
        .color.shadow = 3,
    },
    [FONT_BOLD] = {
        .fontFunction = NULL,
        .maxLetterWidth = 8,
        .maxLetterHeight = 8,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .color.foreground = 1,
        .color.background = 2,
        .color.accent = 2,
        .color.shadow = 15,
    },
    [FONT_NARROWER] = {
        .fontFunction = FontFunc_Narrower,
        .maxLetterWidth = 5,
        .maxLetterHeight = 16,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .color.foreground = 2,
        .color.background = 1,
        .color.accent = 1,
        .color.shadow = 3,
    },
    [FONT_SMALL_NARROWER] = {
        .fontFunction = FontFunc_SmallNarrower,
        .maxLetterWidth = 5,
        .maxLetterHeight = 8,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .color.foreground = 2,
        .color.background = 1,
        .color.accent = 1,
        .color.shadow = 3,
    },
    [FONT_SHORT_NARROW] = {
        .fontFunction = FontFunc_ShortNarrow,
        .maxLetterWidth = 5,
        .maxLetterHeight = 14,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .color.foreground = 2,
        .color.background = 1,
        .color.accent = 1,
        .color.shadow = 3,
    },
    [FONT_SHORT_NARROWER] = {
        .fontFunction = FontFunc_ShortNarrower,
        .maxLetterWidth = 5,
        .maxLetterHeight = 14,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .color.foreground = 2,
        .color.background = 1,
        .color.accent = 1,
        .color.shadow = 3,
    },
};

static const u8 sMenuCursorDimensions[][2] =
{
    [FONT_SMALL]          = { 8,  12 },
    [FONT_NORMAL]         = { 8,  15 },
    [FONT_SHORT]          = { 8,  14 },
    [FONT_SHORT_COPY_1]   = { 8,  14 },
    [FONT_SHORT_COPY_2]   = { 8,  14 },
    [FONT_SHORT_COPY_3]   = { 8,  14 },
    [FONT_BRAILLE]        = { 8,  16 },
    [FONT_NARROW]         = { 8,  15 },
    [FONT_SMALL_NARROW]   = { 8,   8 },
    [FONT_BOLD]           = {},
    [FONT_NARROWER]       = { 8,  15 },
    [FONT_SMALL_NARROWER] = { 8,   8 },
    [FONT_SHORT_NARROW]   = { 8,  14 },
    [FONT_SHORT_NARROWER] = { 8,  14 },
};

// these three arrays are most for readability, ie instead of returning a magic number 8
static const u8 sTextSpeedFrameDelays[] =
{
    [OPTIONS_TEXT_SPEED_SLOW]    = 8,
    [OPTIONS_TEXT_SPEED_MID]     = 4,
    [OPTIONS_TEXT_SPEED_FAST]    = 1,
    [OPTIONS_TEXT_SPEED_INSTANT] = 1,
};

static const u8 sTextSpeedModifiers[] =
{
    [OPTIONS_TEXT_SPEED_SLOW]    = TEXT_SPEED_SLOW_MODIFIER,
    [OPTIONS_TEXT_SPEED_MID]     = TEXT_SPEED_MEDIUM_MODIFIER,
    [OPTIONS_TEXT_SPEED_FAST]    = TEXT_SPEED_FAST_MODIFIER,
    [OPTIONS_TEXT_SPEED_INSTANT] = TEXT_SPEED_INSTANT_MODIFIER,
};

static const u8 sTextScrollSpeeds[] =
{
    [OPTIONS_TEXT_SPEED_SLOW]    = 1,
    [OPTIONS_TEXT_SPEED_MID]     = 2,
    [OPTIONS_TEXT_SPEED_FAST]    = 4,
    [OPTIONS_TEXT_SPEED_INSTANT] = 6,
};

static const u16 sFontBoldJapaneseGlyphs[] = INCGFX_U16("graphics/fonts/japanese_bold.png", ".hwjpnfont");

static void SetFontsPointer(const struct FontInfo *fonts)
{
    gFonts = fonts;
}

u32 GetPlayerTextSpeed(void)
{
    if (gTextFlags.forceMidTextSpeed)
        return OPTIONS_TEXT_SPEED_MID;

    if (gSaveBlock2Ptr->optionsTextSpeed > OPTIONS_TEXT_SPEED_INSTANT)
        gSaveBlock2Ptr->optionsTextSpeed = OPTIONS_TEXT_SPEED_FAST;

    if (FlagGet(FLAG_TEXT_SPEED_INSTANT) || TEXT_SPEED_INSTANT)
        return OPTIONS_TEXT_SPEED_INSTANT;

    return gSaveBlock2Ptr->optionsTextSpeed;
}

u32 GetPlayerTextSpeedDelay(void)
{
    return sTextSpeedFrameDelays[GetPlayerTextSpeed()];
}

u32 GetPlayerTextSpeedModifier(void)
{
    return sTextSpeedModifiers[GetPlayerTextSpeed()];
}

u32 GetPlayerTextScrollSpeed(void)
{
    return sTextScrollSpeeds[GetPlayerTextSpeed()];
}

bool32 IsPlayerTextSpeedInstant(void)
{
    return GetPlayerTextSpeed() == OPTIONS_TEXT_SPEED_INSTANT;
}

void DeactivateAllTextPrinters(void)
{
    struct TextPrinter *currentPrinter = sFirstTextPrinter;
    while (currentPrinter != NULL)
    {
        currentPrinter->isInUse = FALSE;
        currentPrinter = currentPrinter->nextPrinter;
    }

    FreeFinishedTextPrinters();
}

bool16 AddTextPrinterParameterized(u8 windowId, u8 fontId, const u8 *str, u8 x, u8 y, u8 speed, TextPrinterCallback callback)
{
    struct TextPrinterTemplate printerTemplate;

    printerTemplate.currentChar = str;
    printerTemplate.type = WINDOW_TEXT_PRINTER;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = fontId;
    printerTemplate.x = x;
    printerTemplate.y = y;
    printerTemplate.currentX = x;
    printerTemplate.currentY = y;
    printerTemplate.letterSpacing = gFonts[fontId].letterSpacing;
    printerTemplate.lineSpacing = gFonts[fontId].lineSpacing;
    printerTemplate.color = gFonts[fontId].color;
    return AddTextPrinter(&printerTemplate, speed, callback);
}

bool16 AddSpriteTextPrinterParameterized(u8 spriteId, u8 fontId, const u8 *str, u8 x, u8 y, u8 speed, TextPrinterCallback callback)
{
    struct TextPrinterTemplate printerTemplate;

    printerTemplate.currentChar = str;
    printerTemplate.type = SPRITE_TEXT_PRINTER;
    printerTemplate.spriteId = spriteId;
    printerTemplate.fontId = fontId;
    printerTemplate.x = x;
    printerTemplate.y = y;
    printerTemplate.currentX = x;
    printerTemplate.currentY = y;
    printerTemplate.letterSpacing = gFonts[fontId].letterSpacing;
    printerTemplate.lineSpacing = gFonts[fontId].lineSpacing;
    printerTemplate.color = gFonts[fontId].color;
    return AddTextPrinter(&printerTemplate, speed, callback);
}

void AddSpriteTextPrinterParameterized3(u8 spriteId, u8 fontId, u8 left, u8 top, const u8 *color, s8 speed, const u8 *str)
{
    struct TextPrinterTemplate printer;

    printer.currentChar = str;
    printer.type = SPRITE_TEXT_PRINTER;
    printer.spriteId = spriteId;
    printer.fontId = fontId;
    printer.x = left;
    printer.y = top;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.letterSpacing = GetFontAttribute(fontId, FONTATTR_LETTER_SPACING);
    printer.lineSpacing = GetFontAttribute(fontId, FONTATTR_LINE_SPACING);
    printer.color.background = color[0];
    printer.color.foreground = color[1];
    printer.color.shadow = color[2];
    printer.color.accent = color[0];

    AddTextPrinter(&printer, speed, NULL);
}

void AddSpriteTextPrinterParameterized4(u8 spriteId, u8 fontId, u8 left, u8 top, u8 letterSpacing, u8 lineSpacing, const u8 *color, s8 speed, const u8 *str)
{
    struct TextPrinterTemplate printer;

    printer.currentChar = str;
    printer.type = SPRITE_TEXT_PRINTER;
    printer.spriteId = spriteId;
    printer.fontId = fontId;
    printer.x = left;
    printer.y = top;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.letterSpacing = letterSpacing;
    printer.lineSpacing = lineSpacing;
    printer.color.background = color[0];
    printer.color.foreground = color[1];
    printer.color.shadow = color[2];
    printer.color.accent = color[0];

    AddTextPrinter(&printer, speed, NULL);
}

void AddSpriteTextPrinterParameterized6(u8 spriteId, u8 fontId, u8 left, u8 top, u8 letterSpacing, u8 lineSpacing, const union TextColor color, s8 speed, const u8 *str)
{
    struct TextPrinterTemplate printer;

    printer.currentChar = str;
    printer.type = SPRITE_TEXT_PRINTER;
    printer.spriteId = spriteId;
    printer.fontId = fontId;
    printer.x = left;
    printer.y = top;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.letterSpacing = letterSpacing;
    printer.lineSpacing = lineSpacing;
    printer.color = color;

    AddTextPrinter(&printer, speed, NULL);
}

bool32 AddTextPrinter(struct TextPrinterTemplate *printerTemplate, u8 speed, void (*callback)(struct TextPrinterTemplate *, u16))
{
    if (!gFonts)
        return FALSE;

    struct TextPrinter sTempTextPrinter = {0};

    sTempTextPrinter.active = TRUE;
    sTempTextPrinter.state = RENDER_STATE_HANDLE_CHAR;
    sTempTextPrinter.printerTemplate = *printerTemplate;
    sTempTextPrinter.callback = callback;
    sTempTextPrinter.textSpeed = speed;

    if (printerTemplate->type == SPRITE_TEXT_PRINTER)
    {
        sTempTextPrinter.printerTemplate.firstSprite = printerTemplate->spriteId;
        sTempTextPrinter.printerTemplate.firstSpriteInRow = printerTemplate->spriteId;
    }


    GenerateFontHalfRowLookupTable(printerTemplate->color);
    if (speed != TEXT_SKIP_DRAW && speed != 0)
    {
        --sTempTextPrinter.textSpeed;
        sTempTextPrinter.isInUse = TRUE;
        struct TextPrinter *printer = AllocateTextPrinter();
        if (printer != NULL)
        {
            *printer = sTempTextPrinter;
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        sTempTextPrinter.textSpeed = 0;

        // Render all text (up to limit) at once
        for (u32 j = 0; j < 0x400; ++j)
        {
            if (RenderFont(&sTempTextPrinter) == RENDER_FINISH)
                break;
        }

        // All the text is rendered but don't draw it yet.
        if (speed != TEXT_SKIP_DRAW)
        {
            switch (sTempTextPrinter.printerTemplate.type)
            {
            case WINDOW_TEXT_PRINTER:
                CopyWindowToVram(sTempTextPrinter.printerTemplate.windowId, COPYWIN_GFX);
                break;
            case SPRITE_TEXT_PRINTER:
                break;
            }
        }
    }
    gDisableTextPrinters = FALSE;
    return TRUE;
}

void RunTextPrinters(void)
{
    bool32 isInstantText = IsPlayerTextSpeedInstant();
    u32 textRepeats = GetPlayerTextSpeedModifier();

    if (gDisableTextPrinters)
        return;

    u32 numPrinters = GetNumTextPrinters();

    struct TextPrinter *currentPrinter = sFirstTextPrinter;

    do
    {
        u32 numEmpty = 0;
        while (currentPrinter != NULL)
        {
            if (currentPrinter->active)
            {
                for (u32 repeat = 0; repeat < textRepeats || isInstantText; repeat++)
                {
                    u32 renderState = RenderFont(currentPrinter);
                    switch (renderState)
                    {
                    case RENDER_PRINT:
                        switch (currentPrinter->printerTemplate.type)
                        {
                        case WINDOW_TEXT_PRINTER:
                            CopyWindowToVram(currentPrinter->printerTemplate.windowId, COPYWIN_GFX);
                            break;
                        case SPRITE_TEXT_PRINTER:
                            break;
                        }
                        if (currentPrinter->callback != NULL)
                            currentPrinter->callback(&currentPrinter->printerTemplate, renderState);
                        break;
                    case RENDER_UPDATE:
                        if (currentPrinter->callback != NULL)
                            currentPrinter->callback(&currentPrinter->printerTemplate, renderState);
                        isInstantText = FALSE;
                        break;
                    case RENDER_FINISH:
                        currentPrinter->active = FALSE;
                        currentPrinter->isInUse = FALSE;
                        isInstantText = FALSE;
                        break;
                    }

                    if (!currentPrinter->active)
                        break;
                }
            }
            else
            {
                numEmpty++;
            }
            currentPrinter = currentPrinter->nextPrinter;
        }

        if (numEmpty == numPrinters)
        {
            FreeFinishedTextPrinters();
            return;
        }
    } while (isInstantText);
    FreeFinishedTextPrinters();
}

bool32 IsTextPrinterActiveOnWindow(u32 windowId)
{
    struct TextPrinter *currentPrinter = sFirstTextPrinter;

    while (currentPrinter != NULL)
    {
        if (currentPrinter->printerTemplate.type == WINDOW_TEXT_PRINTER
         && currentPrinter->printerTemplate.windowId == windowId)
        {
            return currentPrinter->active;
        }
        currentPrinter = currentPrinter->nextPrinter;
    }

    return FALSE;
}

bool32 IsTextPrinterActiveOnSprite(u32 spriteId)
{
    struct TextPrinter *currentPrinter = sFirstTextPrinter;

    while (currentPrinter != NULL)
    {
        if (currentPrinter->printerTemplate.type == SPRITE_TEXT_PRINTER
         && currentPrinter->printerTemplate.firstSprite == spriteId)
        {
            return currentPrinter->active;
        }
        currentPrinter = currentPrinter->nextPrinter;
    }

    return FALSE;
}

static u32 RenderFont(struct TextPrinter *textPrinter)
{
    u32 ret;
    u16 (*fontFunction)(struct TextPrinter *x) = gFonts[textPrinter->printerTemplate.fontId].fontFunction;

    do
    {
        ret = fontFunction(textPrinter);
    } while (ret == RENDER_REPEAT);

    return ret;
}

void GenerateFontHalfRowLookupTable(union TextColor color)
{
    if (color.asU32 == sLastTextColor.asU32)
    {
        return;
    }

    sLastTextColor = color;

    u8 quarterRows[16] = {
        color.background << 4 | color.background,
        color.foreground << 4 | color.background,
        color.shadow << 4     | color.background,
        color.accent << 4     | color.background,
        color.background << 4 | color.foreground,
        color.foreground << 4 | color.foreground,
        color.shadow << 4     | color.foreground,
        color.accent << 4     | color.foreground,
        color.background << 4 | color.shadow,
        color.foreground << 4 | color.shadow,
        color.shadow << 4     | color.shadow,
        color.accent << 4     | color.shadow,
        color.background << 4 | color.accent,
        color.foreground << 4 | color.accent,
        color.shadow << 4     | color.accent,
        color.accent << 4     | color.accent,
    };

    u8 *current = (u8 *)sFontHalfRowLookupTable;

    for (u32 i = 0; i < 16; i++)
    {
        for (u32 j = 0; j < 16; j++)
        {
            *(current++) = quarterRows[i];
            *(current++) = quarterRows[j];
        }
    }
}

union TextColor SaveTextColors(void)
{
    return sLastTextColor;
}

void RestoreTextColors(union TextColor color)
{
    GenerateFontHalfRowLookupTable(color);
}

void DecompressGlyphTile(const void *src_, void *dest_)
{
    u32 temp;
    const u16 *src = src_;
    u32 *dest = dest_;

    temp = *(src++);
    *(dest++) = (sFontHalfRowLookupTable[temp & 0xFF] << 16) | (sFontHalfRowLookupTable[temp >> 8]);

    temp = *(src++);
    *(dest++) = (sFontHalfRowLookupTable[temp & 0xFF] << 16) | (sFontHalfRowLookupTable[temp >> 8]);

    temp = *(src++);
    *(dest++) = (sFontHalfRowLookupTable[temp & 0xFF] << 16) | (sFontHalfRowLookupTable[temp >> 8]);

    temp = *(src++);
    *(dest++) = (sFontHalfRowLookupTable[temp & 0xFF] << 16) | (sFontHalfRowLookupTable[temp >> 8]);

    temp = *(src++);
    *(dest++) = (sFontHalfRowLookupTable[temp & 0xFF] << 16) | (sFontHalfRowLookupTable[temp >> 8]);

    temp = *(src++);
    *(dest++) = (sFontHalfRowLookupTable[temp & 0xFF] << 16) | (sFontHalfRowLookupTable[temp >> 8]);

    temp = *(src++);
    *(dest++) = (sFontHalfRowLookupTable[temp & 0xFF] << 16) | (sFontHalfRowLookupTable[temp >> 8]);

    temp = *(src++);
    *(dest++) = (sFontHalfRowLookupTable[temp & 0xFF] << 16) | (sFontHalfRowLookupTable[temp >> 8]);
}

static u8 UNUSED GetLastTextColor(enum TextColorType colorType)
{
    switch (colorType)
    {
    case TEXT_COLOR_TYPE_FOREGROUND:
        return sLastTextColor.foreground;
    case TEXT_COLOR_TYPE_HIGHLIGHT:
    case TEXT_COLOR_TYPE_BACKGROUND:
        return sLastTextColor.background;
    case TEXT_COLOR_TYPE_SHADOW:
        return sLastTextColor.shadow;
    case TEXT_COLOR_TYPE_ACCENT:
        return sLastTextColor.accent;
    default:
        return TEXT_COLOR_TRANSPARENT;
    }
}

static u32 OffsetCurrGlyph(u32 shiftWidth)
{
    u32 newWidth = gCurGlyph.width - shiftWidth;

    if (gCurGlyph.width <= 8)
    {
        for (u32 i = 0; i < 8; i++)
        {
            gCurGlyph.gfxBufferTop[i] = gCurGlyph.gfxBufferTop[i] >> (4 * shiftWidth);
            gCurGlyph.gfxBufferBottom[i] = gCurGlyph.gfxBufferBottom[i] >> (4 * shiftWidth);
        }
    }
    else
    {
        //  Do cursed u64 handling of double wide glyphs
        for (u32 i = 0; i < 8; i++)
        {
            u64 tempVal = gCurGlyph.gfxBufferTop[8 + i];
            u64 topVal = (tempVal << 32) | gCurGlyph.gfxBufferTop[i];
            tempVal = gCurGlyph.gfxBufferBottom[8 + i];
            u64 bottomVal = (tempVal << 32) | gCurGlyph.gfxBufferBottom[i];
            topVal = topVal >> (4 * shiftWidth);
            bottomVal = bottomVal >> (4 * shiftWidth);

            gCurGlyph.gfxBufferTop[i] = topVal & 0xFFFFFFFF;
            gCurGlyph.gfxBufferTop[8 + i] = topVal >> 32;

            gCurGlyph.gfxBufferBottom[i] = bottomVal & 0xFFFFFFFF;
            gCurGlyph.gfxBufferBottom[8 + i] = bottomVal >> 32;
        }
    }

    gCurGlyph.width = newWidth;
    return newWidth;
}

inline static void GLYPH_COPY(u8 *windowTiles, u32 widthOffset, u32 x0, u32 y0, u32 *glyphPixels, s32 width, s32 height)
{
    if (width <= 0)
        return;

    u32 widthMask = (1 << (width * 4)) - 1;

    u32 shift0 = (x0 % 8) * 4, shift8 = 32 - shift0;

    u32 *alignedWindowTilesX = (u32 *)(windowTiles + ((x0 / 8) * TILE_SIZE_4BPP));

    u32 y1 = y0 + height;
    for (u32 y = y0; y < y1; y++)
    {
        u32 pixels = *glyphPixels++ & widthMask;

        u32 mask = pixels;
        mask = mask | (mask >> 2);
        mask = mask | (mask >> 1);
        mask = mask & 0x11111111;
        mask = mask * 0xF;

        u32 pixels0 = pixels << shift0, pixels8 = pixels >> shift8;
        u32 mask0 = mask << shift0, mask8 = mask >> shift8;

        u32 *alignedWindowTiles = (u32 *)((u8 *)alignedWindowTilesX + ((y / 8) * widthOffset) + ((y % 8) * 4));

        alignedWindowTiles[0] = (alignedWindowTiles[0] & ~mask0) | pixels0;
        alignedWindowTiles[8] = (alignedWindowTiles[8] & ~mask8) | pixels8;
    }
}

u32 CopyGlyphToVRAM(struct TextPrinter *textPrinter)
{
    u32 *glyphPixels;
    u32 currX, currY, widthOffset;
    s32 glyphWidth, glyphHeight;

    struct Window *window;
    struct WindowTemplate *template;
    u8 *destTiles;

    struct Sprite *sprite;

    bool32 wasCutOff = FALSE;

    currX = textPrinter->printerTemplate.currentX;
    currY = textPrinter->printerTemplate.currentY;
    glyphPixels = gCurGlyph.gfxBufferTop;

    switch (textPrinter->printerTemplate.type)
    {
    case WINDOW_TEXT_PRINTER:
        window = &gWindows[textPrinter->printerTemplate.windowId];
        template = &window->window;

        if ((glyphWidth = (template->width * 8) - textPrinter->printerTemplate.currentX) > gCurGlyph.width)
            glyphWidth = gCurGlyph.width;

        if ((glyphHeight = (template->height * 8) - textPrinter->printerTemplate.currentY) > gCurGlyph.height)
            glyphHeight = gCurGlyph.height;
        destTiles = window->tileData;
        widthOffset = template->width * 32;
        break;
    case SPRITE_TEXT_PRINTER:
        sprite = &gSprites[textPrinter->printerTemplate.spriteId];
        destTiles = (void*)(OBJ_VRAM0) + sprite->oam.tileNum * TILE_SIZE_4BPP;

        if ((glyphWidth = GetSpriteWidth(sprite) - textPrinter->printerTemplate.currentX) > gCurGlyph.width)
            glyphWidth = gCurGlyph.width;
        else
            wasCutOff = TRUE;

        if ((glyphHeight = GetSpriteHeight(sprite) - textPrinter->printerTemplate.currentY) > gCurGlyph.height)
            glyphHeight = gCurGlyph.height;

        widthOffset = GetSpriteWidth(sprite) * 4;
        break;
    default:
        errorf("Illegal printer type");
        return 0;
    }

    if (glyphWidth < 9)
    {
        if (glyphHeight < 9)
        {
            GLYPH_COPY(destTiles, widthOffset, currX, currY, glyphPixels, glyphWidth, glyphHeight);
        }
        else
        {
            GLYPH_COPY(destTiles, widthOffset, currX, currY, glyphPixels, glyphWidth, 8);
            GLYPH_COPY(destTiles, widthOffset, currX, currY + 8, glyphPixels + 16, glyphWidth, glyphHeight - 8);
        }
    }
    else
    {
        if (glyphHeight < 9)
        {
            GLYPH_COPY(destTiles, widthOffset, currX, currY, glyphPixels, 8, glyphHeight);
            GLYPH_COPY(destTiles, widthOffset, currX + 8, currY, glyphPixels + 8, glyphWidth - 8, glyphHeight);
        }
        else
        {
            GLYPH_COPY(destTiles, widthOffset, currX, currY, glyphPixels, 8, 8);
            GLYPH_COPY(destTiles, widthOffset, currX + 8, currY, glyphPixels + 8, glyphWidth - 8, 8);
            GLYPH_COPY(destTiles, widthOffset, currX, currY + 8, glyphPixels + 16, 8, glyphHeight - 8);
            GLYPH_COPY(destTiles, widthOffset, currX + 8, currY + 8, glyphPixels + 24, glyphWidth - 8, glyphHeight - 8);
        }
    }

    //  Handle Y cutoff
    if (textPrinter->printerTemplate.type == SPRITE_TEXT_PRINTER
     && glyphHeight != gCurGlyph.height)
    {
        sprite = &gSprites[gSprites[textPrinter->printerTemplate.spriteId].data[2]];
        destTiles = (void*)(OBJ_VRAM0) + sprite->oam.tileNum * TILE_SIZE_4BPP;

        u32 newHeight = gCurGlyph.height - glyphHeight;

        u32 leftHalf[16];
        u32 rightHalf[16];

        if (gCurGlyph.width > 8)
        {
            for (u32 i = 0; i < 8; i++)
            {
                leftHalf[i] = gCurGlyph.gfxBufferTop[i];
                leftHalf[8 + i] = gCurGlyph.gfxBufferBottom[i];
                rightHalf[i] = gCurGlyph.gfxBufferTop[8 + i];
                rightHalf[8 + i] = gCurGlyph.gfxBufferBottom[8 + i];
            }

            for (u32 i = 0; i < newHeight; i++)
            {
                leftHalf[i] = leftHalf[glyphHeight + i];
                rightHalf[i] = rightHalf[glyphHeight + i];
            }
        }
        else
        {
            for (u32 i = 0; i < 8; i++)
            {
                leftHalf[i] = gCurGlyph.gfxBufferTop[i];
                leftHalf[8 + i] = gCurGlyph.gfxBufferBottom[i];
            }

            for (u32 i = 0; i < newHeight; i++)
                leftHalf[i] = leftHalf[glyphHeight + i];
        }

        glyphHeight = newHeight;

        if (glyphWidth < 9)
        {
            if (glyphHeight < 9)
            {
                GLYPH_COPY(destTiles, widthOffset, currX, 0, leftHalf, glyphWidth, glyphHeight);
            }
            else
            {
                GLYPH_COPY(destTiles, widthOffset, currX, 0, leftHalf, glyphWidth, 8);
                GLYPH_COPY(destTiles, widthOffset, currX, 8, &leftHalf[8], glyphWidth, glyphHeight - 8);
            }
        }
        else
        {
            if (glyphHeight < 9)
            {
                GLYPH_COPY(destTiles, widthOffset, currX, 0, leftHalf, 8, glyphHeight);
                GLYPH_COPY(destTiles, widthOffset, currX + 8, 0, rightHalf, glyphWidth - 8, glyphHeight);
            }
            else
            {
                GLYPH_COPY(destTiles, widthOffset, currX, 0, leftHalf, 8, 8);
                GLYPH_COPY(destTiles, widthOffset, currX + 8, 0, rightHalf, glyphWidth - 8, 8);
                GLYPH_COPY(destTiles, widthOffset, currX, 8, &leftHalf[8], 8, glyphHeight - 8);
                GLYPH_COPY(destTiles, widthOffset, currX + 8, 8, &rightHalf[8], glyphWidth - 8, glyphHeight - 8);
            }
        }
    }

    if (wasCutOff)
        return glyphWidth;

    return 0;
}

#define nextX data[1]
#define nextY data[2]

static void PrintGlyph(struct TextPrinter *textPrinter)
{
    u32 cutOffAmount = CopyGlyphToVRAM(textPrinter);

    //  Handle switching to next sprite here
    if (textPrinter->printerTemplate.type == SPRITE_TEXT_PRINTER
     && cutOffAmount > 0
     && gSprites[textPrinter->printerTemplate.spriteId].nextX != SPRITE_NONE)
    {
        //  Set the data to the next sprite
        textPrinter->printerTemplate.spriteId = gSprites[textPrinter->printerTemplate.spriteId].nextX;
        textPrinter->printerTemplate.currentX = 0;

        //  Copy the remaining part of the glyph to the sprite
        //  Offset the current glyph
        u32 newWidth = OffsetCurrGlyph(cutOffAmount);
        CopyGlyphToVRAM(textPrinter);

        //  Set the print offset for the next glyph
        textPrinter->printerTemplate.currentX = newWidth;

    }
    else
    {
        if (textPrinter->minLetterSpacing)
        {
            textPrinter->printerTemplate.currentX += gCurGlyph.width;
            u32 width = textPrinter->minLetterSpacing - gCurGlyph.width;
            if (width > 0)
            {
                ClearTextSpan(textPrinter, width);
                textPrinter->printerTemplate.currentX += width;
            }
        }
        else
        {
            if (textPrinter->japanese)
                textPrinter->printerTemplate.currentX += (gCurGlyph.width + textPrinter->printerTemplate.letterSpacing);
            else
                textPrinter->printerTemplate.currentX += gCurGlyph.width;
        }
    }
}

void ClearTextSpan(struct TextPrinter *textPrinter, u32 width)
{
    struct Window *window;
    struct Bitmap pixels_data;
    struct TextGlyph *glyph;
    u8 *glyphHeight;

    if (sLastTextColor.background != TEXT_COLOR_TRANSPARENT)
    {
        window = &gWindows[textPrinter->printerTemplate.windowId];
        pixels_data.pixels = window->tileData;
        pixels_data.width = window->window.width << 3;
        pixels_data.height = window->window.height << 3;

        glyph = &gCurGlyph;
        glyphHeight = &glyph->height;

        FillBitmapRect4Bit(
            &pixels_data,
            textPrinter->printerTemplate.currentX,
            textPrinter->printerTemplate.currentY,
            width,
            *glyphHeight,
            sLastTextColor.background);
    }
}

static u16 FontFunc_Small(struct TextPrinter *textPrinter)
{
    if (textPrinter->hasFontIdBeenSet == FALSE)
    {
        textPrinter->fontId = FONT_SMALL;
        textPrinter->hasFontIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

static u16 FontFunc_Normal(struct TextPrinter *textPrinter)
{
    if (textPrinter->hasFontIdBeenSet == FALSE)
    {
        textPrinter->fontId = FONT_NORMAL;
        textPrinter->hasFontIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

static u16 FontFunc_Short(struct TextPrinter *textPrinter)
{
    if (textPrinter->hasFontIdBeenSet == FALSE)
    {
        textPrinter->fontId = FONT_SHORT;
        textPrinter->hasFontIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

static u16 FontFunc_ShortCopy1(struct TextPrinter *textPrinter)
{
    if (textPrinter->hasFontIdBeenSet == FALSE)
    {
        textPrinter->fontId = FONT_SHORT_COPY_1;
        textPrinter->hasFontIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

static u16 FontFunc_ShortCopy2(struct TextPrinter *textPrinter)
{
    if (textPrinter->hasFontIdBeenSet == FALSE)
    {
        textPrinter->fontId = FONT_SHORT_COPY_2;
        textPrinter->hasFontIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

static u16 FontFunc_ShortCopy3(struct TextPrinter *textPrinter)
{
    if (textPrinter->hasFontIdBeenSet == FALSE)
    {
        textPrinter->fontId = FONT_SHORT_COPY_3;
        textPrinter->hasFontIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

static u16 FontFunc_Narrow(struct TextPrinter *textPrinter)
{
    if (textPrinter->hasFontIdBeenSet == FALSE)
    {
        textPrinter->fontId = FONT_NARROW;
        textPrinter->hasFontIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

static u16 FontFunc_SmallNarrow(struct TextPrinter *textPrinter)
{
    if (textPrinter->hasFontIdBeenSet == FALSE)
    {
        textPrinter->fontId = FONT_SMALL_NARROW;
        textPrinter->hasFontIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

static u16 FontFunc_Narrower(struct TextPrinter *textPrinter)
{
    if (textPrinter->hasFontIdBeenSet == FALSE)
    {
        textPrinter->fontId = FONT_NARROWER;
        textPrinter->hasFontIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

static u16 FontFunc_SmallNarrower(struct TextPrinter *textPrinter)
{
    if (textPrinter->hasFontIdBeenSet == FALSE)
    {
        textPrinter->fontId = FONT_SMALL_NARROWER;
        textPrinter->hasFontIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

static u16 FontFunc_ShortNarrow(struct TextPrinter *textPrinter)
{
    if (textPrinter->hasFontIdBeenSet == FALSE)
    {
        textPrinter->fontId = FONT_SHORT_NARROW;
        textPrinter->hasFontIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

static u16 FontFunc_ShortNarrower(struct TextPrinter *textPrinter)
{
    if (textPrinter->hasFontIdBeenSet == FALSE)
    {
        textPrinter->fontId = FONT_SHORT_NARROWER;
        textPrinter->hasFontIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

void TextPrinterInitDownArrowCounters(struct TextPrinter *textPrinter)
{
    if (gTextFlags.autoScroll == 1)
    {
        textPrinter->autoScrollDelay = 0;
    }
    else
    {
        textPrinter->downArrowYPosIdx = 0;
        textPrinter->utilityCounter = 0;
    }
}

void TextPrinterDrawDownArrow(struct TextPrinter *textPrinter)
{
    const u8 *arrowTiles;

    if (gTextFlags.autoScroll == 0)
    {
        if (textPrinter->utilityCounter != 0)
        {
            textPrinter->utilityCounter--;
        }
        else
        {
            FillWindowPixelRect(
                textPrinter->printerTemplate.windowId,
                textPrinter->printerTemplate.color.background << 4 | textPrinter->printerTemplate.color.background,
                textPrinter->printerTemplate.currentX,
                textPrinter->printerTemplate.currentY,
                8,
                16);

            switch (gTextFlags.useAlternateDownArrow)
            {
            case FALSE:
            default:
                arrowTiles = sDownArrowTiles;
                break;
            case TRUE:
                arrowTiles = sDarkDownArrowTiles;
                break;
            }

            BlitBitmapRectToWindow(
                textPrinter->printerTemplate.windowId,
                arrowTiles,
                0,
                sDownArrowYCoords[textPrinter->downArrowYPosIdx],
                8,
                16,
                textPrinter->printerTemplate.currentX,
                textPrinter->printerTemplate.currentY,
                8,
                16);
            CopyWindowToVram(textPrinter->printerTemplate.windowId, COPYWIN_GFX);

            textPrinter->utilityCounter = 8 * GetPlayerTextSpeedModifier();
            textPrinter->downArrowYPosIdx++;
        }
    }
}

void TextPrinterClearDownArrow(struct TextPrinter *textPrinter)
{
    FillWindowPixelRect(
        textPrinter->printerTemplate.windowId,
        textPrinter->printerTemplate.color.background << 4 | textPrinter->printerTemplate.color.background,
        textPrinter->printerTemplate.currentX,
        textPrinter->printerTemplate.currentY,
        8,
        16);
    CopyWindowToVram(textPrinter->printerTemplate.windowId, COPYWIN_GFX);
}

bool32 TextPrinterWaitAutoMode(struct TextPrinter *textPrinter)
{
    if (textPrinter->autoScrollDelay == NUM_FRAMES_AUTO_SCROLL_DELAY)
    {
        textPrinter->autoScrollDelay = 0;
        return TRUE;
    }
    else
    {
        textPrinter->autoScrollDelay++;
        return FALSE;
    }
}

void SetResultWithButtonPress(bool32 *result)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        *result = TRUE;
        PlaySE(SE_SELECT);
    }
}

bool32 TextPrinterWaitWithDownArrow(struct TextPrinter *textPrinter)
{
    bool32 result = FALSE;
    if (gTextFlags.autoScroll != 0 || AUTO_SCROLL_TEXT)
    {
        result = TextPrinterWaitAutoMode(textPrinter);

        if (AUTO_SCROLL_TEXT)
            SetResultWithButtonPress(&result);
    }
    else
    {
        TextPrinterDrawDownArrow(textPrinter);
        SetResultWithButtonPress(&result);
    }
    return result;
}

bool32 TextPrinterWait(struct TextPrinter *textPrinter)
{
    bool32 result = FALSE;
    if (gTextFlags.autoScroll != 0 || AUTO_SCROLL_TEXT)
    {
        result = TextPrinterWaitAutoMode(textPrinter);

        if (AUTO_SCROLL_TEXT)
            SetResultWithButtonPress(&result);
    }
    else
    {
        SetResultWithButtonPress(&result);
    }
    return result;
}

void DrawDownArrow(u8 windowId, u16 x, u16 y, u8 bgColor, bool32 drawArrow, u8 *counter, u8 *yCoordIndex)
{
    const u8 *arrowTiles;

    if (*counter != 0)
    {
        --*counter;
    }
    else
    {
        FillWindowPixelRect(windowId, (bgColor << 4) | bgColor, x, y, 0x8, 0x10);
        if (!drawArrow)
        {
            switch (gTextFlags.useAlternateDownArrow)
            {
            case FALSE:
            default:
                arrowTiles = sDownArrowTiles;
                break;
            case TRUE:
                arrowTiles = sDarkDownArrowTiles;
                break;
            }

            BlitBitmapRectToWindow(windowId, arrowTiles, 0, sDownArrowYCoords[*yCoordIndex & 3], 8, 16, x, y - 2, 8, 16);
            CopyWindowToVram(windowId, COPYWIN_GFX);
            *counter = 8 * GetPlayerTextSpeedModifier();
            ++*yCoordIndex;
        }
    }
}

static u16 RenderText(struct TextPrinter *textPrinter)
{
    u16 currChar;
    s32 width;
    s32 widthHelper;

    switch (textPrinter->state)
    {
    case RENDER_STATE_HANDLE_CHAR:
        if ((JOY_HELD(A_BUTTON | B_BUTTON) && textPrinter->hasPrintBeenSpedUp) || IsPlayerTextSpeedInstant())
            textPrinter->delayCounter = 0;

        if (textPrinter->delayCounter && textPrinter->textSpeed)
        {
            textPrinter->delayCounter--;
            if (gTextFlags.canABSpeedUpPrint && (JOY_NEW(A_BUTTON | B_BUTTON)))
            {
                textPrinter->hasPrintBeenSpedUp = TRUE;
                textPrinter->delayCounter = 0;
            }
            return RENDER_UPDATE;
        }

        if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED) && gTextFlags.autoScroll)
            textPrinter->delayCounter = 3;
        else
            textPrinter->delayCounter = textPrinter->textSpeed;

        do {
            currChar = *textPrinter->printerTemplate.currentChar;
            textPrinter->printerTemplate.currentChar++;
        } while (currChar == CHAR_ZWS);

        switch (currChar)
        {
        case CHAR_NEWLINE:
            textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x;
            textPrinter->printerTemplate.currentY += (gFonts[textPrinter->printerTemplate.fontId].maxLetterHeight + textPrinter->printerTemplate.lineSpacing);
            if (textPrinter->printerTemplate.type == SPRITE_TEXT_PRINTER)
            {
                struct Sprite *sprite = &gSprites[textPrinter->printerTemplate.spriteId];
                textPrinter->printerTemplate.spriteId = textPrinter->printerTemplate.firstSpriteInRow;
                if (textPrinter->printerTemplate.currentY  >= GetSpriteHeight(sprite)
                 && gSprites[textPrinter->printerTemplate.spriteId].nextY != SPRITE_NONE)
                {
                    textPrinter->printerTemplate.currentY = textPrinter->printerTemplate.currentY - GetSpriteHeight(sprite);
                    textPrinter->printerTemplate.spriteId = gSprites[textPrinter->printerTemplate.firstSpriteInRow].nextY;
                    textPrinter->printerTemplate.firstSpriteInRow = textPrinter->printerTemplate.spriteId;
                }
            }
            return RENDER_REPEAT;
        case PLACEHOLDER_BEGIN:
            textPrinter->printerTemplate.currentChar++;
            return RENDER_REPEAT;
        case EXT_CTRL_CODE_BEGIN:
            currChar = *textPrinter->printerTemplate.currentChar;
            textPrinter->printerTemplate.currentChar++;
            switch (currChar)
            {
            case EXT_CTRL_CODE_BACKGROUND:
                textPrinter->printerTemplate.color.background = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                GenerateFontHalfRowLookupTable(textPrinter->printerTemplate.color);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_COLOR:
                textPrinter->printerTemplate.color.foreground = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                GenerateFontHalfRowLookupTable(textPrinter->printerTemplate.color);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_SHADOW:
                textPrinter->printerTemplate.color.shadow = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                GenerateFontHalfRowLookupTable(textPrinter->printerTemplate.color);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_ACCENT:
                textPrinter->printerTemplate.color.accent = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                GenerateFontHalfRowLookupTable(textPrinter->printerTemplate.color);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_HIGHLIGHT:
                textPrinter->printerTemplate.color.background = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.color.accent = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                GenerateFontHalfRowLookupTable(textPrinter->printerTemplate.color);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW:
                textPrinter->printerTemplate.color.foreground = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                textPrinter->printerTemplate.color.background = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.color.accent = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                textPrinter->printerTemplate.color.shadow = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                GenerateFontHalfRowLookupTable(textPrinter->printerTemplate.color);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_TEXT_COLORS:
                textPrinter->printerTemplate.color.foreground = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                textPrinter->printerTemplate.color.shadow = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                textPrinter->printerTemplate.color.accent = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                GenerateFontHalfRowLookupTable(textPrinter->printerTemplate.color);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_PALETTE:
                textPrinter->printerTemplate.currentChar++;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_FONT:
                textPrinter->fontId = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_RESET_FONT:
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_PAUSE:
                textPrinter->delayCounter = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                textPrinter->state = RENDER_STATE_PAUSE;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_PAUSE_UNTIL_PRESS:
                textPrinter->state = RENDER_STATE_WAIT;
                if (gTextFlags.autoScroll)
                    textPrinter->autoScrollDelay = 0;
                return RENDER_UPDATE;
            case EXT_CTRL_CODE_WAIT_SE:
                textPrinter->state = RENDER_STATE_WAIT_SE;
                return RENDER_UPDATE;
            case EXT_CTRL_CODE_PLAY_BGM:
                currChar = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                currChar |= *textPrinter->printerTemplate.currentChar << 8;
                textPrinter->printerTemplate.currentChar++;
                PlayBGM(currChar);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_ESCAPE:
                currChar = *textPrinter->printerTemplate.currentChar | 0x100;
                textPrinter->printerTemplate.currentChar++;
                break;
            case EXT_CTRL_CODE_PLAY_SE:
                currChar = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                currChar |= (*textPrinter->printerTemplate.currentChar << 8);
                textPrinter->printerTemplate.currentChar++;
                PlaySE(currChar);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_SHIFT_RIGHT:
                textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x + *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_SHIFT_DOWN:
                textPrinter->printerTemplate.currentY = textPrinter->printerTemplate.y + *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_FILL_WINDOW:
                if (textPrinter->printerTemplate.type == WINDOW_TEXT_PRINTER)
                {
                    FillWindowPixelBuffer(textPrinter->printerTemplate.windowId, PIXEL_FILL(textPrinter->printerTemplate.color.background));
                    textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x;
                    textPrinter->printerTemplate.currentY = textPrinter->printerTemplate.y;
                }
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_PAUSE_MUSIC:
                m4aMPlayStop(&gMPlayInfo_BGM);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_RESUME_MUSIC:
                m4aMPlayContinue(&gMPlayInfo_BGM);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_CLEAR:
                width = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                if (width > 0)
                {
                    ClearTextSpan(textPrinter, width);
                    textPrinter->printerTemplate.currentX += width;
                    return RENDER_PRINT;
                }
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_SKIP:
                textPrinter->printerTemplate.currentX = *textPrinter->printerTemplate.currentChar + textPrinter->printerTemplate.x;
                textPrinter->printerTemplate.currentChar++;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_CLEAR_TO:
                {
                    widthHelper = *textPrinter->printerTemplate.currentChar;
                    widthHelper += textPrinter->printerTemplate.x;
                    textPrinter->printerTemplate.currentChar++;
                    width = widthHelper - textPrinter->printerTemplate.currentX;
                    if (width > 0)
                    {
                        ClearTextSpan(textPrinter, width);
                        textPrinter->printerTemplate.currentX += width;
                        return RENDER_PRINT;
                    }
                }
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_MIN_LETTER_SPACING:
                textPrinter->minLetterSpacing = *textPrinter->printerTemplate.currentChar++;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_JPN:
                textPrinter->japanese = TRUE;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_ENG:
                textPrinter->japanese = FALSE;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_SPEAKER:
                {
                    enum SpeakerNames name = *textPrinter->printerTemplate.currentChar++;
                    TrySpawnAndShowNamebox(gSpeakerNamesTable[name], NAME_BOX_BASE_TILE_NUM);

                    return RENDER_REPEAT;
                }
            }
            break;
        case CHAR_PROMPT_CLEAR:
            textPrinter->state = RENDER_STATE_CLEAR;
            TextPrinterInitDownArrowCounters(textPrinter);
            return RENDER_UPDATE;
        case CHAR_PROMPT_SCROLL:
            textPrinter->state = RENDER_STATE_SCROLL_START;
            TextPrinterInitDownArrowCounters(textPrinter);
            return RENDER_UPDATE;
        case CHAR_EXTRA_SYMBOL:
            currChar = *textPrinter->printerTemplate.currentChar | 0x100;
            textPrinter->printerTemplate.currentChar++;
            break;
        case CHAR_KEYPAD_ICON:
            if (textPrinter->printerTemplate.type == WINDOW_TEXT_PRINTER)
            {
                currChar = *textPrinter->printerTemplate.currentChar++;
                gCurGlyph.width = DrawKeypadIcon(textPrinter->printerTemplate.windowId, currChar, textPrinter->printerTemplate.currentX, textPrinter->printerTemplate.currentY);
                textPrinter->printerTemplate.currentX += gCurGlyph.width + textPrinter->printerTemplate.letterSpacing;
                return RENDER_PRINT;
            }
            else
            {
                //  Loop over how many 8 px wide glyphs the icon needs
                u32 keypadIconId = *textPrinter->printerTemplate.currentChar++;
                u32 numTiles = sKeypadIcons[keypadIconId].width / 8;
                for (u32 i = 0; i < numTiles; i++)
                {
                    //  Fill the current glyph part
                    for (u32 j = 0; j < 8; j++)
                    {
                        gCurGlyph.gfxBufferTop[j] = ((u32 *)(sKeypadIconTiles + ((i + sKeypadIcons[keypadIconId].tileOffset) * 0x20)))[j];
                        gCurGlyph.gfxBufferBottom[j] = ((u32 *)(sKeypadIconTiles + ((i + 16 + sKeypadIcons[keypadIconId].tileOffset) * 0x20)))[j];
                    }
                    gCurGlyph.width = 8;
                    PrintGlyph(textPrinter);
                }
                return RENDER_PRINT;
            }
        case EOS:
            textPrinter->isInUse = FALSE;
            return RENDER_FINISH;
        }

        switch (textPrinter->fontId)
        {
        case FONT_SMALL:
            DecompressGlyph_Small(currChar, textPrinter->japanese);
            break;
        case FONT_NORMAL:
            DecompressGlyph_Normal(currChar, textPrinter->japanese);
            break;
        case FONT_SHORT:
        case FONT_SHORT_COPY_1:
        case FONT_SHORT_COPY_2:
        case FONT_SHORT_COPY_3:
            DecompressGlyph_Short(currChar, textPrinter->japanese);
            break;
        case FONT_NARROW:
            DecompressGlyph_Narrow(currChar, textPrinter->japanese);
            break;
        case FONT_SMALL_NARROW:
            DecompressGlyph_SmallNarrow(currChar, textPrinter->japanese);
            break;
        case FONT_NARROWER:
            DecompressGlyph_Narrower(currChar, textPrinter->japanese);
            break;
        case FONT_SMALL_NARROWER:
            DecompressGlyph_SmallNarrower(currChar, textPrinter->japanese);
            break;
        case FONT_SHORT_NARROW:
            DecompressGlyph_ShortNarrow(currChar, textPrinter->japanese);
            break;
        case FONT_SHORT_NARROWER:
            DecompressGlyph_ShortNarrower(currChar, textPrinter->japanese);
            break;
        case FONT_BRAILLE:
            break;
        }

        PrintGlyph(textPrinter);

        return RENDER_PRINT;
    case RENDER_STATE_WAIT:
        if (TextPrinterWait(textPrinter))
            textPrinter->state = RENDER_STATE_HANDLE_CHAR;
        return RENDER_UPDATE;
    case RENDER_STATE_CLEAR:
        if (textPrinter->printerTemplate.type == WINDOW_TEXT_PRINTER && TextPrinterWaitWithDownArrow(textPrinter))
        {
            FillWindowPixelBuffer(textPrinter->printerTemplate.windowId, PIXEL_FILL(textPrinter->printerTemplate.color.background));
            textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x;
            textPrinter->printerTemplate.currentY = textPrinter->printerTemplate.y;
            textPrinter->state = RENDER_STATE_HANDLE_CHAR;
        }
        return RENDER_UPDATE;
    case RENDER_STATE_SCROLL_START:
        if (TextPrinterWaitWithDownArrow(textPrinter))
        {
            textPrinter->utilityCounter = 0;
            TextPrinterClearDownArrow(textPrinter);
            textPrinter->scrollDistance = gFonts[textPrinter->printerTemplate.fontId].maxLetterHeight + textPrinter->printerTemplate.lineSpacing;
            textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x;
            textPrinter->state = RENDER_STATE_SCROLL;
        }
        return RENDER_UPDATE;
    case RENDER_STATE_SCROLL:
        if (textPrinter->scrollDistance)
        {
            u32 scrollSpeed = GetPlayerTextScrollSpeed();
            u32 speedModifier = GetPlayerTextSpeedModifier();

            if (textPrinter->utilityCounter != 0)
            {
                textPrinter->utilityCounter--;
                return RENDER_UPDATE;
            }

            if (textPrinter->scrollDistance < scrollSpeed)
            {
                ScrollWindow(textPrinter->printerTemplate.windowId, 0, textPrinter->scrollDistance, PIXEL_FILL(textPrinter->printerTemplate.color.background));
                textPrinter->scrollDistance = 0;
            }
            else
            {
                ScrollWindow(textPrinter->printerTemplate.windowId, 0, scrollSpeed, PIXEL_FILL(textPrinter->printerTemplate.color.background));
                textPrinter->scrollDistance -= scrollSpeed;
            }

            if (speedModifier > 1)
                textPrinter->utilityCounter = speedModifier;
            else
                textPrinter->utilityCounter = 0;

            CopyWindowToVram(textPrinter->printerTemplate.windowId, COPYWIN_GFX);
        }
        else
        {
            textPrinter->state = RENDER_STATE_HANDLE_CHAR;
        }
        return RENDER_UPDATE;
    case RENDER_STATE_WAIT_SE:
        if (!IsSEPlaying())
            textPrinter->state = RENDER_STATE_HANDLE_CHAR;
        return RENDER_UPDATE;
    case RENDER_STATE_PAUSE:
        if (textPrinter->delayCounter != 0)
            textPrinter->delayCounter--;
        else
            textPrinter->state = RENDER_STATE_HANDLE_CHAR;
        return RENDER_UPDATE;
    }

    textPrinter->isInUse = FALSE;
    return RENDER_FINISH;
}

#undef nextX
#undef nextY

static u32 UNUSED GetStringWidthFixedWidthFont(const u8 *str, u8 fontId, u8 letterSpacing)
{
    int i;
    u8 width;
    int temp;
    int temp2;
    u8 line;
    int strPos;
    u8 lineWidths[8];
    const u8 *strLocal;

    for (i = 0; i < (int)ARRAY_COUNT(lineWidths); i++)
        lineWidths[i] = 0;

    width = 0;
    line = 0;
    strLocal = str;
    strPos = 0;

    do
    {
        temp = strLocal[strPos++];
        switch (temp)
        {
        case CHAR_NEWLINE:
        case EOS:
            lineWidths[line] = width;
            width = 0;
            line++;
            break;
        case EXT_CTRL_CODE_BEGIN:
            temp2 = strLocal[strPos++];
            switch (temp2)
            {
            case EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW:
            case EXT_CTRL_CODE_TEXT_COLORS:
                ++strPos;
            case EXT_CTRL_CODE_PLAY_BGM:
            case EXT_CTRL_CODE_PLAY_SE:
                ++strPos;
            case EXT_CTRL_CODE_BACKGROUND:
            case EXT_CTRL_CODE_COLOR:
            case EXT_CTRL_CODE_SHADOW:
            case EXT_CTRL_CODE_ACCENT:
            case EXT_CTRL_CODE_HIGHLIGHT:
            case EXT_CTRL_CODE_PALETTE:
            case EXT_CTRL_CODE_FONT:
            case EXT_CTRL_CODE_PAUSE:
            case EXT_CTRL_CODE_ESCAPE:
            case EXT_CTRL_CODE_SHIFT_RIGHT:
            case EXT_CTRL_CODE_SHIFT_DOWN:
            case EXT_CTRL_CODE_CLEAR:
            case EXT_CTRL_CODE_SKIP:
            case EXT_CTRL_CODE_CLEAR_TO:
            case EXT_CTRL_CODE_MIN_LETTER_SPACING:
            case EXT_CTRL_CODE_SPEAKER:
                ++strPos;
                break;
            case EXT_CTRL_CODE_RESET_FONT:
            case EXT_CTRL_CODE_PAUSE_UNTIL_PRESS:
            case EXT_CTRL_CODE_WAIT_SE:
            case EXT_CTRL_CODE_FILL_WINDOW:
            case EXT_CTRL_CODE_JPN:
            case EXT_CTRL_CODE_ENG:
            default:
                break;
            }
            break;
        case CHAR_DYNAMIC:
        case PLACEHOLDER_BEGIN:
            ++strPos;
            break;
        case CHAR_PROMPT_SCROLL:
        case CHAR_PROMPT_CLEAR:
            break;
        case CHAR_KEYPAD_ICON:
        case CHAR_EXTRA_SYMBOL:
            ++strPos;
        default:
            ++width;
            break;
        }
    } while (temp != EOS);

    for (width = 0, strPos = 0; strPos < 8; ++strPos)
    {
        if (width < lineWidths[strPos])
            width = lineWidths[strPos];
    }

    return (u8)(GetFontAttribute(fontId, FONTATTR_MAX_LETTER_WIDTH) + letterSpacing) * width;
}

static u32 (*GetFontWidthFunc(u8 fontId))(u16, bool32)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sGlyphWidthFuncs); ++i)
    {
        if (fontId == sGlyphWidthFuncs[i].fontId)
            return sGlyphWidthFuncs[i].func;
    }

    return NULL;
}

s32 GetGlyphWidth(u16 glyphId, bool32 isJapanese, u8 fontId)
{
    if (!isJapanese && glyphId == CHAR_ZWS)
        return 0;

    u32 (*func)(u16 fontId, bool32 isJapanese);

    func = GetFontWidthFunc(fontId);
    if (func == NULL)
        return 0;
    return func(glyphId, isJapanese);
}

s32 GetStringWidth(u8 fontId, const u8 *str, s16 letterSpacing)
{
    bool32 isJapanese;
    int minGlyphWidth;
    u32 (*func)(u16 fontId, bool32 isJapanese);
    int localLetterSpacing;
    u32 lineWidth;
    const u8 *bufferPointer;
    int glyphWidth;
    s32 width;

    isJapanese = 0;
    minGlyphWidth = 0;

    func = GetFontWidthFunc(fontId);
    if (func == NULL)
        return 0;

    if (letterSpacing == -1)
        localLetterSpacing = GetFontAttribute(fontId, FONTATTR_LETTER_SPACING);
    else
        localLetterSpacing = letterSpacing;

    width = 0;
    lineWidth = 0;
    bufferPointer = 0;

    while (*str != EOS)
    {
        switch (*str)
        {
        case CHAR_NEWLINE:
            if (lineWidth > width)
                width = lineWidth;
            lineWidth = 0;
            break;
        case PLACEHOLDER_BEGIN:
            switch (*++str)
            {
            case PLACEHOLDER_ID_STRING_VAR_1:
                bufferPointer = gStringVar1;
                break;
            case PLACEHOLDER_ID_STRING_VAR_2:
                bufferPointer = gStringVar2;
                break;
            case PLACEHOLDER_ID_STRING_VAR_3:
                bufferPointer = gStringVar3;
                break;
            default:
                return 0;
            }
        case CHAR_DYNAMIC:
            if (bufferPointer == NULL)
                bufferPointer = DynamicPlaceholderTextUtil_GetPlaceholderPtr(*++str);
            while (*bufferPointer != EOS)
            {
                glyphWidth = func(*bufferPointer++, isJapanese);
                if (minGlyphWidth > 0)
                {
                    if (glyphWidth < minGlyphWidth)
                        glyphWidth = minGlyphWidth;
                    lineWidth += glyphWidth;
                }
                else
                {
                    lineWidth += glyphWidth;
                    if (isJapanese && str[1] != EOS)
                        lineWidth += localLetterSpacing;
                }
            }
            bufferPointer = 0;
            break;
        case EXT_CTRL_CODE_BEGIN:
            switch (*++str)
            {
            case EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW:
            case EXT_CTRL_CODE_TEXT_COLORS:
                ++str;
            case EXT_CTRL_CODE_PLAY_BGM:
            case EXT_CTRL_CODE_PLAY_SE:
                ++str;
            case EXT_CTRL_CODE_BACKGROUND:
            case EXT_CTRL_CODE_COLOR:
            case EXT_CTRL_CODE_SHADOW:
            case EXT_CTRL_CODE_ACCENT:
            case EXT_CTRL_CODE_HIGHLIGHT:
            case EXT_CTRL_CODE_PALETTE:
            case EXT_CTRL_CODE_PAUSE:
            case EXT_CTRL_CODE_ESCAPE:
            case EXT_CTRL_CODE_SHIFT_RIGHT:
            case EXT_CTRL_CODE_SHIFT_DOWN:
            case EXT_CTRL_CODE_SPEAKER:
                ++str;
                break;
            case EXT_CTRL_CODE_FONT:
                func = GetFontWidthFunc(*++str);
                if (func == NULL)
                    return 0;
                if (letterSpacing == -1)
                    localLetterSpacing = GetFontAttribute(*str, FONTATTR_LETTER_SPACING);
                break;
            case EXT_CTRL_CODE_CLEAR:
                glyphWidth = *++str;
                lineWidth += glyphWidth;
                break;
            case EXT_CTRL_CODE_SKIP:
                lineWidth = *++str;
                break;
            case EXT_CTRL_CODE_CLEAR_TO:
                if (*++str > lineWidth)
                    lineWidth = *str;
                break;
            case EXT_CTRL_CODE_MIN_LETTER_SPACING:
                minGlyphWidth = *++str;
                break;
            case EXT_CTRL_CODE_JPN:
                isJapanese = 1;
                break;
            case EXT_CTRL_CODE_ENG:
                isJapanese = 0;
                break;
            case EXT_CTRL_CODE_RESET_FONT:
            case EXT_CTRL_CODE_PAUSE_UNTIL_PRESS:
            case EXT_CTRL_CODE_WAIT_SE:
            case EXT_CTRL_CODE_FILL_WINDOW:
            default:
                break;
            }
            break;
        case CHAR_KEYPAD_ICON:
        case CHAR_EXTRA_SYMBOL:
            if (*str == CHAR_EXTRA_SYMBOL)
                glyphWidth = func(*++str | 0x100, isJapanese);
            else
                glyphWidth = GetKeypadIconWidth(*++str);

            if (minGlyphWidth > 0)
            {
                if (glyphWidth < minGlyphWidth)
                    glyphWidth = minGlyphWidth;
                lineWidth += glyphWidth;
            }
            else
            {
                lineWidth += glyphWidth;
                if (isJapanese && str[1] != EOS)
                    lineWidth += localLetterSpacing;
            }
            break;
        case CHAR_PROMPT_SCROLL:
        case CHAR_PROMPT_CLEAR:
            break;
        default:
            glyphWidth = func(*str, isJapanese);
            if (minGlyphWidth > 0)
            {
                if (glyphWidth < minGlyphWidth)
                    glyphWidth = minGlyphWidth;
                lineWidth += glyphWidth;
            }
            else
            {
                lineWidth += glyphWidth;
                if (isJapanese && str[1] != EOS)
                    lineWidth += localLetterSpacing;
            }
            break;
        }
        ++str;
    }

    if (lineWidth > width)
        return lineWidth;
    return width;
}

s32 GetStringLineWidth(u8 fontId, const u8 *str, s16 letterSpacing, u32 lineNum, u32 strSize)
{
    u32 strWidth = 0, strLen, currLine;
    u8 strCopy[strSize];

    for (currLine = 1; currLine <= lineNum; currLine++)
    {
        strWidth = GetStringWidth(fontId, str, letterSpacing);
        strLen = StringLineLength(str);
        memset(strCopy, EOS, strSize);
        if (currLine == lineNum && strLen != 0)
        {
            StringCopyN(strCopy, str, strLen);
            strWidth = GetStringWidth(fontId, strCopy, letterSpacing);
            strLen = StringLineLength(strCopy);
            StringAppend(strCopy, gText_EmptyString3);
        }
        str += strLen + 1;
    }
    return strWidth;
}

u8 RenderTextHandleBold(u8 *pixels, u8 fontId, u8 *str)
{
    u8 *strLocal;
    int strPos;
    int temp;
    int temp2;

    union TextColor savedTextColors = SaveTextColors();

    union TextColor textColor = {
        .background = TEXT_COLOR_TRANSPARENT,
        .foreground = TEXT_COLOR_WHITE,
        .shadow = TEXT_COLOR_LIGHT_GRAY,
        .accent = TEXT_COLOR_TRANSPARENT,
    };

    GenerateFontHalfRowLookupTable(textColor);
    strLocal = str;
    strPos = 0;

    do
    {
        temp = strLocal[strPos++];
        switch (temp)
        {
        case EXT_CTRL_CODE_BEGIN:
            temp2 = strLocal[strPos++];
            switch (temp2)
            {
            case EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW:
                textColor.foreground = strLocal[strPos++];
                textColor.background = textColor.accent = strLocal[strPos++];
                textColor.shadow = strLocal[strPos++];
                GenerateFontHalfRowLookupTable(textColor);
                continue;
            case EXT_CTRL_CODE_TEXT_COLORS:
                textColor.foreground = strLocal[strPos++];
                textColor.shadow = strLocal[strPos++];
                textColor.accent = strLocal[strPos++];
                GenerateFontHalfRowLookupTable(textColor);
                continue;
            case EXT_CTRL_CODE_BACKGROUND:
                textColor.background = strLocal[strPos++];
                GenerateFontHalfRowLookupTable(textColor);
                continue;
            case EXT_CTRL_CODE_COLOR:
                textColor.foreground = strLocal[strPos++];
                GenerateFontHalfRowLookupTable(textColor);
                continue;
            case EXT_CTRL_CODE_SHADOW:
                textColor.shadow = strLocal[strPos++];
                GenerateFontHalfRowLookupTable(textColor);
                continue;
            case EXT_CTRL_CODE_ACCENT:
                textColor.accent = strLocal[strPos++];
                GenerateFontHalfRowLookupTable(textColor);
                continue;
            case EXT_CTRL_CODE_HIGHLIGHT:
                textColor.background = textColor.accent = strLocal[strPos++];
                GenerateFontHalfRowLookupTable(textColor);
                continue;
            case EXT_CTRL_CODE_FONT:
                fontId = strLocal[strPos++];
                break;
            case EXT_CTRL_CODE_PLAY_BGM:
            case EXT_CTRL_CODE_PLAY_SE:
                ++strPos;
            case EXT_CTRL_CODE_PALETTE:
            case EXT_CTRL_CODE_PAUSE:
            case EXT_CTRL_CODE_ESCAPE:
            case EXT_CTRL_CODE_SHIFT_RIGHT:
            case EXT_CTRL_CODE_SHIFT_DOWN:
            case EXT_CTRL_CODE_CLEAR:
            case EXT_CTRL_CODE_SKIP:
            case EXT_CTRL_CODE_CLEAR_TO:
            case EXT_CTRL_CODE_MIN_LETTER_SPACING:
            case EXT_CTRL_CODE_SPEAKER:
                ++strPos;
                break;
            case EXT_CTRL_CODE_RESET_FONT:
            case EXT_CTRL_CODE_PAUSE_UNTIL_PRESS:
            case EXT_CTRL_CODE_WAIT_SE:
            case EXT_CTRL_CODE_FILL_WINDOW:
            case EXT_CTRL_CODE_JPN:
            case EXT_CTRL_CODE_ENG:
            default:
                continue;
            }
            break;
        case CHAR_DYNAMIC:
        case CHAR_KEYPAD_ICON:
        case CHAR_EXTRA_SYMBOL:
        case PLACEHOLDER_BEGIN:
            ++strPos;
            break;
        case CHAR_PROMPT_SCROLL:
        case CHAR_PROMPT_CLEAR:
        case CHAR_NEWLINE:
        case EOS:
            break;
        default:
            switch (fontId)
            {
            case FONT_BOLD:
                DecompressGlyph_Bold(temp);
                break;
            case FONT_NORMAL:
            default:
                DecompressGlyph_Normal(temp, TRUE);
                break;
            }
            CpuCopy32(gCurGlyph.gfxBufferTop, pixels, 0x20);
            CpuCopy32(gCurGlyph.gfxBufferBottom, pixels + 0x20, 0x20);
            pixels += 0x40;
            break;
        }
    }
    while (temp != EOS);

    RestoreTextColors(savedTextColors);
    return 1;
}

u8 DrawKeypadIcon(u8 windowId, u8 keypadIconId, u16 x, u16 y)
{
    BlitBitmapRectToWindow(
        windowId,
        sKeypadIconTiles + (sKeypadIcons[keypadIconId].tileOffset * 0x20),
        0,
        0,
        0x80,
        0x80,
        x,
        y,
        sKeypadIcons[keypadIconId].width,
        sKeypadIcons[keypadIconId].height);
    return sKeypadIcons[keypadIconId].width;
}

u8 GetKeypadIconWidth(u8 keypadIconId)
{
    return sKeypadIcons[keypadIconId].width;
}

void SetDefaultFontsPointer(void)
{
    SetFontsPointer(sFontInfos);
}

u8 GetFontAttribute(u8 fontId, u8 attributeId)
{
    int result = 0;
    switch (attributeId)
    {
    case FONTATTR_MAX_LETTER_WIDTH:
        result = sFontInfos[fontId].maxLetterWidth;
        break;
    case FONTATTR_MAX_LETTER_HEIGHT:
        result = sFontInfos[fontId].maxLetterHeight;
        break;
    case FONTATTR_LETTER_SPACING:
        result = sFontInfos[fontId].letterSpacing;
        break;
    case FONTATTR_LINE_SPACING:
        result = sFontInfos[fontId].lineSpacing;
        break;
    case FONTATTR_COLOR_ACCENT:
        result = sFontInfos[fontId].color.accent;
        break;
    case FONTATTR_COLOR_FOREGROUND:
        result = sFontInfos[fontId].color.foreground;
        break;
    case FONTATTR_COLOR_BACKGROUND:
        result = sFontInfos[fontId].color.background;
        break;
    case FONTATTR_COLOR_SHADOW:
        result = sFontInfos[fontId].color.shadow;
        break;
    }
    return result;
}

u8 GetMenuCursorDimensionByFont(u8 fontId, u8 whichDimension)
{
    return sMenuCursorDimensions[fontId][whichDimension];
}

static void DecompressGlyph_Small(u16 glyphId, bool32 isJapanese)
{
    const u16 *glyphs;

    if (isJapanese)
    {
        glyphs = gFontSmallJapaneseGlyphs + (0x100 * (glyphId >> 0x4)) + (0x8 * (glyphId & 0xF));
        DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
        DecompressGlyphTile(glyphs + 0x80, gCurGlyph.gfxBufferBottom);
        gCurGlyph.width = 8;
        gCurGlyph.height = 12;
    }
    else
    {
        glyphs = gFontSmallLatinGlyphs + (0x20 * glyphId);
        gCurGlyph.width = gFontSmallLatinGlyphWidths[glyphId];

        if (gCurGlyph.width <= 8)
        {
            DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
            DecompressGlyphTile(glyphs + 0x10, gCurGlyph.gfxBufferBottom);
        }
        else
        {
            DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
            DecompressGlyphTile(glyphs + 0x8, gCurGlyph.gfxBufferTop + 8);
            DecompressGlyphTile(glyphs + 0x10, gCurGlyph.gfxBufferBottom);
            DecompressGlyphTile(glyphs + 0x18, gCurGlyph.gfxBufferBottom + 8);
        }

        gCurGlyph.height = 13;
    }
}

static u32 GetGlyphWidth_Small(u16 glyphId, bool32 isJapanese)
{
    if (isJapanese == TRUE)
        return 8;
    else
        return gFontSmallLatinGlyphWidths[glyphId];
}

static void DecompressGlyph_Narrow(u16 glyphId, bool32 isJapanese)
{
    const u16 *glyphs;

    if (isJapanese == TRUE)
    {
        glyphs = gFontNormalJapaneseGlyphs + (0x100 * (glyphId >> 0x4)) + (0x8 * (glyphId % 0x10));
        DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
        DecompressGlyphTile(glyphs + 0x80, gCurGlyph.gfxBufferBottom);
        gCurGlyph.width = 8;
        gCurGlyph.height = 15;
    }
    else
    {
        glyphs = gFontNarrowLatinGlyphs + (0x20 * glyphId);
        gCurGlyph.width = gFontNarrowLatinGlyphWidths[glyphId];

        if (gCurGlyph.width <= 8)
        {
            DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
            DecompressGlyphTile(glyphs + 0x10, gCurGlyph.gfxBufferBottom);
        }
        else
        {
            DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
            DecompressGlyphTile(glyphs + 0x8, gCurGlyph.gfxBufferTop + 8);
            DecompressGlyphTile(glyphs + 0x10, gCurGlyph.gfxBufferBottom);
            DecompressGlyphTile(glyphs + 0x18, gCurGlyph.gfxBufferBottom + 8);
        }

        gCurGlyph.height = 15;
    }
}

static u32 GetGlyphWidth_Narrow(u16 glyphId, bool32 isJapanese)
{
    if (isJapanese == TRUE)
        return 8;
    else
        return gFontNarrowLatinGlyphWidths[glyphId];
}

static void DecompressGlyph_SmallNarrow(u16 glyphId, bool32 isJapanese)
{
    const u16 *glyphs;

    if (isJapanese == TRUE)
    {
        glyphs = gFontSmallJapaneseGlyphs + (0x100 * (glyphId >> 0x4)) + (0x8 * (glyphId & 0xF));
        DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
        DecompressGlyphTile(glyphs + 0x80, gCurGlyph.gfxBufferBottom);
        gCurGlyph.width = 8;
        gCurGlyph.height = 12;
    }
    else
    {
        glyphs = gFontSmallNarrowLatinGlyphs + (0x20 * glyphId);
        gCurGlyph.width = gFontSmallNarrowLatinGlyphWidths[glyphId];

        if (gCurGlyph.width <= 8)
        {
            DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
            DecompressGlyphTile(glyphs + 0x10, gCurGlyph.gfxBufferBottom);
        }
        else
        {
            DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
            DecompressGlyphTile(glyphs + 0x8, gCurGlyph.gfxBufferTop + 8);
            DecompressGlyphTile(glyphs + 0x10, gCurGlyph.gfxBufferBottom);
            DecompressGlyphTile(glyphs + 0x18, gCurGlyph.gfxBufferBottom + 8);
        }

        gCurGlyph.height = 12;
    }
}

static u32 GetGlyphWidth_SmallNarrow(u16 glyphId, bool32 isJapanese)
{
    if (isJapanese == TRUE)
        return 8;
    else
        return gFontSmallNarrowLatinGlyphWidths[glyphId];
}

static void DecompressGlyph_Short(u16 glyphId, bool32 isJapanese)
{
    const u16 *glyphs;

    if (isJapanese == TRUE)
    {
        glyphs = gFontShortJapaneseGlyphs + (0x100 * (glyphId >> 0x3)) + (0x10 * (glyphId & 0x7));
        DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
        DecompressGlyphTile(glyphs + 0x8, gCurGlyph.gfxBufferTop + 8);
        DecompressGlyphTile(glyphs + 0x80, gCurGlyph.gfxBufferBottom);    // gCurGlyph + 0x20
        DecompressGlyphTile(glyphs + 0x88, gCurGlyph.gfxBufferBottom + 8);    // gCurGlyph + 0x60
        gCurGlyph.width = gFontShortJapaneseGlyphWidths[glyphId];
        gCurGlyph.height = 14;
    }
    else
    {
        glyphs = gFontShortLatinGlyphs + (0x20 * glyphId);
        gCurGlyph.width = gFontShortLatinGlyphWidths[glyphId];

        if (gCurGlyph.width <= 8)
        {
            DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
            DecompressGlyphTile(glyphs + 0x10, gCurGlyph.gfxBufferBottom);
        }
        else
        {
            DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
            DecompressGlyphTile(glyphs + 0x8, gCurGlyph.gfxBufferTop + 8);
            DecompressGlyphTile(glyphs + 0x10, gCurGlyph.gfxBufferBottom);
            DecompressGlyphTile(glyphs + 0x18, gCurGlyph.gfxBufferBottom + 8);
        }

        gCurGlyph.height = 14;
    }
}

static u32 GetGlyphWidth_Short(u16 glyphId, bool32 isJapanese)
{
    if (isJapanese == TRUE)
        return gFontShortJapaneseGlyphWidths[glyphId];
    else
        return gFontShortLatinGlyphWidths[glyphId];
}

static void DecompressGlyph_Normal(u16 glyphId, bool32 isJapanese)
{
    const u16 *glyphs;

    if (isJapanese == TRUE)
    {
        glyphs = gFontNormalJapaneseGlyphs + (0x100 * (glyphId >> 0x4)) + (0x8 * (glyphId % 0x10));
        DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
        DecompressGlyphTile(glyphs + 0x80, gCurGlyph.gfxBufferBottom);
        gCurGlyph.width = 8;
        gCurGlyph.height = 15;
    }
    else
    {
        glyphs = gFontNormalLatinGlyphs + (0x20 * glyphId);
        gCurGlyph.width = gFontNormalLatinGlyphWidths[glyphId];

        if (gCurGlyph.width <= 8)
        {
            DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
            DecompressGlyphTile(glyphs + 0x10, gCurGlyph.gfxBufferBottom);
        }
        else
        {
            DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
            DecompressGlyphTile(glyphs + 0x8, gCurGlyph.gfxBufferTop + 8);
            DecompressGlyphTile(glyphs + 0x10, gCurGlyph.gfxBufferBottom);
            DecompressGlyphTile(glyphs + 0x18, gCurGlyph.gfxBufferBottom + 8);
        }

        gCurGlyph.height = 15;
    }
}

static u32 GetGlyphWidth_Normal(u16 glyphId, bool32 isJapanese)
{
    if (isJapanese == TRUE)
        return 8;
    else
        return gFontNormalLatinGlyphWidths[glyphId];
}

static void DecompressGlyph_Bold(u16 glyphId)
{
    const u16 *glyphs;

    glyphs = sFontBoldJapaneseGlyphs + (0x100 * (glyphId >> 4)) + (0x8 * (glyphId & 0xF));
    DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
    DecompressGlyphTile(glyphs + 0x80, gCurGlyph.gfxBufferBottom);
    gCurGlyph.width = 8;
    gCurGlyph.height = 12;
}

static void DecompressGlyph_Narrower(u16 glyphId, bool32 isJapanese)
{
    const u16 *glyphs;

    if (isJapanese == TRUE)
    {
        glyphs = gFontNormalJapaneseGlyphs + (0x100 * (glyphId >> 0x4)) + (0x8 * (glyphId % 0x10));
        DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
        DecompressGlyphTile(glyphs + 0x80, gCurGlyph.gfxBufferBottom);
        gCurGlyph.width = 8;
        gCurGlyph.height = 15;
    }
    else
    {
        glyphs = gFontNarrowerLatinGlyphs + (0x20 * glyphId);
        gCurGlyph.width = gFontNarrowerLatinGlyphWidths[glyphId];

        if (gCurGlyph.width <= 8)
        {
            DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
            DecompressGlyphTile(glyphs + 0x10, gCurGlyph.gfxBufferBottom);
        }
        else
        {
            DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
            DecompressGlyphTile(glyphs + 0x8, gCurGlyph.gfxBufferTop + 8);
            DecompressGlyphTile(glyphs + 0x10, gCurGlyph.gfxBufferBottom);
            DecompressGlyphTile(glyphs + 0x18, gCurGlyph.gfxBufferBottom + 8);
        }

        gCurGlyph.height = 15;
    }
}

static u32 GetGlyphWidth_Narrower(u16 glyphId, bool32 isJapanese)
{
    if (isJapanese == TRUE)
        return 8;
    else
        return gFontNarrowerLatinGlyphWidths[glyphId];
}

static void DecompressGlyph_SmallNarrower(u16 glyphId, bool32 isJapanese)
{
    const u16 *glyphs;

    if (isJapanese == TRUE)
    {
        glyphs = gFontSmallJapaneseGlyphs + (0x100 * (glyphId >> 0x4)) + (0x8 * (glyphId % 0x10));
        DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
        DecompressGlyphTile(glyphs + 0x80, gCurGlyph.gfxBufferBottom);
        gCurGlyph.width = 8;
        gCurGlyph.height = 15;
    }
    else
    {
        glyphs = gFontSmallNarrowerLatinGlyphs + (0x20 * glyphId);
        gCurGlyph.width = gFontSmallNarrowerLatinGlyphWidths[glyphId];

        if (gCurGlyph.width <= 8)
        {
            DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
            DecompressGlyphTile(glyphs + 0x10, gCurGlyph.gfxBufferBottom);
        }
        else
        {
            DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
            DecompressGlyphTile(glyphs + 0x8, gCurGlyph.gfxBufferTop + 8);
            DecompressGlyphTile(glyphs + 0x10, gCurGlyph.gfxBufferBottom);
            DecompressGlyphTile(glyphs + 0x18, gCurGlyph.gfxBufferBottom + 8);
        }

        gCurGlyph.height = 15;
    }
}

static u32 GetGlyphWidth_SmallNarrower(u16 glyphId, bool32 isJapanese)
{
    if (isJapanese == TRUE)
        return 8;
    else
        return gFontSmallNarrowerLatinGlyphWidths[glyphId];
}

static void DecompressGlyph_ShortNarrow(u16 glyphId, bool32 isJapanese)
{
    const u16 *glyphs;

    if (isJapanese == TRUE)
    {
        glyphs = gFontShortJapaneseGlyphs + (0x100 * (glyphId >> 0x3)) + (0x10 * (glyphId & 0x7));
        DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
        DecompressGlyphTile(glyphs + 0x8, gCurGlyph.gfxBufferTop + 8);
        DecompressGlyphTile(glyphs + 0x80, gCurGlyph.gfxBufferBottom);    // gCurGlyph + 0x20
        DecompressGlyphTile(glyphs + 0x88, gCurGlyph.gfxBufferBottom + 8);    // gCurGlyph + 0x60
        gCurGlyph.width = gFontShortJapaneseGlyphWidths[glyphId];
        gCurGlyph.height = 14;
    }
    else
    {
        glyphs = gFontShortNarrowLatinGlyphs + (0x20 * glyphId);
        gCurGlyph.width = gFontShortNarrowLatinGlyphWidths[glyphId];

        if (gCurGlyph.width <= 8)
        {
            DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
            DecompressGlyphTile(glyphs + 0x10, gCurGlyph.gfxBufferBottom);
        }
        else
        {
            DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
            DecompressGlyphTile(glyphs + 0x8, gCurGlyph.gfxBufferTop + 8);
            DecompressGlyphTile(glyphs + 0x10, gCurGlyph.gfxBufferBottom);
            DecompressGlyphTile(glyphs + 0x18, gCurGlyph.gfxBufferBottom + 8);
        }

        gCurGlyph.height = 14;
    }
}

static u32 GetGlyphWidth_ShortNarrow(u16 glyphId, bool32 isJapanese)
{
    if (isJapanese == TRUE)
        return gFontShortJapaneseGlyphWidths[glyphId];
    else
        return gFontShortNarrowLatinGlyphWidths[glyphId];
}

static void DecompressGlyph_ShortNarrower(u16 glyphId, bool32 isJapanese)
{
    const u16 *glyphs;

    if (isJapanese == TRUE)
    {
        glyphs = gFontShortJapaneseGlyphs + (0x100 * (glyphId >> 0x3)) + (0x10 * (glyphId & 0x7));
        DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
        DecompressGlyphTile(glyphs + 0x8, gCurGlyph.gfxBufferTop + 8);
        DecompressGlyphTile(glyphs + 0x80, gCurGlyph.gfxBufferBottom);    // gCurGlyph + 0x20
        DecompressGlyphTile(glyphs + 0x88, gCurGlyph.gfxBufferBottom + 8);    // gCurGlyph + 0x60
        gCurGlyph.width = gFontShortJapaneseGlyphWidths[glyphId];
        gCurGlyph.height = 14;
    }
    else
    {
        glyphs = gFontShortNarrowerLatinGlyphs + (0x20 * glyphId);
        gCurGlyph.width = gFontShortNarrowerLatinGlyphWidths[glyphId];

        if (gCurGlyph.width <= 8)
        {
            DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
            DecompressGlyphTile(glyphs + 0x10, gCurGlyph.gfxBufferBottom);
        }
        else
        {
            DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
            DecompressGlyphTile(glyphs + 0x8, gCurGlyph.gfxBufferTop + 8);
            DecompressGlyphTile(glyphs + 0x10, gCurGlyph.gfxBufferBottom);
            DecompressGlyphTile(glyphs + 0x18, gCurGlyph.gfxBufferBottom + 8);
        }

        gCurGlyph.height = 14;
    }
}

static u32 GetGlyphWidth_ShortNarrower(u16 glyphId, bool32 isJapanese)
{
    if (isJapanese == TRUE)
        return gFontShortJapaneseGlyphWidths[glyphId];
    else
        return gFontShortNarrowerLatinGlyphWidths[glyphId];
}

static const s8 sNarrowerFontIds[] =
{
    [FONT_SMALL] = FONT_SMALL_NARROW,
    [FONT_NORMAL] = FONT_NARROW,
    [FONT_SHORT] = FONT_SHORT_NARROW,
    [FONT_SHORT_COPY_1] = FONT_SHORT_NARROW,
    [FONT_SHORT_COPY_2] = FONT_SHORT_NARROW,
    [FONT_SHORT_COPY_3] = FONT_SHORT_NARROW,
    [FONT_BRAILLE] = -1,
    [FONT_NARROW] = FONT_NARROWER,
    [FONT_SMALL_NARROW] = FONT_SMALL_NARROWER,
    [FONT_BOLD] = -1,
    [FONT_NARROWER] = -1,
    [FONT_SMALL_NARROWER] = -1,
    [FONT_SHORT_NARROW] = FONT_SHORT_NARROWER,
    [FONT_SHORT_NARROWER] = -1,
};

// If the narrowest font ID doesn't fit the text, we still return that
// ID because clipping is better than crashing.
u32 GetFontIdToFit(const u8 *string, u32 fontId, u32 letterSpacing, u32 widthPx)
{
    for (;;)
    {
        s32 narrowerFontId = sNarrowerFontIds[fontId];
        if (narrowerFontId == -1)
            return fontId;
        if (GetStringWidth(fontId, string, letterSpacing) <= widthPx)
            return fontId;
        fontId = narrowerFontId;
    }
}

u8 *PrependFontIdToFit(u8 *start, u8 *end, u32 fontId, u32 width)
{
    u32 fitFontId = GetFontIdToFit(start, fontId, 0, width);

    if (fitFontId == fontId)
        return end;

    memmove(&start[3], &start[0], end - start);
    start[0] = EXT_CTRL_CODE_BEGIN;
    start[1] = EXT_CTRL_CODE_FONT;
    start[2] = fitFontId;
    end[3] = EOS;
    return end + 3;
}

u8 *WrapFontIdToFit(u8 *start, u8 *end, u32 fontId, u32 width)
{

    u32 fitFontId = GetFontIdToFit(start, fontId, 0, width);
    if (fitFontId != fontId)
    {
        memmove(&start[3], &start[0], end - start);
        start[0] = EXT_CTRL_CODE_BEGIN;
        start[1] = EXT_CTRL_CODE_FONT;
        start[2] = fitFontId;
        end[3] = EXT_CTRL_CODE_BEGIN;
        end[4] = EXT_CTRL_CODE_FONT;
        end[5] = fontId;
        end[6] = EOS;
        return end + 6;
    }
    else
    {
        return end;
    }
}

static struct TextPrinter *AllocateTextPrinter(void)
{
    struct TextPrinter *printer = Alloc(sizeof(struct TextPrinter));

    if (printer == NULL)
    {
        errorf("Failed to allocate text printer");
        return NULL;
    }

    if (sFirstTextPrinter == NULL)
    {
        sFirstTextPrinter = printer;
    }
    else
    {
        struct TextPrinter *currentPrinter = sFirstTextPrinter;
        while (currentPrinter->nextPrinter != NULL)
            currentPrinter = currentPrinter->nextPrinter;

        currentPrinter->nextPrinter = printer;
    }

    return printer;
}

static u32 GetNumTextPrinters(void)
{
    u32 numPrinters = 0;
    struct TextPrinter *currentPrinter = sFirstTextPrinter;
    while (currentPrinter != NULL)
    {
        currentPrinter = currentPrinter->nextPrinter;
        numPrinters++;
    }
    return numPrinters;
}

static void FreeFinishedTextPrinters(void)
{
    //  Clear out printers from the front
    while (sFirstTextPrinter != NULL)
    {
        if (!sFirstTextPrinter->isInUse)
        {
            struct TextPrinter *printer = sFirstTextPrinter;
            sFirstTextPrinter = sFirstTextPrinter->nextPrinter;
            Free(printer);
        }
        else
        {
            break;
        }
    }

    if (sFirstTextPrinter == NULL)
        return;

    //  Clear out printers in the "middle"
    struct TextPrinter *prevPrinter = sFirstTextPrinter;
    struct TextPrinter *currentPrinter = sFirstTextPrinter->nextPrinter;

    while (currentPrinter != NULL)
    {
        if (!currentPrinter->isInUse)
        {
            prevPrinter->nextPrinter = currentPrinter->nextPrinter;
            Free(currentPrinter);
            currentPrinter = prevPrinter->nextPrinter;
        }
        else
        {
            prevPrinter = currentPrinter;
            currentPrinter = currentPrinter->nextPrinter;
        }
    }
}

// FRLG

#define TAG_CURSOR 0x8000

extern const struct OamData gOamData_AffineOff_ObjNormal_16x16;

static const u8 sDoubleArrowTiles1[]       = INCGFX_U8("graphics/fonts/down_arrow_3.png", ".4bpp");
static const u8 sDoubleArrowTiles2[]       = INCGFX_U8("graphics/fonts/down_arrow_4.png", ".4bpp");

static const struct SpriteSheet sSpriteSheets_TextCursor[] =
{
    {sDoubleArrowTiles1, sizeof(sDoubleArrowTiles1), TAG_CURSOR},
    {sDoubleArrowTiles2, sizeof(sDoubleArrowTiles2), TAG_CURSOR},
    {NULL}
};

static const struct SpritePalette sSpritePalettes_TextCursor[] =
{
    {gStandardMenuPalette, TAG_CURSOR},
    {NULL}
};

static const struct SpriteTemplate sSpriteTemplate_TextCursor =
{
    .tileTag = TAG_CURSOR,
    .paletteTag = TAG_CURSOR,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_TextCursor,
};

#define sDelay data[0]
#define sState data[1]

static void SpriteCB_TextCursor(struct Sprite *sprite)
{
    if (sprite->sDelay)
    {
        sprite->sDelay--;
    }
    else
    {
        sprite->sDelay = 8;
        switch (sprite->sState)
        {
        case 0:
            sprite->y2 = 0;
            break;
        case 1:
            sprite->y2 = 1;
            break;
        case 2:
            sprite->y2 = 2;
            break;
        case 3:
            sprite->y2 = 1;
            sprite->sState = 0;
            return;
        }
        sprite->sState++;
    }
}

u8 CreateTextCursorSprite(u8 sheetId, u16 x, u16 y, u8 priority, u8 subpriority)
{
    u8 spriteId;
    LoadSpriteSheet(&sSpriteSheets_TextCursor[sheetId & 1]);
    LoadSpritePalette(&sSpritePalettes_TextCursor[0]);
    spriteId = CreateSprite(&sSpriteTemplate_TextCursor, x + 3, y + 4, subpriority);
    gSprites[spriteId].oam.priority = (priority & 3);
    gSprites[spriteId].oam.matrixNum = 0;
    gSprites[spriteId].sDelay = 8;
    return spriteId;
}

void DestroyTextCursorSprite(u8 spriteId)
{
    DestroySprite(&gSprites[spriteId]);
    FreeSpriteTilesByTag(TAG_CURSOR);
    FreeSpritePaletteByTag(TAG_CURSOR);
}

#undef sDelay
#undef sState

// End FRLG

void DeactivateSingleTextPrinter(u32 id, enum TextPrinterType type)
{
    struct TextPrinter *currentPrinter = sFirstTextPrinter;
    bool32 foundPrinter = FALSE;
    //  This loop cannot exit early because a single window/sprite group can have multiple printers attached to it
    while (currentPrinter != NULL)
    {
        switch (type)
        {
        case WINDOW_TEXT_PRINTER:
            if (currentPrinter->printerTemplate.type == WINDOW_TEXT_PRINTER && currentPrinter->printerTemplate.windowId == id)
            {
                currentPrinter->isInUse = FALSE;
                currentPrinter = NULL;
                foundPrinter = TRUE;
            }
            else
            {
                currentPrinter = currentPrinter->nextPrinter;
            }
            break;
        case SPRITE_TEXT_PRINTER:
            if (currentPrinter->printerTemplate.type == SPRITE_TEXT_PRINTER && currentPrinter->printerTemplate.firstSprite == id)
            {
                currentPrinter->isInUse = FALSE;
                currentPrinter = NULL;
                foundPrinter = TRUE;
            }
            else
            {
                currentPrinter = currentPrinter->nextPrinter;
            }
            break;
        }
    }

    if (foundPrinter)
        FreeFinishedTextPrinters();
}
