MtPyre_4F_EventObjects: @ 8534F90
	object_event 1, EVENT_OBJ_GFX_HEX_MANIAC, 0, 0, 11, 7, 3, 24, 17, 0, 1, 2, MtPyre_4F_EventScript_231C6E, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 3, 11, 3, 1, 17, 0, 0, 0, MtPyre_4F_EventScript_291317, 1130, 0, 0

MtPyre_4F_MapWarps: @ 8534FC0
	warp_def 10, 1, 3, 1, MT_PYRE_5F
	warp_def 2, 5, 3, 1, MT_PYRE_3F
	warp_def 12, 10, 3, 3, MT_PYRE_5F
	warp_def 12, 12, 3, 4, MT_PYRE_5F
	warp_def 9, 10, 3, 2, MT_PYRE_3F
	warp_def 2, 12, 3, 3, MT_PYRE_3F

MtPyre_4F_MapEvents:: @ 8534FF0
	map_events MtPyre_4F_EventObjects, MtPyre_4F_MapWarps, 0x0, 0x0

