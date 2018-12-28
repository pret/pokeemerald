OldaleTown_EventObjects: @ 8527854
	object_event 1, EVENT_OBJ_GFX_GIRL_3, 0, 16, 11, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, OldaleTown_EventScript_1E8EF3, 0
	object_event 2, EVENT_OBJ_GFX_MART_EMPLOYEE, 0, 13, 7, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, OldaleTown_EventScript_1E8EFC, 0
	object_event 3, EVENT_OBJ_GFX_MANIAC, 0, 8, 9, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, OldaleTown_EventScript_1E901F, 0
	object_event 4, EVENT_OBJ_GFX_VAR_0, 0, 11, 19, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, OldaleTown_EventScript_1E9070, FLAG_HIDE_OLDALE_TOWN_RIVAL

OldaleTown_MapWarps: @ 85278B4
	warp_def 5, 7, 0, 0, MAP_OLDALE_TOWN_HOUSE1
	warp_def 15, 16, 0, 0, MAP_OLDALE_TOWN_HOUSE2
	warp_def 6, 16, 0, 0, MAP_OLDALE_TOWN_POKEMON_CENTER_1F
	warp_def 14, 6, 0, 0, MAP_OLDALE_TOWN_MART

OldaleTown_MapCoordEvents: @ 85278D4
	coord_event 0, 10, 3, VAR_0x4051, 0, OldaleTown_EventScript_1E903F
	coord_event 8, 19, 3, VAR_0x40C7, 1, OldaleTown_EventScript_1E9086
	coord_event 9, 19, 3, VAR_0x40C7, 1, OldaleTown_EventScript_1E90A6
	coord_event 10, 19, 3, VAR_0x40C7, 1, OldaleTown_EventScript_1E90C6

OldaleTown_MapBGEvents: @ 8527914
	bg_event 11, 9, 0, BG_EVENT_PLAYER_FACING_ANY, OldaleTown_EventScript_1E8EEA
	bg_event 7, 16, 0, BG_EVENT_PLAYER_FACING_NORTH, OldaleTown_EventScript_271E73
	bg_event 15, 6, 0, BG_EVENT_PLAYER_FACING_NORTH, OldaleTown_EventScript_271E6A
	bg_event 8, 16, 0, BG_EVENT_PLAYER_FACING_NORTH, OldaleTown_EventScript_271E73
	bg_event 16, 6, 0, BG_EVENT_PLAYER_FACING_NORTH, OldaleTown_EventScript_271E6A

OldaleTown_MapEvents:: @ 8527950
	map_events OldaleTown_EventObjects, OldaleTown_MapWarps, OldaleTown_MapCoordEvents, OldaleTown_MapBGEvents

