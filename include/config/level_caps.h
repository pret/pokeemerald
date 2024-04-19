#ifndef GUARD_CONFIG_LEVEL_CAP_H
#define GUARD_CONFIG_LEVEL_CAP_H

// Constants
#define EXP_CAP_NONE                    0 // Regular behavior, no level caps are applied
#define EXP_CAP_HARD                    1 // Pokémon with a level >= the level cap cannot gain any experience
#define EXP_CAP_SOFT                    2 // Pokémon with a level >= the level cap will gain reduced experience

#define LEVEL_CAP_NONE                  0 // No level cap, only applicable if B_EXP_CAP_TYPE is EXP_CAP_NONE
#define LEVEL_CAP_FLAG_LIST             1 // Level cap is chosen according to the first unset flag in `sLevelCapFlagMap`
#define LEVEL_CAP_VARIABLE              2 // Level cap is chosen according to the contents of the event variable specified by B_LEVEL_CAP_VARIABLE

// Configs
#define B_EXP_CAP_TYPE                  EXP_CAP_NONE   // [EXP_CAP_NONE, EXP_CAP_HARD, EXP_CAP_SOFT] choose the type of level cap to apply
#define B_LEVEL_CAP_TYPE                LEVEL_CAP_NONE // [LEVEL_CAP_NONE, LEVEL_CAP_FLAG_LIST, LEVEL_CAP_VARIABLE] choose the method to derive the level cap
#define B_LEVEL_CAP_VARIABLE            0 // event variable used to derive level cap if B_LEVEL_CAP_TYPE is set to LEVEL_CAP_VARIABLE

#define B_RARE_CANDY_CAP                FALSE // If set to true, Rare Candies can't be used to go over the level cap
#define B_LEVEL_CAP_EXP_UP              FALSE // If set to true, mons under level cap will receive more experience

#endif /* GUARD_CONFIG_LEVEL_CAP_H */
