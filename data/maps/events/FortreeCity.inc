FortreeCity_EventObjects: @ 8526B9C
	object_event 1, EVENT_OBJ_GFX_MAN_2, 0, 0, 31, 3, 4, 1, 0, 0, 0, 0, FortreeCity_EventScript_1E25B6, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_GIRL_1, 0, 0, 32, 16, 3, 2, 17, 0, 0, 0, FortreeCity_EventScript_1E25DE, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_WOMAN_7, 0, 0, 32, 10, 3, 3, 16, 0, 0, 0, FortreeCity_EventScript_1E25BF, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_BOY_1, 0, 0, 11, 14, 4, 1, 0, 0, 0, 0, FortreeCity_EventScript_1E25F0, 0, 0, 0
	object_event 5, EVENT_OBJ_GFX_OLD_MAN_2, 0, 0, 8, 10, 3, 1, 0, 0, 0, 0, FortreeCity_EventScript_1E25E7, 0, 0, 0
	object_event 6, EVENT_OBJ_GFX_BOY_5, 0, 0, 9, 16, 3, 8, 0, 0, 0, 0, FortreeCity_EventScript_1E25F9, 0, 0, 0
	object_event 7, EVENT_OBJ_GFX_KECLEON_1, 0, 0, 25, 8, 3, 76, 17, 0, 0, 0, FortreeCity_EventScript_1E2614, 969, 0, 0

FortreeCity_MapWarps: @ 8526C44
	warp_def 5, 6, 0, 0, FORTREE_CITY_POKEMON_CENTER_1F
	warp_def 10, 3, 0, 0, FORTREE_CITY_HOUSE_1
	warp_def 22, 11, 0, 0, FORTREE_CITY_GYM
	warp_def 4, 14, 0, 0, FORTREE_CITY_MART
	warp_def 17, 3, 0, 0, FORTREE_CITY_HOUSE_2
	warp_def 25, 3, 0, 0, FORTREE_CITY_HOUSE_3
	warp_def 32, 2, 0, 0, FORTREE_CITY_HOUSE_4
	warp_def 12, 13, 0, 0, FORTREE_CITY_HOUSE_5
	warp_def 37, 13, 0, 0, FORTREE_CITY_DECORATION_SHOP

FortreeCity_MapBGEvents: @ 8526C8C
	bg_event 6, 9, 0, 0, 0, FortreeCity_EventScript_1E2602
	bg_event 7, 6, 0, 1, 0, FortreeCity_EventScript_271E73
	bg_event 5, 14, 0, 1, 0, FortreeCity_EventScript_271E6A
	bg_event 26, 10, 0, 0, 0, FortreeCity_EventScript_1E260B
	bg_event 6, 6, 0, 1, 0, FortreeCity_EventScript_271E73
	bg_event 6, 14, 0, 1, 0, FortreeCity_EventScript_271E6A

FortreeCity_MapEvents:: @ 8526CD4
	map_events FortreeCity_EventObjects, FortreeCity_MapWarps, 0x0, FortreeCity_MapBGEvents

