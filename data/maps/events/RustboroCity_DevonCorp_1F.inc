RustboroCity_DevonCorp_1F_MapObjects: @ 853037C
	object_event 1, MAP_OBJ_GFX_MAN_7, 0, 0, 2, 6, 3, 2, 17, 0, 0, 0, RustboroCity_DevonCorp_1F_EventScript_211261, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_MAN_7, 0, 0, 15, 5, 3, 2, 18, 0, 0, 0, RustboroCity_DevonCorp_1F_EventScript_211293, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_WOMAN_4, 0, 0, 5, 3, 3, 8, 0, 0, 0, 0, RustboroCity_DevonCorp_1F_EventScript_2112CE, 0, 0, 0

RustboroCity_DevonCorp_1F_MapWarps: @ 85303C4
	warp_def 5, 8, 0, 5, RUSTBORO_CITY
	warp_def 6, 8, 0, 6, RUSTBORO_CITY
	warp_def 14, 1, 0, 0, RUSTBORO_CITY_DEVON_CORP_2F

RustboroCity_DevonCorp_1F_MapBGEvents: @ 85303DC
	bg_event 3, 2, 0, 0, 0, RustboroCity_DevonCorp_1F_EventScript_211312
	bg_event 8, 2, 0, 0, 0, RustboroCity_DevonCorp_1F_EventScript_211309

RustboroCity_DevonCorp_1F_MapEvents:: @ 85303F4
	map_events RustboroCity_DevonCorp_1F_MapObjects, RustboroCity_DevonCorp_1F_MapWarps, 0x0, RustboroCity_DevonCorp_1F_MapBGEvents

