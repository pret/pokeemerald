MossdeepCity_GameCorner_1F_EventObjects: @ 8532F40
	object_event 1, EVENT_OBJ_GFX_OLD_MAN_1, 0, 6, 2, 0, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, MossdeepCity_GameCorner_1F_EventScript_224B54, 0
	object_event 2, EVENT_OBJ_GFX_MAN_5, 0, 4, 2, 0, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, MossdeepCity_GameCorner_1F_EventScript_224B4B, 0

MossdeepCity_GameCorner_1F_MapWarps: @ 8532F70
	warp_def 5, 9, 0, 9, MAP_MOSSDEEP_CITY
	warp_def 6, 9, 0, 9, MAP_MOSSDEEP_CITY
	warp_def 2, 0, 0, 0, MAP_MOSSDEEP_CITY_GAME_CORNER_B1F

MossdeepCity_GameCorner_1F_MapBGEvents: @ 8532F88
	bg_event 3, 0, 0, 0, 0, MossdeepCity_GameCorner_1F_EventScript_224B5D
	bg_event 0, 1, 0, 0, 0, MossdeepCity_GameCorner_1F_EventScript_277E9D
	bg_event 1, 1, 0, 0, 0, MossdeepCity_GameCorner_1F_EventScript_277E96

MossdeepCity_GameCorner_1F_MapEvents:: @ 8532FAC
	map_events MossdeepCity_GameCorner_1F_EventObjects, MossdeepCity_GameCorner_1F_MapWarps, 0x0, MossdeepCity_GameCorner_1F_MapBGEvents

