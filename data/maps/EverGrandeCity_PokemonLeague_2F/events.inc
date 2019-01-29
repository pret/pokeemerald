EverGrandeCity_PokemonLeague_2F_EventObjects:
	object_event 1, EVENT_OBJ_GFX_TEALA, 0, 6, 2, 0, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, EverGrandeCity_PokemonLeague_2F_EventScript_27375B, 0
	object_event 2, EVENT_OBJ_GFX_TEALA, 0, 2, 2, 0, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, EverGrandeCity_PokemonLeague_2F_EventScript_273761, 0
	object_event 3, EVENT_OBJ_GFX_TEALA, 0, 10, 2, 0, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, EverGrandeCity_PokemonLeague_2F_EventScript_273767, 0
	object_event 4, EVENT_OBJ_GFX_MYSTERY_GIFT_MAN, 0, 1, 2, 0, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, EverGrandeCity_PokemonLeague_2F_EventScript_276B03, FLAG_HIDE_POKEMON_CENTER_2F_MYSTERY_GIFT_MAN

EverGrandeCity_PokemonLeague_2F_MapWarps:
	warp_def 1, 6, 4, 4, MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER

EverGrandeCity_PokemonLeague_2F_MapEvents::
	map_events EverGrandeCity_PokemonLeague_2F_EventObjects, EverGrandeCity_PokemonLeague_2F_MapWarps, 0x0, 0x0

