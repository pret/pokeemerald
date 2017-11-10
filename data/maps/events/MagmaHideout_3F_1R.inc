MagmaHideout_3F_1R_MapObjects: @ 85373D0
	object_event 1, MAP_OBJ_GFX_MAGMA_MEMBER_M, 0, 0, 2, 7, 4, 10, 17, 0, 1, 5, MagmaHideout_3F_1R_EventScript_23A1B3, 857, 0, 0
	object_event 2, MAP_OBJ_GFX_MAGMA_MEMBER_F, 0, 0, 21, 21, 0, 9, 17, 0, 1, 4, MagmaHideout_3F_1R_EventScript_23A1CA, 857, 0, 0
	object_event 3, MAP_OBJ_GFX_ITEM_BALL, 0, 0, 9, 16, 0, 1, 17, 0, 0, 0, MagmaHideout_3F_1R_EventScript_291505, 1166, 0, 0

MagmaHideout_3F_1R_MapWarps: @ 8537418
	warp_def 7, 21, 0, 0, MAGMA_HIDEOUT_4F
	warp_def 21, 9, 0, 0, MAGMA_HIDEOUT_3F_2R
	warp_def 23, 3, 0, 2, MAGMA_HIDEOUT_2F_1R

MagmaHideout_3F_1R_MapEvents:: @ 8537430
	map_events MagmaHideout_3F_1R_MapObjects, MagmaHideout_3F_1R_MapWarps, 0x0, 0x0

