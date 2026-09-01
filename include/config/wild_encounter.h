#ifndef GUARD_CONFIG_WILD_ENCOUNTER_H
#define GUARD_CONFIG_WILD_ENCOUNTER_H

// Vanilla
#define WE_VANILLA_RANDOM           TRUE    // If TRUE, Pokémon can randomly spawn on tiles that can trigger wild encounters, as in vanilla.
#define WE_FLAG_NO_ENCOUNTER        0       // If this flag is set, wild encounters will be disabled.

// Double Wild Battles
#define WE_DOUBLE_WILD_CHANCE            0          // % chance of encountering two Pokémon in a Wild Encounter.
#define WE_DOUBLE_WILD_REQUIRE_2_MONS    FALSE      // If set to TRUE, Wild Double Battles will default to Single Battles when the player only has 1 usable Pokémon, ignoring WE_DOUBLE_WILD_CHANCE and WE_FLAG_FORCE_DOUBLE_WILD.
#define WE_WILD_NATURAL_ENEMIES          TRUE       // If set to TRUE, certain wild mon species will attack other species when partnered in double wild battles (eg. Zangoose vs Seviper)

// Wild Battle Flags
#define WE_FLAG_FORCE_DOUBLE_WILD    0     // If this flag is set, all land and surfing wild battles will be double battles.
#define WE_SMART_WILD_AI_FLAG        0     // If this flag is set, wild Pokémon will become smart, with all AI flags enabled.
#define WE_FLAG_NO_CATCHING          0     // If this flag is set, the ability to catch wild Pokémon is disabled.
#define WE_FLAG_NO_RUNNING           0     // If this flag is set, the ability to escape from wild battles is disabled. Also makes Roar/Whirlwind and Teleport (under Gen8) fail.

// Overworld Wild Encounters (OWEs)
#define WE_OW_ENCOUNTERS                        FALSE   // If TRUE, OW Pokémon can spawn as Overworld Wild Encounters on the current map. Requires OW_POKEMON_OBJECT_EVENTS.
                                                        // If WE_OW_ENCOUNTERS is TRUE, it is recommended that OW_GFX_COMPRESS be set to FALSE to prevent VRAM issues.
#define WE_OWE_FLAG_DISABLED                    0       // Replace 0 with a flag to use it to enable/disable generated OWEs.
#define WE_OWE_SPECIAL_ONLY                     FALSE   // If TRUE, generated OWEs can only be special spawns.
#define WE_OWE_BATTLE_PIKE                      TRUE    // If TRUE, OWEs can spawn in the Battle Pike, if FALSE random encounters will be enabled instead. Requires WE_OW_ENCOUNTERS to be TRUE.
#define WE_OWE_BATTLE_PYRAMID                   TRUE    // If TRUE, OWEs can spawn in the Battle Pyramid, if FALSE random encounters will be enabled instead. Requires WE_OW_ENCOUNTERS to be TRUE.
#define WE_OWE_RESTRICT_METATILE                TRUE    // If TRUE, OWEs will stay within tiles with the same encounter metatile behavior as the one it is currently on, if any.
#define WE_OWE_RESTRICT_MAP                     TRUE    // If TRUE, OWEs will stay within their current map bounds.
#define WE_OWE_UNRESTRICT_SIGHT                 FALSE   // If TRUE, OWEs with movement behaviors that respond to the player, will ignore all movement restrictions when they can see the player.
#define WE_OWE_SPAWN_REPLACEMENT                FALSE   // If TRUE, the oldest OWE objects will despawn after a short time and be replaced with a new spawn if possible.
#define WE_OWE_FLEE_DESPAWN                     TRUE    // If TRUE, a fleeing OWE will despawn if it is unable to take a step for a short time.
#define WE_OWE_SHINY_SPARKLE                    FALSE   // If TRUE, shiny OWEs will spawn with a sparkle animation and play the shiny sound effect.
#define WE_OWE_FEEBAS_SPOTS                     FALSE   // If TRUE, any spot that could result in a Feebas fishing encounter can spawn a Feebas OWE.
#define WE_OWE_DESPAWN_SOUND                    FALSE   // If TRUE, plays SE_FLEE when an OWE despawns.
#define WE_OWE_APPROACH_FOR_BATTLE              TRUE    // If TRUE, OWEs will take steps to be right next to the player before the battle starts.
#define WE_OWE_PREVENT_SHINY_DESPAWN            FALSE   // If TRUE, shiny OWEs will not be despawned when off-screen if on the same map as the player, or be replaced if WE_OWE_SPAWN_REPLACEMENT is TRUE.
#define WE_OWE_PREVENT_FEEBAS_DESPAWN           FALSE   // If TRUE, Feebas OWEs spawned from special Feebas fishing spots (when WE_OWE_FEEBAS_SPOTS is TRUE) will not be despawned when off-screen if on the same map as the player, or be replaced if WE_OWE_SPAWN_REPLACEMENT is TRUE.
#define WE_OWE_PREVENT_SPECIAL_MOVEMENT_DESPAWN TRUE    // If TRUE, shiny OWEs (if WE_OWE_PREVENT_SHINY_DESPAWN is TRUE) or Feebas OWEs (if WE_OWE_PREVENT_FEEBAS_DESPAWN is TRUE) will not be despawned by their movement type (for example, OWE_DESPAWN_ON_NOTICE).
#define WE_OWE_DESPAWN_ON_ENTER_TOWN            TRUE    // If TRUE, despawns all OWEs upon entering a city (MAP_TYPE_CITY) or town (MAP_TYPE_TOWN).
#define WE_OWE_NO_REPEL_DEXNAV_COLLISION        FALSE   // If TRUE, OWEs cannot be triggered by a collision if a Repel or the DexNav is active.

#endif // GUARD_CONFIG_WILD_ENCOUNTER_H
