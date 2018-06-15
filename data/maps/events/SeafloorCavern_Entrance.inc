SeafloorCavern_Entrance_EventObjects: @ 85356BC
	object_event 1, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 10, 2, 3, 7, 1, 1, 0, 0, SeafloorCavern_Entrance_EventScript_234485, 941

SeafloorCavern_Entrance_MapWarps: @ 85356D4
	warp_def 10, 18, 3, 0, MAP_UNDERWATER4
	warp_def 10, 1, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM1

SeafloorCavern_Entrance_MapEvents:: @ 85356E4
	map_events SeafloorCavern_Entrance_EventObjects, SeafloorCavern_Entrance_MapWarps, 0x0, 0x0

