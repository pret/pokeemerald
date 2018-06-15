AquaHideout_B1F_EventObjects: @ 8535378
	object_event 1, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 0, 28, 16, 3, 8, 0, 0, 1, 4, AquaHideout_B1F_EventScript_233A85, 924, 0, 0
	object_event 2, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 0, 6, 6, 3, 9, 0, 0, 1, 5, AquaHideout_B1F_EventScript_233AB0, 924, 0, 0
	object_event 3, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 29, 12, 3, 1, 0, 0, 0, 0, AquaHideout_B1F_EventScript_291372, 1071, 0, 0
	object_event 4, EVENT_OBJ_GFX_AQUA_MEMBER_F, 0, 0, 20, 18, 3, 23, 4, 0, 1, 4, AquaHideout_B1F_EventScript_233AD5, 924, 0, 0
	object_event 5, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 15, 9, 3, 1, 17, 0, 0, 0, AquaHideout_B1F_EventScript_291358, 1124, 0, 0
	object_event 6, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 16, 9, 3, 1, 17, 0, 0, 0, AquaHideout_B1F_EventScript_2339EB, 977, 0, 0
	object_event 7, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 15, 10, 3, 1, 17, 0, 0, 0, AquaHideout_B1F_EventScript_291365, 1132, 0, 0
	object_event 8, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 16, 10, 3, 1, 17, 0, 0, 0, AquaHideout_B1F_EventScript_233A38, 978, 0, 0
	object_event 9, EVENT_OBJ_GFX_AQUA_MEMBER_F, 0, 0, 28, 21, 3, 7, 17, 0, 1, 4, AquaHideout_B1F_EventScript_233AEC, 924, 0, 0

AquaHideout_B1F_MapWarps: @ 8535450
	warp_def 29, 1, 3, 2, MAP_AQUA_HIDEOUT_1F
	warp_def 18, 1, 3, 0, MAP_AQUA_HIDEOUT_B2F
	warp_def 12, 1, 3, 1, MAP_AQUA_HIDEOUT_B2F
	warp_def 3, 3, 3, 2, MAP_AQUA_HIDEOUT_B2F
	warp_def 31, 4, 3, 7, MAP_AQUA_HIDEOUT_B1F
	warp_def 27, 4, 3, 8, MAP_AQUA_HIDEOUT_B1F
	warp_def 20, 4, 3, 10, MAP_AQUA_HIDEOUT_B1F
	warp_def 27, 12, 3, 4, MAP_AQUA_HIDEOUT_B1F
	warp_def 3, 15, 3, 5, MAP_AQUA_HIDEOUT_B1F
	warp_def 3, 20, 3, 12, MAP_AQUA_HIDEOUT_B1F
	warp_def 32, 19, 3, 6, MAP_AQUA_HIDEOUT_B1F
	warp_def 23, 10, 3, 22, MAP_AQUA_HIDEOUT_B1F
	warp_def 45, 3, 3, 9, MAP_AQUA_HIDEOUT_B1F
	warp_def 42, 5, 3, 18, MAP_AQUA_HIDEOUT_B1F
	warp_def 45, 5, 3, 12, MAP_AQUA_HIDEOUT_B1F
	warp_def 48, 5, 3, 16, MAP_AQUA_HIDEOUT_B1F
	warp_def 42, 9, 3, 15, MAP_AQUA_HIDEOUT_B1F
	warp_def 45, 9, 3, 20, MAP_AQUA_HIDEOUT_B1F
	warp_def 48, 9, 3, 13, MAP_AQUA_HIDEOUT_B1F
	warp_def 42, 13, 3, 24, MAP_AQUA_HIDEOUT_B1F
	warp_def 45, 13, 3, 17, MAP_AQUA_HIDEOUT_B1F
	warp_def 48, 13, 3, 12, MAP_AQUA_HIDEOUT_B1F
	warp_def 42, 17, 3, 11, MAP_AQUA_HIDEOUT_B1F
	warp_def 45, 17, 3, 17, MAP_AQUA_HIDEOUT_B1F
	warp_def 48, 17, 3, 19, MAP_AQUA_HIDEOUT_B1F

AquaHideout_B1F_MapEvents:: @ 8535518
	map_events AquaHideout_B1F_EventObjects, AquaHideout_B1F_MapWarps, 0x0, 0x0

