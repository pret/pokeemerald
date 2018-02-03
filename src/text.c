#include "global.h"
#include "battle.h"
#include "main.h"
#include "m4a.h"
#include "palette.h"
#include "sound.h"
#include "string_util.h"
#include "window.h"
#include "text.h"

extern void FillBitmapRect4Bit(struct Bitmap *surface, u16 x, u16 y, u16 width, u16 height, u8 fillValue);
extern void FillWindowPixelRect(u8 windowId, u8 fillValue, u16 x, u16 y, u16 width, u16 height);
extern void BlitBitmapRectToWindow(u8 windowId, const u8 *pixels, u16 srcX, u16 srcY, u16 srcWidth, int srcHeight, u16 destX, u16 destY, u16 rectWidth, u16 rectHeight);
extern u8 GetKeypadIconWidth(u8 keypadIconId);
extern void CopyWindowToVram(u8 windowId, u8 mode);
extern u16 Font6Func(struct TextPrinter *textPrinter);
extern u32 GetGlyphWidthFont6(u16 glyphId, bool32 isJapanese);
extern void PlaySE(u16 songNum);
extern u8* UnkTextUtil_GetPtrI(u8 a1);
extern int sub_8197964();

EWRAM_DATA struct TextPrinter gTempTextPrinter = {0};
EWRAM_DATA struct TextPrinter gTextPrinters[NUM_TEXT_PRINTERS] = {0};

static u16 gFontHalfRowLookupTable[0x51];
static u16 gLastTextBgColor;
static u16 gLastTextFgColor;
static u16 gLastTextShadowColor;

extern struct Main gMain;
extern struct MusicPlayerInfo gMPlayInfo_BGM;

const struct FontInfo *gFonts;
u8 gUnknown_03002F84;
u8 gUnknown_03002F90[0x20];
u8 gUnknown_03002FB0[0x20];
u8 gUnknown_03002FD0[0x20];
u8 gUnknown_03002FF0[0x20];
u8 gGlyphDimensions[0x2];
TextFlags gTextFlags;

