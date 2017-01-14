#include "global.h"
#include "string_util.h"
#include "text.h"

#define MAX_PLACEHOLDER_ID 0xD

extern const u8 sDigits[];
extern const s32 sPowersOfTen[];
extern const u8 sSetBrailleFont[];
extern const u8 sGotoLine2[];

typedef u8 *(*ExpandPlaceholderFunc)(void);

extern const ExpandPlaceholderFunc sExpandPlaceholderFuncs[];

extern u8 gUnknownStringVar[];
extern u8 gStringVar1[];
extern u8 gStringVar2[];
extern u8 gStringVar3[];
extern u8 gStringVar4[];

extern u8 gExpandedPlaceholder_Empty[];
extern u8 gExpandedPlaceholder_Kun[];
extern u8 gExpandedPlaceholder_Chan[];
extern u8 gExpandedPlaceholder_Sapphire[];
extern u8 gExpandedPlaceholder_Ruby[];
extern u8 gExpandedPlaceholder_Emerald[];
extern u8 gExpandedPlaceholder_Aqua[];
extern u8 gExpandedPlaceholder_Magma[];
extern u8 gExpandedPlaceholder_Archie[];
extern u8 gExpandedPlaceholder_Maxie[];
extern u8 gExpandedPlaceholder_Kyogre[];
extern u8 gExpandedPlaceholder_Groudon[];
extern u8 gExpandedPlaceholder_Brendan[];
extern u8 gExpandedPlaceholder_May[];

u8 *StringCopy10(u8 *dest, const u8 *src)
{
    u8 i;
    u32 limit = 10;

    for (i = 0; i < limit; i++)
    {
        dest[i] = src[i];

        if (dest[i] == EOS)
            return &dest[i];
    }

    dest[i] = EOS;
    return &dest[i];
}

u8 *StringGetEnd10(u8 *str)
{
    u8 i;
    u32 limit = 10;

    for (i = 0; i < limit; i++)
        if (str[i] == EOS)
            return &str[i];

    str[i] = EOS;
    return &str[i];
}

u8 *StringCopy7(u8 *dest, const u8 *src)
{
    s32 i;
    s32 limit = 7;

    for (i = 0; i < limit; i++)
    {
        dest[i] = src[i];

        if (dest[i] == EOS)
            return &dest[i];
    }

    dest[i] = EOS;
    return &dest[i];
}

u8 *StringCopy(u8 *dest, const u8 *src)
{
    while (*src != EOS)
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = EOS;
    return dest;
}

u8 *StringAppend(u8 *dest, const u8 *src)
{
    while (*dest != EOS)
        dest++;

    return StringCopy(dest, src);
}

u8 *StringCopyN(u8 *dest, const u8 *src, u8 n)
{
    u16 i;

    for (i = 0; i < n; i++)
        dest[i] = src[i];

    return &dest[n];
}

u8 *StringAppendN(u8 *dest, const u8 *src, u8 n)
{
    while (*dest != EOS)
        dest++;

    return StringCopyN(dest, src, n);
}

u16 StringLength(const u8 *str)
{
    u16 length = 0;

    while (str[length] != EOS)
        length++;

    return length;
}

s32 StringCompare(const u8 *str1, const u8 *str2)
{
    while (*str1 == *str2)
    {
        if (*str1 == EOS)
            return 0;
        str1++;
        str2++;
    }

    return *str1 - *str2;
}

s32 StringCompareN(const u8 *str1, const u8 *str2, u32 n)
{
    while (*str1 == *str2)
    {
        if (*str1 == EOS)
            return 0;
        str1++;
        str2++;
        if (--n == 0)
            return 0;
    }

    return *str1 - *str2;
}

bool8 IsStringLengthAtLeast(const u8 *str, s32 n)
{
    u8 i;

    for (i = 0; i < n; i++)
        if (str[i] && str[i] != EOS)
            return TRUE;

    return FALSE;
}

