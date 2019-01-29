BirthIsland_Exterior_EventObjects:
	object_event 1, EVENT_OBJ_GFX_DEOXYS_TRIANGLE, 0, 15, 12, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, BirthIsland_Exterior_EventScript_267F83, FLAG_HIDE_BIRTH_ISLAND_DEOXYS_TRIANGLE
	object_event 2, EVENT_OBJ_GFX_DEOXYS, 0, 15, 3, 0, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, 0x0, FLAG_HIDE_DEOXYS

BirthIsland_Exterior_MapWarps:
	warp_def 15, 24, 0, 0, MAP_BIRTH_ISLAND_HARBOR

BirthIsland_Exterior_MapEvents::
	map_events BirthIsland_Exterior_EventObjects, BirthIsland_Exterior_MapWarps, 0x0, 0x0

