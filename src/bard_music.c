#include "global.h"
#include "bard_music.h"
#include "easy_chat.h"
#include "constants/songs.h"

// Indicates that the previous sound should be held.
#define PREV_BARD_SOUND { .songId = NUM_PHONEME_SONGS }

// Invalid sound, indicates the end of the sounds for the word.
#define NULL_BARD_SOUND { .songId = PHONEME_ID_NONE }

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

static const struct BardSoundTemplate (*const sBardSoundTemplatesTable[EC_NUM_GROUPS])[MAX_BARD_SOUNDS_PER_WORD] = {
    [EC_GROUP_POKEMON]          = NULL, // Handled by sBardSoundTemplates_Pokemon
    [EC_GROUP_TRAINER]          = sBardSoundTemplates_Trainer,
    [EC_GROUP_STATUS]           = sBardSoundTemplates_Status,
    [EC_GROUP_BATTLE]           = sBardSoundTemplates_Battle,
    [EC_GROUP_GREETINGS]        = sBardSoundTemplates_Greetings,
    [EC_GROUP_PEOPLE]           = sBardSoundTemplates_People,
    [EC_GROUP_VOICES]           = sBardSoundTemplates_Voices,
    [EC_GROUP_SPEECH]           = sBardSoundTemplates_Speech,
    [EC_GROUP_ENDINGS]          = sBardSoundTemplates_Endings,
    [EC_GROUP_FEELINGS]         = sBardSoundTemplates_Feelings,
    [EC_GROUP_CONDITIONS]       = sBardSoundTemplates_Conditions,
    [EC_GROUP_ACTIONS]          = sBardSoundTemplates_Actions,
    [EC_GROUP_LIFESTYLE]        = sBardSoundTemplates_Lifestyle,
    [EC_GROUP_HOBBIES]          = sBardSoundTemplates_Hobbies,
    [EC_GROUP_TIME]             = sBardSoundTemplates_Time,
    [EC_GROUP_MISC]             = sBardSoundTemplates_Misc,
    [EC_GROUP_ADJECTIVES]       = sBardSoundTemplates_Adjectives,
    [EC_GROUP_EVENTS]           = sBardSoundTemplates_Events,
    [EC_GROUP_MOVE_1]           = NULL, // Handled by sBardSoundTemplates_Moves
    [EC_GROUP_MOVE_2]           = NULL, // Handled by sBardSoundTemplates_Moves
    [EC_GROUP_TRENDY_SAYING]    = sBardSoundTemplates_TrendySaying,
    [EC_GROUP_POKEMON_NATIONAL] = NULL, // Handled by sBardSoundTemplates_Pokemon
};

// The pitch tables below will be indexed using the number of BardSoundTemplates per word, so a table is selected
// that has at least MAX_BARD_SOUNDS_PER_WORD pitch values. Curiously they select pitch tables whose size is +1
// of the maximum number of sounds per word, so the final pitch value (before PITCH_END) isn't used.
// (i.e., 'NUM_BARD_PITCH_TABLES_PER_SIZE * (MAX_BARD_SOUNDS_PER_WORD-1)' would select a sufficiently large table).
#define BASE_PITCH_TABLE_INDEX (NUM_BARD_PITCH_TABLES_PER_SIZE * MAX_BARD_SOUNDS_PER_WORD)

#define PITCH_END 0x1800

static const s16 sPitch1_0[] = { -0x300, PITCH_END };
static const s16 sPitch1_1[] = { 0x0900, PITCH_END };
static const s16 sPitch1_2[] = { 0x0100, PITCH_END };
static const s16 sPitch1_3[] = { 0x0400, PITCH_END };
static const s16 sPitch1_4[] = { 0x0b00, PITCH_END };

