PetalburgCity_PokemonCenter_1F_EventObjects:
	object_event 1, EVENT_OBJ_GFX_NURSE, 0, 7, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, PetalburgCity_PokemonCenter_1F_EventScript_2079FC, 0
	object_event 2, EVENT_OBJ_GFX_MAN_4, 0, 11, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, PetalburgCity_PokemonCenter_1F_EventScript_291539, 0
	object_event 3, EVENT_OBJ_GFX_FAT_MAN, 0, 2, 3, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, PetalburgCity_PokemonCenter_1F_EventScript_207A0A, 0
	object_event 4, EVENT_OBJ_GFX_YOUNGSTER, 0, 9, 6, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, PetalburgCity_PokemonCenter_1F_EventScript_207A13, 0
	object_event 5, EVENT_OBJ_GFX_WOMAN_5, 0, 5, 4, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, PetalburgCity_PokemonCenter_1F_EventScript_207A1C, 0

PetalburgCity_PokemonCenter_1F_MapWarps:
	warp_def 7, 8, 3, 3, MAP_PETALBURG_CITY
	warp_def 6, 8, 3, 3, MAP_PETALBURG_CITY
	warp_def 1, 6, 4, 0, MAP_PETALBURG_CITY_POKEMON_CENTER_2F

PetalburgCity_PokemonCenter_1F_MapEvents::
	map_events PetalburgCity_PokemonCenter_1F_EventObjects, PetalburgCity_PokemonCenter_1F_MapWarps, 0x0, 0x0

