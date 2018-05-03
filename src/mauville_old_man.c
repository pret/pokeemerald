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
#include "task.h"
#include "menu.h"
#include "m4a.h"
#include "bard_music.h"
#include "constants/songs.h"

#define CHAR_SONG_WORD_SEPARATOR 0x37

extern struct MusicPlayerInfo gMPlayInfo_SE2;

void sub_81204DC(void);
void sub_81206C0(bool8 useTemporaryLyrics); // StartBardSong
void sub_8120944(u8 taskId);
void sub_8120B5C(void);
void sub_8120E08(void); // StorytellerSetup
void sub_8120E50(void);
void sub_81339F8(void); // TraderSetup
void sub_8133A60(void);

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

void sub_81204DC(void)
{
    struct MauvilleManGiddy *giddy = &gSaveBlock1Ptr->oldMan.giddy;
    u16 arr[][2] = {
        {EC_GROUP_POKEMON,   0},
        {EC_GROUP_LIFESTYLE, 0},
        {EC_GROUP_HOBBIES,   0},
        {EC_GROUP_MOVE_1,    0},
        {EC_GROUP_MOVE_2,    0},
        {EC_GROUP_POKEMON_2, 0}
    };
    u16 i;
    u16 r10;
    u16 r7;
    u16 r1;

    for (i = 0; i < 8; i++)
        giddy->questionList[i] = i;

    for (i = 0; i < 8; i++)
    {
        r1 = Random() % (i + 1);
        r7 = giddy->questionList[i];
        giddy->questionList[i] = giddy->questionList[r1];
        giddy->questionList[r1] = r7;
    }

    r10 = 0;
    for (i = 0; i < 6; i++)
    {
        arr[i][1] = EasyChat_GetNumWordsInGroup(arr[i][0]);
        r10 += arr[i][1];
    }

    giddy->questionNum = 0;
    r7 = 0;
    for (i = 0; i < 10; i++)
    {
        r1 = Random() % 10;
        if (r1 < 3 && r7 < 8)
        {
            giddy->randomWords[i] = 0xFFFF;
            r7++;
        }
        else
        {
            s16 r2 = Random() % r10;
            for (r1 = 0; i < 6; r1++)
                if ((r2 -= arr[r1][1]) <= 0)
                    break;
            if (r1 == 6)
                r1 = 0;
            giddy->randomWords[i] = sub_811EE90(arr[r1][0]);
        }
    }
}
void sub_8120628(void)
{
    struct MauvilleManBard *bard = &gSaveBlock1Ptr->oldMan.bard;

    bard->hasChangedSong = FALSE;
}

void sub_8120640(void)
{
    struct MauvilleManHipster *hipster = &gSaveBlock1Ptr->oldMan.hipster;

    hipster->alreadySpoken = FALSE;
}

void sub_8120658(void)
{
    sub_8133A60();
}

void sub_8120664(void)
{
    sub_8120E50();
}

void sub_8120670(void) // ResetMauvilleOldManFlag
{
    switch (sub_81201C8())
    {
        case MAUVILLE_MAN_BARD:
            sub_8120628();
            break;
        case MAUVILLE_MAN_HIPSTER:
            sub_8120640();
            break;
        case MAUVILLE_MAN_STORYTELLER:
            sub_8120664();
            break;
        case MAUVILLE_MAN_TRADER:
            sub_8120658();
            break;
        case MAUVILLE_MAN_GIDDY:
            break;
    }
    sub_8120B5C();
}


#define tState data[0]
#define tCharIndex data[3]
#define tCurrWord data[4]
#define tUseTemporaryLyrics data[5]

#define MACRO1(a) (((a) & 3) + (((a) / 8) & 1))

void sub_81206C0(bool8 useTemporaryLyrics)
{
    u8 taskId = CreateTask(sub_8120944, 80);

    gTasks[taskId].tUseTemporaryLyrics = useTemporaryLyrics;
}

void sub_81206F0(struct TextSubPrinter * printer, u16 a1)
{
    gUnknown_03002F84 = FALSE;
}

void sub_81206FC(struct TextSubPrinter * printer, u16 a1)
{
    gUnknown_03002F84 = TRUE;
}

void sub_8120708(const u8 * src)
{
    NewMenuHelpers_DrawDialogueFrame(0, 0);
    PrintTextOnWindow(0, 1, src, 0, 1, 1, sub_81206FC);
    gUnknown_03002F84 = TRUE;
    CopyWindowToVram(0, 3);
}

void sub_8120748(struct Task *task, struct BardSong *song)
{
    switch (task->tState)
    {
        case 0:  // Initialize song
        {
            struct MauvilleManBard *bard = &gSaveBlock1Ptr->oldMan.bard;
            u16 *lyrics;
            s32 i;

            // Copy lyrics
            if (gSpecialVar_0x8004 == 0)
                lyrics = bard->songLyrics;
            else
                lyrics = bard->temporaryLyrics;
            for (i = 0; i < 6; i++)
                song->lyrics[i] = lyrics[i];
            song->currWord = 0;
        }
            break;
        case 1:  // Wait for BGM to end
            break;
        case 2:  // Initialize word
        {
            u16 word = song->lyrics[song->currWord];
            song->sound = GetWordSounds(word);
            GetWordPhonemes(song, MACRO1(word));
            song->currWord++;
            if (song->sound->var00 != 0xFF)
                song->state = 0;
            else
            {
                song->state = 3;
                song->phonemeTimer = 2;
            }
            break;
        }
        case 3:
        case 4:
        {
            const struct BardSound *sound = &song->sound[song->currPhoneme];

            switch (song->state)
            {
                case 0:
                    song->phonemeTimer = song->phonemes[song->currPhoneme].length;
                    if (sound->var00 <= 50)
                    {
                        u8 num = sound->var00 / 3;
                        m4aSongNumStart(PH_TRAP_HELD + 3 * num);
                    }
                    song->state = 2;
                    song->phonemeTimer--;
                    break;
                case 2:
                    song->state = 1;
                    if (sound->var00 <= 50)
                    {
                        song->volume = 0x100 + sound->volume * 16;
                        m4aMPlayVolumeControl(&gMPlayInfo_SE2, 0xFFFF, song->volume);
                        song->pitch = 0x200 + song->phonemes[song->currPhoneme].pitch;
                        m4aMPlayPitchControl(&gMPlayInfo_SE2, 0xFFFF, song->pitch);
                    }
                    break;
                case 1:
                    if (song->voiceInflection > 10)
                        song->volume -= 2;
                    if (song->voiceInflection & 1)
                        song->pitch += 64;
                    else
                        song->pitch -= 64;
                    m4aMPlayVolumeControl(&gMPlayInfo_SE2, 0xFFFF, song->volume);
                    m4aMPlayPitchControl(&gMPlayInfo_SE2, 0xFFFF, song->pitch);
                    song->voiceInflection++;
                    song->phonemeTimer--;
                    if (song->phonemeTimer == 0)
                    {
                        song->currPhoneme++;
                        if (song->currPhoneme != 6 && song->sound[song->currPhoneme].var00 != 0xFF)
                            song->state = 0;
                        else
                        {
                            song->state = 3;
                            song->phonemeTimer = 2;
                        }
                    }
                    break;
                case 3:
                    song->phonemeTimer--;
                    if (song->phonemeTimer == 0)
                    {
                        m4aMPlayStop(&gMPlayInfo_SE2);
                        song->state = 4;
                    }
                    break;
            }
        }
            break;
        case 5:
            break;
    }
}
