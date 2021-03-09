#include "global.h"
#include "battle.h"
#include "main.h"
#include "m4a.h"
#include "palette.h"
#include "sound.h"
#include "constants/songs.h"
#include "string_util.h"
#include "window.h"
#include "text.h"
#include "blit.h"
#include "menu.h"
#include "dynamic_placeholder_text_util.h"

EWRAM_DATA struct TextPrinter gTempTextPrinter = {0};
EWRAM_DATA struct TextPrinter gTextPrinters[NUM_TEXT_PRINTERS] = {0};

static u16 gFontHalfRowLookupTable[0x51];
static u16 gLastTextBgColor;
static u16 gLastTextFgColor;
static u16 gLastTextShadowColor;

const struct FontInfo *gFonts;
u8 gUnknown_03002F84;
struct Struct_03002F90 gUnknown_03002F90;
TextFlags gTextFlags;

const u8 gFontHalfRowOffsets[] =
{
    0x00, 0x01, 0x02, 0x00, 0x03, 0x04, 0x05, 0x03, 0x06, 0x07, 0x08, 0x06, 0x00, 0x01, 0x02, 0x00,
    0x09, 0x0A, 0x0B, 0x09, 0x0C, 0x0D, 0x0E, 0x0C, 0x0F, 0x10, 0x11, 0x0F, 0x09, 0x0A, 0x0B, 0x09,
    0x12, 0x13, 0x14, 0x12, 0x15, 0x16, 0x17, 0x15, 0x18, 0x19, 0x1A, 0x18, 0x12, 0x13, 0x14, 0x12,
    0x00, 0x01, 0x02, 0x00, 0x03, 0x04, 0x05, 0x03, 0x06, 0x07, 0x08, 0x06, 0x00, 0x01, 0x02, 0x00,
    0x1B, 0x1C, 0x1D, 0x1B, 0x1E, 0x1F, 0x20, 0x1E, 0x21, 0x22, 0x23, 0x21, 0x1B, 0x1C, 0x1D, 0x1B,
    0x24, 0x25, 0x26, 0x24, 0x27, 0x28, 0x29, 0x27, 0x2A, 0x2B, 0x2C, 0x2A, 0x24, 0x25, 0x26, 0x24,
    0x2D, 0x2E, 0x2F, 0x2D, 0x30, 0x31, 0x32, 0x30, 0x33, 0x34, 0x35, 0x33, 0x2D, 0x2E, 0x2F, 0x2D,
    0x1B, 0x1C, 0x1D, 0x1B, 0x1E, 0x1F, 0x20, 0x1E, 0x21, 0x22, 0x23, 0x21, 0x1B, 0x1C, 0x1D, 0x1B,
    0x36, 0x37, 0x38, 0x36, 0x39, 0x3A, 0x3B, 0x39, 0x3C, 0x3D, 0x3E, 0x3C, 0x36, 0x37, 0x38, 0x36,
    0x3F, 0x40, 0x41, 0x3F, 0x42, 0x43, 0x44, 0x42, 0x45, 0x46, 0x47, 0x45, 0x3F, 0x40, 0x41, 0x3F,
    0x48, 0x49, 0x4A, 0x48, 0x4B, 0x4C, 0x4D, 0x4B, 0x4E, 0x4F, 0x50, 0x4E, 0x48, 0x49, 0x4A, 0x48,
    0x36, 0x37, 0x38, 0x36, 0x39, 0x3A, 0x3B, 0x39, 0x3C, 0x3D, 0x3E, 0x3C, 0x36, 0x37, 0x38, 0x36,
    0x00, 0x01, 0x02, 0x00, 0x03, 0x04, 0x05, 0x03, 0x06, 0x07, 0x08, 0x06, 0x00, 0x01, 0x02, 0x00,
    0x09, 0x0A, 0x0B, 0x09, 0x0C, 0x0D, 0x0E, 0x0C, 0x0F, 0x10, 0x11, 0x0F, 0x09, 0x0A, 0x0B, 0x09,
    0x12, 0x13, 0x14, 0x12, 0x15, 0x16, 0x17, 0x15, 0x18, 0x19, 0x1A, 0x18, 0x12, 0x13, 0x14, 0x12,
    0x00, 0x01, 0x02, 0x00, 0x03, 0x04, 0x05, 0x03, 0x06, 0x07, 0x08, 0x06, 0x00, 0x01, 0x02, 0x00
};

const u8 gDownArrowTiles[] = INCBIN_U8("graphics/fonts/down_arrow.4bpp");
const u8 gDarkDownArrowTiles[] = INCBIN_U8("graphics/fonts/down_arrow_RS.4bpp");
const u8 gUnusedFRLGBlankedDownArrow[] = INCBIN_U8("graphics/fonts/unused_frlg_blanked_down_arrow.4bpp");
const u8 gUnusedFRLGDownArrow[] = INCBIN_U8("graphics/fonts/unused_frlg_down_arrow.4bpp");
const u8 gDownArrowYCoords[] = { 0x0, 0x1, 0x2, 0x1 };
const u8 gWindowVerticalScrollSpeeds[] = { 0x1, 0x2, 0x4, 0x0 };

const struct GlyphWidthFunc gGlyphWidthFuncs[] =
{
    { 0x0, GetGlyphWidthFont0 },
    { 0x1, GetGlyphWidthFont1 },
    { 0x2, GetGlyphWidthFont2 },
    { 0x3, GetGlyphWidthFont2 },
    { 0x4, GetGlyphWidthFont2 },
    { 0x5, GetGlyphWidthFont2 },
    { 0x6, GetGlyphWidthFont6 },
    { 0x7, GetGlyphWidthFont7 },
    { 0x8, GetGlyphWidthFont8 }
};

const struct KeypadIcon gKeypadIcons[] =
{
    [CHAR_A_BUTTON]       = {  0x0,  0x8, 0xC },
    [CHAR_B_BUTTON]       = {  0x1,  0x8, 0xC },
    [CHAR_L_BUTTON]       = {  0x2, 0x10, 0xC },
    [CHAR_R_BUTTON]       = {  0x4, 0x10, 0xC },
    [CHAR_START_BUTTON]   = {  0x6, 0x18, 0xC },
    [CHAR_SELECT_BUTTON]  = {  0x9, 0x18, 0xC },
    [CHAR_DPAD_UP]        = {  0xC,  0x8, 0xC },
    [CHAR_DPAD_DOWN]      = {  0xD,  0x8, 0xC },
    [CHAR_DPAD_LEFT]      = {  0xE,  0x8, 0xC },
    [CHAR_DPAD_RIGHT]     = {  0xF,  0x8, 0xC },
    [CHAR_DPAD_UPDOWN]    = { 0x20,  0x8, 0xC },
    [CHAR_DPAD_LEFTRIGHT] = { 0x21,  0x8, 0xC },
    [CHAR_DPAD_NONE]      = { 0x22,  0x8, 0xC }
};

const u8 gKeypadIconTiles[] = INCBIN_U8("graphics/fonts/keypad_icons.4bpp");

