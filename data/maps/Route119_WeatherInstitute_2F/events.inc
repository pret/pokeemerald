Route119_WeatherInstitute_2F_EventObjects: @ 853EBF4
	object_event 1, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 15, 6, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 1, 4, Route119_WeatherInstitute_2F_EventScript_26FF7F, 890
	object_event 2, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 10, 8, 3, MOVEMENT_TYPE_FACE_DOWN_AND_UP, 0, 0, 1, 2, Route119_WeatherInstitute_2F_EventScript_26FF96, 890
	object_event 3, EVENT_OBJ_GFX_AQUA_MEMBER_F, 0, 4, 6, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 1, 0, Route119_WeatherInstitute_2F_EventScript_26FFAD, 890
	object_event 4, EVENT_OBJ_GFX_MAN_5, 0, 0, 6, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, 0x0, 893
	object_event 5, EVENT_OBJ_GFX_SCIENTIST_1, 0, 18, 6, 3, MOVEMENT_TYPE_LOOK_AROUND, 2, 1, 0, 0, Route119_WeatherInstitute_2F_EventScript_27018B, 0
	object_event 6, EVENT_OBJ_GFX_MAN_5, 0, 1, 7, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, 0x0, 893
	object_event 7, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 16, 6, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 0, 0, 0x0, 992
	object_event 8, EVENT_OBJ_GFX_AQUA_MEMBER_F, 0, 19, 6, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 1, 3, Route119_WeatherInstitute_2F_EventScript_26FF68, 890

Route119_WeatherInstitute_2F_MapWarps: @ 853ECB4
	warp_def 17, 1, 0, 2, MAP_ROUTE119_WEATHER_INSTITUTE_1F

Route119_WeatherInstitute_2F_MapEvents:: @ 853ECBC
	map_events Route119_WeatherInstitute_2F_EventObjects, Route119_WeatherInstitute_2F_MapWarps, 0x0, 0x0

