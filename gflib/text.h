#ifndef GUARD_TEXT_H
#define GUARD_TEXT_H

#define CHAR_SPACE             0x00
#define CHAR_A_GRAVE           0x01
#define CHAR_A_ACUTE           0x02
#define CHAR_A_CIRCUMFLEX      0x03
#define CHAR_C_CEDILLA         0x04
#define CHAR_E_GRAVE           0x05
#define CHAR_E_ACUTE           0x06
#define CHAR_E_CIRCUMFLEX      0x07
#define CHAR_E_DIAERESIS       0x08
#define CHAR_I_GRAVE           0x09
//#define CHAR_I_ACUTE         0x0A // Is 0x5A instead
#define CHAR_I_CIRCUMFLEX      0x0B
#define CHAR_I_DIAERESIS       0x0C
#define CHAR_O_GRAVE           0x0D
#define CHAR_O_ACUTE           0x0E
#define CHAR_O_CIRCUMFLEX      0x0F
#define CHAR_OE                0x10
#define CHAR_U_GRAVE           0x11    
#define CHAR_U_ACUTE           0x12
#define CHAR_U_CIRCUMFLEX      0x13
#define CHAR_N_TILDE           0x14
#define CHAR_ESZETT            0x15
#define CHAR_a_GRAVE           0x16
#define CHAR_a_ACUTE           0x17
//#define CHAR_a_CIRCUMFLEX    0x18 // Is 0x68 instead
#define CHAR_c_CEDILLA         0x19
#define CHAR_e_GRAVE           0x1A
#define CHAR_e_ACUTE           0x1B
#define CHAR_e_CIRCUMFLEX      0x1C
#define CHAR_e_DIAERESIS       0x1D
#define CHAR_i_GRAVE           0x1E
//#define CHAR_i_ACUTE         0x1F // Is 0x6F instead
#define CHAR_i_CIRCUMFLEX      0x20
#define CHAR_i_DIAERESIS       0x21
#define CHAR_o_GRAVE           0x22
#define CHAR_o_ACUTE           0x23
#define CHAR_o_CIRCUMFLEX      0x24
#define CHAR_oe                0x25
#define CHAR_u_GRAVE           0x26
#define CHAR_u_ACUTE           0x27
#define CHAR_u_CIRCUMFLEX      0x28
#define CHAR_n_TILDE           0x29
#define CHAR_MASCULINE_ORDINAL 0x2A
#define CHAR_FEMININE_ORDINAL  0x2B
#define CHAR_SUPER_ER          0x2C
#define CHAR_AMPERSAND         0x2D
#define CHAR_PLUS              0x2E
//
#define CHAR_LV                0x34
#define CHAR_EQUALS            0x35
#define CHAR_SEMICOLON         0x36
//
#define CHAR_INV_QUESTION_MARK 0x51
#define CHAR_INV_EXCL_MARK     0x52
#define CHAR_PK                0x53
#define CHAR_MN                0x54
#define CHAR_PO                0x55
#define CHAR_KE                0x56
#define CHAR_BLOCK_1           0x57 // Each of these 3
#define CHAR_BLOCK_2           0x58 // chars contains 1/3
#define CHAR_BLOCK_3           0x59 // of the word BLOCK
#define CHAR_I_ACUTE           0x5A
#define CHAR_PERCENT           0x5B
#define CHAR_LEFT_PAREN        0x5C
#define CHAR_RIGHT_PAREN       0x5D
//
#define CHAR_a_CIRCUMFLEX      0x68
//
#define CHAR_i_ACUTE           0x6F
//
#define CHAR_UNK_SPACER        0x77
//
#define CHAR_UP_ARROW          0x79
#define CHAR_DOWN_ARROW        0x7A
#define CHAR_LEFT_ARROW        0x7B
#define CHAR_RIGHT_ARROW       0x7C
//
#define CHAR_SUPER_E           0x84
#define CHAR_LESS_THAN         0x85
#define CHAR_GREATER_THAN      0x86
//
#define CHAR_SUPER_RE          0xA0
#define CHAR_0                 0xA1
#define CHAR_1                 0xA2
#define CHAR_2                 0xA3
#define CHAR_3                 0xA4
#define CHAR_4                 0xA5
#define CHAR_5                 0xA6
#define CHAR_6                 0xA7
#define CHAR_7                 0xA8
#define CHAR_8                 0xA9
#define CHAR_9                 0xAA
#define CHAR_EXCL_MARK         0xAB
#define CHAR_QUESTION_MARK     0xAC
#define CHAR_PERIOD            0xAD
#define CHAR_HYPHEN            0xAE
#define CHAR_BULLET            0xAF
#define CHAR_ELLIPSIS          0xB0
#define CHAR_DBL_QUOT_LEFT     0xB1
#define CHAR_DBL_QUOT_RIGHT    0xB2
#define CHAR_SGL_QUOT_LEFT     0xB3
#define CHAR_SGL_QUOT_RIGHT    0xB4
#define CHAR_MALE              0xB5
#define CHAR_FEMALE            0xB6
#define CHAR_CURRENCY          0xB7
#define CHAR_COMMA             0xB8
#define CHAR_MULT_SIGN         0xB9
#define CHAR_SLASH             0xBA
#define CHAR_A                 0xBB
#define CHAR_B                 0xBC
#define CHAR_C                 0xBD
#define CHAR_D                 0xBE
#define CHAR_E                 0xBF
#define CHAR_F                 0xC0
#define CHAR_G                 0xC1
#define CHAR_H                 0xC2
#define CHAR_I                 0xC3
#define CHAR_J                 0xC4
#define CHAR_K                 0xC5
#define CHAR_L                 0xC6
#define CHAR_M                 0xC7
#define CHAR_N                 0xC8
#define CHAR_O                 0xC9
#define CHAR_P                 0xCA
#define CHAR_Q                 0xCB
#define CHAR_R                 0xCC
#define CHAR_S                 0xCD
#define CHAR_T                 0xCE
#define CHAR_U                 0xCF
#define CHAR_V                 0xD0
#define CHAR_W                 0xD1
#define CHAR_X                 0xD2
#define CHAR_Y                 0xD3
#define CHAR_Z                 0xD4
#define CHAR_a                 0xD5
#define CHAR_b                 0xD6
#define CHAR_c                 0xD7
#define CHAR_d                 0xD8
#define CHAR_e                 0xD9
#define CHAR_f                 0xDA
#define CHAR_g                 0xDB
#define CHAR_h                 0xDC
#define CHAR_i                 0xDD
#define CHAR_j                 0xDE
#define CHAR_k                 0xDF
#define CHAR_l                 0xE0
#define CHAR_m                 0xE1
#define CHAR_n                 0xE2
#define CHAR_o                 0xE3
#define CHAR_p                 0xE4
#define CHAR_q                 0xE5
#define CHAR_r                 0xE6
#define CHAR_s                 0xE7
#define CHAR_t                 0xE8
#define CHAR_u                 0xE9
#define CHAR_v                 0xEA
#define CHAR_w                 0xEB
#define CHAR_x                 0xEC
#define CHAR_y                 0xED
#define CHAR_z                 0xEE
#define CHAR_BLACK_TRIANGLE    0xEF
#define CHAR_COLON             0xF0
#define CHAR_A_DIAERESIS       0xF1
#define CHAR_O_DIAERESIS       0xF2
#define CHAR_U_DIAERESIS       0xF3
#define CHAR_a_DIAERESIS       0xF4
#define CHAR_o_DIAERESIS       0xF5
#define CHAR_u_DIAERESIS       0xF6
#define CHAR_DYNAMIC           0xF7
#define CHAR_KEYPAD_ICON       0xF8
#define CHAR_EXTRA_SYMBOL      0xF9
#define CHAR_PROMPT_SCROLL     0xFA // waits for button press and scrolls dialog
#define CHAR_PROMPT_CLEAR      0xFB // waits for button press and clears dialog
#define EXT_CTRL_CODE_BEGIN    0xFC // extended control code
#define PLACEHOLDER_BEGIN      0xFD // string placeholder
#define CHAR_NEWLINE           0xFE
#define EOS                    0xFF // end of string

