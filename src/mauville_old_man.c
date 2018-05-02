#include "global.h"
#include "main.h"
#include "constants/easy_chat.h"
#include "mauville_old_man.h"

void sub_8120E08(void); // StorytellerSetup
void sub_81339F8(void); // TraderSetup
void sub_8120B5C(void);

static const u16 sDefaultBardSongLyrics[6] = {
    EC_WORD_SHAKE,
    EC_WORD_IT,
    EC_WORD_DO,
    EC_WORD_THE,
    EC_WORD_DIET,
    EC_WORD_DANCE
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
