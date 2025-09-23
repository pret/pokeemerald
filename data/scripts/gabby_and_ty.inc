@ Gabby and Ty can appear in a fixed location on 3 different routes.
@ Each time they are battled they will disappear from the route they're on
@ and relocate to the next one, in the order Route 111 -> Route 118 -> Route 120.
@ Gabby and Ty have 6 different parties which will get cycled on each appearance.
@ After they're defeated 6 times they will stick to their 6th party but continue
@ cycling between the 3 routes. To determine which trainer party gets used GF created
@ multiple object events for Gabby and Ty on each of the 3 routes. The scripts below
@ handle hiding and showing these objects so the correct party appears on the correct route.
@ Route 111 and Route 118 have 3 object events each (parties 1,4,6 and 2,5,6 respectively)
@ and Route 120 has 2 object events each (parties 3 and 6).
GabbyAndTy_EventScript_UpdateLocation::
	cleartrainerflag TRAINER_GABBY_AND_TY_6  @ Clear flag for their final party to allow infinite rematches.
	specialvar VAR_RESULT, GabbyAndTyGetBattleNum
	switch VAR_RESULT
	case 0, GabbyAndTy_EventScript_MoveForBattle1
	case 1, GabbyAndTy_EventScript_MoveForBattle2
	case 2, GabbyAndTy_EventScript_MoveForBattle3
	case 3, GabbyAndTy_EventScript_MoveForBattle4
	case 4, GabbyAndTy_EventScript_MoveForBattle5
	case 5, GabbyAndTy_EventScript_MoveForBattle6
	case 6, GabbyAndTy_EventScript_MoveForBattle7
	case 7, GabbyAndTy_EventScript_MoveForBattle8
	case 8, GabbyAndTy_EventScript_MoveForBattle9
	end

GabbyAndTy_EventScript_MoveForBattle1::
	call GabbyAndTy_EventScript_ShowAtRoute111_1
	return

GabbyAndTy_EventScript_MoveForBattle2::
	call GabbyAndTy_EventScript_ShowAtRoute118_1
	call GabbyAndTy_EventScript_HideAtRoute111_1
	return

GabbyAndTy_EventScript_MoveForBattle3::
	call GabbyAndTy_EventScript_ShowAtRoute120_1
	call GabbyAndTy_EventScript_HideAtRoute118_1
	return

GabbyAndTy_EventScript_MoveForBattle4::
	call GabbyAndTy_EventScript_ShowAtRoute111_2
	call GabbyAndTy_EventScript_HideAtRoute120_1
	return

GabbyAndTy_EventScript_MoveForBattle5::
	call GabbyAndTy_EventScript_ShowAtRoute118_2
	call GabbyAndTy_EventScript_HideAtRoute111_2
	return

GabbyAndTy_EventScript_MoveForBattle6::
	call GabbyAndTy_EventScript_ShowAtRoute120_2
	call GabbyAndTy_EventScript_HideAtRoute118_2
	return

GabbyAndTy_EventScript_MoveForBattle7::
	call GabbyAndTy_EventScript_ShowAtRoute111_3
	call GabbyAndTy_EventScript_HideAtRoute120_2
	return

GabbyAndTy_EventScript_MoveForBattle8::
	call GabbyAndTy_EventScript_ShowAtRoute118_3
	call GabbyAndTy_EventScript_HideAtRoute111_3
	return

GabbyAndTy_EventScript_MoveForBattle9::
	call GabbyAndTy_EventScript_ShowAtRoute120_2
	call GabbyAndTy_EventScript_HideAtRoute118_3
	return

GabbyAndTy_EventScript_HideAtRoute111_1::
	setflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_1
	return

GabbyAndTy_EventScript_ShowAtRoute111_1::
	clearflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_1
	return

GabbyAndTy_EventScript_HideAtRoute118_1::
	setflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_1
	return

GabbyAndTy_EventScript_ShowAtRoute118_1::
	clearflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_1
	return

GabbyAndTy_EventScript_HideAtRoute120_1::
	setflag FLAG_HIDE_ROUTE_120_GABBY_AND_TY_1
	return

GabbyAndTy_EventScript_ShowAtRoute120_1::
	clearflag FLAG_HIDE_ROUTE_120_GABBY_AND_TY_1
	return

GabbyAndTy_EventScript_HideAtRoute111_2::
	setflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_2
	return

GabbyAndTy_EventScript_ShowAtRoute111_2::
	clearflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_2
	return

GabbyAndTy_EventScript_HideAtRoute118_2::
	setflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_2
	return

GabbyAndTy_EventScript_ShowAtRoute118_2::
	clearflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_2
	return

GabbyAndTy_EventScript_HideAtRoute120_2::
	setflag FLAG_HIDE_ROUTE_120_GABBY_AND_TY_2
	return

GabbyAndTy_EventScript_ShowAtRoute120_2::
	clearflag FLAG_HIDE_ROUTE_120_GABBY_AND_TY_2
	return

