AncientTomb_EventObjects: @ 8536CDC
	object_event 1, EVENT_OBJ_GFX_REGISTEEL, 0, 8, 7, 3, 8, 0, 0, 0, AncientTomb_EventScript_23905A, 937

AncientTomb_MapWarps: @ 8536CF4
	warp_def 8, 29, 3, 0, MAP_ROUTE120
	warp_def 8, 20, 0, 2, MAP_ANCIENT_TOMB
	warp_def 8, 11, 3, 1, MAP_ANCIENT_TOMB

AncientTomb_MapBGEvents: @ 8536D0C
	bg_event 8, 20, 0, 0, 0, AncientTomb_EventScript_239033
	bg_event 7, 20, 0, 0, 0, AncientTomb_EventScript_239050
	bg_event 9, 20, 0, 0, 0, AncientTomb_EventScript_239050

AncientTomb_MapEvents:: @ 8536D30
	map_events AncientTomb_EventObjects, AncientTomb_MapWarps, 0x0, AncientTomb_MapBGEvents

