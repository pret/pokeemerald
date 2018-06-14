DesertRuins_EventObjects: @ 8534354
	object_event 1, EVENT_OBJ_GFX_REGIROCK, 0, 0, 8, 7, 3, 8, 0, 0, 0, 0, DesertRuins_EventScript_22DA02, 935, 0, 0

DesertRuins_MapWarps: @ 853436C
	warp_def 8, 29, 3, 1, ROUTE_111
	warp_def 8, 20, 0, 2, DESERT_RUINS
	warp_def 8, 11, 3, 1, DESERT_RUINS

DesertRuins_MapBGEvents: @ 8534384
	bg_event 8, 20, 0, 0, 0, DesertRuins_EventScript_22D9DB
	bg_event 7, 20, 0, 0, 0, DesertRuins_EventScript_22D9F8
	bg_event 9, 20, 0, 0, 0, DesertRuins_EventScript_22D9F8

DesertRuins_MapEvents:: @ 85343A8
	map_events DesertRuins_EventObjects, DesertRuins_MapWarps, 0x0, DesertRuins_MapBGEvents

