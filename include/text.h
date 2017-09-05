#ifndef GUARD_TEXT_H
#define GUARD_TEXT_H

#define CHAR_SPACE          0x00
#define CHAR_QUESTION_MARK  0xAC
#define CHAR_HYPHEN         0xAE
#define CHAR_CURRENCY       0xB7
#define CHAR_COLON          0xF0
#define EXT_CTRL_CODE_BEGIN 0xFC // extended control code
#define PLACEHOLDER_BEGIN   0xFD // string placeholder
#define CHAR_NEWLINE        0xFE
#define EOS                 0xFF // end of string

#define NUM_TEXT_PRINTERS 32

struct TextPrinter
{
    struct TextSubPrinter {     // TODO: Better name
        u8* current_text_offset;
        u8 windowId;
        u8 fontId;
        u8 x;
        u8 y;
        u8 currentX;        // 0x8
        u8 currentY;
        u8 letterSpacing;
        u8 lineSpacing;
        u8 fontColor_l:4;   // 0xC
        u8 fontColor_h:4;
        u8 bgColor:4;
        u8 shadowColor:4;
    } subPrinter;
    
    void (*callback)(struct TextSubPrinter *, u16); // 0x10
    
    union {
        struct TextPrinterSubStruct
        {
            u8 font_type:4;  // 0x14
            u8 font_type_upper:4;
            u8 field_1:5;
            u8 field_1_upmid:2;
            u8 field_1_top:1;
            u8 frames_visible_counter;
            u8 field_3;
            u8 field_4; // 0x18
            u8 field_5;
            u8 field_6;
            u8 active;
        } sub;
        
        u8 sub_fields[8];
    } sub_union;
    
    u8 state;       // 0x1C
    u8 text_speed;
    u8 delayCounter;
    u8 scrollDistance;
    u8 minLetterSpacing;  // 0x20
    u8 japanese;
};

struct FontInfo
{
    u16 (*fontFunction)(struct TextPrinter *x);
    u8 maxLetterWidth;
    u8 maxLetterHeight;
    u8 letterSpacing;
    u8 lineSpacing;
    u8 fontColor_l:4;
    u8 fontColor_h:4;
    u8 bgColor:4;
    u8 shadowColor:4;
};

struct GlyphWidthFunc{
    u32 font_id;
    u32 (*func)(u16 glyphId, bool32 isJapanese);
};

struct KeypadIcon {
    u16 tile_offset;
    u8 width;
    u8 height;
};

extern u8 gStringVar1[];
extern u8 gStringVar2[];
extern u8 gStringVar3[];
extern u8 gStringVar4[];

void SetFontsPointer(const struct FontInfo *fonts);
void DeactivateAllTextPrinters (void);
u16 PrintTextOnWindow(u8 windowId, u8 fontId, u8 *str, u8 x, u8 y, u8 speed, void (*callback)(struct TextSubPrinter *, u16));
bool16 AddTextPrinter(struct TextSubPrinter *textSubPrinter, u8 speed, void (*callback)(struct TextSubPrinter *, u16));
void RunTextPrinters(void);
bool8 IsTextPrinterActive(u8 id);
u32 RenderFont(struct TextPrinter *textPrinter);
void GenerateFontHalfRowLookupTable(u8 fgColor, u8 bgColor, u8 shadowColor);
void SaveTextColors(u8 *fgColor, u8 *bgColor, u8 *shadowColor);
void RestoreTextColors(u8 *fgColor, u8 *bgColor, u8 *shadowColor);
void DecompressGlyphTile(const u16 *src, u16 *dest);
u8 GetLastTextColor(u8 colorType);
void CopyGlyphToWindow(struct TextPrinter *x);
void ClearTextSpan(struct TextPrinter *textPrinter, u32 width);

u16 Font0Func(struct TextPrinter *textPrinter);
u16 Font1Func(struct TextPrinter *textPrinter);
u16 Font2Func(struct TextPrinter *textPrinter);
u16 Font3Func(struct TextPrinter *textPrinter);
u16 Font4Func(struct TextPrinter *textPrinter);
u16 Font5Func(struct TextPrinter *textPrinter);
u16 Font7Func(struct TextPrinter *textPrinter);
u16 Font8Func(struct TextPrinter *textPrinter);

void TextPrinterInitDownArrowCounters(struct TextPrinter *textPrinter);
void TextPrinterDrawDownArrow(struct TextPrinter *textPrinter);
void TextPrinterClearDownArrow(struct TextPrinter *textPrinter);
bool8 TextPrinterWaitAutoMode(struct TextPrinter *textPrinter);
bool8 TextPrinterWaitWithDownArrow(struct TextPrinter *textPrinter);
bool8 TextPrinterWait(struct TextPrinter *textPrinter);
void DrawDownArrow(u8 windowId, u16 x, u16 y, u8 bgColor, bool8 drawArrow, u8 *counter, u8 *yCoordIndex);
u16 RenderText(struct TextPrinter *textPrinter);
u32 GetStringWidthFixedWidthFont(u8 *str, u8 fontId, u8 letterSpacing);
u32 (*GetFontWidthFunc(u8 glyphId))(u16, bool32);
s32 GetStringWidth(u8 fontId, u8 *str, s16 letterSpacing);
u8 RenderTextFont9(u8 *pixels, u8 fontId, u8 *str);
u8 DrawKeypadIcon(u8 windowId, u8 keypadIconId, u16 x, u16 y);
u8 GetKeypadIconTileOffset(u8 keypadIconId);
u8 GetKeypadIconWidth(u8 keypadIconId);
u8 GetKeypadIconHeight(u8 keypadIconId);
void SetDefaultFontsPointer(void);
u8 GetFontAttribute(u8 fontId, u8 attributeId);
u8 GetMenuCursorDimensionByFont(u8 fontId, u8 whichDimension);
void DecompressGlyphFont0(u16 glyphId, bool32 isJapanese);
u32 GetGlyphWidthFont0(u16 glyphId, bool32 isJapanese);
void DecompressGlyphFont7(u16 glyphId, bool32 isJapanese);
u32 GetGlyphWidthFont7(u16 glyphId, bool32 isJapanese);
void DecompressGlyphFont8(u16 glyphId, bool32 isJapanese);
u32 GetGlyphWidthFont8(u16 glyphId, bool32 isJapanese);
void DecompressGlyphFont2(u16 glyphId, bool32 isJapanese);
u32 GetGlyphWidthFont2(u16 glyphId, bool32 isJapanese);
void DecompressGlyphFont1(u16 glyphId, bool32 isJapanese);
u32 GetGlyphWidthFont1(u16 glyphId, bool32 isJapanese);
void DecompressGlyphFont9(u16 glyphId);

#endif // GUARD_TEXT_H
