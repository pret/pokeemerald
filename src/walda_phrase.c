#include "global.h"
#include "walda_phrase.h"
#include "string_util.h"
#include "event_data.h"
#include "naming_screen.h"
#include "main.h"
#include "text.h"
#include "new_game.h"
#include "overworld.h"
#include "pokemon_storage_system.h"
#include "field_screen_effect.h"

extern const u8 gText_Peekaboo[];

// this file's functions
static void CB2_HandleGivenWaldaPhrase(void);
static u32 GetWaldaPhraseInputCase(u8 *inputPtr);
static bool32 TryCalculateWallpaper(u16* backgroundClr, u16 *foregroundClr, u8 *iconId, u8 *patternId, u16 trainerId, u8 *phrase);
static void sub_81D9D5C(u8 *array, u8 *letterTableIds, u32 arg2, u32 arg3, u32 loopCount);
static u32 sub_81D9DAC(u8 *array, u32 arg1, u32 loopCount);
static void sub_81D9C90(u8 *array, s32 arg1, s32 arg2);
static void sub_81D9CDC(u8 *array, u32 loopCount, u8 arg2);

// only consonants are allowed, no vowels, some lowercase letters are missing
static const u8 sWaldaLettersTable[] =
{
    CHAR_B, CHAR_C, CHAR_D, CHAR_F, CHAR_G, CHAR_H, CHAR_J, CHAR_K, CHAR_L, CHAR_M, CHAR_N, CHAR_P, CHAR_Q, CHAR_R, CHAR_S, CHAR_T, CHAR_V, CHAR_W, CHAR_Z,
    CHAR_b, CHAR_c, CHAR_d, CHAR_f, CHAR_g, CHAR_h, CHAR_j, CHAR_k,         CHAR_m, CHAR_n, CHAR_p, CHAR_q,         CHAR_s
};

enum
{
    PHRASE_GIVEN_NEW,
    PHRASE_NO_CHANGE,
    PHRASE_FIRST_ATTEMPT
};

u16 TryBufferWaldaPhrase(void)
{
    if (IsWaldaPhraseEmpty())
        return FALSE;

    StringCopy(gStringVar1, GetWaldaPhrasePtr());
    return TRUE;
}

void DoWaldaNamingScreen(void)
{
    StringCopy(gStringVar2, GetWaldaPhrasePtr());
    DoNamingScreen(NAMING_SCREEN_WALDA, gStringVar2, 0, 0, 0, CB2_HandleGivenWaldaPhrase);
}

static void CB2_HandleGivenWaldaPhrase(void)
{
    gSpecialVar_0x8004 = GetWaldaPhraseInputCase(gStringVar2);

    switch (gSpecialVar_0x8004)
    {
    case PHRASE_FIRST_ATTEMPT:
        if (IsWaldaPhraseEmpty())
            SetWaldaPhrase(gText_Peekaboo);
        else
            gSpecialVar_0x8004 = PHRASE_NO_CHANGE;
        break;
    case PHRASE_GIVEN_NEW:
        SetWaldaPhrase(gStringVar2);
        break;
    case PHRASE_NO_CHANGE:
        break;
    }

    StringCopy(gStringVar1, GetWaldaPhrasePtr());
    gFieldCallback = FieldCB_ContinueScriptHandleMusic;
    SetMainCallback2(CB2_ReturnToField);
}

static u32 GetWaldaPhraseInputCase(u8 *inputPtr)
{
    if (inputPtr[0] == EOS)
        return PHRASE_FIRST_ATTEMPT;
    if (StringCompare(inputPtr, GetWaldaPhrasePtr()) == 0)
        return PHRASE_NO_CHANGE;

    return PHRASE_GIVEN_NEW;
}

u16 TryGetWallpaperWithWaldaPhrase(void)
{
    u16 backgroundClr, foregroundClr;
    u8 patternId, iconId;
    u16 trainerId = GetTrainerId(gSaveBlock2Ptr->playerTrainerId);
    gSpecialVar_Result = TryCalculateWallpaper(&backgroundClr, &foregroundClr, &iconId, &patternId, trainerId, GetWaldaPhrasePtr());

    if (gSpecialVar_Result)
    {
        SetWaldaWallpaperPatternId(patternId);
        SetWaldaWallpaperIconId(iconId);
        SetWaldaWallpaperColors(backgroundClr, foregroundClr);
    }

    SetWaldaWallpaperLockedOrUnlocked(gSpecialVar_Result);
    return (bool8)(gSpecialVar_Result);
}

