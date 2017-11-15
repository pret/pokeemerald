BattleFrontier_BattlePikeThreePathRoom_MapObjects: @ 853CC80
	object_event 1, MAP_OBJ_GFX_WOMAN_6, 0, 0, 4, 10, 3, 10, 0, 0, 0, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_25C908, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_WOMAN_6, 0, 0, 8, 5, 3, 8, 0, 0, 0, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_25CABB, 0, 0, 0

BattleFrontier_BattlePikeThreePathRoom_MapCoordEvents: @ 853CCB0
	coord_event 2, 3, 3, 0, VAR_0x4001, 0, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C3F4E
	coord_event 6, 3, 3, 0, VAR_0x4001, 0, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C3F59
	coord_event 10, 3, 3, 0, VAR_0x4001, 0, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C3F64
	coord_event 5, 10, 0, 0, VAR_0x4003, 1, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C406D
	coord_event 6, 10, 0, 0, VAR_0x4003, 1, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C406D
	coord_event 6, 9, 3, 0, VAR_0x4002, 0, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4062
	coord_event 5, 9, 3, 0, VAR_0x4002, 0, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4062
	coord_event 7, 9, 3, 0, VAR_0x4002, 0, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4062
	coord_event 7, 10, 0, 0, VAR_0x4003, 1, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C406D

BattleFrontier_BattlePikeThreePathRoom_MapEvents:: @ 853CD40
	map_events BattleFrontier_BattlePikeThreePathRoom_MapObjects, 0x0, BattleFrontier_BattlePikeThreePathRoom_MapCoordEvents, 0x0

