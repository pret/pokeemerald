RustboroCity_Flat1_1F_EventObjects: @ 8530890
	object_event 1, EVENT_OBJ_GFX_MAN_4, 0, 9, 4, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, RustboroCity_Flat1_1F_EventScript_2150CE, 0
	object_event 2, EVENT_OBJ_GFX_WOMAN_7, 0, 12, 4, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, RustboroCity_Flat1_1F_EventScript_2150D7, 0

RustboroCity_Flat1_1F_MapWarps: @ 85308C0
	warp_def 6, 7, 0, 1, MAP_RUSTBORO_CITY
	warp_def 7, 7, 0, 1, MAP_RUSTBORO_CITY
	warp_def 2, 1, 0, 0, MAP_RUSTBORO_CITY_FLAT1_2F

RustboroCity_Flat1_1F_MapEvents:: @ 85308D8
	map_events RustboroCity_Flat1_1F_EventObjects, RustboroCity_Flat1_1F_MapWarps, 0x0, 0x0

