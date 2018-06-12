MtPyre_6F_EventObjects: @ 8535070
	object_event 1, EVENT_OBJ_GFX_HEX_MANIAC, 0, 0, 6, 3, 3, 23, 17, 0, 1, 3, MtPyre_6F_EventScript_231D3B, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 6, 9, 3, 1, 17, 0, 0, 0, MtPyre_6F_EventScript_291331, 1089, 0, 0
	object_event 3, EVENT_OBJ_GFX_PSYCHIC_M, 0, 0, 10, 3, 3, 24, 17, 0, 1, 3, MtPyre_6F_EventScript_231D9D, 0, 0, 0

MtPyre_6F_MapWarps: @ 85350B8
	warp_def 2, 1, 3, 0, MT_PYRE_5F
	warp_def 1, 10, 3, 2, MT_PYRE_5F

MtPyre_6F_MapEvents:: @ 85350C8
	map_events MtPyre_6F_EventObjects, MtPyre_6F_MapWarps, 0x0, 0x0

