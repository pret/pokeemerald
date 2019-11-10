Route110_TrickHousePuzzle2_MapScripts:: @ 826BB73
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHousePuzzle2_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle2_OnTransition
	.byte 0

Route110_TrickHousePuzzle2_OnResume: @ 826BB7E
	compare VAR_TEMP_1, 1
	call_if_eq Route110_TrickHousePuzzle2_EventScript_PressButton1
	compare VAR_TEMP_2, 1
	call_if_eq Route110_TrickHousePuzzle2_EventScript_PressButton2
	compare VAR_TEMP_3, 1
	call_if_eq Route110_TrickHousePuzzle2_EventScript_PressButton3
	compare VAR_TEMP_4, 1
	call_if_eq Route110_TrickHousePuzzle2_EventScript_PressButton4
	end

Route110_TrickHousePuzzle2_OnTransition: @ 826BBAB
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	end

Route110_TrickHousePuzzle2_EventScript_Scroll:: @ 826BBC0
	lockall
	compare VAR_TRICK_HOUSE_PUZZLE_2_STATE, 0
	goto_if_eq Route110_TrickHousePuzzle2_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle2_EventScript_FoundScroll:: @ 826BBD2
	setvar VAR_TRICK_HOUSE_PUZZLE_2_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle2_EventScript_Button1:: @ 826BBDD
	lockall
	setvar VAR_TEMP_1, 1
	playse SE_PIN
	call Route110_TrickHousePuzzle2_EventScript_PressButton1
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_Button2:: @ 826BBF0
	lockall
	setvar VAR_TEMP_2, 1
	playse SE_PIN
	call Route110_TrickHousePuzzle2_EventScript_PressButton2
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_Button3:: @ 826BC03
	lockall
	setvar VAR_TEMP_3, 1
	playse SE_PIN
	call Route110_TrickHousePuzzle2_EventScript_PressButton3
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_Button4:: @ 826BC16
	lockall
	setvar VAR_TEMP_4, 1
	playse SE_PIN
	call Route110_TrickHousePuzzle2_EventScript_PressButton4
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_PressButton1:: @ 826BC29
	setmetatile 11, 12, METATILE_TrickHousePuzzle_Button_Pressed, 0
	setmetatile 1, 13, METATILE_TrickHousePuzzle_Door_Shuttered, 0
	return

Route110_TrickHousePuzzle2_EventScript_PressButton2:: @ 826BC3C
	setmetatile 0, 4, METATILE_TrickHousePuzzle_Button_Pressed, 0
	setmetatile 5, 6, METATILE_TrickHousePuzzle_Door_Shuttered, 0
	return

Route110_TrickHousePuzzle2_EventScript_PressButton3:: @ 826BC4F
	setmetatile 14, 5, METATILE_TrickHousePuzzle_Button_Pressed, 0
	setmetatile 7, 15, METATILE_TrickHousePuzzle_Door_Shuttered, 0
	return

Route110_TrickHousePuzzle2_EventScript_PressButton4:: @ 826BC62
	setmetatile 7, 11, METATILE_TrickHousePuzzle_Button_Pressed, 0
	setmetatile 14, 12, METATILE_TrickHousePuzzle_Door_Shuttered, 0
	return

Route110_TrickHousePuzzle2_EventScript_Ted:: @ 826BC75
	trainerbattle_single TRAINER_TED, Route110_TrickHousePuzzle2_Text_TedIntro, Route110_TrickHousePuzzle2_Text_TedDefeat
	msgbox Route110_TrickHousePuzzle2_Text_TedPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle2_EventScript_Paul:: @ 826BC8C
	trainerbattle_single TRAINER_PAUL, Route110_TrickHousePuzzle2_Text_PaulIntro, Route110_TrickHousePuzzle2_Text_PaulDefeat
	msgbox Route110_TrickHousePuzzle2_Text_PaulPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle2_EventScript_Georgia:: @ 826BCA3
	trainerbattle_single TRAINER_GEORGIA, Route110_TrickHousePuzzle2_Text_GeorgiaIntro, Route110_TrickHousePuzzle2_Text_GeorgiaDefeat
	msgbox Route110_TrickHousePuzzle2_Text_GeorgiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle2_Text_WroteSecretCodeLockOpened: @ 826BCBA
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER is smart.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

Route110_TrickHousePuzzle2_Text_TedIntro: @ 826BD25
	.string "Which switch closes which hole?$"

Route110_TrickHousePuzzle2_Text_TedDefeat: @ 826BD45
	.string "After that battle, I'm even more\n"
	.string "confused!$"

Route110_TrickHousePuzzle2_Text_TedPostBattle: @ 826BD70
	.string "Can I get you to push all the buttons\n"
	.string "for me?$"

Route110_TrickHousePuzzle2_Text_PaulIntro: @ 826BD9E
	.string "Oh! You're on your second TRICK HOUSE\n"
	.string "challenge!$"

Route110_TrickHousePuzzle2_Text_PaulDefeat: @ 826BDCF
	.string "You're good at battling too?$"

Route110_TrickHousePuzzle2_Text_PaulPostBattle: @ 826BDEC
	.string "The TRICK MASTER rigged all the tricks\n"
	.string "in this house all by himself.$"

Route110_TrickHousePuzzle2_Text_GeorgiaIntro: @ 826BE31
	.string "I want to make my own GYM one day.\n"
	.string "So, I'm studying how to set traps.$"

Route110_TrickHousePuzzle2_Text_GeorgiaDefeat: @ 826BE77
	.string "I didn't study battling enough!$"

Route110_TrickHousePuzzle2_Text_GeorgiaPostBattle: @ 826BE97
	.string "You're strong, aren't you?\n"
	.string "Maybe even enough to be a GYM LEADER!$"

