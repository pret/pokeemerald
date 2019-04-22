Route118_MapScripts:: @ 81F3DBC
	map_script MAP_SCRIPT_ON_TRANSITION, Route118_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route118_MapScript1_1F3DF3
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route118_MapScript2_1F3E0A
	.byte 0

Route118_OnTransition: @ 81F3DCC
	call Route118_EventScript_28CCC7
	compare VAR_SHOULD_END_UNUSUAL_WEATHER, 1
	call_if_eq Route118_EventScript_273D13
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_118_EAST
	call_if_eq UnusualWeather_StartGroudonWeather
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_118_WEST
	call_if_eq UnusualWeather_StartGroudonWeather
	end

Route118_MapScript1_1F3DF3: @ 81F3DF3
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_118_EAST
	call_if_eq UnusualWeather_EventScript_PlaceTilesRoute118East
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_118_WEST
	call_if_eq UnusualWeather_EventScript_PlaceTilesRoute118West
	end

Route118_MapScript2_1F3E0A: @ 81F3E0A
	map_script_2 VAR_SHOULD_END_UNUSUAL_WEATHER, 1, UnusualWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route118_EventScript_1F3E14:: @ 81F3E14
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_GOOD_ROD, Route118_EventScript_1F3E69
	msgbox Route118_Text_1F427B, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route118_EventScript_1F3E3E
	compare VAR_RESULT, 0
	goto_if_eq Route118_EventScript_1F3E5F
	end

Route118_EventScript_1F3E3E:: @ 81F3E3E
	msgbox Route118_Text_1F42AF, MSGBOX_DEFAULT
	giveitem_std ITEM_GOOD_ROD
	setflag FLAG_RECEIVED_GOOD_ROD
	msgbox Route118_Text_1F42E7, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_1F3E5F:: @ 81F3E5F
	msgbox Route118_Text_1F4319, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_1F3E69:: @ 81F3E69
	msgbox Route118_Text_1F4331, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_1F3E73:: @ 81F3E73
	msgbox Route118_Text_1F4367, MSGBOX_NPC
	end

Route118_EventScript_1F3E7C:: @ 81F3E7C
	msgbox Route118_Text_1F43F4, MSGBOX_SIGN
	end

Route118_EventScript_1F3E85:: @ 81F3E85
	msgbox Route118_Text_1F440E, MSGBOX_SIGN
	end

Route118_EventScript_1F3E8E:: @ 81F3E8E
	lockall
	setvar VAR_0x8008, 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement 19, Route118_Movement_1F3F61
	waitmovement 0
	goto Route118_EventScript_1F3EE4
	end

Route118_EventScript_1F3EAE:: @ 81F3EAE
	lockall
	setvar VAR_0x8008, 1
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	goto Route118_EventScript_1F3EE4
	end

Route118_EventScript_1F3EC4:: @ 81F3EC4
	lockall
	setvar VAR_0x8008, 2
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement 19, Route118_Movement_1F3F63
	waitmovement 0
	goto Route118_EventScript_1F3EE4
	end

Route118_EventScript_1F3EE4:: @ 81F3EE4
	playse SE_DANSA
	applymovement 19, Route118_Movement_1F3F65
	waitmovement 0
	delay 30
	msgbox Route118_Text_1F40BE, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq Route118_EventScript_1F3F28
	compare VAR_0x8008, 1
	call_if_eq Route118_EventScript_1F3F3A
	compare VAR_0x8008, 2
	call_if_eq Route118_EventScript_1F3F4C
	setvar VAR_ROUTE118_STATE, 1
	removeobject 19
	releaseall
	end

Route118_EventScript_1F3F28:: @ 81F3F28
	applymovement EVENT_OBJ_ID_PLAYER, Route118_Movement_1F3F5E
	applymovement 19, Route118_Movement_1F3F69
	waitmovement 0
	return

Route118_EventScript_1F3F3A:: @ 81F3F3A
	applymovement EVENT_OBJ_ID_PLAYER, Route118_Movement_1F3F5E
	applymovement 19, Route118_Movement_1F3F74
	waitmovement 0
	return

Route118_EventScript_1F3F4C:: @ 81F3F4C
	applymovement EVENT_OBJ_ID_PLAYER, Route118_Movement_1F3F5E
	applymovement 19, Route118_Movement_1F3F7E
	waitmovement 0
	return

Route118_Movement_1F3F5E: @ 81F3F5E
	delay_16
	walk_in_place_fastest_right
	step_end

Route118_Movement_1F3F61: @ 81F3F61
	walk_left
	step_end

Route118_Movement_1F3F63: @ 81F3F63
	walk_right
	step_end

Route118_Movement_1F3F65: @ 81F3F65
	jump_2_down
	delay_16
	walk_down
	step_end

