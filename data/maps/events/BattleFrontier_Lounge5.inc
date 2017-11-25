BattleFrontier_Lounge5_MapObjects: @ 853D2EC
	object_event 1, MAP_OBJ_GFX_LITTLE_GIRL_2, 0, 0, 12, 4, 4, 9, 17, 0, 0, 0, BattleFrontier_Lounge5_EventScript_2645C6, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_GENTLEMAN, 0, 0, 0, 4, 3, 10, 17, 0, 0, 0, BattleFrontier_Lounge5_EventScript_264617, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_BLACK_BELT, 0, 0, 6, 5, 0, 2, 17, 0, 0, 0, BattleFrontier_Lounge5_EventScript_264620, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_LITTLE_BOY_2, 0, 0, 11, 7, 0, 1, 17, 0, 0, 0, BattleFrontier_Lounge5_EventScript_264629, 0, 0, 0

BattleFrontier_Lounge5_MapWarps: @ 853D34C
	warp_def 1, 7, 0, 7, BATTLE_FRONTIER_OUTSIDE_EAST
	warp_def 2, 7, 0, 7, BATTLE_FRONTIER_OUTSIDE_EAST

BattleFrontier_Lounge5_MapEvents:: @ 853D35C
	map_events BattleFrontier_Lounge5_MapObjects, BattleFrontier_Lounge5_MapWarps, 0x0, 0x0

