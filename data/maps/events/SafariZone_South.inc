SafariZone_South_MapObjects: @ 853B2A4
	object_event 1, MAP_OBJ_GFX_CAMPER, 0, 0, 32, 34, 4, 8, 0, 0, 0, 0, SafariZone_South_EventScript_23D2E5, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_BOY_1, 0, 0, 26, 28, 3, 2, 17, 0, 0, 0, SafariZone_South_EventScript_23D2CA, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_MAN_5, 0, 0, 16, 6, 5, 8, 0, 0, 0, 0, SafariZone_South_EventScript_23D2D3, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_YOUNGSTER, 0, 0, 15, 31, 3, 2, 17, 0, 0, 0, SafariZone_South_EventScript_23D2DC, 0, 0, 0
	object_event 5, MAP_OBJ_GFX_CAMPER, 0, 0, 36, 16, 3, 9, 17, 0, 0, 0, SafariZone_South_EventScript_23D390, 717, 0, 0
	object_event 6, MAP_OBJ_GFX_CAMPER, 0, 0, 36, 17, 3, 9, 17, 0, 0, 0, SafariZone_South_EventScript_23D3A2, 717, 0, 0

SafariZone_South_MapWarps: @ 853B334
	warp_def 32, 33, 0, 0, ROUTE_121_SAFARI_ZONE_ENTRANCE

SafariZone_South_MapEvents:: @ 853B33C
	map_events SafariZone_South_MapObjects, SafariZone_South_MapWarps, 0x0, 0x0

