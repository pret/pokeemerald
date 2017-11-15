Route114_FossilManiacsHouse_MapObjects: @ 8533CFC
	object_event 1, MAP_OBJ_GFX_LITTLE_BOY_1, 0, 0, 3, 2, 3, 8, 17, 0, 0, 0, Route114_FossilManiacsHouse_EventScript_22AD3A, 0, 0, 0

Route114_FossilManiacsHouse_MapWarps: @ 8533D14
	warp_def 4, 7, 0, 1, ROUTE_114
	warp_def 5, 7, 0, 1, ROUTE_114
	warp_def 4, 1, 0, 0, ROUTE_114_FOSSIL_MANIACS_TUNNEL

Route114_FossilManiacsHouse_MapBGEvents: @ 8533D2C
	bg_event 5, 3, 0, 1, 0, Route114_FossilManiacsHouse_EventScript_22AD73
	bg_event 6, 3, 0, 1, 0, Route114_FossilManiacsHouse_EventScript_22AD73
	bg_event 7, 2, 0, 1, 0, Route114_FossilManiacsHouse_EventScript_22AD7C
	bg_event 8, 2, 0, 1, 0, Route114_FossilManiacsHouse_EventScript_22AD7C

Route114_FossilManiacsHouse_MapEvents:: @ 8533D5C
	map_events Route114_FossilManiacsHouse_MapObjects, Route114_FossilManiacsHouse_MapWarps, 0x0, Route114_FossilManiacsHouse_MapBGEvents