u8 *ConvertIntToDecimalStringN(u8 *dest, s32 value, enum StringConvertMode mode, u8 n)
{
    enum { WAITING_FOR_NONZERO_DIGIT, WRITING_DIGITS, WRITING_SPACES } state;
    s32 powerOfTen;
    s32 largestPowerOfTen = sPowersOfTen[n - 1];

    state = WAITING_FOR_NONZERO_DIGIT;

    if (mode == STR_CONV_MODE_RIGHT_ALIGN)
        state = WRITING_SPACES;

    if (mode == STR_CONV_MODE_LEADING_ZEROS)
        state = WRITING_DIGITS;

    for (powerOfTen = largestPowerOfTen; powerOfTen > 0; powerOfTen /= 10)
    {
        u8 c;
        u16 digit = value / powerOfTen;
        s32 temp = value - (powerOfTen * digit);

        if (state == WRITING_DIGITS)
        {
            u8 *out = dest++;

            if (digit <= 9)
                c = sDigits[digit];
            else
                c = CHAR_QUESTION_MARK;

            *out = c;
        }
        else if (digit != 0 || powerOfTen == 1)
        {
            u8 *out;
            state = WRITING_DIGITS;
            out = dest++;

            if (digit <= 9)
                c = sDigits[digit];
            else
                c = CHAR_QUESTION_MARK;

            *out = c;
        }
        else if (state == WRITING_SPACES)
        {
            *dest++ = 0x77;
        }

        value = temp;
    }

    *dest = EOS;
    return dest;
}

u8 *ConvertUIntToDecimalStringN(u8 *dest, u32 value, enum StringConvertMode mode, u8 n)
{
    enum { WAITING_FOR_NONZERO_DIGIT, WRITING_DIGITS, WRITING_SPACES } state;
    s32 powerOfTen;
    s32 largestPowerOfTen = sPowersOfTen[n - 1];

    state = WAITING_FOR_NONZERO_DIGIT;

    if (mode == STR_CONV_MODE_RIGHT_ALIGN)
        state = WRITING_SPACES;

    if (mode == STR_CONV_MODE_LEADING_ZEROS)
        state = WRITING_DIGITS;

    for (powerOfTen = largestPowerOfTen; powerOfTen > 0; powerOfTen /= 10)
    {
        u8 c;
        u16 digit = value / powerOfTen;
        u32 temp = value - (powerOfTen * digit);

        if (state == WRITING_DIGITS)
        {
            u8 *out = dest++;

            if (digit <= 9)
                c = sDigits[digit];
            else
                c = CHAR_QUESTION_MARK;

            *out = c;
        }
        else if (digit != 0 || powerOfTen == 1)
        {
            u8 *out;
            state = WRITING_DIGITS;
            out = dest++;

            if (digit <= 9)
                c = sDigits[digit];
            else
                c = CHAR_QUESTION_MARK;

            *out = c;
        }
        else if (state == WRITING_SPACES)
        {
            *dest++ = 0x77;
        }

        value = temp;
    }

    *dest = EOS;
    return dest;
}

u8 *ConvertIntToHexStringN(u8 *dest, s32 value, enum StringConvertMode mode, u8 n)
{
    enum { WAITING_FOR_NONZERO_DIGIT, WRITING_DIGITS, WRITING_SPACES } state;
    u8 i;
    s32 powerOfSixteen;
    s32 largestPowerOfSixteen = 1;

    for (i = 1; i < n; i++)
        largestPowerOfSixteen *= 16;

    state = WAITING_FOR_NONZERO_DIGIT;

    if (mode == STR_CONV_MODE_RIGHT_ALIGN)
        state = WRITING_SPACES;

    if (mode == STR_CONV_MODE_LEADING_ZEROS)
        state = WRITING_DIGITS;

    for (powerOfSixteen = largestPowerOfSixteen; powerOfSixteen > 0; powerOfSixteen /= 16)
    {
        u8 c;
        u32 digit = value / powerOfSixteen;
        s32 temp = value % powerOfSixteen;

        if (state == WRITING_DIGITS)
        {
            char *out = dest++;

            if (digit <= 0xF)
                c = sDigits[digit];
            else
                c = CHAR_QUESTION_MARK;

            *out = c;
        }
        else if (digit != 0 || powerOfSixteen == 1)
        {
            char *out;
            state = WRITING_DIGITS;
            out = dest++;

            if (digit <= 0xF)
                c = sDigits[digit];
            else
                c = CHAR_QUESTION_MARK;

            *out = c;
        }
        else if (state == WRITING_SPACES)
        {
            *dest++ = 0x77;
        }

        value = temp;
    }

    *dest = EOS;
    return dest;
}

