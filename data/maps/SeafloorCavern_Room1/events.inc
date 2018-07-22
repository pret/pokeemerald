SeafloorCavern_Room1_EventObjects: @ 85356F8
	object_event 1, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 5, 11, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room1_EventScript_2908BA, 17
	object_event 2, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 12, 11, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room1_EventScript_2908BA, 18
	object_event 3, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 5, 10, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, SeafloorCavern_Room1_EventScript_2907A6, 19
	object_event 4, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 8, 6, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 1, 2, SeafloorCavern_Room1_EventScript_2347EC, 946
	object_event 5, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 15, 10, 3, MOVEMENT_TYPE_FACE_UP_AND_RIGHT, 1, 1, 1, 3, SeafloorCavern_Room1_EventScript_234803, 946

SeafloorCavern_Room1_MapWarps: @ 8535770
	warp_def 5, 18, 3, 1, MAP_SEAFLOOR_CAVERN_ENTRANCE
	warp_def 17, 13, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM5
	warp_def 6, 2, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM2

SeafloorCavern_Room1_MapEvents:: @ 8535788
	map_events SeafloorCavern_Room1_EventObjects, SeafloorCavern_Room1_MapWarps, 0x0, 0x0

