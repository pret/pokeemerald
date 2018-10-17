SeafloorCavern_Room5_EventObjects: @ 85359F8
	object_event 1, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 3, 11, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room5_EventScript_2908BA, FLAG_TEMP_11
	object_event 2, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 4, 11, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room5_EventScript_2908BA, FLAG_TEMP_12
	object_event 3, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 11, 7, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room5_EventScript_2908BA, FLAG_TEMP_13
	object_event 4, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 3, 13, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room5_EventScript_2907A6, FLAG_TEMP_15
	object_event 5, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 13, 8, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room5_EventScript_2907A6, FLAG_TEMP_16
	object_event 6, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 12, 8, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room5_EventScript_2908BA, FLAG_TEMP_14

SeafloorCavern_Room5_MapWarps: @ 8535A88
	warp_def 4, 1, 3, 1, MAP_SEAFLOOR_CAVERN_ROOM1
	warp_def 15, 12, 3, 1, MAP_SEAFLOOR_CAVERN_ROOM4
	warp_def 7, 17, 3, 2, MAP_SEAFLOOR_CAVERN_ROOM4

SeafloorCavern_Room5_MapEvents:: @ 8535AA0
	map_events SeafloorCavern_Room5_EventObjects, SeafloorCavern_Room5_MapWarps, 0x0, 0x0

