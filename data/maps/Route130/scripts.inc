Route130_MapScripts:: @ 81F735F
	map_script MAP_SCRIPT_ON_TRANSITION, Route130_OnTransition
	.byte 0

Route130_OnTransition: @ 81F7365
	compare VAR_RAYQUAZA_STATE, 4
	call_if_ge Route130_EventScript_1F73B5
	specialvar VAR_RESULT, IsMirageIslandPresent
	compare VAR_RESULT, 1
	goto_if_eq Route130_EventScript_1F73B1
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	setflag FLAG_TEMP_15
	setflag FLAG_TEMP_16
	setflag FLAG_TEMP_17
	setflag FLAG_TEMP_18
	setflag FLAG_TEMP_19
	setflag FLAG_TEMP_1A
	setflag FLAG_TEMP_1B
	setflag FLAG_TEMP_1C
	setflag FLAG_TEMP_1D
	setflag FLAG_TEMP_1E
	setflag FLAG_TEMP_1F
	setmaplayoutindex LAYOUT_ROUTE130
	end

Route130_EventScript_1F73B1:: @ 81F73B1
	setmaplayoutindex LAYOUT_ROUTE130_MIRAGE_ISLAND
	end

Route130_EventScript_1F73B5:: @ 81F73B5
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetWeather15
	return

Route130_EventScript_1F73BF:: @ 81F73BF
	trainerbattle_single TRAINER_RODNEY, Route130_Text_2A328A, Route130_Text_2A32E6
	msgbox Route130_Text_2A3300, MSGBOX_AUTOCLOSE
	end

Route130_EventScript_1F73D6:: @ 81F73D6
	trainerbattle_single TRAINER_KATIE, Route130_Text_2A3363, Route130_Text_2A33AC
	msgbox Route130_Text_2A33F5, MSGBOX_AUTOCLOSE
	end

Route130_EventScript_1F73ED:: @ 81F73ED
	trainerbattle_single TRAINER_SANTIAGO, Route130_Text_2A343A, Route130_Text_2A346D
	msgbox Route130_Text_2A3494, MSGBOX_AUTOCLOSE
	end

