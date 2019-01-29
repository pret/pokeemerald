BattleFrontier_RankingHall_EventObjects:
	object_event 1, EVENT_OBJ_GFX_TEALA, 0, 24, 13, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, BattleFrontier_RankingHall_EventScript_25E52F, 0
	object_event 2, EVENT_OBJ_GFX_NINJA_BOY, 0, 4, 10, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, BattleFrontier_RankingHall_EventScript_25E54A, 0
	object_event 3, EVENT_OBJ_GFX_BOY_3, 0, 44, 11, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, BattleFrontier_RankingHall_EventScript_25E573, 0

BattleFrontier_RankingHall_MapWarps:
	warp_def 26, 14, 3, 4, MAP_BATTLE_FRONTIER_OUTSIDE_EAST
	warp_def 27, 14, 3, 4, MAP_BATTLE_FRONTIER_OUTSIDE_EAST

BattleFrontier_RankingHall_MapBGEvents:
	bg_event 26, 9, 0, BG_EVENT_PLAYER_FACING_NORTH, BattleFrontier_RankingHall_EventScript_25E4AA
	bg_event 23, 8, 0, BG_EVENT_PLAYER_FACING_NORTH, BattleFrontier_RankingHall_EventScript_25E4B6
	bg_event 26, 5, 0, BG_EVENT_PLAYER_FACING_NORTH, BattleFrontier_RankingHall_EventScript_25E4C2
	bg_event 29, 8, 0, BG_EVENT_PLAYER_FACING_NORTH, BattleFrontier_RankingHall_EventScript_25E4CE
	bg_event 42, 9, 0, BG_EVENT_PLAYER_FACING_NORTH, BattleFrontier_RankingHall_EventScript_25E4DA
	bg_event 46, 9, 0, BG_EVENT_PLAYER_FACING_NORTH, BattleFrontier_RankingHall_EventScript_25E4E6
	bg_event 10, 9, 0, BG_EVENT_PLAYER_FACING_NORTH, BattleFrontier_RankingHall_EventScript_25E4F2
	bg_event 8, 7, 0, BG_EVENT_PLAYER_FACING_NORTH, BattleFrontier_RankingHall_EventScript_25E4FE
	bg_event 6, 9, 0, BG_EVENT_PLAYER_FACING_NORTH, BattleFrontier_RankingHall_EventScript_25E50A
	bg_event 44, 7, 0, BG_EVENT_PLAYER_FACING_NORTH, BattleFrontier_RankingHall_EventScript_25E516
	bg_event 16, 8, 0, BG_EVENT_PLAYER_FACING_ANY, BattleFrontier_RankingHall_EventScript_25E538
	bg_event 36, 8, 0, BG_EVENT_PLAYER_FACING_ANY, BattleFrontier_RankingHall_EventScript_25E541

BattleFrontier_RankingHall_MapEvents::
	map_events BattleFrontier_RankingHall_EventObjects, BattleFrontier_RankingHall_MapWarps, 0x0, BattleFrontier_RankingHall_MapBGEvents

