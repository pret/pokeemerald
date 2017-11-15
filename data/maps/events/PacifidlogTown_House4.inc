PacifidlogTown_House4_MapObjects: @ 852ECB4
	object_event 1, MAP_OBJ_GFX_WOMAN_3, 0, 0, 3, 4, 3, 8, 0, 0, 0, 0, PacifidlogTown_House4_EventScript_203F55, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_LITTLE_GIRL_2, 0, 0, 7, 5, 3, 2, 17, 0, 0, 0, PacifidlogTown_House4_EventScript_203F4C, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_BOY_1, 0, 0, 7, 4, 3, 2, 17, 0, 0, 0, PacifidlogTown_House4_EventScript_203F5E, 0, 0, 0

PacifidlogTown_House4_MapWarps: @ 852ECFC
	warp_def 4, 8, 0, 4, PACIFIDLOG_TOWN
	warp_def 5, 8, 0, 4, PACIFIDLOG_TOWN

PacifidlogTown_House4_MapEvents:: @ 852ED0C
	map_events PacifidlogTown_House4_MapObjects, PacifidlogTown_House4_MapWarps, 0x0, 0x0