const struct FontInfo gFontInfos[] =
{
    { Font0Func, 0x5,  0xC, 0x0, 0x0, 0x0, 0x2, 0x1, 0x3 },
    { Font1Func, 0x6, 0x10, 0x0, 0x0, 0x0, 0x2, 0x1, 0x3 },
    { Font2Func, 0x6,  0xE, 0x0, 0x0, 0x0, 0x2, 0x1, 0x3 },
    { Font3Func, 0x6,  0xE, 0x0, 0x0, 0x0, 0x2, 0x1, 0x3 },
    { Font4Func, 0x6,  0xE, 0x0, 0x0, 0x0, 0x2, 0x1, 0x3 },
    { Font5Func, 0x6,  0xE, 0x0, 0x0, 0x0, 0x2, 0x1, 0x3 },
    { Font6Func, 0x8, 0x10, 0x0, 0x8, 0x0, 0x2, 0x1, 0x3 },
    { Font7Func, 0x5, 0x10, 0x0, 0x0, 0x0, 0x2, 0x1, 0x3 },
    { Font8Func, 0x5,  0x8, 0x0, 0x0, 0x0, 0x2, 0x1, 0x3 },
    { NULL,      0x8,  0x8, 0x0, 0x0, 0x0, 0x1, 0x2, 0xF }
};

const u8 gMenuCursorDimensions[][2] =
{
    { 0x8,  0xC },
    { 0x8,  0xF },
    { 0x8,  0xE },
    { 0x8,  0xE },
    { 0x8,  0xE },
    { 0x8,  0xE },
    { 0x8, 0x10 },
    { 0x8,  0xF },
    { 0x8,  0x8 },
    { 0x0,  0x0 }
};

const u16 gFont9JapaneseGlyphs[] = INCBIN_U16("graphics/fonts/font9.hwjpnfont");

extern const u16 gFont8LatinGlyphs[];
extern const u8 gFont8LatinGlyphWidths[];
extern const u16 gFont0LatinGlyphs[];
extern const u8 gFont0LatinGlyphWidths[];
extern const u16 gFont7LatinGlyphs[];
extern const u8 gFont7LatinGlyphWidths[];
extern const u16 gFont2LatinGlyphs[];
extern const u8 gFont2LatinGlyphWidths[];
extern const u16 gFont1LatinGlyphs[];
extern const u8 gFont1LatinGlyphWidths[];
extern const u16 gFont0JapaneseGlyphs[];
extern const u16 gFont1JapaneseGlyphs[];
extern const u16 gFont2JapaneseGlyphs[];
extern const u8 gFont2JapaneseGlyphWidths[];

void SetFontsPointer(const struct FontInfo *fonts)
{
    gFonts = fonts;
}

void DeactivateAllTextPrinters(void)
{
    int printer;
    for (printer = 0; printer < NUM_TEXT_PRINTERS; ++printer)
        gTextPrinters[printer].active = 0;
}

u16 AddTextPrinterParameterized(u8 windowId, u8 fontId, const u8 *str, u8 x, u8 y, u8 speed, void (*callback)(struct TextPrinterTemplate *, u16))
{
    struct TextPrinterTemplate printerTemplate;

    printerTemplate.currentChar = str;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = fontId;
    printerTemplate.x = x;
    printerTemplate.y = y;
    printerTemplate.currentX = x;
    printerTemplate.currentY = y;
    printerTemplate.letterSpacing = gFonts[fontId].letterSpacing;
    printerTemplate.lineSpacing = gFonts[fontId].lineSpacing;
    printerTemplate.unk = gFonts[fontId].unk;
    printerTemplate.fgColor = gFonts[fontId].fgColor;
    printerTemplate.bgColor = gFonts[fontId].bgColor;
    printerTemplate.shadowColor = gFonts[fontId].shadowColor;
    return AddTextPrinter(&printerTemplate, speed, callback);
}

bool16 AddTextPrinter(struct TextPrinterTemplate *printerTemplate, u8 speed, void (*callback)(struct TextPrinterTemplate *, u16))
{
    int i;
    u16 j;

    if (!gFonts)
        return FALSE;

    gTempTextPrinter.active = 1;
    gTempTextPrinter.state = 0;
    gTempTextPrinter.textSpeed = speed;
    gTempTextPrinter.delayCounter = 0;
    gTempTextPrinter.scrollDistance = 0;

    for (i = 0; i < 7; i++)
    {
        gTempTextPrinter.subStructFields[i] = 0;
    }

    gTempTextPrinter.printerTemplate = *printerTemplate;
    gTempTextPrinter.callback = callback;
    gTempTextPrinter.minLetterSpacing = 0;
    gTempTextPrinter.japanese = 0;

    GenerateFontHalfRowLookupTable(printerTemplate->fgColor, printerTemplate->bgColor, printerTemplate->shadowColor);
    if (speed != TEXT_SPEED_FF && speed != 0)
    {
        --gTempTextPrinter.textSpeed;
        gTextPrinters[printerTemplate->windowId] = gTempTextPrinter;
    }
    else
    {
        gTempTextPrinter.textSpeed = 0;
        for (j = 0; j < 0x400; ++j)
        {
            if (RenderFont(&gTempTextPrinter) == 1)
                break;
        }

        if (speed != TEXT_SPEED_FF)
            CopyWindowToVram(gTempTextPrinter.printerTemplate.windowId, 2);
        gTextPrinters[printerTemplate->windowId].active = 0;
    }
    gUnknown_03002F84 = 0;
    return TRUE;
}

void RunTextPrinters(void)
{
    int i;

    if (gUnknown_03002F84 == 0)
    {
        for (i = 0; i < NUM_TEXT_PRINTERS; ++i)
        {
            if (gTextPrinters[i].active)
            {
                u16 temp = RenderFont(&gTextPrinters[i]);
                switch (temp)
                {
                case 0:
                    CopyWindowToVram(gTextPrinters[i].printerTemplate.windowId, 2);
                case 3:
                    if (gTextPrinters[i].callback != 0)
                        gTextPrinters[i].callback(&gTextPrinters[i].printerTemplate, temp);
                    break;
                case 1:
                    gTextPrinters[i].active = 0;
                    break;
                }
            }
        }
    }
}

bool16 IsTextPrinterActive(u8 id)
{
    return gTextPrinters[id].active;
}

u32 RenderFont(struct TextPrinter *textPrinter)
{
    u32 ret;
    while (TRUE)
    {
        ret = gFonts[textPrinter->printerTemplate.fontId].fontFunction(textPrinter);
        if (ret != 2)
            return ret;
    }
}

