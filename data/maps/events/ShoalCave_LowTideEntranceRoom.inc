ShoalCave_LowTideEntranceRoom_MapObjects: @ 853627C
	object_event 1, MAP_OBJ_GFX_ITEM_BALL, 0, 0, 30, 3, 3, 1, 17, 0, 0, 0, ShoalCave_LowTideEntranceRoom_EventScript_2913C0, 1081, 0, 0
	object_event 2, MAP_OBJ_GFX_OLD_MAN_1, 0, 0, 18, 15, 3, 9, 17, 0, 0, 0, ShoalCave_LowTideEntranceRoom_EventScript_236DD9, 0, 0, 0

ShoalCave_LowTideEntranceRoom_MapWarps: @ 85362AC
	warp_def 20, 30, 3, 0, ROUTE_125
	warp_def 19, 5, 3, 0, SHOAL_CAVE_LOW_TIDE_INNER_ROOM
	warp_def 6, 2, 3, 6, SHOAL_CAVE_LOW_TIDE_INNER_ROOM
	warp_def 27, 2, 3, 7, SHOAL_CAVE_LOW_TIDE_INNER_ROOM

ShoalCave_LowTideEntranceRoom_MapEvents:: @ 85362CC
	map_events ShoalCave_LowTideEntranceRoom_MapObjects, ShoalCave_LowTideEntranceRoom_MapWarps, 0x0, 0x0

