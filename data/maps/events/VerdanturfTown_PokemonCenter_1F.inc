VerdanturfTown_PokemonCenter_1F_EventObjects: @ 852E814
	object_event 1, EVENT_OBJ_GFX_NURSE, 0, 0, 7, 2, 3, 8, 0, 0, 0, 0, VerdanturfTown_PokemonCenter_1F_EventScript_20273A, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_GENTLEMAN, 0, 0, 4, 5, 3, 5, 1, 0, 0, 0, VerdanturfTown_PokemonCenter_1F_EventScript_202748, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_OLD_MAN_1, 0, 0, 12, 2, 3, 7, 0, 0, 0, 0, VerdanturfTown_PokemonCenter_1F_EventScript_202751, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_LITTLE_BOY_2, 0, 0, 10, 6, 3, 9, 1, 0, 0, 0, VerdanturfTown_PokemonCenter_1F_EventScript_2C7FE6, 0, 0, 0

VerdanturfTown_PokemonCenter_1F_MapWarps: @ 852E874
	warp_def 7, 8, 3, 2, VERDANTURF_TOWN
	warp_def 6, 8, 3, 2, VERDANTURF_TOWN
	warp_def 1, 6, 4, 0, VERDANTURF_TOWN_POKEMON_CENTER_2F

VerdanturfTown_PokemonCenter_1F_MapEvents:: @ 852E88C
	map_events VerdanturfTown_PokemonCenter_1F_EventObjects, VerdanturfTown_PokemonCenter_1F_MapWarps, 0x0, 0x0