u8 *StringExpandPlaceholders(u8 *dest, const u8 *src)
{
    for (;;)
    {
        u8 c = *src++;
        u8 placeholderId;
        u8 *expandedString;

        switch (c)
        {
        case PLACEHOLDER_BEGIN:
            placeholderId = *src++;
            expandedString = GetExpandedPlaceholder(placeholderId);
            dest = StringExpandPlaceholders(dest, expandedString);
            break;
        case EXT_CTRL_CODE_BEGIN:
            *dest++ = c;
            c = *src++;
            *dest++ = c;

            switch (c)
            {
            case 0x07:
            case 0x09:
            case 0x0F:
            case 0x15:
            case 0x16:
            case 0x17:
            case 0x18:
                break;
            case 0x04:
                *dest++ = *src++;
            case 0x0B:
                *dest++ = *src++;
            default:
                *dest++ = *src++;
            }
            break;
        case EOS:
            *dest = EOS;
            return dest;
        case 0xFA:
        case 0xFB:
        case 0xFE:
        default:
            *dest++ = c;
        }
    }
}

u8 *StringBraille(u8 *dest, const u8 *src)
{
    u8 setBrailleFont[4];
    u8 gotoLine2[5];

    memcpy(setBrailleFont, sSetBrailleFont, 4);
    memcpy(gotoLine2, sGotoLine2, 5);

    dest = StringCopy(dest, setBrailleFont);

    for (;;)
    {
        u8 c = *src++;

        switch (c)
        {
        case EOS:
            *dest = c;
            return dest;
        case 0xFE:
            dest = StringCopy(dest, gotoLine2);
            break;
        default:
            *dest++ = c;
            *dest++ = c + 0x40;
            break;
        }
    }
}

u8 *ExpandPlaceholder_UnknownStringVar(void)
{
    return gUnknownStringVar;
}

u8 *ExpandPlaceholder_PlayerName(void)
{
    return gSaveBlock2Ptr->playerName;
}

u8 *ExpandPlaceholder_StringVar1(void)
{
    return gStringVar1;
}

u8 *ExpandPlaceholder_StringVar2(void)
{
    return gStringVar2;
}

u8 *ExpandPlaceholder_StringVar3(void)
{
    return gStringVar3;
}

u8 *ExpandPlaceholder_KunChan(void)
{
    if (gSaveBlock2Ptr->playerGender == MALE)
        return gExpandedPlaceholder_Kun;
    else
        return gExpandedPlaceholder_Chan;
}

u8 *ExpandPlaceholder_RivalName(void)
{
    if (gSaveBlock2Ptr->playerGender == MALE)
        return gExpandedPlaceholder_May;
    else
        return gExpandedPlaceholder_Brendan;
}

u8 *ExpandPlaceholder_Version(void)
{
    return gExpandedPlaceholder_Emerald;
}

u8 *ExpandPlaceholder_Aqua(void)
{
    return gExpandedPlaceholder_Aqua;
}

u8 *ExpandPlaceholder_Magma(void)
{
    return gExpandedPlaceholder_Magma;
}

u8 *ExpandPlaceholder_Archie(void)
{
    return gExpandedPlaceholder_Archie;
}

u8 *ExpandPlaceholder_Maxie(void)
{
    return gExpandedPlaceholder_Maxie;
}

u8 *ExpandPlaceholder_Kyogre(void)
{
    return gExpandedPlaceholder_Kyogre;
}

u8 *ExpandPlaceholder_Groudon(void)
{
    return gExpandedPlaceholder_Groudon;
}

u8 *GetExpandedPlaceholder(u32 id)
{
    if (id > MAX_PLACEHOLDER_ID)
        return gExpandedPlaceholder_Empty;
    else
        return sExpandPlaceholderFuncs[id]();
}

u8 *StringFill(u8 *dest, u8 c, u16 n)
{
    u16 i;

    for (i = 0; i < n; i++)
        *dest++ = c;

    *dest = EOS;
    return dest;
}

u8 *StringCopyPadded(u8 *dest, const u8 *src, u8 c, u16 n)
{
    while (*src != EOS)
    {
        *dest++ = *src++;

        if (n)
            n--;
    }

    n--;

    while (n != (u16)-1)
    {
        *dest++ = c;
        n--;
    }

    *dest = EOS;
    return dest;
}

u8 *StringFillWithTerminator(u8 *dest, u16 n)
{
    return StringFill(dest, EOS, n);
}
