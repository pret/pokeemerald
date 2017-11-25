BattleFrontier_BattlePikeLobby_MapObjects: @ 853CBB0
	object_event 1, MAP_OBJ_GFX_WOMAN_6, 0, 0, 5, 5, 3, 8, 17, 0, 0, 0, BattleFrontier_BattlePikeLobby_EventScript_25B868, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_HIKER, 0, 0, 10, 9, 3, 7, 17, 0, 0, 0, BattleFrontier_BattlePikeLobby_EventScript_25BAAB, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_LITTLE_GIRL_1, 0, 0, 0, 5, 3, 9, 17, 0, 0, 0, BattleFrontier_BattlePikeLobby_EventScript_25BAB4, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_BEAUTY, 0, 0, 8, 9, 3, 2, 17, 0, 0, 0, BattleFrontier_BattlePikeLobby_EventScript_25BABD, 0, 0, 0

BattleFrontier_BattlePikeLobby_MapWarps: @ 853CC10
	warp_def 5, 12, 0, 0, BATTLE_FRONTIER_OUTSIDE_WEST
	warp_def 4, 12, 0, 0, BATTLE_FRONTIER_OUTSIDE_WEST
	warp_def 6, 12, 0, 0, BATTLE_FRONTIER_OUTSIDE_WEST

BattleFrontier_BattlePikeLobby_MapBGEvents: @ 853CC28
	bg_event 8, 3, 0, 0, 0, BattleFrontier_BattlePikeLobby_EventScript_25BA80
	bg_event 1, 3, 0, 0, 0, BattleFrontier_BattlePikeLobby_EventScript_25BAC6

BattleFrontier_BattlePikeLobby_MapEvents:: @ 853CC40
	map_events BattleFrontier_BattlePikeLobby_MapObjects, BattleFrontier_BattlePikeLobby_MapWarps, 0x0, BattleFrontier_BattlePikeLobby_MapBGEvents

