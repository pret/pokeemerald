Route114_MapScripts:: @ 81F252F
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_MapScript1_1F2561
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route114_MapScript2_1F2578
	.byte 0

Route114_OnTransition: @ 81F253F
	compare VAR_SHOULD_END_UNUSUAL_WEATHER, 1
	call_if_eq Route114_EventScript_273D13
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_114_NORTH
	call_if_eq UnusualWeather_StartGroudonWeather
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_114_SOUTH
	call_if_eq UnusualWeather_StartGroudonWeather
	end

Route114_MapScript1_1F2561: @ 81F2561
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_114_NORTH
	call_if_eq UnusualWeather_EventScript_PlaceTilesRoute114North
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_114_SOUTH
	call_if_eq UnusualWeather_EventScript_PlaceTilesRoute114South
	end

Route114_MapScript2_1F2578: @ 81F2578
	map_script_2 VAR_SHOULD_END_UNUSUAL_WEATHER, 1, UnusualWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route114_EventScript_1F2582:: @ 81F2582
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_ROUTE_114_RECEIVED_BERRY, Route114_EventScript_1F25C7
	msgbox Route114_Text_2A6FCB, MSGBOX_DEFAULT
	random 5
	addvar VAR_RESULT, 15
	addvar VAR_RESULT, 133
	giveitem_std VAR_RESULT
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_ROUTE_114_RECEIVED_BERRY
	msgbox Route114_Text_2A7034, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_1F25C7:: @ 81F25C7
	msgbox Route114_Text_2A706E, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_1F25D1:: @ 81F25D1
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM05, Route114_EventScript_1F2608
	msgbox Route114_Text_1F2809, MSGBOX_DEFAULT
	giveitem_std ITEM_TM05
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM05
	msgbox Route114_Text_1F2872, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_1F2608:: @ 81F2608
	msgbox Route114_Text_1F2872, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_1F2612:: @ 81F2612
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POOCHYENA, 2
	msgbox Route114_Text_1F28A6, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route114_EventScript_1F2625:: @ 81F2625
	msgbox Route114_Text_1F28B3, MSGBOX_SIGN
	end

Route114_EventScript_1F262E:: @ 81F262E
	msgbox Route114_Text_1F28DB, MSGBOX_SIGN
	end

Route114_EventScript_1F2637:: @ 81F2637
	msgbox Route114_Text_1F2910, MSGBOX_SIGN
	end

Route114_EventScript_1F2640:: @ 81F2640
	trainerbattle_single TRAINER_LENNY, Route114_Text_29A6B1, Route114_Text_29A707
	msgbox Route114_Text_29A715, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_1F2657:: @ 81F2657
	trainerbattle_single TRAINER_LUCAS_1, Route114_Text_29A777, Route114_Text_29A7B5
	msgbox Route114_Text_29A7D4, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_1F266E:: @ 81F266E
	trainerbattle_single TRAINER_SHANE, Route114_Text_29A818, Route114_Text_29A88F
	msgbox Route114_Text_29A89F, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_1F2685:: @ 81F2685
	trainerbattle_single TRAINER_NANCY, Route114_Text_29A8D9, Route114_Text_29A90E
	msgbox Route114_Text_29A916, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_1F269C:: @ 81F269C
	trainerbattle_single TRAINER_STEVE_1, Route114_Text_29A943, Route114_Text_29A973, Route114_EventScript_1F26C8
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route114_EventScript_1F26E7
	msgbox Route114_Text_29A981, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_1F26C8:: @ 81F26C8
	special sub_80B4808
	waitmovement 0
	msgbox Route114_Text_29A9F7, MSGBOX_DEFAULT
	register_matchcall TRAINER_STEVE_1
	release
	end

Route114_EventScript_1F26E7:: @ 81F26E7
	trainerbattle_rematch TRAINER_STEVE_1, Route114_Text_29AA3E, Route114_Text_29AA67
	msgbox Route114_Text_29AA94, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_1F26FE:: @ 81F26FE
	trainerbattle_single TRAINER_BERNIE_1, Route114_Text_29AADB, Route114_Text_29AB1A, Route114_EventScript_1F272A
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route114_EventScript_1F2749
	msgbox Route114_Text_29AB36, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_1F272A:: @ 81F272A
	special sub_80B4808
	waitmovement 0
	msgbox Route114_Text_29ABA6, MSGBOX_DEFAULT
	register_matchcall TRAINER_BERNIE_1
	release
	end

Route114_EventScript_1F2749:: @ 81F2749
	trainerbattle_rematch TRAINER_BERNIE_1, Route114_Text_29ABDC, Route114_Text_29AC10
	msgbox Route114_Text_29AC43, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_1F2760:: @ 81F2760
	trainerbattle_single TRAINER_CLAUDE, Route114_Text_29ACB3, Route114_Text_29AD0A
	msgbox Route114_Text_29AD2E, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_1F2777:: @ 81F2777
	trainerbattle_single TRAINER_NOLAN, Route114_Text_29ADA1, Route114_Text_29AE05
	msgbox Route114_Text_29AE3D, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_1F278E:: @ 81F278E
	trainerbattle_double TRAINER_TYRA_AND_IVY, Route114_Text_29AE96, Route114_Text_29AEE7, Route114_Text_29AF3D
	msgbox Route114_Text_29AF0B, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_1F27A9:: @ 81F27A9
	trainerbattle_double TRAINER_TYRA_AND_IVY, Route114_Text_29AF89, Route114_Text_29AFAC, Route114_Text_29B01B
	msgbox Route114_Text_29AFCF, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_1F27C4:: @ 81F27C4
	trainerbattle_single TRAINER_ANGELINA, Route114_Text_29B16F, Route114_Text_29B19C
	msgbox Route114_Text_29B1BC, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_1F27DB:: @ 81F27DB
	trainerbattle_single TRAINER_CHARLOTTE, Route114_Text_29B0DB, Route114_Text_29B0FB
	msgbox Route114_Text_29B11A, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_1F27F2:: @ 81F27F2
	trainerbattle_single TRAINER_KAI, Route114_Text_29B05D, Route114_Text_29B089
	msgbox Route114_Text_29B0B5, MSGBOX_AUTOCLOSE
	end

Route114_Text_1F2809: @ 81F2809
	.string "All my POKéMON does is ROAR…\n"
	.string "No one dares to come near me…\p"
	.string "Sigh… If you would, please take\n"
	.string "this TM away…$"

Route114_Text_1F2872: @ 81F2872
	.string "TM05 contains ROAR.\n"
	.string "A ROAR sends POKéMON scurrying.$"

Route114_Text_1F28A6: @ 81F28A6
	.string "Bow! Bowwow!$"

Route114_Text_1F28B3: @ 81F28B3
	.string "METEOR FALLS\n"
	.string "RUSTBORO CITY THROUGH HERE$"

Route114_Text_1F28DB: @ 81F28DB
	.string "FOSSIL MANIAC'S HOUSE\n"
	.string "“Fossils gratefully accepted!”$"

Route114_Text_1F2910: @ 81F2910
	.string "LANETTE'S HOUSE$"

