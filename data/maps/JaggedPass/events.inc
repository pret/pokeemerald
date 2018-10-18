JaggedPass_EventObjects: @ 8534AE4
	object_event 1, EVENT_OBJ_GFX_HIKER, 0, 10, 8, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 1, 3, JaggedPass_EventScript_230785, 0
	object_event 2, EVENT_OBJ_GFX_CAMPER, 0, 16, 35, 3, MOVEMENT_TYPE_FACE_LEFT_AND_RIGHT, 0, 0, 1, 4, JaggedPass_EventScript_2307FB, 0
	object_event 3, EVENT_OBJ_GFX_ITEM_BALL, 0, 23, 24, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, JaggedPass_EventScript_291184, FLAG_ITEM_JAGGED_PASS_BURN_HEAL
	object_event 4, EVENT_OBJ_GFX_PICNICKER, 0, 9, 21, 3, MOVEMENT_TYPE_FACE_UP_AND_RIGHT, 1, 1, 1, 3, JaggedPass_EventScript_23079C, 0
	object_event 5, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 16, 19, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, JaggedPass_EventScript_230718, FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	object_event 6, EVENT_OBJ_GFX_PICNICKER, 0, 14, 25, 3, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 1, 3, JaggedPass_EventScript_230871, 0
	object_event 7, EVENT_OBJ_GFX_CYCLING_TRIATHLETE_M, 0, 18, 25, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 1, 3, JaggedPass_EventScript_23085A, 0

JaggedPass_MapWarps: @ 8534B8C
	warp_def 14, 40, 3, 2, MAP_ROUTE112
	warp_def 15, 40, 3, 3, MAP_ROUTE112
	warp_def 13, 5, 3, 2, MAP_MT_CHIMNEY
	warp_def 14, 5, 3, 3, MAP_MT_CHIMNEY
	warp_def 16, 18, 0, 0, MAP_MAGMA_HIDEOUT_1F

JaggedPass_MapCoordEvents: @ 8534BB4
	coord_weather_event 13, 15, 3, COORD_EVENT_WEATHER_SUNNY
	coord_weather_event 21, 12, 3, COORD_EVENT_WEATHER_ASH
	coord_weather_event 14, 15, 3, COORD_EVENT_WEATHER_SUNNY
	coord_weather_event 18, 17, 3, COORD_EVENT_WEATHER_SUNNY
	coord_weather_event 22, 19, 3, COORD_EVENT_WEATHER_SUNNY
	coord_event 21, 15, 3, VAR_0x40C8, 1, JaggedPass_EventScript_2306BB
	coord_event 22, 20, 3, VAR_0x40C8, 1, JaggedPass_EventScript_2306BB
	coord_event 21, 20, 3, VAR_0x40C8, 1, JaggedPass_EventScript_2306BB
	coord_event 14, 15, 3, VAR_0x40C8, 1, JaggedPass_EventScript_2306BB
	coord_event 13, 15, 3, VAR_0x40C8, 1, JaggedPass_EventScript_2306BB

JaggedPass_MapBGEvents: @ 8534C54
	bg_hidden_item_event_new 8, 10, 3, ITEM_FULL_HEAL, FLAG_HIDDEN_ITEM_JAGGED_PASS_FULL_HEAL
	bg_hidden_item_event_new 7, 29, 3, ITEM_GREAT_BALL, FLAG_HIDDEN_ITEM_JAGGED_PASS_GREAT_BALL

JaggedPass_MapEvents:: @ 8534C6C
	map_events JaggedPass_EventObjects, JaggedPass_MapWarps, JaggedPass_MapCoordEvents, JaggedPass_MapBGEvents

