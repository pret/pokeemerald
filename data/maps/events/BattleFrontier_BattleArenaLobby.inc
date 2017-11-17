BattleFrontier_BattleArenaLobby_MapObjects: @ 853C814
	object_event 1, MAP_OBJ_GFX_BLACK_BELT, 0, 0, 7, 7, 0, 8, 17, 0, 0, 0, BattleFrontier_BattleArenaLobby_EventScript_255DF4, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_WOMAN_7, 0, 0, 2, 10, 3, 2, 17, 0, 0, 0, BattleFrontier_BattleArenaLobby_EventScript_2560C1, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_MAN_6, 0, 0, 14, 11, 3, 9, 17, 0, 0, 0, BattleFrontier_BattleArenaLobby_EventScript_2560AF, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_CAMPER, 0, 0, 14, 12, 3, 9, 17, 0, 0, 0, BattleFrontier_BattleArenaLobby_EventScript_2560B8, 0, 0, 0
	object_event 5, MAP_OBJ_GFX_YOUNGSTER, 0, 0, 14, 10, 3, 9, 17, 0, 0, 0, BattleFrontier_BattleArenaLobby_EventScript_2560A6, 0, 0, 0

BattleFrontier_BattleArenaLobby_MapWarps: @ 853C88C
	warp_def 7, 12, 3, 1, BATTLE_FRONTIER_OUTSIDE_EAST

BattleFrontier_BattleArenaLobby_MapBGEvents: @ 853C894
	bg_event 5, 9, 3, 1, 0, BattleFrontier_BattleArenaLobby_EventScript_256092
	bg_event 1, 7, 0, 0, 0, BattleFrontier_BattleArenaLobby_EventScript_2560CA

BattleFrontier_BattleArenaLobby_MapEvents:: @ 853C8AC
	map_events BattleFrontier_BattleArenaLobby_MapObjects, BattleFrontier_BattleArenaLobby_MapWarps, 0x0, BattleFrontier_BattleArenaLobby_MapBGEvents

