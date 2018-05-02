#include "global.h"
#include "main.h"
#include "constants/easy_chat.h"
#include "mauville_old_man.h"
#include "event_data.h"
#include "string_util.h"
#include "text.h"
#include "easy_chat.h"
#include "script.h"
#include "random.h"
#include "event_scripts.h"

#define CHAR_SONG_WORD_SEPARATOR 0x37

void sub_8120E08(void); // StorytellerSetup
void sub_81339F8(void); // TraderSetup
void sub_8120B5C(void);
void sub_81206C0(u8 a0); // StartBardSong
void sub_81204DC(void);

static const u16 sDefaultBardSongLyrics[6] = {
    EC_WORD_SHAKE,
    EC_WORD_IT,
    EC_WORD_DO,
    EC_WORD_THE,
    EC_WORD_DIET,
    EC_WORD_DANCE
};

static const u8 * const sGiddyAdjectives[] = {
    gText_SoPretty,
    gText_SoDarling,
    gText_SoRelaxed,
    gText_SoSunny,
    gText_SoDesirable,
    gText_SoExciting,
    gText_SoAmusing,
    gText_SoMagical
};

static const u8 * const sGiddyQuestions[] = {
    gUnknown_08294313,
    gUnknown_08294359,
    gUnknown_08294398,
    gUnknown_082943DA,
    gUnknown_0829441C,
    gUnknown_08294460,
    gUnknown_082944A0,
    gUnknown_082944D5
};

static void SetupBard(void)
{
    u16 i;
    struct MauvilleManBard *bard = &gSaveBlock1Ptr->oldMan.bard;

    bard->id = MAUVILLE_MAN_BARD;
    bard->hasChangedSong = FALSE;
    bard->language = gGameLanguage;
    for (i = 0; i < 6; i++)
        bard->songLyrics[i] = sDefaultBardSongLyrics[i];
}

static void SetupHipster(void)
{
    struct MauvilleManHipster *hipster = &gSaveBlock1Ptr->oldMan.hipster;

    hipster->id = MAUVILLE_MAN_HIPSTER;
    hipster->alreadySpoken = FALSE;
    hipster->language = gGameLanguage;
}

static void SetupStoryteller(void)
{
    sub_8120E08();
}

static void SetupGiddy(void)
{
    struct MauvilleManGiddy *giddy = &gSaveBlock1Ptr->oldMan.giddy;

    giddy->id = MAUVILLE_MAN_GIDDY;
    giddy->taleCounter = 0;
    giddy->language = gGameLanguage;
}

static void SetupTrader(void)
{
    sub_81339F8();
}

void SetMauvilleOldMan(void)
{
    u16 trainerId = (gSaveBlock2Ptr->playerTrainerId[1] << 8) | gSaveBlock2Ptr->playerTrainerId[0];


    // Determine man based on the last digit of the player's trainer ID.
    switch ((trainerId % 10) / 2)
    {
        case MAUVILLE_MAN_BARD:
            SetupBard();
            break;
        case MAUVILLE_MAN_HIPSTER:
            SetupHipster();
            break;
        case MAUVILLE_MAN_TRADER:
            SetupTrader();
            break;
        case MAUVILLE_MAN_STORYTELLER:
            SetupStoryteller();
            break;
        case MAUVILLE_MAN_GIDDY:
            SetupGiddy();
            break;
    }
    sub_8120B5C();
}

u8 sub_81201C8(void) // GetCurrentMauvilleOldMan
{
    struct MauvilleManCommon *common = &gSaveBlock1Ptr->oldMan.common;

    return common->id;
}

void sub_81201DC(void) // ScrSpecial_GetCurrentMauvilleMan
{
    gSpecialVar_Result = sub_81201C8();
}

void sub_81201F4(void) // ScrSpecial_HasBardSongBeenChanged
{
    u16 *scriptResult = &gSpecialVar_Result; // why??
    struct MauvilleManBard *bard = &gSaveBlock1Ptr->oldMan.bard;

    *scriptResult = bard->hasChangedSong;
}

void sub_8120210(void) // ScrSpecial_SaveBardSongLyrics
{
    u16 i;
    struct MauvilleManBard *bard = &gSaveBlock1Ptr->oldMan.bard;

    StringCopy(bard->playerName, gSaveBlock2Ptr->playerName);

    for (i = 0; i < 4; i++)
        bard->playerTrainerId[i] = gSaveBlock2Ptr->playerTrainerId[i];

    for (i = 0; i < 6; i++)
        bard->songLyrics[i] = bard->temporaryLyrics[i];

    bard->hasChangedSong = TRUE;
}

