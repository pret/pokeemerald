VictoryRoad_B2F_EventObjects:
	object_event 1, EVENT_OBJ_GFX_MAN_3, 0, 15, 6, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 1, 2, VictoryRoad_B2F_EventScript_2368D5, 0
	object_event 2, EVENT_OBJ_GFX_MAN_3, 0, 43, 14, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 1, 4, VictoryRoad_B2F_EventScript_2368EC, 0
	object_event 3, EVENT_OBJ_GFX_WOMAN_5, 0, 2, 17, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 1, 2, VictoryRoad_B2F_EventScript_236903, 0
	object_event 4, EVENT_OBJ_GFX_WOMAN_5, 0, 35, 22, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 1, 2, VictoryRoad_B2F_EventScript_23691A, 0
	object_event 5, EVENT_OBJ_GFX_ITEM_BALL, 0, 13, 8, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, VictoryRoad_B2F_EventScript_2914B7, FLAG_ITEM_VICTORY_ROAD_B2F_FULL_HEAL
	object_event 6, EVENT_OBJ_GFX_WOMAN_5, 0, 25, 18, 4, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 1, 2, VictoryRoad_B2F_EventScript_236948, 0
	object_event 7, EVENT_OBJ_GFX_MAN_3, 0, 25, 21, 4, MOVEMENT_TYPE_FACE_UP, 1, 1, 1, 2, VictoryRoad_B2F_EventScript_236931, 0

VictoryRoad_B2F_MapWarps:
	warp_def 30, 25, 3, 0, MAP_VICTORY_ROAD_B1F
	warp_def 43, 2, 3, 3, MAP_VICTORY_ROAD_B1F
	warp_def 19, 12, 3, 1, MAP_VICTORY_ROAD_B1F
	warp_def 5, 26, 3, 6, MAP_VICTORY_ROAD_B1F

VictoryRoad_B2F_MapBGEvents:
	bg_hidden_item_event 28, 5, 3, ITEM_ELIXIR, FLAG_HIDDEN_ITEM_VICTORY_ROAD_B2F_ELIXIR
	bg_hidden_item_event 37, 1, 3, ITEM_MAX_REPEL, FLAG_HIDDEN_ITEM_VICTORY_ROAD_B2F_MAX_REPEL

VictoryRoad_B2F_MapEvents::
	map_events VictoryRoad_B2F_EventObjects, VictoryRoad_B2F_MapWarps, 0x0, VictoryRoad_B2F_MapBGEvents

