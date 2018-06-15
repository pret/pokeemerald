TradeCenter_EventObjects: @ 8539DA0
	object_event 1, EVENT_OBJ_GFX_WOMAN_6, 0, 9, 6, 3, 9, 0, 0, 0, TradeCenter_EventScript_2774B6, 0

TradeCenter_MapWarps: @ 8539DB8
	warp_def 5, 8, 3, 127, MAP_NONE
	warp_def 6, 8, 3, 127, MAP_NONE

TradeCenter_MapCoordEvents: @ 8539DC8
	coord_event 4, 5, 3, 0, VAR_TEMP_0, 0, 0, gUnknown_082773F5
	coord_event 7, 5, 3, 0, VAR_TEMP_0, 0, 0, gUnknown_082773FF

TradeCenter_MapEvents:: @ 8539DE8
	map_events TradeCenter_EventObjects, TradeCenter_MapWarps, TradeCenter_MapCoordEvents, 0x0

