RustboroCity_House2_EventObjects: @ 8530A70
	object_event 1, EVENT_OBJ_GFX_WOMAN_2, 0, 0, 4, 4, 3, 8, 0, 0, 0, 0, RustboroCity_House2_EventScript_215EB4, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_LITTLE_GIRL_2, 0, 0, 4, 5, 3, 7, 0, 0, 0, 0, RustboroCity_House2_EventScript_215EBD, 0, 0, 0

RustboroCity_House2_MapWarps: @ 8530AA0
	warp_def 5, 8, 0, 9, MAP_RUSTBORO_CITY
	warp_def 6, 8, 0, 9, MAP_RUSTBORO_CITY

RustboroCity_House2_MapEvents:: @ 8530AB0
	map_events RustboroCity_House2_EventObjects, RustboroCity_House2_MapWarps, 0x0, 0x0

