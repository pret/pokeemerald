SafariZone_Northeast_MapObjects: @ 853B968
	object_event 1, MAP_OBJ_GFX_BOY_3, 0, 0, 8, 20, 3, 1, 17, 0, 0, 0, SafariZone_Northeast_EventScript_23D3C6, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_GIRL_3, 0, 0, 30, 22, 3, 1, 17, 0, 0, 0, SafariZone_Northeast_EventScript_23D3D8, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_BREAKABLE_ROCK, 0, 0, 11, 11, 3, 1, 17, 0, 0, 0, SafariZone_Northeast_EventScript_2907A6, 21, 0, 0
	object_event 4, MAP_OBJ_GFX_WOMAN_1, 0, 0, 13, 35, 0, 1, 17, 0, 0, 0, SafariZone_Northeast_EventScript_23D3CF, 0, 0, 0
	object_event 5, MAP_OBJ_GFX_BREAKABLE_ROCK, 0, 0, 8, 13, 3, 1, 17, 0, 0, 0, SafariZone_Northeast_EventScript_2907A6, 19, 0, 0
	object_event 6, MAP_OBJ_GFX_BREAKABLE_ROCK, 0, 0, 9, 7, 3, 1, 17, 0, 0, 0, SafariZone_Northeast_EventScript_2907A6, 17, 0, 0
	object_event 7, MAP_OBJ_GFX_BREAKABLE_ROCK, 0, 0, 8, 10, 3, 1, 17, 0, 0, 0, SafariZone_Northeast_EventScript_2907A6, 20, 0, 0
	object_event 8, MAP_OBJ_GFX_BREAKABLE_ROCK, 0, 0, 12, 8, 3, 1, 17, 0, 0, 0, SafariZone_Northeast_EventScript_2907A6, 18, 0, 0
	object_event 9, MAP_OBJ_GFX_ITEM_BALL, 0, 0, 8, 17, 3, 1, 17, 0, 0, 0, SafariZone_Northeast_EventScript_2912E3, 1169, 0, 0

SafariZone_Northeast_MapBGEvents: @ 853BA40
	bg_event 31, 35, 3, 7, 0, ITEM_RARE_CANDY, 106, 0
	bg_event 21, 5, 3, 7, 0, ITEM_ZINC, 107, 0

SafariZone_Northeast_MapEvents:: @ 853BA58
	map_events SafariZone_Northeast_MapObjects, 0x0, 0x0, SafariZone_Northeast_MapBGEvents

