# Overworld Wild Encounters Tutorial
## OWE Spawning
Overworld Wild Encounters (OWEs), refer to the wild encounters that can be seen as object events in the overworld, prior to engaging in battle with them. They use either the `WILD_AREA_LAND` or `WILD_AREA_WATER` encounter tables by default. OWEs come in two types, Generated or Manual.

### Generated OWEs
Generated OWEs are spawned automatically when `WE_OW_ENCOUNTERS` is set to `TRUE`, being spawned on a random encounter tile near the player, with the encounter table used dependant on it. These are considered low priority OWEs, and automatically populate a level, species, gender and shinyness exactly how a vanilla wild encounter would, or can even be a special spawn, but more on those later.
> Setting `OW_GFX_COMPRESS` to `FALSE` will free more space in VRAM, allowing for more large OWEs to spawn, and reducing the chance of running into a tiles error when trying to spawn Generated OWEs.

### Manual OWEs
Manual OWEs are created by the developer as any other object event would be and are defined by having the `.trainerType` set to `TRAINER_TYPE_OW_WILD_ENCOUNTER`. These can be fully customised by the developer, with the level, species, gender and shinyness all able to be specified. The level can be set by filling the desired value in the `trainerRange_berryTreeId`. The latter three are specified by the `graphicsId` of the object, for example;
- `OBJ_EVENT_GFX_SPECIES(BULBASAUR)` will produce a male, non-shiny Bulbasaur.
- `OBJ_EVENT_GFX_SPECIES_SHINY(CHARMANDER)` will produce a male, shiny Charmander.
- `OBJ_EVENT_GFX_SPECIES_FEMALE(SQUIRTLE)` will produce a female, non-shiny Squirtle.
- `OBJ_EVENT_GFX_SPECIES_SHINY_FEMALE(PIKACHU)` will produce a female, shiny Pikachu.

However, Manual OWEs do not have to be defined fully, leaving any of the level, species, gender, shinyness or script unspecified will revert to default behaviours. If left blank, the level or species will be generated from the relevant encounter table. Leaving the shinyness blank will revert to default shiny odds, although this can still be affected by `P_FLAG_FORCE_SHINY` and `P_FLAG_FORCE_NO_SHINY`. Setting the `OBJ_EVENT_MON` bit of the `graphicsId`, but not the `OBJ_EVENT_MON_FEMALE` will result in a male encounter, setting both will result in a female encounter, as seen above, but setting neither will randomise the gender based on species. A species can be defined with a random gender by just using the species define. A specific script can be specified, but if not the default OWE encounter script will be used.
Assuming the following `graphicsId` have `.trainerType` set to `TRAINER_TYPE_OW_WILD_ENCOUNTER`;
- `SPECIES_EEVEE` will result in an Eevee with a randomised level, gender and shinyness, using the default encounter script.
- `OBJ_EVENT_GFX_SPECIES(NONE)` will result in a male randomised species of randomised level, gender and shinyness, using the default encounter script.
- `OBJ_EVENT_GFX_SPECIES_SHINY_FEMALE(NONE)` will result in a female, shiny randomised species with randomised level and gender, using the default encounter script.

As level and species are potentially taken from the Wild Encounter Header, there is an `assertf` to let developers know when an invalid value is used. If the resultant level is invalid, it will be set to `MIN_LEVEL` (1). If the species is invalid, a replacement object will be created using `OBJ_EVENT_GFX_BOY_1`, this will not be an OWE of any kind.

No matter how much of a Manual OWE is defined, it is considered a high priority OWE, and treated as a regular object event in all ways other than ones outlined above. They will always spawn, regardless of level or abilties of player Pokémon. However, they cannot be special spawns.

> When a manual OWE is removed, for whatever reason, it's flag is also set. Because of this, we recommend giving them temporary flags so they can be reset on leaving the map.

### Special Spawns Categories
Special spawns can be one of three types, in decreasing priority: A Roamer, Feebas, or Mass Outbreak Encounter. Generated OWEs can be in any of these categories, however, Manual OWEs cannot. These work exactly as they would normally;
- If a Roamer is on the route and is able to spawn, then it may appear where a Generated OWE would.
- If any OWE spawns on a tile where a Feebas special fishing spot is, it may appear is a Feebas (only if `WE_OWE_FEEBAS_SPOTS` is TRUE).
- If an OWE spawns on a route that has a mass outbreak occuring, it may spawn as an encounter from that mass outbreak.
`OWE_MAX_ROAMERS` limits the max number of total roamers to 252 in order to fit the relevant info within the `ObjectEvent` struct.

