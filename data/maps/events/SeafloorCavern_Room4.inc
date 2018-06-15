SeafloorCavern_Room4_EventObjects: @ 8535994
	object_event 1, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 5, 8, 3, 17, 17, 1, 3, SeafloorCavern_Room4_EventScript_234C9C, 946
	object_event 2, EVENT_OBJ_GFX_AQUA_MEMBER_F, 0, 5, 12, 3, 7, 17, 1, 3, SeafloorCavern_Room4_EventScript_234CB3, 946

SeafloorCavern_Room4_MapWarps: @ 85359C4
	warp_def 13, 1, 3, 1, MAP_SEAFLOOR_CAVERN_ROOM2
	warp_def 4, 1, 3, 1, MAP_SEAFLOOR_CAVERN_ROOM5
	warp_def 9, 10, 3, 2, MAP_SEAFLOOR_CAVERN_ROOM5
	warp_def 10, 15, 3, 1, MAP_SEAFLOOR_CAVERN_ENTRANCE

SeafloorCavern_Room4_MapEvents:: @ 85359E4
	map_events SeafloorCavern_Room4_EventObjects, SeafloorCavern_Room4_MapWarps, 0x0, 0x0

