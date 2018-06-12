VictoryRoad_B2F_EventObjects: @ 8536188
	object_event 1, EVENT_OBJ_GFX_MAN_4, 0, 0, 15, 6, 3, 8, 17, 0, 1, 2, VictoryRoad_B2F_EventScript_2368D5, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_MAN_4, 0, 0, 43, 14, 3, 7, 17, 0, 1, 4, VictoryRoad_B2F_EventScript_2368EC, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_WOMAN_7, 0, 0, 2, 17, 3, 8, 17, 0, 1, 2, VictoryRoad_B2F_EventScript_236903, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_WOMAN_7, 0, 0, 35, 22, 3, 9, 17, 0, 1, 2, VictoryRoad_B2F_EventScript_23691A, 0, 0, 0
	object_event 5, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 13, 8, 3, 1, 17, 0, 0, 0, VictoryRoad_B2F_EventScript_2914B7, 1088, 0, 0
	object_event 6, EVENT_OBJ_GFX_WOMAN_7, 0, 0, 25, 18, 4, 8, 17, 0, 1, 2, VictoryRoad_B2F_EventScript_236948, 0, 0, 0
	object_event 7, EVENT_OBJ_GFX_MAN_4, 0, 0, 25, 21, 4, 7, 17, 0, 1, 2, VictoryRoad_B2F_EventScript_236931, 0, 0, 0

VictoryRoad_B2F_MapWarps: @ 8536230
	warp_def 30, 25, 3, 0, VICTORY_ROAD_B1F
	warp_def 43, 2, 3, 3, VICTORY_ROAD_B1F
	warp_def 19, 12, 3, 1, VICTORY_ROAD_B1F
	warp_def 5, 26, 3, 6, VICTORY_ROAD_B1F

VictoryRoad_B2F_MapBGEvents: @ 8536250
	bg_event 28, 5, 3, 7, 0, ITEM_ELIXIR, 82, 0
	bg_event 37, 1, 3, 7, 0, ITEM_MAX_REPEL, 83, 0

VictoryRoad_B2F_MapEvents:: @ 8536268
	map_events VictoryRoad_B2F_EventObjects, VictoryRoad_B2F_MapWarps, 0x0, VictoryRoad_B2F_MapBGEvents

