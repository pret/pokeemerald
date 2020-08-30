.set LOCALID_MECHADOLL_1, 1
.set LOCALID_MECHADOLL_2, 2
.set LOCALID_MECHADOLL_3, 3
.set LOCALID_MECHADOLL_4, 4
.set LOCALID_MECHADOLL_5, 5

Route110_TrickHousePuzzle5_MapScripts:: @ 826CAF0
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle5_OnTransition
	.byte 0

Route110_TrickHousePuzzle5_OnTransition: @ 826CAF6
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_8, 0
	end

Route110_TrickHousePuzzle5_EventScript_Scroll:: @ 826CB15
	lockall
	compare VAR_TRICK_HOUSE_PUZZLE_5_STATE, 0
	goto_if_eq Route110_TrickHousePuzzle5_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle5_EventScript_FoundScroll:: @ 826CB27
	setvar VAR_TRICK_HOUSE_PUZZLE_5_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1:: @ 826CB32
	lockall
	applymovement LOCALID_MECHADOLL_1, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_TEMP_1, 1
	goto_if_eq Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2:: @ 826CB53
	lockall
	applymovement LOCALID_MECHADOLL_2, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_TEMP_2, 1
	goto_if_eq Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3:: @ 826CB74
	lockall
	applymovement LOCALID_MECHADOLL_3, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_TEMP_3, 1
	goto_if_eq Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4:: @ 826CB95
	lockall
	applymovement LOCALID_MECHADOLL_4, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_TEMP_4, 1
	goto_if_eq Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll5:: @ 826CBB6
	lockall
	applymovement LOCALID_MECHADOLL_5, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_TEMP_5, 1
	goto_if_eq Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll5Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger0:: @ 826CBD7
	lockall
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger1:: @ 826CBE3
	lockall
	setvar VAR_TEMP_9, 1
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger2:: @ 826CBEF
	lockall
	setvar VAR_TEMP_9, 2
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger3:: @ 826CBFB
	lockall
	setvar VAR_TEMP_9, 3
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger4:: @ 826CC07
	lockall
	setvar VAR_TEMP_9, 4
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger0:: @ 826CC13
	lockall
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger1:: @ 826CC1F
	lockall
	setvar VAR_TEMP_9, 1
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger2:: @ 826CC2B
	lockall
	setvar VAR_TEMP_9, 2
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger3:: @ 826CC37
	lockall
	setvar VAR_TEMP_9, 3
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger4:: @ 826CC43
	lockall
	setvar VAR_TEMP_9, 4
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger5:: @ 826CC4F
	lockall
	setvar VAR_TEMP_9, 5
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger0:: @ 826CC5B
	lockall
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger1:: @ 826CC67
	lockall
	setvar VAR_TEMP_9, 1
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger2:: @ 826CC73
	lockall
	setvar VAR_TEMP_9, 2
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger3:: @ 826CC7F
	lockall
	setvar VAR_TEMP_9, 3
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger4:: @ 826CC8B
	lockall
	setvar VAR_TEMP_9, 4
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger0:: @ 826CC97
	lockall
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger1:: @ 826CCA3
	lockall
	setvar VAR_TEMP_9, 1
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger2:: @ 826CCAF
	lockall
	setvar VAR_TEMP_9, 2
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger3:: @ 826CCBB
	lockall
	setvar VAR_TEMP_9, 3
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger4:: @ 826CCC7
	lockall
	setvar VAR_TEMP_9, 4
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
	end

