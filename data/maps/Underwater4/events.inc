Underwater4_MapWarps: @ 852CFEC
	warp_def 38, 26, 3, 0, MAP_UNDERWATER_SEAFLOOR_CAVERN

Underwater4_MapBGEvents: @ 852CFF4
	bg_hidden_item_event 38, 19, 3, ITEM_PROTEIN, FLAG_HIDDEN_ITEM_UNDERWATER_4_PROTEIN
	bg_hidden_item_event 69, 18, 3, ITEM_PEARL, FLAG_HIDDEN_ITEM_UNDERWATER_4_PEARL

Underwater4_MapEvents:: @ 852D00C
	map_events 0x0, Underwater4_MapWarps, 0x0, Underwater4_MapBGEvents

