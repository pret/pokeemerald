EverGrandeCity_ChampionsRoom_EventObjects: @ 8533700
	object_event 1, EVENT_OBJ_GFX_WALLACE, 0, 6, 5, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, 0x0, 0
	object_event 2, EVENT_OBJ_GFX_VAR_0, 0, 6, 12, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, 0x0, FLAG_HIDE_CHAMPIONS_ROOM_RIVAL
	object_event 3, EVENT_OBJ_GFX_PROF_BIRCH, 0, 6, 12, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, 0x0, FLAG_HIDE_CHAMPIONS_ROOM_BIRCH

EverGrandeCity_ChampionsRoom_MapWarps: @ 8533748
	warp_def 6, 12, 3, 1, MAP_EVER_GRANDE_CITY_HALL4
	warp_def 6, 2, 0, 0, MAP_EVER_GRANDE_CITY_HALL_OF_FAME

EverGrandeCity_ChampionsRoom_MapEvents:: @ 8533758
	map_events EverGrandeCity_ChampionsRoom_EventObjects, EverGrandeCity_ChampionsRoom_MapWarps, 0x0, 0x0

