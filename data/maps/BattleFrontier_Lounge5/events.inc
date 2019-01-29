BattleFrontier_Lounge5_EventObjects:
	object_event 1, EVENT_OBJ_GFX_LITTLE_GIRL, 0, 12, 4, 4, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 0, 0, BattleFrontier_Lounge5_EventScript_2645C6, 0
	object_event 2, EVENT_OBJ_GFX_GENTLEMAN, 0, 0, 4, 3, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 0, 0, BattleFrontier_Lounge5_EventScript_264617, 0
	object_event 3, EVENT_OBJ_GFX_BLACK_BELT, 0, 6, 5, 0, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, BattleFrontier_Lounge5_EventScript_264620, 0
	object_event 4, EVENT_OBJ_GFX_LITTLE_BOY, 0, 11, 7, 0, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, BattleFrontier_Lounge5_EventScript_264629, 0

BattleFrontier_Lounge5_MapWarps:
	warp_def 1, 7, 0, 7, MAP_BATTLE_FRONTIER_OUTSIDE_EAST
	warp_def 2, 7, 0, 7, MAP_BATTLE_FRONTIER_OUTSIDE_EAST

BattleFrontier_Lounge5_MapEvents::
	map_events BattleFrontier_Lounge5_EventObjects, BattleFrontier_Lounge5_MapWarps, 0x0, 0x0

