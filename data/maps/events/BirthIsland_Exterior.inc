BirthIsland_Exterior_MapObjects: @ 853D7DC
	object_event 1, MAP_OBJ_GFX_DEOXYS_TRIANGLE, 0, 0, 15, 12, 3, 8, 17, 0, 0, 0, BirthIsland_Exterior_EventScript_267F83, 764, 0, 0
	object_event 2, MAP_OBJ_GFX_DEOXYS, 0, 0, 15, 3, 0, 8, 17, 0, 0, 0, 0x0, 763, 0, 0

BirthIsland_Exterior_MapWarps: @ 853D80C
	warp_def 15, 24, 0, 0, BIRTH_ISLAND_HARBOR

BirthIsland_Exterior_MapEvents:: @ 853D814
	map_events BirthIsland_Exterior_MapObjects, BirthIsland_Exterior_MapWarps, 0x0, 0x0

