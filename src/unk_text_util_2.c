#include "global.h"
#include "main.h"
#include "window.h"
#include "text.h"
#include "sound.h"

ALIGNED(4)
static const u8 sUnknown_08616124[] = {1, 2, 4};
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
            if (gMain.heldKeys & (A_BUTTON | B_BUTTON) && subStruct->hasPrintBeenSpedUp)
            {
                textPrinter->delayCounter = 0;
            }
            if (textPrinter->delayCounter && textPrinter->textSpeed)
            {
                textPrinter->delayCounter --;
                if (gTextFlags.canABSpeedUpPrint && gMain.newKeys & (A_BUTTON | B_BUTTON))
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
                        case 1:
                            textPrinter->printerTemplate.fgColor = *textPrinter->printerTemplate.currentChar++;
                            GenerateFontHalfRowLookupTable(textPrinter->printerTemplate.fgColor, textPrinter->printerTemplate.bgColor, textPrinter->printerTemplate.shadowColor);
                            return 2;
                        case 2:
                            textPrinter->printerTemplate.bgColor = *textPrinter->printerTemplate.currentChar++;
                            GenerateFontHalfRowLookupTable(textPrinter->printerTemplate.fgColor, textPrinter->printerTemplate.bgColor, textPrinter->printerTemplate.shadowColor);
                            return 2;
                        case 3:
                            textPrinter->printerTemplate.shadowColor = *textPrinter->printerTemplate.currentChar++;
                            GenerateFontHalfRowLookupTable(textPrinter->printerTemplate.fgColor, textPrinter->printerTemplate.bgColor, textPrinter->printerTemplate.shadowColor);
                            return 2;
                        case 4:
                            textPrinter->printerTemplate.fgColor = *textPrinter->printerTemplate.currentChar;
                            textPrinter->printerTemplate.bgColor = *++textPrinter->printerTemplate.currentChar;
                            textPrinter->printerTemplate.shadowColor = *++textPrinter->printerTemplate.currentChar;
                            textPrinter->printerTemplate.currentChar++;

                            GenerateFontHalfRowLookupTable(textPrinter->printerTemplate.fgColor, textPrinter->printerTemplate.bgColor, textPrinter->printerTemplate.shadowColor);
                            return 2;
                        case 5:
                            textPrinter->printerTemplate.currentChar++;
                            return 2;
                        case 6:
                            subStruct->glyphId = *textPrinter->printerTemplate.currentChar;
                            textPrinter->printerTemplate.currentChar++;
                            return 2;
                        case 7:
                            return 2;
                        case 8:
                            textPrinter->delayCounter = *textPrinter->printerTemplate.currentChar++;
                            textPrinter->state = 6;
                            return 2;
                        case 9:
                            textPrinter->state = 1;
                            if (gTextFlags.autoScroll)
                            {
                                subStruct->autoScrollDelay = 0;
                            }
                            return 3;
                        case 10:
                            textPrinter->state = 5;
                            return 3;
                        case 11:
                        case 16:
                            textPrinter->printerTemplate.currentChar += 2;
                            return 2;
                        case 12:
                            char_ = *++textPrinter->printerTemplate.currentChar;
                            break;
                        case 13:
                            textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x + *textPrinter->printerTemplate.currentChar++;
                            return 2;
                        case 14:
                            textPrinter->printerTemplate.currentY = textPrinter->printerTemplate.y + *textPrinter->printerTemplate.currentChar++;
                            return 2;
                        case 15:
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
                case 0xF9:
                    char_ = *textPrinter->printerTemplate.currentChar++| 0x100;
                    break;
                case 0xF8:
                    textPrinter->printerTemplate.currentChar++;
                    return 0;
            }
            DecompressGlyphFont6(char_);
            CopyGlyphToWindow(textPrinter);
            textPrinter->printerTemplate.currentX += gUnknown_03002F90.unk80 + textPrinter->printerTemplate.letterSpacing;
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
                if (textPrinter->scrollDistance < sUnknown_08616124[gSaveBlock2Ptr->optionsTextSpeed])
                {
                    ScrollWindow(textPrinter->printerTemplate.windowId, 0, textPrinter->scrollDistance, PIXEL_FILL(textPrinter->printerTemplate.bgColor));
                    textPrinter->scrollDistance = 0;
                }
                else
                {
                    ScrollWindow(textPrinter->printerTemplate.windowId, 0, sUnknown_08616124[gSaveBlock2Ptr->optionsTextSpeed], PIXEL_FILL(textPrinter->printerTemplate.bgColor));
                    textPrinter->scrollDistance -= sUnknown_08616124[gSaveBlock2Ptr->optionsTextSpeed];
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
    DecompressGlyphTile(glyphs, (u16 *)gUnknown_03002F90.unk0);
    DecompressGlyphTile(glyphs + 0x8, (u16 *)(gUnknown_03002F90.unk20));
    DecompressGlyphTile(glyphs + 0x80, (u16 *)(gUnknown_03002F90.unk40));
    DecompressGlyphTile(glyphs + 0x88, (u16 *)(gUnknown_03002F90.unk60));
    gUnknown_03002F90.unk80 = 0x10;
    gUnknown_03002F90.unk81 = 0x10;
}

u32 GetGlyphWidthFont6(u16 glyphId, bool32 isJapanese)
{
    return 0x10;
}
