MossdeepCity_Mart_EventObjects: @ 8532B50
	object_event 1, EVENT_OBJ_GFX_MART_EMPLOYEE, 0, 1, 3, 3, 10, 0, 0, 0, 0, MossdeepCity_Mart_EventScript_2223C8, 0
	object_event 2, EVENT_OBJ_GFX_WOMAN_7, 0, 1, 5, 3, 7, 0, 0, 0, 0, MossdeepCity_Mart_EventScript_2223F6, 0
	object_event 3, EVENT_OBJ_GFX_BOY_2, 0, 8, 3, 3, 3, 0, 1, 0, 0, MossdeepCity_Mart_EventScript_2223FF, 0
	object_event 4, EVENT_OBJ_GFX_SAILOR, 0, 5, 3, 3, 2, 1, 1, 0, 0, MossdeepCity_Mart_EventScript_222408, 0

MossdeepCity_Mart_MapWarps: @ 8532BB0
	warp_def 3, 7, 0, 4, MAP_MOSSDEEP_CITY
	warp_def 4, 7, 0, 4, MAP_MOSSDEEP_CITY

MossdeepCity_Mart_MapEvents:: @ 8532BC0
	map_events MossdeepCity_Mart_EventObjects, MossdeepCity_Mart_MapWarps, 0x0, 0x0