static const s16 sPitch2_0[] = { -0x300, -0x100, PITCH_END };
static const s16 sPitch2_1[] = { -0x300, 0x0200, PITCH_END };
static const s16 sPitch2_2[] = { 0x0200, 0x0400, PITCH_END };
static const s16 sPitch2_3[] = { 0x0600, 0x0800, PITCH_END };
static const s16 sPitch2_4[] = { 0x0900, 0x0800, PITCH_END };

static const s16 sPitch3_0[] = { -0x300, -0x100, -0x300, PITCH_END };
static const s16 sPitch3_1[] = { 0x0400, -0x300, 0x0400, PITCH_END };
static const s16 sPitch3_2[] = { 0x0900, 0x0800, 0x0600, PITCH_END };
static const s16 sPitch3_3[] = { 0x0100, 0x0200, 0x0400, PITCH_END };
static const s16 sPitch3_4[] = { 0x0600, 0x1000, 0x0d00, PITCH_END };

static const s16 sPitch4_0[] = { 0x0400, 0x0900, 0x0400, 0x0900, PITCH_END };
static const s16 sPitch4_1[] = { 0x0900, 0x0400, 0x0d00, 0x0400, PITCH_END };
static const s16 sPitch4_2[] = { 0x0100, 0x0200, 0x0400, 0x0600, PITCH_END };
static const s16 sPitch4_3[] = { 0x0800, 0x0600, 0x0400, 0x0200, PITCH_END };
static const s16 sPitch4_4[] = { 0x0f00, 0x0d00, 0x0b00, 0x0a00, PITCH_END };

static const s16 sPitch5_0[] = { -0x300, -0x100, 0x0100, 0x0200, 0x0400, PITCH_END };
static const s16 sPitch5_1[] = { 0x0900, 0x0800, 0x0600, 0x0400, 0x0200, PITCH_END };
static const s16 sPitch5_2[] = { 0x0100, 0x0400, 0x0900, 0x0400, 0x0100, PITCH_END };
static const s16 sPitch5_3[] = { 0x0900, 0x0400, 0x0900, 0x0400, -0x300, PITCH_END };
static const s16 sPitch5_4[] = { 0x0b00, 0x0800, 0x0400, 0x0400, 0x0600, PITCH_END };

static const s16 sPitch6_0[] = { -0x300, -0x100, 0x0100, 0x0200, 0x0400, 0x0600, PITCH_END };
static const s16 sPitch6_1[] = { 0x0800, 0x0600, 0x0400, 0x0200, 0x0100, -0x100, PITCH_END };
static const s16 sPitch6_2[] = { 0x0100, 0x0200, 0x0400, 0x0100, 0x0200, 0x1000, PITCH_END };
static const s16 sPitch6_3[] = { 0x0400, -0x300, 0x0900, 0x0400, 0x0900, 0x0400, PITCH_END };
static const s16 sPitch6_4[] = { 0x0800, 0x0900, 0x0800, 0x0900, 0x0800, 0x0900, PITCH_END };

static const s16 sPitch7_0[] = { 0x0200, 0x0100, 0x0200, 0x0100, 0x0200, 0x0400, 0x0200, PITCH_END };
static const s16 sPitch7_1[] = { 0x0100, 0x0100, -0x100, -0x100, -0x300, 0x0400, -0x300, PITCH_END };
static const s16 sPitch7_2[] = { 0x0800, 0x0900, 0x0b00, 0x0d00, 0x0e00, 0x0d00, 0x0b00, PITCH_END };
static const s16 sPitch7_3[] = { 0x0800, 0x0600, 0x0400, 0x0200, 0x0d00, 0x0b00, 0x0900, PITCH_END };
static const s16 sPitch7_4[] = { 0x0300, 0x0400, 0x0600, 0x0800, 0x0700, 0x0800, 0x0400, PITCH_END };

