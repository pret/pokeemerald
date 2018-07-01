LilycoveCity_DepartmentStore_1F_EventObjects: @ 853208C
	object_event 1, EVENT_OBJ_GFX_BEAUTY, 0, 8, 2, 3, 8, 0, 0, 0, 0, LilycoveCity_DepartmentStore_1F_EventScript_21F693, 0
	object_event 2, EVENT_OBJ_GFX_BEAUTY, 0, 10, 2, 3, 8, 0, 0, 0, 0, LilycoveCity_DepartmentStore_1F_EventScript_21F69C, 0
	object_event 3, EVENT_OBJ_GFX_WOMAN_2, 0, 14, 5, 3, 2, 1, 1, 0, 0, LilycoveCity_DepartmentStore_1F_EventScript_21F82F, 0
	object_event 4, EVENT_OBJ_GFX_LITTLE_GIRL_2, 0, 4, 4, 3, 2, 1, 1, 0, 0, LilycoveCity_DepartmentStore_1F_EventScript_21F838, 0
	object_event 5, EVENT_OBJ_GFX_MAN_3, 0, 3, 6, 3, 1, 1, 1, 0, 0, LilycoveCity_DepartmentStore_1F_EventScript_21F841, 0
	object_event 6, EVENT_OBJ_GFX_AZUMARILL, 0, 2, 6, 3, 1, 1, 1, 0, 0, LilycoveCity_DepartmentStore_1F_EventScript_21F84A, 0

LilycoveCity_DepartmentStore_1F_MapWarps: @ 853211C
	warp_def 8, 7, 0, 0, MAP_LILYCOVE_CITY
	warp_def 9, 7, 0, 0, MAP_LILYCOVE_CITY
	warp_def 16, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_2F
	warp_def 2, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR

LilycoveCity_DepartmentStore_1F_MapBGEvents: @ 853213C
	bg_event 0, 8, 0, 1, 0, LilycoveCity_DepartmentStore_1F_EventScript_21F85D

LilycoveCity_DepartmentStore_1F_MapEvents:: @ 8532148
	map_events LilycoveCity_DepartmentStore_1F_EventObjects, LilycoveCity_DepartmentStore_1F_MapWarps, 0x0, LilycoveCity_DepartmentStore_1F_MapBGEvents

