FortreeCity_House1_EventObjects: @ 8530C2C
	object_event 1, EVENT_OBJ_GFX_LITTLE_BOY_1, 0, 1, 3, 3, 10, 0, 0, 0, 0, FortreeCity_House1_EventScript_2162BB, 0
	object_event 2, EVENT_OBJ_GFX_ZIGZAGOON_2, 0, 2, 3, 3, 9, 0, 0, 0, 0, FortreeCity_House1_EventScript_216368, 0
	object_event 3, EVENT_OBJ_GFX_OLD_WOMAN_1, 0, 7, 4, 3, 1, 1, 1, 0, 0, FortreeCity_House1_EventScript_21635F, 0

FortreeCity_House1_MapWarps: @ 8530C74
	warp_def 3, 5, 0, 1, MAP_FORTREE_CITY
	warp_def 4, 5, 0, 1, MAP_FORTREE_CITY

FortreeCity_House1_MapEvents:: @ 8530C84
	map_events FortreeCity_House1_EventObjects, FortreeCity_House1_MapWarps, 0x0, 0x0

