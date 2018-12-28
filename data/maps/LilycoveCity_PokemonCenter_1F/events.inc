LilycoveCity_PokemonCenter_1F_EventObjects: @ 8531BCC
	object_event 1, EVENT_OBJ_GFX_NURSE, 0, 7, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, LilycoveCity_PokemonCenter_1F_EventScript_21C5E8, 0
	object_event 2, EVENT_OBJ_GFX_BOY_1, 0, 10, 7, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, LilycoveCity_PokemonCenter_1F_EventScript_21C5F6, 0
	object_event 3, EVENT_OBJ_GFX_MANIAC, 0, 11, 8, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, LilycoveCity_PokemonCenter_1F_EventScript_21C5FF, 0
	object_event 4, EVENT_OBJ_GFX_VAR_0, 0, 1, 3, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, LilycoveCity_PokemonCenter_1F_EventScript_2A836B, 0
	object_event 5, EVENT_OBJ_GFX_VAR_1, 0, 2, 3, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, LilycoveCity_PokemonCenter_1F_EventScript_2A89C7, FLAG_HIDE_LILYCOVE_POKEMON_CENTER_LADY

LilycoveCity_PokemonCenter_1F_MapWarps: @ 8531C44
	warp_def 7, 8, 3, 2, MAP_LILYCOVE_CITY
	warp_def 6, 8, 3, 2, MAP_LILYCOVE_CITY
	warp_def 1, 6, 4, 0, MAP_LILYCOVE_CITY_POKEMON_CENTER_2F

LilycoveCity_PokemonCenter_1F_MapEvents:: @ 8531C5C
	map_events LilycoveCity_PokemonCenter_1F_EventObjects, LilycoveCity_PokemonCenter_1F_MapWarps, 0x0, 0x0

