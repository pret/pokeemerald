SeafloorCavern_Room2_EventObjects: @ 853579C
	object_event 1, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 13, 3, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room2_EventScript_2908BA, 18
	object_event 2, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 10, 3, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room2_EventScript_2908BA, 19
	object_event 3, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 13, 5, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room2_EventScript_2908BA, 17
	object_event 4, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 4, 5, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room2_EventScript_2908BA, 21
	object_event 5, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 7, 4, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room2_EventScript_2908BA, 22
	object_event 6, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 8, 7, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room2_EventScript_2907A6, 24
	object_event 7, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 9, 3, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room2_EventScript_2907A6, 25
	object_event 8, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 4, 8, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room2_EventScript_2908BA, 23

SeafloorCavern_Room2_MapWarps: @ 853585C
	warp_def 10, 7, 3, 2, MAP_SEAFLOOR_CAVERN_ROOM1
	warp_def 4, 10, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM4
	warp_def 6, 1, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM6
	warp_def 11, 1, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM7

SeafloorCavern_Room2_MapEvents:: @ 853587C
	map_events SeafloorCavern_Room2_EventObjects, SeafloorCavern_Room2_MapWarps, 0x0, 0x0

