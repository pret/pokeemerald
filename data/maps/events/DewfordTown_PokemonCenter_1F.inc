DewfordTown_PokemonCenter_1F_EventObjects: @ 852DA34
	object_event 1, EVENT_OBJ_GFX_NURSE, 0, 7, 2, 3, 8, 0, 0, 0, DewfordTown_PokemonCenter_1F_EventScript_1FC537, 0
	object_event 2, EVENT_OBJ_GFX_WOMAN_2, 0, 10, 6, 3, 10, 0, 0, 0, DewfordTown_PokemonCenter_1F_EventScript_1FC545, 0
	object_event 3, EVENT_OBJ_GFX_MAN_4, 0, 5, 5, 0, 5, 18, 0, 0, DewfordTown_PokemonCenter_1F_EventScript_1FC54E, 0

DewfordTown_PokemonCenter_1F_MapWarps: @ 852DA7C
	warp_def 7, 8, 3, 1, MAP_DEWFORD_TOWN
	warp_def 6, 8, 3, 1, MAP_DEWFORD_TOWN
	warp_def 1, 6, 4, 0, MAP_DEWFORD_TOWN_POKEMON_CENTER_2F

DewfordTown_PokemonCenter_1F_MapEvents:: @ 852DA94
	map_events DewfordTown_PokemonCenter_1F_EventObjects, DewfordTown_PokemonCenter_1F_MapWarps, 0x0, 0x0

