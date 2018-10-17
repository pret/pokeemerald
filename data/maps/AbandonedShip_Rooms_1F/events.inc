AbandonedShip_Rooms_1F_EventObjects: @ 8536764
	object_event 1, EVENT_OBJ_GFX_GENTLEMAN, 0, 12, 5, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, AbandonedShip_Rooms_1F_EventScript_237A93, 0
	object_event 2, EVENT_OBJ_GFX_ITEM_BALL, 0, 4, 5, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, AbandonedShip_Rooms_1F_EventScript_29122D, FLAG_0x447
	object_event 3, EVENT_OBJ_GFX_BEAUTY, 0, 10, 11, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 1, 4, AbandonedShip_Rooms_1F_EventScript_237AB3, 0
	object_event 4, EVENT_OBJ_GFX_YOUNGSTER, 0, 10, 16, 3, MOVEMENT_TYPE_FACE_UP_AND_RIGHT, 1, 1, 1, 4, AbandonedShip_Rooms_1F_EventScript_237A9C, 0

AbandonedShip_Rooms_1F_MapWarps: @ 85367C4
	warp_def 4, 16, 3, 4, MAP_ABANDONED_SHIP_CORRIDORS_1F
	warp_def 5, 16, 3, 4, MAP_ABANDONED_SHIP_CORRIDORS_1F
	warp_def 4, 1, 3, 6, MAP_ABANDONED_SHIP_CORRIDORS_1F
	warp_def 13, 16, 3, 5, MAP_ABANDONED_SHIP_CORRIDORS_1F
	warp_def 13, 1, 3, 7, MAP_ABANDONED_SHIP_CORRIDORS_1F
	warp_def 14, 16, 3, 5, MAP_ABANDONED_SHIP_CORRIDORS_1F

AbandonedShip_Rooms_1F_MapEvents:: @ 85367F4
	map_events AbandonedShip_Rooms_1F_EventObjects, AbandonedShip_Rooms_1F_MapWarps, 0x0, 0x0

