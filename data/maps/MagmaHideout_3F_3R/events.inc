MagmaHideout_3F_3R_EventObjects: @ 8537574
	object_event 1, EVENT_OBJ_GFX_ITEM_BALL, 0, 9, 19, 0, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, MagmaHideout_3F_3R_EventScript_29152C, FLAG_ITEM_MAGMA_HIDEOUT_3F_3R_ECAPE_ROPE

MagmaHideout_3F_3R_MapWarps: @ 853758C
	warp_def 16, 1, 0, 1, MAP_MAGMA_HIDEOUT_2F_3R
	warp_def 16, 21, 0, 1, MAP_MAGMA_HIDEOUT_4F

MagmaHideout_3F_3R_MapEvents:: @ 853759C
	map_events MagmaHideout_3F_3R_EventObjects, MagmaHideout_3F_3R_MapWarps, 0x0, 0x0

