Route114_FossilManiacsTunnel_MapObjects: @ 8533D70
	object_event 1, MAP_OBJ_GFX_MANIAC, 0, 0, 5, 3, 3, 7, 17, 0, 0, 0, Route114_FossilManiacsTunnel_EventScript_22AF87, 0, 0, 0

Route114_FossilManiacsTunnel_MapWarps: @ 8533D88
	warp_def 6, 25, 3, 2, ROUTE_114_FOSSIL_MANIACS_HOUSE
	warp_def 7, 25, 3, 2, ROUTE_114_FOSSIL_MANIACS_HOUSE
	warp_def 6, 2, 0, 0, DESERT_UNDERPASS

Route114_FossilManiacsTunnel_MapCoordEvents: @ 8533DA0
	coord_event 5, 4, 3, 0, VAR_0x40CC, 1, 0, Route114_FossilManiacsTunnel_EventScript_22AF66
	coord_event 6, 4, 3, 0, VAR_0x40CC, 1, 0, Route114_FossilManiacsTunnel_EventScript_22AF66

Route114_FossilManiacsTunnel_MapEvents:: @ 8533DC0
	map_events Route114_FossilManiacsTunnel_MapObjects, Route114_FossilManiacsTunnel_MapWarps, Route114_FossilManiacsTunnel_MapCoordEvents, 0x0

