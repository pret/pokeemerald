BattleFrontier_BattlePikeRandomRoom1_EventObjects: @ 853CD54
	object_event 1, EVENT_OBJ_GFX_VAR_0, 0, 4, 4, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, BattleFrontier_BattlePikeRandomRoom1_EventScript_25D7ED, 0
	object_event 2, EVENT_OBJ_GFX_VAR_1, 0, 3, 4, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, BattleFrontier_BattlePikeRandomRoom1_EventScript_25D88D, 0

BattleFrontier_BattlePikeRandomRoom1_MapCoordEvents: @ 853CD84
	coord_event 4, 3, 3, VAR_TEMP_1, 0, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C40A2
	coord_event 3, 6, 3, VAR_TEMP_2, 0, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C4082
	coord_event 3, 7, 3, VAR_TEMP_3, 1, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C408D
	coord_event 4, 6, 3, VAR_TEMP_2, 0, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C4082
	coord_event 5, 6, 3, VAR_TEMP_2, 0, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C4082
	coord_event 4, 7, 3, VAR_TEMP_3, 1, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C408D
	coord_event 5, 7, 3, VAR_TEMP_3, 1, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C408D

BattleFrontier_BattlePikeRandomRoom1_MapEvents:: @ 853CDF4
	map_events BattleFrontier_BattlePikeRandomRoom1_EventObjects, 0x0, BattleFrontier_BattlePikeRandomRoom1_MapCoordEvents, 0x0

