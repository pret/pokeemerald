RustboroCity_Mart_EventObjects: @ 853080C
	object_event 1, EVENT_OBJ_GFX_MART_EMPLOYEE, 0, 1, 3, 3, 10, 0, 0, 0, RustboroCity_Mart_EventScript_214F06, 0
	object_event 2, EVENT_OBJ_GFX_BOY_1, 0, 2, 5, 3, 7, 0, 0, 0, RustboroCity_Mart_EventScript_214F7D, 0
	object_event 3, EVENT_OBJ_GFX_WOMAN_2, 0, 8, 4, 3, 3, 16, 0, 0, RustboroCity_Mart_EventScript_214F74, 0
	object_event 4, EVENT_OBJ_GFX_BUG_CATCHER, 0, 8, 2, 3, 7, 17, 0, 0, RustboroCity_Mart_EventScript_214F86, 0

RustboroCity_Mart_MapWarps: @ 853086C
	warp_def 3, 7, 0, 2, MAP_RUSTBORO_CITY
	warp_def 4, 7, 0, 2, MAP_RUSTBORO_CITY

RustboroCity_Mart_MapEvents:: @ 853087C
	map_events RustboroCity_Mart_EventObjects, RustboroCity_Mart_MapWarps, 0x0, 0x0

