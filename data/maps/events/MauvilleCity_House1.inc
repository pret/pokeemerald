MauvilleCity_House1_EventObjects: @ 852FEEC
	object_event 1, EVENT_OBJ_GFX_SCIENTIST_1, 0, 4, 4, 3, 10, 0, 0, 0, MauvilleCity_House1_EventScript_20F976, 0

MauvilleCity_House1_MapWarps: @ 852FF04
	warp_def 3, 7, 0, 4, MAP_MAUVILLE_CITY
	warp_def 4, 7, 0, 4, MAP_MAUVILLE_CITY

MauvilleCity_House1_MapEvents:: @ 852FF14
	map_events MauvilleCity_House1_EventObjects, MauvilleCity_House1_MapWarps, 0x0, 0x0

