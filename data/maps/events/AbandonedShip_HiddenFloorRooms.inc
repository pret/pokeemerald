AbandonedShip_HiddenFloorRooms_EventObjects: @ 8536B40
	object_event 1, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 41, 4, 3, 1, 0, 0, 0, 0, AbandonedShip_HiddenFloorRooms_EventScript_29127B, 1077, 0, 0
	object_event 2, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 16, 10, 3, 1, 0, 0, 0, 0, AbandonedShip_HiddenFloorRooms_EventScript_291288, 1078, 0, 0
	object_event 3, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 5, 11, 3, 1, 17, 0, 0, 0, AbandonedShip_HiddenFloorRooms_EventScript_2912A2, 1102, 0, 0
	object_event 4, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 31, 11, 3, 1, 17, 0, 0, 0, AbandonedShip_HiddenFloorRooms_EventScript_291295, 1101, 0, 0

AbandonedShip_HiddenFloorRooms_MapWarps: @ 8536BA0
	warp_def 6, 14, 3, 0, ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS
	warp_def 7, 14, 3, 0, ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS
	warp_def 21, 14, 3, 1, ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS
	warp_def 22, 14, 3, 1, ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS
	warp_def 36, 14, 3, 2, ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS
	warp_def 37, 14, 3, 2, ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS
	warp_def 6, 1, 3, 3, ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS
	warp_def 21, 1, 3, 4, ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS
	warp_def 36, 1, 3, 5, ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS

AbandonedShip_HiddenFloorRooms_MapBGEvents: @ 8536BE8
	bg_event 42, 10, 3, 7, 0, ITEM_ROOM_1_KEY, 31, 0
	bg_event 20, 5, 3, 7, 0, ITEM_ROOM_2_KEY, 32, 0
	bg_event 1, 12, 3, 7, 0, ITEM_ROOM_4_KEY, 33, 0
	bg_event 1, 2, 0, 7, 0, ITEM_ROOM_6_KEY, 34, 0
	bg_event 8, 5, 3, 0, 0, AbandonedShip_HiddenFloorRooms_EventScript_238DF3
	bg_event 11, 3, 3, 0, 0, AbandonedShip_HiddenFloorRooms_EventScript_238DF3
	bg_event 10, 10, 3, 0, 0, AbandonedShip_HiddenFloorRooms_EventScript_238DF3
	bg_event 16, 3, 3, 0, 0, AbandonedShip_HiddenFloorRooms_EventScript_238DF3
	bg_event 25, 2, 3, 0, 0, AbandonedShip_HiddenFloorRooms_EventScript_238DF3
	bg_event 24, 6, 3, 0, 0, AbandonedShip_HiddenFloorRooms_EventScript_238DF3

AbandonedShip_HiddenFloorRooms_MapEvents:: @ 8536C60
	map_events AbandonedShip_HiddenFloorRooms_EventObjects, AbandonedShip_HiddenFloorRooms_MapWarps, 0x0, AbandonedShip_HiddenFloorRooms_MapBGEvents

