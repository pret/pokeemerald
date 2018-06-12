LilycoveCity_DepartmentStore_4F_EventObjects: @ 85322A4
	object_event 1, EVENT_OBJ_GFX_GENTLEMAN, 0, 0, 0, 2, 3, 2, 17, 0, 0, 0, LilycoveCity_DepartmentStore_4F_EventScript_21FDEB, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_WOMAN_3, 0, 0, 6, 2, 3, 2, 17, 0, 0, 0, LilycoveCity_DepartmentStore_4F_EventScript_21FDF4, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_YOUNGSTER, 0, 0, 13, 4, 3, 2, 17, 0, 0, 0, LilycoveCity_DepartmentStore_4F_EventScript_21FDFD, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_WOMAN_4, 0, 0, 7, 6, 3, 7, 0, 0, 0, 0, LilycoveCity_DepartmentStore_4F_EventScript_21FE06, 0, 0, 0
	object_event 5, EVENT_OBJ_GFX_WOMAN_4, 0, 0, 9, 6, 3, 7, 0, 0, 0, 0, LilycoveCity_DepartmentStore_4F_EventScript_21FE2C, 0, 0, 0

LilycoveCity_DepartmentStore_4F_MapWarps: @ 853231C
	warp_def 16, 1, 0, 1, LILYCOVE_CITY_DEPARTMENT_STORE_3F
	warp_def 13, 1, 0, 0, LILYCOVE_CITY_DEPARTMENT_STORE_5F
	warp_def 2, 1, 0, 0, LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR

LilycoveCity_DepartmentStore_4F_MapEvents:: @ 8532334
	map_events LilycoveCity_DepartmentStore_4F_EventObjects, LilycoveCity_DepartmentStore_4F_MapWarps, 0x0, 0x0

