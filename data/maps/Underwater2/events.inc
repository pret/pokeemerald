Underwater2_MapWarps: @ 852CF1C
	warp_def 45, 65, 0, 0, MAP_UNDERWATER_SOOTOPOLIS_CITY

Underwater2_MapBGEvents: @ 852CF24
	bg_hidden_item_event 30, 17, 3, ITEM_HEART_SCALE, FLAG_0x00E
	bg_hidden_item_event 41, 19, 3, ITEM_ULTRA_BALL, FLAG_0x00F
	bg_hidden_item_event 63, 19, 3, ITEM_STARDUST, FLAG_0x010
	bg_hidden_item_event 10, 36, 3, ITEM_PEARL, FLAG_0x011
	bg_hidden_item_event 11, 39, 3, ITEM_IRON, FLAG_0x013
	bg_hidden_item_event 12, 35, 3, ITEM_YELLOW_SHARD, FLAG_0x012
	bg_hidden_item_event 65, 60, 3, ITEM_BIG_PEARL, FLAG_0x014
	bg_hidden_item_event 9, 77, 3, ITEM_BLUE_SHARD, FLAG_0x00C

Underwater2_MapEvents:: @ 852CF84
	map_events 0x0, Underwater2_MapWarps, 0x0, Underwater2_MapBGEvents

