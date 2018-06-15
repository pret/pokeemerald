LavaridgeTown_Mart_EventObjects: @ 852E148
	object_event 1, EVENT_OBJ_GFX_MART_EMPLOYEE, 0, 0, 1, 3, 3, 10, 0, 0, 0, 0, LavaridgeTown_Mart_EventScript_1FF9CE, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_OLD_MAN_1, 0, 0, 4, 2, 3, 8, 0, 0, 0, 0, LavaridgeTown_Mart_EventScript_1FF9FE, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_OLD_WOMAN_2, 0, 0, 9, 5, 3, 10, 0, 0, 0, 0, LavaridgeTown_Mart_EventScript_1FFA07, 0, 0, 0

LavaridgeTown_Mart_MapWarps: @ 852E190
	warp_def 3, 7, 0, 2, MAP_LAVARIDGE_TOWN
	warp_def 4, 7, 0, 2, MAP_LAVARIDGE_TOWN

LavaridgeTown_Mart_MapEvents:: @ 852E1A0
	map_events LavaridgeTown_Mart_EventObjects, LavaridgeTown_Mart_MapWarps, 0x0, 0x0

