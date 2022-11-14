#ifndef GUARD_CONFIG_POKEMON_H
#define GUARD_CONFIG_POKEMON_H

#define P_UPDATED_TYPES         GEN_LATEST  // Since Gen 6, several Pokémon were changed to be partially or fully Fairy type.
#define P_UPDATED_STATS         GEN_LATEST  // Since Gen 6, Pokémon stats are updated with each passing generation.
#define P_UPDATED_ABILITIES     GEN_LATEST  // Since Gen 6, certain Pokémon have their abilities changed.
#define P_UPDATED_EGG_GROUPS    GEN_LATEST  // Since Gen 8, certain Pokémon have gained new egg groups.
#define P_SHEDINJA_BALL         GEN_LATEST  // Since Gen 4, Shedinja requires a Poké Ball for its evolution. In Gen 3, Shedinja inherits Nincada's Ball.
#define P_LEGENDARY_PERFECT_IVS GEN_LATEST  // Since Gen 6, Legendaries, Mythicals and Ultra Beasts found in the wild or given through gifts have at least 3 perfect IVs.
#define P_KADABRA_EVERSTONE     GEN_LATEST  // Since Gen 4, Kadabra can evolve even when holding an Everstone.
#define P_NIDORAN_M_DITTO_BREED GEN_LATEST  // Since Gen 5, when Nidoran♂ breeds with Ditto it can produce Nidoran♀ offspring. Before, it would only yield male offspring. This change also applies to Volbeat.
#define P_SHINY_BASE_CHANCE     GEN_LATEST  // Since Gen 6, the base chances of encountering a Shiny Pokémon was raised to 1/4096. This config adds an extra roll to the calculation, which effectively does the same thing.

// Flag settings
// To use the following features in scripting, replace the 0s with the flag ID you're assigning it to.
// Eg: Replace with FLAG_UNUSED_0x264 so you can use that flag to toggle the feature.
#define P_FLAG_FORCE_SHINY      0     // If this flag is set, all wild and gift Pokémon will forced into being Shiny.
#define P_FLAG_FORCE_NO_SHINY   0     // If this flag is set, all wild and gift Pokémon will forced into NOT being Shiny.

// Modifying the latest generation WILL change the saveblock due to Dex flags and will require a new save file.
// Forms are kept based on the base species, Eg: Meowth and Persian will keep all of their forms, but Perrserker will not be available if P_GEN_8_POKEMON is set to FALSE.
// If you're disabling a generation previous to others (eg: Gen 5 but not Gen 6, 7 and 8),
// remember to update NATIONAL_DEX enum in include/constants/pokedex.h to avoid players from softlocking in the non-existant entries.
#define P_GEN_4_POKEMON         TRUE        // Generation 4 Pokémon (DPPt, HGSS)
#define P_GEN_5_POKEMON         TRUE        // Generation 5 Pokémon (BW, B2W2)
#define P_GEN_6_POKEMON         TRUE        // Generation 6 Pokémon (XY, ORAS)
#define P_GEN_7_POKEMON         TRUE        // Generation 7 Pokémon (SM, USUM, LGPE)
#define P_GEN_8_POKEMON         TRUE        // Generation 8 Pokémon (SwSh, BDSP, LA)

#endif // GUARD_CONFIG_POKEMON_H
