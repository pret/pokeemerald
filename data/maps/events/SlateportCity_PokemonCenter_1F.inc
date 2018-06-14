SlateportCity_PokemonCenter_1F_EventObjects: @ 852FBF0
	object_event 1, EVENT_OBJ_GFX_NURSE, 0, 0, 7, 2, 3, 8, 0, 0, 0, 0, SlateportCity_PokemonCenter_1F_EventScript_20DAD3, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_SAILOR, 0, 0, 2, 3, 3, 8, 0, 0, 0, 0, SlateportCity_PokemonCenter_1F_EventScript_20DAE1, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_WOMAN_7, 0, 0, 10, 7, 3, 10, 0, 0, 0, 0, SlateportCity_PokemonCenter_1F_EventScript_20DAEA, 0, 0, 0

SlateportCity_PokemonCenter_1F_MapWarps: @ 852FC38
	warp_def 7, 8, 3, 0, SLATEPORT_CITY
	warp_def 6, 8, 3, 0, SLATEPORT_CITY
	warp_def 1, 6, 4, 0, SLATEPORT_CITY_POKEMON_CENTER_2F

SlateportCity_PokemonCenter_1F_MapEvents:: @ 852FC50
	map_events SlateportCity_PokemonCenter_1F_EventObjects, SlateportCity_PokemonCenter_1F_MapWarps, 0x0, 0x0

