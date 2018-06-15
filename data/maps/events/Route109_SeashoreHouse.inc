Route109_SeashoreHouse_EventObjects: @ 853DDE8
	object_event 1, EVENT_OBJ_GFX_MAN_3, 0, 0, 6, 2, 3, 8, 0, 0, 0, 0, Route109_SeashoreHouse_EventScript_2693FE, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_SAILOR, 0, 0, 2, 3, 3, 8, 0, 0, 1, 2, Route109_SeashoreHouse_EventScript_2694E2, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_TUBER_M, 0, 0, 14, 9, 3, 9, 0, 0, 1, 2, Route109_SeashoreHouse_EventScript_269518, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_BEAUTY, 0, 0, 10, 5, 3, 14, 0, 0, 1, 2, Route109_SeashoreHouse_EventScript_2694FD, 0, 0, 0

Route109_SeashoreHouse_MapWarps: @ 853DE48
	warp_def 6, 9, 0, 0, MAP_ROUTE109
	warp_def 7, 9, 0, 0, MAP_ROUTE109

Route109_SeashoreHouse_MapEvents:: @ 853DE58
	map_events Route109_SeashoreHouse_EventObjects, Route109_SeashoreHouse_MapWarps, 0x0, 0x0

