BattleFrontier_BattleDomeLobby_EventObjects: @ 853C068
	object_event 1, EVENT_OBJ_GFX_TEALA, 0, 5, 10, 0, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, BattleFrontier_BattleDomeLobby_EventScript_249A35, 0
	object_event 2, EVENT_OBJ_GFX_MAN_4, 0, 1, 11, 0, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, BattleFrontier_BattleDomeLobby_EventScript_249E10, 0
	object_event 3, EVENT_OBJ_GFX_LASS, 0, 14, 14, 0, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, BattleFrontier_BattleDomeLobby_EventScript_249DFE, 0
	object_event 4, EVENT_OBJ_GFX_FAT_MAN, 0, 18, 14, 0, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, BattleFrontier_BattleDomeLobby_EventScript_249E07, 0
	object_event 5, EVENT_OBJ_GFX_MANIAC, 0, 8, 14, 0, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, BattleFrontier_BattleDomeLobby_EventScript_249DED, 0
	object_event 6, EVENT_OBJ_GFX_TEALA, 0, 17, 10, 0, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, BattleFrontier_BattleDomeLobby_EventScript_249A47, 0

BattleFrontier_BattleDomeLobby_MapWarps: @ 853C0F8
	warp_def 11, 16, 0, 1, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	warp_def 12, 16, 0, 1, MAP_BATTLE_FRONTIER_OUTSIDE_WEST

BattleFrontier_BattleDomeLobby_MapBGEvents: @ 853C108
	bg_event 4, 10, 0, BG_EVENT_PLAYER_FACING_ANY, BattleFrontier_BattleDomeLobby_EventScript_249D52
	bg_event 7, 10, 0, BG_EVENT_PLAYER_FACING_ANY, BattleFrontier_BattleDomeLobby_EventScript_249D84
	bg_event 18, 10, 0, BG_EVENT_PLAYER_FACING_ANY, BattleFrontier_BattleDomeLobby_EventScript_249D6B
	bg_event 15, 10, 0, BG_EVENT_PLAYER_FACING_ANY, BattleFrontier_BattleDomeLobby_EventScript_249E34

BattleFrontier_BattleDomeLobby_MapEvents:: @ 853C138
	map_events BattleFrontier_BattleDomeLobby_EventObjects, BattleFrontier_BattleDomeLobby_MapWarps, 0x0, BattleFrontier_BattleDomeLobby_MapBGEvents

