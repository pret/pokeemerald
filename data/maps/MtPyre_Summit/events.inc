MtPyre_Summit_EventObjects: @ 85351A0
	object_event 1, EVENT_OBJ_GFX_OLD_MAN_2, 0, 22, 5, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, MtPyre_Summit_EventScript_23213C, 0
	object_event 2, EVENT_OBJ_GFX_ARCHIE, 0, 23, 6, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, 0x0, 916
	object_event 3, EVENT_OBJ_GFX_OLD_WOMAN_1, 0, 23, 5, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, MtPyre_Summit_EventScript_2321A2, 0
	object_event 4, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 21, 15, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 1, 3, MtPyre_Summit_EventScript_2323FD, 917
	object_event 5, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 25, 18, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 1, 3, MtPyre_Summit_EventScript_232414, 917
	object_event 6, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 21, 11, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 1, 3, MtPyre_Summit_EventScript_23242B, 917
	object_event 7, EVENT_OBJ_GFX_AQUA_MEMBER_F, 0, 25, 11, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 1, 3, MtPyre_Summit_EventScript_232442, 917
	object_event 8, EVENT_OBJ_GFX_MAXIE, 0, 23, 6, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, 0x0, 856

MtPyre_Summit_MapWarps: @ 8535260
	warp_def 22, 31, 3, 1, MAP_MT_PYRE_EXTERIOR
	warp_def 23, 31, 3, 1, MAP_MT_PYRE_EXTERIOR
	warp_def 24, 31, 3, 1, MAP_MT_PYRE_EXTERIOR

MtPyre_Summit_MapCoordEvents: @ 8535278
	coord_event 22, 7, 3, VAR_0x40B9, 0, MtPyre_Summit_EventScript_232018
	coord_event 23, 7, 3, VAR_0x40B9, 0, MtPyre_Summit_EventScript_232024
	coord_event 24, 7, 3, VAR_0x40B9, 0, MtPyre_Summit_EventScript_232030
	coord_event 22, 9, 3, VAR_0x40B9, 2, MtPyre_Summit_EventScript_2321EC
	coord_event 23, 9, 3, VAR_0x40B9, 2, MtPyre_Summit_EventScript_2321F8
	coord_event 24, 9, 3, VAR_0x40B9, 2, MtPyre_Summit_EventScript_232204

MtPyre_Summit_MapBGEvents: @ 85352D8
	bg_hidden_item_event 9, 25, 0, ITEM_ZINC, 79
	bg_hidden_item_event 37, 7, 3, ITEM_RARE_CANDY, 80

MtPyre_Summit_MapEvents:: @ 85352F0
	map_events MtPyre_Summit_EventObjects, MtPyre_Summit_MapWarps, MtPyre_Summit_MapCoordEvents, MtPyre_Summit_MapBGEvents

