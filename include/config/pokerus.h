#ifndef GUARD_CONFIG_POKERUS_H
#define GUARD_CONFIG_POKERUS_H

//For Pokérus, we refer to infection as a Pokémon catching Pokérus from an enemy Pokémon (trainer or wild) and we refer to spreading as Pokémon catching Pokérus from another infected Pokémon in the party
#define P_POKERUS_ENABLED                TRUE       // If FALSE, Pokérus will have no effect, won't be shown and won't be aquired in any way but save data won't be affected
#define P_POKERUS_STRAIN_DISTRIBUTION    GEN_LATEST // Pokérus has 16 different strains and their probability distribution change depending on generation, GEN_3 will use the Ruby/Sapphire version and GEN_4 will use the version used in Emerald and Gen 4
#define P_POKERUS_SPREAD_ADJACENCY       GEN_LATEST // In Gen 2, Pokérus spread to one adjacent Pokémon but it spreads to both adjacent Pokémon in gen 3+
#define P_POKERUS_SPREAD_DAYS_LEFT       GEN_LATEST // In Gen 2, a freshly spreaded Pokémon will get its full infection duration based on strain. In gen 3+, the Pokérus duration will copy the duration from the Pokémon it was spreaded from
#define P_POKERUS_INFECT_AGAIN           GEN_LATEST // If Gen 2 only, your party can get infected even when it is already infected with Pokérus (doesn't affect spreading)
#define P_POKERUS_VISIBLE_ON_EGG         GEN_LATEST // Controls if eggs can show Pokérus symbol in summary screen (TRUE from gen 3 to 6, FALSE in gen 2,7 and 8)
#define P_POKERUS_INFECT_EGG             FALSE      // If TRUE, eggs can receive Pokérus from spread and direction infection (gen 2). If FALSE, eggs can receive Pokérus from spread but not direct infection (gen 3). Behavior is unknown in other gens.
#define P_POKERUS_FLAG_INFECTION         0          // If Pokérus can only get infected if this flag is set or undefined (0). This emulates a gen 2 mechanic where Pokémon can only get infected by Pokérus after visiting Goldernrod. This does not affect spreading

// Weird Pokérus behaviors that could be considered bugs. They are TRUE in vanilla Emerald but set to FALSE by default in Expansion (behaviors in other gens is unknown)
#define P_POKERUS_HERD_IMMUNITY          FALSE      // If TRUE, Pokémon that have been previously infected by the Pokérus in your party reduce the chances of your party getting infected by the Pokérus (because they can be rolled at the target of the infection but are now "immune")
#define P_POKERUS_WEAK_VARIANT           FALSE      // If TRUE, the variant 0 of Pokérus can be erased by stronger variant when Pokérus is spreading

#define P_POKERUS_INFECTION_ODDS         3          // Actual probability is POKERUS_INFECTION_ODDS/65536
#define P_POKERUS_SPREAD_ODDS            21846      // Actual probability is POKERUS_SPREAD_ODDS/65536 (21846 should correspond to the vanilla Random() % 3)

#endif // GUARD_CONFIG_POKERUS_H
