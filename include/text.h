#ifndef GUARD_TEXT_H
#define GUARD_TEXT_H

#define CHAR_SPACE          0x00
#define CHAR_0              0xA1
#define CHAR_QUESTION_MARK  0xAC
#define CHAR_PERIOD         0xAD
#define CHAR_HYPHEN         0xAE
#define CHAR_ELLIPSIS       0xB0
#define CHAR_MALE           0xB5
#define CHAR_FEMALE         0xB6
#define CHAR_CURRENCY       0xB7
#define CHAR_COMMA          0xB8
#define CHAR_MULT_SIGN      0xB9
#define CHAR_SLASH          0xBA
#define CHAR_A              0xBB
#define CHAR_B              0xBC
#define CHAR_C              0xBD
#define CHAR_D              0xBE
#define CHAR_E              0xBF
#define CHAR_F              0xC0
#define CHAR_G              0xC1
#define CHAR_H              0xC2
#define CHAR_I              0xC3
#define CHAR_J              0xC4
#define CHAR_K              0xC5
#define CHAR_L              0xC6
#define CHAR_M              0xC7
#define CHAR_N              0xC8
#define CHAR_O              0xC9
#define CHAR_P              0xCA
#define CHAR_Q              0xCB
#define CHAR_R              0xCC
#define CHAR_S              0xCD
#define CHAR_T              0xCE
#define CHAR_U              0xCF
#define CHAR_V              0xD0
#define CHAR_W              0xD1
#define CHAR_X              0xD2
#define CHAR_Y              0xD3
#define CHAR_Z              0xD4
#define CHAR_a              0xD5
#define CHAR_b              0xD6
#define CHAR_c              0xD7
#define CHAR_d              0xD8
#define CHAR_e              0xD9
#define CHAR_f              0xDA
#define CHAR_g              0xDB
#define CHAR_h              0xDC
#define CHAR_i              0xDD
#define CHAR_j              0xDE
#define CHAR_k              0xDF
#define CHAR_l              0xE0
#define CHAR_m              0xE1
#define CHAR_n              0xE2
#define CHAR_o              0xE3
#define CHAR_p              0xE4
#define CHAR_q              0xE5
#define CHAR_r              0xE6
#define CHAR_s              0xE7
#define CHAR_t              0xE8
#define CHAR_u              0xE9
#define CHAR_v              0xEA
#define CHAR_w              0xEB
#define CHAR_x              0xEC
#define CHAR_y              0xED
#define CHAR_z              0xEE
#define CHAR_SPECIAL_F9     0xF9
#define CHAR_COLON          0xF0
#define CHAR_PROMPT_SCROLL  0xFA // waits for button press and scrolls dialog
#define CHAR_PROMPT_CLEAR   0xFB // waits for button press and clears dialog
#define EXT_CTRL_CODE_BEGIN 0xFC // extended control code
#define PLACEHOLDER_BEGIN   0xFD // string placeholder
#define CHAR_NEWLINE        0xFE
#define EOS                 0xFF // end of string

#define TEXT_COLOR_TRANSPARENT  0x0
#define TEXT_COLOR_WHITE        0x1
#define TEXT_COLOR_DARK_GREY    0x2

// battle placeholders are located in battle_message.h

#define EXT_CTRL_CODE_JPN   0x15
#define EXT_CTRL_CODE_ENG   0x16

#define NUM_TEXT_PRINTERS 32

#define TEXT_SPEED_FF 0xFF

struct TextPrinterSubStruct
{
    u8 font_type:4;  // 0x14
    u8 font_type_upper:1;
    u8 font_type_5:3;
    u8 field_1:5;
    u8 field_1_upmid:2;
    u8 field_1_top:1;
    u8 frames_visible_counter;
    u8 field_3;
    u8 field_4; // 0x18
    u8 field_5;
    u8 field_6;
    u8 active;
};

struct TextSubPrinter // TODO: Better name
{
    const u8* current_text_offset;
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
};

struct TextPrinter
{
    struct TextSubPrinter subPrinter;

    void (*callback)(struct TextSubPrinter *, u16); // 0x10

    union {
        struct TextPrinterSubStruct sub;

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

extern const struct FontInfo *gFonts;

struct GlyphWidthFunc
{
    u32 font_id;
    u32 (*func)(u16 glyphId, bool32 isJapanese);
};

struct KeypadIcon
{
    u16 tile_offset;
    u8 width;
    u8 height;
};

typedef struct {
    u8 flag_0:1;
    u8 flag_1:1;
    u8 flag_2:1;
    u8 flag_3:1;
} TextFlags;

extern TextFlags gTextFlags;

struct __attribute__((packed)) TextColor
{
    u8 fgColor;
    u8 bgColor;
    u8 shadowColor;
};

extern u8 gStringVar1[];
extern u8 gStringVar2[];
extern u8 gStringVar3[];
extern u8 gStringVar4[];

u8 gUnknown_03002F84;
u8 gUnknown_03002F90[0x20];
u8 gUnknown_03002FB0[0x20];
u8 gUnknown_03002FD0[0x20];
u8 gUnknown_03002FF0[0x20];
u8 gGlyphDimensions[0x2];

void SetFontsPointer(const struct FontInfo *fonts);
void DeactivateAllTextPrinters(void);
u16 PrintTextOnWindow(u8 windowId, u8 fontId, const u8 *str, u8 x, u8 y, u8 speed, void (*callback)(struct TextSubPrinter *, u16));
bool16 AddTextPrinter(struct TextSubPrinter *textSubPrinter, u8 speed, void (*callback)(struct TextSubPrinter *, u16));
void RunTextPrinters(void);
bool16 IsTextPrinterActive(u8 id);
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
bool16 TextPrinterWaitWithDownArrow(struct TextPrinter *textPrinter);
bool16 TextPrinterWait(struct TextPrinter *textPrinter);
void DrawDownArrow(u8 windowId, u16 x, u16 y, u8 bgColor, bool8 drawArrow, u8 *counter, u8 *yCoordIndex);
u16 RenderText(struct TextPrinter *textPrinter);
u32 GetStringWidthFixedWidthFont(const u8 *str, u8 fontId, u8 letterSpacing);
u32 (*GetFontWidthFunc(u8 glyphId))(u16, bool32);
u32 GetStringWidth(u8 fontId, const u8 *str, s16 letterSpacing);
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
