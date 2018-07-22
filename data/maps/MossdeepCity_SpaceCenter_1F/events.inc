MossdeepCity_SpaceCenter_1F_EventObjects: @ 8532D18
	object_event 1, EVENT_OBJ_GFX_SCIENTIST_1, 0, 7, 2, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, MossdeepCity_SpaceCenter_1F_EventScript_222FD8, 0
	object_event 2, EVENT_OBJ_GFX_SCIENTIST_1, 0, 2, 2, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, MossdeepCity_SpaceCenter_1F_EventScript_223063, 0
	object_event 3, EVENT_OBJ_GFX_SAILOR, 0, 6, 6, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, MossdeepCity_SpaceCenter_1F_EventScript_22308E, 0
	object_event 4, EVENT_OBJ_GFX_OLD_MAN_2, 0, 10, 2, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, MossdeepCity_SpaceCenter_1F_EventScript_223168, 0
	object_event 5, EVENT_OBJ_GFX_WOMAN_5, 0, 14, 7, 3, MOVEMENT_TYPE_WANDER_UP_AND_DOWN, 1, 1, 0, 0, MossdeepCity_SpaceCenter_1F_EventScript_22312D, 0
	object_event 6, EVENT_OBJ_GFX_MAGMA_MEMBER_F, 0, 12, 9, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 1, 2, MossdeepCity_SpaceCenter_1F_EventScript_2231DA, 756
	object_event 7, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 11, 6, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 1, 2, MossdeepCity_SpaceCenter_1F_EventScript_2231F1, 756
	object_event 8, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 10, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 1, 2, MossdeepCity_SpaceCenter_1F_EventScript_223208, 756
	object_event 9, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 13, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 1, 0, MossdeepCity_SpaceCenter_1F_EventScript_22321F, 756
	object_event 10, EVENT_OBJ_GFX_LITTLE_BOY_1, 0, 2, 5, 0, MOVEMENT_TYPE_INVISIBLE, 1, 1, 0, 0, MossdeepCity_SpaceCenter_1F_EventScript_2231CF, 737
	object_event 11, EVENT_OBJ_GFX_STEVEN, 0, 1, 4, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, MossdeepCity_SpaceCenter_1F_EventScript_2231B9, 753

MossdeepCity_SpaceCenter_1F_MapWarps: @ 8532E20
	warp_def 7, 9, 0, 8, MAP_MOSSDEEP_CITY
	warp_def 8, 9, 0, 8, MAP_MOSSDEEP_CITY
	warp_def 13, 1, 0, 0, MAP_MOSSDEEP_CITY_SPACE_CENTER_2F

MossdeepCity_SpaceCenter_1F_MapEvents:: @ 8532E38
	map_events MossdeepCity_SpaceCenter_1F_EventObjects, MossdeepCity_SpaceCenter_1F_MapWarps, 0x0, 0x0

