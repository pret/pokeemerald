EverGrandeCity_PokemonCenter_1F_EventObjects: @ 8533930
	object_event 1, EVENT_OBJ_GFX_NURSE, 0, 0, 7, 2, 3, 8, 0, 0, 0, 0, EverGrandeCity_PokemonCenter_1F_EventScript_229A59, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_WOMAN_7, 0, 0, 5, 5, 3, 8, 0, 0, 0, 0, EverGrandeCity_PokemonCenter_1F_EventScript_229A67, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_OLD_MAN_1, 0, 0, 10, 7, 3, 10, 0, 0, 0, 0, EverGrandeCity_PokemonCenter_1F_EventScript_229A70, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_SCOTT, 0, 0, 9, 4, 3, 7, 0, 0, 0, 0, EverGrandeCity_PokemonCenter_1F_EventScript_229A79, 793, 0, 0

EverGrandeCity_PokemonCenter_1F_MapWarps: @ 8533990
	warp_def 7, 8, 3, 1, EVER_GRANDE_CITY
	warp_def 6, 8, 3, 1, EVER_GRANDE_CITY
	warp_def 1, 6, 4, 0, EVER_GRANDE_CITY_POKEMON_CENTER_2F

EverGrandeCity_PokemonCenter_1F_MapEvents:: @ 85339A8
	map_events EverGrandeCity_PokemonCenter_1F_EventObjects, EverGrandeCity_PokemonCenter_1F_MapWarps, 0x0, 0x0

