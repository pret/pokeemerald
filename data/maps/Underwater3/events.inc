Underwater3_MapWarps: @ 852CF98
	warp_def 57, 5, 0, 0, MAP_UNDERWATER_MARINE_CAVE
	warp_def 67, 38, 0, 0, MAP_UNDERWATER_MARINE_CAVE

Underwater3_MapBGEvents: @ 852CFA8
	bg_hidden_item_event 12, 42, 3, ITEM_STAR_PIECE, FLAG_HIDDEN_ITEM_UNDERWATER_3_STAR_PIECE
	bg_hidden_item_event 50, 36, 3, ITEM_HP_UP, FLAG_HIDDEN_ITEM_UNDERWATER_3_HP_UP
	bg_hidden_item_event 34, 72, 3, ITEM_HEART_SCALE, FLAG_HIDDEN_ITEM_UNDERWATER_3_HEART_SCALE
	bg_hidden_item_event 72, 20, 3, ITEM_RED_SHARD, FLAG_HIDDEN_ITEM_UNDERWATER_3_RED_SHARD

Underwater3_MapEvents:: @ 852CFD8
	map_events 0x0, Underwater3_MapWarps, 0x0, Underwater3_MapBGEvents

