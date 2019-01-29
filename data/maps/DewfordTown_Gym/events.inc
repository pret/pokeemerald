DewfordTown_Gym_EventObjects:
	object_event 1, EVENT_OBJ_GFX_BRAWLY, 0, 4, 3, 0, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, DewfordTown_Gym_EventScript_1FC7C2, 0
	object_event 2, EVENT_OBJ_GFX_BLACK_BELT, 0, 2, 18, 0, MOVEMENT_TYPE_FACE_UP, 0, 0, 1, 3, DewfordTown_Gym_EventScript_1FC8B7, 0
	object_event 3, EVENT_OBJ_GFX_GIRL_3, 0, 15, 3, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 1, 3, DewfordTown_Gym_EventScript_1FC8D9, 0
	object_event 4, EVENT_OBJ_GFX_GIRL_3, 0, 12, 25, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 1, 2, DewfordTown_Gym_EventScript_1FC8FB, 0
	object_event 5, EVENT_OBJ_GFX_MAN_2, 0, 5, 24, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, DewfordTown_Gym_EventScript_1FC983, 0
	object_event 6, EVENT_OBJ_GFX_BLACK_BELT, 0, 7, 8, 1, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 1, 3, DewfordTown_Gym_EventScript_1FC93F, 0
	object_event 7, EVENT_OBJ_GFX_GIRL_3, 0, 16, 9, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 1, 3, DewfordTown_Gym_EventScript_1FC961, 0
	object_event 8, EVENT_OBJ_GFX_SAILOR, 0, 14, 12, 1, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 1, 2, DewfordTown_Gym_EventScript_1FC91D, 0

DewfordTown_Gym_MapWarps:
	warp_def 5, 27, 0, 2, MAP_DEWFORD_TOWN
	warp_def 6, 27, 0, 2, MAP_DEWFORD_TOWN

DewfordTown_Gym_MapBGEvents:
	bg_event 4, 23, 3, BG_EVENT_PLAYER_FACING_NORTH, DewfordTown_Gym_EventScript_1FC9A2
	bg_event 7, 23, 3, BG_EVENT_PLAYER_FACING_NORTH, DewfordTown_Gym_EventScript_1FC9B2
	bg_event 4, 24, 0, BG_EVENT_PLAYER_FACING_NORTH, DewfordTown_Gym_EventScript_1FC9A2
	bg_event 7, 24, 0, BG_EVENT_PLAYER_FACING_NORTH, DewfordTown_Gym_EventScript_1FC9B2

DewfordTown_Gym_MapEvents::
	map_events DewfordTown_Gym_EventObjects, DewfordTown_Gym_MapWarps, 0x0, DewfordTown_Gym_MapBGEvents

