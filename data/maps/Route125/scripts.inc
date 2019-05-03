Route125_MapScripts:: @ 81F6748
	map_script MAP_SCRIPT_ON_TRANSITION, Route125_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route125_MapScript1_1F6783
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route125_MapScript2_1F679A
	.byte 0

Route125_OnTransition: @ 81F6758
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetWeather15
	compare VAR_SHOULD_END_UNUSUAL_WEATHER, 1
	call_if_eq Route125_EventScript_273D13
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_125_WEST
	call_if_eq UnusualWeather_StartKyogreWeather
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_125_EAST
	call_if_eq UnusualWeather_StartKyogreWeather
	end

Route125_MapScript1_1F6783: @ 81F6783
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_125_WEST
	call_if_eq UnusualWeather_EventScript_PlaceTilesRoute125West
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_125_EAST
	call_if_eq UnusualWeather_EventScript_PlaceTilesRoute125East
	end

Route125_MapScript2_1F679A: @ 81F679A
	map_script_2 VAR_SHOULD_END_UNUSUAL_WEATHER, 1, UnusualWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route125_EventScript_1F67A4:: @ 81F67A4
	trainerbattle_single TRAINER_NOLEN, Route125_Text_2A1527, Route125_Text_2A155A
	msgbox Route125_Text_2A1567, MSGBOX_AUTOCLOSE
	end

Route125_EventScript_1F67BB:: @ 81F67BB
	trainerbattle_single TRAINER_STAN, Route125_Text_2A159F, Route125_Text_2A15C7
	msgbox Route125_Text_2A15D5, MSGBOX_AUTOCLOSE
	end

Route125_EventScript_1F67D2:: @ 81F67D2
	trainerbattle_single TRAINER_TANYA, Route125_Text_2A1615, Route125_Text_2A164D
	msgbox Route125_Text_2A165E, MSGBOX_AUTOCLOSE
	end

Route125_EventScript_1F67E9:: @ 81F67E9
	trainerbattle_single TRAINER_SHARON, Route125_Text_2A1686, Route125_Text_2A16C5
	msgbox Route125_Text_2A16CE, MSGBOX_AUTOCLOSE
	end

Route125_EventScript_1F6800:: @ 81F6800
	trainerbattle_single TRAINER_ERNEST_1, Route125_Text_2A16FC, Route125_Text_2A173A, Route125_EventScript_1F682C
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route125_EventScript_1F684B
	msgbox Route125_Text_2A1755, MSGBOX_DEFAULT
	release
	end

Route125_EventScript_1F682C:: @ 81F682C
	special sub_80B4808
	waitmovement 0
	msgbox Route125_Text_2A17CF, MSGBOX_DEFAULT
	register_matchcall TRAINER_ERNEST_1
	release
	end

Route125_EventScript_1F684B:: @ 81F684B
	trainerbattle_rematch TRAINER_ERNEST_1, Route125_Text_2A180E, Route125_Text_2A1851
	msgbox Route125_Text_2A187A, MSGBOX_AUTOCLOSE
	end

Route125_EventScript_1F6862:: @ 81F6862
	trainerbattle_double TRAINER_KIM_AND_IRIS, Route125_Text_2A192B, Route125_Text_2A1989, Route125_Text_2A19F8
	msgbox Route125_Text_2A19A6, MSGBOX_AUTOCLOSE
	end

Route125_EventScript_1F687D:: @ 81F687D
	trainerbattle_double TRAINER_KIM_AND_IRIS, Route125_Text_2A1A35, Route125_Text_2A1A71, Route125_Text_2A1AD9
	msgbox Route125_Text_2A1A92, MSGBOX_AUTOCLOSE
	end

Route125_EventScript_1F6898:: @ 81F6898
	trainerbattle_single TRAINER_PRESLEY, Route125_Text_2A1B1A, Route125_Text_2A1B4E
	msgbox Route125_Text_2A1B70, MSGBOX_AUTOCLOSE
	end

Route125_EventScript_1F68AF:: @ 81F68AF
	trainerbattle_single TRAINER_AURON, Route125_Text_2A1BCE, Route125_Text_2A1BFD
	msgbox Route125_Text_2A1C2A, MSGBOX_AUTOCLOSE
	end