@ Unused
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger5:: @ 826CCD3
	lockall
	setvar VAR_TEMP_9, 5
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll5Trigger0:: @ 826CCDF
	lockall
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll5Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate:: @ 826CCEB
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_1
	playse SE_PIN
	applymovement LOCALID_MECHADOLL_1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MECHADOLL_1, Common_Movement_Delay48
	waitmovement 0
	compare VAR_TEMP_9, 1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1
	compare VAR_TEMP_9, 2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2
	compare VAR_TEMP_9, 3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3
	compare VAR_TEMP_9, 4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Intro, MSGBOX_DEFAULT
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz1
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz2
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz3
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate:: @ 826CD6A
	setvar VAR_TEMP_2, 1
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_2
	playse SE_PIN
	applymovement LOCALID_MECHADOLL_2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MECHADOLL_2, Common_Movement_Delay48
	waitmovement 0
	compare VAR_TEMP_9, 1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight1
	compare VAR_TEMP_9, 2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight2
	compare VAR_TEMP_9, 3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight3
	compare VAR_TEMP_9, 4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight4
	compare VAR_TEMP_9, 5
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight5
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Intro, MSGBOX_DEFAULT
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz1
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz2
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz3
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate:: @ 826CDF4
	setvar VAR_TEMP_3, 1
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_3
	playse SE_PIN
	applymovement LOCALID_MECHADOLL_3, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MECHADOLL_3, Common_Movement_Delay48
	waitmovement 0
	compare VAR_TEMP_9, 1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1
	compare VAR_TEMP_9, 2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2
	compare VAR_TEMP_9, 3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3
	compare VAR_TEMP_9, 4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Intro, MSGBOX_DEFAULT
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz1
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz2
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz3
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate:: @ 826CE73
	setvar VAR_TEMP_4, 1
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_4
	playse SE_PIN
	applymovement LOCALID_MECHADOLL_4, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MECHADOLL_4, Common_Movement_Delay48
	waitmovement 0
	compare VAR_TEMP_9, 1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1
	compare VAR_TEMP_9, 2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2
	compare VAR_TEMP_9, 3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3
	compare VAR_TEMP_9, 4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Intro, MSGBOX_DEFAULT
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz1
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz2
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz3
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll5Activate:: @ 826CEF2
	setvar VAR_TEMP_5, 1
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_5
	playse SE_PIN
	applymovement LOCALID_MECHADOLL_5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MECHADOLL_5, Common_Movement_Delay48
	waitmovement 0
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Intro, MSGBOX_DEFAULT
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz1
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz2
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz3
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz1:: @ 826CF45
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz1, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL1_Q1, 1
	switch VAR_RESULT
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz2:: @ 826CF68
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz2, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL1_Q2, 1
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz3:: @ 826CF8B
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz3, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL1_Q3, 1
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz1:: @ 826CFAE
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz1, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL2_Q1, 1
	switch VAR_RESULT
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz2:: @ 826CFD1
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz2, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL2_Q2, 1
	switch VAR_RESULT
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz3:: @ 826CFF4
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz3, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL2_Q3, 1
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz1:: @ 826D017
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz1, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL3_Q1, 1
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz2:: @ 826D03A
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz2, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL3_Q2, 1
	switch VAR_RESULT
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz3:: @ 826D05D
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz3, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL3_Q3, 1
	switch VAR_RESULT
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz1:: @ 826D080
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz1, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL4_Q1, 1
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz2:: @ 826D0A3
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz2, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL4_Q2, 1
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz3:: @ 826D0C6
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz3, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL4_Q3, 1
	switch VAR_RESULT
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz1:: @ 826D0E9
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz1, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL5_Q1, 1
	switch VAR_RESULT
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz2:: @ 826D10C
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz2, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL5_Q2, 1
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz3:: @ 826D12F
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz3, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL5_Q3, 1
	switch VAR_RESULT
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer:: @ 826D152
	waitse
	playse SE_FAILURE
	msgbox Route110_TrickHousePuzzle5_Text_DisappointmentError, MSGBOX_DEFAULT
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_MechadollShake
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_MechadollShake
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_MechadollShake
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_MechadollShake
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_MechadollShake
	msgbox Route110_TrickHousePuzzle5_Text_Wahahahaha, MSGBOX_DEFAULT
	waitmovement 0
	msgbox Route110_TrickHousePuzzle5_Text_WaitForNextChallenge, MSGBOX_DEFAULT
	closemessage
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE5, 255, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHousePuzzle5_EventScript_CorrectAnswer:: @ 826D1A0
	waitse
	playse SE_SUCCESS
	goto Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
	end

Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough:: @ 826D1AA
	msgbox Route110_TrickHousePuzzle5_Text_CorrectGoThrough, MSGBOX_DEFAULT
	releaseall
	end

