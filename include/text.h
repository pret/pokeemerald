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
#define NUM_WINDOWS 20

struct Window
{
    u8 priority;
    u8 tilemapLeft;
    u8 tilemapTop;
    u8 width;
    u8 height;
    u8 paletteNum;
    u16 baseBlock;
    u8 *tileData;
};

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

struct Bitmap           // TODO: Find a better spot for this
{
    u8* pixels;
    u32 width:16;
    u32 height:16;
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

#endif // GUARD_TEXT_H
