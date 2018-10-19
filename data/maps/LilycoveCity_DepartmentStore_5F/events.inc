LilycoveCity_DepartmentStore_5F_EventObjects: @ 8532348
	object_event 1, EVENT_OBJ_GFX_LITTLE_GIRL, 0, 1, 6, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, LilycoveCity_DepartmentStore_5F_EventScript_2200BC, 0
	object_event 2, EVENT_OBJ_GFX_POKEFAN_F, 0, 7, 7, 3, MOVEMENT_TYPE_FACE_DOWN_AND_LEFT, 1, 1, 0, 0, LilycoveCity_DepartmentStore_5F_EventScript_22006C, 0
	object_event 3, EVENT_OBJ_GFX_WOMAN_3, 0, 7, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, LilycoveCity_DepartmentStore_5F_EventScript_21FFA6, 0
	object_event 4, EVENT_OBJ_GFX_WOMAN_3, 0, 9, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, LilycoveCity_DepartmentStore_5F_EventScript_21FFDC, 0
	object_event 5, EVENT_OBJ_GFX_WOMAN_3, 0, 15, 6, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, LilycoveCity_DepartmentStore_5F_EventScript_22000A, 0
	object_event 6, EVENT_OBJ_GFX_WOMAN_3, 0, 17, 6, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, LilycoveCity_DepartmentStore_5F_EventScript_22003A, 0
	object_event 7, EVENT_OBJ_GFX_WOMAN_2, 0, 9, 5, 3, MOVEMENT_TYPE_FACE_RIGHT, 1, 1, 0, 0, LilycoveCity_DepartmentStore_5F_EventScript_220075, 0

LilycoveCity_DepartmentStore_5F_MapWarps: @ 85323F0
	warp_def 13, 1, 0, 1, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_4F
	warp_def 2, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR
	warp_def 16, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP

LilycoveCity_DepartmentStore_5F_MapEvents:: @ 8532408
	map_events LilycoveCity_DepartmentStore_5F_EventObjects, LilycoveCity_DepartmentStore_5F_MapWarps, 0x0, 0x0

