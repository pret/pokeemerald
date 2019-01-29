MtPyre_3F_EventObjects:
	object_event 1, EVENT_OBJ_GFX_PSYCHIC_M, 0, 1, 4, 3, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT, 1, 1, 1, 4, MtPyre_3F_EventScript_231753, 0
	object_event 2, EVENT_OBJ_GFX_LASS, 0, 11, 4, 3, MOVEMENT_TYPE_FACE_DOWN_AND_LEFT, 1, 1, 1, 4, MtPyre_3F_EventScript_23176A, 0
	object_event 3, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 7, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, MtPyre_3F_EventScript_29130A, FLAG_ITEM_MT_PYRE_3F_SUPER_REPEL
	object_event 4, EVENT_OBJ_GFX_WOMAN_2, 0, 6, 4, 3, MOVEMENT_TYPE_FACE_LEFT_AND_RIGHT, 1, 1, 1, 4, MtPyre_3F_EventScript_231781, 0

MtPyre_3F_MapWarps:
	warp_def 10, 1, 3, 1, MAP_MT_PYRE_2F
	warp_def 2, 1, 3, 1, MAP_MT_PYRE_4F
	warp_def 9, 10, 3, 4, MAP_MT_PYRE_4F
	warp_def 1, 12, 3, 5, MAP_MT_PYRE_4F
	warp_def 10, 12, 3, 2, MAP_MT_PYRE_2F
	warp_def 6, 12, 3, 3, MAP_MT_PYRE_2F

MtPyre_3F_MapEvents::
	map_events MtPyre_3F_EventObjects, MtPyre_3F_MapWarps, 0x0, 0x0

