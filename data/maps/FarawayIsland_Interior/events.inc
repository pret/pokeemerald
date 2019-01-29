FarawayIsland_Interior_EventObjects:
	object_event 1, EVENT_OBJ_GFX_MEW, 0, 13, 17, 3, MOVEMENT_TYPE_COPY_PLAYER_OPPOSITE_IN_GRASS, 15, 15, 0, 1, FarawayIsland_Interior_EventScript_267DF2, FLAG_HIDE_MEW

FarawayIsland_Interior_MapWarps:
	warp_def 12, 19, 0, 0, MAP_FARAWAY_ISLAND_ENTRANCE
	warp_def 13, 19, 0, 1, MAP_FARAWAY_ISLAND_ENTRANCE

FarawayIsland_Interior_MapEvents::
	map_events FarawayIsland_Interior_EventObjects, FarawayIsland_Interior_MapWarps, 0x0, 0x0

