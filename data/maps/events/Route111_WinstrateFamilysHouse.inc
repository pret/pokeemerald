Route111_WinstrateFamilysHouse_EventObjects: @ 8533B94
	object_event 1, EVENT_OBJ_GFX_LASS, 0, 0, 7, 5, 3, 9, 0, 0, 0, 0, Route111_WinstrateFamilysHouse_EventScript_22A4E8, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_MAN_1, 0, 0, 4, 5, 3, 10, 0, 0, 0, 0, Route111_WinstrateFamilysHouse_EventScript_22A48D, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_WOMAN_2, 0, 0, 7, 4, 3, 9, 1, 0, 0, 0, Route111_WinstrateFamilysHouse_EventScript_22A4A2, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_OLD_WOMAN_1, 0, 0, 4, 4, 3, 10, 0, 0, 0, 0, Route111_WinstrateFamilysHouse_EventScript_22A4FD, 0, 0, 0

Route111_WinstrateFamilysHouse_MapWarps: @ 8533BF4
	warp_def 3, 7, 0, 0, ROUTE_111
	warp_def 4, 7, 0, 0, ROUTE_111

Route111_WinstrateFamilysHouse_MapEvents:: @ 8533C04
	map_events Route111_WinstrateFamilysHouse_EventObjects, Route111_WinstrateFamilysHouse_MapWarps, 0x0, 0x0

