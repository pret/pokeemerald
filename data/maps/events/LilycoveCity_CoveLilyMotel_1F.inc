LilycoveCity_CoveLilyMotel_1F_EventObjects: @ 8531134
	object_event 1, EVENT_OBJ_GFX_MAN_1, 0, 0, 10, 3, 3, 7, 0, 0, 0, 0, LilycoveCity_CoveLilyMotel_1F_EventScript_218189, 0, 0, 0

LilycoveCity_CoveLilyMotel_1F_MapWarps: @ 853114C
	warp_def 5, 8, 0, 1, LILYCOVE_CITY
	warp_def 6, 8, 0, 1, LILYCOVE_CITY
	warp_def 2, 1, 0, 0, LILYCOVE_CITY_COVE_LILY_MOTEL_2F

LilycoveCity_CoveLilyMotel_1F_MapCoordEvents: @ 8531164
	coord_event 10, 2, 3, 0, VAR_TEMP_1, 0, 0, LilycoveCity_CoveLilyMotel_1F_EventScript_218211

LilycoveCity_CoveLilyMotel_1F_MapEvents:: @ 8531174
	map_events LilycoveCity_CoveLilyMotel_1F_EventObjects, LilycoveCity_CoveLilyMotel_1F_MapWarps, LilycoveCity_CoveLilyMotel_1F_MapCoordEvents, 0x0

