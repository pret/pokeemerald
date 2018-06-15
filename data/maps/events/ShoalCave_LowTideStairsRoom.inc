ShoalCave_LowTideStairsRoom_EventObjects: @ 8536394
	object_event 1, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 13, 12, 3, 1, 17, 0, 0, 0, ShoalCave_LowTideStairsRoom_EventScript_2913DA, 1083, 0, 0

ShoalCave_LowTideStairsRoom_MapWarps: @ 85363AC
	warp_def 3, 12, 3, 1, MAP_SHOAL_CAVE_LOW_TIDE_INNER_ROOM
	warp_def 7, 4, 3, 2, MAP_SHOAL_CAVE_LOW_TIDE_INNER_ROOM

ShoalCave_LowTideStairsRoom_MapBGEvents: @ 85363BC
	bg_event 11, 11, 3, 0, 0, ShoalCave_LowTideStairsRoom_EventScript_23711A

ShoalCave_LowTideStairsRoom_MapEvents:: @ 85363C8
	map_events ShoalCave_LowTideStairsRoom_EventObjects, ShoalCave_LowTideStairsRoom_MapWarps, 0x0, ShoalCave_LowTideStairsRoom_MapBGEvents

