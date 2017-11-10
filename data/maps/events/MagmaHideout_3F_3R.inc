MagmaHideout_3F_3R_MapObjects: @ 8537574
	object_event 1, MAP_OBJ_GFX_ITEM_BALL, 0, 0, 9, 19, 0, 1, 17, 0, 0, 0, MagmaHideout_3F_3R_EventScript_29152C, 1059, 0, 0

MagmaHideout_3F_3R_MapWarps: @ 853758C
	warp_def 16, 1, 0, 1, MAGMA_HIDEOUT_2F_3R
	warp_def 16, 21, 0, 1, MAGMA_HIDEOUT_4F

MagmaHideout_3F_3R_MapEvents:: @ 853759C
	map_events MagmaHideout_3F_3R_MapObjects, MagmaHideout_3F_3R_MapWarps, 0x0, 0x0