void GenerateFontHalfRowLookupTable(u8 fgColor, u8 bgColor, u8 shadowColor)
{
    u32 fg12, bg12, shadow12;
    u32 temp;

    u16 *current = gFontHalfRowLookupTable;

    gLastTextBgColor = bgColor;
    gLastTextFgColor = fgColor;
    gLastTextShadowColor = shadowColor;

    bg12 = bgColor << 12;
    fg12 = fgColor << 12;
    shadow12 = shadowColor << 12;

    temp = (bgColor << 8) | (bgColor << 4) | bgColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (fgColor << 8) | (bgColor << 4) | bgColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (shadowColor << 8) | (bgColor << 4) | bgColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (bgColor << 8) | (fgColor << 4) | bgColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (fgColor << 8) | (fgColor << 4) | bgColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (shadowColor << 8) | (fgColor << 4) | bgColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (bgColor << 8) | (shadowColor << 4) | bgColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (fgColor << 8) | (shadowColor << 4) | bgColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (shadowColor << 8) | (shadowColor << 4) | bgColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (bgColor << 8) | (bgColor << 4) | fgColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (fgColor << 8) | (bgColor << 4) | fgColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (shadowColor << 8) | (bgColor << 4) | fgColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (bgColor << 8) | (fgColor << 4) | fgColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (fgColor << 8) | (fgColor << 4) | fgColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (shadowColor << 8) | (fgColor << 4) | fgColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (bgColor << 8) | (shadowColor << 4) | fgColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (fgColor << 8) | (shadowColor << 4) | fgColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (shadowColor << 8) | (shadowColor << 4) | fgColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (bgColor << 8) | (bgColor << 4) | shadowColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (fgColor << 8) | (bgColor << 4) | shadowColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (shadowColor << 8) | (bgColor << 4) | shadowColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (bgColor << 8) | (fgColor << 4) | shadowColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (fgColor << 8) | (fgColor << 4) | shadowColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (shadowColor << 8) | (fgColor << 4) | shadowColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (bgColor << 8) | (shadowColor << 4) | shadowColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (fgColor << 8) | (shadowColor << 4) | shadowColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;

    temp = (shadowColor << 8) | (shadowColor << 4) | shadowColor;
    *(current++) = (bg12) | temp;
    *(current++) = (fg12) | temp;
    *(current++) = (shadow12) | temp;
}

void SaveTextColors(u8 *fgColor, u8 *bgColor, u8 *shadowColor)
{
    *bgColor = gLastTextBgColor;
    *fgColor = gLastTextFgColor;
    *shadowColor = gLastTextShadowColor;
}

void RestoreTextColors(u8 *fgColor, u8 *bgColor, u8 *shadowColor)
{
    GenerateFontHalfRowLookupTable(*fgColor, *bgColor, *shadowColor);
}

void DecompressGlyphTile(const void *src_, void *dest_)
{
    u32 temp;
    const u16 *src = src_;
    u32 *dest = dest_;

    temp = *(src++);
    *(dest)++ = ((gFontHalfRowLookupTable[gFontHalfRowOffsets[temp & 0xFF]]) << 16) | (gFontHalfRowLookupTable[gFontHalfRowOffsets[temp >> 8]]);

    temp = *(src++);
    *(dest++) = ((gFontHalfRowLookupTable[gFontHalfRowOffsets[temp & 0xFF]]) << 16) | (gFontHalfRowLookupTable[gFontHalfRowOffsets[temp >> 8]]);

    temp = *(src++);
    *(dest++) = ((gFontHalfRowLookupTable[gFontHalfRowOffsets[temp & 0xFF]]) << 16) | (gFontHalfRowLookupTable[gFontHalfRowOffsets[temp >> 8]]);

    temp = *(src++);
    *(dest++) = ((gFontHalfRowLookupTable[gFontHalfRowOffsets[temp & 0xFF]]) << 16) | (gFontHalfRowLookupTable[gFontHalfRowOffsets[temp >> 8]]);

    temp = *(src++);
    *(dest++) = ((gFontHalfRowLookupTable[gFontHalfRowOffsets[temp & 0xFF]]) << 16) | (gFontHalfRowLookupTable[gFontHalfRowOffsets[temp >> 8]]);

    temp = *(src++);
    *(dest++) = ((gFontHalfRowLookupTable[gFontHalfRowOffsets[temp & 0xFF]]) << 16) | (gFontHalfRowLookupTable[gFontHalfRowOffsets[temp >> 8]]);

    temp = *(src++);
    *(dest++) = ((gFontHalfRowLookupTable[gFontHalfRowOffsets[temp & 0xFF]]) << 16) | (gFontHalfRowLookupTable[gFontHalfRowOffsets[temp >> 8]]);

    temp = *(src++);
    *(dest++) = ((gFontHalfRowLookupTable[gFontHalfRowOffsets[temp & 0xFF]]) << 16) | (gFontHalfRowLookupTable[gFontHalfRowOffsets[temp >> 8]]);
}

u8 GetLastTextColor(u8 colorType)
{
    switch (colorType)
    {
    case 0:
        return gLastTextFgColor;
    case 2:
        return gLastTextBgColor;
    case 1:
        return gLastTextShadowColor;
    default:
        return 0;
    }
}

inline static void GLYPH_COPY(u8 *windowTiles, u32 widthOffset, u32 j, u32 i, u32 *ptr, s32 width, s32 height)
{
    u32 xAdd, yAdd, r5, bits, toOrr, dummyX;
    u8 *dst;

    xAdd = j + width;
    yAdd = i + height;
    dummyX = j;
    for (; i < yAdd; i++)
    {
        r5 = *ptr++;
        for (j = dummyX; j < xAdd; j++)
        {
            if ((toOrr = r5 & 0xF))
            {
                dst = windowTiles + ((j / 8) * 32) + ((j % 8) / 2) + ((i / 8) * widthOffset) + ((i % 8) * 4);
                bits = ((j & 1) * 4);
                *dst = (toOrr << bits) | (*dst & (0xF0 >> bits));
            }
            r5 >>= 4;
        }
    }
}

void CopyGlyphToWindow(struct TextPrinter *textPrinter)
{
    struct Window *win;
    struct WindowTemplate *winTempl;
    u32 *unkStruct;
    u32 currX, currY, widthOffset;
    s32 r4, r0;
    u8 *windowTiles;

    win = &gWindows[textPrinter->printerTemplate.windowId];
    winTempl = &win->window;

    if ((r4 = (winTempl->width * 8) - textPrinter->printerTemplate.currentX) > gUnknown_03002F90.width)
        r4 = gUnknown_03002F90.width;

    if ((r0 = (winTempl->height * 8) - textPrinter->printerTemplate.currentY) > gUnknown_03002F90.height)
        r0 = gUnknown_03002F90.height;

    currX = textPrinter->printerTemplate.currentX;
    currY = textPrinter->printerTemplate.currentY;
    unkStruct = (u32 *)&gUnknown_03002F90.unk0;
    windowTiles = win->tileData;
    widthOffset = winTempl->width * 32;

    if (r4 < 9)
    {
        if (r0 < 9)
        {
            GLYPH_COPY(windowTiles, widthOffset, currX, currY, unkStruct, r4, r0);
        }
        else
        {
            GLYPH_COPY(windowTiles, widthOffset, currX, currY, unkStruct, r4, 8);
            GLYPH_COPY(windowTiles, widthOffset, currX, currY + 8, unkStruct + 16, r4, r0 - 8);
        }
    }
    else
    {
        if (r0 < 9)
        {
            GLYPH_COPY(windowTiles, widthOffset, currX, currY, unkStruct, 8, r0);
            GLYPH_COPY(windowTiles, widthOffset, currX + 8, currY, unkStruct + 8, r4 - 8, r0);
        }
        else
        {
            GLYPH_COPY(windowTiles, widthOffset, currX, currY, unkStruct, 8, 8);
            GLYPH_COPY(windowTiles, widthOffset, currX + 8, currY, unkStruct + 8, r4 - 8, 8);
            GLYPH_COPY(windowTiles, widthOffset, currX, currY + 8, unkStruct + 16, 8, r0 - 8);
            GLYPH_COPY(windowTiles, widthOffset, currX + 8, currY + 8, unkStruct + 24, r4 - 8, r0 - 8);
        }
    }
}