GabbyAndTy_EventScript_HideAtRoute111_3::
	setflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_3
	return

GabbyAndTy_EventScript_ShowAtRoute111_3::
	clearflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_3
	return

GabbyAndTy_EventScript_HideAtRoute118_3::
	setflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_3
	return

GabbyAndTy_EventScript_ShowAtRoute118_3::
	clearflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_3
	return

GabbyAndTy_EventScript_GabbyBattle1::
	trainerbattle_double TRAINER_GABBY_AND_TY_1, GabbyAndTy_Text_GabbyPreFirstBattle, GabbyAndTy_Text_GabbyDefeatFirstTime, GabbyAndTy_Text_GabbyNotEnoughMons, GabbyAndTy_EventScript_FirstInterview
	msgbox GabbyAndTy_Text_KeepingAnEyeOutForYou, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_TyBattle1::
	trainerbattle_double TRAINER_GABBY_AND_TY_1, GabbyAndTy_Text_TyPreFirstBattle, GabbyAndTy_Text_TyDefeatFirstTime, GabbyAndTy_Text_TyNotEnoughMons, GabbyAndTy_EventScript_FirstInterview
	msgbox GabbyAndTy_Text_TyPostBattle, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_GabbyBattle2::
	trainerbattle_double TRAINER_GABBY_AND_TY_2, GabbyAndTy_Text_GabbyIntro, GabbyAndTy_Text_GabbyDefeat, GabbyAndTy_Text_GabbyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
	msgbox GabbyAndTy_Text_KeepingAnEyeOutForYou, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_TyBattle2::
	trainerbattle_double TRAINER_GABBY_AND_TY_2, GabbyAndTy_Text_TyIntro, GabbyAndTy_Text_TyDefeat, GabbyAndTy_Text_TyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
	msgbox GabbyAndTy_Text_TyPostBattle, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_GabbyBattle3::
	trainerbattle_double TRAINER_GABBY_AND_TY_3, GabbyAndTy_Text_GabbyIntro, GabbyAndTy_Text_GabbyDefeat, GabbyAndTy_Text_GabbyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
	msgbox GabbyAndTy_Text_KeepingAnEyeOutForYou, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_TyBattle3::
	trainerbattle_double TRAINER_GABBY_AND_TY_3, GabbyAndTy_Text_TyIntro, GabbyAndTy_Text_TyDefeat, GabbyAndTy_Text_TyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
	msgbox GabbyAndTy_Text_TyPostBattle, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_GabbyBattle4::
	trainerbattle_double TRAINER_GABBY_AND_TY_4, GabbyAndTy_Text_GabbyIntro, GabbyAndTy_Text_GabbyDefeat, GabbyAndTy_Text_GabbyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
	msgbox GabbyAndTy_Text_KeepingAnEyeOutForYou, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_TyBattle4::
	trainerbattle_double TRAINER_GABBY_AND_TY_4, GabbyAndTy_Text_TyIntro, GabbyAndTy_Text_TyDefeat, GabbyAndTy_Text_TyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
	msgbox GabbyAndTy_Text_TyPostBattle, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_GabbyBattle5::
	trainerbattle_double TRAINER_GABBY_AND_TY_5, GabbyAndTy_Text_GabbyIntro, GabbyAndTy_Text_GabbyDefeat, GabbyAndTy_Text_GabbyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
	msgbox GabbyAndTy_Text_KeepingAnEyeOutForYou, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_TyBattle5::
	trainerbattle_double TRAINER_GABBY_AND_TY_5, GabbyAndTy_Text_TyIntro, GabbyAndTy_Text_TyDefeat, GabbyAndTy_Text_TyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
	msgbox GabbyAndTy_Text_TyPostBattle, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_GabbyBattle6::
	trainerbattle_double TRAINER_GABBY_AND_TY_6, GabbyAndTy_Text_GabbyIntro, GabbyAndTy_Text_GabbyDefeat, GabbyAndTy_Text_GabbyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
	msgbox GabbyAndTy_Text_KeepingAnEyeOutForYou, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_TyBattle6::
	trainerbattle_double TRAINER_GABBY_AND_TY_6, GabbyAndTy_Text_TyIntro, GabbyAndTy_Text_TyDefeat, GabbyAndTy_Text_TyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
	msgbox GabbyAndTy_Text_TyPostBattle, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_FirstInterview::
	special GabbyAndTyBeforeInterview
	special GetGabbyAndTyLocalIds
	call_if_eq VAR_FACING, DIR_NORTH, GabbyAndTy_EventScript_FacePlayerNorth
	call_if_eq VAR_FACING, DIR_SOUTH, GabbyAndTy_EventScript_FacePlayerSouth
	call_if_eq VAR_FACING, DIR_EAST, GabbyAndTy_EventScript_FacePlayerEast
	goto_if_set FLAG_TEMP_SKIP_GABBY_INTERVIEW, GabbyAndTy_EventScript_KeepingAnEyeOutForYou
	msgbox GabbyAndTy_Text_WhoAreYouInterview, MSGBOX_YESNO
	goto GabbyAndTy_EventScript_Interview
	end

