FallarborTown_PokemonCenter_1F_EventObjects:
	object_event 1, EVENT_OBJ_GFX_NURSE, 0, 7, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, FallarborTown_PokemonCenter_1F_EventScript_200BE1, 0
	object_event 2, EVENT_OBJ_GFX_GIRL_3, 0, 10, 6, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, FallarborTown_PokemonCenter_1F_EventScript_200BEF, 0
	object_event 3, EVENT_OBJ_GFX_EXPERT_M, 0, 2, 3, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, FallarborTown_PokemonCenter_1F_EventScript_200BF8, 0
	object_event 4, EVENT_OBJ_GFX_WOMAN_2, 0, 10, 2, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, FallarborTown_PokemonCenter_1F_EventScript_200C01, FLAG_HIDE_FALLORBOR_POKEMON_CENTER_LANETTE

FallarborTown_PokemonCenter_1F_MapWarps:
	warp_def 7, 8, 3, 2, MAP_FALLARBOR_TOWN
	warp_def 6, 8, 3, 2, MAP_FALLARBOR_TOWN
	warp_def 1, 6, 4, 0, MAP_FALLARBOR_TOWN_POKEMON_CENTER_2F

FallarborTown_PokemonCenter_1F_MapEvents::
	map_events FallarborTown_PokemonCenter_1F_EventObjects, FallarborTown_PokemonCenter_1F_MapWarps, 0x0, 0x0

