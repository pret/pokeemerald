IslandCave_EventObjects: @ 8536C74
	object_event 1, EVENT_OBJ_GFX_REGICE, 0, 8, 7, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, IslandCave_EventScript_238F58, FLAG_0x3A8

IslandCave_MapWarps: @ 8536C8C
	warp_def 8, 29, 3, 0, MAP_ROUTE105
	warp_def 8, 20, 0, 2, MAP_ISLAND_CAVE
	warp_def 8, 11, 3, 1, MAP_ISLAND_CAVE

IslandCave_MapBGEvents: @ 8536CA4
	bg_event 8, 20, 0, BG_EVENT_PLAYER_FACING_ANY, IslandCave_EventScript_238EEF
	bg_event 7, 20, 0, BG_EVENT_PLAYER_FACING_ANY, IslandCave_EventScript_238F1D
	bg_event 9, 20, 0, BG_EVENT_PLAYER_FACING_ANY, IslandCave_EventScript_238F1D

IslandCave_MapEvents:: @ 8536CC8
	map_events IslandCave_EventObjects, IslandCave_MapWarps, 0x0, IslandCave_MapBGEvents

