SafariZone_RestHouse_EventObjects: @ 853B8FC
	object_event 1, EVENT_OBJ_GFX_YOUNGSTER, 0, 0, 7, 4, 0, 10, 17, 0, 0, 0, SafariZone_RestHouse_EventScript_242BE7, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_PSYCHIC_M, 0, 0, 8, 4, 0, 9, 17, 0, 0, 0, SafariZone_RestHouse_EventScript_242BF0, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_FAT_MAN, 0, 0, 2, 5, 3, 10, 17, 0, 0, 0, SafariZone_RestHouse_EventScript_242BF9, 0, 0, 0

SafariZone_RestHouse_MapWarps: @ 853B944
	warp_def 3, 8, 0, 0, MAP_SAFARI_ZONE_SOUTHWEST
	warp_def 4, 8, 0, 0, MAP_SAFARI_ZONE_SOUTHWEST

SafariZone_RestHouse_MapEvents:: @ 853B954
	map_events SafariZone_RestHouse_EventObjects, SafariZone_RestHouse_MapWarps, 0x0, 0x0

