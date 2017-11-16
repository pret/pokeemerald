Route106_MapObjects: @ 85287E4
	object_event 1, MAP_OBJ_GFX_SWIMMER_M, 0, 0, 18, 5, 1, 27, 4, 0, 1, 3, Route106_EventScript_1EE493, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_SWIMMER_F, 0, 0, 29, 10, 1, 1, 0, 0, 1, 3, Route106_EventScript_1EE4AA, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_FISHERMAN, 0, 0, 51, 14, 3, 10, 0, 0, 1, 4, Route106_EventScript_1EE4C1, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_FISHERMAN, 0, 0, 65, 14, 3, 1, 0, 0, 1, 3, Route106_EventScript_1EE523, 0, 0, 0
	object_event 5, MAP_OBJ_GFX_ITEM_BALL, 0, 0, 29, 14, 3, 1, 0, 0, 0, 0, Route106_EventScript_290D40, 1004, 0, 0

Route106_MapWarps: @ 852885C
	warp_def 48, 16, 0, 0, GRANITE_CAVE_1F

Route106_MapBGEvents: @ 8528864
	bg_event 41, 11, 3, 7, 0, ITEM_POKE_BALL, 63, 0
	bg_event 53, 12, 0, 7, 0, ITEM_STARDUST, 46, 0
	bg_event 68, 15, 3, 7, 0, ITEM_HEART_SCALE, 47, 0
	bg_event 59, 13, 3, 0, 0, Route106_EventScript_1EE48A

Route106_MapEvents:: @ 8528894
	map_events Route106_MapObjects, Route106_MapWarps, 0x0, Route106_MapBGEvents