// In practice only sPitch7_# below are used below.
// BASE_PITCH_TABLE_INDEX is 30 by default, and this table is always indexed with (x + 30), where x is some value 0 - 4
static const s16 *const sPitchTables[NUM_BARD_PITCH_TABLES_PER_SIZE * 7] = {
    sPitch1_0, sPitch1_1, sPitch1_2, sPitch1_3, sPitch1_4,
    sPitch2_0, sPitch2_1, sPitch2_2, sPitch2_3, sPitch2_4,
    sPitch3_0, sPitch3_1, sPitch3_2, sPitch3_3, sPitch3_4,
    sPitch4_0, sPitch4_1, sPitch4_2, sPitch4_3, sPitch4_4,
    sPitch5_0, sPitch5_1, sPitch5_2, sPitch5_3, sPitch5_4,
    sPitch6_0, sPitch6_1, sPitch6_2, sPitch6_3, sPitch6_4,
    sPitch7_0, sPitch7_1, sPitch7_2, sPitch7_3, sPitch7_4
};

// If this fails, CalcWordSounds will likely read out of bounds for sPitchTables.
STATIC_ASSERT(BASE_PITCH_TABLE_INDEX + (NUM_BARD_PITCH_TABLES_PER_SIZE-1) < ARRAY_COUNT(sPitchTables), NotEnoughPitchTablesForBardSounds)

static const struct BardSoundTemplate sEmptyPhonemeTemplate[] = {
    NULL_BARD_SOUND,
    NULL_BARD_SOUND,
    NULL_BARD_SOUND,
    NULL_BARD_SOUND,
    NULL_BARD_SOUND,
    NULL_BARD_SOUND
};

static const int sPhonemeLengths[NUM_PHONEME_SONGS + 1] = {
    [PHONEME_ID(PH_TRAP_BLEND)] = 9,
    [PHONEME_ID(PH_TRAP_HELD)] = 22,
    [PHONEME_ID(PH_TRAP_SOLO)] = 15,
    [PHONEME_ID(PH_FACE_BLEND)] = 16,
    [PHONEME_ID(PH_FACE_HELD)] = 39,
    [PHONEME_ID(PH_FACE_SOLO)] = 21,
    [PHONEME_ID(PH_CLOTH_BLEND)] = 9,
    [PHONEME_ID(PH_CLOTH_HELD)] = 30,
    [PHONEME_ID(PH_CLOTH_SOLO)] = 24,
    [PHONEME_ID(PH_DRESS_BLEND)] = 15,
    [PHONEME_ID(PH_DRESS_HELD)] = 25,
    [PHONEME_ID(PH_DRESS_SOLO)] = 12,
    [PHONEME_ID(PH_FLEECE_BLEND)] = 22,
    [PHONEME_ID(PH_FLEECE_HELD)] = 45,
    [PHONEME_ID(PH_FLEECE_SOLO)] = 24,
    [PHONEME_ID(PH_KIT_BLEND)] = 15,
    [PHONEME_ID(PH_KIT_HELD)] = 40,
    [PHONEME_ID(PH_KIT_SOLO)] = 9,
    [PHONEME_ID(PH_PRICE_BLEND)] = 21,
    [PHONEME_ID(PH_PRICE_HELD)] = 42,
    [PHONEME_ID(PH_PRICE_SOLO)] = 18,
    [PHONEME_ID(PH_LOT_BLEND)] = 9,
    [PHONEME_ID(PH_LOT_HELD)] = 22,
    [PHONEME_ID(PH_LOT_SOLO)] = 15,
    [PHONEME_ID(PH_GOAT_BLEND)] = 27,
    [PHONEME_ID(PH_GOAT_HELD)] = 48,
    [PHONEME_ID(PH_GOAT_SOLO)] = 18,
    [PHONEME_ID(PH_THOUGHT_BLEND)] = 27,
    [PHONEME_ID(PH_THOUGHT_HELD)] = 33,
    [PHONEME_ID(PH_THOUGHT_SOLO)] = 24,
    [PHONEME_ID(PH_CHOICE_BLEND)] = 25,
    [PHONEME_ID(PH_CHOICE_HELD)] = 39,
    [PHONEME_ID(PH_CHOICE_SOLO)] = 19,
    [PHONEME_ID(PH_MOUTH_BLEND)] = 16,
    [PHONEME_ID(PH_MOUTH_HELD)] = 54,
    [PHONEME_ID(PH_MOUTH_SOLO)] = 18,
    [PHONEME_ID(PH_FOOT_BLEND)] = 9,
    [PHONEME_ID(PH_FOOT_HELD)] = 45,
    [PHONEME_ID(PH_FOOT_SOLO)] = 15,
    [PHONEME_ID(PH_GOOSE_BLEND)] = 12,
    [PHONEME_ID(PH_GOOSE_HELD)] = 39,
    [PHONEME_ID(PH_GOOSE_SOLO)] = 23,
    [PHONEME_ID(PH_STRUT_BLEND)] = 5,
    [PHONEME_ID(PH_STRUT_HELD)] = 45,
    [PHONEME_ID(PH_STRUT_SOLO)] = 12,
    [PHONEME_ID(PH_CURE_BLEND)] = 21,
    [PHONEME_ID(PH_CURE_HELD)] = 48,
    [PHONEME_ID(PH_CURE_SOLO)] = 12,
    [PHONEME_ID(PH_NURSE_BLEND)] = 21,
    [PHONEME_ID(PH_NURSE_HELD)] = 69,
    [PHONEME_ID(PH_NURSE_SOLO)] = 18,
    [NUM_PHONEME_SONGS] = 15, // This is the length that will be used by PREV_BARD_SOUND to hold the previous phoneme sound.
};

