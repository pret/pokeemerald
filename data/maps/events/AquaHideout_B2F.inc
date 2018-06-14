AquaHideout_B2F_EventObjects: @ 853552C
	object_event 1, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 0, 23, 19, 3, 9, 0, 0, 0, 0, AquaHideout_B2F_EventScript_233E09, 924, 0, 0
	object_event 2, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 0, 23, 10, 3, 45, 52, 0, 1, 3, AquaHideout_B2F_EventScript_233E8A, 924, 0, 0
	object_event 3, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 3, 13, 3, 1, 0, 0, 0, 0, AquaHideout_B2F_EventScript_29137F, 1072, 0, 0
	object_event 4, EVENT_OBJ_GFX_SUBMARINE_SHADOW, 0, 0, 19, 20, 1, 9, 0, 0, 0, 0, 0x0, 943, 0, 0
	object_event 5, EVENT_OBJ_GFX_AQUA_MEMBER_F, 0, 0, 7, 5, 3, 10, 17, 0, 1, 5, AquaHideout_B2F_EventScript_233EAF, 924, 0, 0
	object_event 6, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 0, 13, 5, 3, 9, 17, 0, 1, 5, AquaHideout_B2F_EventScript_233EC6, 924, 0, 0

AquaHideout_B2F_MapWarps: @ 85355BC
	warp_def 18, 1, 3, 1, AQUA_HIDEOUT_B1F
	warp_def 12, 1, 3, 2, AQUA_HIDEOUT_B1F
	warp_def 3, 3, 3, 3, AQUA_HIDEOUT_B1F
	warp_def 31, 8, 3, 5, AQUA_HIDEOUT_B2F
	warp_def 8, 8, 3, 8, AQUA_HIDEOUT_B2F
	warp_def 5, 8, 3, 3, AQUA_HIDEOUT_B2F
	warp_def 18, 13, 3, 7, AQUA_HIDEOUT_B2F
	warp_def 12, 13, 3, 6, AQUA_HIDEOUT_B2F
	warp_def 31, 17, 3, 4, AQUA_HIDEOUT_B2F
	warp_def 32, 20, 3, 4, AQUA_HIDEOUT_B1F

AquaHideout_B2F_MapCoordEvents: @ 853560C
	coord_event 28, 17, 3, 0, VAR_TEMP_1, 0, 0, AquaHideout_B2F_EventScript_233DE5
	coord_event 28, 16, 3, 0, VAR_TEMP_1, 0, 0, AquaHideout_B2F_EventScript_233DE5

AquaHideout_B2F_MapEvents:: @ 853562C
	map_events AquaHideout_B2F_EventObjects, AquaHideout_B2F_MapWarps, AquaHideout_B2F_MapCoordEvents, 0x0

