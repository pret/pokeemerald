FallarborTown_BattleTentLobby_MapObjects: @ 852E370
	object_event 1, MAP_OBJ_GFX_BLACK_BELT, 0, 0, 6, 5, 3, 8, 17, 0, 0, 0, FallarborTown_BattleTentLobby_EventScript_200001, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_HIKER, 0, 0, 1, 5, 3, 5, 17, 0, 0, 0, FallarborTown_BattleTentLobby_EventScript_20020D, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_LITTLE_BOY_2, 0, 0, 12, 6, 3, 3, 17, 0, 0, 0, FallarborTown_BattleTentLobby_EventScript_200216, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_LASS, 0, 0, 10, 9, 3, 8, 17, 0, 0, 0, FallarborTown_BattleTentLobby_EventScript_20021F, 0, 0, 0
	object_event 5, MAP_OBJ_GFX_SCOTT, 0, 0, 0, 7, 3, 10, 17, 0, 0, 0, FallarborTown_BattleTentLobby_EventScript_200228, 767, 0, 0

FallarborTown_BattleTentLobby_MapWarps: @ 852E3E8
	warp_def 6, 9, 0, 1, FALLARBOR_TOWN
	warp_def 7, 9, 0, 1, FALLARBOR_TOWN

FallarborTown_BattleTentLobby_MapBGEvents: @ 852E3F8
	bg_event 4, 5, 0, 0, 0, FallarborTown_BattleTentLobby_EventScript_20024F

FallarborTown_BattleTentLobby_MapEvents:: @ 852E404
	map_events FallarborTown_BattleTentLobby_MapObjects, FallarborTown_BattleTentLobby_MapWarps, 0x0, FallarborTown_BattleTentLobby_MapBGEvents

