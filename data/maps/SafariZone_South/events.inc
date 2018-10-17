SafariZone_South_EventObjects: @ 853B2A4
	object_event 1, EVENT_OBJ_GFX_CAMPER, 0, 32, 34, 4, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, SafariZone_South_EventScript_23D2E5, 0
	object_event 2, EVENT_OBJ_GFX_BOY_1, 0, 26, 28, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, SafariZone_South_EventScript_23D2CA, 0
	object_event 3, EVENT_OBJ_GFX_MAN_4, 0, 16, 6, 5, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, SafariZone_South_EventScript_23D2D3, 0
	object_event 4, EVENT_OBJ_GFX_YOUNGSTER, 0, 15, 31, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, SafariZone_South_EventScript_23D2DC, 0
	object_event 5, EVENT_OBJ_GFX_CAMPER, 0, 36, 16, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 0, 0, SafariZone_South_EventScript_23D390, FLAG_0x2CD
	object_event 6, EVENT_OBJ_GFX_CAMPER, 0, 36, 17, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 0, 0, SafariZone_South_EventScript_23D3A2, FLAG_0x2CD

SafariZone_South_MapWarps: @ 853B334
	warp_def 32, 33, 0, 0, MAP_ROUTE121_SAFARI_ZONE_ENTRANCE

SafariZone_South_MapEvents:: @ 853B33C
	map_events SafariZone_South_EventObjects, SafariZone_South_MapWarps, 0x0, 0x0

