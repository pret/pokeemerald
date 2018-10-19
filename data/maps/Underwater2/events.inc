Underwater2_MapWarps: @ 852CF1C
	warp_def 45, 65, 0, 0, MAP_UNDERWATER_SOOTOPOLIS_CITY

Underwater2_MapBGEvents: @ 852CF24
	bg_hidden_item_event_new 30, 17, 3, ITEM_HEART_SCALE, FLAG_HIDDEN_ITEM_UNDERWATER_2_HEART_SCALE
	bg_hidden_item_event_new 41, 19, 3, ITEM_ULTRA_BALL, FLAG_HIDDEN_ITEM_UNDERWATER_2_ULTRA_BALL
	bg_hidden_item_event_new 63, 19, 3, ITEM_STARDUST, FLAG_HIDDEN_ITEM_UNDERWATER_2_STARDUST
	bg_hidden_item_event_new 10, 36, 3, ITEM_PEARL, FLAG_HIDDEN_ITEM_UNDERWATER_2_PEARL
	bg_hidden_item_event_new 11, 39, 3, ITEM_IRON, FLAG_HIDDEN_ITEM_UNDERWATER_2_IRON
	bg_hidden_item_event_new 12, 35, 3, ITEM_YELLOW_SHARD, FLAG_HIDDEN_ITEM_UNDERWATER_2_YELLOW_SHARD
	bg_hidden_item_event_new 65, 60, 3, ITEM_BIG_PEARL, FLAG_HIDDEN_ITEM_UNDERWATER_2_BIG_PEARL
	bg_hidden_item_event_new 9, 77, 3, ITEM_BLUE_SHARD, FLAG_HIDDEN_ITEM_UNDERWATER_2_BLUE_SHARD

Underwater2_MapEvents:: @ 852CF84
	map_events 0x0, Underwater2_MapWarps, 0x0, Underwater2_MapBGEvents

