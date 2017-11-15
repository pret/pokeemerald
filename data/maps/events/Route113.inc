Route113_MapObjects: @ 8529B2C
	object_event 1, MAP_OBJ_GFX_LITTLE_BOY_1, 0, 0, 66, 12, 3, 5, 1, 0, 0, 0, Route113_EventScript_1F2193, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_GENTLEMAN, 0, 0, 36, 10, 3, 3, 16, 0, 0, 0, Route113_EventScript_1F218A, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_YOUNGSTER, 0, 0, 62, 8, 3, 8, 0, 0, 1, 3, Route113_EventScript_1F21C0, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_YOUNGSTER, 0, 0, 21, 11, 3, 17, 0, 0, 1, 3, Route113_EventScript_1F21D7, 0, 0, 0
	object_event 5, MAP_OBJ_GFX_WOMAN_7, 0, 0, 51, 11, 3, 23, 0, 0, 1, 2, Route113_EventScript_1F21EE, 0, 0, 0
	object_event 6, MAP_OBJ_GFX_ITEM_BALL, 0, 0, 53, 7, 3, 1, 0, 0, 0, 0, Route113_EventScript_290DDC, 1012, 0, 0
	object_event 7, MAP_OBJ_GFX_ITEM_BALL, 0, 0, 79, 5, 3, 1, 0, 0, 0, 0, Route113_EventScript_290DE9, 1013, 0, 0
	object_event 8, MAP_OBJ_GFX_LITTLE_BOY_1, 0, 0, 29, 6, 3, 63, 0, 0, 3, 1, Route113_EventScript_1F2250, 0, 0, 0
	object_event 9, MAP_OBJ_GFX_LITTLE_BOY_1, 0, 0, 71, 2, 3, 63, 0, 0, 3, 1, Route113_EventScript_1F22B2, 0, 0, 0
	object_event 10, MAP_OBJ_GFX_LITTLE_GIRL_1, 0, 0, 45, 6, 3, 8, 17, 0, 1, 1, Route113_EventScript_1F22C9, 0, 0, 0
	object_event 11, MAP_OBJ_GFX_LITTLE_GIRL_1, 0, 0, 46, 6, 3, 8, 17, 0, 1, 1, Route113_EventScript_1F22E4, 0, 0, 0
	object_event 12, MAP_OBJ_GFX_ITEM_BALL, 0, 0, 15, 15, 3, 1, 17, 0, 0, 0, Route113_EventScript_290DF6, 1143, 0, 0
	object_event 13, MAP_OBJ_GFX_MANIAC, 0, 0, 75, 3, 3, 9, 17, 0, 1, 4, Route113_EventScript_1F2344, 0, 0, 0
	object_event 14, MAP_OBJ_GFX_CAMPER, 0, 0, 71, 4, 3, 7, 17, 0, 1, 1, Route113_EventScript_1F232D, 0, 0, 0
	object_event 15, MAP_OBJ_GFX_PICNICKER, 0, 0, 7, 6, 3, 26, 49, 0, 1, 6, Route113_EventScript_1F22FF, 0, 0, 0
	object_event 16, MAP_OBJ_GFX_MAN_6, 0, 0, 7, 13, 3, 25, 49, 0, 1, 6, Route113_EventScript_1F2316, 0, 0, 0

Route113_MapWarps: @ 8529CAC
	warp_def 33, 5, 0, 0, ROUTE_113_GLASS_WORKSHOP
	warp_def 41, 12, 0, 0, TERRA_CAVE_ENTRANCE
	warp_def 88, 5, 0, 0, TERRA_CAVE_ENTRANCE

Route113_MapCoordEvents: @ 8529CC4
	coord_event 19, 11, 3, 0, 8, 0, 0, 0x0
	coord_event 19, 10, 3, 0, 8, 0, 0, 0x0
	coord_event 19, 12, 3, 0, 8, 0, 0, 0x0
	coord_event 19, 13, 3, 0, 8, 0, 0, 0x0
	coord_event 86, 9, 3, 0, 8, 0, 0, 0x0
	coord_event 85, 10, 3, 0, 8, 0, 0, 0x0
	coord_event 85, 11, 3, 0, 8, 0, 0, 0x0
	coord_event 14, 10, 3, 0, 2, 0, 0, 0x0
	coord_event 14, 11, 3, 0, 2, 0, 0, 0x0
	coord_event 14, 12, 3, 0, 2, 0, 0, 0x0
	coord_event 14, 13, 3, 0, 2, 0, 0, 0x0
	coord_event 94, 8, 3, 0, 2, 0, 0, 0x0
	coord_event 94, 9, 3, 0, 2, 0, 0, 0x0
	coord_event 94, 10, 3, 0, 2, 0, 0, 0x0
	coord_event 94, 11, 0, 0, 2, 0, 0, 0x0
	coord_event 19, 14, 3, 0, 8, 0, 0, 0x0
	coord_event 87, 8, 3, 0, 8, 0, 0, 0x0
	coord_event 87, 6, 3, 0, 8, 0, 0, 0x0
	coord_event 87, 7, 3, 0, 8, 0, 0, 0x0

Route113_MapBGEvents: @ 8529DF4
	bg_event 85, 6, 0, 0, 0, Route113_EventScript_1F219C
	bg_event 12, 9, 0, 0, 0, Route113_EventScript_1F21A5
	bg_event 58, 4, 3, 0, 0, Route113_EventScript_1F21B7
	bg_event 31, 5, 0, 0, 0, Route113_EventScript_1F21AE
	bg_event 49, 8, 3, 8, 0, ITEM_GREAT_BALL, 0, 0
	bg_event 66, 3, 3, 7, 0, ITEM_ETHER, 3, 0
	bg_event 22, 5, 3, 7, 0, ITEM_TM32, 30, 0
	bg_event 73, 3, 3, 7, 0, ITEM_NUGGET, 98, 0

Route113_MapEvents:: @ 8529E54
	map_events Route113_MapObjects, Route113_MapWarps, Route113_MapCoordEvents, Route113_MapBGEvents

