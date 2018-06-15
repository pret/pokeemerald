VerdanturfTown_BattleTentLobby_EventObjects: @ 852E648
	object_event 1, EVENT_OBJ_GFX_OLD_MAN_1, 0, 6, 5, 3, 8, 17, 0, 0, VerdanturfTown_BattleTentLobby_EventScript_201873, 0
	object_event 2, EVENT_OBJ_GFX_GIRL_1, 0, 0, 5, 3, 2, 17, 0, 0, VerdanturfTown_BattleTentLobby_EventScript_201A7B, 0
	object_event 3, EVENT_OBJ_GFX_BOY_3, 0, 9, 7, 3, 2, 17, 0, 0, VerdanturfTown_BattleTentLobby_EventScript_201ABC, 0
	object_event 4, EVENT_OBJ_GFX_BOY_2, 0, 1, 8, 3, 10, 17, 0, 0, VerdanturfTown_BattleTentLobby_EventScript_201AC5, 0
	object_event 5, EVENT_OBJ_GFX_SCOTT, 0, 12, 6, 3, 9, 17, 0, 0, VerdanturfTown_BattleTentLobby_EventScript_201AD0, 766
	object_event 6, EVENT_OBJ_GFX_LITTLE_BOY_2, 0, 2, 8, 3, 9, 17, 0, 0, VerdanturfTown_BattleTentLobby_EventScript_201AF7, 0

VerdanturfTown_BattleTentLobby_MapWarps: @ 852E6D8
	warp_def 6, 9, 0, 0, MAP_VERDANTURF_TOWN
	warp_def 7, 9, 0, 0, MAP_VERDANTURF_TOWN

VerdanturfTown_BattleTentLobby_MapBGEvents: @ 852E6E8
	bg_event 4, 5, 0, 0, 0, VerdanturfTown_BattleTentLobby_EventScript_201B02

VerdanturfTown_BattleTentLobby_MapEvents:: @ 852E6F4
	map_events VerdanturfTown_BattleTentLobby_EventObjects, VerdanturfTown_BattleTentLobby_MapWarps, 0x0, VerdanturfTown_BattleTentLobby_MapBGEvents

