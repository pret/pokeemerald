Route110_TrickHousePuzzle5_MapObjects: @ 853E4C0
	object_event 1, MAP_OBJ_GFX_MAN_1, 0, 0, 6, 17, 3, 9, 0, 0, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CB32, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_MAN_1, 0, 0, 0, 7, 3, 10, 0, 0, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CB53, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_MAN_1, 0, 0, 14, 10, 3, 9, 0, 0, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CB74, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_MAN_1, 0, 0, 14, 19, 3, 9, 0, 0, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CB95, 0, 0, 0
	object_event 5, MAP_OBJ_GFX_MAN_1, 0, 0, 10, 4, 3, 10, 0, 0, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CBB6, 0, 0, 0

Route110_TrickHousePuzzle5_MapWarps: @ 853E538
	warp_def 0, 21, 3, 2, ROUTE_110_TRICK_HOUSE_ENTRANCE
	warp_def 1, 21, 3, 2, ROUTE_110_TRICK_HOUSE_ENTRANCE
	warp_def 13, 1, 3, 0, ROUTE_110_TRICK_HOUSE_END

Route110_TrickHousePuzzle5_MapCoordEvents: @ 853E550
	coord_event 5, 17, 3, 0, VAR_0x4001, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CBD7
	coord_event 4, 17, 3, 0, VAR_0x4001, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CBE3
	coord_event 3, 17, 3, 0, VAR_0x4001, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CBEF
	coord_event 2, 17, 3, 0, VAR_0x4001, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CBFB
	coord_event 1, 7, 3, 0, VAR_0x4002, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CC13
	coord_event 2, 7, 3, 0, VAR_0x4002, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CC1F
	coord_event 13, 10, 3, 0, VAR_0x4003, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CC5B
	coord_event 12, 10, 3, 0, VAR_0x4003, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CC67
	coord_event 11, 10, 3, 0, VAR_0x4003, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CC73
	coord_event 13, 19, 3, 0, VAR_0x4004, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CC97
	coord_event 12, 19, 3, 0, VAR_0x4004, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CCA3
	coord_event 11, 4, 3, 0, VAR_0x4005, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CCDF
	coord_event 1, 17, 3, 0, VAR_0x4001, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CC07
	coord_event 3, 7, 3, 0, VAR_0x4002, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CC2B
	coord_event 4, 7, 3, 0, VAR_0x4002, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CC37
	coord_event 5, 7, 3, 0, VAR_0x4002, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CC43
	coord_event 6, 7, 3, 0, VAR_0x4002, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CC4F
	coord_event 10, 10, 3, 0, VAR_0x4003, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CC7F
	coord_event 9, 10, 3, 0, VAR_0x4003, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CC8B
	coord_event 11, 19, 3, 0, VAR_0x4004, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CCAF
	coord_event 10, 19, 3, 0, VAR_0x4004, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CCBB
	coord_event 9, 19, 3, 0, VAR_0x4004, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CCC7

Route110_TrickHousePuzzle5_MapBGEvents: @ 853E6B0
	bg_event 11, 21, 0, 0, 0, Route110_TrickHousePuzzle5_EventScript_26CB15

Route110_TrickHousePuzzle5_MapEvents:: @ 853E6BC
	map_events Route110_TrickHousePuzzle5_MapObjects, Route110_TrickHousePuzzle5_MapWarps, Route110_TrickHousePuzzle5_MapCoordEvents, Route110_TrickHousePuzzle5_MapBGEvents

