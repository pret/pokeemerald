ShoalCave_LowTideEntranceRoom_EventObjects: @ 853627C
	object_event 1, EVENT_OBJ_GFX_ITEM_BALL, 0, 30, 3, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, ShoalCave_LowTideEntranceRoom_EventScript_2913C0, FLAG_0x439
	object_event 2, EVENT_OBJ_GFX_EXPERT_M, 0, 18, 15, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 0, 0, ShoalCave_LowTideEntranceRoom_EventScript_236DD9, 0

ShoalCave_LowTideEntranceRoom_MapWarps: @ 85362AC
	warp_def 20, 30, 3, 0, MAP_ROUTE125
	warp_def 19, 5, 3, 0, MAP_SHOAL_CAVE_LOW_TIDE_INNER_ROOM
	warp_def 6, 2, 3, 6, MAP_SHOAL_CAVE_LOW_TIDE_INNER_ROOM
	warp_def 27, 2, 3, 7, MAP_SHOAL_CAVE_LOW_TIDE_INNER_ROOM

ShoalCave_LowTideEntranceRoom_MapEvents:: @ 85362CC
	map_events ShoalCave_LowTideEntranceRoom_EventObjects, ShoalCave_LowTideEntranceRoom_MapWarps, 0x0, 0x0

