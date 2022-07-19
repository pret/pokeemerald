.set LOCALID_MECHADOLL_1, 1
.set LOCALID_MECHADOLL_2, 2
.set LOCALID_MECHADOLL_3, 3
.set LOCALID_MECHADOLL_4, 4
.set LOCALID_MECHADOLL_5, 5

Route110_TrickHousePuzzle5_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle5_OnTransition
	.byte 0

Route110_TrickHousePuzzle5_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_8, 0
	end

Route110_TrickHousePuzzle5_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_5_STATE, 0, Route110_TrickHousePuzzle5_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle5_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_5_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1::
	lockall
	applymovement LOCALID_MECHADOLL_1, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_TEMP_1, 1, Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2::
	lockall
	applymovement LOCALID_MECHADOLL_2, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_TEMP_2, 1, Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3::
	lockall
	applymovement LOCALID_MECHADOLL_3, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_TEMP_3, 1, Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4::
	lockall
	applymovement LOCALID_MECHADOLL_4, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_TEMP_4, 1, Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll5::
	lockall
	applymovement LOCALID_MECHADOLL_5, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_TEMP_5, 1, Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll5Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger0::
	lockall
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger1::
	lockall
	setvar VAR_TEMP_9, 1
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger2::
	lockall
	setvar VAR_TEMP_9, 2
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger3::
	lockall
	setvar VAR_TEMP_9, 3
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger4::
	lockall
	setvar VAR_TEMP_9, 4
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger0::
	lockall
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger1::
	lockall
	setvar VAR_TEMP_9, 1
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger2::
	lockall
	setvar VAR_TEMP_9, 2
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger3::
	lockall
	setvar VAR_TEMP_9, 3
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger4::
	lockall
	setvar VAR_TEMP_9, 4
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger5::
	lockall
	setvar VAR_TEMP_9, 5
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger0::
	lockall
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger1::
	lockall
	setvar VAR_TEMP_9, 1
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger2::
	lockall
	setvar VAR_TEMP_9, 2
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger3::
	lockall
	setvar VAR_TEMP_9, 3
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger4::
	lockall
	setvar VAR_TEMP_9, 4
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger0::
	lockall
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger1::
	lockall
	setvar VAR_TEMP_9, 1
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger2::
	lockall
	setvar VAR_TEMP_9, 2
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger3::
	lockall
	setvar VAR_TEMP_9, 3
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger4::
	lockall
	setvar VAR_TEMP_9, 4
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
	end

@ Unused
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger5::
	lockall
	setvar VAR_TEMP_9, 5
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll5Trigger0::
	lockall
	setvar VAR_TEMP_9, 0
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll5Activate
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate::
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_1
	playse SE_PIN
	applymovement LOCALID_MECHADOLL_1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MECHADOLL_1, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1
	call_if_eq VAR_TEMP_9, 2, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2
	call_if_eq VAR_TEMP_9, 3, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3
	call_if_eq VAR_TEMP_9, 4, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Intro, MSGBOX_DEFAULT
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz1
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz2
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz3
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate::
	setvar VAR_TEMP_2, 1
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_2
	playse SE_PIN
	applymovement LOCALID_MECHADOLL_2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MECHADOLL_2, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight1
	call_if_eq VAR_TEMP_9, 2, Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight2
	call_if_eq VAR_TEMP_9, 3, Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight3
	call_if_eq VAR_TEMP_9, 4, Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight4
	call_if_eq VAR_TEMP_9, 5, Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight5
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Intro, MSGBOX_DEFAULT
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz1
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz2
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz3
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate::
	setvar VAR_TEMP_3, 1
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_3
	playse SE_PIN
	applymovement LOCALID_MECHADOLL_3, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MECHADOLL_3, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1
	call_if_eq VAR_TEMP_9, 2, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2
	call_if_eq VAR_TEMP_9, 3, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3
	call_if_eq VAR_TEMP_9, 4, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Intro, MSGBOX_DEFAULT
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz1
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz2
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz3
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate::
	setvar VAR_TEMP_4, 1
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_4
	playse SE_PIN
	applymovement LOCALID_MECHADOLL_4, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MECHADOLL_4, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1
	call_if_eq VAR_TEMP_9, 2, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2
	call_if_eq VAR_TEMP_9, 3, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3
	call_if_eq VAR_TEMP_9, 4, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Intro, MSGBOX_DEFAULT
	random 3
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz1
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz2
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz3
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll5Activate::
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

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz1::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz1, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL1_Q1, TRUE
	switch VAR_RESULT
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz2::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz2, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL1_Q2, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz3::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz3, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL1_Q3, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz1::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz1, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL2_Q1, TRUE
	switch VAR_RESULT
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz2::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz2, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL2_Q2, TRUE
	switch VAR_RESULT
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz3::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz3, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL2_Q3, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz1::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz1, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL3_Q1, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz2::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz2, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL3_Q2, TRUE
	switch VAR_RESULT
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz3::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz3, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL3_Q3, TRUE
	switch VAR_RESULT
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz1::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz1, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL4_Q1, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz2::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz2, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL4_Q2, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz3::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz3, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL4_Q3, TRUE
	switch VAR_RESULT
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz1::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz1, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL5_Q1, TRUE
	switch VAR_RESULT
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz2::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz2, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL5_Q2, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz3::
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz3, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MECHADOLL5_Q3, TRUE
	switch VAR_RESULT
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
	end

Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer::
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
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE5, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHousePuzzle5_EventScript_CorrectAnswer::
	waitse
	playse SE_SUCCESS
	goto Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
	end

Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough::
	msgbox Route110_TrickHousePuzzle5_Text_CorrectGoThrough, MSGBOX_DEFAULT
	releaseall
	end

