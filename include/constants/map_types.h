#ifndef GUARD_CONSTANTS_MAP_TYPES_H
#define GUARD_CONSTANTS_MAP_TYPES_H

#define MAP_TYPE_0           0
#define MAP_TYPE_TOWN        1
#define MAP_TYPE_CITY        2
#define MAP_TYPE_ROUTE       3
#define MAP_TYPE_UNDERGROUND 4
#define MAP_TYPE_UNDERWATER  5
#define MAP_TYPE_6           6
#define MAP_TYPE_7           7
#define MAP_TYPE_INDOOR      8
#define MAP_TYPE_SECRET_BASE 9

#define MAP_BATTLE_SCENE_NORMAL       0
#define MAP_BATTLE_SCENE_GYM          1
#define MAP_BATTLE_SCENE_MAGMA        2
#define MAP_BATTLE_SCENE_AQUA         3
#define MAP_BATTLE_SCENE_SIDNEY       4
#define MAP_BATTLE_SCENE_PHOEBE       5
#define MAP_BATTLE_SCENE_GLACIA       6
#define MAP_BATTLE_SCENE_DRAKE        7
#define MAP_BATTLE_SCENE_FRONTIER     8

/* Map Script Types
 * 
 * MAP_SCRIPT_SET_METATILES - Set metatiles
 * MAP_SCRIPT_TRIGGER_EVENTS - Trigger scripted events
 * MAP_SCRIPT_SET_DATA - Set flags, vars, and objects
 * MAP_SCRIPT_TRIGGER_MAP_SCRIPTS - Trigger other map scripts
 * MAP_SCRIPT_TRIGGER_SPECIALS - Trigger specials and set step callbacks
 * MAP_SCRIPT_TYPE_SET_DIVE_WARP - Set dive warp
 * MAP_SCRIPT_TYPE_7 - Load special sprites and/or palettes?
*/
#define MAP_SCRIPT_SET_METATILES 1
#define MAP_SCRIPT_TRIGGER_EVENTS 2
#define MAP_SCRIPT_SET_DATA 3
#define MAP_SCRIPT_TRIGGER_MAP_SCRIPTS 4
#define MAP_SCRIPT_TRIGGER_SPECIALS 5
#define MAP_SCRIPT_SET_DIVE_WARP 6
#define MAP_SCRIPT_TYPE_7 7


#endif  // GUARD_CONSTANTS_MAP_TYPES_H
