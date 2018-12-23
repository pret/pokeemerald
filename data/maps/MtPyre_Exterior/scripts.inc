MtPyre_Exterior_MapScripts:: @ 8231FCC
	map_script 3, MtPyre_Exterior_MapScript1_231FD2
	.byte 0

MtPyre_Exterior_MapScript1_231FD2: @ 8231FD2
	call MtPyre_Exterior_EventScript_231FD8
	end

MtPyre_Exterior_EventScript_231FD8:: @ 8231FD8
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 12
	goto_if_lt MtPyre_Exterior_EventScript_231FE9
	return

MtPyre_Exterior_EventScript_231FE9:: @ 8231FE9
	setweather 6
	return

MtPyre_Exterior_EventScript_231FED:: @ 8231FED
	setweather 6
	doweather
	end

MtPyre_Exterior_EventScript_231FF2:: @ 8231FF2
	setweather 2
	doweather
	end

