MtPyre_Exterior_EventObjects: @ 85350DC
	object_event 1, EVENT_OBJ_GFX_ITEM_BALL, 0, 27, 15, 3, 1, 0, 0, 0, MtPyre_Exterior_EventScript_29133E, 1073
	object_event 2, EVENT_OBJ_GFX_ITEM_BALL, 0, 19, 40, 3, 1, 0, 0, 0, MtPyre_Exterior_EventScript_29134B, 1074

MtPyre_Exterior_MapWarps: @ 853510C
	warp_def 10, 42, 3, 1, MAP_MT_PYRE_1F
	warp_def 19, 10, 3, 1, MAP_MT_PYRE_SUMMIT
	warp_def 20, 10, 3, 1, MAP_MT_PYRE_SUMMIT

MtPyre_Exterior_MapCoordEvents: @ 8535124
	coord_event 24, 21, 3, 0, 0, 0, 0, MtPyre_Exterior_EventScript_231FED
	coord_event 25, 21, 3, 0, 0, 0, 0, MtPyre_Exterior_EventScript_231FED
	coord_event 22, 27, 3, 0, 0, 0, 0, MtPyre_Exterior_EventScript_231FF2
	coord_event 23, 28, 3, 0, 0, 0, 0, MtPyre_Exterior_EventScript_231FF2
	coord_event 26, 21, 3, 0, 0, 0, 0, MtPyre_Exterior_EventScript_231FED

MtPyre_Exterior_MapBGEvents: @ 8535174
	bg_event 9, 8, 0, 7, 0, ITEM_ULTRA_BALL, 29, 0
	bg_event 16, 22, 0, 7, 0, ITEM_MAX_ETHER, 78, 0

MtPyre_Exterior_MapEvents:: @ 853518C
	map_events MtPyre_Exterior_EventObjects, MtPyre_Exterior_MapWarps, MtPyre_Exterior_MapCoordEvents, MtPyre_Exterior_MapBGEvents

