BattleFrontier_BattleFactoryLobby_EventObjects: @ 853C9D8
	object_event 1, EVENT_OBJ_GFX_SCIENTIST_1, 0, 4, 7, 0, 8, 17, 0, 0, BattleFrontier_BattleFactoryLobby_EventScript_2585CB, 0
	object_event 2, EVENT_OBJ_GFX_WOMAN_1, 0, 3, 11, 0, 2, 17, 0, 0, BattleFrontier_BattleFactoryLobby_EventScript_258813, 0
	object_event 3, EVENT_OBJ_GFX_CAMPER, 0, 14, 11, 0, 8, 0, 0, 0, BattleFrontier_BattleFactoryLobby_EventScript_25881C, 0
	object_event 4, EVENT_OBJ_GFX_PICNICKER, 0, 13, 11, 0, 10, 17, 0, 0, BattleFrontier_BattleFactoryLobby_EventScript_258825, 0
	object_event 5, EVENT_OBJ_GFX_FAT_MAN, 0, 6, 10, 0, 1, 17, 0, 0, BattleFrontier_BattleFactoryLobby_EventScript_258830, 0
	object_event 6, EVENT_OBJ_GFX_SCIENTIST_1, 0, 14, 7, 0, 8, 17, 0, 0, BattleFrontier_BattleFactoryLobby_EventScript_2585DD, 0

BattleFrontier_BattleFactoryLobby_MapWarps: @ 853CA68
	warp_def 9, 11, 0, 2, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	warp_def 10, 11, 0, 2, MAP_BATTLE_FRONTIER_OUTSIDE_WEST

BattleFrontier_BattleFactoryLobby_MapBGEvents: @ 853CA78
	bg_event 2, 7, 0, 1, 0, BattleFrontier_BattleFactoryLobby_EventScript_2587E1
	bg_event 11, 7, 0, 1, 0, BattleFrontier_BattleFactoryLobby_EventScript_2587FA
	bg_event 9, 4, 0, 0, 0, BattleFrontier_BattleFactoryLobby_EventScript_258839

BattleFrontier_BattleFactoryLobby_MapEvents:: @ 853CA9C
	map_events BattleFrontier_BattleFactoryLobby_EventObjects, BattleFrontier_BattleFactoryLobby_MapWarps, 0x0, BattleFrontier_BattleFactoryLobby_MapBGEvents

