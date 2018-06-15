BattleFrontier_Lounge3_EventObjects: @ 853D1B8
	object_event 1, EVENT_OBJ_GFX_HIKER, 0, 4, 6, 0, 7, 1, 1, 0, 0, BattleFrontier_Lounge3_EventScript_261D83, 0
	object_event 2, EVENT_OBJ_GFX_FAT_MAN, 0, 4, 4, 0, 8, 1, 1, 0, 0, BattleFrontier_Lounge3_EventScript_261FE1, 0
	object_event 3, EVENT_OBJ_GFX_WOMAN_3, 0, 3, 5, 0, 10, 1, 1, 0, 0, BattleFrontier_Lounge3_EventScript_261FC1, 0
	object_event 4, EVENT_OBJ_GFX_WOMAN_2, 0, 5, 5, 0, 9, 1, 1, 0, 0, BattleFrontier_Lounge3_EventScript_261FD1, 0
	object_event 5, EVENT_OBJ_GFX_MAN_4, 0, 0, 6, 0, 2, 0, 3, 0, 0, BattleFrontier_Lounge3_EventScript_261FB8, 0

BattleFrontier_Lounge3_MapWarps: @ 853D230
	warp_def 4, 9, 0, 9, MAP_BATTLE_FRONTIER_OUTSIDE_EAST

BattleFrontier_Lounge3_MapEvents:: @ 853D238
	map_events BattleFrontier_Lounge3_EventObjects, BattleFrontier_Lounge3_MapWarps, 0x0, 0x0

