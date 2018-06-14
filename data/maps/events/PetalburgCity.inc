PetalburgCity_EventObjects: @ 8525FD0
	object_event 1, EVENT_OBJ_GFX_WOMAN_5, 0, 0, 16, 18, 3, 2, 17, 0, 0, 0, PetalburgCity_EventScript_1DC3FD, 728, 0, 0
	object_event 2, EVENT_OBJ_GFX_WALLY, 0, 0, 15, 10, 3, 7, 0, 0, 0, 0, 0x0, 726, 0, 0
	object_event 3, EVENT_OBJ_GFX_BOY_1, 0, 0, 8, 22, 3, 8, 0, 0, 0, 0, PetalburgCity_EventScript_1DC3E6, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_GENTLEMAN, 0, 0, 20, 10, 3, 3, 16, 0, 0, 0, PetalburgCity_EventScript_1DC488, 0, 0, 0
	object_event 5, EVENT_OBJ_GFX_MAN_3, 0, 0, 15, 10, 3, 7, 0, 0, 0, 0, 0x0, 830, 0, 0
	object_event 6, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 19, 2, 3, 1, 0, 0, 0, 0, PetalburgCity_EventScript_2910B4, 1039, 0, 0
	object_event 7, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 3, 28, 3, 1, 0, 0, 0, 0, PetalburgCity_EventScript_2910C1, 1040, 0, 0
	object_event 8, EVENT_OBJ_GFX_BOY_2, 0, 0, 12, 15, 3, 1, 0, 0, 0, 0, PetalburgCity_EventScript_1DC82E, 0, 0, 0
	object_event 9, EVENT_OBJ_GFX_SCOTT, 0, 0, 13, 12, 3, 1, 17, 0, 0, 0, 0x0, 995, 0, 0

PetalburgCity_MapWarps: @ 85260A8
	warp_def 10, 19, 0, 0, PETALBURG_CITY_HOUSE_1
	warp_def 7, 5, 0, 0, PETALBURG_CITY_WALLYS_HOUSE
	warp_def 15, 8, 0, 0, PETALBURG_CITY_GYM
	warp_def 20, 16, 0, 0, PETALBURG_CITY_POKEMON_CENTER_1F
	warp_def 20, 24, 0, 0, PETALBURG_CITY_HOUSE_2
	warp_def 25, 12, 0, 0, PETALBURG_CITY_MART

PetalburgCity_MapCoordEvents: @ 85260D8
	coord_event 8, 10, 3, 0, VAR_0x4057, 0, 0, PetalburgCity_EventScript_1DC49A
	coord_event 8, 11, 3, 0, VAR_0x4057, 0, 0, PetalburgCity_EventScript_1DC4A6
	coord_event 8, 12, 3, 0, VAR_0x4057, 0, 0, PetalburgCity_EventScript_1DC4B2
	coord_event 8, 13, 3, 0, VAR_0x4057, 0, 0, PetalburgCity_EventScript_1DC4BE
	coord_event 4, 10, 3, 0, VAR_0x40C9, 0, 0, PetalburgCity_EventScript_1DC691
	coord_event 4, 11, 3, 0, VAR_0x40C9, 0, 0, PetalburgCity_EventScript_1DC6A7
	coord_event 4, 12, 3, 0, VAR_0x40C9, 0, 0, PetalburgCity_EventScript_1DC6BD
	coord_event 4, 13, 3, 0, VAR_0x40C9, 0, 0, PetalburgCity_EventScript_1DC6D3

PetalburgCity_MapBGEvents: @ 8526158
	bg_event 17, 10, 0, 0, 0, PetalburgCity_EventScript_1DC476
	bg_event 26, 12, 0, 1, 0, PetalburgCity_EventScript_271E6A
	bg_event 21, 16, 0, 1, 0, PetalburgCity_EventScript_271E73
	bg_event 17, 16, 0, 0, 0, PetalburgCity_EventScript_1DC47F
	bg_event 22, 16, 0, 1, 0, PetalburgCity_EventScript_271E73
	bg_event 27, 12, 0, 1, 0, PetalburgCity_EventScript_271E6A
	bg_event 8, 9, 0, 0, 0, PetalburgCity_EventScript_1DC491
	bg_event 11, 29, 3, 7, 0, ITEM_RARE_CANDY, 95, 0

PetalburgCity_MapEvents:: @ 85261B8
	map_events PetalburgCity_EventObjects, PetalburgCity_MapWarps, PetalburgCity_MapCoordEvents, PetalburgCity_MapBGEvents

