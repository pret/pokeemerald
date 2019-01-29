FortreeCity_House2_EventObjects:
	object_event 1, EVENT_OBJ_GFX_EXPERT_F, 0, 2, 3, 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT, 1, 0, 0, 0, FortreeCity_House2_EventScript_2177CB, 0
	object_event 2, EVENT_OBJ_GFX_EXPERT_M, 0, 6, 3, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 0, 0, 0, FortreeCity_House2_EventScript_2C811E, 0

FortreeCity_House2_MapWarps:
	warp_def 3, 5, 0, 4, MAP_FORTREE_CITY
	warp_def 4, 5, 0, 4, MAP_FORTREE_CITY

FortreeCity_House2_MapEvents::
	map_events FortreeCity_House2_EventObjects, FortreeCity_House2_MapWarps, 0x0, 0x0

