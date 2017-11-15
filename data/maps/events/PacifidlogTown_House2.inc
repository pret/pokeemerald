PacifidlogTown_House2_MapObjects: @ 852EBF4
	object_event 1, MAP_OBJ_GFX_GENTLEMAN, 0, 0, 3, 5, 3, 8, 17, 0, 0, 0, PacifidlogTown_House2_EventScript_203792, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_AZURILL, 0, 0, 8, 6, 3, 1, 17, 0, 0, 0, PacifidlogTown_House2_EventScript_203891, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_AZURILL, 0, 0, 1, 7, 3, 1, 17, 0, 0, 0, PacifidlogTown_House2_EventScript_2038AC, 0, 0, 0

PacifidlogTown_House2_MapWarps: @ 852EC3C
	warp_def 4, 8, 0, 2, PACIFIDLOG_TOWN
	warp_def 5, 8, 0, 2, PACIFIDLOG_TOWN

PacifidlogTown_House2_MapEvents:: @ 852EC4C
	map_events PacifidlogTown_House2_MapObjects, PacifidlogTown_House2_MapWarps, 0x0, 0x0

