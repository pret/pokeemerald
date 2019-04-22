Route115_MapScripts:: @ 81F2920
	map_script MAP_SCRIPT_ON_LOAD, Route115_MapScript1_1F2930
	map_script MAP_SCRIPT_ON_TRANSITION, Route115_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route115_MapScript2_1F2969
	.byte 0

Route115_MapScript1_1F2930: @ 81F2930
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_115_WEST
	call_if_eq UnusualWeather_EventScript_PlaceTilesRoute115West
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_115_EAST
	call_if_eq UnusualWeather_EventScript_PlaceTilesRoute115East
	end

Route115_OnTransition: @ 81F2947
	compare VAR_SHOULD_END_UNUSUAL_WEATHER, 1
	call_if_eq Route115_EventScript_273D13
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_115_WEST
	call_if_eq UnusualWeather_StartGroudonWeather
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_115_EAST
	call_if_eq UnusualWeather_StartGroudonWeather
	end

Route115_MapScript2_1F2969: @ 81F2969
	map_script_2 VAR_SHOULD_END_UNUSUAL_WEATHER, 1, UnusualWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route115_EventScript_1F2973:: @ 81F2973
	msgbox Route115_Text_1F2B55, MSGBOX_NPC
	end

Route115_EventScript_1F297C:: @ 81F297C
	msgbox Route115_Text_1F2BC9, MSGBOX_SIGN
	end

Route115_EventScript_1F2985:: @ 81F2985
	msgbox Route115_Text_1F2BE3, MSGBOX_SIGN
	end

Route115_EventScript_1F298E:: @ 81F298E
	trainerbattle_single TRAINER_TIMOTHY_1, Route115_Text_29B1FA, Route115_Text_29B230, Route115_EventScript_1F29BA
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route115_EventScript_1F29D9
	msgbox Route115_Text_29B258, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_1F29BA:: @ 81F29BA
	special sub_80B4808
	waitmovement 0
	msgbox Route115_Text_29B2B3, MSGBOX_DEFAULT
	register_matchcall TRAINER_TIMOTHY_1
	release
	end

Route115_EventScript_1F29D9:: @ 81F29D9
	trainerbattle_rematch TRAINER_TIMOTHY_1, Route115_Text_29B32C, Route115_Text_29B372
	msgbox Route115_Text_29B385, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_1F29F0:: @ 81F29F0
	trainerbattle_single TRAINER_KOICHI, Route115_Text_29B3CC, Route115_Text_29B3ED
	msgbox Route115_Text_29B3FF, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_1F2A07:: @ 81F2A07
	trainerbattle_single TRAINER_NOB_1, Route115_Text_29B449, Route115_Text_29B480, Route115_EventScript_1F2A33
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route115_EventScript_1F2A52
	msgbox Route115_Text_29B49D, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_1F2A33:: @ 81F2A33
	special sub_80B4808
	waitmovement 0
	msgbox Route115_Text_29B50B, MSGBOX_DEFAULT
	register_matchcall TRAINER_NOB_1
	release
	end

Route115_EventScript_1F2A52:: @ 81F2A52
	trainerbattle_rematch TRAINER_NOB_1, Route115_Text_29B547, Route115_Text_29B59D
	msgbox Route115_Text_29B5B5, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_1F2A69:: @ 81F2A69
	trainerbattle_single TRAINER_CYNDY_1, Route115_Text_29B5EF, Route115_Text_29B62D, Route115_EventScript_1F2A95
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route115_EventScript_1F2AB4
	msgbox Route115_Text_29B647, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_1F2A95:: @ 81F2A95
	special sub_80B4808
	waitmovement 0
	msgbox Route115_Text_29B6AB, MSGBOX_DEFAULT
	register_matchcall TRAINER_CYNDY_1
	release
	end

Route115_EventScript_1F2AB4:: @ 81F2AB4
	trainerbattle_rematch TRAINER_CYNDY_1, Route115_Text_29B6FA, Route115_Text_29B71A
	msgbox Route115_Text_29B737, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_1F2ACB:: @ 81F2ACB
	trainerbattle_single TRAINER_HECTOR, Route115_Text_29B78F, Route115_Text_29B7C5
	msgbox Route115_Text_29B7EA, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_1F2AE2:: @ 81F2AE2
	trainerbattle_single TRAINER_KYRA, Route115_Text_29B826, Route115_Text_29B85D
	msgbox Route115_Text_29B869, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_1F2AF9:: @ 81F2AF9
	trainerbattle_single TRAINER_JAIDEN, Route115_Text_29B8C1, Route115_Text_29B8E8
	msgbox Route115_Text_29B904, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_1F2B10:: @ 81F2B10
	trainerbattle_single TRAINER_ALIX, Route115_Text_29B9CB, Route115_Text_29B9F6
	msgbox Route115_Text_29BA04, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_1F2B27:: @ 81F2B27
	trainerbattle_single TRAINER_HELENE, Route115_Text_29B92D, Route115_Text_29B958
	msgbox Route115_Text_29B971, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_1F2B3E:: @ 81F2B3E
	trainerbattle_single TRAINER_MARLENE, Route115_Text_29BA2C, Route115_Text_29BA67
	msgbox Route115_Text_29BA87, MSGBOX_AUTOCLOSE
	end

Route115_Text_1F2B55: @ 81F2B55
	.string "Exploring a cave isn't like walking\n"
	.string "on a road.\p"
	.string "You never know when wild POKéMON will\n"
	.string "appear. It's full of suspense.$"

Route115_Text_1F2BC9: @ 81F2BC9
	.string "ROUTE 115\n"
	.string "{DOWN_ARROW} RUSTBORO CITY$"

Route115_Text_1F2BE3: @ 81F2BE3
	.string "METEOR FALLS\n"
	.string "FALLARBOR TOWN THROUGH HERE$"

