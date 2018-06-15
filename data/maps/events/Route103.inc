Route103_EventObjects: @ 85280DC
	object_event 1, EVENT_OBJ_GFX_MAN_4, 0, 0, 49, 12, 3, 9, 0, 0, 0, 0, Route103_EventScript_1EC5E2, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_HIPSTER, 0, 0, 10, 3, 3, 10, 0, 0, 0, 0, Route103_EventScript_1EC3C1, 723, 0, 0
	object_event 3, EVENT_OBJ_GFX_WOMAN_3, 0, 0, 71, 11, 3, 18, 0, 0, 1, 3, Route103_EventScript_1EC5F4, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_LITTLE_GIRL_1, 0, 0, 65, 12, 3, 8, 0, 0, 1, 1, Route103_EventScript_1EC66E, 0, 0, 0
	object_event 5, EVENT_OBJ_GFX_LITTLE_GIRL_1, 0, 0, 64, 12, 3, 8, 0, 0, 1, 1, Route103_EventScript_1EC60B, 0, 0, 0
	object_event 6, EVENT_OBJ_GFX_FISHERMAN, 0, 0, 50, 8, 3, 26, 16, 0, 1, 3, Route103_EventScript_1EC6D1, 0, 0, 0
	object_event 7, EVENT_OBJ_GFX_BERRY_TREE, 0, 0, 58, 5, 3, 12, 0, 0, 0, 5, BerryTreeScript, 0, 0, 0
	object_event 8, EVENT_OBJ_GFX_BERRY_TREE, 0, 0, 59, 5, 3, 12, 0, 0, 0, 6, BerryTreeScript, 0, 0, 0
	object_event 9, EVENT_OBJ_GFX_BERRY_TREE, 0, 0, 60, 5, 3, 12, 0, 0, 0, 7, BerryTreeScript, 0, 0, 0
	object_event 10, EVENT_OBJ_GFX_BOY_1, 0, 0, 20, 10, 3, 2, 33, 0, 0, 0, Route103_EventScript_1EC5D9, 0, 0, 0
	object_event 11, EVENT_OBJ_GFX_PROF_BIRCH, 0, 0, 7, 3, 3, 2, 17, 0, 0, 0, Route103_EventScript_272141, 898, 0, 0
	object_event 12, EVENT_OBJ_GFX_MAN_3, 0, 0, 56, 13, 3, 10, 0, 0, 1, 5, Route103_EventScript_1EC6E8, 0, 0, 0
	object_event 13, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 50, 5, 3, 1, 17, 0, 0, 0, Route103_EventScript_290CE5, 1114, 0, 0
	object_event 14, EVENT_OBJ_GFX_CUTTABLE_TREE, 0, 0, 67, 7, 3, 1, 17, 0, 0, 0, Route103_EventScript_2906BB, 18, 0, 0
	object_event 15, EVENT_OBJ_GFX_CUTTABLE_TREE, 0, 0, 72, 8, 3, 1, 17, 0, 0, 0, Route103_EventScript_2906BB, 19, 0, 0
	object_event 16, EVENT_OBJ_GFX_BLACK_BELT, 0, 0, 67, 5, 3, 8, 17, 0, 1, 2, Route103_EventScript_1EC761, 0, 0, 0
	object_event 17, EVENT_OBJ_GFX_MAN_6, 0, 0, 67, 9, 3, 7, 17, 0, 1, 2, Route103_EventScript_1EC74A, 0, 0, 0
	object_event 18, EVENT_OBJ_GFX_SWIMMER_F, 0, 0, 36, 6, 1, 26, 49, 0, 1, 5, Route103_EventScript_1EC78F, 0, 0, 0
	object_event 19, EVENT_OBJ_GFX_SWIMMER_M, 0, 0, 36, 13, 1, 25, 49, 0, 1, 5, Route103_EventScript_1EC778, 0, 0, 0
	object_event 20, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 64, 7, 0, 1, 17, 0, 0, 0, Route103_EventScript_290CF2, 1137, 0, 0

Route103_MapWarps: @ 85282BC
	warp_def 45, 6, 0, 0, MAP_ALTERING_CAVE

Route103_MapBGEvents: @ 85282C4
	bg_event 11, 9, 0, 0, 0, Route103_EventScript_1EC5EB

Route103_MapEvents:: @ 85282D0
	map_events Route103_EventObjects, Route103_MapWarps, 0x0, Route103_MapBGEvents

