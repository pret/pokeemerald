AbandonedShip_Room_B1F_EventObjects: @ 853697C
	object_event 1, EVENT_OBJ_GFX_ITEM_BALL, 0, 4, 4, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, AbandonedShip_Room_B1F_EventScript_291254, FLAG_ITEM_ABANDONED_SHIP_ROOMS_B1F_TM_13

AbandonedShip_Room_B1F_MapWarps: @ 8536994
	warp_def 4, 7, 3, 5, MAP_ABANDONED_SHIP_CORRIDORS_B1F
	warp_def 5, 7, 3, 5, MAP_ABANDONED_SHIP_CORRIDORS_B1F

AbandonedShip_Room_B1F_MapEvents:: @ 85369A4
	map_events AbandonedShip_Room_B1F_EventObjects, AbandonedShip_Room_B1F_MapWarps, 0x0, 0x0

