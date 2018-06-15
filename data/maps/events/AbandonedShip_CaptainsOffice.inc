AbandonedShip_CaptainsOffice_EventObjects: @ 8536A5C
	object_event 1, EVENT_OBJ_GFX_SCIENTIST_1, 0, 0, 3, 4, 3, 8, 0, 0, 0, 0, AbandonedShip_CaptainsOffice_EventScript_2387E2, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 0, 6, 3, 1, 17, 0, 0, 0, AbandonedShip_CaptainsOffice_EventScript_29126E, 1100, 0, 0

AbandonedShip_CaptainsOffice_MapWarps: @ 8536A8C
	warp_def 7, 6, 3, 4, MAP_ABANDONED_SHIP_DECK
	warp_def 8, 6, 3, 4, MAP_ABANDONED_SHIP_DECK

AbandonedShip_CaptainsOffice_MapEvents:: @ 8536A9C
	map_events AbandonedShip_CaptainsOffice_EventObjects, AbandonedShip_CaptainsOffice_MapWarps, 0x0, 0x0

