PetalburgWoods_EventObjects: @ 85345E4
	object_event 1, EVENT_OBJ_GFX_CUTTABLE_TREE, 0, 0, 19, 10, 3, 1, 0, 0, 0, 0, PetalburgWoods_EventScript_2906BB, 17, 0, 0
	object_event 2, EVENT_OBJ_GFX_CUTTABLE_TREE, 0, 0, 19, 11, 3, 1, 0, 0, 0, 0, PetalburgWoods_EventScript_2906BB, 18, 0, 0
	object_event 3, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 0, 26, 17, 3, 10, 0, 0, 0, 0, 0x0, 725, 0, 0
	object_event 4, EVENT_OBJ_GFX_MAN_2, 0, 0, 26, 20, 3, 1, 0, 0, 0, 0, 0x0, 724, 0, 0
	object_event 5, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 45, 7, 3, 8, 0, 0, 0, 0, PetalburgWoods_EventScript_29110F, 1056, 0, 0
	object_event 6, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 35, 20, 3, 8, 0, 0, 0, 0, PetalburgWoods_EventScript_291102, 1055, 0, 0
	object_event 7, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 4, 8, 3, 1, 0, 0, 0, 0, PetalburgWoods_EventScript_29111C, 1058, 0, 0
	object_event 8, EVENT_OBJ_GFX_BOY_2, 0, 0, 15, 19, 3, 3, 33, 0, 0, 0, PetalburgWoods_EventScript_22E210, 0, 0, 0
	object_event 9, EVENT_OBJ_GFX_BUG_CATCHER, 0, 0, 7, 32, 3, 22, 0, 0, 1, 3, PetalburgWoods_EventScript_22E26D, 0, 0, 0
	object_event 10, EVENT_OBJ_GFX_BUG_CATCHER, 0, 0, 4, 14, 3, 20, 0, 0, 1, 3, PetalburgWoods_EventScript_22E284, 0, 0, 0
	object_event 11, EVENT_OBJ_GFX_BOY_3, 0, 0, 30, 34, 3, 2, 18, 0, 0, 0, PetalburgWoods_EventScript_22E219, 0, 0, 0
	object_event 12, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 4, 26, 3, 1, 17, 0, 0, 0, PetalburgWoods_EventScript_291129, 1117, 0, 0
	object_event 13, EVENT_OBJ_GFX_GIRL_2, 0, 0, 33, 5, 3, 1, 17, 0, 0, 0, PetalburgWoods_EventScript_22E222, 0, 0, 0

PetalburgWoods_MapWarps: @ 853471C
	warp_def 14, 5, 0, 2, ROUTE_104
	warp_def 15, 5, 0, 3, ROUTE_104
	warp_def 16, 38, 0, 4, ROUTE_104
	warp_def 17, 38, 0, 5, ROUTE_104
	warp_def 36, 38, 0, 6, ROUTE_104
	warp_def 37, 38, 0, 7, ROUTE_104

PetalburgWoods_MapCoordEvents: @ 853474C
	coord_event 26, 23, 3, 0, VAR_0x4098, 0, 0, PetalburgWoods_EventScript_22DFD7
	coord_event 27, 23, 3, 0, VAR_0x4098, 0, 0, PetalburgWoods_EventScript_22E079

PetalburgWoods_MapBGEvents: @ 853476C
	bg_event 14, 32, 3, 0, 0, PetalburgWoods_EventScript_22E25B
	bg_event 39, 35, 3, 7, 0, ITEM_POTION, 58, 0
	bg_event 26, 6, 3, 7, 0, ITEM_TINY_MUSHROOM, 59, 0
	bg_event 40, 29, 3, 7, 0, ITEM_TINY_MUSHROOM, 60, 0
	bg_event 4, 19, 3, 7, 0, ITEM_POKE_BALL, 61, 0
	bg_event 11, 8, 3, 0, 0, PetalburgWoods_EventScript_22E264

PetalburgWoods_MapEvents:: @ 85347B4
	map_events PetalburgWoods_EventObjects, PetalburgWoods_MapWarps, PetalburgWoods_MapCoordEvents, PetalburgWoods_MapBGEvents

