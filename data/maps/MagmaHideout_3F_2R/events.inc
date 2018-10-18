MagmaHideout_3F_2R_EventObjects: @ 8537444
	object_event 1, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 16, 3, 0, MOVEMENT_TYPE_FACE_DOWN_AND_LEFT, 1, 1, 1, 3, MagmaHideout_3F_2R_EventScript_23A3D5, FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	object_event 2, EVENT_OBJ_GFX_ITEM_BALL, 0, 5, 9, 0, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, MagmaHideout_3F_2R_EventScript_291512, FLAG_ITEM_MAGMA_HIDEOUT_3F_2R_PP_MAX

MagmaHideout_3F_2R_MapWarps: @ 8537474
	warp_def 12, 15, 0, 1, MAP_MAGMA_HIDEOUT_3F_1R

MagmaHideout_3F_2R_MapEvents:: @ 853747C
	map_events MagmaHideout_3F_2R_EventObjects, MagmaHideout_3F_2R_MapWarps, 0x0, 0x0

