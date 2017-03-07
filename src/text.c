#include "global.h"
#include "text.h"
#include "battle.h"
#include "main.h"
#include "palette.h"
#include "string_util.h"

EWRAM_DATA struct TextPrinter gTempTextPrinter;
EWRAM_DATA struct TextPrinter gTextPrinters[NUM_TEXT_PRINTERS];

extern u8 gUnknown_03002F84[];

extern struct FontInfo *gFonts;

u16 AddTextPrinter(struct TextWindow *textWindow, u8 speed, void (*callback)(u16, struct TextWindow *));
void GenerateFontHalfRowLookupTable(u8 fgColor, u8 bgColor, u8 shadowColor);
u32 RenderFont(struct TextPrinter *textPrinter);
void CopyWindowToVram(u8 windowId, u8 mode);

void SetFontsPointer(struct FontInfo *fonts)
{
    gFonts = fonts;
}

void DeactivateAllTextPrinters (void)
{
    int printer;
    for (printer = 0; printer < NUM_TEXT_PRINTERS; ++printer)
        gTextPrinters[printer].sub_union.sub.field_7 = 0;
}

u16 Print(u8 windowId, u8 fontId, u8 *str, u8 x, u8 y, u8 speed, void (*callback)(u16, struct TextWindow *))
{
    struct TextWindow window;

    window.current_text_offset = str;
    window.windowId = windowId;
    window.fontId = fontId;
    window.x = x;
    window.y = y;
    window.currentX = x;
    window.currentY = y;
    window.letterSpacing = gFonts[fontId].letterSpacing;
    window.lineSpacing = gFonts[fontId].lineSpacing;
    window.fontColor_l = gFonts[fontId].fontColor_l;
    window.fontColor_h = gFonts[fontId].fontColor_h;
    window.bgColor = gFonts[fontId].bgColor;
    window.shadowColor = gFonts[fontId].shadowColor;
    return AddTextPrinter(&window, speed, callback);
}

u16 AddTextPrinter(struct TextWindow *textWindow, u8 speed, void (*callback)(u16, struct TextWindow *))
{
    int i;
    u16 j;

    if (!gFonts)
        return FALSE;
    
    gTempTextPrinter.sub_union.sub.field_7 = 1;
    gTempTextPrinter.state = 0;
    gTempTextPrinter.text_speed = speed;
    gTempTextPrinter.delayCounter = 0;
    gTempTextPrinter.scrollDistance = 0;
    
    for (i = 0; i < 7; ++i)
    {
        gTempTextPrinter.sub_union.sub_fields[i] = 0;
    }
    
    gTempTextPrinter.window = *textWindow;
    gTempTextPrinter.callback = callback;
    gTempTextPrinter.minLetterSpacing = 0;
    gTempTextPrinter.japanese = 0;

    GenerateFontHalfRowLookupTable(textWindow->fontColor_h, textWindow->bgColor, textWindow->shadowColor);
    if (speed != 0xFF && speed != 0x0)
    {
        --gTempTextPrinter.text_speed;
        gTextPrinters[textWindow->windowId] = gTempTextPrinter;
    }
    else
    {
        gTempTextPrinter.text_speed = 0;
        for (j = 0; j < 0x400; ++j)
        {
            if (RenderFont(&gTempTextPrinter) == 1)
                break;
        }
        
        if (speed != 0xFF)
          CopyWindowToVram(gTempTextPrinter.window.windowId, 2);
        gTextPrinters[textWindow->windowId].sub_union.sub.field_7 = 0;
    }
    gUnknown_03002F84[0] = 0;
    return TRUE;
}

// struct means TextWindow, no struct means TextPrinter
