@ Unused
EventScript_28CCAA:: @ 828CCAA
	setvar VAR_0x8005, 8
	special InterviewBefore
	compare VAR_RESULT, 1
	goto_if_eq EventScript_UnusedRet
	setvar VAR_0x8005, 8
	special InterviewAfter
	return

EventScript_UnusedRet:: @ 828CCC6
	return

@ Gabby and Ty always move to the same spots for the first 5 battles
@ From the 6th battle onwards, they move randomly between locations 6-8
@ Note: The local IDs of Gabby and Ty are hard-coded in GabbyAndTySetScriptVarsToObjectEventLocalIds
GabbyAndTy_EventScript_UpdateLocation:: @ 828CCC7
	cleartrainerflag TRAINER_GABBY_AND_TY_6
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

GabbyAndTy_EventScript_MoveForBattle1:: @ 828CD38
	call GabbyAndTy_EventScript_ShowAtRoute111_1
	return

GabbyAndTy_EventScript_MoveForBattle2:: @ 828CD3E
	call GabbyAndTy_EventScript_ShowAtRoute118_1
	call GabbyAndTy_EventScript_HideAtRoute111_1
	return

GabbyAndTy_EventScript_MoveForBattle3:: @ 828CD49
	call GabbyAndTy_EventScript_ShowAtRoute120_1
	call GabbyAndTy_EventScript_HideAtRoute118_1
	return

GabbyAndTy_EventScript_MoveForBattle4:: @ 828CD54
	call GabbyAndTy_EventScript_ShowAtRoute111_3
	call GabbyAndTy_EventScript_HideAtRoute120_1
	return

GabbyAndTy_EventScript_MoveForBattle5:: @ 828CD5F
	call GabbyAndTy_EventScript_ShowAtRoute118_2
	call GabbyAndTy_EventScript_HideAtRoute111_3
	return

GabbyAndTy_EventScript_MoveForBattle6:: @ 828CD6A
	call GabbyAndTy_EventScript_ShowAtRoute120_2
	call GabbyAndTy_EventScript_HideAtRoute118_2
	return

GabbyAndTy_EventScript_MoveForBattle7:: @ 828CD75
	call GabbyAndTy_EventScript_ShowAtRoute111_2
	call GabbyAndTy_EventScript_HideAtRoute120_2
	return

GabbyAndTy_EventScript_MoveForBattle8:: @ 828CD80
	call GabbyAndTy_EventScript_ShowAtRoute118_3
	call GabbyAndTy_EventScript_HideAtRoute111_2
	return

GabbyAndTy_EventScript_MoveForBattle9:: @ 828CD8B
	call GabbyAndTy_EventScript_ShowAtRoute120_2
	call GabbyAndTy_EventScript_HideAtRoute118_3
	return

GabbyAndTy_EventScript_HideAtRoute111_1:: @ 828CD96
	setflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_1
	return

GabbyAndTy_EventScript_ShowAtRoute111_1:: @ 828CD9A
	clearflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_1
	return

GabbyAndTy_EventScript_HideAtRoute118_1:: @ 828CD9E
	setflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_1
	return

GabbyAndTy_EventScript_ShowAtRoute118_1:: @ 828CDA2
	clearflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_1
	return

GabbyAndTy_EventScript_HideAtRoute120_1:: @ 828CDA6
	setflag FLAG_HIDE_ROUTE_120_GABBY_AND_TY_1
	return

GabbyAndTy_EventScript_ShowAtRoute120_1:: @ 828CDAA
	clearflag FLAG_HIDE_ROUTE_120_GABBY_AND_TY_1
	return

GabbyAndTy_EventScript_HideAtRoute111_3:: @ 828CDAE
	setflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_3
	return

GabbyAndTy_EventScript_ShowAtRoute111_3:: @ 828CDB2
	clearflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_3
	return

GabbyAndTy_EventScript_HideAtRoute118_2:: @ 828CDB6
	setflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_2
	return

GabbyAndTy_EventScript_ShowAtRoute118_2:: @ 828CDBA
	clearflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_2
	return

GabbyAndTy_EventScript_HideAtRoute120_2:: @ 828CDBE
	setflag FLAG_HIDE_ROUTE_120_GABBY_AND_TY_2
	return

GabbyAndTy_EventScript_ShowAtRoute120_2:: @ 828CDC2
	clearflag FLAG_HIDE_ROUTE_120_GABBY_AND_TY_2
	return

GabbyAndTy_EventScript_HideAtRoute111_2:: @ 828CDC6
	setflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_2
	return

GabbyAndTy_EventScript_ShowAtRoute111_2:: @ 828CDCA
	clearflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_2
	return

GabbyAndTy_EventScript_HideAtRoute118_3:: @ 828CDCE
	setflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_3
	return

GabbyAndTy_EventScript_ShowAtRoute118_3:: @ 828CDD2
	clearflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_3
	return