static u8 GetLetterTableId(u8 letter)
{
    s32 i;

    for (i = 0; i < ARRAY_COUNT(sWaldaLettersTable); i++)
    {
        if (sWaldaLettersTable[i] == letter)
            return i;
    }

    return ARRAY_COUNT(sWaldaLettersTable);
}

static bool32 TryCalculateWallpaper(u16* backgroundClr, u16 *foregroundClr, u8 *iconId, u8 *patternId, u16 trainerId, u8 *phrase)
{
    s32 i;
    ALIGNED(2) u8 array[12];
    u8 charsByTableId[16];
    u16 *ptr;

    if (StringLength(phrase) != 15)
        return FALSE;

    for (i = 0; i < 15; i++)
    {
        charsByTableId[i] = GetLetterTableId(phrase[i]);
        if (charsByTableId[i] == ARRAY_COUNT(sWaldaLettersTable))
            return FALSE;
    }

    for (i = 0; i < 14; i++)
    {
        sub_81D9D5C(array, charsByTableId, (5 * i), 3 + (8 * i), 5);
    }

    sub_81D9D5C(array, charsByTableId, 70, 115, 2);

    if (sub_81D9DAC(array, 0, 3) != sub_81D9DAC(charsByTableId, 117, 3))
        return FALSE;

    sub_81D9C90(array, 9, 21);
    sub_81D9C90(array, 8, array[8] & 0xF);
    sub_81D9CDC(array, 8, array[8] >> 4);

    if (array[6] != (array[0] ^ array[2] ^ array[4] ^ (trainerId >> 8)))
        return FALSE;

    if (array[7] != (array[1] ^ array[3] ^ array[5] ^ (trainerId & 0xFF)))
        return FALSE;

    ptr = (u16*)(&array[0]);
    *backgroundClr = *ptr;

    ptr = (u16*)(&array[2]);
    *foregroundClr = *ptr;

    *iconId = array[4];
    *patternId = array[5];

    return TRUE;
}

static void sub_81D9C90(u8 *array, s32 arg1, s32 arg2)
{
    s32 i, j;
    u8 var1, var2;

    for (i = arg2 - 1; i != -1; i--)
    {
        var1 = (array[0] & 0x80) >> 7;

        for (j = arg1 - 1; j >= 0; j--)
        {
            var2 = (array[j] & 0x80) >> 7;
            array[j] <<= 1;
            array[j] |= var1;
            var1 = var2;
        }
    }
}

static void sub_81D9CDC(u8 *array, u32 loopCount, u8 arg2)
{
    u32 i;

    arg2 |= (arg2 << 4);

    for (i = 0; i < loopCount; i++)
    {
        array[i] ^= arg2;
    }
}

static bool8 sub_81D9D0C(u8 *array, u32 arg1)
{
    u32 arrayId = arg1 >> 3;
    u32 bits = 0x80 >> (7 & arg1);

    return ((array[arrayId] & bits) != 0);
}

static void sub_81D9D28(u8 *array, u32 arg1)
{
    u32 arrayId = arg1 >> 3;
    u8 bits = 0x80 >> (7 & arg1);

    array[arrayId] |= bits;
}

static void sub_81D9D40(u8 *array, u32 arg1)
{
    u32 arrayId = arg1 >> 3;
    u8 bits = ~(0x80 >> (7 & arg1));

    array[arrayId] &= bits;
}

static void sub_81D9D5C(u8 *array, u8 *letterTableIds, u32 arg2, u32 arg3, u32 loopCount)
{
    u32 i;

    for (i = 0; i < loopCount; i++)
    {
        if (sub_81D9D0C(letterTableIds, arg3 + i))
            sub_81D9D28(array, arg2 + i);
        else
            sub_81D9D40(array, arg2 + i);
    }
}

static u32 sub_81D9DAC(u8 *array, u32 arg1, u32 loopCount)
{
    u32 ret, i;

    for (ret = 0, i = 0; i < loopCount; i++)
    {
        ret <<= 1;
        ret |= sub_81D9D0C(array, arg1 + i);
    }

    return ret;
}
