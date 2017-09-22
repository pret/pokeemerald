#include "global.h"
#include "main.h"
#include "window.h"
#include "text.h"
#include "sound.h"

extern const u8 gUnknown_08616124[];

void DecompressGlyphFont6(u16);

u16 Font6Func(struct TextPrinter *textPrinter)
{
    u16 char_;
    struct TextPrinterSubStruct *sub;
    
    sub = &textPrinter->sub_union.sub;
    switch (textPrinter->state)
    {
        case 0:
            if (gMain.heldKeys & (A_BUTTON | B_BUTTON) && sub->font_type_upper)
            {
                textPrinter->delayCounter = 0;
            }
            if (textPrinter->delayCounter && textPrinter->text_speed)
            {
                textPrinter->delayCounter --;
                if (gTextFlags.flag_0 && gMain.newKeys & (A_BUTTON | B_BUTTON))
                {
                    sub->font_type_upper = TRUE;
                    textPrinter->delayCounter = 0;
                }
                return 3;
            }
            if (gTextFlags.flag_2)
            {
                textPrinter->delayCounter = 3;
            }
            else
            {
                textPrinter->delayCounter = textPrinter->text_speed;
            }
            char_ = *textPrinter->subPrinter.current_text_offset ++;
            switch (char_)
            {
                case EOS:
                    return 1;
                case CHAR_NEWLINE:
                    textPrinter->subPrinter.currentX = textPrinter->subPrinter.x;
                    textPrinter->subPrinter.currentY += gFonts[textPrinter->subPrinter.fontId].maxLetterHeight + textPrinter->subPrinter.lineSpacing;
                    return 2;
                case PLACEHOLDER_BEGIN:
                    textPrinter->subPrinter.current_text_offset ++;
                    return 2;
                case EXT_CTRL_CODE_BEGIN:
                    char_ = *textPrinter->subPrinter.current_text_offset ++;
                    switch (char_)
                    {
                        case 1:
                            textPrinter->subPrinter.fontColor_h = *textPrinter->subPrinter.current_text_offset ++;
                            GenerateFontHalfRowLookupTable(textPrinter->subPrinter.fontColor_h, textPrinter->subPrinter.bgColor, textPrinter->subPrinter.shadowColor);
                            return 2;
                        case 2:
                            textPrinter->subPrinter.bgColor = *textPrinter->subPrinter.current_text_offset ++;
                            GenerateFontHalfRowLookupTable(textPrinter->subPrinter.fontColor_h, textPrinter->subPrinter.bgColor, textPrinter->subPrinter.shadowColor);
                            return 2;
                        case 3:
                            textPrinter->subPrinter.shadowColor = *textPrinter->subPrinter.current_text_offset ++;
                            GenerateFontHalfRowLookupTable(textPrinter->subPrinter.fontColor_h, textPrinter->subPrinter.bgColor, textPrinter->subPrinter.shadowColor);
                            return 2;
                        case 4:
                            textPrinter->subPrinter.fontColor_h = *textPrinter->subPrinter.current_text_offset;
                            textPrinter->subPrinter.bgColor = *++ textPrinter->subPrinter.current_text_offset;
                            textPrinter->subPrinter.shadowColor = *++ textPrinter->subPrinter.current_text_offset;
                            textPrinter->subPrinter.current_text_offset ++;

                            GenerateFontHalfRowLookupTable(textPrinter->subPrinter.fontColor_h, textPrinter->subPrinter.bgColor, textPrinter->subPrinter.shadowColor);
                            return 2;
                        case 5:
                            textPrinter->subPrinter.current_text_offset ++;
                            return 2;
                        case 6:
                            sub->font_type = *textPrinter->subPrinter.current_text_offset;
                            textPrinter->subPrinter.current_text_offset ++;
                            return 2;
                        case 7:
                            return 2;
                        case 8:
                            textPrinter->delayCounter = *textPrinter->subPrinter.current_text_offset ++;
                            textPrinter->state = 6;
                            return 2;
                        case 9:
                            textPrinter->state = 1;
                            if (gTextFlags.flag_2)
                            {
                                sub->frames_visible_counter = 0;
                            }
                            return 3;
                        case 10:
                            textPrinter->state = 5;
                            return 3;
                        case 11:
                        case 16:
                            textPrinter->subPrinter.current_text_offset += 2;
                            return 2;
                        case 12:
                            char_ = *++textPrinter->subPrinter.current_text_offset;
                            break;
                        case 13:
                            textPrinter->subPrinter.currentX = textPrinter->subPrinter.x + *textPrinter->subPrinter.current_text_offset ++;
                            return 2;
                        case 14:
                            textPrinter->subPrinter.currentY = textPrinter->subPrinter.y + *textPrinter->subPrinter.current_text_offset ++;
                            return 2;
                        case 15:
                            FillWindowPixelBuffer(textPrinter->subPrinter.windowId, textPrinter->subPrinter.bgColor | (textPrinter->subPrinter.bgColor << 4));
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
                    char_ = *textPrinter->subPrinter.current_text_offset ++ | 0x100;
                    break;
                case 0xF8:
                    textPrinter->subPrinter.current_text_offset ++;
                    return 0;
            }
            DecompressGlyphFont6(char_);
            CopyGlyphToWindow(textPrinter);
            textPrinter->subPrinter.currentX += gUnknown_03002F90[0x80] + textPrinter->subPrinter.letterSpacing;
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
                FillWindowPixelBuffer(textPrinter->subPrinter.windowId, textPrinter->subPrinter.bgColor | (textPrinter->subPrinter.bgColor << 4));
                textPrinter->subPrinter.currentX = textPrinter->subPrinter.x;
                textPrinter->subPrinter.currentY = textPrinter->subPrinter.y;
                textPrinter->state = 0;
            }
            return 3;
        case 3:
            if (TextPrinterWaitWithDownArrow(textPrinter))
            {
                TextPrinterClearDownArrow(textPrinter);
                textPrinter->scrollDistance = gFonts[textPrinter->subPrinter.fontId].maxLetterHeight + textPrinter->subPrinter.lineSpacing;
                textPrinter->subPrinter.currentX = textPrinter->subPrinter.x;
                textPrinter->state = 4;
            }
            return 3;
        case 4:
            if (textPrinter->scrollDistance)
            {
                if (textPrinter->scrollDistance < gUnknown_08616124[gSaveBlock2Ptr->optionsTextSpeed])
                {
                    ScrollWindow(textPrinter->subPrinter.windowId, 0, textPrinter->scrollDistance, textPrinter->subPrinter.bgColor | (textPrinter->subPrinter.bgColor << 4));
                    textPrinter->scrollDistance = 0;
                }
                else
                {
                    ScrollWindow(textPrinter->subPrinter.windowId, 0, gUnknown_08616124[gSaveBlock2Ptr->optionsTextSpeed], textPrinter->subPrinter.bgColor | (textPrinter->subPrinter.bgColor << 4));
                    textPrinter->scrollDistance -= gUnknown_08616124[gSaveBlock2Ptr->optionsTextSpeed];
                }
                CopyWindowToVram(textPrinter->subPrinter.windowId, 2);
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
