#include "global.h"
#include "bard_music.h"
#include "easy_chat.h"

#include "data/bard_music/bard_sounds.h"
#include "data/bard_music/word_pitch.h"
#include "data/bard_music/default_sound.h"
#include "data/bard_music/length_table.h"

static s16 CalcWordPitch(int pitchIdx, int songPos)
{
    return sBardSoundPitchTables[pitchIdx][songPos];
}

const struct BardSound *GetWordSounds(u16 word)
{
    u32 category;
    u32 subword;
    const struct BardSound (*ptr)[6];

    if (IsBardWordInvalid(word))
    {
        return gBardSound_InvalidWord;
    }
    category = EC_GROUP(word);
    subword = EC_INDEX(word);
    switch (category)
    {
        case EC_GROUP_POKEMON:
        case EC_GROUP_POKEMON_NATIONAL:
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
        if (sound->songLengthId != 0xFF)
        {
            song->phonemes[i].length = sound->songLengthOffset + gBardSoundLengthTable[sound->songLengthId];
            song->phonemes[i].pitch = CalcWordPitch(word + 30, i);
            song->length += song->phonemes[i].length;
        }
    }
    song->currPhoneme = 0;
    song->voiceInflection = 0;
}
