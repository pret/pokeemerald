RustboroCity_PokemonSchool_EventObjects: @ 85305EC
	object_event 1, EVENT_OBJ_GFX_BOY_5, 0, 8, 6, 3, 10, 0, 0, 0, 0, RustboroCity_PokemonSchool_EventScript_213F5F, 0
	object_event 2, EVENT_OBJ_GFX_BOY_5, 0, 9, 6, 3, 9, 0, 0, 0, 0, RustboroCity_PokemonSchool_EventScript_213F68, 0
	object_event 3, EVENT_OBJ_GFX_BOY_4, 0, 3, 8, 3, 7, 0, 0, 0, 0, RustboroCity_PokemonSchool_EventScript_213F71, 0
	object_event 4, EVENT_OBJ_GFX_LASS, 0, 10, 8, 3, 7, 0, 0, 0, 0, RustboroCity_PokemonSchool_EventScript_213F7A, 0
	object_event 5, EVENT_OBJ_GFX_SCHOOL_KID_M, 0, 3, 6, 3, 8, 0, 0, 0, 0, RustboroCity_PokemonSchool_EventScript_213F83, 0
	object_event 6, EVENT_OBJ_GFX_GENTLEMAN, 0, 5, 3, 3, 8, 1, 1, 0, 0, RustboroCity_PokemonSchool_EventScript_213F95, 0
	object_event 7, EVENT_OBJ_GFX_SCOTT, 0, 0, 10, 0, 7, 1, 1, 0, 0, RustboroCity_PokemonSchool_EventScript_214040, 999

RustboroCity_PokemonSchool_MapWarps: @ 8530694
	warp_def 5, 10, 0, 4, MAP_RUSTBORO_CITY
	warp_def 6, 10, 0, 4, MAP_RUSTBORO_CITY

RustboroCity_PokemonSchool_MapBGEvents: @ 85306A4
	bg_event 5, 2, 0, 0, 0, RustboroCity_PokemonSchool_EventScript_213EA9
	bg_event 4, 2, 0, 0, 0, RustboroCity_PokemonSchool_EventScript_213EA9
	bg_event 6, 2, 0, 0, 0, RustboroCity_PokemonSchool_EventScript_213EA9
	bg_event 7, 2, 0, 0, 0, RustboroCity_PokemonSchool_EventScript_213EA9
	bg_event 3, 5, 0, 0, 0, RustboroCity_PokemonSchool_EventScript_213F8C

RustboroCity_PokemonSchool_MapEvents:: @ 85306E0
	map_events RustboroCity_PokemonSchool_EventObjects, RustboroCity_PokemonSchool_MapWarps, 0x0, RustboroCity_PokemonSchool_MapBGEvents

