BattleFrontier_Lounge2_EventObjects:
	object_event 1, EVENT_OBJ_GFX_MANIAC, 0, 8, 4, 0, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 0, 0, BattleFrontier_Lounge2_EventScript_260643, 0
	object_event 2, EVENT_OBJ_GFX_MANIAC, 0, 10, 4, 0, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 0, 0, BattleFrontier_Lounge2_EventScript_26073C, 0
	object_event 3, EVENT_OBJ_GFX_MANIAC, 0, 10, 3, 0, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 0, 0, BattleFrontier_Lounge2_EventScript_260747, 0
	object_event 4, EVENT_OBJ_GFX_RUNNING_TRIATHLETE_F, 0, 4, 6, 0, MOVEMENT_TYPE_WANDER_AROUND, 1, 2, 0, 0, BattleFrontier_Lounge2_EventScript_26075D, 0
	object_event 5, EVENT_OBJ_GFX_MANIAC, 0, 10, 5, 0, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 0, 0, BattleFrontier_Lounge2_EventScript_260752, 0

BattleFrontier_Lounge2_MapWarps:
	warp_def 1, 7, 0, 3, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	warp_def 2, 7, 0, 3, MAP_BATTLE_FRONTIER_OUTSIDE_WEST

BattleFrontier_Lounge2_MapEvents::
	map_events BattleFrontier_Lounge2_EventObjects, BattleFrontier_Lounge2_MapWarps, 0x0, 0x0

