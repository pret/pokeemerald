MtPyre_2F_EventObjects: @ 8534DF0
	object_event 1, EVENT_OBJ_GFX_MANIAC, 0, 3, 6, 3, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 1, 2, MtPyre_2F_EventScript_231128, 0
	object_event 2, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 10, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, MtPyre_2F_EventScript_2912FD, 1129
	object_event 3, EVENT_OBJ_GFX_WOMAN_1, 0, 9, 3, 3, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 0, 0, MtPyre_2F_EventScript_231116, 0
	object_event 4, EVENT_OBJ_GFX_POKEFAN_M, 0, 12, 10, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, MtPyre_2F_EventScript_23111F, 0
	object_event 5, EVENT_OBJ_GFX_WOMAN_4, 0, 2, 9, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 1, 1, MtPyre_2F_EventScript_23115A, 0
	object_event 6, EVENT_OBJ_GFX_MAN_4, 0, 3, 9, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 1, 1, MtPyre_2F_EventScript_23113F, 0
	object_event 7, EVENT_OBJ_GFX_BLACK_BELT, 0, 6, 9, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 1, 2, MtPyre_2F_EventScript_23118C, 0
	object_event 8, EVENT_OBJ_GFX_HEX_MANIAC, 0, 6, 6, 3, MOVEMENT_TYPE_FACE_DOWN_AND_LEFT, 1, 1, 1, 2, MtPyre_2F_EventScript_231175, 0

MtPyre_2F_MapWarps: @ 8534EB0
	warp_def 2, 1, 3, 4, MAP_MT_PYRE_1F
	warp_def 10, 1, 3, 0, MAP_MT_PYRE_3F
	warp_def 10, 12, 3, 4, MAP_MT_PYRE_3F
	warp_def 6, 12, 3, 5, MAP_MT_PYRE_3F
	warp_def 11, 9, 3, 5, MAP_MT_PYRE_1F

MtPyre_2F_MapEvents:: @ 8534ED8
	map_events MtPyre_2F_EventObjects, MtPyre_2F_MapWarps, 0x0, 0x0

