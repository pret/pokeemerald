Underwater4_MapWarps: @ 852CFEC
	warp_def 38, 26, 3, 0, UNDERWATER_SEAFLOOR_CAVERN

Underwater4_MapBGEvents: @ 852CFF4
	bg_event 38, 19, 3, 7, 0, ITEM_PROTEIN, 25, 0
	bg_event 69, 18, 3, 7, 0, ITEM_PEARL, 26, 0

Underwater4_MapEvents:: @ 852D00C
	map_events 0x0, Underwater4_MapWarps, 0x0, Underwater4_MapBGEvents

