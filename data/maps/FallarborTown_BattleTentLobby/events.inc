FallarborTown_BattleTentLobby_EventObjects:
	object_event 1, EVENT_OBJ_GFX_BLACK_BELT, 0, 6, 5, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, FallarborTown_BattleTentLobby_EventScript_200001, 0
	object_event 2, EVENT_OBJ_GFX_HIKER, 0, 1, 5, 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT, 1, 1, 0, 0, FallarborTown_BattleTentLobby_EventScript_20020D, 0
	object_event 3, EVENT_OBJ_GFX_LITTLE_BOY, 0, 12, 6, 3, MOVEMENT_TYPE_WANDER_UP_AND_DOWN, 1, 1, 0, 0, FallarborTown_BattleTentLobby_EventScript_200216, 0
	object_event 4, EVENT_OBJ_GFX_LASS, 0, 10, 9, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, FallarborTown_BattleTentLobby_EventScript_20021F, 0
	object_event 5, EVENT_OBJ_GFX_SCOTT, 0, 0, 7, 3, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 0, 0, FallarborTown_BattleTentLobby_EventScript_200228, FLAG_HIDE_FALLORBOR_TOWN_BATTLE_TENT_SCOTT

FallarborTown_BattleTentLobby_MapWarps:
	warp_def 6, 9, 0, 1, MAP_FALLARBOR_TOWN
	warp_def 7, 9, 0, 1, MAP_FALLARBOR_TOWN

FallarborTown_BattleTentLobby_MapBGEvents:
	bg_event 4, 5, 0, BG_EVENT_PLAYER_FACING_ANY, FallarborTown_BattleTentLobby_EventScript_20024F

FallarborTown_BattleTentLobby_MapEvents::
	map_events FallarborTown_BattleTentLobby_EventObjects, FallarborTown_BattleTentLobby_MapWarps, 0x0, FallarborTown_BattleTentLobby_MapBGEvents

