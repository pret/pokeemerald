SootopolisCity_PokemonCenter_1F_MapObjects: @ 8533174
	object_event 1, MAP_OBJ_GFX_NURSE, 0, 0, 7, 2, 3, 8, 0, 0, 0, 0, SootopolisCity_PokemonCenter_1F_EventScript_226500, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_GENTLEMAN, 0, 0, 12, 4, 3, 2, 17, 0, 0, 0, SootopolisCity_PokemonCenter_1F_EventScript_22650E, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_WOMAN_7, 0, 0, 4, 7, 3, 5, 1, 0, 0, 0, SootopolisCity_PokemonCenter_1F_EventScript_226538, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_WOMAN_1, 0, 0, 2, 3, 3, 2, 17, 0, 0, 0, SootopolisCity_PokemonCenter_1F_EventScript_2C8256, 0, 0, 0

SootopolisCity_PokemonCenter_1F_MapWarps: @ 85331D4
	warp_def 7, 8, 3, 0, SOOTOPOLIS_CITY
	warp_def 6, 8, 3, 0, SOOTOPOLIS_CITY
	warp_def 1, 6, 4, 0, SOOTOPOLIS_CITY_POKEMON_CENTER_2F

SootopolisCity_PokemonCenter_1F_MapEvents:: @ 85331EC
	map_events SootopolisCity_PokemonCenter_1F_MapObjects, SootopolisCity_PokemonCenter_1F_MapWarps, 0x0, 0x0