const u8 gFontHalfRowOffsets[] = {
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

const u8 gDownArrowTiles[] = INCBIN_U8("data/graphics/fonts/down_arrow.4bpp");
const u8 gDarkDownArrowTiles[] = INCBIN_U8("data/graphics/fonts/down_arrow_RS.4bpp");
const u8 gUnusedFRLGBlankedDownArrow[] = INCBIN_U8("data/graphics/fonts/unused_frlg_blanked_down_arrow.4bpp");
const u8 gUnusedFRLGDownArrow[] = INCBIN_U8("data/graphics/fonts/unused_frlg_down_arrow.4bpp");
const u8 gDownArrowYCoords[] = { 0x0, 0x1, 0x2, 0x1 };
const u8 gWindowVerticalScrollSpeeds[] = { 0x1, 0x2, 0x4, 0x0 };

const struct GlyphWidthFunc gGlyphWidthFuncs[] = {
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

const struct KeypadIcon gKeypadIcons[] = {
    {  0x0,  0x8, 0xC },
    {  0x1,  0x8, 0xC },
    {  0x2, 0x10, 0xC },
    {  0x4, 0x10, 0xC },
    {  0x6, 0x18, 0xC },
    {  0x9, 0x18, 0xC },
    {  0xC,  0x8, 0xC },
    {  0xD,  0x8, 0xC },
    {  0xE,  0x8, 0xC },
    {  0xF,  0x8, 0xC },
    { 0x20,  0x8, 0xC },
    { 0x21,  0x8, 0xC },
    { 0x22,  0x8, 0xC }
};

const u8 gKeypadIconTiles[] = INCBIN_U8("data/graphics/fonts/keypad_icons.4bpp");

const struct FontInfo gFontInfos[] = {
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

const u8 gMenuCursorDimensions[][2] = {
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

const u16 gFont9JapaneseGlyphs[] = INCBIN_U16("data/graphics/fonts/font9.hwjpnfont");

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

void DeactivateAllTextPrinters (void)
{
    int printer;
    for (printer = 0; printer < NUM_TEXT_PRINTERS; ++printer)
        gTextPrinters[printer].sub_union.sub.active = 0;
}

u16 PrintTextOnWindow(u8 windowId, u8 fontId, const u8 *str, u8 x, u8 y, u8 speed, void (*callback)(struct TextSubPrinter *, u16))
{
    struct TextSubPrinter subPrinter;

    subPrinter.current_text_offset = str;
    subPrinter.windowId = windowId;
    subPrinter.fontId = fontId;
    subPrinter.x = x;
    subPrinter.y = y;
    subPrinter.currentX = x;
    subPrinter.currentY = y;
    subPrinter.letterSpacing = gFonts[fontId].letterSpacing;
    subPrinter.lineSpacing = gFonts[fontId].lineSpacing;
    subPrinter.fontColor_l = gFonts[fontId].fontColor_l;
    subPrinter.fontColor_h = gFonts[fontId].fontColor_h;
    subPrinter.bgColor = gFonts[fontId].bgColor;
    subPrinter.shadowColor = gFonts[fontId].shadowColor;
    return AddTextPrinter(&subPrinter, speed, callback);
}

bool16 AddTextPrinter(struct TextSubPrinter *textSubPrinter, u8 speed, void (*callback)(struct TextSubPrinter *, u16))
{
    int i;
    u16 j;

    if (!gFonts)
        return FALSE;

    gTempTextPrinter.sub_union.sub.active = 1;
    gTempTextPrinter.state = 0;
    gTempTextPrinter.text_speed = speed;
    gTempTextPrinter.delayCounter = 0;
    gTempTextPrinter.scrollDistance = 0;

    for (i = 0; i < 7; ++i)
    {
        gTempTextPrinter.sub_union.sub_fields[i] = 0;
    }

    gTempTextPrinter.subPrinter = *textSubPrinter;
    gTempTextPrinter.callback = callback;
    gTempTextPrinter.minLetterSpacing = 0;
    gTempTextPrinter.japanese = 0;

    GenerateFontHalfRowLookupTable(textSubPrinter->fontColor_h, textSubPrinter->bgColor, textSubPrinter->shadowColor);
    if (speed != TEXT_SPEED_FF && speed != 0x0)
    {
        --gTempTextPrinter.text_speed;
        gTextPrinters[textSubPrinter->windowId] = gTempTextPrinter;
    }
    else
    {
        gTempTextPrinter.text_speed = 0;
        for (j = 0; j < 0x400; ++j)
        {
            if ((u32)RenderFont(&gTempTextPrinter) == 1)
                break;
        }

        if (speed != TEXT_SPEED_FF)
          CopyWindowToVram(gTempTextPrinter.subPrinter.windowId, 2);
        gTextPrinters[textSubPrinter->windowId].sub_union.sub.active = 0;
    }
    gUnknown_03002F84 = 0;
    return TRUE;
}

void RunTextPrinters(void)
{
    int i;
    u16 temp;

    if (gUnknown_03002F84 == 0)
    {
        for (i = 0; i < 0x20; ++i)
        {
            if (gTextPrinters[i].sub_union.sub.active != 0)
            {
                temp = RenderFont(&gTextPrinters[i]);
                switch (temp) {
                    case 0:
                        CopyWindowToVram(gTextPrinters[i].subPrinter.windowId, 2);
                    case 3:
                        if (gTextPrinters[i].callback != 0)
                            gTextPrinters[i].callback(&gTextPrinters[i].subPrinter, temp);
                        break;
                    case 1:
                        gTextPrinters[i].sub_union.sub.active = 0;
                        break;
                }
            }
        }
    }
}

bool16 IsTextPrinterActive(u8 id)
{
    return gTextPrinters[id].sub_union.sub.active;
}

u32 RenderFont(struct TextPrinter *textPrinter)
{
    u32 ret;
    while (TRUE)
    {
        ret = gFonts[textPrinter->subPrinter.fontId].fontFunction(textPrinter);
        if (ret != 2)
            return ret;
    }
}

#ifdef NONMATCHING
void GenerateFontHalfRowLookupTable(u8 fgColor, u8 bgColor, u8 shadowColor)
{
    u16* current = gFontHalfRowLookupTable;

    gLastTextBgColor = bgColor;
    gLastTextFgColor = fgColor;
    gLastTextShadowColor = shadowColor;

    *(current++) = (bgColor << 12) | (bgColor << 8) | (bgColor << 4) | bgColor;
    *(current++) = (fgColor << 12) | (bgColor << 8) | (bgColor << 4) | bgColor;
    *(current++) = (shadowColor << 12) | (bgColor << 8) | (bgColor << 4) | bgColor;

    *(current++) = (bgColor << 12) | (fgColor << 8) | (bgColor << 4) | bgColor;
    *(current++) = (fgColor << 12) | (fgColor << 8) | (bgColor << 4) | bgColor;
    *(current++) = (shadowColor << 12) | (fgColor << 8) | (bgColor << 4) | bgColor;

    *(current++) = (bgColor << 12) | (shadowColor << 8) | (bgColor << 4) | bgColor;
    *(current++) = (fgColor << 12) | (shadowColor << 8) | (bgColor << 4) | bgColor;
    *(current++) = (shadowColor << 12) | (shadowColor << 8) | (bgColor << 4) | bgColor;

    *(current++) = (bgColor << 12) | (bgColor << 8) | (fgColor << 4) | bgColor;
    *(current++) = (fgColor << 12) | (bgColor << 8) | (fgColor << 4) | bgColor;
    *(current++) = (shadowColor << 12) | (bgColor << 8) | (fgColor << 4) | bgColor;

    *(current++) = (bgColor << 12) | (fgColor << 8) | (fgColor << 4) | bgColor;
    *(current++) = (fgColor << 12) | (fgColor << 8) | (fgColor << 4) | bgColor;
    *(current++) = (shadowColor << 12) | (fgColor << 8) | (fgColor << 4) | bgColor;

    *(current++) = (bgColor << 12) | (shadowColor << 8) | (fgColor << 4) | bgColor;
    *(current++) = (fgColor << 12) | (shadowColor << 8) | (fgColor << 4) | bgColor;
    *(current++) = (shadowColor << 12) | (shadowColor << 8) | (fgColor << 4) | bgColor;

    *(current++) = (bgColor << 12) | (bgColor << 8) | (shadowColor << 4) | bgColor;
    *(current++) = (fgColor << 12) | (bgColor << 8) | (shadowColor << 4) | bgColor;
    *(current++) = (shadowColor << 12) | (bgColor << 8) | (shadowColor << 4) | bgColor;

    *(current++) = (bgColor << 12) | (fgColor << 8) | (shadowColor << 4) | bgColor;
    *(current++) = (fgColor << 12) | (fgColor << 8) | (shadowColor << 4) | bgColor;
    *(current++) = (shadowColor << 12) | (fgColor << 8) | (shadowColor << 4) | bgColor;

    *(current++) = (bgColor << 12) | (shadowColor << 8) | (shadowColor << 4) | bgColor;
    *(current++) = (fgColor << 12) | (shadowColor << 8) | (shadowColor << 4) | bgColor;
    *(current++) = (shadowColor << 12) | (shadowColor << 8) | (shadowColor << 4) | bgColor;

    *(current++) = (bgColor << 12) | (bgColor << 8) | (bgColor << 4) | fgColor;
    *(current++) = (fgColor << 12) | (bgColor << 8) | (bgColor << 4) | fgColor;
    *(current++) = (shadowColor << 12) | (bgColor << 8) | (bgColor << 4) | fgColor;

    *(current++) = (bgColor << 12) | (fgColor << 8) | (bgColor << 4) | fgColor;
    *(current++) = (fgColor << 12) | (fgColor << 8) | (bgColor << 4) | fgColor;
    *(current++) = (shadowColor << 12) | (fgColor << 8) | (bgColor << 4) | fgColor;

    *(current++) = (bgColor << 12) | (shadowColor << 8) | (bgColor << 4) | fgColor;
    *(current++) = (fgColor << 12) | (shadowColor << 8) | (bgColor << 4) | fgColor;
    *(current++) = (shadowColor << 12) | (shadowColor << 8) | (bgColor << 4) | fgColor;

    *(current++) = (bgColor << 12) | (bgColor << 8) | (fgColor << 4) | fgColor;
    *(current++) = (fgColor << 12) | (bgColor << 8) | (fgColor << 4) | fgColor;
    *(current++) = (shadowColor << 12) | (bgColor << 8) | (fgColor << 4) | fgColor;

    *(current++) = (bgColor << 12) | (fgColor << 8) | (fgColor << 4) | fgColor;
    *(current++) = (fgColor << 12) | (fgColor << 8) | (fgColor << 4) | fgColor;
    *(current++) = (shadowColor << 12) | (fgColor << 8) | (fgColor << 4) | fgColor;

    *(current++) = (bgColor << 12) | (shadowColor << 8) | (fgColor << 4) | fgColor;
    *(current++) = (fgColor << 12) | (shadowColor << 8) | (fgColor << 4) | fgColor;
    *(current++) = (shadowColor << 12) | (shadowColor << 8) | (fgColor << 4) | fgColor;

    *(current++) = (bgColor << 12) | (bgColor << 8) | (shadowColor << 4) | fgColor;
    *(current++) = (fgColor << 12) | (bgColor << 8) | (shadowColor << 4) | fgColor;
    *(current++) = (shadowColor << 12) | (bgColor << 8) | (shadowColor << 4) | fgColor;

    *(current++) = (bgColor << 12) | (fgColor << 8) | (shadowColor << 4) | fgColor;
    *(current++) = (fgColor << 12) | (fgColor << 8) | (shadowColor << 4) | fgColor;
    *(current++) = (shadowColor << 12) | (fgColor << 8) | (shadowColor << 4) | fgColor;

    *(current++) = (bgColor << 12) | (shadowColor << 8) | (shadowColor << 4) | fgColor;
    *(current++) = (fgColor << 12) | (shadowColor << 8) | (shadowColor << 4) | fgColor;
    *(current++) = (shadowColor << 12) | (shadowColor << 8) | (shadowColor << 4) | fgColor;

    *(current++) = (bgColor << 12) | (bgColor << 8) | (bgColor << 4) | shadowColor;
    *(current++) = (fgColor << 12) | (bgColor << 8) | (bgColor << 4) | shadowColor;
    *(current++) = (shadowColor << 12) | (bgColor << 8) | (bgColor << 4) | shadowColor;

    *(current++) = (bgColor << 12) | (fgColor << 8) | (bgColor << 4) | shadowColor;
    *(current++) = (fgColor << 12) | (fgColor << 8) | (bgColor << 4) | shadowColor;
    *(current++) = (shadowColor << 12) | (fgColor << 8) | (bgColor << 4) | shadowColor;

    *(current++) = (bgColor << 12) | (shadowColor << 8) | (bgColor << 4) | shadowColor;
    *(current++) = (fgColor << 12) | (shadowColor << 8) | (bgColor << 4) | shadowColor;
    *(current++) = (shadowColor << 12) | (shadowColor << 8) | (bgColor << 4) | shadowColor;

    *(current++) = (bgColor << 12) | (bgColor << 8) | (fgColor << 4) | shadowColor;
    *(current++) = (fgColor << 12) | (bgColor << 8) | (fgColor << 4) | shadowColor;
    *(current++) = (shadowColor << 12) | (bgColor << 8) | (fgColor << 4) | shadowColor;

    *(current++) = (bgColor << 12) | (fgColor << 8) | (fgColor << 4) | shadowColor;
    *(current++) = (fgColor << 12) | (fgColor << 8) | (fgColor << 4) | shadowColor;
    *(current++) = (shadowColor << 12) | (fgColor << 8) | (fgColor << 4) | shadowColor;

    *(current++) = (bgColor << 12) | (shadowColor << 8) | (fgColor << 4) | shadowColor;
    *(current++) = (fgColor << 12) | (shadowColor << 8) | (fgColor << 4) | shadowColor;
    *(current++) = (shadowColor << 12) | (shadowColor << 8) | (fgColor << 4) | shadowColor;

    *(current++) = (bgColor << 12) | (bgColor << 8) | (shadowColor << 4) | shadowColor;
    *(current++) = (fgColor << 12) | (bgColor << 8) | (shadowColor << 4) | shadowColor;
    *(current++) = (shadowColor << 12) | (bgColor << 8) | (shadowColor << 4) | shadowColor;

    *(current++) = (bgColor << 12) | (fgColor << 8) | (shadowColor << 4) | shadowColor;
    *(current++) = (fgColor << 12) | (fgColor << 8) | (shadowColor << 4) | shadowColor;
    *(current++) = (shadowColor << 12) | (fgColor << 8) | (shadowColor << 4) | shadowColor;

    *(current++) = (bgColor << 12) | (shadowColor << 8) | (shadowColor << 4) | shadowColor;
    *(current++) = (fgColor << 12) | (shadowColor << 8) | (shadowColor << 4) | shadowColor;
    *(current++) = (shadowColor << 12) | (shadowColor << 8) | (shadowColor << 4) | shadowColor;
}
#else
ASM_DIRECT
void GenerateFontHalfRowLookupTable(u8 fgColor, u8 bgColor, u8 shadowColor)
{
    asm("push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, #0x24\n\
    lsl r0, #24\n\
    lsr r0, #24\n\
    lsl r1, #24\n\
    lsr r1, #24\n\
    lsl r2, #24\n\
    lsr r2, #24\n\
    ldr r3, =gFontHalfRowLookupTable\n\
    ldr r4, =gLastTextBgColor\n\
    strh r1, [r4]\n\
    ldr r4, =gLastTextFgColor\n\
    strh r0, [r4]\n\
    ldr r4, =gLastTextShadowColor\n\
    strh r2, [r4]\n\
    lsl r5, r1, #12\n\
    lsl r6, r0, #12\n\
    lsl r4, r2, #12\n\
    mov r8, r4\n\
    lsl r7, r1, #8\n\
    str r7, [sp]\n\
    lsl r4, r1, #4\n\
    mov r9, r4\n\
    orr r7, r4\n\
    str r7, [sp, #0x4]\n\
    orr r7, r1\n\
    add r4, r5, #0\n\
    orr r4, r7\n\
    strh r4, [r3]\n\
    add r3, #0x2\n\
    add r4, r6, #0\n\
    orr r4, r7\n\
    strh r4, [r3]\n\
    add r3, #0x2\n\
    mov r4, r8\n\
    orr r7, r4\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    lsl r7, r0, #8\n\
    mov r10, r7\n\
    mov r4, r10\n\
    mov r7, r9\n\
    orr r4, r7\n\
    str r4, [sp, #0x8]\n\
    add r7, r4, #0\n\
    orr r7, r1\n\
    add r4, r5, #0\n\
    orr r4, r7\n\
    strh r4, [r3]\n\
    add r3, #0x2\n\
    add r4, r6, #0\n\
    orr r4, r7\n\
    strh r4, [r3]\n\
    add r3, #0x2\n\
    mov r4, r8\n\
    orr r7, r4\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    lsl r7, r2, #8\n\
    mov r12, r7\n\
    mov r4, r12\n\
    mov r7, r9\n\
    orr r4, r7\n\
    str r4, [sp, #0xC]\n\
    add r7, r4, #0\n\
    orr r7, r1\n\
    add r4, r5, #0\n\
    orr r4, r7\n\
    strh r4, [r3]\n\
    add r3, #0x2\n\
    add r4, r6, #0\n\
    orr r4, r7\n\
    strh r4, [r3]\n\
    add r3, #0x2\n\
    mov r4, r8\n\
    orr r7, r4\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    lsl r7, r0, #4\n\
    mov r9, r7\n\
    ldr r4, [sp]\n\
    orr r4, r7\n\
    str r4, [sp, #0x10]\n\
    add r7, r4, #0\n\
    orr r7, r1\n\
    add r4, r5, #0\n\
    orr r4, r7\n\
    strh r4, [r3]\n\
    add r3, #0x2\n\
    add r4, r6, #0\n\
    orr r4, r7\n\
    strh r4, [r3]\n\
    add r3, #0x2\n\
    mov r4, r8\n\
    orr r7, r4\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    mov r7, r10\n\
    add r4, r7, #0\n\
    mov r7, r9\n\
    orr r4, r7\n\
    str r4, [sp, #0x14]\n\
    add r7, r4, #0\n\
    orr r7, r1\n\
    add r4, r5, #0\n\
    orr r4, r7\n\
    strh r4, [r3]\n\
    add r3, #0x2\n\
    add r4, r6, #0\n\
    orr r4, r7\n\
    strh r4, [r3]\n\
    add r3, #0x2\n\
    mov r4, r8\n\
    orr r7, r4\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    mov r7, r12\n\
    add r4, r7, #0\n\
    mov r7, r9\n\
    orr r4, r7\n\
    str r4, [sp, #0x18]\n\
    add r7, r4, #0\n\
    orr r7, r1\n\
    add r4, r5, #0\n\
    orr r4, r7\n\
    strh r4, [r3]\n\
    add r3, #0x2\n\
    add r4, r6, #0\n\
    orr r4, r7\n\
    strh r4, [r3]\n\
    add r3, #0x2\n\
    mov r4, r8\n\
    orr r7, r4\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    lsl r7, r2, #4\n\
    mov r9, r7\n\
    mov r4, r9\n\
    ldr r7, [sp]\n\
    orr r7, r4\n\
    str r7, [sp, #0x1C]\n\
    orr r7, r1\n\
    add r4, r5, #0\n\
    orr r4, r7\n\
    strh r4, [r3]\n\
    add r3, #0x2\n\
    add r4, r6, #0\n\
    orr r4, r7\n\
    strh r4, [r3]\n\
    add r3, #0x2\n\
    mov r4, r8\n\
    orr r7, r4\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    mov r7, r9\n\
    mov r4, r10\n\
    orr r4, r7\n\
    str r4, [sp, #0x20]\n\
    add r7, r4, #0\n\
    orr r7, r1\n\
    add r4, r5, #0\n\
    orr r4, r7\n\
    strh r4, [r3]\n\
    add r3, #0x2\n\
    add r4, r6, #0\n\
    orr r4, r7\n\
    strh r4, [r3]\n\
    add r3, #0x2\n\
    mov r4, r8\n\
    orr r7, r4\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    mov r4, r12\n\
    mov r7, r9\n\
    orr r4, r7\n\
    add r7, r4, #0\n\
    orr r7, r1\n\
    add r1, r5, #0\n\
    orr r1, r7\n\
    strh r1, [r3]\n\
    add r3, #0x2\n\
    add r1, r6, #0\n\
    orr r1, r7\n\
    strh r1, [r3]\n\
    add r3, #0x2\n\
    mov r1, r8\n\
    orr r7, r1\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    ldr r7, [sp, #0x4]\n\
    orr r7, r0\n\
    add r1, r5, #0\n\
    orr r1, r7\n\
    strh r1, [r3]\n\
    add r3, #0x2\n\
    add r1, r6, #0\n\
    orr r1, r7\n\
    strh r1, [r3]\n\
    add r3, #0x2\n\
    mov r1, r8\n\
    orr r7, r1\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    ldr r7, [sp, #0x8]\n\
    orr r7, r0\n\
    add r1, r5, #0\n\
    orr r1, r7\n\
    strh r1, [r3]\n\
    add r3, #0x2\n\
    add r1, r6, #0\n\
    orr r1, r7\n\
    strh r1, [r3]\n\
    add r3, #0x2\n\
    mov r1, r8\n\
    orr r7, r1\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    ldr r7, [sp, #0xC]\n\
    orr r7, r0\n\
    add r1, r5, #0\n\
    orr r1, r7\n\
    strh r1, [r3]\n\
    add r3, #0x2\n\
    add r1, r6, #0\n\
    orr r1, r7\n\
    strh r1, [r3]\n\
    add r3, #0x2\n\
    mov r1, r8\n\
    orr r7, r1\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    ldr r7, [sp, #0x10]\n\
    orr r7, r0\n\
    add r1, r5, #0\n\
    orr r1, r7\n\
    strh r1, [r3]\n\
    add r3, #0x2\n\
    add r1, r6, #0\n\
    orr r1, r7\n\
    strh r1, [r3]\n\
    add r3, #0x2\n\
    mov r1, r8\n\
    orr r7, r1\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    ldr r7, [sp, #0x14]\n\
    orr r7, r0\n\
    add r1, r5, #0\n\
    orr r1, r7\n\
    strh r1, [r3]\n\
    add r3, #0x2\n\
    add r1, r6, #0\n\
    orr r1, r7\n\
    strh r1, [r3]\n\
    add r3, #0x2\n\
    mov r1, r8\n\
    orr r7, r1\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    ldr r7, [sp, #0x18]\n\
    orr r7, r0\n\
    add r1, r5, #0\n\
    orr r1, r7\n\
    strh r1, [r3]\n\
    add r3, #0x2\n\
    add r1, r6, #0\n\
    orr r1, r7\n\
    strh r1, [r3]\n\
    add r3, #0x2\n\
    mov r1, r8\n\
    orr r7, r1\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    ldr r7, [sp, #0x1C]\n\
    orr r7, r0\n\
    add r1, r5, #0\n\
    orr r1, r7\n\
    strh r1, [r3]\n\
    add r3, #0x2\n\
    add r1, r6, #0\n\
    orr r1, r7\n\
    strh r1, [r3]\n\
    add r3, #0x2\n\
    mov r1, r8\n\
    orr r7, r1\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    ldr r7, [sp, #0x20]\n\
    orr r7, r0\n\
    add r1, r5, #0\n\
    orr r1, r7\n\
    strh r1, [r3]\n\
    add r3, #0x2\n\
    add r1, r6, #0\n\
    orr r1, r7\n\
    strh r1, [r3]\n\
    add r3, #0x2\n\
    mov r1, r8\n\
    orr r7, r1\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    add r7, r4, #0\n\
    orr r7, r0\n\
    add r0, r5, #0\n\
    orr r0, r7\n\
    strh r0, [r3]\n\
    add r3, #0x2\n\
    add r0, r6, #0\n\
    orr r0, r7\n\
    strh r0, [r3]\n\
    add r3, #0x2\n\
    orr r7, r1\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    add r7, r2, #0\n\
    ldr r0, [sp, #0x4]\n\
    orr r7, r0\n\
    add r0, r5, #0\n\
    orr r0, r7\n\
    strh r0, [r3]\n\
    add r3, #0x2\n\
    add r0, r6, #0\n\
    orr r0, r7\n\
    strh r0, [r3]\n\
    add r3, #0x2\n\
    orr r7, r1\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    add r7, r2, #0\n\
    ldr r1, [sp, #0x8]\n\
    orr r7, r1\n\
    add r0, r5, #0\n\
    orr r0, r7\n\
    strh r0, [r3]\n\
    add r3, #0x2\n\
    add r0, r6, #0\n\
    orr r0, r7\n\
    strh r0, [r3]\n\
    add r3, #0x2\n\
    mov r0, r8\n\
    orr r7, r0\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    add r7, r2, #0\n\
    ldr r1, [sp, #0xC]\n\
    orr r7, r1\n\
    add r0, r5, #0\n\
    orr r0, r7\n\
    strh r0, [r3]\n\
    add r3, #0x2\n\
    add r0, r6, #0\n\
    orr r0, r7\n\
    strh r0, [r3]\n\
    add r3, #0x2\n\
    mov r0, r8\n\
    orr r7, r0\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    add r7, r2, #0\n\
    ldr r1, [sp, #0x10]\n\
    orr r7, r1\n\
    add r0, r5, #0\n\
    orr r0, r7\n\
    strh r0, [r3]\n\
    add r3, #0x2\n\
    add r0, r6, #0\n\
    orr r0, r7\n\
    strh r0, [r3]\n\
    add r3, #0x2\n\
    mov r0, r8\n\
    orr r7, r0\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    add r7, r2, #0\n\
    ldr r1, [sp, #0x14]\n\
    orr r7, r1\n\
    add r0, r5, #0\n\
    orr r0, r7\n\
    strh r0, [r3]\n\
    add r3, #0x2\n\
    add r0, r6, #0\n\
    orr r0, r7\n\
    strh r0, [r3]\n\
    add r3, #0x2\n\
    mov r0, r8\n\
    orr r7, r0\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    add r7, r2, #0\n\
    ldr r1, [sp, #0x18]\n\
    orr r7, r1\n\
    add r0, r5, #0\n\
    orr r0, r7\n\
    strh r0, [r3]\n\
    add r3, #0x2\n\
    add r0, r6, #0\n\
    orr r0, r7\n\
    strh r0, [r3]\n\
    add r3, #0x2\n\
    mov r0, r8\n\
    orr r7, r0\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    add r7, r2, #0\n\
    ldr r1, [sp, #0x1C]\n\
    orr r7, r1\n\
    add r0, r5, #0\n\
    orr r0, r7\n\
    strh r0, [r3]\n\
    add r3, #0x2\n\
    add r0, r6, #0\n\
    orr r0, r7\n\
    strh r0, [r3]\n\
    add r3, #0x2\n\
    mov r0, r8\n\
    orr r7, r0\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    add r7, r2, #0\n\
    ldr r1, [sp, #0x20]\n\
    orr r7, r1\n\
    add r0, r5, #0\n\
    orr r0, r7\n\
    strh r0, [r3]\n\
    add r3, #0x2\n\
    add r0, r6, #0\n\
    orr r0, r7\n\
    strh r0, [r3]\n\
    add r3, #0x2\n\
    mov r0, r8\n\
    orr r7, r0\n\
    strh r7, [r3]\n\
    add r3, #0x2\n\
    add r7, r2, #0\n\
    orr r7, r4\n\
    orr r5, r7\n\
    strh r5, [r3]\n\
    add r3, #0x2\n\
    orr r6, r7\n\
    strh r6, [r3]\n\
    orr r0, r7\n\
    strh r0, [r3, #0x2]\n\
    add sp, #0x24\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool");
}
#endif

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

#ifdef NONMATCHING
void DecompressGlyphTile(const u16 *src, u16 *dest)
{
    u32 temp;

    temp = src[0];
    *(dest++) = (gFontHalfRowLookupTable[gFontHalfRowOffsets[temp & 0xFF]] << 16) | gFontHalfRowLookupTable[gFontHalfRowOffsets[temp >> 8]];
    temp = src[1];
    src += 2;
    dest[1] = (gFontHalfRowLookupTable[gFontHalfRowOffsets[temp & 0xFF]] << 16) | gFontHalfRowLookupTable[gFontHalfRowOffsets[temp >> 8]];
    dest++;
    temp = *(src++);
    *(dest++) = (gFontHalfRowLookupTable[gFontHalfRowOffsets[temp & 0xFF]] << 16) | gFontHalfRowLookupTable[gFontHalfRowOffsets[temp >> 8]];
    temp = *(src++);
    *(dest++) = (gFontHalfRowLookupTable[gFontHalfRowOffsets[temp & 0xFF]] << 16) | gFontHalfRowLookupTable[gFontHalfRowOffsets[temp >> 8]];
    temp = *(src++);
    *(dest++) = (gFontHalfRowLookupTable[gFontHalfRowOffsets[temp & 0xFF]] << 16) | gFontHalfRowLookupTable[gFontHalfRowOffsets[temp >> 8]];
    temp = *(src++);
    *(dest++) = (gFontHalfRowLookupTable[gFontHalfRowOffsets[temp & 0xFF]] << 16) | gFontHalfRowLookupTable[gFontHalfRowOffsets[temp >> 8]];
    *(dest++) = (gFontHalfRowLookupTable[gFontHalfRowOffsets[src[0] & 0xFF]] << 16) | gFontHalfRowLookupTable[gFontHalfRowOffsets[src[0] >> 8]];
    *(dest) = (gFontHalfRowLookupTable[gFontHalfRowOffsets[src[1] & 0xFF]] << 16) | gFontHalfRowLookupTable[gFontHalfRowOffsets[src[1] >> 8]];
}
#else
ASM_DIRECT
void DecompressGlyphTile(const u16 *src, u16 *dest)
{
    asm("push {r4-r7,lr}\n\
    mov r7, r8\n\
    push {r7}\n\
    ldrh r7, [r0]\n\
    ldr r5, =gFontHalfRowLookupTable\n\
    ldr r4, =gFontHalfRowOffsets\n\
    mov r2, #0xFF\n\
    mov r8, r2\n\
    add r2, r7, #0\n\
    mov r3, r8\n\
    and r2, r3\n\
    add r2, r4\n\
    ldrb r2, [r2]\n\
    lsl r2, #1\n\
    add r2, r5\n\
    ldrh r3, [r2]\n\
    lsl r3, #16\n\
    lsr r2, r7, #8\n\
    add r2, r4\n\
    ldrb r2, [r2]\n\
    lsl r2, #1\n\
    add r2, r5\n\
    ldrh r2, [r2]\n\
    orr r3, r2\n\
    add r6, r1, #0\n\
    stmia r6!, {r3}\n\
    ldrh r7, [r0, #0x2]\n\
    add r0, #0x4\n\
    add r2, r7, #0\n\
    mov r3, r8\n\
    and r2, r3\n\
    add r2, r4\n\
    ldrb r2, [r2]\n\
    lsl r2, #1\n\
    add r2, r5\n\
    ldrh r3, [r2]\n\
    lsl r3, #16\n\
    lsr r2, r7, #8\n\
    add r2, r4\n\
    ldrb r2, [r2]\n\
    lsl r2, #1\n\
    add r2, r5\n\
    ldrh r2, [r2]\n\
    orr r3, r2\n\
    str r3, [r1, #0x4]\n\
    add r6, #0x4\n\
    ldrh r7, [r0]\n\
    add r0, #0x2\n\
    add r1, r7, #0\n\
    mov r2, r8\n\
    and r1, r2\n\
    add r1, r4\n\
    ldrb r1, [r1]\n\
    lsl r1, #1\n\
    add r1, r5\n\
    ldrh r2, [r1]\n\
    lsl r2, #16\n\
    lsr r1, r7, #8\n\
    add r1, r4\n\
    ldrb r1, [r1]\n\
    lsl r1, #1\n\
    add r1, r5\n\
    ldrh r1, [r1]\n\
    orr r2, r1\n\
    stmia r6!, {r2}\n\
    ldrh r7, [r0]\n\
    add r0, #0x2\n\
    add r1, r7, #0\n\
    mov r3, r8\n\
    and r1, r3\n\
    add r1, r4\n\
    ldrb r1, [r1]\n\
    lsl r1, #1\n\
    add r1, r5\n\
    ldrh r2, [r1]\n\
    lsl r2, #16\n\
    lsr r1, r7, #8\n\
    add r1, r4\n\
    ldrb r1, [r1]\n\
    lsl r1, #1\n\
    add r1, r5\n\
    ldrh r1, [r1]\n\
    orr r2, r1\n\
    stmia r6!, {r2}\n\
    ldrh r7, [r0]\n\
    add r0, #0x2\n\
    add r1, r7, #0\n\
    and r1, r3\n\
    add r1, r4\n\
    ldrb r1, [r1]\n\
    lsl r1, #1\n\
    add r1, r5\n\
    ldrh r2, [r1]\n\
    lsl r2, #16\n\
    lsr r1, r7, #8\n\
    add r1, r4\n\
    ldrb r1, [r1]\n\
    lsl r1, #1\n\
    add r1, r5\n\
    ldrh r1, [r1]\n\
    orr r2, r1\n\
    stmia r6!, {r2}\n\
    ldrh r7, [r0]\n\
    add r0, #0x2\n\
    add r1, r7, #0\n\
    and r1, r3\n\
    add r1, r4\n\
    ldrb r1, [r1]\n\
    lsl r1, #1\n\
    add r1, r5\n\
    ldrh r2, [r1]\n\
    lsl r2, #16\n\
    lsr r1, r7, #8\n\
    add r1, r4\n\
    ldrb r1, [r1]\n\
    lsl r1, #1\n\
    add r1, r5\n\
    ldrh r1, [r1]\n\
    orr r2, r1\n\
    stmia r6!, {r2}\n\
    ldrh r7, [r0]\n\
    add r1, r7, #0\n\
    and r1, r3\n\
    add r1, r4\n\
    ldrb r1, [r1]\n\
    lsl r1, #1\n\
    add r1, r5\n\
    ldrh r2, [r1]\n\
    lsl r2, #16\n\
    lsr r1, r7, #8\n\
    add r1, r4\n\
    ldrb r1, [r1]\n\
    lsl r1, #1\n\
    add r1, r5\n\
    ldrh r1, [r1]\n\
    orr r2, r1\n\
    stmia r6!, {r2}\n\
    ldrh r7, [r0, #0x2]\n\
    add r0, r7, #0\n\
    and r0, r3\n\
    add r0, r4\n\
    ldrb r0, [r0]\n\
    lsl r0, #1\n\
    add r0, r5\n\
    ldrh r1, [r0]\n\
    lsl r1, #16\n\
    lsr r0, r7, #8\n\
    add r0, r4\n\
    ldrb r0, [r0]\n\
    lsl r0, #1\n\
    add r0, r5\n\
    ldrh r0, [r0]\n\
    orr r1, r0\n\
    str r1, [r6]\n\
    pop {r3}\n\
    mov r8, r3\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool");
}
#endif

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

ASM_DIRECT
void CopyGlyphToWindow(struct TextPrinter *x)
{
    asm("push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, #0x8C\n\
    add r3, r0, #0\n\
    ldrb r1, [r3, #0x4]\n\
    lsl r0, r1, #1\n\
    add r0, r1\n\
    lsl r0, #2\n\
    ldr r1, =gWindows\n\
    add r1, r0, r1\n\
    add r2, r1, #0\n\
    ldrb r7, [r1, #0x3]\n\
    lsl r0, r7, #3\n\
    ldrb r6, [r3, #0x8]\n\
    sub r4, r0, r6\n\
    ldr r5, =gUnknown_03002F90\n\
    add r0, r5, #0\n\
    add r0, #0x80\n\
    ldrb r0, [r0]\n\
    cmp r4, r0\n\
    ble _08004DD2\n\
    add r4, r0, #0\n\
_08004DD2:\n\
    ldrb r0, [r1, #0x4]\n\
    lsl r0, #3\n\
    ldrb r3, [r3, #0x9]\n\
    sub r0, r3\n\
    add r1, r5, #0\n\
    add r1, #0x81\n\
    ldrb r1, [r1]\n\
    cmp r0, r1\n\
    ble _08004DE6\n\
    add r0, r1, #0\n\
_08004DE6:\n\
    str r6, [sp]\n\
    mov r8, r3\n\
    add r3, r5, #0\n\
    ldr r2, [r2, #0x8]\n\
    mov r9, r2\n\
    lsl r1, r7, #5\n\
    str r1, [sp, #0x4]\n\
    cmp r4, #0x8\n\
    ble _08004DFA\n\
    b _08004F94\n\
_08004DFA:\n\
    cmp r0, #0x8\n\
    bgt _08004E84\n\
    mov r1, r8\n\
    str r3, [sp, #0x8]\n\
    add r2, r6, #0\n\
    add r2, r4\n\
    mov r8, r2\n\
    add r0, r1, r0\n\
    str r0, [sp, #0xC]\n\
    str r6, [sp, #0x10]\n\
    cmp r1, r0\n\
    bcc _08004E14\n\
    b _080052AA\n\
_08004E14:\n\
    ldr r3, [sp, #0x8]\n\
    ldm r3!, {r5}\n\
    str r3, [sp, #0x8]\n\
    ldr r4, [sp, #0x10]\n\
    add r0, r1, #0x1\n\
    mov r10, r0\n\
    cmp r4, r8\n\
    bcs _08004E72\n\
    mov r2, #0x7\n\
    mov r12, r2\n\
    lsr r0, r1, #3\n\
    ldr r2, [sp, #0x4]\n\
    add r3, r0, #0\n\
    mul r3, r2\n\
    add r7, r3, #0\n\
    mov r3, r12\n\
    and r1, r3\n\
    lsl r6, r1, #2\n\
_08004E38:\n\
    add r3, r5, #0\n\
    mov r0, #0xF\n\
    and r3, r0\n\
    cmp r3, #0\n\
    beq _08004E6A\n\
    lsr r2, r4, #3\n\
    lsl r2, #5\n\
    add r2, r9\n\
    add r0, r4, #0\n\
    mov r1, r12\n\
    and r0, r1\n\
    lsr r0, #1\n\
    add r2, r0\n\
    add r2, r7\n\
    add r2, r6\n\
    mov r1, #0x1\n\
    and r1, r4\n\
    lsl r1, #2\n\
    lsl r3, r1\n\
    mov r0, #0xF0\n\
    asr r0, r1\n\
    ldrb r1, [r2]\n\
    and r0, r1\n\
    orr r3, r0\n\
    strb r3, [r2]\n\
_08004E6A:\n\
    lsr r5, #4\n\
    add r4, #0x1\n\
    cmp r4, r8\n\
    bcc _08004E38\n\
_08004E72:\n\
    mov r1, r10\n\
    ldr r2, [sp, #0xC]\n\
    cmp r1, r2\n\
    bcc _08004E14\n\
    b _080052AA\n\
    .pool\n\
_08004E84:\n\
    mov r1, r8\n\
    str r3, [sp, #0x14]\n\
    ldr r3, [sp]\n\
    add r3, r4\n\
    mov r12, r3\n\
    add r2, r1, #0\n\
    add r2, #0x8\n\
    str r2, [sp, #0x18]\n\
    ldr r3, [sp]\n\
    str r3, [sp, #0x1C]\n\
    mov r2, r12\n\
    str r2, [sp, #0x74]\n\
    ldr r3, [sp, #0x18]\n\
    str r3, [sp, #0x88]\n\
    sub r0, #0x8\n\
    str r0, [sp, #0x80]\n\
    cmp r1, r3\n\
    bcs _08004F0E\n\
_08004EA8:\n\
    ldr r0, [sp, #0x14]\n\
    ldm r0!, {r5}\n\
    str r0, [sp, #0x14]\n\
    ldr r4, [sp, #0x1C]\n\
    add r2, r1, #0x1\n\
    mov r8, r2\n\
    cmp r4, r12\n\
    bcs _08004F06\n\
    mov r3, #0x7\n\
    mov r10, r3\n\
    lsr r0, r1, #3\n\
    ldr r3, [sp, #0x4]\n\
    add r2, r0, #0\n\
    mul r2, r3\n\
    add r7, r2, #0\n\
    mov r0, r10\n\
    and r1, r0\n\
    lsl r6, r1, #2\n\
_08004ECC:\n\
    add r3, r5, #0\n\
    mov r1, #0xF\n\
    and r3, r1\n\
    cmp r3, #0\n\
    beq _08004EFE\n\
    lsr r2, r4, #3\n\
    lsl r2, #5\n\
    add r2, r9\n\
    add r0, r4, #0\n\
    mov r1, r10\n\
    and r0, r1\n\
    lsr r0, #1\n\
    add r2, r0\n\
    add r2, r7\n\
    add r2, r6\n\
    mov r1, #0x1\n\
    and r1, r4\n\
    lsl r1, #2\n\
    lsl r3, r1\n\
    mov r0, #0xF0\n\
    asr r0, r1\n\
    ldrb r1, [r2]\n\
    and r0, r1\n\
    orr r3, r0\n\
    strb r3, [r2]\n\
_08004EFE:\n\
    lsr r5, #4\n\
    add r4, #0x1\n\
    cmp r4, r12\n\
    bcc _08004ECC\n\
_08004F06:\n\
    mov r1, r8\n\
    ldr r2, [sp, #0x18]\n\
    cmp r1, r2\n\
    bcc _08004EA8\n\
_08004F0E:\n\
    ldr r1, [sp, #0x88]\n\
    ldr r3, =gUnknown_03002FD0\n\
    str r3, [sp, #0x20]\n\
    ldr r0, [sp, #0x74]\n\
    mov r8, r0\n\
    ldr r2, [sp, #0x80]\n\
    add r2, r1, r2\n\
    str r2, [sp, #0x24]\n\
    ldr r3, [sp]\n\
    str r3, [sp, #0x28]\n\
    cmp r1, r2\n\
    bcc _08004F28\n\
    b _080052AA\n\
_08004F28:\n\
    ldr r0, [sp, #0x20]\n\
    ldm r0!, {r5}\n\
    str r0, [sp, #0x20]\n\
    ldr r4, [sp, #0x28]\n\
    add r2, r1, #0x1\n\
    mov r10, r2\n\
    cmp r4, r8\n\
    bcs _08004F86\n\
    mov r3, #0x7\n\
    mov r12, r3\n\
    lsr r0, r1, #3\n\
    ldr r3, [sp, #0x4]\n\
    add r2, r0, #0\n\
    mul r2, r3\n\
    add r7, r2, #0\n\
    mov r0, r12\n\
    and r1, r0\n\
    lsl r6, r1, #2\n\
_08004F4C:\n\
    add r3, r5, #0\n\
    mov r1, #0xF\n\
    and r3, r1\n\
    cmp r3, #0\n\
    beq _08004F7E\n\
    lsr r2, r4, #3\n\
    lsl r2, #5\n\
    add r2, r9\n\
    add r0, r4, #0\n\
    mov r1, r12\n\
    and r0, r1\n\
    lsr r0, #1\n\
    add r2, r0\n\
    add r2, r7\n\
    add r2, r6\n\
    mov r1, #0x1\n\
    and r1, r4\n\
    lsl r1, #2\n\
    lsl r3, r1\n\
    mov r0, #0xF0\n\
    asr r0, r1\n\
    ldrb r1, [r2]\n\
    and r0, r1\n\
    orr r3, r0\n\
    strb r3, [r2]\n\
_08004F7E:\n\
    lsr r5, #4\n\
    add r4, #0x1\n\
    cmp r4, r8\n\
    bcc _08004F4C\n\
_08004F86:\n\
    mov r1, r10\n\
    ldr r2, [sp, #0x24]\n\
    cmp r1, r2\n\
    bcc _08004F28\n\
    b _080052AA\n\
    .pool\n\
_08004F94:\n\
    cmp r0, #0x8\n\
    ble _08004F9A\n\
    b _080050A4\n\
_08004F9A:\n\
    mov r1, r8\n\
    str r3, [sp, #0x2C]\n\
    ldr r3, [sp]\n\
    add r3, #0x8\n\
    mov r12, r3\n\
    add r0, r8\n\
    str r0, [sp, #0x30]\n\
    ldr r0, [sp]\n\
    str r0, [sp, #0x34]\n\
    ldr r2, [sp, #0x30]\n\
    str r2, [sp, #0x78]\n\
    str r3, [sp, #0x84]\n\
    sub r4, #0x8\n\
    str r4, [sp, #0x7C]\n\
    cmp r8, r2\n\
    bcs _0800501C\n\
_08004FBA:\n\
    ldr r0, [sp, #0x2C]\n\
    ldm r0!, {r5}\n\
    str r0, [sp, #0x2C]\n\
    ldr r4, [sp, #0x34]\n\
    add r2, r1, #0x1\n\
    mov r10, r2\n\
    cmp r4, r12\n\
    bcs _08005014\n\
    lsr r0, r1, #3\n\
    ldr r2, [sp, #0x4]\n\
    add r3, r0, #0\n\
    mul r3, r2\n\
    add r7, r3, #0\n\
    mov r3, #0x7\n\
    and r1, r3\n\
    lsl r6, r1, #2\n\
_08004FDA:\n\
    add r3, r5, #0\n\
    mov r0, #0xF\n\
    and r3, r0\n\
    cmp r3, #0\n\
    beq _0800500C\n\
    lsr r2, r4, #3\n\
    lsl r2, #5\n\
    add r2, r9\n\
    add r0, r4, #0\n\
    mov r1, #0x7\n\
    and r0, r1\n\
    lsr r0, #1\n\
    add r2, r0\n\
    add r2, r7\n\
    add r2, r6\n\
    mov r1, #0x1\n\
    and r1, r4\n\
    lsl r1, #2\n\
    lsl r3, r1\n\
    mov r0, #0xF0\n\
    asr r0, r1\n\
    ldrb r1, [r2]\n\
    and r0, r1\n\
    orr r3, r0\n\
    strb r3, [r2]\n\
_0800500C:\n\
    lsr r5, #4\n\
    add r4, #0x1\n\
    cmp r4, r12\n\
    bcc _08004FDA\n\
_08005014:\n\
    mov r1, r10\n\
    ldr r2, [sp, #0x30]\n\
    cmp r1, r2\n\
    bcc _08004FBA\n\
_0800501C:\n\
    mov r1, r8\n\
    ldr r3, =gUnknown_03002FB0\n\
    str r3, [sp, #0x38]\n\
    ldr r0, [sp, #0x84]\n\
    ldr r2, [sp, #0x7C]\n\
    add r0, r2\n\
    mov r8, r0\n\
    ldr r3, [sp, #0x78]\n\
    str r3, [sp, #0x3C]\n\
    ldr r0, [sp, #0x84]\n\
    str r0, [sp, #0x40]\n\
    cmp r1, r3\n\
    bcc _08005038\n\
    b _080052AA\n\
_08005038:\n\
    ldr r2, [sp, #0x38]\n\
    ldm r2!, {r5}\n\
    str r2, [sp, #0x38]\n\
    ldr r4, [sp, #0x40]\n\
    add r3, r1, #0x1\n\
    mov r10, r3\n\
    cmp r4, r8\n\
    bcs _08005096\n\
    mov r0, #0x7\n\
    mov r12, r0\n\
    lsr r0, r1, #3\n\
    ldr r3, [sp, #0x4]\n\
    add r2, r0, #0\n\
    mul r2, r3\n\
    add r7, r2, #0\n\
    mov r0, r12\n\
    and r1, r0\n\
    lsl r6, r1, #2\n\
_0800505C:\n\
    add r3, r5, #0\n\
    mov r1, #0xF\n\
    and r3, r1\n\
    cmp r3, #0\n\
    beq _0800508E\n\
    lsr r2, r4, #3\n\
    lsl r2, #5\n\
    add r2, r9\n\
    add r0, r4, #0\n\
    mov r1, r12\n\
    and r0, r1\n\
    lsr r0, #1\n\
    add r2, r0\n\
    add r2, r7\n\
    add r2, r6\n\
    mov r1, #0x1\n\
    and r1, r4\n\
    lsl r1, #2\n\
    lsl r3, r1\n\
    mov r0, #0xF0\n\
    asr r0, r1\n\
    ldrb r1, [r2]\n\
    and r0, r1\n\
    orr r3, r0\n\
    strb r3, [r2]\n\
_0800508E:\n\
    lsr r5, #4\n\
    add r4, #0x1\n\
    cmp r4, r8\n\
    bcc _0800505C\n\
_08005096:\n\
    mov r1, r10\n\
    ldr r2, [sp, #0x3C]\n\
    cmp r1, r2\n\
    bcc _08005038\n\
    b _080052AA\n\
    .pool\n\
_080050A4:\n\
    mov r1, r8\n\
    str r5, [sp, #0x44]\n\
    ldr r3, [sp]\n\
    add r3, #0x8\n\
    mov r12, r3\n\
    mov r2, r8\n\
    add r2, #0x8\n\
    str r2, [sp, #0x48]\n\
    ldr r3, [sp]\n\
    str r3, [sp, #0x4C]\n\
    str r2, [sp, #0x88]\n\
    sub r0, #0x8\n\
    str r0, [sp, #0x80]\n\
    mov r0, r12\n\
    str r0, [sp, #0x84]\n\
    sub r4, #0x8\n\
    str r4, [sp, #0x7C]\n\
    cmp r8, r2\n\
    bcs _0800512C\n\
_080050CA:\n\
    ldr r2, [sp, #0x44]\n\
    ldm r2!, {r5}\n\
    str r2, [sp, #0x44]\n\
    ldr r4, [sp, #0x4C]\n\
    add r3, r1, #0x1\n\
    mov r10, r3\n\
    cmp r4, r12\n\
    bcs _08005124\n\
    lsr r0, r1, #3\n\
    ldr r3, [sp, #0x4]\n\
    add r2, r0, #0\n\
    mul r2, r3\n\
    add r7, r2, #0\n\
    mov r0, #0x7\n\
    and r1, r0\n\
    lsl r6, r1, #2\n\
_080050EA:\n\
    add r3, r5, #0\n\
    mov r1, #0xF\n\
    and r3, r1\n\
    cmp r3, #0\n\
    beq _0800511C\n\
    lsr r2, r4, #3\n\
    lsl r2, #5\n\
    add r2, r9\n\
    add r0, r4, #0\n\
    mov r1, #0x7\n\
    and r0, r1\n\
    lsr r0, #1\n\
    add r2, r0\n\
    add r2, r7\n\
    add r2, r6\n\
    mov r1, #0x1\n\
    and r1, r4\n\
    lsl r1, #2\n\
    lsl r3, r1\n\
    mov r0, #0xF0\n\
    asr r0, r1\n\
    ldrb r1, [r2]\n\
    and r0, r1\n\
    orr r3, r0\n\
    strb r3, [r2]\n\
_0800511C:\n\
    lsr r5, #4\n\
    add r4, #0x1\n\
    cmp r4, r12\n\
    bcc _080050EA\n\
_08005124:\n\
    mov r1, r10\n\
    ldr r2, [sp, #0x48]\n\
    cmp r1, r2\n\
    bcc _080050CA\n\
_0800512C:\n\
    mov r1, r8\n\
    ldr r3, =gUnknown_03002FB0\n\
    str r3, [sp, #0x50]\n\
    ldr r0, [sp, #0x84]\n\
    ldr r2, [sp, #0x7C]\n\
    add r0, r2\n\
    mov r8, r0\n\
    ldr r3, [sp, #0x88]\n\
    str r3, [sp, #0x54]\n\
    ldr r0, [sp, #0x84]\n\
    str r0, [sp, #0x58]\n\
    cmp r1, r3\n\
    bcs _080051AC\n\
_08005146:\n\
    ldr r2, [sp, #0x50]\n\
    ldm r2!, {r5}\n\
    str r2, [sp, #0x50]\n\
    ldr r4, [sp, #0x58]\n\
    add r3, r1, #0x1\n\
    mov r10, r3\n\
    cmp r4, r8\n\
    bcs _080051A4\n\
    mov r0, #0x7\n\
    mov r12, r0\n\
    lsr r0, r1, #3\n\
    ldr r3, [sp, #0x4]\n\
    add r2, r0, #0\n\
    mul r2, r3\n\
    add r7, r2, #0\n\
    mov r0, r12\n\
    and r1, r0\n\
    lsl r6, r1, #2\n\
_0800516A:\n\
    add r3, r5, #0\n\
    mov r1, #0xF\n\
    and r3, r1\n\
    cmp r3, #0\n\
    beq _0800519C\n\
    lsr r2, r4, #3\n\
    lsl r2, #5\n\
    add r2, r9\n\
    add r0, r4, #0\n\
    mov r1, r12\n\
    and r0, r1\n\
    lsr r0, #1\n\
    add r2, r0\n\
    add r2, r7\n\
    add r2, r6\n\
    mov r1, #0x1\n\
    and r1, r4\n\
    lsl r1, #2\n\
    lsl r3, r1\n\
    mov r0, #0xF0\n\
    asr r0, r1\n\
    ldrb r1, [r2]\n\
    and r0, r1\n\
    orr r3, r0\n\
    strb r3, [r2]\n\
_0800519C:\n\
    lsr r5, #4\n\
    add r4, #0x1\n\
    cmp r4, r8\n\
    bcc _0800516A\n\
_080051A4:\n\
    mov r1, r10\n\
    ldr r2, [sp, #0x54]\n\
    cmp r1, r2\n\
    bcc _08005146\n\
_080051AC:\n\
    ldr r1, [sp, #0x88]\n\
    ldr r3, =gUnknown_03002FD0\n\
    str r3, [sp, #0x5C]\n\
    ldr r0, [sp, #0x84]\n\
    mov r8, r0\n\
    ldr r2, [sp, #0x80]\n\
    add r2, r1, r2\n\
    str r2, [sp, #0x60]\n\
    ldr r3, [sp]\n\
    str r3, [sp, #0x64]\n\
    cmp r1, r2\n\
    bcs _0800522A\n\
_080051C4:\n\
    ldr r0, [sp, #0x5C]\n\
    ldm r0!, {r5}\n\
    str r0, [sp, #0x5C]\n\
    ldr r4, [sp, #0x64]\n\
    add r2, r1, #0x1\n\
    mov r10, r2\n\
    cmp r4, r8\n\
    bcs _08005222\n\
    mov r3, #0x7\n\
    mov r12, r3\n\
    lsr r0, r1, #3\n\
    ldr r3, [sp, #0x4]\n\
    add r2, r0, #0\n\
    mul r2, r3\n\
    add r7, r2, #0\n\
    mov r0, r12\n\
    and r1, r0\n\
    lsl r6, r1, #2\n\
_080051E8:\n\
    add r3, r5, #0\n\
    mov r1, #0xF\n\
    and r3, r1\n\
    cmp r3, #0\n\
    beq _0800521A\n\
    lsr r2, r4, #3\n\
    lsl r2, #5\n\
    add r2, r9\n\
    add r0, r4, #0\n\
    mov r1, r12\n\
    and r0, r1\n\
    lsr r0, #1\n\
    add r2, r0\n\
    add r2, r7\n\
    add r2, r6\n\
    mov r1, #0x1\n\
    and r1, r4\n\
    lsl r1, #2\n\
    lsl r3, r1\n\
    mov r0, #0xF0\n\
    asr r0, r1\n\
    ldrb r1, [r2]\n\
    and r0, r1\n\
    orr r3, r0\n\
    strb r3, [r2]\n\
_0800521A:\n\
    lsr r5, #4\n\
    add r4, #0x1\n\
    cmp r4, r8\n\
    bcc _080051E8\n\
_08005222:\n\
    mov r1, r10\n\
    ldr r2, [sp, #0x60]\n\
    cmp r1, r2\n\
    bcc _080051C4\n\
_0800522A:\n\
    ldr r4, [sp, #0x84]\n\
    ldr r1, [sp, #0x88]\n\
    ldr r3, =gUnknown_03002FF0\n\
    str r3, [sp, #0x68]\n\
    ldr r0, [sp, #0x7C]\n\
    add r0, r4\n\
    mov r8, r0\n\
    ldr r2, [sp, #0x80]\n\
    add r2, r1, r2\n\
    str r2, [sp, #0x6C]\n\
    str r4, [sp, #0x70]\n\
    cmp r1, r2\n\
    bcs _080052AA\n\
_08005244:\n\
    ldr r3, [sp, #0x68]\n\
    ldm r3!, {r5}\n\
    str r3, [sp, #0x68]\n\
    ldr r4, [sp, #0x70]\n\
    add r0, r1, #0x1\n\
    mov r10, r0\n\
    cmp r4, r8\n\
    bcs _080052A2\n\
    mov r2, #0x7\n\
    mov r12, r2\n\
    lsr r0, r1, #3\n\
    ldr r2, [sp, #0x4]\n\
    add r3, r0, #0\n\
    mul r3, r2\n\
    add r7, r3, #0\n\
    mov r3, r12\n\
    and r1, r3\n\
    lsl r6, r1, #2\n\
_08005268:\n\
    add r3, r5, #0\n\
    mov r0, #0xF\n\
    and r3, r0\n\
    cmp r3, #0\n\
    beq _0800529A\n\
    lsr r2, r4, #3\n\
    lsl r2, #5\n\
    add r2, r9\n\
    add r0, r4, #0\n\
    mov r1, r12\n\
    and r0, r1\n\
    lsr r0, #1\n\
    add r2, r0\n\
    add r2, r7\n\
    add r2, r6\n\
    mov r1, #0x1\n\
    and r1, r4\n\
    lsl r1, #2\n\
    lsl r3, r1\n\
    mov r0, #0xF0\n\
    asr r0, r1\n\
    ldrb r1, [r2]\n\
    and r0, r1\n\
    orr r3, r0\n\
    strb r3, [r2]\n\
_0800529A:\n\
    lsr r5, #4\n\
    add r4, #0x1\n\
    cmp r4, r8\n\
    bcc _08005268\n\
_080052A2:\n\
    mov r1, r10\n\
    ldr r2, [sp, #0x6C]\n\
    cmp r1, r2\n\
    bcc _08005244\n\
_080052AA:\n\
    add sp, #0x8C\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool");
}

void ClearTextSpan(struct TextPrinter *textPrinter, u32 width)
{
    struct Window *window;
    struct Bitmap pixels_data;
    u8* gUnk;
    u8* glyphHeight;

    if (gLastTextBgColor != 0)
    {
        window = &gWindows[textPrinter->subPrinter.windowId];
        pixels_data.pixels = window->tileData;
        pixels_data.width = window->window.width << 3;
        pixels_data.height = window->window.height << 3;

        gUnk = gUnknown_03002F90;
        glyphHeight = &gUnk[0x81];

        FillBitmapRect4Bit(
            &pixels_data,
            textPrinter->subPrinter.currentX,
            textPrinter->subPrinter.currentY,
            width,
            *glyphHeight,
            gLastTextBgColor);
    }
}

u16 Font0Func(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = &textPrinter->sub_union.sub;

    if (subStruct->field_1_top == 0)
    {
        textPrinter->sub_union.sub.font_type = 0;
        subStruct->field_1_top = 1;
    }
    return RenderText(textPrinter);
}

u16 Font1Func(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = &textPrinter->sub_union.sub;

    if (subStruct->field_1_top == 0)
    {
        textPrinter->sub_union.sub.font_type = 1;
        subStruct->field_1_top = 1;
    }
    return RenderText(textPrinter);
}

u16 Font2Func(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = &textPrinter->sub_union.sub;

    if (subStruct->field_1_top == 0)
    {
        textPrinter->sub_union.sub.font_type = 2;
        subStruct->field_1_top = 1;
    }
    return RenderText(textPrinter);
}

u16 Font3Func(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = &textPrinter->sub_union.sub;

    if (subStruct->field_1_top == 0)
    {
        textPrinter->sub_union.sub.font_type = 3;
        subStruct->field_1_top = 1;
    }
    return RenderText(textPrinter);
}

u16 Font4Func(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = &textPrinter->sub_union.sub;

    if (subStruct->field_1_top == 0)
    {
        textPrinter->sub_union.sub.font_type = 4;
        subStruct->field_1_top = 1;
    }
    return RenderText(textPrinter);
}

u16 Font5Func(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = &textPrinter->sub_union.sub;

    if (subStruct->field_1_top == 0)
    {
        textPrinter->sub_union.sub.font_type = 5;
        subStruct->field_1_top = 1;
    }
    return RenderText(textPrinter);
}

u16 Font7Func(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = &textPrinter->sub_union.sub;

    if (subStruct->field_1_top == 0)
    {
        textPrinter->sub_union.sub.font_type = 7;
        subStruct->field_1_top = 1;
    }
    return RenderText(textPrinter);
}

u16 Font8Func(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = &textPrinter->sub_union.sub;

    if (subStruct->field_1_top == 0)
    {
        textPrinter->sub_union.sub.font_type = 8;
        subStruct->field_1_top = 1;
    }
    return RenderText(textPrinter);
}

void TextPrinterInitDownArrowCounters(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = &textPrinter->sub_union.sub;

    if (gTextFlags.flag_2 == 1)
        subStruct->frames_visible_counter = 0;
    else
    {
        subStruct->field_1_upmid = 0;
        subStruct->field_1 = 0;
    }
}

void TextPrinterDrawDownArrow(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = &textPrinter->sub_union.sub;
    const u8 *arrowTiles;

    if (gTextFlags.flag_2 == 0)
    {
        if (subStruct->field_1 != 0)
        {
            subStruct->field_1 = ((*(u32*)&textPrinter->sub_union.sub) << 19 >> 27) - 1;    // convoluted way of getting field_1, necessary to match
        }
        else
        {
            FillWindowPixelRect(
                textPrinter->subPrinter.windowId,
                textPrinter->subPrinter.bgColor << 4 | textPrinter->subPrinter.bgColor,
                textPrinter->subPrinter.currentX,
                textPrinter->subPrinter.currentY,
                0x8,
                0x10);

            switch (gTextFlags.flag_1)
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
                textPrinter->subPrinter.windowId,
                arrowTiles,
                0,
                gDownArrowYCoords[*(u32*)subStruct << 17 >> 30], // subStruct->field_1_upmid but again, stupidly retrieved
                0x8,
                0x10,
                textPrinter->subPrinter.currentX,
                textPrinter->subPrinter.currentY,
                0x8,
                0x10);
            CopyWindowToVram(textPrinter->subPrinter.windowId, 0x2);

            subStruct->field_1 = 0x8;
            subStruct->field_1_upmid = (*(u32*)subStruct << 17 >> 30) + 1;
        }
    }
}

void TextPrinterClearDownArrow(struct TextPrinter *textPrinter)
{
    FillWindowPixelRect(
        textPrinter->subPrinter.windowId,
        textPrinter->subPrinter.bgColor << 4 | textPrinter->subPrinter.bgColor,
        textPrinter->subPrinter.currentX,
        textPrinter->subPrinter.currentY,
        0x8,
        0x10);
    CopyWindowToVram(textPrinter->subPrinter.windowId, 0x2);
}

bool8 TextPrinterWaitAutoMode(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = &textPrinter->sub_union.sub;

    if (subStruct->frames_visible_counter == 49)
    {
        return TRUE;
    }
    else
    {
        ++subStruct->frames_visible_counter;
        return FALSE;
    }
}

bool16 TextPrinterWaitWithDownArrow(struct TextPrinter *textPrinter)
{
    bool8 result = FALSE;
    if (gTextFlags.flag_2 != 0)
    {
        result = TextPrinterWaitAutoMode(textPrinter);
    }
    else
    {
        TextPrinterDrawDownArrow(textPrinter);
        if (gMain.newKeys & (A_BUTTON | B_BUTTON))
        {
            result = TRUE;
            PlaySE(5);
        }
    }
    return result;
}

bool16 TextPrinterWait(struct TextPrinter *textPrinter)
{
    bool16 result = FALSE;
    if (gTextFlags.flag_2 != 0)
    {
        result = TextPrinterWaitAutoMode(textPrinter);
    }
    else
    {
        if (gMain.newKeys & (A_BUTTON | B_BUTTON))
        {
            result = TRUE;
            PlaySE(5);
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
            switch (gTextFlags.flag_1)
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
#ifdef NONMATCHING
u16 RenderText(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *r4 = &textPrinter->sub_union.sub;
    u16 currChar;
    s32 width;

    switch (textPrinter->state) // _080057C4
    {
    case 0: // _080057F0
        if ((gMain.heldKeys & (A_BUTTON | B_BUTTON)) && r4->font_type_upper)
            textPrinter->delayCounter = 0;

        if (textPrinter->delayCounter && textPrinter->text_speed) //_0800580A
        {
            textPrinter->delayCounter--;
            if (gTextFlags.flag_0 && (gMain.newKeys & (A_BUTTON | B_BUTTON)))
            {
                r4->font_type_upper = 1;
                textPrinter->delayCounter = 0;
            }
            return 3;
        }

        if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED) && gTextFlags.flag_2)
            textPrinter->delayCounter = 3;
        else
            textPrinter->delayCounter = textPrinter->text_speed;

        currChar = *textPrinter->subPrinter.current_text_offset;
        textPrinter->subPrinter.current_text_offset++;

        switch (currChar) //_0800588A
        {
        case 0xF8+6: //_080058B8
            textPrinter->subPrinter.currentX = textPrinter->subPrinter.x;
            textPrinter->subPrinter.currentY += (gFonts[textPrinter->subPrinter.fontId].maxLetterHeight + textPrinter->subPrinter.lineSpacing);
            return 2;
        case 0xF8+5: //_080058DC
            textPrinter->subPrinter.current_text_offset++;
            return 2;
        case 0xF8+4: //_080058E0
            currChar = *textPrinter->subPrinter.current_text_offset;
            textPrinter->subPrinter.current_text_offset++;
            switch (currChar) // _080058F0
            {
            case 1: // _08005960
                textPrinter->subPrinter.fontColor_h = *textPrinter->subPrinter.current_text_offset;
                textPrinter->subPrinter.current_text_offset++;
                GenerateFontHalfRowLookupTable(textPrinter->subPrinter.fontColor_h, textPrinter->subPrinter.bgColor, textPrinter->subPrinter.shadowColor);
                return 2;
            case 2: // _08005982
                textPrinter->subPrinter.bgColor = *textPrinter->subPrinter.current_text_offset;
                textPrinter->subPrinter.current_text_offset++;
                GenerateFontHalfRowLookupTable(textPrinter->subPrinter.fontColor_h, textPrinter->subPrinter.bgColor, textPrinter->subPrinter.shadowColor);
                return 2;
            case 3: // _080059A6
                textPrinter->subPrinter.shadowColor = *textPrinter->subPrinter.current_text_offset;
                textPrinter->subPrinter.current_text_offset++;
                GenerateFontHalfRowLookupTable(textPrinter->subPrinter.fontColor_h, textPrinter->subPrinter.bgColor, textPrinter->subPrinter.shadowColor);
                return 2;
            case 4: // _080059C0
                textPrinter->subPrinter.fontColor_h = *textPrinter->subPrinter.current_text_offset;
                textPrinter->subPrinter.current_text_offset++;
                textPrinter->subPrinter.bgColor = *textPrinter->subPrinter.current_text_offset;
                textPrinter->subPrinter.current_text_offset++;
                textPrinter->subPrinter.shadowColor = *textPrinter->subPrinter.current_text_offset;
                textPrinter->subPrinter.current_text_offset++;
                GenerateFontHalfRowLookupTable(textPrinter->subPrinter.fontColor_h, textPrinter->subPrinter.bgColor, textPrinter->subPrinter.shadowColor);
                return 2;
            case 5: // _08005A0E
                textPrinter->subPrinter.current_text_offset++;
                return 2;
            case 6: //_08005A12
                r4->font_type = *textPrinter->subPrinter.current_text_offset;
                textPrinter->subPrinter.current_text_offset++;
                return 2;
            case 7: // _08005A0A
                return 2;
            case 8: // _08005A2A
                textPrinter->delayCounter = *textPrinter->subPrinter.current_text_offset;
                textPrinter->subPrinter.current_text_offset++;
                textPrinter->state = 6;
                return 2;
            case 9: // _08005A3A
                textPrinter->state = 1;
                if (gTextFlags.flag_2)
                    r4->frames_visible_counter = 0;
                return 3;
            case 10: // _08005A58
                textPrinter->state = 5;
                return 3;
            case 11: // _08005A5C
                currChar = *textPrinter->subPrinter.current_text_offset;
                textPrinter->subPrinter.current_text_offset++;
                currChar |= *textPrinter->subPrinter.current_text_offset << 8;
                textPrinter->subPrinter.current_text_offset++;
                PlayBGM(currChar);
                return 2;
            case 16: // _08005A76
                currChar = *textPrinter->subPrinter.current_text_offset;
                textPrinter->subPrinter.current_text_offset++;
                currChar |= (*textPrinter->subPrinter.current_text_offset << 8);
                textPrinter->subPrinter.current_text_offset++;
                PlaySE(currChar);
                return 2;
            case 13: // _08005A90
                textPrinter->subPrinter.currentX = textPrinter->subPrinter.x + *textPrinter->subPrinter.current_text_offset;
                textPrinter->subPrinter.current_text_offset++;
                return 2;
            case 14: // _08005A98
                textPrinter->subPrinter.currentY = textPrinter->subPrinter.y + *textPrinter->subPrinter.current_text_offset;
                textPrinter->subPrinter.current_text_offset++;
                return 2;
            case 15: // _08005AA4
                FillWindowPixelBuffer(textPrinter->subPrinter.windowId, textPrinter->subPrinter.bgColor | textPrinter->subPrinter.bgColor << 4);
                textPrinter->subPrinter.currentX = textPrinter->subPrinter.x;
                textPrinter->subPrinter.currentY = textPrinter->subPrinter.y;
                return 2;
            case 23: // _08005ABE
                m4aMPlayStop(&gMPlayInfo_BGM);
                return 2;
            case 24: // _08005ACC
                m4aMPlayContinue(&gMPlayInfo_BGM);
                return 2;
            case 17: // _08005AD8
                width = *textPrinter->subPrinter.current_text_offset;
                textPrinter->subPrinter.current_text_offset++;
                if (width > 0)
                {
                    ClearTextSpan(textPrinter, width);
                    textPrinter->subPrinter.currentX += width;
                    return 0;
                }
                return 2;
            case 18: // _08005AF2
                textPrinter->subPrinter.currentX = *textPrinter->subPrinter.current_text_offset + textPrinter->subPrinter.x;
                textPrinter->subPrinter.current_text_offset++;
                return 2;
            case 19: // _08005B02
                {
                    s32 widthHelper = *textPrinter->subPrinter.current_text_offset;
                    widthHelper += textPrinter->subPrinter.x;
                    textPrinter->subPrinter.current_text_offset++;
                    width = widthHelper - textPrinter->subPrinter.currentX;
                    if (width > 0)
                    {
                        ClearTextSpan(textPrinter, width);
                        textPrinter->subPrinter.currentX += width;
                        return 0;
                    }
                }
                return 2;
            case 20: // _08005B26
                textPrinter->minLetterSpacing = *textPrinter->subPrinter.current_text_offset++;
                return 2;
            case 21: // _08005B36
                textPrinter->japanese = 1;
                return 2;
            case 22: // _08005B3E
                textPrinter->japanese = 0;
                return 2;
            case 12: // _08005B5A
                currChar = *textPrinter->subPrinter.current_text_offset | 0x100;
                textPrinter->subPrinter.current_text_offset++;
                break;
            }
            break;

        case 0xF8+3: // _08005B48
            textPrinter->state = 2;
            TextPrinterInitDownArrowCounters(textPrinter);
            return 3;
        case 0xF8+2: // _08005B4C
            textPrinter->state = 3;
            TextPrinterInitDownArrowCounters(textPrinter);
            return 3;
        case 0xF8+1: // _08005B5A
            currChar = *textPrinter->subPrinter.current_text_offset | 0x100;
            textPrinter->subPrinter.current_text_offset++;
            break;
        case 0xF8+0: // _08005B6C
            currChar = *textPrinter->subPrinter.current_text_offset;
            textPrinter->subPrinter.current_text_offset++;
            gUnknown_03002F90[0x80] = DrawKeypadIcon(textPrinter->subPrinter.windowId, currChar, textPrinter->subPrinter.currentX, textPrinter->subPrinter.currentY);
            textPrinter->subPrinter.currentX += gUnknown_03002F90[0x80] + textPrinter->subPrinter.letterSpacing;
            return 0;
        case 0xF8+7: // _08005D6C
            return 1;
        }

        switch (r4->font_type) // _08005B90
        {
        case 0: // _08005BCC
            DecompressGlyphFont0(currChar, textPrinter->japanese);
            break;
        case 1: // _08005BDA
            DecompressGlyphFont1(currChar, textPrinter->japanese);
            break;
        case 2:
        case 3:
        case 4:
        case 5: // _08005BE8
            DecompressGlyphFont2(currChar, textPrinter->japanese);
            break;
        case 7: // _08005BF6
            DecompressGlyphFont7(currChar, textPrinter->japanese);
            break;
        case 8: // _08005C04
            DecompressGlyphFont8(currChar, textPrinter->japanese);
            break;
        case 6: // _08005C10
            break;
        }

        CopyGlyphToWindow(textPrinter); // _08005C10

        if (textPrinter->minLetterSpacing)
        {
            textPrinter->subPrinter.currentX += gUnknown_03002F90[0x80];
            width = textPrinter->minLetterSpacing - gUnknown_03002F90[0x80];
            if (width > 0)
            {
                ClearTextSpan(textPrinter, width);
                textPrinter->subPrinter.currentX += width;
            }
        }
        else // _08005C48
        {
            if (textPrinter->japanese)
                textPrinter->subPrinter.currentX += (gUnknown_03002F90[0x80] + textPrinter->subPrinter.letterSpacing);
            else
                textPrinter->subPrinter.currentX += gUnknown_03002F90[0x80];
        }
        return 0;
    case 1: // _08005C78
        if (TextPrinterWait(textPrinter))
            textPrinter->state = 0;
        return 3;
    case 2: // _08005C8C
        if (TextPrinterWaitWithDownArrow(textPrinter))
        {
            FillWindowPixelBuffer(textPrinter->subPrinter.windowId, (textPrinter->subPrinter.bgColor << 4) | textPrinter->subPrinter.bgColor);
            textPrinter->subPrinter.currentX = textPrinter->subPrinter.x;
            textPrinter->subPrinter.currentY = textPrinter->subPrinter.y;
            textPrinter->state = 0;
        }
        return 3;
    case 3: // _08005CB8
        if (TextPrinterWaitWithDownArrow(textPrinter))
        {
            TextPrinterClearDownArrow(textPrinter);
            textPrinter->scrollDistance = gFonts[textPrinter->subPrinter.fontId].maxLetterHeight + textPrinter->subPrinter.lineSpacing;
            textPrinter->subPrinter.currentX = textPrinter->subPrinter.x;
            textPrinter->state = 4;
        }
        return 3;
    case 4: // _08005CF0
        if (textPrinter->scrollDistance)
        {
            int scrollSpeed = sub_8197964();
            int speed = gWindowVerticalScrollSpeeds[scrollSpeed];
            if (textPrinter->scrollDistance < speed)
            {
                ScrollWindow(textPrinter->subPrinter.windowId, 0, textPrinter->scrollDistance, textPrinter->subPrinter.bgColor << 4 | textPrinter->subPrinter.bgColor);
                textPrinter->scrollDistance = 0;
            }
            else
            {
                ScrollWindow(textPrinter->subPrinter.windowId, 0, speed, textPrinter->subPrinter.bgColor << 4 | textPrinter->subPrinter.bgColor);
                textPrinter->scrollDistance -= speed;
            }
            CopyWindowToVram(textPrinter->subPrinter.windowId, 2);
        }
        else
        {
            textPrinter->state = 0;
        }
        return 3;
    case 5: // _08005D48
        if (!IsSEPlaying())
            textPrinter->state = 0;
        return 3;
    case 6: // _08005D5A
        if (textPrinter->delayCounter != 0)
            textPrinter->delayCounter--;
        else
            textPrinter->state = 0;
        return 3;
    }

    return 1;
}
#else
__attribute__((naked))
u16 RenderText(struct TextPrinter *textPrinter)
{
    asm("push {r4-r6,lr}\n\
    add r6, r0, #0\n\
    add r4, r6, #0\n\
    add r4, #0x14\n\
    ldrb r0, [r6, #0x1C]\n\
    cmp r0, #0x6\n\
    bls _080057C4\n\
    b _08005D6C\n\
_080057C4:\n\
    lsl r0, #2\n\
    ldr r1, =_080057D4\n\
    add r0, r1\n\
    ldr r0, [r0]\n\
    mov pc, r0\n\
    .pool\n\
    .align 2, 0\n\
_080057D4:\n\
    .4byte _080057F0\n\
    .4byte _08005C78\n\
    .4byte _08005C8C\n\
    .4byte _08005CB8\n\
    .4byte _08005CF0\n\
    .4byte _08005D48\n\
    .4byte _08005D5A\n\
_080057F0:\n\
    ldr r2, =gMain\n\
    ldrh r1, [r2, #0x2C]\n\
    mov r0, #0x3\n\
    and r0, r1\n\
    cmp r0, #0\n\
    beq _0800580A\n\
    ldrb r1, [r4]\n\
    mov r0, #0x10\n\
    and r0, r1\n\
    cmp r0, #0\n\
    beq _0800580A\n\
    mov r0, #0\n\
    strb r0, [r6, #0x1E]\n\
_0800580A:\n\
    ldrb r1, [r6, #0x1E]\n\
    cmp r1, #0\n\
    beq _0800584C\n\
    ldrb r0, [r6, #0x1D]\n\
    cmp r0, #0\n\
    beq _0800584C\n\
    sub r0, r1, #0x1\n\
    strb r0, [r6, #0x1E]\n\
    ldr r0, =gTextFlags\n\
    ldrb r1, [r0]\n\
    mov r0, #0x1\n\
    and r0, r1\n\
    cmp r0, #0\n\
    bne _08005828\n\
    b _08005B56\n\
_08005828:\n\
    ldrh r1, [r2, #0x2E]\n\
    mov r0, #0x3\n\
    and r0, r1\n\
    cmp r0, #0\n\
    bne _08005834\n\
    b _08005B56\n\
_08005834:\n\
    ldrb r0, [r4]\n\
    mov r1, #0x10\n\
    orr r0, r1\n\
    strb r0, [r4]\n\
    mov r0, #0\n\
    strb r0, [r6, #0x1E]\n\
    b _08005B56\n\
    .pool\n\
_0800584C:\n\
    ldr r0, =gBattleTypeFlags\n\
    ldr r0, [r0]\n\
    mov r1, #0x80\n\
    lsl r1, #17\n\
    and r0, r1\n\
    cmp r0, #0\n\
    bne _08005874\n\
    ldr r0, =gTextFlags\n\
    ldrb r1, [r0]\n\
    mov r0, #0x4\n\
    and r0, r1\n\
    cmp r0, #0\n\
    beq _08005874\n\
    mov r0, #0x3\n\
    b _08005876\n\
    .pool\n\
_08005874:\n\
    ldrb r0, [r6, #0x1D]\n\
_08005876:\n\
    strb r0, [r6, #0x1E]\n\
    ldr r0, [r6]\n\
    ldrb r3, [r0]\n\
    add r0, #0x1\n\
    str r0, [r6]\n\
    add r0, r3, #0\n\
    sub r0, #0xF8\n\
    cmp r0, #0x7\n\
    bls _0800588A\n\
    b _08005B90\n\
_0800588A:\n\
    lsl r0, #2\n\
    ldr r1, =_08005898\n\
    add r0, r1\n\
    ldr r0, [r0]\n\
    mov pc, r0\n\
    .pool\n\
    .align 2, 0\n\
_08005898:\n\
    .4byte _08005B6C\n\
    .4byte _08005B5A\n\
    .4byte _08005B4C\n\
    .4byte _08005B48\n\
    .4byte _080058E0\n\
    .4byte _080058DC\n\
    .4byte _080058B8\n\
    .4byte _08005D6C\n\
_080058B8:\n\
    ldrb r0, [r6, #0x6]\n\
    strb r0, [r6, #0x8]\n\
    ldrb r1, [r6, #0x5]\n\
    ldr r0, =gFonts\n\
    ldr r2, [r0]\n\
    lsl r0, r1, #1\n\
    add r0, r1\n\
    lsl r0, #2\n\
    add r0, r2\n\
    ldrb r1, [r6, #0xB]\n\
    ldrb r0, [r0, #0x5]\n\
    add r1, r0\n\
    ldrb r0, [r6, #0x9]\n\
    add r0, r1\n\
    b _08005ABA\n\
    .pool\n\
_080058DC:\n\
    ldr r0, [r6]\n\
    b _08005B30\n\
_080058E0:\n\
    ldr r0, [r6]\n\
    ldrb r3, [r0]\n\
    add r0, #0x1\n\
    str r0, [r6]\n\
    sub r0, r3, #0x1\n\
    cmp r0, #0x17\n\
    bls _080058F0\n\
    b _08005B90\n\
_080058F0:\n\
    lsl r0, #2\n\
    ldr r1, =_08005900\n\
    add r0, r1\n\
    ldr r0, [r0]\n\
    mov pc, r0\n\
    .pool\n\
    .align 2, 0\n\
_08005900:\n\
    .4byte _08005960 @0\n\
    .4byte _08005982 @1\n\
    .4byte _080059A6 @2\n\
    .4byte _080059C0 @3\n\
    .4byte _08005A0E @4\n\
    .4byte _08005A12 @5\n\
    .4byte _08005A0A @6\n\
    .4byte _08005A2A @7\n\
    .4byte _08005A3A @8\n\
    .4byte _08005A58 @9\n\
    .4byte _08005A5C @10\n\
    .4byte _08005B5A @11\n\
    .4byte _08005A90 @12\n\
    .4byte _08005A98 @13\n\
    .4byte _08005AA4 @14\n\
    .4byte _08005A76 @15\n\
    .4byte _08005AD8 @16\n\
    .4byte _08005AF2 @17\n\
    .4byte _08005B02 @18\n\
    .4byte _08005B26 @19\n\
    .4byte _08005B36 @20\n\
    .4byte _08005B3E @21\n\
    .4byte _08005ABE @22\n\
    .4byte _08005ACC @23\n\
_08005960:\n\
    ldr r2, [r6]\n\
    ldrb r1, [r2]\n\
    lsl r1, #4\n\
    ldrb r3, [r6, #0xC]\n\
    mov r0, #0xF\n\
    and r0, r3\n\
    orr r0, r1\n\
    strb r0, [r6, #0xC]\n\
    add r2, #0x1\n\
    str r2, [r6]\n\
    lsl r0, #24\n\
    lsr r0, #28\n\
    ldrb r2, [r6, #0xD]\n\
    lsl r1, r2, #28\n\
    lsr r1, #28\n\
    lsr r2, #4\n\
    b _08005A06\n\
_08005982:\n\
    ldr r1, [r6]\n\
    ldrb r2, [r1]\n\
    mov r0, #0xF\n\
    and r0, r2\n\
    ldrb r3, [r6, #0xD]\n\
    mov r2, #0x10\n\
    neg r2, r2\n\
    and r2, r3\n\
    orr r2, r0\n\
    strb r2, [r6, #0xD]\n\
    add r1, #0x1\n\
    str r1, [r6]\n\
    ldrb r0, [r6, #0xC]\n\
    lsr r0, #4\n\
    lsl r1, r2, #28\n\
    lsr r1, #28\n\
    lsr r2, #4\n\
    b _08005A06\n\
_080059A6:\n\
    ldr r1, [r6]\n\
    ldrb r0, [r1]\n\
    lsl r0, #4\n\
    ldrb r3, [r6, #0xD]\n\
    mov r2, #0xF\n\
    and r2, r3\n\
    orr r2, r0\n\
    strb r2, [r6, #0xD]\n\
    add r1, #0x1\n\
    str r1, [r6]\n\
    ldrb r0, [r6, #0xC]\n\
    lsr r0, #4\n\
    b _080059FE\n\
_080059C0:\n\
    ldr r3, [r6]\n\
    ldrb r1, [r3]\n\
    lsl r1, #4\n\
    ldrb r4, [r6, #0xC]\n\
    mov r2, #0xF\n\
    add r0, r2, #0\n\
    and r0, r4\n\
    orr r0, r1\n\
    strb r0, [r6, #0xC]\n\
    add r5, r3, #0x1\n\
    str r5, [r6]\n\
    ldrb r3, [r3, #0x1]\n\
    add r1, r2, #0\n\
    and r1, r3\n\
    ldrb r4, [r6, #0xD]\n\
    mov r3, #0x10\n\
    neg r3, r3\n\
    and r3, r4\n\
    orr r3, r1\n\
    strb r3, [r6, #0xD]\n\
    add r4, r5, #0x1\n\
    str r4, [r6]\n\
    ldrb r1, [r5, #0x1]\n\
    lsl r1, #4\n\
    and r2, r3\n\
    orr r2, r1\n\
    strb r2, [r6, #0xD]\n\
    add r4, #0x1\n\
    str r4, [r6]\n\
    lsl r0, #24\n\
    lsr r0, #28\n\
_080059FE:\n\
    lsl r1, r2, #28\n\
    lsr r1, #28\n\
    lsl r2, #24\n\
    lsr r2, #28\n\
_08005A06:\n\
    bl GenerateFontHalfRowLookupTable\n\
_08005A0A:\n\
    mov r0, #0x2\n\
    b _08005D6E\n\
_08005A0E:\n\
    ldr r0, [r6]\n\
    b _08005B30\n\
_08005A12:\n\
    ldr r0, [r6]\n\
    ldrb r0, [r0]\n\
    mov r1, #0xF\n\
    and r1, r0\n\
    ldrb r2, [r4]\n\
    mov r0, #0x10\n\
    neg r0, r0\n\
    and r0, r2\n\
    orr r0, r1\n\
    strb r0, [r4]\n\
    ldr r0, [r6]\n\
    b _08005B30\n\
_08005A2A:\n\
    ldr r0, [r6]\n\
    ldrb r1, [r0]\n\
    strb r1, [r6, #0x1E]\n\
    add r0, #0x1\n\
    str r0, [r6]\n\
    mov r0, #0x6\n\
    strb r0, [r6, #0x1C]\n\
    b _08005A0A\n\
_08005A3A:\n\
    mov r0, #0x1\n\
    strb r0, [r6, #0x1C]\n\
    ldr r0, =gTextFlags\n\
    ldrb r1, [r0]\n\
    mov r0, #0x4\n\
    and r0, r1\n\
    cmp r0, #0\n\
    bne _08005A4C\n\
    b _08005B56\n\
_08005A4C:\n\
    mov r0, #0\n\
    strb r0, [r4, #0x2]\n\
    b _08005B56\n\
    .pool\n\
_08005A58:\n\
    mov r0, #0x5\n\
    b _08005D56\n\
_08005A5C:\n\
    ldr r0, [r6]\n\
    ldrb r3, [r0]\n\
    add r1, r0, #0x1\n\
    str r1, [r6]\n\
    ldrb r0, [r0, #0x1]\n\
    lsl r0, #8\n\
    orr r3, r0\n\
    add r1, #0x1\n\
    str r1, [r6]\n\
    add r0, r3, #0\n\
    bl PlayBGM\n\
    b _08005A0A\n\
_08005A76:\n\
    ldr r0, [r6]\n\
    ldrb r3, [r0]\n\
    add r1, r0, #0x1\n\
    str r1, [r6]\n\
    ldrb r0, [r0, #0x1]\n\
    lsl r0, #8\n\
    orr r3, r0\n\
    add r1, #0x1\n\
    str r1, [r6]\n\
    add r0, r3, #0\n\
    bl PlaySE\n\
    b _08005A0A\n\
_08005A90:\n\
    ldr r1, [r6]\n\
    ldrb r0, [r1]\n\
    ldrb r3, [r6, #0x6]\n\
    b _08005AF8\n\
_08005A98:\n\
    ldr r1, [r6]\n\
    ldrb r0, [r1]\n\
    ldrb r2, [r6, #0x7]\n\
    add r0, r2\n\
    strb r0, [r6, #0x9]\n\
    b _08005AFC\n\
_08005AA4:\n\
    ldrb r0, [r6, #0x4]\n\
    ldrb r2, [r6, #0xD]\n\
    lsl r2, #28\n\
    lsr r1, r2, #4\n\
    orr r1, r2\n\
    lsr r1, #24\n\
    bl FillWindowPixelBuffer\n\
    ldrb r0, [r6, #0x6]\n\
    strb r0, [r6, #0x8]\n\
    ldrb r0, [r6, #0x7]\n\
_08005ABA:\n\
    strb r0, [r6, #0x9]\n\
    b _08005A0A\n\
_08005ABE:\n\
    ldr r0, =gMPlayInfo_BGM\n\
    bl m4aMPlayStop\n\
    b _08005A0A\n\
    .pool\n\
_08005ACC:\n\
    ldr r0, =gMPlayInfo_BGM\n\
    bl m4aMPlayContinue\n\
    b _08005A0A\n\
    .pool\n\
_08005AD8:\n\
    ldr r0, [r6]\n\
    ldrb r4, [r0]\n\
    add r0, #0x1\n\
    str r0, [r6]\n\
    cmp r4, #0\n\
    ble _08005A0A\n\
    add r0, r6, #0\n\
    add r1, r4, #0\n\
    bl ClearTextSpan\n\
    ldrb r0, [r6, #0x8]\n\
    add r0, r4\n\
    b _08005C6E\n\
_08005AF2:\n\
    ldr r1, [r6]\n\
    ldrb r0, [r6, #0x6]\n\
    ldrb r3, [r1]\n\
_08005AF8:\n\
    add r0, r3\n\
    strb r0, [r6, #0x8]\n\
_08005AFC:\n\
    add r1, #0x1\n\
    str r1, [r6]\n\
    b _08005A0A\n\
_08005B02:\n\
    ldr r0, [r6]\n\
    ldrb r2, [r0]\n\
    ldrb r1, [r6, #0x6]\n\
    add r2, r1\n\
    add r0, #0x1\n\
    str r0, [r6]\n\
    ldrb r0, [r6, #0x8]\n\
    sub r4, r2, r0\n\
    cmp r4, #0\n\
    bgt _08005B18\n\
    b _08005A0A\n\
_08005B18:\n\
    add r0, r6, #0\n\
    add r1, r4, #0\n\
    bl ClearTextSpan\n\
    ldrb r0, [r6, #0x8]\n\
    add r0, r4\n\
    b _08005C6E\n\
_08005B26:\n\
    ldr r0, [r6]\n\
    ldrb r2, [r0]\n\
    add r1, r6, #0\n\
    add r1, #0x20\n\
    strb r2, [r1]\n\
_08005B30:\n\
    add r0, #0x1\n\
    str r0, [r6]\n\
    b _08005A0A\n\
_08005B36:\n\
    add r1, r6, #0\n\
    add r1, #0x21\n\
    mov r0, #0x1\n\
    b _08005B44\n\
_08005B3E:\n\
    add r1, r6, #0\n\
    add r1, #0x21\n\
    mov r0, #0\n\
_08005B44:\n\
    strb r0, [r1]\n\
    b _08005A0A\n\
_08005B48:\n\
    mov r0, #0x2\n\
    b _08005B4E\n\
_08005B4C:\n\
    mov r0, #0x3\n\
_08005B4E:\n\
    strb r0, [r6, #0x1C]\n\
    add r0, r6, #0\n\
    bl TextPrinterInitDownArrowCounters\n\
_08005B56:\n\
    mov r0, #0x3\n\
    b _08005D6E\n\
_08005B5A:\n\
    ldr r0, [r6]\n\
    ldrb r3, [r0]\n\
    mov r2, #0x80\n\
    lsl r2, #1\n\
    add r1, r2, #0\n\
    orr r3, r1\n\
    add r0, #0x1\n\
    str r0, [r6]\n\
    b _08005B90\n\
_08005B6C:\n\
    ldr r0, [r6]\n\
    ldrb r3, [r0]\n\
    add r0, #0x1\n\
    str r0, [r6]\n\
    ldrb r0, [r6, #0x4]\n\
    add r1, r3, #0\n\
    ldrb r2, [r6, #0x8]\n\
    ldrb r3, [r6, #0x9]\n\
    bl DrawKeypadIcon\n\
    ldr r1, =gUnknown_03002F90\n\
    add r1, #0x80\n\
    strb r0, [r1]\n\
    ldrb r3, [r6, #0xA]\n\
    add r0, r3\n\
    b _08005C6A\n\
    .pool\n\
_08005B90:\n\
    ldr r0, [r4]\n\
    lsl r0, #28\n\
    lsr r0, #28\n\
    cmp r0, #0x8\n\
    bhi _08005C10\n\
    lsl r0, #2\n\
    ldr r1, =_08005BA8\n\
    add r0, r1\n\
    ldr r0, [r0]\n\
    mov pc, r0\n\
    .pool\n\
    .align 2, 0\n\
_08005BA8:\n\
    .4byte _08005BCC\n\
    .4byte _08005BDA\n\
    .4byte _08005BE8\n\
    .4byte _08005BE8\n\
    .4byte _08005BE8\n\
    .4byte _08005BE8\n\
    .4byte _08005C10\n\
    .4byte _08005BF6\n\
    .4byte _08005C04\n\
_08005BCC:\n\
    add r0, r6, #0\n\
    add r0, #0x21\n\
    ldrb r1, [r0]\n\
    add r0, r3, #0\n\
    bl DecompressGlyphFont0\n\
    b _08005C10\n\
_08005BDA:\n\
    add r0, r6, #0\n\
    add r0, #0x21\n\
    ldrb r1, [r0]\n\
    add r0, r3, #0\n\
    bl DecompressGlyphFont1\n\
    b _08005C10\n\
_08005BE8:\n\
    add r0, r6, #0\n\
    add r0, #0x21\n\
    ldrb r1, [r0]\n\
    add r0, r3, #0\n\
    bl DecompressGlyphFont2\n\
    b _08005C10\n\
_08005BF6:\n\
    add r0, r6, #0\n\
    add r0, #0x21\n\
    ldrb r1, [r0]\n\
    add r0, r3, #0\n\
    bl DecompressGlyphFont7\n\
    b _08005C10\n\
_08005C04:\n\
    add r0, r6, #0\n\
    add r0, #0x21\n\
    ldrb r1, [r0]\n\
    add r0, r3, #0\n\
    bl DecompressGlyphFont8\n\
_08005C10:\n\
    add r0, r6, #0\n\
    bl CopyGlyphToWindow\n\
    add r2, r6, #0\n\
    add r2, #0x20\n\
    ldrb r0, [r2]\n\
    cmp r0, #0\n\
    beq _08005C48\n\
    ldr r1, =gUnknown_03002F90\n\
    add r1, #0x80\n\
    ldrb r0, [r1]\n\
    ldrb r3, [r6, #0x8]\n\
    add r0, r3\n\
    strb r0, [r6, #0x8]\n\
    ldrb r2, [r2]\n\
    ldrb r0, [r1]\n\
    sub r4, r2, r0\n\
    cmp r4, #0\n\
    ble _08005C70\n\
    add r0, r6, #0\n\
    add r1, r4, #0\n\
    bl ClearTextSpan\n\
    ldrb r0, [r6, #0x8]\n\
    add r0, r4\n\
    b _08005C6E\n\
    .pool\n\
_08005C48:\n\
    add r0, r6, #0\n\
    add r0, #0x21\n\
    ldrb r0, [r0]\n\
    cmp r0, #0\n\
    beq _08005C64\n\
    ldr r0, =gUnknown_03002F90\n\
    add r0, #0x80\n\
    ldrb r1, [r6, #0xA]\n\
    ldrb r0, [r0]\n\
    add r1, r0\n\
    ldrb r0, [r6, #0x8]\n\
    b _08005C6C\n\
    .pool\n\
_08005C64:\n\
    ldr r0, =gUnknown_03002F90\n\
    add r0, #0x80\n\
    ldrb r0, [r0]\n\
_08005C6A:\n\
    ldrb r1, [r6, #0x8]\n\
_08005C6C:\n\
    add r0, r1\n\
_08005C6E:\n\
    strb r0, [r6, #0x8]\n\
_08005C70:\n\
    mov r0, #0\n\
    b _08005D6E\n\
    .pool\n\
_08005C78:\n\
    add r0, r6, #0\n\
    bl TextPrinterWait\n\
    lsl r0, #16\n\
    cmp r0, #0\n\
    bne _08005C86\n\
    b _08005B56\n\
_08005C86:\n\
    mov r0, #0\n\
    strb r0, [r6, #0x1C]\n\
    b _08005B56\n\
_08005C8C:\n\
    add r0, r6, #0\n\
    bl TextPrinterWaitWithDownArrow\n\
    lsl r0, #16\n\
    cmp r0, #0\n\
    bne _08005C9A\n\
    b _08005B56\n\
_08005C9A:\n\
    ldrb r0, [r6, #0x4]\n\
    ldrb r2, [r6, #0xD]\n\
    lsl r2, #28\n\
    lsr r1, r2, #4\n\
    orr r1, r2\n\
    lsr r1, #24\n\
    bl FillWindowPixelBuffer\n\
    ldrb r0, [r6, #0x6]\n\
    mov r1, #0\n\
    strb r0, [r6, #0x8]\n\
    ldrb r0, [r6, #0x7]\n\
    strb r0, [r6, #0x9]\n\
    strb r1, [r6, #0x1C]\n\
    b _08005B56\n\
_08005CB8:\n\
    add r0, r6, #0\n\
    bl TextPrinterWaitWithDownArrow\n\
    lsl r0, #16\n\
    cmp r0, #0\n\
    bne _08005CC6\n\
    b _08005B56\n\
_08005CC6:\n\
    add r0, r6, #0\n\
    bl TextPrinterClearDownArrow\n\
    ldrb r1, [r6, #0x5]\n\
    ldr r0, =gFonts\n\
    ldr r2, [r0]\n\
    lsl r0, r1, #1\n\
    add r0, r1\n\
    lsl r0, #2\n\
    add r0, r2\n\
    ldrb r1, [r6, #0xB]\n\
    ldrb r0, [r0, #0x5]\n\
    add r1, r0\n\
    strb r1, [r6, #0x1F]\n\
    ldrb r0, [r6, #0x6]\n\
    strb r0, [r6, #0x8]\n\
    mov r0, #0x4\n\
    strb r0, [r6, #0x1C]\n\
    b _08005B56\n\
    .pool\n\
_08005CF0:\n\
    ldrb r0, [r6, #0x1F]\n\
    cmp r0, #0\n\
    beq _08005D44\n\
    bl sub_8197964\n\
    ldr r1, =gWindowVerticalScrollSpeeds\n\
    add r0, r1\n\
    ldrb r4, [r0]\n\
    ldrb r2, [r6, #0x1F]\n\
    cmp r2, r4\n\
    bge _08005D20\n\
    ldrb r0, [r6, #0x4]\n\
    ldrb r1, [r6, #0xD]\n\
    lsl r1, #28\n\
    lsr r3, r1, #4\n\
    orr r3, r1\n\
    lsr r3, #24\n\
    mov r1, #0\n\
    bl ScrollWindow\n\
    mov r0, #0\n\
    b _08005D38\n\
    .pool\n\
_08005D20:\n\
    ldrb r0, [r6, #0x4]\n\
    ldrb r1, [r6, #0xD]\n\
    lsl r1, #28\n\
    lsr r3, r1, #4\n\
    orr r3, r1\n\
    lsr r3, #24\n\
    mov r1, #0\n\
    add r2, r4, #0\n\
    bl ScrollWindow\n\
    ldrb r0, [r6, #0x1F]\n\
    sub r0, r4\n\
_08005D38:\n\
    strb r0, [r6, #0x1F]\n\
    ldrb r0, [r6, #0x4]\n\
    mov r1, #0x2\n\
    bl CopyWindowToVram\n\
    b _08005B56\n\
_08005D44:\n\
    strb r0, [r6, #0x1C]\n\
    b _08005B56\n\
_08005D48:\n\
    bl IsSEPlaying\n\
    lsl r0, #24\n\
    lsr r0, #24\n\
    cmp r0, #0\n\
    beq _08005D56\n\
    b _08005B56\n\
_08005D56:\n\
    strb r0, [r6, #0x1C]\n\
    b _08005B56\n\
_08005D5A:\n\
    ldrb r0, [r6, #0x1E]\n\
    add r1, r0, #0\n\
    cmp r1, #0\n\
    beq _08005D68\n\
    sub r0, #0x1\n\
    strb r0, [r6, #0x1E]\n\
    b _08005B56\n\
_08005D68:\n\
    strb r1, [r6, #0x1C]\n\
    b _08005B56\n\
_08005D6C:\n\
    mov r0, #0x1\n\
_08005D6E:\n\
    pop {r4-r6}\n\
    pop {r1}\n\
    bx r1\n");
}
#endif

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
            case 0xFE:
            case 0xFF:
                lineWidths[line] = width;
                width = 0;
                line++;
                break;
            case 0xFC:
                temp2 = strLocal[strPos++];
                switch (temp2)
                {
                    case 0x4:
                        ++strPos;
                    case 0xB:
                    case 0x10:
                        ++strPos;
                    case 0x1:
                    case 0x2:
                    case 0x3:
                    case 0x5:
                    case 0x6:
                    case 0x8:
                    case 0xC:
                    case 0xD:
                    case 0xE:
                    case 0x11:
                    case 0x12:
                    case 0x13:
                    case 0x14:
                        ++strPos;
                        break;
                    case 0x7:
                    case 0x9:
                    case 0xA:
                    case 0xF:
                    case 0x15:
                    case 0x16:
                    default:
                        break;
                }
                break;
            case 0xF7:
            case 0xFD:
                ++strPos;
                break;
            case 0xFA:
            case 0xFB:
                break;
            case 0xF8:
            case 0xF9:
                ++strPos;
            default:
                ++width;
                break;
        }
    } while (temp != 0xFF);

    for (width = 0, strPos = 0; strPos < 8; ++strPos)
    {
        if (width < lineWidths[strPos])
            width = lineWidths[strPos];
    }

    return (u8)(GetFontAttribute(fontId, 0) + letterSpacing) * width;
}

u32 (*GetFontWidthFunc(u8 glyphId))(u16, bool32)
{
    u32 i;

    for (i = 0; i < 9; ++i)
    {
        if (glyphId == gGlyphWidthFuncs[i].font_id)
            return gGlyphWidthFuncs[i].func;
    }

    return 0;
}

u32 GetStringWidth(u8 fontId, const u8 *str, s16 letterSpacing)
{
    bool8 isJapanese;
    int minGlyphWidth;
    u32 (*func)(u16 glyphId, bool32 isJapanese);
    s32 result;
    int localLetterSpacing;
    u32 lineWidth;
    u8 *bufferPointer;
    int glyphWidth;
    u32 width;

    isJapanese = 0;
    minGlyphWidth = 0;

    func = GetFontWidthFunc(fontId);
    if (func == NULL)
        return 0;

    if (letterSpacing == -1)
        localLetterSpacing = GetFontAttribute(fontId, 2);
    else
        localLetterSpacing = letterSpacing;

    width = 0;
    lineWidth = 0;
    bufferPointer = 0;

    while (*str != 0xFF)
    {
        switch (*str)
        {
            case 0xFE:
                if (lineWidth > width)
                    width = lineWidth;
                lineWidth = 0;
                break;
            case 0xFD:
                switch (*++str)
                {
                    case 0x2:
                        bufferPointer = gStringVar1;
                        break;
                    case 0x3:
                        bufferPointer = gStringVar2;
                        break;
                    case 0x4:
                        bufferPointer = gStringVar3;
                        break;
                    default:
                        return 0;
                }
            case 0xF7:
                if (bufferPointer == NULL)
                    bufferPointer = UnkTextUtil_GetPtrI(*++str);
                while (*bufferPointer != 0xFF)
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
                        if (isJapanese && str[1] != 0xFF)
                            lineWidth += localLetterSpacing;
                    }
                }
                bufferPointer = 0;
                break;
            case 0xFC:
                switch (*++str)
                {
                    case 0x4:
                        ++str;
                    case 0xB:
                    case 0x10:
                        ++str;
                    case 0x1:
                    case 0x2:
                    case 0x3:
                    case 0x5:
                    case 0x8:
                    case 0xC:
                    case 0xD:
                    case 0xE:
                        ++str;
                        break;
                    case 0x6:
                        func = GetFontWidthFunc(*++str);
                        if (func == NULL)
                            return 0;
                        if (letterSpacing == -1)
                            localLetterSpacing = GetFontAttribute(*str, 2);
                        break;
                    case 0x11:
                        glyphWidth = *++str;
                        lineWidth += glyphWidth;
                        break;
                    case 0x12:
                        lineWidth = *++str;
                        break;
                    case 0x13:
                        if (*++str > lineWidth)
                            lineWidth = *str;
                        break;
                    case 0x14:
                        minGlyphWidth = *++str;
                        break;
                    case 0x15:
                        isJapanese = 1;
                        break;
                    case 0x16:
                        isJapanese = 0;
                        break;
                    case 0x7:
                    case 0x9:
                    case 0xA:
                    case 0xF:
                    default:
                        break;
                }
                break;
            case 0xF8:
            case 0xF9:
                if (*str == 0xF9)
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
                    if (isJapanese && str[1] != 0xFF)
                        lineWidth += localLetterSpacing;
                }
                break;
            case 0xFA:
            case 0xFB:
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
                    if (isJapanese && str[1] != 0xFF)
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

    fgColor = 1;
    bgColor = 0;
    shadowColor = 3;

    GenerateFontHalfRowLookupTable(1, 0, 3);
    strLocal = str;
    strPos = 0;

    do
    {
        temp = strLocal[strPos++];
        switch (temp)
        {
            case 0xFC:
                temp2 = strLocal[strPos++];
                switch (temp2)
                {
                    case 0x4:
                        fgColor = strLocal[strPos++];
                        bgColor = strLocal[strPos++];
                        shadowColor = strLocal[strPos++];
                        GenerateFontHalfRowLookupTable(fgColor, bgColor, shadowColor);
                        continue;
                    case 0x1:
                        fgColor = strLocal[strPos++];
                        GenerateFontHalfRowLookupTable(fgColor, bgColor, shadowColor);
                        continue;
                    case 0x2:
                        bgColor = strLocal[strPos++];
                        GenerateFontHalfRowLookupTable(fgColor, bgColor, shadowColor);
                        continue;
                    case 0x3:
                        shadowColor = strLocal[strPos++];
                        GenerateFontHalfRowLookupTable(fgColor, bgColor, shadowColor);
                        continue;
                    case 0x6:
                        fontId = strLocal[strPos++];
                        break;
                    case 0xB:
                    case 0x10:
                        ++strPos;
                    case 0x5:
                    case 0x8:
                    case 0xC:
                    case 0xD:
                    case 0xE:
                    case 0x11:
                    case 0x12:
                    case 0x13:
                    case 0x14:
                        ++strPos;
                        break;
                    case 0x7:
                    case 0x9:
                    case 0xA:
                    case 0xF:
                    case 0x15:
                    case 0x16:
                    default:
                        continue;
                }
                break;
            case 0xF7:
            case 0xF8:
            case 0xF9:
            case 0xFD:
                ++strPos;
                break;
            case 0xFA:
            case 0xFB:
            case 0xFE:
            case 0xFF:
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

                CpuCopy32(gUnknown_03002F90, pixels, 0x20);
                CpuCopy32(gUnknown_03002F90 + 0x40, pixels + 0x20, 0x20);
                pixels += 0x40;
                break;
        }
    }
    while (temp != 0xFF);

    RestoreTextColors(&colorBackup[0], &colorBackup[1], &colorBackup[2]);
    return 1;
}

