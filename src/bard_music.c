
// Includes
#include "global.h"
#include "bard_music.h"
#include "text.h"
#include "easy_chat.h"

// Static type declarations

// Static RAM declarations

// Static ROM declarations

// .rodata

extern const struct BardSound gBardSounds_Pokemon[][6];
extern const struct BardSound gBardSounds_Moves[][6];
extern const struct BardSound (*const gBardSoundsTable[])[6];
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
