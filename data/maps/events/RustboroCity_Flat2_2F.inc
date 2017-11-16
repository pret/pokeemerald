RustboroCity_Flat2_2F_MapObjects: @ 8530B20
	object_event 1, MAP_OBJ_GFX_OLD_MAN_2, 0, 0, 11, 4, 3, 10, 0, 0, 0, 0, RustboroCity_Flat2_2F_EventScript_215FD8, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_LITTLE_BOY_1, 0, 0, 7, 3, 3, 5, 2, 0, 0, 0, RustboroCity_Flat2_2F_EventScript_215FE1, 0, 0, 0

RustboroCity_Flat2_2F_MapWarps: @ 8530B50
	warp_def 3, 1, 0, 2, RUSTBORO_CITY_FLAT_2_1F
	warp_def 1, 1, 0, 0, RUSTBORO_CITY_FLAT_2_3F

RustboroCity_Flat2_2F_MapEvents:: @ 8530B60
	map_events RustboroCity_Flat2_2F_MapObjects, RustboroCity_Flat2_2F_MapWarps, 0x0, 0x0

