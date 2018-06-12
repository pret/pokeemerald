FortreeCity_Gym_EventObjects: @ 8530C98
	object_event 1, EVENT_OBJ_GFX_WINONA, 0, 0, 15, 2, 3, 8, 0, 0, 0, 0, FortreeCity_Gym_EventScript_2165C8, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_MAN_6, 0, 0, 4, 14, 3, 8, 0, 0, 1, 3, FortreeCity_Gym_EventScript_2166A8, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_CAMPER, 0, 0, 10, 10, 3, 9, 0, 0, 1, 2, FortreeCity_Gym_EventScript_2166D6, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_PICNICKER, 0, 0, 5, 17, 3, 9, 0, 0, 1, 1, FortreeCity_Gym_EventScript_2166ED, 0, 0, 0
	object_event 5, EVENT_OBJ_GFX_MAN_6, 0, 0, 9, 8, 3, 8, 0, 0, 1, 2, FortreeCity_Gym_EventScript_2166BF, 0, 0, 0
	object_event 6, EVENT_OBJ_GFX_MAN_2, 0, 0, 15, 21, 3, 8, 0, 0, 0, 0, FortreeCity_Gym_EventScript_216732, 0, 0, 0
	object_event 7, EVENT_OBJ_GFX_MAN_6, 0, 0, 4, 23, 3, 10, 17, 0, 1, 1, FortreeCity_Gym_EventScript_216704, 0, 0, 0
	object_event 8, EVENT_OBJ_GFX_MAN_6, 0, 0, 1, 10, 3, 7, 17, 0, 1, 3, FortreeCity_Gym_EventScript_21671B, 0, 0, 0

FortreeCity_Gym_MapWarps: @ 8530D58
	warp_def 15, 24, 0, 2, FORTREE_CITY
	warp_def 16, 24, 0, 2, FORTREE_CITY

FortreeCity_Gym_MapBGEvents: @ 8530D68
	bg_event 14, 21, 0, 1, 0, FortreeCity_Gym_EventScript_216751
	bg_event 17, 21, 0, 1, 0, FortreeCity_Gym_EventScript_216761

FortreeCity_Gym_MapEvents:: @ 8530D80
	map_events FortreeCity_Gym_EventObjects, FortreeCity_Gym_MapWarps, 0x0, FortreeCity_Gym_MapBGEvents

