#include "global.h"
#include "text.h"
#include "battle.h"
#include "main.h"
#include "palette.h"
#include "string_util.h"

EWRAM_DATA struct TextPrinter gTempTextPrinter;
EWRAM_DATA struct TextPrinter gTextPrinters[NUM_TEXT_PRINTERS];

extern u16 gFontHalfRowLookupTable[];
extern u16 gLastTextBgColor;
extern u16 gLastTextFgColor;
extern u16 gLastTextShadowColor;

extern struct FontInfo *gFonts;
extern u8 gUnknown_03002F84[];

extern u8 gFontHalfRowOffsets[];

u16 AddTextPrinter(struct TextWindow *textWindow, u8 speed, void (*callback)(struct TextWindow *, u16));
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
        gTextPrinters[printer].sub_union.sub.active = 0;
}

u16 Print(u8 windowId, u8 fontId, u8 *str, u8 x, u8 y, u8 speed, void (*callback)(struct TextWindow *, u16))
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

u16 AddTextPrinter(struct TextWindow *textWindow, u8 speed, void (*callback)(struct TextWindow *, u16))
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
            if ((u32)RenderFont(&gTempTextPrinter) == 1)
                break;
        }
        
        if (speed != 0xFF)
          CopyWindowToVram(gTempTextPrinter.window.windowId, 2);
        gTextPrinters[textWindow->windowId].sub_union.sub.active = 0;
    }
    gUnknown_03002F84[0] = 0;
    return TRUE;
}

void RunTextPrinters(void)
{
    int i;
    u16 temp;

    if (gUnknown_03002F84[0] == 0)
    {
        for (i = 0; i < 0x20; ++i)
        {
            if (gTextPrinters[i].sub_union.sub.active != 0)
            {
                temp = RenderFont(&gTextPrinters[i]);
                switch (temp) {
                    case 0:
                        CopyWindowToVram(gTextPrinters[i].window.windowId, 2);
                    case 3:
                        if (gTextPrinters[i].callback != 0)
                            gTextPrinters[i].callback(&gTextPrinters[i].window, temp);
                        break;
                    case 1:
                        gTextPrinters[i].sub_union.sub.active = 0;
                        break;
                }
            }
        }
    }
}

bool8 IsTextPrinterActive(u8 id)
{
    return gTextPrinters[id].sub_union.sub.active;
}


u32 RenderFont(struct TextPrinter *textPrinter)
{
    u32 ret;
    while (TRUE)
    {
        ret = gFonts[textPrinter->window.fontId].fontFunction(textPrinter);
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
__attribute__((naked))
void GenerateFontHalfRowLookupTable(u8 fgColor, u8 bgColor, u8 shadowColor)
{
    asm("	push {r4-r7,lr}\n\
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

// struct means TextWindow, no struct means TextPrinter

//#ifdef NONMATCHING
void DecompressGlyphTile(u16 *src, u32 *dest)
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
/*#else
__attribute__((naked))
void DecompressGlyphTile(u16 *src, u32 *dest)
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
#endif*/

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


