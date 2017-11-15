RustboroCity_DevonCorp_3F_MapObjects: @ 85304BC
	object_event 1, MAP_OBJ_GFX_GENTLEMAN, 0, 0, 17, 5, 3, 9, 0, 0, 0, 0, RustboroCity_DevonCorp_3F_EventScript_21256C, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_MAN_2, 0, 0, 3, 5, 3, 10, 0, 0, 0, 0, RustboroCity_DevonCorp_3F_EventScript_2125E1, 949, 0, 0
	object_event 3, MAP_OBJ_GFX_GENTLEMAN, 0, 0, 15, 5, 3, 76, 17, 0, 0, 0, RustboroCity_DevonCorp_3F_EventScript_21256C, 0, 0, 0

RustboroCity_DevonCorp_3F_MapWarps: @ 8530504
	warp_def 2, 1, 0, 1, RUSTBORO_CITY_DEVON_CORP_2F

RustboroCity_DevonCorp_3F_MapBGEvents: @ 853050C
	bg_event 1, 5, 3, 0, 0, RustboroCity_DevonCorp_3F_EventScript_212600
	bg_event 1, 7, 3, 0, 0, RustboroCity_DevonCorp_3F_EventScript_212600

RustboroCity_DevonCorp_3F_MapEvents:: @ 8530524
	map_events RustboroCity_DevonCorp_3F_MapObjects, RustboroCity_DevonCorp_3F_MapWarps, 0x0, RustboroCity_DevonCorp_3F_MapBGEvents

