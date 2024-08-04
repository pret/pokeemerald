#ifndef GUARD_CONFIG_POKEMON_H
#define GUARD_CONFIG_POKEMON_H

// Species data settings
#define P_UPDATED_TYPES             GEN_LATEST  // Since Gen 6, several Pokémon were changed to be partially or fully Fairy type.
#define P_UPDATED_STATS             GEN_LATEST  // Since Gen 6, Pokémon stats are updated with each passing generation.
#define P_UPDATED_ABILITIES         GEN_LATEST  // Since Gen 6, certain Pokémon have their abilities changed.
#define P_UPDATED_EGG_GROUPS        GEN_LATEST  // Since Gen 8, certain Pokémon have gained new egg groups.
#define P_UPDATED_FRIENDSHIP        GEN_LATEST  // Since Gen 8, the base friendship of certain Pokémon was changed.
#define P_UPDATED_EVS               GEN_LATEST  // Some Pokémon have received EV updates after their introduction.
#define P_UPDATED_EXP_YIELDS        GEN_LATEST  // Since Gen 5, some Pokémon have received base Experience changes.

// Learnsets
#define P_LVL_UP_LEARNSETS          GEN_LATEST  // Choose which set of Level Up Learnsets to use.
                                                // For generations that hadn't introduced a species yet, we use their first appearence (eg. Chikorita's Gen2 data if the config is set to GEN_1).
                                                // For generations that don't include a previously introduced species, we use their last apperance (eg. Snivy's Gen7 data if the config is set to GEN_8).
                                                // GEN_1/2/3/4/5/6/7: Yellow, Crystal, RSE, HGSS, B2W2, ORAS, USUM learnsets respectively.
                                                // GEN_8: Use the following priority: BDSP for Gen1-4 Pokémon, then LA for species introduced in that game, then SwSh for species present in those games. Otherwise, use GEN_7.
                                                // GEN_9: SV For species present in those games. Otherwise use GEN_8.

// Evolution settings
#define P_FRIENDSHIP_EVO_THRESHOLD   GEN_LATEST  // Since Gen 8, Pokémon that evolve by friendship evolve at or above 160 friendship instead of 220.

// Breeding settings
#define P_NIDORAN_M_DITTO_BREED         GEN_LATEST  // Since Gen 5, when Nidoran♂ breeds with Ditto it can produce Nidoran♀ offspring. Before, it would only yield male offspring. This change also applies to Volbeat.
#define P_INCENSE_BREEDING              GEN_LATEST  // Since Gen 9, cross-generation Baby Pokémon don't require Incense being held by the parents to be obtained via breeding.
#define P_EGG_HATCH_LEVEL               GEN_LATEST  // Since Gen 4, Pokémon will hatch from eggs at level 1 instead of 5.
#define P_BALL_INHERITING               GEN_LATEST  // Since Gen 6, Eggs from the Daycare will inherit the Poké Ball from their mother. From Gen 7 onwards, the father can pass it down as well, as long as it's of the same species as the mother.
#define P_TM_INHERITANCE                GEN_LATEST  // Since Gen 6, the father no longer passes down TMs to the baby.
#define P_MOTHER_EGG_MOVE_INHERITANCE   GEN_LATEST  // Since Gen 6, the mother can also pass down Egg Moves.
#define P_NATURE_INHERITANCE            GEN_LATEST  // In Gen 3, Everstone grants Ditto and mothers a 50% chance to pass on Nature. Since Gen 4, anyone can pass on nature. Since Gen 5, the chance is 100%.
#define P_ABILITY_INHERITANCE           GEN_LATEST  // In B2W2, a female Pokémon has an 80% chance of passing down their ability if bred with a male. Since Gen 6, the chance is 80% for normal ability and 60% for Hidden Ability, and anyone can pass down their abilities if bred with Ditto. NOTE: BW's effect: 60% chance to pass down HA and random for normal ability has been omitted.
#define P_EGG_MOVE_TRANSFER             GEN_LATEST  // Starting in Gen 8, if two Pokémon of the same species are together in the Daycare, one knows an Egg Move, and the other has an empty slot, the other Pokémon will receive the Egg Move in the empty slot. In Gen 9, if a Pokémon holds a Mirror Herb, it will receive Egg Moves from the other regardless of species.

// Species-specific settings
#define P_SHEDINJA_BALL             GEN_LATEST  // Since Gen 4, Shedinja requires a Poké Ball for its evolution. In Gen 3, Shedinja inherits Nincada's Ball.
#define P_KADABRA_EVERSTONE         GEN_LATEST  // Since Gen 4, Kadabra can evolve even when holding an Everstone.
#define P_SHUCKLE_BERRY_JUICE       GEN_LATEST  // In Gen 2, Shuckle had a 1/16 chance of converting Berry that it's holding into Berry Juice. Enabling this will allow Shuckle to do this with an Oran Berry, which is the spiritual succesor of the Berry item.

// Other settings
#define P_CUSTOM_GENDER_DIFF_ICONS  TRUE        // If TRUE, will give more Pokémon custom icons for their female forms, i.e. Hippopotas and Hippowdon
#define P_FOOTPRINTS                TRUE        // If TRUE, Pokémon will have footprints (as was the case up to Gen 5 and in BDSP). Disabling this saves some ROM space.
#define P_LEGENDARY_PERFECT_IVS     GEN_LATEST  // Since Gen 6, Legendaries, Mythicals and Ultra Beasts found in the wild or given through gifts have at least 3 perfect IVs.
#define P_EV_CAP                    GEN_LATEST  // Since Gen 6, the max EVs per stat is 252 instead of 255.
#define P_SHOW_TERA_TYPE            GEN_8       // Since Gen 9, the Tera Type is shown on the summary screen.
#define P_TM_LITERACY               GEN_LATEST  // Since Gen 6, TM illiterate Pokémon can learn TMs that teach moves that are in their level-up learnsets.

// Learnset helper toggles
#define P_LEARNSET_HELPER_TEACHABLE TRUE        // If TRUE, teachable_learnsets.h will be populated by tools/learnset_helpers/teachable.py using the included JSON files based on available TMs and tutors.

// Flag settings
// To use the following features in scripting, replace the 0s with the flag ID you're assigning it to.
// Eg: Replace with FLAG_UNUSED_0x264 so you can use that flag to toggle the feature.
#define P_FLAG_FORCE_SHINY      0     // If this flag is set, all wild and gift Pokémon will forced into being Shiny.
#define P_FLAG_FORCE_NO_SHINY   0     // If this flag is set, all wild and gift Pokémon will forced into NOT being Shiny.

// Go here if you want to disable specific families of Pokémon.
#include "config/species_enabled.h"

#endif // GUARD_CONFIG_POKEMON_H
