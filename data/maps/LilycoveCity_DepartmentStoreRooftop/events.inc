LilycoveCity_DepartmentStoreRooftop_EventObjects: @ 853241C
	object_event 1, EVENT_OBJ_GFX_MAN_2, 0, 4, 4, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_220268, 0
	object_event 2, EVENT_OBJ_GFX_MAN_3, 0, 7, 5, 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT, 1, 0, 0, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_22028C, 0
	object_event 3, EVENT_OBJ_GFX_ROOFTOP_SALE_WOMAN, 0, 6, 1, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_22022F, FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN
	object_event 4, EVENT_OBJ_GFX_WOMAN_3, 0, 15, 5, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 0, 0, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_2C8186, 0

LilycoveCity_DepartmentStoreRooftop_MapWarps: @ 853247C
	warp_def 13, 3, 0, 2, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_5F

LilycoveCity_DepartmentStoreRooftop_MapBGEvents: @ 8532484
	bg_event 9, 1, 0, BG_EVENT_PLAYER_FACING_ANY, LilycoveCity_DepartmentStoreRooftop_EventScript_220295
	bg_event 10, 1, 0, BG_EVENT_PLAYER_FACING_ANY, LilycoveCity_DepartmentStoreRooftop_EventScript_220295

LilycoveCity_DepartmentStoreRooftop_MapEvents:: @ 853249C
	map_events LilycoveCity_DepartmentStoreRooftop_EventObjects, LilycoveCity_DepartmentStoreRooftop_MapWarps, 0x0, LilycoveCity_DepartmentStoreRooftop_MapBGEvents

