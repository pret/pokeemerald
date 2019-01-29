FortreeCity_House3_EventObjects:
	object_event 1, EVENT_OBJ_GFX_MANIAC, 0, 0, 3, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, FortreeCity_House3_EventScript_217AE8, 0
	object_event 2, EVENT_OBJ_GFX_SCHOOL_KID_M, 0, 5, 4, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, FortreeCity_House3_EventScript_217AF1, 0

FortreeCity_House3_MapWarps:
	warp_def 3, 5, 0, 5, MAP_FORTREE_CITY
	warp_def 4, 5, 0, 5, MAP_FORTREE_CITY

FortreeCity_House3_MapEvents::
	map_events FortreeCity_House3_EventObjects, FortreeCity_House3_MapWarps, 0x0, 0x0

