AbandonedShip_Rooms2_B1F_EventObjects: @ 85368F4
	object_event 1, EVENT_OBJ_GFX_CAMPER, 0, 3, 4, 3, 2, 17, 0, 0, AbandonedShip_Rooms2_B1F_EventScript_238025, 0
	object_event 2, EVENT_OBJ_GFX_ITEM_BALL, 0, 13, 3, 3, 1, 17, 0, 0, AbandonedShip_Rooms2_B1F_EventScript_291247, 1097

AbandonedShip_Rooms2_B1F_MapWarps: @ 8536924
	warp_def 4, 7, 3, 1, MAP_ABANDONED_SHIP_CORRIDORS_B1F
	warp_def 5, 7, 3, 1, MAP_ABANDONED_SHIP_CORRIDORS_B1F
	warp_def 13, 7, 3, 0, MAP_ABANDONED_SHIP_CORRIDORS_B1F
	warp_def 14, 7, 3, 0, MAP_ABANDONED_SHIP_CORRIDORS_B1F

AbandonedShip_Rooms2_B1F_MapEvents:: @ 8536944
	map_events AbandonedShip_Rooms2_B1F_EventObjects, AbandonedShip_Rooms2_B1F_MapWarps, 0x0, 0x0