void ClearTextSpan(struct TextPrinter *textPrinter, u32 width)
{
    struct Window *window;
    struct Bitmap pixels_data;
    struct Struct_03002F90 *gUnk;
    u8* glyphHeight;

    if (gLastTextBgColor != 0)
    {
        window = &gWindows[textPrinter->printerTemplate.windowId];
        pixels_data.pixels = window->tileData;
        pixels_data.width = window->window.width << 3;
        pixels_data.height = window->window.height << 3;

        gUnk = &gUnknown_03002F90;
        glyphHeight = &gUnk->height;

        FillBitmapRect4Bit(
            &pixels_data,
            textPrinter->printerTemplate.currentX,
            textPrinter->printerTemplate.currentY,
            width,
            *glyphHeight,
            gLastTextBgColor);
    }
}

u16 Font0Func(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);

    if (subStruct->hasGlyphIdBeenSet == FALSE)
    {
        subStruct->glyphId = 0;
        subStruct->hasGlyphIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

u16 Font1Func(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);

    if (subStruct->hasGlyphIdBeenSet == FALSE)
    {
        subStruct->glyphId = 1;
        subStruct->hasGlyphIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

u16 Font2Func(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);

    if (subStruct->hasGlyphIdBeenSet == FALSE)
    {
        subStruct->glyphId = 2;
        subStruct->hasGlyphIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

u16 Font3Func(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);

    if (subStruct->hasGlyphIdBeenSet == FALSE)
    {
        subStruct->glyphId = 3;
        subStruct->hasGlyphIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

u16 Font4Func(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);

    if (subStruct->hasGlyphIdBeenSet == FALSE)
    {
        subStruct->glyphId = 4;
        subStruct->hasGlyphIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

u16 Font5Func(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);

    if (subStruct->hasGlyphIdBeenSet == FALSE)
    {
        subStruct->glyphId = 5;
        subStruct->hasGlyphIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

u16 Font7Func(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);

    if (subStruct->hasGlyphIdBeenSet == FALSE)
    {
        subStruct->glyphId = 7;
        subStruct->hasGlyphIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

u16 Font8Func(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);

    if (subStruct->hasGlyphIdBeenSet == FALSE)
    {
        subStruct->glyphId = 8;
        subStruct->hasGlyphIdBeenSet = TRUE;
    }
    return RenderText(textPrinter);
}

void TextPrinterInitDownArrowCounters(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);

    if (gTextFlags.autoScroll == 1)
    {
        subStruct->autoScrollDelay = 0;
    }
    else
    {
        subStruct->downArrowYPosIdx = 0;
        subStruct->downArrowDelay = 0;
    }
}

void TextPrinterDrawDownArrow(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);
    const u8 *arrowTiles;

    if (gTextFlags.autoScroll == 0)
    {
        if (subStruct->downArrowDelay != 0)
        {
            subStruct->downArrowDelay--;
        }
        else
        {
            FillWindowPixelRect(
                textPrinter->printerTemplate.windowId,
                textPrinter->printerTemplate.bgColor << 4 | textPrinter->printerTemplate.bgColor,
                textPrinter->printerTemplate.currentX,
                textPrinter->printerTemplate.currentY,
                8,
                16);

            switch (gTextFlags.useAlternateDownArrow)
            {
                case FALSE:
                default:
                    arrowTiles = gDownArrowTiles;
                    break;
                case TRUE:
                    arrowTiles = gDarkDownArrowTiles;
                    break;
            }

            BlitBitmapRectToWindow(
                textPrinter->printerTemplate.windowId,
                arrowTiles,
                0,
                gDownArrowYCoords[subStruct->downArrowYPosIdx],
                8,
                16,
                textPrinter->printerTemplate.currentX,
                textPrinter->printerTemplate.currentY,
                8,
                16);
            CopyWindowToVram(textPrinter->printerTemplate.windowId, 2);

            subStruct->downArrowDelay = 8;
            subStruct->downArrowYPosIdx++;
        }
    }
}

void TextPrinterClearDownArrow(struct TextPrinter *textPrinter)
{
    FillWindowPixelRect(
        textPrinter->printerTemplate.windowId,
        textPrinter->printerTemplate.bgColor << 4 | textPrinter->printerTemplate.bgColor,
        textPrinter->printerTemplate.currentX,
        textPrinter->printerTemplate.currentY,
        8,
        16);
    CopyWindowToVram(textPrinter->printerTemplate.windowId, 2);
}

bool8 TextPrinterWaitAutoMode(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);

    if (subStruct->autoScrollDelay == 49)
    {
        return TRUE;
    }
    else
    {
        subStruct->autoScrollDelay++;
        return FALSE;
    }
}

bool16 TextPrinterWaitWithDownArrow(struct TextPrinter *textPrinter)
{
    bool8 result = FALSE;
    if (gTextFlags.autoScroll != 0)
    {
        result = TextPrinterWaitAutoMode(textPrinter);
    }
    else
    {
        TextPrinterDrawDownArrow(textPrinter);
        if (JOY_NEW(A_BUTTON | B_BUTTON))
        {
            result = TRUE;
            PlaySE(SE_SELECT);
        }
    }
    return result;
}

bool16 TextPrinterWait(struct TextPrinter *textPrinter)
{
    bool16 result = FALSE;
    if (gTextFlags.autoScroll != 0)
    {
        result = TextPrinterWaitAutoMode(textPrinter);
    }
    else
    {
        if (JOY_NEW(A_BUTTON | B_BUTTON))
        {
            result = TRUE;
            PlaySE(SE_SELECT);
        }
    }
    return result;
}

void DrawDownArrow(u8 windowId, u16 x, u16 y, u8 bgColor, bool8 drawArrow, u8 *counter, u8 *yCoordIndex)
{
    const u8 *arrowTiles;

    if (*counter != 0)
    {
        --*counter;
    }
    else
    {
        FillWindowPixelRect(windowId, (bgColor << 4) | bgColor, x, y, 0x8, 0x10);
        if (drawArrow == 0)
        {
            switch (gTextFlags.useAlternateDownArrow)
            {
                case 0:
                default:
                    arrowTiles = gDownArrowTiles;
                    break;
                case 1:
                    arrowTiles = gDarkDownArrowTiles;
                    break;
            }

            BlitBitmapRectToWindow(
                windowId,
                arrowTiles,
                0,
                gDownArrowYCoords[*yCoordIndex & 3],
                0x8,
                0x10,
                x,
                y - 2,
                0x8,
                0x10);
            CopyWindowToVram(windowId, 0x2);
            *counter = 8;
            ++*yCoordIndex;
        }
    }
}

u16 RenderText(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);
    u16 currChar;
    s32 width;
    s32 widthHelper;

    switch (textPrinter->state)
    {
    case 0:
        if ((JOY_HELD(A_BUTTON | B_BUTTON)) && subStruct->hasPrintBeenSpedUp)
            textPrinter->delayCounter = 0;

        if (textPrinter->delayCounter && textPrinter->textSpeed)
        {
            textPrinter->delayCounter--;
            if (gTextFlags.canABSpeedUpPrint && (JOY_NEW(A_BUTTON | B_BUTTON)))
            {
                subStruct->hasPrintBeenSpedUp = TRUE;
                textPrinter->delayCounter = 0;
            }
            return 3;
        }

        if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED) && gTextFlags.autoScroll)
            textPrinter->delayCounter = 3;
        else
            textPrinter->delayCounter = textPrinter->textSpeed;

        currChar = *textPrinter->printerTemplate.currentChar;
        textPrinter->printerTemplate.currentChar++;

        switch (currChar)
        {
        case CHAR_NEWLINE:
            textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x;
            textPrinter->printerTemplate.currentY += (gFonts[textPrinter->printerTemplate.fontId].maxLetterHeight + textPrinter->printerTemplate.lineSpacing);
            return 2;
        case PLACEHOLDER_BEGIN:
            textPrinter->printerTemplate.currentChar++;
            return 2;
        case EXT_CTRL_CODE_BEGIN:
            currChar = *textPrinter->printerTemplate.currentChar;
            textPrinter->printerTemplate.currentChar++;
            switch (currChar)
            {
            case EXT_CTRL_CODE_COLOR:
                textPrinter->printerTemplate.fgColor = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                GenerateFontHalfRowLookupTable(textPrinter->printerTemplate.fgColor, textPrinter->printerTemplate.bgColor, textPrinter->printerTemplate.shadowColor);
                return 2;
            case EXT_CTRL_CODE_HIGHLIGHT:
                textPrinter->printerTemplate.bgColor = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                GenerateFontHalfRowLookupTable(textPrinter->printerTemplate.fgColor, textPrinter->printerTemplate.bgColor, textPrinter->printerTemplate.shadowColor);
                return 2;
            case EXT_CTRL_CODE_SHADOW:
                textPrinter->printerTemplate.shadowColor = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                GenerateFontHalfRowLookupTable(textPrinter->printerTemplate.fgColor, textPrinter->printerTemplate.bgColor, textPrinter->printerTemplate.shadowColor);
                return 2;
            case EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW:
                textPrinter->printerTemplate.fgColor = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                textPrinter->printerTemplate.bgColor = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                textPrinter->printerTemplate.shadowColor = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                GenerateFontHalfRowLookupTable(textPrinter->printerTemplate.fgColor, textPrinter->printerTemplate.bgColor, textPrinter->printerTemplate.shadowColor);
                return 2;
            case EXT_CTRL_CODE_PALETTE:
                textPrinter->printerTemplate.currentChar++;
                return 2;
            case EXT_CTRL_CODE_SIZE:
                subStruct->glyphId = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                return 2;
            case EXT_CTRL_CODE_RESET_SIZE:
                return 2;
            case EXT_CTRL_CODE_PAUSE:
                textPrinter->delayCounter = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                textPrinter->state = 6;
                return 2;
            case EXT_CTRL_CODE_PAUSE_UNTIL_PRESS:
                textPrinter->state = 1;
                if (gTextFlags.autoScroll)
                    subStruct->autoScrollDelay = 0;
                return 3;
            case EXT_CTRL_CODE_WAIT_SE:
                textPrinter->state = 5;
                return 3;
            case EXT_CTRL_CODE_PLAY_BGM:
                currChar = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                currChar |= *textPrinter->printerTemplate.currentChar << 8;
                textPrinter->printerTemplate.currentChar++;
                PlayBGM(currChar);
                return 2;
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
                return 2;
            case EXT_CTRL_CODE_SHIFT_TEXT:
                textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x + *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                return 2;
            case EXT_CTRL_CODE_SHIFT_DOWN:
                textPrinter->printerTemplate.currentY = textPrinter->printerTemplate.y + *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                return 2;
            case EXT_CTRL_CODE_FILL_WINDOW:
                FillWindowPixelBuffer(textPrinter->printerTemplate.windowId, PIXEL_FILL(textPrinter->printerTemplate.bgColor));
                textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x;
                textPrinter->printerTemplate.currentY = textPrinter->printerTemplate.y;
                return 2;
            case EXT_CTRL_CODE_PAUSE_MUSIC:
                m4aMPlayStop(&gMPlayInfo_BGM);
                return 2;
            case EXT_CTRL_CODE_RESUME_MUSIC:
                m4aMPlayContinue(&gMPlayInfo_BGM);
                return 2;
            case EXT_CTRL_CODE_CLEAR:
                width = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                if (width > 0)
                {
                    ClearTextSpan(textPrinter, width);
                    textPrinter->printerTemplate.currentX += width;
                    return 0;
                }
                return 2;
            case EXT_CTRL_CODE_SKIP:
                textPrinter->printerTemplate.currentX = *textPrinter->printerTemplate.currentChar + textPrinter->printerTemplate.x;
                textPrinter->printerTemplate.currentChar++;
                return 2;
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
                        return 0;
                    }
                }
                return 2;
            case EXT_CTRL_CODE_MIN_LETTER_SPACING:
                textPrinter->minLetterSpacing = *textPrinter->printerTemplate.currentChar++;
                return 2;
            case EXT_CTRL_CODE_JPN:
                textPrinter->japanese = 1;
                return 2;
            case EXT_CTRL_CODE_ENG:
                textPrinter->japanese = 0;
                return 2;
            }
            break;
        case CHAR_PROMPT_CLEAR:
            textPrinter->state = 2;
            TextPrinterInitDownArrowCounters(textPrinter);
            return 3;
        case CHAR_PROMPT_SCROLL:
            textPrinter->state = 3;
            TextPrinterInitDownArrowCounters(textPrinter);
            return 3;
        case CHAR_EXTRA_SYMBOL:
            currChar = *textPrinter->printerTemplate.currentChar | 0x100;
            textPrinter->printerTemplate.currentChar++;
            break;
        case CHAR_KEYPAD_ICON:
            currChar = *textPrinter->printerTemplate.currentChar++;
            gUnknown_03002F90.width = DrawKeypadIcon(textPrinter->printerTemplate.windowId, currChar, textPrinter->printerTemplate.currentX, textPrinter->printerTemplate.currentY);
            textPrinter->printerTemplate.currentX += gUnknown_03002F90.width + textPrinter->printerTemplate.letterSpacing;
            return 0;
        case EOS:
            return 1;
        }

        switch (subStruct->glyphId)
        {
        case 0:
            DecompressGlyphFont0(currChar, textPrinter->japanese);
            break;
        case 1:
            DecompressGlyphFont1(currChar, textPrinter->japanese);
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            DecompressGlyphFont2(currChar, textPrinter->japanese);
            break;
        case 7:
            DecompressGlyphFont7(currChar, textPrinter->japanese);
            break;
        case 8:
            DecompressGlyphFont8(currChar, textPrinter->japanese);
            break;
        case 6:
            break;
        }

        CopyGlyphToWindow(textPrinter);

        if (textPrinter->minLetterSpacing)
        {
            textPrinter->printerTemplate.currentX += gUnknown_03002F90.width;
            width = textPrinter->minLetterSpacing - gUnknown_03002F90.width;
            if (width > 0)
            {
                ClearTextSpan(textPrinter, width);
                textPrinter->printerTemplate.currentX += width;
            }
        }
        else
        {
            if (textPrinter->japanese)
                textPrinter->printerTemplate.currentX += (gUnknown_03002F90.width + textPrinter->printerTemplate.letterSpacing);
            else
                textPrinter->printerTemplate.currentX += gUnknown_03002F90.width;
        }
        return 0;
    case 1:
        if (TextPrinterWait(textPrinter))
            textPrinter->state = 0;
        return 3;
    case 2:
        if (TextPrinterWaitWithDownArrow(textPrinter))
        {
            FillWindowPixelBuffer(textPrinter->printerTemplate.windowId, PIXEL_FILL(textPrinter->printerTemplate.bgColor));
            textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x;
            textPrinter->printerTemplate.currentY = textPrinter->printerTemplate.y;
            textPrinter->state = 0;
        }
        return 3;
    case 3:
        if (TextPrinterWaitWithDownArrow(textPrinter))
        {
            TextPrinterClearDownArrow(textPrinter);
            textPrinter->scrollDistance = gFonts[textPrinter->printerTemplate.fontId].maxLetterHeight + textPrinter->printerTemplate.lineSpacing;
            textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x;
            textPrinter->state = 4;
        }
        return 3;
    case 4:
        if (textPrinter->scrollDistance)
        {
            int scrollSpeed = GetPlayerTextSpeed();
            int speed = gWindowVerticalScrollSpeeds[scrollSpeed];
            if (textPrinter->scrollDistance < speed)
            {
                ScrollWindow(textPrinter->printerTemplate.windowId, 0, textPrinter->scrollDistance, PIXEL_FILL(textPrinter->printerTemplate.bgColor));
                textPrinter->scrollDistance = 0;
            }
            else
            {
                ScrollWindow(textPrinter->printerTemplate.windowId, 0, speed, PIXEL_FILL(textPrinter->printerTemplate.bgColor));
                textPrinter->scrollDistance -= speed;
            }
            CopyWindowToVram(textPrinter->printerTemplate.windowId, 2);
        }
        else
        {
            textPrinter->state = 0;
        }
        return 3;
    case 5:
        if (!IsSEPlaying())
            textPrinter->state = 0;
        return 3;
    case 6:
        if (textPrinter->delayCounter != 0)
            textPrinter->delayCounter--;
        else
            textPrinter->state = 0;
        return 3;
    }

    return 1;
}