// CHAR_KEYPAD_ICON chars
#define CHAR_A_BUTTON       0x00
#define CHAR_B_BUTTON       0x01
#define CHAR_L_BUTTON       0x02
#define CHAR_R_BUTTON       0x03
#define CHAR_START_BUTTON   0x04
#define CHAR_SELECT_BUTTON  0x05
#define CHAR_DPAD_UP        0x06
#define CHAR_DPAD_DOWN      0x07
#define CHAR_DPAD_LEFT      0x08
#define CHAR_DPAD_RIGHT     0x09
#define CHAR_DPAD_UPDOWN    0x0A
#define CHAR_DPAD_LEFTRIGHT 0x0B
#define CHAR_DPAD_NONE      0x0C

// CHAR_EXTRA_SYMBOL chars
#define CHAR_UP_ARROW_2    0x00
#define CHAR_DOWN_ARROW_2  0x01
#define CHAR_LEFT_ARROW_2  0x02
#define CHAR_RIGHT_ARROW_2 0x03
#define CHAR_PLUS_2        0x04
#define CHAR_LV_2          0x05
#define CHAR_PP            0x06
#define CHAR_ID            0x07
#define CHAR_NO            0x08
#define CHAR_UNDERSCORE    0x09

#define EXT_CTRL_CODE_COLOR                  0x01
#define EXT_CTRL_CODE_HIGHLIGHT              0x02
#define EXT_CTRL_CODE_SHADOW                 0x03
#define EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW 0x04
#define EXT_CTRL_CODE_PALETTE                0x05
#define EXT_CTRL_CODE_SIZE                   0x06
#define EXT_CTRL_CODE_RESET_SIZE             0x07
#define EXT_CTRL_CODE_PAUSE                  0x08
#define EXT_CTRL_CODE_PAUSE_UNTIL_PRESS      0x09
#define EXT_CTRL_CODE_WAIT_SE                0x0A
#define EXT_CTRL_CODE_PLAY_BGM               0x0B
#define EXT_CTRL_CODE_ESCAPE                 0x0C
#define EXT_CTRL_CODE_SHIFT_TEXT             0x0D
#define EXT_CTRL_CODE_SHIFT_DOWN             0x0E
#define EXT_CTRL_CODE_FILL_WINDOW            0x0F
#define EXT_CTRL_CODE_PLAY_SE                0x10
#define EXT_CTRL_CODE_CLEAR                  0x11
#define EXT_CTRL_CODE_SKIP                   0x12
#define EXT_CTRL_CODE_CLEAR_TO               0x13
#define EXT_CTRL_CODE_MIN_LETTER_SPACING     0x14
#define EXT_CTRL_CODE_JPN                    0x15
#define EXT_CTRL_CODE_ENG                    0x16
#define EXT_CTRL_CODE_PAUSE_MUSIC            0x17
#define EXT_CTRL_CODE_RESUME_MUSIC           0x18

