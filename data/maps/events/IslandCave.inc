IslandCave_EventObjects: @ 8536C74
	object_event 1, EVENT_OBJ_GFX_REGICE, 0, 0, 8, 7, 3, 8, 0, 0, 0, 0, IslandCave_EventScript_238F58, 936, 0, 0

IslandCave_MapWarps: @ 8536C8C
	warp_def 8, 29, 3, 0, ROUTE_105
	warp_def 8, 20, 0, 2, ISLAND_CAVE
	warp_def 8, 11, 3, 1, ISLAND_CAVE

IslandCave_MapBGEvents: @ 8536CA4
	bg_event 8, 20, 0, 0, 0, IslandCave_EventScript_238EEF
	bg_event 7, 20, 0, 0, 0, IslandCave_EventScript_238F1D
	bg_event 9, 20, 0, 0, 0, IslandCave_EventScript_238F1D

IslandCave_MapEvents:: @ 8536CC8
	map_events IslandCave_EventObjects, IslandCave_MapWarps, 0x0, IslandCave_MapBGEvents