u32 GetStringWidthFixedWidthFont(const u8 *str, u8 fontId, u8 letterSpacing)
{
    int i;
    u8 width;
    int temp;
    int temp2;
    u8 line;
    int strPos;
    u8 lineWidths[8];
    const u8 *strLocal;

    for (i = 0; i < 8; i++)
    {
        lineWidths[i] = 0;
    }

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
                ++strPos;
            case EXT_CTRL_CODE_PLAY_BGM:
            case EXT_CTRL_CODE_PLAY_SE:
                ++strPos;
            case EXT_CTRL_CODE_COLOR:
            case EXT_CTRL_CODE_HIGHLIGHT:
            case EXT_CTRL_CODE_SHADOW:
            case EXT_CTRL_CODE_PALETTE:
            case EXT_CTRL_CODE_SIZE:
            case EXT_CTRL_CODE_PAUSE:
            case EXT_CTRL_CODE_ESCAPE:
            case EXT_CTRL_CODE_SHIFT_TEXT:
            case EXT_CTRL_CODE_SHIFT_DOWN:
            case EXT_CTRL_CODE_CLEAR:
            case EXT_CTRL_CODE_SKIP:
            case EXT_CTRL_CODE_CLEAR_TO:
            case EXT_CTRL_CODE_MIN_LETTER_SPACING:
                ++strPos;
                break;
            case EXT_CTRL_CODE_RESET_SIZE:
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

u32 (*GetFontWidthFunc(u8 glyphId))(u16, bool32)
{
    u32 i;

    for (i = 0; i < 9; ++i)
    {
        if (glyphId == gGlyphWidthFuncs[i].fontId)
            return gGlyphWidthFuncs[i].func;
    }

    return NULL;
}

s32 GetStringWidth(u8 fontId, const u8 *str, s16 letterSpacing)
{
    bool8 isJapanese;
    int minGlyphWidth;
    u32 (*func)(u16 glyphId, bool32 isJapanese);
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
                ++str;
            case EXT_CTRL_CODE_PLAY_BGM:
            case EXT_CTRL_CODE_PLAY_SE:
                ++str;
            case EXT_CTRL_CODE_COLOR:
            case EXT_CTRL_CODE_HIGHLIGHT:
            case EXT_CTRL_CODE_SHADOW:
            case EXT_CTRL_CODE_PALETTE:
            case EXT_CTRL_CODE_PAUSE:
            case EXT_CTRL_CODE_ESCAPE:
            case EXT_CTRL_CODE_SHIFT_TEXT:
            case EXT_CTRL_CODE_SHIFT_DOWN:
                ++str;
                break;
            case EXT_CTRL_CODE_SIZE:
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
            case EXT_CTRL_CODE_RESET_SIZE:
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
    else
        return width;
}

u8 RenderTextFont9(u8 *pixels, u8 fontId, u8 *str)
{
    u8 shadowColor;
    u8 *strLocal;
    int strPos;
    int temp;
    int temp2;
    u8 colorBackup[3];
    u8 fgColor;
    u8 bgColor;

    SaveTextColors(&colorBackup[0], &colorBackup[1], &colorBackup[2]);

    fgColor = TEXT_COLOR_WHITE;
    bgColor = TEXT_COLOR_TRANSPARENT;
    shadowColor = TEXT_COLOR_LIGHT_GREY;

    GenerateFontHalfRowLookupTable(TEXT_COLOR_WHITE, TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_GREY);
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
                fgColor = strLocal[strPos++];
                bgColor = strLocal[strPos++];
                shadowColor = strLocal[strPos++];
                GenerateFontHalfRowLookupTable(fgColor, bgColor, shadowColor);
                continue;
            case EXT_CTRL_CODE_COLOR:
                fgColor = strLocal[strPos++];
                GenerateFontHalfRowLookupTable(fgColor, bgColor, shadowColor);
                continue;
            case EXT_CTRL_CODE_HIGHLIGHT:
                bgColor = strLocal[strPos++];
                GenerateFontHalfRowLookupTable(fgColor, bgColor, shadowColor);
                continue;
            case EXT_CTRL_CODE_SHADOW:
                shadowColor = strLocal[strPos++];
                GenerateFontHalfRowLookupTable(fgColor, bgColor, shadowColor);
                continue;
            case EXT_CTRL_CODE_SIZE:
                fontId = strLocal[strPos++];
                break;
            case EXT_CTRL_CODE_PLAY_BGM:
            case EXT_CTRL_CODE_PLAY_SE:
                ++strPos;
            case EXT_CTRL_CODE_PALETTE:
            case EXT_CTRL_CODE_PAUSE:
            case EXT_CTRL_CODE_ESCAPE:
            case EXT_CTRL_CODE_SHIFT_TEXT:
            case EXT_CTRL_CODE_SHIFT_DOWN:
            case EXT_CTRL_CODE_CLEAR:
            case EXT_CTRL_CODE_SKIP:
            case EXT_CTRL_CODE_CLEAR_TO:
            case EXT_CTRL_CODE_MIN_LETTER_SPACING:
                ++strPos;
                break;
            case EXT_CTRL_CODE_RESET_SIZE:
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
            case 9:
                DecompressGlyphFont9(temp);
                break;
            case 1:
            default:
                DecompressGlyphFont1(temp, 1);
                break;
            }
            CpuCopy32(gUnknown_03002F90.unk0, pixels, 0x20);
            CpuCopy32(gUnknown_03002F90.unk40, pixels + 0x20, 0x20);
            pixels += 0x40;
            break;
        }
    }
    while (temp != EOS);

    RestoreTextColors(&colorBackup[0], &colorBackup[1], &colorBackup[2]);
    return 1;
}

