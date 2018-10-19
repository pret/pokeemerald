MagmaHideout_3F_1R_EventObjects: @ 85373D0
	object_event 1, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 2, 7, 4, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 1, 5, MagmaHideout_3F_1R_EventScript_23A1B3, FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	object_event 2, EVENT_OBJ_GFX_MAGMA_MEMBER_F, 0, 21, 21, 0, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 1, 4, MagmaHideout_3F_1R_EventScript_23A1CA, FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	object_event 3, EVENT_OBJ_GFX_ITEM_BALL, 0, 9, 16, 0, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, MagmaHideout_3F_1R_EventScript_291505, FLAG_ITEM_MAGMA_HIDEOUT_3F_1R_NUGGET

MagmaHideout_3F_1R_MapWarps: @ 8537418
	warp_def 7, 21, 0, 0, MAP_MAGMA_HIDEOUT_4F
	warp_def 21, 9, 0, 0, MAP_MAGMA_HIDEOUT_3F_2R
	warp_def 23, 3, 0, 2, MAP_MAGMA_HIDEOUT_2F_1R

MagmaHideout_3F_1R_MapEvents:: @ 8537430
	map_events MagmaHideout_3F_1R_EventObjects, MagmaHideout_3F_1R_MapWarps, 0x0, 0x0

