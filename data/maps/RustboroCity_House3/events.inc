RustboroCity_House3_EventObjects: @ 8530BC0
	object_event 1, EVENT_OBJ_GFX_OLD_MAN, 0, 4, 5, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, RustboroCity_House3_EventScript_216191, 0
	object_event 2, EVENT_OBJ_GFX_OLD_WOMAN, 0, 7, 5, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, RustboroCity_House3_EventScript_21619A, 0
	object_event 3, EVENT_OBJ_GFX_PIKACHU, 0, 4, 4, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, RustboroCity_House3_EventScript_2161A3, 0

RustboroCity_House3_MapWarps: @ 8530C08
	warp_def 5, 8, 0, 11, MAP_RUSTBORO_CITY
	warp_def 6, 8, 0, 11, MAP_RUSTBORO_CITY

RustboroCity_House3_MapEvents:: @ 8530C18
	map_events RustboroCity_House3_EventObjects, RustboroCity_House3_MapWarps, 0x0, 0x0

