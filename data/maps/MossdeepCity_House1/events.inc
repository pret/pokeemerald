MossdeepCity_House1_EventObjects: @ 8532978
	object_event 1, EVENT_OBJ_GFX_BLACK_BELT, 0, 3, 3, 3, MOVEMENT_TYPE_WANDER_UP_AND_DOWN, 1, 1, 0, 0, MossdeepCity_House1_EventScript_221FD6, 0
	object_event 2, EVENT_OBJ_GFX_WOMAN_3, 0, 7, 4, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, MossdeepCity_House1_EventScript_222006, 0

MossdeepCity_House1_MapWarps: @ 85329A8
	warp_def 3, 7, 0, 0, MAP_MOSSDEEP_CITY
	warp_def 4, 7, 0, 0, MAP_MOSSDEEP_CITY

MossdeepCity_House1_MapEvents:: @ 85329B8
	map_events MossdeepCity_House1_EventObjects, MossdeepCity_House1_MapWarps, 0x0, 0x0

