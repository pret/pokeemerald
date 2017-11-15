RustboroCity_Mart_MapObjects: @ 853080C
	object_event 1, MAP_OBJ_GFX_MART_EMPLOYEE, 0, 0, 1, 3, 3, 10, 0, 0, 0, 0, RustboroCity_Mart_EventScript_214F06, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_BOY_1, 0, 0, 2, 5, 3, 7, 0, 0, 0, 0, RustboroCity_Mart_EventScript_214F7D, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_WOMAN_2, 0, 0, 8, 4, 3, 3, 16, 0, 0, 0, RustboroCity_Mart_EventScript_214F74, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_BUG_CATCHER, 0, 0, 8, 2, 3, 7, 17, 0, 0, 0, RustboroCity_Mart_EventScript_214F86, 0, 0, 0

RustboroCity_Mart_MapWarps: @ 853086C
	warp_def 3, 7, 0, 2, RUSTBORO_CITY
	warp_def 4, 7, 0, 2, RUSTBORO_CITY

RustboroCity_Mart_MapEvents:: @ 853087C
	map_events RustboroCity_Mart_MapObjects, RustboroCity_Mart_MapWarps, 0x0, 0x0

