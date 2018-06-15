PacifidlogTown_House5_EventObjects: @ 852ED20
	object_event 1, EVENT_OBJ_GFX_OLD_MAN_1, 0, 9, 4, 3, 10, 0, 0, 0, PacifidlogTown_House5_EventScript_204111, 0
	object_event 2, EVENT_OBJ_GFX_GENTLEMAN, 0, 3, 4, 3, 10, 0, 0, 0, PacifidlogTown_House5_EventScript_204137, 0

PacifidlogTown_House5_MapWarps: @ 852ED50
	warp_def 4, 8, 0, 5, MAP_PACIFIDLOG_TOWN
	warp_def 5, 8, 0, 5, MAP_PACIFIDLOG_TOWN

PacifidlogTown_House5_MapEvents:: @ 852ED60
	map_events PacifidlogTown_House5_EventObjects, PacifidlogTown_House5_MapWarps, 0x0, 0x0

