BirthIsland_Harbor_EventObjects: @ 853D828
	object_event 1, EVENT_OBJ_GFX_SAILOR, 0, 0, 8, 5, 0, 7, 17, 0, 0, 0, BirthIsland_Harbor_EventScript_26805D, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_SS_TIDAL, 0, 0, 8, 7, 1, 10, 17, 0, 0, 0, 0x0, 0, 0, 0

BirthIsland_Harbor_MapWarps: @ 853D858
	warp_def 8, 2, 0, 0, MAP_BIRTH_ISLAND_EXTERIOR

BirthIsland_Harbor_MapEvents:: @ 853D860
	map_events BirthIsland_Harbor_EventObjects, BirthIsland_Harbor_MapWarps, 0x0, 0x0

