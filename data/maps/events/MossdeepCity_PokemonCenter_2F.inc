MossdeepCity_PokemonCenter_2F_EventObjects: @ 8532AAC
	object_event 1, EVENT_OBJ_GFX_TEALA, 0, 0, 6, 2, 0, 8, 17, 0, 0, 0, MossdeepCity_PokemonCenter_2F_EventScript_27375B, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_TEALA, 0, 0, 2, 2, 3, 8, 17, 0, 0, 0, MossdeepCity_PokemonCenter_2F_EventScript_273761, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_TEALA, 0, 0, 10, 2, 0, 8, 17, 0, 0, 0, MossdeepCity_PokemonCenter_2F_EventScript_273767, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_MYSTERY_GIFT_MAN, 0, 0, 1, 2, 0, 8, 17, 0, 0, 0, MossdeepCity_PokemonCenter_2F_EventScript_276B03, 702, 0, 0
	object_event 5, EVENT_OBJ_GFX_WOMAN_7, 0, 0, 11, 7, 3, 5, 17, 0, 0, 0, MossdeepCity_PokemonCenter_2F_EventScript_22235B, 0, 0, 0

MossdeepCity_PokemonCenter_2F_MapWarps: @ 8532B24
	warp_def 1, 6, 4, 2, MOSSDEEP_CITY_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, UNION_ROOM
	warp_def 9, 1, 3, 0, TRADE_CENTER

MossdeepCity_PokemonCenter_2F_MapEvents:: @ 8532B3C
	map_events MossdeepCity_PokemonCenter_2F_EventObjects, MossdeepCity_PokemonCenter_2F_MapWarps, 0x0, 0x0

