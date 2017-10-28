#ifndef GUARD_BARD_SOUNDS_TABLE_H
#define GUARD_BARD_SOUNDS_TABLE_H

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
