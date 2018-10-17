Underwater1_MapBGEvents: @ 852CEB4
	bg_hidden_item_event 42, 51, 0, ITEM_CARBOS, FLAG_0x008
	bg_hidden_item_event 14, 40, 0, ITEM_GREEN_SHARD, FLAG_0x009
	bg_hidden_item_event 66, 34, 3, ITEM_PEARL, FLAG_0x00A
	bg_hidden_item_event 64, 54, 3, ITEM_BIG_PEARL, FLAG_0x00B
	bg_hidden_item_event 70, 64, 3, ITEM_HEART_SCALE, FLAG_0x00D
	bg_hidden_item_event 42, 5, 3, ITEM_CALCIUM, FLAG_0x024
	bg_hidden_item_event 45, 36, 3, ITEM_HEART_SCALE, FLAG_0x026

Underwater1_MapEvents:: @ 852CF08
	map_events 0x0, 0x0, 0x0, Underwater1_MapBGEvents

