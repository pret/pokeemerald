Underwater2_MapWarps: @ 852CF1C
	warp_def 45, 65, 0, 0, UNDERWATER_SOOTOPOLIS_CITY

Underwater2_MapBGEvents: @ 852CF24
	bg_event 30, 17, 3, 7, 0, ITEM_HEART_SCALE, 14, 0
	bg_event 41, 19, 3, 7, 0, ITEM_ULTRA_BALL, 15, 0
	bg_event 63, 19, 3, 7, 0, ITEM_STARDUST, 16, 0
	bg_event 10, 36, 3, 7, 0, ITEM_PEARL, 17, 0
	bg_event 11, 39, 3, 7, 0, ITEM_IRON, 19, 0
	bg_event 12, 35, 3, 7, 0, ITEM_YELLOW_SHARD, 18, 0
	bg_event 65, 60, 3, 7, 0, ITEM_BIG_PEARL, 20, 0
	bg_event 9, 77, 3, 7, 0, ITEM_BLUE_SHARD, 12, 0

Underwater2_MapEvents:: @ 852CF84
	map_events 0x0, Underwater2_MapWarps, 0x0, Underwater2_MapBGEvents

