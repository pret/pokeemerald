Route113_EventObjects: @ 8529B2C
	object_event 1, EVENT_OBJ_GFX_NINJA_BOY, 0, 66, 12, 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT, 1, 0, 0, 0, Route113_EventScript_1F2193, 0
	object_event 2, EVENT_OBJ_GFX_GENTLEMAN, 0, 36, 10, 3, MOVEMENT_TYPE_WANDER_UP_AND_DOWN, 0, 1, 0, 0, Route113_EventScript_1F218A, 0
	object_event 3, EVENT_OBJ_GFX_YOUNGSTER, 0, 62, 8, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 1, 3, Route113_EventScript_1F21C0, 0
	object_event 4, EVENT_OBJ_GFX_YOUNGSTER, 0, 21, 11, 3, MOVEMENT_TYPE_FACE_DOWN_AND_LEFT, 0, 0, 1, 3, Route113_EventScript_1F21D7, 0
	object_event 5, EVENT_OBJ_GFX_WOMAN_5, 0, 51, 11, 3, MOVEMENT_TYPE_ROTATE_COUNTERCLOCKWISE, 0, 0, 1, 2, Route113_EventScript_1F21EE, 0
	object_event 6, EVENT_OBJ_GFX_ITEM_BALL, 0, 53, 7, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, Route113_EventScript_290DDC, 1012
	object_event 7, EVENT_OBJ_GFX_ITEM_BALL, 0, 79, 5, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, Route113_EventScript_290DE9, 1013
	object_event 8, EVENT_OBJ_GFX_NINJA_BOY, 0, 29, 6, 3, MOVEMENT_TYPE_HIDDEN, 0, 0, 3, 1, Route113_EventScript_1F2250, 0
	object_event 9, EVENT_OBJ_GFX_NINJA_BOY, 0, 71, 2, 3, MOVEMENT_TYPE_HIDDEN, 0, 0, 3, 1, Route113_EventScript_1F22B2, 0
	object_event 10, EVENT_OBJ_GFX_TWIN, 0, 45, 6, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 1, 1, Route113_EventScript_1F22C9, 0
	object_event 11, EVENT_OBJ_GFX_TWIN, 0, 46, 6, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 1, 1, Route113_EventScript_1F22E4, 0
	object_event 12, EVENT_OBJ_GFX_ITEM_BALL, 0, 15, 15, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, Route113_EventScript_290DF6, 1143
	object_event 13, EVENT_OBJ_GFX_MANIAC, 0, 75, 3, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 1, 4, Route113_EventScript_1F2344, 0
	object_event 14, EVENT_OBJ_GFX_CAMPER, 0, 71, 4, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 1, 1, Route113_EventScript_1F232D, 0
	object_event 15, EVENT_OBJ_GFX_PICNICKER, 0, 7, 6, 3, MOVEMENT_TYPE_WALK_DOWN_AND_UP, 1, 3, 1, 6, Route113_EventScript_1F22FF, 0
	object_event 16, EVENT_OBJ_GFX_MAN_5, 0, 7, 13, 3, MOVEMENT_TYPE_WALK_UP_AND_DOWN, 1, 3, 1, 6, Route113_EventScript_1F2316, 0

Route113_MapWarps: @ 8529CAC
	warp_def 33, 5, 0, 0, MAP_ROUTE113_GLASS_WORKSHOP
	warp_def 41, 12, 0, 0, MAP_TERRA_CAVE_ENTRANCE
	warp_def 88, 5, 0, 0, MAP_TERRA_CAVE_ENTRANCE

Route113_MapCoordEvents: @ 8529CC4
	coord_weather_event 19, 11, 3, COORD_EVENT_WEATHER_ASH
	coord_weather_event 19, 10, 3, COORD_EVENT_WEATHER_ASH
	coord_weather_event 19, 12, 3, COORD_EVENT_WEATHER_ASH
	coord_weather_event 19, 13, 3, COORD_EVENT_WEATHER_ASH
	coord_weather_event 86, 9, 3, COORD_EVENT_WEATHER_ASH
	coord_weather_event 85, 10, 3, COORD_EVENT_WEATHER_ASH
	coord_weather_event 85, 11, 3, COORD_EVENT_WEATHER_ASH
	coord_weather_event 14, 10, 3, COORD_EVENT_WEATHER_SUNNY
	coord_weather_event 14, 11, 3, COORD_EVENT_WEATHER_SUNNY
	coord_weather_event 14, 12, 3, COORD_EVENT_WEATHER_SUNNY
	coord_weather_event 14, 13, 3, COORD_EVENT_WEATHER_SUNNY
	coord_weather_event 94, 8, 3, COORD_EVENT_WEATHER_SUNNY
	coord_weather_event 94, 9, 3, COORD_EVENT_WEATHER_SUNNY
	coord_weather_event 94, 10, 3, COORD_EVENT_WEATHER_SUNNY
	coord_weather_event 94, 11, 0, COORD_EVENT_WEATHER_SUNNY
	coord_weather_event 19, 14, 3, COORD_EVENT_WEATHER_ASH
	coord_weather_event 87, 8, 3, COORD_EVENT_WEATHER_ASH
	coord_weather_event 87, 6, 3, COORD_EVENT_WEATHER_ASH
	coord_weather_event 87, 7, 3, COORD_EVENT_WEATHER_ASH

Route113_MapBGEvents: @ 8529DF4
	bg_event 85, 6, 0, BG_EVENT_PLAYER_FACING_ANY, Route113_EventScript_1F219C
	bg_event 12, 9, 0, BG_EVENT_PLAYER_FACING_ANY, Route113_EventScript_1F21A5
	bg_event 58, 4, 3, BG_EVENT_PLAYER_FACING_ANY, Route113_EventScript_1F21B7
	bg_event 31, 5, 0, BG_EVENT_PLAYER_FACING_ANY, Route113_EventScript_1F21AE
	bg_secret_base_event 49, 8, 3, SECRET_BASE_RED_CAVE1_3
	bg_hidden_item_event 66, 3, 3, ITEM_ETHER, 3
	bg_hidden_item_event 22, 5, 3, ITEM_TM32, 30
	bg_hidden_item_event 73, 3, 3, ITEM_NUGGET, 98

Route113_MapEvents:: @ 8529E54
	map_events Route113_EventObjects, Route113_MapWarps, Route113_MapCoordEvents, Route113_MapBGEvents