// Copies lyrics into gStringVar4
void sub_8120280(void)
{
    struct MauvilleManBard *bard = &gSaveBlock1Ptr->oldMan.bard;
    u16 specialVar = gSpecialVar_0x8004;  // It's a bit odd to use this temp variable, but it seems needed to match.
    u16 *lyrics;
    u16 lineNum;
    u8 *wordEnd;
    u8 *str;

    lyrics = bard->temporaryLyrics;
    if (specialVar == 0)
        lyrics = bard->songLyrics;
    wordEnd = gStringVar4;
    str = wordEnd;
    // Put three words on each line
    for (lineNum = 0; lineNum < 2; lineNum++)
    {
        wordEnd = CopyEasyChatWord(wordEnd, *(lyrics++));
        while (wordEnd != str)
        {
            if (*str == CHAR_SPACE)
                *str = CHAR_SONG_WORD_SEPARATOR;
            str++;
        }

        str++;
        *(wordEnd++) = CHAR_SPACE;

        wordEnd = CopyEasyChatWord(wordEnd, *(lyrics++));
        while (wordEnd != str)
        {
            if (*str == CHAR_SPACE)
                *str = CHAR_SONG_WORD_SEPARATOR;
            str++;
        }

        str++;
        *(wordEnd++) = CHAR_NEWLINE;

        wordEnd = CopyEasyChatWord(wordEnd, *(lyrics++));
        while (wordEnd != str)
        {
            if (*str == CHAR_SPACE)
                *str = CHAR_SONG_WORD_SEPARATOR;
            str++;
        }

        if (lineNum == 0)
        {
            *(wordEnd++) = EXT_CTRL_CODE_BEGIN;
            *(wordEnd++) = 15;
        }
    }
}

void sub_8120340(void) // ScrSpecial_PlayBardSong
{
    sub_81206C0(gSpecialVar_0x8004);
    ScriptContext1_Stop();
}

void sub_8120358(void) // ScrSpecial_GetHipsterSpokenFlag
{
    u16 *scriptResult = &gSpecialVar_Result; // again??
    struct MauvilleManHipster *hipster = &gSaveBlock1Ptr->oldMan.hipster;

    *scriptResult = hipster->alreadySpoken;
}

void sub_8120374(void) // ScrSpecial_SetHipsterSpokenFlag
{
    struct MauvilleManHipster *hipster = &gSaveBlock1Ptr->oldMan.hipster;

    hipster->alreadySpoken = TRUE;
}

void sub_812038C(void) // ScrSpecial_HipsterTeachWord
{
    u16 var = sub_811F01C();

    if (var == 0xFFFF)
    {
        gSpecialVar_Result = FALSE;
    }
    else
    {
        CopyEasyChatWord(gStringVar1, var);
        gSpecialVar_Result = TRUE;
    }
}

void sub_81203C4(void) // ScrSpecial_GiddyShouldTellAnotherTale
{
    struct MauvilleManGiddy *giddy = &gSaveBlock1Ptr->oldMan.giddy;

    if (giddy->taleCounter == 10)
    {
        gSpecialVar_Result = FALSE;
        giddy->taleCounter = 0;
    }
    else
    {
        gSpecialVar_Result = TRUE;
    }
}

void sub_81203FC(void) // ScrSpecial_GenerateGiddyLine
{
    struct MauvilleManGiddy *giddy = &gSaveBlock1Ptr->oldMan.giddy;

    if (giddy->taleCounter == 0)
        sub_81204DC();

    if (giddy->randomWords[giddy->taleCounter] != 0xFFFF) // is not the last element of the array?
    {
        u8 *stringPtr;
        u32 adjective = Random();

        adjective %= 8;
        stringPtr = CopyEasyChatWord(gStringVar4, giddy->randomWords[giddy->taleCounter]);
        stringPtr = StringCopy(stringPtr, gOtherText_Is);
        stringPtr = StringCopy(stringPtr, sGiddyAdjectives[adjective]);
        StringCopy(stringPtr, gOtherText_DontYouAgree);
    }
    else
    {
        StringCopy(gStringVar4, sGiddyQuestions[giddy->questionList[giddy->questionNum++]]);
    }

    if (!(Random() % 10))
        giddy->taleCounter = 10;
    else
        giddy->taleCounter++;

    gSpecialVar_Result = TRUE;
}
