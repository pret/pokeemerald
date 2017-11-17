DoubleBattleColosseum_MapWarps: @ 8539E88
	warp_def 5, 8, 3, 127, NONE
	warp_def 6, 8, 3, 127, NONE
	warp_def 7, 8, 3, 127, NONE
	warp_def 8, 8, 3, 127, NONE

DoubleBattleColosseum_MapCoordEvents: @ 8539EA8
	coord_event 3, 4, 3, 0, VAR_0x4000, 0, 0, gUnknown_08277388
	coord_event 3, 6, 3, 0, VAR_0x4000, 0, 0, gUnknown_082773BE
	coord_event 10, 4, 3, 0, VAR_0x4000, 0, 0, gUnknown_082773A3
	coord_event 10, 6, 3, 0, VAR_0x4000, 0, 0, gUnknown_082773D9

DoubleBattleColosseum_MapEvents:: @ 8539EE8
	map_events 0x0, DoubleBattleColosseum_MapWarps, DoubleBattleColosseum_MapCoordEvents, 0x0

