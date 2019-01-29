LilycoveCity_Harbor_EventObjects:
	object_event 1, EVENT_OBJ_GFX_BEAUTY, 0, 8, 10, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, LilycoveCity_Harbor_EventScript_21E00F, FLAG_HIDE_LILYCOVE_HARBOR_FERRY_ATTENDANT
	object_event 2, EVENT_OBJ_GFX_SS_TIDAL, 0, 8, 9, 1, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, 0x0, FLAG_HIDE_LILYCOVE_HARBOR_SSTIDAL
	object_event 3, EVENT_OBJ_GFX_SAILOR, 0, 3, 13, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, LilycoveCity_Harbor_EventScript_21E637, 0
	object_event 4, EVENT_OBJ_GFX_SAILOR, 0, 8, 10, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, 0x0, FLAG_HIDE_LILYCOVE_HARBOR_FERRY_SAILOR
	object_event 5, EVENT_OBJ_GFX_EXPERT_M, 0, 8, 10, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, 0x0, FLAG_HIDE_LILYCOVE_HARBOR_EON_TICKET_TAKER

LilycoveCity_Harbor_MapWarps:
	warp_def 11, 14, 0, 12, MAP_LILYCOVE_CITY
	warp_def 12, 14, 0, 12, MAP_LILYCOVE_CITY

LilycoveCity_Harbor_MapEvents::
	map_events LilycoveCity_Harbor_EventObjects, LilycoveCity_Harbor_MapWarps, 0x0, 0x0

