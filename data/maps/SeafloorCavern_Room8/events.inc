SeafloorCavern_Room8_EventObjects: @ 8535B04
	object_event 1, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 4, 7, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, FLAG_TEMP_11
	object_event 2, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 5, 7, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, FLAG_TEMP_12
	object_event 3, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 6, 7, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, FLAG_TEMP_13
	object_event 4, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 3, 6, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, FLAG_TEMP_14
	object_event 5, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 7, 6, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, FLAG_TEMP_15
	object_event 6, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 4, 5, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, FLAG_TEMP_16
	object_event 7, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 5, 5, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, FLAG_TEMP_17
	object_event 8, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 6, 5, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, FLAG_TEMP_18
	object_event 9, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 3, 4, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, FLAG_TEMP_19
	object_event 10, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 4, 4, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, FLAG_TEMP_1A
	object_event 11, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 6, 4, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, FLAG_TEMP_1B
	object_event 12, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 7, 4, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, FLAG_TEMP_1C

SeafloorCavern_Room8_MapWarps: @ 8535C24
	warp_def 5, 2, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM9
	warp_def 5, 12, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM3

SeafloorCavern_Room8_MapEvents:: @ 8535C34
	map_events SeafloorCavern_Room8_EventObjects, SeafloorCavern_Room8_MapWarps, 0x0, 0x0

