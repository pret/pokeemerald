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

struct TextWindow {
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
};

struct TextPrinter
{
    struct TextWindow window;
    
    void (*callback)(u16, struct TextWindow *); // 0x10
    
    union {
        struct
        {
            u8 field_0; // 0x14
            u8 field_1;
            u8 field_2;
            u8 field_3;
            u8 field_4; // 0x18
            u8 field_5;
            u8 field_6;
            u8 field_7;
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

#endif // GUARD_TEXT_H
