BattleFrontier_Lounge1_EventObjects:
	object_event 1, EVENT_OBJ_GFX_OLD_MAN, 0, 0, 6, 0, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 0, 0, BattleFrontier_Lounge1_EventScript_25E775, 0
	object_event 2, EVENT_OBJ_GFX_BOY_3, 0, 7, 6, 0, MOVEMENT_TYPE_WANDER_AROUND, 1, 2, 0, 0, BattleFrontier_Lounge1_EventScript_25E94D, 0
	object_event 3, EVENT_OBJ_GFX_BOY_2, 0, 5, 4, 0, MOVEMENT_TYPE_WANDER_AROUND, 2, 1, 0, 0, BattleFrontier_Lounge1_EventScript_25E956, 0

BattleFrontier_Lounge1_MapWarps:
	warp_def 4, 9, 0, 5, MAP_BATTLE_FRONTIER_OUTSIDE_EAST

BattleFrontier_Lounge1_MapEvents::
	map_events BattleFrontier_Lounge1_EventObjects, BattleFrontier_Lounge1_MapWarps, 0x0, 0x0

