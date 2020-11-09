#ifndef GUARD_CONSTANTS_POKEMON_CONFIG_H
#define GUARD_CONSTANTS_POKEMON_CONFIG_H

#ifndef GEN_3
#define GEN_3 0
#define GEN_4 1
#define GEN_5 2
#define GEN_6 3
#define GEN_7 4
#define GEN_8 5
#endif

#define P_UPDATED_TYPES         GEN_8 // In Gen6+, several Pokémon were changed to be partially or fully Fairy type.
#define P_UPDATED_STATS         GEN_8 // Since Gen 6, Pokémon stats are updated with each passing generation.
#define P_UPDATED_ABILITIES     GEN_8 // Since Gen 6, certain Pokémon have their abilities changed. Requires BATTLE_ENGINE for Gen4+ abilities.
#define P_UPDATED_EGG_GROUPS    GEN_8 // Since Gen 8, certain Pokémon have gained new egg groups.

#endif // GUARD_CONSTANTS_POKEMON_CONFIG_H
