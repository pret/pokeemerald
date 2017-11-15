MauvilleCity_Mart_MapObjects: @ 8530310
	object_event 1, MAP_OBJ_GFX_MART_EMPLOYEE, 0, 0, 1, 3, 3, 10, 0, 0, 0, 0, MauvilleCity_Mart_EventScript_2110E6, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_OLD_MAN_1, 0, 0, 5, 4, 3, 10, 0, 0, 0, 0, MauvilleCity_Mart_EventScript_21111C, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_MAN_4, 0, 0, 5, 5, 3, 10, 0, 0, 0, 0, MauvilleCity_Mart_EventScript_211125, 0, 0, 0

MauvilleCity_Mart_MapWarps: @ 8530358
	warp_def 3, 7, 0, 3, MAUVILLE_CITY
	warp_def 4, 7, 0, 3, MAUVILLE_CITY

MauvilleCity_Mart_MapEvents:: @ 8530368
	map_events MauvilleCity_Mart_MapObjects, MauvilleCity_Mart_MapWarps, 0x0, 0x0

