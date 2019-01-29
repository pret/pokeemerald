BirthIsland_Harbor_EventObjects:
	object_event 1, EVENT_OBJ_GFX_SAILOR, 0, 8, 5, 0, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, BirthIsland_Harbor_EventScript_26805D, 0
	object_event 2, EVENT_OBJ_GFX_SS_TIDAL, 0, 8, 7, 1, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 0, 0, 0x0, 0

BirthIsland_Harbor_MapWarps:
	warp_def 8, 2, 0, 0, MAP_BIRTH_ISLAND_EXTERIOR

BirthIsland_Harbor_MapEvents::
	map_events BirthIsland_Harbor_EventObjects, BirthIsland_Harbor_MapWarps, 0x0, 0x0

