SlateportCity_BattleTentLobby_EventObjects:
	object_event 1, EVENT_OBJ_GFX_SCIENTIST_1, 0, 6, 5, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, SlateportCity_BattleTentLobby_EventScript_2088AA, 0
	object_event 2, EVENT_OBJ_GFX_SAILOR, 0, 1, 5, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, SlateportCity_BattleTentLobby_EventScript_208A3D, 0
	object_event 3, EVENT_OBJ_GFX_MAN_3, 0, 3, 7, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, SlateportCity_BattleTentLobby_EventScript_208A7E, 0
	object_event 4, EVENT_OBJ_GFX_GIRL_1, 0, 1, 8, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, SlateportCity_BattleTentLobby_EventScript_208A87, 0
	object_event 5, EVENT_OBJ_GFX_WOMAN_2, 0, 11, 8, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 0, 0, SlateportCity_BattleTentLobby_EventScript_208A90, 0

SlateportCity_BattleTentLobby_MapWarps:
	warp_def 6, 9, 0, 3, MAP_SLATEPORT_CITY
	warp_def 7, 9, 0, 3, MAP_SLATEPORT_CITY

SlateportCity_BattleTentLobby_MapBGEvents:
	bg_event 4, 5, 0, BG_EVENT_PLAYER_FACING_ANY, SlateportCity_BattleTentLobby_EventScript_208A99

SlateportCity_BattleTentLobby_MapEvents::
	map_events SlateportCity_BattleTentLobby_EventObjects, SlateportCity_BattleTentLobby_MapWarps, 0x0, SlateportCity_BattleTentLobby_MapBGEvents

