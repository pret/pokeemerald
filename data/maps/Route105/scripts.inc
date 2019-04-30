Route105_MapScripts:: @ 81EE1DB
	map_script MAP_SCRIPT_ON_LOAD, Route105_MapScript1_1EE1EB
	map_script MAP_SCRIPT_ON_TRANSITION, Route105_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route105_MapScript2_1EE240
	.byte 0

Route105_MapScript1_1EE1EB: @ 81EE1EB
	call_if_unset FLAG_REGI_DOORS_OPENED, Route105_EventScript_1EE20B
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_105_NORTH
	call_if_eq UnusualWeather_EventScript_PlaceTilesRoute105North
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_105_SOUTH
	call_if_eq UnusualWeather_EventScript_PlaceTilesRoute105South
	end

Route105_EventScript_1EE20B:: @ 81EE20B
	setmetatile 9, 19, 124, 1
	setmetatile 9, 20, 145, 1
	return

Route105_OnTransition: @ 81EE21E
	compare VAR_SHOULD_END_UNUSUAL_WEATHER, 1
	call_if_eq Route105_EventScript_273D13
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_105_NORTH
	call_if_eq UnusualWeather_StartKyogreWeather
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_105_SOUTH
	call_if_eq UnusualWeather_StartKyogreWeather
	end

Route105_MapScript2_1EE240: @ 81EE240
	map_script_2 VAR_SHOULD_END_UNUSUAL_WEATHER, 1, UnusualWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route105_EventScript_1EE24A:: @ 81EE24A
	trainerbattle_single TRAINER_FOSTER, Route105_Text_295D0F, Route105_Text_295D62
	msgbox Route105_Text_295DAB, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_1EE261:: @ 81EE261
	trainerbattle_single TRAINER_LUIS, Route105_Text_295DF5, Route105_Text_295E66
	msgbox Route105_Text_295E72, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_1EE278:: @ 81EE278
	trainerbattle_single TRAINER_DOMINIK, Route105_Text_295EB7, Route105_Text_295EEA
	msgbox Route105_Text_295F08, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_1EE28F:: @ 81EE28F
	trainerbattle_single TRAINER_BEVERLY, Route105_Text_295F5C, Route105_Text_295FA0
	msgbox Route105_Text_295FAE, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_1EE2A6:: @ 81EE2A6
	trainerbattle_single TRAINER_IMANI, Route105_Text_296025, Route105_Text_296059
	msgbox Route105_Text_296076, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_1EE2BD:: @ 81EE2BD
	trainerbattle_single TRAINER_JOSUE, Route105_Text_29626F, Route105_Text_2962CB
	msgbox Route105_Text_2962EC, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_1EE2D4:: @ 81EE2D4
	trainerbattle_single TRAINER_ANDRES_1, Route105_Text_2960A9, Route105_Text_2960DB, Route105_EventScript_1EE300
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route105_EventScript_1EE31F
	msgbox Route105_Text_2960FA, MSGBOX_DEFAULT
	release
	end

Route105_EventScript_1EE300:: @ 81EE300
	special sub_80B4808
	waitmovement 0
	msgbox Route105_Text_296159, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANDRES_1
	release
	end

Route105_EventScript_1EE31F:: @ 81EE31F
	trainerbattle_rematch TRAINER_ANDRES_1, Route105_Text_29619E, Route105_Text_2961DD
	msgbox Route105_Text_2961FE, MSGBOX_AUTOCLOSE
	end

Route104_Text_1EE336: @ 81EE336
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "DAD: Oh, {PLAYER}?\p"
	.string "… … … … … …\n"
	.string "Where are you now?\l"
	.string "It sounds windy wherever you are.\p"
	.string "I just heard from DEVON's MR. STONE\n"
	.string "about your POKéNAV, so I decided\l"
	.string "to give you a call.\p"
	.string "It sounds like you're doing fine,\n"
	.string "so that's fine with me.\p"
	.string "You take care now.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Route104_Text_1EE463: @ 81EE463
	.string "Registered DAD NORMAN\n"
	.string "in the POKéNAV.$"
