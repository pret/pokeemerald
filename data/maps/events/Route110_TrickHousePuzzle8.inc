Route110_TrickHousePuzzle8_EventObjects: @ 853E908
	object_event 1, EVENT_OBJ_GFX_MAN_4, 0, 0, 1, 10, 3, 7, 0, 0, 1, 1, Route110_TrickHousePuzzle8_EventScript_26E81F, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_MAN_4, 0, 0, 4, 2, 3, 10, 0, 0, 1, 1, Route110_TrickHousePuzzle8_EventScript_26E84D, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_WOMAN_7, 0, 0, 8, 17, 3, 9, 0, 0, 1, 1, Route110_TrickHousePuzzle8_EventScript_26E836, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 2, 2, 3, 1, 0, 0, 0, 0, Route110_TrickHousePuzzle8_EventScript_291476, 1069, 0, 0

Route110_TrickHousePuzzle8_MapWarps: @ 853E968
	warp_def 0, 21, 3, 2, MAP_ROUTE110_TRICK_HOUSE_ENTRANCE
	warp_def 1, 21, 3, 2, MAP_ROUTE110_TRICK_HOUSE_ENTRANCE
	warp_def 13, 1, 0, 0, MAP_ROUTE110_TRICK_HOUSE_END

Route110_TrickHousePuzzle8_MapBGEvents: @ 853E980
	bg_event 3, 21, 3, 0, 0, Route110_TrickHousePuzzle8_EventScript_26E802

Route110_TrickHousePuzzle8_MapEvents:: @ 853E98C
	map_events Route110_TrickHousePuzzle8_EventObjects, Route110_TrickHousePuzzle8_MapWarps, 0x0, Route110_TrickHousePuzzle8_MapBGEvents

