#ifndef GUARD_BARD_MUSIC_H
#define GUARD_BARD_MUSIC_H

// The maximum number of BardSoundTemplates/BardSounds there can be for each easy chat word.
#define MAX_BARD_SOUNDS_PER_WORD 6

// The number of pitch tables there are for each pitch table size (see sPitchTables).
#define NUM_BARD_PITCH_TABLES_PER_SIZE 5

// This struct describes which phoneme song to play for the sound, and whether to
// make any adjustments to its length or volume. Very few sounds make any adjustments.
struct BardSoundTemplate
{
    u8 songId;
    s8 lengthAdjustment;
    u16 unused; // Only set on EC_WORD_WAAAH, and never read.
    s16 volume;
};

// This is the length and pitch to play the phoneme song at.
// These will be calculated in 'CalcWordSounds'.
struct BardSound
{
    u16 length;
    u16 pitch;
};

struct BardSong
{
    u8 lyricsIndex;
    u8 soundIndex;
    u8 timer;
    u8 state;
    s16 length; // Length of the sound for the word currently being sung (i.e. the sum of 'length' in all the current word's phonemes).
    u16 volume;
    s16 pitch;
    s16 voiceInflection;
    u16 lyrics[NUM_BARD_SONG_WORDS];
    struct BardSound sounds[MAX_BARD_SOUNDS_PER_WORD];
    const struct BardSoundTemplate *soundTemplates;
};

extern const u16 gNumBardWords_Species;
extern const u16 gNumBardWords_Moves;

const struct BardSoundTemplate *GetWordSoundTemplates(u16 easyChatWord);
void CalcWordSounds(struct BardSong *song, u16 pitchTableIndex);

#endif //GUARD_BARD_MUSIC_H
