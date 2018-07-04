Route110_SeasideCyclingRoadNorthEntrance_EventObjects: @ 853E9A0
	object_event 1, EVENT_OBJ_GFX_MART_EMPLOYEE, 0, 7, 2, 3, 8, 0, 0, 0, 0, Route110_SeasideCyclingRoadNorthEntrance_EventScript_26EA78, 0

Route110_SeasideCyclingRoadNorthEntrance_MapWarps: @ 853E9B8
	warp_def 1, 5, 0, 4, MAP_ROUTE110
	warp_def 2, 5, 0, 4, MAP_ROUTE110
	warp_def 12, 5, 0, 5, MAP_ROUTE110
	warp_def 13, 5, 0, 5, MAP_ROUTE110

Route110_SeasideCyclingRoadNorthEntrance_MapCoordEvents: @ 853E9D8
	coord_event 7, 4, 3, 0, VAR_TEMP_1, 0, 0, Route110_SeasideCyclingRoadNorthEntrance_EventScript_26EA84
	coord_event 5, 4, 3, 0, VAR_TEMP_1, 1, 0, Route110_SeasideCyclingRoadNorthEntrance_EventScript_26EAB6

Route110_SeasideCyclingRoadNorthEntrance_MapEvents:: @ 853E9F8
	map_events Route110_SeasideCyclingRoadNorthEntrance_EventObjects, Route110_SeasideCyclingRoadNorthEntrance_MapWarps, Route110_SeasideCyclingRoadNorthEntrance_MapCoordEvents, 0x0

