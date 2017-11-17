LavaridgeTown_House_MapObjects: @ 852E0DC
	object_event 1, MAP_OBJ_GFX_OLD_MAN_2, 0, 0, 2, 3, 3, 1, 17, 0, 0, 0, LavaridgeTown_House_EventScript_1FF912, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_ZIGZAGOON_2, 0, 0, 6, 6, 3, 1, 17, 0, 0, 0, LavaridgeTown_House_EventScript_1FF91B, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_LITTLE_BOY_1, 0, 0, 8, 4, 3, 2, 17, 0, 0, 0, LavaridgeTown_House_EventScript_2C804E, 0, 0, 0

LavaridgeTown_House_MapWarps: @ 852E124
	warp_def 3, 7, 0, 4, LAVARIDGE_TOWN
	warp_def 4, 7, 0, 4, LAVARIDGE_TOWN

LavaridgeTown_House_MapEvents:: @ 852E134
	map_events LavaridgeTown_House_MapObjects, LavaridgeTown_House_MapWarps, 0x0, 0x0

