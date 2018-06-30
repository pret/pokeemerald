Route125_EventObjects: @ 852C50C
	object_event 1, EVENT_OBJ_GFX_SWIMMER_M, 0, 7, 31, 1, 28, 0, 0, 1, 2, Route125_EventScript_1F67A4, 0
	object_event 2, EVENT_OBJ_GFX_SWIMMER_M, 0, 45, 9, 1, 10, 2, 5, 1, 2, Route125_EventScript_1F67BB, 0
	object_event 3, EVENT_OBJ_GFX_SWIMMER_F, 0, 38, 24, 1, 28, 6, 0, 1, 3, Route125_EventScript_1F67D2, 0
	object_event 4, EVENT_OBJ_GFX_SWIMMER_F, 0, 30, 28, 1, 52, 9, 9, 1, 3, Route125_EventScript_1F67E9, 0
	object_event 5, EVENT_OBJ_GFX_SAILOR, 0, 21, 30, 3, 13, 0, 0, 1, 2, Route125_EventScript_1F6800, 0
	object_event 6, EVENT_OBJ_GFX_LASS, 0, 17, 19, 3, 8, 1, 1, 1, 1, Route125_EventScript_1F6862, 0
	object_event 7, EVENT_OBJ_GFX_LASS, 0, 18, 19, 3, 8, 1, 1, 1, 1, Route125_EventScript_1F687D, 0
	object_event 8, EVENT_OBJ_GFX_MAN_6, 0, 43, 19, 3, 28, 2, 1, 1, 3, Route125_EventScript_1F6898, 0
	object_event 9, EVENT_OBJ_GFX_OLD_MAN_1, 0, 48, 19, 3, 27, 2, 1, 1, 3, Route125_EventScript_1F68AF, 0
	object_event 10, EVENT_OBJ_GFX_ITEM_BALL, 0, 46, 17, 3, 1, 1, 1, 0, 0, Route125_EventScript_291018, 1154

Route125_MapWarps: @ 852C5FC
	warp_def 22, 19, 0, 0, MAP_SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM

Route125_MapBGEvents: @ 852C604
	bg_event 53, 10, 0, 8, 0, ITEM_ULTRA_BALL, 0, 0
	bg_event 55, 11, 0, 8, 0, ITEM_HEAL_POWDER, 0, 0
	bg_event 7, 25, 0, 8, 0, ITEM_RETRO_MAIL, 0, 0
	bg_event 24, 32, 0, 8, 0, ITEM_PINAP_BERRY, 0, 0

Route125_MapEvents:: @ 852C634
	map_events Route125_EventObjects, Route125_MapWarps, 0x0, Route125_MapBGEvents

