#include "global.h"
#include "string_util.h"
#include "event_data.h"
#include "naming_screen.h"
#include "main.h"
#include "text.h"
#include "new_game.h"

extern void (*gFieldCallback)(void);

extern const u8 gText_Peekaboo[];

extern u8 *GetWaldaPhrasePtr(void);
extern bool32 IsWaldaPhraseEmpty(void);
extern void sub_80AF168(void);
extern void c2_exit_to_overworld_2_switch(void);
extern void SetWaldaPhrase(const u8 *src);
extern void SetWaldaWallpaperPatternId(u8 patternId);
extern void SetWaldaWallpaperIconId(u8 iconId);
extern void SetWaldaWallpaperColors(u16 backgroundColor, u16 foregroundColor);
extern void SetWaldaWallpaperLockedOrUnlocked(bool32 unlocked);

// this file's functions
void CB2_HandleGivenWaldaPhrase(void);
u32 GetWaldaPhraseInputCase(u8 *inputPtr);
bool32 TryCalculateWallpaper(u16* backgroundClr, u16 *foregroundClr, u8 *iconId, u8 *patternId, u16 trainerId, u8 *phrase);
void sub_81D9D5C(u8 *array, u8 *letterTableIds, s32 arg2, s32 arg3, s32 arg4);
s32 sub_81D9DAC(u8 *array, s32 arg1, s32 arg2);
void sub_81D9C90(u8 *array, s32 arg1, s32 arg2);
void sub_81D9CDC(u8 *array, s32 arg1, u8 arg2);

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

void DoWaldaNamingScreen(void)
{
    StringCopy(gStringVar2, GetWaldaPhrasePtr());
    DoNamingScreen(NAMING_SCREEN_WALDA, gStringVar2, 0, 0, 0, CB2_HandleGivenWaldaPhrase);
}

void CB2_HandleGivenWaldaPhrase(void)
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
    gFieldCallback = sub_80AF168;
    SetMainCallback2(c2_exit_to_overworld_2_switch);
}

u32 GetWaldaPhraseInputCase(u8 *inputPtr)
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
    u16 trainerId = ReadUnalignedWord(gSaveBlock2Ptr->playerTrainerId);
    gScriptResult = TryCalculateWallpaper(&backgroundClr, &foregroundClr, &iconId, &patternId, trainerId, GetWaldaPhrasePtr());

    if (gScriptResult)
    {
        SetWaldaWallpaperPatternId(patternId);
        SetWaldaWallpaperIconId(iconId);
        SetWaldaWallpaperColors(backgroundClr, foregroundClr);
    }

    SetWaldaWallpaperLockedOrUnlocked(gScriptResult);
    return (bool8)(gScriptResult);
}

u8 GetLetterTableId(u8 letter)
{
    s32 i;

    for (i = 0; i < ARRAY_COUNT(sWaldaLettersTable); i++)
    {
        if (sWaldaLettersTable[i] == letter)
            return i;
    }

    return ARRAY_COUNT(sWaldaLettersTable);
}

bool32 TryCalculateWallpaper(u16* backgroundClr, u16 *foregroundClr, u8 *iconId, u8 *patternId, u16 trainerId, u8 *phrase)
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

void sub_81D9C90(u8 *array, s32 arg1, s32 arg2)
{
    s32 i, j;
    u8 var1, var2;

    for (i = arg2 - 1; i != -1; i--)
    {
        var1 = (array[0] & 0x80) >> 7;

        var1++;var1--; // needed to match

        for (j = arg1 - 1; j >= 0; j--)
        {
            var2 = array[j] & 0x80;
            array[j] <<= 1;
            array[j] |= var1;
            var1 = var2 >> 7;
        }
    }
}