@ Absurd redundancy in movement scripts that could be resolved by using VAR_TEMP_8 for applymovement instead
@ Many of the below movement scripts arent even used, see below
@   Mechadoll 2 is the only mechadoll to walk right, all the other WalkRight scripts are unused
@   Mechadoll 5 never walks, all the Mechadoll5Walk scripts are unused
@   No mechadoll walks left 5 paces, all the WalkLeft5 scripts are unused
Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1:: @ 826D1B4
	compare VAR_TEMP_8, LOCALID_MECHADOLL_1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft1
	compare VAR_TEMP_8, LOCALID_MECHADOLL_2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft1
	compare VAR_TEMP_8, LOCALID_MECHADOLL_3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft1
	compare VAR_TEMP_8, LOCALID_MECHADOLL_4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft1
	compare VAR_TEMP_8, LOCALID_MECHADOLL_5
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft1
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2:: @ 826D1EC
	compare VAR_TEMP_8, LOCALID_MECHADOLL_1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft2
	compare VAR_TEMP_8, LOCALID_MECHADOLL_2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft2
	compare VAR_TEMP_8, LOCALID_MECHADOLL_3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft2
	compare VAR_TEMP_8, LOCALID_MECHADOLL_4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft2
	compare VAR_TEMP_8, LOCALID_MECHADOLL_5
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft2
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3:: @ 826D224
	compare VAR_TEMP_8, LOCALID_MECHADOLL_1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft3
	compare VAR_TEMP_8, LOCALID_MECHADOLL_2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft3
	compare VAR_TEMP_8, LOCALID_MECHADOLL_3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft3
	compare VAR_TEMP_8, LOCALID_MECHADOLL_4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft3
	compare VAR_TEMP_8, LOCALID_MECHADOLL_5
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft3
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4:: @ 826D25C
	compare VAR_TEMP_8, LOCALID_MECHADOLL_1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft4
	compare VAR_TEMP_8, LOCALID_MECHADOLL_2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft4
	compare VAR_TEMP_8, LOCALID_MECHADOLL_3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft4
	compare VAR_TEMP_8, LOCALID_MECHADOLL_4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft4
	compare VAR_TEMP_8, LOCALID_MECHADOLL_5
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft4
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft5:: @ 826D294
	compare VAR_TEMP_8, LOCALID_MECHADOLL_1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft5
	compare VAR_TEMP_8, LOCALID_MECHADOLL_2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft5
	compare VAR_TEMP_8, LOCALID_MECHADOLL_3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft5
	compare VAR_TEMP_8, LOCALID_MECHADOLL_4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft5
	compare VAR_TEMP_8, LOCALID_MECHADOLL_5
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft5
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight1:: @ 826D2CC
	compare VAR_TEMP_8, LOCALID_MECHADOLL_1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight1
	compare VAR_TEMP_8, LOCALID_MECHADOLL_2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight1
	compare VAR_TEMP_8, LOCALID_MECHADOLL_3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight1
	compare VAR_TEMP_8, LOCALID_MECHADOLL_4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight1
	compare VAR_TEMP_8, LOCALID_MECHADOLL_5
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight1
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight2:: @ 826D304
	compare VAR_TEMP_8, LOCALID_MECHADOLL_1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight2
	compare VAR_TEMP_8, LOCALID_MECHADOLL_2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight2
	compare VAR_TEMP_8, LOCALID_MECHADOLL_3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight2
	compare VAR_TEMP_8, LOCALID_MECHADOLL_4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight2
	compare VAR_TEMP_8, LOCALID_MECHADOLL_5
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight2
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight3:: @ 826D33C
	compare VAR_TEMP_8, LOCALID_MECHADOLL_1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight3
	compare VAR_TEMP_8, LOCALID_MECHADOLL_2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight3
	compare VAR_TEMP_8, LOCALID_MECHADOLL_3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight3
	compare VAR_TEMP_8, LOCALID_MECHADOLL_4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight3
	compare VAR_TEMP_8, LOCALID_MECHADOLL_5
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight3
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight4:: @ 826D374
	compare VAR_TEMP_8, LOCALID_MECHADOLL_1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight4
	compare VAR_TEMP_8, LOCALID_MECHADOLL_2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight4
	compare VAR_TEMP_8, LOCALID_MECHADOLL_3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight4
	compare VAR_TEMP_8, LOCALID_MECHADOLL_4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight4
	compare VAR_TEMP_8, LOCALID_MECHADOLL_5
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight4
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight5:: @ 826D3AC
	compare VAR_TEMP_8, LOCALID_MECHADOLL_1
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight5
	compare VAR_TEMP_8, LOCALID_MECHADOLL_2
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight5
	compare VAR_TEMP_8, LOCALID_MECHADOLL_3
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight5
	compare VAR_TEMP_8, LOCALID_MECHADOLL_4
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight5
	compare VAR_TEMP_8, LOCALID_MECHADOLL_5
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight5
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft1:: @ 826D3E4
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft1
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft1:: @ 826D3EF
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft1
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft1:: @ 826D3FA
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft1
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft1:: @ 826D405
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft1
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft1:: @ 826D410
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft1
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft2:: @ 826D41B
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft2
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft2:: @ 826D426
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft2
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft2:: @ 826D431
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft2
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft2:: @ 826D43C
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft2
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft2:: @ 826D447
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft2
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft3:: @ 826D452
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft3
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft3:: @ 826D45D
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft3
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft3:: @ 826D468
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft3
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft3:: @ 826D473
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft3
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft3:: @ 826D47E
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft3
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft4:: @ 826D489
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft4
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft4:: @ 826D494
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft4
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft4:: @ 826D49F
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft4
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft4:: @ 826D4AA
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft4
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft4:: @ 826D4B5
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft4
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft5:: @ 826D4C0
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft5
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft5:: @ 826D4CB
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft5
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft5:: @ 826D4D6
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft5
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft5:: @ 826D4E1
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft5
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft5:: @ 826D4EC
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft5
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight1:: @ 826D4F7
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight1
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight1:: @ 826D502
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight1
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight1:: @ 826D50D
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight1
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight1:: @ 826D518
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight1
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight1:: @ 826D523
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight1
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight2:: @ 826D52E
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight2
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight2:: @ 826D539
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight2
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight2:: @ 826D544
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight2
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight2:: @ 826D54F
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight2
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight2:: @ 826D55A
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight2
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight3:: @ 826D565
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight3
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight3:: @ 826D570
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight3
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight3:: @ 826D57B
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight3
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight3:: @ 826D586
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight3
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight3:: @ 826D591
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight3
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight4:: @ 826D59C
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight4
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight4:: @ 826D5A7
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight4
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight4:: @ 826D5B2
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight4
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight4:: @ 826D5BD
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight4
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight4:: @ 826D5C8
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight4
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight5:: @ 826D5D3
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight5
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight5:: @ 826D5DE
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight5
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight5:: @ 826D5E9
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight5
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight5:: @ 826D5F4
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight5
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight5:: @ 826D5FF
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight5
	waitmovement 0
	return

