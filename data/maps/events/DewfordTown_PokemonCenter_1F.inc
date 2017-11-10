DewfordTown_PokemonCenter_1F_MapObjects: @ 852DA34
	object_event 1, MAP_OBJ_GFX_NURSE, 0, 0, 7, 2, 3, 8, 0, 0, 0, 0, DewfordTown_PokemonCenter_1F_EventScript_1FC537, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_WOMAN_2, 0, 0, 10, 6, 3, 10, 0, 0, 0, 0, DewfordTown_PokemonCenter_1F_EventScript_1FC545, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_MAN_4, 0, 0, 5, 5, 0, 5, 18, 0, 0, 0, DewfordTown_PokemonCenter_1F_EventScript_1FC54E, 0, 0, 0

DewfordTown_PokemonCenter_1F_MapWarps: @ 852DA7C
	warp_def 7, 8, 3, 1, DEWFORD_TOWN
	warp_def 6, 8, 3, 1, DEWFORD_TOWN
	warp_def 1, 6, 4, 0, DEWFORD_TOWN_POKEMON_CENTER_2F

DewfordTown_PokemonCenter_1F_MapEvents:: @ 852DA94
	map_events DewfordTown_PokemonCenter_1F_MapObjects, DewfordTown_PokemonCenter_1F_MapWarps, 0x0, 0x0

