SeafloorCavern_Room3_EventObjects: @ 8535890
	object_event 1, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 13, 10, 3, 1, 0, 0, 0, 0, SeafloorCavern_Room3_EventScript_2908BA, 18, 0, 0
	object_event 2, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 11, 10, 3, 1, 0, 0, 0, 0, SeafloorCavern_Room3_EventScript_2908BA, 20, 0, 0
	object_event 3, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 12, 9, 3, 1, 0, 0, 0, 0, SeafloorCavern_Room3_EventScript_2908BA, 21, 0, 0
	object_event 4, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 12, 7, 3, 1, 0, 0, 0, 0, SeafloorCavern_Room3_EventScript_2908BA, 22, 0, 0
	object_event 5, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 11, 8, 3, 1, 0, 0, 0, 0, SeafloorCavern_Room3_EventScript_2908BA, 23, 0, 0
	object_event 6, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 12, 11, 3, 1, 0, 0, 0, 0, SeafloorCavern_Room3_EventScript_2908BA, 24, 0, 0
	object_event 7, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 13, 8, 3, 1, 0, 0, 0, 0, SeafloorCavern_Room3_EventScript_2908BA, 25, 0, 0
	object_event 8, EVENT_OBJ_GFX_AQUA_MEMBER_F, 0, 0, 9, 5, 3, 9, 17, 0, 1, 6, SeafloorCavern_Room3_EventScript_234938, 946, 0, 0
	object_event 9, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 0, 5, 5, 3, 10, 17, 0, 1, 4, SeafloorCavern_Room3_EventScript_23494F, 946, 0, 0

SeafloorCavern_Room3_MapWarps: @ 8535968
	warp_def 8, 1, 3, 1, SEAFLOOR_CAVERN_ROOM_8
	warp_def 9, 13, 3, 1, SEAFLOOR_CAVERN_ROOM_7
	warp_def 4, 15, 3, 1, SEAFLOOR_CAVERN_ROOM_6

SeafloorCavern_Room3_MapEvents:: @ 8535980
	map_events SeafloorCavern_Room3_EventObjects, SeafloorCavern_Room3_MapWarps, 0x0, 0x0

