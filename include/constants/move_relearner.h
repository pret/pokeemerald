#ifndef GUARD_CONSTANTS_MOVE_RELEARNER_H
#define GUARD_CONSTANTS_MOVE_RELEARNER_H

// Max number of moves shown by the move relearner.
// Increased from 25 to 60 so Mew can display all TMs/HMs.
// If you plan on adding more TMs, increase this number too.
#define MAX_RELEARNER_MOVES 60

// Move Relearner menu change constants
enum MoveRelearnerStates
{
    MOVE_RELEARNER_LEVEL_UP_MOVES,
    MOVE_RELEARNER_EGG_MOVES,
    MOVE_RELEARNER_TM_MOVES,
    MOVE_RELEARNER_TUTOR_MOVES,
    MOVE_RELEARNER_COUNT,
};

enum RelearnMode
{
    RELEARN_MODE_NONE = 0,
    RELEARN_MODE_SCRIPT = 1,                     // Relearning moves through an event script
    // These two must stay 2 and 3, they are tied to the summary screen pages
    RELEARN_MODE_PSS_PAGE_BATTLE_MOVES = 2,      // Relearning moves through the summary screen's battle moves page
    RELEARN_MODE_PSS_PAGE_CONTEST_MOVES = 3,     // Relearning moves through the summary screen's contest moves page (defaults to contest page on relearner screen)
};

#endif // GUARD_CONSTANTS_MOVE_RELEARNER_H
