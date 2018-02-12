BattleFrontier_BattlePikeRandomRoom1_MapObjects: @ 853CD54
	object_event 1, MAP_OBJ_GFX_HIPSTER, 0, 0, 4, 4, 3, 8, 17, 0, 0, 0, BattleFrontier_BattlePikeRandomRoom1_EventScript_25D7ED, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_TRADER, 0, 0, 3, 4, 3, 8, 17, 0, 0, 0, BattleFrontier_BattlePikeRandomRoom1_EventScript_25D88D, 0, 0, 0

BattleFrontier_BattlePikeRandomRoom1_MapCoordEvents: @ 853CD84
	coord_event 4, 3, 3, 0, VAR_0x4001, 0, 0, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C40A2
	coord_event 3, 6, 3, 0, VAR_0x4002, 0, 0, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C4082
	coord_event 3, 7, 3, 0, VAR_0x4003, 1, 0, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C408D
	coord_event 4, 6, 3, 0, VAR_0x4002, 0, 0, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C4082
	coord_event 5, 6, 3, 0, VAR_0x4002, 0, 0, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C4082
	coord_event 4, 7, 3, 0, VAR_0x4003, 1, 0, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C408D
	coord_event 5, 7, 3, 0, VAR_0x4003, 1, 0, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C408D

BattleFrontier_BattlePikeRandomRoom1_MapEvents:: @ 853CDF4
	map_events BattleFrontier_BattlePikeRandomRoom1_MapObjects, 0x0, BattleFrontier_BattlePikeRandomRoom1_MapCoordEvents, 0x0

