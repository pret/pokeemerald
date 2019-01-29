DewfordTown_House2_EventObjects:
	object_event 1, EVENT_OBJ_GFX_MAN_3, 0, 6, 5, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, DewfordTown_House2_EventScript_1FE22E, 0
	object_event 2, EVENT_OBJ_GFX_BOY_2, 0, 2, 3, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, DewfordTown_House2_EventScript_1FE271, 0

DewfordTown_House2_MapWarps:
	warp_def 3, 8, 0, 4, MAP_DEWFORD_TOWN
	warp_def 4, 8, 0, 4, MAP_DEWFORD_TOWN

DewfordTown_House2_MapEvents::
	map_events DewfordTown_House2_EventObjects, DewfordTown_House2_MapWarps, 0x0, 0x0