u8 DrawKeypadIcon(u8 windowId, u8 keypadIconId, u16 x, u16 y)
{
    BlitBitmapRectToWindow(
        windowId,
        gKeypadIconTiles + (gKeypadIcons[keypadIconId].tileOffset * 0x20),
        0,
        0,
        0x80,
        0x80,
        x,
        y,
        gKeypadIcons[keypadIconId].width,
        gKeypadIcons[keypadIconId].height);
    return gKeypadIcons[keypadIconId].width;
}

u8 GetKeypadIconTileOffset(u8 keypadIconId)
{
    return gKeypadIcons[keypadIconId].tileOffset;
}

u8 GetKeypadIconWidth(u8 keypadIconId)
{
    return gKeypadIcons[keypadIconId].width;
}

u8 GetKeypadIconHeight(u8 keypadIconId)
{
    return gKeypadIcons[keypadIconId].height;
}

void SetDefaultFontsPointer(void)
{
    SetFontsPointer(&gFontInfos[0]);
}

u8 GetFontAttribute(u8 fontId, u8 attributeId)
{
    int result = 0;
    switch (attributeId)
    {
        case FONTATTR_MAX_LETTER_WIDTH:
            result = gFontInfos[fontId].maxLetterWidth;
            break;
        case FONTATTR_MAX_LETTER_HEIGHT:
            result = gFontInfos[fontId].maxLetterHeight;
            break;
        case FONTATTR_LETTER_SPACING:
            result = gFontInfos[fontId].letterSpacing;
            break;
        case FONTATTR_LINE_SPACING:
            result = gFontInfos[fontId].lineSpacing;
            break;
        case FONTATTR_UNKNOWN:
            result = gFontInfos[fontId].unk;
            break;
        case FONTATTR_COLOR_FOREGROUND:
            result = gFontInfos[fontId].fgColor;
            break;
        case FONTATTR_COLOR_BACKGROUND:
            result = gFontInfos[fontId].bgColor;
            break;
        case FONTATTR_COLOR_SHADOW:
            result = gFontInfos[fontId].shadowColor;
            break;
    }
    return result;
}

