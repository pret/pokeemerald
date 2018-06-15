SingleBattleColosseum_EventObjects: @ 8539D44
	object_event 1, EVENT_OBJ_GFX_WOMAN_6, 0, 0, 9, 3, 3, 9, 0, 0, 0, 0, SingleBattleColosseum_EventScript_2774A6, 0, 0, 0

SingleBattleColosseum_MapWarps: @ 8539D5C
	warp_def 6, 8, 3, 127, MAP_NONE
	warp_def 7, 8, 3, 127, MAP_NONE

SingleBattleColosseum_MapCoordEvents: @ 8539D6C
	coord_event 3, 5, 3, 0, VAR_TEMP_0, 0, 0, gUnknown_08277374
	coord_event 10, 5, 3, 0, VAR_TEMP_0, 0, 0, gUnknown_0827737E

SingleBattleColosseum_MapEvents:: @ 8539D8C
	map_events SingleBattleColosseum_EventObjects, SingleBattleColosseum_MapWarps, SingleBattleColosseum_MapCoordEvents, 0x0

