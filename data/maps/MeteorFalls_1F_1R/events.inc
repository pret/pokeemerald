MeteorFalls_1F_1R_EventObjects: @ 8533F74
	object_event 1, EVENT_OBJ_GFX_ITEM_BALL, 0, 2, 4, 3, 1, 0, 0, 0, 0, MeteorFalls_1F_1R_EventScript_2911AB, 1044
	object_event 2, EVENT_OBJ_GFX_ITEM_BALL, 0, 2, 14, 3, 1, 0, 0, 0, 0, MeteorFalls_1F_1R_EventScript_2911C5, 1046
	object_event 3, EVENT_OBJ_GFX_ITEM_BALL, 0, 27, 5, 3, 1, 0, 0, 0, 0, MeteorFalls_1F_1R_EventScript_2911B8, 1045
	object_event 4, EVENT_OBJ_GFX_ITEM_BALL, 0, 26, 32, 3, 1, 0, 0, 0, 0, MeteorFalls_1F_1R_EventScript_2911D2, 1047
	object_event 5, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 12, 20, 3, 8, 0, 0, 0, 0, 0x0, 939
	object_event 6, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 14, 21, 3, 9, 0, 0, 0, 0, 0x0, 939
	object_event 7, EVENT_OBJ_GFX_ARCHIE, 0, 6, 20, 3, 10, 0, 0, 0, 0, 0x0, 938
	object_event 8, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 6, 20, 3, 10, 0, 0, 0, 0, 0x0, 938
	object_event 9, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 6, 21, 3, 1, 0, 0, 0, 0, 0x0, 938
	object_event 10, EVENT_OBJ_GFX_SCIENTIST_1, 0, 13, 23, 3, 21, 0, 0, 0, 0, MeteorFalls_1F_1R_EventScript_22BF25, 942

MeteorFalls_1F_1R_MapWarps: @ 8534064
	warp_def 27, 18, 4, 0, MAP_ROUTE114
	warp_def 6, 39, 3, 0, MAP_ROUTE115
	warp_def 10, 3, 3, 0, MAP_METEOR_FALLS_1F_2R
	warp_def 5, 4, 3, 4, MAP_METEOR_FALLS_B1F_1R
	warp_def 26, 28, 3, 5, MAP_METEOR_FALLS_B1F_1R
	warp_def 4, 2, 0, 0, MAP_METEOR_FALLS_STEVENS_CAVE

MeteorFalls_1F_1R_MapCoordEvents: @ 8534094
	coord_event 14, 18, 4, 0, VAR_0x40BF, 0, 0, MeteorFalls_1F_1R_EventScript_22BD5F

MeteorFalls_1F_1R_MapBGEvents: @ 85340A4
	bg_event 9, 58, 0, 0, 0, 0x0

MeteorFalls_1F_1R_MapEvents:: @ 85340B0
	map_events MeteorFalls_1F_1R_EventObjects, MeteorFalls_1F_1R_MapWarps, MeteorFalls_1F_1R_MapCoordEvents, MeteorFalls_1F_1R_MapBGEvents

