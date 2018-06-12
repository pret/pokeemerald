VerdanturfTown_House_EventObjects: @ 852EA1C
	object_event 1, EVENT_OBJ_GFX_WOMAN_7, 0, 0, 4, 5, 3, 7, 0, 0, 0, 0, VerdanturfTown_House_EventScript_20335F, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_WOMAN_7, 0, 0, 4, 4, 3, 8, 0, 0, 0, 0, VerdanturfTown_House_EventScript_203368, 0, 0, 0

VerdanturfTown_House_MapWarps: @ 852EA4C
	warp_def 3, 8, 0, 6, VERDANTURF_TOWN
	warp_def 4, 8, 0, 6, VERDANTURF_TOWN

VerdanturfTown_House_MapEvents:: @ 852EA5C
	map_events VerdanturfTown_House_EventObjects, VerdanturfTown_House_MapWarps, 0x0, 0x0

