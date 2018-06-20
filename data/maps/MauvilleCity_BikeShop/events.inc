MauvilleCity_BikeShop_EventObjects: @ 852FE80
	object_event 1, EVENT_OBJ_GFX_MAN_2, 0, 2, 5, 3, 9, 0, 0, 0, 0, MauvilleCity_BikeShop_EventScript_20EBBC, 0
	object_event 2, EVENT_OBJ_GFX_MAN_6, 0, 7, 6, 3, 2, 1, 1, 0, 0, MauvilleCity_BikeShop_EventScript_20ED31, 0

MauvilleCity_BikeShop_MapWarps: @ 852FEB0
	warp_def 3, 8, 0, 2, MAP_MAUVILLE_CITY
	warp_def 4, 8, 0, 2, MAP_MAUVILLE_CITY

MauvilleCity_BikeShop_MapBGEvents: @ 852FEC0
	bg_event 8, 1, 0, 0, 0, MauvilleCity_BikeShop_EventScript_20ED3A
	bg_event 11, 1, 0, 0, 0, MauvilleCity_BikeShop_EventScript_20EDAE

MauvilleCity_BikeShop_MapEvents:: @ 852FED8
	map_events MauvilleCity_BikeShop_EventObjects, MauvilleCity_BikeShop_MapWarps, 0x0, MauvilleCity_BikeShop_MapBGEvents

