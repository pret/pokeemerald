Route108_EventObjects: @ 8528964
	object_event 1, EVENT_OBJ_GFX_SWIMMER_M, 0, 52, 13, 1, 45, 3, 3, 1, 3, Route108_EventScript_1EE68A, 0
	object_event 2, EVENT_OBJ_GFX_SWIMMER_F, 0, 35, 12, 1, 13, 1, 1, 1, 3, Route108_EventScript_1EE6B8, 0
	object_event 3, EVENT_OBJ_GFX_SWIMMER_M, 0, 13, 13, 1, 24, 0, 0, 1, 3, Route108_EventScript_1EE6A1, 0
	object_event 4, EVENT_OBJ_GFX_SWIMMER_F, 0, 8, 7, 1, 20, 6, 0, 1, 3, Route108_EventScript_1EE6CF, 0
	object_event 5, EVENT_OBJ_GFX_WOMAN_7, 0, 41, 5, 3, 10, 1, 1, 1, 1, Route108_EventScript_1EE6E6, 0
	object_event 6, EVENT_OBJ_GFX_SAILOR, 0, 43, 5, 3, 9, 1, 1, 1, 1, Route108_EventScript_1EE6FD, 0
	object_event 7, EVENT_OBJ_GFX_ITEM_BALL, 0, 42, 4, 3, 1, 1, 1, 0, 0, Route108_EventScript_290D4D, 1139

Route108_MapWarps: @ 8528A0C
	warp_def 29, 6, 3, 0, MAP_ABANDONED_SHIP_DECK

Route108_MapBGEvents: @ 8528A14
	bg_event 38, 14, 3, 7, 0, ITEM_RARE_CANDY, 86, 0

Route108_MapEvents:: @ 8528A20
	map_events Route108_EventObjects, Route108_MapWarps, 0x0, Route108_MapBGEvents

