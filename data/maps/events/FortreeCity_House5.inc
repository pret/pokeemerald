FortreeCity_House5_MapObjects: @ 8531044
	object_event 1, MAP_OBJ_GFX_WOMAN_2, 0, 0, 6, 4, 3, 20, 0, 0, 0, 0, FortreeCity_House5_EventScript_217EF2, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_ZIGZAGOON_2, 0, 0, 6, 3, 3, 8, 0, 0, 0, 0, FortreeCity_House5_EventScript_217F04, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_MAN_1, 0, 0, 2, 4, 3, 10, 0, 0, 0, 0, FortreeCity_House5_EventScript_217EFB, 0, 0, 0

FortreeCity_House5_MapWarps: @ 853108C
	warp_def 3, 5, 0, 7, FORTREE_CITY
	warp_def 4, 5, 0, 7, FORTREE_CITY

FortreeCity_House5_MapEvents:: @ 853109C
	map_events FortreeCity_House5_MapObjects, FortreeCity_House5_MapWarps, 0x0, 0x0

