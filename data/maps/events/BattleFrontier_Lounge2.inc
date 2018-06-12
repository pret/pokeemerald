BattleFrontier_Lounge2_EventObjects: @ 853D11C
	object_event 1, EVENT_OBJ_GFX_MANIAC, 0, 0, 8, 4, 0, 10, 17, 0, 0, 0, BattleFrontier_Lounge2_EventScript_260643, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_MANIAC, 0, 0, 10, 4, 0, 9, 17, 0, 0, 0, BattleFrontier_Lounge2_EventScript_26073C, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_MANIAC, 0, 0, 10, 3, 0, 9, 17, 0, 0, 0, BattleFrontier_Lounge2_EventScript_260747, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_RUNNING_TRIATHLETE_F, 0, 0, 4, 6, 0, 2, 33, 0, 0, 0, BattleFrontier_Lounge2_EventScript_26075D, 0, 0, 0
	object_event 5, EVENT_OBJ_GFX_MANIAC, 0, 0, 10, 5, 0, 9, 17, 0, 0, 0, BattleFrontier_Lounge2_EventScript_260752, 0, 0, 0

BattleFrontier_Lounge2_MapWarps: @ 853D194
	warp_def 1, 7, 0, 3, BATTLE_FRONTIER_OUTSIDE_WEST
	warp_def 2, 7, 0, 3, BATTLE_FRONTIER_OUTSIDE_WEST

BattleFrontier_Lounge2_MapEvents:: @ 853D1A4
	map_events BattleFrontier_Lounge2_EventObjects, BattleFrontier_Lounge2_MapWarps, 0x0, 0x0

