RustboroCity_Flat1_1F_MapObjects: @ 8530890
	object_event 1, MAP_OBJ_GFX_MAN_4, 0, 0, 9, 4, 3, 10, 0, 0, 0, 0, RustboroCity_Flat1_1F_EventScript_2150CE, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_WOMAN_7, 0, 0, 12, 4, 3, 9, 0, 0, 0, 0, RustboroCity_Flat1_1F_EventScript_2150D7, 0, 0, 0

RustboroCity_Flat1_1F_MapWarps: @ 85308C0
	warp_def 6, 7, 0, 1, RUSTBORO_CITY
	warp_def 7, 7, 0, 1, RUSTBORO_CITY
	warp_def 2, 1, 0, 0, RUSTBORO_CITY_FLAT_1_2F

RustboroCity_Flat1_1F_MapEvents:: @ 85308D8
	map_events RustboroCity_Flat1_1F_MapObjects, RustboroCity_Flat1_1F_MapWarps, 0x0, 0x0

