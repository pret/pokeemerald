BirthIsland_Exterior_EventObjects: @ 853D7DC
	object_event 1, EVENT_OBJ_GFX_DEOXYS_TRIANGLE, 0, 15, 12, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, BirthIsland_Exterior_EventScript_267F83, FLAG_0x2FC
	object_event 2, EVENT_OBJ_GFX_DEOXYS, 0, 15, 3, 0, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, 0x0, FLAG_0x2FB

BirthIsland_Exterior_MapWarps: @ 853D80C
	warp_def 15, 24, 0, 0, MAP_BIRTH_ISLAND_HARBOR

BirthIsland_Exterior_MapEvents:: @ 853D814
	map_events BirthIsland_Exterior_EventObjects, BirthIsland_Exterior_MapWarps, 0x0, 0x0