#define TEXT_COLOR_TRANSPARENT  0x0
#define TEXT_COLOR_WHITE        0x1
#define TEXT_COLOR_DARK_GREY    0x2
#define TEXT_COLOR_LIGHT_GREY   0x3
#define TEXT_COLOR_RED          0x4
#define TEXT_COLOR_LIGHT_RED    0x5
#define TEXT_COLOR_GREEN        0x6
#define TEXT_COLOR_LIGHT_GREEN  0x7
#define TEXT_COLOR_BLUE         0x8
#define TEXT_COLOR_LIGHT_BLUE   0x9
#define TEXT_DYNAMIC_COLOR_1    0xA // Usually white
#define TEXT_DYNAMIC_COLOR_2    0xB // Usually white w/ tinge of green
#define TEXT_DYNAMIC_COLOR_3    0xC // Usually white
#define TEXT_DYNAMIC_COLOR_4    0xD // Usually aquamarine
#define TEXT_DYNAMIC_COLOR_5    0xE // Usually blue-green
#define TEXT_DYNAMIC_COLOR_6    0xF // Usually cerulean

#define PLACEHOLDER_ID_UNKNOWN       0x0
#define PLACEHOLDER_ID_PLAYER        0x1
#define PLACEHOLDER_ID_STRING_VAR_1  0x2
#define PLACEHOLDER_ID_STRING_VAR_2  0x3
#define PLACEHOLDER_ID_STRING_VAR_3  0x4
#define PLACEHOLDER_ID_KUN           0x5
#define PLACEHOLDER_ID_RIVAL         0x6
#define PLACEHOLDER_ID_VERSION       0x7
#define PLACEHOLDER_ID_AQUA          0x8
#define PLACEHOLDER_ID_MAGMA         0x9
#define PLACEHOLDER_ID_ARCHIE        0xA 
#define PLACEHOLDER_ID_MAXIE         0xB
#define PLACEHOLDER_ID_KYOGRE        0xC
#define PLACEHOLDER_ID_GROUDON       0xD

