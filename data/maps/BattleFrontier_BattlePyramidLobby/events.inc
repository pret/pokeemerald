BattleFrontier_BattlePyramidLobby_EventObjects: @ 853C598
	object_event 1, EVENT_OBJ_GFX_HIKER, 0, 7, 12, 4, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, BattleFrontier_BattlePyramidLobby_EventScript_2508B1, 0
	object_event 2, EVENT_OBJ_GFX_HEX_MANIAC, 0, 14, 13, 4, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 0, 0, BattleFrontier_BattlePyramidLobby_EventScript_250ACE, 0
	object_event 3, EVENT_OBJ_GFX_WOMAN_4, 0, 2, 15, 4, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, BattleFrontier_BattlePyramidLobby_EventScript_250E83, 0
	object_event 4, EVENT_OBJ_GFX_FAT_MAN, 0, 12, 16, 4, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, BattleFrontier_BattlePyramidLobby_EventScript_250E8C, 0

BattleFrontier_BattlePyramidLobby_MapWarps: @ 853C5F8
	warp_def 7, 17, 4, 3, MAP_BATTLE_FRONTIER_OUTSIDE_EAST

BattleFrontier_BattlePyramidLobby_MapBGEvents: @ 853C600
	bg_event 5, 12, 0, BG_EVENT_PLAYER_FACING_NORTH, BattleFrontier_BattlePyramidLobby_EventScript_250D42
	bg_event 1, 12, 0, BG_EVENT_PLAYER_FACING_ANY, BattleFrontier_BattlePyramidLobby_EventScript_250E95

BattleFrontier_BattlePyramidLobby_MapEvents:: @ 853C618
	map_events BattleFrontier_BattlePyramidLobby_EventObjects, BattleFrontier_BattlePyramidLobby_MapWarps, 0x0, BattleFrontier_BattlePyramidLobby_MapBGEvents

