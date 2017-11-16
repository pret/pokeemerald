Route110_TrickHousePuzzle7_MapObjects: @ 853E768
	object_event 1, MAP_OBJ_GFX_PSYCHIC_M, 0, 0, 9, 20, 0, 10, 0, 0, 1, 1, Route110_TrickHousePuzzle7_EventScript_26E389, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_LASS, 0, 0, 10, 2, 0, 7, 0, 0, 1, 1, Route110_TrickHousePuzzle7_EventScript_26E3B7, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_HEX_MANIAC, 0, 0, 8, 17, 0, 9, 0, 0, 1, 1, Route110_TrickHousePuzzle7_EventScript_26E3A0, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_ITEM_BALL, 0, 0, 5, 12, 3, 1, 0, 0, 0, 0, Route110_TrickHousePuzzle7_EventScript_291469, 1068, 0, 0
	object_event 5, MAP_OBJ_GFX_PSYCHIC_M, 0, 0, 9, 2, 3, 8, 17, 0, 1, 1, Route110_TrickHousePuzzle7_EventScript_26E3E5, 0, 0, 0
	object_event 6, MAP_OBJ_GFX_LASS, 0, 0, 8, 13, 3, 7, 17, 0, 1, 1, Route110_TrickHousePuzzle7_EventScript_26E3CE, 0, 0, 0
	object_event 7, MAP_OBJ_GFX_GENTLEMAN, 0, 0, 9, 12, 3, 9, 17, 0, 1, 1, Route110_TrickHousePuzzle7_EventScript_26E3FC, 0, 0, 0
	object_event 8, MAP_OBJ_GFX_TRICK_HOUSE_STATUE, 0, 0, 4, 17, 0, 1, 17, 0, 0, 0, 0x0, 0, 0, 0
	object_event 9, MAP_OBJ_GFX_TRICK_HOUSE_STATUE, 0, 0, 4, 6, 0, 1, 17, 0, 0, 0, 0x0, 0, 0, 0

Route110_TrickHousePuzzle7_MapWarps: @ 853E840
	warp_def 0, 21, 3, 2, ROUTE_110_TRICK_HOUSE_ENTRANCE
	warp_def 1, 21, 3, 2, ROUTE_110_TRICK_HOUSE_ENTRANCE
	warp_def 13, 1, 3, 0, ROUTE_110_TRICK_HOUSE_END
	warp_def 13, 4, 0, 4, ROUTE_110_TRICK_HOUSE_PUZZLE_7
	warp_def 7, 3, 0, 3, ROUTE_110_TRICK_HOUSE_PUZZLE_7
	warp_def 13, 11, 0, 6, ROUTE_110_TRICK_HOUSE_PUZZLE_7
	warp_def 4, 3, 0, 5, ROUTE_110_TRICK_HOUSE_PUZZLE_7
	warp_def 1, 17, 0, 8, ROUTE_110_TRICK_HOUSE_PUZZLE_7
	warp_def 0, 11, 0, 7, ROUTE_110_TRICK_HOUSE_PUZZLE_7
	warp_def 2, 3, 0, 10, ROUTE_110_TRICK_HOUSE_PUZZLE_7
	warp_def 4, 13, 0, 9, ROUTE_110_TRICK_HOUSE_PUZZLE_7
	warp_def 1, 3, 0, 12, ROUTE_110_TRICK_HOUSE_PUZZLE_7
	warp_def 8, 12, 0, 11, ROUTE_110_TRICK_HOUSE_PUZZLE_7

Route110_TrickHousePuzzle7_MapCoordEvents: @ 853E8A8
	coord_event 8, 19, 0, 0, VAR_0x4001, 0, 0, Route110_TrickHousePuzzle7_EventScript_26E31B
	coord_event 0, 14, 0, 0, VAR_0x4001, 0, 0, Route110_TrickHousePuzzle7_EventScript_26E331
	coord_event 6, 6, 0, 0, VAR_0x4001, 0, 0, Route110_TrickHousePuzzle7_EventScript_26E347
	coord_event 9, 7, 0, 0, VAR_0x4001, 0, 0, Route110_TrickHousePuzzle7_EventScript_26E35D

Route110_TrickHousePuzzle7_MapBGEvents: @ 853E8E8
	bg_event 6, 17, 0, 0, 0, Route110_TrickHousePuzzle7_EventScript_26E1D0

Route110_TrickHousePuzzle7_MapEvents:: @ 853E8F4
	map_events Route110_TrickHousePuzzle7_MapObjects, Route110_TrickHousePuzzle7_MapWarps, Route110_TrickHousePuzzle7_MapCoordEvents, Route110_TrickHousePuzzle7_MapBGEvents

