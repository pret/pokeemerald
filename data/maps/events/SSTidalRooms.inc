SSTidalRooms_MapObjects: @ 853A314
	object_event 1, MAP_OBJ_GFX_MAN_3, 0, 0, 4, 7, 3, 10, 0, 0, 1, 0, SSTidalRooms_EventScript_23CA49, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_GENTLEMAN, 0, 0, 34, 11, 3, 9, 0, 0, 1, 3, SSTidalRooms_EventScript_23CA60, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_GENTLEMAN, 0, 0, 21, 5, 3, 10, 0, 0, 1, 0, SSTidalRooms_EventScript_23CA77, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_MAN_5, 0, 0, 5, 14, 3, 8, 0, 0, 1, 1, SSTidalRooms_EventScript_23CA8E, 0, 0, 0
	object_event 5, MAP_OBJ_GFX_WOMAN_5, 0, 0, 4, 14, 3, 8, 0, 0, 1, 1, SSTidalRooms_EventScript_23CAA9, 0, 0, 0
	object_event 6, MAP_OBJ_GFX_BOY_4, 0, 0, 22, 11, 3, 8, 17, 0, 1, 3, SSTidalRooms_EventScript_23CAC4, 0, 0, 0
	object_event 7, MAP_OBJ_GFX_WOMAN_3, 0, 0, 15, 6, 3, 9, 0, 0, 1, 0, SSTidalRooms_EventScript_23CADB, 0, 0, 0
	object_event 8, MAP_OBJ_GFX_MANIAC, 0, 0, 28, 5, 3, 7, 17, 0, 0, 0, SSTidalRooms_EventScript_23C9F2, 951, 0, 0

SSTidalRooms_MapWarps: @ 853A3D4
	warp_def 4, 16, 0, 0, SS_TIDAL_CORRIDOR
	warp_def 5, 16, 0, 0, SS_TIDAL_CORRIDOR
	warp_def 13, 16, 0, 1, SS_TIDAL_CORRIDOR
	warp_def 14, 16, 0, 1, SS_TIDAL_CORRIDOR
	warp_def 22, 16, 0, 2, SS_TIDAL_CORRIDOR
	warp_def 23, 16, 0, 2, SS_TIDAL_CORRIDOR
	warp_def 31, 16, 0, 3, SS_TIDAL_CORRIDOR
	warp_def 32, 16, 0, 3, SS_TIDAL_CORRIDOR
	warp_def 4, 1, 0, 4, SS_TIDAL_CORRIDOR
	warp_def 13, 1, 0, 5, SS_TIDAL_CORRIDOR
	warp_def 22, 1, 0, 6, SS_TIDAL_CORRIDOR
	warp_def 31, 1, 0, 7, SS_TIDAL_CORRIDOR

SSTidalRooms_MapBGEvents: @ 853A434
	bg_event 15, 11, 0, 0, 0, SSTidalRooms_EventScript_23CA33
	bg_event 15, 12, 0, 0, 0, SSTidalRooms_EventScript_23CA33

SSTidalRooms_MapEvents:: @ 853A44C
	map_events SSTidalRooms_MapObjects, SSTidalRooms_MapWarps, 0x0, SSTidalRooms_MapBGEvents

