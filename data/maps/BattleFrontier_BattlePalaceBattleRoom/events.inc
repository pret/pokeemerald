BattleFrontier_BattlePalaceBattleRoom_EventObjects: @ 853C4FC
	object_event 1, EVENT_OBJ_GFX_TRADER, 0, 1, 9, 3, 7, 1, 1, 0, 0, 0x0, 0
	object_event 2, EVENT_OBJ_GFX_HIPSTER, 0, 13, 1, 3, 8, 1, 1, 0, 0, 0x0, 0
	object_event 3, EVENT_OBJ_GFX_OLD_MAN_1, 0, 1, 4, 3, 10, 1, 1, 0, 0, 0x0, 0
	object_event 4, EVENT_OBJ_GFX_DUSCLOPS, 0, 13, 1, 3, 8, 1, 1, 0, 0, 0x0, 0
	object_event 5, EVENT_OBJ_GFX_AZURILL, 0, 13, 1, 3, 8, 1, 1, 0, 0, 0x0, 0

BattleFrontier_BattlePalaceBattleRoom_MapWarps: @ 853C574
	warp_def 0, 9, 3, 2, MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR
	warp_def 1, 9, 3, 2, MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR

BattleFrontier_BattlePalaceBattleRoom_MapEvents:: @ 853C584
	map_events BattleFrontier_BattlePalaceBattleRoom_EventObjects, BattleFrontier_BattlePalaceBattleRoom_MapWarps, 0x0, 0x0

