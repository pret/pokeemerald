SSTidalLowerDeck_EventObjects: @ 853A2BC
	object_event 1, EVENT_OBJ_GFX_SAILOR, 0, 10, 4, 3, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_RIGHT_UP_LEFT, 4, 4, 1, 3, SSTidalLowerDeck_EventScript_23C819, 0
	object_event 2, EVENT_OBJ_GFX_SAILOR, 0, 7, 4, 3, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT, 7, 4, 1, 3, SSTidalLowerDeck_EventScript_23C830, 0

SSTidalLowerDeck_MapWarps: @ 853A2EC
	warp_def 15, 2, 3, 8, MAP_SS_TIDAL_CORRIDOR

SSTidalLowerDeck_MapBGEvents: @ 853A2F4
	bg_hidden_item_event 0, 2, 0, ITEM_LEFTOVERS, FLAG_0x023

SSTidalLowerDeck_MapEvents:: @ 853A300
	map_events SSTidalLowerDeck_EventObjects, SSTidalLowerDeck_MapWarps, 0x0, SSTidalLowerDeck_MapBGEvents

