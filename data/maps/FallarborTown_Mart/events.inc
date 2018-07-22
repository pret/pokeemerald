FallarborTown_Mart_EventObjects: @ 852E2D4
	object_event 1, EVENT_OBJ_GFX_MART_EMPLOYEE, 0, 1, 3, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, FallarborTown_Mart_EventScript_1FFCBF, 0
	object_event 2, EVENT_OBJ_GFX_WOMAN_3, 0, 5, 3, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, FallarborTown_Mart_EventScript_1FFCF4, 0
	object_event 3, EVENT_OBJ_GFX_MAN_3, 0, 9, 6, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, FallarborTown_Mart_EventScript_1FFCFD, 0
	object_event 4, EVENT_OBJ_GFX_SKITTY, 0, 2, 5, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, FallarborTown_Mart_EventScript_1FFD06, 0
	object_event 5, EVENT_OBJ_GFX_GIRL_2, 0, 7, 2, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, FallarborTown_Mart_EventScript_2C80B6, 0

FallarborTown_Mart_MapWarps: @ 852E34C
	warp_def 3, 7, 0, 0, MAP_FALLARBOR_TOWN
	warp_def 4, 7, 0, 0, MAP_FALLARBOR_TOWN

FallarborTown_Mart_MapEvents:: @ 852E35C
	map_events FallarborTown_Mart_EventObjects, FallarborTown_Mart_MapWarps, 0x0, 0x0

