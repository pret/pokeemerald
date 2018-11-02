RustboroCity_DevonCorp_1F_EventObjects: @ 853037C
	object_event 1, EVENT_OBJ_GFX_DEVON_EMPLOYEE, 0, 2, 6, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, RustboroCity_DevonCorp_1F_EventScript_211261, 0
	object_event 2, EVENT_OBJ_GFX_DEVON_EMPLOYEE, 0, 15, 5, 3, MOVEMENT_TYPE_WANDER_AROUND, 2, 1, 0, 0, RustboroCity_DevonCorp_1F_EventScript_211293, 0
	object_event 3, EVENT_OBJ_GFX_WOMAN_3, 0, 5, 3, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, RustboroCity_DevonCorp_1F_EventScript_2112CE, 0

RustboroCity_DevonCorp_1F_MapWarps: @ 85303C4
	warp_def 5, 8, 0, 5, MAP_RUSTBORO_CITY
	warp_def 6, 8, 0, 6, MAP_RUSTBORO_CITY
	warp_def 14, 1, 0, 0, MAP_RUSTBORO_CITY_DEVON_CORP_2F

RustboroCity_DevonCorp_1F_MapBGEvents: @ 85303DC
	bg_event 3, 2, 0, BG_EVENT_PLAYER_FACING_ANY, RustboroCity_DevonCorp_1F_EventScript_211312
	bg_event 8, 2, 0, BG_EVENT_PLAYER_FACING_ANY, RustboroCity_DevonCorp_1F_EventScript_211309

RustboroCity_DevonCorp_1F_MapEvents:: @ 85303F4
	map_events RustboroCity_DevonCorp_1F_EventObjects, RustboroCity_DevonCorp_1F_MapWarps, 0x0, RustboroCity_DevonCorp_1F_MapBGEvents

