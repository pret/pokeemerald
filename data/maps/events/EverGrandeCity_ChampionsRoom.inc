EverGrandeCity_ChampionsRoom_EventObjects: @ 8533700
	object_event 1, EVENT_OBJ_GFX_WALLACE, 0, 0, 6, 5, 3, 8, 0, 0, 0, 0, 0x0, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_HIPSTER, 0, 0, 6, 12, 3, 7, 0, 0, 0, 0, 0x0, 920, 0, 0
	object_event 3, EVENT_OBJ_GFX_PROF_BIRCH, 0, 0, 6, 12, 3, 7, 0, 0, 0, 0, 0x0, 921, 0, 0

EverGrandeCity_ChampionsRoom_MapWarps: @ 8533748
	warp_def 6, 12, 3, 1, EVER_GRANDE_CITY_HALL_4
	warp_def 6, 2, 0, 0, EVER_GRANDE_CITY_HALL_OF_FAME

EverGrandeCity_ChampionsRoom_MapEvents:: @ 8533758
	map_events EverGrandeCity_ChampionsRoom_EventObjects, EverGrandeCity_ChampionsRoom_MapWarps, 0x0, 0x0