@ Absurd redundancy in movement scripts that could be resolved by using VAR_TEMP_8 for applymovement instead
@ Many of the below movement scripts arent even used, see below
@   Mechadoll 2 is the only mechadoll to walk right, all the other WalkRight scripts are unused
@   Mechadoll 5 never walks, all the Mechadoll5Walk scripts are unused
@   No mechadoll walks left 5 paces, all the WalkLeft5 scripts are unused
Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1::
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft1
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft1
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft1
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft1
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft1
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2::
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft2
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft2
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft2
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft2
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft2
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3::
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft3
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft3
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft3
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft3
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft3
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4::
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft4
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft4
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft4
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft4
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft4
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft5::
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft5
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft5
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft5
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft5
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft5
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight1::
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight1
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight1
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight1
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight1
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight1
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight2::
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight2
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight2
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight2
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight2
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight2
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight3::
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight3
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight3
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight3
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight3
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight3
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight4::
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight4
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight4
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight4
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight4
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight4
	return

Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight5::
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight5
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight5
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight5
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight5
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight5
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft1::
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft1
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft1::
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft1
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft1::
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft1
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft1::
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft1
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft1::
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft1
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft2::
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft2
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft2::
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft2
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft2::
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft2
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft2::
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft2
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft2::
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft2
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft3::
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft3
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft3::
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft3
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft3::
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft3
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft3::
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft3
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft3::
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft3
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft4::
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft4
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft4::
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft4
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft4::
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft4
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft4::
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft4
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft4::
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft4
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft5::
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft5
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft5::
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft5
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft5::
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft5
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft5::
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft5
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft5::
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft5
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight1::
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight1
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight1::
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight1
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight1::
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight1
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight1::
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight1
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight1::
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight1
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight2::
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight2
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight2::
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight2
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight2::
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight2
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight2::
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight2
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight2::
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight2
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight3::
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight3
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight3::
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight3
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight3::
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight3
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight3::
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight3
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight3::
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight3
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight4::
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight4
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight4::
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight4
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight4::
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight4
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight4::
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight4
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight4::
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight4
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight5::
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight5
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight5::
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight5
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight5::
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight5
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight5::
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight5
	waitmovement 0
	return

Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight5::
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight5
	waitmovement 0
	return

Route110_TrickHousePuzzle5_Movement_WalkLeft1:
	walk_left
	step_end

Route110_TrickHousePuzzle5_Movement_WalkLeft2:
	walk_left
	walk_left
	step_end

Route110_TrickHousePuzzle5_Movement_WalkLeft3:
	walk_left
	walk_left
	walk_left
	step_end

Route110_TrickHousePuzzle5_Movement_WalkLeft4:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route110_TrickHousePuzzle5_Movement_WalkLeft5:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route110_TrickHousePuzzle5_Movement_WalkRight1:
	walk_right
	step_end

Route110_TrickHousePuzzle5_Movement_WalkRight2:
	walk_right
	walk_right
	step_end

Route110_TrickHousePuzzle5_Movement_WalkRight3:
	walk_right
	walk_right
	walk_right
	step_end

Route110_TrickHousePuzzle5_Movement_WalkRight4:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route110_TrickHousePuzzle5_Movement_WalkRight5:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route110_TrickHousePuzzle5_Movement_MechadollShake:
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

Route110_TrickHousePuzzle5_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} écrit le code secret\n"
	.string "sur la porte.\p"
	.string "“Le MAITRE DES PIEGES est un génie.”\n"
	.string "… … … … … … … …\p"
	.string "La porte s’ouvre!$"

