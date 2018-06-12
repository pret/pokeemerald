SlateportCity_Harbor_EventObjects: @ 852FA68
	object_event 1, EVENT_OBJ_GFX_BEAUTY, 0, 0, 8, 10, 3, 8, 0, 0, 0, 0, SlateportCity_Harbor_EventScript_20CAF1, 905, 0, 0
	object_event 2, EVENT_OBJ_GFX_SAILOR, 0, 0, 4, 12, 3, 9, 0, 0, 0, 0, SlateportCity_Harbor_EventScript_20CC52, 905, 0, 0
	object_event 3, EVENT_OBJ_GFX_FAT_MAN, 0, 0, 1, 12, 3, 10, 0, 0, 0, 0, SlateportCity_Harbor_EventScript_20CC99, 905, 0, 0
	object_event 4, EVENT_OBJ_GFX_SCIENTIST_1, 0, 0, 6, 13, 3, 1, 0, 0, 0, 0, SlateportCity_Harbor_EventScript_20CCA2, 841, 0, 0
	object_event 5, EVENT_OBJ_GFX_SS_TIDAL, 0, 0, 8, 9, 1, 10, 0, 0, 0, 0, 0x0, 860, 0, 0
	object_event 6, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 0, 7, 10, 3, 10, 0, 0, 0, 0, 0x0, 845, 0, 0
	object_event 7, EVENT_OBJ_GFX_ARCHIE, 0, 0, 8, 10, 3, 9, 0, 0, 0, 0, 0x0, 846, 0, 0
	object_event 8, EVENT_OBJ_GFX_SUBMARINE_SHADOW, 0, 0, 7, 9, 1, 10, 0, 0, 0, 0, 0x0, 848, 0, 0

SlateportCity_Harbor_MapWarps: @ 852FB28
	warp_def 11, 14, 0, 8, SLATEPORT_CITY
	warp_def 12, 14, 0, 8, SLATEPORT_CITY
	warp_def 19, 15, 0, 9, SLATEPORT_CITY
	warp_def 20, 15, 0, 9, SLATEPORT_CITY

SlateportCity_Harbor_MapCoordEvents: @ 852FB48
	coord_event 8, 11, 3, 0, VAR_0x40A0, 1, 0, SlateportCity_Harbor_EventScript_20C9BB
	coord_event 8, 12, 3, 0, VAR_0x40A0, 1, 0, SlateportCity_Harbor_EventScript_20C9C7
	coord_event 8, 13, 3, 0, VAR_0x40A0, 1, 0, SlateportCity_Harbor_EventScript_20C9D3
	coord_event 8, 14, 3, 0, VAR_0x40A0, 1, 0, SlateportCity_Harbor_EventScript_20C9DF

SlateportCity_Harbor_MapEvents:: @ 852FB88
	map_events SlateportCity_Harbor_EventObjects, SlateportCity_Harbor_MapWarps, SlateportCity_Harbor_MapCoordEvents, 0x0

