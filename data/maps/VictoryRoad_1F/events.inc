VictoryRoad_1F_EventObjects: @ 8535E04
	object_event 1, EVENT_OBJ_GFX_MAN_3, 0, 33, 22, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 1, 3, VictoryRoad_1F_EventScript_235E73, 0
	object_event 2, EVENT_OBJ_GFX_WOMAN_5, 0, 6, 15, 4, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 1, 4, VictoryRoad_1F_EventScript_235EA1, 0
	object_event 3, EVENT_OBJ_GFX_MAN_3, 0, 27, 34, 3, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT, 0, 0, 1, 3, VictoryRoad_1F_EventScript_235E8A, 0
	object_event 4, EVENT_OBJ_GFX_WALLY, 0, 12, 25, 4, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, VictoryRoad_1F_EventScript_235E2C, FLAG_0x35A
	object_event 5, EVENT_OBJ_GFX_ITEM_BALL, 0, 40, 26, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, VictoryRoad_1F_EventScript_291483, FLAG_0x43C
	object_event 6, EVENT_OBJ_GFX_ITEM_BALL, 0, 37, 39, 4, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, VictoryRoad_1F_EventScript_291490, FLAG_0x43D
	object_event 7, EVENT_OBJ_GFX_WALLY, 0, 31, 9, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, VictoryRoad_1F_EventScript_235E35, FLAG_0x2EF
	object_event 8, EVENT_OBJ_GFX_WOMAN_5, 0, 29, 17, 3, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 1, 2, VictoryRoad_1F_EventScript_235ECF, 0
	object_event 9, EVENT_OBJ_GFX_MAN_3, 0, 32, 17, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 1, 2, VictoryRoad_1F_EventScript_235EB8, 0

VictoryRoad_1F_MapWarps: @ 8535EDC
	warp_def 15, 40, 3, 2, MAP_EVER_GRANDE_CITY
	warp_def 39, 5, 3, 3, MAP_EVER_GRANDE_CITY
	warp_def 21, 32, 3, 5, MAP_VICTORY_ROAD_B1F
	warp_def 42, 38, 4, 2, MAP_VICTORY_ROAD_B1F
	warp_def 9, 14, 4, 4, MAP_VICTORY_ROAD_B1F

VictoryRoad_1F_MapCoordEvents: @ 8535F04
	coord_event 2, 23, 4, VAR_0x40C3, 0, VictoryRoad_1F_EventScript_235DAF
	coord_event 3, 23, 4, VAR_0x40C3, 0, VictoryRoad_1F_EventScript_235DC8

VictoryRoad_1F_MapBGEvents: @ 8535F24
	bg_hidden_item_event 30, 39, 4, ITEM_ULTRA_BALL, FLAG_0x051

VictoryRoad_1F_MapEvents:: @ 8535F30
	map_events VictoryRoad_1F_EventObjects, VictoryRoad_1F_MapWarps, VictoryRoad_1F_MapCoordEvents, VictoryRoad_1F_MapBGEvents

