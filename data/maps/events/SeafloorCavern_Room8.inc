SeafloorCavern_Room8_EventObjects: @ 8535B04
	object_event 1, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 4, 7, 3, 1, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, 17
	object_event 2, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 5, 7, 3, 1, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, 18
	object_event 3, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 6, 7, 3, 1, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, 19
	object_event 4, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 3, 6, 3, 1, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, 20
	object_event 5, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 7, 6, 3, 1, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, 21
	object_event 6, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 4, 5, 3, 1, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, 22
	object_event 7, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 5, 5, 3, 1, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, 23
	object_event 8, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 6, 5, 3, 1, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, 24
	object_event 9, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 3, 4, 3, 1, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, 25
	object_event 10, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 4, 4, 3, 1, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, 26
	object_event 11, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 6, 4, 3, 1, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, 27
	object_event 12, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 7, 4, 3, 1, 0, 0, 0, 0, SeafloorCavern_Room8_EventScript_2908BA, 28

SeafloorCavern_Room8_MapWarps: @ 8535C24
	warp_def 5, 2, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM9
	warp_def 5, 12, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM3

SeafloorCavern_Room8_MapEvents:: @ 8535C34
	map_events SeafloorCavern_Room8_EventObjects, SeafloorCavern_Room8_MapWarps, 0x0, 0x0