GabbyAndTy_EventScript_GabbyBattle1:: @ 828CDD6
	trainerbattle_double TRAINER_GABBY_AND_TY_1, GabbyAndTy_Text_GabbyPreFirstBattle, GabbyAndTy_Text_GabbyDefeatFirstTime, GabbyAndTy_Text_GabbyNotEnoughMons, GabbyAndTy_EventScript_FirstInterview
	msgbox GabbyAndTy_Text_KeepingAnEyeOutForYou, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_TyBattle1:: @ 828CDF6
	trainerbattle_double TRAINER_GABBY_AND_TY_1, GabbyAndTy_Text_TyPreFirstBattle, GabbyAndTy_Text_TyDefeatFirstTime, GabbyAndTy_Text_TyNotEnoughMons, GabbyAndTy_EventScript_FirstInterview
	msgbox GabbyAndTy_Text_TyPostBattle, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_GabbyBattle2:: @ 828CE16
	trainerbattle_double TRAINER_GABBY_AND_TY_2, GabbyAndTy_Text_GabbyIntro, GabbyAndTy_Text_GabbyDefeat, GabbyAndTy_Text_GabbyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
	msgbox GabbyAndTy_Text_KeepingAnEyeOutForYou, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_TyBattle2:: @ 828CE36
	trainerbattle_double TRAINER_GABBY_AND_TY_2, GabbyAndTy_Text_TyIntro, GabbyAndTy_Text_TyDefeat, GabbyAndTy_Text_TyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
	msgbox GabbyAndTy_Text_TyPostBattle, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_GabbyBattle3:: @ 828CE56
	trainerbattle_double TRAINER_GABBY_AND_TY_3, GabbyAndTy_Text_GabbyIntro, GabbyAndTy_Text_GabbyDefeat, GabbyAndTy_Text_GabbyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
	msgbox GabbyAndTy_Text_KeepingAnEyeOutForYou, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_TyBattle3:: @ 828CE76
	trainerbattle_double TRAINER_GABBY_AND_TY_3, GabbyAndTy_Text_TyIntro, GabbyAndTy_Text_TyDefeat, GabbyAndTy_Text_TyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
	msgbox GabbyAndTy_Text_TyPostBattle, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_GabbyBattle4:: @ 828CE96
	trainerbattle_double TRAINER_GABBY_AND_TY_4, GabbyAndTy_Text_GabbyIntro, GabbyAndTy_Text_GabbyDefeat, GabbyAndTy_Text_GabbyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
	msgbox GabbyAndTy_Text_KeepingAnEyeOutForYou, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_TyBattle4:: @ 828CEB6
	trainerbattle_double TRAINER_GABBY_AND_TY_4, GabbyAndTy_Text_TyIntro, GabbyAndTy_Text_TyDefeat, GabbyAndTy_Text_TyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
	msgbox GabbyAndTy_Text_TyPostBattle, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_GabbyBattle5:: @ 828CED6
	trainerbattle_double TRAINER_GABBY_AND_TY_5, GabbyAndTy_Text_GabbyIntro, GabbyAndTy_Text_GabbyDefeat, GabbyAndTy_Text_GabbyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
	msgbox GabbyAndTy_Text_KeepingAnEyeOutForYou, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_TyBattle5:: @ 828CEF6
	trainerbattle_double TRAINER_GABBY_AND_TY_5, GabbyAndTy_Text_TyIntro, GabbyAndTy_Text_TyDefeat, GabbyAndTy_Text_TyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
	msgbox GabbyAndTy_Text_TyPostBattle, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_GabbyBattle6:: @ 828CF16
	trainerbattle_double TRAINER_GABBY_AND_TY_6, GabbyAndTy_Text_GabbyIntro, GabbyAndTy_Text_GabbyDefeat, GabbyAndTy_Text_GabbyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
	msgbox GabbyAndTy_Text_KeepingAnEyeOutForYou, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_TyBattle6:: @ 828CF36
	trainerbattle_double TRAINER_GABBY_AND_TY_6, GabbyAndTy_Text_TyIntro, GabbyAndTy_Text_TyDefeat, GabbyAndTy_Text_TyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
	msgbox GabbyAndTy_Text_TyPostBattle, MSGBOX_DEFAULT
	release
	end

GabbyAndTy_EventScript_FirstInterview:: @ 828CF56
	special GabbyAndTyBeforeInterview
	special GabbyAndTySetScriptVarsToObjectEventLocalIds
	compare VAR_FACING, DIR_NORTH
	call_if_eq GabbyAndTy_EventScript_FacePlayerNorth
	compare VAR_FACING, DIR_SOUTH
	call_if_eq GabbyAndTy_EventScript_FacePlayerSouth
	compare VAR_FACING, DIR_EAST
	call_if_eq GabbyAndTy_EventScript_FacePlayerEast
	goto_if_set FLAG_TEMP_1, GabbyAndTy_EventScript_KeepingAnEyeOutForYou
	msgbox GabbyAndTy_Text_WhoAreYouInterview, MSGBOX_YESNO
	goto GabbyAndTy_EventScript_Interview
	end

