AbandonedShip_Corridors_B1F_EventObjects: @ 8536808
	object_event 1, EVENT_OBJ_GFX_TUBER_M, 0, 2, 8, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, AbandonedShip_Corridors_B1F_EventScript_237DBF, 0
	object_event 2, EVENT_OBJ_GFX_SAILOR, 0, 9, 6, 3, MOVEMENT_TYPE_FACE_LEFT_AND_RIGHT, 0, 0, 1, 4, AbandonedShip_Corridors_B1F_EventScript_237E13, 0

AbandonedShip_Corridors_B1F_MapWarps: @ 8536838
	warp_def 6, 4, 3, 2, MAP_ABANDONED_SHIP_ROOMS2_B1F
	warp_def 3, 4, 3, 0, MAP_ABANDONED_SHIP_ROOMS2_B1F
	warp_def 5, 7, 3, 0, MAP_ABANDONED_SHIP_ROOMS_B1F
	warp_def 8, 7, 3, 1, MAP_ABANDONED_SHIP_ROOMS_B1F
	warp_def 11, 7, 3, 2, MAP_ABANDONED_SHIP_ROOMS_B1F
	warp_def 11, 4, 3, 0, MAP_ABANDONED_SHIP_ROOM_B1F
	warp_def 0, 2, 3, 10, MAP_ABANDONED_SHIP_CORRIDORS_1F
	warp_def 8, 2, 3, 9, MAP_ABANDONED_SHIP_CORRIDORS_1F

AbandonedShip_Corridors_B1F_MapBGEvents: @ 8536878
	bg_event 11, 4, 3, 0, 0, AbandonedShip_Corridors_B1F_EventScript_237DC8

AbandonedShip_Corridors_B1F_MapEvents:: @ 8536884
	map_events AbandonedShip_Corridors_B1F_EventObjects, AbandonedShip_Corridors_B1F_MapWarps, 0x0, AbandonedShip_Corridors_B1F_MapBGEvents

