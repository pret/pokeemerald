PacifidlogTown_EventObjects: @ 8527DE8
	object_event 1, EVENT_OBJ_GFX_GIRL_1, 0, 10, 23, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, PacifidlogTown_EventScript_1EBACC, 0
	object_event 2, EVENT_OBJ_GFX_FISHERMAN, 0, 11, 14, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, PacifidlogTown_EventScript_1EBAD5, 0
	object_event 3, EVENT_OBJ_GFX_NINJA_BOY, 0, 9, 16, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, PacifidlogTown_EventScript_1EBAC3, 0

PacifidlogTown_MapWarps: @ 8527E30
	warp_def 8, 15, 0, 0, MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_1F
	warp_def 16, 13, 0, 0, MAP_PACIFIDLOG_TOWN_HOUSE1
	warp_def 3, 22, 0, 0, MAP_PACIFIDLOG_TOWN_HOUSE2
	warp_def 12, 24, 0, 0, MAP_PACIFIDLOG_TOWN_HOUSE3
	warp_def 2, 12, 0, 0, MAP_PACIFIDLOG_TOWN_HOUSE4
	warp_def 17, 21, 0, 0, MAP_PACIFIDLOG_TOWN_HOUSE5

PacifidlogTown_MapBGEvents: @ 8527E60
	bg_event 9, 15, 0, BG_EVENT_PLAYER_FACING_NORTH, PacifidlogTown_EventScript_271E73
	bg_event 7, 16, 0, BG_EVENT_PLAYER_FACING_ANY, PacifidlogTown_EventScript_1EBADE
	bg_event 10, 15, 0, BG_EVENT_PLAYER_FACING_NORTH, PacifidlogTown_EventScript_271E73

PacifidlogTown_MapEvents:: @ 8527E84
	map_events PacifidlogTown_EventObjects, PacifidlogTown_MapWarps, 0x0, PacifidlogTown_MapBGEvents

