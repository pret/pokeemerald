LilycoveCity_DepartmentStore_3F_EventObjects: @ 8532200
	object_event 1, EVENT_OBJ_GFX_RUNNING_TRIATHLETE_M, 0, 0, 5, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, LilycoveCity_DepartmentStore_3F_EventScript_21FCB6, 0
	object_event 2, EVENT_OBJ_GFX_POKEFAN_M, 0, 7, 7, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, LilycoveCity_DepartmentStore_3F_EventScript_21FCBF, 0
	object_event 3, EVENT_OBJ_GFX_WOMAN_5, 0, 13, 5, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, LilycoveCity_DepartmentStore_3F_EventScript_21FCC8, 0
	object_event 4, EVENT_OBJ_GFX_WOMAN_3, 0, 8, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, LilycoveCity_DepartmentStore_3F_EventScript_21FC65, 0
	object_event 5, EVENT_OBJ_GFX_WOMAN_3, 0, 10, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, LilycoveCity_DepartmentStore_3F_EventScript_21FC8C, 0

LilycoveCity_DepartmentStore_3F_MapWarps: @ 8532278
	warp_def 13, 1, 0, 1, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_2F
	warp_def 16, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_4F
	warp_def 2, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR

LilycoveCity_DepartmentStore_3F_MapEvents:: @ 8532290
	map_events LilycoveCity_DepartmentStore_3F_EventObjects, LilycoveCity_DepartmentStore_3F_MapWarps, 0x0, 0x0

