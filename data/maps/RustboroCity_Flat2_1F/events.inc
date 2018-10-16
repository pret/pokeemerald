RustboroCity_Flat2_1F_EventObjects: @ 8530AC4
	object_event 1, EVENT_OBJ_GFX_SKITTY, 0, 11, 4, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, RustboroCity_Flat2_1F_EventScript_215F80, 0
	object_event 2, EVENT_OBJ_GFX_OLD_WOMAN, 0, 8, 4, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, RustboroCity_Flat2_1F_EventScript_215F77, 0

RustboroCity_Flat2_1F_MapWarps: @ 8530AF4
	warp_def 2, 8, 0, 10, MAP_RUSTBORO_CITY
	warp_def 3, 8, 0, 10, MAP_RUSTBORO_CITY
	warp_def 3, 1, 0, 0, MAP_RUSTBORO_CITY_FLAT2_2F

RustboroCity_Flat2_1F_MapEvents:: @ 8530B0C
	map_events RustboroCity_Flat2_1F_EventObjects, RustboroCity_Flat2_1F_MapWarps, 0x0, 0x0

