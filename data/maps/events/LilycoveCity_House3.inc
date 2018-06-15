LilycoveCity_House3_EventObjects: @ 8531F84
	object_event 1, EVENT_OBJ_GFX_BOY_5, 0, 3, 4, 3, 8, 1, 1, 0, 0, LilycoveCity_House3_EventScript_21EF3D, 0
	object_event 2, EVENT_OBJ_GFX_WOMAN_2, 0, 7, 4, 3, 9, 0, 0, 0, 0, LilycoveCity_House3_EventScript_21EE4B, 0
	object_event 3, EVENT_OBJ_GFX_BOY_5, 0, 1, 4, 3, 8, 1, 1, 0, 0, LilycoveCity_House3_EventScript_21EED5, 0
	object_event 4, EVENT_OBJ_GFX_BOY_5, 0, 2, 5, 3, 7, 1, 1, 0, 0, LilycoveCity_House3_EventScript_21EF09, 0
	object_event 5, EVENT_OBJ_GFX_BOY_5, 0, 2, 3, 3, 8, 1, 1, 0, 0, LilycoveCity_House3_EventScript_21EEA1, 0
	object_event 6, EVENT_OBJ_GFX_MAN_1, 0, 7, 5, 3, 9, 1, 1, 0, 0, LilycoveCity_House3_EventScript_21EE8A, 0

LilycoveCity_House3_MapWarps: @ 8532014
	warp_def 3, 7, 0, 10, MAP_LILYCOVE_CITY
	warp_def 4, 7, 0, 10, MAP_LILYCOVE_CITY

LilycoveCity_House3_MapEvents:: @ 8532024
	map_events LilycoveCity_House3_EventObjects, LilycoveCity_House3_MapWarps, 0x0, 0x0

