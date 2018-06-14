SSTidalLowerDeck_EventObjects: @ 853A2BC
	object_event 1, EVENT_OBJ_GFX_SAILOR, 0, 0, 10, 4, 3, 46, 68, 0, 1, 3, SSTidalLowerDeck_EventScript_23C819, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_SAILOR, 0, 0, 7, 4, 3, 50, 71, 0, 1, 3, SSTidalLowerDeck_EventScript_23C830, 0, 0, 0

SSTidalLowerDeck_MapWarps: @ 853A2EC
	warp_def 15, 2, 3, 8, SS_TIDAL_CORRIDOR

SSTidalLowerDeck_MapBGEvents: @ 853A2F4
	bg_event 0, 2, 0, 7, 0, ITEM_LEFTOVERS, 35, 0

SSTidalLowerDeck_MapEvents:: @ 853A300
	map_events SSTidalLowerDeck_EventObjects, SSTidalLowerDeck_MapWarps, 0x0, SSTidalLowerDeck_MapBGEvents

