LilycoveCity_Harbor_MapObjects: @ 8531E1C
	object_event 1, MAP_OBJ_GFX_BEAUTY, 0, 0, 8, 10, 3, 8, 0, 0, 0, 0, LilycoveCity_Harbor_EventScript_21E00F, 908, 0, 0
	object_event 2, MAP_OBJ_GFX_SS_TIDAL, 0, 0, 8, 9, 1, 10, 0, 0, 0, 0, 0x0, 861, 0, 0
	object_event 3, MAP_OBJ_GFX_SAILOR, 0, 0, 3, 13, 3, 2, 17, 0, 0, 0, LilycoveCity_Harbor_EventScript_21E637, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_SAILOR, 0, 0, 8, 10, 3, 8, 0, 0, 0, 0, 0x0, 909, 0, 0
	object_event 5, MAP_OBJ_GFX_OLD_MAN_1, 0, 0, 8, 10, 3, 8, 17, 0, 0, 0, 0x0, 748, 0, 0

LilycoveCity_Harbor_MapWarps: @ 8531E94
	warp_def 11, 14, 0, 12, LILYCOVE_CITY
	warp_def 12, 14, 0, 12, LILYCOVE_CITY

LilycoveCity_Harbor_MapEvents:: @ 8531EA4
	map_events LilycoveCity_Harbor_MapObjects, LilycoveCity_Harbor_MapWarps, 0x0, 0x0

