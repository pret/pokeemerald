FortreeCity_House4_EventObjects: @ 8530FD8
	object_event 1, EVENT_OBJ_GFX_WOMAN_4, 0, 6, 4, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, FortreeCity_House4_EventScript_217C81, 0
	object_event 2, EVENT_OBJ_GFX_BOY_3, 0, 1, 3, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, FortreeCity_House4_EventScript_217C8A, 0
	object_event 3, EVENT_OBJ_GFX_WINGULL, 0, 2, 3, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, FortreeCity_House4_EventScript_217D20, FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL

FortreeCity_House4_MapWarps: @ 8531020
	warp_def 3, 5, 0, 6, MAP_FORTREE_CITY
	warp_def 4, 5, 0, 6, MAP_FORTREE_CITY

FortreeCity_House4_MapEvents:: @ 8531030
	map_events FortreeCity_House4_EventObjects, FortreeCity_House4_MapWarps, 0x0, 0x0

