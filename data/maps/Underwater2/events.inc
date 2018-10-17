Underwater2_MapWarps: @ 852CF1C
	warp_def 45, 65, 0, 0, MAP_UNDERWATER_SOOTOPOLIS_CITY

Underwater2_MapBGEvents: @ 852CF24
	bg_hidden_item_event 30, 17, 3, ITEM_HEART_SCALE, FLAG_TEMP_E
	bg_hidden_item_event 41, 19, 3, ITEM_ULTRA_BALL, FLAG_TEMP_F
	bg_hidden_item_event 63, 19, 3, ITEM_STARDUST, FLAG_TEMP_10
	bg_hidden_item_event 10, 36, 3, ITEM_PEARL, FLAG_TEMP_11
	bg_hidden_item_event 11, 39, 3, ITEM_IRON, FLAG_TEMP_13
	bg_hidden_item_event 12, 35, 3, ITEM_YELLOW_SHARD, FLAG_TEMP_12
	bg_hidden_item_event 65, 60, 3, ITEM_BIG_PEARL, FLAG_TEMP_14
	bg_hidden_item_event 9, 77, 3, ITEM_BLUE_SHARD, FLAG_TEMP_C

Underwater2_MapEvents:: @ 852CF84
	map_events 0x0, Underwater2_MapWarps, 0x0, Underwater2_MapBGEvents

