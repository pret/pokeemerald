LilycoveCity_Harbor_EventObjects: @ 8531E1C
	object_event 1, EVENT_OBJ_GFX_BEAUTY, 0, 8, 10, 3, 8, 0, 0, 0, 0, LilycoveCity_Harbor_EventScript_21E00F, 908
	object_event 2, EVENT_OBJ_GFX_SS_TIDAL, 0, 8, 9, 1, 10, 0, 0, 0, 0, 0x0, 861
	object_event 3, EVENT_OBJ_GFX_SAILOR, 0, 3, 13, 3, 2, 1, 1, 0, 0, LilycoveCity_Harbor_EventScript_21E637, 0
	object_event 4, EVENT_OBJ_GFX_SAILOR, 0, 8, 10, 3, 8, 0, 0, 0, 0, 0x0, 909
	object_event 5, EVENT_OBJ_GFX_OLD_MAN_1, 0, 8, 10, 3, 8, 1, 1, 0, 0, 0x0, 748

LilycoveCity_Harbor_MapWarps: @ 8531E94
	warp_def 11, 14, 0, 12, MAP_LILYCOVE_CITY
	warp_def 12, 14, 0, 12, MAP_LILYCOVE_CITY

LilycoveCity_Harbor_MapEvents:: @ 8531EA4
	map_events LilycoveCity_Harbor_EventObjects, LilycoveCity_Harbor_MapWarps, 0x0, 0x0

