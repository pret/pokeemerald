PetalburgCity_PokemonCenter_1F_EventObjects: @ 852F164
	object_event 1, EVENT_OBJ_GFX_NURSE, 0, 0, 7, 2, 3, 8, 0, 0, 0, 0, PetalburgCity_PokemonCenter_1F_EventScript_2079FC, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_MAN_5, 0, 0, 11, 2, 3, 8, 0, 0, 0, 0, PetalburgCity_PokemonCenter_1F_EventScript_291539, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_FAT_MAN, 0, 0, 2, 3, 3, 8, 0, 0, 0, 0, PetalburgCity_PokemonCenter_1F_EventScript_207A0A, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_YOUNGSTER, 0, 0, 9, 6, 3, 2, 17, 0, 0, 0, PetalburgCity_PokemonCenter_1F_EventScript_207A13, 0, 0, 0
	object_event 5, EVENT_OBJ_GFX_WOMAN_7, 0, 0, 5, 4, 3, 1, 17, 0, 0, 0, PetalburgCity_PokemonCenter_1F_EventScript_207A1C, 0, 0, 0

PetalburgCity_PokemonCenter_1F_MapWarps: @ 852F1DC
	warp_def 7, 8, 3, 3, PETALBURG_CITY
	warp_def 6, 8, 3, 3, PETALBURG_CITY
	warp_def 1, 6, 4, 0, PETALBURG_CITY_POKEMON_CENTER_2F

PetalburgCity_PokemonCenter_1F_MapEvents:: @ 852F1F4
	map_events PetalburgCity_PokemonCenter_1F_EventObjects, PetalburgCity_PokemonCenter_1F_MapWarps, 0x0, 0x0

