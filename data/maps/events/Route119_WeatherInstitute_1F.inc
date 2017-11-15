Route119_WeatherInstitute_1F_MapObjects: @ 853EB20
	object_event 1, MAP_OBJ_GFX_AQUA_MEMBER_M, 0, 0, 15, 3, 3, 9, 0, 0, 1, 3, Route119_WeatherInstitute_1F_EventScript_26FB29, 890, 0, 0
	object_event 2, MAP_OBJ_GFX_AQUA_MEMBER_F, 0, 0, 10, 5, 3, 8, 0, 0, 1, 2, Route119_WeatherInstitute_1F_EventScript_26FB40, 890, 0, 0
	object_event 3, MAP_OBJ_GFX_MAN_5, 0, 0, 5, 4, 3, 8, 0, 0, 0, 0, Route119_WeatherInstitute_1F_EventScript_26FB0F, 892, 0, 0
	object_event 4, MAP_OBJ_GFX_MAN_5, 0, 0, 2, 11, 3, 1, 1, 0, 0, 0, Route119_WeatherInstitute_1F_EventScript_26FAC8, 892, 0, 0
	object_event 5, MAP_OBJ_GFX_LITTLE_BOY_1, 0, 0, 14, 11, 3, 2, 17, 0, 0, 0, Route119_WeatherInstitute_1F_EventScript_26FAA4, 0, 0, 0

Route119_WeatherInstitute_1F_MapWarps: @ 853EB98
	warp_def 9, 12, 0, 0, ROUTE_119
	warp_def 10, 12, 0, 0, ROUTE_119
	warp_def 17, 1, 0, 0, ROUTE_119_WEATHER_INSTITUTE_2F

Route119_WeatherInstitute_1F_MapBGEvents: @ 853EBB0
	bg_event 1, 2, 0, 0, 0, Route119_WeatherInstitute_1F_EventScript_26FB18
	bg_event 1, 3, 0, 0, 0, Route119_WeatherInstitute_1F_EventScript_26FB18
	bg_event 0, 2, 0, 0, 0, Route119_WeatherInstitute_1F_EventScript_26FB18
	bg_event 0, 3, 0, 0, 0, Route119_WeatherInstitute_1F_EventScript_26FB18

Route119_WeatherInstitute_1F_MapEvents:: @ 853EBE0
	map_events Route119_WeatherInstitute_1F_MapObjects, Route119_WeatherInstitute_1F_MapWarps, 0x0, Route119_WeatherInstitute_1F_MapBGEvents

