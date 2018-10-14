BattleFrontier_Mart_EventObjects: @ 853D68C
	object_event 1, EVENT_OBJ_GFX_MART_EMPLOYEE, 0, 1, 3, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, BattleFrontier_Mart_EventScript_267ACC, 0
	object_event 2, EVENT_OBJ_GFX_OLD_WOMAN, 0, 5, 4, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, BattleFrontier_Mart_EventScript_267B0B, 0
	object_event 3, EVENT_OBJ_GFX_OLD_MAN, 0, 5, 5, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, BattleFrontier_Mart_EventScript_267B02, 0
	object_event 4, EVENT_OBJ_GFX_BOY_2, 0, 8, 4, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, BattleFrontier_Mart_EventScript_267B20, 0

BattleFrontier_Mart_MapWarps: @ 853D6EC
	warp_def 3, 7, 0, 4, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	warp_def 4, 7, 0, 4, MAP_BATTLE_FRONTIER_OUTSIDE_WEST

BattleFrontier_Mart_MapEvents:: @ 853D6FC
	map_events BattleFrontier_Mart_EventObjects, BattleFrontier_Mart_MapWarps, 0x0, 0x0

