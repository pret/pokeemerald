SSTidalCorridor_MapObjects: @ 853A158
	object_event 1, MAP_OBJ_GFX_SAILOR, 0, 0, 1, 11, 3, 7, 0, 0, 0, 0, SSTidalCorridor_EventScript_23C119, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_SAILOR, 0, 0, 16, 7, 3, 3, 32, 0, 0, 0, SSTidalCorridor_EventScript_23C1A3, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_OLD_MAN_1, 0, 0, 9, 2, 3, 8, 17, 0, 0, 0, SSTidalCorridor_EventScript_23C0D9, 950, 0, 0
	object_event 4, MAP_OBJ_GFX_WINGULL, 0, 0, 7, 2, 3, 1, 17, 0, 0, 0, SSTidalCorridor_EventScript_23C0E2, 950, 0, 0
	object_event 5, MAP_OBJ_GFX_SCOTT, 0, 0, 9, 10, 3, 9, 0, 0, 0, 0, 0x0, 810, 0, 0

SSTidalCorridor_MapWarps: @ 853A1D0
	warp_def 4, 9, 3, 0, SS_TIDAL_ROOMS
	warp_def 7, 9, 3, 2, SS_TIDAL_ROOMS
	warp_def 10, 9, 3, 4, SS_TIDAL_ROOMS
	warp_def 13, 9, 3, 6, SS_TIDAL_ROOMS
	warp_def 4, 3, 3, 8, SS_TIDAL_ROOMS
	warp_def 7, 3, 3, 9, SS_TIDAL_ROOMS
	warp_def 10, 3, 3, 10, SS_TIDAL_ROOMS
	warp_def 13, 3, 3, 11, SS_TIDAL_ROOMS
	warp_def 16, 2, 3, 0, SS_TIDAL_LOWER_DECK

SSTidalCorridor_MapBGEvents: @ 853A218
	bg_event 2, 1, 0, 0, 0, SSTidalCorridor_EventScript_23C17D
	bg_event 4, 1, 0, 0, 0, SSTidalCorridor_EventScript_23C17D
	bg_event 6, 1, 0, 0, 0, SSTidalCorridor_EventScript_23C17D
	bg_event 8, 1, 0, 0, 0, SSTidalCorridor_EventScript_23C17D
	bg_event 10, 1, 0, 0, 0, SSTidalCorridor_EventScript_23C17D
	bg_event 12, 1, 0, 0, 0, SSTidalCorridor_EventScript_23C17D
	bg_event 14, 1, 0, 0, 0, SSTidalCorridor_EventScript_23C17D
	bg_event 16, 1, 0, 0, 0, SSTidalCorridor_EventScript_23C17D
	bg_event 5, 9, 0, 1, 0, SSTidalCorridor_EventScript_23C0F5
	bg_event 8, 9, 0, 1, 0, SSTidalCorridor_EventScript_23C0FE
	bg_event 11, 9, 0, 1, 0, SSTidalCorridor_EventScript_23C107
	bg_event 14, 9, 0, 1, 0, SSTidalCorridor_EventScript_23C110

SSTidalCorridor_MapEvents:: @ 853A2A8
	map_events SSTidalCorridor_MapObjects, SSTidalCorridor_MapWarps, 0x0, SSTidalCorridor_MapBGEvents

