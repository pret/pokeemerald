PetalburgCity_House2_EventObjects: @ 852F110
	object_event 1, EVENT_OBJ_GFX_WOMAN_2, 0, 0, 2, 5, 3, 2, 17, 0, 0, 0, PetalburgCity_House2_EventScript_2078F3, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_SCHOOL_KID_M, 0, 0, 7, 5, 3, 8, 0, 0, 0, 0, PetalburgCity_House2_EventScript_2078FC, 0, 0, 0

PetalburgCity_House2_MapWarps: @ 852F140
	warp_def 3, 7, 0, 4, MAP_PETALBURG_CITY
	warp_def 4, 7, 0, 4, MAP_PETALBURG_CITY

PetalburgCity_House2_MapEvents:: @ 852F150
	map_events PetalburgCity_House2_EventObjects, PetalburgCity_House2_MapWarps, 0x0, 0x0

