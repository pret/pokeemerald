FieryPath_EventObjects: @ 8534C80
	object_event 1, EVENT_OBJ_GFX_ITEM_BALL, 0, 8, 3, 3, 1, 1, 1, 0, 0, FieryPath_EventScript_29119E, 1091
	object_event 2, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 10, 15, 3, 1, 0, 0, 0, 0, FieryPath_EventScript_2908BA, 17
	object_event 3, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 17, 15, 3, 1, 0, 0, 0, 0, FieryPath_EventScript_2908BA, 18
	object_event 4, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 8, 11, 3, 1, 0, 0, 0, 0, FieryPath_EventScript_2908BA, 19
	object_event 5, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 3, 12, 3, 1, 0, 0, 0, 0, FieryPath_EventScript_2908BA, 20
	object_event 6, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 6, 23, 3, 1, 0, 0, 0, 0, FieryPath_EventScript_2908BA, 21
	object_event 7, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 5, 24, 3, 1, 0, 0, 0, 0, FieryPath_EventScript_2908BA, 22
	object_event 8, EVENT_OBJ_GFX_ITEM_BALL, 0, 7, 32, 3, 1, 1, 1, 0, 0, FieryPath_EventScript_291191, 1111

FieryPath_MapWarps: @ 8534D40
	warp_def 26, 36, 3, 4, MAP_ROUTE112
	warp_def 26, 4, 3, 5, MAP_ROUTE112

FieryPath_MapEvents:: @ 8534D50
	map_events FieryPath_EventObjects, FieryPath_MapWarps, 0x0, 0x0