Route118_Movement_1F3F69: @ 81F3F69
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route118_Movement_1F3F74: @ 81F3F74
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route118_Movement_1F3F7E: @ 81F3F7E
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route118_EventScript_1F3F87:: @ 81F3F87
	trainerbattle_single TRAINER_ROSE_1, Route118_Text_29D290, Route118_Text_29D2D8, Route118_EventScript_1F3FB3
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route118_EventScript_1F3FD2
	msgbox Route118_Text_29D2FA, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_1F3FB3:: @ 81F3FB3
	special sub_80B4808
	waitmovement 0
	msgbox Route118_Text_29D343, MSGBOX_DEFAULT
	register_matchcall TRAINER_ROSE_1
	release
	end

Route118_EventScript_1F3FD2:: @ 81F3FD2
	trainerbattle_rematch TRAINER_ROSE_1, Route118_Text_29D382, Route118_Text_29D3AA
	msgbox Route118_Text_29D3D9, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_1F3FE9:: @ 81F3FE9
	trainerbattle_single TRAINER_BARNY, Route118_Text_29D515, Route118_Text_29D55C
	msgbox Route118_Text_29D587, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_1F4000:: @ 81F4000
	trainerbattle_single TRAINER_WADE, Route118_Text_29D5DF, Route118_Text_29D64C
	msgbox Route118_Text_29D663, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_1F4017:: @ 81F4017
	trainerbattle_single TRAINER_DALTON_1, Route118_Text_29D6AF, Route118_Text_29D6CD, Route118_EventScript_1F4043
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route118_EventScript_1F4062
	msgbox Route118_Text_29D6D8, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_1F4043:: @ 81F4043
	special sub_80B4808
	waitmovement 0
	msgbox Route118_Text_29D74A, MSGBOX_DEFAULT
	register_matchcall TRAINER_DALTON_1
	release
	end

Route118_EventScript_1F4062:: @ 81F4062
	trainerbattle_rematch TRAINER_DALTON_1, Route118_Text_29D789, Route118_Text_29D7CA
	msgbox Route118_Text_29D7D5, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_1F4079:: @ 81F4079
	trainerbattle_single TRAINER_PERRY, Route118_Text_29D41D, Route118_Text_29D45B
	msgbox Route118_Text_29D46C, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_1F4090:: @ 81F4090
	trainerbattle_single TRAINER_CHESTER, Route118_Text_29D4A6, Route118_Text_29D4C4
	msgbox Route118_Text_29D4DA, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_1F40A7:: @ 81F40A7
	trainerbattle_single TRAINER_DEANDRE, Route118_Text_29D81B, Route118_Text_29D83C
	msgbox Route118_Text_29D872, MSGBOX_AUTOCLOSE
	end

Route118_Text_1F40BE: @ 81F40BE
	.string "STEVEN: Hi, {PLAYER}{KUN}!\p"
	.string "It's me, STEVEN!\n"
	.string "We met in the cave near DEWFORD.\p"
	.string "Have you met many kinds of POKéMON\n"
	.string "since I last saw you?\p"
	.string "There are many, many kinds of POKéMON\n"
	.string "in this wide world of ours.\p"
	.string "If you wanted to raise only your\n"
	.string "favorites, that's fine.\p"
	.string "Perhaps you find it more fun to raise\n"
	.string "all sorts of POKéMON.\p"
	.string "As a TRAINER of POKéMON,\n"
	.string "what do you think?\p"
	.string "Of course, it's not any of my business.\p"
	.string "It would be nice if we were to meet\n"
	.string "again somewhere.$"

Route118_Text_1F427B: @ 81F427B
	.string "Hmm!\n"
	.string "A GOOD ROD is really good!\p"
	.string "Wouldn't you agree?$"

Route118_Text_1F42AF: @ 81F42AF
	.string "Hmm!\n"
	.string "We're of identical minds!\p"
	.string "Hmm!\n"
	.string "Take this GOOD ROD!$"

Route118_Text_1F42E7: @ 81F42E7
	.string "Wherever there's water, try your luck\n"
	.string "at fishing.$"

Route118_Text_1F4319: @ 81F4319
	.string "Don't you like to fish?$"

Route118_Text_1F4331: @ 81F4331
	.string "Try catching all sorts of POKéMON\n"
	.string "with your GOOD ROD.$"

Route118_Text_1F4367: @ 81F4367
	.string "Even if there isn't a boat, you can\n"
	.string "cross rivers and the sea if you have\l"
	.string "a POKéMON that knows SURF.\p"
	.string "POKéMON can be counted on to do so\n"
	.string "much!$"

Route118_Text_1F43F4: @ 81F43F4
	.string "ROUTE 118\n"
	.string "{LEFT_ARROW} MAUVILLE CITY$"

Route118_Text_1F440E: @ 81F440E
	.string "ROUTE 118\n"
	.string "{UP_ARROW} ROUTE 119$"

