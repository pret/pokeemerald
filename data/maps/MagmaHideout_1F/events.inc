MagmaHideout_1F_EventObjects:
	object_event 1, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 4, 5, 0, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 1, 2, MagmaHideout_1F_EventScript_23988C, FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	object_event 2, EVENT_OBJ_GFX_ITEM_BALL, 0, 3, 20, 0, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, MagmaHideout_1F_EventScript_2914DE, FLAG_ITEM_MAGMA_HIDEOUT_1F_RARE_CANDY
	object_event 3, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 30, 20, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 1, 4, MagmaHideout_1F_EventScript_2398A3, FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	object_event 4, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 5, 22, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, MagmaHideout_1F_EventScript_2908BA, FLAG_TEMP_11
	object_event 5, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 7, 22, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, MagmaHideout_1F_EventScript_2908BA, FLAG_TEMP_12
	object_event 6, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 6, 23, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, MagmaHideout_1F_EventScript_2908BA, FLAG_TEMP_13

MagmaHideout_1F_MapWarps:
	warp_def 10, 34, 3, 4, MAP_JAGGED_PASS
	warp_def 25, 34, 3, 1, MAP_MAGMA_HIDEOUT_2F_1R
	warp_def 31, 3, 0, 1, MAP_MAGMA_HIDEOUT_2F_2R
	warp_def 20, 22, 0, 0, MAP_MAGMA_HIDEOUT_2F_3R

MagmaHideout_1F_MapEvents::
	map_events MagmaHideout_1F_EventObjects, MagmaHideout_1F_MapWarps, 0x0, 0x0

