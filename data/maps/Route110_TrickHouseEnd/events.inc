Route110_TrickHouseEnd_EventObjects: @ 853DEFC
	object_event 1, EVENT_OBJ_GFX_MAN_1, 0, 4, 5, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, Route110_TrickHouseEnd_EventScript_26AD17, FLAG_HIDE_TRICK_HOUSE_END_MAN

Route110_TrickHouseEnd_MapWarps: @ 853DF14
	warp_def 10, 1, 3, 2, MAP_ROUTE110_TRICK_HOUSE_PUZZLE1
	warp_def 2, 1, 3, 0, MAP_ROUTE110_TRICK_HOUSE_CORRIDOR

Route110_TrickHouseEnd_MapCoordEvents: @ 853DF24
	coord_event 2, 2, 3, VAR_TEMP_2, 0, Route110_TrickHouseEnd_EventScript_26B041

Route110_TrickHouseEnd_MapBGEvents: @ 853DF34
	bg_hidden_item_event_new 4, 5, 3, ITEM_NUGGET, FLAG_HIDDEN_ITEM_TRICK_HOUSE_NUGGET

Route110_TrickHouseEnd_MapEvents:: @ 853DF40
	map_events Route110_TrickHouseEnd_EventObjects, Route110_TrickHouseEnd_MapWarps, Route110_TrickHouseEnd_MapCoordEvents, Route110_TrickHouseEnd_MapBGEvents

