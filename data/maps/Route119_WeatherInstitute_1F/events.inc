Route119_WeatherInstitute_1F_EventObjects:
	object_event 1, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 15, 3, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 1, 3, Route119_WeatherInstitute_1F_EventScript_26FB29, FLAG_HIDE_ROUTE_119_TEAM_AQUA
	object_event 2, EVENT_OBJ_GFX_AQUA_MEMBER_F, 0, 10, 5, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 1, 2, Route119_WeatherInstitute_1F_EventScript_26FB40, FLAG_HIDE_ROUTE_119_TEAM_AQUA
	object_event 3, EVENT_OBJ_GFX_MAN_4, 0, 5, 4, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, Route119_WeatherInstitute_1F_EventScript_26FB0F, FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS
	object_event 4, EVENT_OBJ_GFX_MAN_4, 0, 2, 11, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 0, 0, 0, Route119_WeatherInstitute_1F_EventScript_26FAC8, FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS
	object_event 5, EVENT_OBJ_GFX_NINJA_BOY, 0, 14, 11, 3, MOVEMENT_TYPE_WANDER_AROUND, 1, 1, 0, 0, Route119_WeatherInstitute_1F_EventScript_26FAA4, 0

Route119_WeatherInstitute_1F_MapWarps:
	warp_def 9, 12, 0, 0, MAP_ROUTE119
	warp_def 10, 12, 0, 0, MAP_ROUTE119
	warp_def 17, 1, 0, 0, MAP_ROUTE119_WEATHER_INSTITUTE_2F

Route119_WeatherInstitute_1F_MapBGEvents:
	bg_event 1, 2, 0, BG_EVENT_PLAYER_FACING_ANY, Route119_WeatherInstitute_1F_EventScript_26FB18
	bg_event 1, 3, 0, BG_EVENT_PLAYER_FACING_ANY, Route119_WeatherInstitute_1F_EventScript_26FB18
	bg_event 0, 2, 0, BG_EVENT_PLAYER_FACING_ANY, Route119_WeatherInstitute_1F_EventScript_26FB18
	bg_event 0, 3, 0, BG_EVENT_PLAYER_FACING_ANY, Route119_WeatherInstitute_1F_EventScript_26FB18

Route119_WeatherInstitute_1F_MapEvents::
	map_events Route119_WeatherInstitute_1F_EventObjects, Route119_WeatherInstitute_1F_MapWarps, 0x0, Route119_WeatherInstitute_1F_MapBGEvents

