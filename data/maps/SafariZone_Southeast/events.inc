SafariZone_Southeast_EventObjects: @ 853BA6C
	object_event 1, EVENT_OBJ_GFX_BOY_4, 0, 7, 7, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, SafariZone_Southeast_EventScript_23D3BD, 0
	object_event 2, EVENT_OBJ_GFX_FAT_MAN, 0, 20, 30, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, SafariZone_Southeast_EventScript_23D3B4, 0
	object_event 3, EVENT_OBJ_GFX_LITTLE_GIRL_2, 0, 8, 26, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, SafariZone_Southeast_EventScript_23D3AB, 0
	object_event 4, EVENT_OBJ_GFX_ITEM_BALL, 0, 31, 15, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, SafariZone_Southeast_EventScript_2912F0, 1170
	object_event 5, EVENT_OBJ_GFX_CAMPER, 0, 12, 16, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 0, 0, SafariZone_Southeast_EventScript_23D399, 747

SafariZone_Southeast_MapBGEvents: @ 853BAE4
	bg_event 19, 36, 3, 7, 0, ITEM_PP_UP, 108, 0
	bg_event 32, 33, 0, 7, 0, ITEM_FULL_RESTORE, 105, 0

SafariZone_Southeast_MapEvents:: @ 853BAFC
	map_events SafariZone_Southeast_EventObjects, 0x0, 0x0, SafariZone_Southeast_MapBGEvents

