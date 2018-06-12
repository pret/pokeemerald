MagmaHideout_2F_2R_EventObjects: @ 853731C
	object_event 1, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 0, 29, 8, 3, 9, 17, 0, 1, 7, MagmaHideout_2F_2R_EventScript_239E4D, 857, 0, 0
	object_event 2, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 0, 25, 11, 3, 10, 17, 0, 1, 2, MagmaHideout_2F_2R_EventScript_239E36, 857, 0, 0
	object_event 3, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 21, 7, 3, 1, 17, 0, 0, 0, MagmaHideout_2F_2R_EventScript_2914EB, 1164, 0, 0
	object_event 4, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 0, 8, 9, 3, 8, 17, 0, 1, 4, MagmaHideout_2F_2R_EventScript_239E1F, 857, 0, 0
	object_event 5, EVENT_OBJ_GFX_MAGMA_MEMBER_F, 0, 0, 7, 13, 3, 10, 17, 0, 1, 1, MagmaHideout_2F_2R_EventScript_239E08, 857, 0, 0
	object_event 6, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 14, 6, 3, 1, 17, 0, 0, 0, MagmaHideout_2F_2R_EventScript_2914F8, 1165, 0, 0

MagmaHideout_2F_2R_MapWarps: @ 85373AC
	warp_def 10, 22, 3, 0, MAGMA_HIDEOUT_2F_1R
	warp_def 36, 4, 0, 2, MAGMA_HIDEOUT_1F

MagmaHideout_2F_2R_MapEvents:: @ 85373BC
	map_events MagmaHideout_2F_2R_EventObjects, MagmaHideout_2F_2R_MapWarps, 0x0, 0x0

