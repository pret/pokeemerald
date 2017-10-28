#ifndef GUARD_BARD_SOUNDS_TABLE_H
#define GUARD_BARD_SOUNDS_TABLE_H

#define NULL_BARD_SOUND { 0xff }

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

#endif //GUARD_BARD_SOUNDS_TABLE_H
