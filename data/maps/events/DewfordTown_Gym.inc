DewfordTown_Gym_MapObjects: @ 852DB34
	object_event 1, MAP_OBJ_GFX_BRAWLY, 0, 0, 4, 3, 0, 8, 0, 0, 0, 0, DewfordTown_Gym_EventScript_1FC7C2, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_BLACK_BELT, 0, 0, 2, 18, 0, 7, 0, 0, 1, 3, DewfordTown_Gym_EventScript_1FC8B7, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_GIRL_3, 0, 0, 15, 3, 3, 8, 0, 0, 1, 3, DewfordTown_Gym_EventScript_1FC8D9, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_GIRL_3, 0, 0, 12, 25, 3, 7, 0, 0, 1, 2, DewfordTown_Gym_EventScript_1FC8FB, 0, 0, 0
	object_event 5, MAP_OBJ_GFX_MAN_2, 0, 0, 5, 24, 3, 8, 0, 0, 0, 0, DewfordTown_Gym_EventScript_1FC983, 0, 0, 0
	object_event 6, MAP_OBJ_GFX_BLACK_BELT, 0, 0, 7, 8, 1, 10, 17, 0, 1, 3, DewfordTown_Gym_EventScript_1FC93F, 0, 0, 0
	object_event 7, MAP_OBJ_GFX_GIRL_3, 0, 0, 16, 9, 3, 8, 17, 0, 1, 3, DewfordTown_Gym_EventScript_1FC961, 0, 0, 0
	object_event 8, MAP_OBJ_GFX_SAILOR, 0, 0, 14, 12, 1, 10, 17, 0, 1, 2, DewfordTown_Gym_EventScript_1FC91D, 0, 0, 0

DewfordTown_Gym_MapWarps: @ 852DBF4
	warp_def 5, 27, 0, 2, DEWFORD_TOWN
	warp_def 6, 27, 0, 2, DEWFORD_TOWN

DewfordTown_Gym_MapBGEvents: @ 852DC04
	bg_event 4, 23, 3, 1, 0, DewfordTown_Gym_EventScript_1FC9A2
	bg_event 7, 23, 3, 1, 0, DewfordTown_Gym_EventScript_1FC9B2
	bg_event 4, 24, 0, 1, 0, DewfordTown_Gym_EventScript_1FC9A2
	bg_event 7, 24, 0, 1, 0, DewfordTown_Gym_EventScript_1FC9B2

DewfordTown_Gym_MapEvents:: @ 852DC34
	map_events DewfordTown_Gym_MapObjects, DewfordTown_Gym_MapWarps, 0x0, DewfordTown_Gym_MapBGEvents

