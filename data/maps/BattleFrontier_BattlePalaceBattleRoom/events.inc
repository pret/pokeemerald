BattleFrontier_BattlePalaceBattleRoom_EventObjects: @ 853C4FC
	object_event 1, EVENT_OBJ_GFX_VAR_1, 0, 1, 9, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, 0x0, 0
	object_event 2, EVENT_OBJ_GFX_VAR_0, 0, 13, 1, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, 0x0, 0
	object_event 3, EVENT_OBJ_GFX_EXPERT_M, 0, 1, 4, 3, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 0, 0, 0x0, 0
	object_event 4, EVENT_OBJ_GFX_DUSCLOPS, 0, 13, 1, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, 0x0, 0
	object_event 5, EVENT_OBJ_GFX_AZURILL, 0, 13, 1, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, 0x0, 0

BattleFrontier_BattlePalaceBattleRoom_MapWarps: @ 853C574
	warp_def 0, 9, 3, 2, MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR
	warp_def 1, 9, 3, 2, MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR

BattleFrontier_BattlePalaceBattleRoom_MapEvents:: @ 853C584
	map_events BattleFrontier_BattlePalaceBattleRoom_EventObjects, BattleFrontier_BattlePalaceBattleRoom_MapWarps, 0x0, 0x0

