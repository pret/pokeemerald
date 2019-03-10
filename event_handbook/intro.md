# The Emerald Event Handbook

## Goals

This handbook is intended to be a thorough documentation of the pokeemerald event system.
It aims to document:
- State changes
- Event chains
- Flags and variables used
- Map locations
- Unknown behaviors

This documentation is intended to be extremely thorough; it's a substitute for
code comments, not a walkthrough. If it's an event, it will be documented here.

Flags relating to gender differences during events can be briefly explained, rather than full documentation. There are simply far too many of them, and naming conventions will be sufficient.

## Why not just use comments?

Code comments are preferable where possible; however, there are two problems with emerald's
event system that prevent the use of comments for thorough event docs:
- The code order must stay consistent. Related events, variables, and functions cannot be
  pulled into a single file with a comment at the top; nor even a single section of a file.
- The event code is spread widely across the codebase. There are many interlocking parts, and
  often multiple things happening simultaneously. This makes following control flow extremely
  difficult.

## Organization

I don't know how exactly this is going to be organized, but I'm going to start by going through
each map, in roughly the order the player would visit.

Maps:
- [ ] Littleroot Town
- [ ] Route 101
- [ ] Oldale Town
- [ ] Route 103
- [ ] Route 102
- [ ] Petalburg City
- [ ] Route 104
- [ ] Petalburg Woods
- [ ] Rustboro City
- [ ] Route 116
- [ ] Rusturf Tunnel
- [ ] Rustboro City
- [ ] Dewford Town
- [ ] Granite Cave

# About the Event System

Events fall into a few broad categories:
- Warp Events
- Object Events
- Background Events
- Coord Events
- Map Header Events

The events that can be triggered at any time are encoded into the map header data for the current map. They can be found by looking into the `data/maps/<map name>/map.json` file, and the corresponding `scripts.inc` file.

If you want to modify how an event is set up, or add a new one, the `porymap` tool is very useful. However, any script writing will have to be done by hand.

## Warp Events

The simplest event is a Warp Event. These events do not use scripts; they are simply special tiles on the map that warp to a predefined location. The location they warp to is defined by their `dest_warp_id` and `map_id`. The `map_id` field contains the unique ID for a map, and the `dest_warp_id` is an index into that map's warp events array. (Indexes start at 0.)

For example, the warp tile for the door to Professor Birch's lab is defined:
```json
{
    "x": 7,
    "y": 16,
    "elevation": 0,
    "dest_map": "MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB",
    "dest_warp_id": 0
}
```

The `x`, `y`, and `elevation` fields are the warp tile's location on the LittlerootTown map. The destination map is Professor Birch's lab, and the destination warp has index 0. In the `map.json` file for the lab, the entry at index 0 (the 1st entry) in the warp event array is:
```json
{
    "x": 6,
    "y": 12,
    "elevation": 0,
    "dest_map": "MAP_LITTLEROOT_TOWN",
    "dest_warp_id": 2
}
```
So when the warp event is activated, the player will be warped to `x = 6, y = 12, elevation = 0` on the lab map.

Warp tiles genenerally come in pairs that connect to each other. In the example above, the warp tile in the lab points back to the warp event in Littleroot Town. (Note that the lab's warp tile is at index 2 (the 3rd entry) in the Littleroot Town map.) Doors that are two tiles wide pick a particular side. In the above example, the door into the lab is just one tile, while the door out of the lab is two tiles wide. The warp into the lap just picks one of the two door tiles, the choice is mostly up to preference. Both warp tiles in the lab point to the same warp tile in the town.

There is a special kind of warp event called a "dynamic warp". Dynamic warps are warp events that have a special `dest_warp_id`: `127`. Warp events with this destination can be customized and changed by event scripts, via the `setwarp` script command.

## Object Events

Object Events are event scripts tied to a specific sprite. These events are run whenever the player interacts with them (i.e. presses "A" while facing them). These events often involve starting dialog, conversations, or just making a message box describing the object.

The script that is run is given by the `script` field of the event. The script can be found in the corresponding `scripts.inc` file. Their sprite is given by the `graphics_id` field. The `movement_type` field used to specify what direction the player must be facing to interact with the object. For example, a sign that can only be read from the front would use `MOVEMENT_TYPE_FACE_UP`. If an object doesn't have a script associated with it, the script field will be `0x0`.

Object Events can be hidden with the `flag` field. The flag can be a constant number (`0` or `1`), or the name of a global scripting variable (such as `FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE`). The flag is `1` if the object should be hidden, and it is visible if the flag is `0`. (TODO: When exactly is this flag checked? Just on load, or continuously?)

### Trainers

Object Events are also used for trainers. Their `trainer_type` indicates what sprite they have (Cool Trainer / Bug Catcher), and the length of their "vision" is given by `trainer_sight_or_berry_tree_id`, measured in tiles. (TODO: More detail about how trainers are encoded, and how they move.)

### Berry Trees

(TODO: Berry trees?)

## TODO: Background Events

## TODO: Coord Events

## Map Header Events

There are a few special types of map event that aren't associated with a particular place or thing. These are Map Header events. There are seven types of Map Header events:

- OnMapLoad
- OnMapTransition
- OnMapResume
- OnReturnToField
- OnMapDiveWarp
- OnInput
- OnWarpIntoMap

A map can only have one event of each kind at any time, except for OnInput and OnWarpIntoMap events. Maps can contain a table of OnInput and OnWarpIntoMap events.

Event tables are a list of events along with a condition for when they should be run. Whenever a table is checked, the event system will start at the top of the table, and check each condition in order. The conditions are a pair of values before the script name. If the two values are equal, the event script is run. Note that once an event is found, the rest of the table is ignored.

The "values" in these condition pairs can be a fixed constant, or the name of a variable. For example, if an event has the form: `map_script_2 VAR_INTRO_SEQUENCE_STATE, 1, LittlerootTown_EventScript_BrendanExitMovingTruck`, then this script will only intercept the event if `VAR_INTRO_SEQUENCE_STATE` is set to 1.

### OnMapLoad Script

This event script is run whenever a map is loaded into memory. It will be run regardless of how the map is being loaded, whether from a save file or by normal means.

### OnMapTransition Script

This event script, like OnMapLoad, is run whenever a map is loaded into memory. However, it is only run when the player is moving from one map to another; it is not run when the player loads a save file. This script will run before OnMapLoad.

### OnMapResume Script

This event script is run to resume the animations, timers, and general operation of a map. This happens when the player exits a menu, such as the start menu.

Note that maps are loaded in a "paused" state, so this script is also run when a map had finished loading (after both OnMapTransition and OnMapLoad). It is not run after loading from a save file.

### OnReturnToField Script

This event script is run whenever the CB2_ReturnToField function is called. The exact times that ReturnToField is called haven't been fully documented yet.

OnMapResume is always called before this script.

### OnMapDiveWarp Script

This event script runs when the player attempts to use Dive on a tile that doesn't have a map connection. Rather than immediately failing, the event system will run this script, allowing the script to "intercept" the Dive and warp the player to a custom location. The custom location is set through the `setdivewarp` script command.

### OnMapFrame Table

This table is checked every frame, unless an event is already running. If a script is run on this table, then any button press during this frame is "intercepted" and is not used for anything else (like movement). 

### OnWarpIntoMap Table