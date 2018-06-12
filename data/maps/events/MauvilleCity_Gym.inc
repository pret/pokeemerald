MauvilleCity_Gym_EventObjects: @ 852FD5C
	object_event 1, EVENT_OBJ_GFX_WATTSON, 0, 0, 5, 2, 0, 8, 0, 0, 0, 0, MauvilleCity_Gym_EventScript_20DEEB, 913, 0, 0
	object_event 2, EVENT_OBJ_GFX_MAN_6, 0, 0, 7, 8, 3, 8, 0, 0, 1, 1, MauvilleCity_Gym_EventScript_20E0D0, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_GIRL_3, 0, 0, 1, 16, 0, 7, 0, 0, 1, 2, MauvilleCity_Gym_EventScript_20E0FE, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_YOUNGSTER, 0, 0, 5, 10, 0, 9, 0, 0, 1, 2, MauvilleCity_Gym_EventScript_20E0E7, 0, 0, 0
	object_event 5, EVENT_OBJ_GFX_MAN_6, 0, 0, 1, 13, 0, 8, 0, 0, 1, 2, MauvilleCity_Gym_EventScript_20E0B9, 0, 0, 0
	object_event 6, EVENT_OBJ_GFX_MAN_2, 0, 0, 7, 20, 0, 9, 0, 0, 0, 0, MauvilleCity_Gym_EventScript_20E12C, 0, 0, 0
	object_event 7, EVENT_OBJ_GFX_MANIAC, 0, 0, 7, 10, 3, 7, 17, 0, 1, 1, MauvilleCity_Gym_EventScript_20E115, 0, 0, 0

MauvilleCity_Gym_MapWarps: @ 852FE04
	warp_def 4, 20, 0, 0, MAUVILLE_CITY
	warp_def 5, 20, 0, 0, MAUVILLE_CITY

MauvilleCity_Gym_MapCoordEvents: @ 852FE14
	coord_event 4, 12, 3, 0, VAR_TEMP_0, 0, 0, MauvilleCity_Gym_EventScript_20E01E
	coord_event 3, 9, 3, 0, VAR_TEMP_0, 0, 0, MauvilleCity_Gym_EventScript_20E043
	coord_event 0, 15, 3, 0, VAR_TEMP_0, 0, 0, MauvilleCity_Gym_EventScript_20DFF9
	coord_event 8, 9, 3, 0, VAR_TEMP_0, 0, 0, MauvilleCity_Gym_EventScript_20E068

MauvilleCity_Gym_MapBGEvents: @ 852FE54
	bg_event 3, 18, 0, 1, 0, MauvilleCity_Gym_EventScript_20E14B
	bg_event 6, 18, 0, 1, 0, MauvilleCity_Gym_EventScript_20E15B

MauvilleCity_Gym_MapEvents:: @ 852FE6C
	map_events MauvilleCity_Gym_EventObjects, MauvilleCity_Gym_MapWarps, MauvilleCity_Gym_MapCoordEvents, MauvilleCity_Gym_MapBGEvents

