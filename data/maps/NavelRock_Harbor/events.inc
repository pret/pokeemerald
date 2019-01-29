NavelRock_Harbor_EventObjects:
	object_event 1, EVENT_OBJ_GFX_SAILOR, 0, 8, 5, 0, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, NavelRock_Harbor_EventScript_2690BD, 0
	object_event 2, EVENT_OBJ_GFX_SS_TIDAL, 0, 8, 7, 1, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 0, 0, 0x0, 0

NavelRock_Harbor_MapWarps:
	warp_def 8, 2, 0, 0, MAP_NAVEL_ROCK_EXTERIOR

NavelRock_Harbor_MapEvents::
	map_events NavelRock_Harbor_EventObjects, NavelRock_Harbor_MapWarps, 0x0, 0x0