u8 GetMenuCursorDimensionByFont(u8 fontId, u8 whichDimension)
{
    return gMenuCursorDimensions[fontId][whichDimension];
}

void DecompressGlyphFont0(u16 glyphId, bool32 isJapanese)
{
    const u16* glyphs;

    if (isJapanese == 1)
    {
        glyphs = gFont0JapaneseGlyphs + (0x100 * (glyphId >> 0x4)) + (0x8 * (glyphId & 0xF));
        DecompressGlyphTile(glyphs, gUnknown_03002F90.unk0);
        DecompressGlyphTile(glyphs + 0x80, gUnknown_03002F90.unk40);    // gUnknown_03002F90 + 0x40
        gUnknown_03002F90.width = 8;     // gGlyphWidth
        gUnknown_03002F90.height = 12;    // gGlyphHeight
    }
    else
    {
        glyphs = gFont0LatinGlyphs + (0x20 * glyphId);
        gUnknown_03002F90.width = gFont0LatinGlyphWidths[glyphId];

        if (gUnknown_03002F90.width <= 8)
        {
            DecompressGlyphTile(glyphs, gUnknown_03002F90.unk0);
            DecompressGlyphTile(glyphs + 0x10, gUnknown_03002F90.unk40);
        }
        else
        {
            DecompressGlyphTile(glyphs, gUnknown_03002F90.unk0);
            DecompressGlyphTile(glyphs + 0x8, gUnknown_03002F90.unk20);
            DecompressGlyphTile(glyphs + 0x10, gUnknown_03002F90.unk40);
            DecompressGlyphTile(glyphs + 0x18, gUnknown_03002F90.unk60);
        }

        gUnknown_03002F90.height = 13;
    }
}

u32 GetGlyphWidthFont0(u16 glyphId, bool32 isJapanese)
{
    if (isJapanese == TRUE)
        return 8;
    else
        return gFont0LatinGlyphWidths[glyphId];
}

void DecompressGlyphFont7(u16 glyphId, bool32 isJapanese)
{
    const u16* glyphs;

    if (isJapanese == TRUE)
    {
        int eff;
        glyphs = gFont1JapaneseGlyphs + (0x100 * (glyphId >> 0x4)) + (0x8 * (glyphId & (eff = 0xF)));  // shh, no questions, only matching now
        DecompressGlyphTile(glyphs, gUnknown_03002F90.unk0);
        DecompressGlyphTile(glyphs + 0x80, gUnknown_03002F90.unk40);    // gUnknown_03002F90 + 0x40
        gUnknown_03002F90.width = 8;     // gGlyphWidth
        gUnknown_03002F90.height = 15;    // gGlyphHeight
    }
    else
    {
        glyphs = gFont7LatinGlyphs + (0x20 * glyphId);
        gUnknown_03002F90.width = gFont7LatinGlyphWidths[glyphId];

        if (gUnknown_03002F90.width <= 8)
        {
            DecompressGlyphTile(glyphs, gUnknown_03002F90.unk0);
            DecompressGlyphTile(glyphs + 0x10, gUnknown_03002F90.unk40);
        }
        else
        {
            DecompressGlyphTile(glyphs, gUnknown_03002F90.unk0);
            DecompressGlyphTile(glyphs + 0x8, gUnknown_03002F90.unk20);
            DecompressGlyphTile(glyphs + 0x10, gUnknown_03002F90.unk40);
            DecompressGlyphTile(glyphs + 0x18, gUnknown_03002F90.unk60);
        }

        gUnknown_03002F90.height = 15;
    }
}

