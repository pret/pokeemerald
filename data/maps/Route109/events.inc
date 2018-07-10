Route109_EventObjects: @ 8528A34
	object_event 1, EVENT_OBJ_GFX_MR_BRINEYS_BOAT, 0, 21, 26, 1, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, 0x0, 744
	object_event 2, EVENT_OBJ_GFX_OLD_MAN_1, 0, 21, 24, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, Route109_EventScript_1EE910, 741
	object_event 3, EVENT_OBJ_GFX_SWIMMER_M, 0, 12, 36, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 1, 5, Route109_EventScript_1EEA3D, 0
	object_event 4, EVENT_OBJ_GFX_SWIMMER_F, 0, 25, 39, 1, MOVEMENT_TYPE_FACE_UP_AND_LEFT, 0, 0, 1, 5, Route109_EventScript_1EEA54, 0
	object_event 5, EVENT_OBJ_GFX_SAILOR, 0, 15, 17, 4, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 1, 1, Route109_EventScript_1EEA6B, 0
	object_event 6, EVENT_OBJ_GFX_SAILOR, 0, 24, 13, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 1, 6, Route109_EventScript_1EEA82, 0
	object_event 7, EVENT_OBJ_GFX_TUBER_M, 0, 19, 10, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 1, 3, Route109_EventScript_1EEA99, 0
	object_event 8, EVENT_OBJ_GFX_TUBER_F, 0, 22, 7, 3, MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_RIGHT, 0, 0, 1, 4, Route109_EventScript_1EEAFB, 0
	object_event 9, EVENT_OBJ_GFX_LITTLE_GIRL_2, 0, 11, 6, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, Route109_EventScript_1EE995, 0
	object_event 10, EVENT_OBJ_GFX_ITEM_BALL, 0, 27, 46, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, Route109_EventScript_290D5A, 1005
	object_event 11, EVENT_OBJ_GFX_TUBER_F, 0, 29, 32, 3, MOVEMENT_TYPE_FACE_DOWN_AND_UP, 0, 0, 1, 3, Route109_EventScript_1EEB74, 0
	object_event 12, EVENT_OBJ_GFX_TUBER_F, 0, 28, 31, 3, MOVEMENT_TYPE_FACE_DOWN_AND_LEFT, 0, 0, 1, 3, Route109_EventScript_1EEB5D, 0
	object_event 13, EVENT_OBJ_GFX_FISHERMAN, 0, 21, 56, 0, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 1, 3, Route109_EventScript_1EEB8B, 0
	object_event 14, EVENT_OBJ_GFX_TUBER_M, 0, 24, 18, 3, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 0, 0, Route109_EventScript_1EE99E, 0
	object_event 15, EVENT_OBJ_GFX_TUBER_F, 0, 25, 18, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 0, 0, Route109_EventScript_1EE9B5, 0
	object_event 16, EVENT_OBJ_GFX_WOMAN_2, 0, 30, 32, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, Route109_EventScript_1EEA06, 0
	object_event 17, EVENT_OBJ_GFX_WOMAN_5, 0, 8, 41, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 1, 1, Route109_EventScript_1EEBBD, 0
	object_event 18, EVENT_OBJ_GFX_MAN_5, 0, 9, 41, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 1, 1, Route109_EventScript_1EEBA2, 0
	object_event 19, EVENT_OBJ_GFX_OLD_MAN_2, 0, 33, 6, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, Route109_EventScript_1EEA0F, 0
	object_event 20, EVENT_OBJ_GFX_ZIGZAGOON_2, 0, 32, 6, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, Route109_EventScript_1EEA18, 0
	object_event 21, EVENT_OBJ_GFX_TUBER_F, 0, 17, 13, 3, MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_RIGHT, 1, 1, 1, 6, Route109_EventScript_1EEBEF, 0
	object_event 22, EVENT_OBJ_GFX_TUBER_M, 0, 27, 7, 3, MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_LEFT, 1, 1, 1, 4, Route109_EventScript_1EEBD8, 0
	object_event 23, EVENT_OBJ_GFX_ITEM_BALL, 0, 25, 6, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, Route109_EventScript_290D67, 1140
	object_event 24, EVENT_OBJ_GFX_MAN_6, 0, 17, 56, 3, MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_RIGHT, 1, 1, 1, 3, Route109_EventScript_1EEC06, 0

Route109_MapWarps: @ 8528C74
	warp_def 12, 5, 0, 0, MAP_ROUTE109_SEASHORE_HOUSE

Route109_MapBGEvents: @ 8528C7C
	bg_event 15, 5, 0, 0, 0, Route109_EventScript_1EEA2B
	bg_event 29, 10, 3, 0, 0, Route109_EventScript_1EEA34
	bg_event 16, 23, 3, 7, 0, ITEM_REVIVE, 50, 0
	bg_event 33, 5, 3, 7, 0, ITEM_HEART_SCALE, 52, 0
	bg_event 9, 10, 3, 7, 0, ITEM_GREAT_BALL, 51, 0
	bg_event 28, 20, 3, 7, 0, ITEM_ETHER, 64, 0
	bg_event 13, 16, 3, 7, 0, ITEM_HEART_SCALE, 90, 0
	bg_event 8, 42, 3, 7, 0, ITEM_HEART_SCALE, 91, 0

Route109_MapEvents:: @ 8528CDC
	map_events Route109_EventObjects, Route109_MapWarps, 0x0, Route109_MapBGEvents

