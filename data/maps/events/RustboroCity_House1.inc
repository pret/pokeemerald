RustboroCity_House1_EventObjects: @ 85309C8
	object_event 1, EVENT_OBJ_GFX_CAMPER, 0, 0, 6, 4, 3, 9, 0, 0, 0, 0, RustboroCity_House1_EventScript_21593F, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_HIKER, 0, 0, 9, 2, 3, 8, 0, 0, 0, 0, RustboroCity_House1_EventScript_2159DF, 0, 0, 0

RustboroCity_House1_MapWarps: @ 85309F8
	warp_def 5, 7, 0, 7, RUSTBORO_CITY
	warp_def 6, 7, 0, 7, RUSTBORO_CITY

RustboroCity_House1_MapEvents:: @ 8530A08
	map_events RustboroCity_House1_EventObjects, RustboroCity_House1_MapWarps, 0x0, 0x0

