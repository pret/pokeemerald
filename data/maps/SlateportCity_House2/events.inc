SlateportCity_House2_EventObjects: @ 852FB9C
	object_event 1, EVENT_OBJ_GFX_POKEFAN_M, 0, 4, 4, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, SlateportCity_House2_EventScript_20D9AF, 0
	object_event 2, EVENT_OBJ_GFX_GIRL_3, 0, 7, 4, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, SlateportCity_House2_EventScript_20D9B8, 0

SlateportCity_House2_MapWarps: @ 852FBCC
	warp_def 3, 7, 0, 10, MAP_SLATEPORT_CITY
	warp_def 4, 7, 0, 10, MAP_SLATEPORT_CITY

SlateportCity_House2_MapEvents:: @ 852FBDC
	map_events SlateportCity_House2_EventObjects, SlateportCity_House2_MapWarps, 0x0, 0x0

