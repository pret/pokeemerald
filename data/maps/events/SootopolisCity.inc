SootopolisCity_MapObjects: @ 8527314
	object_event 1, MAP_OBJ_GFX_OLD_MAN_1, 0, 0, 31, 18, 3, 8, 0, 0, 0, 0, SootopolisCity_EventScript_1E5E8D, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_WOMAN_5, 0, 0, 47, 33, 0, 9, 0, 0, 0, 0, SootopolisCity_EventScript_1E5FE2, 854, 0, 0
	object_event 3, MAP_OBJ_GFX_GIRL_2, 0, 0, 9, 43, 3, 5, 1, 0, 0, 0, SootopolisCity_EventScript_1E5ED8, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_LITTLE_BOY_1, 0, 0, 51, 14, 3, 8, 0, 0, 0, 0, SootopolisCity_EventScript_1E608E, 0, 0, 0
	object_event 5, MAP_OBJ_GFX_BOY_1, 0, 0, 43, 26, 3, 1, 0, 0, 0, 0, SootopolisCity_EventScript_1E60E3, 0, 0, 0
	object_event 6, MAP_OBJ_GFX_MAN_1, 0, 0, 26, 4, 3, 5, 1, 0, 0, 0, SootopolisCity_EventScript_1E6017, 839, 0, 0
	object_event 7, MAP_OBJ_GFX_STEVEN, 0, 0, 20, 36, 3, 8, 17, 0, 0, 0, SootopolisCity_EventScript_1E6166, 973, 0, 0
	object_event 8, MAP_OBJ_GFX_WOMAN_7, 0, 0, 49, 34, 3, 3, 17, 0, 0, 0, SootopolisCity_EventScript_1E6038, 0, 0, 0
	object_event 9, MAP_OBJ_GFX_GROUDON_3, 0, 0, 28, 44, 0, 80, 17, 0, 0, 0, 0x0, 998, 0, 0
	object_event 10, MAP_OBJ_GFX_KYOGRE_3, 0, 0, 34, 44, 1, 79, 17, 0, 0, 0, 0x0, 997, 0, 0
	object_event 11, MAP_OBJ_GFX_RAYQUAZA_2, 0, 0, 31, 41, 1, 10, 17, 0, 0, 0, 0x0, 996, 0, 0
	object_event 12, MAP_OBJ_GFX_MANIAC, 0, 0, 17, 44, 3, 10, 17, 0, 0, 0, SootopolisCity_EventScript_1E6411, 854, 0, 0
	object_event 13, MAP_OBJ_GFX_GIRL_3, 0, 0, 14, 42, 3, 10, 17, 0, 0, 0, SootopolisCity_EventScript_1E63DB, 854, 0, 0
	object_event 14, MAP_OBJ_GFX_BLACK_BELT, 0, 0, 17, 40, 3, 10, 17, 0, 0, 0, SootopolisCity_EventScript_1E6393, 854, 0, 0
	object_event 15, MAP_OBJ_GFX_BOY_2, 0, 0, 19, 37, 3, 8, 17, 0, 0, 0, SootopolisCity_EventScript_1E635D, 854, 0, 0
	object_event 16, MAP_OBJ_GFX_MAXIE, 0, 0, 29, 33, 3, 8, 17, 0, 0, 0, SootopolisCity_EventScript_1E64F2, 827, 0, 0
	object_event 17, MAP_OBJ_GFX_ARCHIE, 0, 0, 31, 33, 3, 8, 17, 0, 0, 0, SootopolisCity_EventScript_1E651F, 826, 0, 0
	object_event 18, MAP_OBJ_GFX_WALLACE, 0, 0, 31, 18, 3, 8, 17, 0, 0, 0, SootopolisCity_EventScript_1E6446, 816, 0, 0

SootopolisCity_MapWarps: @ 85274C4
	warp_def 43, 31, 0, 0, SOOTOPOLIS_CITY_POKEMON_CENTER_1F
	warp_def 17, 29, 0, 0, SOOTOPOLIS_CITY_MART
	warp_def 31, 32, 0, 0, SOOTOPOLIS_CITY_GYM_1F
	warp_def 31, 16, 3, 0, CAVE_OF_ORIGIN_ENTRANCE
	warp_def 9, 6, 0, 0, SOOTOPOLIS_CITY_HOUSE_1
	warp_def 45, 6, 0, 0, SOOTOPOLIS_CITY_HOUSE_2
	warp_def 9, 17, 0, 0, SOOTOPOLIS_CITY_HOUSE_3
	warp_def 44, 17, 0, 0, SOOTOPOLIS_CITY_HOUSE_4
	warp_def 9, 26, 0, 0, SOOTOPOLIS_CITY_HOUSE_5
	warp_def 53, 28, 0, 0, SOOTOPOLIS_CITY_HOUSE_6
	warp_def 8, 35, 0, 0, SOOTOPOLIS_CITY_HOUSE_7
	warp_def 48, 25, 0, 0, SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE
	warp_def 51, 36, 0, 0, SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F

SootopolisCity_MapBGEvents: @ 852752C
	bg_event 33, 34, 3, 0, 0, SootopolisCity_EventScript_1E614B
	bg_event 19, 29, 0, 1, 0, SootopolisCity_EventScript_271E6A
	bg_event 44, 31, 0, 1, 0, SootopolisCity_EventScript_271E73
	bg_event 45, 31, 0, 1, 0, SootopolisCity_EventScript_271E73
	bg_event 18, 29, 0, 1, 0, SootopolisCity_EventScript_271E6A
	bg_event 41, 37, 0, 0, 0, SootopolisCity_EventScript_1E6154

SootopolisCity_MapEvents:: @ 8527574
	map_events SootopolisCity_MapObjects, SootopolisCity_MapWarps, 0x0, SootopolisCity_MapBGEvents

