
// Includes
#include "global.h"
#include "bard_music.h"
#include "easy_chat.h"

#define NULL_BARD_SOUND {0xff, 0, 0, 0, 0}

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
#include "data/bard_music/bard_sounds_table.h"
#include "data/bard_music/word_pitch.h"
#include "data/bard_music/default_sound.h"
#include "data/bard_music/length_table.h"

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
            song->phonemes[i].length = sound->var01 + gBardSoundLengthTable[sound->var00];
            song->phonemes[i].pitch = CalcWordPitch(word + 30, i);
            song->length += song->phonemes[i].length;
        }
    }
    song->currPhoneme = 0;
    song->voiceInflection = 0;
}