GabbyAndTy_EventScript_FacePlayerNorth:: @ 828CF94
	applymovement VAR_0x8004, GabbyAndTy_Movement_WalkInPlaceDown
	waitmovement 0
	return

GabbyAndTy_EventScript_FacePlayerSouth:: @ 828CF9F
	applymovement VAR_0x8004, GabbyAndTy_Movement_WalkInPlaceUp
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

GabbyAndTy_EventScript_FacePlayerEast:: @ 828CFB1
	applymovement VAR_0x8004, GabbyAndTy_Movement_WalkInPlaceLeft
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

GabbyAndTy_EventScript_RequestInterview:: @ 828CFC3
	special GabbyAndTyBeforeInterview
	special GabbyAndTySetScriptVarsToObjectEventLocalIds
	compare VAR_FACING, DIR_NORTH
	call_if_eq GabbyAndTy_EventScript_FacePlayerNorth
	compare VAR_FACING, DIR_SOUTH
	call_if_eq GabbyAndTy_EventScript_FacePlayerSouth
	compare VAR_FACING, DIR_EAST
	call_if_eq GabbyAndTy_EventScript_FacePlayerEast
	goto_if_set FLAG_TEMP_1, GabbyAndTy_EventScript_KeepingAnEyeOutForYou
	specialvar VAR_RESULT, GabbyAndTyGetLastQuote
	compare VAR_RESULT, 0
	goto_if_eq GabbyAndTy_EventScript_DidntInterviewLastTime
	msgbox GabbyAndTy_Text_QuoteFromLastInterview, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GabbyAndTyGetLastBattleTrivia
	switch VAR_RESULT
	case 0, GabbyAndTy_EventScript_RequestInterviewNoTrivia
	case 1, GabbyAndTy_EventScript_RequestInterviewShortBattle
	case 2, GabbyAndTy_EventScript_RequestInterviewThrewBall
	case 3, GabbyAndTy_EventScript_RequestInterviewUsedItems
	case 4, GabbyAndTy_EventScript_RequestInterviewLostAMon
	end

GabbyAndTy_Movement_WalkInPlaceDown: @ 828D04D
	walk_in_place_down
	step_end

GabbyAndTy_Movement_WalkInPlaceUp: @ 828D04F
	walk_in_place_up
	step_end

GabbyAndTy_Movement_WalkInPlaceLeft: @ 828D051
	walk_in_place_left
	step_end

GabbyAndTy_EventScript_DidntInterviewLastTime:: @ 828D053
	msgbox GabbyAndTy_Text_GiveUsAnInterviewThisTime, MSGBOX_YESNO
	goto GabbyAndTy_EventScript_Interview
	end

GabbyAndTy_EventScript_RequestInterviewNoTrivia:: @ 828D061
	msgbox GabbyAndTy_Text_InterviewAgain, MSGBOX_YESNO
	goto GabbyAndTy_EventScript_Interview
	end

GabbyAndTy_EventScript_RequestInterviewShortBattle:: @ 828D06F
	msgbox GabbyAndTy_Text_YouStompedUsInterviewAgain, MSGBOX_YESNO
	goto GabbyAndTy_EventScript_Interview
	end

GabbyAndTy_EventScript_RequestInterviewThrewBall:: @ 828D07D
	msgbox GabbyAndTy_Text_YouThrewABallAtUsInterviewAgain, MSGBOX_YESNO
	goto GabbyAndTy_EventScript_Interview
	end

GabbyAndTy_EventScript_RequestInterviewUsedItems:: @ 828D08B
	msgbox GabbyAndTy_Text_CleverItemSkillsInterviewAgain, MSGBOX_YESNO
	goto GabbyAndTy_EventScript_Interview
	end

GabbyAndTy_EventScript_RequestInterviewLostAMon:: @ 828D099
	msgbox GabbyAndTy_Text_WeLookedRespectableInterviewAgain, MSGBOX_YESNO
	goto GabbyAndTy_EventScript_Interview
	end

GabbyAndTy_EventScript_Interview:: @ 828D0A7
	compare VAR_RESULT, NO
	goto_if_eq GabbyAndTy_EventScript_DontGiveUpKeepingEyeOut
	msgbox GabbyAndTy_Text_DescribeYourFeelings, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_GABBY_AND_TY
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 0
	goto_if_eq GabbyAndTy_EventScript_DontGiveUpKeepingEyeOut
	msgbox GabbyAndTy_Text_PerfectWellBeSeeingYou, MSGBOX_DEFAULT
	special GabbyAndTyAfterInterview
	setflag FLAG_TEMP_1
	release
	end

GabbyAndTy_EventScript_DontGiveUpKeepingEyeOut:: @ 828D0E1
	msgbox GabbyAndTy_Text_DontGiveUpKeepingEyeOut, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	release
	end

GabbyAndTy_EventScript_KeepingAnEyeOutForYou:: @ 828D0EE
	msgbox GabbyAndTy_Text_KeepingAnEyeOutForYou, MSGBOX_DEFAULT
	release
	end
