#ifndef GUARD_CONSTANTS_POKEMON_CONFIG_H
#define GUARD_CONSTANTS_POKEMON_CONFIG_H

#define P_UPDATED_TYPES         GEN_LATEST  // Since Gen 6, several Pokémon were changed to be partially or fully Fairy type.
#define P_UPDATED_STATS         GEN_LATEST  // Since Gen 6, Pokémon stats are updated with each passing generation.
#define P_UPDATED_ABILITIES     GEN_LATEST  // Since Gen 6, certain Pokémon have their abilities changed.
#define P_UPDATED_EGG_GROUPS    GEN_LATEST  // Since Gen 8, certain Pokémon have gained new egg groups.
#define P_SHEDINJA_BALL         GEN_LATEST  // Since Gen 4, Shedinja requires a Poké Ball for its evolution. In Gen 3, Shedinja inherits Nincada's Ball.
#define P_LEGENDARY_PERFECT_IVS GEN_LATEST  // Since Gen 6, Legendaries, Mythicals and Ultra Beasts found in the wild or given through gifts have at least 3 perfect IVs.
#define P_KADABRA_EVERSTONE     GEN_LATEST  // Since Gen 4, Kadabra can evolve even when holding an Everstone.
#define P_NIDORAN_M_DITTO_BREED GEN_LATEST  // Since Gen 5, when Nidoran♂ breeds with Ditto it can produce Nidoran♀ offspring. Before, it would only yield male offspring. This change also applies to Volbeat.

#define P_NEW_POKEMON           TRUE        // Turning this to FALSE will remove all newly added Pokémon and Forms. Only Unown, Castform and Deoxys forms will remain.

#define P_ENABLE_DEBUG          TRUE        // Enables a debug menu for pokemon sprites and icons, accessed by pressing SELECT in the summary screen.

#endif // GUARD_CONSTANTS_POKEMON_CONFIG_H
