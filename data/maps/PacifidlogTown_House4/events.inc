PacifidlogTown_House4_EventObjects:
	object_event 1, EVENT_OBJ_GFX_WOMAN_2, 0, 3, 4, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, PacifidlogTown_House4_EventScript_203F55, 0
	object_event 2, EVENT_OBJ_GFX_LITTLE_GIRL, 0, 7, 5, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, PacifidlogTown_House4_EventScript_203F4C, 0
	object_event 3, EVENT_OBJ_GFX_BOY_1, 0, 7, 4, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, PacifidlogTown_House4_EventScript_203F5E, 0

PacifidlogTown_House4_MapWarps:
	warp_def 4, 8, 0, 4, MAP_PACIFIDLOG_TOWN
	warp_def 5, 8, 0, 4, MAP_PACIFIDLOG_TOWN

PacifidlogTown_House4_MapEvents::
	map_events PacifidlogTown_House4_EventObjects, PacifidlogTown_House4_MapWarps, 0x0, 0x0

