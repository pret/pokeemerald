RustboroCity_DevonCorp_3F_EventObjects: @ 85304BC
	object_event 1, EVENT_OBJ_GFX_GENTLEMAN, 0, 17, 5, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, RustboroCity_DevonCorp_3F_EventScript_21256C, 0
	object_event 2, EVENT_OBJ_GFX_MAN_2, 0, 3, 5, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, RustboroCity_DevonCorp_3F_EventScript_2125E1, FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	object_event 3, EVENT_OBJ_GFX_GENTLEMAN, 0, 15, 5, 3, MOVEMENT_TYPE_INVISIBLE, 1, 1, 0, 0, RustboroCity_DevonCorp_3F_EventScript_21256C, 0

RustboroCity_DevonCorp_3F_MapWarps: @ 8530504
	warp_def 2, 1, 0, 1, MAP_RUSTBORO_CITY_DEVON_CORP_2F

RustboroCity_DevonCorp_3F_MapBGEvents: @ 853050C
	bg_event 1, 5, 3, BG_EVENT_PLAYER_FACING_ANY, RustboroCity_DevonCorp_3F_EventScript_212600
	bg_event 1, 7, 3, BG_EVENT_PLAYER_FACING_ANY, RustboroCity_DevonCorp_3F_EventScript_212600

RustboroCity_DevonCorp_3F_MapEvents:: @ 8530524
	map_events RustboroCity_DevonCorp_3F_EventObjects, RustboroCity_DevonCorp_3F_MapWarps, 0x0, RustboroCity_DevonCorp_3F_MapBGEvents

