Route105_EventObjects: @ 85286F0
	object_event 1, EVENT_OBJ_GFX_SWIMMER_M, 0, 19, 60, 1, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 1, 6, Route105_EventScript_1EE261, 0
	object_event 2, EVENT_OBJ_GFX_SWIMMER_M, 0, 27, 36, 1, MOVEMENT_TYPE_WALK_LEFT_AND_RIGHT, 7, 0, 1, 3, Route105_EventScript_1EE278, 0
	object_event 3, EVENT_OBJ_GFX_SWIMMER_F, 0, 8, 45, 1, MOVEMENT_TYPE_WALK_UP_AND_DOWN, 0, 7, 1, 3, Route105_EventScript_1EE28F, 0
	object_event 4, EVENT_OBJ_GFX_SWIMMER_F, 0, 19, 9, 1, MOVEMENT_TYPE_ROTATE_CLOCKWISE, 0, 5, 1, 3, Route105_EventScript_1EE2A6, 0
	object_event 5, EVENT_OBJ_GFX_ITEM_BALL, 0, 8, 73, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, Route105_EventScript_290D33, FLAG_ITEM_ROUTE_105_IRON
	object_event 6, EVENT_OBJ_GFX_HIKER, 0, 17, 48, 3, MOVEMENT_TYPE_WALK_DOWN_AND_UP, 0, 7, 1, 3, Route105_EventScript_1EE24A, 0
	object_event 7, EVENT_OBJ_GFX_MAN_5, 0, 4, 54, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 2, 1, 2, Route105_EventScript_1EE2BD, 0
	object_event 8, EVENT_OBJ_GFX_HIKER, 0, 4, 58, 3, MOVEMENT_TYPE_FACE_UP, 0, 2, 1, 4, Route105_EventScript_1EE2D4, 0

Route105_MapWarps: @ 85287B0
	warp_def 9, 20, 0, 0, MAP_ISLAND_CAVE

Route105_MapBGEvents: @ 85287B8
	bg_hidden_item_event 15, 68, 3, ITEM_HEART_SCALE, FLAG_HIDDEN_ITEM_ROUTE_105_HEART_SCALE
	bg_hidden_item_event 5, 56, 3, ITEM_BIG_PEARL, FLAG_HIDDEN_ITEM_ROUTE_105_BIG_PEARL

Route105_MapEvents:: @ 85287D0
	map_events Route105_EventObjects, Route105_MapWarps, 0x0, Route105_MapBGEvents