u32 GetGlyphWidthFont7(u16 glyphId, bool32 isJapanese)
{
    if (isJapanese == TRUE)
        return 8;
    else
        return gFont7LatinGlyphWidths[glyphId];
}

void DecompressGlyphFont8(u16 glyphId, bool32 isJapanese)
{
    const u16* glyphs;

    if (isJapanese == TRUE)
    {
        glyphs = gFont0JapaneseGlyphs + (0x100 * (glyphId >> 0x4)) + (0x8 * (glyphId & 0xF));
        DecompressGlyphTile(glyphs, gUnknown_03002F90.unk0);
        DecompressGlyphTile(glyphs + 0x80, gUnknown_03002F90.unk40);    // gUnknown_03002F90 + 0x40
        gUnknown_03002F90.width = 8;     // gGlyphWidth
        gUnknown_03002F90.height = 12;    // gGlyphHeight
    }
    else
    {
        glyphs = gFont8LatinGlyphs + (0x20 * glyphId);
        gUnknown_03002F90.width = gFont8LatinGlyphWidths[glyphId];

        if (gUnknown_03002F90.width <= 8)
        {
            DecompressGlyphTile(glyphs, gUnknown_03002F90.unk0);
            DecompressGlyphTile(glyphs + 0x10, gUnknown_03002F90.unk40);
        }
        else
        {
            DecompressGlyphTile(glyphs, gUnknown_03002F90.unk0);
            DecompressGlyphTile(glyphs + 0x8, gUnknown_03002F90.unk20);
            DecompressGlyphTile(glyphs + 0x10, gUnknown_03002F90.unk40);
            DecompressGlyphTile(glyphs + 0x18, gUnknown_03002F90.unk60);
        }

        gUnknown_03002F90.height = 12;
    }
}

u32 GetGlyphWidthFont8(u16 glyphId, bool32 isJapanese)
{
    if (isJapanese == TRUE)
        return 8;
    else
        return gFont8LatinGlyphWidths[glyphId];
}

void DecompressGlyphFont2(u16 glyphId, bool32 isJapanese)
{
    const u16* glyphs;

    if (isJapanese == TRUE)
    {
        glyphs = gFont2JapaneseGlyphs + (0x100 * (glyphId >> 0x3)) + (0x10 * (glyphId & 0x7));
        DecompressGlyphTile(glyphs, gUnknown_03002F90.unk0);
        DecompressGlyphTile(glyphs + 0x8, gUnknown_03002F90.unk20);    // gUnknown_03002F90 + 0x40
        DecompressGlyphTile(glyphs + 0x80, gUnknown_03002F90.unk40);    // gUnknown_03002F90 + 0x20
        DecompressGlyphTile(glyphs + 0x88, gUnknown_03002F90.unk60);    // gUnknown_03002F90 + 0x60
        gUnknown_03002F90.width = gFont2JapaneseGlyphWidths[glyphId];     // gGlyphWidth
        gUnknown_03002F90.height = 14;    // gGlyphHeight
    }
    else
    {
        glyphs = gFont2LatinGlyphs + (0x20 * glyphId);
        gUnknown_03002F90.width = gFont2LatinGlyphWidths[glyphId];

        if (gUnknown_03002F90.width <= 8)
        {
            DecompressGlyphTile(glyphs, gUnknown_03002F90.unk0);
            DecompressGlyphTile(glyphs + 0x10, gUnknown_03002F90.unk40);
        }
        else
        {
            DecompressGlyphTile(glyphs, gUnknown_03002F90.unk0);
            DecompressGlyphTile(glyphs + 0x8, gUnknown_03002F90.unk20);
            DecompressGlyphTile(glyphs + 0x10, gUnknown_03002F90.unk40);
            DecompressGlyphTile(glyphs + 0x18, gUnknown_03002F90.unk60);
        }

        gUnknown_03002F90.height = 14;
    }
}

u32 GetGlyphWidthFont2(u16 glyphId, bool32 isJapanese)
{
    if (isJapanese == TRUE)
        return gFont2JapaneseGlyphWidths[glyphId];
    else
        return gFont2LatinGlyphWidths[glyphId];
}

void DecompressGlyphFont1(u16 glyphId, bool32 isJapanese)
{
    const u16* glyphs;

    if (isJapanese == TRUE)
    {
        int eff;
        glyphs = gFont1JapaneseGlyphs + (0x100 * (glyphId >> 0x4)) + (0x8 * (glyphId & (eff = 0xF)));  // shh, no questions, only matching now
        DecompressGlyphTile(glyphs, gUnknown_03002F90.unk0);
        DecompressGlyphTile(glyphs + 0x80, gUnknown_03002F90.unk40);    // gUnknown_03002F90 + 0x40
        gUnknown_03002F90.width = 8;     // gGlyphWidth
        gUnknown_03002F90.height = 15;    // gGlyphHeight
    }
    else
    {
        glyphs = gFont1LatinGlyphs + (0x20 * glyphId);
        gUnknown_03002F90.width = gFont1LatinGlyphWidths[glyphId];

        if (gUnknown_03002F90.width <= 8)
        {
            DecompressGlyphTile(glyphs, gUnknown_03002F90.unk0);
            DecompressGlyphTile(glyphs + 0x10, gUnknown_03002F90.unk40);
        }
        else
        {
            DecompressGlyphTile(glyphs, gUnknown_03002F90.unk0);
            DecompressGlyphTile(glyphs + 0x8, gUnknown_03002F90.unk20);
            DecompressGlyphTile(glyphs + 0x10, gUnknown_03002F90.unk40);
            DecompressGlyphTile(glyphs + 0x18, gUnknown_03002F90.unk60);
        }

        gUnknown_03002F90.height = 15;
    }
}

u32 GetGlyphWidthFont1(u16 glyphId, bool32 isJapanese)
{
    if (isJapanese == TRUE)
        return 8;
    else
        return gFont1LatinGlyphWidths[glyphId];
}

void DecompressGlyphFont9(u16 glyphId)
{
    const u16* glyphs;

    glyphs = gFont9JapaneseGlyphs + (0x100 * (glyphId >> 4)) + (0x8 * (glyphId & 0xF));
    DecompressGlyphTile(glyphs, gUnknown_03002F90.unk0);
    DecompressGlyphTile(glyphs + 0x80, gUnknown_03002F90.unk40);
    gUnknown_03002F90.width = 8;
    gUnknown_03002F90.height = 12;
}
