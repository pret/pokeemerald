#ifndef GUARD_BARD_SOUNDS_TABLE_H
#define GUARD_BARD_SOUNDS_TABLE_H

#define NULL_BARD_SOUND { 0xff }

#include "pokemon.h"
#include "moves.h"
#include "trainer.h"
#include "status.h"
#include "battle.h"
#include "greetings.h"
#include "people.h"
#include "voices.h"
#include "speech.h"
#include "endings.h"
#include "feelings.h"
#include "conditions.h"
#include "actions.h"
#include "lifestyle.h"
#include "hobbies.h"
#include "time.h"
#include "misc.h"
#include "adjectives.h"
#include "events.h"
#include "trendysaying.h"

const struct BardSound (*const gBardSoundsTable[EC_NUM_GROUPS])[6] = {
    [EC_GROUP_POKEMON]       = NULL, // Handled by gBardSounds_Pokemon
    [EC_GROUP_TRAINER]       = gBardSounds_Trainer,
    [EC_GROUP_STATUS]        = gBardSounds_Status,
    [EC_GROUP_BATTLE]        = gBardSounds_Battle,
    [EC_GROUP_GREETINGS]     = gBardSounds_Greetings,
    [EC_GROUP_PEOPLE]        = gBardSounds_People,
    [EC_GROUP_VOICES]        = gBardSounds_Voices,
    [EC_GROUP_SPEECH]        = gBardSounds_Speech,
    [EC_GROUP_ENDINGS]       = gBardSounds_Endings,
    [EC_GROUP_FEELINGS]      = gBardSounds_Feelings,
    [EC_GROUP_CONDITIONS]    = gBardSounds_Conditions,
    [EC_GROUP_ACTIONS]       = gBardSounds_Actions,
    [EC_GROUP_LIFESTYLE]     = gBardSounds_Lifestyle,
    [EC_GROUP_HOBBIES]       = gBardSounds_Hobbies,
    [EC_GROUP_TIME]          = gBardSounds_Time,
    [EC_GROUP_MISC]          = gBardSounds_Misc,
    [EC_GROUP_ADJECTIVES]    = gBardSounds_Adjectives,
    [EC_GROUP_EVENTS]        = gBardSounds_Events,
    [EC_GROUP_MOVE_1]        = NULL, // Handled by gBardSounds_Moves
    [EC_GROUP_MOVE_2]        = NULL, // Handled by gBardSounds_Moves
    [EC_GROUP_TRENDY_SAYING] = gBardSounds_TrendySaying,
    [EC_GROUP_POKEMON_2]     = NULL // Handled by gBardSounds_Pokemon
};

#endif //GUARD_BARD_SOUNDS_TABLE_H
