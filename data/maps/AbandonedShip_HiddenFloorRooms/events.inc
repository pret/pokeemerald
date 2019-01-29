AbandonedShip_HiddenFloorRooms_EventObjects:
	object_event 1, EVENT_OBJ_GFX_ITEM_BALL, 0, 41, 4, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, AbandonedShip_HiddenFloorRooms_EventScript_29127B, FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_6_LUXURY_BALL
	object_event 2, EVENT_OBJ_GFX_ITEM_BALL, 0, 16, 10, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, AbandonedShip_HiddenFloorRooms_EventScript_291288, FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_4_SCANNER
	object_event 3, EVENT_OBJ_GFX_ITEM_BALL, 0, 5, 11, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, AbandonedShip_HiddenFloorRooms_EventScript_2912A2, FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_1_TM_18
	object_event 4, EVENT_OBJ_GFX_ITEM_BALL, 0, 31, 11, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, AbandonedShip_HiddenFloorRooms_EventScript_291295, FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_3_WATER_STONE

AbandonedShip_HiddenFloorRooms_MapWarps:
	warp_def 6, 14, 3, 0, MAP_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS
	warp_def 7, 14, 3, 0, MAP_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS
	warp_def 21, 14, 3, 1, MAP_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS
	warp_def 22, 14, 3, 1, MAP_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS
	warp_def 36, 14, 3, 2, MAP_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS
	warp_def 37, 14, 3, 2, MAP_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS
	warp_def 6, 1, 3, 3, MAP_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS
	warp_def 21, 1, 3, 4, MAP_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS
	warp_def 36, 1, 3, 5, MAP_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS

AbandonedShip_HiddenFloorRooms_MapBGEvents:
	bg_hidden_item_event 42, 10, 3, ITEM_ROOM_1_KEY, FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_1_KEY
	bg_hidden_item_event 20, 5, 3, ITEM_ROOM_2_KEY, FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_2_KEY
	bg_hidden_item_event 1, 12, 3, ITEM_ROOM_4_KEY, FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_4_KEY
	bg_hidden_item_event 1, 2, 0, ITEM_ROOM_6_KEY, FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_6_KEY
	bg_event 8, 5, 3, BG_EVENT_PLAYER_FACING_ANY, AbandonedShip_HiddenFloorRooms_EventScript_238DF3
	bg_event 11, 3, 3, BG_EVENT_PLAYER_FACING_ANY, AbandonedShip_HiddenFloorRooms_EventScript_238DF3
	bg_event 10, 10, 3, BG_EVENT_PLAYER_FACING_ANY, AbandonedShip_HiddenFloorRooms_EventScript_238DF3
	bg_event 16, 3, 3, BG_EVENT_PLAYER_FACING_ANY, AbandonedShip_HiddenFloorRooms_EventScript_238DF3
	bg_event 25, 2, 3, BG_EVENT_PLAYER_FACING_ANY, AbandonedShip_HiddenFloorRooms_EventScript_238DF3
	bg_event 24, 6, 3, BG_EVENT_PLAYER_FACING_ANY, AbandonedShip_HiddenFloorRooms_EventScript_238DF3

AbandonedShip_HiddenFloorRooms_MapEvents::
	map_events AbandonedShip_HiddenFloorRooms_EventObjects, AbandonedShip_HiddenFloorRooms_MapWarps, 0x0, AbandonedShip_HiddenFloorRooms_MapBGEvents

