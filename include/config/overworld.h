#ifndef GUARD_CONFIG_OVERWORLD_H
#define GUARD_CONFIG_OVERWORLD_H

// Movement config
#define OW_RUNNING_INDOORS          GEN_LATEST  // In Gen4+, players are allowed to run indoors.

// Other settings
#define OW_POISON_DAMAGE                GEN_LATEST // In Gen4, Pokémon no longer faint from Poison in the overworld. In Gen5+, they no longer take damage at all.
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
#define OW_PC_RELEASE_ITEM          GEN_LATEST // In Gen8+, Pokémon that get released with a held item return it to the bag.

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

// Overworld Pokémon
#define OW_POKEMON_OBJECT_EVENTS       TRUE       // Adds Object Event fields for every species. Can be used for NPCs using the OBJ_EVENT_GFX_SPECIES macro (eg. OBJ_EVENT_GFX_SPECIES(BULBASAUR))
#define OW_SUBSTITUTE_PLACEHOLDER      TRUE       // Use a substitute OW for Pokémon that are missing overworld sprites
#define OW_LARGE_OW_SUPPORT            TRUE       // If true, adds a small amount of overhead to OW code so that large (48x48, 64x64) OWs will display correctly under bridges, etc.
#define OW_PKMN_OBJECTS_SHARE_PALETTES FALSE      // [WIP!! NOT ALL PALETTES HAVE BEEN ADJUSTED FOR THIS!!] If TRUE, follower palettes are taken from battle sprites.
#define OW_GFX_COMPRESS                TRUE       // Adds support for compressed OW graphics, (Also compresses pokemon follower graphics).
                                                  // Compressed gfx are incompatible with non-power-of-two sprite sizes:
                                                  // (You should not use 48x48 sprites/tables for compressed gfx)
                                                  // 16x32, 32x32, 64x64 etc are fine
// Follower Pokémon
#define OW_FOLLOWERS_ENABLED           FALSE      // Enables follower Pokémon, HGSS style. Requires OW_POKEMON_OBJECT_EVENTS. Note that additional scripting may be required for them to be fully supported!
#define OW_FOLLOWERS_BOBBING           TRUE       // If true, follower pokemon will bob up and down during their idle & walking animations
#define OW_FOLLOWERS_POKEBALLS         TRUE       // Followers will emerge from the pokeball they are stored in, instead of a normal pokeball

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

// These generational defines only make a distinction for OW_ALTERED_TIME_RATIO
#define GEN_8_PLA                       GEN_LATEST + 2

//Time
#define OW_TIMES_OF_DAY                 GEN_LATEST // Different generations have the times of day change at different times.
#define OW_USE_FAKE_RTC                 FALSE      // When TRUE, seconds on the in-game clock will only advance once every 60 playTimeVBlanks (every 60 frames).
#define OW_ALTERED_TIME_RATIO           GEN_LATEST // In GEN_8_PLA, the time in game moves forward 60 seconds for every second in the RTC. In GEN_9, it is 20 seconds. This has no effect if OW_USE_FAKE_RTC is FALSE.

// Overworld flags
// To use the following features in scripting, replace the 0s with the flag ID you're assigning it to.
// Eg: Replace with FLAG_UNUSED_0x264 so you can use that flag to toggle the feature.
#define OW_FLAG_PAUSE_TIME          0  // If this flag is set and OW_USE_FAKE_RTC is enabled, seconds on the in-game clock will not advance.
#define OW_FLAG_NO_ENCOUNTER        0  // If this flag is set, wild encounters will be disabled.
#define OW_FLAG_NO_TRAINER_SEE      0  // If this flag is set, trainers will not battle the player unless they're talked to.
#define OW_FLAG_NO_COLLISION        0  // If this flag is set, the player will be able to walk over tiles with collision. Mainly intended for debugging purposes.

#define BATTLE_PYRAMID_RANDOM_ENCOUNTERS    FALSE    // If set to TRUE, battle pyramid Pokemon will be generated randomly based on the round's challenge instead of hardcoded in src/data/battle_frontier/battle_pyramid_level_50_wild_mons.h (or open_level_wild_mons.h)

// Map pop-up config
#define OW_POPUP_GENERATION        GEN_3    // Different generations display location names in overworld pop-ups differently.
                                            // Only choies are currently GEN_3 and GEN_5, all others will default to Gen3 pop-ups.

// Gen5 map pop-up config
// Constants
#define OW_POPUP_BW_TIME_NONE      0   // Don't show the time
#define OW_POPUP_BW_TIME_12_HR     1   // Use 12 hour (AM/PM) time
#define OW_POPUP_BW_TIME_24_HR     2   // Use 24 hour time

#define OW_POPUP_BW_COLOR_BLACK    0   // Black pop-up from B2
#define OW_POPUP_BW_COLOR_WHITE    1   // White pop-up from W2

// Configuration
#define OW_POPUP_BW_COLOR          OW_POPUP_BW_COLOR_BLACK  // B2W2 use different colors for their map pop-ups.
#define OW_POPUP_BW_TIME_MODE      OW_POPUP_BW_TIME_NONE    // Determines what type of time is shown.
#define OW_POPUP_BW_ALPHA_BLEND    FALSE                    // Enables alpha blending/transparency for the pop-ups. Mainly intended to be used with the black color option.

// Pokémon Center
#define OW_IGNORE_EGGS_ON_HEAL     GEN_LATEST               // In Gen 4+, the nurse in the Pokémon Center does not heal Eggs on healing machine.

#endif // GUARD_CONFIG_OVERWORLD_H
