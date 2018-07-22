FarawayIsland_Interior_EventObjects: @ 853D7A0
	object_event 1, EVENT_OBJ_GFX_MEW, 0, 13, 17, 3, MOVEMENT_TYPE_COPY_PLAYER_OPPOSITE_IN_GRASS, 15, 15, 0, 1, FarawayIsland_Interior_EventScript_267DF2, 718

FarawayIsland_Interior_MapWarps: @ 853D7B8
	warp_def 12, 19, 0, 0, MAP_FARAWAY_ISLAND_ENTRANCE
	warp_def 13, 19, 0, 1, MAP_FARAWAY_ISLAND_ENTRANCE

FarawayIsland_Interior_MapEvents:: @ 853D7C8
	map_events FarawayIsland_Interior_EventObjects, FarawayIsland_Interior_MapWarps, 0x0, 0x0

