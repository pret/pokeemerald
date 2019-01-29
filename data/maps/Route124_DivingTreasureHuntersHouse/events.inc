Route124_DivingTreasureHuntersHouse_EventObjects:
	object_event 1, EVENT_OBJ_GFX_MAN_5, 0, 5, 4, 0, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, Route124_DivingTreasureHuntersHouse_EventScript_270A32, 0

Route124_DivingTreasureHuntersHouse_MapWarps:
	warp_def 3, 8, 0, 0, MAP_ROUTE124
	warp_def 4, 8, 0, 0, MAP_ROUTE124

Route124_DivingTreasureHuntersHouse_MapBGEvents:
	bg_event 7, 1, 0, BG_EVENT_PLAYER_FACING_ANY, Route124_DivingTreasureHuntersHouse_EventScript_270F63

Route124_DivingTreasureHuntersHouse_MapEvents::
	map_events Route124_DivingTreasureHuntersHouse_EventObjects, Route124_DivingTreasureHuntersHouse_MapWarps, 0x0, Route124_DivingTreasureHuntersHouse_MapBGEvents

