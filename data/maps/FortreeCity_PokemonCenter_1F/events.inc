FortreeCity_PokemonCenter_1F_EventObjects: @ 8530D94
	object_event 1, EVENT_OBJ_GFX_NURSE, 0, 7, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, FortreeCity_PokemonCenter_1F_EventScript_2173E7, 0
	object_event 2, EVENT_OBJ_GFX_GENTLEMAN, 0, 4, 7, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, FortreeCity_PokemonCenter_1F_EventScript_2173F5, 0
	object_event 3, EVENT_OBJ_GFX_MAN_4, 0, 8, 5, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, FortreeCity_PokemonCenter_1F_EventScript_2173FE, 0
	object_event 4, EVENT_OBJ_GFX_BOY_3, 0, 2, 3, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, FortreeCity_PokemonCenter_1F_EventScript_217407, 0

FortreeCity_PokemonCenter_1F_MapWarps: @ 8530DF4
	warp_def 7, 8, 3, 0, MAP_FORTREE_CITY
	warp_def 6, 8, 3, 0, MAP_FORTREE_CITY
	warp_def 1, 6, 4, 0, MAP_FORTREE_CITY_POKEMON_CENTER_2F

FortreeCity_PokemonCenter_1F_MapEvents:: @ 8530E0C
	map_events FortreeCity_PokemonCenter_1F_EventObjects, FortreeCity_PokemonCenter_1F_MapWarps, 0x0, 0x0

