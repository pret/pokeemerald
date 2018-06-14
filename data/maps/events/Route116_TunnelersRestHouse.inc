Route116_TunnelersRestHouse_EventObjects: @ 8533E34
	object_event 1, EVENT_OBJ_GFX_MAN_3, 0, 0, 6, 5, 3, 10, 0, 0, 0, 0, Route116_TunnelersRestHouse_EventScript_22B85A, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_MAN_3, 0, 0, 3, 6, 3, 1, 17, 0, 0, 0, Route116_TunnelersRestHouse_EventScript_22B86C, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_MAN_3, 0, 0, 7, 2, 3, 7, 1, 0, 0, 0, Route116_TunnelersRestHouse_EventScript_22B863, 0, 0, 0

Route116_TunnelersRestHouse_MapWarps: @ 8533E7C
	warp_def 4, 8, 0, 1, ROUTE_116
	warp_def 5, 8, 0, 1, ROUTE_116

Route116_TunnelersRestHouse_MapEvents:: @ 8533E8C
	map_events Route116_TunnelersRestHouse_EventObjects, Route116_TunnelersRestHouse_MapWarps, 0x0, 0x0

