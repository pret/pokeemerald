Route119_House_MapObjects: @ 853ECD0
	object_event 1, MAP_OBJ_GFX_WOMAN_5, 0, 0, 7, 2, 3, 8, 0, 0, 0, 0, Route119_House_EventScript_270966, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_WINGULL, 0, 0, 1, 6, 3, 2, 34, 0, 0, 0, Route119_House_EventScript_27096F, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_WINGULL, 0, 0, 0, 4, 3, 2, 19, 0, 0, 0, Route119_House_EventScript_27096F, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_WINGULL, 0, 0, 2, 2, 3, 2, 17, 0, 0, 0, Route119_House_EventScript_27096F, 0, 0, 0
	object_event 5, MAP_OBJ_GFX_WINGULL, 0, 0, 8, 5, 3, 2, 35, 0, 0, 0, Route119_House_EventScript_27096F, 0, 0, 0
	object_event 6, MAP_OBJ_GFX_WINGULL, 0, 0, 6, 6, 3, 2, 34, 0, 0, 0, Route119_House_EventScript_27096F, 0, 0, 0
	object_event 7, MAP_OBJ_GFX_WINGULL, 0, 0, 5, 3, 3, 2, 49, 0, 0, 0, Route119_House_EventScript_27096F, 0, 0, 0

Route119_House_MapWarps: @ 853ED78
	warp_def 3, 8, 0, 1, ROUTE_119
	warp_def 4, 8, 0, 1, ROUTE_119

Route119_House_MapEvents:: @ 853ED88
	map_events Route119_House_MapObjects, Route119_House_MapWarps, 0x0, 0x0