> `WE_OWE_SPECIAL_ONLY` can be used to restrict generated overworld wild encounters to only spawn, if they are within these special categories.

### Restricted Despawning
There are three configs that can be used to restrict the despawning of Generated OWEs.

- If `WE_OWE_PREVENT_SHINY_DESPAWN` is set to `TRUE`, any Generated OWE that spawns as shiny will not be despawned if they go outside of the viewable area. They can still be despawned off-screen if the player goes to another map. This config also ensures that shiny Generated OWEs will never be despawned and replaced if `WE_OWE_SPAWN_REPLACEMENT` is `TRUE`.
- If `WE_OWE_PREVENT_FEEBAS_DESPAWN` is set to `TRUE`, any Generated OWE that is a Feebas spawned from a Feebas fishing spot will follow the same rules as `WE_OWE_PREVENT_SHINY_DESPAWN` above.
- If `WE_OWE_DESPAWN_ON_ENTER_TOWN` is set to `TRUE`, all Generated OWEs will be instantly despawned upon the player crossing a map connection into a map with a map type of either `MAP_TYPE_TOWN` or `MAP_TYPE_CITY`, like what happens in Scarlet/Violet.

None of these three configs can prevent the forceful despawning of OWEs to free up limited resources, as is explained in the next section.

## High Priority and Low Priority OWEs
Low Priority OWEs may not be spawned or even be destroyed in certain situations. There are checks to prevent these from spawning if it would fail, including for the number of event objects, palettes and object tiles. There are also similar checks, when spawning object events other than Low Priotity OWEs. These checks will despawn the oldest of Low Priority OWEs when other objects event are attempting to be spawned and Low Priority OWEs are using these resources. Low Priority OWEs may also be destroyed by NPC object events colliding with them due to their movements or the OWE being in the way of a trainer interaction. High priority OWEs are treated as regular objects and will not be destroyed in the ways outlined above, but may cause the destruction of Generated OWEs and will not face spawning restrictions.
These despawn conditions will overwrite the restrictive despawns mentioned above.

## Encountering an OWE
Any collision between the player and the OWE will start an encounter. An encounter will also start if the player interacts with the OWE with the A button.

If the `WE_OWE_APPROACH_FOR_BATTLE` config is `TRUE`, the OWE will take steps to be right next to the player before the battle begins. Otherwise, the objects will be frozen and the battle will start immediately.

The default encounter script is `InteractWithOverworldWildEncounter`, but can be customised to effect all uses of it. For example, the following change will prevent the encountered species cry from playing before the battle starts.
```diff
InteractWithOverworldWildEncounter::
    lock
    overworldwildencounterapproach
    applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
    facetogether
-   getoverworldwildencounterspecies VAR_0x8005
-   playmoncry VAR_0x8005, CRY_MODE_DOUBLES
-   waitmoncry
    tryoverworldwildencounter
    waitstate
    end
```


## Repel and Lure Behaviours
Repels will prevent the spawning of generated OWEs that are a lower level than the player's lead Pokemon. Lower level generated OWEs that have already been spawned will be immediately despawned when a repel is used. Existing generated OWEs can also be despawned if the player switches a higher level Pokemon to the front of the party if a repel is already active.

Lures increasse the frequency of generated OWE spawning.

## OWE Behaviour Types
The behaviors that these OWEs have is set up to be customizable for each individual species. By default, every species is set to `OWE_IGNORE_PLAYER`. To add a different behavior to a species, find their species struct in their `gen_X_families.h` file in the `src/data/pokemon/species_info` folder and add a `.overworldEncounterBehavior = <BEHAVIOR>` to it. `<BEHAVIOR>` should be replaced with the behavior you want them to use. For example, if I wanted to add the `OWE_FLEE_PLAYER_NORMAL` behavior to Mudkip I would open `gen_3_families.h`, find the struct for `SPECIES_MUDKIP`, and add `.overworldEncounterBehavior = OWE_FLEE_PLAYER_NORMAL` to the end of it like so:
```diff
        .eggMoveLearnset = sMudkipEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_MARSHTOMP}),
+       .overworldEncounterBehavior = OWE_FLEE_PLAYER_NORMAL
    },

    [SPECIES_MARSHTOMP] =
    {
        .baseHP        = 70,
```

