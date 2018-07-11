BattleFrontier_BattlePikeLobby_EventObjects: @ 853CBB0
	object_event 1, EVENT_OBJ_GFX_WOMAN_6, 0, 5, 5, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, BattleFrontier_BattlePikeLobby_EventScript_25B868, 0
	object_event 2, EVENT_OBJ_GFX_HIKER, 0, 10, 9, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, BattleFrontier_BattlePikeLobby_EventScript_25BAAB, 0
	object_event 3, EVENT_OBJ_GFX_LITTLE_GIRL_1, 0, 0, 5, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 0, 0, BattleFrontier_BattlePikeLobby_EventScript_25BAB4, 0
	object_event 4, EVENT_OBJ_GFX_BEAUTY, 0, 8, 9, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, BattleFrontier_BattlePikeLobby_EventScript_25BABD, 0

BattleFrontier_BattlePikeLobby_MapWarps: @ 853CC10
	warp_def 5, 12, 0, 0, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	warp_def 4, 12, 0, 0, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	warp_def 6, 12, 0, 0, MAP_BATTLE_FRONTIER_OUTSIDE_WEST

BattleFrontier_BattlePikeLobby_MapBGEvents: @ 853CC28
	bg_event 8, 3, 0, BG_EVENT_PLAYER_FACING_ANY, BattleFrontier_BattlePikeLobby_EventScript_25BA80
	bg_event 1, 3, 0, BG_EVENT_PLAYER_FACING_ANY, BattleFrontier_BattlePikeLobby_EventScript_25BAC6

BattleFrontier_BattlePikeLobby_MapEvents:: @ 853CC40
	map_events BattleFrontier_BattlePikeLobby_EventObjects, BattleFrontier_BattlePikeLobby_MapWarps, 0x0, BattleFrontier_BattlePikeLobby_MapBGEvents

