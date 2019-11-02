#include "global.h"
#include "text.h"
#include "korean.h"
#include "korean_table.h"

u8 CheckKoreanGlyph(u16 glyph)
{
    return glyph >= 0x37 && glyph <= 0x41;
}

u8 CheckJaum(u8 glyph)
{
    return glyph >= 0x01 && glyph <= 0x13;
}

u8 CheckMoum(u8 glyph)
{
    return !CheckJaum(glyph);
}

u8 GetCho(u8 index)
{
    return index - 1;
}

u8 GetJung(u8 index)
{
    return index - 0x14;
}

u8 GetJong(u8 index)
{
    u8 i = 0;
    s8 ch;

    while ((ch = gConvertJongToChoTable[i]) != -1)
    {
        if (ch == index)
            return i;
        i++;
    }

    // 예외처리
    return -1;
}

u16 ConvertKoreanToUnicode(u16 korean)
{
    return gConvertKoreanToUnicodeTable[korean - 0x3700];
}

u16 ConvertUnicodeToKorean(u16 code)
{
    return gConvertUnicodeToKoreanTable[code];
}

u8 ConvertToCho(u16 korean)
{
    u16 code = gConvertKoreanToUnicodeTable[korean - 0x3700];
    return ((code / 28) / 21) + 0x01;
}

u8 ConvertJongToCho(u8 jong)
{
    return gConvertJongToChoTable[jong];
}

u8 ConvertToJung(u16 korean)
{
    u16 code = gConvertKoreanToUnicodeTable[korean - 0x3700];
    return ((code / 28) % 21) + 0x14;
}

u8 ConvertToJong(u16 korean)
{
    return gConvertJongToChoTable[gConvertKoreanToUnicodeTable[korean - 0x3700] % 28];
}

u8 ConvertToJongIndex(u16 korean)
{
    return gConvertKoreanToUnicodeTable[korean - 0x3700] % 28;
}

u16 GetKorean(u8 cho, u8 jung, u8 jong)
{    
    return (((cho * 21) + jung) * 28) + jong;
}

u8 MergeJaum(u8 ch, u8 ch2)
{
    switch (ch)
    {
    // ㄱ
    case 0x01:
        // ㅅ
        if (ch2 == 0x0A)
            return 3;
        break;
    // ㄴ
    case 0x03:
        switch (ch2)
        {
        // ㅈ
        case 0x0D:
            return 5;
        // ㅎ
        case 0x13:
            return 6;
        }
        break;
    // ㄹ
    case 0x06:
        switch (ch2)
        {
        // ㄱ
        case 0x01:
            return 9;
        // ㅁ
        case 0x07:
            return 10;
        // ㅂ
        case 0x08:
            return 11;
        // ㅅ
        case 0x0A:
            return 12;
        // ㅌ
        case 0x11:
            return 13;
        // ㅍ
        case 0x12:
            return 14;
        // ㅎ
        case 0x13:
            return 15;
        }
        break;
    // ㅂ
    case 0x08:
        if (ch2 == 0x0A)
            return 18;
        break;
    } // end switch

    // 조합불가
    return 0;
}

u8 MergeMoum(u8 ch, u8 ch2)
{
    switch (ch)
    {
    // ㅗ
    case 0x1C:
        switch (ch2)
        {
        // ㅏ
        case 0x14:
            return 0x1D;
        // ㅐ
        case 0x15:
            return 0x1E;
        // ㅣ
        case 0x28:
            return 0x1F;
        }
        break;

    // ㅜ
    case 0x21:
        switch (ch2)
        {
        // ㅓ
        case 0x18:
            return 0x22;
        // ㅔ
        case 0x19:
            return 0x23;
        // ㅣ
        case 0x28:
            return 0x24;
        }
        break;

    // ㅡ
    case 0x26:
        // ㅣ
        if (ch2 == 0x28)
            return 0x27;
        break;
    }

    // 조합불가
    return 0;
}

u8 SplitJong(u8 ch, u8 index)
{
    if (index == 0)
    {
        if (ch == 3)
        {
            return 1;
        }
        else if (ch >= 5 && ch <= 6)
        {
            return 4;
        }
        else if (ch >= 9 && ch <= 15)
        {
            return 8;
        }
        else if (ch == 18)
        {
            return 17;
        }
    }
    else
    {
        switch (ch)
        {
        // ㄳ
        case 3:
            return 19;
        // ㄵ
        case 5:
            return 22;
        // ㄶ
        case 6:
            return 27;
        // ㄺ
        case 9:
            return 1;
        // ㄻ
        case 10:
            return 16;
        // ㄼ
        case 11:
            return 17;
        // ㄽ
        case 12:
            return 19;
        // ㄾ
        case 13:
            return 25;
        // ㄿ
        case 14:
            return 26;
        // ㅀ
        case 15:
            return 27;
        // ㅄ
        case 18:
            return 19;
        }
    }

    return 0;
}

bool8 CheckHasJongSeong(u16 ch)
{
    if (CheckKoreanGlyph((ch & 0xff00) >> 8))
    {
        // 한글 종성유무 체크
        return gConvertKoreanToUnicodeTable[ch - 0x3700] % 28;
    }
    else
    {
        // 다른 경우는 종성이 아닌걸로 처리
        return FALSE;
    }
}

u16 GetKoreanChar(struct TextPrinter *textPrinter, u16 currChar)
{
    if (CheckKoreanGlyph(currChar))
    {
        // 현재 바이트와 다음 바이트와 조합
        u16 newChar = (currChar << 8) | *textPrinter->printerTemplate.currentChar;
        textPrinter->printerTemplate.currentChar++;
        return newChar;
    }
    else
    {
        // 한글 바이트가 아닐경우 기존 글자로 반환
        return currChar;
    }
}
