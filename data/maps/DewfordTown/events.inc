DewfordTown_EventObjects: @ 8527964
	object_event 1, EVENT_OBJ_GFX_WOMAN_3, 0, 7, 12, 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT, 1, 0, 0, 0, DewfordTown_EventScript_1E95B1, 0
	object_event 2, EVENT_OBJ_GFX_OLD_MAN_1, 0, 12, 9, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 1, 0, 3, DewfordTown_EventScript_1E9511, 740
	object_event 3, EVENT_OBJ_GFX_FISHERMAN, 0, 12, 14, 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT, 1, 0, 0, 0, DewfordTown_EventScript_1E95D5, 0
	object_event 4, EVENT_OBJ_GFX_MR_BRINEYS_BOAT, 0, 12, 8, 1, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, 0x0, 743
	object_event 5, EVENT_OBJ_GFX_BOY_1, 0, 1, 6, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, DewfordTown_EventScript_1E9922, 0

DewfordTown_MapWarps: @ 85279DC
	warp_def 3, 3, 0, 0, MAP_DEWFORD_TOWN_HALL
	warp_def 2, 10, 0, 0, MAP_DEWFORD_TOWN_POKEMON_CENTER_1F
	warp_def 8, 17, 0, 0, MAP_DEWFORD_TOWN_GYM
	warp_def 17, 14, 0, 0, MAP_DEWFORD_TOWN_HOUSE1
	warp_def 8, 8, 0, 0, MAP_DEWFORD_TOWN_HOUSE2

DewfordTown_MapBGEvents: @ 8527A04
	bg_event 10, 10, 0, BG_EVENT_PLAYER_FACING_ANY, DewfordTown_EventScript_1E95BA
	bg_event 11, 16, 0, BG_EVENT_PLAYER_FACING_ANY, DewfordTown_EventScript_1E95C3
	bg_event 4, 10, 0, BG_EVENT_PLAYER_FACING_NORTH, DewfordTown_EventScript_271E73
	bg_event 3, 10, 0, BG_EVENT_PLAYER_FACING_NORTH, DewfordTown_EventScript_271E73
	bg_event 2, 4, 0, BG_EVENT_PLAYER_FACING_ANY, DewfordTown_EventScript_1E95CC

DewfordTown_MapEvents:: @ 8527A40
	map_events DewfordTown_EventObjects, DewfordTown_MapWarps, 0x0, DewfordTown_MapBGEvents

