MagmaHideout_4F_EventObjects: @ 8537490
	object_event 1, EVENT_OBJ_GFX_GROUDON_1, 0, 16, 17, 0, 8, 1, 1, 0, 0, 0x0, 853
	object_event 2, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 31, 22, 0, 10, 1, 1, 1, 3, MagmaHideout_4F_EventScript_23A68C, 857
	object_event 3, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 30, 13, 0, 9, 1, 1, 1, 3, MagmaHideout_4F_EventScript_23A6A3, 857
	object_event 4, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 26, 13, 0, 10, 1, 1, 1, 3, MagmaHideout_4F_EventScript_23A6BA, 857
	object_event 5, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 22, 4, 0, 8, 1, 1, 1, 4, MagmaHideout_4F_EventScript_23A6D1, 857
	object_event 6, EVENT_OBJ_GFX_MAXIE, 0, 16, 21, 0, 7, 1, 1, 0, 0, MagmaHideout_4F_EventScript_23A560, 857
	object_event 7, EVENT_OBJ_GFX_GROUDON_2, 0, 16, 17, 3, 8, 1, 1, 0, 0, 0x0, 850
	object_event 8, EVENT_OBJ_GFX_ITEM_BALL, 0, 3, 7, 0, 1, 1, 1, 0, 0, MagmaHideout_4F_EventScript_29151F, 1168

MagmaHideout_4F_MapWarps: @ 8537550
	warp_def 46, 7, 0, 0, MAP_MAGMA_HIDEOUT_3F_1R
	warp_def 20, 21, 0, 1, MAP_MAGMA_HIDEOUT_3F_3R

MagmaHideout_4F_MapEvents:: @ 8537560
	map_events MagmaHideout_4F_EventObjects, MagmaHideout_4F_MapWarps, 0x0, 0x0

