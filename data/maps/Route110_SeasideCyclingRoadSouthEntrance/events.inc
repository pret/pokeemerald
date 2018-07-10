Route110_SeasideCyclingRoadSouthEntrance_EventObjects: @ 853EA0C
	object_event 1, EVENT_OBJ_GFX_MART_EMPLOYEE, 0, 7, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, Route110_SeasideCyclingRoadSouthEntrance_EventScript_26EBC4, 0

Route110_SeasideCyclingRoadSouthEntrance_MapWarps: @ 853EA24
	warp_def 1, 5, 0, 2, MAP_ROUTE110
	warp_def 2, 5, 0, 2, MAP_ROUTE110
	warp_def 12, 5, 0, 3, MAP_ROUTE110
	warp_def 13, 5, 0, 3, MAP_ROUTE110

Route110_SeasideCyclingRoadSouthEntrance_MapCoordEvents: @ 853EA44
	coord_event 7, 4, 3, 0, VAR_TEMP_1, 0, 0, Route110_SeasideCyclingRoadSouthEntrance_EventScript_26EBD0
	coord_event 5, 4, 3, 0, VAR_TEMP_1, 1, 0, Route110_SeasideCyclingRoadSouthEntrance_EventScript_26EC13

Route110_SeasideCyclingRoadSouthEntrance_MapEvents:: @ 853EA64
	map_events Route110_SeasideCyclingRoadSouthEntrance_EventObjects, Route110_SeasideCyclingRoadSouthEntrance_MapWarps, Route110_SeasideCyclingRoadSouthEntrance_MapCoordEvents, 0x0

