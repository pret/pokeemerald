AquaHideout_1F_EventObjects: @ 8535304
	object_event 1, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 0, 13, 11, 3, 8, 0, 0, 0, 0, AquaHideout_1F_EventScript_233494, 821, 0, 0
	object_event 2, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 0, 14, 11, 3, 8, 0, 0, 0, 0, AquaHideout_1F_EventScript_2334C6, 822, 0, 0
	object_event 3, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 0, 20, 4, 3, 50, 93, 0, 1, 3, AquaHideout_1F_EventScript_2334F8, 924, 0, 0

AquaHideout_1F_MapWarps: @ 853534C
	warp_def 13, 27, 1, 6, MAP_LILYCOVE_CITY
	warp_def 14, 27, 1, 6, MAP_LILYCOVE_CITY
	warp_def 22, 1, 3, 0, MAP_AQUA_HIDEOUT_B1F

AquaHideout_1F_MapEvents:: @ 8535364
	map_events AquaHideout_1F_EventObjects, AquaHideout_1F_MapWarps, 0x0, 0x0

