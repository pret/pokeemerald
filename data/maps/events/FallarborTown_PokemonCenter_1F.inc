FallarborTown_PokemonCenter_1F_EventObjects: @ 852E4A0
	object_event 1, EVENT_OBJ_GFX_NURSE, 0, 7, 2, 3, 8, 0, 0, 0, FallarborTown_PokemonCenter_1F_EventScript_200BE1, 0
	object_event 2, EVENT_OBJ_GFX_GIRL_3, 0, 10, 6, 3, 10, 0, 0, 0, FallarborTown_PokemonCenter_1F_EventScript_200BEF, 0
	object_event 3, EVENT_OBJ_GFX_OLD_MAN_1, 0, 2, 3, 3, 8, 0, 0, 0, FallarborTown_PokemonCenter_1F_EventScript_200BF8, 0
	object_event 4, EVENT_OBJ_GFX_WOMAN_3, 0, 10, 2, 3, 7, 0, 0, 0, FallarborTown_PokemonCenter_1F_EventScript_200C01, 871

FallarborTown_PokemonCenter_1F_MapWarps: @ 852E500
	warp_def 7, 8, 3, 2, MAP_FALLARBOR_TOWN
	warp_def 6, 8, 3, 2, MAP_FALLARBOR_TOWN
	warp_def 1, 6, 4, 0, MAP_FALLARBOR_TOWN_POKEMON_CENTER_2F

FallarborTown_PokemonCenter_1F_MapEvents:: @ 852E518
	map_events FallarborTown_PokemonCenter_1F_EventObjects, FallarborTown_PokemonCenter_1F_MapWarps, 0x0, 0x0

