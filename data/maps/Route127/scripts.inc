Route127_MapScripts:: @ 81F69D9
	map_script MAP_SCRIPT_ON_TRANSITION, Route127_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route127_MapScript1_1F6A14
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route127_MapScript2_1F6A2B
	.byte 0

Route127_OnTransition: @ 81F69E9
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetWeather15
	compare VAR_SHOULD_END_UNUSUAL_WEATHER, 1
	call_if_eq Route127_EventScript_273D13
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_127_NORTH
	call_if_eq UnusualWeather_StartKyogreWeather
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_127_SOUTH
	call_if_eq UnusualWeather_StartKyogreWeather
	end

Route127_MapScript1_1F6A14: @ 81F6A14
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_127_NORTH
	call_if_eq UnusualWeather_EventScript_PlaceTilesRoute127North
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_127_SOUTH
	call_if_eq UnusualWeather_EventScript_PlaceTilesRoute127South
	end

Route127_MapScript2_1F6A2B: @ 81F6A2B
	map_script_2 VAR_SHOULD_END_UNUSUAL_WEATHER, 1, UnusualWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route127_EventScript_1F6A35:: @ 81F6A35
	trainerbattle_single TRAINER_CAMDEN, Route127_Text_2A225F, Route127_Text_2A2294
	msgbox Route127_Text_2A22A1, MSGBOX_AUTOCLOSE
	end

Route127_EventScript_1F6A4C:: @ 81F6A4C
	trainerbattle_single TRAINER_DONNY, Route127_Text_2A22DD, Route127_Text_2A2315
	msgbox Route127_Text_2A232C, MSGBOX_AUTOCLOSE
	end

Route127_EventScript_1F6A63:: @ 81F6A63
	trainerbattle_single TRAINER_JONAH, Route127_Text_2A2381, Route127_Text_2A23E1
	msgbox Route127_Text_2A240C, MSGBOX_AUTOCLOSE
	end

Route127_EventScript_1F6A7A:: @ 81F6A7A
	trainerbattle_single TRAINER_HENRY, Route127_Text_2A2450, Route127_Text_2A2483
	msgbox Route127_Text_2A2494, MSGBOX_AUTOCLOSE
	end

Route127_EventScript_1F6A91:: @ 81F6A91
	trainerbattle_single TRAINER_ROGER, Route127_Text_2A24C6, Route127_Text_2A250B
	msgbox Route127_Text_2A2538, MSGBOX_AUTOCLOSE
	end

Route127_EventScript_1F6AA8:: @ 81F6AA8
	trainerbattle_single TRAINER_AIDAN, Route127_Text_2A257A, Route127_Text_2A25C1
	msgbox Route127_Text_2A25D2, MSGBOX_AUTOCLOSE
	end

Route127_EventScript_1F6ABF:: @ 81F6ABF
	trainerbattle_single TRAINER_ATHENA, Route127_Text_2A27D0, Route127_Text_2A27FC
	msgbox Route127_Text_2A2832, MSGBOX_AUTOCLOSE
	end

Route127_EventScript_1F6AD6:: @ 81F6AD6
	trainerbattle_single TRAINER_KOJI_1, Route127_Text_2A264D, Route127_Text_2A2685, Route127_EventScript_1F6B02
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route127_EventScript_1F6B21
	msgbox Route127_Text_2A26AC, MSGBOX_DEFAULT
	release
	end

Route127_EventScript_1F6B02:: @ 81F6B02
	special sub_80B4808
	waitmovement 0
	msgbox Route127_Text_2A26EE, MSGBOX_DEFAULT
	register_matchcall TRAINER_KOJI_1
	release
	end

Route127_EventScript_1F6B21:: @ 81F6B21
	trainerbattle_rematch TRAINER_KOJI_1, Route127_Text_2A2734, Route127_Text_2A276B
	msgbox Route127_Text_2A278E, MSGBOX_AUTOCLOSE
	end

