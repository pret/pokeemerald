Route125_EventObjects:
	object_event 1, EVENT_OBJ_GFX_SWIMMER_M, 0, 7, 31, 1, MOVEMENT_TYPE_WALK_RIGHT_AND_LEFT, 0, 0, 1, 2, Route125_EventScript_1F67A4, 0
	object_event 2, EVENT_OBJ_GFX_SWIMMER_M, 0, 45, 9, 1, MOVEMENT_TYPE_FACE_RIGHT, 2, 5, 1, 2, Route125_EventScript_1F67BB, 0
	object_event 3, EVENT_OBJ_GFX_SWIMMER_F, 0, 38, 24, 1, MOVEMENT_TYPE_WALK_RIGHT_AND_LEFT, 6, 0, 1, 3, Route125_EventScript_1F67D2, 0
	object_event 4, EVENT_OBJ_GFX_SWIMMER_F, 0, 30, 28, 1, MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_DOWN_LEFT_UP, 9, 9, 1, 3, Route125_EventScript_1F67E9, 0
	object_event 5, EVENT_OBJ_GFX_SAILOR, 0, 21, 30, 3, MOVEMENT_TYPE_FACE_DOWN_AND_UP, 0, 0, 1, 2, Route125_EventScript_1F6800, 0
	object_event 6, EVENT_OBJ_GFX_LASS, 0, 17, 19, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 1, 1, Route125_EventScript_1F6862, 0
	object_event 7, EVENT_OBJ_GFX_LASS, 0, 18, 19, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 1, 1, Route125_EventScript_1F687D, 0
	object_event 8, EVENT_OBJ_GFX_MAN_5, 0, 43, 19, 3, MOVEMENT_TYPE_WALK_RIGHT_AND_LEFT, 2, 1, 1, 3, Route125_EventScript_1F6898, 0
	object_event 9, EVENT_OBJ_GFX_EXPERT_M, 0, 48, 19, 3, MOVEMENT_TYPE_WALK_LEFT_AND_RIGHT, 2, 1, 1, 3, Route125_EventScript_1F68AF, 0
	object_event 10, EVENT_OBJ_GFX_ITEM_BALL, 0, 46, 17, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, Route125_EventScript_291018, FLAG_ITEM_ROUTE_125_BIG_PEARL

Route125_MapWarps:
	warp_def 22, 19, 0, 0, MAP_SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM

Route125_MapBGEvents:
	bg_secret_base_event 53, 10, 0, SECRET_BASE_RED_CAVE1_2
	bg_secret_base_event 55, 11, 0, SECRET_BASE_RED_CAVE4_2
	bg_secret_base_event 7, 25, 0, SECRET_BASE_YELLOW_CAVE2_2
	bg_secret_base_event 24, 32, 0, SECRET_BASE_YELLOW_CAVE4_2

Route125_MapEvents::
	map_events Route125_EventObjects, Route125_MapWarps, 0x0, Route125_MapBGEvents

