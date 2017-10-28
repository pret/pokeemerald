
// Includes
#include "global.h"
#include "bard_music.h"
#include "easy_chat.h"

// Static type declarations

// Static RAM declarations

// Static ROM declarations

// .rodata

#include "data/bard_music/pokemon.h"
#include "data/bard_music/moves.h"
#include "data/bard_music/trainer.h"
#include "data/bard_music/status.h"
#include "data/bard_music/battle.h"
#include "data/bard_music/greetings.h"
#include "data/bard_music/people.h"
#include "data/bard_music/voices.h"
#include "data/bard_music/speech.h"
#include "data/bard_music/endings.h"
#include "data/bard_music/feelings.h"
#include "data/bard_music/conditions.h"
#include "data/bard_music/actions.h"
#include "data/bard_music/lifestyle.h"
#include "data/bard_music/hobbies.h"
#include "data/bard_music/time.h"
#include "data/bard_music/misc.h"
#include "data/bard_music/adjectives.h"
#include "data/bard_music/events.h"
#include "data/bard_music/trendysaying.h"

const struct BardSound (*const gBardSoundsTable[])[6] = {
    NULL,
    gBardSounds_Trainer,
    gBardSounds_Status,
    gBardSounds_Battle,
    gBardSounds_Greetings,
    gBardSounds_People,
    gBardSounds_Voices,
    gBardSounds_Speech,
    gBardSounds_Endings,
    gBardSounds_Feelings,
    gBardSounds_Conditions,
    gBardSounds_Actions,
    gBardSounds_Lifestyle,
    gBardSounds_Hobbies,
    gBardSounds_Time,
    gBardSounds_Misc,
    gBardSounds_Adjectives,
    gBardSounds_Events,
    NULL,
    NULL,
    gBardSounds_TrendySaying,
    NULL
};

extern const s16 *const gUnknown_0860A320[];
extern const int gUnknown_0860A3DC[];
extern const struct BardSound gBardSound_InvalidWord[6];

// .text

s16 CalcWordPitch(int arg0, int songPos)
{
    return gUnknown_0860A320[arg0][songPos];
}

const struct BardSound *GetWordSounds(u16 word)
{
    u32 category;
    u32 subword;
    const struct BardSound (*ptr)[6];

    if (IsECWordInValidRange(word))
    {
        return gBardSound_InvalidWord;
    }
    category = word >> 9;
    subword = word & 0x1ff;
    switch (category)
    {
        case EC_GROUP_POKEMON:
        case EC_GROUP_POKEMON_2:
            ptr = gBardSounds_Pokemon;
            break;
        case EC_GROUP_MOVE_1:
        case EC_GROUP_MOVE_2:
            ptr = gBardSounds_Moves;
            break;
        default:
            ptr = gBardSoundsTable[category];
            break;
    }
    ptr += subword;
    return *ptr;
}

void GetWordPhonemes(struct BardSong *song, u16 word)
{
    int i;
    const struct BardSound *sound;

    song->length = 0;
    for (i = 0; i < 6; i ++)
    {
        sound = &song->sound[i];
        if (sound->var00 != 0xFF)
        {
            song->phonemes[i].length = sound->var01 + gUnknown_0860A3DC[sound->var00];
            song->phonemes[i].pitch = CalcWordPitch(word + 30, i);
            song->length += song->phonemes[i].length;
        }
    }
    song->currPhoneme = 0;
    song->voiceInflection = 0;
}
