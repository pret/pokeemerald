LilycoveCity_DepartmentStore_2F_EventObjects: @ 853215C
	object_event 1, EVENT_OBJ_GFX_COOK, 0, 8, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, LilycoveCity_DepartmentStore_2F_EventScript_21FB2D, 0
	object_event 2, EVENT_OBJ_GFX_POKEFAN_F, 0, 0, 5, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, LilycoveCity_DepartmentStore_2F_EventScript_21FB36, 0
	object_event 3, EVENT_OBJ_GFX_SAILOR, 0, 13, 5, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, LilycoveCity_DepartmentStore_2F_EventScript_21FB3F, 0
	object_event 4, EVENT_OBJ_GFX_WOMAN_3, 0, 10, 6, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, LilycoveCity_DepartmentStore_2F_EventScript_21FB7A, 0
	object_event 5, EVENT_OBJ_GFX_WOMAN_3, 0, 7, 6, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, LilycoveCity_DepartmentStore_2F_EventScript_21FB48, 0

LilycoveCity_DepartmentStore_2F_MapWarps: @ 85321D4
	warp_def 16, 1, 0, 2, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_1F
	warp_def 13, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_3F
	warp_def 2, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR

LilycoveCity_DepartmentStore_2F_MapEvents:: @ 85321EC
	map_events LilycoveCity_DepartmentStore_2F_EventObjects, LilycoveCity_DepartmentStore_2F_MapWarps, 0x0, 0x0

