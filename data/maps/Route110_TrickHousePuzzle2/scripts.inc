Route110_TrickHousePuzzle2_MapScripts:: @ 826BB73
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHousePuzzle2_MapScript1_26BB7E
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle2_OnTransition
	.byte 0

Route110_TrickHousePuzzle2_MapScript1_26BB7E: @ 826BB7E
	compare VAR_TEMP_1, 1
	call_if_eq Route110_TrickHousePuzzle2_EventScript_26BC29
	compare VAR_TEMP_2, 1
	call_if_eq Route110_TrickHousePuzzle2_EventScript_26BC3C
	compare VAR_TEMP_3, 1
	call_if_eq Route110_TrickHousePuzzle2_EventScript_26BC4F
	compare VAR_TEMP_4, 1
	call_if_eq Route110_TrickHousePuzzle2_EventScript_26BC62
	end

Route110_TrickHousePuzzle2_OnTransition: @ 826BBAB
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	end

Route110_TrickHousePuzzle2_EventScript_26BBC0:: @ 826BBC0
	lockall
	compare VAR_TRICK_HOUSE_PUZZLE_2_STATE, 0
	goto_if_eq Route110_TrickHousePuzzle2_EventScript_26BBD2
	goto Route110_TrickHousePuzzle2_EventScript_26A3DB
	end

Route110_TrickHousePuzzle2_EventScript_26BBD2:: @ 826BBD2
	setvar VAR_TRICK_HOUSE_PUZZLE_2_STATE, 1
	goto Route110_TrickHousePuzzle2_EventScript_26A3E5
	end

Route110_TrickHousePuzzle2_EventScript_26BBDD:: @ 826BBDD
	lockall
	setvar VAR_TEMP_1, 1
	playse SE_PIN
	call Route110_TrickHousePuzzle2_EventScript_26BC29
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_26BBF0:: @ 826BBF0
	lockall
	setvar VAR_TEMP_2, 1
	playse SE_PIN
	call Route110_TrickHousePuzzle2_EventScript_26BC3C
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_26BC03:: @ 826BC03
	lockall
	setvar VAR_TEMP_3, 1
	playse SE_PIN
	call Route110_TrickHousePuzzle2_EventScript_26BC4F
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_26BC16:: @ 826BC16
	lockall
	setvar VAR_TEMP_4, 1
	playse SE_PIN
	call Route110_TrickHousePuzzle2_EventScript_26BC62
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_26BC29:: @ 826BC29
	setmetatile 11, 12, METATILE_TrickHousePuzzle_Button_Pressed, 0
	setmetatile 1, 13, METATILE_TrickHousePuzzle_Door_Shuttered, 0
	return

Route110_TrickHousePuzzle2_EventScript_26BC3C:: @ 826BC3C
	setmetatile 0, 4, METATILE_TrickHousePuzzle_Button_Pressed, 0
	setmetatile 5, 6, METATILE_TrickHousePuzzle_Door_Shuttered, 0
	return

Route110_TrickHousePuzzle2_EventScript_26BC4F:: @ 826BC4F
	setmetatile 14, 5, METATILE_TrickHousePuzzle_Button_Pressed, 0
	setmetatile 7, 15, METATILE_TrickHousePuzzle_Door_Shuttered, 0
	return

Route110_TrickHousePuzzle2_EventScript_26BC62:: @ 826BC62
	setmetatile 7, 11, METATILE_TrickHousePuzzle_Button_Pressed, 0
	setmetatile 14, 12, METATILE_TrickHousePuzzle_Door_Shuttered, 0
	return

Route110_TrickHousePuzzle2_EventScript_26BC75:: @ 826BC75
	trainerbattle_single TRAINER_TED, Route110_TrickHousePuzzle2_Text_26BD25, Route110_TrickHousePuzzle2_Text_26BD45
	msgbox Route110_TrickHousePuzzle2_Text_26BD70, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle2_EventScript_26BC8C:: @ 826BC8C
	trainerbattle_single TRAINER_PAUL, Route110_TrickHousePuzzle2_Text_26BD9E, Route110_TrickHousePuzzle2_Text_26BDCF
	msgbox Route110_TrickHousePuzzle2_Text_26BDEC, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle2_EventScript_26BCA3:: @ 826BCA3
	trainerbattle_single TRAINER_GEORGIA, Route110_TrickHousePuzzle2_Text_26BE31, Route110_TrickHousePuzzle2_Text_26BE77
	msgbox Route110_TrickHousePuzzle2_Text_26BE97, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle2_Text_26BCBA: @ 826BCBA
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER is smart.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

Route110_TrickHousePuzzle2_Text_26BD25: @ 826BD25
	.string "Which switch closes which hole?$"

Route110_TrickHousePuzzle2_Text_26BD45: @ 826BD45
	.string "After that battle, I'm even more\n"
	.string "confused!$"

Route110_TrickHousePuzzle2_Text_26BD70: @ 826BD70
	.string "Can I get you to push all the buttons\n"
	.string "for me?$"

Route110_TrickHousePuzzle2_Text_26BD9E: @ 826BD9E
	.string "Oh! You're on your second TRICK HOUSE\n"
	.string "challenge!$"

Route110_TrickHousePuzzle2_Text_26BDCF: @ 826BDCF
	.string "You're good at battling too?$"

Route110_TrickHousePuzzle2_Text_26BDEC: @ 826BDEC
	.string "The TRICK MASTER rigged all the tricks\n"
	.string "in this house all by himself.$"

Route110_TrickHousePuzzle2_Text_26BE31: @ 826BE31
	.string "I want to make my own GYM one day.\n"
	.string "So, I'm studying how to set traps.$"

Route110_TrickHousePuzzle2_Text_26BE77: @ 826BE77
	.string "I didn't study battling enough!$"

Route110_TrickHousePuzzle2_Text_26BE97: @ 826BE97
	.string "You're strong, aren't you?\n"
	.string "Maybe even enough to be a GYM LEADER!$"

