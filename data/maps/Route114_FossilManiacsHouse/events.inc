Route114_FossilManiacsHouse_EventObjects:
	object_event 1, EVENT_OBJ_GFX_NINJA_BOY, 0, 3, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, Route114_FossilManiacsHouse_EventScript_22AD3A, 0

Route114_FossilManiacsHouse_MapWarps:
	warp_def 4, 7, 0, 1, MAP_ROUTE114
	warp_def 5, 7, 0, 1, MAP_ROUTE114
	warp_def 4, 1, 0, 0, MAP_ROUTE114_FOSSIL_MANIACS_TUNNEL

Route114_FossilManiacsHouse_MapBGEvents:
	bg_event 5, 3, 0, BG_EVENT_PLAYER_FACING_NORTH, Route114_FossilManiacsHouse_EventScript_22AD73
	bg_event 6, 3, 0, BG_EVENT_PLAYER_FACING_NORTH, Route114_FossilManiacsHouse_EventScript_22AD73
	bg_event 7, 2, 0, BG_EVENT_PLAYER_FACING_NORTH, Route114_FossilManiacsHouse_EventScript_22AD7C
	bg_event 8, 2, 0, BG_EVENT_PLAYER_FACING_NORTH, Route114_FossilManiacsHouse_EventScript_22AD7C

Route114_FossilManiacsHouse_MapEvents::
	map_events Route114_FossilManiacsHouse_EventObjects, Route114_FossilManiacsHouse_MapWarps, 0x0, Route114_FossilManiacsHouse_MapBGEvents

