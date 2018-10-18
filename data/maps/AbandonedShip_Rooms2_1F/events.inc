AbandonedShip_Rooms2_1F_EventObjects: @ 85369B8
	object_event 1, EVENT_OBJ_GFX_MAN_4, 0, 7, 13, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 1, 1, AbandonedShip_Rooms2_1F_EventScript_2380A7, 0
	object_event 2, EVENT_OBJ_GFX_WOMAN_4, 0, 6, 13, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 1, 1, AbandonedShip_Rooms2_1F_EventScript_23810B, 0
	object_event 3, EVENT_OBJ_GFX_ITEM_BALL, 0, 4, 4, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, AbandonedShip_Rooms2_1F_EventScript_291261, FLAG_ITEM_ABANDONED_SHIP_ROOMS_2_1F_REVIVE
	object_event 4, EVENT_OBJ_GFX_HIKER, 0, 3, 2, 3, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 1, 3, AbandonedShip_Rooms2_1F_EventScript_238186, 0
	object_event 5, EVENT_OBJ_GFX_TUBER_F, 0, 7, 2, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 1, 3, AbandonedShip_Rooms2_1F_EventScript_23816F, 0

AbandonedShip_Rooms2_1F_MapWarps: @ 8536A30
	warp_def 4, 16, 3, 8, MAP_ABANDONED_SHIP_CORRIDORS_1F
	warp_def 5, 16, 3, 8, MAP_ABANDONED_SHIP_CORRIDORS_1F
	warp_def 4, 1, 3, 11, MAP_ABANDONED_SHIP_CORRIDORS_1F

AbandonedShip_Rooms2_1F_MapEvents:: @ 8536A48
	map_events AbandonedShip_Rooms2_1F_EventObjects, AbandonedShip_Rooms2_1F_MapWarps, 0x0, 0x0

