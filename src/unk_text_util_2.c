#include "global.h"
#include "main.h"
#include "window.h"
#include "text.h"
#include "sound.h"

ALIGNED(4)
static const u8 sScrollDistances[] = {1, 2, 4};
static const u16 sFont6BrailleGlyphs[] = INCBIN_U16("graphics/fonts/font6.fwjpnfont");

static void DecompressGlyphFont6(u16);

u16 Font6Func(struct TextPrinter *textPrinter)
{
    u16 char_;
    struct TextPrinterSubStruct *subStruct;
    subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);

    switch (textPrinter->state)
    {
        case 0:
            if (JOY_HELD(A_BUTTON | B_BUTTON) && subStruct->hasPrintBeenSpedUp)
            {
                textPrinter->delayCounter = 0;
            }
            if (textPrinter->delayCounter && textPrinter->textSpeed)
            {
                textPrinter->delayCounter --;
                if (gTextFlags.canABSpeedUpPrint && JOY_NEW(A_BUTTON | B_BUTTON))
                {
                    subStruct->hasPrintBeenSpedUp = TRUE;
                    textPrinter->delayCounter = 0;
                }
                return 3;
            }
            if (gTextFlags.autoScroll)
            {
                textPrinter->delayCounter = 3;
            }
            else
            {
                textPrinter->delayCounter = textPrinter->textSpeed;
            }
            char_ = *textPrinter->printerTemplate.currentChar++;
            switch (char_)
            {
                case EOS:
                    return 1;
                case CHAR_NEWLINE:
                    textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x;
                    textPrinter->printerTemplate.currentY += gFonts[textPrinter->printerTemplate.fontId].maxLetterHeight + textPrinter->printerTemplate.lineSpacing;
                    return 2;
                case PLACEHOLDER_BEGIN:
                    textPrinter->printerTemplate.currentChar++;
                    return 2;
                case EXT_CTRL_CODE_BEGIN:
                    char_ = *textPrinter->printerTemplate.currentChar++;
                    switch (char_)
                    {
                        case EXT_CTRL_CODE_COLOR:
                            textPrinter->printerTemplate.fgColor = *textPrinter->printerTemplate.currentChar++;
                            GenerateFontHalfRowLookupTable(textPrinter->printerTemplate.fgColor, textPrinter->printerTemplate.bgColor, textPrinter->printerTemplate.shadowColor);
                            return 2;
                        case EXT_CTRL_CODE_HIGHLIGHT:
                            textPrinter->printerTemplate.bgColor = *textPrinter->printerTemplate.currentChar++;
                            GenerateFontHalfRowLookupTable(textPrinter->printerTemplate.fgColor, textPrinter->printerTemplate.bgColor, textPrinter->printerTemplate.shadowColor);
                            return 2;
                        case EXT_CTRL_CODE_SHADOW:
                            textPrinter->printerTemplate.shadowColor = *textPrinter->printerTemplate.currentChar++;
                            GenerateFontHalfRowLookupTable(textPrinter->printerTemplate.fgColor, textPrinter->printerTemplate.bgColor, textPrinter->printerTemplate.shadowColor);
                            return 2;
                        case EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW:
                            textPrinter->printerTemplate.fgColor = *textPrinter->printerTemplate.currentChar;
                            textPrinter->printerTemplate.bgColor = *++textPrinter->printerTemplate.currentChar;
                            textPrinter->printerTemplate.shadowColor = *++textPrinter->printerTemplate.currentChar;
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
                            textPrinter->delayCounter = *textPrinter->printerTemplate.currentChar++;
                            textPrinter->state = 6;
                            return 2;
                        case EXT_CTRL_CODE_PAUSE_UNTIL_PRESS:
                            textPrinter->state = 1;
                            if (gTextFlags.autoScroll)
                            {
                                subStruct->autoScrollDelay = 0;
                            }
                            return 3;
                        case EXT_CTRL_CODE_WAIT_SE:
                            textPrinter->state = 5;
                            return 3;
                        case EXT_CTRL_CODE_PLAY_BGM:
                        case EXT_CTRL_CODE_PLAY_SE:
                            textPrinter->printerTemplate.currentChar += 2;
                            return 2;
                        case EXT_CTRL_CODE_ESCAPE:
                            char_ = *++textPrinter->printerTemplate.currentChar;
                            break;
                        case EXT_CTRL_CODE_SHIFT_TEXT:
                            textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x + *textPrinter->printerTemplate.currentChar++;
                            return 2;
                        case EXT_CTRL_CODE_SHIFT_DOWN:
                            textPrinter->printerTemplate.currentY = textPrinter->printerTemplate.y + *textPrinter->printerTemplate.currentChar++;
                            return 2;
                        case EXT_CTRL_CODE_FILL_WINDOW:
                            FillWindowPixelBuffer(textPrinter->printerTemplate.windowId, PIXEL_FILL(textPrinter->printerTemplate.bgColor));
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
                    char_ = *textPrinter->printerTemplate.currentChar++| 0x100;
                    break;
                case CHAR_KEYPAD_ICON:
                    textPrinter->printerTemplate.currentChar++;
                    return 0;
            }
            DecompressGlyphFont6(char_);
            CopyGlyphToWindow(textPrinter);
            textPrinter->printerTemplate.currentX += gCurGlyph.width + textPrinter->printerTemplate.letterSpacing;
            return 0;
        case 1:
            if (TextPrinterWait(textPrinter))
            {
                textPrinter->state = 0;
            }
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
                if (textPrinter->scrollDistance < sScrollDistances[gSaveBlock2Ptr->optionsTextSpeed])
                {
                    ScrollWindow(textPrinter->printerTemplate.windowId, 0, textPrinter->scrollDistance, PIXEL_FILL(textPrinter->printerTemplate.bgColor));
                    textPrinter->scrollDistance = 0;
                }
                else
                {
                    ScrollWindow(textPrinter->printerTemplate.windowId, 0, sScrollDistances[gSaveBlock2Ptr->optionsTextSpeed], PIXEL_FILL(textPrinter->printerTemplate.bgColor));
                    textPrinter->scrollDistance -= sScrollDistances[gSaveBlock2Ptr->optionsTextSpeed];
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
            {
                textPrinter->state = 0;
            }
            return 3;
        case 6:
            if (textPrinter->delayCounter)
            {
                textPrinter->delayCounter --;
            }
            else
            {
                textPrinter->state = 0;
            }
            return 3;
    }
    return 1;
}

static void DecompressGlyphFont6(u16 glyph)
{
    const u16 *glyphs;

    glyphs = sFont6BrailleGlyphs + 0x100 * (glyph / 8) + 0x10 * (glyph % 8);
    DecompressGlyphTile(glyphs, gCurGlyph.gfxBufferTop);
    DecompressGlyphTile(glyphs + 0x8, gCurGlyph.gfxBufferTop + 8);
    DecompressGlyphTile(glyphs + 0x80, gCurGlyph.gfxBufferBottom);
    DecompressGlyphTile(glyphs + 0x88, gCurGlyph.gfxBufferBottom + 8);
    gCurGlyph.width = 0x10;
    gCurGlyph.height = 0x10;
}

u32 GetGlyphWidthFont6(u16 glyphId, bool32 isJapanese)
{
    return 0x10;
}
