#ifndef GUARD_DIFFICULTY_CONSTANTS_H
#define GUARD_DIFFICULTY_CONSTANTS_H

enum DifficultyLevel
{
    DIFFICULTY_EASY,
    DIFFICULTY_NORMAL, //If you rename this, the word "Normal" in fprint_trainers must be replaced with the new difficulty name.
    DIFFICULTY_HARD,
#if TESTING
    DIFFICULTY_TEST,
#endif 
    DIFFICULTY_COUNT,
};

#define DIFFICULTY_MIN 0
#define DIFFICULTY_MAX (DIFFICULTY_COUNT - 1)

#endif // GUARD_DIFFICULTY_CONSTANTS_H
