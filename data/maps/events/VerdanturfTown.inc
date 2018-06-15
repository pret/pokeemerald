VerdanturfTown_EventObjects: @ 8527CDC
	object_event 1, EVENT_OBJ_GFX_MAN_2, 0, 0, 4, 17, 3, 5, 1, 0, 0, 0, VerdanturfTown_EventScript_1EB5A8, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_LITTLE_GIRL_1, 0, 0, 9, 2, 3, 9, 1, 0, 0, 0, VerdanturfTown_EventScript_1EB575, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_BOY_1, 0, 0, 7, 11, 3, 3, 16, 0, 0, 0, VerdanturfTown_EventScript_1EB5BA, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_CAMPER, 0, 0, 7, 6, 3, 5, 1, 0, 0, 0, VerdanturfTown_EventScript_1EB5B1, 0, 0, 0

VerdanturfTown_MapWarps: @ 8527D3C
	warp_def 3, 7, 0, 0, MAP_VERDANTURF_TOWN_BATTLE_TENT_LOBBY
	warp_def 12, 3, 0, 0, MAP_VERDANTURF_TOWN_MART
	warp_def 16, 3, 0, 0, MAP_VERDANTURF_TOWN_POKEMON_CENTER_1F
	warp_def 10, 14, 0, 0, MAP_VERDANTURF_TOWN_WANDAS_HOUSE
	warp_def 8, 1, 0, 1, MAP_RUSTURF_TUNNEL
	warp_def 1, 14, 0, 0, MAP_VERDANTURF_TOWN_FRIENDSHIP_RATERS_HOUSE
	warp_def 17, 15, 0, 0, MAP_VERDANTURF_TOWN_HOUSE

VerdanturfTown_MapBGEvents: @ 8527D74
	bg_event 14, 3, 0, 1, 0, VerdanturfTown_EventScript_271E6A
	bg_event 14, 6, 0, 0, 0, VerdanturfTown_EventScript_1EB5D9
	bg_event 17, 3, 0, 1, 0, VerdanturfTown_EventScript_271E73
	bg_event 7, 14, 0, 0, 0, VerdanturfTown_EventScript_1EB5E2
	bg_event 13, 3, 0, 1, 0, VerdanturfTown_EventScript_271E6A
	bg_event 18, 3, 0, 1, 0, VerdanturfTown_EventScript_271E73
	bg_event 1, 8, 0, 0, 0, VerdanturfTown_EventScript_1EB5EB
	bg_event 7, 3, 0, 0, 0, VerdanturfTown_EventScript_1EB5F4

VerdanturfTown_MapEvents:: @ 8527DD4
	map_events VerdanturfTown_EventObjects, VerdanturfTown_MapWarps, 0x0, VerdanturfTown_MapBGEvents

