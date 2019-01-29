EverGrandeCity_PokemonLeague_1F_EventObjects:
	object_event 1, EVENT_OBJ_GFX_NURSE, 0, 3, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, EverGrandeCity_PokemonLeague_1F_EventScript_2295FC, 0
	object_event 2, EVENT_OBJ_GFX_MART_EMPLOYEE, 0, 16, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, EverGrandeCity_PokemonLeague_1F_EventScript_22960A, 0
	object_event 3, EVENT_OBJ_GFX_MAN_3, 0, 8, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, EverGrandeCity_PokemonLeague_1F_EventScript_229636, 0
	object_event 4, EVENT_OBJ_GFX_MAN_3, 0, 11, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, EverGrandeCity_PokemonLeague_1F_EventScript_229636, 0

EverGrandeCity_PokemonLeague_1F_MapWarps:
	warp_def 9, 11, 3, 0, MAP_EVER_GRANDE_CITY
	warp_def 10, 11, 3, 0, MAP_EVER_GRANDE_CITY
	warp_def 9, 1, 3, 0, MAP_EVER_GRANDE_CITY_HALL5
	warp_def 10, 1, 3, 0, MAP_EVER_GRANDE_CITY_HALL5
	warp_def 1, 7, 4, 0, MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_2F

EverGrandeCity_PokemonLeague_1F_MapEvents::
	map_events EverGrandeCity_PokemonLeague_1F_EventObjects, EverGrandeCity_PokemonLeague_1F_MapWarps, 0x0, 0x0

