MtPyre_6F_EventObjects:
	object_event 1, EVENT_OBJ_GFX_HEX_MANIAC, 0, 6, 3, 3, MOVEMENT_TYPE_ROTATE_COUNTERCLOCKWISE, 1, 1, 1, 3, MtPyre_6F_EventScript_231D3B, 0
	object_event 2, EVENT_OBJ_GFX_ITEM_BALL, 0, 6, 9, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, MtPyre_6F_EventScript_291331, FLAG_ITEM_MT_PYRE_6F_TM_30
	object_event 3, EVENT_OBJ_GFX_PSYCHIC_M, 0, 10, 3, 3, MOVEMENT_TYPE_ROTATE_CLOCKWISE, 1, 1, 1, 3, MtPyre_6F_EventScript_231D9D, 0

MtPyre_6F_MapWarps:
	warp_def 2, 1, 3, 0, MAP_MT_PYRE_5F
	warp_def 1, 10, 3, 2, MAP_MT_PYRE_5F

MtPyre_6F_MapEvents::
	map_events MtPyre_6F_EventObjects, MtPyre_6F_MapWarps, 0x0, 0x0

