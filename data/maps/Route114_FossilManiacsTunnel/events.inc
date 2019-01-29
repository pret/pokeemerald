Route114_FossilManiacsTunnel_EventObjects:
	object_event 1, EVENT_OBJ_GFX_MANIAC, 0, 5, 3, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, Route114_FossilManiacsTunnel_EventScript_22AF87, 0

Route114_FossilManiacsTunnel_MapWarps:
	warp_def 6, 25, 3, 2, MAP_ROUTE114_FOSSIL_MANIACS_HOUSE
	warp_def 7, 25, 3, 2, MAP_ROUTE114_FOSSIL_MANIACS_HOUSE
	warp_def 6, 2, 0, 0, MAP_DESERT_UNDERPASS

Route114_FossilManiacsTunnel_MapCoordEvents:
	coord_event 5, 4, 3, VAR_0x40CC, 1, Route114_FossilManiacsTunnel_EventScript_22AF66
	coord_event 6, 4, 3, VAR_0x40CC, 1, Route114_FossilManiacsTunnel_EventScript_22AF66

Route114_FossilManiacsTunnel_MapEvents::
	map_events Route114_FossilManiacsTunnel_EventObjects, Route114_FossilManiacsTunnel_MapWarps, Route114_FossilManiacsTunnel_MapCoordEvents, 0x0

