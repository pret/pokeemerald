Route102_EventObjects: @ 8527FD8
	object_event 1, EVENT_OBJ_GFX_LITTLE_BOY, 0, 18, 11, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, Route102_EventScript_1EC0E1, 0
	object_event 2, EVENT_OBJ_GFX_YOUNGSTER, 0, 33, 14, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 1, 3, Route102_EventScript_1EC105, 0
	object_event 3, EVENT_OBJ_GFX_BUG_CATCHER, 0, 25, 15, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 1, 2, Route102_EventScript_1EC1B3, 0
	object_event 4, EVENT_OBJ_GFX_LASS, 0, 8, 7, 3, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT, 0, 0, 1, 3, Route102_EventScript_1EC1CA, 0
	object_event 5, EVENT_OBJ_GFX_BOY_1, 0, 37, 4, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, Route102_EventScript_1EC0FC, 0
	object_event 6, EVENT_OBJ_GFX_ITEM_BALL, 0, 11, 15, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, Route102_EventScript_290CD8, FLAG_0x3E8
	object_event 7, EVENT_OBJ_GFX_BERRY_TREE, 0, 24, 2, 3, MOVEMENT_TYPE_BERRY_TREE_GROWTH, 0, 0, 0, 2, BerryTreeScript, 0
	object_event 8, EVENT_OBJ_GFX_BERRY_TREE, 0, 25, 2, 3, MOVEMENT_TYPE_BERRY_TREE_GROWTH, 0, 0, 0, 1, BerryTreeScript, 0
	object_event 9, EVENT_OBJ_GFX_YOUNGSTER, 0, 19, 4, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 1, 3, Route102_EventScript_1EC1E1, 0

Route102_MapBGEvents: @ 85280B0
	bg_event 17, 2, 0, BG_EVENT_PLAYER_FACING_ANY, Route102_EventScript_1EC0F3
	bg_event 40, 9, 0, BG_EVENT_PLAYER_FACING_ANY, Route102_EventScript_1EC0EA

Route102_MapEvents:: @ 85280C8
	map_events Route102_EventObjects, 0x0, 0x0, Route102_MapBGEvents

