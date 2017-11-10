PetalburgCity_Mart_MapObjects: @ 852F294
	object_event 1, MAP_OBJ_GFX_MART_EMPLOYEE, 0, 0, 1, 3, 3, 10, 0, 0, 0, 0, PetalburgCity_Mart_EventScript_207D69, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_MAN_1, 0, 0, 9, 4, 3, 10, 0, 0, 0, 0, PetalburgCity_Mart_EventScript_207DE8, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_BOY_1, 0, 0, 6, 3, 3, 8, 0, 0, 0, 0, PetalburgCity_Mart_EventScript_207DDF, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_WOMAN_3, 0, 0, 5, 5, 3, 10, 0, 0, 0, 0, PetalburgCity_Mart_EventScript_207DD6, 0, 0, 0

PetalburgCity_Mart_MapWarps: @ 852F2F4
	warp_def 3, 7, 0, 5, PETALBURG_CITY
	warp_def 4, 7, 0, 5, PETALBURG_CITY

PetalburgCity_Mart_MapEvents:: @ 852F304
	map_events PetalburgCity_Mart_MapObjects, PetalburgCity_Mart_MapWarps, 0x0, 0x0

