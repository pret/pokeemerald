Route110_TrickHousePuzzle6_EventObjects:
	object_event 1, EVENT_OBJ_GFX_PICNICKER, 0, 7, 9, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 1, 1, Route110_TrickHousePuzzle6_EventScript_26DDE1, 0
	object_event 2, EVENT_OBJ_GFX_MAN_5, 0, 11, 10, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 1, 3, Route110_TrickHousePuzzle6_EventScript_26DDF8, 0
	object_event 3, EVENT_OBJ_GFX_CAMPER, 0, 4, 5, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 1, 1, Route110_TrickHousePuzzle6_EventScript_26DE0F, 0
	object_event 4, EVENT_OBJ_GFX_ITEM_BALL, 0, 11, 21, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, Route110_TrickHousePuzzle6_EventScript_29145C, FLAG_ITEM_TRICK_HOUSE_PUZZLE_6_GLITTER_MAIL

Route110_TrickHousePuzzle6_MapWarps:
	warp_def 0, 21, 3, 2, MAP_ROUTE110_TRICK_HOUSE_ENTRANCE
	warp_def 1, 21, 3, 2, MAP_ROUTE110_TRICK_HOUSE_ENTRANCE
	warp_def 13, 1, 3, 0, MAP_ROUTE110_TRICK_HOUSE_END

Route110_TrickHousePuzzle6_MapBGEvents:
	bg_event 0, 10, 3, BG_EVENT_PLAYER_FACING_ANY, Route110_TrickHousePuzzle6_EventScript_26DDC4

Route110_TrickHousePuzzle6_MapEvents::
	map_events Route110_TrickHousePuzzle6_EventObjects, Route110_TrickHousePuzzle6_MapWarps, 0x0, Route110_TrickHousePuzzle6_MapBGEvents

