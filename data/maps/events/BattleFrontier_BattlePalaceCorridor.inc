BattleFrontier_BattlePalaceCorridor_EventObjects: @ 853C420
	object_event 1, EVENT_OBJ_GFX_OLD_MAN_1, 0, 0, 8, 12, 3, 7, 17, 0, 0, 0, 0x0, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_AZURILL, 0, 0, 3, 5, 0, 2, 1, 0, 0, 0, 0x0, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_KIRLIA, 0, 0, 12, 6, 0, 14, 32, 0, 0, 0, 0x0, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_PIKACHU, 0, 0, 15, 5, 0, 1, 17, 0, 0, 0, 0x0, 0, 0, 0
	object_event 5, EVENT_OBJ_GFX_ZIGZAGOON_2, 0, 0, 4, 9, 0, 14, 32, 0, 0, 0, 0x0, 0, 0, 0
	object_event 6, EVENT_OBJ_GFX_AZUMARILL, 0, 0, 13, 9, 0, 1, 16, 0, 0, 0, 0x0, 0, 0, 0
	object_event 7, EVENT_OBJ_GFX_WINGULL, 0, 0, 3, 10, 0, 2, 33, 0, 0, 0, 0x0, 0, 0, 0

BattleFrontier_BattlePalaceCorridor_MapWarps: @ 853C4C8
	warp_def 8, 13, 3, 2, BATTLE_FRONTIER_BATTLE_PALACE_LOBBY
	warp_def 9, 13, 3, 2, BATTLE_FRONTIER_BATTLE_PALACE_LOBBY
	warp_def 6, 3, 3, 0, BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
	warp_def 10, 3, 3, 0, BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM

BattleFrontier_BattlePalaceCorridor_MapEvents:: @ 853C4E8
	map_events BattleFrontier_BattlePalaceCorridor_EventObjects, BattleFrontier_BattlePalaceCorridor_MapWarps, 0x0, 0x0