// battle placeholders are located in battle_message.h

#define NUM_TEXT_PRINTERS 32

#define TEXT_SPEED_FF 0xFF

enum
{
    FONTATTR_MAX_LETTER_WIDTH,
    FONTATTR_MAX_LETTER_HEIGHT,
    FONTATTR_LETTER_SPACING,
    FONTATTR_LINE_SPACING,
    FONTATTR_UNKNOWN,   // dunno what this is yet
    FONTATTR_COLOR_FOREGROUND,
    FONTATTR_COLOR_BACKGROUND,
    FONTATTR_COLOR_SHADOW
};

struct TextPrinterSubStruct
{
    u8 glyphId:4;  // 0x14
    bool8 hasPrintBeenSpedUp:1;
    u8 unk:3;
    u8 downArrowDelay:5;
    u8 downArrowYPosIdx:2;
    bool8 hasGlyphIdBeenSet:1;
    u8 autoScrollDelay;
};

struct TextPrinterTemplate
{
    const u8* currentChar;
    u8 windowId;
    u8 fontId;
    u8 x;
    u8 y;
    u8 currentX;        // 0x8
    u8 currentY;
    u8 letterSpacing;
    u8 lineSpacing;
    u8 unk:4;   // 0xC
    u8 fgColor:4;
    u8 bgColor:4;
    u8 shadowColor:4;
};

struct TextPrinter
{
    struct TextPrinterTemplate printerTemplate;

    void (*callback)(struct TextPrinterTemplate *, u16); // 0x10

    u8 subStructFields[7]; // always cast to struct TextPrinterSubStruct... so why bother
    u8 active;
    u8 state;       // 0x1C
    u8 textSpeed;
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
    u8 unk:4;
    u8 fgColor:4;
    u8 bgColor:4;
    u8 shadowColor:4;
};

extern const struct FontInfo *gFonts;

struct GlyphWidthFunc
{
    u32 fontId;
    u32 (*func)(u16 glyphId, bool32 isJapanese);
};

struct KeypadIcon
{
    u16 tileOffset;
    u8 width;
    u8 height;
};

typedef struct {
    bool8 canABSpeedUpPrint:1;
    bool8 useAlternateDownArrow:1;
    bool8 autoScroll:1;
    bool8 forceMidTextSpeed:1;
} TextFlags;

struct Struct_03002F90
{
    u32 unk0[8];
    u32 unk20[8];
    u32 unk40[8];
    u32 unk60[8];
    u8 width;
    u8 height;
};

extern TextFlags gTextFlags;

extern u8 gUnknown_03002F84;
extern struct Struct_03002F90 gUnknown_03002F90;

void SetFontsPointer(const struct FontInfo *fonts);
void DeactivateAllTextPrinters(void);
u16 AddTextPrinterParameterized(u8 windowId, u8 fontId, const u8 *str, u8 x, u8 y, u8 speed, void (*callback)(struct TextPrinterTemplate *, u16));
bool16 AddTextPrinter(struct TextPrinterTemplate *template, u8 speed, void (*callback)(struct TextPrinterTemplate *, u16));
void RunTextPrinters(void);
bool16 IsTextPrinterActive(u8 id);
u32 RenderFont(struct TextPrinter *textPrinter);
void GenerateFontHalfRowLookupTable(u8 fgColor, u8 bgColor, u8 shadowColor);
void SaveTextColors(u8 *fgColor, u8 *bgColor, u8 *shadowColor);
void RestoreTextColors(u8 *fgColor, u8 *bgColor, u8 *shadowColor);
void DecompressGlyphTile(const void *src_, void *dest_);
u8 GetLastTextColor(u8 colorType);
void CopyGlyphToWindow(struct TextPrinter *x);
void ClearTextSpan(struct TextPrinter *textPrinter, u32 width);
u8 GetMenuCursorDimensionByFont(u8, u8);

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
s32 GetStringWidth(u8 fontId, const u8 *str, s16 letterSpacing);
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

// unk_text_util_2.c
u16 Font6Func(struct TextPrinter *textPrinter);
u32 GetGlyphWidthFont6(u16 glyphId, bool32 isJapanese);

#endif // GUARD_TEXT_H
