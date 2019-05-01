EverGrandeCity_MapScripts:: @ 81E7D1B
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	.byte 0

EverGrandeCity_OnTransition: @ 81E7D21
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetWeather15
	end

EverGrandeCity_EventScript_1E7D2B:: @ 81E7D2B
	msgbox EverGrandeCity_Text_1E7D4F, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_1E7D34:: @ 81E7D34
	msgbox EverGrandeCity_Text_1E7D89, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_1E7D3D:: @ 81E7D3D
	msgbox EverGrandeCity_Text_1E7D65, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_1E7D46:: @ 81E7D46
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setvar VAR_TEMP_1, 1
	end

EverGrandeCity_Text_1E7D4F: @ 81E7D4F
	.string "ENTERING VICTORY ROAD$"

EverGrandeCity_Text_1E7D65: @ 81E7D65
	.string "ENTERING POKéMON LEAGUE\n"
	.string "CENTER GATE$"

EverGrandeCity_Text_1E7D89: @ 81E7D89
	.string "EVER GRANDE CITY\p"
	.string "“The paradise of flowers, the sea,\n"
	.string "and POKéMON.”$"

