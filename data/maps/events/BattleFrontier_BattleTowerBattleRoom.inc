BattleFrontier_BattleTowerBattleRoom_MapObjects: @ 853B7D0
	object_event 1, MAP_OBJ_GFX_HIPSTER, 0, 0, 5, 1, 3, 8, 0, 0, 0, 0, 0x0, 888, 0, 0
	object_event 2, MAP_OBJ_GFX_TEALA, 0, 0, 1, 7, 3, 10, 0, 0, 0, 0, 0x0, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_TEALA, 0, 0, 4, 8, 3, 7, 0, 0, 0, 0, 0x0, 0, 0, 0

BattleFrontier_BattleTowerBattleRoom_MapWarps: @ 853B818
	warp_def 5, 8, 0, 2, BATTLE_FRONTIER_BATTLE_TOWER_LOBBY
	warp_def 6, 8, 0, 2, BATTLE_FRONTIER_BATTLE_TOWER_LOBBY

BattleFrontier_BattleTowerBattleRoom_MapEvents:: @ 853B828
	map_events BattleFrontier_BattleTowerBattleRoom_MapObjects, BattleFrontier_BattleTowerBattleRoom_MapWarps, 0x0, 0x0