GabbyAndTy_EventScript_FacePlayerNorth::
	applymovement VAR_0x8004, GabbyAndTy_Movement_WalkInPlaceDown
	waitmovement 0
	return

GabbyAndTy_EventScript_FacePlayerSouth::
	applymovement VAR_0x8004, GabbyAndTy_Movement_WalkInPlaceUp
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

GabbyAndTy_EventScript_FacePlayerEast::
	applymovement VAR_0x8004, GabbyAndTy_Movement_WalkInPlaceLeft
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

GabbyAndTy_EventScript_RequestInterview::
	special GabbyAndTyBeforeInterview
	special GetGabbyAndTyLocalIds
	call_if_eq VAR_FACING, DIR_NORTH, GabbyAndTy_EventScript_FacePlayerNorth
	call_if_eq VAR_FACING, DIR_SOUTH, GabbyAndTy_EventScript_FacePlayerSouth
	call_if_eq VAR_FACING, DIR_EAST, GabbyAndTy_EventScript_FacePlayerEast
	goto_if_set FLAG_TEMP_SKIP_GABBY_INTERVIEW, GabbyAndTy_EventScript_KeepingAnEyeOutForYou
	specialvar VAR_RESULT, GabbyAndTyGetLastQuote
	goto_if_eq VAR_RESULT, 0, GabbyAndTy_EventScript_DidntInterviewLastTime
	msgbox GabbyAndTy_Text_QuoteFromLastInterview, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GabbyAndTyGetLastBattleTrivia
	switch VAR_RESULT
	case 0, GabbyAndTy_EventScript_RequestInterviewNoTrivia
	case 1, GabbyAndTy_EventScript_RequestInterviewShortBattle
	case 2, GabbyAndTy_EventScript_RequestInterviewThrewBall
	case 3, GabbyAndTy_EventScript_RequestInterviewUsedItems
	case 4, GabbyAndTy_EventScript_RequestInterviewLostAMon
	end

GabbyAndTy_Movement_WalkInPlaceDown:
	walk_in_place_down
	step_end

GabbyAndTy_Movement_WalkInPlaceUp:
	walk_in_place_up
	step_end

GabbyAndTy_Movement_WalkInPlaceLeft:
	walk_in_place_left
	step_end

GabbyAndTy_EventScript_DidntInterviewLastTime::
	msgbox GabbyAndTy_Text_GiveUsAnInterviewThisTime, MSGBOX_YESNO
	goto GabbyAndTy_EventScript_Interview
	end

GabbyAndTy_EventScript_RequestInterviewNoTrivia::
	msgbox GabbyAndTy_Text_InterviewAgain, MSGBOX_YESNO
	goto GabbyAndTy_EventScript_Interview
	end

GabbyAndTy_EventScript_RequestInterviewShortBattle::
	msgbox GabbyAndTy_Text_YouStompedUsInterviewAgain, MSGBOX_YESNO
	goto GabbyAndTy_EventScript_Interview
	end

GabbyAndTy_EventScript_RequestInterviewThrewBall::
	msgbox GabbyAndTy_Text_YouThrewABallAtUsInterviewAgain, MSGBOX_YESNO
	goto GabbyAndTy_EventScript_Interview
	end

GabbyAndTy_EventScript_RequestInterviewUsedItems::
	msgbox GabbyAndTy_Text_CleverItemSkillsInterviewAgain, MSGBOX_YESNO
	goto GabbyAndTy_EventScript_Interview
	end

GabbyAndTy_EventScript_RequestInterviewLostAMon::
	msgbox GabbyAndTy_Text_WeLookedRespectableInterviewAgain, MSGBOX_YESNO
	goto GabbyAndTy_EventScript_Interview
	end

GabbyAndTy_EventScript_Interview::
	goto_if_eq VAR_RESULT, NO, GabbyAndTy_EventScript_DontGiveUpKeepingEyeOut
	msgbox GabbyAndTy_Text_DescribeYourFeelings, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_GABBY_AND_TY
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, GabbyAndTy_EventScript_DontGiveUpKeepingEyeOut
	msgbox GabbyAndTy_Text_PerfectWellBeSeeingYou, MSGBOX_DEFAULT
	special GabbyAndTyAfterInterview
	setflag FLAG_TEMP_SKIP_GABBY_INTERVIEW
	release
	end

GabbyAndTy_EventScript_DontGiveUpKeepingEyeOut::
	msgbox GabbyAndTy_Text_DontGiveUpKeepingEyeOut, MSGBOX_DEFAULT
	setflag FLAG_TEMP_SKIP_GABBY_INTERVIEW
	release
	end

GabbyAndTy_EventScript_KeepingAnEyeOutForYou::
	msgbox GabbyAndTy_Text_KeepingAnEyeOutForYou, MSGBOX_DEFAULT
	release
	end
