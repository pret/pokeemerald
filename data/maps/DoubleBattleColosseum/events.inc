DoubleBattleColosseum_MapWarps:
	warp_def 5, 8, 3, 127, MAP_NONE
	warp_def 6, 8, 3, 127, MAP_NONE
	warp_def 7, 8, 3, 127, MAP_NONE
	warp_def 8, 8, 3, 127, MAP_NONE

DoubleBattleColosseum_MapCoordEvents:
	coord_event 3, 4, 3, VAR_TEMP_0, 0, gUnknown_08277388
	coord_event 3, 6, 3, VAR_TEMP_0, 0, gUnknown_082773BE
	coord_event 10, 4, 3, VAR_TEMP_0, 0, gUnknown_082773A3
	coord_event 10, 6, 3, VAR_TEMP_0, 0, gUnknown_082773D9

DoubleBattleColosseum_MapEvents::
	map_events 0x0, DoubleBattleColosseum_MapWarps, DoubleBattleColosseum_MapCoordEvents, 0x0

