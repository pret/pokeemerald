RustboroCity_Gym_EventObjects: @ 8530538
	object_event 1, EVENT_OBJ_GFX_ROXANNE, 0, 0, 5, 2, 3, 8, 0, 0, 0, 0, RustboroCity_Gym_EventScript_212F31, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_YOUNGSTER, 0, 0, 5, 13, 3, 8, 0, 0, 1, 2, RustboroCity_Gym_EventScript_212FE3, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_YOUNGSTER, 0, 0, 3, 9, 3, 9, 0, 0, 1, 3, RustboroCity_Gym_EventScript_212FFA, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_MAN_2, 0, 0, 3, 18, 3, 8, 0, 0, 0, 0, RustboroCity_Gym_EventScript_213028, 0, 0, 0
	object_event 5, EVENT_OBJ_GFX_HIKER, 0, 0, 1, 6, 3, 8, 17, 0, 1, 3, RustboroCity_Gym_EventScript_213011, 0, 0, 0

RustboroCity_Gym_MapWarps: @ 85305B0
	warp_def 5, 19, 0, 0, MAP_RUSTBORO_CITY
	warp_def 6, 19, 0, 0, MAP_RUSTBORO_CITY

RustboroCity_Gym_MapBGEvents: @ 85305C0
	bg_event 2, 18, 0, 1, 0, RustboroCity_Gym_EventScript_213047
	bg_event 8, 18, 0, 1, 0, RustboroCity_Gym_EventScript_213057

RustboroCity_Gym_MapEvents:: @ 85305D8
	map_events RustboroCity_Gym_EventObjects, RustboroCity_Gym_MapWarps, 0x0, RustboroCity_Gym_MapBGEvents

