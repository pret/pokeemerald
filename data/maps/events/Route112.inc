Route112_MapObjects: @ 8529974
	object_event 1, MAP_OBJ_GFX_MAGMA_MEMBER_M, 0, 0, 26, 30, 3, 7, 17, 0, 0, 0, Route112_EventScript_1F1DB7, 819, 0, 0
	object_event 2, MAP_OBJ_GFX_HIKER, 0, 0, 24, 34, 3, 14, 0, 0, 1, 2, Route112_EventScript_1F1E6A, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_CAMPER, 0, 0, 29, 49, 3, 8, 0, 0, 1, 3, Route112_EventScript_1F1EE3, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_PICNICKER, 0, 0, 22, 46, 3, 23, 0, 0, 1, 3, Route112_EventScript_1F1EFA, 0, 0, 0
	object_event 5, MAP_OBJ_GFX_HIKER, 0, 0, 15, 40, 3, 16, 0, 0, 1, 3, Route112_EventScript_1F1E81, 0, 0, 0
	object_event 6, MAP_OBJ_GFX_MAGMA_MEMBER_M, 0, 0, 27, 30, 3, 7, 0, 0, 0, 0, Route112_EventScript_1F1DB7, 819, 0, 0
	object_event 7, MAP_OBJ_GFX_BERRY_TREE, 0, 0, 27, 6, 0, 12, 0, 0, 0, 24, BerryTreeScript, 0, 0, 0
	object_event 8, MAP_OBJ_GFX_BERRY_TREE, 0, 0, 28, 6, 0, 12, 0, 0, 0, 23, BerryTreeScript, 0, 0, 0
	object_event 9, MAP_OBJ_GFX_BERRY_TREE, 0, 0, 29, 6, 0, 12, 0, 0, 0, 22, BerryTreeScript, 0, 0, 0
	object_event 10, MAP_OBJ_GFX_BERRY_TREE, 0, 0, 30, 6, 3, 12, 0, 0, 0, 21, BerryTreeScript, 0, 0, 0
	object_event 11, MAP_OBJ_GFX_HIKER, 0, 0, 8, 50, 3, 26, 48, 0, 0, 0, Route112_EventScript_1F1E61, 0, 0, 0
	object_event 12, MAP_OBJ_GFX_ITEM_BALL, 0, 0, 14, 43, 3, 1, 0, 0, 0, 0, Route112_EventScript_290DCF, 1011, 0, 0
	object_event 13, MAP_OBJ_GFX_MAN_6, 0, 0, 31, 7, 3, 18, 17, 0, 1, 3, Route112_EventScript_1F1F11, 0, 0, 0
	object_event 14, MAP_OBJ_GFX_WOMAN_3, 0, 0, 31, 11, 3, 15, 17, 0, 1, 3, Route112_EventScript_1F1F28, 0, 0, 0

Route112_MapWarps: @ 8529AC4
	warp_def 28, 27, 0, 0, ROUTE_112_CABLE_CAR_STATION
	warp_def 29, 27, 0, 1, ROUTE_112_CABLE_CAR_STATION
	warp_def 6, 46, 3, 0, JAGGED_PASS
	warp_def 7, 46, 3, 1, JAGGED_PASS
	warp_def 11, 36, 0, 0, FIERY_PATH
	warp_def 22, 10, 0, 1, FIERY_PATH

Route112_MapBGEvents: @ 8529AF4
	bg_event 19, 44, 3, 0, 0, Route112_EventScript_1F1E4F
	bg_event 22, 37, 0, 0, 0, Route112_EventScript_1F1E46
	bg_event 4, 49, 0, 0, 0, Route112_EventScript_1F1E58

Route112_MapEvents:: @ 8529B18
	map_events Route112_MapObjects, Route112_MapWarps, 0x0, Route112_MapBGEvents