Route110_TrickHousePuzzle5_Movement_WalkLeft1: @ 826D60A
	walk_left
	step_end

Route110_TrickHousePuzzle5_Movement_WalkLeft2: @ 826D60C
	walk_left
	walk_left
	step_end

Route110_TrickHousePuzzle5_Movement_WalkLeft3: @ 826D60F
	walk_left
	walk_left
	walk_left
	step_end

Route110_TrickHousePuzzle5_Movement_WalkLeft4: @ 826D613
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route110_TrickHousePuzzle5_Movement_WalkLeft5: @ 826D618
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route110_TrickHousePuzzle5_Movement_WalkRight1: @ 826D61E
	walk_right
	step_end

Route110_TrickHousePuzzle5_Movement_WalkRight2: @ 826D620
	walk_right
	walk_right
	step_end

Route110_TrickHousePuzzle5_Movement_WalkRight3: @ 826D623
	walk_right
	walk_right
	walk_right
	step_end

Route110_TrickHousePuzzle5_Movement_WalkRight4: @ 826D627
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route110_TrickHousePuzzle5_Movement_WalkRight5: @ 826D62C
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route110_TrickHousePuzzle5_Movement_MechadollShake: @ 826D632
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_down
	step_end

Route110_TrickHousePuzzle5_Text_WroteSecretCodeLockOpened: @ 826D660
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER is a genius.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

Route110_TrickHousePuzzle5_Text_Mechadoll1Intro: @ 826D6CE
	.string "CLICKETY-CLACK…\n"
	.string "MECHADOLL 1 AM I!\p"
	.string "IF YOU ANSWER QUIZZES CORRECTLY,\n"
	.string "THEN YOU WILL GO TO MECHADOLL 5.\l"
	.string "THEN YOU CAN OBTAIN THE SECRET CODE.$"

Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz1: @ 826D757
	.string "MECHADOLL 1 QUIZ.\p"
	.string "One of these POKéMON is not found\n"
	.string "on ROUTE 110. Which one is it?$"

Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz2: @ 826D7AA
	.string "MECHADOLL 1 QUIZ.\p"
	.string "One of these POKéMON is not of the\n"
	.string "WATER type. Which one is it?$"

Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz3: @ 826D7FC
	.string "MECHADOLL 1 QUIZ.\p"
	.string "One of these POKéMON does not use\n"
	.string "LEECH LIFE. Which one is it?$"

