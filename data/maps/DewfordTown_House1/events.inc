DewfordTown_House1_EventObjects: @ 852D9C8
	object_event 1, EVENT_OBJ_GFX_WOMAN_3, 0, 6, 3, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, DewfordTown_House1_EventScript_1FC3D7, 0
	object_event 2, EVENT_OBJ_GFX_MAN_1, 0, 3, 3, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, DewfordTown_House1_EventScript_1FC3CE, 0
	object_event 3, EVENT_OBJ_GFX_ZIGZAGOON_2, 0, 4, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 3, 1, 0, 0, DewfordTown_House1_EventScript_1FC3E0, 0

DewfordTown_House1_MapWarps: @ 852DA10
	warp_def 3, 7, 0, 3, MAP_DEWFORD_TOWN
	warp_def 4, 7, 0, 3, MAP_DEWFORD_TOWN

DewfordTown_House1_MapEvents:: @ 852DA20
	map_events DewfordTown_House1_EventObjects, DewfordTown_House1_MapWarps, 0x0, 0x0

