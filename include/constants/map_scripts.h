#ifndef GUARD_CONSTANTS_MAP_SCRIPTS_H
#define GUARD_CONSTANTS_MAP_SCRIPTS_H

/*
    IDs for special scripts that can be run for a particular map.
    For the functions that handle when they are run, see these constants' uses in src/script.c

    Below describes when a script of this kind will be called, and what it typically does.
    They are numbered in the order that they will be called when entering a map (from a warp or camera transition).
    NOTE: These descriptions are just of what they generally do, not what they always or have to do

    3. ON_LOAD: Run after the layout is loaded (but not drawn yet).
                Almost exclusively used to set metatiles on the map before it's first drawn

    6. ON_FRAME_TABLE: Run every frame after the map has faded in, before player input is processed.
                       This is a table of scripts that each run if their condition is satisfied.
                       Used to trigger an event, such as the player exiting the cable car or the SS Tidal sailor announcing progress

    2. ON_TRANSITION: Run during the transition to the map
                      Used to set map-specific flags/vars, update object positions/movement types, set weather, etc

    5. ON_WARP_INTO_MAP_TABLE: Run after the map's objects are loaded.
                               This is a table of scripts that each run if their condition is satisfied.
                               Used to add objects to the scene or update something about the player as they warp in (e.g. their facing dir or visibility)
                               Note that ON_TRANSITION may also handle object visibility, but would do so by modifying a flag or var

    4. ON_RESUME: Run at the end of map load, and again any time upon returning to field (e.g. exiting the Bag menu, or finishing a battle)
                  Used to hide defeated static pokemon, or maintain some map state (e.g. the Trainer Hill timer, or the cycling road challenge)
                  In some maps this takes the metatile setting job of ON_LOAD

    1. ON_DIVE_WARP: Run after the player chooses to dive/emerge.
                     Only used once, to determine whether or not the player should emerge in the Sealed Chamber

    x. ON_RETURN_TO_FIELD: Run exlusively upon returning to the field, shortly after ON_RESUME (as opposed to ON_RESUME, which also runs once on entering the map)
                           Used rarely, when something must only happen on reload (e.g. making sure Mew is above the grass after battling it on Faraway Island)

*/

#define MAP_SCRIPT_ON_LOAD 1
#define MAP_SCRIPT_ON_FRAME_TABLE 2
#define MAP_SCRIPT_ON_TRANSITION 3
#define MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE 4
#define MAP_SCRIPT_ON_RESUME 5
#define MAP_SCRIPT_ON_DIVE_WARP 6
#define MAP_SCRIPT_ON_RETURN_TO_FIELD 7

#endif // GUARD_CONSTANTS_MAP_SCRIPTS_H
