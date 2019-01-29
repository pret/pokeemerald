TradeCenter_EventObjects:
	object_event 1, EVENT_OBJ_GFX_LINK_RECEPTIONIST, 0, 9, 6, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, TradeCenter_EventScript_2774B6, 0

TradeCenter_MapWarps:
	warp_def 5, 8, 3, 127, MAP_NONE
	warp_def 6, 8, 3, 127, MAP_NONE

TradeCenter_MapCoordEvents:
	coord_event 4, 5, 3, VAR_TEMP_0, 0, gUnknown_082773F5
	coord_event 7, 5, 3, VAR_TEMP_0, 0, gUnknown_082773FF

TradeCenter_MapEvents::
	map_events TradeCenter_EventObjects, TradeCenter_MapWarps, TradeCenter_MapCoordEvents, 0x0

