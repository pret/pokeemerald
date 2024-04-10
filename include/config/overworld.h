#ifndef GUARD_CONFIG_OVERWORLD_H
#define GUARD_CONFIG_OVERWORLD_H

// Movement config
#define OW_RUNNING_INDOORS          GEN_LATEST  // In Gen4+, players are allowed to run indoors.

// Other settings
#define OW_POISON_DAMAGE                GEN_LATEST // In Gen4, Pokémon no longer faint from Poison in the overworld. In Gen5+, they no longer take damage at all.
#define OW_TIMES_OF_DAY                 GEN_LATEST // Different generations have the times of day change at different times.
#define OW_DOUBLE_APPROACH_WITH_ONE_MON FALSE      // If enabled, you can be spotted by two trainers at the same time even if you only have one eligible Pokémon in your party.
#define OW_HIDE_REPEAT_MAP_POPUP        FALSE      // If enabled, map popups will not appear if entering a map with the same Map Section Id as the last.

// These generational defines only make a distinction for Berries and the OW_PC_MOVE_ORDER
#define GEN_6_XY GEN_6
#define GEN_6_ORAS GEN_LATEST + 1

// PC settings
#define OW_PC_PRESS_B               GEN_LATEST // In Gen4, pressing B when holding a Pokémon is equivalent to placing it. In Gen3, it gives the "You're holding a Pokémon!" error.
#define OW_PC_JAPAN_WALDA_ICONS     TRUE       // In the US release of Emerald, the Cross, Bolt, and Plusle icons for Walda's wallpapers were left blank from the Japan release. Setting this to TRUE will restore them.
#define OW_PC_HEAL                  GEN_LATEST // In Gen8+, Pokémon are not healed when deposited in the PC.
#define OW_PC_MOVE_ORDER            GEN_LATEST // Starting in Gen4, the order of options in the PC menu change.

#define OW_BERRY_MUTATIONS             FALSE      // If enabled, Berry plants can mutate based on berries planted next to them.
#define OW_BERRY_MUTATION_CHANCE       25         // Determines the % chance of a mutation.
#define OW_BERRY_MOISTURE              FALSE      // If enabled, Berry watering is not a matter of watering it once per stage, but rather of keeping the soil moist.
#define OW_BERRY_ALWAYS_WATERABLE      FALSE      // If OW_BERRY_MOISTURE is enabled, this setting allows the player to continuously water soil; dry soil will cause a decrease in Berry Yield (like Gen4). When off, soil can only be watered when dry and watering increases yield (like Gen6).
#define OW_BERRY_MULCH_USAGE           FALSE      // If enabled, Mulch can be used on soil to fertilize it. Otherwise, it is considered unusable. Note that moisture effects only work with OW_BERRY_MOISTURE enabled!
#define OW_BERRY_WEEDS                 FALSE      // If enabled, weeds may grow on Berry plants that the player needs to take care of. Without OW_BERRY_MOISTURE, weeding bonuses are rounded down.
#define OW_BERRY_PESTS                 FALSE      // If enabled, pests may approach Berry plants that the player needs to take care of. Without OW_BERRY_MOISTURE, pest bonuses are rounded down.
#define OW_BERRY_SIX_STAGES            FALSE      // In XY, Berries go through six stages instead of four. This toggle does not affect the time it takes for a tree to be ready for harvest. Without OW_BERRY_MOISTURE, the two extra stages count as BERRY_STAGE_TALLER for watering purposes.

#define OW_BERRY_GROWTH_RATE           GEN_3      // Presets for how long each Berry plant takes to grow.
#define OW_BERRY_YIELD_RATE            GEN_3      // Presets for how many Berries each plant can yield.
#define OW_BERRY_DRAIN_RATE            GEN_6_ORAS // If OW_BERRY_MOISTURE is enabled, this setting changes how fast the soil dries out. GEN_4 uses a Berry-dependent drain rate, GEN_6_XY dries out in 24 hours (4 hours with the relevant Mulch) and GEN_6_ORAS dries out in 4 hours. Other values are illegal.

// Out-of-battle Ability effects
#define OW_SYNCHRONIZE_NATURE       GEN_LATEST // In Gen8+, if a Pokémon with Synchronize leads the party, wild Pokémon will always have their same Nature as opposed to the 50% chance in previous games. Gift Pokémon excluded.
                                               // In USUM (here GEN_7), if a Pokémon with Synchronize leads the party, gift Pokémon will always have their same Nature regardless of their Egg Group.
                                               // In ORAS (here GEN_6), if a Pokémon with Synchronize leads the party, gift Pokémon from the No Eggs Discovered Egg Group will always have their same Nature.
#define OW_SUPER_LUCK               GEN_LATEST // In Gen8+, if a Pokémon with Super Luck is leading the party, the wild held item rate is increased to 60%/20%.
#define OW_INFILTRATOR              GEN_LATEST // In Gen8+, if a Pokémon with Infiltrator is leading the party, the wild encounter rate is halved.
#define OW_HARVEST                  GEN_LATEST // In Gen8+, if a Pokémon with Harvest is leading the party, there is a 50% chance to encounter a Grass-type Pokémon.
#define OW_LIGHTNING_ROD            GEN_LATEST // In Gen8+, if a Pokémon with Lightning Rod is leading the party, there is a 50% chance to encounter an Electric-type Pokémon.
#define OW_STORM_DRAIN              GEN_LATEST // In Gen8+, if a Pokémon with Storm Drain is leading the party, there is a 50% chance to encounter a Water-type Pokémon.
#define OW_FLASH_FIRE               GEN_LATEST // In Gen8+, if a Pokémon with Flash Fire is leading the party, there is a 50% chance to encounter a Fire-type Pokémon.

// Overworld flags
// To use the following features in scripting, replace the 0s with the flag ID you're assigning it to.
// Eg: Replace with FLAG_UNUSED_0x264 so you can use that flag to toggle the feature.
#define OW_FLAG_NO_ENCOUNTER        0  // If this flag is set, wild encounters will be disabled.
#define OW_FLAG_NO_TRAINER_SEE      0  // If this flag is set, trainers will not battle the player unless they're talked to.
#define OW_FLAG_NO_COLLISION        0  // If this flag is set, the player will be able to walk over tiles with collision. Mainly intended for debugging purposes.

#define BATTLE_PYRAMID_RANDOM_ENCOUNTERS    FALSE    // If set to TRUE, battle pyramid Pokemon will be generated randomly based on the round's challenge instead of hardcoded in src/data/battle_frontier/battle_pyramid_level_50_wild_mons.h (or open_level_wild_mons.h)

#endif // GUARD_CONFIG_OVERWORLD_H
