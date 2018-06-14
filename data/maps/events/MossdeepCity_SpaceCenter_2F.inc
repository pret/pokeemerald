MossdeepCity_SpaceCenter_2F_EventObjects: @ 8532E4C
	object_event 1, EVENT_OBJ_GFX_BOY_4, 0, 0, 6, 2, 3, 7, 0, 0, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_223F03, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_GENTLEMAN, 0, 0, 11, 8, 3, 7, 0, 0, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_223EC8, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_SCIENTIST_1, 0, 0, 5, 6, 3, 2, 17, 0, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_223E8D, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_STEVEN, 0, 0, 1, 8, 3, 8, 17, 0, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_223F7A, 863, 0, 0
	object_event 5, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 0, 12, 2, 3, 10, 17, 0, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_223F3E, 862, 0, 0
	object_event 6, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 0, 13, 3, 3, 7, 17, 0, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_223F50, 862, 0, 0
	object_event 7, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 0, 14, 2, 3, 9, 17, 0, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_223F47, 862, 0, 0
	object_event 8, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 0, 0, 8, 3, 10, 17, 0, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_223F59, 862, 0, 0
	object_event 9, EVENT_OBJ_GFX_MAXIE, 0, 0, 1, 9, 3, 7, 17, 0, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_223F6F, 862, 0, 0

MossdeepCity_SpaceCenter_2F_MapWarps: @ 8532F24
	warp_def 13, 1, 0, 2, MOSSDEEP_CITY_SPACE_CENTER_1F

MossdeepCity_SpaceCenter_2F_MapEvents:: @ 8532F2C
	map_events MossdeepCity_SpaceCenter_2F_EventObjects, MossdeepCity_SpaceCenter_2F_MapWarps, 0x0, 0x0

