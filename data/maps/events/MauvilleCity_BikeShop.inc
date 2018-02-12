MauvilleCity_BikeShop_MapObjects: @ 852FE80
	object_event 1, MAP_OBJ_GFX_MAN_2, 0, 0, 2, 5, 3, 9, 0, 0, 0, 0, MauvilleCity_BikeShop_EventScript_20EBBC, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_MAN_6, 0, 0, 7, 6, 3, 2, 17, 0, 0, 0, MauvilleCity_BikeShop_EventScript_20ED31, 0, 0, 0

MauvilleCity_BikeShop_MapWarps: @ 852FEB0
	warp_def 3, 8, 0, 2, MAUVILLE_CITY
	warp_def 4, 8, 0, 2, MAUVILLE_CITY

MauvilleCity_BikeShop_MapBGEvents: @ 852FEC0
	bg_event 8, 1, 0, 0, 0, MauvilleCity_BikeShop_EventScript_20ED3A
	bg_event 11, 1, 0, 0, 0, MauvilleCity_BikeShop_EventScript_20EDAE

MauvilleCity_BikeShop_MapEvents:: @ 852FED8
	map_events MauvilleCity_BikeShop_MapObjects, MauvilleCity_BikeShop_MapWarps, 0x0, MauvilleCity_BikeShop_MapBGEvents

