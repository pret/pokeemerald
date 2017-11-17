Route127_MapObjects: @ 852C734
	object_event 1, MAP_OBJ_GFX_SWIMMER_M, 0, 0, 45, 42, 1, 14, 0, 0, 1, 2, Route127_EventScript_1F6A35, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_SWIMMER_F, 0, 0, 18, 68, 1, 21, 0, 0, 1, 4, Route127_EventScript_1F6A4C, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_ITEM_BALL, 0, 0, 14, 6, 3, 1, 0, 0, 0, 0, Route127_EventScript_291032, 1034, 0, 0
	object_event 4, MAP_OBJ_GFX_ITEM_BALL, 0, 0, 64, 39, 3, 1, 0, 0, 0, 0, Route127_EventScript_29103F, 1035, 0, 0
	object_event 5, MAP_OBJ_GFX_FISHERMAN, 0, 0, 42, 21, 3, 9, 17, 0, 1, 0, Route127_EventScript_1F6A63, 0, 0, 0
	object_event 6, MAP_OBJ_GFX_FISHERMAN, 0, 0, 64, 19, 3, 10, 17, 0, 1, 0, Route127_EventScript_1F6A91, 0, 0, 0
	object_event 7, MAP_OBJ_GFX_FISHERMAN, 0, 0, 54, 14, 3, 7, 17, 0, 1, 0, Route127_EventScript_1F6A7A, 0, 0, 0
	object_event 8, MAP_OBJ_GFX_MAN_6, 0, 0, 15, 23, 3, 9, 17, 0, 1, 2, Route127_EventScript_1F6AA8, 0, 0, 0
	object_event 9, MAP_OBJ_GFX_BLACK_BELT, 0, 0, 63, 63, 3, 1, 17, 0, 1, 3, Route127_EventScript_1F6AD6, 0, 0, 0
	object_event 10, MAP_OBJ_GFX_WOMAN_7, 0, 0, 12, 23, 3, 10, 17, 0, 1, 2, Route127_EventScript_1F6ABF, 0, 0, 0
	object_event 11, MAP_OBJ_GFX_ITEM_BALL, 0, 0, 13, 20, 3, 1, 0, 0, 0, 0, Route127_EventScript_29104C, 1155, 0, 0

Route127_MapBGEvents: @ 852C83C
	bg_event 59, 67, 0, 8, 0, ITEM_ENERGY_ROOT, 0, 0
	bg_event 59, 72, 0, 8, 0, ITEM_SITRUS_BERRY, 0, 0
	bg_event 67, 63, 0, 8, 0, ITEM_WEPEAR_BERRY, 0, 0
	bg_event 61, 21, 0, 8, 0, ITEM_FIGY_BERRY, 0, 0
	bg_event 45, 24, 0, 8, 0, ITEM_GLITTER_MAIL, 0, 0

Route127_MapEvents:: @ 852C878
	map_events Route127_MapObjects, 0x0, 0x0, Route127_MapBGEvents

