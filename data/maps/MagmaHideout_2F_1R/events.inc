MagmaHideout_2F_1R_EventObjects: @ 8537290
	object_event 1, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 18, 19, 3, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN, 5, 4, 1, 1, MagmaHideout_2F_1R_EventScript_239B7F, FLAG_0x359
	object_event 2, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 12, 14, 3, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_RIGHT_UP_LEFT, 7, 6, 1, 3, MagmaHideout_2F_1R_EventScript_239B96, FLAG_0x359
	object_event 3, EVENT_OBJ_GFX_MAGMA_MEMBER_F, 0, 8, 8, 3, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 1, 7, MagmaHideout_2F_1R_EventScript_239B51, FLAG_0x359
	object_event 4, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 21, 11, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 1, 3, MagmaHideout_2F_1R_EventScript_239B68, FLAG_0x359

MagmaHideout_2F_1R_MapWarps: @ 85372F0
	warp_def 11, 23, 0, 0, MAP_MAGMA_HIDEOUT_2F_2R
	warp_def 8, 2, 0, 1, MAP_MAGMA_HIDEOUT_1F
	warp_def 17, 33, 3, 2, MAP_MAGMA_HIDEOUT_3F_1R

MagmaHideout_2F_1R_MapEvents:: @ 8537308
	map_events MagmaHideout_2F_1R_EventObjects, MagmaHideout_2F_1R_MapWarps, 0x0, 0x0

