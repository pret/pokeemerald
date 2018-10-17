Route110_TrickHousePuzzle1_EventObjects: @ 853DF88
	object_event 1, EVENT_OBJ_GFX_LASS, 0, 14, 20, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 1, 6, Route110_TrickHousePuzzle1_EventScript_26B948, 0
	object_event 2, EVENT_OBJ_GFX_YOUNGSTER, 0, 14, 8, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 1, 2, Route110_TrickHousePuzzle1_EventScript_26B95F, 0
	object_event 3, EVENT_OBJ_GFX_LASS, 0, 2, 15, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 1, 2, Route110_TrickHousePuzzle1_EventScript_26B976, 0
	object_event 4, EVENT_OBJ_GFX_CUTTABLE_TREE, 0, 11, 16, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, Route110_TrickHousePuzzle1_EventScript_2906BB, FLAG_TEMP_13
	object_event 5, EVENT_OBJ_GFX_CUTTABLE_TREE, 0, 13, 18, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, Route110_TrickHousePuzzle1_EventScript_2906BB, FLAG_TEMP_12
	object_event 6, EVENT_OBJ_GFX_CUTTABLE_TREE, 0, 14, 14, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, Route110_TrickHousePuzzle1_EventScript_2906BB, FLAG_TEMP_14
	object_event 7, EVENT_OBJ_GFX_CUTTABLE_TREE, 0, 11, 8, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, Route110_TrickHousePuzzle1_EventScript_2906BB, FLAG_TEMP_17
	object_event 8, EVENT_OBJ_GFX_CUTTABLE_TREE, 0, 8, 10, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, Route110_TrickHousePuzzle1_EventScript_2906BB, FLAG_TEMP_16
	object_event 9, EVENT_OBJ_GFX_CUTTABLE_TREE, 0, 11, 12, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, Route110_TrickHousePuzzle1_EventScript_2906BB, FLAG_TEMP_15
	object_event 10, EVENT_OBJ_GFX_CUTTABLE_TREE, 0, 2, 4, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, Route110_TrickHousePuzzle1_EventScript_2906BB, FLAG_TEMP_19
	object_event 11, EVENT_OBJ_GFX_CUTTABLE_TREE, 0, 13, 6, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, Route110_TrickHousePuzzle1_EventScript_2906BB, FLAG_TEMP_18
	object_event 12, EVENT_OBJ_GFX_CUTTABLE_TREE, 0, 0, 6, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, Route110_TrickHousePuzzle1_EventScript_2906BB, FLAG_TEMP_1B
	object_event 13, EVENT_OBJ_GFX_ITEM_BALL, 0, 9, 4, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, Route110_TrickHousePuzzle1_EventScript_29140E, FLAG_0x424
	object_event 14, EVENT_OBJ_GFX_CUTTABLE_TREE, 0, 4, 8, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, Route110_TrickHousePuzzle1_EventScript_2906BB, FLAG_TEMP_1C
	object_event 15, EVENT_OBJ_GFX_CUTTABLE_TREE, 0, 2, 12, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, Route110_TrickHousePuzzle1_EventScript_2906BB, FLAG_TEMP_1E

Route110_TrickHousePuzzle1_MapWarps: @ 853E0F0
	warp_def 0, 21, 3, 2, MAP_ROUTE110_TRICK_HOUSE_ENTRANCE
	warp_def 1, 21, 3, 2, MAP_ROUTE110_TRICK_HOUSE_ENTRANCE
	warp_def 13, 1, 3, 0, MAP_ROUTE110_TRICK_HOUSE_END

Route110_TrickHousePuzzle1_MapBGEvents: @ 853E108
	bg_event 3, 16, 0, BG_EVENT_PLAYER_FACING_ANY, Route110_TrickHousePuzzle1_EventScript_26B92B

Route110_TrickHousePuzzle1_MapEvents:: @ 853E114
	map_events Route110_TrickHousePuzzle1_EventObjects, Route110_TrickHousePuzzle1_MapWarps, 0x0, Route110_TrickHousePuzzle1_MapBGEvents

