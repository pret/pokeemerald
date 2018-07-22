Underwater2_MapWarps: @ 852CF1C
	warp_def 45, 65, 0, 0, MAP_UNDERWATER_SOOTOPOLIS_CITY

Underwater2_MapBGEvents: @ 852CF24
	bg_hidden_item_event 30, 17, 3, ITEM_HEART_SCALE, 14
	bg_hidden_item_event 41, 19, 3, ITEM_ULTRA_BALL, 15
	bg_hidden_item_event 63, 19, 3, ITEM_STARDUST, 16
	bg_hidden_item_event 10, 36, 3, ITEM_PEARL, 17
	bg_hidden_item_event 11, 39, 3, ITEM_IRON, 19
	bg_hidden_item_event 12, 35, 3, ITEM_YELLOW_SHARD, 18
	bg_hidden_item_event 65, 60, 3, ITEM_BIG_PEARL, 20
	bg_hidden_item_event 9, 77, 3, ITEM_BLUE_SHARD, 12

Underwater2_MapEvents:: @ 852CF84
	map_events 0x0, Underwater2_MapWarps, 0x0, Underwater2_MapBGEvents

