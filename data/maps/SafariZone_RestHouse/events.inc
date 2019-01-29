SafariZone_RestHouse_EventObjects:
	object_event 1, EVENT_OBJ_GFX_YOUNGSTER, 0, 7, 4, 0, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 0, 0, SafariZone_RestHouse_EventScript_242BE7, 0
	object_event 2, EVENT_OBJ_GFX_PSYCHIC_M, 0, 8, 4, 0, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 0, 0, SafariZone_RestHouse_EventScript_242BF0, 0
	object_event 3, EVENT_OBJ_GFX_FAT_MAN, 0, 2, 5, 3, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 0, 0, SafariZone_RestHouse_EventScript_242BF9, 0

SafariZone_RestHouse_MapWarps:
	warp_def 3, 8, 0, 0, MAP_SAFARI_ZONE_SOUTHWEST
	warp_def 4, 8, 0, 0, MAP_SAFARI_ZONE_SOUTHWEST

SafariZone_RestHouse_MapEvents::
	map_events SafariZone_RestHouse_EventObjects, SafariZone_RestHouse_MapWarps, 0x0, 0x0

