MtChimney_CableCarStation_EventObjects: @ 8533CA8
	object_event 1, EVENT_OBJ_GFX_BEAUTY, 0, 0, 6, 6, 3, 8, 0, 0, 0, 0, MtChimney_CableCarStation_EventScript_22AC4B, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_CABLE_CAR, 0, 0, 6, 3, 3, 1, 0, 0, 0, 0, 0x0, 0, 0, 0

MtChimney_CableCarStation_MapWarps: @ 8533CD8
	warp_def 6, 11, 0, 0, MT_CHIMNEY
	warp_def 7, 11, 0, 1, MT_CHIMNEY

MtChimney_CableCarStation_MapEvents:: @ 8533CE8
	map_events MtChimney_CableCarStation_EventObjects, MtChimney_CableCarStation_MapWarps, 0x0, 0x0

