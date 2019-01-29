FallarborTown_House1_EventObjects:
	object_event 1, EVENT_OBJ_GFX_SCIENTIST_1, 0, 6, 4, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, FallarborTown_House1_EventScript_200F13, FLAG_HIDE_FALLARBOR_HOUSE_1_PROF_COZMO
	object_event 2, EVENT_OBJ_GFX_WOMAN_2, 0, 5, 6, 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT, 1, 0, 0, 0, FallarborTown_House1_EventScript_200FBC, 0

FallarborTown_House1_MapWarps:
	warp_def 3, 8, 0, 3, MAP_FALLARBOR_TOWN
	warp_def 4, 8, 0, 3, MAP_FALLARBOR_TOWN

FallarborTown_House1_MapEvents::
	map_events FallarborTown_House1_EventObjects, FallarborTown_House1_MapWarps, 0x0, 0x0

