Underwater3_MapWarps: @ 852CF98
	warp_def 57, 5, 0, 0, MAP_UNDERWATER_MARINE_CAVE
	warp_def 67, 38, 0, 0, MAP_UNDERWATER_MARINE_CAVE

Underwater3_MapBGEvents: @ 852CFA8
	bg_hidden_item_event 12, 42, 3, ITEM_STAR_PIECE, 21
	bg_hidden_item_event 50, 36, 3, ITEM_HP_UP, 22
	bg_hidden_item_event 34, 72, 3, ITEM_HEART_SCALE, 23
	bg_hidden_item_event 72, 20, 3, ITEM_RED_SHARD, 24

Underwater3_MapEvents:: @ 852CFD8
	map_events 0x0, Underwater3_MapWarps, 0x0, Underwater3_MapBGEvents