static s16 GetWordPitch(int tableIndex, int pitchIndex)
{
    return sPitchTables[tableIndex][pitchIndex];
}

const struct BardSoundTemplate *GetWordSoundTemplates(u16 easyChatWord)
{
    u32 category;
    u32 subword;
    const struct BardSoundTemplate (*ptr)[MAX_BARD_SOUNDS_PER_WORD];

    if (IsBardWordInvalid(easyChatWord))
        return sEmptyPhonemeTemplate;

    category = EC_GROUP(easyChatWord);
    subword = EC_INDEX(easyChatWord);
    switch (category)
    {
        case EC_GROUP_POKEMON:
        case EC_GROUP_POKEMON_NATIONAL:
            ptr = sBardSoundTemplates_Pokemon;
            break;
        case EC_GROUP_MOVE_1:
        case EC_GROUP_MOVE_2:
            ptr = sBardSoundTemplates_Moves;
            break;
        default:
            ptr = sBardSoundTemplatesTable[category];
            break;
    }
    ptr += subword;
    return *ptr;
}

// Assumes that 'soundTemplates' has already been loaded with the BardSoundTemplates for the easy chat word to calculate sounds for.
// 'pitchTableIndex' is chosen depending on the easy chat word, but is essentially an arbitrary value 0-4.
void CalcWordSounds(struct BardSong *song, u16 pitchTableIndex)
{
    int i;
    const struct BardSoundTemplate *template;

    song->length = 0;

    for (i = 0; i < MAX_BARD_SOUNDS_PER_WORD; i ++)
    {
        template = &song->soundTemplates[i];
        if (template->songId != PHONEME_ID_NONE)
        {
            // Calculate the length and pitch of each phoneme in this word.
            // A phoneme's length is always the same, and depends on the phoneme song and any adjustments in the template.
            // Its pitch changes depending on the easy chat word and where in the list of templates the phoneme appears.
            song->sounds[i].length = template->lengthAdjustment + sPhonemeLengths[template->songId];
            song->sounds[i].pitch = GetWordPitch(pitchTableIndex + BASE_PITCH_TABLE_INDEX, i);

            // Add this phoneme's length to the total sound length for this word.
            song->length += song->sounds[i].length;
        }
    }
    song->soundIndex = 0;
    song->voiceInflection = 0;
}
