Underwater3_MapWarps: @ 852CF98
	warp_def 57, 5, 0, 0, MAP_UNDERWATER_MARINE_CAVE
	warp_def 67, 38, 0, 0, MAP_UNDERWATER_MARINE_CAVE

Underwater3_MapBGEvents: @ 852CFA8
	bg_event 12, 42, 3, 7, 0, ITEM_STAR_PIECE, 21, 0
	bg_event 50, 36, 3, 7, 0, ITEM_HP_UP, 22, 0
	bg_event 34, 72, 3, 7, 0, ITEM_HEART_SCALE, 23, 0
	bg_event 72, 20, 3, 7, 0, ITEM_RED_SHARD, 24, 0

Underwater3_MapEvents:: @ 852CFD8
	map_events 0x0, Underwater3_MapWarps, 0x0, Underwater3_MapBGEvents

