NewMauville_Entrance_MapWarps: @ 8536474
	warp_def 4, 6, 3, 0, MAP_ROUTE110
	warp_def 4, 1, 3, 0, MAP_NEW_MAUVILLE_INSIDE

NewMauville_Entrance_MapCoordEvents: @ 8536484
	coord_event 4, 2, 3, VAR_0x40BA, 0, NewMauville_Entrance_EventScript_2372FF

NewMauville_Entrance_MapEvents:: @ 8536494
	map_events 0x0, NewMauville_Entrance_MapWarps, NewMauville_Entrance_MapCoordEvents, 0x0

