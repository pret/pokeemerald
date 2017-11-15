LilycoveCity_DepartmentStore_3F_MapObjects: @ 8532200
	object_event 1, MAP_OBJ_GFX_RUNNING_TRIATHLETE_M, 0, 0, 0, 5, 3, 2, 17, 0, 0, 0, LilycoveCity_DepartmentStore_3F_EventScript_21FCB6, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_MAN_3, 0, 0, 7, 7, 3, 2, 17, 0, 0, 0, LilycoveCity_DepartmentStore_3F_EventScript_21FCBF, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_WOMAN_7, 0, 0, 13, 5, 3, 2, 17, 0, 0, 0, LilycoveCity_DepartmentStore_3F_EventScript_21FCC8, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_WOMAN_4, 0, 0, 8, 2, 3, 8, 0, 0, 0, 0, LilycoveCity_DepartmentStore_3F_EventScript_21FC65, 0, 0, 0
	object_event 5, MAP_OBJ_GFX_WOMAN_4, 0, 0, 10, 2, 3, 8, 17, 0, 0, 0, LilycoveCity_DepartmentStore_3F_EventScript_21FC8C, 0, 0, 0

LilycoveCity_DepartmentStore_3F_MapWarps: @ 8532278
	warp_def 13, 1, 0, 1, LILYCOVE_CITY_DEPARTMENT_STORE_2F
	warp_def 16, 1, 0, 0, LILYCOVE_CITY_DEPARTMENT_STORE_4F
	warp_def 2, 1, 0, 0, LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR

LilycoveCity_DepartmentStore_3F_MapEvents:: @ 8532290
	map_events LilycoveCity_DepartmentStore_3F_MapObjects, LilycoveCity_DepartmentStore_3F_MapWarps, 0x0, 0x0

