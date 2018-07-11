SafariZone_Southwest_EventObjects: @ 853B24C
	object_event 1, EVENT_OBJ_GFX_WOMAN_3, 0, 22, 9, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, SafariZone_Southwest_EventScript_23D267, 0
	object_event 2, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 37, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, SafariZone_Southwest_EventScript_2912D6, 1131

SafariZone_Southwest_MapWarps: @ 853B27C
	warp_def 29, 7, 3, 0, MAP_SAFARI_ZONE_REST_HOUSE

SafariZone_Southwest_MapBGEvents: @ 853B284
	bg_event 32, 7, 3, BG_EVENT_PLAYER_FACING_ANY, SafariZone_Southwest_EventScript_23D270

SafariZone_Southwest_MapEvents:: @ 853B290
	map_events SafariZone_Southwest_EventObjects, SafariZone_Southwest_MapWarps, 0x0, SafariZone_Southwest_MapBGEvents

