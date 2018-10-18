RustboroCity_Flat2_3F_EventObjects: @ 8530B74
	object_event 1, EVENT_OBJ_GFX_DEVON_EMPLOYEE, 0, 7, 3, 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT, 2, 0, 0, 0, RustboroCity_Flat2_3F_EventScript_216117, 0
	object_event 2, EVENT_OBJ_GFX_WOMAN_1, 0, 12, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, RustboroCity_Flat2_3F_EventScript_216120, 0

RustboroCity_Flat2_3F_MapWarps: @ 8530BA4
	warp_def 1, 1, 0, 1, MAP_RUSTBORO_CITY_FLAT2_2F

RustboroCity_Flat2_3F_MapEvents:: @ 8530BAC
	map_events RustboroCity_Flat2_3F_EventObjects, RustboroCity_Flat2_3F_MapWarps, 0x0, 0x0

