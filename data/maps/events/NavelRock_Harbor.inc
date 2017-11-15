NavelRock_Harbor_MapObjects: @ 853DA24
	object_event 1, MAP_OBJ_GFX_SAILOR, 0, 0, 8, 5, 0, 7, 17, 0, 0, 0, NavelRock_Harbor_EventScript_2690BD, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_SS_TIDAL, 0, 0, 8, 7, 1, 10, 17, 0, 0, 0, 0x0, 0, 0, 0

NavelRock_Harbor_MapWarps: @ 853DA54
	warp_def 8, 2, 0, 0, NAVEL_ROCK_EXTERIOR

NavelRock_Harbor_MapEvents:: @ 853DA5C
	map_events NavelRock_Harbor_MapObjects, NavelRock_Harbor_MapWarps, 0x0, 0x0

