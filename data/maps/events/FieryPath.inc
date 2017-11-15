FieryPath_MapObjects: @ 8534C80
	object_event 1, MAP_OBJ_GFX_ITEM_BALL, 0, 0, 8, 3, 3, 1, 17, 0, 0, 0, FieryPath_EventScript_29119E, 1091, 0, 0
	object_event 2, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 10, 15, 3, 1, 0, 0, 0, 0, FieryPath_EventScript_2908BA, 17, 0, 0
	object_event 3, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 17, 15, 3, 1, 0, 0, 0, 0, FieryPath_EventScript_2908BA, 18, 0, 0
	object_event 4, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 8, 11, 3, 1, 0, 0, 0, 0, FieryPath_EventScript_2908BA, 19, 0, 0
	object_event 5, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 3, 12, 3, 1, 0, 0, 0, 0, FieryPath_EventScript_2908BA, 20, 0, 0
	object_event 6, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 6, 23, 3, 1, 0, 0, 0, 0, FieryPath_EventScript_2908BA, 21, 0, 0
	object_event 7, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 5, 24, 3, 1, 0, 0, 0, 0, FieryPath_EventScript_2908BA, 22, 0, 0
	object_event 8, MAP_OBJ_GFX_ITEM_BALL, 0, 0, 7, 32, 3, 1, 17, 0, 0, 0, FieryPath_EventScript_291191, 1111, 0, 0

FieryPath_MapWarps: @ 8534D40
	warp_def 26, 36, 3, 4, ROUTE_112
	warp_def 26, 4, 3, 5, ROUTE_112

FieryPath_MapEvents:: @ 8534D50
	map_events FieryPath_MapObjects, FieryPath_MapWarps, 0x0, 0x0