Route110_TrickHousePuzzle5_Text_Mechadoll1Intro:
	.string "CLINK-CLIC-CLANK-CLAC…\n"
	.string "MECAPOUPEE 1 JE SUIS!\p"
	.string "SI TU REPONDS CORRECTEMENT A CES\n"
	.string "QUESTIONS, TU POURRAS PARLER A\l"
	.string "MECAPOUPEE 5 ET AVOIR LE CODE SECRET.$"

Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz1:
	.string "QUIZ MECAPOUPEE 1.\p"
	.string "L’un de ces POKéMON ne se trouve pas\n"
	.string "sur la ROUTE 110. Lequel?$"

Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz2:
	.string "QUIZ MECAPOUPEE 1.\p"
	.string "L’un de ces POKéMON n’est pas du type\n"
	.string "EAU. Lequel?$"

Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz3:
	.string "QUIZ MECAPOUPEE 1.\p"
	.string "L’un des ces POKéMON ne peut pas\n"
	.string "utiliser VAMPIRISME. Lequel?$"

Route110_TrickHousePuzzle5_Text_CorrectGoThrough:
	.string "FELICITATIONS. BIEN REPONDU.\n"
	.string "AVANCE, S’IL TE PLAIT.$"

Route110_TrickHousePuzzle5_Text_DisappointmentError:
	.string "BZZZT. DECEPTION.\n"
	.string "ERREUR FATALE.$"

Route110_TrickHousePuzzle5_Text_Wahahahaha:
	.string "OUAHAHAHAHA! OUAHAHAHAHA!\n"
	.string "CLINK-CLAC!$"

Route110_TrickHousePuzzle5_Text_WaitForNextChallenge:
	.string "TON PROCHAIN DEFI NOUS ATTENDONS.$"

Route110_TrickHousePuzzle5_Text_Mechadoll2Intro:
	.string "CLINK-CLAC…\n"
	.string "MECAPOUPEE 2 JE SUIS!\p"
	.string "PARAMETRE DE DIFFICULTE DU QUIZ\n"
	.string "DE MECAPOUPEE 1 TROP BAS.$"

Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz1:
	.string "QUIZ MECAPOUPEE 2.\p"
	.string "Lequel de ces POKéMON TIMMY a-t-il\n"
	.string "emprunté à ton père?$"

Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz2:
	.string "QUIZ MECAPOUPEE 2.\p"
	.string "Lequel de ces POKéMON poursuivait\n"
	.string "PROF. SEKO?$"

Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz3:
	.string "QUIZ MECAPOUPEE 2.\p"
	.string "Lequel de ces POKéMON la TEAM AQUA\n"
	.string "a-t-elle utilisé dans le BOIS CLEMENTI?$"

Route110_TrickHousePuzzle5_Text_Mechadoll3Intro:
	.string "CLINK-CLAC…\n"
	.string "MECAPOUPEE 3 JE SUIS!\p"
	.string "L’ARGENT EST MON SEUL INTERET.$"

Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz1:
	.string "QUIZ MECAPOUPEE 3.\p"
	.string "Qu’est-ce qui coûte le plus cher?\n"
	.string "Trois LETTRES PORT ou un ANTI-BRULE?$"

Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz2:
	.string "QUIZ MECAPOUPEE 3.\p"
	.string "Si tu vends une SUPER BALL et\n"
	.string "achètes une POTION, combien te\l"
	.string "reste-t-il d’argent?$"

Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz3:
	.string "QUIZ MECAPOUPEE 3.\p"
	.string "Un REPOUSSE et un SODA COOL\n"
	.string "coûtent-ils plus qu’une SUPER POTION?$"

Route110_TrickHousePuzzle5_Text_Mechadoll4Intro:
	.string "CLINK-CLAC…\n"
	.string "MECAPOUPEE 4 JE SUIS!\p"
	.string "MON QUIZ PORTE SUR LA BEAUTE.$"

Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz1:
	.string "QUIZ MECAPOUPEE 4.\p"
	.string "Dans la MAISON DU BORD DE MER, y\n"
	.string "avait-il plus d’hommes ou de femmes?$"

Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz2:
	.string "QUIZ MECAPOUPEE 4.\p"
	.string "A VERMILAVA, y avait-il plus de vieux\n"
	.string "monsieurs ou de vieilles dames?$"

Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz3:
	.string "QUIZ MECAPOUPEE 4.\p"
	.string "Dans l’ECOLE DE DRESSEURS,\n"
	.string "combien y avait-il d’élèves filles?$"

Route110_TrickHousePuzzle5_Text_Mechadoll5Intro:
	.string "CLINK-CLAC…\n"
	.string "MECAPOUPEE 5 JE SUIS!\p"
	.string "LA PLUS GRANDE REUSSITE DE MON\n"
	.string "MAITRE, JE SUIS.$"

Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz1:
	.string "QUIZ MECAPOUPEE 5.\p"
	.string "Au FAN CLUB POKéMON de POIVRESSEL,\n"
	.string "combien y avait-il de POKéMON?$"

Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz2:
	.string "QUIZ MECAPOUPEE 5.\p"
	.string "A CIMETRONELLE, combien y avait-il\n"
	.string "de cabanes?$"

Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz3:
	.string "QUIZ MECAPOUPEE 5.\p"
	.string "Sur la PISTE CYCLABLE, combien de\n"
	.string "TRIATHLETES y avait-il?$"
