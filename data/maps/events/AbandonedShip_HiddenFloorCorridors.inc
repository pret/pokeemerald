AbandonedShip_HiddenFloorCorridors_MapWarps: @ 8536ACC
	warp_def 3, 8, 3, 0, ABANDONED_SHIP_HIDDEN_FLOOR_ROOMS
	warp_def 6, 8, 3, 2, ABANDONED_SHIP_HIDDEN_FLOOR_ROOMS
	warp_def 9, 8, 3, 4, ABANDONED_SHIP_HIDDEN_FLOOR_ROOMS
	warp_def 3, 3, 3, 6, ABANDONED_SHIP_HIDDEN_FLOOR_ROOMS
	warp_def 6, 3, 3, 7, ABANDONED_SHIP_HIDDEN_FLOOR_ROOMS
	warp_def 9, 3, 3, 8, ABANDONED_SHIP_HIDDEN_FLOOR_ROOMS

AbandonedShip_HiddenFloorCorridors_MapBGEvents: @ 8536AFC
	bg_event 3, 8, 3, 0, 0, AbandonedShip_HiddenFloorCorridors_EventScript_238A19
	bg_event 6, 8, 3, 0, 0, AbandonedShip_HiddenFloorCorridors_EventScript_238A50
	bg_event 3, 4, 0, 0, 0, AbandonedShip_HiddenFloorCorridors_EventScript_238A87
	bg_event 9, 4, 0, 0, 0, AbandonedShip_HiddenFloorCorridors_EventScript_238ABE

AbandonedShip_HiddenFloorCorridors_MapEvents:: @ 8536B2C
	map_events 0x0, AbandonedShip_HiddenFloorCorridors_MapWarps, 0x0, AbandonedShip_HiddenFloorCorridors_MapBGEvents

