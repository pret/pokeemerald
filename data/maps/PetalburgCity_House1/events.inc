PetalburgCity_House1_EventObjects: @ 852F0BC
	object_event 1, EVENT_OBJ_GFX_GIRL_1, 0, 7, 4, 3, MOVEMENT_TYPE_WANDER_AROUND, 2, 2, 0, 0, PetalburgCity_House1_EventScript_2077A3, 0
	object_event 2, EVENT_OBJ_GFX_EXPERT_M, 0, 4, 4, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, PetalburgCity_House1_EventScript_20779A, 0

PetalburgCity_House1_MapWarps: @ 852F0EC
	warp_def 3, 8, 0, 0, MAP_PETALBURG_CITY
	warp_def 4, 8, 0, 0, MAP_PETALBURG_CITY

PetalburgCity_House1_MapEvents:: @ 852F0FC
	map_events PetalburgCity_House1_EventObjects, PetalburgCity_House1_MapWarps, 0x0, 0x0

