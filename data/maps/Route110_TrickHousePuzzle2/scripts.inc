Route110_TrickHousePuzzle2_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHousePuzzle2_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle2_OnTransition
	.byte 0

Route110_TrickHousePuzzle2_OnResume:
	compare VAR_TEMP_1, 1
	call_if_eq Route110_TrickHousePuzzle2_EventScript_PressButton1
	compare VAR_TEMP_2, 1
	call_if_eq Route110_TrickHousePuzzle2_EventScript_PressButton2
	compare VAR_TEMP_3, 1
	call_if_eq Route110_TrickHousePuzzle2_EventScript_PressButton3
	compare VAR_TEMP_4, 1
	call_if_eq Route110_TrickHousePuzzle2_EventScript_PressButton4
	end

Route110_TrickHousePuzzle2_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	end

Route110_TrickHousePuzzle2_EventScript_Scroll::
	lockall
	compare VAR_TRICK_HOUSE_PUZZLE_2_STATE, 0
	goto_if_eq Route110_TrickHousePuzzle2_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle2_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_2_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle2_EventScript_Button1::
	lockall
	setvar VAR_TEMP_1, 1
	playse SE_PIN
	call Route110_TrickHousePuzzle2_EventScript_PressButton1
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_Button2::
	lockall
	setvar VAR_TEMP_2, 1
	playse SE_PIN
	call Route110_TrickHousePuzzle2_EventScript_PressButton2
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_Button3::
	lockall
	setvar VAR_TEMP_3, 1
	playse SE_PIN
	call Route110_TrickHousePuzzle2_EventScript_PressButton3
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_Button4::
	lockall
	setvar VAR_TEMP_4, 1
	playse SE_PIN
	call Route110_TrickHousePuzzle2_EventScript_PressButton4
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_PressButton1::
	setmetatile 11, 12, METATILE_TrickHousePuzzle_Button_Pressed, 0
	setmetatile 1, 13, METATILE_TrickHousePuzzle_Door_Shuttered, 0
	return

Route110_TrickHousePuzzle2_EventScript_PressButton2::
	setmetatile 0, 4, METATILE_TrickHousePuzzle_Button_Pressed, 0
	setmetatile 5, 6, METATILE_TrickHousePuzzle_Door_Shuttered, 0
	return

Route110_TrickHousePuzzle2_EventScript_PressButton3::
	setmetatile 14, 5, METATILE_TrickHousePuzzle_Button_Pressed, 0
	setmetatile 7, 15, METATILE_TrickHousePuzzle_Door_Shuttered, 0
	return

Route110_TrickHousePuzzle2_EventScript_PressButton4::
	setmetatile 7, 11, METATILE_TrickHousePuzzle_Button_Pressed, 0
	setmetatile 14, 12, METATILE_TrickHousePuzzle_Door_Shuttered, 0
	return

Route110_TrickHousePuzzle2_EventScript_Ted::
	trainerbattle_single TRAINER_TED, Route110_TrickHousePuzzle2_Text_TedIntro, Route110_TrickHousePuzzle2_Text_TedDefeat
	msgbox Route110_TrickHousePuzzle2_Text_TedPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle2_EventScript_Paul::
	trainerbattle_single TRAINER_PAUL, Route110_TrickHousePuzzle2_Text_PaulIntro, Route110_TrickHousePuzzle2_Text_PaulDefeat
	msgbox Route110_TrickHousePuzzle2_Text_PaulPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle2_EventScript_Georgia::
	trainerbattle_single TRAINER_GEORGIA, Route110_TrickHousePuzzle2_Text_GeorgiaIntro, Route110_TrickHousePuzzle2_Text_GeorgiaDefeat
	msgbox Route110_TrickHousePuzzle2_Text_GeorgiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle2_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER is smart.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

Route110_TrickHousePuzzle2_Text_TedIntro:
	.string "Which switch closes which hole?$"

Route110_TrickHousePuzzle2_Text_TedDefeat:
	.string "After that battle, I'm even more\n"
	.string "confused!$"

Route110_TrickHousePuzzle2_Text_TedPostBattle:
	.string "Can I get you to push all the buttons\n"
	.string "for me?$"

Route110_TrickHousePuzzle2_Text_PaulIntro:
	.string "Oh! You're on your second TRICK HOUSE\n"
	.string "challenge!$"

Route110_TrickHousePuzzle2_Text_PaulDefeat:
	.string "You're good at battling too?$"

Route110_TrickHousePuzzle2_Text_PaulPostBattle:
	.string "The TRICK MASTER rigged all the tricks\n"
	.string "in this house all by himself.$"

Route110_TrickHousePuzzle2_Text_GeorgiaIntro:
	.string "I want to make my own GYM one day.\n"
	.string "So, I'm studying how to set traps.$"

Route110_TrickHousePuzzle2_Text_GeorgiaDefeat:
	.string "I didn't study battling enough!$"

Route110_TrickHousePuzzle2_Text_GeorgiaPostBattle:
	.string "You're strong, aren't you?\n"
	.string "Maybe even enough to be a GYM LEADER!$"

