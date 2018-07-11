BattleFrontier_BattlePikeThreePathRoom_EventObjects: @ 853CC80
	object_event 1, EVENT_OBJ_GFX_WOMAN_6, 0, 4, 10, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_25C908, 0
	object_event 2, EVENT_OBJ_GFX_WOMAN_6, 0, 8, 5, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_25CABB, 0

BattleFrontier_BattlePikeThreePathRoom_MapCoordEvents: @ 853CCB0
	coord_event 2, 3, 3, VAR_TEMP_1, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C3F4E
	coord_event 6, 3, 3, VAR_TEMP_1, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C3F59
	coord_event 10, 3, 3, VAR_TEMP_1, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C3F64
	coord_event 5, 10, 0, VAR_TEMP_3, 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C406D
	coord_event 6, 10, 0, VAR_TEMP_3, 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C406D
	coord_event 6, 9, 3, VAR_TEMP_2, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4062
	coord_event 5, 9, 3, VAR_TEMP_2, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4062
	coord_event 7, 9, 3, VAR_TEMP_2, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4062
	coord_event 7, 10, 0, VAR_TEMP_3, 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C406D

BattleFrontier_BattlePikeThreePathRoom_MapEvents:: @ 853CD40
	map_events BattleFrontier_BattlePikeThreePathRoom_EventObjects, 0x0, BattleFrontier_BattlePikeThreePathRoom_MapCoordEvents, 0x0

