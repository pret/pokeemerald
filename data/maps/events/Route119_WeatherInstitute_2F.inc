Route119_WeatherInstitute_2F_MapObjects: @ 853EBF4
	object_event 1, MAP_OBJ_GFX_AQUA_MEMBER_M, 0, 0, 15, 6, 3, 10, 0, 0, 1, 4, Route119_WeatherInstitute_2F_EventScript_26FF7F, 890, 0, 0
	object_event 2, MAP_OBJ_GFX_AQUA_MEMBER_M, 0, 0, 10, 8, 3, 13, 0, 0, 1, 2, Route119_WeatherInstitute_2F_EventScript_26FF96, 890, 0, 0
	object_event 3, MAP_OBJ_GFX_AQUA_MEMBER_F, 0, 0, 4, 6, 3, 10, 0, 0, 1, 0, Route119_WeatherInstitute_2F_EventScript_26FFAD, 890, 0, 0
	object_event 4, MAP_OBJ_GFX_MAN_5, 0, 0, 0, 6, 3, 10, 0, 0, 0, 0, 0x0, 893, 0, 0
	object_event 5, MAP_OBJ_GFX_SCIENTIST_1, 0, 0, 18, 6, 3, 1, 18, 0, 0, 0, Route119_WeatherInstitute_2F_EventScript_27018B, 0, 0, 0
	object_event 6, MAP_OBJ_GFX_MAN_5, 0, 0, 1, 7, 3, 10, 0, 0, 0, 0, 0x0, 893, 0, 0
	object_event 7, MAP_OBJ_GFX_AQUA_MEMBER_M, 0, 0, 16, 6, 3, 9, 17, 0, 0, 0, 0x0, 992, 0, 0
	object_event 8, MAP_OBJ_GFX_AQUA_MEMBER_F, 0, 0, 19, 6, 3, 9, 17, 0, 1, 3, Route119_WeatherInstitute_2F_EventScript_26FF68, 890, 0, 0

Route119_WeatherInstitute_2F_MapWarps: @ 853ECB4
	warp_def 17, 1, 0, 2, ROUTE_119_WEATHER_INSTITUTE_1F

Route119_WeatherInstitute_2F_MapEvents:: @ 853ECBC
	map_events Route119_WeatherInstitute_2F_MapObjects, Route119_WeatherInstitute_2F_MapWarps, 0x0, 0x0

