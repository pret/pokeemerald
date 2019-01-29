EverGrandeCity_MapWarps:
	warp_def 18, 5, 0, 0, MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F
	warp_def 27, 48, 0, 0, MAP_EVER_GRANDE_CITY_POKEMON_CENTER_1F
	warp_def 18, 41, 0, 0, MAP_VICTORY_ROAD_1F
	warp_def 18, 27, 0, 1, MAP_VICTORY_ROAD_1F

EverGrandeCity_MapCoordEvents:
	coord_event 17, 58, 1, VAR_TEMP_1, 0, EverGrandeCity_EventScript_1E7D46
	coord_event 16, 58, 1, VAR_TEMP_1, 0, EverGrandeCity_EventScript_1E7D46
	coord_event 18, 58, 1, VAR_TEMP_1, 0, EverGrandeCity_EventScript_1E7D46
	coord_event 19, 58, 1, VAR_TEMP_1, 0, EverGrandeCity_EventScript_1E7D46
	coord_event 20, 58, 1, VAR_TEMP_1, 0, EverGrandeCity_EventScript_1E7D46
	coord_event 21, 58, 1, VAR_TEMP_1, 0, EverGrandeCity_EventScript_1E7D46
	coord_event 22, 58, 1, VAR_TEMP_1, 0, EverGrandeCity_EventScript_1E7D46
	coord_event 23, 58, 1, VAR_TEMP_1, 0, EverGrandeCity_EventScript_1E7D46
	coord_event 24, 58, 1, VAR_TEMP_1, 0, EverGrandeCity_EventScript_1E7D46
	coord_event 25, 58, 1, VAR_TEMP_1, 0, EverGrandeCity_EventScript_1E7D46
	coord_event 26, 58, 1, VAR_TEMP_1, 0, EverGrandeCity_EventScript_1E7D46

EverGrandeCity_MapBGEvents:
	bg_event 19, 43, 5, BG_EVENT_PLAYER_FACING_ANY, EverGrandeCity_EventScript_1E7D2B
	bg_event 29, 48, 0, BG_EVENT_PLAYER_FACING_NORTH, EverGrandeCity_EventScript_271E73
	bg_event 18, 52, 5, BG_EVENT_PLAYER_FACING_ANY, EverGrandeCity_EventScript_1E7D34
	bg_event 23, 15, 0, BG_EVENT_PLAYER_FACING_ANY, EverGrandeCity_EventScript_1E7D3D
	bg_event 28, 48, 0, BG_EVENT_PLAYER_FACING_NORTH, EverGrandeCity_EventScript_271E73

EverGrandeCity_MapEvents::
	map_events 0x0, EverGrandeCity_MapWarps, EverGrandeCity_MapCoordEvents, EverGrandeCity_MapBGEvents

