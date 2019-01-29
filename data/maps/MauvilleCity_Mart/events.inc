MauvilleCity_Mart_EventObjects:
	object_event 1, EVENT_OBJ_GFX_MART_EMPLOYEE, 0, 1, 3, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, MauvilleCity_Mart_EventScript_2110E6, 0
	object_event 2, EVENT_OBJ_GFX_EXPERT_M, 0, 5, 4, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, MauvilleCity_Mart_EventScript_21111C, 0
	object_event 3, EVENT_OBJ_GFX_MAN_3, 0, 5, 5, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, MauvilleCity_Mart_EventScript_211125, 0

MauvilleCity_Mart_MapWarps:
	warp_def 3, 7, 0, 3, MAP_MAUVILLE_CITY
	warp_def 4, 7, 0, 3, MAP_MAUVILLE_CITY

MauvilleCity_Mart_MapEvents::
	map_events MauvilleCity_Mart_EventObjects, MauvilleCity_Mart_MapWarps, 0x0, 0x0

