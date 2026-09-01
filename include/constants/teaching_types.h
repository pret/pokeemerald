#ifndef GUARD_CONSTANTS_TEACHING_TYPES_H
#define GUARD_CONSTANTS_TEACHING_TYPES_H

/*
Teaching Types are not used directly by the ROM but they are used by
make_teachables.py to generate teachable learnsets. To save ROM space, the info is
stored in 1 bit and the python script reads the name of the define.
This means we can have multiple "modes" that define to 1.
You can add additional teaching types but they would need to be described in the
python script.
*/


/* DEFAULT_LEARNING
Vanilla uses: most Pokémon
Allow a Pokémon to learn all universal moves
*/
#define DEFAULT_LEARNING    0

/* TM_ILLITERATE
Vanilla uses: Pokémon with "gimmick" moveset (Ditto, Smeargle, Magikarp, ...)
Pokemon can't learn any universal moves (unless it was added to their teachable learnset)
*/
#define TM_ILLITERATE       1

/* ALL_TEACHABLES
Vanilla uses: Mew
Allows a Pokémon to learn almost every teachable move (whether from TM or tutors)
Some moves are excluded, they are listed in SignatureTeachables
*/
#define ALL_TEACHABLES      1


#endif  // GUARD_CONSTANTS_TEACHING_TYPES_H
