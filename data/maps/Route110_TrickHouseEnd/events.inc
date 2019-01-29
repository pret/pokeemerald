Route110_TrickHouseEnd_EventObjects:
	object_event 1, EVENT_OBJ_GFX_MAN_1, 0, 4, 5, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, Route110_TrickHouseEnd_EventScript_26AD17, FLAG_HIDE_TRICK_HOUSE_END_MAN

Route110_TrickHouseEnd_MapWarps:
	warp_def 10, 1, 3, 2, MAP_ROUTE110_TRICK_HOUSE_PUZZLE1
	warp_def 2, 1, 3, 0, MAP_ROUTE110_TRICK_HOUSE_CORRIDOR

Route110_TrickHouseEnd_MapCoordEvents:
	coord_event 2, 2, 3, VAR_TEMP_2, 0, Route110_TrickHouseEnd_EventScript_26B041

Route110_TrickHouseEnd_MapBGEvents:
	bg_hidden_item_event 4, 5, 3, ITEM_NUGGET, FLAG_HIDDEN_ITEM_TRICK_HOUSE_NUGGET

Route110_TrickHouseEnd_MapEvents::
	map_events Route110_TrickHouseEnd_EventObjects, Route110_TrickHouseEnd_MapWarps, Route110_TrickHouseEnd_MapCoordEvents, Route110_TrickHouseEnd_MapBGEvents

