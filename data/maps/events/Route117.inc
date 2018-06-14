Route117_EventObjects: @ 852A828
	object_event 1, EVENT_OBJ_GFX_WOMAN_1, 0, 0, 13, 13, 3, 8, 0, 0, 0, 0, Route117_EventScript_1F399A, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_LITTLE_BOY_2, 0, 0, 25, 5, 3, 40, 34, 0, 0, 0, Route117_EventScript_1F39A3, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_OLD_MAN_2, 0, 0, 47, 4, 3, 8, 0, 0, 0, 0, Route117_EventScript_291C18, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_ZIGZAGOON_2, 0, 0, 33, 3, 3, 1, 17, 0, 0, 0, 0x0, 0, 0, 0
	object_event 5, EVENT_OBJ_GFX_KECLEON_1, 0, 0, 39, 4, 3, 1, 0, 0, 0, 0, 0x0, 0, 0, 0
	object_event 6, EVENT_OBJ_GFX_AZUMARILL, 0, 0, 42, 2, 3, 1, 17, 0, 0, 0, 0x0, 0, 0, 0
	object_event 7, EVENT_OBJ_GFX_PIKACHU, 0, 0, 49, 2, 3, 1, 0, 0, 0, 0, 0x0, 0, 0, 0
	object_event 8, EVENT_OBJ_GFX_RUNNING_TRIATHLETE_M, 0, 0, 38, 16, 3, 28, 8, 0, 1, 4, Route117_EventScript_1F3A94, 0, 0, 0
	object_event 9, EVENT_OBJ_GFX_WOMAN_3, 0, 0, 8, 10, 3, 23, 0, 0, 1, 3, Route117_EventScript_1F3A32, 0, 0, 0
	object_event 10, EVENT_OBJ_GFX_MAN_5, 0, 0, 33, 11, 3, 16, 0, 0, 1, 4, Route117_EventScript_1F39D0, 0, 0, 0
	object_event 11, EVENT_OBJ_GFX_BERRY_TREE, 0, 0, 41, 13, 3, 12, 0, 0, 0, 29, BerryTreeScript, 0, 0, 0
	object_event 12, EVENT_OBJ_GFX_BERRY_TREE, 0, 0, 42, 13, 3, 12, 0, 0, 0, 28, BerryTreeScript, 0, 0, 0
	object_event 13, EVENT_OBJ_GFX_BERRY_TREE, 0, 0, 43, 13, 3, 12, 0, 0, 0, 27, BerryTreeScript, 0, 0, 0
	object_event 14, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 16, 18, 3, 1, 0, 0, 0, 0, Route117_EventScript_290EB9, 1022, 0, 0
	object_event 15, EVENT_OBJ_GFX_CUTTABLE_TREE, 0, 0, 15, 2, 3, 1, 0, 0, 0, 0, Route117_EventScript_2906BB, 17, 0, 0
	object_event 16, EVENT_OBJ_GFX_ITEM_BALL, 0, 0, 9, 1, 3, 1, 0, 0, 0, 0, Route117_EventScript_290EC6, 1023, 0, 0
	object_event 17, EVENT_OBJ_GFX_RUNNING_TRIATHLETE_F, 0, 0, 26, 13, 3, 33, 34, 0, 1, 5, Route117_EventScript_1F3AF6, 0, 0, 0
	object_event 18, EVENT_OBJ_GFX_MANIAC, 0, 0, 17, 12, 3, 7, 17, 0, 1, 4, Route117_EventScript_1F3B58, 0, 0, 0
	object_event 19, EVENT_OBJ_GFX_LASS, 0, 0, 43, 6, 3, 8, 0, 0, 1, 1, Route117_EventScript_1F3BD3, 0, 0, 0
	object_event 20, EVENT_OBJ_GFX_LASS, 0, 0, 42, 6, 3, 8, 0, 0, 1, 1, Route117_EventScript_1F3B6F, 0, 0, 0
	object_event 21, EVENT_OBJ_GFX_GIRL_2, 0, 0, 48, 10, 3, 2, 17, 0, 0, 0, Route117_EventScript_1F39AC, 0, 0, 0
	object_event 22, EVENT_OBJ_GFX_LASS, 0, 0, 15, 4, 3, 10, 17, 0, 1, 4, Route117_EventScript_1F3C4E, 0, 0, 0
	object_event 23, EVENT_OBJ_GFX_GIRL_3, 0, 0, 21, 4, 3, 9, 17, 0, 1, 4, Route117_EventScript_1F3C65, 0, 0, 0
	object_event 24, EVENT_OBJ_GFX_RUNNING_TRIATHLETE_F, 0, 0, 16, 4, 3, 28, 20, 0, 1, 4, Route117_EventScript_1F3C37, 0, 0, 0

Route117_MapWarps: @ 852AA68
	warp_def 51, 5, 0, 0, ROUTE_117_POKEMON_DAY_CARE

Route117_MapBGEvents: @ 852AA70
	bg_event 16, 6, 0, 0, 0, Route117_EventScript_1F39B5
	bg_event 49, 12, 0, 0, 0, Route117_EventScript_1F39BE
	bg_event 49, 5, 0, 0, 0, Route117_EventScript_1F39C7
	bg_event 3, 18, 3, 7, 0, ITEM_REPEL, 72, 0

Route117_MapEvents:: @ 852AAA0
	map_events Route117_EventObjects, Route117_MapWarps, 0x0, Route117_MapBGEvents

