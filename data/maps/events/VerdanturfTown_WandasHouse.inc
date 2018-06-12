VerdanturfTown_WandasHouse_EventObjects: @ 852E92C
	object_event 1, EVENT_OBJ_GFX_WALLY, 0, 0, 14, 5, 3, 2, 17, 0, 0, 0, VerdanturfTown_WandasHouse_EventScript_2028BF, 806, 0, 0
	object_event 2, EVENT_OBJ_GFX_BLACK_BELT, 0, 0, 5, 4, 3, 8, 0, 0, 0, 0, VerdanturfTown_WandasHouse_EventScript_202913, 808, 0, 0
	object_event 3, EVENT_OBJ_GFX_MAN_3, 0, 0, 7, 2, 3, 8, 0, 0, 0, 0, VerdanturfTown_WandasHouse_EventScript_2028E1, 809, 0, 0
	object_event 4, EVENT_OBJ_GFX_WOMAN_2, 0, 0, 2, 4, 3, 10, 0, 0, 0, 0, VerdanturfTown_WandasHouse_EventScript_20294E, 0, 0, 0
	object_event 5, EVENT_OBJ_GFX_WOMAN_3, 0, 0, 5, 5, 3, 9, 0, 0, 0, 0, VerdanturfTown_WandasHouse_EventScript_20291C, 984, 0, 0

VerdanturfTown_WandasHouse_MapWarps: @ 852E9A4
	warp_def 7, 7, 0, 3, VERDANTURF_TOWN
	warp_def 8, 7, 0, 3, VERDANTURF_TOWN

VerdanturfTown_WandasHouse_MapEvents:: @ 852E9B4
	map_events VerdanturfTown_WandasHouse_EventObjects, VerdanturfTown_WandasHouse_MapWarps, 0x0, 0x0

