#ifndef GUARD_CONFIG_OVERWORLD_H
#define GUARD_CONFIG_OVERWORLD_H

// Movement config
#define OW_RUNNING_INDOORS          GEN_LATEST  // In Gen4+, players are allowed to run indoors.

// Other settings
#define OW_POISON_DAMAGE            GEN_LATEST // In Gen4, Pokémon no longer faint from Poison in the overworld. In Gen5+, they no longer take damage at all.

// PC settings
#define OW_PC_PRESS_B               GEN_LATEST // In Gen4, pressing B when holding a Pokémon is equivalent to placing it. In Gen3, it gives the "You're holding a Pokémon!" error.
#define OW_PC_JAPAN_WALDA_ICONS     TRUE       // In the US release of Emerald, the Cross, Bolt, and Plusle icons for Walda's wallpapers were left blank from the Japan release. Setting this to TRUE will restore them.

// Out-of-battle Ability effects
#define OW_SYNCHRONIZE_NATURE       GEN_LATEST // In Gen8, if a Pokémon with Synchronize is leading the party, it's 100% guaranteed that wild Pokémon will have the same Nature, as opposed to 50% previously. Stationary Pokémon are excluded in Gen3. In Gen6, all No Eggs Discovered gift Pokémon will have the same Nature, while in Gen7 all gift Pokémon will, regardless of Egg Group - In Gen 8, no gift Pokémon are affected. In Gen9, this ability has no out-of-battle effect.
#define OW_COMPOUND_EYES            GEN_LATEST // Prior to Gen9, if a Pokémon with Compound Eyes is leading the party, the wild held item rate is increased to 60%/20%.
#define OW_SUPER_LUCK               GEN_LATEST // In Gen8, if a Pokémon with Super Luck is leading the party, the wild held item rate is increased to 60%/20%.
#define OW_CUTE_CHARM               GEN_LATEST // Prior to Gen9, if a Pokémon with Cute Charm is leading the party, wild encounters have a 66.7% chance to be forced to be of the opposite gender.
#define OW_ILLUMINATE               GEN_LATEST // Prior to Gen9, if a Pokémon with Illuminate is leading the party, the wild encounter rate is doubled.
#define OW_INFILTRATOR              GEN_LATEST // In Gen8, if a Pokémon with Infiltrator is leading the party, the wild encounter rate is halved.
#define OW_HARVEST                  GEN_LATEST // In Gen8, if a Pokémon with Harvest is leading the party, there is a 50% chance to encounter a Grass-type Pokémon.
#define OW_LIGHTNING_ROD            GEN_LATEST // In Gen8, if a Pokémon with Lightning Rod is leading the party, there is a 50% chance to encounter an Electric-type Pokémon.
#define OW_STORM_DRAIN              GEN_LATEST // In Gen8, if a Pokémon with Storm Drain is leading the party, there is a 50% chance to encounter a Water-type Pokémon.
#define OW_FLASH_FIRE               GEN_LATEST // In Gen8, if a Pokémon with Flash Fire is leading the party, there is a 50% chance to encounter a Fire-type Pokémon.
#define OW_MAGNET_PULL              GEN_LATEST // Prior to Gen9, if a Pokémon with Magnet Pull is leading the party, there is a 50% chance to encounter a Steel-type Pokémon.
#define OW_STATIC                   GEN_LATEST // Prior to Gen9, if a Pokémon with Static is leading the party, there is a 50% chance to encounter an Electric-type Pokémon.

// Overworld flags
// To use the following features in scripting, replace the 0s with the flag ID you're assigning it to.
// Eg: Replace with FLAG_UNUSED_0x264 so you can use that flag to toggle the feature.
#define OW_FLAG_NO_ENCOUNTER        0  // If this flag is set, wild encounters will be disabled.
#define OW_FLAG_NO_TRAINER_SEE      0  // If this flag is set, trainers will not battle the player unless they're talked to.
#define OW_FLAG_NO_COLLISION        0  // If this flag is set, the player will be able to walk over tiles with collision. Mainly intended for debugging purposes.

#define BATTLE_PYRAMID_RANDOM_ENCOUNTERS    FALSE    // If set to TRUE, battle pyramid Pokemon will be generated randomly based on the round's challenge instead of hardcoded in src/data/battle_frontier/battle_pyramid_level_50_wild_mons.h (or open_level_wild_mons.h)

#endif // GUARD_CONFIG_OVERWORLD_H
