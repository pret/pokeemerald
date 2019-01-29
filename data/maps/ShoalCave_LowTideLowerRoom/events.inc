ShoalCave_LowTideLowerRoom_EventObjects:
	object_event 1, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 25, 3, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, ShoalCave_LowTideLowerRoom_EventScript_2908BA, FLAG_TEMP_11
	object_event 2, EVENT_OBJ_GFX_BLACK_BELT, 0, 11, 4, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, ShoalCave_LowTideLowerRoom_EventScript_2371B2, 0

ShoalCave_LowTideLowerRoom_MapWarps:
	warp_def 7, 2, 3, 3, MAP_SHOAL_CAVE_LOW_TIDE_INNER_ROOM
	warp_def 2, 6, 3, 4, MAP_SHOAL_CAVE_LOW_TIDE_INNER_ROOM
	warp_def 19, 11, 3, 5, MAP_SHOAL_CAVE_LOW_TIDE_INNER_ROOM
	warp_def 28, 11, 3, 0, MAP_SHOAL_CAVE_LOW_TIDE_ICE_ROOM

ShoalCave_LowTideLowerRoom_MapBGEvents:
	bg_event 18, 2, 3, BG_EVENT_PLAYER_FACING_ANY, ShoalCave_LowTideLowerRoom_EventScript_237176

ShoalCave_LowTideLowerRoom_MapEvents::
	map_events ShoalCave_LowTideLowerRoom_EventObjects, ShoalCave_LowTideLowerRoom_MapWarps, 0x0, ShoalCave_LowTideLowerRoom_MapBGEvents

