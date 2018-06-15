Route110_SeasideCyclingRoadEntrance2_EventObjects: @ 853EA0C
	object_event 1, EVENT_OBJ_GFX_MART_EMPLOYEE, 0, 0, 7, 2, 3, 8, 0, 0, 0, 0, Route110_SeasideCyclingRoadEntrance2_EventScript_26EBC4, 0, 0, 0

Route110_SeasideCyclingRoadEntrance2_MapWarps: @ 853EA24
	warp_def 1, 5, 0, 2, MAP_ROUTE110
	warp_def 2, 5, 0, 2, MAP_ROUTE110
	warp_def 12, 5, 0, 3, MAP_ROUTE110
	warp_def 13, 5, 0, 3, MAP_ROUTE110

Route110_SeasideCyclingRoadEntrance2_MapCoordEvents: @ 853EA44
	coord_event 7, 4, 3, 0, VAR_TEMP_1, 0, 0, Route110_SeasideCyclingRoadEntrance2_EventScript_26EBD0
	coord_event 5, 4, 3, 0, VAR_TEMP_1, 1, 0, Route110_SeasideCyclingRoadEntrance2_EventScript_26EC13

Route110_SeasideCyclingRoadEntrance2_MapEvents:: @ 853EA64
	map_events Route110_SeasideCyclingRoadEntrance2_EventObjects, Route110_SeasideCyclingRoadEntrance2_MapWarps, Route110_SeasideCyclingRoadEntrance2_MapCoordEvents, 0x0