Route110_TrickHousePuzzle5_Text_CorrectGoThrough: @ 826D84D
	.string "CONGRATULATIONS. CORRECT YOU ARE.\n"
	.string "GO THROUGH. PLEASE.$"

Route110_TrickHousePuzzle5_Text_DisappointmentError: @ 826D883
	.string "BZZZT. DISAPPOINTMENT.\n"
	.string "ERROR.$"

Route110_TrickHousePuzzle5_Text_Wahahahaha: @ 826D8A1
	.string "WAHAHAHAHA! WAHAHAHAHA!\n"
	.string "CLICKETY-CLACK!$"

Route110_TrickHousePuzzle5_Text_WaitForNextChallenge: @ 826D8C9
	.string "YOUR NEXT CHALLENGE WE WAIT FOR.$"

Route110_TrickHousePuzzle5_Text_Mechadoll2Intro: @ 826D8EA
	.string "CLICKETY-CLACK…\n"
	.string "MECHADOLL 2 AM I!\p"
	.string "MECHADOLL 1'S QUIZ DIFFICULTY LEVEL\n"
	.string "IS SET TOO LOW.$"

Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz1: @ 826D940
	.string "MECHADOLL 2 QUIZ.\p"
	.string "Which of these POKéMON did WALLY\n"
	.string "borrow from your father?$"

Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz2: @ 826D98C
	.string "MECHADOLL 2 QUIZ.\p"
	.string "Which of these POKéMON was chasing\n"
	.string "PROF. BIRCH?$"

Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz3: @ 826D9CE
	.string "MECHADOLL 2 QUIZ.\p"
	.string "Which of these POKéMON did TEAM AQUA\n"
	.string "use in PETALBURG FOREST?$"

Route110_TrickHousePuzzle5_Text_Mechadoll3Intro: @ 826DA1E
	.string "CLICKETY-CLACK…\n"
	.string "MECHADOLL 3 AM I!\p"
	.string "MATTERS OF MONEY ARE MY SOLE FOCUS.$"

Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz1: @ 826DA64
	.string "MECHADOLL 3 QUIZ.\p"
	.string "Which costs more?\n"
	.string "Three HARBOR MAILS or one BURN HEAL?$"

Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz2: @ 826DAAD
	.string "MECHADOLL 3 QUIZ.\p"
	.string "Sell one GREAT BALL and buy\n"
	.string "one POTION. How much money remains?$"

Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz3: @ 826DAFF
	.string "MECHADOLL 3 QUIZ.\p"
	.string "Do one REPEL and SODA POP cost\n"
	.string "more than one SUPER POTION?$"

Route110_TrickHousePuzzle5_Text_Mechadoll4Intro: @ 826DB4C
	.string "CLICKETY-CLACK…\n"
	.string "MECHADOLL 4 THAT IS ME!\p"
	.string "MY QUIZ IS AN OBJECT OF BEAUTY.$"

Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz1: @ 826DB94
	.string "MECHADOLL 4 QUIZ.\p"
	.string "In SEASHORE HOUSE, were there more men\n"
	.string "or women?$"

Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz2: @ 826DBD7
	.string "MECHADOLL 4 QUIZ.\p"
	.string "In LAVARIDGE TOWN, were there more\n"
	.string "elderly men or elderly women?$"

Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz3: @ 826DC2A
	.string "MECHADOLL 4 QUIZ.\p"
	.string "In the TRAINER'S SCHOOL, how many\n"
	.string "girl students were there?$"

Route110_TrickHousePuzzle5_Text_Mechadoll5Intro: @ 826DC78
	.string "CLICKETY-CLACK…\n"
	.string "MECHADOLL 5 AM I!\p"
	.string "THE MASTER'S BEST AND PROUDEST\n"
	.string "ACHIEVEMENT AM I.$"

Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz1: @ 826DCCB
	.string "MECHADOLL 5 QUIZ.\p"
	.string "In SLATEPORT's POKéMON FAN CLUB,\n"
	.string "how many POKéMON were there?$"

Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz2: @ 826DD1B
	.string "MECHADOLL 5 QUIZ.\p"
	.string "In FORTREE CITY, how many\n"
	.string "tree houses were there?$"

Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz3: @ 826DD5F
	.string "MECHADOLL 5 QUIZ.\p"
	.string "On the CYCLING ROAD, how many\n"
	.string "TRIATHLETES were there?$"
