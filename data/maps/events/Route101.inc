Route101_MapObjects: @ 8527E98
	object_event 1, MAP_OBJ_GFX_YOUNGSTER, 0, 0, 16, 8, 3, 1, 0, 0, 0, 0, Route101_EventScript_1EBDFB, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_PROF_BIRCH, 0, 0, 9, 13, 0, 71, 0, 0, 0, 0, 0x0, 720, 0, 0
	object_event 3, MAP_OBJ_GFX_BIRCHS_BAG, 0, 0, 7, 14, 3, 1, 0, 0, 0, 0, Route101_EventScript_1EBE16, 700, 0, 0
	object_event 4, MAP_OBJ_GFX_ZIGZAGOON_1, 0, 0, 10, 13, 0, 70, 0, 0, 0, 0, 0x0, 750, 0, 0
	object_event 5, MAP_OBJ_GFX_PROF_BIRCH, 0, 0, 5, 11, 3, 1, 0, 0, 0, 0, Route101_EventScript_272141, 897, 0, 0
	object_event 6, MAP_OBJ_GFX_BOY_2, 0, 0, 2, 13, 3, 5, 17, 0, 0, 0, Route101_EventScript_1EBE04, 991, 0, 0

Route101_MapCoordEvents: @ 8527F28
	coord_event 10, 19, 3, 0, VAR_0x4060, 1, 0, Route101_EventScript_1EBCDE
	coord_event 11, 19, 3, 0, VAR_0x4060, 1, 0, Route101_EventScript_1EBCDE
	coord_event 10, 18, 3, 0, VAR_0x4060, 2, 0, Route101_EventScript_1EBD4E
	coord_event 11, 18, 3, 0, VAR_0x4060, 2, 0, Route101_EventScript_1EBD4E
	coord_event 6, 16, 3, 0, VAR_0x4060, 2, 0, Route101_EventScript_1EBD64
	coord_event 6, 15, 3, 0, VAR_0x4060, 2, 0, Route101_EventScript_1EBD64
	coord_event 6, 17, 3, 0, VAR_0x4060, 2, 0, Route101_EventScript_1EBD64
	coord_event 6, 18, 3, 0, VAR_0x4060, 2, 0, Route101_EventScript_1EBD64
	coord_event 7, 13, 3, 0, VAR_0x4060, 2, 0, Route101_EventScript_1EBD7A

Route101_MapBGEvents: @ 8527FB8
	bg_event 5, 9, 0, 0, 0, Route101_EventScript_1EBE0D

Route101_MapEvents:: @ 8527FC4
	map_events Route101_MapObjects, 0x0, Route101_MapCoordEvents, Route101_MapBGEvents

