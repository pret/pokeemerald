SeafloorCavern_Room3_EventObjects: @ 8535890
	object_event 1, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 13, 10, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room3_EventScript_2908BA, FLAG_0x012
	object_event 2, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 11, 10, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room3_EventScript_2908BA, FLAG_0x014
	object_event 3, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 12, 9, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room3_EventScript_2908BA, FLAG_0x015
	object_event 4, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 12, 7, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room3_EventScript_2908BA, FLAG_0x016
	object_event 5, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 11, 8, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room3_EventScript_2908BA, FLAG_0x017
	object_event 6, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 12, 11, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room3_EventScript_2908BA, FLAG_0x018
	object_event 7, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 13, 8, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room3_EventScript_2908BA, FLAG_0x019
	object_event 8, EVENT_OBJ_GFX_AQUA_MEMBER_F, 0, 9, 5, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 1, 6, SeafloorCavern_Room3_EventScript_234938, FLAG_0x3B2
	object_event 9, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 5, 5, 3, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 1, 4, SeafloorCavern_Room3_EventScript_23494F, FLAG_0x3B2

SeafloorCavern_Room3_MapWarps: @ 8535968
	warp_def 8, 1, 3, 1, MAP_SEAFLOOR_CAVERN_ROOM8
	warp_def 9, 13, 3, 1, MAP_SEAFLOOR_CAVERN_ROOM7
	warp_def 4, 15, 3, 1, MAP_SEAFLOOR_CAVERN_ROOM6

SeafloorCavern_Room3_MapEvents:: @ 8535980
	map_events SeafloorCavern_Room3_EventObjects, SeafloorCavern_Room3_MapWarps, 0x0, 0x0

