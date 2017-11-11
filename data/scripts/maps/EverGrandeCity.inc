EverGrandeCity_MapScripts:: @ 81E7D1B
	map_script 3, EverGrandeCity_MapScript1_1E7D21
	.byte 0

EverGrandeCity_MapScript1_1E7D21: @ 81E7D21
	checkflag FLAG_SYS_WEATHER_CTRL
	call_if 1, EverGrandeCity_EventScript_27207A
	end

EverGrandeCity_EventScript_1E7D2B:: @ 81E7D2B
	msgbox EverGrandeCity_Text_1E7D4F, 3
	end

EverGrandeCity_EventScript_1E7D34:: @ 81E7D34
	msgbox EverGrandeCity_Text_1E7D89, 3
	end

EverGrandeCity_EventScript_1E7D3D:: @ 81E7D3D
	msgbox EverGrandeCity_Text_1E7D65, 3
	end

EverGrandeCity_EventScript_1E7D46:: @ 81E7D46
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setvar VAR_0x4001, 1
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

