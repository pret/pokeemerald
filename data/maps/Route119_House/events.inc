Route119_House_EventObjects: @ 853ECD0
	object_event 1, EVENT_OBJ_GFX_WOMAN_5, 0, 7, 2, 3, 8, 0, 0, 0, 0, Route119_House_EventScript_270966, 0
	object_event 2, EVENT_OBJ_GFX_WINGULL, 0, 1, 6, 3, 2, 2, 2, 0, 0, Route119_House_EventScript_27096F, 0
	object_event 3, EVENT_OBJ_GFX_WINGULL, 0, 0, 4, 3, 2, 3, 1, 0, 0, Route119_House_EventScript_27096F, 0
	object_event 4, EVENT_OBJ_GFX_WINGULL, 0, 2, 2, 3, 2, 1, 1, 0, 0, Route119_House_EventScript_27096F, 0
	object_event 5, EVENT_OBJ_GFX_WINGULL, 0, 8, 5, 3, 2, 3, 2, 0, 0, Route119_House_EventScript_27096F, 0
	object_event 6, EVENT_OBJ_GFX_WINGULL, 0, 6, 6, 3, 2, 2, 2, 0, 0, Route119_House_EventScript_27096F, 0
	object_event 7, EVENT_OBJ_GFX_WINGULL, 0, 5, 3, 3, 2, 1, 3, 0, 0, Route119_House_EventScript_27096F, 0

Route119_House_MapWarps: @ 853ED78
	warp_def 3, 8, 0, 1, MAP_ROUTE119
	warp_def 4, 8, 0, 1, MAP_ROUTE119

Route119_House_MapEvents:: @ 853ED88
	map_events Route119_House_EventObjects, Route119_House_MapWarps, 0x0, 0x0

