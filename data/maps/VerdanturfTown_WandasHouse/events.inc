VerdanturfTown_WandasHouse_EventObjects: @ 852E92C
	object_event 1, EVENT_OBJ_GFX_WALLY, 0, 14, 5, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, VerdanturfTown_WandasHouse_EventScript_2028BF, FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	object_event 2, EVENT_OBJ_GFX_BLACK_BELT, 0, 5, 4, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, VerdanturfTown_WandasHouse_EventScript_202913, FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_LOVER_MAN
	object_event 3, EVENT_OBJ_GFX_POKEFAN_M, 0, 7, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, VerdanturfTown_WandasHouse_EventScript_2028E1, FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	object_event 4, EVENT_OBJ_GFX_POKEFAN_F, 0, 2, 4, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, VerdanturfTown_WandasHouse_EventScript_20294E, 0
	object_event 5, EVENT_OBJ_GFX_WOMAN_2, 0, 5, 5, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, VerdanturfTown_WandasHouse_EventScript_20291C, FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_LOVER_WOMAN

VerdanturfTown_WandasHouse_MapWarps: @ 852E9A4
	warp_def 7, 7, 0, 3, MAP_VERDANTURF_TOWN
	warp_def 8, 7, 0, 3, MAP_VERDANTURF_TOWN

VerdanturfTown_WandasHouse_MapEvents:: @ 852E9B4
	map_events VerdanturfTown_WandasHouse_EventObjects, VerdanturfTown_WandasHouse_MapWarps, 0x0, 0x0

