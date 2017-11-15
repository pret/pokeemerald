BattleFrontier_Lounge3_MapObjects: @ 853D1B8
	object_event 1, MAP_OBJ_GFX_HIKER, 0, 0, 4, 6, 0, 7, 17, 0, 0, 0, BattleFrontier_Lounge3_EventScript_261D83, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_FAT_MAN, 0, 0, 4, 4, 0, 8, 17, 0, 0, 0, BattleFrontier_Lounge3_EventScript_261FE1, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_WOMAN_3, 0, 0, 3, 5, 0, 10, 17, 0, 0, 0, BattleFrontier_Lounge3_EventScript_261FC1, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_WOMAN_2, 0, 0, 5, 5, 0, 9, 17, 0, 0, 0, BattleFrontier_Lounge3_EventScript_261FD1, 0, 0, 0
	object_event 5, MAP_OBJ_GFX_MAN_4, 0, 0, 0, 6, 0, 2, 48, 0, 0, 0, BattleFrontier_Lounge3_EventScript_261FB8, 0, 0, 0

BattleFrontier_Lounge3_MapWarps: @ 853D230
	warp_def 4, 9, 0, 9, BATTLE_FRONTIER_OUTSIDE_EAST

BattleFrontier_Lounge3_MapEvents:: @ 853D238
	map_events BattleFrontier_Lounge3_MapObjects, BattleFrontier_Lounge3_MapWarps, 0x0, 0x0

