LavaridgeTown_Mart_EventObjects:
	object_event 1, EVENT_OBJ_GFX_MART_EMPLOYEE, 0, 1, 3, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, LavaridgeTown_Mart_EventScript_1FF9CE, 0
	object_event 2, EVENT_OBJ_GFX_EXPERT_M, 0, 4, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, LavaridgeTown_Mart_EventScript_1FF9FE, 0
	object_event 3, EVENT_OBJ_GFX_OLD_WOMAN, 0, 9, 5, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, LavaridgeTown_Mart_EventScript_1FFA07, 0

LavaridgeTown_Mart_MapWarps:
	warp_def 3, 7, 0, 2, MAP_LAVARIDGE_TOWN
	warp_def 4, 7, 0, 2, MAP_LAVARIDGE_TOWN

LavaridgeTown_Mart_MapEvents::
	map_events LavaridgeTown_Mart_EventObjects, LavaridgeTown_Mart_MapWarps, 0x0, 0x0

