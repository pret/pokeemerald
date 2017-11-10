Route102_MapObjects: @ 8527FD8
	object_event 1, MAP_OBJ_GFX_LITTLE_BOY_2, 0, 0, 18, 11, 3, 1, 0, 0, 0, 0, Route102_EventScript_1EC0E1, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_YOUNGSTER, 0, 0, 33, 14, 3, 8, 0, 0, 1, 3, Route102_EventScript_1EC105, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_BUG_CATCHER, 0, 0, 25, 15, 3, 7, 0, 0, 1, 2, Route102_EventScript_1EC1B3, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_LASS, 0, 0, 8, 7, 3, 18, 0, 0, 1, 3, Route102_EventScript_1EC1CA, 0, 0, 0
	object_event 5, MAP_OBJ_GFX_BOY_1, 0, 0, 37, 4, 3, 2, 17, 0, 0, 0, Route102_EventScript_1EC0FC, 0, 0, 0
	object_event 6, MAP_OBJ_GFX_ITEM_BALL, 0, 0, 11, 15, 3, 8, 0, 0, 0, 0, Route102_EventScript_290CD8, 1000, 0, 0
	object_event 7, MAP_OBJ_GFX_BERRY_TREE, 0, 0, 24, 2, 3, 12, 0, 0, 0, 2, BerryTreeScript, 0, 0, 0
	object_event 8, MAP_OBJ_GFX_BERRY_TREE, 0, 0, 25, 2, 3, 12, 0, 0, 0, 1, BerryTreeScript, 0, 0, 0
	object_event 9, MAP_OBJ_GFX_YOUNGSTER, 0, 0, 19, 4, 3, 8, 17, 0, 1, 3, Route102_EventScript_1EC1E1, 0, 0, 0

Route102_MapBGEvents: @ 85280B0
	bg_event 17, 2, 0, 0, 0, Route102_EventScript_1EC0F3
	bg_event 40, 9, 0, 0, 0, Route102_EventScript_1EC0EA

Route102_MapEvents:: @ 85280C8
	map_events Route102_MapObjects, 0x0, 0x0, Route102_MapBGEvents

