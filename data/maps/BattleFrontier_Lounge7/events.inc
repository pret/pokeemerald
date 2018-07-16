BattleFrontier_Lounge7_EventObjects: @ 853D3A4
	object_event 1, EVENT_OBJ_GFX_SAILOR, 0, 0, 7, 0, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, BattleFrontier_Lounge7_EventScript_2656DB, 0
	object_event 2, EVENT_OBJ_GFX_OLD_WOMAN_1, 0, 2, 5, 0, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 0, 0, BattleFrontier_Lounge7_EventScript_265255, 0
	object_event 3, EVENT_OBJ_GFX_OLD_WOMAN_1, 0, 6, 5, 0, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 0, 0, BattleFrontier_Lounge7_EventScript_265445, 0
	object_event 4, EVENT_OBJ_GFX_GENTLEMAN, 0, 8, 3, 0, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 0, 0, BattleFrontier_Lounge7_EventScript_2656E4, 0

BattleFrontier_Lounge7_MapWarps: @ 853D404
	warp_def 4, 9, 0, 7, MAP_BATTLE_FRONTIER_OUTSIDE_WEST

BattleFrontier_Lounge7_MapEvents:: @ 853D40C
	map_events BattleFrontier_Lounge7_EventObjects, BattleFrontier_Lounge7_MapWarps, 0x0, 0x0

