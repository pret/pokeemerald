RustboroCity_DevonCorp_2F_EventObjects: @ 8530408
	object_event 1, EVENT_OBJ_GFX_SCIENTIST_1, 0, 6, 5, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, RustboroCity_DevonCorp_2F_EventScript_21186F, 0
	object_event 2, EVENT_OBJ_GFX_SCIENTIST_1, 0, 1, 5, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, RustboroCity_DevonCorp_2F_EventScript_211886, 0
	object_event 3, EVENT_OBJ_GFX_SCIENTIST_1, 0, 2, 6, 3, MOVEMENT_TYPE_FACE_UP_AND_LEFT, 0, 0, 0, 0, RustboroCity_DevonCorp_2F_EventScript_2118B0, 0
	object_event 4, EVENT_OBJ_GFX_SCIENTIST_1, 0, 10, 5, 3, MOVEMENT_TYPE_FACE_UP, 0, 10, 0, 0, RustboroCity_DevonCorp_2F_EventScript_2118DA, 0
	object_event 5, EVENT_OBJ_GFX_SCIENTIST_1, 0, 14, 8, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, RustboroCity_DevonCorp_2F_EventScript_2118F1, 0
	object_event 6, EVENT_OBJ_GFX_SCIENTIST_1, 0, 14, 5, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, RustboroCity_DevonCorp_2F_EventScript_211BCF, 0

RustboroCity_DevonCorp_2F_MapWarps: @ 8530498
	warp_def 14, 1, 0, 2, MAP_RUSTBORO_CITY_DEVON_CORP_1F
	warp_def 2, 1, 0, 0, MAP_RUSTBORO_CITY_DEVON_CORP_3F

RustboroCity_DevonCorp_2F_MapEvents:: @ 85304A8
	map_events RustboroCity_DevonCorp_2F_EventObjects, RustboroCity_DevonCorp_2F_MapWarps, 0x0, 0x0

