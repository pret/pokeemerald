RustboroCity_House1_EventObjects: @ 85309C8
	object_event 1, EVENT_OBJ_GFX_CAMPER, 0, 6, 4, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, RustboroCity_House1_EventScript_21593F, 0
	object_event 2, EVENT_OBJ_GFX_HIKER, 0, 9, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, RustboroCity_House1_EventScript_2159DF, 0

RustboroCity_House1_MapWarps: @ 85309F8
	warp_def 5, 7, 0, 7, MAP_RUSTBORO_CITY
	warp_def 6, 7, 0, 7, MAP_RUSTBORO_CITY

RustboroCity_House1_MapEvents:: @ 8530A08
	map_events RustboroCity_House1_EventObjects, RustboroCity_House1_MapWarps, 0x0, 0x0