The behaviors themselves are defined in `src/data/pokemon/wild_encounter_overworld_behavior.h`. These are the customizable parameters:
- `movementType` is the movement type you want the object event to have. More on these in the next section.
- `viewDistance` is the number of tiles away the mon is able to notice the player in the cardinal directions (similar to the sight distance of trainers).
- `viewWidth` is the total width of the area in which the mon will notice the player. For example, if `viewWidth` is set to `3`, the mon will be able to detect the player if they are within 1 tile of either side of the line of sight.
- `activeDistance` is the max distance away from the mon that the player can be before the mon loses track of them and goes back to wandering.
- `idleSpeed` is the speed at which the mon will take a step while wandering (player is not noticed). This must be one of the values in `enum SpeedOWE`.
- `activeSpeed` is the speed at which the mon will take a step while active (player has been noticed). This must be one of the values in `enum SpeedOWE`.
- `returnToIdle` is the condition under which the mon (while active) will go back to idly wandering. The three possible parameters are `PLAYER_OUTSIDE_ACTIVE_RANGE`, `PLAYER_CANT_BE_SEEN`, and `NEVER_RETURN`.

If any of these parameters are not defined, they will be automatically assigned the value of `0`.

A small number of premade behaviors have been provided and are ready to use. You can add as many new custom behaviors as you like, but make sure to add each behavior to `enum OverworldWildEncounterBehaviors`, making sure that `OWE_SPECIES_BEHAVIOR_COUNT` is always at the end.

The same behavior can be used for multiple different species.

## OWE Movements
While OWE objects can be given any movement type, there are several different custom movement types that were made specifically for OWEs:
- The basic one is `MOVEMENT_TYPE_WANDER_AROUND_OWE`. All of the other OWE movement types start with this behavior and differentiate into other behavior when they notice the player. Similar to `MOVEMENT_TYPE_WANDER_AROUND`, the object will take steps in random directions at random intervals. The main difference here is that the object will never turn more than 90 degrees from their current facing direction when taking a step. OWEs with this movement type will completely ignore the player until they are directly collided/interacted with.
- `MOVEMENT_TYPE_CHASE_PLAYER_OWE` will switch the OWE to chasing down the player when it notices the player. The OWE is still blocked by collision, but does have the intelligence to walk around small obstacles. They will go back to wandering if the player goes outside of their sight radius.
- `MOVEMENT_TYPE_FLEE_PLAYER_OWE` will switch the OWE to fleeing from the player when it notices the player. They use the same pathfinding logic as `MOVEMENT_TYPE_CHASE_PLAYER_OWE`, but in the opposite direction from the player. They will go back to wandering if the player goes outside of their sight radius. If `WE_OWE_FLEE_DESPAWN` is set to `TRUE`, the fleeing OWE will despawn if it is unable to take a step for a short amount of time (ie, if they are cornered).
- `MOVEMENT_TYPE_WATCH_PLAYER_OWE` will switch the OWE to stand in place and always face in the direction of the player's location when the player is noticed by it. They will go back to wandering if the player goes outside of their sight radius.
- `MOVEMENT_TYPE_APPROACH_PLAYER_OWE` will switch the OWE to approach the player as if curious when it notices the player. The OWE will try to keep a one tile gap between itself and the player. They may also occasionally do an excited hop. They will go back to wandering if the player goes outside of their sight radius.
- `MOVEMENT_TYPE_DESPAWN_OWE` will make the OWE do a very brief animation of surprise and then instantly despawn when it notices the player.

### Restricted Movements
There are two configs that can restrict the movement of OWEs. Both are `TRUE` by default.
- `WE_OWE_RESTRICT_METATILE` will restrict OWE movement to the metatile type they spawned on. For example, if an OWE spawns in a grass patch they will not be able to leave that grass patch.
- `WE_OWE_RESTRICT_MAP` will prevent OWEs from leaving the map that they were spawned in.

Regardless of configs, OWEs cannot move from water onto land, or vice versa.

### How Data is Saved
Some existing members of the `ObjectEvent` struct have been repurposed for OWEs. This has no effect on the existing functionality outside of OWEs.

```
struct ObjectEvent
{
    …
    u8 warpArrowSpriteId;        // Stores encounter category for Overworld Encounters, as well as some bit flags.
    …
    u8 trainerRange_berryTreeId; // Stores the level for Overworld Encounters.
    …
    u8 playerCopyableMovement;   // Stores the age for Overworld Encounters.
    …
}
```
