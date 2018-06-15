MossdeepCity_House2_EventObjects: @ 85329CC
	object_event 1, EVENT_OBJ_GFX_MAN_5, 0, 0, 6, 6, 3, 9, 0, 0, 0, 0, MossdeepCity_House2_EventScript_2220DF, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_LITTLE_GIRL_1, 0, 0, 4, 4, 3, 8, 0, 0, 0, 0, MossdeepCity_House2_EventScript_2220E8, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_WINGULL, 0, 0, 4, 5, 3, 7, 0, 0, 0, 0, MossdeepCity_House2_EventScript_2220F1, 934, 0, 0

MossdeepCity_House2_MapWarps: @ 8532A14
	warp_def 3, 8, 0, 3, MAP_MOSSDEEP_CITY
	warp_def 4, 8, 0, 3, MAP_MOSSDEEP_CITY

MossdeepCity_House2_MapEvents:: @ 8532A24
	map_events MossdeepCity_House2_EventObjects, MossdeepCity_House2_MapWarps, 0x0, 0x0

