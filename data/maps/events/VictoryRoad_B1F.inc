VictoryRoad_B1F_EventObjects: @ 8535F44
	object_event 1, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 20, 5, 3, 1, 0, 0, 0, 0, VictoryRoad_B1F_EventScript_2908BA, 19, 0, 0
	object_event 2, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 21, 4, 3, 1, 0, 0, 0, 0, VictoryRoad_B1F_EventScript_2908BA, 20, 0, 0
	object_event 3, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 4, 7, 3, 1, 0, 0, 0, 0, VictoryRoad_B1F_EventScript_2908BA, 17, 0, 0
	object_event 4, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 9, 10, 3, 1, 0, 0, 0, 0, VictoryRoad_B1F_EventScript_2908BA, 18, 0, 0
	object_event 5, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 20, 26, 3, 1, 0, 0, 0, 0, VictoryRoad_B1F_EventScript_2908BA, 23, 0, 0
	object_event 6, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 21, 25, 3, 1, 0, 0, 0, 0, VictoryRoad_B1F_EventScript_2908BA, 22, 0, 0
	object_event 7, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 35, 6, 3, 1, 0, 0, 0, 0, VictoryRoad_B1F_EventScript_2908BA, 30, 0, 0
	object_event 8, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 0, 19, 5, 3, 1, 0, 0, 0, 0, VictoryRoad_B1F_EventScript_2907A6, 25, 0, 0
	object_event 9, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 0, 20, 4, 3, 1, 0, 0, 0, 0, VictoryRoad_B1F_EventScript_2907A6, 26, 0, 0
	object_event 10, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 0, 18, 12, 3, 1, 0, 0, 0, 0, VictoryRoad_B1F_EventScript_2907A6, 27, 0, 0
	object_event 11, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 0, 20, 25, 3, 1, 0, 0, 0, 0, VictoryRoad_B1F_EventScript_2907A6, 28, 0, 0
	object_event 12, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 0, 21, 26, 3, 1, 0, 0, 0, 0, VictoryRoad_B1F_EventScript_2907A6, 29, 0, 0
	object_event 13, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 34, 4, 3, 1, 0, 0, 0, 0, VictoryRoad_B1F_EventScript_2908BA, 31, 0, 0
	object_event 14, EVENT_OBJ_GFX_MAN_4, 0, 0, 37, 12, 3, 9, 0, 0, 1, 3, VictoryRoad_B1F_EventScript_2364E5, 0, 0, 0
	object_event 15, EVENT_OBJ_GFX_WOMAN_7, 0, 0, 26, 16, 3, 7, 0, 0, 1, 4, VictoryRoad_B1F_EventScript_2364FC, 0, 0, 0
	object_event 16, EVENT_OBJ_GFX_WOMAN_7, 0, 0, 5, 21, 3, 9, 0, 0, 1, 2, VictoryRoad_B1F_EventScript_236513, 0, 0, 0
	object_event 17, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 0, 34, 3, 3, 1, 17, 0, 0, 0, VictoryRoad_B1F_EventScript_2907A6, 21, 0, 0
	object_event 18, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 42, 8, 4, 1, 17, 0, 0, 0, VictoryRoad_B1F_EventScript_29149D, 1086, 0, 0
	object_event 19, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 32, 3, 3, 1, 17, 0, 0, 0, VictoryRoad_B1F_EventScript_2914AA, 1087, 0, 0
	object_event 20, EVENT_OBJ_GFX_MAN_4, 0, 0, 14, 16, 3, 8, 17, 0, 1, 4, VictoryRoad_B1F_EventScript_23652A, 0, 0, 0
	object_event 21, EVENT_OBJ_GFX_WOMAN_7, 0, 0, 14, 20, 3, 16, 17, 0, 1, 3, VictoryRoad_B1F_EventScript_236541, 0, 0, 0

VictoryRoad_B1F_MapWarps: @ 853613C
	warp_def 30, 25, 3, 0, MAP_VICTORY_ROAD_B2F
	warp_def 17, 16, 3, 2, MAP_VICTORY_ROAD_B2F
	warp_def 42, 25, 3, 3, MAP_VICTORY_ROAD_1F
	warp_def 42, 2, 4, 1, MAP_VICTORY_ROAD_B2F
	warp_def 8, 3, 3, 4, MAP_VICTORY_ROAD_1F
	warp_def 20, 21, 3, 2, MAP_VICTORY_ROAD_1F
	warp_def 5, 26, 3, 3, MAP_VICTORY_ROAD_B2F

VictoryRoad_B1F_MapEvents:: @ 8536174
	map_events VictoryRoad_B1F_EventObjects, VictoryRoad_B1F_MapWarps, 0x0, 0x0

