AquaHideout_B2F_EventObjects:
	object_event 1, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 23, 19, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, AquaHideout_B2F_EventScript_233E09, FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	object_event 2, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 23, 10, 3, MOVEMENT_TYPE_WALK_SEQUENCE_UP_LEFT_DOWN_RIGHT, 4, 3, 1, 3, AquaHideout_B2F_EventScript_233E8A, FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	object_event 3, EVENT_OBJ_GFX_ITEM_BALL, 0, 3, 13, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, AquaHideout_B2F_EventScript_29137F, FLAG_ITEM_AQUA_HIDEOUT_B2F_NEST_BALL
	object_event 4, EVENT_OBJ_GFX_SUBMARINE_SHADOW, 0, 19, 20, 1, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, 0x0, FLAG_HIDE_AQUA_HIDEOUT_B2F_SUBMARINE_SHADOW
	object_event 5, EVENT_OBJ_GFX_AQUA_MEMBER_F, 0, 7, 5, 3, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 1, 5, AquaHideout_B2F_EventScript_233EAF, FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	object_event 6, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 13, 5, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 1, 5, AquaHideout_B2F_EventScript_233EC6, FLAG_HIDE_AQUA_HIDEOUT_GRUNTS

AquaHideout_B2F_MapWarps:
	warp_def 18, 1, 3, 1, MAP_AQUA_HIDEOUT_B1F
	warp_def 12, 1, 3, 2, MAP_AQUA_HIDEOUT_B1F
	warp_def 3, 3, 3, 3, MAP_AQUA_HIDEOUT_B1F
	warp_def 31, 8, 3, 5, MAP_AQUA_HIDEOUT_B2F
	warp_def 8, 8, 3, 8, MAP_AQUA_HIDEOUT_B2F
	warp_def 5, 8, 3, 3, MAP_AQUA_HIDEOUT_B2F
	warp_def 18, 13, 3, 7, MAP_AQUA_HIDEOUT_B2F
	warp_def 12, 13, 3, 6, MAP_AQUA_HIDEOUT_B2F
	warp_def 31, 17, 3, 4, MAP_AQUA_HIDEOUT_B2F
	warp_def 32, 20, 3, 4, MAP_AQUA_HIDEOUT_B1F

AquaHideout_B2F_MapCoordEvents:
	coord_event 28, 17, 3, VAR_TEMP_1, 0, AquaHideout_B2F_EventScript_233DE5
	coord_event 28, 16, 3, VAR_TEMP_1, 0, AquaHideout_B2F_EventScript_233DE5

AquaHideout_B2F_MapEvents::
	map_events AquaHideout_B2F_EventObjects, AquaHideout_B2F_MapWarps, AquaHideout_B2F_MapCoordEvents, 0x0

