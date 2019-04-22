Route129_MapScripts:: @ 81F7284
	map_script MAP_SCRIPT_ON_TRANSITION, Route129_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route129_MapScript1_1F7294
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route129_MapScript2_1F72E2
	.byte 0

Route129_MapScript1_1F7294: @ 81F7294
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_129_WEST
	call_if_eq UnusualWeather_EventScript_PlaceTilesRoute129West
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_129_EAST
	call_if_eq UnusualWeather_EventScript_PlaceTilesRoute129East
	end

Route129_OnTransition: @ 81F72AB
	compare VAR_SHOULD_END_UNUSUAL_WEATHER, 1
	call_if_eq Route129_EventScript_273D13
	compare VAR_RAYQUAZA_STATE, 4
	call_if_ge Route129_EventScript_1F72D8
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_129_WEST
	call_if_eq UnusualWeather_StartKyogreWeather
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_129_EAST
	call_if_eq UnusualWeather_StartKyogreWeather
	end

Route129_EventScript_1F72D8:: @ 81F72D8
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetWeather15
	return

Route129_MapScript2_1F72E2: @ 81F72E2
	map_script_2 VAR_SHOULD_END_UNUSUAL_WEATHER, 1, UnusualWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route129_EventScript_1F72EC:: @ 81F72EC
	trainerbattle_single TRAINER_CHASE, Route129_Text_2A2F66, Route129_Text_2A2F9D
	msgbox Route129_Text_2A2FB9, MSGBOX_AUTOCLOSE
	end

Route129_EventScript_1F7303:: @ 81F7303
	trainerbattle_single TRAINER_ALLISON, Route129_Text_2A2FF2, Route129_Text_2A3034
	msgbox Route129_Text_2A3048, MSGBOX_AUTOCLOSE
	end

Route129_EventScript_1F731A:: @ 81F731A
	trainerbattle_single TRAINER_REED, Route129_Text_2A30CD, Route129_Text_2A30F1
	msgbox Route129_Text_2A3114, MSGBOX_AUTOCLOSE
	end

Route129_EventScript_1F7331:: @ 81F7331
	trainerbattle_single TRAINER_TISHA, Route129_Text_2A314E, Route129_Text_2A317D
	msgbox Route129_Text_2A31A6, MSGBOX_AUTOCLOSE
	end

Route129_EventScript_1F7348:: @ 81F7348
	trainerbattle_single TRAINER_CLARENCE, Route129_Text_2A3204, Route129_Text_2A3239
	msgbox Route129_Text_2A3252, MSGBOX_AUTOCLOSE
	end