u8 DrawKeypadIcon(u8 windowId, u8 keypadIconId, u16 x, u16 y)
{
    BlitBitmapRectToWindow(
        windowId,
        gKeypadIconTiles + (gKeypadIcons[keypadIconId].tile_offset * 0x20),
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
    return gKeypadIcons[keypadIconId].tile_offset;
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
        case 0:
            result = gFontInfos[fontId].maxLetterWidth;
            break;
        case 1:
            result = gFontInfos[fontId].maxLetterHeight;
            break;
        case 2:
            result = gFontInfos[fontId].letterSpacing;
            break;
        case 3:
            result = gFontInfos[fontId].lineSpacing;
            break;
        case 4:
            result = gFontInfos[fontId].fontColor_l;
            break;
        case 5:
            result = gFontInfos[fontId].fontColor_h;
            break;
        case 6:
            result = gFontInfos[fontId].bgColor;
            break;
        case 7:
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
        DecompressGlyphTile(glyphs, (u16 *)gUnknown_03002F90);
        DecompressGlyphTile(glyphs + 0x80, (u16 *)(gUnknown_03002F90 + 0x40));    // gUnknown_03002FD0
        gUnknown_03002F90[0x80] = 8;     // gGlyphWidth
        gUnknown_03002F90[0x81] = 12;    // gGlyphHeight
    }
    else
    {
        glyphs = gFont0LatinGlyphs + (0x20 * glyphId);
        gUnknown_03002F90[0x80] = gFont0LatinGlyphWidths[glyphId];

        if (gUnknown_03002F90[0x80] <= 8)
        {
            DecompressGlyphTile(glyphs, (u16 *)gUnknown_03002F90);
            DecompressGlyphTile(glyphs + 0x10, (u16 *)(gUnknown_03002F90 + 0x40));
        }
        else
        {
            DecompressGlyphTile(glyphs, (u16 *)gUnknown_03002F90);
            DecompressGlyphTile(glyphs + 0x8, (u16 *)(gUnknown_03002F90 + 0x20));
            DecompressGlyphTile(glyphs + 0x10, (u16 *)(gUnknown_03002F90 + 0x40));
            DecompressGlyphTile(glyphs + 0x18, (u16 *)(gUnknown_03002F90 + 0x60));
        }

        gUnknown_03002F90[0x81] = 13;
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
        DecompressGlyphTile(glyphs, (u16 *)gUnknown_03002F90);
        DecompressGlyphTile(glyphs + 0x80, (u16 *)(gUnknown_03002F90 + 0x40));    // gUnknown_03002FD0
        gUnknown_03002F90[0x80] = 8;     // gGlyphWidth
        gUnknown_03002F90[0x81] = 15;    // gGlyphHeight
    }
    else
    {
        glyphs = gFont7LatinGlyphs + (0x20 * glyphId);
        gUnknown_03002F90[0x80] = gFont7LatinGlyphWidths[glyphId];

        if (gUnknown_03002F90[0x80] <= 8)
        {
            DecompressGlyphTile(glyphs, (u16 *)gUnknown_03002F90);
            DecompressGlyphTile(glyphs + 0x10, (u16 *)(gUnknown_03002F90 + 0x40));
        }
        else
        {
            DecompressGlyphTile(glyphs, (u16 *)gUnknown_03002F90);
            DecompressGlyphTile(glyphs + 0x8, (u16 *)(gUnknown_03002F90 + 0x20));
            DecompressGlyphTile(glyphs + 0x10, (u16 *)(gUnknown_03002F90 + 0x40));
            DecompressGlyphTile(glyphs + 0x18, (u16 *)(gUnknown_03002F90 + 0x60));
        }

        gUnknown_03002F90[0x81] = 15;
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
        DecompressGlyphTile(glyphs, (u16 *)gUnknown_03002F90);
        DecompressGlyphTile(glyphs + 0x80, (u16 *)(gUnknown_03002F90 + 0x40));    // gUnknown_03002FD0
        gUnknown_03002F90[0x80] = 8;     // gGlyphWidth
        gUnknown_03002F90[0x81] = 12;    // gGlyphHeight
    }
    else
    {
        glyphs = gFont8LatinGlyphs + (0x20 * glyphId);
        gUnknown_03002F90[0x80] = gFont8LatinGlyphWidths[glyphId];

        if (gUnknown_03002F90[0x80] <= 8)
        {
            DecompressGlyphTile(glyphs, (u16 *)gUnknown_03002F90);
            DecompressGlyphTile(glyphs + 0x10, (u16 *)(gUnknown_03002F90 + 0x40));
        }
        else
        {
            DecompressGlyphTile(glyphs, (u16 *)gUnknown_03002F90);
            DecompressGlyphTile(glyphs + 0x8, (u16 *)(gUnknown_03002F90 + 0x20));
            DecompressGlyphTile(glyphs + 0x10, (u16 *)(gUnknown_03002F90 + 0x40));
            DecompressGlyphTile(glyphs + 0x18, (u16 *)(gUnknown_03002F90 + 0x60));
        }

        gUnknown_03002F90[0x81] = 12;
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
        DecompressGlyphTile(glyphs, (u16 *)gUnknown_03002F90);
        DecompressGlyphTile(glyphs + 0x8, (u16 *)(gUnknown_03002F90 + 0x20));    // gUnknown_03002FD0
        DecompressGlyphTile(glyphs + 0x80, (u16 *)(gUnknown_03002F90 + 0x40));    // gUnknown_03002FB0
        DecompressGlyphTile(glyphs + 0x88, (u16 *)(gUnknown_03002F90 + 0x60));    // gUnknown_03002FF0
        gUnknown_03002F90[0x80] = gFont2JapaneseGlyphWidths[glyphId];     // gGlyphWidth
        gUnknown_03002F90[0x81] = 14;    // gGlyphHeight
    }
    else
    {
        glyphs = gFont2LatinGlyphs + (0x20 * glyphId);
        gUnknown_03002F90[0x80] = gFont2LatinGlyphWidths[glyphId];

        if (gUnknown_03002F90[0x80] <= 8)
        {
            DecompressGlyphTile(glyphs, (u16 *)gUnknown_03002F90);
            DecompressGlyphTile(glyphs + 0x10, (u16 *)(gUnknown_03002F90 + 0x40));
        }
        else
        {
            DecompressGlyphTile(glyphs, (u16 *)gUnknown_03002F90);
            DecompressGlyphTile(glyphs + 0x8, (u16 *)(gUnknown_03002F90 + 0x20));
            DecompressGlyphTile(glyphs + 0x10, (u16 *)(gUnknown_03002F90 + 0x40));
            DecompressGlyphTile(glyphs + 0x18, (u16 *)(gUnknown_03002F90 + 0x60));
        }

        gUnknown_03002F90[0x81] = 14;
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
        DecompressGlyphTile(glyphs, (u16 *)gUnknown_03002F90);
        DecompressGlyphTile(glyphs + 0x80, (u16 *)(gUnknown_03002F90 + 0x40));    // gUnknown_03002FD0
        gUnknown_03002F90[0x80] = 8;     // gGlyphWidth
        gUnknown_03002F90[0x81] = 15;    // gGlyphHeight
    }
    else
    {
        glyphs = gFont1LatinGlyphs + (0x20 * glyphId);
        gUnknown_03002F90[0x80] = gFont1LatinGlyphWidths[glyphId];

        if (gUnknown_03002F90[0x80] <= 8)
        {
            DecompressGlyphTile(glyphs, (u16 *)gUnknown_03002F90);
            DecompressGlyphTile(glyphs + 0x10, (u16 *)(gUnknown_03002F90 + 0x40));
        }
        else
        {
            DecompressGlyphTile(glyphs, (u16 *)gUnknown_03002F90);
            DecompressGlyphTile(glyphs + 0x8, (u16 *)(gUnknown_03002F90 + 0x20));
            DecompressGlyphTile(glyphs + 0x10, (u16 *)(gUnknown_03002F90 + 0x40));
            DecompressGlyphTile(glyphs + 0x18, (u16 *)(gUnknown_03002F90 + 0x60));
        }

        gUnknown_03002F90[0x81] = 15;
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
    DecompressGlyphTile(glyphs, (u16 *)gUnknown_03002F90);
    DecompressGlyphTile(glyphs + 0x80, (u16 *)(gUnknown_03002F90 + 0x40));
    gUnknown_03002F90[0x80] = 8;
    gUnknown_03002F90[0x81] = 12;
}
