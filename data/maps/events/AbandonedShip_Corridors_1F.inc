AbandonedShip_Corridors_1F_MapObjects: @ 85366C0
	object_event 1, MAP_OBJ_GFX_YOUNGSTER, 0, 0, 17, 7, 3, 2, 17, 0, 0, 0, AbandonedShip_Corridors_1F_EventScript_2379A5, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_TUBER_M, 0, 0, 5, 10, 3, 45, 116, 0, 1, 3, AbandonedShip_Corridors_1F_EventScript_2379AE, 0, 0, 0

AbandonedShip_Corridors_1F_MapWarps: @ 85366F0
	warp_def 9, 11, 3, 2, ABANDONED_SHIP_DECK
	warp_def 8, 11, 3, 2, ABANDONED_SHIP_DECK
	warp_def 0, 11, 3, 3, ABANDONED_SHIP_DECK
	warp_def 1, 11, 3, 3, ABANDONED_SHIP_DECK
	warp_def 11, 9, 3, 0, ABANDONED_SHIP_ROOMS_1F
	warp_def 14, 9, 3, 3, ABANDONED_SHIP_ROOMS_1F
	warp_def 11, 3, 3, 2, ABANDONED_SHIP_ROOMS_1F
	warp_def 14, 3, 3, 4, ABANDONED_SHIP_ROOMS_1F
	warp_def 3, 9, 3, 0, ABANDONED_SHIP_ROOMS_2_1F
	warp_def 16, 2, 3, 7, ABANDONED_SHIP_CORRIDORS_B1F
	warp_def 5, 2, 3, 6, ABANDONED_SHIP_CORRIDORS_B1F
	warp_def 3, 3, 3, 2, ABANDONED_SHIP_ROOMS_2_1F

AbandonedShip_Corridors_1F_MapEvents:: @ 8536750
	map_events AbandonedShip_Corridors_1F_MapObjects, AbandonedShip_Corridors_1F_MapWarps, 0x0, 0x0

